![Switch Header](Images/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

# Definition

Provide a surrogate or placeholder for another object to control access to it.

# UML class diagram

![AbstractFactory](Images/DesignPatterns/proxy.gif)

# Sample code

This structural code demonstrates the Proxy pattern which provides a representative object (proxy) that controls access to another similar object.

```c++
// Proxy pattern -- Structural example
 
#include <Switch/Switch>
 
using namespace System;
 
namespace DesignPatterns {
  namespace Structural {
    // The 'Subject' abstract class
    class Subject _abstract {
    public:
      virtual void Request() const = 0;
    };
    
    // The 'RealSubject' class
    class RealSubject : public Subject {
    public:
      void Request() const override {Console::WriteLine("Called RealSubject.Request()");}
    };
    
    // The 'Proxy' class
    class Proxy : public Subject {
    public:
      void Request() const override  {
        this->realSubject.Request();
      }
 
    private:
      RealSubject realSubject;
    };
    
    // MainApp startup class for Structural
    // Proxy Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Create proxy and request a service
        Proxy proxy;
        proxy.Request();
      }
    };
  }
}
 
// Specify the Main entry point to System
_startup (DesignPatterns::Structural::MainApp)
```

# Output

```
Called RealSubject.Request()
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2017 by GAMMA Soft.
