#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::ForegroundColor = ConsoleColor::DarkBlue;
      Console::WriteLine("This is a colored text");
      Console::ForegroundColor = ConsoleColor::Blue;
      Console::WriteLine("This is a colored text");
      Console::WriteLine();
      Console::ForegroundColor = ConsoleColor::DarkGreen;
      Console::WriteLine("This is a colored text");
      Console::ForegroundColor = ConsoleColor::Green;
      Console::WriteLine("This is a colored text");
      Console::WriteLine();
      Console::ForegroundColor = ConsoleColor::DarkCyan;
      Console::WriteLine("This is a colored text");
      Console::ForegroundColor = ConsoleColor::Cyan;
      Console::WriteLine("This is a colored text");
      Console::WriteLine();
      Console::ForegroundColor = ConsoleColor::DarkRed;
      Console::WriteLine("This is a colored text");
      Console::ForegroundColor = ConsoleColor::Red;
      Console::WriteLine("This is a colored text");
      Console::WriteLine();
      Console::ForegroundColor = ConsoleColor::DarkMagenta;
      Console::WriteLine("This is a colored text");
      Console::ForegroundColor = ConsoleColor::Magenta;
      Console::WriteLine("This is a colored text");
      Console::WriteLine();
      Console::ForegroundColor = ConsoleColor::DarkYellow;
      Console::WriteLine("This is a colored text");
      Console::ForegroundColor = ConsoleColor::Yellow;
      Console::WriteLine("This is a colored text");
      Console::WriteLine();
      Console::ForegroundColor = ConsoleColor::DarkGray;
      Console::WriteLine("This is a colored text");
      Console::ForegroundColor = ConsoleColor::Gray;
      Console::WriteLine("This is a colored text");
      Console::WriteLine();
      Console::ForegroundColor = ConsoleColor::Black;
      Console::WriteLine("This is a colored text");
      Console::ForegroundColor = ConsoleColor::White;
      Console::WriteLine("This is a colored text");
      
      Console::ResetColor();
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output with colors:
//
