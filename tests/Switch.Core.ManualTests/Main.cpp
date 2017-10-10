#define TRACE
#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>

using namespace System;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
    }
  };
}

_startup (Examples::Program)
