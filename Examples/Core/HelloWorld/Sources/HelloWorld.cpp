#include <Pcf/Pcf>

using namespace System;

namespace HelloWorld {
  class Program {
  public:
    /// @brief The main entry point for the application.
    static void Main() {
      //Console::WriteLine("Hello, World!");
      Console::WriteLine("\u00df\u6c34\U0001f34c");
    }
  };
}

pcf_startup (HelloWorld::Program)

// This code produces the following output:
//
// Hello, World!
