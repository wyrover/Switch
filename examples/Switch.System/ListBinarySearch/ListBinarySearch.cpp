#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      List<string> dinosaurs;
      
      dinosaurs.Add("Pachycephalosaurus");
      dinosaurs.Add("Amargasaurus");
      dinosaurs.Add("Mamenchisaurus");
      dinosaurs.Add("Deinonychus");
      
      Console::WriteLine();
      for (string dinosaur : dinosaurs)
        Console::WriteLine(dinosaur);
      
      Console::WriteLine("\nSort");
      dinosaurs.Sort();
      
      Console::WriteLine();
      for (string dinosaur : dinosaurs)
        Console::WriteLine(dinosaur);
      
      Console::WriteLine("\nBinarySearch and Insert \"Coelophysis\":");
      int index = dinosaurs.BinarySearch("Coelophysis");
      if (index < 0)
        dinosaurs.Insert(~index, "Coelophysis");
      
      Console::WriteLine();
      for (string dinosaur : dinosaurs)
        Console::WriteLine(dinosaur);
      
      Console::WriteLine("\nBinarySearch and Insert \"Tyrannosaurus\":");
      index = dinosaurs.BinarySearch("Tyrannosaurus");
      if (index < 0)
        dinosaurs.Insert(~index, "Tyrannosaurus");
      
      Console::WriteLine();
      for (string dinosaur : dinosaurs)
        Console::WriteLine(dinosaur);
    }
  };
}

_startup(Examples::Program)

// This code example produces the following output:
//
// Pachycephalosaurus
// Amargasaurus
// Mamenchisaurus
// Deinonychus
//
// Sort
//
// Amargasaurus
// Deinonychus
// Mamenchisaurus
// Pachycephalosaurus
//
// BinarySearch and Insert "Coelophysis":
//
// Amargasaurus
// Coelophysis
// Deinonychus
// Mamenchisaurus
// Pachycephalosaurus
//
// BinarySearch and Insert "Tyrannosaurus":
//
// Amargasaurus
// Coelophysis
// Deinonychus
// Mamenchisaurus
// Pachycephalosaurus
// Tyrannosaurus
