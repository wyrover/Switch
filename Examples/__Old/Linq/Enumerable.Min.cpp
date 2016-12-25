#include <Pcf/Pcf>

using namespace System;
using namespace System::Linq;

class Pet : public object, public IComparable {
public:
  Pet() : age(0) {}
  Pet(const string& name, int age) : name(name), age(age) {}
  Pet(const Pet& pet) : name(pet.name), age(pet.age) {}

  Property<int, ReadOnly> Age {
    [&] {return this->age;}
  };

  Property<string, ReadOnly> Name {
    [&] {return this->name;}
  };

  virtual int CompareTo(const IComparable& other) const { return Int32(this->age).CompareTo(as<Pet>(other).age); }

private:
  string name;
  int age;
};

int main(int argc, char* argv[]) {
  Array<Pet> pets = {
    {"Barley", 8},
    {"Boots", 4},
    {"Whiskers", 1}
  };
  
  Pet min = pets.Min();
  
  Console::WriteLine("The 'minimum' animal is {0}.", min.Name);
}

// This code produces the following output:
//
// The 'minimum' animal is Whiskers.
