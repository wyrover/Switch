#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <thread>

#include "../../../Includes/Pcf/System/Environment.h"
#include "../../../Includes/Pcf/System/SystemVersion.h"
#include "../../../Includes/Pcf/System/IO/Directory.h"
#include "../../../Includes/Pcf/System/IO/DirectoryNotFoundException.h"
#include "../../../Includes/Pcf/System/Diagnostics/StackTrace.h"
#include "../../../Includes/Pcf/System/Threading/Thread.h"
#include "../Os/Directory.h"
#include "../Os/Drive.h"
#include "../Os/Information.h"

#if _WIN32
#pragma warning(push)
#pragma warning(disable:4459)
#endif

using namespace System;
using namespace System::Collections::Generic;

extern char** environ;

namespace {
#if WIN32
  int setenv(const char name[], const char value[], int overwrite) {
    return _putenv(String::Format("{0}={1}", name, value).Data());
  }

  int unsetenv(const char *name) {
    return _putenv(String::Format("{0}=", name).Data());
  }
#endif
  
  Collections::Specialized::StringDictionary GetEnvironmentVariables() {
    Collections::Specialized::StringDictionary envs;
    for (int32 index = 0; environ[index] != null; index++) {
      System::Array<string> keyValue = string(environ[index]).Split('=');
      envs[keyValue[0]] = keyValue[1];
    }
    return envs;
  };

  System::Array<String> commandLineArgs;
  Collections::Specialized::StringDictionary environmentVariables = GetEnvironmentVariables();
  int32 exitCode;
}

#if !PATH_MAX
const int32 PATH_MAX = 1024;
#endif

Property<String, ReadOnly> Environment::CommandLine {
  [] {
    if (commandLineArgs.Length == 0)
      throw InvalidOperationException("You must call Environment::SetCommandLineArgs() method in main before.", pcf_current_information);
      
    string commandLine = commandLineArgs[0];
    for (int i = 1; i < commandLineArgs.Length; i++)
      commandLine += " " + (commandLineArgs[i].Contains(" ") ? string::Format("\"{0}\"", commandLineArgs[i]) : commandLineArgs[i]);
    return commandLine;
  }
};

Property<string> Environment::CurrentDirectory {
  [] {return Os::Directory::GetCurrentDirectory();},
  [](string value) {
    if (String::IsNullOrEmpty(value))
      throw ArgumentException(pcf_current_information);
    if (!System::IO::Directory::Exists(value))
      throw IO::DirectoryNotFoundException(pcf_current_information);
    if (Os::Directory::SetCurrentDirectory(value) != 0)
      throw IO::IOException(pcf_current_information);
  }
};

Property<int32, ReadOnly> Environment::CurrentManagedThreadId {
  [] {return System::Threading::Thread::CurrentThread().ManagedThreadId();}
};

Property<int32> Environment::ExitCode {
  [] {return exitCode;},
  [](int32 value) {exitCode = value;}
};

Property<bool, ReadOnly> Environment::HasShutdownStarted {
  [] {return false;}
};

Property<bool, ReadOnly> Environment::Is64BitOperatingSystem {
  [] {return Pcf::Os::Information::IsOs64Bit();}
};

Property<bool, ReadOnly> Environment::Is64BitProcess {
  [] {return IntPtr::Size == 8;}
};

Property<String, ReadOnly> Environment::MachineName {
  [] {return Pcf::Os::Information::GetMachineName();}
};

Property<String, ReadOnly> Environment::NewLine {
  [] {return Os::Information::NewLine();}
};

Property<const OperatingSystem&, ReadOnly> Environment::OSVersion {
  []()->const OperatingSystem& {
    static OperatingSystem os(PlatformID::Unknown, System::Version());
    if (os.Platform == PlatformID::Unknown) {
      int32 major, minor, build, revision;
      Pcf::Os::Information::GetOsVersion(major, minor, build, revision);
      os = OperatingSystem(Os::Information::GetOsPlatformID(), System::Version(major, minor, build, revision));
    }
    return os;
  }
};

Property<int32, ReadOnly> Environment::ProcessorCount {
  [] {
    static int32 processorCount = as<int32>(std::thread::hardware_concurrency());
    return processorCount;
  }
};

Property<String, ReadOnly> Environment::StackTrace {
  [] {return Diagnostics::StackTrace(true).ToString();}
};

Property<String, ReadOnly> Environment::SystemDirectory {
  [] {return GetFolderPath(Environment::SpecialFolder::System);}
};

Property<int32, ReadOnly> Environment::TickCount {
  [] {return Pcf::Os::Information::GetTickCount();}
};

Property<String, ReadOnly> Environment::UserDomainName {
  [] {return Pcf::Os::Information::GetUserDomainName();}
};

Property<bool, ReadOnly> Environment::UserInteractive {
  [] {return Pcf::Os::Information::GetUserInteractive();}
};

Property<String, ReadOnly> Environment::UserName {
  [] {return Pcf::Os::Information::GetUserName();}
};

Property<const System::Version&, ReadOnly> Environment::Version {
  []()->const System::Version& {return Pcf::GetVersion();}
};

Property<int64, ReadOnly> Environment::WorkingSet {
  [] {return Pcf::Os::Information::GetWorkingSet();}
};

void Environment::Exit(int32 exitCode) {
  exit(exitCode);
}

String Environment::ExpandEnvironmentVariables(const String& name) {
  string buffer = name;
  string result;
  
  int32 index = buffer.IndexOf('%');
  while (index != -1 && buffer.IndexOf('%', index+1) != -1) {
    result += buffer.Substring(0, index);
    buffer = buffer.Remove(0, index+1);
    index = buffer.IndexOf('%');
    if (Environment::GetEnvironmentVariable(buffer.Substring(0, index)) != "")
      result += Environment::GetEnvironmentVariable(buffer.Substring(0, index));
    else
      result += string::Format("%{0}%", buffer.Substring(0, index));
    buffer = buffer.Remove(0, index+1);
    index = buffer.IndexOf('%');
  }
  result += buffer;
  return result;
}

const Array<String>& Environment::GetCommandLineArgs() {
  return commandLineArgs;
}

String Environment::GetEnvironmentVariable(const String& variable) {
  char* value = getenv(variable.Data());
  
  if (value == null)
    return "";
  
  return value;
}

const Collections::Generic::IDictionary<String, String>& Environment::GetEnvironmentVariables() {
  return environmentVariables;
}

String Environment::GetFolderPath(Environment::SpecialFolder folder) {
  return Os::Directory::GetKnowFolderPath(folder);
}

Array<String> Environment::GetLogicalDrives() {
  return Os::Drive::GetDrives();
}

void Environment::SetEnvironmentVariable(const String& name, const String& value) {
  if (name.IsEmpty())
    throw ArgumentException(pcf_current_information);
  
  if (value.IsEmpty()) {
    environmentVariables.Remove(name);
    if (unsetenv(name.Data()) != 0)
      throw ArgumentException(pcf_current_information);
  } else {
    environmentVariables[name] = value;
    if (setenv(name.Data(), value.Data(), 1) != 0)
      throw ArgumentException(pcf_current_information);
  }
}

Array<string> Environment::SetCommandLineArgs(char* argv[], int argc) {
  if (commandLineArgs.Length != 0)
    throw InvalidOperationException("Can be called only once", pcf_current_information);
  
  System::Threading::Thread::RegisterCurrentThread();
  commandLineArgs = Array<string>(std::vector<string>(argv, argv+argc));
  return Array<string>(std::vector<string>(argv+1, argv+argc));
}

#if _WIN32
#pragma warning(pop)
#endif

