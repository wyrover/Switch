#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("The number of processors on this computer is {0}.", Environment::ProcessorCount);
    }
  };
}

pcf_startup (Examples::Program)


// This example produces results similar to the following:
//
// The number of processors on this computer is 8.