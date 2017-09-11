#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Boolean raining = false;
      Boolean busLate = true;
      
      Console::WriteLine("It is raining: {0}", raining);
      Console::WriteLine("The bus is late: {0}", busLate);
    }
  };
}

startup (Examples::Program)

// This code produces the following output:
//
// It is raining: False
// The bus is late: True
