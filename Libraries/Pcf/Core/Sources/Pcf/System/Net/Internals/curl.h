#pragma once

#include "../../../../../Includes/Pcf/Types.h"

/// @cond
namespace Pcf {
  namespace System {
    namespace Net {
      class Curl {
      public:
        static int32 Cleanup(void* request);

        static bool GetOSSupportsWebOperations();
        static int32 GetContentDownloadLength(void* request, double* value);
        static int32 GetContentType(void* request, char** value);
        static int32 GetResponseCode(void* request, int64* value);
        
        static int32 GlobalCleanup();
        static int32 GlobalInit();
        static int32 Init(void** request);
        static int32 Perform(void* request);
        
        static int32 SetCarriageReturnLinefeed(void* request, int32 value);
        static int32 SetCreateDirectoryIfDirectoryMissing(void* request);
        static int32 SetDirectoryListOnly(void* request, int32 value);
        static int32 SetInFileSize(void* request, int64 value);
        static int32 SetPostFieldSize(void* request, int64 value);
        static int32 SetUrl(void* request, const char* value);
        static int32 SetUserName(void* request, const char* value);
        static int32 SetPassword(void* request, const char* value);
        static int32 SetReadData(void* request, void* value);
        static int32 SetReadFunction(void* request, size_t value(void *buffer, size_t size, size_t nmemb, void *stream));
        static int32 SetTransfertText(void* request, int32 value);
        static int32 SetTimeout(void* request, int32 value);
        static int32 SetUpload(void* request, int32 value);
        static int32 SetVerbose(void* request, int32 value);
        static int32 SetWriteData(void* request, void* value);
        static int32 SetWriteFunction(void* request, size_t value(void *buffer, size_t size, size_t nmemb, void *stream));
        static int32 SetAllowRedirection(void* request, int32 value);
        static int32 SetHttpPut(void* request, int32 value);
        static int32 SetHttpPost(void* request, int32 value);
        static void* AppendToList(void* list, const char* value);
        static void FreeList(void* list);
        static int32 SetHttpHeader(void* request, void* list);
      };
    }
  }
}
using namespace Pcf; 
/// @endcond
