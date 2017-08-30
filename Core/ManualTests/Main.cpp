#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      r<Version> version = ref_new<Version>(1, 2, 3);
      Console::WriteLine("version = {0}", version());
    }
  };
}

pcf_startup (Examples::Program)

