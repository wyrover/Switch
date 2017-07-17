#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program : public object {
  public:
    // The main entry point for the application.
    static void Main(const Array<string>& args) {
      // write arguments to the console
      for (string arg : args)
        Console::WriteLine(arg);
      
      // return 42
      Environment::ExitCode = 42;
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output if One Two "Three Four" Five are entered on command line:
//
// One
// Two
// Three Four
// Five
