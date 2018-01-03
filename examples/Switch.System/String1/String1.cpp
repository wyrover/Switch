#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      string string1 = "This is a string created by assignment.";
      Console::WriteLine(string1);
      string string2a = "The path is C:\\PublicDocuments\\Report1.doc";
      Console::WriteLine(string2a);
      string string2b = R"(The path is C:\PublicDocuments\Report1.doc)";
      Console::WriteLine(string2b);
    }
  };
}

startup_(Examples::Program);

// This code produces the following output:
//
// This is a string created by assignment.
// The path is C:\PublicDocuments\Report1.doc
// The path is C:\PublicDocuments\Report1.doc
