// Mediator pattern -- Behavioral example

#include <Switch/Switch>

using namespace System;

namespace DesignPatterns {
  namespace Behavioral {
    class Mediator;

    // The 'Colleague' abstract class
    class Colleague abstract_ {
    public:
      // Constructor
      Colleague(Mediator& mediator) : mediator(mediator)  {}

    protected:
      ref<Mediator> mediator;
    };

    // The 'Mediator' abstract class
    class Mediator abstract_ {
    public:
      virtual void Send(const string& message, Colleague& colleague) = 0;
    };

    // A 'ConcreteColleague' class
    class ConcreteColleague1 : public Colleague {
    public:
      // Constructor
      explicit ConcreteColleague1(Mediator& mediator) : Colleague(mediator) {}

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
      explicit ConcreteColleague2(Mediator& mediator) : Colleague(mediator) {}

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
      property_<ConcreteColleague1, writeonly_> Colleague1 {
        set_ { colleague1 = value; }
      };

      property_<ConcreteColleague2, writeonly_> Colleague2 {
        set_ { colleague2 = value; }
      };

      void Send(const string& message, Colleague& colleague) override {
        if (colleague == this->colleague1)
          this->colleague2().Notify(message);
        else
          this->colleague1().Notify(message);
      }

    private:
      ref<ConcreteColleague1> colleague1;
      ref<ConcreteColleague2> colleague2;

    };

    // MainApp startup_ class for Behavioral
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
startup_(DesignPatterns::Behavioral::MainApp);

// This code produces the following output:
//
//  Colleague2 gets message: How are you?
//  Colleague1 gets message: Fine, thanks
