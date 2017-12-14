#include <Switch/Switch>

using namespace System;
using namespace System::IO;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine();
      // Change the directory to user's desktop
      Environment::CurrentDirectory = Environment::GetFolderPath(Environment::SpecialFolder::Desktop);
      DirectoryInfo info(".");

      Console::WriteLine("Directory Info:   " + info.FullName);
    }
  };
}

_startup(Examples::Program);

// This example produces results similar to the following:
//
//
// CommandLine:  "Directory Info:   /Users/!---OMITTED---!/Desktop
