#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <thread>

#include "SocketInit.hpp"

#include "../../../Includes/Switch/Microsoft/Win32/Registry.hpp"
#include "../../../Includes/Switch/System/AccessViolationException.hpp"
#include "../../../Includes/Switch/System/Console.hpp"
#include "../../../Includes/Switch/System/Environment.hpp"
#include "../../../Includes/Switch/System/SystemVersion.hpp"
#include "../../../Includes/Switch/System/IO/Directory.hpp"
#include "../../../Includes/Switch/System/IO/DirectoryNotFoundException.hpp"
#include "../../../Includes/Switch/System/Diagnostics/StackTrace.hpp"
#include "../../../Includes/Switch/System/SystemException.hpp"
#include "../../../Includes/Switch/System/Threading/Thread.hpp"
#include "../../../Includes/Switch/System/Threading/AbandonedMutexException.hpp"
#include "../../__OS/CoreApi.hpp"

using namespace System;
using namespace System::Collections::Generic;

#if defined(_WIN32)
  __declspec(dllimport) extern char** environ;
#else
  extern char** environ;
#endif

namespace {
  struct ConsoleChangeCodePage {
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
  
  struct ConsoleInterceptSignals {
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
      System::Console::CancelKeyPress(ref<object>::Null(), consoleCancel);
      if (consoleCancel.Cancel == false)
        Environment::Exit(-1);
    }
  };
  
  struct SignalCatcher {
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
      throw System::InvalidOperationException(_current_information);
    }
    
    static void SignalAbortExceptionHandler(int32 signal) {
      ::signal(signal, SignalCatcher::SignalAbortExceptionHandler);
      //throw System::Threading::ThreadAbortException(_current_information);
      exit(-1);
    }
    
    static void SignalFloatingPointExceptionHandler(int32 signal) {
      ::signal(signal, SignalCatcher::SignalFloatingPointExceptionHandler);
      throw System::ArithmeticException(_current_information);
    }
    
