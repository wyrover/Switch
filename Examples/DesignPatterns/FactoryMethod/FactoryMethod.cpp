// Factory Method pattern -- Creational example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Creational {
    /// @brief The 'Product' abstract class
    class Product pcf_abstract {
    };
    
    /// @brief A 'ConcreteProduct' class
    class ConcreteProductA : public Product {
    };
    
    /// @brief A 'ConcreteProduct' class
    class ConcreteProductB : public Product {
    };
    
    /// @brief The 'Creator' abstract class
    class Creator pcf_abstract {
    public:
      virtual refptr<Product> FactoryMethod() const = 0;
    };
    
    /// @brief A 'ConcreteCreator' class
    class ConcreteCreatorA : public Creator {
    public:
      refptr<Product> FactoryMethod() const override {return pcf_new<ConcreteProductA>();}
    };
    
    /// @brief A 'ConcreteCreator' class
    class ConcreteCreatorB : public Creator {
    public:
      refptr<Product> FactoryMethod() const override {return pcf_new<ConcreteProductB>();}
    };
    
    class MainApp {
    public:
      /// @brief Entry point into console application.
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

pcf_startup (DesignPatterns::Creational::MainApp)

// This code produces the following output:
//
// Created ConcreteProductA
// Created ConcreteProductB
