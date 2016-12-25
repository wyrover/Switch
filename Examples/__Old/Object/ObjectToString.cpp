#include <Pcf/Pcf>

using namespace System;

namespace ObjectTest {
  namespace Examples {
    class Object1 : public object {
    };
  }
}

int main(int argc, char* argv[]) {
  Up<Object> obj1 = Up<Object>::Create<ObjectTest::Examples::Object1>();
  Console::WriteLine(obj1->ToString());
  
  Up<Object> obj2 = Up<Object>::Create<DateTime>(1971, 1, 5, 23, 5, 0);
  Console::WriteLine(obj2->ToString());
  
  Up<Object> obj3 = Up<Object>::Create<Boolean>();
  Console::WriteLine(obj3->ToString());
}

// This code produces the following output:
//
// ObjectTest::Examples::Object1
// 5/01/1971 23:05:00
// False
