#include <Switch/Switch>

using namespace System;
using namespace System::Threading::Tasks;

namespace Examples {
  class TestAsync : public object {
  public:
    sw_async(Task<>, CounterTask, {
      for (int counter = 1; counter <= 5; counter++)
        Console::WriteLine("counter --> {0}", counter);
    });
    
    sw_async(Task<string>, ComputeStringTask, {
      return "My result";
    });
    
    // The main entry point for the application.
    static void Main() {
      TestAsync testAsync;
      
      sw_await testAsync.CounterTask;
      
      string value = sw_await testAsync.ComputeStringTask;
      Console::WriteLine(value);
    }
  };
}

sw_startup (Examples::TestAsync)

// This code produces output similar to the following:
//
// counter --> 1
// counter --> 2
// counter --> 3
// counter --> 4
// counter --> 5
// My result
