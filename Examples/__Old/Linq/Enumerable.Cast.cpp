#include <Pcf/Pcf>

using namespace System;
using namespace System::Linq;
using namespace System::Collections::Generic;

int main(int argc, char* argv[]) {
  // Create a list of object.
  Collections::ArrayList fruits;
  fruits.Add("mango");
  fruits.Add("apple");
  fruits.Add("lemon");
  
  Up<IEnumerable<Sp<string>>> query = fruits.Cast<Sp<string>>();
  
  for (Sp<string> fruit : *query) {
    Console::WriteLine(*fruit);
  }
}

// This code produces the following output:
//
// mango
// apple
// lemon
//
