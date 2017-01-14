#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <thread>

#include "../../../Includes/Pcf/System/AccessViolationException.h"
#include "../../../Includes/Pcf/System/Console.h"
#include "../../../Includes/Pcf/System/Environment.h"
#include "../../../Includes/Pcf/System/SystemVersion.h"
#include "../../../Includes/Pcf/System/IO/Directory.h"
#include "../../../Includes/Pcf/System/IO/DirectoryNotFoundException.h"
#include "../../../Includes/Pcf/System/Diagnostics/StackTrace.h"
#include "../../../Includes/Pcf/System/SystemException.h"
#include "../../../Includes/Pcf/System/Threading/Thread.h"
#include "../../../Includes/Pcf/System/Threading/AbandonedMutexException.h"
#include "../../__OS/CoreApi.h"

using namespace System;
using namespace System::Collections::Generic;

extern char** environ;

namespace {
  class ConsoleChangeCodePage {
  public:
    ConsoleChangeCodePage() {
      __OS::CoreApi::Console::SetInputCodePage(65001);
      __OS::CoreApi::Console::SetOutputCodePage(65001);
    }
    
    ~ConsoleChangeCodePage() {
      __OS::CoreApi::Console::SetInputCodePage(previousInputCodePage);
      __OS::CoreApi::Console::SetOutputCodePage(previousOutputCodePage);
    }
    
  private:
    int32 previousInputCodePage = __OS::CoreApi::Console::GetInputCodePage();
    int32 previousOutputCodePage = __OS::CoreApi::Console::GetOutputCodePage();
  };
  
  class ConsoleInterceptSignals {
  public:
    ConsoleInterceptSignals() {
      auto signalKeys =__OS::CoreApi::Console::GetSignalKeys();
      for(auto signal : signalKeys)
        ::signal(signal.Key, ConsoleInterceptSignals::SignalHandler);
    }
    
    ~ConsoleInterceptSignals() {
      auto signalKeys =__OS::CoreApi::Console::GetSignalKeys();
      for(auto signal : signalKeys)
        ::signal(signal.Key, SIG_DFL);
    }
    
  private:
    static void SignalHandler(int32 signal) {
      static auto signalKeys =__OS::CoreApi::Console::GetSignalKeys();
      ::signal(signal, ConsoleInterceptSignals::SignalHandler);
      System::ConsoleCancelEventArgs consoleCancel = System::ConsoleCancelEventArgs(false, signalKeys[signal]);
      System::Console::CancelKeyPress(Reference<object>::Null(), consoleCancel);
      if (consoleCancel.Cancel == false)
        Environment::Exit(-1);
    }
  };
  
  class SignalCatcher {
  public:
    SignalCatcher() {
      signal(SIGILL, SignalCatcher::SignalIllegalInstructionHandler);
      signal(SIGABRT, SignalCatcher::SignalAbortExceptionHandler);
      signal(SIGFPE, SignalCatcher::SignalFloatingPointExceptionHandler);
      signal(SIGSEGV, SignalCatcher::SignalSegmentationViolationHandler);
    }
    
    ~SignalCatcher() {
      signal(SIGILL, SIG_DFL);
      signal(SIGABRT, SIG_DFL);
      signal(SIGFPE, SIG_DFL);
      signal(SIGSEGV, SIG_DFL);
    }
    
    static void SignalIllegalInstructionHandler(int32 signal) {
      ::signal(signal, SignalCatcher::SignalIllegalInstructionHandler);
      throw System::InvalidOperationException(pcf_current_information);
    }
    
    static void SignalAbortExceptionHandler(int32 signal) {
      ::signal(signal, SignalCatcher::SignalAbortExceptionHandler);
      //throw System::Threading::ThreadAbortException(pcf_current_information);
      exit(-1);
    }
    
    static void SignalFloatingPointExceptionHandler(int32 signal) {
      ::signal(signal, SignalCatcher::SignalFloatingPointExceptionHandler);
      throw System::ArithmeticException(pcf_current_information);
    }
    
    static void SignalSegmentationViolationHandler(int32 signal) {
      ::signal(signal, SignalCatcher::SignalSegmentationViolationHandler);
      throw System::AccessViolationException(pcf_current_information);
    }
  };

  Collections::Specialized::StringDictionary GetEnvironmentVariables() {
    Collections::Specialized::StringDictionary envs;
    for (int32 index = 0; environ[index] != null; index++) {
      System::Array<string> keyValue = string(environ[index]).Split('=');
      envs[keyValue[0]] = keyValue[1];
    }
    return envs;
  }

  Property<Collections::Specialized::StringDictionary&, ReadOnly> EnvironmentVariables {
    []()->Collections::Specialized::StringDictionary& {
      static Collections::Specialized::StringDictionary environmentVariables = GetEnvironmentVariables();
      return environmentVariables;
    }
  };
  
