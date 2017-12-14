#include <Switch/System/Threading/Timer.hpp>
#include <Switch/System/Threading/AutoResetEvent.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Threading;

namespace {
  class TimerCtrlTest : public object {
  public:
    TimerCtrlTest() : Number(0), Event(false), State(null) {}

    void Run(object& State) {
      this->State = &State;
      if (++this->Number == 10)
        this->Event.Set();
    }

    int32 Number;
    AutoResetEvent Event;
    object* State;
  };

  TEST(TimerTest, CreateTimerWithoutDueTimeAndWithoutPeriod) {
    TimerCtrlTest test;
    _using(Timer timer(TimerCallback(test, &TimerCtrlTest::Run))) {
      ASSERT_FALSE(test.Event.WaitOne(10));
      ASSERT_EQ(0, test.Number);
      ASSERT_TRUE(test.State == null);
    }
    ASSERT_FALSE(test.Event.WaitOne(10));
    ASSERT_EQ(0, test.Number);
  }

  /*
  TEST(TimerTest, CreateTimerWithoutDueTimeAndWithoutPeriodAndCallChange) {
    TimerTest test;
    _using(Timer timer(TimerCallback(test, &TimerTest::Run))) {
      ASSERT_NO_THROW(timer.Change(10, -1));
      ASSERT_TRUE(test.Event.WaitOne(100));
      ASSERT_EQ(1, test.Number);
      ASSERT_EQ(&timer, test.State);
    }
  }
   */
}
