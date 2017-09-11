#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create a list of object.
      Array<string> cats = {"Barley", "Boots", "Whiskers"};
      Array<string> dogs = {"Bounder", "Snoopy", "Fido"};
      
      refptr<IEnumerable<string>> query = cats.Concat(dogs);
      
      for (string name : *query) {
        Console::WriteLine(name);
      }
    }
  };
}

startup (Examples::Program)

// This code produces the following output:
//
// Barley
// Boots
// Whiskers
// Bounder
// Snoopy
// Fido
//
