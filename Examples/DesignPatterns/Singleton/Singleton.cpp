// Singleton pattern -- Creational example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Creational {
    // The 'Singleton' class
    class Singleton : public object {
    public:
      static Singleton& Instance() {return instance;}

    protected:
      // Constructor is 'protected'
      Singleton() {}
      Singleton(const Singleton&) = delete;
      Singleton& operator =(const Singleton&) = delete;
      
    private:
      static Singleton instance;
    };

    Singleton Singleton::instance;
    
    // MainApp startup class for Creational
    // Singleton Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Constructor is protected -- cannot use constructor
        ref<Singleton> singleton1 = Singleton::Instance();
        ref<Singleton> singleton2 = Singleton::Instance();

        // Test for same instance
        if (&singleton1 == &singleton2)
          Console::WriteLine("Objects are the same instance");
      }
    };
  }
}

pcf_startup (DesignPatterns::Creational::MainApp)

// This code produces the following output:
//
// Objects are the same instance
