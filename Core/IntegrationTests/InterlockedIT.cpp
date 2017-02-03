#include <Pcf/System/Threading/Interlocked.h>
#include <Pcf/System/Threading/Thread.h>
#include <Pcf/System/Random.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {

class CountClass {
public:
  static int32 UnsafeInstanceCount;
  static int32 SafeInstanceCount;

  CountClass() {
    UnsafeInstanceCount++;
    Threading::Interlocked::Increment(SafeInstanceCount);
  }

  ~CountClass() {
    UnsafeInstanceCount--;
    Threading::Interlocked::Decrement(SafeInstanceCount);
  }
};

int32 CountClass::UnsafeInstanceCount = 0;
int32 CountClass::SafeInstanceCount = 0;
int32 usingResource = 0;
int32 safeTotalValue = 0;
int32 unsafeTotalValue = 0;
const int32 addEnd = 5;

class Interlocked: public testing::Test {  
protected: 
  static void ThreadProc(const object&) {
    // Create 100000 instances of CountClass.
    for (int i = 0; i < 100000; i++)
      CountClass cClass;
  }

  static void ThreadProc2(const object&) {
    for (int i = 0; i < 5; i++) {
      UseResource();
      //Wait 0.1 second before next attempt.
      Threading::Thread::Sleep(100);
    }
  }

  static bool UseResource() {
    //0 indicates that the method is not in use.
    if (0 == Threading::Interlocked::Exchange(usingResource, 1)) {
      //Code to access a resource that is not Threading::Thread safe would go here.

      //Simulate some work
      Threading::Thread::Sleep(50);

      //Release the lock
      Threading::Interlocked::Exchange(usingResource, 0);
      return true;
    }
    return false;
  }

  static void ThreadProc3(const Object& _data) {
    for (int i = 0; i < static_cast<const Int32&>(_data); i++) {
      SafeAddToTotal(addEnd);
      UnsafeAddToTotal(addEnd);
    }
  }

  static int32_t SafeAddToTotal(int32_t addend) {
    int32 initialValue = 0;
    int32 computedValue = 0;
    do {
      initialValue = safeTotalValue;
      computedValue = initialValue + addend;
    } while (initialValue != Threading::Interlocked::CompareExchange(safeTotalValue, computedValue, initialValue));
    return computedValue;
  }

  static int32_t UnsafeAddToTotal(int32_t addend) {
    unsafeTotalValue += addend;
    return unsafeTotalValue;
  }
};  


TEST_F(Interlocked, IncrementDecrement) {
  Threading::Thread thread1((Threading::ParameterizedThreadStart)&ThreadProc);
  Threading::Thread thread2((Threading::ParameterizedThreadStart)&ThreadProc);
  thread1.Start();
  thread2.Start();
  thread1.Join();
  thread2.Join();

  //EXPECT_FALSE(CountClass::UnsafeInstanceCount == 0); Not necessary true
  EXPECT_TRUE(CountClass::SafeInstanceCount == 0);
}

TEST_F(Interlocked, DISABLED_Exchange) { // problem under CE
  const int32_t maxThread = 9;
  sp<Threading::Thread> threads[maxThread];
  System::Random myRandom(1000);

  for (Int32 index = 0; index < maxThread; index++) {
    threads[index] = sp<Threading::Thread>::Create((Threading::ParameterizedThreadStart)&ThreadProc2);
	  threads[index]->Name = string::Format("Thread{0}", index+1);
    //Wait a random amount of time before starting next thread.
    Threading::Thread::Sleep(myRandom.Next(0, 100));
    threads[index]->Start();
  }

  for (Int32 index = 0; index < maxThread; index++)
  	threads[index]->Join();
}

TEST_F(Interlocked, DISABLED_CompareExchange) { // problem under CE
  safeTotalValue = 0;
  unsafeTotalValue = 0;
  const int32_t maxThread = 9;
  sp<Threading::Thread>threads[maxThread];
  static Int32 loopCount = 10000;
  for (Int32 index = 0; index < maxThread; index++) {
    threads[index] = sp<Threading::Thread>::Create((Threading::ParameterizedThreadStart)&ThreadProc3);
    threads[index]->Name = string::Format("Thread{0}", index+1);
    threads[index]->Start(loopCount);
  }

  for (Int32 index = 0; index < maxThread; index++)
    threads[index]->Join();

  int32 expectedResult = maxThread * loopCount * addEnd;
  EXPECT_TRUE(safeTotalValue == expectedResult);
}

}
