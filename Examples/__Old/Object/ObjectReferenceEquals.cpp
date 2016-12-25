#include <Pcf/Pcf>

using namespace System;

int main(int argc, char* argv[]) {
  Object* o = null;
  Object* p = null;
  Object* q = new Object();
  
  Console::WriteLine(Object::ReferenceEquals(*o, *p));
  p = q;
  Console::WriteLine(Object::ReferenceEquals(*p, *q));
  Console::WriteLine(Object::ReferenceEquals(*o, *p));
  delete(q);
}

// This code produces the following output:
//
// True
// True
// False
