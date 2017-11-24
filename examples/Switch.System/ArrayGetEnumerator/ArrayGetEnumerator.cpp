#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Creates and initializes a new Array.
      Array<string> myArray(10);
      
      myArray[0] = "The";
      myArray[1] = "quick";
      myArray[2] = "brown";
      myArray[3] = "fox";
      myArray[4] = "jumped";
      myArray[5] = "over";
      myArray[6] = "the";
      myArray[7] = "lazy";
      myArray[8] = "dog";
      
      // Displays the values of the Array.
      int index = 0;
      System::Collections::Generic::Enumerator<string> myEnumerator = myArray.GetEnumerator();
      Console::WriteLine("The Array contains the following values:");
      while (myEnumerator.MoveNext())
        Console::WriteLine("[{0}] {1}", index++, myEnumerator.Current);
    }
  };
  
}

_startup(Examples::Program);

// This code produces the following output:
//
// The Array contains the following values:
// [0] The
// [1] quick
// [2] brown
// [3] fox
// [4] jumped
// [5] over
// [6] the
// [7] lazy
// [8] dog
// [9]
