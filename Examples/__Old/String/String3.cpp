#include <Pcf/Pcf>

using namespace System;

int main(int argc, char* argv[]) {
  string string1 = "Today is " + DateTime::Now + ".";
  Console::WriteLine(string1);
  
  string string2 = "This is one sentence. "_S + "This is a second. ";
  string2 += "This is a third sentence.";
  Console::WriteLine(string2);
}

// This code produces the following output:
//
// Today is 27/01/2014 11:36:14.
// This is one sentence. This is a second. This is a third sentence.
