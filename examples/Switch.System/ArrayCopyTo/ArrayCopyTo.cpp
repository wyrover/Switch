#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Creates and initializes two new Arrays.
      Array<string> mySourceArray(6);
      mySourceArray.SetValue("three", 0);
      mySourceArray.SetValue("napping", 1);
      mySourceArray.SetValue("cats", 2);
      mySourceArray.SetValue("in", 3);
      mySourceArray.SetValue("the", 4);
      mySourceArray.SetValue("barn", 5);
      Array<string> myTargetArray(15);
      myTargetArray.SetValue("The", 0);
      myTargetArray.SetValue("quick", 1);
      myTargetArray.SetValue("brown", 2);
      myTargetArray.SetValue("fox", 3);
      myTargetArray.SetValue("jumps", 4);
      myTargetArray.SetValue("over", 5);
      myTargetArray.SetValue("the", 6);
      myTargetArray.SetValue("lazy", 7);
      myTargetArray.SetValue("dog", 8);

      // Displays the values of the Array.
      Console::WriteLine("The target Array contains the following (before and after copying):");
      PrintValues(myTargetArray, ' ');

      // Copies the source Array to the target Array, starting at index 6.
      mySourceArray.CopyTo(myTargetArray, 6);

      // Displays the values of the Array.
      PrintValues(myTargetArray, ' ');
    }

  private:
    static void PrintValues(const Array<string>& myArray, char32 separator) {
      System::Collections::Generic::Enumerator<string>  enumerator = myArray.GetEnumerator();
      int index = 0;
      int cols = myArray.GetLength(myArray.Rank - 1);
      while (enumerator.MoveNext()) {
        if (index < cols)
          index++;
        else {
          Console::WriteLine();
          index = 1;
        }
        Console::Write("{0}{1}", separator, enumerator.Current);
      }
      Console::WriteLine();
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// The target Array contains the following (before and after copying):
//  The quick brown fox jumps over the lazy dog
//  The quick brown fox jumps over three napping cats in the barn
