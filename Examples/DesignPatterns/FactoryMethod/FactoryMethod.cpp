// Factory Method pattern -- Creational example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Creational {
    // The 'Product' abstract class
    class Product pcf_abstract {
    public:
      ~Product() = 0;
    };
    
    inline Product::~Product() {}
    
    // A 'ConcreteProduct' class
    class ConcreteProductA : public Product {
    };
    
    // A 'ConcreteProduct' class
    class ConcreteProductB : public Product {
    };
    
    // The 'Creator' abstract class
    class Creator pcf_abstract {
    public:
      virtual refptr<Product> FactoryMethod() const = 0;
    };
    
    // A 'ConcreteCreator' class
    class ConcreteCreatorA : public Creator {
    public:
      refptr<Product> FactoryMethod() const override {return pcf_new<ConcreteProductA>();}
    };
    
    // A 'ConcreteCreator' class
    class ConcreteCreatorB : public Creator {
    public:
      refptr<Product> FactoryMethod() const override {return pcf_new<ConcreteProductB>();}
    };
    
    // MainApp startup class for Creational
    // Factory Method Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // An array of creators
        Array<refptr<Creator>> creators(2);
        
        creators[0] = pcf_new<ConcreteCreatorA>();
        creators[1] = pcf_new<ConcreteCreatorB>();
        
        // Iterate over creators and create products
        for (refptr<Creator> creator : creators) {
          refptr<Product> product = creator->FactoryMethod();
          Console::WriteLine("Created {0}", product->GetType().Name);
        }
      }
    };
  }
}

// Specify the Main entry point to System
pcf_startup (DesignPatterns::Creational::MainApp)

// This code produces the following output:
//
// Created ConcreteProductA
// Created ConcreteProductB
