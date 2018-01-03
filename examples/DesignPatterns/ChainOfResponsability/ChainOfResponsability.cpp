// Chain of Responsibility pattern -- Behavioral example

#include <Switch/Switch>

using namespace System;

namespace DesignPatterns {
  namespace Behavioral {
    // The 'Handler' abstract class
    class Handler abstract_ {
    public:
      void SetSuccessor(refptr<Handler> successor) {this->successor = successor;}

      virtual void HandleRequest(int request) const = 0;

    protected:
      refptr<Handler> successor;
    };

    // The 'ConcreteHandler1' class
    class ConcreteHandler1 : public Handler {
    public:
      void HandleRequest(int request) const override {
        if (request >= 0 && request < 10)
          Console::WriteLine("{0} handled request {1}", this->GetType().Name, request);
        else if (this->successor != null)
          successor->HandleRequest(request);
      }
    };

    // The 'ConcreteHandler2' class
    class ConcreteHandler2 : public Handler {
    public:
      void HandleRequest(int request) const override {
        if (request >= 10 && request < 20)
          Console::WriteLine("{0} handled request {1}", this->GetType().Name, request);
        else if (this->successor != null)
          successor->HandleRequest(request);
      }
    };

    // The 'ConcreteHandler3' class
    class ConcreteHandler3 : public Handler {
    public:
      void HandleRequest(int request) const override {
        if (request >= 20 && request < 30)
          Console::WriteLine("{0} handled request {1}", this->GetType().Name, request);
        else if (this->successor != null)
          successor->HandleRequest(request);
      }
    };

    // MainApp startup_ class for Behavioral
    // Chain Of Responsability Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Setup Chain of Responsibility
        refptr<Handler> h1 = ref_new<ConcreteHandler1>();
        refptr<Handler> h2 = ref_new<ConcreteHandler2>();
        refptr<Handler> h3 = ref_new<ConcreteHandler3>();
        h1->SetSuccessor(h2);
        h2->SetSuccessor(h3);

        // Generate and process request
        int requests[] = { 2, 5, 14, 22, 18, 3, 27, 20 };

        for (int request : requests)
          h1->HandleRequest(request);
      }
    };
  }
}

// Specify the Main entry point to System
startup_(DesignPatterns::Behavioral::MainApp);

// This code produces the following output:
//
// ConcreteHandler1 handled request 2
// ConcreteHandler1 handled request 5
// ConcreteHandler2 handled request 14
// ConcreteHandler3 handled request 22
// ConcreteHandler2 handled request 18
// ConcreteHandler1 handled request 3
// ConcreteHandler3 handled request 27
// ConcreteHandler3 handled request 20
