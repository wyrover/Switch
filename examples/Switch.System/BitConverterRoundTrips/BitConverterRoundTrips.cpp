#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      int value = -16;
      Array<byte> bytes = BitConverter::GetBytes(value);
      
      // Convert bytes back to Int32.
      int intValue = BitConverter::ToInt32(bytes, 0);
      Console::WriteLine("{0} = {1}: {2}", value, intValue, Int32(value).Equals(intValue) ? "Round-trips" : "Does not round-trip");
      // Convert bytes to UInt32.
      uint uintValue = BitConverter::ToUInt32(bytes, 0);
      Console::WriteLine("{0} = {1}: {2}", value, uintValue, Int32(value).Equals(uintValue) ? "Round-trips" : "Does not round-trip");
    }
  };
}

_startup(Examples::Program)

// This code produces the following output:
//
// -16 = -16: Round-trips
// -16 = 4294967280: Does not round-trip
