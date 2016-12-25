// Singleton pattern -- Creational example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Creational {
    /// @brief The 'Singleton' class
    class Singleton : public object {
    public:
      static Singleton& Instance() {return instance;}

    protected:
      // Constructor is 'protected'
      Singleton() {}
      /// @cond
      Singleton(const Singleton&) = delete;
      Singleton& operator =(const Singleton&) = delete;
      /// @endcond
      
    private:
      static Singleton instance;
    };

    Singleton Singleton::instance;
  }
}

/// @brief Entry point into console application.
int main(int argc, char* argv[]) {
  using namespace DesignPatterns::Creational;
  
  // Constructor is protected -- cannot use constructor
  Singleton& singleton1 = Singleton::Instance();
  Singleton& singleton2 = Singleton::Instance();
  
  // Test for same instance
  if (&singleton1 == &singleton2) {
    Console::WriteLine("Objects are the same instance");
  }
}

// This code produces the following output:
//
// Objects are the same instance
