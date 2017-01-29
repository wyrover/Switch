// Adapter pattern -- Structural example

#include <Pcf/Pcf>

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
  }
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  using namespace DesignPatterns::Structural;
  
  // Create adapter and place a request
  Up<Target> target = new Adapter();
  target->Request();
  
  return 0;
}

// This code produces the following output:
//
// Called SpecificRequest()
