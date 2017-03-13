#include <Pcf/System/Console.h>
#include <Pcf/Startup.h>

using namespace System;

namespace Examples {
  class Program {
  public:
    static void Main() {
      //Console::WriteLine("Hello, World!");
      std::vector<int, Allocator<int>> a = {1, 2, 3, 4};
      Array<int> b = {1, 2, 3, 4};

      Console::WriteLine("b = {0}", string::Join(", ", b));
    }
  };
}

pcf_startup (Examples::Program)

