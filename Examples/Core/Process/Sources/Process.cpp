#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      up<System::Diagnostics::Process> process = System::Diagnostics::Process::Start("echo", "Hello, World!");
      IO::StreamReader reader(process->StandardOutput());
      Console::WriteLine(reader.ReadToEnd());

      /*
      System::Diagnostics::ProcessStartInfo command;
      if (Environment::OSVersion().Platform > PlatformID::WinCE)
        command = System::Diagnostics::ProcessStartInfo("ls");
      else
        command = System::Diagnostics::ProcessStartInfo("dir", "/B");
      Console::WriteLine();
      Console::WriteLine(">" + command);
      System::Diagnostics::Process::Start(command);
      
      if (Environment::OSVersion().Platform > PlatformID::WinCE) {
        command = System::Diagnostics::ProcessStartInfo("ls", "-lia");
      } else {
        command = System::Diagnostics::ProcessStartInfo("dir");
      }
      Console::WriteLine();
      Console::WriteLine(">" + command);
      System::Diagnostics::Process::Start(command);
      
      if (Environment::OSVersion().Platform == PlatformID::MacOSX) {
        System::Diagnostics::Process::Start(System::Diagnostics::ProcessStartInfo("open", "."));
      }
      if (Environment::OSVersion().Platform == PlatformID::Win32NT) {
        System::Diagnostics::Process::Start(System::Diagnostics::ProcessStartInfo("explorer", "."));
      }
      
      if (Environment::OSVersion().Platform == PlatformID::MacOSX) {
        System::Diagnostics::Process::Start(System::Diagnostics::ProcessStartInfo("open", "-a /Applications/calculator.app"));
      }
      if (Environment::OSVersion().Platform == PlatformID::Win32NT) {
        System::Diagnostics::Process::Start(System::Diagnostics::ProcessStartInfo("calc"));
      }
      
      //System::Diagnostics::Process::Start(System::Diagnostics::ProcessStartInfo("http://www.google.com"));
       */
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
