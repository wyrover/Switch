#pragma once

#include <Switch/Types.hpp>
#include <Switch/System/String.hpp>

namespace Switch {
  namespace System {
    namespace Net {
      class Curl {
      public:
        static int32 Cleanup(intptr request);

        static bool GetOSSupportsWebOperations();
        static int32 GetContentDownloadLength(intptr request, double& value);
        static int32 GetContentType(intptr request, string& value);
        static int32 GetResponseCode(intptr request, int64& value);
        
        static int32 GlobalCleanup();
        static int32 GlobalInit();
        static int32 Init(intptr& request);
        static int32 Perform(intptr request);
        
        static int32 SetCarriageReturnLinefeed(intptr request, int32 value);
        static int32 SetCreateDirectoryIfDirectoryMissing(intptr request);
        static int32 SetDirectoryListOnly(intptr request, int32 value);
        static int32 SetInFileSize(intptr request, int64 value);
        static int32 SetPostFieldSize(intptr request, int64 value);
        static int32 SetUrl(intptr request, const string& value);
        static int32 SetUserName(intptr request, const string& value);
        static int32 SetPassword(intptr request, const string& value);
        static int32 SetReadData(intptr request, void* value);
        static int32 SetReadFunction(intptr request, size_t value(void *buffer, size_t size, size_t nmemb, void *stream));
        static int32 SetTransfertText(intptr request, int32 value);
        static int32 SetTimeout(intptr request, int32 value);
        static int32 SetUpload(intptr request, int32 value);
        static int32 SetVerbose(intptr request, int32 value);
        static int32 SetWriteData(intptr request, void* value);
        static int32 SetWriteFunction(intptr request, size_t value(void *buffer, size_t size, size_t nmemb, void *stream));
        static int32 SetAllowRedirection(intptr request, int32 value);
        static int32 SetHttpPut(intptr request, int32 value);
        static int32 SetHttpPost(intptr request, int32 value);
        static intptr AppendToList(intptr list, const string& value);
        static void FreeList(intptr list);
        static int32 SetHttpHeader(intptr request, intptr list);
      };
    }
  }
}

using namespace Switch; 
