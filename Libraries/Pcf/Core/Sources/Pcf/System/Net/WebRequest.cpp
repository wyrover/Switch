#include "../../../../Includes/Pcf/System/Net/WebRequest.h"
#include "../../../../Includes/Pcf/System/Buffer.h"
#include "../../../../Includes/Pcf/System/Convert.h"
#include "../../../../Includes/Pcf/System/Math.h"
#include "../../../../Includes/Pcf/System/ObjectClosedException.h"
#include "../../../../Includes/Pcf/System/TimeoutException.h"
#include "../../../../Includes/Pcf/System/IO/IOException.h"
#include "../../../../Includes/Pcf/System/Net/WebException.h"
#include "../../../../Includes/Pcf/System/Net/FtpWebRequest.h"
#include "../../../../Includes/Pcf/System/Net/HttpWebRequest.h"
#include "../../../../Includes/Pcf/System/Net/WebRequestMethods.h"
#include "../../../../Includes/Pcf/System/Threading/TimeOut.h"
#include "Internals/curl.h"

using namespace System;
using namespace System::Net;
using namespace System::IO;
using namespace System::Threading;

int32 WebRequest::pendingRequest = 0;

WebRequest::WebRequest(const string& uri) : uri(uri){
  InitWebRequest();
}

WebRequest::WebRequest(const Uri& uri) : uri(uri) {
  InitWebRequest();
}

void WebRequest::InitWebRequest() {
  if (Curl::GetOSSupportsWebOperations() == false || (pendingRequest == 0 && Curl::GlobalInit() != 0))
    throw NotSupportedException(pcf_current_information);
  
  Curl::Init(&this->requestHandle);
  
  if (this->requestHandle == null)
    throw NotSupportedException(pcf_current_information);
  
  pendingRequest++;
  Curl::SetUrl(this->requestHandle, uri.AbsoluteUri().Data());
  Curl::SetVerbose(this->requestHandle, 0L);
}

WebRequest::~WebRequest() {
  if (this->requestHandle != null) {
    Curl::Cleanup(this->requestHandle);
    pendingRequest--;
    
    if (pendingRequest == 0)
      Curl::GlobalCleanup();
  }
}

