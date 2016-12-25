#include "curl.h"

#include "../../../../../Includes/Pcf/Types.h"

#include <curl/curl.h>

using namespace System::Net;

int32 Curl::Cleanup(void* request) {
  curl_easy_cleanup(request);
  return 0;
}

bool Curl::GetOSSupportsWebOperations() {
  return true;
}

int32 Curl::GetContentDownloadLength(void* request, double* value) {
  return curl_easy_getinfo(request, CURLINFO_CONTENT_LENGTH_DOWNLOAD, value);
}

int32 Curl::GetContentType(void* request, char **value) {
  return curl_easy_getinfo(request, CURLINFO_CONTENT_TYPE, value);
}

int32 Curl::GetResponseCode(void* request, int64 *value) {
  return curl_easy_getinfo(request, CURLINFO_RESPONSE_CODE, value);
}

int32 Curl::GlobalCleanup() {
  curl_global_cleanup();
  return 0;
}

int32 Curl::GlobalInit() {
  return curl_global_init(CURL_GLOBAL_DEFAULT);
}

int32 Curl::Init(void** request) {
  *request = curl_easy_init();
  return 0;
}

int32 Curl::Perform(void* request) {
  return curl_easy_perform(request);
}

int32 Curl::SetCarriageReturnLinefeed(void* request, int32 value) {
  return curl_easy_setopt(request, CURLOPT_CRLF, value);
}

int32 Curl::SetCreateDirectoryIfDirectoryMissing(void* request) {
  return curl_easy_setopt(request, CURLOPT_FTP_CREATE_MISSING_DIRS, CURLFTP_CREATE_DIR);
}

int32 Curl::SetDirectoryListOnly(void* request, int32 value) {
  return curl_easy_setopt(request, CURLOPT_DIRLISTONLY, value);
}

int32 Curl::SetInFileSize(void* request, int64 value) {
  return curl_easy_setopt(request, CURLOPT_INFILESIZE, value);
}

int32 Curl::SetPostFieldSize(void* request, int64 value) {
  //force using read function to get post data
  curl_easy_setopt(request,CURLOPT_POSTFIELDS, null);
  return curl_easy_setopt(request, CURLOPT_POSTFIELDSIZE, value);
}

int32 Curl::SetUrl(void* request, const char *value) {
  return curl_easy_setopt(request, CURLOPT_URL, value);
}

int32 Curl::SetTimeout(void* request, int32 value) {
  //Convert Infinite timeout -1 to 0 in libcurl
  return curl_easy_setopt(request, CURLOPT_TIMEOUT_MS, (value==-1)?0:value);
}

int32 Curl::SetPassword(void* request, const char *value) {
  return curl_easy_setopt(request, CURLOPT_PASSWORD, value);
}

int32 Curl::SetReadData(void* request, void* value) {
  return curl_easy_setopt(request, CURLOPT_READDATA, value);
}

int32 Curl::SetReadFunction(void* request, size_t value(void *buffer, size_t size, size_t nmemb, void *stream)) {
  return curl_easy_setopt(request, CURLOPT_READFUNCTION, value);
}

int32 Curl::SetUserName(void* request, const char *value) {
  return curl_easy_setopt(request, CURLOPT_USERNAME, value);
}

int32 Curl::SetTransfertText(void* request, int32 value) {
  return curl_easy_setopt(request, CURLOPT_TRANSFERTEXT, value);
}

int32 Curl::SetUpload(void* request, int32 value) {
  return curl_easy_setopt(request, CURLOPT_UPLOAD, value);
}

int32 Curl::SetVerbose(void* request, int32 value) {
  return curl_easy_setopt(request, CURLOPT_VERBOSE, value);
}

int32 Curl::SetWriteData(void* request, void* value) {
  return curl_easy_setopt(request, CURLOPT_WRITEDATA, value);
}

int32 Curl::SetWriteFunction(void* request, size_t value(void *buffer, size_t size, size_t nmemb, void *stream)) {
  return curl_easy_setopt(request, CURLOPT_WRITEFUNCTION, value);
}

int32 Curl::SetAllowRedirection(void* request, int32 value) {
  return curl_easy_setopt(request,  CURLOPT_FOLLOWLOCATION, value);
}

int32 Curl::SetHttpPut(void* request, int32 value) {
  return curl_easy_setopt(request,  CURLOPT_PUT, value);
}

int32 Curl::SetHttpPost(void* request, int32 value) {
  return curl_easy_setopt(request,  CURLOPT_POST, value);
}

void* Curl::AppendToList(void* list, const char* value){
  return (void*)curl_slist_append((curl_slist*)list, value);
}

void Curl::FreeList(void* list) {
  if (list != null)
    curl_slist_free_all((curl_slist*)list);
}

int32 Curl::SetHttpHeader(void* request, void* list) {
  return curl_easy_setopt(request,  CURLOPT_HTTPHEADER, (curl_slist*)list);
}
