// Abstract Factory pattern -- Creational example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Creational {
    // The 'AbstractProductA' abstract class
    class AbstractProductA pcf_abstract {
    };
    
    // The 'AbstractProductB' abstract class
    class AbstractProductB pcf_abstract {
    public:
      virtual void Interact(const AbstractProductA& a) const =0;
    };
    
    // The 'AbstractFactory' abstract class
    class AbstractFactory pcf_abstract {
    public:
      virtual refptr<AbstractProductA> CreateProductA() const =0;
      virtual refptr<AbstractProductB> CreateProductB() const =0;
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
      refptr<AbstractProductA> CreateProductA() const override {return pcf_new<ProductA1>();}
      refptr<AbstractProductB> CreateProductB() const override {return pcf_new<ProductB1>();}
    };
    
    // The 'ConcreteFactory2' class
    class ConcreteFactory2 : public AbstractFactory {
    public:
      refptr<AbstractProductA> CreateProductA() const override {return pcf_new<ProductA2>();}
      refptr<AbstractProductB> CreateProductB() const override {return pcf_new<ProductB2>();}
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
      refptr<AbstractProductA> abstractProductA;
      refptr<AbstractProductB> abstractProductB;
    };
    
    class MainApp {
    public:
      // The main entry point for the application.
      static void Main() {
        // Abstract factory #1
        refptr<AbstractFactory> factory1 = pcf_new<ConcreteFactory1>();
        Client client1(*factory1);
        client1.Run();
        
        // Abstract factory #2
        refptr<AbstractFactory> factory2 = pcf_new<ConcreteFactory2>();
        Client client2(*factory2);
        client2.Run();
      }
    };
  }
}

pcf_startup (DesignPatterns::Creational::MainApp)

// This code produces the following output:
//
// ProductB1 interacts with ProductA1
// ProductB2 interacts with ProductA2
