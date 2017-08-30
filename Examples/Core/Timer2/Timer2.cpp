#include <Switch/Switch>

using namespace System;
using namespace System::Threading;

namespace Examples {
  class StatusChecker : public object {
  public:
    explicit StatusChecker(int32 count) : maxCount(count) {}
    
    // This method is called by the timer delegate.
    void CheckStatus(Object& stateInfo) {
      Console::WriteLine("{0} Checking status {1,2}.", DateTime::Now().ToString("%H:%M:%S"), Int32(++invokeCount).ToString());
      
      if (invokeCount == maxCount) {
        // Reset the counter and signal Main.
        invokeCount  = 0;
        as<AutoResetEvent>(stateInfo).Set();
      }
    }
    
  private:
    int invokeCount = 0;
    int maxCount;
  };
  
  class TimerExample {
  public:
    static void Main() {
      // Create an event to signal the timeout count threshold in the
      // timer callback.
      AutoResetEvent autoEvent(false);
      
      StatusChecker statusChecker(10);
      
      // Create an inferred delegate that invokes methods for the timer.
      TimerCallback tcb = TimerCallback(statusChecker, &StatusChecker::CheckStatus);
      
      // Create a timer that signals the delegate to invoke
      // CheckStatus after one second, and every 1/4 second
      // thereafter.
      Console::WriteLine("{0} Creating timer.\n", DateTime::Now().ToString("%H:%M:%S"));
      Timer stateTimer(tcb, autoEvent, 1000, 250);
      
      // When autoEvent signals, change the period to every
      // 1/2 second.
      autoEvent.WaitOne(5000);
      stateTimer.Change(0, 500);
      Console::WriteLine("\nChanging period.\n");
      
      // When autoEvent signals the second time, dispose of
      // the timer.
      autoEvent.WaitOne(5000);
      
      Console::WriteLine("\nDestroying timer.");
    }
  };
}

sw_startup (Examples::TimerExample)

// This code produces the following output:
//
// 21:29:53 Creating timer.
//
// 21:29:54 Checking status  1.
// 21:29:54 Checking status  2.
// 21:29:55 Checking status  3.
// 21:29:55 Checking status  4.
// 21:29:55 Checking status  5.
// 21:29:55 Checking status  6.
// 21:29:56 Checking status  7.
// 21:29:56 Checking status  8.
// 21:29:56 Checking status  9.
// 21:29:56 Checking status 10.
//
// Changing period.
//
// 21:29:57 Checking status  1.
// 21:29:57 Checking status  2.
// 21:29:58 Checking status  3.
// 21:29:58 Checking status  4.
// 21:29:59 Checking status  5.
// 21:29:59 Checking status  6.
// 21:30:00 Checking status  7.
// 21:30:00 Checking status  8.
// 21:30:01 Checking status  9.
//
// Destroying timer.
