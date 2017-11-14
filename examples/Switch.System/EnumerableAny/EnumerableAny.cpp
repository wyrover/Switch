#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      List<int> numbers = {1, 2};
      
      bool hasElements = numbers.Any();
      
      Console::WriteLine("The list {0} empty.", hasElements ? "is not" : "is");
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// The list is not empty.
//
