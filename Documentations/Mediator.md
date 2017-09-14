![Switch Header](Images/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Download](Download.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

# Definition

Define an object that encapsulates how a set of objects interact. Mediator promotes loose coupling by keeping objects from referring to each other explicitly, and it lets you vary their interaction independently.

# UML class diagram

![AbstractFactory](Images/DesignPatterns/mediator.gif)

# Sample code

This structural code demonstrates the Mediator pattern facilitating loosely coupled communication between different objects and object types. The mediator is a central hub through which all interaction must take place.

```c++
// Mediator pattern -- Behavioral example
 
#include <Switch/Switch>
 
using namespace System;
 
namespace DesignPatterns {
  namespace Behavioral {
    class Mediator;
    
    // The 'Colleague' abstract class
    class Colleague _abstract {
    public:
      // Constructor
      Colleague(Mediator& mediator) : mediator(mediator)  {}
 
    protected:
      ref<Mediator> mediator;
    };
    
    // The 'Mediator' abstract class
    class Mediator _abstract {
    public:
      virtual void Send(const string& message, Colleague& colleague) = 0;
    };
    
    // A 'ConcreteColleague' class
    class ConcreteColleague1 : public Colleague {
    public:
      // Constructor
      ConcreteColleague1(Mediator& mediator) : Colleague(mediator) {}
      
      void Send(const string& message) {
        mediator().Send(message, *this);
      }
      
      void Notify(const string& message) {
        Console::WriteLine("Colleague1 gets message: " + message);
      }
    };
    
    // A 'ConcreteColleague' class
    class ConcreteColleague2 : public Colleague {
    public:
      // Constructor
      ConcreteColleague2(Mediator& mediator) : Colleague(mediator) {}
      
      void Send(const string& message) {
        mediator().Send(message, *this);
      }
      
      void Notify(const string& message) {
        Console::WriteLine("Colleague2 gets message: " + message);
      }
    };
    
    // The 'ConcreteMediator' class
    class ConcreteMediator : public Mediator {
    public:
      _property<ConcreteColleague1, _writeonly> Colleague1 {
        _set { colleague1 = value; }
      };
      
      _property<ConcreteColleague2, _writeonly> Colleague2 {
        _set { colleague2 = value; }
      };
      
      void Send(const string& message, Colleague& colleague) override {
        if (colleague == this->colleague1) {
          this->colleague2().Notify(message);
        } else {
          this->colleague1().Notify(message);
        }
      }
 
    private:
      ref<ConcreteColleague1> colleague1;
      ref<ConcreteColleague2> colleague2;
 
    };
    
    // MainApp startup class for Behavioral
    // Mediator Design Pattern.
    class MainApp {
    public:
      /// Entry point into console application.
      static void Main() {
        ConcreteMediator m;
        
        ConcreteColleague1 c1(m);
        ConcreteColleague2 c2(m);
        
        m.Colleague1 = c1;
        m.Colleague2 = c2;
        
        c1.Send("How are you?");
        c2.Send("Fine, thanks");
      }
    };
  }
}
 
// Specify the Main entry point to System
_startup (DesignPatterns::Behavioral::MainApp)
```

# Output

```
Colleague2 gets message: How are you?
Colleague1 gets message: Fine, thanks
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2017 by GAMMA Soft.
