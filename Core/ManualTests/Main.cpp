#include <Pcf/Core.h>

using namespace System;
using namespace System::IO;

namespace Examples {
  class Program {
  public:
    static void Main() {
      //Console::WriteLine("Hello, World!");
      Console::WriteLine("{0}", DateTime(1601, 1, 5));
    }
  };
}

pcf_startup (Examples::Program)
