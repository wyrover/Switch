#include <Pcf/System/Threading/Timer.h>
#include <Pcf/System/Threading/AutoResetEvent.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Threading;
using namespace TUnit;

namespace {
  class ThreadTest : public TestFixture {
  protected:
    static bool hasMainThreadNamedOnlyOnce;

    void GetMainThreadThenGetManagedThreadId() {
      Thread thread = Thread::CurrentThread;
      Assert::AreEqual(1, thread.ManagedThreadId, pcf_current_information);
    }
    
    void GetMainThreadThenGetHandle() {
      Thread thread = Thread::CurrentThread;
      Assert::AreNotEqual(intptr(-1), thread.Handle, pcf_current_information);
    }
    
    void GetMainThreadThenIsAlive() {
      Thread thread = Thread::CurrentThread;
      Assert::True(thread.IsAlive, pcf_current_information);
    }
    
    void GetMainThreadThenIsBackground() {
      Thread thread = Thread::CurrentThread;
      Assert::False(thread.IsBackground, pcf_current_information);
    }
    
    void GetMainThreadThenGetName() {
      Thread thread = Thread::CurrentThread;
      if (!hasMainThreadNamedOnlyOnce)
        Assert::AreEqual("", thread.Name, pcf_current_information);
      else
        Assert::AreEqual("Main", thread.Name, pcf_current_information);
    }
    
    void GetMainThreadThenGetPriority() {
      Thread thread = Thread::CurrentThread;
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, pcf_current_information);
    }
    
    void GetMainThreadThenGetThreadState() {
      Thread thread = Thread::CurrentThread;
      Assert::AreEqual(ThreadState::Running, thread.ThreadState(), pcf_current_information);
    }
    
