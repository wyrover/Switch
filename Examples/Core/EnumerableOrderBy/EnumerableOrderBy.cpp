#include <Pcf/Pcf>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;

namespace Examples {
  class Program {
    class Pet : public object {
    public:
      Pet() : age(0) {}
      Pet(const string& name, int age) : name(name), age(age) {}
      Pet(const Pet& pet) : name(pet.name), age(pet.age) {}
      
      Property<int, ReadOnly> Age {
        pcf_get {return this->age;}
      };
      
      Property<string, ReadOnly> Name {
        pcf_get {return this->name;}
      };
      
    private:
      string name;
      int age;
    };
    
  public:
    // The main entry point for the application.
    static void Main() {
      Array<Pet> pets = {
        {"Barley", 8},
        {"Boots", 4},
        {"Whiskers", 1}
      };
 
      refptr<IEnumerable<Pet>> query = pets.OrderBy<int>(pcf_delegate(const Pet& pet) {return  pet.Age();});
      
      for (Pet& pet : *query)
        Console::WriteLine("{0} - {1}", pet.Name, pet.Age);
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// Whiskers - 1
// Boots - 4
// Barley - 8
