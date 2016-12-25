// Chain of Responsibility pattern -- Structural example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Behavioral {
    /// @brief The 'Handler' abstract class
    class Handler : public Abstract {
    public:
      void SetSuccessor(Sp<Handler> successor) {this->successor = successor;}
      
      virtual void HandleRequest(int request) const =0;

    protected:
      Sp<Handler> successor;
    };
    
    /// @brief The 'ConcreteHandler1' class
    class ConcreteHandler1 : public Handler {
    public:
      void HandleRequest(int request) const override {
        if (request >= 0 && request < 10) {
          Console::WriteLine("{0} handled request {1}", this->GetType().Name, request);
        } else if (!this->successor.IsNull()) {
          successor->HandleRequest(request);
        }
      }
    };
    
    /// @brief The 'ConcreteHandler2' class
    class ConcreteHandler2 : public Handler {
    public:
      void HandleRequest(int request) const override {
        if (request >= 10 && request < 20) {
          Console::WriteLine("{0} handled request {1}", this->GetType().Name, request);
        } else if (!this->successor.IsNull()) {
          successor->HandleRequest(request);
        }
      }
    };
    
    /// @brief The 'ConcreteHandler3' class
    class ConcreteHandler3 : public Handler {
    public:
      void HandleRequest(int request) const override {
        if (request >= 20 && request < 30) {
          Console::WriteLine("{0} handled request {1}", this->GetType().Name, request);
        } else if (!this->successor.IsNull()) {
          successor->HandleRequest(request);
        }
      }
    };
  }
}

/// @brief Entry point into console application.
int main(int argc, char* argv[]) {
  using namespace DesignPatterns::Behavioral;
  
  // Setup Chain of Responsibility
  Sp<Handler> h1 = new ConcreteHandler1();
  Sp<Handler> h2 = new ConcreteHandler2();
  Sp<Handler> h3 = new ConcreteHandler3();
  h1->SetSuccessor(h2);
  h2->SetSuccessor(h3);
  
  // Generate and process request
  int requests[] = { 2, 5, 14, 22, 18, 3, 27, 20 };
  
  for (int request : requests) {
    h1->HandleRequest(request);
  }
}

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
