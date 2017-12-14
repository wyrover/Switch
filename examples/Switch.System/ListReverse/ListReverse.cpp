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
      dinosaurs.Add("Parasauralophus");
      dinosaurs.Add("Mamenchisaurus");
      dinosaurs.Add("Amargasaurus");
      dinosaurs.Add("Coelophysis");
      dinosaurs.Add("Oviraptor");

      Console::WriteLine();
      for (string dinosaur : dinosaurs)
        Console::WriteLine(dinosaur);

      dinosaurs.Reverse();

      Console::WriteLine();
      for (string dinosaur : dinosaurs)
        Console::WriteLine(dinosaur);

      dinosaurs.Reverse(1, 4);

      Console::WriteLine();
      for (string dinosaur : dinosaurs)
        Console::WriteLine(dinosaur);
    }
  };
}

_startup(Examples::Program);

// This code example produces the following output:
//
// Pachycephalosaurus
// Parasauralophus
// Mamenchisaurus
// Amargasaurus
// Coelophysis
// Oviraptor
//
// Oviraptor
// Coelophysis
// Amargasaurus
// Mamenchisaurus
// Parasauralophus
// Pachycephalosaurus
//
// Oviraptor
// Parasauralophus
// Mamenchisaurus
// Amargasaurus
// Coelophysis
// Pachycephalosaurus
