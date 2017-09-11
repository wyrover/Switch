// Bridge pattern -- Structural example

#include <Switch/Switch>

using namespace System;

namespace DesignPatterns {
  namespace Structural {
    // The 'Implementor' abstract class
    class Implementor _abstract {
    public:
      virtual void Operation() const = 0;
    };
    
    // The 'Abstraction' class
    class Abstraction : public object {
    public:
      // Property
      property<refptr<DesignPatterns::Structural::Implementor>, writeonly> Implementor {
        _set {this->implementor = value;}
      };
      
      virtual void Operation() const {
        this->implementor->Operation();
      }

    protected:
      refptr<DesignPatterns::Structural::Implementor> implementor;
    };
    
    // The 'RefinedAbstraction' class
    class RefinedAbstraction : public Abstraction {
    public:
      void Operation() const override {
        this->implementor->Operation();
      }
    };
    
    // The 'ConcreteImplementorA' class
    class ConcreteImplementorA : public Implementor {
    public:
      void Operation() const override {
        Console::WriteLine("ConcreteImplementorA Operation");
      }
    };
    
    // The 'ConcreteImplementorB' class
    class ConcreteImplementorB : public Implementor {
    public:
      void Operation() const override {
        Console::WriteLine("ConcreteImplementorB Operation");
      }
    };
    
    // MainApp startup class for Structural
    // Bridge Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        refptr<Abstraction> ab = ref_new<RefinedAbstraction>();
        
        // Set implementation and call
        ab->Implementor = ref_new<ConcreteImplementorA>();
        ab->Operation();
        
        // Change implemention and call
        ab->Implementor = ref_new<ConcreteImplementorB>();
        ab->Operation();
      }
    };
  }
}

// Specify the Main entry point to System
startup (DesignPatterns::Structural::MainApp)

// This code produces the following output:
//
// ConcreteImplementorA Operation
// ConcreteImplementorB Operation
