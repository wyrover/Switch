// Observer pattern -- Structural example

#include <Pcf/Pcf>

using namespace System;
using namespace System::Collections::Generic;

namespace DesignPatterns {
  namespace Behavioral {
    /// <summary>
    /// The 'Observer' abstract class
    /// </summary>
    class Observer : public Abstract {
    public:
      virtual void Update() =0;
    };

    /// @brief The 'Subject' abstract class
    class Subject : public Abstract {
    public:
      void Attach(Sp<Observer> observer) {this->observers.Add(observer);}

      void Detach(Sp<Observer> observer) {this->observers.Remove(observer);}

      void Notify() {
        for(Sp<Observer> o : this->observers) {
          o->Update();
        }
      }

    private:
      List<Sp<Observer>> observers;
    };

    /// @brief The 'ConcreteSubject' class
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

    /// @brief The 'ConcreteObserver' class
    class ConcreteObserver : public Observer {
    public:
      // Constructor
      ConcreteObserver(Sp<ConcreteSubject> subject, const string& name) : subject(subject), name(name) {}

      void Update() override {
        this->observerState = this->subject->SubjectState;
        Console::WriteLine("Observer {0}'s new state is {1}", this->name, this->observerState);
      }

      // Gets or sets subject
      Property<Sp<ConcreteSubject>> Subject {
        pcf_get { return this->subject; },
        pcf_set { this->subject = value; }
      };

    private:
      string observerState;
      Sp<ConcreteSubject> subject;
      string name;
    };
  }
}

/// @brief Entry point into console application.
int main(int32 argc, char* argv[]) {
  using namespace DesignPatterns::Behavioral;
  
  // Configure Observer pattern
  Sp<ConcreteSubject> s = new ConcreteSubject();
  
  s->Attach(new ConcreteObserver(s, "X"));
  s->Attach(new ConcreteObserver(s, "Y"));
  s->Attach(new ConcreteObserver(s, "Z"));
  
  // Change subject and notify observers
  s->SubjectState = "ABC";
  s->Notify();
  
  // Wait for user
  Console::ReadKey();
}

// This code produces the following output:
//
// Observer X's new state is ABC
// Observer Y's new state is ABC
// Observer Z's new state is ABC
