#define TRACE
#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#
using namespace System;
using namespace System::Threading;

namespace Examples {
  using Tester = delegate<void>;
  
  class Register _static {
  public:
    static void Add(Tester tester) {
      testers.Add(tester);
    }
    
  private:
    static System::Collections::Generic::List<Tester> testers;
  };
  
  System::Collections::Generic::List<Tester> Register::testers;
  
  
  class MyClass : public object {
    
  };
  

  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("Switch version = {0}", Environment::Version);
    }
  };
}

_startup (Examples::Program)
