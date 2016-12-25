#include <Pcf/Pcf>

using namespace System;
using namespace System::Linq;

class Pet : public object {
public:
  Pet() {}
  Pet(const string& name, int age) : name(name), age(age) {}
  Pet(const Pet& pet) : name(pet.name), age(pet.age) {}

  Property<int, ReadOnly> Age {
    [&] {return this->age;}
  };

  Property<string, ReadOnly> Name {
    [&] {return this->name;}
  };

private:
  string name;
  int age = 0;
};

int main(int argc, char* argv[]) {
  // Create an array of Pets.
  Array<Pet> pets = {
    {"Barley", 8},
    {"Boots", 4},
    {"Whiskers", 1}
  };
  
  // Determine whether all pet names
  // in the array start with 'B'.
  bool allStartWithB = pets.All([&](const Pet& pet)->bool {
    return pet.Name().StartsWith("B");
  });
  
  Console::WriteLine("{0} pet names start with 'B'.", allStartWithB ? "All" : "Not all");
}

// This code produces the following output:
//
// Not all pet names start with 'B'.
//
