#include <Switch/Switch>

using namespace System;
using namespace System::Diagnostics;
using namespace System::IO;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Process process = Process::Start("gcc", "--version");
      //StreamReader reader(process.StandardOutput());
      Console::WriteLine(StreamReader(process.StandardOutput()).ReadToEnd());

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

      //System::Diagnostics::Process::Start(System::Diagnostics::ProcessStartInfo("https://www.gammasoft71.wixsite.com/switch"));
       */
    }
  };
}

startup_(Examples::Program);

// This code produces the following output:
//
