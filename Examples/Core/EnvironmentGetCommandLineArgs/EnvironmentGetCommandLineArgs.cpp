#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine();
      //  Invoke this sample with an arbitrary set of command line arguments.
      Array<String> arguments = Environment::GetCommandLineArgs();
      Console::WriteLine("GetCommandLineArgs: {0}", String::Join(", ", arguments));
    }
  };
}

pcf_startup (Examples::Program)


// This example produces results similar to the following:
//
// >EnvironmentGetCommandLineArgs ARBITRARY TEXT
//
// GetCommandLineArgs: /!---OMITTED---!/EnvironmentGetCommandLineArgs, ARBITRARY, TEXT
