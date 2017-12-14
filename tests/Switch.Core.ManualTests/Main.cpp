#include <Switch/Startup.hpp>
#include <Switch/System/Boolean.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Guid.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("Time since boot : {0}", TimeSpan::FromMilliseconds(Environment::TickCount & Int32::MaxValue));
    }
  };
}

_startup(Examples::Program);
