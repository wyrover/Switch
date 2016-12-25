#include <Pcf/Pcf>

using namespace System;
using namespace System::Diagnostics;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    static void Main() {
      auto th = Thread(ThreadStart(ExecuteInForeground));
      th.Start();
      Thread::Sleep(1000);
      Console::WriteLine("Main thread ({0}) exiting...", Thread::CurrentThread().ManagedThreadId);
    }

  private:
    static void ExecuteInForeground() {
      DateTime start = DateTime::Now;
      auto sw = Stopwatch::StartNew();
      Console::WriteLine("Thread {0}: {1}, Priority {2}", Thread::CurrentThread().ManagedThreadId, Thread::CurrentThread().ThreadState, Thread::CurrentThread().Priority);
      do {
        Console::WriteLine("Thread {0}: Elapsed {1:N2} seconds", Thread::CurrentThread().ManagedThreadId, sw.ElapsedMilliseconds / 1000.0);
        Thread::Sleep(500);
      } while (sw.ElapsedMilliseconds <= 5000);
      sw.Stop();
    }
  };
}

pcf_startup (Examples::Program)

// This code produces output similar to the following:
//
// Thread 2: Running, Priority Normal
// Thread 2: Elapsed 0.00 seconds
// Thread 2: Elapsed 0.50 seconds
// Main thread (1) exiting...
// Thread 2: Elapsed 1.00 seconds
// Thread 2: Elapsed 1.51 seconds
// Thread 2: Elapsed 2.01 seconds
// Thread 2: Elapsed 2.51 seconds
// Thread 2: Elapsed 3.01 seconds
// Thread 2: Elapsed 3.51 seconds
// Thread 2: Elapsed 4.01 seconds
// Thread 2: Elapsed 4.52 seconds

