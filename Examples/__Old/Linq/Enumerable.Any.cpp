#include <Pcf/Pcf>

using namespace System;
using namespace System::Linq;
using namespace System::Collections::Generic;

int main(int argc, char* argv[]) {
  List<int> numbers = {1, 2};
  
  bool hasElements = numbers.Any();
  
  Console::WriteLine("The list {0} empty.", hasElements ? "is not" : "is");
}

// This code produces the following output:
//
// The list is not empty.
//
