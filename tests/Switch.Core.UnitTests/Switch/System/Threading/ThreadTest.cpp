#include <Switch/System/Threading/Timer.hpp>
#include <Switch/System/Threading/AutoResetEvent.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Threading;
using namespace TUnit;

namespace {
  class ThreadTest : public TestFixture {
  protected:
    static bool hasMainThreadNamedOnlyOnce;

    void GetMainThreadThenGetManagedThreadId() {
      Thread thread = Thread::CurrentThread();
      Assert::AreEqual(1, thread.ManagedThreadId, _caller);
    }
    
    void GetMainThreadThenGetHandle() {
      Thread thread = Thread::CurrentThread();
      Assert::AreNotEqual(intptr(-1), thread.Handle, _caller);
    }
    
    void GetMainThreadThenIsAlive() {
      Thread thread = Thread::CurrentThread();
      Assert::True(thread.IsAlive, _caller);
    }
    
    void GetMainThreadThenIsBackground() {
      Thread thread = Thread::CurrentThread();
      Assert::False(thread.IsBackground, _caller);
    }
    
    void GetMainThreadThenGetName() {
      Thread thread = Thread::CurrentThread();
      if (!hasMainThreadNamedOnlyOnce)
        Assert::AreEqual("", thread.Name, _caller);
      else
        Assert::AreEqual("Main", thread.Name, _caller);
    }
    
    void GetMainThreadThenGetPriority() {
      Thread thread = Thread::CurrentThread();
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, _caller);
    }
    
    void GetMainThreadThenGetThreadState() {
      Thread thread = Thread::CurrentThread();
      Assert::AreEqual(ThreadState::Running, thread.ThreadState(), _caller);
    }
    
    void GetMainThreadThenSetName() {
      Thread thread = Thread::CurrentThread();
      if (!hasMainThreadNamedOnlyOnce) {
        Assert::AreEqual("", thread.Name, _caller);
        Assert::DoesNotThrows(_delegate {thread.Name = "Main";}, _caller);
        Assert::AreEqual("Main", thread.Name, _caller);
        hasMainThreadNamedOnlyOnce = true;
      } else {
        Assert::AreEqual("Main", thread.Name, _caller);
        Assert::Throws<InvalidOperationException>(_delegate {thread.Name = "";}, _caller);
      }
    }
    
