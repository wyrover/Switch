#include <Pcf/System/Threading/Timer.h>
#include <Pcf/System/Threading/ManualResetEvent.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Threading;
using namespace TUnit;

namespace {
  class TimerIT : public testing::Test {
  protected:
    void SetUp() override {
    }
    
    void TearDown() override {
    }
  };
  
  class TimerTest : public object {
  public:
    TimerTest() : number(0), event(false) {}

    void Run(object& state) {
      if (++number == 10)
        event.Set();
    }
    
    int32 number;
    AutoResetEvent event;
  };
  
  TEST_F(TimerIT, AutoResetEventFalseSetDoubleWaitResetWait) {
    AutoResetEvent event(false);
    ASSERT_EQ(false, event.WaitOne(0));
    event.Set();
    ASSERT_EQ(true, event.WaitOne(0));
    ASSERT_EQ(false, event.WaitOne(0));
    event.Reset();
    ASSERT_EQ(false, event.WaitOne(0));
  }
  
  TEST_F(TimerIT, ManualResetEventFalseSetDoubleWaitResetWait) {
    ManualResetEvent event(false);
    ASSERT_EQ(false, event.WaitOne(0));
    event.Set();
    ASSERT_EQ(true, event.WaitOne(0));
    ASSERT_EQ(true, event.WaitOne(0));
    event.Reset();
    ASSERT_EQ(false, event.WaitOne(0));
  }
  
  TEST_F(TimerIT, CreateTimer) {
    TimerTest test;
    Up<Timer> timer = new Timer(TimerCallback(test, &TimerTest::Run), test, 20, 10);
    ASSERT_FALSE(test.event.WaitOne(100));
    ASSERT_TRUE(test.event.WaitOne(200));
    ASSERT_EQ(10, test.number);
    timer.Reset();
    ASSERT_FALSE(test.event.WaitOne(20));
    ASSERT_EQ(10, test.number);
  }
}