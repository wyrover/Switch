#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<char32> chars = { 'w', 'o', 'r', 'd' };
      Array<sbyte> bytes = { 0x41, 0x42, 0x43, 0x44, 0x45, 0x00 };
      char cstr[] = "12345";
      
      // Create a string from a character array.
      string string1(chars);
      Console::WriteLine(string1);
      
      // Create a string that consists of a character repeated 20 times.
      string string2('c', 20);
      Console::WriteLine(string2);
      
      // Create a string from a pointer to a signed byte array.
      string stringFromBytes(bytes);
      
      // Create a string from a pointer to a character array.
      string stringFromChars(cstr);
      
      Console::WriteLine(stringFromBytes);
      Console::WriteLine(stringFromChars);
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// word
// cccccccccccccccccccc
// ABCDE
// 12345
