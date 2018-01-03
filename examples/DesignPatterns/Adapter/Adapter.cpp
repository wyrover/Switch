// Adapter pattern -- Structural example

#include <Switch/Switch>

using namespace System;

namespace DesignPatterns {
  namespace Structural {
    // The 'Target' class
    class Target : public object {
    public:
      virtual void Request() const {
        Console::WriteLine("Called Target Request()");
      }
    };

    // The 'Adaptee' class
    class Adaptee : public object {
    public:
      void SpecificRequest() const {
        Console::WriteLine("Called SpecificRequest()");
      }
    };

    // The 'Adapter' class
    class Adapter : public Target {
    public:
      void Request() const override {
        // Possibly do some other work
        //  and then call SpecificRequest
        this->adaptee.SpecificRequest();
      }
    private:
      Adaptee adaptee;
    };

    // MainApp startup_ class for Structural
    // Adapter Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Create adapter and place a request
        refptr<Target> target = ref_new<Adapter>();
        target->Request();
      }
    };
  }
}

// Specify the Main entry point to System
startup_(DesignPatterns::Structural::MainApp);

// This code produces the following output:
//
// Called SpecificRequest()
