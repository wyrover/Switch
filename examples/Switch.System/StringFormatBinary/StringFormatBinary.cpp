#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("Value of 165 in binary = 0b{0:B16}.", 0b10100101);
    }
  };
}

_startup(Examples::Program)

// This code produces the following output:
//
// Value of 165 in binary = 0b0000000010100101.
