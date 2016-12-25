#include "../../../../Includes/Pcf/System/Threading/Thread.h"
#include "../../../../Includes/Pcf/System/Environment.h"

#if _WIN32
#pragma warning(push)
#pragma warning(disable: 4201)
#include <windows.h>
#pragma warning(pop)
#else
#include <cmath>
#include <pthread.h>
#endif

using namespace System;
using namespace System::Threading;

Thread::ThreadCollection Thread::threads;
std::recursive_mutex Thread::mutex;

Thread::~Thread() {
  if (Enum<System::Threading::ThreadState>(this->data->state).HasFlag(ThreadState::Background)) {
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

void Thread::ThreadItem::RunWithOrWithoutParam(const object* obj, bool withParam) {
  auto endThread = pcf_delegate {
    this->state |= System::Threading::ThreadState::Stopped;
    this->endThreadEvent.Set();
    if (Enum<System::Threading::ThreadState>(this->state).HasFlag(System::Threading::ThreadState::Background)) {
      std::lock_guard<std::recursive_mutex> lock(mutex);
      for (int i = 0; i < threads.Count; i++) {
        if (threads[i].data->managedThreadId == this->managedThreadId) {
          threads.RemoveAt(i);
          break;
        }
      }
    }
  };

  try {
    this->SetNameThreadForDebugger();
    if (Enum<System::Threading::ThreadState>(this->state).HasFlag(ThreadState::Background) && this->thread.joinable()) {
      this->detachedThreadId = this->thread.get_id();
      this->thread.detach();
    }
    if (this->priority != ThreadPriority::Normal)
      SetPriority();
    if (withParam)
      this->parameterizedThreadStart(*obj);
    else
      this->threadStart();
    endThread();
  } catch(...) {
    endThread();
    throw;
  }
}

#if _WIN32
namespace {
  // https://msdn.microsoft.com/en-us/library/xcb2z8hs.aspx
  void SetThreadName(DWORD dwThreadID, const char* threadName) {
#pragma pack(push, 8)
    struct THREADNAME_INFO {
      DWORD dwType;
      LPCSTR szName;
      DWORD dwThreadID;
      DWORD dwFlags;
    };
#pragma pack(pop)

#pragma warning(push)
#pragma warning(disable: 6320 6322)
    __try {
      THREADNAME_INFO info {0x1000, threadName, dwThreadID, 0};
      RaiseException(0x406D1388, 0, sizeof(info) / sizeof(ULONG_PTR), (ULONG_PTR*)&info);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
    }
#pragma warning(pop)
  }
}
#endif

void Thread::ThreadItem::SetNameThreadForDebugger() {
  Action<string> currentName = pcf_delegate(string n) {
#if _WIN32
#pragma warning(push)
#pragma warning(disable: 4302 4311)
    ::SetThreadName(GetCurrentThreadId(), n.Data());
#pragma warning(pop)
#elif __APPLE__
    pthread_setname_np(n.Data());
#else
    pthread_setname_np(pthread_self(), n.Data());
#endif
  };
  currentName(this->name);
}

bool Thread::ThreadItem::SetPriority() {
  return SetPriority(this->thread.native_handle(), this->priority);
}

bool Thread::ThreadItem::SetPriority(Thread::NativeHandle handle, ThreadPriority priority) {
  Func<NativeHandle, ThreadPriority, bool> setPriority = pcf_delegate(NativeHandle handle, ThreadPriority p) {
#if _WIN32
    return SetThreadPriority(handle, (int)p - 2) != FALSE;
#else
    int32 policy;
    sched_param schedParam;
    if (::pthread_getschedparam(handle, &policy, &schedParam) != 0)
      return false;
    
    schedParam.sched_priority = (int32)ceil(((double)p * (sched_get_priority_max(policy) - sched_get_priority_min(policy)) / 4) + sched_get_priority_min(policy));
    return pthread_setschedparam(handle, policy, &schedParam) == 0;
#endif
  };
  return setPriority(handle, priority);
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
#if _WIN32
    return TerminateThread(this->data->thread.native_handle(), -1) != FALSE;
#else
    return pthread_cancel(this->data->thread.native_handle()) == 0;
#endif
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
  
  Action<NativeHandle> resume = pcf_delegate(NativeHandle handle) {
#if _WNI32
    ResumeThread(handle)
#else
    // The POSIX standard provides no mechanism by which a thread A can suspend the execution of another thread B, without cooperation from B. The only way to implement a suspend/resume mechanism is to have B check periodically some global variable for a suspend request and then suspend itself on a condition variable, which another thread can signal later to restart B.
#endif
  };
  
  resume(this->data->thread.native_handle());
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
  
  Func<ThreadPriority, bool> setCurrentPriority = pcf_delegate(ThreadPriority p) {
#if _WIN32
    return ThreadItem::SetPriority(GetCurrentThread(), p);
#else
    return ThreadItem::SetPriority(pthread_self(), p);
#endif
  };
  
  if (this->data->managedThreadId == MainManagedThreadId && CurrentThread().ManagedThreadId == MainManagedThreadId) {
    if (setCurrentPriority(priority) != true)
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
  
  Action<NativeHandle> suspend = pcf_delegate(NativeHandle handle) {
#if _WNI32
    SuspendThread(handle)
#else
    // The POSIX standard provides no mechanism by which a thread A can suspend the execution of another thread B, without cooperation from B. The only way to implement a suspend/resume mechanism is to have B check periodically some global variable for a suspend request and then suspend itself on a condition variable, which another thread can signal later to restart B.
#endif
  };
  
  this->data->state |= System::Threading::ThreadState::SuspendRequested;
  suspend(this->data->thread.native_handle());
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
