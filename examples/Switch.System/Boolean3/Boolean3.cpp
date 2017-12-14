#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      byte byteValue = 12;
      Console::WriteLine(Convert::ToBoolean(byteValue));

      byte byteValue2 = 0;
      Console::WriteLine(Convert::ToBoolean(byteValue2));

      int intValue = -16345;
      Console::WriteLine(Convert::ToBoolean(intValue));

      int64 longValue = 945;
      Console::WriteLine(Convert::ToBoolean(longValue));

      sbyte sbyteValue = -12;
      Console::WriteLine(Convert::ToBoolean(sbyteValue));

      double dblValue = 0;
      Console::WriteLine(Convert::ToBoolean(dblValue));

      float sngValue = .0001f;
      Console::WriteLine(Convert::ToBoolean(sngValue));
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// True
// False
// True
// True
// True
// False
// True
