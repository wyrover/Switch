#include <Pcf/Pcf>

using namespace System;
using namespace System::Diagnostics;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    static void Main() {
      auto th = Thread(ParameterizedThreadStart(ExecuteInForeground));
      th.Start(Int32(4500));
      Thread::Sleep(1000);
      Console::WriteLine("Main thread ({0}) exiting...", Thread::CurrentThread().ManagedThreadId);
    }

  private:
    static void ExecuteInForeground(const object& obj) {
      int interval;
      try {
        interval = as<Int32>(obj);
      } catch (InvalidCastException) {
        interval = 5000;
      }
      DateTime start = DateTime::Now;
      auto sw = Stopwatch::StartNew();
      Console::WriteLine("Thread {0}: {1}, Priority {2}", Thread::CurrentThread().ManagedThreadId, Thread::CurrentThread().ThreadState, Thread::CurrentThread().Priority);
      do {
        Console::WriteLine("Thread {0}: Elapsed {1:N2} seconds", Thread::CurrentThread().ManagedThreadId, sw.ElapsedMilliseconds / 1000.0);
        Thread::Sleep(500);
      } while (sw.ElapsedMilliseconds <= interval);
      sw.Stop();
    }
  };
}

pcf_startup (Examples::Program)

// This code produces output similar to the following:
//
// Thread 2: Running, Priority Normal
// Thread 2: Elapsed 0.00 seconds
// Thread 2: Elapsed 0.51 seconds
// Main thread (1) exiting...
// Thread 2: Elapsed 1.01 seconds
// Thread 2: Elapsed 1.51 seconds
// Thread 2: Elapsed 2.02 seconds
// Thread 2: Elapsed 2.52 seconds
// Thread 2: Elapsed 3.02 seconds
// Thread 2: Elapsed 3.53 seconds
// Thread 2: Elapsed 4.03 seconds

