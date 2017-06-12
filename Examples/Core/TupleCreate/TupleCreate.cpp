#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    static void Main() {
      auto t = Tuple<>::Create(25, Uri("http://www.gammasoft.com"));

      Console::WriteLine("Tuple : " + t);

      int i = t.Item1;
      Uri u = t.Item2;
      Console::WriteLine("i = {0}", i);
      Console::WriteLine("u = {0}", u);
    }
  };
}

// Specify the Main entry point to System
pcf_startup (Examples::Program);

// This code produces the following output:
//
// Tuple : (25, http://www.gammasoft.com/)
// i = 25
// u = http://www.gammasoft.com/
