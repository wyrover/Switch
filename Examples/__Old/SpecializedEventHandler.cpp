#include <Pcf/Pcf>

using namespace System;

namespace SpecializedEventHandlerExample {
  // define a secialized event argument from EventArgs class contains a string message
  class SpecializedEventArgs : public EventArgs {
  public:
    explicit SpecializedEventArgs(const string& message) : EventArgs(), message(message) { }
    SpecializedEventArgs(const SpecializedEventArgs& e) : EventArgs(e), message(e.message) { }

    const string& GetMessage() const { return this->message; }

  private:
    string message;
  };

  // Declares a specialized event handler from TEventHandler<T> with a SpecializedEventArgs argument.
  using SpecializedEventHandler = TEventHandler<const SpecializedEventArgs&>;

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
}

int main(int argc, char* argv[]) {
  using namespace SpecializedEventHandlerExample;
  
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

//This code produces the following output:
//
//Call myEvent :
//  OnMyEvent is called - First call.
//  OnMyEventStatic is called - First call.
