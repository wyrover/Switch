![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

# Definition

Avoid coupling the sender of a request to its receiver by giving more than one object a chance to handle the request. Chain the receiving objects and pass the request along the chain until an object handles it.

Usage     ![Usage](Pictures/Usage2.png)     Medium low

# UML class diagram

![AbstractFactory](Pictures/DesignPatterns/chain.gif)

# Sample code

This structural code demonstrates the Chain of Responsibility pattern in which several linked objects (the Chain) are offered the opportunity to respond to a request or hand it off to the object next in line.

```c++
// Chain of Responsibility pattern -- Behavioral example
 
#include <Switch/Switch>
 
using namespace System;
 
namespace DesignPatterns {
  namespace Behavioral {
    // The 'Handler' abstract class
    class Handler _abstract {
    public:
      void SetSuccessor(refptr<Handler> successor) {this->successor = successor;}
      
      virtual void HandleRequest(int request) const =0;
 
    protected:
      refptr<Handler> successor;
    };
    
    // The 'ConcreteHandler1' class
    class ConcreteHandler1 : public Handler {
    public:
      void HandleRequest(int request) const override {
        if (request >= 0 && request < 10) {
          Console::WriteLine("{0} handled request {1}", this->GetType().Name, request);
        } else if (!this->successor.IsNull()) {
          successor->HandleRequest(request);
        }
      }
    };
    
    // The 'ConcreteHandler2' class
    class ConcreteHandler2 : public Handler {
    public:
      void HandleRequest(int request) const override {
        if (request >= 10 && request < 20) {
          Console::WriteLine("{0} handled request {1}", this->GetType().Name, request);
        } else if (!this->successor.IsNull()) {
          successor->HandleRequest(request);
        }
      }
    };
    
    // The 'ConcreteHandler3' class
    class ConcreteHandler3 : public Handler {
    public:
      void HandleRequest(int request) const override {
        if (request >= 20 && request < 30) {
          Console::WriteLine("{0} handled request {1}", this->GetType().Name, request);
        } else if (!this->successor.IsNull()) {
          successor->HandleRequest(request);
        }
      }
    };
    
    // MainApp startup class for Behavioral
    // Chain Of Responsability Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Setup Chain of Responsibility
        refptr<Handler> h1 = ref_new<ConcreteHandler1>();
        refptr<Handler> h2 = ref_new<ConcreteHandler2>();
        refptr<Handler> h3 = ref_new<ConcreteHandler3>();
        h1->SetSuccessor(h2);
        h2->SetSuccessor(h3);
        
        // Generate and process request
        int requests[] = { 2, 5, 14, 22, 18, 3, 27, 20 };
        
        for (int request : requests) {
          h1->HandleRequest(request);
        }
      }
    };
  }
}
 
// Specify the Main entry point to System
_startup (DesignPatterns::Behavioral::MainApp)
```

# Output

```
ConcreteHandler1 handled request 2
ConcreteHandler1 handled request 5
ConcreteHandler2 handled request 14
ConcreteHandler3 handled request 22
ConcreteHandler2 handled request 18
ConcreteHandler1 handled request 3
ConcreteHandler3 handled request 27
ConcreteHandler3 handled request 20
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2017 by GAMMA Soft.
