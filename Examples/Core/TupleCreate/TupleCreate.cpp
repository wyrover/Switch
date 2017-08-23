#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    static void Main() {
      auto t = Tuple<>::Create(25, Version(1, 2, 3));

      Console::WriteLine("Tuple : " + t);

      int i = t.Item1;
      Version v = t.Item2;
      Console::WriteLine("i = {0}", i);
      Console::WriteLine("v = {0}", v);
    }
  };
}

// Specify the Main entry point to System
pcf_startup (Examples::Program);

// This code produces the following output:
//
// Tuple : (25, 1.2.3)
// i = 25
// v = 1.2.3
