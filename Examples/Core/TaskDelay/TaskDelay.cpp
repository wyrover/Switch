#include <Switch/Switch>

using namespace System;
using namespace System::Threading::Tasks;

namespace Examples {
  class Program {
  public:
    static void Main() {
      auto t = Task<>::Run<int>(_delegate {
        _await Task<>::Delay(TimeSpan::FromSeconds(1.5));
        return 42;
      });
      t.Wait();
      Console::WriteLine("Task t Status: {0}, Result: {1}", t.Status, t.Result);
    }
  };
}

startup (Examples::Program)

// The example displays the following output:
//
// Task t Status: RanToCompletion, Result: 42
