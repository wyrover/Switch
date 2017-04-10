#include <Pcf/Core.h>

using namespace System;

namespace Examples {
  class Program {
  public:
    static void Main() {
      //Console::WriteLine("Hello, World!");
      
      refptr<object> s = pcf_new<string>("Hello, World!");
      Console::WriteLine(*s);
      
    }
  };
}

pcf_startup (Examples::Program)
