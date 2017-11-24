// Strategy pattern -- Behavioral example

#include <Switch/Switch>

using namespace System;

namespace DesignPatterns {
  namespace Behavioral {
    // The 'Strategy' abstract class
    class Strategy _abstract {
    public:
      virtual void AlgorithmInterface() = 0;
    };
    
    // A 'ConcreteStrategy' class
    class ConcreteStrategyA : public Strategy {
    public:
      void AlgorithmInterface() override {
        Console::WriteLine("Called ConcreteStrategyA.AlgorithmInterface()");
      }
    };
    
    // A 'ConcreteStrategy' class
    class ConcreteStrategyB : public Strategy {
    public:
      void AlgorithmInterface() override {
        Console::WriteLine("Called ConcreteStrategyB.AlgorithmInterface()");
      }
    };
    
    // A 'ConcreteStrategy' class
    class ConcreteStrategyC : public Strategy {
    public:
      void AlgorithmInterface() override {
        Console::WriteLine("Called ConcreteStrategyC.AlgorithmInterface()");
      }
    };
    
    // The 'Context' class
    class Context : public object {
    public:
      // Constructors
      Context() {}
      explicit Context(refptr<Strategy> strategy) : strategy(strategy) {}
      Context(const Context& context) : strategy(context.strategy) {}
      Context& operator=(const Context& context) {
        this->strategy = context.strategy;
        return *this;
      }
      
      void ContextInterface() {
        this->strategy->AlgorithmInterface();
      }
      
    private:
      refptr<Strategy> strategy;
    };
    
    // MainApp _startup class for Behavioral
    // Strategy Design Pattern.
    class MainApp {
    public:
      /// Entry point into console application.
      static void Main() {
        Context context;
        
        // Three contexts following different strategies
        context = Context(ref_new<ConcreteStrategyA>());
        context.ContextInterface();
        
        context = Context(ref_new<ConcreteStrategyB>());
        context.ContextInterface();
        
        context = Context(ref_new<ConcreteStrategyC>());
        context.ContextInterface();
      }
    };
  }
}

// Specify the Main entry point to System
_startup(DesignPatterns::Behavioral::MainApp);

// This code produces the following output:
//
// Called ConcreteStrategyA.AlgorithmInterface()
// Called ConcreteStrategyB.AlgorithmInterface()
// Called ConcreteStrategyC.AlgorithmInterface()
