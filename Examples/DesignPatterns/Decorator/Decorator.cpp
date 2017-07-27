// Decorator pattern -- Structural example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Structural {
    // The 'Component' abstract class
    class Component : public Abstract {
    public:
      virtual void Operation() const = 0;
    };
    
    // The 'ConcreteComponent' class
    class ConcreteComponent : public Component {
    public:
      void Operation() const override {Console::WriteLine("ConcreteComponent.Operation()");}
    };
    
    // The 'Decorator' abstract class
    class Decorator : public Component {
    public:
      void SetComponent(refptr<Component> component) {this->component = component;}
      
      void Operation() const override {
        if (component != null) {
          component->Operation();
        }
      }
      
    protected:
      refptr<Component> component;
    };
    
    // The 'ConcreteDecoratorA' class
    class ConcreteDecoratorA : public Decorator {
    public:
      void Operation() const override {
        Decorator::Operation();
        Console::WriteLine("ConcreteDecoratorA.Operation()");
      }
    };
    
    // The 'ConcreteDecoratorB' class
    class ConcreteDecoratorB : public Decorator {
    public:
      void Operation() const override {
        Decorator::Operation();
        AddedBehavior();
        Console::WriteLine("ConcreteDecoratorB.Operation()");
      }
      
      void AddedBehavior() const {}
    };
    
    // MainApp startup class for Structural
    // Decorator Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Create ConcreteComponent and two Decorators
        refptr<ConcreteComponent> c = pcf_new<ConcreteComponent>();
        refptr<ConcreteDecoratorA> d1 = pcf_new<ConcreteDecoratorA>();
        refptr<ConcreteDecoratorB> d2 = pcf_new<ConcreteDecoratorB>();
        
        // Link decorators
        d1->SetComponent(as<Component>(c));
        d2->SetComponent(as<Component>(d1));
        
        d2->Operation();
      }
    };
  }
}

pcf_startup (DesignPatterns::Structural::MainApp)

// This code produces the following output:
//
// ConcreteComponent.Operation()
// ConcreteDecoratorA.Operation()
// ConcreteDecoratorB.Operation()
