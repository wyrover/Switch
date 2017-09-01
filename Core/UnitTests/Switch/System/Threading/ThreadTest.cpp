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
      Thread thread = Thread::CurrentThread;
      Assert::AreEqual(1, thread.ManagedThreadId, _current_information);
    }
    
    void GetMainThreadThenGetHandle() {
      Thread thread = Thread::CurrentThread;
      Assert::AreNotEqual(intptr(-1), thread.Handle, _current_information);
    }
    
    void GetMainThreadThenIsAlive() {
      Thread thread = Thread::CurrentThread;
      Assert::True(thread.IsAlive, _current_information);
    }
    
    void GetMainThreadThenIsBackground() {
      Thread thread = Thread::CurrentThread;
      Assert::False(thread.IsBackground, _current_information);
    }
    
    void GetMainThreadThenGetName() {
      Thread thread = Thread::CurrentThread;
      if (!hasMainThreadNamedOnlyOnce)
        Assert::AreEqual("", thread.Name, _current_information);
      else
        Assert::AreEqual("Main", thread.Name, _current_information);
    }
    
    void GetMainThreadThenGetPriority() {
      Thread thread = Thread::CurrentThread;
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, _current_information);
    }
    
    void GetMainThreadThenGetThreadState() {
      Thread thread = Thread::CurrentThread;
      Assert::AreEqual(ThreadState::Running, thread.ThreadState(), _current_information);
    }
    
    void GetMainThreadThenSetName() {
      Thread thread = Thread::CurrentThread;
      if (!hasMainThreadNamedOnlyOnce) {
        Assert::AreEqual("", thread.Name, _current_information);
        Assert::DoesNotThrows(_delegate {thread.Name = "Main";}, _current_information);
        Assert::AreEqual("Main", thread.Name, _current_information);
        hasMainThreadNamedOnlyOnce = true;
      } else {
        Assert::AreEqual("Main", thread.Name, _current_information);
        Assert::Throws<InvalidOperationException>(_delegate {thread.Name = "";}, _current_information);
      }
    }
    
    void GetMainThreadThenSetPriority() {
      Thread thread = Thread::CurrentThread;
      Assert::DoesNotThrows(_delegate {thread.Priority = ThreadPriority::AboveNormal;}, _current_information);
      Assert::AreEqual(ThreadPriority::AboveNormal, thread.Priority, _current_information);
      Assert::DoesNotThrows(_delegate {thread.Priority = ThreadPriority::Normal;}, _current_information);
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, _current_information);
    }
    
    void GetMainThreadThenAbort() {
      Thread thread = Thread::CurrentThread;
      // If you uncomments the next line, the unit tests will be aborted ;-)
      //Assert::DoesNotThrows(_delegate {thread.Abort();}, _current_information);
    }
    
    void GetMainThreadThenSetIsBackgroundToTrue() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.IsBackground = true;}, _current_information);
    }
    
    void GetMainThreadThenGetHashCode() {
      Thread thread = Thread::CurrentThread;
      Assert::AreEqual(1, thread.GetHashCode(), _current_information);
    }
    
    void GetMainThreadThenInterrupt() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Interrupt();}, _current_information);
    }
    
    void GetMainThreadThenJoin() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Join();}, _current_information);
    }
    
    void GetMainThreadThenJoinWithBadTimeout() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Join(-2);}, _current_information);
    }
    
    void GetMainThreadThenJoinWithInfiniteTimeout() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Join(Timeout::Infinite);}, _current_information);
    }
    
    void GetMainThreadThenJoinWithTimeout() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Join(1);}, _current_information);
    }
    
    void GetMainThreadThenResume() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Resume();}, _current_information);
    }
    
    void GetMainThreadThenStart() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<ThreadStateException>(_delegate {thread.Start();}, _current_information);
    }
    
    void GetMainThreadThenStartWithThreadStart() {
      Thread thread = Thread::CurrentThread;
      ThreadStart threadStart = _delegate {};
      Assert::Throws<ThreadStateException>(_delegate {thread.Start(threadStart);}, _current_information);
    }
    
    void GetMainThreadThenStartWithParameterizedThreadStart() {
      Thread thread = Thread::CurrentThread;
      ParameterizedThreadStart parameterizedTeadStart = _delegate(const object&) {};
      Assert::Throws<ThreadStateException>(_delegate {thread.Start(parameterizedTeadStart);}, _current_information);
    }
    
    void GetMainThreadThenSuspend() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Suspend();}, _current_information);
    }
    
    void CreateUnmanagedThreadThenGetManagedThreadId() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::AreEqual(0, thread.ManagedThreadId, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenGetHandle() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::AreEqual(intptr(-1), thread.Handle, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenIsAlive() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::True(thread.IsAlive, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenIsBackground() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::True(thread.IsBackground);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenGetName() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::AreEqual("", thread.Name);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenGetPriority() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::AreEqual(ThreadPriority::Normal, thread.Priority, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenGetThreadState() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::AreEqual(ThreadState::Running, thread.ThreadState() & ThreadState::Running, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenSetName() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(_delegate {thread.Name = "Unmanaged";}, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenSetPriority() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(_delegate {thread.Priority = ThreadPriority::Highest;}, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenAbort() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(_delegate {thread.Abort();}, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenSetIsBackgroundToTrue() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(_delegate {thread.IsBackground = true;}, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenGetHashCode() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::AreEqual(0, thread.GetHashCode(), _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenInterrupt() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(_delegate {thread.Interrupt();}, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenJoin() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(_delegate {thread.Join();}, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenJoinWithBadTimeout() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(_delegate {thread.Join(-2);}, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenJoinWithInfiniteTimeout() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(_delegate {thread.Join(Timeout::Infinite);}, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenJoinWithTimeout() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(_delegate {thread.Join(1);}, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenResume() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(_delegate {thread.Resume();}, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenStart() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<ThreadStateException>(_delegate {thread.Start();}, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenStartWithThreadStart() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        ThreadStart threadStart = _delegate {};
        Assert::Throws<ThreadStateException>(_delegate {thread.Start(threadStart);}, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenStartWithParameterizedThreadStart() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        ParameterizedThreadStart parameterizedTeadStart = _delegate(const object&) {};
        Assert::Throws<ThreadStateException>(_delegate {thread.Start(parameterizedTeadStart);}, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenSuspend() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(_delegate {thread.Suspend();}, _current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateEmptyThreadThenGetManagedThreadId() {
      Thread thread;
      Assert::AreEqual(0, thread.ManagedThreadId, _current_information);
    }
    
    void CreateEmptyThreadThenGetHandle() {
      Thread thread;
      Assert::AreEqual(intptr(-1), thread.Handle, _current_information);
    }
    
    void CreateEmptyThreadThenIsAlive() {
      Thread thread;
      Assert::False(thread.IsAlive, _current_information);
    }
    
    void CreateEmptyThreadThenIsBackground() {
      Thread thread;
      Assert::False(thread.IsBackground, _current_information);
    }
    
    void CreateEmptyThreadThenGetName() {
      Thread thread;
      Assert::AreEqual("", thread.Name, _current_information);
    }
    
    void CreateEmptyThreadThenGetPriority() {
      Thread thread;
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, _current_information);
    }
    
    void CreateEmptyThreadThenGetThreadState() {
      Thread thread;
      Assert::AreEqual(ThreadState::Unstarted, thread.ThreadState, _current_information);
    }
    
    void CreateEmptyThreadThenSetName() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Name = "Empty";}, _current_information);
    }
    
    void CreateEmptyThreadThenSetPriority() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Priority = ThreadPriority::Highest;}, _current_information);
    }
    
    void CreateEmptyThreadThenAbort() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Abort();}, _current_information);
    }
    
    void CreateEmptyThreadThenSetIsBackgroundToTrue() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.IsBackground = true;}, _current_information);
    }
    
    void CreateEmptyThreadThenGetHashCode() {
      Thread thread;
      Assert::AreEqual(0, thread.GetHashCode(), _current_information);
    }
    
    void CreateEmptyThreadThenInterrupt() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Interrupt();}, _current_information);
    }
    
    void CreateEmptyThreadThenJoin() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Join();}, _current_information);
    }
    
    void CreateEmptyThreadThenJoinWithBadTimeout() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Join(-2);}, _current_information);
    }
    
    void CreateEmptyThreadThenJoinWithInfiniteTimeout() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Join(Timeout::Infinite);}, _current_information);
    }
    
    void CreateEmptyThreadThenJoinWithTimeout() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Join(1);}, _current_information);
    }
    
    void CreateEmptyThreadThenResume() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Resume();}, _current_information);
    }
    
    void CreateEmptyThreadThenStart() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Start();}, _current_information);
    }
    
    void CreateEmptyThreadThenStartWithThreadStart() {
      Thread thread;
      object obj;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Start(obj);}, _current_information);
    }
    
    void CreateEmptyThreadThenStartWithParameterizedThreadStart() {
      Thread thread;
      object obj;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Start(obj);}, _current_information);
    }
    
    void CreateEmptyThreadThenSuspend() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(_delegate {thread.Suspend();}, _current_information);
    }
    
    void CreateThreadWithThreadStartThenGetManagedThreadId() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Greater(thread.ManagedThreadId, 1, _current_information);
    }
    
    void CreateThreadWithThreadStartThenGetHandle() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreNotEqual(intptr(-1), thread.Handle, _current_information);
    }
    
    void CreateThreadWithThreadStartThenIsAlive() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::False(thread.IsAlive, _current_information);
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
      Assert::True(thread.IsAlive, _current_information);
    }
    
    void CreateThreadWithThreadStartThenIsBackground() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::False(thread.IsBackground, _current_information);
    }
    
    void CreateThreadWithThreadStartThenGetName() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreEqual("", thread.Name, _current_information);
    }
    
    void CreateThreadWithThreadStartThenGetPriority() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, _current_information);
    }
    
    void CreateThreadWithThreadStartThenGetThreadState() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreEqual(ThreadState::Unstarted, thread.ThreadState, _current_information);
    }
    
    void CreateThreadWithThreadStartThenSetName() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::DoesNotThrows(_delegate {thread.Name = "Thread";}, _current_information);
      Assert::AreEqual("Thread", thread.Name);
    }
    
    void CreateThreadWithThreadStartThenSetPriority() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::DoesNotThrows(_delegate {thread.Priority = ThreadPriority::Highest;}, _current_information);
      Assert::AreEqual(ThreadPriority::Highest, thread.Priority);
    }
    
    void CreateThreadWithThreadStartThenAbort() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Abort();}, _current_information);
      Assert::AreEqual(0, counter, _current_information);
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
      Assert::Throws<ThreadAbortException>(_delegate {thread.Abort();}, _current_information);
      Assert::AreEqual(0, counter, _current_information);
    }
    
    void CreateThreadWithThreadStartThenSetIsBackgroundToTrue() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::DoesNotThrows(_delegate {thread.IsBackground = true;}, _current_information);
    }
    
    void CreateThreadWithThreadStartThenGetHashCode() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreEqual(thread.ManagedThreadId, thread.GetHashCode(), _current_information);
    }
    
    void CreateThreadWithThreadStartThenInterrupt() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Interrupt();}, _current_information);
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
      Assert::Throws<ThreadInterruptedException>(_delegate {thread.Interrupt();}, _current_information);
    }
    
    void CreateThreadWithThreadStartThenSuspend() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Suspend();}, _current_information);
    }
    
    void CreateThreadWithThreadStartThenResume() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Resume();}, _current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenResume() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::Throws<ThreadStateException>(_delegate {thread.Resume();}, _current_information);
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
      Assert::DoesNotThrows(_delegate {thread.Resume();}, _current_information);
    }
    
    void CreateThreadWithThreadStartThenStart() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::DoesNotThrows(_delegate {thread.Start();}, _current_information);
    }
    
    void CreateThreadWithThreadStartThenStartWithParameterizedThreadStart() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      ParameterizedThreadStart parameterizedTeadStart = _delegate(const object&) {};
      Assert::Throws<InvalidOperationException>(_delegate {thread.Start(parameterizedTeadStart);}, _current_information);
    }
    
    void CreateThreadWithThreadStartThenJoin() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Join();}, _current_information);
     }
    
    void CreateThreadWithThreadStartStartItThenJoin() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::DoesNotThrows(_delegate {thread.Join();}, _current_information);
      Assert::AreEqual(1, counter, _current_information);
    }
    
    void CreateThreadWithThreadStartThenJoinWithBadTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Join(-2);}, _current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenJoinWithBadTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {thread.Join(-2);}, _current_information);
    }
    
    void CreateThreadWithThreadStartThenJoinWithInfiniteTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::DoesNotThrows(_delegate {thread.Join(Timeout::Infinite);}, _current_information);
      Assert::AreEqual(1, counter, _current_information);
    }
    
    void CreateThreadWithThreadStartThenJoinWithTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Join(5);}, _current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenJoinWithTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::True(thread.Join(5), _current_information);
      Assert::AreEqual(1, counter, _current_information);
   }
    
    void CreateThreadWithThreadStartStartItThenJoinWithTimeSpanTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = _delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::True(thread.Join(TimeSpan::FromMilliseconds(5)), _current_information);
      Assert::AreEqual(1, counter, _current_information);
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
      Assert::False(thread.Join(2), _current_information);
      Assert::AreEqual(0, counter, _current_information);
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
      Assert::False(thread.Join(TimeSpan::FromMilliseconds(2)), _current_information);
      Assert::AreEqual(0, counter, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetManagedThreadId() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::Greater(thread.ManagedThreadId, 1, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetHandle() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreNotEqual(intptr(-1), thread.Handle, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenIsAlive() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::False(thread.IsAlive, _current_information);
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
      Assert::True(thread.IsAlive, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenIsBackground() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::False(thread.IsBackground, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetName() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreEqual("", thread.Name, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetPriority() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetThreadState() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreEqual(ThreadState::Unstarted, thread.ThreadState, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenSetName() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(_delegate {thread.Name = "Thread";}, _current_information);
      Assert::AreEqual("Thread", thread.Name);
    }
    
    void CreateThreadWithParameterizedThreadStartThenSetPriority() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(_delegate {thread.Priority = ThreadPriority::Highest;}, _current_information);
      Assert::AreEqual(ThreadPriority::Highest, thread.Priority);
    }
    
    void CreateThreadWithParameterizedThreadStartThenAbort() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Abort();}, _current_information);
      Assert::AreEqual(0, counter, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenAbort() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Thread::Sleep(100);
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Thread::Sleep(5);
      Assert::Throws<ThreadAbortException>(_delegate {thread.Abort();}, _current_information);
      Assert::AreEqual(0, counter, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenSetIsBackgroundToTrue() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(_delegate {thread.IsBackground = true;}, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetHashCode() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreEqual(thread.ManagedThreadId, thread.GetHashCode(), _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenInterrupt() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Interrupt();}, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenInterrupt() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Thread::Sleep(100);
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Thread::Sleep(5);
      Assert::Throws<ThreadInterruptedException>(_delegate {thread.Interrupt();}, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenSuspend() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Suspend();}, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenResume() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Resume();}, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenResume() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::Throws<ThreadStateException>(_delegate {thread.Resume();}, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItSuspendThenResume() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Thread::Sleep(10);
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      thread.Suspend();
      Assert::DoesNotThrows(_delegate {thread.Resume();}, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenStart() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::IsInstanceOfType<Thread>(param, _current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(_delegate {thread.Start();}, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenStartWithThreadStart() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(_delegate {thread.Start(counter);}, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenJoin() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Join();}, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoin() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::DoesNotThrows(_delegate {thread.Join();}, _current_information);
      Assert::AreEqual(0, counter, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenJoinWithBadTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Join(-2);}, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithBadTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {thread.Join(-2);}, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenJoinWithInfiniteTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::DoesNotThrows(_delegate {thread.Join(Timeout::Infinite);}, _current_information);
      Assert::AreEqual(0, counter, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenJoinWithTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(_delegate {thread.Join(5);}, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::True(thread.Join(5), _current_information);
      Assert::AreEqual(0, counter, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithTimeSpanTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::True(thread.Join(TimeSpan::FromMilliseconds(5)), _current_information);
      Assert::AreEqual(0, counter, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithToShortTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Thread::Sleep(20);
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::False(thread.Join(2), _current_information);
      Assert::AreEqual(0, counter, _current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithToShortTimeSpanTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = _delegate(const object& param) {
        Thread::Sleep(20);
        Assert::AreEqual(0, as<Int32>(param), _current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::False(thread.Join(TimeSpan::FromMilliseconds(2)), _current_information);
      Assert::AreEqual(0, counter, _current_information);
    }
  };
  
  bool ThreadTest::hasMainThreadNamedOnlyOnce = false;

  _test(ThreadTest, GetMainThreadThenGetManagedThreadId)
  _test(ThreadTest, GetMainThreadThenGetHandle)
  _test(ThreadTest, GetMainThreadThenIsAlive)
  _test(ThreadTest, GetMainThreadThenIsBackground)
  _test(ThreadTest, GetMainThreadThenGetName)
  _test(ThreadTest, GetMainThreadThenGetPriority)
  _test(ThreadTest, GetMainThreadThenGetThreadState)
  _test(ThreadTest, GetMainThreadThenSetName)
  _test(ThreadTest, GetMainThreadThenSetPriority)
  _test(ThreadTest, GetMainThreadThenAbort)
  _test(ThreadTest, GetMainThreadThenSetIsBackgroundToTrue)
  _test(ThreadTest, GetMainThreadThenGetHashCode)
  _test(ThreadTest, GetMainThreadThenInterrupt)
  _test(ThreadTest, GetMainThreadThenJoin)
  _test(ThreadTest, GetMainThreadThenJoinWithBadTimeout)
  _test(ThreadTest, GetMainThreadThenJoinWithInfiniteTimeout)
  _test(ThreadTest, GetMainThreadThenJoinWithTimeout)
  _test(ThreadTest, GetMainThreadThenResume)
  _test(ThreadTest, GetMainThreadThenStart)
  _test(ThreadTest, GetMainThreadThenStartWithThreadStart)
  _test(ThreadTest, GetMainThreadThenStartWithParameterizedThreadStart)
  _test(ThreadTest, GetMainThreadThenSuspend)
  
  _test(ThreadTest, CreateUnmanagedThreadThenGetManagedThreadId)
  _test(ThreadTest, CreateUnmanagedThreadThenGetHandle)
  _test(ThreadTest, CreateUnmanagedThreadThenIsAlive)
  _test(ThreadTest, CreateUnmanagedThreadThenIsBackground)
  _test(ThreadTest, CreateUnmanagedThreadThenGetName)
  _test(ThreadTest, CreateUnmanagedThreadThenGetPriority)
  _test(ThreadTest, CreateUnmanagedThreadThenGetThreadState)
  _test(ThreadTest, CreateUnmanagedThreadThenSetName)
  _test(ThreadTest, CreateUnmanagedThreadThenSetPriority)
  _test(ThreadTest, CreateUnmanagedThreadThenAbort)
  _test(ThreadTest, CreateUnmanagedThreadThenSetIsBackgroundToTrue)
  _test(ThreadTest, CreateUnmanagedThreadThenGetHashCode)
  _test(ThreadTest, CreateUnmanagedThreadThenInterrupt)
  _test(ThreadTest, CreateUnmanagedThreadThenJoin)
  _test(ThreadTest, CreateUnmanagedThreadThenJoinWithBadTimeout)
  _test(ThreadTest, CreateUnmanagedThreadThenJoinWithInfiniteTimeout)
  _test(ThreadTest, CreateUnmanagedThreadThenJoinWithTimeout)
  _test(ThreadTest, CreateUnmanagedThreadThenResume)
  _test(ThreadTest, CreateUnmanagedThreadThenStart)
  _test(ThreadTest, CreateUnmanagedThreadThenStartWithThreadStart)
  _test(ThreadTest, CreateUnmanagedThreadThenStartWithParameterizedThreadStart)
  _test(ThreadTest, CreateUnmanagedThreadThenSuspend)
  
  _test(ThreadTest, CreateEmptyThreadThenGetManagedThreadId)
  _test(ThreadTest, CreateEmptyThreadThenGetHandle)
  _test(ThreadTest, CreateEmptyThreadThenIsAlive)
  _test(ThreadTest, CreateEmptyThreadThenIsBackground)
  _test(ThreadTest, CreateEmptyThreadThenGetName)
  _test(ThreadTest, CreateEmptyThreadThenGetPriority)
  _test(ThreadTest, CreateEmptyThreadThenGetThreadState)
  _test(ThreadTest, CreateEmptyThreadThenSetName)
  _test(ThreadTest, CreateEmptyThreadThenSetPriority)
  _test(ThreadTest, CreateEmptyThreadThenAbort)
  _test(ThreadTest, CreateEmptyThreadThenSetIsBackgroundToTrue)
  _test(ThreadTest, CreateEmptyThreadThenGetHashCode)
  _test(ThreadTest, CreateEmptyThreadThenInterrupt)
  _test(ThreadTest, CreateEmptyThreadThenJoin)
  _test(ThreadTest, CreateEmptyThreadThenJoinWithBadTimeout)
  _test(ThreadTest, CreateEmptyThreadThenJoinWithInfiniteTimeout)
  _test(ThreadTest, CreateEmptyThreadThenJoinWithTimeout)
  _test(ThreadTest, CreateEmptyThreadThenResume)
  _test(ThreadTest, CreateEmptyThreadThenStart)
  _test(ThreadTest, CreateEmptyThreadThenStartWithThreadStart)
  _test(ThreadTest, CreateEmptyThreadThenStartWithParameterizedThreadStart)
  _test(ThreadTest, CreateEmptyThreadThenSuspend)
  
  _test(ThreadTest, CreateThreadWithThreadStartThenGetManagedThreadId)
  _test(ThreadTest, CreateThreadWithThreadStartThenGetHandle)
  _test(ThreadTest, CreateThreadWithThreadStartThenIsAlive)
  _test(ThreadTest, CreateThreadWithThreadStartStartItThenIsAlive)
  _test(ThreadTest, CreateThreadWithThreadStartThenIsBackground)
  _test(ThreadTest, CreateThreadWithThreadStartThenGetName)
  _test(ThreadTest, CreateThreadWithThreadStartThenGetPriority)
  _test(ThreadTest, CreateThreadWithThreadStartThenGetThreadState)
  _test(ThreadTest, CreateThreadWithThreadStartThenSetName)
  _test(ThreadTest, CreateThreadWithThreadStartThenSetPriority)
  _test(ThreadTest, CreateThreadWithThreadStartThenAbort)
  _test(ThreadTest, CreateThreadWithThreadStartStartItThenAbort)
  _test(ThreadTest, CreateThreadWithThreadStartThenSetIsBackgroundToTrue)
  _test(ThreadTest, CreateThreadWithThreadStartThenGetHashCode)
  _test(ThreadTest, CreateThreadWithThreadStartThenInterrupt)
  _test(ThreadTest, CreateThreadWithThreadStartStartItThenInterrupt)
  _test(ThreadTest, CreateThreadWithThreadStartThenSuspend)
  _test(ThreadTest, CreateThreadWithThreadStartThenResume)
  _test(ThreadTest, CreateThreadWithThreadStartStartItThenResume)
  _test(ThreadTest, CreateThreadWithThreadStartStartItSuspendThenResume)
  _test(ThreadTest, CreateThreadWithThreadStartThenStart)
  _test(ThreadTest, CreateThreadWithThreadStartThenStartWithParameterizedThreadStart)
  _test(ThreadTest, CreateThreadWithThreadStartThenJoin)
  _test(ThreadTest, CreateThreadWithThreadStartStartItThenJoin)
  _test(ThreadTest, CreateThreadWithThreadStartThenJoinWithBadTimeout)
  _test(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithBadTimeout)
  _test(ThreadTest, CreateThreadWithThreadStartThenJoinWithInfiniteTimeout)
  _test(ThreadTest, CreateThreadWithThreadStartThenJoinWithTimeout)
  _test(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithTimeout)
  _test(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithTimeSpanTimeout)
  _test(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithToShortTimeout)
  _test(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithToShortTimeSpanTimeout)
  
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetManagedThreadId)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetHandle)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenIsAlive)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenIsAlive)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenIsBackground)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetName)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetPriority)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetThreadState)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenSetName)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenSetPriority)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenAbort)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenAbort)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenSetIsBackgroundToTrue)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetHashCode)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenInterrupt)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenInterrupt)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenSuspend)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenResume)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenResume)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItSuspendThenResume)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenStart)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenStartWithThreadStart)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoin)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoin)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoinWithBadTimeout)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithBadTimeout)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoinWithInfiniteTimeout)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoinWithTimeout)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithTimeout)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithTimeSpanTimeout)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithToShortTimeout)
  _test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithToShortTimeSpanTimeout)
}

