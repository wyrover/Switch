#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Creates and initializes a one-dimensional Array of type Int32.
      auto my1DArray = Array<>::CreateInstance<int32>(5);
      for (int i = my1DArray.GetLowerBound(0); i <= my1DArray.GetUpperBound(0); i++)
        my1DArray.SetValue(i+1, i);
      
      // Displays the values of the Array.
      Console::WriteLine( "The one-dimensional Array contains the following values:" );
      PrintValues( my1DArray );
    }
    
  private:
    template<typename T>
    static void PrintValues(const Array<T>& myArr)  {
      _<System::Collections::Generic::IEnumerator<T>> myEnumerator = myArr.GetEnumerator();
      int i = 0;
      int cols = myArr.GetLength(myArr.Rank - 1);
      while (myEnumerator->MoveNext())  {
        if (i < cols)  {
          i++;
        } else  {
          Console::WriteLine();
          i = 1;
        }
        Console::Write("\t{0}", myEnumerator->Current);
      }
      Console::WriteLine();
    }
  };
}

_startup (Examples::Program)

// This code produces the following output:
//
// The one-dimensional Array contains the following values:
//     1  2  3  4  5
