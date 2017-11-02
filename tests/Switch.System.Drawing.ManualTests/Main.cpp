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
    }
  };
}

_startup(Examples::Program)
