// Prototype pattern -- Creational example

#include <Switch/Switch>

using namespace System;

namespace DesignPatterns {
  namespace Creational {
    // The 'Prototype' abstract class
    class Prototype _abstract {
    public:
      // Constructor
      Prototype(const string& id) : id(id) {}
      Prototype(const Prototype& prototype) : id(prototype.id) {}
      
      // Gets id
      _property<string, _readonly> Id {
        _get {return this->id;}
      };
      
      virtual refptr<Prototype> Clone() const = 0;

    private:
      string id;
    };
    
    // A 'ConcretePrototype' class
    class ConcretePrototype1 : public Prototype {
    public:
      // Constructor
      ConcretePrototype1(const string& id) : Prototype(id) {}
      
      // Returns a shallow copy
      refptr<Prototype> Clone() const override {return as<Prototype>(this->MemberwiseClone<ConcretePrototype1>());}
    };
    
    // A 'ConcretePrototype' class
    class ConcretePrototype2 : public Prototype {
    public:
      // Constructor
      ConcretePrototype2(const string& id) : Prototype(id) {}
      
      // Returns a shallow copy
      refptr<Prototype> Clone() const override {return as<Prototype>(this->MemberwiseClone<ConcretePrototype2>());}
    };
    
    // MainApp _startup class for Creational
    // Prototype Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Create two instances and clone each
        
        refptr<ConcretePrototype1> p1 = ref_new<ConcretePrototype1>("I");
        refptr<ConcretePrototype1> c1 = as<ConcretePrototype1>(p1->Clone());
        Console::WriteLine("Cloned: {0}", c1->Id);
        
        refptr<ConcretePrototype2> p2 = ref_new<ConcretePrototype2>("II");
        refptr<ConcretePrototype2> c2 = as<ConcretePrototype2>(p2->Clone());
        Console::WriteLine("Cloned: {0}", c2->Id);
      }
    };
  }
}

// Specify the Main entry point to System
_startup(DesignPatterns::Creational::MainApp)

// This code produces the following output:
//
// Cloned: I
// Cloned: II
