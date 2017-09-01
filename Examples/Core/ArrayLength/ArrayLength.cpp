#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // make a single dimension array
      Array<int> myArray1(5);
      
      // make a 3 dimensional array
      Array<int, 3> myArray2(5, 3, 2);
      
      Console::WriteLine("Lengths of single dimension array");
      // show the total length of the entire array or all dimensions
      Console::WriteLine("    Total length of the array = {0}", myArray1.Length);
      
      Console::WriteLine("Lengths of {0} dimension array", myArray2.Rank);
      for (int rank = 0; rank < myArray2.Rank; rank++) {
        // show the lengths of each dimension
        Console::WriteLine("    Length of dimension({0}) = {1}", rank,  myArray2.GetLength(rank));
      }
      // show the total length of the entire array or all dimensions
      Console::WriteLine("    Total length of the array = {0}", myArray2.Length);
    }
  };
}

_startup (Examples::Program)

// This code produces the following output:
//
// Lengths of single dimension array
//     Total length of the array = 5
//
// Lengths of 3 dimension array
//     Length of dimension(0) = 5
//     Length of dimension(1) = 3
//     Length of dimension(2) = 2
//     Total length of the array = 30
