#if defined(_WIN32)

#define UNICODE

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <windows.h>
#include "../../include/Switch/Undef.hpp"

#include "Api.hpp"

System::PlatformID Native::EnvironmentApi::GetOsPlatformID() {
  return System::PlatformID::Win32NT;
}

string Native::EnvironmentApi::NewLine() {
  return "\r\n";
}

int32 Native::EnvironmentApi::GetOsVersion(int32& major, int32& minor, int32& build, int32& revision) {
#pragma warning(push)
#pragma warning(disable : 4996)
  OSVERSIONINFOEX versionInfo;
  ZeroMemory(&versionInfo, sizeof(OSVERSIONINFOEX));
  versionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
  if (GetVersionEx((LPOSVERSIONINFO)&versionInfo)) {
    major = versionInfo.dwMajorVersion;
    minor = versionInfo.dwMinorVersion;
    build = versionInfo.dwBuildNumber;
    revision = versionInfo.wServicePackMajor << 16;
  }
#pragma warning(pop)
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
