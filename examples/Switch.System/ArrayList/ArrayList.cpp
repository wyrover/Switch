#include <Switch/Switch>

using namespace System;
using namespace System::Collections;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Creates and initializes a new ArrayList.
      ArrayList myAL;
      myAL.Add("Hello");
      myAL.Add("World");
      myAL.Add("!");
      
      // Displays the properties and values of the ArrayList.
      Console::WriteLine("myAL");
      Console::WriteLine("    Count:    {0}", myAL.Count);
      Console::WriteLine("    Capacity: {0}", myAL.Capacity);
      Console::Write("    Values:");
      PrintValues(myAL);
    }
    
  private:
    static void PrintValues(const IEnumerable& myList) {
      for (Any obj : myList)
        Console::Write("   {0}", obj);
      Console::WriteLine();
    }
  };
}

_startup(Examples::Program)

// This code example produces the following output:
//
// myAL
//     Count:    3
//     Capacity: 4
//     Values:   Hello   World   !
