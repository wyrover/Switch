#include <Switch/Switch>

using namespace System;
using namespace System::Threading;
using namespace System::Threading::Tasks;

namespace Examples {
  class Program {
  public:
    // Demonstrates:
    //      ThreadLocal<T> constructor
    //      ThreadLocal<T>.Value
    //      One usage of ThreadLocal<T>
    static void Main() {
      // Thread-Local variable that yields a name for a thread
      ThreadLocal<string> threadName(_delegate {
        return "Thread"_s + Thread::CurrentThread().ManagedThreadId;
      });
      
      // Action that prints out ThreadName for the current thread
      Action<> action = _delegate {
        // If ThreadName.IsValueCreated is true, it means that we are not the
        // first action to run on this thread.
        bool repeat = threadName.IsValueCreated;
        
        Console::WriteLine("threadName = {0} {1}", threadName.Value, repeat ? "(repeat)" : "");
      };
      
      // Launch eight of them.  On 4 cores or less, you should see some repeat ThreadNames
      Parallel::Invoke(action, action, action, action, action, action, action, action);
    }
  };
}

_startup(Examples::Program)

// This code produces output similar to the following:
//
// ThreadName = Thread4
// ThreadName = Thread6
// ThreadName = Thread7
// ThreadName = Thread9
// ThreadName = Thread3
// ThreadName = Thread8
// ThreadName = Thread4 (repeat)
// ThreadName = Thread2

