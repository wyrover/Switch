#include <Pcf/Pcf>

using namespace System;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main(const Array<string>& args) {
      int x = 0;
      //
      if ((args.Length == 1) && (Int32::TryParse(args[0], x) == true) && ((x >= 1) && (x <= 9))) {
        for (int i = 1; i <= x; i++) {
          Console::WriteLine("Beep number {0}.", i);
          Console::Beep();
        }
      } else
        Console::WriteLine("Usage: Enter the number of times (between 1 and 9) to beep.");
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// The current window width is 100, and the current window height is 60.
//   (Press any key to continue...)
// The new window width is 50, and the new window height is 30.
//   (Press any key to continue...)
// The current window width is 100, and the current window height is 60.
