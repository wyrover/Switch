#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<int> items = {10, 20, 30};
      
      try {
        Console::WriteLine("items[3] = {0}", items[3]);
      } catch(const ArgumentOutOfRangeException& exception) {
        Console::WriteLine("Exception occured : {0}", exception.Message);
      }
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// Exception occured : Specified argument is out of range of valid values.
