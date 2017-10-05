#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::Out << "Hello, " << "World!" << Environment::NewLine;
      Console::Out << "Value = " << 42 << Environment::NewLine;
      Console::Out << "Value (Hex) = 0x" << Int32(42).ToString("X") << Environment::NewLine;
      Console::Out << "Current date = " << DateTime::Now << Environment::NewLine;
      Console::Out << "DayOfWeek = " << DayOfWeek::Monday << Environment::NewLine;
      Console::Out << "Duration = " << 23_h + 5_min + 24_s << Environment::NewLine;
    }
  };
}

_startup (Examples::Program)

// This code produces the following output:
//
// Hello, World!
// Value = 42
// Value (Hex) = 0x2A
// Current date = 13/09/2016 21:43:20
// DayOfWeek = Monday
// Duration = 23:05:24
