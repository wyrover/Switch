#include <Switch/Switch>

using namespace System;
using namespace System::Collections;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine();
      Console::WriteLine("UserInteractive: {0}", Environment::UserInteractive);
    }
  };
}

startup_(Examples::Program);

// This example produces results similar to the following:
//
//
// UserInteractive: True
