#include <Pcf/System/Linq/Linq.hpp>
#include <Pcf/System/Console.hpp>
#include <Pcf/Startup.hpp>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;

namespace ManualTests {
  struct Abs : public object {
    ~Abs() override = 0;
  };
  
  inline Abs::~Abs() { }
  
  class C2 : public Abs {
  protected:
    C2() {}
  };

  class C3 : public C2 {
  };
  
  class Program {
  public:
    static void Main() {
      C3 c;
    }
  };
}

pcf_startup (ManualTests::Program)
