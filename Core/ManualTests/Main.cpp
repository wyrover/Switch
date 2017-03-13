#include <Pcf/Core.h>

using namespace System;

namespace Examples {
  class Program {
  public:
    static void Write(const Array<string>& a) {
      Console::WriteLine("Length = {0}", a.Length);
      for (auto i : a)
        Console::WriteLine(i);
    }

    static void Main() {
      Array<string> a = {"1", "2", "3", "4"};
      Write(a);
    }
  };
}

pcf_startup (Examples::Program)

