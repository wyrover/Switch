#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine();
      Array<String> drives = Environment::GetLogicalDrives();
      Console::WriteLine("GetLogicalDrives: {0}", String::Join(", ", drives));
    }
  };
}

startup (Examples::Program)


// This example produces results similar to the following if you run it on Windows:
//
//
// GetLogicalDrives: A:\, C:\, D:\
//
