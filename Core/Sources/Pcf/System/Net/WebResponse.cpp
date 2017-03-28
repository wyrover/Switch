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
  this->responseStream.SetWebRequest(this->webRequest);
}

WebResponse::~WebResponse() {
  this->responseStream.Close();
}

System::Net::WebResponse::WebResponseStream WebResponse::GetResponseStream() {
  return this->responseStream;
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
  this->responseStream.StartTransfert();
}


void WebResponse::EndTransfert() {
  this->responseStream.EndTransfert();
}

int64 WebResponse::GetResponseCode() const {
  if (!Curl::GetOSSupportsWebOperations())
    throw NotSupportedException(pcf_current_information);

  int64 code = 0;
  Curl::GetResponseCode(this->webRequest->GetRequestHandle(), &code);
  return int64(code);
}

void WebResponse::WebResponseStream::SetWebRequest(WebRequest* webRequest) {
  this->data->webRequest = webRequest;
}

void WebResponse::WebResponseStream::StartTransfert() {
  //If the request is not started launch the writing thread
  if (!this->data->started) {
    this->data->started = true;
    //Launch the writing thread
    this->data->writeEvent.Reset();
    this->data->readEvent.Set();
    this->data->webRequest->ProccessRequest();
    //Wait the first response packet
    if (!this->data->writeEvent.WaitOne(this->data->webRequest->Timeout))
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
  bool isTimeout = !this->data->writeEvent.WaitOne(this->data->webRequest->Timeout);
  if (this->data->webRequest->internalError == 0) {
    if (!isTimeout && !this->data->finished) {
      byteToCopy = Math::Min(count, (this->data->bufferSize - this->data->bufferOffset));
      Buffer::BlockCopy(this->data->buffer, this->data->bufferSize, this->data->bufferOffset, handle, count, 0, byteToCopy);

      if (byteToCopy < (this->data->bufferSize - this->data->bufferOffset)) {
        this->data->bufferOffset = this->data->bufferOffset + byteToCopy;
      } else {
        //Release write thread if all the data has been read
        this->data->writeEvent.Reset();
        this->data->readEvent.Set();
      }
    } else {
      if (isTimeout)
          throw TimeoutException(pcf_current_information);
      
      //Transfer is finished
      this->data->finished = true;
      this->data->readEvent.Set();
      byteToCopy = -1;
    }
  } else {
    //Internal error occur
    this->data->finished = true;
    this->data->readEvent.Set();
    byteToCopy = -1;
  }

  return byteToCopy;
}

int32 WebResponse::WebResponseStream::Receive(const void* handle, int32 count) {
  //Wait previous read is finished  
  if (!this->data->readEvent.WaitOne(ReadTimeout()))
    throw TimeoutException(pcf_current_information);

  if (this->data->webRequest->internalError != 0)
    return 0;

  if (!this->data->finished) {
    this->data->buffer = const_cast<void*>(handle);
    this->data->bufferSize = count;
    this->data->bufferOffset = 0;
    //Unlock Read thread
    this->data->readEvent.Reset();
    this->data->writeEvent.Set();

    //Wait end of read
    if (!this->data->readEvent.WaitOne(ReadTimeout()))
      throw TimeoutException(pcf_current_information);
  }
 
  return count;
}

void WebResponse::WebResponseStream::EndTransfert() {
  this->data->finished = true;
  this->data->writeEvent.Set();
  this->data->readEvent.Set();
}

void WebResponse::WebResponseStream::Close() {  
  if (!IsClosed()) {
    Stream::Close();
    EndTransfert();
    if (this->data->started)
      this->data->webRequest->requestThread.Join();
  }
}


