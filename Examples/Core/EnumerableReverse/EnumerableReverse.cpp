#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<char32> apple = {'a', 'p', 'p', 'l', 'e'};
      
      refptr<IEnumerable<char32>> reversed = apple.Enumerable::Reverse();
      for (char32 chr : *reversed)
        Console::Write(string::Format("{0} ", chr));
      
      Console::WriteLine();
    }
  };
}

startup (Examples::Program)

// This code produces the following output:
//
// e l p p a