    void GetMainThreadThenSetPriority() {
      Thread thread = Thread::CurrentThread();
      Assert::DoesNotThrows(_delegate {thread.Priority = ThreadPriority::AboveNormal;}, _caller);
      Assert::AreEqual(ThreadPriority::AboveNormal, thread.Priority, _caller);
      Assert::DoesNotThrows(_delegate {thread.Priority = ThreadPriority::Normal;}, _caller);
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, _caller);
    }
    
    void GetMainThreadThenAbort() {
      Thread thread = Thread::CurrentThread();
      // If you uncomments the next line, the unit tests will be aborted ;-)
      //Assert::DoesNotThrows(_delegate {thread.Abort();}, _caller);
    }
    
    void GetMainThreadThenSetIsBackgroundToTrue() {
      Thread thread = Thread::CurrentThread();
      Assert::Throws<InvalidOperationException>(_delegate {thread.IsBackground = true;}, _caller);
    }
    
    void GetMainThreadThenGetHashCode() {
      Thread thread = Thread::CurrentThread();
      Assert::AreEqual(1, thread.GetHashCode(), _caller);
    }
    
    void GetMainThreadThenInterrupt() {
      Thread thread = Thread::CurrentThread();
      Assert::Throws<InvalidOperationException>(_delegate {thread.Interrupt();}, _caller);
    }
    
    void GetMainThreadThenJoin() {
      Thread thread = Thread::CurrentThread();
      Assert::Throws<InvalidOperationException>(_delegate {thread.Join();}, _caller);
    }
    
    void GetMainThreadThenJoinWithBadTimeout() {
      Thread thread = Thread::CurrentThread();
      Assert::Throws<InvalidOperationException>(_delegate {thread.Join(-2);}, _caller);
    }
    
    void GetMainThreadThenJoinWithInfiniteTimeout() {
      Thread thread = Thread::CurrentThread();
      Assert::Throws<InvalidOperationException>(_delegate {thread.Join(Timeout::Infinite);}, _caller);
    }
    
    void GetMainThreadThenJoinWithTimeout() {
      Thread thread = Thread::CurrentThread();
      Assert::Throws<InvalidOperationException>(_delegate {thread.Join(1);}, _caller);
    }
    
    void GetMainThreadThenResume() {
      Thread thread = Thread::CurrentThread();
      Assert::Throws<InvalidOperationException>(_delegate {thread.Resume();}, _caller);
    }
    
    void GetMainThreadThenStart() {
      Thread thread = Thread::CurrentThread();
      Assert::Throws<ThreadStateException>(_delegate {thread.Start();}, _caller);
    }
    
    void GetMainThreadThenStartWithThreadStart() {
      Thread thread = Thread::CurrentThread();
      ThreadStart threadStart = _delegate {};
      Assert::Throws<ThreadStateException>(_delegate {thread.Start(threadStart);}, _caller);
    }
    
    void GetMainThreadThenStartWithParameterizedThreadStart() {
      Thread thread = Thread::CurrentThread();
      ParameterizedThreadStart parameterizedTeadStart = _delegate(const object&) {};
      Assert::Throws<ThreadStateException>(_delegate {thread.Start(parameterizedTeadStart);}, _caller);
    }
    
    void GetMainThreadThenSuspend() {
      Thread thread = Thread::CurrentThread();
      Assert::Throws<InvalidOperationException>(_delegate {thread.Suspend();}, _caller);
    }
    
    void CreateUnmanagedThreadThenGetManagedThreadId() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::AreEqual(0, thread.ManagedThreadId, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenGetHandle() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::AreEqual(intptr(-1), thread.Handle, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenIsAlive() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::True(thread.IsAlive, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenIsBackground() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::True(thread.IsBackground);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenGetName() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::AreEqual("", thread.Name);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenGetPriority() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::AreEqual(ThreadPriority::Normal, thread.Priority, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenGetThreadState() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::AreEqual(ThreadState::Running, thread.ThreadState() & ThreadState::Running, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenSetName() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::Throws<InvalidOperationException>(_delegate {thread.Name = "Unmanaged";}, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenSetPriority() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::Throws<InvalidOperationException>(_delegate {thread.Priority = ThreadPriority::Highest;}, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenAbort() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::Throws<InvalidOperationException>(_delegate {thread.Abort();}, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenSetIsBackgroundToTrue() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::Throws<InvalidOperationException>(_delegate {thread.IsBackground = true;}, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenGetHashCode() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::AreEqual(0, thread.GetHashCode(), _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenInterrupt() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::Throws<InvalidOperationException>(_delegate {thread.Interrupt();}, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenJoin() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::Throws<InvalidOperationException>(_delegate {thread.Join();}, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenJoinWithBadTimeout() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::Throws<InvalidOperationException>(_delegate {thread.Join(-2);}, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenJoinWithInfiniteTimeout() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::Throws<InvalidOperationException>(_delegate {thread.Join(Timeout::Infinite);}, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenJoinWithTimeout() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::Throws<InvalidOperationException>(_delegate {thread.Join(1);}, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenResume() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::Throws<InvalidOperationException>(_delegate {thread.Resume();}, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenStart() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::Throws<ThreadStateException>(_delegate {thread.Start();}, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenStartWithThreadStart() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        ThreadStart threadStart = _delegate {};
        Assert::Throws<ThreadStateException>(_delegate {thread.Start(threadStart);}, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenStartWithParameterizedThreadStart() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        ParameterizedThreadStart parameterizedTeadStart = _delegate(const object&) {};
        Assert::Throws<ThreadStateException>(_delegate {thread.Start(parameterizedTeadStart);}, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenSuspend() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread();
        Assert::Throws<InvalidOperationException>(_delegate {thread.Suspend();}, _caller);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateEmptyThreadThenGetManagedThreadId() {
      Thread thread;
      Assert::AreEqual(0, thread.ManagedThreadId, _caller);
    }
    
    void CreateEmptyThreadThenGetHandle() {
      Thread thread;
      Assert::AreEqual(intptr(-1), thread.Handle, _caller);
    }
    
    void CreateEmptyThreadThenIsAlive() {
      Thread thread;
      Assert::False(thread.IsAlive, _caller);
    }
    
    void CreateEmptyThreadThenIsBackground() {
      Thread thread;
      Assert::False(thread.IsBackground, _caller);
    }
    
    void CreateEmptyThreadThenGetName() {
      Thread thread;
      Assert::AreEqual("", thread.Name, _caller);
    }
    
    void CreateEmptyThreadThenGetPriority() {
      Thread thread;
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, _caller);
    }
    
    void CreateEmptyThreadThenGetThreadState() {
      Thread thread;
      Assert::AreEqual(ThreadState::Unstarted, thread.ThreadState, _caller);
    }
    
    void CreateEmptyThreadThenSetName() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Name = "Empty";}, _caller);
    }
    
    void CreateEmptyThreadThenSetPriority() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Priority = ThreadPriority::Highest;}, _caller);
    }
    
    void CreateEmptyThreadThenAbort() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Abort();}, _caller);
    }
    
    void CreateEmptyThreadThenSetIsBackgroundToTrue() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.IsBackground = true;}, _caller);
    }
    
    void CreateEmptyThreadThenGetHashCode() {
      Thread thread;
      Assert::AreEqual(0, thread.GetHashCode(), _caller);
    }
    
    void CreateEmptyThreadThenInterrupt() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Interrupt();}, _caller);
    }
    
    void CreateEmptyThreadThenJoin() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Join();}, _caller);
    }
    
    void CreateEmptyThreadThenJoinWithBadTimeout() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Join(-2);}, _caller);
    }
    
    void CreateEmptyThreadThenJoinWithInfiniteTimeout() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Join(Timeout::Infinite);}, _caller);
    }
    
    void CreateEmptyThreadThenJoinWithTimeout() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Join(1);}, _caller);
    }
    
    void CreateEmptyThreadThenResume() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Resume();}, _caller);
    }
    
    void CreateEmptyThreadThenStart() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Start();}, _caller);
    }
    
    void CreateEmptyThreadThenStartWithThreadStart() {
      Thread thread;
      object obj;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Start(obj);}, _caller);
    }
    
    void CreateEmptyThreadThenStartWithParameterizedThreadStart() {
      Thread thread;
      object obj;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Start(obj);}, _caller);
    }
    
    void CreateEmptyThreadThenSuspend() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Suspend();}, _caller);
    }
    
    void CreateThreadWithThreadStartThenGetManagedThreadId() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Greater(thread.ManagedThreadId, 1, _caller);
    }
    
    void CreateThreadWithThreadStartThenGetHandle() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreNotEqual(intptr(-1), thread.Handle, _caller);
    }
    
    void CreateThreadWithThreadStartThenIsAlive() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::False(thread.IsAlive, _caller);
    }
    
    void CreateThreadWithThreadStartStartItThenIsAlive() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        Thread::Sleep(10);
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::True(thread.IsAlive, _caller);
    }
    
    void CreateThreadWithThreadStartThenIsBackground() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::False(thread.IsBackground, _caller);
    }
    
    void CreateThreadWithThreadStartThenGetName() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreEqual("", thread.Name, _caller);
    }
    
    void CreateThreadWithThreadStartThenGetPriority() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, _caller);
    }
    
    void CreateThreadWithThreadStartThenGetThreadState() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreEqual(ThreadState::Unstarted, thread.ThreadState, _caller);
    }
    
    void CreateThreadWithThreadStartThenSetName() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::DoesNotThrows(_delegate {thread.Name = "Thread";}, _caller);
      Assert::AreEqual("Thread", thread.Name);
    }
    
    void CreateThreadWithThreadStartThenSetPriority() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::DoesNotThrows(_delegate {thread.Priority = ThreadPriority::Highest;}, _caller);
      Assert::AreEqual(ThreadPriority::Highest, thread.Priority);
    }
    
    void CreateThreadWithThreadStartThenAbort() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Abort();}, _caller);
      Assert::AreEqual(0, counter, _caller);
    }
    
    void CreateThreadWithThreadStartStartItThenAbort() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        Thread::Sleep(100);
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Thread::Sleep(5);
      Assert::Throws<ThreadAbortException>(_delegate {thread.Abort();}, _caller);
      Assert::AreEqual(0, counter, _caller);
    }
    
    void CreateThreadWithThreadStartThenSetIsBackgroundToTrue() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::DoesNotThrows(_delegate {thread.IsBackground = true;}, _caller);
    }
    
    void CreateThreadWithThreadStartThenGetHashCode() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreEqual(thread.ManagedThreadId, thread.GetHashCode(), _caller);
    }
    
    void CreateThreadWithThreadStartThenInterrupt() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Interrupt();}, _caller);
    }
    
    void CreateThreadWithThreadStartStartItThenInterrupt() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        Thread::Sleep(100);
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Thread::Sleep(5);
      Assert::Throws<ThreadInterruptedException>(_delegate {thread.Interrupt();}, _caller);
    }
    
    void CreateThreadWithThreadStartThenSuspend() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Suspend();}, _caller);
    }
    
    void CreateThreadWithThreadStartThenResume() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Resume();}, _caller);
    }
    
    void CreateThreadWithThreadStartStartItThenResume() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::Throws<ThreadStateException>(_delegate {thread.Resume();}, _caller);
    }
    
    void CreateThreadWithThreadStartStartItSuspendThenResume() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        Thread::Sleep(10);
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      thread.Suspend();
      Assert::DoesNotThrows(_delegate {thread.Resume();}, _caller);
    }
    
    void CreateThreadWithThreadStartThenStart() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::DoesNotThrows(_delegate {thread.Start();}, _caller);
    }
    
    void CreateThreadWithThreadStartThenStartWithParameterizedThreadStart() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      ParameterizedThreadStart parameterizedTeadStart = _delegate(const object&) {};
      Assert::Throws<InvalidOperationException>(_delegate {thread.Start(parameterizedTeadStart);}, _caller);
    }
    
    void CreateThreadWithThreadStartThenJoin() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Join();}, _caller);
     }
    
    void CreateThreadWithThreadStartStartItThenJoin() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::DoesNotThrows(_delegate {thread.Join();}, _caller);
      Assert::AreEqual(1, counter, _caller);
    }
    
    void CreateThreadWithThreadStartThenJoinWithBadTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Join(-2);}, _caller);
    }
    
    void CreateThreadWithThreadStartStartItThenJoinWithBadTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {thread.Join(-2);}, _caller);
    }
    
    void CreateThreadWithThreadStartThenJoinWithInfiniteTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::DoesNotThrows(_delegate {thread.Join(Timeout::Infinite);}, _caller);
      Assert::AreEqual(1, counter, _caller);
    }
    
    void CreateThreadWithThreadStartThenJoinWithTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Join(5);}, _caller);
    }
    
    void CreateThreadWithThreadStartStartItThenJoinWithTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::True(thread.Join(5), _caller);
      Assert::AreEqual(1, counter, _caller);
   }
    
    void CreateThreadWithThreadStartStartItThenJoinWithTimeSpanTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::True(thread.Join(TimeSpan::FromMilliseconds(5)), _caller);
      Assert::AreEqual(1, counter, _caller);
    }
    
    void CreateThreadWithThreadStartStartItThenJoinWithToShortTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        Thread::Sleep(20);
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::False(thread.Join(2), _caller);
      Assert::AreEqual(0, counter, _caller);
    }
    
    void CreateThreadWithThreadStartStartItThenJoinWithToShortTimeSpanTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        Thread::Sleep(20);
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::False(thread.Join(TimeSpan::FromMilliseconds(2)), _caller);
      Assert::AreEqual(0, counter, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetManagedThreadId() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::Greater(thread.ManagedThreadId, 1, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetHandle() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreNotEqual(intptr(-1), thread.Handle, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenIsAlive() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::False(thread.IsAlive, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenIsAlive() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Thread::Sleep(10);
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::True(thread.IsAlive, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenIsBackground() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::False(thread.IsBackground, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetName() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreEqual("", thread.Name, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetPriority() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetThreadState() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreEqual(ThreadState::Unstarted, thread.ThreadState, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenSetName() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(_delegate {thread.Name = "Thread";}, _caller);
      Assert::AreEqual("Thread", thread.Name);
    }
    
    void CreateThreadWithParameterizedThreadStartThenSetPriority() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(_delegate {thread.Priority = ThreadPriority::Highest;}, _caller);
      Assert::AreEqual(ThreadPriority::Highest, thread.Priority);
    }
    
    void CreateThreadWithParameterizedThreadStartThenAbort() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Abort();}, _caller);
      Assert::AreEqual(0, counter, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenAbort() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Thread::Sleep(100);
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Thread::Sleep(5);
      Assert::Throws<ThreadAbortException>(_delegate {thread.Abort();}, _caller);
      Assert::AreEqual(0, counter, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenSetIsBackgroundToTrue() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(_delegate {thread.IsBackground = true;}, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetHashCode() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreEqual(thread.ManagedThreadId, thread.GetHashCode(), _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenInterrupt() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Interrupt();}, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenInterrupt() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Thread::Sleep(100);
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Thread::Sleep(5);
      Assert::Throws<ThreadInterruptedException>(_delegate {thread.Interrupt();}, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenSuspend() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Suspend();}, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenResume() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Resume();}, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenResume() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::Throws<ThreadStateException>(_delegate {thread.Resume();}, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItSuspendThenResume() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Thread::Sleep(10);
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      thread.Suspend();
      Assert::DoesNotThrows(_delegate {thread.Resume();}, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenStart() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::IsInstanceOfType<Thread>(param, _caller);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(_delegate {thread.Start();}, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenStartWithThreadStart() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(_delegate {thread.Start(counter);}, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenJoin() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Join();}, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoin() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::DoesNotThrows(_delegate {thread.Join();}, _caller);
      Assert::AreEqual(0, counter, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenJoinWithBadTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Join(-2);}, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithBadTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {thread.Join(-2);}, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenJoinWithInfiniteTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::DoesNotThrows(_delegate {thread.Join(Timeout::Infinite);}, _caller);
      Assert::AreEqual(0, counter, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartThenJoinWithTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Join(5);}, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::True(thread.Join(5), _caller);
      Assert::AreEqual(0, counter, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithTimeSpanTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::True(thread.Join(TimeSpan::FromMilliseconds(5)), _caller);
      Assert::AreEqual(0, counter, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithToShortTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Thread::Sleep(20);
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::False(thread.Join(2), _caller);
      Assert::AreEqual(0, counter, _caller);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithToShortTimeSpanTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Thread::Sleep(20);
        Assert::AreEqual(0, as<Int32>(param), _caller);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::False(thread.Join(TimeSpan::FromMilliseconds(2)), _caller);
      Assert::AreEqual(0, counter, _caller);
    }
  };
  
  bool ThreadTest::hasMainThreadNamedOnlyOnce = false;

  _AddTest(ThreadTest, GetMainThreadThenGetManagedThreadId)
  _AddTest(ThreadTest, GetMainThreadThenGetHandle)
  _AddTest(ThreadTest, GetMainThreadThenIsAlive)
  _AddTest(ThreadTest, GetMainThreadThenIsBackground)
  _AddTest(ThreadTest, GetMainThreadThenGetName)
  _AddTest(ThreadTest, GetMainThreadThenGetPriority)
  _AddTest(ThreadTest, GetMainThreadThenGetThreadState)
  _AddTest(ThreadTest, GetMainThreadThenSetName)
  _AddTest(ThreadTest, GetMainThreadThenSetPriority)
  _AddTest(ThreadTest, GetMainThreadThenAbort)
  _AddTest(ThreadTest, GetMainThreadThenSetIsBackgroundToTrue)
  _AddTest(ThreadTest, GetMainThreadThenGetHashCode)
  _AddTest(ThreadTest, GetMainThreadThenInterrupt)
  _AddTest(ThreadTest, GetMainThreadThenJoin)
  _AddTest(ThreadTest, GetMainThreadThenJoinWithBadTimeout)
  _AddTest(ThreadTest, GetMainThreadThenJoinWithInfiniteTimeout)
  _AddTest(ThreadTest, GetMainThreadThenJoinWithTimeout)
  _AddTest(ThreadTest, GetMainThreadThenResume)
  _AddTest(ThreadTest, GetMainThreadThenStart)
  _AddTest(ThreadTest, GetMainThreadThenStartWithThreadStart)
  _AddTest(ThreadTest, GetMainThreadThenStartWithParameterizedThreadStart)
  _AddTest(ThreadTest, GetMainThreadThenSuspend)
  
  _AddTest(ThreadTest, CreateUnmanagedThreadThenGetManagedThreadId)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenGetHandle)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenIsAlive)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenIsBackground)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenGetName)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenGetPriority)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenGetThreadState)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenSetName)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenSetPriority)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenAbort)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenSetIsBackgroundToTrue)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenGetHashCode)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenInterrupt)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenJoin)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenJoinWithBadTimeout)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenJoinWithInfiniteTimeout)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenJoinWithTimeout)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenResume)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenStart)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenStartWithThreadStart)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenStartWithParameterizedThreadStart)
  _AddTest(ThreadTest, CreateUnmanagedThreadThenSuspend)
  
  _AddTest(ThreadTest, CreateEmptyThreadThenGetManagedThreadId)
  _AddTest(ThreadTest, CreateEmptyThreadThenGetHandle)
  _AddTest(ThreadTest, CreateEmptyThreadThenIsAlive)
  _AddTest(ThreadTest, CreateEmptyThreadThenIsBackground)
  _AddTest(ThreadTest, CreateEmptyThreadThenGetName)
  _AddTest(ThreadTest, CreateEmptyThreadThenGetPriority)
  _AddTest(ThreadTest, CreateEmptyThreadThenGetThreadState)
  _AddTest(ThreadTest, CreateEmptyThreadThenSetName)
  _AddTest(ThreadTest, CreateEmptyThreadThenSetPriority)
  _AddTest(ThreadTest, CreateEmptyThreadThenAbort)
  _AddTest(ThreadTest, CreateEmptyThreadThenSetIsBackgroundToTrue)
  _AddTest(ThreadTest, CreateEmptyThreadThenGetHashCode)
  _AddTest(ThreadTest, CreateEmptyThreadThenInterrupt)
  _AddTest(ThreadTest, CreateEmptyThreadThenJoin)
  _AddTest(ThreadTest, CreateEmptyThreadThenJoinWithBadTimeout)
  _AddTest(ThreadTest, CreateEmptyThreadThenJoinWithInfiniteTimeout)
  _AddTest(ThreadTest, CreateEmptyThreadThenJoinWithTimeout)
  _AddTest(ThreadTest, CreateEmptyThreadThenResume)
  _AddTest(ThreadTest, CreateEmptyThreadThenStart)
  _AddTest(ThreadTest, CreateEmptyThreadThenStartWithThreadStart)
  _AddTest(ThreadTest, CreateEmptyThreadThenStartWithParameterizedThreadStart)
  _AddTest(ThreadTest, CreateEmptyThreadThenSuspend)
  
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenGetManagedThreadId)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenGetHandle)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenIsAlive)
  _AddTest(ThreadTest, CreateThreadWithThreadStartStartItThenIsAlive)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenIsBackground)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenGetName)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenGetPriority)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenGetThreadState)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenSetName)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenSetPriority)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenAbort)
  _AddTest(ThreadTest, CreateThreadWithThreadStartStartItThenAbort)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenSetIsBackgroundToTrue)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenGetHashCode)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenInterrupt)
  _AddTest(ThreadTest, CreateThreadWithThreadStartStartItThenInterrupt)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenSuspend)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenResume)
  _AddTest(ThreadTest, CreateThreadWithThreadStartStartItThenResume)
  _AddTest(ThreadTest, CreateThreadWithThreadStartStartItSuspendThenResume)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenStart)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenStartWithParameterizedThreadStart)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenJoin)
  _AddTest(ThreadTest, CreateThreadWithThreadStartStartItThenJoin)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenJoinWithBadTimeout)
  _AddTest(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithBadTimeout)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenJoinWithInfiniteTimeout)
  _AddTest(ThreadTest, CreateThreadWithThreadStartThenJoinWithTimeout)
  _AddTest(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithTimeout)
  _AddTest(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithTimeSpanTimeout)
  _AddTest(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithToShortTimeout)
  _AddTest(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithToShortTimeSpanTimeout)
  
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetManagedThreadId)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetHandle)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenIsAlive)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenIsAlive)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenIsBackground)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetName)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetPriority)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetThreadState)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenSetName)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenSetPriority)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenAbort)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenAbort)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenSetIsBackgroundToTrue)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetHashCode)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenInterrupt)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenInterrupt)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenSuspend)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenResume)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenResume)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartStartItSuspendThenResume)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenStart)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenStartWithThreadStart)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoin)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoin)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoinWithBadTimeout)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithBadTimeout)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoinWithInfiniteTimeout)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoinWithTimeout)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithTimeout)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithTimeSpanTimeout)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithToShortTimeout)
  _AddTest(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithToShortTimeSpanTimeout)
}