    static void SignalSegmentationViolationHandler(int32 signal) {
      ::signal(signal, SignalCatcher::SignalSegmentationViolationHandler);
      throw System::AccessViolationException(_current_information);
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

  _property<Collections::Specialized::StringDictionary&, _readonly> EnvironmentVariables {
    []()->Collections::Specialized::StringDictionary& {
      static Collections::Specialized::StringDictionary environmentVariables = GetEnvironmentVariables();
      return environmentVariables;
    }
  };
  
  int32 exitCode;
  bool userInteractive = true;
  refptr<SocketInit> socketInit;
  refptr<System::Array<String>> commandLineArgs;
  refptr<ConsoleChangeCodePage> consoleChangeCodePage;
  refptr<ConsoleInterceptSignals> consoleInterceptSignals;
  refptr<SignalCatcher> signalCatcher;
}

_property<String, _readonly> Environment::CommandLine {
  [] {
    if (commandLineArgs->Length == 0)
      throw InvalidOperationException("You must call System::Environment::SetCommandLineArgs(argv, argc); method in main before.", _current_information);
      
    string commandLine = string::Format("\"{0}\" ", commandLineArgs.ToObject()[0]);
    for (int i = 1; i < commandLineArgs->Length; i++)
      commandLine += string::Format(" {0}", (commandLineArgs.ToObject()[i].Contains(" ") ? string::Format("\"{0}\"", commandLineArgs.ToObject()[i]) : commandLineArgs.ToObject()[i]));
    return commandLine;
  }
};

_property<string> Environment::CurrentDirectory {
  [] {return __OS::CoreApi::Directory::GetCurrentDirectory();},
  [](string value) {
    if (String::IsNullOrEmpty(value))
      throw ArgumentException(_current_information);
    if (!System::IO::Directory::Exists(value))
      throw IO::DirectoryNotFoundException(_current_information);
    if (__OS::CoreApi::Directory::SetCurrentDirectory(value) != 0)
      throw IO::IOException(_current_information);
  }
};

_property<int32, _readonly> Environment::CurrentManagedThreadId {
  [] {return System::Threading::Thread::CurrentThread().ManagedThreadId();}
};

_property<int32> Environment::ExitCode {
  [] {return exitCode;},
  [](int32 value) {exitCode = value;}
};

_property<bool, _readonly> Environment::HasShutdownStarted {
  [] {return false;}
};

_property<bool, _readonly> Environment::Is64BitOperatingSystem {
  [] {return __OS::CoreApi::Environment::IsOs64Bit();}
};

_property<bool, _readonly> Environment::Is64BitProcess {
  [] {return IntPtr::Size == 8;}
};

_property<String, _readonly> Environment::MachineName {
  [] {return __OS::CoreApi::Environment::GetMachineName();}
};

_property<String, _readonly> Environment::NewLine {
  [] {return __OS::CoreApi::Environment::NewLine();}
};

_property<const OperatingSystem&, _readonly> Environment::OSVersion {
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

_property<int32, _readonly> Environment::ProcessorCount {
  [] {
    static int32 processorCount = as<int32>(std::thread::hardware_concurrency());
    return processorCount;
  }
};

_property<String, _readonly> Environment::StackTrace {
  [] {return Diagnostics::StackTrace(3, true).ToString();}
};

_property<String, _readonly> Environment::SystemDirectory {
  [] {return GetFolderPath(Environment::SpecialFolder::System);}
};

_property<int32, _readonly> Environment::SystemPageSize {
  [] {return 4096;}
};

_property<int32, _readonly> Environment::TickCount {
  [] {return __OS::CoreApi::Environment::GetTickCount();}
};

_property<String, _readonly> Environment::UserDomainName {
  [] {return __OS::CoreApi::Environment::GetUserDomainName();}
};

_property<bool, _readonly> Environment::UserInteractive {
  [] {return ::userInteractive;}
};

_property<String, _readonly> Environment::UserName {
  [] {return __OS::CoreApi::Environment::GetUserName();}
};

_property<const System::Version&, _readonly> Environment::Version {
  []()->const System::Version& {return Switch::GetVersion();}
};

_property<int64, _readonly> Environment::WorkingSet {
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
  if (commandLineArgs->Length == 0)
    throw InvalidOperationException("You must call System::Environment::SetCommandLineArgs(argv, argc); method in main before.", _current_information);
  return commandLineArgs();
}

String Environment::GetEnvironmentVariable(const String& variable, EnvironmentVariableTarget target) {
  if (!Enum<EnvironmentVariableTarget>::GetValues().Contains(target))
    throw ArgumentException(_current_information);
  
  if (target == EnvironmentVariableTarget::Process) {
    char* value = getenv(variable.Data());
    return value == null ? "" : value;
  } else  if (target == EnvironmentVariableTarget::User)
    return Microsoft::Win32::Registry::GetValue("HKEY_CURRENT_USER\\Environment", variable, "").ToString();
  return Microsoft::Win32::Registry::GetValue("HKEY_LOCAL_MACHINE\\System\\CurrentControlSet\\Control\\Session Manager\\Environment", variable, "").ToString();
}

const Collections::Generic::IDictionary<String, String>& Environment::GetEnvironmentVariables(EnvironmentVariableTarget target) {
  if (!Enum<EnvironmentVariableTarget>::GetValues().Contains(target))
    throw ArgumentException(_current_information);
  
  if (target == EnvironmentVariableTarget::Process)
    return EnvironmentVariables;

  static Collections::Specialized::StringDictionary environmentVariables;
  environmentVariables.Clear();
  Microsoft::Win32::RegistryKey key = target == EnvironmentVariableTarget::User ? Microsoft::Win32::Registry::CurrentUser().CreateSubKey("Environment") : Microsoft::Win32::Registry::LocalMachine().CreateSubKey("System").CreateSubKey("CurrentControlSet").CreateSubKey("Control").CreateSubKey("Session Manager").CreateSubKey("Environment");
  for (auto name : key.GetValueNames())
    environmentVariables[name] = key.GetValue(name).ToString();
  return environmentVariables;
}

String Environment::GetFolderPath(Environment::SpecialFolder folder, Environment::SpecialFolderOption option) {
  if (!Enum<Environment::SpecialFolderOption>::GetValues().Contains(option))
    throw ArgumentException(_current_information);
  
  string path = __OS::CoreApi::Directory::GetKnowFolderPath(folder);

  if (option == Environment::SpecialFolderOption::None)
    return  !System::IO::Directory::Exists(path) ? "" :  path;
  
  if (!System::IO::Directory::Exists(path))
    System::IO::Directory::CreateDirectory(path);
  
  return path;
}

Array<String> Environment::GetLogicalDrives() {
  return __OS::CoreApi::Drive::GetDrives();
}

void Environment::SetEnvironmentVariable(const String& name, const String& value, EnvironmentVariableTarget target) {
  if (string::IsNullOrEmpty(name))
    throw ArgumentException(_current_information);
  
  if (target == EnvironmentVariableTarget::Process) {
    if (string::IsNullOrEmpty(value)) {
      EnvironmentVariables().Remove(name);
      if (__OS::CoreApi::Environment::UnsetEnv(name) != 0)
        throw ArgumentException(_current_information);
    } else {
      EnvironmentVariables()[name] = value;
      if (__OS::CoreApi::Environment::SetEnv(name, value) != 0)
        throw ArgumentException(_current_information);
    }
  } else {
    Microsoft::Win32::RegistryKey key = target == EnvironmentVariableTarget::User ? Microsoft::Win32::Registry::CurrentUser().CreateSubKey("Environment") : Microsoft::Win32::Registry::LocalMachine().CreateSubKey("System").CreateSubKey("CurrentControlSet").CreateSubKey("Control").CreateSubKey("Session Manager").CreateSubKey("Environment");
    if (string::IsNullOrEmpty(value))
      key.DeleteValue(name);
    else
      key.SetValue(name, value);
  }
}

Array<string> Environment::SetCommandLineArgs(char* argv[], int argc) {
  if (commandLineArgs != null)
    throw InvalidOperationException("Can be called only once", _current_information);

  socketInit = ref_new<SocketInit>();
  consoleChangeCodePage = ref_new<ConsoleChangeCodePage>();
  consoleInterceptSignals = ref_new<ConsoleInterceptSignals>();
  signalCatcher = ref_new<SignalCatcher>();
  System::Threading::Thread::RegisterCurrentThread();
  commandLineArgs = ref_new<Array<string>>(std::vector<string>(argv, argv+argc));
  return Array<string>(std::vector<string>(argv+1, argv+argc));
}

void Environment::SetUserInteractive(bool userInteractive) {
  ::userInteractive = userInteractive;
}

