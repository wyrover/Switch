#if defined(_WIN32)

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <rpc.h>
#include <windows.h>
#include "../../include/Switch/Undef.hpp"

#include "Api.hpp"

static string CreateProcess(const string& command) {
  FILE* fs = _popen(command.Data(), "r");
  string result;
  while(!feof(fs)) {
    char buf[512];
    int32 bufLength = static_cast<int>(fread(buf, 1, 512, fs));
    buf[bufLength] = 0;
    result += buf;
  }
  _pclose(fs);
  return result;
}

System::PlatformID Native::EnvironmentApi::GetOsPlatformID() {
  return System::PlatformID::Win32NT;
}

string Native::EnvironmentApi::NewLine() {
  return "\r\n";
}

int32 Native::EnvironmentApi::GetOsVersion(int32& major, int32& minor, int32& build, int32& revision) {
  string result = CreateProcess("ver");
  System::Array<string> numbers = result.Substring(result.LastIndexOf(" ")).Replace("]", "").Split({ '.', '\n' });
  if(numbers.Length() < 1 || !System::Int32::TryParse(numbers[0], major))
    major = 0;
  if(numbers.Length() < 2 || !System::Int32::TryParse(numbers[1], minor))
    minor = 0;
  if(numbers.Length() < 3 || !System::Int32::TryParse(numbers[2], build))
    build = 0;
  if(numbers.Length() < 4 || !System::Int32::TryParse(numbers[3], revision))
    revision = 0;
  return 0;
}

bool Native::EnvironmentApi::IsOs64Bit() {
  return string(getenv("PROCESSOR_ARCHITECTURE")).EndsWith("64");
}

string Native::EnvironmentApi::GetMachineName() {
  char name[512];
  strcpy_s(name, 512, getenv("COMPUTERNAME"));
  return name;
}

int32 Native::EnvironmentApi::GetTickCount() {
  return ::GetTickCount();
}

string Native::EnvironmentApi::GetUserDomainName() {
  char name[512];
  strcpy_s(name, 512, getenv("USERDOMAIN"));
  return name;
}

string Native::EnvironmentApi::GetUserName() {
  char name[512];
  strcpy(name, getenv("USERNAME"));
  return name;
}

int64 Native::EnvironmentApi::GetWorkingSet() {
  return 0;
}

int32 Native::EnvironmentApi::SetEnv(const string& name, const string& value) {
  return _putenv(string::Format("{0}={1}", name, value).Data);
}

int32 Native::EnvironmentApi::UnsetEnv(const string& name) {
  return _putenv(string::Format("{0}=", name).Data);
}

System::Guid Native::EnvironmentApi::NewGuid() {
  UUID guid;
  UuidCreate(&guid);
  return System::Guid(guid.Data1, guid.Data2, guid.Data3, guid.Data4);
}

#endif
