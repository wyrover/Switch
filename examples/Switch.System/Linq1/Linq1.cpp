#include <Switch/Switch>

using namespace System;
using namespace System::Linq;
using namespace System::Collections::Generic;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<string> names = { "Burke", "Connor", "Frank", "Everett", "Albert", "George", "Harris", "David" };

      refptr<IEnumerable<string>> query = from<string>(names)
      | where<string>(_delegate(string s) {return s.Length == 5;})
      | orderby<string>(_delegate(string s) {return s;})
      | select<string>(_delegate(string s) {return s.ToUpper();});

      for (string item : *query)
        Console::WriteLine(item);
    }
  };
}

_startup(Examples::Program);

// This code example produces the following output:
//
// BURKE
// DAVID
// FRANK
