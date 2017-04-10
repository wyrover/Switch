#include <Pcf/Core.h>

using namespace System;

namespace Examples {
  class Program {
  public:
    static void Main() {
      //Console::WriteLine("Hello, World!");
      
      refptr<object> s1 = pcf_new<string>("Hello, World!");
      Console::WriteLine(*s1);

      ref<object> s2 = string("Hello, World!");
      Console::WriteLine(*s2);
    }
  };
}

pcf_startup (Examples::Program)
