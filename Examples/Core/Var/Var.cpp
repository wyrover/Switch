#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      System::Collections::Specialized::StringDictionary pets;
      pets["Belgian Sheperd"] = "Dog";
      pets["Bengal"] = "Cat";
      pets["Cocker"] = "Dog";
      pets["Dalmatian"] = "Dog";
      pets["Egyptian Mau"] = "Cat";
      pets["Persian"] = "Cat";
      pets["Pied Mutation Cockatiel"] = "Bird";
      
      // you can use _var type insted :
      // System::Collections::Specialized::StringKeyValuePair item
      for (_var item : pets) {
        Console::WriteLine(item);
      }
    }
  };
}

startup (Examples::Program)

// This code produces the following output:
//
// [Belgian Sheperd, Dog]
// [Bengal, Cat]
// [Cocker, Dog]
// [Dalmatian, Dog]
// [Egyptian Mau, Cat]
// [Persian, Cat]
// [Pied Mutation Cockatiel, Bird]
