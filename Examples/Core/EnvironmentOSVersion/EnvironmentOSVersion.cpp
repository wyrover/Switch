#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine();
      Console::WriteLine("OSVersion: {0}", Environment::OSVersion().ToString());
    }
  };
}

pcf_startup (Examples::Program)


// This example produces results similar to the following, if you run it on macOS Sierra:
//
//
// OSVersion: macOS 10.12.6.0
