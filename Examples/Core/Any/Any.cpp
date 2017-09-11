#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create an empty a.
      any a;
      Console::WriteLine("a {0} value", a.HasValue ? "has" : "hasn't");
      Console::WriteLine("a = {0}", a);
      Console::WriteLine();
     
      // Assign integer to a
      a = 42;
      Console::WriteLine("a = {0}", a);
      Console::WriteLine("a {0} int", is<int32>(a) ? "is" : "isn't");
      Console::WriteLine("a {0} string", is<string>(a) ? "is" : "isn't");
      int i = a;
      Console::WriteLine("i = {0}", i);
      Console::WriteLine();
      
      // Assign string to a
      a = "Hello, World!";
      Console::WriteLine("a = {0}", a);
      Console::WriteLine("a {0} int", is<int32>(a) ? "is" : "isn't");
      Console::WriteLine("a {0} string", is<string>(a) ? "is" : "isn't");
      string s = a;
      Console::WriteLine("s = {0}", s);
      Console::WriteLine();

      // Cast any of type string into a int
      try {
        int i2 = a;
        Console::WriteLine("i2 = {0}", i2);
      } catch (const InvalidCastException&) {
        Console::WriteLine("a cannot cast in int");
      }
    }
  };
}

startup (Examples::Program)

// This code produces the following output:
//
// a hasn't value
// a =
//
// a = 42
// a is int
// a isn't string
// i = 42
//
// a = Hello, World!
// a isn't int
// a is string
// s = Hello, World!
//
// a cannot cast in int
