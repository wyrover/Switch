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
      Memento(const string& state) : state(state) {}
      Memento(const Memento& memento) : state(memento.state) {}
      
      // Gets or sets state
      Property<string, ReadOnly> State {
        _get { return this->state; }
      };

    private:
      string state;
    };
    
    // The 'Originator' class
    class Originator : public object {
    public:
      // Property
      Property<string> State {
        _get { return this->state; },
        _set {
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
      Property<DesignPatterns::Behavioral::Memento> Memento {
        _get { return this->memento; },
        _set { this->memento = value; }
      };

    private:
      DesignPatterns::Behavioral::Memento memento;
    };

    // MainApp startup class for Behavioral
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
_startup (DesignPatterns::Behavioral::MainApp)

// This code produces the following output:
//
// State = On
// State = Off
// Restoring state...
// State = On
