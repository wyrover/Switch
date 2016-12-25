#include <Pcf/Pcf>

using namespace System;

int main(int argc, char* argv[]) {
  up<string> str = up<string>::Create("Hello world!");
  Console::WriteLine("str = {0}", str.ToString().c_str());
  Console::WriteLine(*str);
  str = up<string>::Create("another string !");
  Console::WriteLine("str = {0}", str.ToString().c_str());
  Console::WriteLine(*str);
  
  up<string> str2 = str;
  Console::WriteLine("str2 = {0}", str2.ToString().c_str());
  Console::WriteLine("str = {0}", str.ToString().c_str());
  Console::WriteLine(*str2);
  str2 = null;
  Console::WriteLine("str2 = {0}", str2.ToString().c_str());
  Sp<string> sp = Sp<string>::Create("Test sp");
  Console::WriteLine("sp = {0}", sp.ToString().c_str());
  up<int> a = up<int>::Create(234);
  Console::WriteLine("a = {0}", a.ToString().c_str());
  Sp<string> b;
  Console::WriteLine("b = {0}", b.ToString().c_str());
}

// This code produces the following output:
//
// str = Pcf::UniquePointer<Pcf::System::String> [Pointer=140704215999824]
// Hello world!
// str = Pcf::UniquePointer<Pcf::System::String> [Pointer=140704216001168]
// another string !
// str2 = Pcf::UniquePointer<Pcf::System::String> [Pointer=140704216001168]
// str = Pcf::UniquePointer<Pcf::System::String> [Pointer=null]
// another string !
// str2 = Pcf::UniquePointer<Pcf::System::String> [Pointer=null]
// sp = Pcf::SharedPointer<Pcf::System::String> [Pointer=140704215999520, UseCount=1]
// a = Pcf::UniquePointer<int> [Pointer=140704215998368]
// b = Pcf::SharedPointer<Pcf::System::String> [Pointer=null]
