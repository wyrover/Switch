#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Boolean flag = true;
      
      byte byteValue;
      byteValue = Convert::ToByte(flag);
      Console::WriteLine("{0} -> {1}", flag, byteValue);
      
      sbyte sbyteValue;
      sbyteValue = Convert::ToSByte(flag);
      Console::WriteLine("{0} -> {1}", flag, sbyteValue);
      
      double dblValue;
      dblValue = Convert::ToDouble(flag);
      Console::WriteLine("{0} -> {1}", flag, dblValue);
      
      int intValue;
      intValue = Convert::ToInt32(flag);
      Console::WriteLine("{0} -> {1}", flag, intValue);
    }
  };
}

sw_startup (Examples::Program)

// This code produces the following output:
//
// True -> 1
// True -> 1
// True -> 1
// True -> 1
