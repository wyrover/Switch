#include <Pcf/Core.h>

using namespace System;

namespace Examples {
  class Program {
  public:
    static void Main() {
      Console::WriteLine("Hello, World!");
      //refptr<object> s1 = pcf_new<string>("toto");
      std::shared_ptr<object> s = std::make_shared<string>("toto");
      std::shared_ptr<object> s2 = std::shared_ptr<string>(new string("toto"));
      std::shared_ptr<string> s3 = std::shared_ptr<string>(new string("toto"));
      std::shared_ptr<object> s4 = s3;
      
      Console::WriteLine(*s);
      
    }
  };
}

pcf_startup (Examples::Program)
