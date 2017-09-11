#include <Switch/Switch>

using namespace System;
using namespace System::Linq;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<string> fruits = {"apple", "mango", "orange", "passionfruit", "grape"};
      
      // Determine whether any string in the array is longer than "banana".
      string longestName =
      fruits.Agregate<string, string>("bananas",
                                      _delegate(const string& longest, const string& next) {
                                        return next.Length > longest.Length ? next : longest;
                                      },
                                      // Return the final result as an upper case string.
                                      _delegate(const string& fruit) {
                                        return fruit.ToUpper();
                                      });
      
      Console::WriteLine("The fruit with the longest name is {0}", longestName);
    }
  };
}

startup (Examples::Program)

// This code produces the following output:
//
// The fruit with the longest name is PASSIONFRUIT.
//
