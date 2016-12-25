#include <Pcf/Pcf>

using namespace System;
using namespace System::Collections::Generic;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<string> input = {"Brachiosaurus", "Amargasaurus", "Mamenchisaurus"};
      List<string> dinosaurs(input);
      
      Console::WriteLine("\nCapacity: {0}", dinosaurs.Capacity);
      
      Console::WriteLine();
      for (string dinosaur : dinosaurs)
        Console::WriteLine(dinosaur);
      
      Console::WriteLine("\nAddRange(dinosaurs)");
      dinosaurs.AddRange(dinosaurs);
      
      Console::WriteLine();
      for (string dinosaur : dinosaurs)
        Console::WriteLine(dinosaur);
      
      Console::WriteLine("\nRemoveRange(2, 2)");
      dinosaurs.RemoveRange(2, 2);
      
      Console::WriteLine();
      for (string dinosaur : dinosaurs)
        Console::WriteLine(dinosaur);
      
      input = {"Tyrannosaurus", "Deinonychus", "Velociraptor"};
      
      Console::WriteLine("\nInsertRange(3, input)");
      dinosaurs.InsertRange(3, input);
      
      Console::WriteLine();
      for (string dinosaur : dinosaurs)
        Console::WriteLine(dinosaur);
      
      Console::WriteLine("\noutput = dinosaurs.GetRange(2, 3).ToArray()");
      Array<string> output = dinosaurs.GetRange(2, 3).ToArray();
      
      Console::WriteLine();
      for (string dinosaur : output)
        Console::WriteLine(dinosaur);
    }
  };
}

pcf_startup (Examples::Program)

// This code example produces the following output:
//
// Capacity: 4
//
// Brachiosaurus
// Amargasaurus
// Mamenchisaurus
//
// AddRange(*dinosaurs)
//
// Brachiosaurus
// Amargasaurus
// Mamenchisaurus
// Brachiosaurus
// Amargasaurus
// Mamenchisaurus
//
// RemoveRange(2, 2)
//
// Brachiosaurus
// Amargasaurus
// Amargasaurus
// Mamenchisaurus
//
// InsertRange(3, input)
//
// Brachiosaurus
// Amargasaurus
// Amargasaurus
// Tyrannosaurus
// Deinonychus
// Velociraptor
// Mamenchisaurus
//
// output = dinosaurs.GetRange(2, 3).ToArray()
//
// Amargasaurus
// Tyrannosaurus
// Deinonychus
