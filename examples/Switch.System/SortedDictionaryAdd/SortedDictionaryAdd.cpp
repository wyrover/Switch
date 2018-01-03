#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create a new dictionary of int, with string keys.
      //
      SortedDictionary<string, int> numbers;

      // Add some elements to the dictionary.
      numbers.Add("One", 1);
      numbers.Add("Two", 2);
      numbers.Add("Tree", 3);
      numbers.Add("Four", 4);
      numbers.Add("Five", 5);
      numbers.Add("Six", 6);
      numbers.Add("Seven", 7);
      numbers.Add("Eigth", 8);
      numbers.Add("Nine", 9);
      numbers.Add("Ten", 10);

      // Show the dictionary elements.
      Console::WriteLine("numbers[\"One\"]   -> "_s + numbers["One"]);
      Console::WriteLine("numbers[\"Two\"]   -> "_s + numbers["Two"]);
      Console::WriteLine("numbers[\"Tree\"]  -> "_s + numbers["Tree"]);
      Console::WriteLine("numbers[\"Four\"]  -> "_s + numbers["Four"]);
      Console::WriteLine("numbers[\"Five\"]  -> "_s + numbers["Five"]);
      Console::WriteLine("numbers[\"Six\"]   -> "_s + numbers["Six"]);
      Console::WriteLine("numbers[\"Seven\"] -> "_s + numbers["Seven"]);
      Console::WriteLine("numbers[\"Eigth\"] -> "_s + numbers["Eigth"]);
      Console::WriteLine("numbers[\"Nine\"]  -> "_s + numbers["Nine"]);
      Console::WriteLine("numbers[\"Ten\"]   -> "_s + numbers["Ten"]);
    }
  };
}

startup_(Examples::Program);

// This code example produces the following output:
//
// numbers["One"]   -> 1
// numbers["Two"]   -> 2
// numbers["Tree"]  -> 3
// numbers["Four"]  -> 4
// numbers["Five"]  -> 5
// numbers["Six"]   -> 6
// numbers["Seven"] -> 7
// numbers["Eigth"] -> 8
// numbers["Nine"]  -> 9
// numbers["Ten"]   -> 10
