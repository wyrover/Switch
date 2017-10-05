#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::Write("Hello ");
      Console::WriteLine("World!");
      Console::Write("Enter your name: ");
      string name = Console::ReadLine();
      Console::Write("Good day, ");
      Console::Write(name);
      Console::WriteLine("!");
    }
  };
}

_startup (Examples::Program)

// This code produces the following output:
//
// Hello World!
// Enter your name: James
// Good day, James!
