// Observer pattern -- Behavorial example

#include <Pcf/Pcf>

using namespace System;
using namespace System::Collections::Generic;

namespace DesignPatterns {
  namespace Behavioral {
    // The 'Observer' abstract class
    class Observer pcf_abstract {
    public:
      virtual void Update() = 0;
    };

    // The 'Subject' abstract class
    class Subject pcf_abstract {
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
      Property<string> SubjectState {
        pcf_get { return this->subjectState; },
        pcf_set { this->subjectState = value; }
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
      Property<refptr<ConcreteSubject>> Subject {
        pcf_get { return this->subject; },
        pcf_set { this->subject = value; }
      };

    private:
      string observerState;
      refptr<ConcreteSubject> subject;
      string name;
    };
    
    /// MainApp startup class for Behavorial
    // Observer Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Configure Observer pattern
        refptr<ConcreteSubject> s = pcf_new<ConcreteSubject>();
        
        s->Attach(new ConcreteObserver(s, "X"));
        s->Attach(new ConcreteObserver(s, "Y"));
        s->Attach(new ConcreteObserver(s, "Z"));
        
        // Change subject and notify observers
        s->SubjectState = "ABC";
        s->Notify();
      }
    };
  }
}

// Specify the Main entry point to System
pcf_startup (DesignPatterns::Behavioral::MainApp)

// This code produces the following output:
//
// Observer X's new state is ABC
// Observer Y's new state is ABC
// Observer Z's new state is ABC
