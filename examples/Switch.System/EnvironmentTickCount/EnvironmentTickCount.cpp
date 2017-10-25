#include <Switch/Switch>

using namespace System;

// TickCount cycles between Int32.MinValue, which is a negative
// number, and Int32.MaxValue once every 49.8 days. This sample
// removes the sign bit to yield a nonnegative number that cycles
// between zero and Int32.MaxValue once every 24.9 days.

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      int result = Environment::TickCount & Int32::MaxValue;
      Console::WriteLine("TickCount: {0}", result);
    }
  };
}

_startup (Examples::Program)

// This example produces results similar to the following:
//
// TickCount: 1739655579

