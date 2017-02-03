#include <Pcf/Pcf>

using namespace System;

namespace Test {
  class Program {
  public:
    static void Main() {
      auto t = Tuple<>::Create(25, "My string");

      Console::WriteLine("Tuple : " + t);
    }
  };
}

// Specify the Main entry point to System
pcf_statup (Test::Program);

// This code produces the following output:
//
// Tuple : (25, My string)
