#define TRACE
#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#
using namespace System;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("Switch version = {0}", Environment::Version);
    }
  };
}

_startup (Examples::Program)
