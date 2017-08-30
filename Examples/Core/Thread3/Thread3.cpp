#include <Switch/Switch>

using namespace System;
using namespace System::Diagnostics;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    static Object obj;

    static void Main() {
      Thread::CurrentThread().Name = "Main";
      ThreadPool::QueueUserWorkItem(ShowThreadInformation);
      auto th1 = Thread(ParameterizedThreadStart(ShowThreadInformation));
      th1.Start();
      auto th2 = Thread(ParameterizedThreadStart(ShowThreadInformation));
      th2.IsBackground = true;
      th2.Start();
      Thread::Sleep(500);
      ShowThreadInformation(object());
    }

  private:
    static void ShowThreadInformation(const Object& state) {
      sw_lock (obj) {
        auto th  = Thread::CurrentThread();
        Console::WriteLine("Managed thread #{0}: ", th.ManagedThreadId);
        Console::WriteLine("   Background thread: {0}", th.IsBackground);
        Console::WriteLine("   Thread pool thread: {0}", th.IsThreadPoolThread);
        Console::WriteLine("   Priority: {0}", th.Priority);
        Console::WriteLine("   Name: {0}", th.Name);
        Console::WriteLine();
      }
    }
  };

  Object Program::obj;
}

sw_startup (Examples::Program)

// This code produces output similar to the following:
//
// Managed thread #5:
// Background thread: True
// Thread pool thread: True
// Priority: Normal
// Name: Thread Pool
//
// Managed thread #10:
// Background thread: False
// Thread pool thread: False
// Priority: Normal
// Name:
//
// Managed thread #11:
// Background thread: True
// Thread pool thread: False
// Priority: Normal
// Name:
//
// Managed thread #1:
// Background thread: False
// Thread pool thread: False
// Priority: Normal
// Name: Main
