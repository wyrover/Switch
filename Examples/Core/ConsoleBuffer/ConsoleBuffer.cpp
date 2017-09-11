#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("The current buffer height is {0} rows.", Console::BufferHeight);
      Console::WriteLine("The current buffer width is {0} columns.", Console::BufferWidth);
    }
  };
}

startup (Examples::Program)

// This code produces the following output:
//
// The current buffer height is 300 rows.
// The current buffer width is 85 columns.
