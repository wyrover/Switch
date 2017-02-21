#include <Pcf/System/Collections/ArrayList.h>
#include <Pcf/System/Console.h>
#include <Pcf/System/Guid.h>
#include <Pcf/System/Nullable.h>
#include <Pcf/Startup.h>

using namespace System;
using namespace System::Collections;

namespace Examples {
  class Program {
  public:
    static void MyFunc() noexcept {
    }
    
    static void Main() {
      Console::WriteLine("Hello, World!");

      //UInt32 a = 25;
      //Console::WriteLine("a {0} 0", a == 0 ? "==" : "!=");
    }
  };
}

pcf_startup (Examples::Program)

