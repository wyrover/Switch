#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<string> values = {string::Empty, "True", "False", "true", "false", "    true    ", "TrUe", "fAlSe", "fa lse", "0", "1", "-1", "string"};
      // Parse strings using the Boolean.Parse method.
      for (string value : values) {
        try {
          bool flag = Boolean::Parse(value);
          Console::WriteLine("'{0}' --> {1}", value, flag);
        } catch (const ArgumentException&) {
          Console::WriteLine("Cannot parse a null string.");
        } catch (const FormatException&) {
          Console::WriteLine("Cannot parse '{0}'.", value);
        }
      }
      Console::WriteLine();
      // Parse strings using the Boolean.TryParse method.
      for (string value : values) {
        bool flag = false;
        if (Boolean::TryParse(value, flag))
          Console::WriteLine("'{0}' --> {1}", value, flag);
        else
          Console::WriteLine("Unable to parse '{0}'", value);
      }
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// Cannot parse ''.
// 'True' --> True
// 'False' --> False
// 'true' --> True
// 'false' --> False
// '    true    ' --> True
// 'TrUe' --> True
// 'fAlSe' --> False
// Cannot parse 'fa lse'.
// Cannot parse '0'.
// Cannot parse '1'.
// Cannot parse '-1'.
// Cannot parse 'string'.
//
// Unable to parse ''
// 'True' --> True
// 'False' --> False
// 'true' --> True
// 'false' --> False
// '    true    ' --> True
// 'TrUe' --> True
// 'fAlSe' --> False
// Unable to parse 'fa lse'
// Unable to parse '0'
// Unable to parse '1'
// Unable to parse '-1'
// Unable to parse 'string'
