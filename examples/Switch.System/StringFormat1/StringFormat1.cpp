#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      decimal pricePerOunce = 17.36;
      String s = String::Format("The current price is {0} per ounce.", pricePerOunce);
      Console::WriteLine(s);
    }
  };
}

_startup(Examples::Program)

// This code produces the following output:
//
// The current price is 17.36 per ounce.
