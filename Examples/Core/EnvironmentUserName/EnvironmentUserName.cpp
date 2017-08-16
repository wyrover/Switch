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
      Console::WriteLine("UserName: {0}", Environment::UserName);
    }
  };
}

pcf_startup (Examples::Program)

// This example produces results similar to the following:
//
//
// UserName: !---OMITTED---!
