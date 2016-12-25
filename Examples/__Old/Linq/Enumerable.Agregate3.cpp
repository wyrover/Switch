#include <Pcf/Pcf>

using namespace System;
using namespace System::Linq;

int main(int argc, char* argv[]) {
  Array<string> fruits = {"apple", "mango", "orange", "passionfruit", "grape"};
  
  // Determine whether any string in the array is longer than "banana".
  string longestName =
  fruits.Agregate<string, string>("bananas",
                                  [&](const string& longest, const string& next) {
                                    return next.Length > longest.Length ? next : longest;
                                  },
                                  // Return the final result as an upper case string.
                                  [&](const string& fruit) {
                                    return fruit.ToUpper();
                                  });
  
  Console::WriteLine("The fruit with the longest name is {0}", longestName);
}

// This code produces the following output:
//
// The fruit with the longest name is PASSIONFRUIT.
//
