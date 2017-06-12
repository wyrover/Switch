#include <Pcf/Pcf>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create a list of object.
      Collections::ArrayList fruits;
      fruits.Add("mango");
      fruits.Add("apple");
      fruits.Add("lemon");
      
      refptr<IEnumerable<string>> query = fruits.Cast<string>();
      
      for (string fruit : *query) {
        Console::WriteLine(fruit);
      }
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// mango
// apple
// lemon
//
