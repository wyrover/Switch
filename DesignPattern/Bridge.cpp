// Bridge pattern -- Structural example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Structural {
    /// @brief The 'Implementor' abstract class
    class Implementor : public Abstract {
    public:
      virtual void Operation() const =0;
    };
    
    /// @brief The 'Abstraction' class
    class Abstraction : public object {
    public:
      // Property
      Property<Up<DesignPatterns::Structural::Implementor>, WriteOnly> Implementor {
        pcf_set {this->implementor = value;}
      };
      
      virtual void Operation() const {
        this->implementor->Operation();
      }

    protected:
      Up<DesignPatterns::Structural::Implementor> implementor;
    };
    
    /// @brief The 'RefinedAbstraction' class
    class RefinedAbstraction : public Abstraction {
    public:
      void Operation() const override {
        this->implementor->Operation();
      }
    };
    
    /// @brief The 'ConcreteImplementorA' class
    class ConcreteImplementorA : public Implementor {
    public:
      void Operation() const override {
        Console::WriteLine("ConcreteImplementorA Operation");
      }
    };
    
    /// @brief The 'ConcreteImplementorB' class
    class ConcreteImplementorB : public Implementor {
    public:
      void Operation() const override {
        Console::WriteLine("ConcreteImplementorB Operation");
      }
    };
  }
}

/// @brief Entry point into console application.
int main(int argc, char* argv[]) {
  using namespace DesignPatterns::Structural;
  
  Up<Abstraction> ab = new RefinedAbstraction();
  
  // Set implementation and call
  ab->Implementor = new ConcreteImplementorA();
  ab->Operation();
  
  // Change implemention and call
  ab->Implementor = new ConcreteImplementorB();
  ab->Operation();
}

// This code produces the following output:
//
// oncreteImplementorA Operation
// ConcreteImplementorB Operation
