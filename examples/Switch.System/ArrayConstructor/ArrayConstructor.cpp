#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    static void Main() {
      // make a single dimension array
      Array<int> myArray1(5);
      
      // make a 3 dimensional array
      Array<int, 3> myArray2(5, 3, 2);
      
      // make an array from native array
      int myNativeArray[] = {10, 20, 30, 40, 50, 60, 70};
      Array<int> myArray3(myNativeArray);
      
      // make an array from initializer list
      Array<int> myArray4 = {100, 200, 300, 400, 500, 600, 700};
      
      int index = 0;
      // show the array values
      Console::WriteLine("The Array contains the following values:");
      for (int value : myArray3)
        Console::WriteLine("[{0}] {1}", index++, value);
    }
  };
}

// The main entry point for the application.
_startup(Examples::Program)

// This code produces the following output:
//
// The Array contains the following values:
// [0] 10
// [1] 20
// [2] 30
// [3] 40
// [4] 50
// [5] 60
// [6] 70
