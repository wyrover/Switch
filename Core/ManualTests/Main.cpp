#include <Pcf/Microsoft/Win32/Registry.hpp>
#include <Pcf/System/Console.hpp>
#include <Pcf/System/Environment.hpp>
#include <Pcf/System/String.hpp>
#include <Pcf/Startup.hpp>

using namespace System;
using namespace Microsoft::Win32;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      ConsoleColor backColor = Console::BackgroundColor;
      ConsoleColor foreColor = Console::ForegroundColor;

      Console::BackgroundColor = ConsoleColor::Gray;
      Console::WriteLine("                    ");

      Console::BackgroundColor = ConsoleColor::DarkGray;
      Console::WriteLine("                    ");

      Console::BackgroundColor = backColor;

      Console::ForegroundColor = ConsoleColor::Gray;
      Console::WriteLine("████████████████████");

      Console::ForegroundColor = ConsoleColor::DarkGray;
      Console::WriteLine("████████████████████");

      Console::BackgroundColor = backColor;
      Console::ForegroundColor = foreColor;
    }
  };
}

pcf_startup (Examples::Program)

