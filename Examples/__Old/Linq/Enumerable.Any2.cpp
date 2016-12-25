#include <Pcf/Pcf>

using namespace System;
using namespace System::Linq;

class Pet : public object {
public:
  Pet() {}
  Pet(const string& name, int age, bool vaccinated) : name(name), age(age), vaccinated(vaccinated) {}
  Pet(const Pet& pet) : name(pet.name), age(pet.age), vaccinated(pet.vaccinated) {}

  Property<int, ReadOnly> Age {
    [&] { return this->age; }
  };

  Property<bool, ReadOnly> IsVaccinated {
    [&] { return this->vaccinated; }
  };

  Property<string, ReadOnly> Name {
    [&] { return this->name; }
  };

private:
  string name;
  int age = 0;
  bool vaccinated = false;
};

int main(int argc, char* argv[]) {
  // Create an array of Pets.
  Array<Pet> pets = {
    {"Barley", 8, true},
    {"Boots", 4, false},
    {"Whiskers", 1, false}
  };
  
  // Determine whether any pets over age 1 are also unvaccinated.
  bool unvaccinated = pets.Any([&](const Pet& pet) {
    return pet.IsVaccinated == false && pet.Age > 1;
  });
  
  Console::WriteLine("There {0} unvaccinated animals over age one.", unvaccinated ? "are" : "are not any");
}

// This code produces the following output:
//
// There are unvaccinated animals over age one.
//
