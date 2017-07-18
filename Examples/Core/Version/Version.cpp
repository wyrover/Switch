#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Get the operating system version.
      OperatingSystem os = Environment::OSVersion;
      Version ver = os.Version;
      Console::WriteLine("Operating System: {0} ({1})", os.VersionString, ver.ToString());
    }
  };
}

pcf_startup (Examples::Program)

// This code can produces the following output if you run it on macOS Sierra :
//
// Operating System: macOS 10.12.5.0 (10.12.5.0)

