#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program : public object {
  public:
    // The main entry point for the application.
    static void Main() {
      // Write arguments to the console output
      for (string arg : Environment::GetCommandLineArgs())
        Console::WriteLine(arg);
      
      // return 42
      Environment::ExitCode = 42;
    }
  };
}

_startup(Examples::Program)
// _startup(Examples::Program) is same as :
//
// int main(int argc, char* argv[]) {
//   Environment::SetCommandLineArgs(argv, argc)
//   Examples::Program::Main();
//   return Environment::ExitCode;
// }


// This code produces the following output if One Two "Three Four" Five are entered on command line:
//
// /!---OMITTED---!/Main1
// One
// Two
// Three Four
// Five
