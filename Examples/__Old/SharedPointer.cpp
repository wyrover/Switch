#include <Pcf/Pcf>

using namespace System;

int main(int argc, char* argv[]) {
  sp<string> p1 = sp<string>::Create("First string****");
  
  if (!p1)
    Console::WriteLine("p1 == null");
  
  Console::WriteLine("*p1 = {0}", *p1);
  Console::WriteLine("p1 UseCount =  {0}{1}", p1.GetUseCount(), Environment::NewLine);
  
  pcf_using (Sp<string> p2 = p1) {
    Console::WriteLine("*p2 = {0}", *p2);
    Console::WriteLine("p1 UseCount =  {0}{1}", p1.GetUseCount(), Environment::NewLine);
    
    *p2 = p2->TrimEnd('*');
    
    Console::WriteLine("*p2 = {0}", *p2);
    Console::WriteLine("p2 UseCount =  {0}{1}", p2.GetUseCount(), Environment::NewLine);
  }
  
  Console::WriteLine("*p1 = {0}", *p1);
  Console::WriteLine("p1 UseCount =  {0}{1}", p1.GetUseCount(), Environment::NewLine);
  
  p1 = Sp<string>::Null();
  if (!p1)
    Console::WriteLine("p1 == null");
  Console::WriteLine("p1 UseCount =  {0}{1}", p1.GetUseCount(), Environment::NewLine);
}

// This code produces the following output :
//
// *p1 = First string****
// p1 UseCount =  1
//
// *p2 = First string****
// p1 UseCount =  2
//
// *p2 = Another string
// p2 UseCount =  2
//
// *p1 = Another string
// p1 UseCount =  1
//
// p1 == null
// p1 UseCount =  0
