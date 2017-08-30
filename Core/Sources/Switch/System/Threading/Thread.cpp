#include "../../../../Includes/Switch/System/Threading/Thread.hpp"
#include "../../../../Includes/Switch/System/Environment.hpp"
#include "../../../__OS/CoreApi.hpp"

using namespace System;
using namespace System::Threading;

Thread::ThreadCollection Thread::threads;
std::recursive_mutex Thread::mutex;

void Thread::ThreadItem::RunWithOrWithoutParam(const object* obj, bool withParam) {
  this->SetNameThreadForDebugger();
  if (Enum<System::Threading::ThreadState>(this->state).HasFlag(System::Threading::ThreadState::Background) && this->thread.joinable()) {
    if (this->thread.joinable()) {
      this->detachedThreadId = this->thread.get_id();
      this->thread.detach();
    }
  }
  if (this->priority != ThreadPriority::Normal)
    SetPriority();
  if (withParam)
    this->parameterizedThreadStart(*obj);
  else
    this->threadStart();
  
  this->state |= System::Threading::ThreadState::Stopped;
  this->endThreadEvent.Set();
  if (Enum<System::Threading::ThreadState>(this->state).HasFlag(System::Threading::ThreadState::Background)) {
    if (this->thread.joinable()) {
      this->detachedThreadId = this->thread.get_id();
      this->thread.detach();
    }
    std::lock_guard<std::recursive_mutex> lock(mutex);
    for (int i = 0; i < threads.Count; i++) {
      if (threads[i].data->managedThreadId == this->managedThreadId) {
        threads.RemoveAt(i);
        break;
      }
    }
  }
}

void Thread::ThreadItem::SetNameThreadForDebugger() {
  __OS::CoreApi::Thread::SetNameOfCurrentThread(this->name);
}

bool Thread::ThreadItem::SetPriority() {
  return SetPriority(this->thread.native_handle(), this->priority);
}

bool Thread::ThreadItem::SetPriority(Thread::NativeHandle handle, ThreadPriority priority) {
  return __OS::CoreApi::Thread::SetPriority((intptr)handle, (int32)priority);
}

Property<Thread&, ReadOnly> Thread::CurrentThread {
  []()->Thread& {return Thread::__CurrentThread__();}
};

void Thread::Abort() {
  if (this->data->managedThreadId == NoneManagedThreadId)
    throw InvalidOperationException(pcf_current_information);
  
  if (Enum<System::Threading::ThreadState>(this->data->state).HasFlag(System::Threading::ThreadState::Unstarted) || Enum<System::Threading::ThreadState>(this->data->state).HasFlag(System::Threading::ThreadState::Suspended))
    throw ThreadStateException(pcf_current_information);
  
  this->data->state |= System::Threading::ThreadState::AbortRequested;
  
  if (this->data->managedThreadId == MainManagedThreadId && CurrentThread().MainManagedThreadId == MainManagedThreadId)
    Environment::Exit(0);
  
  if (Cancel() == true) {
    this->data->state |= System::Threading::ThreadState::Aborted;
    this->data->state &= ~System::Threading::ThreadState::AbortRequested;
    this->data->endThreadEvent.Set();
    throw ThreadAbortException(pcf_current_information);
  }
}

bool Thread::Cancel() {
  return __OS::CoreApi::Thread::Cancel((intptr)this->data->thread.native_handle());
}

void Thread::Close() {
  if (Enum<System::Threading::ThreadState>(this->data->state).HasFlag(System::Threading::ThreadState::Background)) {
    if (this->data->thread.joinable()) {
      this->data->detachedThreadId = this->data->thread.get_id();
      this->data->thread.detach();
    }
  } else if (this->data->managedThreadId != NoneManagedThreadId && this->data->managedThreadId != MainManagedThreadId && !Enum<System::Threading::ThreadState>(this->data->state).HasFlag(System::Threading::ThreadState::Unstarted) && this->data.GetUseCount() == 2) {
    int32 managedThreadId = this->data->managedThreadId;
    this->Join();
    this->data.Reset();
    std::lock_guard<std::recursive_mutex> lock(mutex);
    for (int i = 0; i < threads.Count; i++) {
      if (threads[i].data->managedThreadId == managedThreadId) {
        threads.RemoveAt(i);
        break;
      }
    }
  }
}

