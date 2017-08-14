#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    static const string formatter;
    
    // Convert a double argument to a byte array and display it.
    static void GetBytesInt16(int16 argument) {
      Array<byte> byteArray = BitConverter::GetBytes(argument);
      Console::WriteLine(formatter, argument, BitConverter::ToString(byteArray));
    }

    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("This example of the BitConverter.GetBytes(int16) "
                         "\nmethod generates the following output.\n");
      Console::WriteLine(formatter, "int16", "byte array");
      Console::WriteLine(formatter, "------", "----------");
      
      // Convert int16 values and display the results.
      GetBytesInt16(0);
      GetBytesInt16(15);
      GetBytesInt16(-15);
      GetBytesInt16(10000);
      GetBytesInt16(-10000);
      GetBytesInt16(Int16::MinValue);
      GetBytesInt16(Int16::MaxValue);
    }
  };
  
  const string Program::formatter = "{0,10}{1,13}";
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// This example of the BitConverter.GetBytes(int16)
// method generates the following output.
//
//      int16   byte array
//     ------   ----------
//          0        00-00
//         15        0F-00
//        -15        F1-FF
//      10000        10-27
//     -10000        F0-D8
//     -32768        00-80
//      32767        FF-7F
