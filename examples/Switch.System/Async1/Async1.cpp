#include <Switch/Switch>

using namespace System;
using namespace System::Threading::Tasks;

namespace Examples {
  class TestAsync : public object {
  public:
    async<Task<>> CounterTask {
      delegate_ {
        for (int counter = 1; counter <= 5; counter++)
          Console::WriteLine("counter --> {0}", counter);
      }
    };

    async<Task<string>> ComputeStringTask {
      delegate_ {
        return "My result";
      }
    };

    // The main entry point for the application.
    static void Main() {
      TestAsync testAsync;

      await() << testAsync.CounterTask;

      string value = await() << testAsync.ComputeStringTask;
      Console::WriteLine(value);
    }
  };
}

startup_(Examples::TestAsync);

// This code produces output similar to the following:
//
// counter --> 1
// counter --> 2
// counter --> 3
// counter --> 4
// counter --> 5
// My result
