// State pattern -- Behavioral example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Behavioral {
    class Context;
    // The 'State' abstract class
    class State pcf_abstract {
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
      Property<refptr<DesignPatterns::Behavioral::State>> State {
        pcf_get { return this->state; },
        pcf_set {
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
      context.State = pcf_new<ConcreteStateB>();
    }

    inline void ConcreteStateB::Handle(Context& context) {
      context.State = pcf_new<ConcreteStateA>();
    }

    // MainApp startup class for Behavioral
    // State Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Setup context in a state
        Context c(pcf_new<ConcreteStateA>());
        
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
pcf_startup (DesignPatterns::Behavioral::MainApp)

// This code produces the following output:
//
// State: ConcreteStateA
// State: ConcreteStateB
// State: ConcreteStateA
// State: ConcreteStateB
// State: ConcreteStateA
