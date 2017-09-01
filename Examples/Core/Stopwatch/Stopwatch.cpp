#include <Switch/Switch>

using namespace System;
using namespace System::Diagnostics;
using namespace System::Threading;

namespace Examples {
  class Program : public object {
  public:
    // The main entry point for the application.
    static void Main() {
      Stopwatch stopwatch;
      stopwatch.Start();
      Thread::Sleep(10000);
      stopwatch.Stop();
      // Get the elapsed time as a TimeSpan value.
      TimeSpan ts = stopwatch.Elapsed;
      
      // Format and display the TimeSpan value.
      string elapsedTime = String::Format("{0:D2}:{1:D2}:{2:D2}.{3:D2}", ts.Hours, ts.Minutes, ts.Seconds, ts.Milliseconds / 10);
      Console::WriteLine("RunTime " + elapsedTime);
    }
  };
}

_startup (Examples::Program)

// This code produces the following output:
//
// TRunTime 00:00:10.00
