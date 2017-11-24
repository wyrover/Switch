#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Creates a new one-dimensional Array of type Int32.
      Array<int> my1DIntArray(5);
      
      // Uses GetLowerBound and GetUpperBound in the for loop.
      for (int index = my1DIntArray.GetLowerBound(0); index <= my1DIntArray.GetUpperBound(0); index++)
        my1DIntArray.SetValue(index + 1, index);
        
      // Displays the bounds and values of the one-dimensional Array.
      Console::WriteLine("One-dimensional Array:");
      Console::WriteLine("Rank\tLower\tUpper");
      Console::WriteLine("0\t{0}\t{1}", my1DIntArray.GetLowerBound(0), my1DIntArray.GetUpperBound(0));
      Console::WriteLine("Values:");
      for (int index = 0; index < my1DIntArray.GetLength(0); index++)
        Console::Write("\t{0}", my1DIntArray[index]);
        
      Console::WriteLine();
      
      // Creates a new three-dimensional Array of type Int32.
      Array<int, 3> my3DIntArray(2, 3, 4);
      
      // Uses GetLowerBound and GetUpperBound in the for loop.
      for (int i = my3DIntArray.GetLowerBound(0); i <= my3DIntArray.GetUpperBound(0); i++) {
        for (int j = my3DIntArray.GetLowerBound(1); j <= my3DIntArray.GetUpperBound(1); j++) {
          for (int k = my3DIntArray.GetLowerBound(2); k <= my3DIntArray.GetUpperBound(2); k++)
            my3DIntArray.SetValue((i * 100) + (j * 10) + k, i, j, k);
        }
      }
      
      // Displays the bounds and values of the multidimensional Array.
      Console::WriteLine("Multidimensional Array:");
      Console::WriteLine("Rank\tLower\tUpper");
      for (int index = 0; index < my3DIntArray.Rank; index++)
        Console::WriteLine("{0}\t{1}\t{2}", index, my3DIntArray.GetLowerBound(index), my3DIntArray.GetUpperBound(index));
      Console::WriteLine("Values:");
      PrintValues(my3DIntArray);
    }
    
  private:
    static void PrintValues(const Array<int, 3>& arr) {
      System::Collections::Generic::Enumerator<int> myEnumerator = arr.GetEnumerator();
      int index = 0;
      int cols = arr.GetLength(arr.Rank - 1);
      while (myEnumerator.MoveNext()) {
        if (index < cols)
          index++;
        else {
          Console::WriteLine();
          index = 1;
        }
        Console::Write("\t{0}", myEnumerator.Current);
      }
      Console::WriteLine();
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// One-dimensional Array:
// Rank Lower Upper
// 0   0   4
// Values:
//     1   2   3   4   5
// Multidimensional Array:
// Rank    Lower  Upper
// 0   0   1
// 1   0   2
// 2   0   3
// Values:
//     0   1   2   3
//     10  11  12  13
//     20  21  22  23
//     100 101 102 103
//     110 111 112 113
//     120 121 122 123
