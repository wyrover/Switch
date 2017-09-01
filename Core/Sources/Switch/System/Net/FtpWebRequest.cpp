#include "../../../../Includes/Switch/System/Net/FtpWebRequest.hpp"
#include "../../../../Includes/Switch/System/Net/WebRequestMethods.hpp"
#include "Internals/curl.hpp"

using namespace System;
using namespace System::Net;

FtpWebRequest::FtpWebRequest(const string& uri): WebRequest(uri) {
  this->ftpWebResponse.SetWebRequest(*this);
  SetUseBinary(true);
}

FtpWebRequest::FtpWebRequest(const Uri& uri): WebRequest(uri) {
  this->ftpWebResponse.SetWebRequest(*this);
  SetUseBinary(true);
}

WebRequest::WebRequestStream FtpWebRequest::GetRequestStream() {
  if (GetMethod()==WebRequestMethods::Ftp::UploadFile)
    return WebRequest::GetRequestStream();

  throw InvalidOperationException(_current_information);
}

void FtpWebRequest::SetUseBinary(bool useBinary) {
  if (Curl::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(_current_information);

  this->useBinary = useBinary;

  if (useBinary) {
    Curl::SetTransfertText(this->requestHandle, 0L);
    Curl::SetCarriageReturnLinefeed(this->requestHandle, 0L);
  }
  else
    Curl::SetTransfertText(this->requestHandle, 1L);
}

bool FtpWebRequest::GetUseBinary() {
  return this->useBinary;
}

void FtpWebRequest::ProcessMakeDirectory() {
  if (Curl::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(_current_information);

  Curl::SetCreateDirectoryIfDirectoryMissing(this->requestHandle);
  this->internalError = Curl::Perform(this->requestHandle);
}

void FtpWebRequest::ProcessListDirectory() {
  if (Curl::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(_current_information);

  Curl::SetDirectoryListOnly(this->requestHandle, 1L);
}

void FtpWebRequest::ProcessListDirectoryDetails() {
  if (Curl::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(_current_information);
}

WebResponse& FtpWebRequest::GetInternalResponse() {
    return this->ftpWebResponse;
}

WebResponse& FtpWebRequest::GetResponse() {
  if (GetMethod()==WebRequestMethods::Ftp::MakeDirectory) {
    //No stream needed to process the request
    ProcessMakeDirectory();
  }
  else if (GetMethod()==WebRequestMethods::Ftp::ListDirectory) {
    //A reponse stream is needed
    ProcessListDirectory();
  }
  else if (GetMethod()==WebRequestMethods::Ftp::ListDirectoryDetails) {
    //A reponse stream is needed
    ProcessListDirectoryDetails();
  }
  if (IsResponseStreamNeeded())
    this->ftpWebResponse.StartTransfert();
  return this->ftpWebResponse;
}

void FtpWebRequest::Finished(int32 error) {
  WebRequest::Finished(error);
}

