#include <Pcf/System/Console.h>
#include <Pcf/Startup.h>

using namespace System;

namespace Examples {
  class Program {
  public:
    static void Main() {
      Console::WriteLine("Hello, World!");
    }
  };
}

pcf_startup (Examples::Program)
