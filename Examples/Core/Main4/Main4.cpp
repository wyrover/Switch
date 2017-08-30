#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program : public object {
  public:
    // The main entry point for the application.
    static int Main(const Array<string>& args) {
      // Write arguments to the console output
      for (string arg : args)
        Console::WriteLine(arg);
      
      return 42;
    }
  };
}

sw_startup (Examples::Program)
// sw_startup (Examples::Program) is same as :
//
// int main(int argc, char* argv[]) {
//   return Examples::Program::Main(Environment::SetCommandLineArgs(argv, argc));
// }


// This code produces the following output if One Two "Three Four" Five are entered on command line:
//
// One
// Two
// Three Four
// Five
