// Abstract Factory pattern -- Creational example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Creational {
    // The 'AbstractProductA' abstract class
    class AbstractProductA : public Abstract {
    };
    
    // The 'AbstractProductB' abstract class
    class AbstractProductB : public Abstract {
    public:
      virtual void Interact(const AbstractProductA& a) const =0;
    };
    
    // The 'AbstractFactory' abstract class
    class AbstractFactory : public Abstract {
    public:
      virtual Up<AbstractProductA> CreateProductA() const =0;
      virtual Up<AbstractProductB> CreateProductB() const =0;
    };
    
    // The 'ProductA1' class
    class ProductA1 final : public AbstractProductA {
    };
    
    // The 'ProductB1' class
    class ProductB1 final : public AbstractProductB {
    public:
      void Interact(const AbstractProductA& a) const override {Console::WriteLine(string::Format("{0} interacts with {1}", this->GetType().Name, a.GetType().Name));}
    };
    
    // The 'ProductA2' class
    class ProductA2 final : public AbstractProductA {
    };
    
    // The 'ProductB2' class
    class ProductB2 final : public AbstractProductB {
    public:
      void Interact(const AbstractProductA& a) const override {Console::WriteLine(string::Format("{0} interacts with {1}", this->GetType().Name, a.GetType().Name));}
    };
    
    // The 'ConcreteFactory1' class
    class ConcreteFactory1 : public AbstractFactory {
    public:
      Up<AbstractProductA> CreateProductA() const override {return Up<AbstractProductA>::Create<ProductA1>();}
      Up<AbstractProductB> CreateProductB() const override {return Up<AbstractProductB>::Create<ProductB1>();}
    };
    
    // The 'ConcreteFactory2' class
    class ConcreteFactory2 : public AbstractFactory {
    public:
      Up<AbstractProductA> CreateProductA() const override {return Up<AbstractProductA>::Create<ProductA2>();}
      Up<AbstractProductB> CreateProductB() const override {return Up<AbstractProductB>::Create<ProductB2>();}
    };
    
    // The 'Client' class. Interaction environment for the products.
    class Client : public object {
    public:
      // Constructor
      Client(const AbstractFactory& factory) {
        this->abstractProductB = factory.CreateProductB();
        this->abstractProductA = factory.CreateProductA();
      }
      
      void Run() {this->abstractProductB->Interact(*this->abstractProductA);}

    private:
      Up<AbstractProductA> abstractProductA;
      Up<AbstractProductB> abstractProductB;
    };
  }
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  using namespace DesignPatterns::Creational;

  // Abstract factory #1
  Up<AbstractFactory> factory1 = Up<AbstractFactory>::Create<ConcreteFactory1>();
  Client client1(*factory1);
  client1.Run();
  
  // Abstract factory #2
  Up<AbstractFactory> factory2 = Up<AbstractFactory>::Create<ConcreteFactory2>();
  Client client2(*factory2);
  client2.Run();
  
  return 0;
}

// This code produces the following output:
//
// ProductB1 interacts with ProductA1
// ProductB2 interacts with ProductA2
