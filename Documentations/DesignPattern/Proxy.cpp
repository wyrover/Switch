// Proxy pattern -- Structural example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Structural {
    /// @brief The 'Subject' abstract class
    class Subject : public Abstract {
    public:
      virtual void Request() const =0;
    };
    
    /// @brief The 'RealSubject' class
    class RealSubject : public Subject {
    public:
      void Request() const override {Console::WriteLine("Called RealSubject.Request()");}
    };
    
    /// @brief The 'Proxy' class
    class Proxy : public Subject {
    public:
      void Request() const override  {
        this->realSubject.Request();
      }

    private:
      RealSubject realSubject;
    };
  }
}

/// @brief Entry point into console application.
int main(int argc, char* argv[]) {
  using namespace DesignPatterns::Structural;
  
  // Create proxy and request a service
  Proxy proxy;
  proxy.Request();
}

// This code produces the following output:
//
// Called RealSubject.Request()
