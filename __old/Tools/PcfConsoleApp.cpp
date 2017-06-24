#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    static void Main(const Array<string>& args) {
      Console::WriteLine("Hello, World!");
    }
  };
}

pcf_startup (Examples::Program)
