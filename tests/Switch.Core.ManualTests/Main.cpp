#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("Hello, World!");
      for (auto& value : Enum<>::GetValues<Environment::SpecialFolderOption>())
        Console::WriteLine("{0}", value);
    }
  };
}

startup_(Examples::Program);
