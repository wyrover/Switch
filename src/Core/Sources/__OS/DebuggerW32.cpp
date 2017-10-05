#if defined(_WIN32)

#include <windows.h>
#include "../../Includes/Switch/Undef.hpp"

#include "CoreApi.hpp"

void __OS::CoreApi::Debugger::Log(int32 level, const string& category, const string &message) {
  if (string::IsNullOrEmpty(category))
    OutputDebugStringA(message.Data);
  else {
    OutputDebugStringA(category.Data);
    OutputDebugStringA(": ");
    OutputDebugStringA(message.Data);
  }
}

#endif
