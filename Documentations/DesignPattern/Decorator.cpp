// Decorator pattern -- Structural example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Structural {
    /// @brief The 'Component' abstract class
    class Component : public Abstract {
    public:
      virtual void Operation() const =0;
    };
    
    /// @brief The 'ConcreteComponent' class
    class ConcreteComponent : public Component {
    public:
      void Operation() const override {Console::WriteLine("ConcreteComponent.Operation()");}
    };
    
    /// brief The 'Decorator' abstract class
    class Decorator : public Component {
    public:
      void SetComponent(Up<Component> component) {this->component = component;}
      
      void Operation() const override {
        if (!component.IsNull()) {
          component->Operation();
        }
      }
      
    protected:
      Up<Component> component;
    };
    
    /// @brief The 'ConcreteDecoratorA' class
    class ConcreteDecoratorA : public Decorator {
    public:
      void Operation() const override {
        Decorator::Operation();
        Console::WriteLine("ConcreteDecoratorA.Operation()");
      }
    };
    
    /// @brief The 'ConcreteDecoratorB' class
    class ConcreteDecoratorB : public Decorator {
    public:
      void Operation() const override {
        Decorator::Operation();
        AddedBehavior();
        Console::WriteLine("ConcreteDecoratorB.Operation()");
      }
      
      void AddedBehavior() const {}
    };
  }
}

/// @brief Entry point into console application.
int main(int argc, char* argv[]) {
  using namespace DesignPatterns::Structural;
  
  // Create ConcreteComponent and two Decorators
  Up<ConcreteComponent> c = new ConcreteComponent();
  Up<ConcreteDecoratorA> d1 = new ConcreteDecoratorA();
  Up<ConcreteDecoratorB> d2 = new ConcreteDecoratorB();
  
  // Link decorators
  d1->SetComponent(as<Component>(c));
  d2->SetComponent(as<Component>(d1));
  
  d2->Operation();
}

// This code produces the following output:
//
// ConcreteComponent.Operation()
// ConcreteDecoratorA.Operation()
// ConcreteDecoratorB.Operation()
