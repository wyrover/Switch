#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      int value = 12345678;
      Array<byte> bytes = BitConverter::GetBytes(value);
      Console::WriteLine(BitConverter::ToString(bytes));

      if (BitConverter::IsLittleEndian)
        Array<>::Reverse(bytes);

      Console::WriteLine(BitConverter::ToString(bytes));
      // Call method to send byte stream across machine boundaries.

      // Receive byte stream from beyond machine boundaries.
      Console::WriteLine(BitConverter::ToString(bytes));
      if (BitConverter::IsLittleEndian)
        Array<>::Reverse(bytes);

      Console::WriteLine(BitConverter::ToString(bytes));
      int result = BitConverter::ToInt32(bytes, 0);
      Console::WriteLine("Original value: {0}", value);
      Console::WriteLine("Returned value: {0}", result);
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// 4E-61-BC-00
// 00-BC-61-4E
// 00-BC-61-4E
// 4E-61-BC-00
// Original value: 12345678
// Returned value: 12345678
