#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program : public object {
  public:
    // The main entry point for the application.
    static int Main() {
      // write arguments to the console
      for (string arg : Environment::GetCommandLineArgs())
        Console::WriteLine(arg);
      
      return 42;
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output if One Two "Three Four" Five are entered on command line:
//
// /!---OMITTED---!/Main1
// One
// Two
// Three Four
// Five
