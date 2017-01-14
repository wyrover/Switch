#include <Pcf/Pcf>

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
