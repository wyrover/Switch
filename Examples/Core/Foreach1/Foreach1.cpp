#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      string colors[] = {"Red", "Blue", "Green", "Yellow", "Gray"};
      
      for (string item : colors) {
        Console::WriteLine(item);
      }
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// Red
// Blue
// Green
// Yellow
// Gray
