#include "../../../../Includes/Switch/System/Net/WebRequest.hpp"
#include "../../../../Includes/Switch/System/Buffer.hpp"
#include "../../../../Includes/Switch/System/Convert.hpp"
#include "../../../../Includes/Switch/System/Math.hpp"
#include "../../../../Includes/Switch/System/ObjectClosedException.hpp"
#include "../../../../Includes/Switch/System/TimeoutException.hpp"
#include "../../../../Includes/Switch/System/IO/IOException.hpp"
#include "../../../../Includes/Switch/System/Net/WebException.hpp"
#include "../../../../Includes/Switch/System/Net/FtpWebRequest.hpp"
#include "../../../../Includes/Switch/System/Net/HttpWebRequest.hpp"
#include "../../../../Includes/Switch/System/Net/WebRequestMethods.hpp"
#include "../../../../Includes/Switch/System/Threading/TimeOut.hpp"
#include "Internals/curl.hpp"

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
    throw NotSupportedException(sw_current_information);
  
  Curl::Init(this->requestHandle);
  
  if (this->requestHandle == IntPtr::Zero)
    throw NotSupportedException(sw_current_information);
  
  pendingRequest++;
  Curl::SetUrl(this->requestHandle, uri.AbsoluteUri);
  Curl::SetVerbose(this->requestHandle, 0L);
}

WebRequest::~WebRequest() {
  if (this->requestHandle != IntPtr::Zero) {
    Curl::Cleanup(this->requestHandle);
    pendingRequest--;
    
    if (pendingRequest == 0)
      Curl::GlobalCleanup();
  }
}

refptr<WebRequest> WebRequest::Create(const Uri& requestUriString) {
  if (Curl::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(sw_current_information);
  
  if (requestUriString.Scheme == Uri::UriSchemeFtp)
    return new FtpWebRequest(requestUriString);
  
  if (requestUriString.Scheme == Uri::UriSchemeHttp)
    return new HttpWebRequest(requestUriString);
  
  if (requestUriString.Scheme == Uri::UriSchemeHttps)
    return new HttpWebRequest(requestUriString);
  
  throw NotSupportedException(sw_current_information);
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
    throw NotSupportedException(sw_current_information);
  
  if (this->requestHandle == IntPtr::Zero)
    throw NotSupportedException(sw_current_information);
  
  Curl::SetUserName(this->requestHandle, credential.UserName);
  Curl::SetPassword(this->requestHandle, credential.Password);
  this->credential = credential;
}

void WebRequest::ProccessRequestThread() {
  if (Curl::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(sw_current_information);
  
  try {
    this->internalError = Curl::Perform(this->GetRequestHandle());
    if (this->internalError == 0) {
      double contentLength;
      if (Curl::GetContentDownloadLength(this->GetRequestHandle(), contentLength) == 0)
        this->GetInternalResponse().contentLength = Convert::ToInt64(Double(contentLength));
      
      this->internalError = Curl::GetContentType(this->GetRequestHandle(), this->GetInternalResponse().contentType);
    }
    this->Finished(this->internalError);
  } catch (const Exception&) {
    this->internalError = this->IsResponseStreamNeeded() ? 19 : 25;
    this->Finished(this->internalError);
  }
}

void WebRequest::Finished(int32 error) {
  if (!Curl::GetOSSupportsWebOperations())
    throw NotSupportedException(sw_current_information);
  
  //Unlock write thread if finished before sending
  this->requestStream.data->readEvent.Set();
  GetInternalResponse().EndTransfert();
  
  if (error != 0) {
    throw System::Net::WebException(sw_current_information);
  }
}

void WebRequest::ProccessRequest() {
  if (!Curl::GetOSSupportsWebOperations())
    throw NotSupportedException(sw_current_information);
  
  //Thread already opened by the other stream (response or request)
  if (this->requestThread.IsAlive())
    return;
  
  Curl::SetTimeout(this->requestHandle, Timeout());
  
  if (IsResponseStreamNeeded()) {
    Curl::SetWriteFunction(this->requestHandle, WebResponse::WriteStream);
    Curl::SetWriteData(this->requestHandle, &GetInternalResponse().responseStream);
  } else
    Curl::SetWriteFunction(this->requestHandle, WebResponse::WriteNullStream);
  
  if (IsRequestStreamNeeded()) {
    Curl::SetReadFunction(this->requestHandle, WebRequest::ReadStream);
    Curl::SetReadData(this->requestHandle, &this->requestStream);
    
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

System::Net::WebRequest::WebRequestStream WebRequest::GetRequestStream() {
  return this->requestStream;
}

int64 WebRequest::WebRequestStream::Seek(int64, System::IO::SeekOrigin) {
  throw NotSupportedException(sw_current_information);	
}

void WebRequest::WebRequestStream::Write(const Array<byte>& buffer, int32 offset, int32 count) {
  if (offset < 0)
    throw ArgumentOutOfRangeException(sw_current_information);
  if (IsClosed())
    throw ObjectClosedException(sw_current_information);
  if (!CanWrite())
    throw NotSupportedException(sw_current_information);

  if (CanWrite()) {
    Write((void*)&buffer.Data()[offset], count);
  }
}

void WebRequest::WebRequestStream::Write(const void* handle, int32 count) {
  if (IsClosed())
    throw IO::IOException(sw_current_information);
  
  //If the request is not started launch the writing thread
  if (!this->data->started) {
    this->data->started = true;
    this->data->webRequest->ProccessRequest();
  }
  
  if (this->data->webRequest->internalError == 0) {
    this->data->buffer = (void*)handle;
    this->data->bufferSize =count;
    this->data->bufferOffset = 0;
    //release read
    this->data->writeEvent.Set();
    //Wait read is finished
    
    if (!this->data->readEvent.WaitOne(this->data->webRequest->Timeout()))
      throw TimeoutException(sw_current_information);
  } else {
    //release read
    this->data->writeEvent.Set();
    throw InvalidOperationException(sw_current_information);
  }
}

int32 WebRequest::WebRequestStream::Send(void* handle, int32 count) {
  int32 byteToCopy = 0;
  // Wait data to read
  if (!this->data->writeEvent.WaitOne(this->data->webRequest->Timeout()))
    throw TimeoutException(sw_current_information);
  
  if (this->data->webRequest->internalError == 0) {
    byteToCopy = Math::Min(count, (this->data->bufferSize - this->data->bufferOffset));
    Buffer::BlockCopy(this->data->buffer, this->data->bufferSize, this->data->bufferOffset, handle, count, 0, byteToCopy);
    this->data->bufferOffset += byteToCopy;
    if (this->data->bufferOffset == this->data->bufferSize) {
      // Release write thread if all the data has been read
      this->data->writeEvent.Reset();
      this->data->readEvent.Set();
    }
  } else {
    this->data->readEvent.Set();
    byteToCopy = 0x10000000 ; //CURL_READFUNC_ABORT  0x10000000
  }

  return byteToCopy;
}

void WebRequest::WebRequestStream::Close() {
  if (!IsClosed()) {
    Stream::Close();
    //Unlock sending thread with an empty buffer
    this->data->bufferSize = 0;
    this->data->bufferOffset = 0;
    this->data->writeEvent.Set();
    if (this->data->started && !this->data->webRequest->IsResponseStreamNeeded())
      this->data->webRequest->requestThread.Join();
  }
}


