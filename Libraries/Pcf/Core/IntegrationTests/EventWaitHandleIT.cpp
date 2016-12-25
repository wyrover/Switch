#include <Pcf/System/Threading/EventWaitHandle.h>
#include <Pcf/System/Threading/AutoResetEvent.h>
#include <Pcf/System/Threading/Thread.h>
#include <Pcf/System/Collections/Generic/Queue.h>
#include <Pcf/System/Console.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Threading;
using namespace TUnit;

namespace TestCtor_Unnamed {
  TEST(EventWaitHandle, Ctor_Unnamed) {
    EventWaitHandle event1(false, EventResetMode::AutoReset);
    EventWaitHandle event2(false, EventResetMode::AutoReset);
    ASSERT_NE(event1, event2);
  }
}

namespace TestConcurrentThread {
  static Up<EventWaitHandle> sync;
  static bool quit = false;
  static int32 nbEventRaised = 0;
  static int32 nbEventLowered = 0;
  
  void EventRaiser() {
    while (!quit) {
      sync->Set();
      nbEventRaised++;
      Thread::Sleep(1);
    }
  }
  
  void EventLower() {
    while (!quit || nbEventLowered < nbEventRaised) {
      if (sync->WaitOne(10)) {
        nbEventLowered++;
      }
    }
  }
  
  TEST(EventWaitHandle, ConcurrentThread) {
    Up<Thread> eventRaiser = new Thread((ThreadStart)&EventRaiser);
    Up<Thread> eventLower = new Thread((ThreadStart)&EventLower);

    sync = new EventWaitHandle(false, EventResetMode::AutoReset);

    eventLower->Start();
    eventRaiser->Start();
    
    Thread::Sleep(3000);
    quit = true;
    Thread::Sleep(100);
    
    ASSERT_TRUE(eventRaiser->Join(1000));
    ASSERT_TRUE(eventLower->Join(1000));
    
    ASSERT_EQ(nbEventLowered, nbEventRaised);
  }
}

namespace TestConcurrentQueue {
  static int32 nbCount = 3000;
  static Up<EventWaitHandle> sync;
  static int32 nbEventRaised = 0;
  static int32 nbEventLowered = 0;
  static Queue<int32> items;
  
  void EventRaiser() {
    while (nbEventRaised < nbCount) {
      LockGuard lock(items.SyncRoot);
      items.Enqueue(++nbEventRaised);
      sync->Set();
    }
  }
  
  void EventLower() {
    while (nbEventLowered < nbCount) {
      if (sync->WaitOne()) {
        LockGuard lock(items.SyncRoot);
        while (items.Count != 0) {
          EXPECT_EQ(nbEventLowered+1, items.Dequeue());
          ++nbEventLowered;
        }
      }
    }
  }
  
  TEST(EventWaitHandle, ConcurrentQueue) {
    Up<Thread> eventRaiser = new Thread((ThreadStart)&EventRaiser);
    Up<Thread> eventLower = new Thread((ThreadStart)&EventLower);

    sync = new EventWaitHandle(false, EventResetMode::AutoReset);

    eventLower->Start();
    eventRaiser->Start();
    
    eventRaiser->Join();
    eventLower->Join();
    
    ASSERT_EQ(0, items.Count);
    ASSERT_EQ(nbCount, nbEventRaised);
    ASSERT_EQ(nbCount, nbEventLowered);
  }
}

namespace {
  static AutoResetEvent event(false);
  static bool quit = false;
  int32 nbEventRaised = 0;
  int32 nbEventLowered = 0;
  int32 nbThreadLower = 10;
  
  void EventRaiser() {
    while (!quit) {
      Thread::Sleep(5);
      event.Set();
      nbEventRaised++;
    }
  }
  
  void EventLower() {
    while (!quit) {
      if (event.WaitOne() == true)
        nbEventLowered++;
    }
  }
  
  TEST(AutoResetEvent, ConcurrentThread) {
    Up<Thread> eventRaiser = new Thread((ThreadStart)&EventRaiser);
    Array<Sp<Thread>> eventLowers(nbThreadLower);
    
    for (int32 i = 0; i < nbThreadLower; i++)
      eventLowers[i] = Sp<Thread>::Create((ThreadStart)&EventLower);
    
    for (Sp<Thread> thread : eventLowers)
      thread->Start();
    eventRaiser->Start();

    Thread::Sleep(3000);
    quit = true;
    
    eventRaiser->Join(100);
    for (Sp<Thread> thread : eventLowers)
      thread->Join(100);
    
    Console::WriteLine("nbEventRaised = {0}", nbEventRaised);
    Console::WriteLine("nbEventLowered = {0}", nbEventLowered);
    ASSERT_EQ(nbEventRaised, nbEventLowered);
    
  }
  
  TEST(AutoResetEvent, CreateAndMakeTwoWait) {
    AutoResetEvent a(true);
    
    EXPECT_TRUE(a.WaitOne());
    ASSERT_FALSE(a.WaitOne(0));
  }
}