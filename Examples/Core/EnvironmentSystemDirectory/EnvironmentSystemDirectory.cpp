#include <Pcf/Pcf>

using namespace System;
using namespace System::Collections;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine();
      //  <-- Keep this information secure! -->
      Console::WriteLine("SystemDirectory: {0}", Environment::SystemDirectory);
    }
  };
}

pcf_startup (Examples::Program)

// This example produces results similar to the following if you run it on Windows 10:
//
// SystemDirectory: C:\Windows\System32

