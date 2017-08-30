// Flyweight pattern -- Structural example

#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;

namespace DesignPatterns {
  namespace Structural {
    // The 'Flyweight' abstract class
    class Flyweight sw_abstract {
    public:
      virtual void Operation(int extrinsicstate) const =0;
    };
    
    // The 'ConcreteFlyweight' class
    class ConcreteFlyweight : public Flyweight {
    public:
      void Operation(int extrinsicstate) const override {
        Console::WriteLine("ConcreteFlyweight: {0}", extrinsicstate);
      }
    };
    
    // The 'FlyweightFactory' class
    class FlyweightFactory : public object {
    public:
      // Constructor
      FlyweightFactory() {
        flyweights.Add("X", sw_new<ConcreteFlyweight>());
        flyweights.Add("Y", sw_new<ConcreteFlyweight>());
        flyweights.Add("Z", sw_new<ConcreteFlyweight>());
      }
      
      refptr<Flyweight> GetFlyweight(const string& key) const {return flyweights[key];}

    private:
      Dictionary<string, refptr<Flyweight>> flyweights;
    };
    
    /// @brief The 'UnsharedConcreteFlyweight' class
    class UnsharedConcreteFlyweight : public Flyweight {
    public:
      void Operation(int extrinsicstate) const override  {Console::WriteLine("UnsharedConcreteFlyweight: {0}", extrinsicstate);}
    };
    
    // MainApp startup class for Structural
    // Flyweight Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Arbitrary extrinsic state
        int extrinsicstate = 22;
        
        FlyweightFactory factory;
        
        // Work with different flyweight instances
        refptr<Flyweight> fx = factory.GetFlyweight("X");
        fx->Operation(--extrinsicstate);
        
        refptr<Flyweight> fy = factory.GetFlyweight("Y");
        fy->Operation(--extrinsicstate);
        
        refptr<Flyweight> fz = factory.GetFlyweight("Z");
        fz->Operation(--extrinsicstate);
        
        refptr<UnsharedConcreteFlyweight> fu = sw_new<UnsharedConcreteFlyweight>();
        fu->Operation(--extrinsicstate);
      }
    };
  }
}

// Specify the Main entry point to System
sw_startup (DesignPatterns::Structural::MainApp)

// This code produces the following output:
//
// ConcreteFlyweight: 21
// ConcreteFlyweight: 20
// ConcreteFlyweight: 19
// UnsharedConcreteFlyweight: 18
