#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <thread>

#include "SocketInit.hpp"

#include "../../../include/Switch/Microsoft/Win32/Registry.hpp"
#include "../../../include/Switch/System/AccessViolationException.hpp"
#include "../../../include/Switch/System/Console.hpp"
#include "../../../include/Switch/System/Environment.hpp"
#include "../../../include/Switch/System/IO/Directory.hpp"
#include "../../../include/Switch/System/IO/DirectoryNotFoundException.hpp"
#include "../../../include/Switch/System/Diagnostics/StackTrace.hpp"
#include "../../../include/Switch/System/SystemException.hpp"
#include "../../../include/Switch/System/Threading/Thread.hpp"
#include "../../../include/Switch/System/Threading/AbandonedMutexException.hpp"
#include "../../Native/Api.hpp"

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
      Native::ConsoleApi::SetInputCodePage(65001);
      Native::ConsoleApi::SetOutputCodePage(65001);
    }
    
    ~ConsoleChangeCodePage() {
      Native::ConsoleApi::SetInputCodePage(previousInputCodePage);
      Native::ConsoleApi::SetOutputCodePage(previousOutputCodePage);
    }
    
  private:
    int32 previousInputCodePage = Native::ConsoleApi::GetInputCodePage();
    int32 previousOutputCodePage = Native::ConsoleApi::GetOutputCodePage();
  };
  
  struct ConsoleInterceptSignals {
    ConsoleInterceptSignals() {
      auto signalKeys =Native::ConsoleApi::GetSignalKeys();
      for(auto signal : signalKeys)
        ::signal(signal.Key, ConsoleInterceptSignals::SignalHandler);
    }
    
    ~ConsoleInterceptSignals() {
      auto signalKeys =Native::ConsoleApi::GetSignalKeys();
      for(auto signal : signalKeys)
        ::signal(signal.Key, SIG_DFL);
    }
    
  private:
    static void SignalHandler(int32 signal) {
      static auto signalKeys =Native::ConsoleApi::GetSignalKeys();
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
      throw System::InvalidOperationException(_caller);
    }
    
    static void SignalAbortExceptionHandler(int32 signal) {
      ::signal(signal, SignalCatcher::SignalAbortExceptionHandler);
      //throw System::Threading::ThreadAbortException(_caller);
      exit(-1);
    }
    
    static void SignalFloatingPointExceptionHandler(int32 signal) {
      ::signal(signal, SignalCatcher::SignalFloatingPointExceptionHandler);
      throw System::ArithmeticException(_caller);
    }
    
    static void SignalSegmentationViolationHandler(int32 signal) {
      ::signal(signal, SignalCatcher::SignalSegmentationViolationHandler);
      throw System::AccessViolationException(_caller);
    }
  };

  Collections::Generic::Dictionary<string, string> GetEnvironmentVariables() {
    Collections::Generic::Dictionary<string, string> envs;
    for (int32 index = 0; environ[index] != null; index++) {
      System::Array<string> keyValue = string(environ[index]).Split('=');
      envs[keyValue[0]] = keyValue[1];
    }
    return envs;
  }

  _property<Collections::Generic::Dictionary<string, string>&, _readonly> EnvironmentVariables {
    []()->Collections::Generic::Dictionary<string, string>& {
      static Collections::Generic::Dictionary<string, string> environmentVariables = GetEnvironmentVariables();
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
      throw InvalidOperationException("You must call System::Environment::SetCommandLineArgs(argv, argc); method in main before.", _caller);
      
    string commandLine = string::Format("\"{0}\" ", commandLineArgs.ToObject()[0]);
    for (int i = 1; i < commandLineArgs->Length; i++)
      commandLine += string::Format(" {0}", (commandLineArgs.ToObject()[i].Contains(" ") ? string::Format("\"{0}\"", commandLineArgs.ToObject()[i]) : commandLineArgs.ToObject()[i]));
    return commandLine;
  }
};

