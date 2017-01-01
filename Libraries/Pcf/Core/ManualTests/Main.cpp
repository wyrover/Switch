#include <Pcf/Pcf>

using namespace System;
using namespace System::Diagnostics;
using namespace System::Net;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    static void Main(const Array<string>& args) {
      //Process process = Process::Start("http://www.google.com");
      //Console::WriteLine(process.StandardOutput().ReadToEnd());
      
      //intptr processId = StartProcess("/Users/yves/Projects/Pcf/Build/0.1.0/Examples/Debug/Calculator", "");
      //intptr childPid = StartProcess("echo", "Hello, World!");
      //intptr childPid = StartProcess("open", "-a /Applications/calculator.app");
      
      //Console::WriteLine("[Process {0}] Wait {1}", GetCurrentProcess(), processId);
      //int32 exitCode = WaitEndProcess(processId);
      //Console::WriteLine("[Process {0}] End with exitCode = {1}", GetCurrentProcess(), exitCode);
      
      for (auto process : Process::GetProcesses()) {
        try {
          Console::WriteLine(process);
        }  catch(...) {
        }
      }

      Console::WriteLine("__________________________________");
      Console::WriteLine(Process::GetCurrentProcess());
      Console::WriteLine("__________________________________");

      /*
      Console::WriteLine("[Process {0}] Create", GetCurrentProcess());
      Process process = Process::Start("/Users/yves/Projects/Pcf/Build/0.1.0/Examples/Debug/Calculator", "");
      Console::WriteLine("[Process {0}] Wait", GetCurrentProcess());
      process.WaitForExit();
      Console::WriteLine("[Process {0}] End", GetCurrentProcess());
       */
    }
  };
}

pcf_startup (Examples::Program)
