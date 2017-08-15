#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine();
      Console::WriteLine("NewLine: {0}  first line{0}  second line{0}  third line", Environment::NewLine);
    }
  };
}

pcf_startup (Examples::Program)

// This example produces results similar to the following:
//
//
// NewLine:
//   first line
//   second line
//   third line
