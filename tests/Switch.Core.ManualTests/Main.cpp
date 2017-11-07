#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      if ("value" == "value"_s)
        Console::WriteLine("equal");
      Console::WriteLine("Test");
    }
  };
}

_startup(Examples::Program)
