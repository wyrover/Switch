#include <Switch/Switch>

using namespace System;
using namespace System::Linq;

namespace Examples {
  class Program {
    class Pet : public object {
    public:
      Pet() {}
      Pet(const string& name, int age) : name(name), age(age) {}
      Pet(const Pet& pet) : name(pet.name), age(pet.age) {}
      
      Property<int, ReadOnly> Age {
        _get {return this->age;}
      };
      
      Property<string, ReadOnly> Name {
        _get {return this->name;}
      };
      
    private:
      string name;
      int age = 0;
    };
    
  public:
    // The main entry point for the application.
    static void Main() {
      // Create an array of Pets.
      Array<Pet> pets = {
        {"Barley", 8},
        {"Boots", 4},
        {"Whiskers", 1}
      };
      
      // Determine whether all pet names
      // in the array start with 'B'.
      bool allStartWithB = pets.All(_delegate(const Pet& pet)->bool {
        return pet.Name().StartsWith("B");
      });
      
      Console::WriteLine("{0} pet names start with 'B'.", allStartWithB ? "All" : "Not all");
    }
  };
}

_startup (Examples::Program)

// This code produces the following output:
//
// Not all pet names start with 'B'.
//
