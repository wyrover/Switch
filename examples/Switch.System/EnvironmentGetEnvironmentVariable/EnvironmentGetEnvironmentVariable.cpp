#include <Switch/Switch>

using namespace System;
using namespace System::IO;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Change the directory to %WINDIR% if on Windows otherwise %HOME%
      Environment::CurrentDirectory = Environment::GetEnvironmentVariable(Environment::OSVersion().IsWindowsFamilly ? "windir" : "HOME");
      DirectoryInfo info(".");

      Console::WriteLine("Directory Info:   " + info.FullName);
    }
  };
}

startup_(Examples::Program);


// This example produces results similar to the following if you run it on Windows:
//
// Directory Info:   C:\windows
