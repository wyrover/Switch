#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;

namespace Examples {
  namespace ObjectTest {
    class Object1 : public object {
    };
  }

  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      refptr<Object> obj1 = ref_new<ObjectTest::Object1>();
      Console::WriteLine(obj1->ToString());

      refptr<Object> obj2 = ref_new<DateTime>(1971, 1, 5, 23, 5, 0);
      Console::WriteLine(obj2->ToString());

      refptr<Object> obj3 = ref_new<Boolean>();
      Console::WriteLine(obj3->ToString());
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// Examples::ObjectTest::Object1
// 5/01/1971 23:05:00
// False
