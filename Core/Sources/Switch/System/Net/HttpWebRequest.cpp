#include "../../../../Includes/Switch/System/Net/HttpWebRequest.hpp"
#include "../../../../Includes/Switch/System/Net/WebRequestMethods.hpp"
#include "Internals/curl.hpp"

using namespace System;
using namespace System::Net;

HttpWebRequest::HttpWebRequest(const string& uri): WebRequest(uri) {
  this->httpWebResponse.SetWebRequest(*this);
  this->method = WebRequestMethods::Http::Get;
}

HttpWebRequest::HttpWebRequest(const Uri& uri): WebRequest(uri) {
  this->httpWebResponse.SetWebRequest(*this);
  this->method = WebRequestMethods::Http::Get;
}

HttpWebRequest::~HttpWebRequest() {
  Curl::FreeList(this->header);
}

WebRequest::WebRequestStream HttpWebRequest::GetRequestStream() {
  if (!this->contentType.IsEmpty()) {
    string contentType = string::Format("Content-Type: {0}", this->contentType);
    this->header = Curl::AppendToList(this->header, contentType);
    Curl::SetHttpHeader(this->requestHandle, this->header);
  }
  
  if (GetMethod() == WebRequestMethods::Http::Put) {
    Curl::SetHttpPut(this->requestHandle, 1L);
    return WebRequest::GetRequestStream();
  }
  
  if (GetMethod() == WebRequestMethods::Http::Post) {
    Curl::SetHttpPost(this->requestHandle,1L);
    return WebRequest::GetRequestStream();
  }

  throw InvalidOperationException(pcf_current_information);
}

WebResponse& HttpWebRequest::GetInternalResponse() {
  return this->httpWebResponse;
}

WebResponse& HttpWebRequest::GetResponse() {
  if (IsResponseStreamNeeded())
    this->httpWebResponse.StartTransfert();
  
  return this->httpWebResponse;
}

void HttpWebRequest::Finished(int32 error) {
  WebRequest::Finished(error);
}

bool HttpWebRequest::GetAllowAutoRedirect() const {
  if (Curl::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(pcf_current_information);
  
  return this->allowAutoRedirect;
}

void HttpWebRequest::SetAllowAutoRedirect(bool autoRedirect) {
  if (Curl::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(pcf_current_information);
  
  this->allowAutoRedirect = autoRedirect;
  Curl::SetAllowRedirection(this->requestHandle, this->allowAutoRedirect? 1L : 0L);
}

const string& HttpWebRequest::GetContentType() const {
  if (Curl::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(pcf_current_information);
  
  return this->contentType;
}

void HttpWebRequest::SetContentType(const string& contentType) {
  if (Curl::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(pcf_current_information);
  
  this->contentType = contentType;
}