    void GetMainThreadThenSetName() {
      Thread thread = Thread::CurrentThread;
      if (!hasMainThreadNamedOnlyOnce) {
        Assert::AreEqual("", thread.Name, pcf_current_information);
        Assert::DoesNotThrows(pcf_delegate {thread.Name = "Main";}, pcf_current_information);
        Assert::AreEqual("Main", thread.Name, pcf_current_information);
        hasMainThreadNamedOnlyOnce = true;
      } else {
        Assert::AreEqual("Main", thread.Name, pcf_current_information);
        Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Name = "";}, pcf_current_information);
      }
    }
    
    void GetMainThreadThenSetPriority() {
      Thread thread = Thread::CurrentThread;
      Assert::DoesNotThrows(pcf_delegate {thread.Priority = ThreadPriority::AboveNormal;}, pcf_current_information);
      Assert::AreEqual(ThreadPriority::AboveNormal, thread.Priority, pcf_current_information);
      Assert::DoesNotThrows(pcf_delegate {thread.Priority = ThreadPriority::Normal;}, pcf_current_information);
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, pcf_current_information);
    }
    
    void GetMainThreadThenAbort() {
      Thread thread = Thread::CurrentThread;
      // If you uncomments the next line, the unit tests will be aborted ;-)
      //Assert::DoesNotThrows(pcf_delegate {thread.Abort();}, pcf_current_information);
    }
    
    void GetMainThreadThenSetIsBackgroundToTrue() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.IsBackground = true;}, pcf_current_information);
    }
    
    void GetMainThreadThenGetHashCode() {
      Thread thread = Thread::CurrentThread;
      Assert::AreEqual(1, thread.GetHashCode(), pcf_current_information);
    }
    
    void GetMainThreadThenInterrupt() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Interrupt();}, pcf_current_information);
    }
    
    void GetMainThreadThenJoin() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Join();}, pcf_current_information);
    }
    
    void GetMainThreadThenJoinWithBadTimeout() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Join(-2);}, pcf_current_information);
    }
    
    void GetMainThreadThenJoinWithInfiniteTimeout() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Join(Timeout::Infinite);}, pcf_current_information);
    }
    
    void GetMainThreadThenJoinWithTimeout() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Join(1);}, pcf_current_information);
    }
    
    void GetMainThreadThenResume() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Resume();}, pcf_current_information);
    }
    
    void GetMainThreadThenStart() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Start();}, pcf_current_information);
    }
    
    void GetMainThreadThenStartWithThreadStart() {
      Thread thread = Thread::CurrentThread;
      ThreadStart threadStart = pcf_delegate {};
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Start(threadStart);}, pcf_current_information);
    }
    
    void GetMainThreadThenStartWithParameterizedThreadStart() {
      Thread thread = Thread::CurrentThread;
      ParameterizedThreadStart parameterizedTeadStart = pcf_delegate(const object&) {};
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Start(parameterizedTeadStart);}, pcf_current_information);
    }
    
    void GetMainThreadThenSuspend() {
      Thread thread = Thread::CurrentThread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Suspend();}, pcf_current_information);
    }
    
    void CreateUnmanagedThreadThenGetManagedThreadId() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::AreEqual(0, thread.ManagedThreadId, pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenGetHandle() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::AreEqual(intptr(-1), thread.Handle, pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenIsAlive() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::True(thread.IsAlive, pcf_current_information);
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
        Assert::AreEqual(ThreadPriority::Normal, thread.Priority, pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenGetThreadState() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::AreEqual(ThreadState::Running, thread.ThreadState() & ThreadState::Running, pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenSetName() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Name = "Unmanaged";}, pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenSetPriority() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Priority = ThreadPriority::Highest;}, pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenAbort() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Abort();}, pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenSetIsBackgroundToTrue() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(pcf_delegate {thread.IsBackground = true;}, pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenGetHashCode() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::AreEqual(0, thread.GetHashCode(), pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenInterrupt() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Interrupt();}, pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenJoin() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Join();}, pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenJoinWithBadTimeout() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Join(-2);}, pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenJoinWithInfiniteTimeout() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Join(Timeout::Infinite);}, pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenJoinWithTimeout() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Join(1);}, pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenResume() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Resume();}, pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenStart() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<ThreadStateException>(pcf_delegate {thread.Start();}, pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenStartWithThreadStart() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        ThreadStart threadStart = pcf_delegate {};
        Assert::Throws<ThreadStateException>(pcf_delegate {thread.Start(threadStart);}, pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenStartWithParameterizedThreadStart() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        ParameterizedThreadStart parameterizedTeadStart = pcf_delegate(const object&) {};
        Assert::Throws<ThreadStateException>(pcf_delegate {thread.Start(parameterizedTeadStart);}, pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateUnmanagedThreadThenSuspend() {
      std::function<void()> threadStart = [] {
        Thread thread = Thread::CurrentThread;
        Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Suspend();}, pcf_current_information);
      };
      std::thread thread(threadStart);
      thread.join();
    }
    
    void CreateEmptyThreadThenGetManagedThreadId() {
      Thread thread;
      Assert::AreEqual(0, thread.ManagedThreadId, pcf_current_information);
    }
    
    void CreateEmptyThreadThenGetHandle() {
      Thread thread;
      Assert::AreEqual(intptr(-1), thread.Handle, pcf_current_information);
    }
    
    void CreateEmptyThreadThenIsAlive() {
      Thread thread;
      Assert::False(thread.IsAlive, pcf_current_information);
    }
    
    void CreateEmptyThreadThenIsBackground() {
      Thread thread;
      Assert::False(thread.IsBackground, pcf_current_information);
    }
    
    void CreateEmptyThreadThenGetName() {
      Thread thread;
      Assert::AreEqual("", thread.Name, pcf_current_information);
    }
    
    void CreateEmptyThreadThenGetPriority() {
      Thread thread;
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, pcf_current_information);
    }
    
    void CreateEmptyThreadThenGetThreadState() {
      Thread thread;
      Assert::AreEqual(ThreadState::Unstarted, thread.ThreadState, pcf_current_information);
    }
    
    void CreateEmptyThreadThenSetName() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Name = "Empty";}, pcf_current_information);
    }
    
    void CreateEmptyThreadThenSetPriority() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Priority = ThreadPriority::Highest;}, pcf_current_information);
    }
    
    void CreateEmptyThreadThenAbort() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Abort();}, pcf_current_information);
    }
    
    void CreateEmptyThreadThenSetIsBackgroundToTrue() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.IsBackground = true;}, pcf_current_information);
    }
    
    void CreateEmptyThreadThenGetHashCode() {
      Thread thread;
      Assert::AreEqual(0, thread.GetHashCode(), pcf_current_information);
    }
    
    void CreateEmptyThreadThenInterrupt() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Interrupt();}, pcf_current_information);
    }
    
    void CreateEmptyThreadThenJoin() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Join();}, pcf_current_information);
    }
    
    void CreateEmptyThreadThenJoinWithBadTimeout() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Join(-2);}, pcf_current_information);
    }
    
    void CreateEmptyThreadThenJoinWithInfiniteTimeout() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Join(Timeout::Infinite);}, pcf_current_information);
    }
    
    void CreateEmptyThreadThenJoinWithTimeout() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Join(1);}, pcf_current_information);
    }
    
    void CreateEmptyThreadThenResume() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Resume();}, pcf_current_information);
    }
    
    void CreateEmptyThreadThenStart() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Start();}, pcf_current_information);
    }
    
    void CreateEmptyThreadThenStartWithThreadStart() {
      Thread thread;
      object obj;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Start(obj);}, pcf_current_information);
    }
    
    void CreateEmptyThreadThenStartWithParameterizedThreadStart() {
      Thread thread;
      object obj;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Start(obj);}, pcf_current_information);
    }
    
    void CreateEmptyThreadThenSuspend() {
      Thread thread;
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Suspend();}, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenGetManagedThreadId() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Greater(thread.ManagedThreadId, 1, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenGetHandle() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreNotEqual(intptr(-1), thread.Handle, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenIsAlive() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::False(thread.IsAlive, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenIsAlive() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        Thread::Sleep(10);
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::True(thread.IsAlive, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenIsBackground() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::False(thread.IsBackground, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenGetName() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreEqual("", thread.Name, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenGetPriority() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenGetThreadState() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreEqual(ThreadState::Unstarted, thread.ThreadState, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenSetName() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::DoesNotThrows(pcf_delegate {thread.Name = "Thread";}, pcf_current_information);
      Assert::AreEqual("Thread", thread.Name);
    }
    
    void CreateThreadWithThreadStartThenSetPriority() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::DoesNotThrows(pcf_delegate {thread.Priority = ThreadPriority::Highest;}, pcf_current_information);
      Assert::AreEqual(ThreadPriority::Highest, thread.Priority);
    }
    
    void CreateThreadWithThreadStartThenAbort() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Abort();}, pcf_current_information);
      Assert::AreEqual(0, counter, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenAbort() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        Thread::Sleep(100);
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Thread::Sleep(5);
      Assert::Throws<ThreadAbortException>(pcf_delegate {thread.Abort();}, pcf_current_information);
      Assert::AreEqual(0, counter, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenSetIsBackgroundToTrue() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::DoesNotThrows(pcf_delegate {thread.IsBackground = true;}, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenGetHashCode() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::AreEqual(thread.ManagedThreadId, thread.GetHashCode(), pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenInterrupt() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Interrupt();}, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenInterrupt() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        Thread::Sleep(100);
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Thread::Sleep(5);
      Assert::Throws<ThreadInterruptedException>(pcf_delegate {thread.Interrupt();}, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenSuspend() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Suspend();}, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenResume() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Resume();}, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenResume() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Resume();}, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartStartItSuspendThenResume() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        Thread::Sleep(10);
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      thread.Suspend();
      Assert::DoesNotThrows(pcf_delegate {thread.Resume();}, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenStart() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::DoesNotThrows(pcf_delegate {thread.Start();}, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenStartWithParameterizedThreadStart() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      ParameterizedThreadStart parameterizedTeadStart = pcf_delegate(const object&) {};
      Assert::Throws<InvalidOperationException>(pcf_delegate {thread.Start(parameterizedTeadStart);}, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenJoin() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Join();}, pcf_current_information);
     }
    
    void CreateThreadWithThreadStartStartItThenJoin() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::DoesNotThrows(pcf_delegate {thread.Join();}, pcf_current_information);
      Assert::AreEqual(1, counter, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenJoinWithBadTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Join(-2);}, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenJoinWithBadTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {thread.Join(-2);}, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenJoinWithInfiniteTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::DoesNotThrows(pcf_delegate {thread.Join(Timeout::Infinite);}, pcf_current_information);
      Assert::AreEqual(1, counter, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartThenJoinWithTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Join(5);}, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenJoinWithTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::True(thread.Join(5), pcf_current_information);
      Assert::AreEqual(1, counter, pcf_current_information);
   }
    
    void CreateThreadWithThreadStartStartItThenJoinWithTimeSpanTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::True(thread.Join(TimeSpan::FromMilliseconds(5)), pcf_current_information);
      Assert::AreEqual(1, counter, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenJoinWithToShortTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        Thread::Sleep(20);
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::False(thread.Join(2), pcf_current_information);
      Assert::AreEqual(0, counter, pcf_current_information);
    }
    
    void CreateThreadWithThreadStartStartItThenJoinWithToShortTimeSpanTimeout() {
      static int32 counter;
      counter = 0;
      ThreadStart threadStart = pcf_delegate {
        Thread::Sleep(20);
        counter++;
      };
      Thread thread(threadStart);
      thread.Start();
      Assert::False(thread.Join(TimeSpan::FromMilliseconds(2)), pcf_current_information);
      Assert::AreEqual(0, counter, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetManagedThreadId() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::Greater(thread.ManagedThreadId, 1, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetHandle() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreNotEqual(intptr(-1), thread.Handle, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenIsAlive() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::False(thread.IsAlive, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenIsAlive() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Thread::Sleep(10);
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::True(thread.IsAlive, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenIsBackground() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::False(thread.IsBackground, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetName() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreEqual("", thread.Name, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetPriority() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreEqual(ThreadPriority::Normal, thread.Priority, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetThreadState() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        counter++;
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreEqual(ThreadState::Unstarted, thread.ThreadState, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenSetName() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(pcf_delegate {thread.Name = "Thread";}, pcf_current_information);
      Assert::AreEqual("Thread", thread.Name);
    }
    
    void CreateThreadWithParameterizedThreadStartThenSetPriority() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(pcf_delegate {thread.Priority = ThreadPriority::Highest;}, pcf_current_information);
      Assert::AreEqual(ThreadPriority::Highest, thread.Priority);
    }
    
    void CreateThreadWithParameterizedThreadStartThenAbort() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Abort();}, pcf_current_information);
      Assert::AreEqual(0, counter, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenAbort() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Thread::Sleep(100);
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Thread::Sleep(5);
      Assert::Throws<ThreadAbortException>(pcf_delegate {thread.Abort();}, pcf_current_information);
      Assert::AreEqual(0, counter, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenSetIsBackgroundToTrue() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(pcf_delegate {thread.IsBackground = true;}, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenGetHashCode() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::AreEqual(thread.ManagedThreadId, thread.GetHashCode(), pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenInterrupt() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Interrupt();}, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenInterrupt() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Thread::Sleep(100);
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Thread::Sleep(5);
      Assert::Throws<ThreadInterruptedException>(pcf_delegate {thread.Interrupt();}, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenSuspend() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Suspend();}, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenResume() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Resume();}, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenResume() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Resume();}, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItSuspendThenResume() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Thread::Sleep(10);
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      thread.Suspend();
      Assert::DoesNotThrows(pcf_delegate {thread.Resume();}, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenStart() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::IsInstanceOfType<Thread>(param, pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(pcf_delegate {thread.Start();}, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenStartWithThreadStart() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::DoesNotThrows(pcf_delegate {thread.Start(counter);}, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenJoin() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Join();}, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoin() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::DoesNotThrows(pcf_delegate {thread.Join();}, pcf_current_information);
      Assert::AreEqual(0, counter, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenJoinWithBadTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Join(-2);}, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithBadTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {thread.Join(-2);}, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenJoinWithInfiniteTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::DoesNotThrows(pcf_delegate {thread.Join(Timeout::Infinite);}, pcf_current_information);
      Assert::AreEqual(0, counter, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartThenJoinWithTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      Assert::Throws<ThreadStateException>(pcf_delegate {thread.Join(5);}, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::True(thread.Join(5), pcf_current_information);
      Assert::AreEqual(0, counter, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithTimeSpanTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::True(thread.Join(TimeSpan::FromMilliseconds(5)), pcf_current_information);
      Assert::AreEqual(0, counter, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithToShortTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Thread::Sleep(20);
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::False(thread.Join(2), pcf_current_information);
      Assert::AreEqual(0, counter, pcf_current_information);
    }
    
    void CreateThreadWithParameterizedThreadStartStartItThenJoinWithToShortTimeSpanTimeout() {
      static Int32 counter;
      counter = 0;
      ParameterizedThreadStart parameterizedThreadStart = pcf_delegate(const object& param) {
        Thread::Sleep(20);
        Assert::AreEqual(0, as<Int32>(param), pcf_current_information);
      };
      Thread thread(parameterizedThreadStart);
      thread.Start(counter);
      Assert::False(thread.Join(TimeSpan::FromMilliseconds(2)), pcf_current_information);
      Assert::AreEqual(0, counter, pcf_current_information);
    }
  };
  
  bool ThreadTest::hasMainThreadNamedOnlyOnce = false;

  pcf_test(ThreadTest, GetMainThreadThenGetManagedThreadId)
  pcf_test(ThreadTest, GetMainThreadThenGetHandle)
  pcf_test(ThreadTest, GetMainThreadThenIsAlive)
  pcf_test(ThreadTest, GetMainThreadThenIsBackground)
  pcf_test(ThreadTest, GetMainThreadThenGetName)
  pcf_test(ThreadTest, GetMainThreadThenGetPriority)
  pcf_test(ThreadTest, GetMainThreadThenGetThreadState)
  pcf_test(ThreadTest, GetMainThreadThenSetName)
  pcf_test(ThreadTest, GetMainThreadThenSetPriority)
  pcf_test(ThreadTest, GetMainThreadThenAbort)
  pcf_test(ThreadTest, GetMainThreadThenSetIsBackgroundToTrue)
  pcf_test(ThreadTest, GetMainThreadThenGetHashCode)
  pcf_test(ThreadTest, GetMainThreadThenInterrupt)
  pcf_test(ThreadTest, GetMainThreadThenJoin)
  pcf_test(ThreadTest, GetMainThreadThenJoinWithBadTimeout)
  pcf_test(ThreadTest, GetMainThreadThenJoinWithInfiniteTimeout)
  pcf_test(ThreadTest, GetMainThreadThenJoinWithTimeout)
  pcf_test(ThreadTest, GetMainThreadThenResume)
  pcf_test(ThreadTest, GetMainThreadThenStart)
  pcf_test(ThreadTest, GetMainThreadThenStartWithThreadStart)
  pcf_test(ThreadTest, GetMainThreadThenStartWithParameterizedThreadStart)
  pcf_test(ThreadTest, GetMainThreadThenSuspend)
  
  pcf_test(ThreadTest, CreateUnmanagedThreadThenGetManagedThreadId)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenGetHandle)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenIsAlive)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenIsBackground)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenGetName)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenGetPriority)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenGetThreadState)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenSetName)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenSetPriority)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenAbort)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenSetIsBackgroundToTrue)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenGetHashCode)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenInterrupt)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenJoin)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenJoinWithBadTimeout)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenJoinWithInfiniteTimeout)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenJoinWithTimeout)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenResume)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenStart)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenStartWithThreadStart)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenStartWithParameterizedThreadStart)
  pcf_test(ThreadTest, CreateUnmanagedThreadThenSuspend)
  
  pcf_test(ThreadTest, CreateEmptyThreadThenGetManagedThreadId)
  pcf_test(ThreadTest, CreateEmptyThreadThenGetHandle)
  pcf_test(ThreadTest, CreateEmptyThreadThenIsAlive)
  pcf_test(ThreadTest, CreateEmptyThreadThenIsBackground)
  pcf_test(ThreadTest, CreateEmptyThreadThenGetName)
  pcf_test(ThreadTest, CreateEmptyThreadThenGetPriority)
  pcf_test(ThreadTest, CreateEmptyThreadThenGetThreadState)
  pcf_test(ThreadTest, CreateEmptyThreadThenSetName)
  pcf_test(ThreadTest, CreateEmptyThreadThenSetPriority)
  pcf_test(ThreadTest, CreateEmptyThreadThenAbort)
  pcf_test(ThreadTest, CreateEmptyThreadThenSetIsBackgroundToTrue)
  pcf_test(ThreadTest, CreateEmptyThreadThenGetHashCode)
  pcf_test(ThreadTest, CreateEmptyThreadThenInterrupt)
  pcf_test(ThreadTest, CreateEmptyThreadThenJoin)
  pcf_test(ThreadTest, CreateEmptyThreadThenJoinWithBadTimeout)
  pcf_test(ThreadTest, CreateEmptyThreadThenJoinWithInfiniteTimeout)
  pcf_test(ThreadTest, CreateEmptyThreadThenJoinWithTimeout)
  pcf_test(ThreadTest, CreateEmptyThreadThenResume)
  pcf_test(ThreadTest, CreateEmptyThreadThenStart)
  pcf_test(ThreadTest, CreateEmptyThreadThenStartWithThreadStart)
  pcf_test(ThreadTest, CreateEmptyThreadThenStartWithParameterizedThreadStart)
  pcf_test(ThreadTest, CreateEmptyThreadThenSuspend)
  
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenGetManagedThreadId)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenGetHandle)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenIsAlive)
  pcf_test(ThreadTest, CreateThreadWithThreadStartStartItThenIsAlive)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenIsBackground)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenGetName)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenGetPriority)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenGetThreadState)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenSetName)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenSetPriority)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenAbort)
  pcf_test(ThreadTest, CreateThreadWithThreadStartStartItThenAbort)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenSetIsBackgroundToTrue)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenGetHashCode)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenInterrupt)
  pcf_test(ThreadTest, CreateThreadWithThreadStartStartItThenInterrupt)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenSuspend)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenResume)
  pcf_test(ThreadTest, CreateThreadWithThreadStartStartItThenResume)
  pcf_test(ThreadTest, CreateThreadWithThreadStartStartItSuspendThenResume)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenStart)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenStartWithParameterizedThreadStart)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenJoin)
  pcf_test(ThreadTest, CreateThreadWithThreadStartStartItThenJoin)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenJoinWithBadTimeout)
  pcf_test(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithBadTimeout)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenJoinWithInfiniteTimeout)
  pcf_test(ThreadTest, CreateThreadWithThreadStartThenJoinWithTimeout)
  pcf_test(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithTimeout)
  pcf_test(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithTimeSpanTimeout)
  pcf_test(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithToShortTimeout)
  pcf_test(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithToShortTimeSpanTimeout)
  
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetManagedThreadId)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetHandle)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenIsAlive)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenIsAlive)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenIsBackground)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetName)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetPriority)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetThreadState)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenSetName)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenSetPriority)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenAbort)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenAbort)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenSetIsBackgroundToTrue)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetHashCode)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenInterrupt)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenInterrupt)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenSuspend)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenResume)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenResume)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItSuspendThenResume)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenStart)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenStartWithThreadStart)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoin)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoin)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoinWithBadTimeout)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithBadTimeout)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoinWithInfiniteTimeout)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoinWithTimeout)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithTimeout)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithTimeSpanTimeout)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithToShortTimeout)
  pcf_test(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithToShortTimeSpanTimeout)
}

