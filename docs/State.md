![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

# Definition

Allow an object to alter its behavior when its internal state changes. The object will appear to change its class.

Usage     ![Usage](Pictures/Usage3.png)     Medium

# UML class diagram

![AbstractFactory](Pictures/DesignPatterns/state.gif)

# Sample code

This structural code demonstrates the State pattern which allows an object to behave differently depending on its internal state. The difference in behavior is delegated to objects that represent this state.

```c++
// State pattern -- Behavioral example
 
#include <Switch/Switch>
 
using namespace System;
 
namespace DesignPatterns {
  namespace Behavioral {
    class Context;
    // The 'State' abstract class
    class State _abstract {
    public:
      virtual void Handle(Context& context) = 0;
    };
 
    // The 'Context' class
    class Context : public object {
    public:
      // Constructor
      Context(refptr<DesignPatterns::Behavioral::State> state) {
        this->State = state;
      }
      
      // Gets or sets the state
      _property<refptr<DesignPatterns::Behavioral::State>> State {
        _get { return this->state; },
        _set {
          this->state = value;
          Console::WriteLine("State: " + this->state->GetType().Name);
        }
      };
      
      void Request() {
        this->state->Handle(*this);
      }
 
    private:
      refptr<DesignPatterns::Behavioral::State> state;
    };
    
    // A 'ConcreteState' class
    class ConcreteStateA : public State {
    public:
      void Handle(Context& context) override;
    };
    
    // A 'ConcreteState' class
    class ConcreteStateB : public State {
    public:
      void Handle(Context& context) override;
    };
 
    inline void ConcreteStateA::Handle(Context& context) {
      context.State = ref_new<ConcreteStateB>();
    }
 
    inline void ConcreteStateB::Handle(Context& context) {
      context.State = ref_new<ConcreteStateA>();
    }
 
    // MainApp startup class for Behavioral
    // State Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Setup context in a state
        Context c(ref_new<ConcreteStateA>());
        
        // Issue requests, which toggles state
        c.Request();
        c.Request();
        c.Request();
        c.Request();
      }
    };
  }
}
 
// Specify the Main entry point to System
_startup(DesignPatterns::Behavioral::MainApp);
```

# Output

```
State: ConcreteStateA
State: ConcreteStateB
State: ConcreteStateA
State: ConcreteStateB
State: ConcreteStateA
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2017 by GAMMA Soft.
