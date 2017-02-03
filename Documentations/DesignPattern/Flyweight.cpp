// Flyweight pattern -- Structural example

#include <Pcf/Pcf>

using namespace System;
using namespace System::Collections::Generic;

namespace DesignPatterns {
  namespace Structural {
    /// @brief The 'Flyweight' abstract class
    class Flyweight : public Abstract {
    public:
      virtual void Operation(int extrinsicstate) const =0;
    };
    
    /// @brief The 'ConcreteFlyweight' class
    class ConcreteFlyweight : public Flyweight {
    public:
      void Operation(int extrinsicstate) const override {
        Console::WriteLine("ConcreteFlyweight: {0}", extrinsicstate);
      }
    };
    
    /// @brief The 'FlyweightFactory' class
    class FlyweightFactory : public object {
    public:
      // Constructor
      FlyweightFactory() {
        flyweights.Add("X", new ConcreteFlyweight());
        flyweights.Add("Y", new ConcreteFlyweight());
        flyweights.Add("Z", new ConcreteFlyweight());
      }
      
    public:
      Sp<Flyweight> GetFlyweight(const string& key) const {return flyweights[key];}

    private:
      Dictionary<string, Sp<Flyweight>> flyweights;
    };
    
    /// @brief The 'UnsharedConcreteFlyweight' class
    class UnsharedConcreteFlyweight : public Flyweight {
    public:
      void Operation(int extrinsicstate) const override  {Console::WriteLine("UnsharedConcreteFlyweight: {0}", extrinsicstate);}
    };
  }
}

/// @brief Entry point into console application.
int main(int argc, char* argv[])  {
  using namespace DesignPatterns::Structural;
  
  // Arbitrary extrinsic state
  int extrinsicstate = 22;
  
  FlyweightFactory factory;
  
  // Work with different flyweight instances
  Sp<Flyweight> fx = factory.GetFlyweight("X");
  fx->Operation(--extrinsicstate);
  
  Sp<Flyweight> fy = factory.GetFlyweight("Y");
  fy->Operation(--extrinsicstate);
  
  Sp<Flyweight> fz = factory.GetFlyweight("Z");
  fz->Operation(--extrinsicstate);
  
  Up<UnsharedConcreteFlyweight> fu = new UnsharedConcreteFlyweight();
  fu->Operation(--extrinsicstate);
}

// This code produces the following output:
//
// ConcreteFlyweight: 21
// ConcreteFlyweight: 20
// ConcreteFlyweight: 19
// UnsharedConcreteFlyweight: 18
