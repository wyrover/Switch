#include "../../../../Includes/Switch/System/Threading/ThreadPool.hpp"
#include "../../../../Includes/Switch/System/Convert.hpp"
#include "../../../../Includes/Switch/System/Environment.hpp"
#include "../../../../Includes/Switch/System/Threading/Mutex.hpp"
#include "../../../../Includes/Switch/System/Threading/ThreadInterruptedException.hpp"
#include "../../../../Includes/Switch/System/Threading/TimeOut.hpp"

using namespace System;
using namespace System::Threading;

int32 ThreadPool::maxThreads = 800;
int32 ThreadPool::maxAsynchronousIOThreads = 800;
int32 ThreadPool::minThreads = int32(std::thread::hardware_concurrency());
int32 ThreadPool::minAsynchronousIOThreads = int32(std::thread::hardware_concurrency());
bool ThreadPool::closed = false;
ThreadPool::ThreadPoolItemCollection ThreadPool::threadPoolItems;
ThreadPool::ThreadPoolAsynchronousIOItemCollection ThreadPool::threadPoolAsynchronousIOItems;

Semaphore ThreadPool::semaphore = Semaphore(0, maxThreads);
Semaphore ThreadPool::asynchronousIOSemaphore = Semaphore(0, maxAsynchronousIOThreads);
ThreadPool::ThreadArray ThreadPool::threads;
ThreadPool::AsynchronousThreadArray ThreadPool::asynchronousIOThreads;

ThreadPool::ThreadArray::~ThreadArray() {
  closed = true;
  for (Thread& thread : *this)
    if (thread.ThreadState != ThreadState::Unstarted)
      semaphore.Release();
  
  for (Thread& thread : *this)
    if (thread.ThreadState != ThreadState::Unstarted)
      thread.Join();
  closed = false;
}

ThreadPool::AsynchronousThreadArray::~AsynchronousThreadArray() {
  closed = true;
  for (Thread& thread : *this)
    if (thread.ThreadState != ThreadState::Unstarted)
      asynchronousIOSemaphore.Release();
  
  for (Thread& thread : *this)
    if (thread.ThreadState != ThreadState::Unstarted)
      thread.Join();
  closed = false;
}

void ThreadPool::GetAvailableThreads(int32& workerThreads, int32& completionPortThreads) {
  workerThreads = maxThreads - threadPoolItems.Count;
  completionPortThreads = maxAsynchronousIOThreads - threadPoolAsynchronousIOItems.Count;
}

void ThreadPool::GetMaxThreads(int32& workerThreads, int32& completionPortThreads) {
  workerThreads = maxThreads;
  completionPortThreads = maxAsynchronousIOThreads;
}

void ThreadPool::GetMinThreads(int32& workerThreads, int32& completionPortThreads) {
  workerThreads = minThreads;
  completionPortThreads = minAsynchronousIOThreads;
}

bool ThreadPool::QueueUserWorkItem(const WaitCallback& callBack) {
  if (threads.Count == 0)
    CreateThreads();
  _lock(threadPoolItems.SyncRoot) {
    if (threadPoolItems.Count() == maxThreads)
      return false;
    threadPoolItems.Enqueue(new ThreadPoolItem(callBack));
    semaphore.Release();
  }
  return true;
}

bool ThreadPool::QueueUserWorkItem(const WaitCallback& callBack, object& state) {
  if (threads.Count == 0)
    CreateThreads();
  _lock(threadPoolItems.SyncRoot) {
    if (threadPoolItems.Count() == maxThreads)
      return false;
    threadPoolItems.Enqueue(new ThreadPoolItem(callBack, state));
    semaphore.Release();
  }
  return true;
}

RegisteredWaitHandle ThreadPool::RegisterWaitForSingleObject(WaitHandle& waitObject, const WaitOrTimerCallback& callBack, object& state, int32 millisecondsTimeoutInterval, bool executeOnlyOnce) {
  if (asynchronousIOThreads.Count == 0)
    CreateAsynchronousIOThreads();
  RegisteredWaitHandle result;
  _lock(threadPoolAsynchronousIOItems.SyncRoot) {
    if (threadPoolAsynchronousIOItems.Count() == maxAsynchronousIOThreads) {
      return result;
    }
    refptr<ThreadPoolAsynchronousIOItem> item = new ThreadPoolAsynchronousIOItem(callBack, state, waitObject, millisecondsTimeoutInterval, executeOnlyOnce);
    result.item = item.ToPointer();
    threadPoolAsynchronousIOItems.Enqueue(item);
    asynchronousIOSemaphore.Release();
  }
  return result;
}

