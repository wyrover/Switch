#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      DateTime dateAndTime(2011, 7, 6, 7, 32, 0);
      double temperature = 24.6;
      string result = String::Format("At {0:t} on {0:D}, the temperature was {1:F1} degrees Fahrenheit.", dateAndTime, temperature);
      Console::WriteLine(result);
    }
  };
}

startup_(Examples::Program);

// This code produces the following output:
//
// At 06/07/2011 07:32:00 on 06/07/2011 07:32:00, the temperature was 24.6 degrees celcius.
