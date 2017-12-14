#include <Switch/Switch>

using namespace System;

namespace Examples {
  // define a secialized event argument from EventArgs class contains a string message
  class SpecializedEventArgs : public EventArgs {
  public:
    explicit SpecializedEventArgs(const string& message) : EventArgs(), message(message) { }
    SpecializedEventArgs(const SpecializedEventArgs& e) : EventArgs(e), message(e.message) { }
    SpecializedEventArgs& operator=(const SpecializedEventArgs& e) {
      this->EventArgs::operator=(e);
      this->message = e.message;
      return *this;
    }

    const string& GetMessage() const { return this->message; }

  private:
    string message;
  };

  // Declares a specialized event handler from GenericEventHandler<T> with a SpecializedEventArgs argument.
  using SpecializedEventHandler = GenericEventHandler<const SpecializedEventArgs&>;

  // Defines some methods to which the delegate can point.
  class MySampleClass : public object {
  public:
    // Defines an instance method.
    void OnMyEvent(const Object&, const SpecializedEventArgs& e) {
      Console::WriteLine("  OnMyEvent is called - {0}", e.GetMessage());
    }

    // Defines a static method.
    static void OnMyEventStatic(const Object&, const SpecializedEventArgs& e) {
      Console::WriteLine("  OnMyEventStatic is called - {0}", e.GetMessage());
    }
  };

  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Creates one delegate for two method. For the instance method, an
      // instance (mySC) must be supplied. For the static method, use the
      // class name.
      MySampleClass mySC;
      SpecializedEventHandler myEvent;

      myEvent += SpecializedEventHandler(mySC, &MySampleClass::OnMyEvent);
      myEvent += SpecializedEventHandler(&MySampleClass::OnMyEventStatic);

      // Invokes the EventHandler.
      Console::WriteLine("Call myEvent :");
      myEvent(string("Sender"), SpecializedEventArgs("First call."));
    }
  };
}

_startup(Examples::Program);

//This code produces the following output:
//
//Call myEvent :
//  OnMyEvent is called - First call.
//  OnMyEventStatic is called - First call.
