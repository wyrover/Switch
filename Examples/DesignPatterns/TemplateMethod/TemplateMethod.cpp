// Template Method pattern -- Bahavorial example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Behavioral {
    // The 'AbstractClass' abstract class
    class AbstractClass pcf_abstract {
    public:
      virtual void PrimitiveOperation1() = 0;
      virtual void PrimitiveOperation2() = 0;
      
      // The "Template method"
      void TemplateMethod() {
        PrimitiveOperation1();
        PrimitiveOperation2();
        Console::WriteLine("");
      }
    };
    
    // A 'ConcreteClass' class
    class ConcreteClassA : public AbstractClass {
    public:
      void PrimitiveOperation1() override {
        Console::WriteLine("ConcreteClassA.PrimitiveOperation1()");
      }
      
      void PrimitiveOperation2() override {
        Console::WriteLine("ConcreteClassA.PrimitiveOperation2()");
      }
    };
    
    // A 'ConcreteClass' class
    class ConcreteClassB : public AbstractClass {
    public:
      void PrimitiveOperation1() override {
        Console::WriteLine("ConcreteClassB.PrimitiveOperation1()");
      }
      
      void PrimitiveOperation2() override {
        Console::WriteLine("ConcreteClassB.PrimitiveOperation2()");
      }
    };
    
    // MainApp startup class for Behavorial
    // Template Method Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        refptr<AbstractClass> aA = pcf_new<ConcreteClassA>();
        aA->TemplateMethod();
        
        refptr<AbstractClass> aB = pcf_new<ConcreteClassB>();
        aB->TemplateMethod();
      }
    };
  }
}

// Specify the Main entry point to System
pcf_startup (DesignPatterns::Behavioral::MainApp)

// This code produces the following output:
//
// ConcreteClassA.PrimitiveOperation1()
// ConcreteClassA.PrimitiveOperation2()
//
// ConcreteClassB.PrimitiveOperation1()
// ConcreteClassB.PrimitiveOperation2()
