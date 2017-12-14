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
      Dictionary<string, int> numbers;

      // Add some elements to the dictionary.
      numbers["One"] = 1;
      numbers["Two"] = 2;
      numbers["Tree"] = 3;
      numbers["Four"] = 4;
      numbers["Five"] = 5;
      numbers["Six"] = 6;
      numbers["Seven"] = 7;
      numbers["Eigth"] = 8;
      numbers["Nine"] = 9;
      numbers["Ten"] = 10;

      // Show the dictionary elements.
      Console::WriteLine("numbers[\"One\"]   -> {0}", numbers["One"]);
      Console::WriteLine("numbers[\"Two\"]   -> {0}", numbers["Two"]);
      Console::WriteLine("numbers[\"Tree\"]  -> {0}", numbers["Tree"]);
      Console::WriteLine("numbers[\"Four\"]  -> {0}", numbers["Four"]);
      Console::WriteLine("numbers[\"Five\"]  -> {0}", numbers["Five"]);
      Console::WriteLine("numbers[\"Six\"]   -> {0}", numbers["Six"]);
      Console::WriteLine("numbers[\"Seven\"] -> {0}", numbers["Seven"]);
      Console::WriteLine("numbers[\"Eigth\"] -> {0}", numbers["Eigth"]);
      Console::WriteLine("numbers[\"Nine\"]  -> {0}", numbers["Nine"]);
      Console::WriteLine("numbers[\"Ten\"]   -> {0}", numbers["Ten"]);

      Console::WriteLine();
      for (KeyValuePair<string, int> item : numbers)
        Console::WriteLine("numbers[{0}] = {1}", item.Key(), item.Value());
    }
  };
}

_startup(Examples::Program);

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
//
// numbers[Ten] = 10
// numbers[Nine] = 9
// numbers[Seven] = 7
// numbers[Six] = 6
// numbers[Five] = 5
// numbers[Eigth] = 8
// numbers[Four] = 4
// numbers[Tree] = 3
// numbers[Two] = 2
// numbers[One] = 1
