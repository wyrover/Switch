#include <Pcf/System/Threading/Thread.h>
#include <Pcf/System/Threading/EventWaitHandle.h>
#include <Pcf/System/Threading/Mutex.h>
#include <Pcf/System/Diagnostics/Stopwatch.h>
#include <Pcf/System/Console.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace TUnit;

namespace {

// To use a test fixture, derive a class from testing::Test.

static int numIterations = 1;
static Int32 threadCount = 0;

class Thread : public testing::Test {

protected:
  void SetUp() override {
    if (string::IsNullOrEmpty(Threading::Thread::GetCurrentThread()->GetName()))
      Threading::Thread::GetCurrentThread()->SetName("MainThread");
    threadCount = 0;
  }
  
  void TearDown() override { }
  
  static void DoWork(Object& _data) {
    UInt32 DataU32 = (UInt32&)(_data);
    Sp<Threading::Thread> CurrentThread = Threading::Thread::GetCurrentThread();
    EXPECT_TRUE(CurrentThread->GetName() == string("ThreadUnitTest"));
    Threading::Thread::Sleep(50);
    Threading::Thread::Sleep(TimeSpan(500000)); // 500 msec
  }
  
  static void MyThreadProcs(Object&) {
    for (Int32 index = 0; index < 10000; index++) {
      EXPECT_EQ(index, index);
      Threading::Thread::Sleep(0);
    }
  }
  
  static void MyThreadProc(Object& _data) {
    UseResource(as<Threading::Mutex>(_data));
  }
  
  static void MyThreadProc2(Object& /*_data*/) {
    Threading::Mutex mutex = Threading::Mutex::OpenExisting("MyMutex");
    UseResource(mutex);
  }
  
  static void UseResource(Threading::Mutex& _Mutex) {
    for (int i = 0; i < numIterations; i++) {
      // Wait until it is safe to enter.
      _Mutex.WaitOne();
      
      // Place code to access non-reentrant resources here.
      // Simulate some work.
      Threading::Thread::Sleep(50);
      
      // Release the Threading::Mutex.
      _Mutex.ReleaseMutex();
    }
  }
  
  static void MyThreadProc3(Object&) {
    bool createdNew = false;
    Threading::EventWaitHandle evh(false, Threading::EventResetMode::ManualReset, "evh", createdNew);
    EXPECT_EQ(createdNew, false);
    threadCount++;
    EXPECT_TRUE(evh.WaitOne());
    threadCount--;
    evh.Close();
  }
  
  static void MyThreadProc4(Object&) {
    Threading::EventWaitHandle evh = Threading::EventWaitHandle::OpenExisting("evh");
    Threading::Thread::Sleep(120);
    evh.Set();
    evh.Reset();
  }
  
  static void MyThreadProc5(Object&) {
    Threading::EventWaitHandle evh1 = Threading::EventWaitHandle::OpenExisting("evh1");
    Threading::EventWaitHandle evh2 = Threading::EventWaitHandle::OpenExisting("evh2");
    Threading::Mutex mutex = Threading::Mutex::OpenExisting("MyMutex");
    // Get mutex ownership
    mutex.WaitOne();
    Threading::Thread::Sleep(60);
    evh1.Set();
    evh2.Set();
    Threading::Thread::Sleep(60);
    mutex.ReleaseMutex();
    evh1.Reset();
    evh2.Reset();
  }
  
  static void MyThreadProc6(Object&) {
    Threading::EventWaitHandle evh1 = Threading::EventWaitHandle::OpenExisting("evh1");
    Threading::EventWaitHandle evh2 = Threading::EventWaitHandle::OpenExisting("evh2");
    Threading::Mutex mutex = Threading::Mutex::OpenExisting("MyMutex");
    {
      Threading::Thread::Sleep(120);
      
      Console::WriteLine(DateTime::Now + " : Evh2");
      evh2.Set();
      Threading::Thread::Sleep(20);
      Console::WriteLine(DateTime::Now + " : Evh1");
      evh1.Set();
      Threading::Thread::Sleep(60);
      Console::WriteLine(DateTime::Now + " : Threading::Mutex");
      mutex.ReleaseMutex();
    }
    
    evh1.Reset();
    evh2.Reset();
  }
  
