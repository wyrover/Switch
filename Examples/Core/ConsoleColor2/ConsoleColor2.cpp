#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::BackgroundColor = ConsoleColor::DarkBlue;
      Console::WriteLine("                    ");
      Console::BackgroundColor = ConsoleColor::Blue;
      Console::WriteLine("                    ");
      Console::WriteLine();
      Console::BackgroundColor = ConsoleColor::DarkGreen;
      Console::WriteLine("                    ");
      Console::BackgroundColor = ConsoleColor::Green;
      Console::WriteLine("                    ");
      Console::WriteLine();
      Console::BackgroundColor = ConsoleColor::DarkCyan;
      Console::WriteLine("                    ");
      Console::BackgroundColor = ConsoleColor::Cyan;
      Console::WriteLine("                    ");
      Console::WriteLine();
      Console::BackgroundColor = ConsoleColor::DarkRed;
      Console::WriteLine("                    ");
      Console::BackgroundColor = ConsoleColor::Red;
      Console::WriteLine("                    ");
      Console::WriteLine();
      Console::BackgroundColor = ConsoleColor::DarkMagenta;
      Console::WriteLine("                    ");
      Console::BackgroundColor = ConsoleColor::Magenta;
      Console::WriteLine("                    ");
      Console::WriteLine();
      Console::BackgroundColor = ConsoleColor::DarkYellow;
      Console::WriteLine("                    ");
      Console::BackgroundColor = ConsoleColor::Yellow;
      Console::WriteLine("                    ");
      Console::WriteLine();
      Console::BackgroundColor = ConsoleColor::DarkGray;
      Console::WriteLine("                    ");
      Console::BackgroundColor = ConsoleColor::Gray;
      Console::WriteLine("                    ");
      Console::WriteLine();
      Console::BackgroundColor = ConsoleColor::Black;
      Console::WriteLine("                    ");
      Console::BackgroundColor = ConsoleColor::White;
      Console::WriteLine("                    ");
      
      Console::ResetColor();
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output with colors:
//
