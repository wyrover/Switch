#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      SortedSet<int> evenNumbers;
      SortedSet<int> oddNumbers;
      
      for (int i = 0; i < 5; i++) {
        // Populate numbers with just even numbers.
        evenNumbers.Add(i * 2);
        
        // Populate oddNumbers with just odd numbers.
        oddNumbers.Add((i * 2) + 1);
      }
      
      Console::Write("evenNumbers contains {0} elements: ", evenNumbers.Count);
      DisplaySet(evenNumbers);
      
      Console::Write("oddNumbers contains {0} elements: ", oddNumbers.Count);
      DisplaySet(oddNumbers);
      
      // Create a new SortedSet populated with even numbers.
      SortedSet<int> numbers(evenNumbers);
      Console::WriteLine("numbers UnionWith oddNumbers...");
      numbers.UnionWith(oddNumbers);
      
      Console::Write("numbers contains {0} elements: ", numbers.Count);
      DisplaySet(numbers);
    }
    
  private:
    static void DisplaySet(const SortedSet<int>& set) {
      Console::Write("{");
      for (int i : set)
        Console::Write(" "_S + i);
      Console::WriteLine(" }");
    }
  };
}

_startup(Examples::Program)

// This code example produces the following output:
//
// evenNumbers contains 5 elements: { 0 2 4 6 8 }
// oddNumbers contains 5 elements: { 1 3 5 7 9 }
// numbers UnionWith oddNumbers...
// numbers contains 10 elements: { 0 1 2 3 4 5 6 7 8 9 }
