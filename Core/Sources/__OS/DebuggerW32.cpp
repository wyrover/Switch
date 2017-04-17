#if defined(_WIN32)

#include <windows.h>
#include "../../Includes/Pcf/Undef.h"

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
