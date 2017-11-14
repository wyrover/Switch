#include <Switch/Switch.Core>

using namespace System;

namespace HelloWorld {
  class Program {
  public:
    static void Main() {
      Console::WriteLine("Hello, World!");
    }
  };
}

_startup(HelloWorld::Program);

// This code produces the following output:
//
// Hello, World!
