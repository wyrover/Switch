#include <Switch/Switch>

using namespace System;

namespace Examples {
  class MyBaseClass : public object {
  };
  
  class MyDerivedClass: public MyBaseClass {
  };
  
  class ObjectClass : public object {
  };
  
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Examples::MyBaseClass myBase;
      Examples::MyDerivedClass myDerived;
      Object* o = &myDerived;
      Examples::MyBaseClass* b = &myDerived;
      
      Console::WriteLine("myBase: Type is {0}", myBase.GetType());
      Console::WriteLine("myDerived: Type is {0}", myDerived.GetType());
      Console::WriteLine("o: Type is {0}", o->GetType());
      Console::WriteLine("b: Type is {0}", b->GetType());
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// myBase: Type is Examples::MyBaseClass
// myDerived: Type is Examples::MyDerivedClass
// o: Type is Examples::MyDerivedClass
// b: Type is Examples::MyDerivedClass
