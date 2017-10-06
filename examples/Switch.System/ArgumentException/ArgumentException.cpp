#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // ArgumentException is not thrown because 10 is an even number.
      Console::WriteLine("10 divided by 2 is {0}", DivideByTwo(10));
      try {
        // ArgumentException is thrown because 7 is not an even number.
        Console::WriteLine("7 divided by 2 is {0}", DivideByTwo(7));
      }
      catch (const ArgumentException&) {
        // Show the user that 7 cannot be divided by 2.
        Console::WriteLine("7 is not divided by 2 integrally.");
      }
    }
    
  private:
    static int DivideByTwo(int num) {
      // If num is an odd number, throw an ArgumentException.
      if ((num & 1) == 1)
        throw ArgumentException("Number must be even");
      
      // num is even, return half of its value.
      return num / 2;
    }
  };
}

_startup (Examples::Program)

// This code produces the following output:
//
// 10 divided by 2 is 5
// 7 is not divided by 2 integrally.
