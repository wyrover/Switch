#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      string string1 = "Today is " + DateTime::Now() + ".";
      Console::WriteLine(string1);
      
      string string2 = "This is one sentence. "_s + "This is a second. ";
      string2 += "This is a third sentence.";
      Console::WriteLine(string2);
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// Today is 27/01/2014 11:36:14.
// This is one sentence. This is a second. This is a third sentence.
