#include <Switch/Switch>

using namespace System;

namespace Examples {
  // Defines some methods to which the delegate can point.
  class Program : public object {
  public:
    // Defines an instance method.
    void OnMyEvent(const Object&, const EventArgs&) {
      Console::WriteLine("  OnMyEvent is called.");
    }
    
    // Defines a static method.
    static void OnMyEventStatic(const Object&, const EventArgs&) {
      Console::WriteLine("  OnMyEventStatic is called.");
    }

    // The main entry point for the application.
    static void Main() {
      // Creates one delegate for two method. For the instance method, an
      // instance (mySC) must be supplied. For the static method, use the
      // class name.
      Program mySC;
      EventHandler myEvent;
      
      myEvent += {mySC, &Program::OnMyEvent};
      myEvent += OnMyEventStatic;
      
      // Invokes the EventHandler.
      Console::WriteLine("Call myEvent :");
      myEvent(string("Sender"), EventArgs());
    }
  };
}

startup (Examples::Program)

// This code produces the following output:
//
// Call myEvent :
//   OnMyEvent is called.
//   OnMyEventStatic is called.
