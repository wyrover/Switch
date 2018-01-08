![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

# Definition

Define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

Usage     ![Usage](Pictures/Usage5.png)     High

# UML class diagram

![AbstractFactory](Pictures/DesignPatterns/observer.gif)

# Sample code

This structural code demonstrates the Observer pattern in which registered objects are notified of and updated with a state change.

```c++
// Observer pattern -- Behavioral example
 
#include <Switch/Switch>
 
using namespace System;
using namespace System::Collections::Generic;
 
namespace DesignPatterns {
  namespace Behavioral {
    // The 'Observer' abstract class
    class Observer abstract_ {
    public:
      virtual void Update() = 0;
    };
 
    // The 'Subject' abstract class
    class Subject abstract_ {
    public:
      void Attach(refptr<Observer> observer) {this->observers.Add(observer);}
 
      void Detach(refptr<Observer> observer) {this->observers.Remove(observer);}
 
      void Notify() {
        for(refptr<Observer> o : this->observers) {
          o->Update();
        }
      }
 
    private:
      List<refptr<Observer>> observers;
    };
 
    // The 'ConcreteSubject' class
    class ConcreteSubject : public Subject {
    public:
      // Gets or sets subject state
      property_<string> SubjectState {
        get_ { return this->subjectState; },
        set_ { this->subjectState = value; }
      };
 
    private:
      string subjectState;
    };
 
    // The 'ConcreteObserver' class
    class ConcreteObserver : public Observer {
    public:
      // Constructor
      ConcreteObserver(refptr<ConcreteSubject> subject, const string& name) : subject(subject), name(name) {}
 
      void Update() override {
        this->observerState = this->subject->SubjectState;
        Console::WriteLine("Observer {0}'s new state is {1}", this->name, this->observerState);
      }
 
      // Gets or sets subject
      property_<refptr<ConcreteSubject>> Subject {
        get_ { return this->subject; },
        set_ { this->subject = value; }
      };
 
    private:
      string observerState;
      refptr<ConcreteSubject> subject;
      string name;
    };
    
    // MainApp startup class for Behavioral
    // Observer Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Configure Observer pattern
        refptr<ConcreteSubject> s = ref_new<ConcreteSubject>();
        
        s->Attach(ref_new<ConcreteObserver>(s, "X"));
        s->Attach(ref_new<ConcreteObserver>(s, "Y"));
        s->Attach(ref_new<ConcreteObserver>(s, "Z"));
        
        // Change subject and notify observers
        s->SubjectState = "ABC";
        s->Notify();
      }
    };
  }
}
 
// Specify the Main entry point to System
startup_(DesignPatterns::Behavioral::MainApp);
```

# Output

```
Observer X's new state is ABC
Observer Y's new state is ABC
Observer Z's new state is ABC
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
