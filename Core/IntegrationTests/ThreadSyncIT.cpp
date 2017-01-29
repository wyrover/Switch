#include <Pcf/System/Threading/AutoResetEvent.h>
#include <Pcf/System/Threading/ManualResetEvent.h>
#include <Pcf/System/Threading/Mutex.h>
#include <Pcf/System/Threading/Semaphore.h>
#include <Pcf/System/Threading/Thread.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Threading;
using namespace TUnit;

namespace {
  
  class ThreadSynchro : public testing::Test {
  public:
    static const int32 CountMax = 1000;
    static int32 counter;
    
    void SetUp() {
      counter = 0;
    }
    
    void TearDown() {
    }
    
    static void Write(const Object& /*obj*/) {
      //Console::Write(obj);
    }
    
    static void WriteLine(const Object& obj) {
      Write(obj.ToString() + Environment::NewLine);
    }
    
    static void Write(const string& str) {
      Write(as<Object>(str));
    }
    
    static void WriteLine(const string& str) {
      WriteLine(as<Object>(str));
    }
    
    static void ThreadAutoResetEvent(Object& event) {
      for (int32 index = 0; index < CountMax; index++) {
        if (as<AutoResetEvent>(event).WaitOne()) {
          counter++;
          Write("+");
          as<AutoResetEvent>(event).Set();
        }
      }
    }
    
    static void ThreadLock(Object& sync) {
      for (int32 index = 0; index < CountMax; index++) {
        LockGuard lock(sync);
        counter++;
        Write("+");
      }
    }
    
    static void ThreadManualResetEvent(Object& event) {
      for (int32 index = 0; index < CountMax; index++) {
        if (as<ManualResetEvent>(event).WaitOne()) {
          counter++;
          Write("+");
          as<ManualResetEvent>(event).Set();
          Thread::Sleep(0);
          as<ManualResetEvent>(event).Reset();
        }
      }
    }
    
    static void ThreadMutex(Object& mutex) {
      for (int32 index = 0; index < CountMax; index++) {
        if (as<Mutex>(mutex).WaitOne()) {
          counter++;
          Write("+");
          as<Mutex>(mutex).ReleaseMutex();
        }
      }
    }
    
    static void ThreadSemaphore(Object& semaphore) {
      for (int32 index = 0; index < CountMax; index++) {
        if (as<Semaphore>(semaphore).WaitOne()) {
          counter++;
          Write("+");
          as<Semaphore>(semaphore).Release();
        }
      }
    }
  };
  
  int32 ThreadSynchro::counter;
  const int32 ThreadSynchro::CountMax;
  
  TEST_F(ThreadSynchro, AutoResetEvent) {
    int32 index = 0;
    AutoResetEvent event(true);
    Thread thread((ParameterizedThreadStart)ThreadAutoResetEvent);
    
    thread.Start(event);
    
    while (index < CountMax) {
      if (event.WaitOne()) {
        int32 cpt = counter;
        EXPECT_EQ(cpt, counter);
        index++;
        Write("-");
        event.Set();
      }
    }
    
    thread.Join();
    
    EXPECT_EQ(CountMax, index);
    EXPECT_EQ(CountMax, counter);
    Write(Environment::NewLine);
  }
  
  TEST_F(ThreadSynchro, Lock) {
    int32 index = 0;
    
    //sp<TimeSpan> duration;
    //profile(duration)
    {
      Object sync;
      Thread thread((ParameterizedThreadStart)ThreadLock);
      
      thread.Start(sync);
      
      while (index < CountMax) {
        pcf_lock(sync) {
          Int32 cpt = counter;
          EXPECT_EQ(cpt, counter);
          index++;
          Write("-");
        }
      }
      
      thread.Join();
      Write(Environment::NewLine);
    }
    //Console::WriteLine("Lock Duration : " + *duration);
    
    EXPECT_EQ(CountMax, index);
    EXPECT_EQ(CountMax, counter);
  }
  
  TEST_F(ThreadSynchro, DISABLED_ManualResetEvent) {
    int32 index = 0;
    ManualResetEvent event(false);
    Thread thread((ParameterizedThreadStart)ThreadManualResetEvent);
    
    thread.Start(event);
    
    event.Set();
    Thread::Sleep(0);
    event.Reset();
    
    while (index < CountMax) {
      if (event.WaitOne()) {
        int32 cpt = counter;
        EXPECT_EQ(cpt, counter);
        index++;
        Write("-");
        event.Set();
        Thread::Sleep(0);
        event.Reset();
      }
    }
    
    thread.Join();
    
    EXPECT_EQ(CountMax, index);
    EXPECT_EQ(CountMax, counter);
    Write(Environment::NewLine);
  }
  
  TEST_F(ThreadSynchro, Mutex) {
    int32 index = 0;
    Mutex mutex;
    Thread thread((ParameterizedThreadStart)ThreadMutex);
    
    thread.Start(mutex);
    
    while (index < CountMax) {
      if (mutex.WaitOne()) {
        int32 cpt = counter;
        EXPECT_EQ(cpt, counter);
        index++;
        Write("-");
        mutex.ReleaseMutex();
      }
    }
    
    thread.Join();
    Write(Environment::NewLine);
    
    EXPECT_EQ(CountMax, index);
    EXPECT_EQ(CountMax, counter);
  }
  
  TEST_F(ThreadSynchro, Semaphore) {
    int32 index = 0;
    Semaphore semaphore(1, 1);
    Thread thread((ParameterizedThreadStart)ThreadSemaphore);
    
    thread.Start(semaphore);
    
    while (index < CountMax) {
      if (semaphore.WaitOne()) {
        int32 cpt = counter;
        EXPECT_EQ(cpt, counter);
        index++;
        Write("-");
        semaphore.Release();
      }
    }
    
    thread.Join();
    Write(Environment::NewLine);
    
    EXPECT_EQ(CountMax, index);
    EXPECT_EQ(CountMax, counter);
  }
  
}

