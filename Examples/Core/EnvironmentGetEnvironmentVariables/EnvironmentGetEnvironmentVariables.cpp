#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine();
      Console::WriteLine("GetEnvironmentVariables: ");
      for (auto de : Environment::GetEnvironmentVariables())
        Console::WriteLine("  {0} = {1}", de.Key, de.Value);
    }
  };
}

pcf_startup (Examples::Program)


// Output from the example is not shown, since it is:
//    Lengthy.
//    Specific to the machine on which the example is run.
//    May reveal information that should remain secure.
