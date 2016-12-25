#include <Pcf/Pcf>

using namespace System;
using namespace System::Linq;
using namespace System::Collections::Generic;

int main(int argc, char* argv[]) {
  Array<char32> apple = {'a', 'p', 'p', 'l', 'e'};
  
  Up<IEnumerable<char32>> reversed = apple.Reverse();
  for (char32 chr : *reversed)
    Console::Write(string::Format("{0} ", chr));

  Console::WriteLine();
}

// This code produces the following output:
//
// e l p p a
