#include <Pcf/Microsoft/Win32/Registry.hpp>
#include <Pcf/System/IO/Path.hpp>
#include <Pcf/System/Console.hpp>
#include <Pcf/System/Environment.hpp>
#include <Pcf/System/String.hpp>
#include <Pcf/System/TimeSpan.hpp>
#include <Pcf/System/Tuple.hpp>
#include <Pcf/Startup.hpp>

using namespace System;
using namespace Microsoft::Win32;

namespace Examples {
  class Application {
  public:
    static void Run() {
      bool cursorVisible = Console::CursorVisible;
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

      Console::ResetColor();
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
    template<typename T>
    static string Fct(InitializerList<T> il) {
      return string::Format("{{{0}}}", string::Join(", ", Array<T>(il)));
    }
    
    template<typename T>
    static string Fct(InitializerList<InitializerList<T>> il) {
      int32 length = -1;
      string result = "{";
      bool first = true;
      for (auto a : il) {
        if (length != -1 && length != (int32)a.size())
          throw ArgumentException(pcf_current_information);
        length = (int32)a.size();
        if (!first) result += ", ";
        result += string::Format("{{{0}}}", string::Join(", ", Array<T>(a)));
        first = false;
      }
      result += "}";
      return result;
    }
    
    template<typename T>
    static string Fct(InitializerList<InitializerList<InitializerList<T>>> il) {
      return string::Format("{{{0}}}", string::Join(", ", Array<T>(il)));
    }
    
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("1 = {0}", Fct<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}));
      Console::WriteLine("2 = {0}", Fct<int>({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}}));
      
      //Console::WriteLine(); Application::Run();
      
    }
  };
}

pcf_startup (Examples::Program)

