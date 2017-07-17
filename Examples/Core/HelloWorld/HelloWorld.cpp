#include <Pcf/Pcf>

using namespace System;

namespace HelloWorld {
  class Program {
  public:
    static void Main() {
      Console::WriteLine("Hello, World!");
    }
  };
}

pcf_startup (HelloWorld::Program)

// This code produces the following output:
//
// Hello, World!
