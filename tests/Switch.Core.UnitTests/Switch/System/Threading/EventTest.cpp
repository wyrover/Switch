#include <Switch/System/Threading/EventWaitHandle.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Threading;

namespace SwitchUnitTests {
  TEST(EventTest,  CreateEventWithoutName) {
    bool createdNew = false;
    EventWaitHandle ev(false, EventResetMode::ManualReset, "", createdNew);
    ASSERT_TRUE(createdNew);
  }
  
  TEST(EventTest,  CreateEventWitName) {
    bool createdNew;
    EventWaitHandle ev(false, EventResetMode::ManualReset, "Event", createdNew);
    ASSERT_TRUE(createdNew);
  }
  
  TEST(EventTest,  CreateEventWithDifferentName) {
    bool createdNew;
    EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event 1", createdNew);
    ASSERT_TRUE(createdNew);
    EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event 2", createdNew);
    ASSERT_TRUE(createdNew);
  }
  
  TEST(EventTest,  CreateEventWithSameName) {
    bool createdNew;
    EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event", createdNew);
    ASSERT_TRUE(createdNew);
    EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event", createdNew);
    ASSERT_FALSE(createdNew);
  }
  
  TEST(EventTest,  CreateEventWithFalseInitialState) {
    EventWaitHandle ev(false, EventResetMode::ManualReset);
    ASSERT_FALSE(ev.WaitOne(1));
  }
  
  TEST(EventTest,  CreateEventWithTrueInitialState) {
    EventWaitHandle ev(true, EventResetMode::ManualReset);
    ASSERT_TRUE(ev.WaitOne(1));
  }
  
  TEST(EventTest,  CloseEventWithoutName) {
    bool createdNew;
    EventWaitHandle ev(false, EventResetMode::ManualReset, "", createdNew);
    ASSERT_NO_THROW(ev.Close());
  }
  
  TEST(EventTest,  CloseEventWithName) {
    bool createdNew;
    EventWaitHandle ev(false, EventResetMode::ManualReset, "Event", createdNew);
    ASSERT_NO_THROW(ev.Close());
  }
  
  TEST(EventTest,  CloseEventWithDifferentName) {
    bool createdNew;
    EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event 1", createdNew);
    EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event 2", createdNew);
    ASSERT_NO_THROW(ev1.Close());
    ASSERT_NO_THROW(ev2.Close());
  }
  
  TEST(EventTest,  CloseEventWithSameName) {
    bool createdNew;
    EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event", createdNew);
    EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event", createdNew);
    ASSERT_NO_THROW(ev1.Close());
    ASSERT_NO_THROW(ev2.Close());
  }
  
  TEST(EventTest,  SetEvent) {
    EventWaitHandle ev(false, EventResetMode::ManualReset);
    ASSERT_TRUE(ev.Set());
  }
  
  TEST(EventTest,  ResetEvent) {
    EventWaitHandle ev(false, EventResetMode::ManualReset);
    ASSERT_TRUE(ev.Reset());
  }
  
  TEST(EventTest,  WaitManualResetEvent) {
    EventWaitHandle ev(false, EventResetMode::ManualReset);
    ASSERT_FALSE(ev.WaitOne(1));
  }
  
  TEST(EventTest,  WaitManualResetEventAfterSet) {
    EventWaitHandle ev(false, EventResetMode::ManualReset);
    ASSERT_FALSE(ev.WaitOne(1));
    ASSERT_TRUE(ev.Set());
    ASSERT_TRUE(ev.WaitOne(1));
    ASSERT_TRUE(ev.WaitOne(1));
  }
  
  TEST(EventTest,  WaitAutoResetEvent) {
    EventWaitHandle ev(false, EventResetMode::AutoReset);
    ASSERT_FALSE(ev.WaitOne(1));
  }
  
  TEST(EventTest,  WaitAutoResetEventAfterSet) {
    EventWaitHandle ev(false, EventResetMode::AutoReset);
    ASSERT_FALSE(ev.WaitOne(1));
    ASSERT_TRUE(ev.Set());
    ASSERT_TRUE(ev.WaitOne(1));
    ASSERT_FALSE(ev.WaitOne(1));
  }
  
  TEST(EventTest,  WaitManualResetEventAfterReseSet) {
    EventWaitHandle ev(true, EventResetMode::AutoReset);
    ASSERT_TRUE(ev.WaitOne(1));
    ASSERT_TRUE(ev.Reset());
    ASSERT_FALSE(ev.WaitOne(1));
  }
  
  TEST(EventTest,  WaitAutoResetEventAfterReseSet) {
    EventWaitHandle ev(true, EventResetMode::AutoReset);
    ASSERT_TRUE(ev.WaitOne(1));
    ASSERT_FALSE(ev.WaitOne(1));
    ASSERT_TRUE(ev.Reset());
    ASSERT_FALSE(ev.WaitOne(1));
  }
  
  TEST(EventTest,  OpenExistingWithoutCreatingEventBebore) {
    //ASSERT_TRUE(EventWaitHandle::OpenExisting("Event") == null);
  }
  
  TEST(EventTest,  OpenExistingWithCreatingAnotherEventBebore) {
    EventWaitHandle ev(false, EventResetMode::ManualReset, "Event");
    // ASSERT_TRUE(EventWaitHandle::OpenExisting("Event 1") == null);
  }
  
  TEST(EventTest,  OpenExistingWithCreatingEventBebore) {
    EventWaitHandle ev(false, EventResetMode::ManualReset, "Event");
    // ASSERT_FALSE(EventWaitHandle::OpenExisting("Event") == null);
  }
  
  TEST(EventTest,  DoubleAutoResesetEvent) {
    EventWaitHandle ev1(false, EventResetMode::AutoReset);
    EventWaitHandle ev2(false, EventResetMode::AutoReset);
    
    ASSERT_FALSE(ev1.WaitOne(1));
    ASSERT_FALSE(ev2.WaitOne(1));
    
    ASSERT_NO_THROW(ev1.Set());
    ASSERT_FALSE(ev2.WaitOne(1));
    ASSERT_TRUE(ev1.WaitOne(1));
    ASSERT_FALSE(ev1.WaitOne(1));
    
    ASSERT_NO_THROW(ev2.Set());
    ASSERT_FALSE(ev1.WaitOne(1));
    ASSERT_TRUE(ev2.WaitOne(1));
    ASSERT_FALSE(ev2.WaitOne(1));
  }
}

