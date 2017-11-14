![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

# Definition

Decouple an abstraction from its implementation so that the two can vary independently.

Usage     ![Usage](Pictures/Usage3.png)     Medium

# UML class diagram

![AbstractFactory](Diagrams/UML/DesignPatterns/Bridge.png)

# Sample code

This structural code demonstrates the Builder pattern in which complex objects are created in a step-by-step fashion. The construction process can create different object representations and provides a high level of control over the assembly of the objects.

```c++
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
      _property<refptr<DesignPatterns::Structural::Implementor>, _writeonly> Implementor {
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
_startup(DesignPatterns::Structural::MainApp);
```

# Output

```
ConcreteImplementorA Operation
ConcreteImplementorB Operation
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2017 by GAMMA Soft.
