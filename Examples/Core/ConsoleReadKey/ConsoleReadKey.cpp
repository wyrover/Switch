#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::CancelKeyPress += pcf_delegate(const object& sender, System::ConsoleCancelEventArgs& e) {
        Console::WriteLine("Signal {0} intercepted !", e.SpecialKey);
        e.Cancel = true;
      };
      
      while (true) {
        if (Console::KeyAvailable) {
          ConsoleKeyInfo keyInfo = Console::ReadKey(true);
          Console::WriteLine("Key = {0} ({1}), Char = '{2}' ({3}), Modifiers = {4}", keyInfo.Key, Convert::ToInt32(keyInfo.Key), keyInfo.KeyChar, Convert::ToInt32(keyInfo.KeyChar), keyInfo.Modifiers);
          if (keyInfo.Key == ConsoleKey::Escape) break;
        }
      }
    }
  };
}

pcf_startup (Examples::Program)
