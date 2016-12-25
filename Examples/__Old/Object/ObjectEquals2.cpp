#include <Pcf/Pcf>

using namespace System;

int main(int argc, char* argv[]) {
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

// This code produces the following output:
//
// Object::Equals("Tom", "Carol") => False
// Object::Equals("Tom", "Tom") => True
// Object::Equals("", "Tom") => False
// Object::Equals("Carol", "") => False
// Object::Equals("", "") => True
