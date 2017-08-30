#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine();
      //  <-- Keep this information secure! -->
      Console::WriteLine("MachineName: {0}", Environment::MachineName);
    }
  };
}

sw_startup (Examples::Program)

// This example produces results similar to the following:
//
//
// MachineName: !---OMITTED---!
