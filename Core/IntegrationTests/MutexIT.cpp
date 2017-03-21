#include <Pcf/System/Threading/Mutex.h>
#include <Pcf/System/Threading/Thread.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {
  class Mutex : public testing::Test {
  public:
    static Threading::Mutex _mutex;
    static Object _sync;
    static Boolean _stoppingTest;
    static Int32 _counter;
    
    void SetUp() {
    }
    
    void TearDown() {
    }
    
    static void MyThread(const Object&) {
      for (int32 index = 0; index < 100; index++) {
        _mutex.WaitOne();
        EXPECT_EQ(index, index);
        _mutex.ReleaseMutex();
      }
    }
    
    static void MyThread2(const Object& _param) {
      for (int32 index = 0; index < 100; index++) {
        static_cast<Threading::Mutex&>(const_cast<Object&>(_param)).WaitOne();
        EXPECT_EQ(index, index);
        static_cast<Threading::Mutex&>(const_cast<Object&>(_param)).ReleaseMutex();
      }
    }
    
    static void MyThread3(const Object&) {
      for (int32 index = 0; index < 10000; index++) {
        System::Threading::LockGuard lock(_sync);
        int32 cpt = _counter;
        EXPECT_EQ(cpt, _counter);
        _counter++;
      }
    }
    
    static void MyThread4(const Object& _param) {
      for ( ; ; ) {
        static_cast<Threading::Mutex&>(const_cast<Object&>(_param)).WaitOne();
        if (_stoppingTest)
          return;
        _counter++;
      }
    }
  };
  
  Threading::Mutex Mutex::_mutex;
  Object Mutex::_sync;
  Boolean Mutex::_stoppingTest;
  Int32 Mutex::_counter;

  TEST_F(Mutex, Ctor_Unnamed) {
    Threading::Mutex mutex1;
    Threading::Mutex mutex2;
    
    // Make sure two unnamed mutexes are different
    ASSERT_NE(mutex1, mutex2);
  }
  
  TEST_F(Mutex, Ctor) {
    Threading::Thread thread((Threading::ParameterizedThreadStart)&MyThread);
    thread.Start();
    for (int32 index = 0; index < 100; index++) {
      _mutex.WaitOne();
      EXPECT_EQ(index, index);
      _mutex.ReleaseMutex();
    }
    thread.Join();
  }
  
  TEST_F(Mutex, NewMutex) {
    Threading::Mutex mutex;
    Threading::Thread thread((Threading::ParameterizedThreadStart)&MyThread2);
    thread.Start(mutex);
    for (int32 index = 0; index < 100; index++) {
      mutex.WaitOne();
      EXPECT_EQ(index, index);
      mutex.ReleaseMutex();
    }
    thread.Join();
  }
  
  TEST_F(Mutex, Lock) {
    _counter = 0;
    Threading::Thread thread((Threading::ParameterizedThreadStart)&MyThread3);
    thread.Start();
    for (int32 index = 0; index < 10000; index++) {
      System::Threading::LockGuard lock(_sync);
      Int32 cpt = _counter;
      EXPECT_EQ(cpt, _counter);
      _counter++;
    }
    thread.Join();
  }
  
  TEST_F(Mutex, DISABLED_MultipleWaitsIntegrationTest) {
    _stoppingTest = false;
    _counter = 0;
    Threading::Mutex mutex(true);
    Threading::Thread thread((Threading::ParameterizedThreadStart)&MyThread4);
    thread.Start(mutex);
    Threading::Thread::Sleep(100);
    mutex.ReleaseMutex();
    Threading::Thread::Sleep(100);
    mutex.ReleaseMutex();
    Threading::Thread::Sleep(100);
    mutex.ReleaseMutex();
    Threading::Thread::Sleep(100);
    _stoppingTest = true;
    mutex.ReleaseMutex();
    thread.Join();
    ASSERT_EQ(3, _counter);
  }
}
