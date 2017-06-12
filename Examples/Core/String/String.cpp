#include <Pcf/Pcf>

using namespace System;

int main(int argc, char* argv[]) {
  string s1 = "Hello, World!";
  Console::WriteLine(s1);
  string s2 = "Привет мир!";
  Console::WriteLine(s2);
  string s3 = "こんにちは世界！";
  Console::WriteLine(s3);
}

// This code produces the following output:
//
// Hello, World!
// Привет мир!
// ?こんにちは世界！
//
