![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

# Definition

Define the skeleton of an algorithm in an operation, deferring some steps to subclasses. Template Method lets subclasses redefine certain steps of an algorithm without changing the algorithm's structure.

Usage     ![Usage](Pictures/Usage3.png)     Medium

# UML class diagram

![AbstractFactory](Pictures/DesignPatterns/template.gif)

# Sample code

This structural code demonstrates the Template method which provides a skeleton calling sequence of methods. One or more steps can be deferred to subclasses which implement these steps without changing the overall calling sequence.

```c++
// Template Method pattern -- Bahavorial example
 
#include <Switch/Switch>
 
using namespace System;
 
namespace DesignPatterns {
  namespace Behavioral {
    // The 'AbstractClass' abstract class
    class AbstractClass abstract_ {
    public:
      virtual void PrimitiveOperation1() = 0;
      virtual void PrimitiveOperation2() = 0;
      
      // The "Template method"
      void TemplateMethod() {
        PrimitiveOperation1();
        PrimitiveOperation2();
        Console::WriteLine("");
      }
    };
    
    // A 'ConcreteClass' class
    class ConcreteClassA : public AbstractClass {
    public:
      void PrimitiveOperation1() override {
        Console::WriteLine("ConcreteClassA.PrimitiveOperation1()");
      }
      
      void PrimitiveOperation2() override {
        Console::WriteLine("ConcreteClassA.PrimitiveOperation2()");
      }
    };
    
    // A 'ConcreteClass' class
    class ConcreteClassB : public AbstractClass {
    public:
      void PrimitiveOperation1() override {
        Console::WriteLine("ConcreteClassB.PrimitiveOperation1()");
      }
      
      void PrimitiveOperation2() override {
        Console::WriteLine("ConcreteClassB.PrimitiveOperation2()");
      }
    };
    
    // MainApp startup class for Behavioral
    // Template Method Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        refptr<AbstractClass> aA = ref_new<ConcreteClassA>();
        aA->TemplateMethod();
        
        refptr<AbstractClass> aB = ref_new<ConcreteClassB>();
        aB->TemplateMethod();
      }
    };
  }
}
 
// Specify the Main entry point to System
startup_(DesignPatterns::Behavioral::MainApp);
```

# Output

```
ConcreteClassA.PrimitiveOperation1()
ConcreteClassA.PrimitiveOperation2()
​
ConcreteClassB.PrimitiveOperation1()
ConcreteClassB.PrimitiveOperation2()
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
