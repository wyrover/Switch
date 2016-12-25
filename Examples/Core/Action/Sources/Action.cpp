#include <Pcf/Pcf>

using namespace System;
using namespace System::Collections::Generic;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      List<String> names;
      names.Add("Bruce");
      names.Add("Alfred");
      names.Add("Tim");
      names.Add("Richard");
      
      // Display the contents of the list using the Print method.
      names.ForEach(Print);
      
      // The following demonstrates the lambda of C++ to display the contents of the list to the console.
      names.ForEach(pcf_delegate(const String& name) {
        Console::WriteLine(name);
      });
    }

  private:
    static void Print(const string& s) {
      Console::WriteLine(s);
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// Bruce
// Alfred
// Tim
// Richard
// Bruce
// Alfred
// Tim
// Richard
