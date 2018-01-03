#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program : public object {
  public:
    // The main entry point for the application.
    static void Main(const Array<string>& args) {
      // Write arguments to the console output
      for (string arg : args)
        Console::WriteLine(arg);

      // return 42
      Environment::ExitCode = 42;
    }
  };
}

startup_(Examples::Program);
// startup_(Examples::Program); is same as :
//
// int main(int argc, char* argv[]) {
//   Examples::Program::Main(Environment::SetCommandLineArgs(argv, argc));
//   return Environment::ExitCode;
// }


// This code produces the following output if One Two "Three Four" Five are entered on command line:
//
// One
// Two
// Three Four
// Five
