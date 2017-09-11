#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      List<string> dinosaurs;
      
      dinosaurs.Add("Tyrannosaurus");
      dinosaurs.Add("Amargasaurus");
      dinosaurs.Add("Mamenchisaurus");
      dinosaurs.Add("Brachiosaurus");
      dinosaurs.Add("Compsognathus");
      
      Console::WriteLine();
      for (string dinosaur : dinosaurs)
        Console::WriteLine(dinosaur);
      
      // Declare an array with 15 elements.
      Array<string> array(15);
      
      dinosaurs.CopyTo(array);
      dinosaurs.CopyTo(array, 6);
      dinosaurs.CopyTo(2, array, 12, 3);
      
      Console::WriteLine("\nContents of the array:");
      for (string dinosaur : array)
        Console::WriteLine(dinosaur);

    }
  };
}

_startup (Examples::Program)

// This code example produces the following output:
//
// Tyrannosaurus
// Amargasaurus
// Mamenchisaurus
// Brachiosaurus
// Compsognathus
//
// Contents of the array:
// Tyrannosaurus
// Amargasaurus
// Mamenchisaurus
// Brachiosaurus
// Compsognathus
//
// Tyrannosaurus
// Amargasaurus
// Mamenchisaurus
// Brachiosaurus
// Compsognathus
//
// Mamenchisaurus
// Brachiosaurus
// Compsognathus
