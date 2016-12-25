#include <Pcf/Pcf>

using namespace System;

int main(int argc, char* argv[]) {
  Sp<Object> object1 = Sp<Object>::Create();
  Sp<Object> object2 = Sp<Object>::Create();
  
  Sp<Object> object3 = object2;
  Console::WriteLine(object1->Equals(*object3));
  object3 = object1;
  Console::WriteLine(object1->Equals(*object3));
}

// This code produces the following output:
//
// False
// True
