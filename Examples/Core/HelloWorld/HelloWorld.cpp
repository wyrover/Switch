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

sw_startup (HelloWorld::Program)

// This code produces the following output:
//
// Hello, World!
