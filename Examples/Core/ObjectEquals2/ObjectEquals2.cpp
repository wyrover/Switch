#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      string s1 = "Tom";
      string s2 = "Carol";
      Console::WriteLine("Object::Equals(\"{0}\", \"{1}\") => {2}", s1, s2, Object::Equals(s1, s2));
      
      s1 = "Tom";
      s2 = "Tom";
      Console::WriteLine("Object::Equals(\"{0}\", \"{1}\") => {2}", s1, s2, Object::Equals(s1, s2));
      
      s1 = "";
      s2 = "Tom";
      Console::WriteLine("Object::Equals(\"{0}\", \"{1}\") => {2}", s1, s2, Object::Equals(s1, s2));
      
      s1 = "Carol";
      s2 = "";
      Console::WriteLine("Object::Equals(\"{0}\", \"{1}\") => {2}", s1, s2, Object::Equals(s1, s2));
      
      s1 = "";
      s2 = "";
      Console::WriteLine("Object::Equals(\"{0}\", \"{1}\") => {2}", s1, s2, Object::Equals(s1, s2));
    }
  };
}

startup (Examples::Program)

// This code produces the following output:
//
// Object::Equals("Tom", "Carol") => False
// Object::Equals("Tom", "Tom") => True
// Object::Equals("", "Tom") => False
// Object::Equals("Carol", "") => False
// Object::Equals("", "") => True
