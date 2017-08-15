#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine();
      //  <-- Keep this information secure! -->
      Console::WriteLine("MachineName: {0}", Environment::MachineName);
    }
  };
}

pcf_startup (Examples::Program)

// This example produces results similar to the following:
//
//
// MachineName: !---OMITTED---!