bool Thread::DoWait(WaitHandle& waitHandle, int32 millisecondsTimeOut) {
  if (millisecondsTimeOut < -1)
    throw ArgumentException(pcf_current_information);
  
  CurrentThread().data->state |= System::Threading::ThreadState::WaitSleepJoin;
  if (CurrentThread().data->interrupted)
    CurrentThread().Interrupt();
  bool result = false;
  try {
    result = waitHandle.Wait(millisecondsTimeOut);
    CurrentThread().data->state &= ~System::Threading::ThreadState::WaitSleepJoin;
    return result;
  } catch(...) {
    CurrentThread().data->state &= ~System::Threading::ThreadState::WaitSleepJoin;
    throw;
  }
  return result;
}

void Thread::Interrupt() {
  if (this->data->managedThreadId == NoneManagedThreadId || this->data->managedThreadId == MainManagedThreadId)
    throw InvalidOperationException(pcf_current_information);
  
  if (Enum<System::Threading::ThreadState>(this->data->state).HasFlag(System::Threading::ThreadState::Unstarted))
    throw ThreadStateException(pcf_current_information);
  
  if (Enum<System::Threading::ThreadState>(this->data->state).HasFlag(System::Threading::ThreadState::WaitSleepJoin) && Cancel() == true) {
    this->data->state &= ~System::Threading::ThreadState::WaitSleepJoin;
    this->data->interrupted = false;
    this->data->endThreadEvent.Set();
    throw ThreadInterruptedException(pcf_current_information);
  }
  
  this->data->interrupted = true;
}

void Thread::Resume() {
  if (this->data->managedThreadId == NoneManagedThreadId || this->data->managedThreadId == MainManagedThreadId)
    throw InvalidOperationException(pcf_current_information);
  if (!Enum<System::Threading::ThreadState>(this->data->state).HasFlag(System::Threading::ThreadState::Suspended))
    throw ThreadStateException(pcf_current_information);
  
  __OS::CoreApi::Thread::Resume((intptr)this->data->thread.native_handle());
  this->data->state &= ~System::Threading::ThreadState::Suspended;
}

void Thread::SetName(const string &name) {
  if (!this->data->name.IsEmpty())
    throw InvalidOperationException(pcf_current_information);
  
  this->data->name = name;
  if (this->data->managedThreadId == CurrentThread().ManagedThreadId)
    this->data->SetNameThreadForDebugger();
}

void Thread::SetPriority(ThreadPriority priority) {
  if (Enum<System::Threading::ThreadState>(this->data->state).HasFlag(System::Threading::ThreadState::Aborted) || Enum<System::Threading::ThreadState>(this->data->state).HasFlag(System::Threading::ThreadState::Stopped))
    throw ThreadStateException(pcf_current_information);
  
  this->data->priority = priority;
  if (this->data->managedThreadId == MainManagedThreadId && CurrentThread().ManagedThreadId == MainManagedThreadId) {
    if (ThreadItem::SetPriority((Thread::NativeHandle)__OS::CoreApi::Thread::GetCurrent(), priority) != true)
      throw ThreadStateException(pcf_current_information);
    return;
  }
  
  if (!Enum<System::Threading::ThreadState>(this->data->state).HasFlag(System::Threading::ThreadState::Unstarted) && this->data->SetPriority() != true)
    throw ThreadStateException(pcf_current_information);
}

void Thread::Suspend() {
  if (this->data->managedThreadId == NoneManagedThreadId || this->data->managedThreadId == MainManagedThreadId)
    throw InvalidOperationException(pcf_current_information);
  if (!this->IsAlive())
    throw ThreadStateException(pcf_current_information);
  
  this->data->state |= System::Threading::ThreadState::SuspendRequested;
  __OS::CoreApi::Thread::Suspend((intptr)this->data->thread.native_handle());
  this->data->state |= System::Threading::ThreadState::Suspended;
  this->data->state &= ~System::Threading::ThreadState::SuspendRequested;
}

Thread& Thread::__CurrentThread__() {
  ThreadId id = std::this_thread::get_id();
  std::lock_guard<std::recursive_mutex> lock(mutex);
  for (auto& item : threads) {
    if (item.data->thread.get_id() == id || item.data->detachedThreadId == id || item.data->mainThreadId == id)
      return item;
  }
  
  static Thread thread;
  thread.data->state &= ~System::Threading::ThreadState::Unstarted;
  thread.data->state |= System::Threading::ThreadState::Background;
  return thread;
}
