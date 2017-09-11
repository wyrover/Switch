#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      List<string> colors;
      
      colors.Add("Red");
      colors.Add("Blue");
      colors.Add("Green");
      colors.Add("Yellow");
      colors.Add("Gray");
      
      for (string item : colors) {
        Console::WriteLine(item);
      }
    }
  };
}

startup (Examples::Program)

// This code produces the following output:
//
// Red
// Blue
// Green
// Yellow
// Gray
