#include <Pcf/System/Collections/Generic/Queue.h>
#include <Pcf/System/Threading/Semaphore.h>
#include <Pcf/System/Threading/Thread.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Collections;
using namespace System::Threading;
using namespace TUnit;

namespace {
class Queue : public object, public testing::Test {
public:
  Queue() : _semaphore(0, 10) { }

  void SetUp() override { }
  void TearDown() override { }
  void TestBody() override { }

  static void EnqueueThread(const Object& args);
  static void DequeueThread(const Object& args);
  
protected:
  Generic::Queue<Int32> _queue;
  Semaphore _semaphore;
};

void Queue::EnqueueThread(const Object& args) {
  int32 index = 0;
  while (index < 10) {
    pcf_lock(as<Queue>(args)._queue.SyncRoot) {
      Thread::Sleep(20 + index); // Simulate threatment
      as<Queue>(const_cast<object&>(args))._queue.Enqueue(index++);
    }
    as<Queue>(const_cast<object&>(args))._semaphore.Release(1);
  }
  EXPECT_EQ(10, index);
}

void Queue::DequeueThread(const Object& args) {
  int32 index = 0;
  while (index < 10) {
    as<Queue>(const_cast<object&>(args))._semaphore.WaitOne();
    pcf_lock(as<Queue>(args)._queue.SyncRoot) {
      EXPECT_EQ(as<Queue>(const_cast<object&>(args))._queue.Dequeue(), index++);
      Thread::Sleep(10 + index); // Simulate threatment
    }
  }
  EXPECT_EQ(10, index);
}

TEST_F(Queue, QueueDequeue) {
  Queue threadingHelper;
  Thread EnqueueThread((ParameterizedThreadStart)&Queue::EnqueueThread);
  Thread DequeueThread((ParameterizedThreadStart)&Queue::DequeueThread);
  EnqueueThread.Start(threadingHelper);
  DequeueThread.Start(threadingHelper);
  EnqueueThread.Join();
  DequeueThread.Join();
}

TEST_F(Queue, GetSyncRoot) {
  pcf_lock(_queue.SyncRoot) {
    _queue.Enqueue(1);
    _queue.Enqueue(2);
    _queue.Enqueue(3);
    _queue.Enqueue(4);
    _queue.Enqueue(5);
    _queue.Enqueue(6);
    _queue.Enqueue(7);
    _queue.Enqueue(8);
    _queue.Enqueue(9);
    _queue.Enqueue(10);
    _queue.Enqueue(11);
    _queue.Enqueue(12);
  }

  Generic::Enumerator<Int32> enumerator = _queue.GetEnumerator();
  int32 index = 0;
  while (enumerator.MoveNext())
    EXPECT_EQ(enumerator.Current(), ++index);
  EXPECT_EQ(index, 12);
}

}
