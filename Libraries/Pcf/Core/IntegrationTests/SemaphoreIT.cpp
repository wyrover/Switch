#include <Pcf/System/Threading/Semaphore.h>
#include <Pcf/System/Threading/Thread.h>
#include <Pcf/System/Collections/Generic/Queue.h>
#include <Pcf/System/Guid.h>
#include <Pcf/System/Random.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Threading;
using namespace System::Collections::Generic;
using namespace TUnit;

namespace {

static void ThreadProc(Object& _data) { 
  Threading::Semaphore sem = (Threading::Semaphore&)_data;
  sem.WaitOne();
  Thread::Sleep(100);
  sem.Release();
}

TEST(Semaphore, Ctor_Unnamed) {
  Threading::Semaphore sem1(0, 1);
  Threading::Semaphore sem2(0, 1);
  // Make sure two unnamed semaphores are different
  ASSERT_NE(sem1, sem2);
}

TEST(Semaphore, SemaphoreExceptions) {
  bool createdNew;
  Threading::Semaphore sem(0, 3, "MySempaphore", createdNew);
  EXPECT_TRUE(createdNew);
  EXPECT_THROW(sem.Release(4), SemaphoreFullException);
  sem.Close();
}

TEST(Semaphore, DISABLED_SemaphoreFunctions) {
  bool createdNew(false);
  static Threading::Semaphore sem(0, 3, "MySempaphore", createdNew);
  EXPECT_TRUE(createdNew);
  const int32_t numThread = 5;
  Sp<Thread> threads[numThread];
  for (Int32 i = 0; i < numThread; i++) {
    threads[i] = Sp<Thread>::Create((ParameterizedThreadStart)&ThreadProc);
    threads[i]->SetName("Thread" + Int32(i+1));
    threads[i]->Start(sem);
  }

  Thread::Sleep(50);
  sem.Release();

  Thread::Sleep(50);
  sem.Release(2);

  for (Int32 i = 0; i < numThread; i++)
    threads[i]->Join();
  sem.Close();
}

class SemaphoreThreadTask : public object {
  using KeyValuePairGuids = KeyValuePair<Guid, Guid>;
    
public:
  SemaphoreThreadTask() : _semaphore(0, Int32::MaxValue) {
  }

  void AddItems() {
    while (_nbAdd < nbSignals) {
      int32 nbAddItems = _rand.Next(1, 3);
      if (_nbAdd + nbAddItems > nbSignals)
        nbAddItems = nbSignals - _nbAdd;

      for (int32 i = 0; i < nbAddItems; i++) {
        LockGuard lock(_queue.SyncRoot);
        _queue.Enqueue(_nbAdd+i);
      }
      _nbAdd += nbAddItems;
      _semaphore.Release(nbAddItems);
    }
  }
    
  void CheckItems() {
    EXPECT_EQ(0, _queue.Count);
    EXPECT_EQ(nbSignals, _nbAdd);
    EXPECT_EQ(nbSignals, _nbRemove);
  }
        
  void RemoveItems() {
    while (_nbRemove != nbSignals) {
      _semaphore.WaitOne();
      LockGuard lock(_queue.SyncRoot);
      EXPECT_EQ(_nbRemove, _queue.Dequeue());
      _nbRemove++;
    }
  }
    
private:
  static const int32_t nbSignals;
  Threading::Semaphore _semaphore;
  Queue<Int32> _queue;
  System::Random _rand;
  Int32 _nbAdd;
  Int32 _nbRemove;
};
  
const int32_t SemaphoreThreadTask::nbSignals = 1000;

TEST(Semaphore, WaitOne) {
  SemaphoreThreadTask task;
    
  Thread addItems(ThreadStart(task, &SemaphoreThreadTask::AddItems));
  Thread removeItems(ThreadStart(task, &SemaphoreThreadTask::RemoveItems));
    
  addItems.Start();
  removeItems.Start();
  addItems.Join();
  removeItems.Join();
  task.CheckItems();
}
  
}

