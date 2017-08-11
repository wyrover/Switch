#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      string m0 = "This example increments the cursor size from 1% to 100%:\n";
      string m1 = "Cursor size = {0}%. (Press any key to continue...)";
      Array<int> sizes = { 1, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
      int saveCursorSize;
      //
      saveCursorSize = Console::CursorSize;
      Console::WriteLine(m0);
      for(int size : sizes) {
        Console::CursorSize = size;
        Console::WriteLine(m1, size);
        Console::ReadKey();
      }
      Console::CursorSize = saveCursorSize;
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// Hello World!
// Enter your name: James
// Good day, James!
