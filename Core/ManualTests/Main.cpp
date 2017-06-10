#include <Pcf/System/Console.hpp>
#include <Pcf/Startup.hpp>

using namespace System;

namespace ManualTests {
  class Program {
  public:
    static void Main() {
      Console::WriteLine("Hello, World!");
    }
  };
}

pcf_startup (ManualTests::Program)
