#include <Switch/System/Threading/Timer.hpp>
#include <Switch/System/Threading/AutoResetEvent.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Threading;
using namespace TUnit;

namespace {
  class TimerUT : public testing::Test {
  public:
    void SetUp() override {
    }
    
    void TearDown() override {
    }
  };

  class TimerTest : public object {
  public:
    TimerTest() : Number(0), Event(false), State(null) {}
    
    void Run(object& State) {
      this->State = &State;
      if (++this->Number == 10)
        this->Event.Set();
    }
    
    int32 Number;
    AutoResetEvent Event;
    object* State;
  };

  TEST_F(TimerUT, CreateTimerWithoutDueTimeAndWithoutPeriod) {
    TimerTest test;
    pcf_using(Timer timer(TimerCallback(test, &TimerTest::Run))) {
      ASSERT_FALSE(test.Event.WaitOne(10));
      ASSERT_EQ(0, test.Number);
      ASSERT_TRUE(test.State == null);
    }
    ASSERT_FALSE(test.Event.WaitOne(10));
    ASSERT_EQ(0, test.Number);
  }
  
  /*
  TEST_F(TimerUT, CreateTimerWithoutDueTimeAndWithoutPeriodAndCallChange) {
    TimerTest test;
    pcf_using(Timer timer(TimerCallback(test, &TimerTest::Run))) {
      ASSERT_NO_THROW(timer.Change(10, -1));
      ASSERT_TRUE(test.Event.WaitOne(100));
      ASSERT_EQ(1, test.Number);
      ASSERT_EQ(&timer, test.State);
    }
  }
   */
}