  static void TimerThreadProc(Object& _data) {
    Int32& count = as<Int32>(_data);
    count++;
    Threading::Thread::Sleep(0);
  }
  
  static void SimpleThread(Object& /*obj*/) {
    EXPECT_EQ(string("SimpleThread"), Threading::Thread::GetCurrentThread()->GetName());
    EXPECT_EQ(Threading::ThreadState(Threading::ThreadState::Running), Threading::Thread::GetCurrentThread()->GetState());
    for (int32 i = 0; i < 10; i++);
    Threading::Thread::Sleep(10);
  }
};

TEST_F(Thread, SimpleThread) {
  EXPECT_EQ(string("MainThread"), Threading::Thread::GetCurrentThread()->GetName());
  EXPECT_EQ(Threading::ThreadState(Threading::ThreadState::Running), Threading::Thread::GetCurrentThread()->GetState());
  Sp<Threading::Thread> thread = new Threading::Thread((Threading::ParameterizedThreadStart)SimpleThread);
  EXPECT_NE(thread, Sp<Threading::Thread>::Null());
  thread->SetName("SimpleThread");
  EXPECT_EQ(string("SimpleThread"), thread->GetName());
  EXPECT_EQ(Threading::ThreadState(Threading::ThreadState::Unstarted), thread->GetState());
  thread->Start();
  Threading::Thread::Sleep(100);
  thread->Join();
}

TEST_F(Thread, Thread) {
  EXPECT_THROW(Threading::Thread((Threading::ParameterizedThreadStart)null), ArgumentNullException);
  DateTime StartTime = DateTime::Now;
  Threading::Thread newThread((Threading::ParameterizedThreadStart)DoWork);
  EXPECT_EQ(newThread.GetName(), string::Empty);
  newThread.SetName("ThreadUnitTest");
  EXPECT_EQ(newThread.GetName(), string("ThreadUnitTest"));
  EXPECT_THROW(newThread.SetName("OtherName"), InvalidOperationException);
  EXPECT_FALSE(newThread.IsAlive());
  EXPECT_EQ(newThread.GetState(), Threading::ThreadState::Unstarted);
  static UInt32 five = 5;
  EXPECT_THROW(newThread.GetPriority(), Threading::ThreadStateException);
  newThread.Start(five);
  Threading::Thread::Sleep(10);
  // Pas nécessairement il peut être en mode ThreadStatWaitSleepJoin (comme par exemple s'il est dans un Threading::Thread::Sleep...)
  //EXPECT_EQ(newThread.GetState(), ThreadStateRunning);
  EXPECT_TRUE(newThread.IsAlive());
  EXPECT_EQ(newThread.GetPriority(), Threading::ThreadPriority(Threading::ThreadPriority::Normal));
  // Priority test
  newThread.SetPriority(Threading::ThreadPriority::Lowest);
  EXPECT_EQ(newThread.GetPriority(), Threading::ThreadPriority(Threading::ThreadPriority::Lowest));
  newThread.SetPriority(Threading::ThreadPriority::BelowNormal);
  EXPECT_EQ(newThread.GetPriority(), Threading::ThreadPriority(Threading::ThreadPriority::BelowNormal));
  newThread.SetPriority(Threading::ThreadPriority::Normal);
  EXPECT_EQ(newThread.GetPriority(), Threading::ThreadPriority(Threading::ThreadPriority::Normal));
  newThread.SetPriority(Threading::ThreadPriority::AboveNormal);
  EXPECT_EQ(newThread.GetPriority(), Threading::ThreadPriority(Threading::ThreadPriority::AboveNormal));
  newThread.SetPriority(Threading::ThreadPriority::Highest);
  EXPECT_EQ(newThread.GetPriority(), Threading::ThreadPriority(Threading::ThreadPriority::Highest));
  
  // Join
  // Pas nécessairement il peut être en mode ThreadStatWaitSleepJoin (comme par exemple s'il est dans un Threading::Thread::Sleep...)
  //EXPECT_EQ(newThread.GetState(), ThreadStateWaitSleepJoin);
  EXPECT_TRUE(newThread.IsAlive());
  EXPECT_FALSE(newThread.Join(10));
  // Pas nécessairement il peut être en mode ThreadStatWaitSleepJoin (comme par exemple s'il est dans un Threading::Thread::Sleep...)
  //EXPECT_EQ(newThread.GetState(), ThreadStateWaitSleepJoin);
  EXPECT_TRUE(newThread.IsAlive());
  EXPECT_FALSE(newThread.Join(TimeSpan(10)));
  // Pas nécessairement il peut être en mode ThreadStatWaitSleepJoin (comme par exemple s'il est dans un Threading::Thread::Sleep...)
  //EXPECT_EQ(newThread.GetState(), ThreadStateWaitSleepJoin);
  EXPECT_TRUE(newThread.IsAlive());
  
  newThread.Join();
  
  EXPECT_EQ(newThread.GetState(), Threading::ThreadState(Threading::ThreadState::Stopped));
  EXPECT_FALSE(newThread.IsAlive());
}

TEST_F(Thread, ThreadPriorityCanBeSetBeforeStartingAThread) {
  Threading::ThreadPriority wanted = Threading::ThreadPriority::AboveNormal;
  Threading::ThreadPriority expected = Threading::ThreadPriority::Normal;
  Sp<Threading::Thread> thread = new Threading::Thread((Threading::ThreadStart)[&]() {
    expected = Threading::Thread::GetCurrentThread()->GetPriority();
  });

	thread->SetPriority(wanted);
	thread->Start();

	thread->Join();
	EXPECT_EQ(expected, wanted);
}

/*
 TEST_F(Thread, Threads)
 {
 const int32_t nbMaxThreads = 50;
 const int32_t nbCount = 42;
 Up<Threading::Thread> threads[nbMaxThreads];
 
 for (Int32 count = 0; count < nbCount; count++)
 {
 for (Int32 index=0; index < nbMaxThreads; index++)
 {
 threads[index] = Up<Threading::Thread>::Create(MyThreadProcs);
 threads[index]->SetName("Threading::Thread " + Int32(index+1));
 threads[index]->Start(index);
 }
 
 Threading::Thread::Sleep(10);
 
 // Wait for all threads to terminate and close them
 for (Int32 index = 0; index < nbMaxThreads; index++)
 {
 threads[index]->Join();
 threads[index]->Close();
 }
 }
 
 EXPECT_TRUE(threadCount == 0);
 }
 */

TEST_F(Thread, UnnamedMutex) {
  const Int32 nbMaxThreads = 3;
  Threading::Mutex mutex(false);
  Collections::Generic::List<Sp<Threading::Thread>> threads;
  
  // Create the threads that will use the protected resource.
  Int32 count;
  while (threads.Count < nbMaxThreads) {
    threads.Add(new Threading::Thread((Threading::ParameterizedThreadStart)MyThreadProc));
    threads[threads.Count-1]->SetName(string("Threading::Thread ") + threads.Count);
    threads[threads.Count-1]->Start(mutex);
  }
  // Wait for all threads to terminate and close them
  for (int32 index = 0; index < nbMaxThreads; index++) 
    threads[index]->Join();
  
  mutex.Close();
}

TEST_F(Thread, NamedMutex) {
  const int32_t nbMaxThreads = 3;
  Up<Threading::Thread> threads[nbMaxThreads];
  bool createdNew = false;
  Threading::Mutex mutex(false, "MyMutex", createdNew);
  EXPECT_TRUE(createdNew);
  // Create the threads that will use the protected resource.
  for (Int32 index = 0; index < nbMaxThreads; index++) {
    threads[index] = Up<Threading::Thread>::Create((Threading::ParameterizedThreadStart)MyThreadProc2);
    threads[index]->SetName("Threading::Thread " + Int32(index+1));
    threads[index]->Start(index);
  }

  // Wait for all threads to terminate and close them
  for (int32 index = 0; index < nbMaxThreads; index++) {
    threads[index]->Join();
  }
  mutex.Close();
}

TEST_F(Thread, DISABLED_ManualResetEvent) {
  bool createdNew = false;
  Threading::EventWaitHandle evh(false, Threading::EventResetMode::ManualReset, "evh", createdNew);
  Int32 index = 0;
  threadCount = 0;
  const int32_t nbMaxThreads = 5;
  Up<Threading::Thread> threads[nbMaxThreads];
  
  for (index = 0; index < nbMaxThreads; index++) {
    threads[index] = Up<Threading::Thread>::Create((Threading::ParameterizedThreadStart)MyThreadProc3);
    threads[index]->SetName("Threading::Thread " + Int32(index+1));
    threads[index]->Start(index);
  }
  
  // Wait until all the threads have started and blocked.
  while (threadCount < nbMaxThreads)
    Threading::Thread::Sleep(1);
  
  EXPECT_EQ(threadCount, nbMaxThreads);
  
  // Because the Threading::EventWaitHandle was created with
  // ManualReset mode, signaling it releases all the
  // waiting threads.
  evh.Set();
  
  // Wait for all threads to terminate and close them
  for (Int32 index = 0; index < nbMaxThreads; index++) {
    threads[index]->Join();
  }
  EXPECT_EQ(threadCount, 0);
  evh.Close();
}

TEST_F(Thread, DISABLED_AutoResetEvent) {
  const int32_t nbMaxThreads = 5;
  Up<Threading::Thread> threads[nbMaxThreads];
  bool createdNew = false;
  Threading::EventWaitHandle evh(false, Threading::EventResetMode::ManualReset, "evh", createdNew);
  for (Int32 index = 0; index < nbMaxThreads; index++) {
    threads[index] = Up<Threading::Thread>::Create((Threading::ParameterizedThreadStart)MyThreadProc3);
    threads[index]->SetName("Threading::Thread " + Int32(index+1));
    threads[index]->Start(index);
  }
  
  // Wait until all the threads have started and blocked.
  while (threadCount < nbMaxThreads)
    Threading::Thread::Sleep(10);
  
  // Because the Threading::EventWaitHandle was created with
  // AutoReset mode, signaling it releases only one thread.
  for (Int32 index = 0; index < nbMaxThreads; index++) {
    evh.Set();
    while (threadCount > nbMaxThreads - (index + 1))
      Threading::Thread::Sleep(0);
  }
  
  // Wait for all threads to terminate and close them
  for (Int32 index = 0; index < nbMaxThreads; index++) {
    threads[index]->Join();
  }
  EXPECT_TRUE(threadCount == 0);
  evh.Close();
}

TEST_F(Thread, WaitHandleWaitOne) {
  Threading::EventWaitHandle evh(false, Threading::EventResetMode::AutoReset, "evh");
  UInt32 obj = 0;
  Sp<Threading::Thread> thread = new Threading::Thread((Threading::ParameterizedThreadStart)MyThreadProc4);
  thread->Start(obj);
  EXPECT_FALSE(evh.WaitOne(00));
  EXPECT_FALSE(evh.WaitOne(TimeSpan(500000)));
  evh.WaitOne();
  evh.Close();
  thread->Join();
}

/*
TEST_F(Thread, WaitHandleWaitAll)
{
  List<WaitHandle> waitHandles;
  waitHandles.Add(new Threading::EventWaitHandle(false, Threading::EventResetMode::AutoReset, "evh1"));
  waitHandles.Add(new Threading::EventWaitHandle(false, Threading::EventResetMode::AutoReset, "evh2"));
  waitHandles.Add(new Threading::Mutex(true, "MyMutex"));
  
  
  UInt32 Object = 0;
  Sp<Threading::Thread> thread = new Threading::Thread(MyThreadProc5);
  thread->Start(Object);
  
  // Release the mutex
  Threading::Thread::Sleep(20);
  as<Threading::Mutex>(*waitHandles[2]).ReleaseMutex();
  
  EXPECT_FALSE(WaitHandle::WaitAll(waitHandles, 500));
  EXPECT_FALSE(WaitHandle::WaitAll(waitHandles, TimeSpan(5000000)));
  EXPECT_TRUE(WaitHandle::WaitAll(waitHandles));
  
  waitHandles[0].Release();
  waitHandles[1].Release();
  waitHandles[2].Release();
  
  thread->Join();
}
*/
/*
 TEST_F(Thread, WaitHandleWaitAny)
 {
 WaitHandle* waitHandle[3];
 Threading::EventWaitHandle event1 = Threading::EventWaitHandle(false, EventResetModeAutoReset, "evh1");
 Threading::EventWaitHandle event2 = Threading::EventWaitHandle(false, EventResetModeAutoReset, "evh2");
 Threading::Mutex mutex = Threading::Mutex(true, "MyMutex");
 waitHandle[0] = &event1;
 waitHandle[1] = &event2;
 waitHandle[2] = &mutex;
 
 
 UInt32 Object = 0;
 Threading::Thread Threading::Thread(MyThreadProc6);
 Threading::Thread.Start(Object);
 
 // Release the mutex
 //Threading::Thread::Sleep(20);
 //((const Threading::Mutex*)waitHandle[2])->ReleaseMutex();
 
 Console::WriteLine("Read " + DateTime::Now + " : TO");
 EXPECT_EQ(WaitHandle::WaitAny(waitHandle, sizeof(waitHandle)/sizeof(waitHandle[0]), 500), WaitHandle::WaitTimeOut());
 Console::WriteLine("Read " + DateTime::Now + " : TO");
 EXPECT_EQ(WaitHandle::WaitAny(waitHandle, sizeof(waitHandle)/sizeof(waitHandle[0]), TimeSpan(5000000)), WaitHandle::WaitTimeOut());
 Console::WriteLine("Read " + DateTime::Now + " : Evh2");
 EXPECT_EQ(WaitHandle::WaitAny(waitHandle, sizeof(waitHandle)/sizeof(waitHandle[0])), 1);
 Threading::Thread::Sleep(40);
 Console::WriteLine("Read " + DateTime::Now + " : Evh1");
 EXPECT_EQ(WaitHandle::WaitAny(waitHandle, sizeof(waitHandle)/sizeof(waitHandle[0])), 0);
 Threading::Thread::Sleep(80);
 Console::WriteLine("Read " + DateTime::Now + " : Threading::Mutex");
 EXPECT_EQ(WaitHandle::WaitAny(waitHandle, sizeof(waitHandle)/sizeof(waitHandle[0])), 2);
 
 waitHandle[0]->Close();
 waitHandle[1]->Close();
 waitHandle[2]->Close();
 
 Threading::Thread.Join();
 Threading::Thread.Close();
 }

TEST_F(Thread, Timer) {
  Int32 count;
  Sp<Threading::Timer> timer = new Threading::Timer(TimerThreadProc, count, TimeSpan::FromMilliseconds(40.0), TimeSpan::FromMilliseconds(20.0));
  Threading::Thread::Sleep(115); // Attente de 1,1 Seconde
  timer.Reset();
  EXPECT_EQ(count, 4);
}
*/

TEST_F(Thread, Sleep) {
  const Int32 timeout = 20;
  Diagnostics::Stopwatch stopWatch;
  stopWatch.Start();
  Threading::Thread::Sleep(timeout);
  stopWatch.Stop();
  EXPECT_GE(stopWatch.Elapsed().Ticks(), timeout);
}

TEST_F(Thread, Rename) {
  EXPECT_EQ(string("MainThread"), Threading::Thread::GetCurrentThread()->GetName());
  EXPECT_THROW(Threading::Thread::GetCurrentThread()->SetName("MainThread"), InvalidOperationException);
}

}