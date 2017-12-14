#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      List<int> grades = {78, 92, 100, 37, 81};

      double average = grades.Average();

      Console::WriteLine("The average grade is {0}.", average);
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// The average grade is 77.6.
