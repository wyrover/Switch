#include <Switch/Switch>

using namespace System;

namespace SwitchEvents {
  // Define a class to hold custom event info
  /// The following example shows how to declare and raise an event that uses EventHandler as the underlying delegate type.
  /// @include Event.cpp
  class CustomEventArgs : public EventArgs {
  public:
    CustomEventArgs(const string& s) : message(s) {}
    CustomEventArgs(const CustomEventArgs& cea) : message(cea.message) {}
    
    property<string> Message {
      _get { return this->message; },
      _set { this->message = value; }
    };
    
  private:
    string message;
  };
  
  // Class that publishes an event
  class Publisher : public object {
  public:
    // Declare the event using EventHandler<T>
    event<Publisher, GenericEventHandler<const CustomEventArgs&>> RaiseCustomEvent;
    
    void DoSomething() {
      // Write some code that does something useful here
      // then raise the event. You can also raise an event
      // before you execute a block of code.
      CustomEventArgs customEventArgs("Did something");
      OnRaiseCustomEvent(customEventArgs);
    }
    
  protected:
    // Wrap event invocations inside a protected virtual method
    // to allow derived classes to override the event invocation behavior
    virtual void OnRaiseCustomEvent(CustomEventArgs& e) const {
      // Make a temporary copy of the event to avoid possibility of
      // a race condition if the last subscriber unsubscribes
      // immediately after the null check and before the event is raised.
      GenericEventHandler<const CustomEventArgs&> handler = as<GenericEventHandler<const CustomEventArgs&>>(RaiseCustomEvent);
      
      // Format the string to send inside the CustomEventArgs parameter
      e.Message += String::Format(" at {0}", DateTime::Now().ToString());
        
      // Use the () operator to raise the event.
      handler(*this, e);
    }
  };
  
  //Class that subscribes to an event
  class Subscriber : public object {
  public:
    Subscriber(const string& id, Publisher& pub) : id(id) {
      // Subscribe to the event
      pub.RaiseCustomEvent += {*this, &Subscriber::HandleCustomEvent};
    }
    
    // Define what actions to take when the event is raised.
    void HandleCustomEvent(const object& sender, const CustomEventArgs& e) const {
      Console::WriteLine(id + " received this message: {0}", e.Message);
    }

  private:
    string id;
  };

  class Program : public object {
  public:
    // The main entry point for the application.
    static void Main() {
      
      Publisher pub;
      Subscriber sub1("sub1", pub);
      Subscriber sub2("sub2", pub);
      
      // Call the method that raises the event.
      pub.DoSomething();
    }
  };
}

startup (SwitchEvents::Program)

// This code produces output similar to the following:
//
// sub1 received this message: Did something at 19/06/2017 10:56:51
// sub2 received this message: Did something at 19/06/2017 10:56:51
