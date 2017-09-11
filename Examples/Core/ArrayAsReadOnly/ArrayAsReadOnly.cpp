#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create and initialize a new string array.
      Array<string> myArr = {"The", "quick", "brown", "fox"};
      
      // Display the values of the array.
      Console::WriteLine("The string array initially contains the following values:");
      PrintIndexAndValues(myArr);
      
      // Create a read-only collection wrapper around the array.
      System::Collections::ObjectModel::ReadOnlyCollection<string> myList = Array<>::AsReadOnly(myArr);
      
      // Display the values of the read-only IList.
      Console::WriteLine("The read-only IList contains the following values:");
      PrintIndexAndValues(myList);
      
      // Attempt to change a value through the wrapper.
      try {
        myList[3] = "CAT";
      } catch (const NotSupportedException& e) {
        Console::WriteLine("{0} - {1}", e.GetType(), e.Message);
        Console::WriteLine();
      }
      
      // Change a value in the original array.
      myArr[2] = "RED";
      
      // Display the values of the array.
      Console::WriteLine("After changing the third element, the string array contains the following values:");
      PrintIndexAndValues(myArr);
      
      // Display the values of the read-only IList.
      Console::WriteLine("After changing the third element, the read-only IList contains the following values:");
      PrintIndexAndValues(myList);
    }
    
  private:
    static void PrintIndexAndValues(const Array<string>& myArr) {
      for (int i = 0; i < myArr.Length; i++)
        Console::WriteLine("   {0} : {1}", i, myArr[i]);
      Console::WriteLine();
    }
    
    static void PrintIndexAndValues(const IList<string>& myList) {
      for (int i = 0; i < myList.Count; i++)
        Console::WriteLine("   {0} : {1}", i, myList[i]);
      Console::WriteLine();
    }
  };
}

startup (Examples::Program)

// This code produces the following output:
//
// The string array initially contains the following values:
//    0 : The
//    1 : quick
//    2 : brown
//    3 : fox
//
// The read-only IList contains the following values:
//    0 : The
//    1 : quick
//    2 : brown
//    3 : fox
//
// System::NotSupportedException - Collection is read-only.
//
// After changing the third element, the string array contains the following values:
//    0 : The
//    1 : quick
//    2 : RED
//    3 : fox
//
// After changing the third element, the read-only IList contains the following values:
//    0 : The
//    1 : quick
//    2 : RED
//    3 : fox
