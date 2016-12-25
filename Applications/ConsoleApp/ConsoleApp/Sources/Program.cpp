#include <Pcf/Pcf>

using namespace System;

namespace ConsoleApp {
  class Program {
  public:
    /// @brief The main entry point for the application.
    static void Main() {
      Console::WriteLine("Hello, World!");
      Console::WriteLine("Привет мир!");
      Console::WriteLine("こんにちは世界!");
    }
  };
}

pcf_startup (ConsoleApp::Program)
