#if _WIN32

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <Windows.h>

#include "../Information.h"
#include "../../../../Includes/Pcf/Types.h"
#include "../../../../Includes/Pcf/System/Environment.h"

using namespace Os;

static string CreateProcess(const string& command) {
  FILE* fs = _popen(command.Data(), "r");
  string result;
  while (!feof(fs)) {
    char buf[512];
    int32 bufLength = static_cast<int>(fread(buf, 1, 512, fs));
    buf[bufLength] = 0;
    result += buf;
  }
  _pclose(fs);
  return result;
}

System::PlatformID Information::GetOsPlatformID() {
  return System::PlatformID::Win32NT;
}

string Information::NewLine() {
  return "\r\n";
}

int32 Information::GetOsVersion(int32& major, int32& minor, int32& build, int32& revision) {
  string result = CreateProcess("ver");
  System::Array<string> numbers = result.Substring(result.LastIndexOf(" ")).Replace("]", "").Split({ '.', '\n' });
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

bool Information::IsOs64Bit() {
  return string(getenv("PROCESSOR_ARCHITECTURE")).EndsWith("64");
}

string Information::GetMachineName() {
  char name[512];
  strcpy_s(name, 512, getenv("COMPUTERNAME"));
  return name;
}

int32 Information::GetTickCount() {
  return ::GetTickCount();
}

string Information::GetUserDomainName() {
  char name[512];
  strcpy_s(name, 512, getenv("USERDOMAIN"));
  return name;
}

bool Information::GetUserInteractive() {
  return false;
}

string Information::GetUserName() {
  char name[512];
  strcpy(name, getenv("USERNAME"));
  return name;
}

int64 Information::GetWorkingSet() {
  return 0;
}

#endif
