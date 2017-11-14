#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<string> values = {"09", "12.6", "0", "-13 "};
      
      for (string value : values) {
        Boolean success, result;
        int number;
        success = Int32::TryParse(value, number);
        
        if (success) {
          // The method throws no exceptions.
          result = Convert::ToBoolean(number);
          Console::WriteLine("Converted '{0}' to {1}", value, result);
        } else {
          Console::WriteLine("Unable to convert '{0}'", value);
        }
      }
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// Converted '09' to True
// Unable to convert '12.6'
// Converted '0' to False
// Converted '-13 ' to True
