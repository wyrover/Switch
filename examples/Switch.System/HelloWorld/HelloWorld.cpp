#include <Switch/Switch>

using namespace System;

namespace HelloWorld {
  class Program {
  public:
    static void Main() {
      Console::WriteLine("Hello, World!");
    }
  };
}

startup_(HelloWorld::Program);

// This code produces the following output:
//
// Hello, World!
