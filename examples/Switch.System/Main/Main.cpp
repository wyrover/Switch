#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program : public object {
  public:
    // The main entry point for the application.
    static int Main(const Array<string>& args) {
      int number;
      if (args.Count != 1 || Int32::TryParse(args[0], number) == false || number < 0 || number > 20) {
        Console::WriteLine("Please enter an integer argument betwween 0 and 20.");
        Console::WriteLine("Usage: Factorial <integer>");
        return -1;
      }

      Console::WriteLine("The Factorial of {0} is {1}", number, delegate_ {
        int64 result = 1;
        for (int i = 1; i <= number; ++i)
          result *= i;
        return result;
      }());
      return 0;
    }
  };
}

startup_(Examples::Program);

// This code produces the following output if 3 is entered on command line:
//
// The factorial of 3 is 6.
