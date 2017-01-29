#if _WIN32

#pragma warning(push)
#pragma warning(disable: 4201)
#include <windows.h>
#pragma warning(pop)

#include "CoreApi.h"

void __OS::CoreApi::Debugger::Log(int32 level, const string& category, const string &message) {
  if (category.IsEmpty())
    OutputDebugStringA(message.Data);
  else {
    OutputDebugStringA(category.Data);
    OutputDebugStringA(": ");
    OutputDebugStringA(message.Data);
  }
}

#endif
