// Observer pattern -- Behavioral example

#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;

namespace DesignPatterns {
  namespace Behavioral {
    // The 'Observer' abstract class
    class Observer _abstract {
    public:
      virtual void Update() = 0;
    };

    // The 'Subject' abstract class
    class Subject _abstract {
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
      property<string> SubjectState {
        _get { return this->subjectState; },
        _set { this->subjectState = value; }
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
      property<refptr<ConcreteSubject>> Subject {
        _get { return this->subject; },
        _set { this->subject = value; }
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
_startup (DesignPatterns::Behavioral::MainApp)

// This code produces the following output:
//
// Observer X's new state is ABC
// Observer Y's new state is ABC
// Observer Z's new state is ABC
