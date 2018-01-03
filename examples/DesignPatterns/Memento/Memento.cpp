// Memento pattern -- Behavioral example

#include <Switch/Switch>

using namespace System;

namespace DesignPatterns {
  namespace Behavioral {
    // The 'Memento' class
    class Memento : public object {
    public:
      // Constructor
      Memento() {}
      explicit Memento(const string& state) : state(state) {}
      Memento(const Memento& memento) : state(memento.state) {}
      Memento& operator=(const Memento& memento) {
        this->state = memento.state;
        return *this;
      }

      // Gets or sets state
      property_<string, readonly_> State {
        get_ { return this->state; }
      };

    private:
      string state;
    };

    // The 'Originator' class
    class Originator : public object {
    public:
      // Property
      property_<string> State {
        get_ { return this->state; },
        set_ {
          this->state = value;
          Console::WriteLine("State = " + this->state);
        }
      };

      // Creates memento
      Memento CreateMemento() {
        return Memento(this->state);
      }

      // Restores original state
      void SetMemento(const Memento& memento) {
        Console::WriteLine("Restoring state...");
        State = memento.State;
      }

    private:
      string state;
    };

    // The 'Caretaker' class
    class Caretaker : public object {
    public:
      Caretaker() {}

      // Gets or sets memento
      property_<DesignPatterns::Behavioral::Memento> Memento {
        get_ { return this->memento; },
        set_ { this->memento = value; }
      };

    private:
      DesignPatterns::Behavioral::Memento memento;
    };

    // MainApp startup_ class for Behavioral
    // Memento Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        Originator o;
        o.State = "On";

        // Store internal state
        Caretaker c;
        c.Memento = o.CreateMemento();

        // Continue changing originator
        o.State = "Off";

        // Restore saved state
        o.SetMemento(c.Memento);
      }
    };
  }
}

// Specify the Main entry point to System
startup_(DesignPatterns::Behavioral::MainApp);

// This code produces the following output:
//
// State = On
// State = Off
// Restoring state...
// State = On
