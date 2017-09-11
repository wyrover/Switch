#include <Switch/Switch>

using namespace System;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    static void Main() {
      int counter = 0;
      TimerCallback callback = _delegate(object& state) {
        Console::WriteLine("counter -> {0}", ++counter);
      };
      
      Timer timer(callback, 0, 10);
      Thread::Sleep(100);
    }
  };
}

startup (Examples::Program)

// The example displays the following output:
//
// counter -> 1
// counter -> 2
// counter -> 3
// counter -> 4
// counter -> 5
// counter -> 6
// counter -> 7
// counter -> 8
// counter -> 9
// counter -> 10
