#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Random rnd;
      Array<string> malePetNames = {"Rufus", "Bear", "Dakota", "Fido", "Vanya", "Samuel", "Koani", "Volodya", "Prince", "Yiska"};
      Array<string> femalePetNames = {"Maggie", "Penny", "Saya", "Princess", "Abby", "Laila", "Sadie", "Olivia", "Starlight", "Talla"};
      
      // Generate random indexes for pet names.
      int mIndex = rnd.Next(malePetNames.Length);
      int fIndex = rnd.Next(femalePetNames.Length);
      
      // Display the result.
      Console::WriteLine("Suggested pet name of the day: ");
      Console::WriteLine("   For a male:     {0}", malePetNames[mIndex]);
      Console::WriteLine("   For a female:   {0}", femalePetNames[fIndex]);
    }
  };
}

startup (Examples::Program)

// This code produces the following output:
//
// Suggested pet name of the day:
//    For a male:     Koani
//    For a female:   Maggie
