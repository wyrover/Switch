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
      Assert::AreEqual(1, thread.ManagedThreadId, sw_current_information);
    }
    
    void GetMainThreadThenGetHandle() {
      Thread thread = Thread::CurrentThread;
      Assert::AreNotEqual(intptr(-1), thread.Handle, sw_current_information);
    }
    
    void GetMainThreadThenIsAlive() {
      Thread thread = Thread::CurrentThread;
      Assert::True(thread.IsAlive, sw_current_information);
    }
    
    void GetMainThreadThenIsBackground() {
      Thread thread = Thread::CurrentThread;
      Assert::False(thread.IsBackground, sw_current_information);
    }
    
    void GetMainThreadThenGetName() {
      Thread thread = Thread::CurrentThread;
      if (!hasMainThreadNamedOnlyOnce)
        Assert::AreEqual("", thread.Name, sw_current_information);
      else
        Assert::AreEqual("Main", thread.Name, sw_current_information);
    }
    
    void GetMainThreadThenGetPriority() {
      Thread thread = Thread::CurrentThread;
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, sw_current_information);
    }
    
    void GetMainThreadThenGetThreadState() {
      Thread thread = Thread::CurrentThread;
      Assert::AreEqual(ThreadState::Running, thread.ThreadState(), sw_current_information);
    }
    
    void GetMainThreadThenSetName() {
      Thread thread = Thread::CurrentThread;
      if (!hasMainThreadNamedOnlyOnce) {
        Assert::AreEqual("", thread.Name, sw_current_information);
        Assert::DoesNotThrows(sw_delegate {thread.Name = "Main";}, sw_current_information);
        Assert::AreEqual("Main", thread.Name, sw_current_information);
        hasMainThreadNamedOnlyOnce = true;
      } else {
        Assert::AreEqual("Main", thread.Name, sw_current_information);
        Assert::Throws<InvalidOperationException>(sw_delegate {thread.Name = "";}, sw_current_information);
      }
    }
    
    void GetMainThreadThenSetPriority() {
      Thread thread = Thread::CurrentThread;
      Assert::DoesNotThrows(sw_delegate {thread.Priority = ThreadPriority::AboveNormal;}, sw_current_information);
      Assert::AreEqual(ThreadPriority::AboveNormal, thread.Priority, sw_current_information);
      Assert::DoesNotThrows(sw_delegate {thread.Priority = ThreadPriority::Normal;}, sw_current_information);
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, sw_current_information);
    }
    
    void GetMainThreadThenAbort() {
      Thread thread = Thread::CurrentThread;
      // If you uncomments the next line, the unit tests will be aborted ;-)
      //Assert::DoesNotThrows(sw_delegate {thread.Abort();}, sw_current_information);
    }
    
    void GetMainThreadThenSetIsBackgroundToTrue() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.IsBackground = true;}, sw_current_information);
    }
    
    void GetMainThreadThenGetHashCode() {
      Thread thread = Thread::CurrentThread;
      Assert::AreEqual(1, thread.GetHashCode(), sw_current_information);
    }
    
    void GetMainThreadThenInterrupt() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Interrupt();}, sw_current_information);
    }
    
    void GetMainThreadThenJoin() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Join();}, sw_current_information);
    }
    
    void GetMainThreadThenJoinWithBadTimeout() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Join(-2);}, sw_current_information);
    }
    
    void GetMainThreadThenJoinWithInfiniteTimeout() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Join(Timeout::Infinite);}, sw_current_information);
    }
    
    void GetMainThreadThenJoinWithTimeout() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Join(1);}, sw_current_information);
    }
    
    void GetMainThreadThenResume() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Resume();}, sw_current_information);
    }
    
    void GetMainThreadThenStart() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Start();}, sw_current_information);
    }
    
    void GetMainThreadThenStartWithThreadStart() {
      Thread thread = Thread::CurrentThread;
      ThreadStart threadStart = sw_delegate {};
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Start(threadStart);}, sw_current_information);
    }
    
    void GetMainThreadThenStartWithParameterizedThreadStart() {
      Thread thread = Thread::CurrentThread;
      ParameterizedThreadStart parameterizedTeadStart = sw_delegate(const object&) {};
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Start(parameterizedTeadStart);}, sw_current_information);
    }
    
    void GetMainThreadThenSuspend() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Suspend();}, sw_current_information);
    }
    
    void CreateUnmanagedThreadThenGetManagedThreadId() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::AreEqual(0, thread.ManagedThreadId, sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenGetHandle() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::AreEqual(intptr(-1), thread.Handle, sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenIsAlive() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::True(thread.IsAlive, sw_current_information);
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
        Assert::AreEqual(ThreadPriority::Normal, thread.Priority, sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenGetThreadState() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::AreEqual(ThreadState::Running, thread.ThreadState() & ThreadState::Running, sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenSetName() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(sw_delegate {thread.Name = "Unmanaged";}, sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenSetPriority() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(sw_delegate {thread.Priority = ThreadPriority::Highest;}, sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenAbort() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(sw_delegate {thread.Abort();}, sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenSetIsBackgroundToTrue() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(sw_delegate {thread.IsBackground = true;}, sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenGetHashCode() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::AreEqual(0, thread.GetHashCode(), sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenInterrupt() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(sw_delegate {thread.Interrupt();}, sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenJoin() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(sw_delegate {thread.Join();}, sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenJoinWithBadTimeout() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(sw_delegate {thread.Join(-2);}, sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenJoinWithInfiniteTimeout() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(sw_delegate {thread.Join(Timeout::Infinite);}, sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenJoinWithTimeout() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(sw_delegate {thread.Join(1);}, sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenResume() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(sw_delegate {thread.Resume();}, sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenStart() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<ThreadStateException>(sw_delegate {thread.Start();}, sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenStartWithThreadStart() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        ThreadStart threadStart = sw_delegate {};
        Assert::Throws<ThreadStateException>(sw_delegate {thread.Start(threadStart);}, sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenStartWithParameterizedThreadStart() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        ParameterizedThreadStart parameterizedTeadStart = sw_delegate(const object&) {};
        Assert::Throws<ThreadStateException>(sw_delegate {thread.Start(parameterizedTeadStart);}, sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenSuspend() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(sw_delegate {thread.Suspend();}, sw_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateEmptyThreadThenGetManagedThreadId() {
      Thread thread;
      Assert::AreEqual(0, thread.ManagedThreadId, sw_current_information);
    }
    
    void CreateEmptyThreadThenGetHandle() {
      Thread thread;
      Assert::AreEqual(intptr(-1), thread.Handle, sw_current_information);
    }
    
    void CreateEmptyThreadThenIsAlive() {
      Thread thread;
      Assert::False(thread.IsAlive, sw_current_information);
    }
    
    void CreateEmptyThreadThenIsBackground() {
      Thread thread;
      Assert::False(thread.IsBackground, sw_current_information);
    }
    
    void CreateEmptyThreadThenGetName() {
      Thread thread;
      Assert::AreEqual("", thread.Name, sw_current_information);
    }
    
    void CreateEmptyThreadThenGetPriority() {
      Thread thread;
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, sw_current_information);
    }
    
    void CreateEmptyThreadThenGetThreadState() {
      Thread thread;
      Assert::AreEqual(ThreadState::Unstarted, thread.ThreadState, sw_current_information);
    }
    
    void CreateEmptyThreadThenSetName() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Name = "Empty";}, sw_current_information);
    }
    
    void CreateEmptyThreadThenSetPriority() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Priority = ThreadPriority::Highest;}, sw_current_information);
    }
    
    void CreateEmptyThreadThenAbort() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Abort();}, sw_current_information);
    }
    
    void CreateEmptyThreadThenSetIsBackgroundToTrue() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.IsBackground = true;}, sw_current_information);
    }
    
    void CreateEmptyThreadThenGetHashCode() {
      Thread thread;
      Assert::AreEqual(0, thread.GetHashCode(), sw_current_information);
    }
    
    void CreateEmptyThreadThenInterrupt() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Interrupt();}, sw_current_information);
    }
    
    void CreateEmptyThreadThenJoin() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Join();}, sw_current_information);
    }
    
    void CreateEmptyThreadThenJoinWithBadTimeout() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Join(-2);}, sw_current_information);
    }
    
    void CreateEmptyThreadThenJoinWithInfiniteTimeout() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Join(Timeout::Infinite);}, sw_current_information);
    }
    
    void CreateEmptyThreadThenJoinWithTimeout() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Join(1);}, sw_current_information);
    }
    
    void CreateEmptyThreadThenResume() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Resume();}, sw_current_information);
    }
    
    void CreateEmptyThreadThenStart() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Start();}, sw_current_information);
    }
    
    void CreateEmptyThreadThenStartWithThreadStart() {
      Thread thread;
      object obj;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Start(obj);}, sw_current_information);
    }
    
    void CreateEmptyThreadThenStartWithParameterizedThreadStart() {
      Thread thread;
      object obj;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Start(obj);}, sw_current_information);
    }
    
    void CreateEmptyThreadThenSuspend() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Suspend();}, sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenGetManagedThreadId() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Greater(thread.ManagedThreadId, 1, sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenGetHandle() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreNotEqual(intptr(-1), thread.Handle, sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenIsAlive() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::False(thread.IsAlive, sw_current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenIsAlive() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        Thread::Sleep(10);
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::True(thread.IsAlive, sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenIsBackground() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::False(thread.IsBackground, sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenGetName() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreEqual("", thread.Name, sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenGetPriority() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenGetThreadState() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreEqual(ThreadState::Unstarted, thread.ThreadState, sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenSetName() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::DoesNotThrows(sw_delegate {thread.Name = "Thread";}, sw_current_information);
      Assert::AreEqual("Thread", thread.Name);
    }
    
    void CreateThreadWithThreadStartThenSetPriority() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::DoesNotThrows(sw_delegate {thread.Priority = ThreadPriority::Highest;}, sw_current_information);
      Assert::AreEqual(ThreadPriority::Highest, thread.Priority);
    }
    
    void CreateThreadWithThreadStartThenAbort() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Abort();}, sw_current_information);
      Assert::AreEqual(0, counter, sw_current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenAbort() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        Thread::Sleep(100);
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Thread::Sleep(5);
      Assert::Throws<ThreadAbortException>(sw_delegate {thread.Abort();}, sw_current_information);
      Assert::AreEqual(0, counter, sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenSetIsBackgroundToTrue() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::DoesNotThrows(sw_delegate {thread.IsBackground = true;}, sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenGetHashCode() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreEqual(thread.ManagedThreadId, thread.GetHashCode(), sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenInterrupt() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Interrupt();}, sw_current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenInterrupt() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        Thread::Sleep(100);
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Thread::Sleep(5);
      Assert::Throws<ThreadInterruptedException>(sw_delegate {thread.Interrupt();}, sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenSuspend() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Suspend();}, sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenResume() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Resume();}, sw_current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenResume() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Resume();}, sw_current_information);
    }
    
    void CreateThreadWithThreadStartStartItSuspendThenResume() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        Thread::Sleep(10);
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      thread.Suspend();
      Assert::DoesNotThrows(sw_delegate {thread.Resume();}, sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenStart() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::DoesNotThrows(sw_delegate {thread.Start();}, sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenStartWithParameterizedThreadStart() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      ParameterizedThreadStart parameterizedTeadStart = sw_delegate(const object&) {};
      Assert::Throws<InvalidOperationException>(sw_delegate {thread.Start(parameterizedTeadStart);}, sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenJoin() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Join();}, sw_current_information);
     }
    
    void CreateThreadWithThreadStartStartItThenJoin() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::DoesNotThrows(sw_delegate {thread.Join();}, sw_current_information);
      Assert::AreEqual(1, counter, sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenJoinWithBadTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Join(-2);}, sw_current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenJoinWithBadTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {thread.Join(-2);}, sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenJoinWithInfiniteTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::DoesNotThrows(sw_delegate {thread.Join(Timeout::Infinite);}, sw_current_information);
      Assert::AreEqual(1, counter, sw_current_information);
    }
    
    void CreateThreadWithThreadStartThenJoinWithTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Join(5);}, sw_current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenJoinWithTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::True(thread.Join(5), sw_current_information);
      Assert::AreEqual(1, counter, sw_current_information);
   }
    
    void CreateThreadWithThreadStartStartItThenJoinWithTimeSpanTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::True(thread.Join(TimeSpan::FromMilliseconds(5)), sw_current_information);
      Assert::AreEqual(1, counter, sw_current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenJoinWithToShortTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        Thread::Sleep(20);
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::False(thread.Join(2), sw_current_information);
      Assert::AreEqual(0, counter, sw_current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenJoinWithToShortTimeSpanTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = sw_delegate {
        Thread::Sleep(20);
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::False(thread.Join(TimeSpan::FromMilliseconds(2)), sw_current_information);
      Assert::AreEqual(0, counter, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetManagedThreadId() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::Greater(thread.ManagedThreadId, 1, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetHandle() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreNotEqual(intptr(-1), thread.Handle, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenIsAlive() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::False(thread.IsAlive, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenIsAlive() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Thread::Sleep(10);
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::True(thread.IsAlive, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenIsBackground() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::False(thread.IsBackground, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetName() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreEqual("", thread.Name, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetPriority() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetThreadState() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreEqual(ThreadState::Unstarted, thread.ThreadState, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenSetName() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(sw_delegate {thread.Name = "Thread";}, sw_current_information);
      Assert::AreEqual("Thread", thread.Name);
    }
    
    void CreateThreadWithParameterizedThreadStartThenSetPriority() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(sw_delegate {thread.Priority = ThreadPriority::Highest;}, sw_current_information);
      Assert::AreEqual(ThreadPriority::Highest, thread.Priority);
    }
    
    void CreateThreadWithParameterizedThreadStartThenAbort() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Abort();}, sw_current_information);
      Assert::AreEqual(0, counter, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenAbort() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Thread::Sleep(100);
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Thread::Sleep(5);
      Assert::Throws<ThreadAbortException>(sw_delegate {thread.Abort();}, sw_current_information);
      Assert::AreEqual(0, counter, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenSetIsBackgroundToTrue() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(sw_delegate {thread.IsBackground = true;}, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetHashCode() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreEqual(thread.ManagedThreadId, thread.GetHashCode(), sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenInterrupt() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Interrupt();}, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenInterrupt() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Thread::Sleep(100);
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Thread::Sleep(5);
      Assert::Throws<ThreadInterruptedException>(sw_delegate {thread.Interrupt();}, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenSuspend() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Suspend();}, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenResume() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Resume();}, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenResume() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Resume();}, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItSuspendThenResume() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Thread::Sleep(10);
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      thread.Suspend();
      Assert::DoesNotThrows(sw_delegate {thread.Resume();}, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenStart() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::IsInstanceOfType<Thread>(param, sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(sw_delegate {thread.Start();}, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenStartWithThreadStart() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(sw_delegate {thread.Start(counter);}, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenJoin() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Join();}, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoin() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::DoesNotThrows(sw_delegate {thread.Join();}, sw_current_information);
      Assert::AreEqual(0, counter, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenJoinWithBadTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Join(-2);}, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithBadTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {thread.Join(-2);}, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenJoinWithInfiniteTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::DoesNotThrows(sw_delegate {thread.Join(Timeout::Infinite);}, sw_current_information);
      Assert::AreEqual(0, counter, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenJoinWithTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(sw_delegate {thread.Join(5);}, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::True(thread.Join(5), sw_current_information);
      Assert::AreEqual(0, counter, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithTimeSpanTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::True(thread.Join(TimeSpan::FromMilliseconds(5)), sw_current_information);
      Assert::AreEqual(0, counter, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithToShortTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Thread::Sleep(20);
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::False(thread.Join(2), sw_current_information);
      Assert::AreEqual(0, counter, sw_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithToShortTimeSpanTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = sw_delegate(const object& param) {
        Thread::Sleep(20);
        Assert::AreEqual(0, as<Int32>(param), sw_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::False(thread.Join(TimeSpan::FromMilliseconds(2)), sw_current_information);
      Assert::AreEqual(0, counter, sw_current_information);
    }
  };
  
  bool ThreadTest::hasMainThreadNamedOnlyOnce = false;

  sw_test(ThreadTest, GetMainThreadThenGetManagedThreadId)
  sw_test(ThreadTest, GetMainThreadThenGetHandle)
  sw_test(ThreadTest, GetMainThreadThenIsAlive)
  sw_test(ThreadTest, GetMainThreadThenIsBackground)
  sw_test(ThreadTest, GetMainThreadThenGetName)
  sw_test(ThreadTest, GetMainThreadThenGetPriority)
  sw_test(ThreadTest, GetMainThreadThenGetThreadState)
  sw_test(ThreadTest, GetMainThreadThenSetName)
  sw_test(ThreadTest, GetMainThreadThenSetPriority)
  sw_test(ThreadTest, GetMainThreadThenAbort)
  sw_test(ThreadTest, GetMainThreadThenSetIsBackgroundToTrue)
  sw_test(ThreadTest, GetMainThreadThenGetHashCode)
  sw_test(ThreadTest, GetMainThreadThenInterrupt)
  sw_test(ThreadTest, GetMainThreadThenJoin)
  sw_test(ThreadTest, GetMainThreadThenJoinWithBadTimeout)
  sw_test(ThreadTest, GetMainThreadThenJoinWithInfiniteTimeout)
  sw_test(ThreadTest, GetMainThreadThenJoinWithTimeout)
  sw_test(ThreadTest, GetMainThreadThenResume)
  sw_test(ThreadTest, GetMainThreadThenStart)
  sw_test(ThreadTest, GetMainThreadThenStartWithThreadStart)
  sw_test(ThreadTest, GetMainThreadThenStartWithParameterizedThreadStart)
  sw_test(ThreadTest, GetMainThreadThenSuspend)
  
  sw_test(ThreadTest, CreateUnmanagedThreadThenGetManagedThreadId)
  sw_test(ThreadTest, CreateUnmanagedThreadThenGetHandle)
  sw_test(ThreadTest, CreateUnmanagedThreadThenIsAlive)
  sw_test(ThreadTest, CreateUnmanagedThreadThenIsBackground)
  sw_test(ThreadTest, CreateUnmanagedThreadThenGetName)
  sw_test(ThreadTest, CreateUnmanagedThreadThenGetPriority)
  sw_test(ThreadTest, CreateUnmanagedThreadThenGetThreadState)
  sw_test(ThreadTest, CreateUnmanagedThreadThenSetName)
  sw_test(ThreadTest, CreateUnmanagedThreadThenSetPriority)
  sw_test(ThreadTest, CreateUnmanagedThreadThenAbort)
  sw_test(ThreadTest, CreateUnmanagedThreadThenSetIsBackgroundToTrue)
  sw_test(ThreadTest, CreateUnmanagedThreadThenGetHashCode)
  sw_test(ThreadTest, CreateUnmanagedThreadThenInterrupt)
  sw_test(ThreadTest, CreateUnmanagedThreadThenJoin)
  sw_test(ThreadTest, CreateUnmanagedThreadThenJoinWithBadTimeout)
  sw_test(ThreadTest, CreateUnmanagedThreadThenJoinWithInfiniteTimeout)
  sw_test(ThreadTest, CreateUnmanagedThreadThenJoinWithTimeout)
  sw_test(ThreadTest, CreateUnmanagedThreadThenResume)
  sw_test(ThreadTest, CreateUnmanagedThreadThenStart)
  sw_test(ThreadTest, CreateUnmanagedThreadThenStartWithThreadStart)
  sw_test(ThreadTest, CreateUnmanagedThreadThenStartWithParameterizedThreadStart)
  sw_test(ThreadTest, CreateUnmanagedThreadThenSuspend)
  
  sw_test(ThreadTest, CreateEmptyThreadThenGetManagedThreadId)
  sw_test(ThreadTest, CreateEmptyThreadThenGetHandle)
  sw_test(ThreadTest, CreateEmptyThreadThenIsAlive)
  sw_test(ThreadTest, CreateEmptyThreadThenIsBackground)
  sw_test(ThreadTest, CreateEmptyThreadThenGetName)
  sw_test(ThreadTest, CreateEmptyThreadThenGetPriority)
  sw_test(ThreadTest, CreateEmptyThreadThenGetThreadState)
  sw_test(ThreadTest, CreateEmptyThreadThenSetName)
  sw_test(ThreadTest, CreateEmptyThreadThenSetPriority)
  sw_test(ThreadTest, CreateEmptyThreadThenAbort)
  sw_test(ThreadTest, CreateEmptyThreadThenSetIsBackgroundToTrue)
  sw_test(ThreadTest, CreateEmptyThreadThenGetHashCode)
  sw_test(ThreadTest, CreateEmptyThreadThenInterrupt)
  sw_test(ThreadTest, CreateEmptyThreadThenJoin)
  sw_test(ThreadTest, CreateEmptyThreadThenJoinWithBadTimeout)
  sw_test(ThreadTest, CreateEmptyThreadThenJoinWithInfiniteTimeout)
  sw_test(ThreadTest, CreateEmptyThreadThenJoinWithTimeout)
  sw_test(ThreadTest, CreateEmptyThreadThenResume)
  sw_test(ThreadTest, CreateEmptyThreadThenStart)
  sw_test(ThreadTest, CreateEmptyThreadThenStartWithThreadStart)
  sw_test(ThreadTest, CreateEmptyThreadThenStartWithParameterizedThreadStart)
  sw_test(ThreadTest, CreateEmptyThreadThenSuspend)
  
  sw_test(ThreadTest, CreateThreadWithThreadStartThenGetManagedThreadId)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenGetHandle)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenIsAlive)
  sw_test(ThreadTest, CreateThreadWithThreadStartStartItThenIsAlive)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenIsBackground)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenGetName)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenGetPriority)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenGetThreadState)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenSetName)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenSetPriority)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenAbort)
  sw_test(ThreadTest, CreateThreadWithThreadStartStartItThenAbort)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenSetIsBackgroundToTrue)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenGetHashCode)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenInterrupt)
  sw_test(ThreadTest, CreateThreadWithThreadStartStartItThenInterrupt)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenSuspend)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenResume)
  sw_test(ThreadTest, CreateThreadWithThreadStartStartItThenResume)
  sw_test(ThreadTest, CreateThreadWithThreadStartStartItSuspendThenResume)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenStart)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenStartWithParameterizedThreadStart)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenJoin)
  sw_test(ThreadTest, CreateThreadWithThreadStartStartItThenJoin)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenJoinWithBadTimeout)
  sw_test(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithBadTimeout)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenJoinWithInfiniteTimeout)
  sw_test(ThreadTest, CreateThreadWithThreadStartThenJoinWithTimeout)
  sw_test(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithTimeout)
  sw_test(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithTimeSpanTimeout)
  sw_test(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithToShortTimeout)
  sw_test(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithToShortTimeSpanTimeout)
  
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetManagedThreadId)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetHandle)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenIsAlive)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenIsAlive)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenIsBackground)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetName)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetPriority)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetThreadState)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenSetName)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenSetPriority)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenAbort)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenAbort)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenSetIsBackgroundToTrue)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetHashCode)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenInterrupt)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenInterrupt)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenSuspend)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenResume)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenResume)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItSuspendThenResume)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenStart)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenStartWithThreadStart)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoin)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoin)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoinWithBadTimeout)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithBadTimeout)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoinWithInfiniteTimeout)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoinWithTimeout)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithTimeout)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithTimeSpanTimeout)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithToShortTimeout)
  sw_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithToShortTimeSpanTimeout)
}

