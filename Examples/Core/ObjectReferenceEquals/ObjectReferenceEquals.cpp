#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Object* o = null;
      Object* p = null;
      Object* q = new Object();
      
      Console::WriteLine(Object::ReferenceEquals(*o, *p));
      p = q;
      Console::WriteLine(Object::ReferenceEquals(*p, *q));
      Console::WriteLine(Object::ReferenceEquals(*o, *p));
      delete(q);
    }
  };
}

sw_startup (Examples::Program)

// This code produces the following output:
//
// True
// True
// False