_property<string> Environment::CurrentDirectory {
  [] {return Native::DirectoryApi::GetCurrentDirectory();},
  [](string value) {
    if (String::IsNullOrEmpty(value))
      throw ArgumentException(_caller);
    if (!System::IO::Directory::Exists(value))
      throw IO::DirectoryNotFoundException(_caller);
    if (Native::DirectoryApi::SetCurrentDirectory(value) != 0)
      throw IO::IOException(_caller);
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
  [] {return Native::EnvironmentApi::IsOs64Bit();}
};

_property<bool, _readonly> Environment::Is64BitProcess {
  [] {return IntPtr::Size == 8;}
};

_property<String, _readonly> Environment::MachineName {
  [] {return Native::EnvironmentApi::GetMachineName();}
};

_property<String, _readonly> Environment::NewLine {
  [] {return Native::EnvironmentApi::NewLine();}
};

_property<const OperatingSystem&, _readonly> Environment::OSVersion {
  []()->const OperatingSystem& {
    static OperatingSystem os(PlatformID::Unknown, System::Version());
    if (os.Platform == PlatformID::Unknown) {
      int32 major, minor, build, revision;
      Native::EnvironmentApi::GetOsVersion(major, minor, build, revision);
      os = OperatingSystem(Native::EnvironmentApi::GetOsPlatformID(), System::Version(major, minor, build, revision));
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
  [] {return Native::EnvironmentApi::GetTickCount();}
};

_property<String, _readonly> Environment::UserDomainName {
  [] {return Native::EnvironmentApi::GetUserDomainName();}
};

_property<bool, _readonly> Environment::UserInteractive {
  [] {return ::userInteractive;}
};

_property<String, _readonly> Environment::UserName {
  [] {return Native::EnvironmentApi::GetUserName();}
};

_property<const System::Version, _readonly> Environment::Version {
  [] {return Native::EnvironmentApi::GetVersion();}
};

_property<int64, _readonly> Environment::WorkingSet {
  [] {return Native::EnvironmentApi::GetWorkingSet();}
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
    throw InvalidOperationException("You must call System::Environment::SetCommandLineArgs(argv, argc); method in main before.", _caller);
  return commandLineArgs();
}

String Environment::GetEnvironmentVariable(const String& variable, EnvironmentVariableTarget target) {
  if (!Enum<EnvironmentVariableTarget>::GetValues().Contains(target))
    throw ArgumentException(_caller);
  
  if (target == EnvironmentVariableTarget::Process) {
    char* value = getenv(variable.Data());
    return value == null ? "" : value;
  } else  if (target == EnvironmentVariableTarget::User)
    return Microsoft::Win32::Registry::GetValue("HKEY_CURRENT_USER\\Environment", variable, "").ToString();
  return Microsoft::Win32::Registry::GetValue("HKEY_LOCAL_MACHINE\\System\\CurrentControlSet\\Control\\Session Manager\\Environment", variable, "").ToString();
}

const Collections::Generic::IDictionary<String, String>& Environment::GetEnvironmentVariables(EnvironmentVariableTarget target) {
  if (!Enum<EnvironmentVariableTarget>::GetValues().Contains(target))
    throw ArgumentException(_caller);
  
  if (target == EnvironmentVariableTarget::Process)
    return EnvironmentVariables;

  static Collections::Generic::Dictionary<string, string> environmentVariables;
  environmentVariables.Clear();
  Microsoft::Win32::RegistryKey key = target == EnvironmentVariableTarget::User ? Microsoft::Win32::Registry::CurrentUser().CreateSubKey("Environment") : Microsoft::Win32::Registry::LocalMachine().CreateSubKey("System").CreateSubKey("CurrentControlSet").CreateSubKey("Control").CreateSubKey("Session Manager").CreateSubKey("Environment");
  for (auto name : key.GetValueNames())
    environmentVariables[name] = key.GetValue(name).ToString();
  return environmentVariables;
}

String Environment::GetFolderPath(Environment::SpecialFolder folder, Environment::SpecialFolderOption option) {
  if (!Enum<Environment::SpecialFolderOption>::GetValues().Contains(option))
    throw ArgumentException(_caller);
  
  string path = Native::DirectoryApi::GetKnowFolderPath(folder);

  if (option == Environment::SpecialFolderOption::None)
    return  !System::IO::Directory::Exists(path) ? "" :  path;
  
  if (!System::IO::Directory::Exists(path))
    System::IO::Directory::CreateDirectory(path);
  
  return path;
}

Array<String> Environment::GetLogicalDrives() {
  return Native::DriveApi::GetDrives();
}

void Environment::SetEnvironmentVariable(const String& name, const String& value, EnvironmentVariableTarget target) {
  if (string::IsNullOrEmpty(name))
    throw ArgumentException(_caller);
  
  if (target == EnvironmentVariableTarget::Process) {
    if (string::IsNullOrEmpty(value)) {
      EnvironmentVariables().Remove(name);
      if (Native::EnvironmentApi::UnsetEnv(name) != 0)
        throw ArgumentException(_caller);
    } else {
      EnvironmentVariables()[name] = value;
      if (Native::EnvironmentApi::SetEnv(name, value) != 0)
        throw ArgumentException(_caller);
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
    throw InvalidOperationException("Can be called only once", _caller);

  socketInit = ref_new<SocketInit>();
  consoleChangeCodePage = ref_new<ConsoleChangeCodePage>();
  consoleInterceptSignals = ref_new<ConsoleInterceptSignals>();
  signalCatcher = ref_new<SignalCatcher>();
  System::Threading::Thread::RegisterCurrentThread();
  commandLineArgs = ref_new<Array<string>>(std::vector<string>(argv, argv+argc));
  return Array<string>(std::vector<string>(argv+1, argv+argc));
}

void Environment::SetUserInteractive(bool ui) {
  ::userInteractive = ui;
}