  int32 exitCode;
  UniquePointer<System::Array<String>> commandLineArgs;
  UniquePointer<ConsoleChangeCodePage> consoleChangeCodePage;
  UniquePointer<ConsoleInterceptSignals> consoleInterceptSignals;
  UniquePointer<SignalCatcher> signalCatcher;
}

Property<String, ReadOnly> Environment::CommandLine {
  [] {
    if (commandLineArgs->Length == 0)
      throw InvalidOperationException("You must call Environment::SetCommandLineArgs() method in main before.", pcf_current_information);
      
    string commandLine = commandLineArgs.ToObject()[0];
    for (int i = 1; i < commandLineArgs->Length; i++)
      commandLine += " " + (commandLineArgs.ToObject()[i].Contains(" ") ? string::Format("\"{0}\"", commandLineArgs.ToObject()[i]) : commandLineArgs.ToObject()[i]);
    return commandLine;
  }
};

Property<string> Environment::CurrentDirectory {
  [] {return __OS::CoreApi::Directory::GetCurrentDirectory();},
  [](string value) {
    if (String::IsNullOrEmpty(value))
      throw ArgumentException(pcf_current_information);
    if (!System::IO::Directory::Exists(value))
      throw IO::DirectoryNotFoundException(pcf_current_information);
    if (__OS::CoreApi::Directory::SetCurrentDirectory(value) != 0)
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
  [] {return __OS::CoreApi::Environment::IsOs64Bit();}
};

Property<bool, ReadOnly> Environment::Is64BitProcess {
  [] {return IntPtr::Size == 8;}
};

Property<String, ReadOnly> Environment::MachineName {
  [] {return __OS::CoreApi::Environment::GetMachineName();}
};

Property<String, ReadOnly> Environment::NewLine {
  [] {return __OS::CoreApi::Environment::NewLine();}
};

Property<const OperatingSystem&, ReadOnly> Environment::OSVersion {
  []()->const OperatingSystem& {
    static OperatingSystem os(PlatformID::Unknown, System::Version());
    if (os.Platform == PlatformID::Unknown) {
      int32 major, minor, build, revision;
      __OS::CoreApi::Environment::GetOsVersion(major, minor, build, revision);
      os = OperatingSystem(__OS::CoreApi::Environment::GetOsPlatformID(), System::Version(major, minor, build, revision));
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
  [] {return __OS::CoreApi::Environment::GetTickCount();}
};

Property<String, ReadOnly> Environment::UserDomainName {
  [] {return __OS::CoreApi::Environment::GetUserDomainName();}
};

Property<bool, ReadOnly> Environment::UserInteractive {
  [] {return __OS::CoreApi::Environment::GetUserInteractive();}
};

Property<String, ReadOnly> Environment::UserName {
  [] {return __OS::CoreApi::Environment::GetUserName();}
};

Property<const System::Version&, ReadOnly> Environment::Version {
  []()->const System::Version& {return Pcf::GetVersion();}
};

Property<int64, ReadOnly> Environment::WorkingSet {
  [] {return __OS::CoreApi::Environment::GetWorkingSet();}
};

void Environment::Exit(int32 ec) {
  exit(ec);
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
  return commandLineArgs.ToObject();
}

String Environment::GetEnvironmentVariable(const String& variable) {
  char* value = getenv(variable.Data());
  
  if (value == null)
    return "";
  
  return value;
}

const Collections::Generic::IDictionary<String, String>& Environment::GetEnvironmentVariables() {
  return EnvironmentVariables;
}

String Environment::GetFolderPath(Environment::SpecialFolder folder) {
  return __OS::CoreApi::Directory::GetKnowFolderPath(folder);
}

Array<String> Environment::GetLogicalDrives() {
  return __OS::CoreApi::Drive::GetDrives();
}

void Environment::SetEnvironmentVariable(const String& name, const String& value) {
  if (name.IsEmpty())
    throw ArgumentException(pcf_current_information);
  
  if (value.IsEmpty()) {
    EnvironmentVariables().Remove(name);
    if (__OS::CoreApi::Environment::UnsetEnv(name) != 0)
      throw ArgumentException(pcf_current_information);
  } else {
    EnvironmentVariables()[name] = value;
    if (__OS::CoreApi::Environment::SetEnv(name, value) != 0)
      throw ArgumentException(pcf_current_information);
  }
}

Array<string> Environment::SetCommandLineArgs(char* argv[], int argc) {
  if (commandLineArgs != null)
    throw InvalidOperationException("Can be called only once", pcf_current_information);

  consoleChangeCodePage = UniquePointer<ConsoleChangeCodePage>::Create();
  //consoleInterceptSignals = UniquePointer<ConsoleInterceptSignals>::Create();
  signalCatcher = UniquePointer<SignalCatcher>::Create();
  System::Threading::Thread::RegisterCurrentThread();
  commandLineArgs = UniquePointer<Array<string>>::Create(std::vector<string>(argv, argv+argc));
  return Array<string>(std::vector<string>(argv+1, argv+argc));
}