UniquePointer<WebRequest> WebRequest::Create(const Uri& requestUriString) {
  if (Curl::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(pcf_current_information);
  
  if (requestUriString.Scheme == Uri::UriSchemeFtp)
    return new FtpWebRequest(requestUriString);
  
  if (requestUriString.Scheme == Uri::UriSchemeHttp)
    return new HttpWebRequest(requestUriString);
  
  throw NotSupportedException(pcf_current_information);
}

NetworkCredential&  WebRequest::GetCredential() {
  return this->credential;
}

bool WebRequest::IsRequestStreamNeeded() const {
  return GetMethod() == WebRequestMethods::Ftp::UploadFile || GetMethod() == WebRequestMethods::Http::Put || GetMethod() == WebRequestMethods::Http::Post;
}

bool WebRequest::IsResponseStreamNeeded() const {
  return  GetMethod() == WebRequestMethods::Ftp::DownloadFile || GetMethod() == WebRequestMethods::Ftp::ListDirectory || GetMethod() == WebRequestMethods::Ftp::ListDirectoryDetails || GetMethod() == WebRequestMethods::Http::Get || GetMethod() == WebRequestMethods::Http::Post;
}

void WebRequest::SetCredential(const NetworkCredential& credential) {
  if (Curl::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(pcf_current_information);
  
  if (this->requestHandle == null)
    throw NotSupportedException(pcf_current_information);
  
  Curl::SetUserName(this->requestHandle, credential.UserName().Data());
  Curl::SetPassword(this->requestHandle, credential.Password().Data());
  this->credential = credential;
}

void WebRequest::ProccessRequestThread() {
  if (Curl::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(pcf_current_information);
  
  try {
    this->internalError = Curl::Perform(this->GetRequestHandle());
    if (this->internalError == 0) {
      double contentLength;
      if (Curl::GetContentDownloadLength(this->GetRequestHandle(), &contentLength) == 0)
        this->GetInternalResponse().contentLength = Convert::ToInt64(Double(contentLength));
      
      char* contentType;
      if (Curl::GetContentType(this->GetRequestHandle(), &contentType) == 0 && contentType!=null)
        this->GetInternalResponse().contentType = string(contentType);
    }
    this->Finished(this->internalError);
  } catch (const Exception&) {
    this->internalError = this->IsResponseStreamNeeded() ? 19 : 25;
    this->Finished(this->internalError);
  }
}

void WebRequest::Finished(int32 error) {
  if (!Curl::GetOSSupportsWebOperations())
    throw NotSupportedException(pcf_current_information);
  
  //Unlock write thread if finished before sending
  this->requestStream->readEvent.Set();
  GetInternalResponse().EndTransfert();
  
  if (error != 0) {
    throw System::Net::WebException(pcf_current_information);
  }
}

void WebRequest::ProccessRequest() {
  if (!Curl::GetOSSupportsWebOperations())
    throw NotSupportedException(pcf_current_information);
  
  //Thread already opened by the other stream (response or request)
  if (this->requestThread.IsAlive())
    return;
  
  Curl::SetTimeout(this->requestHandle, Timeout());
  
  if (IsResponseStreamNeeded()) {
    Curl::SetWriteFunction(this->requestHandle, WebResponse::WriteStream);
    Curl::SetWriteData(this->requestHandle, GetInternalResponse().GetResponseStream().ToPointer());
  } else
    Curl::SetWriteFunction(this->requestHandle, WebResponse::WriteNullStream);
  
  if (IsRequestStreamNeeded()) {
    Curl::SetReadFunction(this->requestHandle, WebRequest::ReadStream);
    Curl::SetReadData(this->requestHandle, this->requestStream.ToPointer());
    
    if (GetMethod()==WebRequestMethods::Http::Post) {
      Curl::SetUpload(this->requestHandle, 0L);
      if (this->contentLength > 0)
        Curl::SetPostFieldSize(this->requestHandle, this->contentLength);
    } else {
      Curl::SetUpload(this->requestHandle, 1L);
      if (this->contentLength > 0)
        Curl::SetInFileSize(this->requestHandle, this->contentLength);
    }
  }
  
  this->requestThread.Start();
}

size_t WebRequest::ReadStream(void* buffer, size_t size, size_t nmemb, void* stream) {
  try {
    WebRequestStream* webRequestStream = (WebRequestStream*)stream;
    return webRequestStream->Send(buffer, static_cast<int32>(size*nmemb));
  } catch (const System::Exception&) {
    //Time out occurs during reading abort using CURL_READFUNC_ABORT return code
    return 0x10000000;
  }
}

SharedPointer<Stream> WebRequest::GetRequestStream() {
  return this->requestStream.ChangeType<Stream>();
}

int64 WebRequest::WebRequestStream::Seek(int64, System::IO::SeekOrigin) {
  throw NotSupportedException(pcf_current_information);	
}

void WebRequest::WebRequestStream::Write(const Array<byte>& buffer, int32 offset, int32 count) {
  if (offset < 0)
    throw ArgumentOutOfRangeException(pcf_current_information);
  if (IsClosed())
    throw ObjectClosedException(pcf_current_information);
  if (!CanWrite())
    throw NotSupportedException(pcf_current_information);

  if (CanWrite()) {
    Write((void*)&buffer.Data()[offset], count);
  }
}

void WebRequest::WebRequestStream::Write(const void* handle, int32 count) {
  if (IsClosed())
    throw IO::IOException(pcf_current_information);
  
  //If the request is not started launch the writing thread
  if (!this->started) {
    this->started = true;
    this->webRequest->ProccessRequest();
  }
  
  if (this->webRequest->internalError == 0) {
    buffer = (void*)handle;
    this->bufferSize =count;
    this->bufferOffset = 0;
    //release read
    this->writeEvent.Set();
    //Wait read is finished
    
    if (!this->readEvent.WaitOne(this->webRequest->Timeout()))
      throw TimeoutException(pcf_current_information);
  } else {
    //release read
    this->writeEvent.Set();
    throw InvalidOperationException(pcf_current_information);
  }
}

int32 WebRequest::WebRequestStream::Send(void* handle, int32 count) {
  int32 byteToCopy = 0;
  // Wait data to read
  if (!this->writeEvent.WaitOne(this->webRequest->Timeout()))
    throw TimeoutException(pcf_current_information);
  
  if (this->webRequest->internalError == 0) {
    byteToCopy = Math::Min(count, (this->bufferSize - this->bufferOffset));
    Buffer::BlockCopy(buffer, this->bufferSize, this->bufferOffset, handle, count, 0, byteToCopy);
    this->bufferOffset += byteToCopy;
    if (this->bufferOffset == this->bufferSize) {
      // Release write thread if all the data has been read
      this->writeEvent.Reset();
      this->readEvent.Set();
    }
  } else {
    this->readEvent.Set();
    byteToCopy = 0x10000000 ; //CURL_READFUNC_ABORT  0x10000000
  }

  return byteToCopy;
}

void WebRequest::WebRequestStream::Close() {
  if (!IsClosed()) {
    Stream::Close();
    //Unlock sending thread with an empty buffer
    this->bufferSize = 0;
    this->bufferOffset = 0;
    this->writeEvent.Set();
    if (this->started && !this->webRequest->IsResponseStreamNeeded())
      this->webRequest->requestThread.Join();
  }
}


