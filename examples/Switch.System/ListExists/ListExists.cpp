#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      List<string> dinosaurs;

      dinosaurs.Add("Compsognathus");
      dinosaurs.Add("Amargasaurus");
      dinosaurs.Add("Oviraptor");
      dinosaurs.Add("Velociraptor");
      dinosaurs.Add("Deinonychus");
      dinosaurs.Add("Dilophosaurus");
      dinosaurs.Add("Gallimimus");
      dinosaurs.Add("Triceratops");

      Console::WriteLine();
      for (string dinosaur : dinosaurs)
        Console::WriteLine(dinosaur);

      Console::WriteLine("\nTrueForAll(EndsWithSaurus): {0}", dinosaurs.TrueForAll(Predicate<const string&>(&EndsWithSaurus)));

      Console::WriteLine("\nFind(EndsWithSaurus): {0}", dinosaurs.Find(Predicate<const string&>(&EndsWithSaurus)));

      Console::WriteLine("\nFindLast(EndsWithSaurus): {0}", dinosaurs.FindLast(Predicate<const string&>(&EndsWithSaurus)));

      Console::WriteLine("\nFindAll(EndsWithSaurus):");
      List<string> sublist = dinosaurs.FindAll(Predicate<const string&>(&EndsWithSaurus));

      for (string dinosaur : sublist)
        Console::WriteLine(dinosaur);

      Console::WriteLine("\n{0} elements removed by RemoveAll(EndsWithSaurus).", dinosaurs.RemoveAll(Predicate<const string&>(&EndsWithSaurus)));

      Console::WriteLine("\nList now contains:");
      for (string dinosaur : dinosaurs)
        Console::WriteLine(dinosaur);

      Console::WriteLine("\nExists(EndsWithSaurus): {0}", dinosaurs.Exists(Predicate<const string&>(&EndsWithSaurus)));
    }

  private:
    // Search predicate returns true if a string ends in "saurus".
    static bool EndsWithSaurus(const string& s) {
      return s.ToLower().EndsWith("saurus");
    }
  };
}


startup_(Examples::Program);

// This code example produces the following output:
//
// Compsognathus
// Amargasaurus
// Oviraptor
// Velociraptor
// Deinonychus
// Dilophosaurus
// Gallimimus
// Triceratops
//
// TrueForAll(EndsWithSaurus): False
//
// Find(EndsWithSaurus): Amargasaurus
//
// FindLast(EndsWithSaurus): Dilophosaurus
//
// FindAll(EndsWithSaurus):
// Amargasaurus
// Dilophosaurus
//
// 2 elements removed by RemoveAll(EndsWithSaurus).
//
// List now contains:
// Compsognathus
// Oviraptor
// Velociraptor
// Deinonychus
// Gallimimus
// Triceratops
//
// Exists(EndsWithSaurus): False
