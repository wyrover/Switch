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
      std::cout << Boolean {true} << std::endl;
    }
  };
}

_startup(Examples::Program);
