#include <Pcf/Pcf>

using namespace System;

namespace FactorialExample {
  template<int64 number>
  struct Factorial {
  public:
    static int64 Value() { return Factorial<number-1>::Value() * number; }
  };
  
  template<>
  struct Factorial<0> {
  public:
    static int64 Value() { return 1; }
  };
  
  class Progam {
  public:
    static void Main() {
      Console::WriteLine("Factorial<3>::Value()  = {0}", FactorialExample::Factorial<3>::Value());
      Console::WriteLine("Factorial<6>::Value()  = {0}", FactorialExample::Factorial<6>::Value());
      Console::WriteLine("Factorial<20>::Value() = {0}", FactorialExample::Factorial<20>::Value());
    }
  };
}

pcf_startup (FactorialExample::Progam)

// This code produces the following output:
//
// Factorial<3>::Value()  = 6
// Factorial<6>::Value()  = 720
// Factorial<20>::Value() = 2432902008176640000
