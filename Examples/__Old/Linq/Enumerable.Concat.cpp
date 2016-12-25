#include <Pcf/Pcf>

using namespace System;
using namespace System::Linq;
using namespace System::Collections::Generic;

int main(int argc, char* argv[]) {
  // Create a list of object.
  Array<string> cats = {"Barley", "Boots", "Whiskers"};
  Array<string> dogs = {"Bounder", "Snoopy", "Fido"};
  
  Up<IEnumerable<string>> query = cats.Concat(dogs);
  
  for (string name : *query) {
    Console::WriteLine(name);
  }
}

// This code produces the following output:
//
// Barley
// Boots
// Whiskers
// Bounder
// Snoopy
// Fido
//
