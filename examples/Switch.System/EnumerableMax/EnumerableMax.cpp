#include <Switch/Switch>

using namespace System;
using namespace System::Linq;

namespace Examples {
  class Program {
    class Pet : public object, public IComparable {
    public:
      Pet() : age(0) {}
      Pet(const string& name, int age) : name(name), age(age) {}
      Pet(const Pet& pet) : name(pet.name), age(pet.age) {}
      Pet& operator=(const Pet& pet) {
        this->name = pet.name;
        this->age = pet.age;
        return *this;
      }

      _property<int, _readonly> Age {
        _get {return this->age;}
      };
      
      _property<string, _readonly> Name {
        _get {return this->name;}
      };
      
      virtual bool Equals(const object& other) const {
        return is<Pet>(other) && this->name == as<Pet>(other).name && this->age == as<Pet>(other).age;
      }
      
      virtual int CompareTo(const IComparable& other) const {
        if (!is<Pet>(other))
          return 1;
        
        int sumOther = as<Pet>(other).age + as<Pet>(other).name.Length;
        int sumThis = this->age + this->name.Length;
        
        if (sumOther > sumThis)
          return -1;
        
        if (sumOther == sumThis)
          return 0;
        
        return 1;
      }
      
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
      
      Pet max = pets.Max();
      
      Console::WriteLine("The 'maximum' animal is {0}.", max.Name);
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// The 'maximum' animal is Barley.
