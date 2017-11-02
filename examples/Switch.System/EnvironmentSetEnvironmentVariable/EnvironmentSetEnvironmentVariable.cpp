#include <Switch/Switch>

using namespace System;
using namespace System::IO;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      string value;
      bool toDelete = false;
      
      // Check whether the environment variable exists.
      value = Environment::GetEnvironmentVariable("Test1");
      // If necessary, create it.
      if (string::IsNullOrEmpty(value)) {
        Environment::SetEnvironmentVariable("Test1", "Value1");
        toDelete = true;
        
        // Now retrieve it.
        value = Environment::GetEnvironmentVariable("Test1");
      }
      // Display the value.
      Console::WriteLine("Test1: {0}\n", value);
      
      // Confirm that the value can only be retrieved from the process
      // environment block.
      Console::WriteLine("Attempting to retrieve Test1 from:");
      for (EnvironmentVariableTarget enumValue : Enum<EnvironmentVariableTarget>::GetValues()) {
        value = Environment::GetEnvironmentVariable("Test1", enumValue);
        Console::WriteLine("   {0}: {1}", enumValue, !string::IsNullOrEmpty(value) ? value : "not found");
      }
      Console::WriteLine();
      
      // If we've created it, now delete it.
      if (toDelete) {
        Environment::SetEnvironmentVariable("Test1", "");
        // Confirm the deletion.
        if (Environment::GetEnvironmentVariable("Test1") == "")
          Console::WriteLine("Test1 has been deleted.");
      }
    }
  };
}

_startup(Examples::Program)


// This example produces results similar to the following if you run it on Windows:
//
// Test1: Value1
//
// Attempting to retrieve Test1 from:
//   Process: Value1
//   User: not found
//   Machine: not found
//
//  Test1 has been deleted.
