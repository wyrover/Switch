#if __linux__ || __APPLE__

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <time.h>
#include <sys/time.h>

#include "CoreApi.h"
#include "../../Includes/Pcf/UniquePointer.h"

namespace {
  static string CreateProcess(const string& command) {
    FILE* fs = popen(command.Data(), "r");
    string result;
    while (!feof(fs)) {
      char buf[512];
      int32 l = (int32)fread(buf, 1, 512, fs);
      buf[l] = 0;
      result += buf;
    }
    pclose(fs);
    return result;
  }
}

string __OS::CoreApi::Environment::NewLine() {
  return "\n";
}

System::PlatformID __OS::CoreApi::Environment::GetOsPlatformID() {
#if __APPLE__
  return System::PlatformID::MacOSX;
#else
  return System::PlatformID::Unix;
#endif
}

int32 __OS::CoreApi::Environment::GetOsVersion(int32& major, int32& minor, int32& build, int32& revision) {
#if __APPLE__
  System::Array<string> numbers = CreateProcess("sw_vers -productVersion").Split({'.', '\n'});
#else
  System::Array<string> numbers = CreateProcess("uname -r").Split({'.', '-', '\n'});
#endif
  if (numbers.Length() < 1 || !System::Int32::TryParse(numbers[0], major))
    major = 0;
  if (numbers.Length() < 2 || !System::Int32::TryParse(numbers[1], minor))
    minor = 0;
  if (numbers.Length() < 3 || !System::Int32::TryParse(numbers[2], build))
    build = 0;
  if (numbers.Length() < 4 || !System::Int32::TryParse(numbers[3], revision))
    revision = 0;
  return 0;
}

bool __OS::CoreApi::Environment::IsOs64Bit() {
  return CreateProcess("uname -m").EndsWith("64");
}

string __OS::CoreApi::Environment::GetMachineName() {
  return CreateProcess("uname -n");
}

int32 __OS::CoreApi::Environment::GetTickCount() {
  struct timeval tv;
  if(gettimeofday(&tv, null) != 0)
    return 0;
  return int32((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

string __OS::CoreApi::Environment::GetUserDomainName() {
  return CreateProcess("uname -n");
}

bool __OS::CoreApi::Environment::GetUserInteractive() {
  return false;
}

string __OS::CoreApi::Environment::GetUserName() {
  char name[512];
  strcpy(name, getenv("USER"));
  return name;
}

int64 __OS::CoreApi::Environment::GetWorkingSet() {
  return 0;
}

int32 __OS::CoreApi::Environment::SetEnv(const string& name, const string& value) {
  return setenv(name.Data, value.Data, 1);
}

int32 __OS::CoreApi::Environment::UnsetEnv(const string& name) {
  return unsetenv(name.Data);
}

#endif
