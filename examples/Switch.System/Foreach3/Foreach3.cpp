#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      string str = string::Join(Environment::NewLine, {"Red", "Blue", "Green", "Yellow", "Gray"});
      
      for (char32 item : str) {
        Console::Write(item);
      }
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// Red
// Blue
// Green
// Yellow
// Gray
