// Facade pattern -- Structural example

#include <Switch/Switch>

using namespace System;

namespace DesignPatterns {
  namespace Structural {
    // The 'Subsystem ClassA' class
    class SubSystemOne : public object {
    public:
      void MethodOne() const {Console::WriteLine(" SubSystemOne Method");}
    };
    
    // The 'Subsystem ClassB' class
    class SubSystemTwo : public object {
    public:
      void MethodTwo() const {Console::WriteLine(" SubSystemTwo Method");}
    };
    
    // The 'Subsystem ClassC' class
    class SubSystemThree : public object {
    public:
      void MethodThree() const {Console::WriteLine(" SubSystemThree Method");}
    };
    
    // The 'Subsystem ClassD' class
    class SubSystemFour : public object {
    public:
      void MethodFour() const {Console::WriteLine(" SubSystemFour Method");}
    };
    
    // The 'Facade' class
    class Facade : public object {
    public:
      Facade() {}
      
      void MethodA() const {
        Console::WriteLine("\nMethodA() ---- ");
        this->one.MethodOne();
        this->two.MethodTwo();
        this->four.MethodFour();
      }
      
      void MethodB() const {
        Console::WriteLine("\nMethodB() ---- ");
        this->two.MethodTwo();
        this->three.MethodThree();
      }

    private:
      SubSystemOne one;
      SubSystemTwo two;
      SubSystemThree three;
      SubSystemFour four;
    };
    
    // MainApp startup class for Structural
    // Facade Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        Facade facade;
        
        facade.MethodA();
        facade.MethodB();
      }
    };
  }
}

// Specify the Main entry point to System
_startup (DesignPatterns::Structural::MainApp)

// This code produces the following output:
//
// MethodA() ----
//  SubSystemOne Method
//  SubSystemTwo Method
//  SubSystemFour Method
//
// MethodB() ----
//  SubSystemTwo Method
//  SubSystemThree Method
