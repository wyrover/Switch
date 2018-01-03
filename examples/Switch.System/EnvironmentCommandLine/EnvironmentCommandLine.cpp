#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine();
      // Invoke this sample with an arbitrary set of command line arguments.
      Console::WriteLine("CommandLine: {0}", Environment::CommandLine);
    }
  };
}

startup_(Examples::Program);

// This example produces results similar to the following:
//
// >EnvironmentCommandLine ARBITRARY TEXT
//
// CommandLine:  "/!---OMITTED---!/EnvironmentCommandLine"  ARBITRARY TEXT
