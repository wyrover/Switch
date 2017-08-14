#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    static const string formatter;
    
    // Convert a bool argument to a byte array and display it.
    static void GetBytesChar(Char argument) {
      Array<byte> byteArray = BitConverter::GetBytes(argument);
      Console::WriteLine(formatter, argument, BitConverter::ToString(byteArray));
    }

    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("This example of the BitConverter::GetBytes(char) "
                         "\nmethod generates the following output.\n");
      Console::WriteLine(formatter, "char", "byte array");
      Console::WriteLine(formatter, "----", "----------");
      
      // Convert bool values and display the results.
      GetBytesChar('\0');
      GetBytesChar(' ');
      GetBytesChar('*');
      GetBytesChar('3');
      GetBytesChar('A');
      GetBytesChar('[');
      GetBytesChar('a');
      GetBytesChar('{');
    }
  };
  
  const string Program::formatter = "{0,10}{1,16}";
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// This example of the BitConverter::GetBytes(char)
// method generates the following output.
//
// char          byte array
// ----          ----------
//              00-00-00-00
//              20-00-00-00
//    *         2A-00-00-00
//    3         33-00-00-00
//    A         41-00-00-00
//    [         5B-00-00-00
//    a         61-00-00-00
//    {         7B-00-00-00
