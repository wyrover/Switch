#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("This example of the BitConverter::IsLittleEndian field "
        "generates \nthe following output when run on "
        "x86-class computers.\n");
      Console::WriteLine("IsLittleEndian:  {0}", BitConverter::IsLittleEndian());
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// This example of the BitConverter::IsLittleEndian field generates
// the following output when run on x86-class computers.
//
// IsLittleEndian:  True
