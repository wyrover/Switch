#include <Pcf/Microsoft/Win32/Registry.hpp>
#include <Pcf/System/IO/Path.hpp>
#include <Pcf/System/Console.hpp>
#include <Pcf/System/Environment.hpp>
#include <Pcf/System/String.hpp>
#include <Pcf/Startup.hpp>

using namespace System;
using namespace Microsoft::Win32;

namespace Examples {
  class Application {
  public:
    static void Run() {
      bool cursorVisible = Console::CursorVisible;
      ConsoleColor backColor = Console::BackgroundColor;
      ConsoleColor foreColor = Console::ForegroundColor;
      int32 windowWidth = Console::WindowWidth;
      int32 windowHeight = Console::WindowHeight;
      int32 bufferWidth = Console::BufferWidth;
      int32 bufferHeight = Console::BufferHeight;
      string title = Console::Title;

      Console::WindowWidth = 80;
      Console::WindowHeight = 25;
      Console::BufferWidth = 80;
      Console::BufferHeight = 25;
      Console::Title = System::IO::Path::GetFileNameWithoutExtension(Environment::GetCommandLineArgs()[0]);

      Console::CursorVisible = false;
      Console::BackgroundColor = ConsoleColor::Gray;
      Console::ForegroundColor = ConsoleColor::DarkBlue;
      Console::Clear();

      string line(u'▒', Console::WindowWidth);
      for (int y = 1; y < Console::WindowHeight - 1; y++) {
        Console::SetCursorPosition(0, y);
        Console::Write(line);
      }

      Console::BackgroundColor = ConsoleColor::Gray;
      Console::ForegroundColor = ConsoleColor::DarkRed;
      Console::SetCursorPosition(1, 0);
      Console::Write(u'≡');

      Console::BackgroundColor = ConsoleColor::Gray;
      Console::ForegroundColor = ConsoleColor::Black;
      Console::SetCursorPosition(4, 0);
      Console::Write("File  Edit  Windows");

      Console::BackgroundColor = ConsoleColor::Gray;
      Console::ForegroundColor = ConsoleColor::DarkRed;
      Console::SetCursorPosition(1, Console::WindowHeight - 1);
      Console::Write("Ctrl-X");
      
      Console::BackgroundColor = ConsoleColor::Gray;
      Console::ForegroundColor = ConsoleColor::Black;
      Console::SetCursorPosition(8, Console::WindowHeight - 1);
      Console::Write("Exit");
      
      MessageLoop();

      Console::BackgroundColor = backColor;
      Console::ForegroundColor = foreColor;
      Console::BufferWidth = bufferWidth;
      Console::BufferHeight = bufferHeight;
      Console::WindowWidth = windowWidth;
      Console::WindowHeight = windowHeight;
      Console::Title = title;
      Console::Clear();
      Console::CursorVisible = cursorVisible;
    }

  private:
    static void MessageLoop() {
      while (true) {
        //System::Diagnostics::Debug::WriteLine("MessageLoop");
        if (Console::KeyAvailable) {
          ConsoleKeyInfo keyInfo = Console::ReadKey(true);
          if (keyInfo.Key == ConsoleKey::X && (keyInfo.Modifiers == ConsoleModifiers::Alt || keyInfo.Modifiers == ConsoleModifiers::Control)) break;
        }
      }
    }
  };

  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine(); Application::Run();
    }
  };
}

pcf_startup (Examples::Program)

