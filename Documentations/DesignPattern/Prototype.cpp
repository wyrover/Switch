// Prototype pattern -- Creational example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Creational {
    /// @brief The 'Prototype' abstract class
    class Prototype : public Abstract {
    public:
      // Constructor
      Prototype(const string& id) : id(id) {}
      
      // Gets id
      Property<string, ReadOnly> Id {
        pcf_get {return this->id;}
      };
      
      virtual Up<Prototype> Clone() const =0;

    private:
      string id;
    };
    
    /// @brief A 'ConcretePrototype' class
    class ConcretePrototype1 : public Prototype {
    public:
      // Constructor
      ConcretePrototype1(const string& id) : Prototype(id) {}
      
      // Returns a shallow copy
      Up<Prototype> Clone() const override {return this->MemberwiseClone<ConcretePrototype1>().As<Prototype>();}
    };
    
    /// @brief A 'ConcretePrototype' class
    class ConcretePrototype2 : public Prototype {
    public:
      // Constructor
      ConcretePrototype2(const string& id) : Prototype(id) {}
      
      // Returns a shallow copy
      Up<Prototype> Clone() const override {return this->MemberwiseClone<ConcretePrototype2>().As<Prototype>();}
    };
  }
}

/// @brief Entry point into console application.
int main(int argc, char* argv[]) {
  using namespace DesignPatterns::Creational;
  
  // Create two instances and clone each
  
  Up<ConcretePrototype1> p1 = new ConcretePrototype1("I");
  Up<ConcretePrototype1> c1 = p1->Clone().As<ConcretePrototype1>();
  Console::WriteLine("Cloned: {0}", c1->Id);
  
  Up<ConcretePrototype2> p2 = new ConcretePrototype2("II");
  Up<ConcretePrototype2> c2 = p2->Clone().As<ConcretePrototype2>();
  Console::WriteLine("Cloned: {0}", c2->Id);
}

// This code produces the following output:
//
// Cloned: I
// Cloned: II
