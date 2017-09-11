#include <Switch/Switch>

using namespace System;

namespace Examples {
  // Declares a delegate for a method that takes in an Int32 and returns a string.
  using MyMethodDelegate = Delegate<string, int>;
  
  // Defines some methods to which the delegate can point.
  class Program : public object {
  public:
    // The main entry point for the application.
    static void Main() {
      // Creates one delegate for each method. For the instance method, an
      // instance (mySC) must be supplied. For the static method, use the
      // class name.
      Examples::Program mySC;
      Examples::MyMethodDelegate myD1(mySC, &Examples::Program::MyStringMethod);
      Examples::MyMethodDelegate myD2(&Examples::Program::MySignMethod);
      
      // Invokes the delegates.
      Console::WriteLine("{0} is {1}; use the sign \"{2}\".", 5, myD1(5), myD2(5));
      Console::WriteLine("{0} is {1}; use the sign \"{2}\".", -3, myD1(-3), myD2(-3));
      Console::WriteLine("{0} is {1}; use the sign \"{2}\".", 0, myD1(0), myD2(0));
    }

  private:
    // Defines an instance method.
    string MyStringMethod(int myInt) {
      if (myInt > 0) {
        return "positive";
      }
      if (myInt < 0) {
        return "negative";
      }
      return "zero";
    }
    
    // Defines a static method.
    static string MySignMethod(int myInt) {
      if (myInt > 0) {
        return "+";
      }
      if (myInt < 0) {
        return "-";
      }
      return "";
    }
  };
}

startup (Examples::Program)

// This code produces the following output:
//
// 5 is positive; use the sign "+".
// -3 is negative; use the sign "-".
// 0 is zero; use the sign "".
