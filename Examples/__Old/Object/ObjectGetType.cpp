#include <Pcf/Pcf>

using namespace System;

namespace ObjectTest {
  class MyBaseClass : public object {
  };

  class MyDerivedClass: public MyBaseClass {
  };

  class ObjectClass : public object {
  };
}

int main(int argc, char* argv[]) {
  ObjectTest::MyBaseClass myBase;
  ObjectTest::MyDerivedClass myDerived;
  Object* o = &myDerived;
  ObjectTest::MyBaseClass* b = &myDerived;
  
  Console::WriteLine("myBase: Type is {0}", myBase.GetType());
  Console::WriteLine("myDerived: Type is {0}", myDerived.GetType());
  Console::WriteLine("o: Type is {0}", o->GetType());
  Console::WriteLine("b: Type is {0}", b->GetType());
}

// This code produces the following output:
//
// myBase: Type is ObjectTest::MyBaseClass
// myDerived: Type is ObjectTest::MyDerivedClass
// o: Type is ObjectTest::MyDerivedClass
// b: Type is ObjectTest::MyDerivedClass
