#define TRACE

#include <Switch/Nameof.hpp>
#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      byte value = 0;
      Console::WriteLine("value = {0}", _nameof(value));
      Console::WriteLine("value = {0}", _typeof(value));
      Console::WriteLine("value = {0}", value);
    }
  };
}

_startup (Examples::Program)
