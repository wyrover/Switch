#include <Switch/Switch>

using namespace System;
using namespace System::Threading;

namespace Examples {
  // Simple threading scenario: Start a static method running
  // on a second thread.
  class ThreadExample : public object {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("Main thread: Start a second thread.");
      // The constructor for the Thread class requires a ThreadStart
      // delegate that represents the method to be executed on the
      // thread.  Switch simplifies the creation of this delegate.
      Thread t = Thread(ThreadStart(ThreadProc));
      
      // Start ThreadProc.  Note that on a uniprocessor, the new
      // thread does not get any processor time until the main thread
      // is preempted or yields.  Uncomment the Thread.Sleep that
      // follows t->Start() to see the difference.
      t.Start();
      //Thread::Sleep(0);
      
      for (int i = 0; i < 4; i++) {
        Console::WriteLine("Main thread: Do some work.");
        Thread::Sleep(0);
      }
      
      Console::WriteLine("Main thread: Call Join(), to wait until ThreadProc ends.");
      t.Join();
      Console::WriteLine("Main thread: ThreadProc.Join has returned.");
    }

    // The ThreadProc method is called when the thread starts.
    // It loops ten times, writing to the console and yielding
    // the rest of its time slice each time, and then ends.
    static void ThreadProc() {
      for (int i = 0; i < 10; i++) {
        Console::WriteLine("ThreadProc: {0}", i);
        // Yield the rest of the time slice.
        Thread::Sleep(0);
      }
    }
  };
}

startup (Examples::ThreadExample)

// This code produces the following output:
//
// Main thread: Start a second thread.
// Main thread: Do some work.
// Main thread: Do some work.
// Main thread: Do some work.
// Main thread: Do some work.
// ThreadProc: 0
// Main thread: Call Join(), to wait until ThreadProc ends.
// ThreadProc: 1
// ThreadProc: 2
// ThreadProc: 3
// ThreadProc: 4
// ThreadProc: 5
// ThreadProc: 6
// ThreadProc: 7
// ThreadProc: 8
// ThreadProc: 9
// Main thread: ThreadProc.Join has returned.
