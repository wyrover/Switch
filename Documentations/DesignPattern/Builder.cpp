// Builder pattern -- Creational example

#include <Pcf/Pcf>

using namespace System;
using namespace System::Collections::Generic;

namespace DesignPatterns {
  namespace Creational {
    /// @brief The 'Product' class
    class Product : public object {
    public:
      void Add(string part) {
        this->parts.Add(part);
      }

      void Show() const {
        Console::WriteLine("\nProduct Parts -------");
        for (string part : this->parts)
          Console::WriteLine(part);
      }

    private:
      List<string> parts;
    };

    /// @brief The 'Builder' abstract class
    class Builder : public Abstract {
    public:
      virtual void BuildPartA() =0;
      virtual void BuildPartB() =0;
      virtual const Product& GetResult() const =0;
    };

    /// @brief The 'Director' class
    class Director : public object {
    public:
      // Builder uses a complex series of steps
      void Construct(Builder& builder) {
        builder.BuildPartA();
        builder.BuildPartB();
      }
    };

    /// @brief The 'ConcreteBuilder1' class
    class ConcreteBuilder1 : public Builder {
    public:
      void BuildPartA() override {this->product.Add("PartA");}
      void BuildPartB() override {this->product.Add("PartB");}
      const Product& GetResult() const override {return this->product;}

    private:
      Product product;
    };

    /// @brief The 'ConcreteBuilder2' class
    class ConcreteBuilder2 : public Builder {
    public:
      void BuildPartA() override {this->product.Add("PartX");}
      void BuildPartB() override {this->product.Add("PartY");}
      const Product& GetResult() const override {return this->product;}

    private:
      Product product;
    };
  }
}

/// @brief Entry point into console application.
int main(int argc, char* argv[]) {
  using namespace DesignPatterns::Creational;
  
  // Create director and builders
  Director director;
  
  Up<Builder> b1 = Up<Builder>::Create<ConcreteBuilder1>();
  Up<Builder> b2 = Up<Builder>::Create<ConcreteBuilder2>();
  
  // Construct two products
  director.Construct(*b1);
  Product p1 = b1->GetResult();
  p1.Show();
  
  director.Construct(*b2);
  Product p2 = b2->GetResult();
  p2.Show();
}

// This code produces the following output:
//
// Product Parts -------
// PartA
// PartB
//
// Product Parts -------
// PartX
// PartY
