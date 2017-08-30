#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("WorkingSet: {0}", Environment::WorkingSet);
    }
  };
}

sw_startup (Examples::Program)


// This example produces results similar to the following:
//
// WorkingSet: 5038080
