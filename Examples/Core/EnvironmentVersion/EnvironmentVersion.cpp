#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine();
      Console::WriteLine("Version: {0}", Environment::Version);
    }
  };
}

sw_startup (Examples::Program)


// This example produces results similar to the following:
//
//
// Version: 0.3.0
