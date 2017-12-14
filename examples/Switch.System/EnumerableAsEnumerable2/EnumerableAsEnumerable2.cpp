#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create a c++ native array.
      string fruits[] = { "apple", "passionfruit", "banana", "mango", "orange", "blueberry", "grape", "strawberry" };

      // transform c++ aray to Enumerable and call Where method.
      refptr<IEnumerable<string>> query = Enumerable::AsEnumerable(fruits)->Where(_delegate(string fruit) { return fruit.Contains("o");});

      // Display the output.
      Console::WriteLine("query = {{{0}}}", string::Join(", ", *query));
    }
  };
}

_startup(Examples::Program);

// This code example produces the following output:
//
// query = {passionfruit, mango, orange}


