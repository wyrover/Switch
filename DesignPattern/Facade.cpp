// Facade pattern -- Real World example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Structural {
    /// @brief The 'Subsystem ClassA' class
    class SubSystemOne : public object {
    public:
      void MethodOne() const {Console::WriteLine(" SubSystemOne Method");}
    };
    
    /// @brief The 'Subsystem ClassB' class
    class SubSystemTwo : public object {
    public:
      void MethodTwo() const {Console::WriteLine(" SubSystemTwo Method");}
    };
    
    /// @brief The 'Subsystem ClassC' class
    class SubSystemThree : public object {
    public:
      void MethodThree() const {Console::WriteLine(" SubSystemThree Method");}
    };
    
    /// @brief The 'Subsystem ClassD' class
    class SubSystemFour : public object {
    public:
      void MethodFour() const {Console::WriteLine(" SubSystemFour Method");}
    };
    
    /// @brief The 'Facade' class
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
  }
}

/// @brief Entry point into console application.
int main(int argc, char* argv[]) {
  using namespace DesignPatterns::Structural;
  
  Facade facade;
  
  facade.MethodA();
  facade.MethodB();
}

// This code produces the following output:
//
// MethodA() ----
// SubSystemOne Method
// SubSystemTwo Method
// SubSystemFour Method
//
// MethodB() ----
// SubSystemTwo Method
// SubSystemThree Method
