#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Collections::ObjectModel;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      List<string> dinosaurs(4);
      
      Console::WriteLine("\nCapacity: {0}", dinosaurs.Capacity);
      
      dinosaurs.Add("Tyrannosaurus");
      dinosaurs.Add("Amargasaurus");
      dinosaurs.Add("Mamenchisaurus");
      dinosaurs.Add("Deinonychus");
      
      Console::WriteLine();
      for (string s : dinosaurs)
        Console::WriteLine(s);
      
      Console::WriteLine("\nReadOnlyCollection<string> roDinosaurs = dinosaurs.AsReadOnly()");
      ReadOnlyCollection<string> roDinosaurs = dinosaurs.AsReadOnly();
      
      Console::WriteLine("\nElements in the read-only collection:");
      for (string dinosaur : roDinosaurs)
        Console::WriteLine(dinosaur);
      
      Console::WriteLine("\ndinosaurs[2] = \"Coelophysis\"");
      dinosaurs[2] = "Coelophysis";
      
      Console::WriteLine("\nElements in the read-only collection:");
      for (string dinosaur : roDinosaurs)
        Console::WriteLine(dinosaur);
    }
  };
}

_startup(Examples::Program);

// This code example produces the following output:
//
// Capacity: 4
//
// Tyrannosaurus
// Amargasaurus
// Mamenchisaurus
// Deinonychus
//
// ReadOnlyCollection<string><string> roDinosaurs = dinosaurs.AsReadOnly()
//
// Elements in the read-only collection:
// Tyrannosaurus
// Amargasaurus
// Mamenchisaurus
// Deinonychus
//
// dinosaurs[2] = "Coelophysis"
//
// Elements in the read-only collection:
// Tyrannosaurus
// Amargasaurus
// Coelophysis
// Deinonychus
