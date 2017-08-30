#include "curl.hpp"

#include "../../../../../Includes/Pcf/Types.hpp"

#include <curl/curl.h>

using namespace System::Net;

int32 Curl::Cleanup(intptr request) {
  curl_easy_cleanup((CURL*)request);
  return 0;
}

bool Curl::GetOSSupportsWebOperations() {
  return true;
}

int32 Curl::GetContentDownloadLength(intptr request, double& value) {
  return curl_easy_getinfo((CURL*)request, CURLINFO_CONTENT_LENGTH_DOWNLOAD, value);
}

int32 Curl::GetContentType(intptr request, string& value) {
  char* str;
  int32 result = curl_easy_getinfo((CURL*)request, CURLINFO_CONTENT_TYPE, &str);
  if (result == 0 && str != null)
    value = str;
  return result;
}

int32 Curl::GetResponseCode(intptr request, int64& value) {
  return curl_easy_getinfo((CURL*)request, CURLINFO_RESPONSE_CODE, &value);
}

int32 Curl::GlobalCleanup() {
  curl_global_cleanup();
  return 0;
}

int32 Curl::GlobalInit() {
  return curl_global_init(CURL_GLOBAL_DEFAULT);
}

int32 Curl::Init(intptr& request) {
  request = (intptr)curl_easy_init();
  return 0;
}

int32 Curl::Perform(intptr request) {
  return curl_easy_perform((CURL*)request);
}

int32 Curl::SetCarriageReturnLinefeed(intptr request, int32 value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_CRLF, value);
}

int32 Curl::SetCreateDirectoryIfDirectoryMissing(intptr request) {
  return curl_easy_setopt((CURL*)request, CURLOPT_FTP_CREATE_MISSING_DIRS, CURLFTP_CREATE_DIR);
}

int32 Curl::SetDirectoryListOnly(intptr request, int32 value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_DIRLISTONLY, value);
}

int32 Curl::SetInFileSize(intptr request, int64 value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_INFILESIZE, value);
}

int32 Curl::SetPostFieldSize(intptr request, int64 value) {
  //force using read function to get post data
  curl_easy_setopt((CURL*)request,CURLOPT_POSTFIELDS, null);
  return curl_easy_setopt((CURL*)request, CURLOPT_POSTFIELDSIZE, value);
}

int32 Curl::SetUrl(intptr request, const string& value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_URL, value.c_str());
}

int32 Curl::SetTimeout(intptr request, int32 value) {
  //Convert Infinite timeout -1 to 0 in libcurl
  return curl_easy_setopt((CURL*)request, CURLOPT_TIMEOUT_MS, (value==-1)?0:value);
}

int32 Curl::SetPassword(intptr request, const string& value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_PASSWORD, value.c_str());
}

int32 Curl::SetReadData(intptr request, void* value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_READDATA, value);
}

int32 Curl::SetReadFunction(intptr request, size_t value(void *buffer, size_t size, size_t nmemb, void *stream)) {
  return curl_easy_setopt((CURL*)request, CURLOPT_READFUNCTION, value);
}

int32 Curl::SetUserName(intptr request, const string& value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_USERNAME, value.c_str());
}

int32 Curl::SetTransfertText(intptr request, int32 value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_TRANSFERTEXT, value);
}

int32 Curl::SetUpload(intptr request, int32 value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_UPLOAD, value);
}

int32 Curl::SetVerbose(intptr request, int32 value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_VERBOSE, value);
}

int32 Curl::SetWriteData(intptr request, void* value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_WRITEDATA, value);
}

int32 Curl::SetWriteFunction(intptr request, size_t value(void *buffer, size_t size, size_t nmemb, void *stream)) {
  return curl_easy_setopt((CURL*)request, CURLOPT_WRITEFUNCTION, value);
}

int32 Curl::SetAllowRedirection(intptr request, int32 value) {
  return curl_easy_setopt((CURL*)request,  CURLOPT_FOLLOWLOCATION, value);
}

int32 Curl::SetHttpPut(intptr request, int32 value) {
  return curl_easy_setopt((CURL*)request,  CURLOPT_PUT, value);
}

int32 Curl::SetHttpPost(intptr request, int32 value) {
  return curl_easy_setopt((CURL*)request,  CURLOPT_POST, value);
}

intptr Curl::AppendToList(intptr list, const string& value){
  return (intptr)curl_slist_append((curl_slist*)list, value.c_str());
}

void Curl::FreeList(intptr list) {
  if (list != IntPtr::Zero)
    curl_slist_free_all((curl_slist*)list);
}

int32 Curl::SetHttpHeader(intptr request, intptr list) {
  return curl_easy_setopt((CURL*)request,  CURLOPT_HTTPHEADER, (curl_slist*)list);
}
