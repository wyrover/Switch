#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Creates and initializes two new Arrays.
      Array<string> mySourceArray(6);
      mySourceArray[0] = "three";
      mySourceArray[1] = "napping";
      mySourceArray[2] = "cats";
      mySourceArray[3] = "in";
      mySourceArray[4] = "the";
      mySourceArray[5] = "barn";
      string myTargetArray[15];
      myTargetArray[0] = "The";
      myTargetArray[1] = "quick";
      myTargetArray[2] = "brown";
      myTargetArray[3] = "fox";
      myTargetArray[4] = "jumps";
      myTargetArray[5] = "over";
      myTargetArray[6] = "the";
      myTargetArray[7] = "lazy";
      myTargetArray[8] = "dog";
      
      // Displays the values of the Array.
      Console::WriteLine("The target Array contains the following (before and after copying):");
      PrintValues(myTargetArray, 15, ' ');
      
      // Copies the source Array to the target Array, starting at index 6.
      mySourceArray.CopyTo(myTargetArray, 15, 6);
      
      // Displays the values of the Array.
      PrintValues(myTargetArray, 15, ' ');
     }
    
  private:
    static void PrintValues(const string arr[], int length, char32 separator) {
      for (int index = 0; index < length; index++) {
        Console::Write("{0}{1}", separator, arr[index]);
      }
      Console::WriteLine();
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
//  The quick brown fox jumps over the lazy dog
//  The quick brown fox jumps over three napping cats in the barn
