// Factory Method pattern -- Creational example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Creational {
    /// @brief The 'Product' abstract class
    class Product : public Abstract {
    };
    
    /// @brief A 'ConcreteProduct' class
    class ConcreteProductA : public Product {
    };
    
    /// @brief A 'ConcreteProduct' class
    class ConcreteProductB : public Product {
    };
    
    /// @brief The 'Creator' abstract class
    class Creator : public Abstract {
    public:
      virtual Up<Product> FactoryMethod() const =0;
    };
    
    /// @brief A 'ConcreteCreator' class
    class ConcreteCreatorA : public Creator {
    public:
      Up<Product> FactoryMethod() const override {return Up<Product>::Create<ConcreteProductA>();}
    };
    
    /// @brief A 'ConcreteCreator' class
    class ConcreteCreatorB : public Creator {
    public:
      Up<Product> FactoryMethod() const override {return Up<Product>::Create<ConcreteProductB>();}
    };
  }
}

/// @brief Entry point into console application.
int main(int argc, char* argv[]) {
  using namespace DesignPatterns::Creational;
  
  // An array of creators
  Array<Up<Creator>> creators(2);
  
  creators[0] = Up<Creator>::Create<ConcreteCreatorA>();
  creators[1] = Up<Creator>::Create<ConcreteCreatorB>();
  
  // Iterate over creators and create products
  for (Up<Creator> creator : creators) {
    Up<Product> product = creator->FactoryMethod();
    Console::WriteLine("Created {0}", product->GetType().Name);
  }
}

// This code produces the following output:
//
// Created ConcreteProductA
// Created ConcreteProductB
