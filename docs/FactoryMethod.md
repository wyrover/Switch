[![Switch Header](Pictures/SwitchNativeC++port.png)](https://gammasoft71.wixsite.com/switch)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|---------------------------------------------------------|

# Definition

Define an interface for creating an object, but let subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses.

Usage     ![Usage](Pictures/Usage5.png)     High

# UML class diagram

![AbstractFactory](Diagrams/UML/DesignPatterns/FactoryMethod.png)

# Sample code

This structural code demonstrates the Factory method offering great flexibility in creating different objects. The Abstract class may provide a default object, but each subclass can instantiate an extended version of the object.

```c++
// Factory Method pattern -- Creational example
​
#include <Switch/Switch>
​
using namespace System;
​
namespace DesignPatterns {
  namespace Creational {
    // The 'Product' abstract class
    class Product abstract_ {
    public:
      ~Product() = 0;
    };
    
    inline Product::~Product() {}
    
    // A 'ConcreteProduct' class
    class ConcreteProductA : public Product {
    };
    
    // A 'ConcreteProduct' class
    class ConcreteProductB : public Product {
    };
    
    // The 'Creator' abstract class
    class Creator abstract_ {
    public:
      virtual refptr<Product> FactoryMethod() const = 0;
    };
    
    // A 'ConcreteCreator' class
    class ConcreteCreatorA : public Creator {
    public:
      refptr<Product> FactoryMethod() const override {return ref_new<ConcreteProductA>();}
    };
    
    // A 'ConcreteCreator' class
    class ConcreteCreatorB : public Creator {
    public:
      refptr<Product> FactoryMethod() const override {return ref_new<ConcreteProductB>();}
    };
    
    // MainApp startup class for Creational
    // Factory Method Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // An array of creators
        Array<refptr<Creator>> creators(2);
        
        creators[0] = ref_new<ConcreteCreatorA>();
        creators[1] = ref_new<ConcreteCreatorB>();
        
        // Iterate over creators and create products
        for (refptr<Creator> creator : creators) {
          refptr<Product> product = creator->FactoryMethod();
          Console::WriteLine("Created {0}", product->GetType().Name);
        }
      }
    };
  }
}
 
// Specify the Main entry point to System
startup_(DesignPatterns::Creational::MainApp);
```

# Output

```
Created ConcreteProductA
Created ConcreteProductB
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
