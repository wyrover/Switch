#include "../../../../Includes/Pcf/Types.h"
#include "../../../../Includes/Pcf/System/Net/WebResponse.h"
#include "../../../../Includes/Pcf/System/Buffer.h"
#include "../../../../Includes/Pcf/System/Math.h"
#include "../../../../Includes/Pcf/System/TimeoutException.h"
#include "../../../../Includes/Pcf/System/IO/IOException.h"
#include "../../../../Includes/Pcf/System/Net/WebRequest.h"
#include "Internals/curl.h"

using namespace System;
using namespace System::Net;
using namespace System::IO;
using namespace System::Threading;

WebResponse::WebResponse() {
  if (!Curl::GetOSSupportsWebOperations())
    throw NotSupportedException(pcf_current_information);
}

void WebResponse::SetWebRequest(WebRequest& webRequest) {
  if (!Curl::GetOSSupportsWebOperations())
    throw NotSupportedException(pcf_current_information);

  this->webRequest = &webRequest;
  this->responseStream->SetWebRequest(this->webRequest);
}

WebResponse::~WebResponse() {
  this->responseStream->Close();
}

SharedPointer<Stream> WebResponse::GetResponseStream() {
  return this->responseStream.ChangeType<Stream>();
}

size_t WebResponse::WriteNullStream(void* buffer, size_t size, size_t nmemb, void* stream) {
  return nmemb*size;
}

size_t WebResponse::WriteStream(void* buffer, size_t size, size_t nmemb, void* stream) {
  WebResponseStream* webResponseStream = (WebResponseStream*)stream;
  int32 ret = webResponseStream->Receive(buffer, static_cast<int32>(size*nmemb));
  return ret;
}

void WebResponse::StartTransfert() {
  this->responseStream->StartTransfert();
}


void WebResponse::EndTransfert() {
  this->responseStream->EndTransfert();
}

int64 WebResponse::GetResponseCode() const {
  if (!Curl::GetOSSupportsWebOperations())
    throw NotSupportedException(pcf_current_information);

  int64 code = 0;
  Curl::GetResponseCode(this->webRequest->GetRequestHandle(), &code);
  return int64(code);
}

WebResponse::WebResponseStream::WebResponseStream() : Stream(1000, 1000) {
}

void WebResponse::WebResponseStream::SetWebRequest(WebRequest* webRequest) {
  this->webRequest = webRequest;
}

void WebResponse::WebResponseStream::StartTransfert() {
  //If the request is not started launch the writing thread
  if (!this->started) {
    this->started = true;
    //Launch the writing thread
    this->writeEvent.Reset();
    this->readEvent.Set();
    this->webRequest->ProccessRequest();
    //Wait the first response packet
    if (!this->writeEvent.WaitOne(this->webRequest->Timeout))
      throw TimeoutException(pcf_current_information);
  }
}

int64 WebResponse::WebResponseStream::Seek(int64, System::IO::SeekOrigin) { 
  throw NotSupportedException(pcf_current_information);	
}

int32 WebResponse::WebResponseStream::Read(Array<byte>& buffer, int32 offset, int32 count) {
  if (offset < 0)
    throw ArgumentOutOfRangeException(pcf_current_information);
  if (IsClosed())
    throw IOException(pcf_current_information);
  if (!CanRead())
    throw NotSupportedException(pcf_current_information);

  int32 nbBytesRead = 0;
  if (CanRead()) {
    nbBytesRead = Read((void*)&buffer.Data()[offset], count);
  }

  if (nbBytesRead == -1)
    nbBytesRead = 0;

  return nbBytesRead;
}


int32 WebResponse::WebResponseStream::Read(void* handle, int32 count) {
  int32 byteToCopy  =0;
  StartTransfert();
  //Wait data to read
  bool isTimeout = !this->writeEvent.WaitOne(this->webRequest->Timeout);
  if (this->webRequest->internalError == 0) {
    if (!isTimeout && !this->finished) {
      byteToCopy = Math::Min(count, (this->bufferSize - this->bufferOffset));
      Buffer::BlockCopy(buffer, this->bufferSize, this->bufferOffset, handle, count, 0, byteToCopy);

      if (byteToCopy < (this->bufferSize - this->bufferOffset)) {
        this->bufferOffset = this->bufferOffset + byteToCopy;
      } else {
        //Release write thread if all the data has been read
        this->writeEvent.Reset();
        this->readEvent.Set();
      }
    } else {
      if (isTimeout)
          throw TimeoutException(pcf_current_information);
      
      //Transfer is finished
      this->finished = true;
      this->readEvent.Set();
      byteToCopy = -1;
    }
  } else {
    //Internal error occur
    this->finished = true;
    this->readEvent.Set();
    byteToCopy = -1;
  }

  return byteToCopy;
}

int32 WebResponse::WebResponseStream::Receive(const void* handle, int32 count) {
  //Wait previous read is finished  
  if (!this->readEvent.WaitOne(ReadTimeout()))
    throw TimeoutException(pcf_current_information);

  if (this->webRequest->internalError != 0)
    return 0;

  if (!this->finished) {
    buffer = const_cast<void*>(handle);
    this->bufferSize = count;
    this->bufferOffset = 0;
    //Unlock Read thread
    this->readEvent.Reset();
    this->writeEvent.Set();

    //Wait end of read
    if (!this->readEvent.WaitOne(ReadTimeout()))
      throw TimeoutException(pcf_current_information);
  }
 
  return count;
}

void WebResponse::WebResponseStream::EndTransfert() {
  this->finished = true;
  this->writeEvent.Set();
  this->readEvent.Set();
}

void WebResponse::WebResponseStream::Close() {  
  if (!IsClosed()) {
    Stream::Close();
    EndTransfert();
    if (this->started)
      this->webRequest->requestThread.Join();
  }
}


