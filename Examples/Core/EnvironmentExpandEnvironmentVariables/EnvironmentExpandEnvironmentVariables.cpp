#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      String str;
      String nl = Environment::NewLine;
      
      Console::WriteLine();
      //  <-- Keep this information secure! -->
      String query = "My system drive is %SystemDrive% and my system root is %SystemRoot%";
      str = Environment::ExpandEnvironmentVariables(query);
      Console::WriteLine("ExpandEnvironmentVariables: {0}  {1}", nl, str);
    }
  };
}

startup (Examples::Program)


// This example produces results similar to the following:
//
// ExpandEnvironmentVariables:
//   My system drive is C: and my system root is C:\windows
