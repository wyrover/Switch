#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("This example of the BitConverter::GetBytes(bool)\n"
                         "method generates the following output.\n");
      Console::WriteLine("{0,10}{1,16}", "bool", "byte array");
      Console::WriteLine("{0,10}{1,16}", "----", "----------");
      
      // Convert bool values and display the results.
      GetBytesBool(false);
      GetBytesBool(true);
    }
    
  private:
    // Convert a bool argument to a byte array and display it.
    static void GetBytesBool(Boolean argument) {
      Array<byte> byteArray = BitConverter::GetBytes(argument);
      Console::WriteLine("{0,10}{1,16}", argument, BitConverter::ToString(byteArray));
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// This example of the BitConverter::GetBytes(bool)
// method generates the following output.
//
//       bool      byte array
//       ----      ----------
//      False              00
//       True              01