bool ThreadPool::SetMaxThreads(int32 workerThreads, int32 completionPortThreads) {
  if (workerThreads < Environment::ProcessorCount || completionPortThreads < Environment::ProcessorCount)
    return false;

  maxThreads = workerThreads;
  maxAsynchronousIOThreads = completionPortThreads;
  
  _lock(threadPoolItems.SyncRoot)
    semaphore = Semaphore(semaphore.Release(), maxThreads);
  _lock(threadPoolAsynchronousIOItems.SyncRoot)
    asynchronousIOSemaphore = Semaphore(asynchronousIOSemaphore.Release(), maxAsynchronousIOThreads);
  
  return true;
}

bool ThreadPool::SetMinThreads(int32 workerThreads, int32 completionPortThreads) {
  if (workerThreads < 0 || completionPortThreads < 0 || workerThreads >= maxThreads || completionPortThreads >= maxAsynchronousIOThreads)
    return false;
  
  minThreads = workerThreads;
  minAsynchronousIOThreads = completionPortThreads;
  
  if (threads.Count != 0)
    CreateThreads();
  
  if (asynchronousIOThreads.Count != 0)
    CreateAsynchronousIOThreads();
  
  return true;
}

void ThreadPool::CreateThreads() {
  threads = ThreadArray(minThreads);
  for (int32 i = 0; i < minThreads; i++) {
    threads[i] = Thread(ThreadStart(&ThreadPool::Run));
    threads[i].Name = "Thread Pool";
    threads[i].data->isThreadPoolThread = true;
    threads[i].IsBackground = true;
    threads[i].Start();
  }
}

void ThreadPool::CreateAsynchronousIOThreads() {
  asynchronousIOThreads = AsynchronousThreadArray(minAsynchronousIOThreads);
  for (int32 i = 0; i < minAsynchronousIOThreads; i++) {
    asynchronousIOThreads[i] = Thread(ThreadStart(&ThreadPool::AsynchronousIORun));
    asynchronousIOThreads[i].Name = "Thread Pool";
    asynchronousIOThreads[i].data->isThreadPoolThread = true;
    asynchronousIOThreads[i].IsBackground = true;
    asynchronousIOThreads[i].Start();
  }
}

void ThreadPool::Run() {
  while(!closed) {
    semaphore.WaitOne();
    if (!closed) {
      refptr<ThreadPoolItem> item;
      _lock(threadPoolItems.SyncRoot)
        item = threadPoolItems.Dequeue();
      item->callback(*item->state);
    }
  }
}

void ThreadPool::AsynchronousIORun() {
  while(!closed) {
    asynchronousIOSemaphore.WaitOne();
    if (!closed) {
      refptr<ThreadPoolAsynchronousIOItem> item;
      _lock(threadPoolAsynchronousIOItems.SyncRoot)
      item = threadPoolAsynchronousIOItems.Dequeue();
      
      do {
        bool timeout = !item->waitObject->WaitOne(item->millisecondsTimeoutInterval);
        if (!item->unregistered)
          item->callback(*item->state, timeout);
      } while (!item->executeOnlyOnce && !item->unregistered);
    }
  }
}

bool RegisteredWaitHandle::Unregister() {
  if (item == null)
    return false;
  
  ThreadPool::ThreadPoolAsynchronousIOItem& item = *((ThreadPool::ThreadPoolAsynchronousIOItem*)this->item);
  item.unregistered = true;
  return item.waitObject->Signal();
}

bool RegisteredWaitHandle::Unregister(WaitHandle& waitObject) {
  if (item == null)
    return false;
  
  ThreadPool::ThreadPoolAsynchronousIOItem& item = *((ThreadPool::ThreadPoolAsynchronousIOItem*)this->item);
  item.unregistered = true;
  return waitObject.Signal();
}
