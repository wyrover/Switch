#if _WIN32

#include <Windows.h>
#include "CoreApi.h"

intptr __OS::CoreApi::Process::Create(const string& fileName, const string& arguments) {
  intptr child = 0;
  return child;
}

intptr __OS::CoreApi::Process::CreateShell(const string& fileName, const string& arguments) {
  return (intptr)_popen(string::Format("\"\"{0}\"{1}{2}\"", fileName, string::IsNullOrEmpty(arguments) ? "" : " ", arguments).Data, "r");
}

bool __OS::CoreApi::Process::Destroy(intptr handle) {
  return false;
}

int32 __OS::CoreApi::Process::DestroyShell(intptr handle) {
  return _pclose((FILE*)handle);
}

intptr __OS::CoreApi::Process::GetCurrent() {
  return (intptr)GetCurrentProcess();
}

bool __OS::CoreApi::Process::WaitEnd(intptr handle, int32& exitCode) {
  return false;
}

bool __OS::CoreApi::Process::WaitEnd(intptr handle, int32 timeout, int32& exitCode) {
  return false;
}

#endif
