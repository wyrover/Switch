#include <Pcf/Pcf>

using namespace System;
using namespace System::Collections::Generic;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create and initialize a new string array.
      Array<string> myArray(12);
      myArray.SetValue("the", 0);
      myArray.SetValue("quick", 1);
      myArray.SetValue("brown", 2);
      myArray.SetValue("fox", 3);
      myArray.SetValue("jumps", 4);
      myArray.SetValue("over", 5);
      myArray.SetValue("the", 6);
      myArray.SetValue("lazy", 7);
      myArray.SetValue("dog", 8);
      myArray.SetValue("in", 9);
      myArray.SetValue("the", 10);
      myArray.SetValue("barn", 11);
      
      // Displays the values of the Array.
      Console::WriteLine( "The Array contains the following values:" );
      PrintIndexAndValues(myArray);
      
      // Searches for the first occurrence of the duplicated value.
      string myString = "the";
      int myIndex = Array<string>::IndexOf(myArray, myString);
      Console::WriteLine("The first occurrence of \"{0}\" is at index {1}.", myString, myIndex);
      
      // Searches for the first occurrence of the duplicated value in the last section of the Array.
      myIndex = Array<string>::IndexOf(myArray, myString, 4);
      Console::WriteLine("The first occurrence of \"{0}\" between index 4 and the end is at index {1}.", myString, myIndex);
      
      // Searches for the first occurrence of the duplicated value in a section of the Array.
      myIndex = Array<string>::IndexOf(myArray, myString, 6, 5);
      Console::WriteLine("The first occurrence of \"{0}\" between index 6 and index 10 is at index {1}.", myString, myIndex);
    }
    
  private:
    static void PrintIndexAndValues(const Array<string>& arr) {
      for (int index = arr.GetLowerBound(0); index <= arr.GetUpperBound(0); index++) {
        Console::WriteLine("\t[{0}]:\t{1}", index, arr.GetValue(index));
      }
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// The Array contains the following values:
//     [0]:   the
//     [1]:   quick
//     [2]:   brown
//     [3]:   fox
//     [4]:   jumps
//     [5]:   over
//     [6]:   the
//     [7]:   lazy
//     [8]:   dog
//     [9]:   in
//     [10]:  the
//     [11]:  barn
// The first occurrence of "the" is at index 0.
// The first occurrence of "the" between index 4 and the end is at index 6.
// The first occurrence of "the" between index 6 and index 10 is at index 6.
