#include <Switch/System/Threading/Thread.hpp>
#include <Switch/System/Threading/AutoResetEvent.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Threading;

namespace {
  bool hasMainThreadNamedOnlyOnce = false;

  TEST(ThreadTest, GetMainThreadThenGetManagedThreadId) {
    Thread thread = Thread::CurrentThread();
    ASSERT_EQ(1, thread.ManagedThreadId);
  }

  TEST(ThreadTest, GetMainThreadThenGetHandle) {
    Thread thread = Thread::CurrentThread();
    ASSERT_NE(intptr(-1), thread.Handle);
  }

  TEST(ThreadTest, GetMainThreadThenIsAlive) {
    Thread thread = Thread::CurrentThread();
    ASSERT_TRUE(thread.IsAlive);
  }

  TEST(ThreadTest, GetMainThreadThenIsBackground) {
    Thread thread = Thread::CurrentThread();
    ASSERT_FALSE(thread.IsBackground);
  }

  TEST(ThreadTest, GetMainThreadThenGetName) {
    Thread thread = Thread::CurrentThread();
    if (!hasMainThreadNamedOnlyOnce)
      ASSERT_EQ("", thread.Name);
    else
      ASSERT_EQ("Main", thread.Name);
  }

  TEST(ThreadTest, GetMainThreadThenGetPriority) {
    Thread thread = Thread::CurrentThread();
    ASSERT_EQ(ThreadPriority::Normal, thread.Priority);
  }

  TEST(ThreadTest, GetMainThreadThenGetThreadState) {
    Thread thread = Thread::CurrentThread();
    ASSERT_EQ(ThreadState::Running, thread.ThreadState());
  }

  TEST(ThreadTest, GetMainThreadThenSetName) {
    Thread thread = Thread::CurrentThread();
    if (!hasMainThreadNamedOnlyOnce) {
      ASSERT_EQ("", thread.Name);
      ASSERT_NO_THROW(thread.Name = "Main");
      ASSERT_EQ("Main", thread.Name);
      hasMainThreadNamedOnlyOnce = true;
    } else {
      ASSERT_EQ("Main", thread.Name);
      ASSERT_THROW(thread.Name = "", InvalidOperationException);
    }
  }

  TEST(ThreadTest, GetMainThreadThenSetPriority) {
    Thread thread = Thread::CurrentThread();
    ASSERT_NO_THROW(thread.Priority = ThreadPriority::AboveNormal);
    ASSERT_EQ(ThreadPriority::AboveNormal, thread.Priority);
    ASSERT_NO_THROW(thread.Priority = ThreadPriority::Normal);
    ASSERT_EQ(ThreadPriority::Normal, thread.Priority);
  }

  TEST(ThreadTest, GetMainThreadThenAbort) {
    Thread thread = Thread::CurrentThread();
    // If you uncomments the next line, the unit tests will be aborted ;-)
    //ASSERT_NO_THROW(_delegate {thread.Abort());
  }

  TEST(ThreadTest, GetMainThreadThenSetIsBackgroundToTrue) {
    Thread thread = Thread::CurrentThread();
    ASSERT_THROW(thread.IsBackground = true, InvalidOperationException);
  }

  TEST(ThreadTest, GetMainThreadThenGetHashCode) {
    Thread thread = Thread::CurrentThread();
    ASSERT_EQ(1, thread.GetHashCode());
  }

  TEST(ThreadTest, GetMainThreadThenInterrupt) {
    Thread thread = Thread::CurrentThread();
    ASSERT_THROW(thread.Interrupt(), InvalidOperationException);
  }

  TEST(ThreadTest, GetMainThreadThenJoin) {
    Thread thread = Thread::CurrentThread();
    ASSERT_THROW(thread.Join(), InvalidOperationException);
  }

  TEST(ThreadTest, GetMainThreadThenJoinWithBadTimeout) {
    Thread thread = Thread::CurrentThread();
    ASSERT_THROW(thread.Join(-2), InvalidOperationException);
  }

  TEST(ThreadTest, GetMainThreadThenJoinWithInfiniteTimeout) {
    Thread thread = Thread::CurrentThread();
    ASSERT_THROW(thread.Join(Timeout::Infinite), InvalidOperationException);
  }

  TEST(ThreadTest, GetMainThreadThenJoinWithTimeout) {
    Thread thread = Thread::CurrentThread();
    ASSERT_THROW(thread.Join(1), InvalidOperationException);
  }

  TEST(ThreadTest, GetMainThreadThenResume) {
    Thread thread = Thread::CurrentThread();
    ASSERT_THROW(thread.Resume(), InvalidOperationException);
  }

  TEST(ThreadTest, GetMainThreadThenStart) {
    Thread thread = Thread::CurrentThread();
    ASSERT_THROW(thread.Start(), ThreadStateException);
  }

  TEST(ThreadTest, GetMainThreadThenStartWithThreadStart) {
    Thread thread = Thread::CurrentThread();
    ThreadStart threadStart = _delegate {};
    ASSERT_THROW(thread.Start(threadStart), ThreadStateException);
  }

  TEST(ThreadTest, GetMainThreadThenStartWithParameterizedThreadStart) {
    Thread thread = Thread::CurrentThread();
    ParameterizedThreadStart parameterizedTeadStart = _delegate(const object&) {};
    ASSERT_THROW(thread.Start(parameterizedTeadStart), ThreadStateException);
  }

  TEST(ThreadTest, GetMainThreadThenSuspend) {
    Thread thread = Thread::CurrentThread();
    ASSERT_THROW(thread.Suspend(), InvalidOperationException);
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenGetManagedThreadId) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_EQ(0, thread.ManagedThreadId);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenGetHandle) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_EQ(intptr(-1), thread.Handle);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenIsAlive) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_TRUE(thread.IsAlive);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenIsBackground) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_TRUE(thread.IsBackground);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenGetName) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_EQ("", thread.Name);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenGetPriority) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_EQ(ThreadPriority::Normal, thread.Priority);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenGetThreadState) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_EQ(ThreadState::Running, thread.ThreadState() & ThreadState::Running);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenSetName) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_THROW(thread.Name = "Unmanaged", InvalidOperationException);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenSetPriority) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_THROW(thread.Priority = ThreadPriority::Highest, InvalidOperationException);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenAbort) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_THROW(thread.Abort(), InvalidOperationException);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenSetIsBackgroundToTrue) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_THROW(thread.IsBackground = true, InvalidOperationException);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenGetHashCode) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_EQ(0, thread.GetHashCode());
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenInterrupt) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_THROW(thread.Interrupt(), InvalidOperationException);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenJoin) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_THROW(thread.Join(), InvalidOperationException);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenJoinWithBadTimeout) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_THROW(thread.Join(-2), InvalidOperationException);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenJoinWithInfiniteTimeout) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_THROW(thread.Join(Timeout::Infinite), InvalidOperationException);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenJoinWithTimeout) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_THROW(thread.Join(1), InvalidOperationException);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenResume) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_THROW(thread.Resume(), InvalidOperationException);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenStart) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_THROW(thread.Start(), ThreadStateException);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenStartWithThreadStart) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ThreadStart threadStart = _delegate {};
      ASSERT_THROW(thread.Start(threadStart), ThreadStateException);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenStartWithParameterizedThreadStart) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ParameterizedThreadStart parameterizedTeadStart = _delegate(const object&) {};
      ASSERT_THROW(thread.Start(parameterizedTeadStart), ThreadStateException);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateUnmanagedThreadThenSuspend) {
    std::function<void()> threadStart = [] {
      Thread thread = Thread::CurrentThread();
      ASSERT_THROW(thread.Suspend(), InvalidOperationException);
    };
    std::thread thread(threadStart);
    thread.join();
  }

  TEST(ThreadTest, CreateEmptyThreadThenGetManagedThreadId) {
    Thread thread;
    ASSERT_EQ(0, thread.ManagedThreadId);
  }

  TEST(ThreadTest, CreateEmptyThreadThenGetHandle) {
    Thread thread;
    ASSERT_EQ(intptr(-1), thread.Handle);
  }

  TEST(ThreadTest, CreateEmptyThreadThenIsAlive) {
    Thread thread;
    ASSERT_FALSE(thread.IsAlive);
  }

  TEST(ThreadTest, CreateEmptyThreadThenIsBackground) {
    Thread thread;
    ASSERT_FALSE(thread.IsBackground);
  }

  TEST(ThreadTest, CreateEmptyThreadThenGetName) {
    Thread thread;
    ASSERT_EQ("", thread.Name);
  }

  TEST(ThreadTest, CreateEmptyThreadThenGetPriority) {
    Thread thread;
    ASSERT_EQ(ThreadPriority::Normal, thread.Priority);
  }

  TEST(ThreadTest, CreateEmptyThreadThenGetThreadState) {
    Thread thread;
    ASSERT_EQ(ThreadState::Unstarted, thread.ThreadState);
  }

  TEST(ThreadTest, CreateEmptyThreadThenSetName) {
    Thread thread;
    ASSERT_THROW(thread.Name = "Empty", InvalidOperationException);
  }

  TEST(ThreadTest, CreateEmptyThreadThenSetPriority) {
    Thread thread;
    ASSERT_THROW(thread.Priority = ThreadPriority::Highest, InvalidOperationException);
  }

  TEST(ThreadTest, CreateEmptyThreadThenAbort) {
    Thread thread;
    ASSERT_THROW(thread.Abort(), InvalidOperationException);
  }

  TEST(ThreadTest, CreateEmptyThreadThenSetIsBackgroundToTrue) {
    Thread thread;
    ASSERT_THROW(thread.IsBackground = true, InvalidOperationException);
  }

  TEST(ThreadTest, CreateEmptyThreadThenGetHashCode) {
    Thread thread;
    ASSERT_EQ(0, thread.GetHashCode());
  }

  TEST(ThreadTest, CreateEmptyThreadThenInterrupt) {
    Thread thread;
    ASSERT_THROW(thread.Interrupt(), InvalidOperationException);
  }

  TEST(ThreadTest, CreateEmptyThreadThenJoin) {
    Thread thread;
    ASSERT_THROW(thread.Join(), InvalidOperationException);
  }

  TEST(ThreadTest, CreateEmptyThreadThenJoinWithBadTimeout) {
    Thread thread;
    ASSERT_THROW(thread.Join(-2), InvalidOperationException);
  }

  TEST(ThreadTest, CreateEmptyThreadThenJoinWithInfiniteTimeout) {
    Thread thread;
    ASSERT_THROW(thread.Join(Timeout::Infinite), InvalidOperationException);
  }

  TEST(ThreadTest, CreateEmptyThreadThenJoinWithTimeout) {
    Thread thread;
    ASSERT_THROW(thread.Join(1), InvalidOperationException);
  }

  TEST(ThreadTest, CreateEmptyThreadThenResume) {
    Thread thread;
    ASSERT_THROW(thread.Resume(), InvalidOperationException);
  }

  TEST(ThreadTest, CreateEmptyThreadThenStart) {
    Thread thread;
    ASSERT_THROW(thread.Start(), InvalidOperationException);
  }

  TEST(ThreadTest, CreateEmptyThreadThenStartWithThreadStart) {
    Thread thread;
    object obj;
    ASSERT_THROW(thread.Start(obj), InvalidOperationException);
  }

  TEST(ThreadTest, CreateEmptyThreadThenStartWithParameterizedThreadStart) {
    Thread thread;
    object obj;
    ASSERT_THROW(thread.Start(obj), InvalidOperationException);
  }

  TEST(ThreadTest, CreateEmptyThreadThenSuspend) {
    Thread thread;
    ASSERT_THROW(thread.Suspend(), InvalidOperationException);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenGetManagedThreadId) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_GT(thread.ManagedThreadId, 1);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenGetHandle) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_NE(intptr(-1), thread.Handle);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenIsAlive) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_FALSE(thread.IsAlive);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartStartItThenIsAlive) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      Thread::Sleep(10);
      counter++;
    };
    Thread thread(threadStart);
    thread.Start();
    ASSERT_TRUE(thread.IsAlive);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenIsBackground) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_FALSE(thread.IsBackground);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenGetName) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_EQ("", thread.Name);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenGetPriority) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_EQ(ThreadPriority::Normal, thread.Priority);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenGetThreadState) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_EQ(ThreadState::Unstarted, thread.ThreadState);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenSetName) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_NO_THROW(thread.Name = "Thread");
    ASSERT_EQ("Thread", thread.Name);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenSetPriority) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_NO_THROW(thread.Priority = ThreadPriority::Highest);
    ASSERT_EQ(ThreadPriority::Highest, thread.Priority);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenAbort) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_THROW(thread.Abort(), ThreadStateException);
    ASSERT_EQ(0, counter);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartStartItThenAbort) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      Thread::Sleep(100);
      counter++;
    };
    Thread thread(threadStart);
    thread.Start();
    Thread::Sleep(5);
    ASSERT_THROW(thread.Abort(), ThreadAbortException);
    ASSERT_EQ(0, counter);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenSetIsBackgroundToTrue) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_NO_THROW(thread.IsBackground = true);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenGetHashCode) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_EQ(thread.ManagedThreadId, thread.GetHashCode());
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenInterrupt) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_THROW(thread.Interrupt(), ThreadStateException);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartStartItThenInterrupt) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      Thread::Sleep(100);
      counter++;
    };
    Thread thread(threadStart);
    thread.Start();
    Thread::Sleep(5);
    ASSERT_THROW(thread.Interrupt(), ThreadInterruptedException);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenSuspend) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_THROW(thread.Suspend(), ThreadStateException);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenResume) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_THROW(thread.Resume(), ThreadStateException);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartStartItThenResume) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    thread.Start();
    ASSERT_THROW(thread.Resume(), ThreadStateException);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartStartItSuspendThenResume) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      Thread::Sleep(10);
      counter++;
    };
    Thread thread(threadStart);
    thread.Start();
    thread.Suspend();
    ASSERT_NO_THROW(thread.Resume());
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenStart) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_NO_THROW(thread.Start());
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenStartWithParameterizedThreadStart) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ParameterizedThreadStart parameterizedTeadStart = _delegate(const object&) {};
    ASSERT_THROW(thread.Start(parameterizedTeadStart), InvalidOperationException);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenJoin) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_THROW(thread.Join(), ThreadStateException);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartStartItThenJoin) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    thread.Start();
    ASSERT_NO_THROW(thread.Join());
    ASSERT_EQ(1, counter);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenJoinWithBadTimeout) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_THROW(thread.Join(-2), ThreadStateException);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithBadTimeout) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    thread.Start();
    ASSERT_THROW(thread.Join(-2), ArgumentOutOfRangeException);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenJoinWithInfiniteTimeout) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    thread.Start();
    ASSERT_NO_THROW(thread.Join(Timeout::Infinite));
    ASSERT_EQ(1, counter);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartThenJoinWithTimeout) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    ASSERT_THROW(thread.Join(5), ThreadStateException);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithTimeout) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    thread.Start();
    ASSERT_TRUE(thread.Join(5));
    ASSERT_EQ(1, counter);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithTimeSpanTimeout) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      counter++;
    };
    Thread thread(threadStart);
    thread.Start();
    ASSERT_TRUE(thread.Join(TimeSpan::FromMilliseconds(5)));
    ASSERT_EQ(1, counter);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithToShortTimeout) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      Thread::Sleep(20);
      counter++;
    };
    Thread thread(threadStart);
    thread.Start();
    ASSERT_FALSE(thread.Join(2));
    ASSERT_EQ(0, counter);
  }

  TEST(ThreadTest, CreateThreadWithThreadStartStartItThenJoinWithToShortTimeSpanTimeout) {
    static int32 counter;
    counter = 0;
    ThreadStart threadStart = _delegate {
      Thread::Sleep(20);
      counter++;
    };
    Thread thread(threadStart);
    thread.Start();
    ASSERT_FALSE(thread.Join(TimeSpan::FromMilliseconds(2)));
    ASSERT_EQ(0, counter);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetManagedThreadId) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      counter++;
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_GT(thread.ManagedThreadId, 1);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetHandle) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      counter++;
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_NE(intptr(-1), thread.Handle);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenIsAlive) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      counter++;
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_FALSE(thread.IsAlive);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenIsAlive) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      Thread::Sleep(10);
      counter++;
    };
    Thread thread(parameterizedThreadStart);
    thread.Start(counter);
    ASSERT_TRUE(thread.IsAlive);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenIsBackground) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      counter++;
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_FALSE(thread.IsBackground);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetName) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      counter++;
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_EQ("", thread.Name);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetPriority) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      counter++;
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_EQ(ThreadPriority::Normal, thread.Priority);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetThreadState) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      counter++;
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_EQ(ThreadState::Unstarted, thread.ThreadState);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenSetName) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_NO_THROW(thread.Name = "Thread");
    ASSERT_EQ("Thread", thread.Name);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenSetPriority) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_NO_THROW(thread.Priority = ThreadPriority::Highest);
    ASSERT_EQ(ThreadPriority::Highest, thread.Priority);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenAbort) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_THROW(thread.Abort(), ThreadStateException);
    ASSERT_EQ(0, counter);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenAbort) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      Thread::Sleep(100);
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    thread.Start(counter);
    Thread::Sleep(5);
    ASSERT_THROW(thread.Abort(), ThreadAbortException);
    ASSERT_EQ(0, counter);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenSetIsBackgroundToTrue) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_NO_THROW(thread.IsBackground = true);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenGetHashCode) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_EQ(thread.ManagedThreadId, thread.GetHashCode());
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenInterrupt) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_THROW(thread.Interrupt(), ThreadStateException);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenInterrupt) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      Thread::Sleep(100);
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    thread.Start(counter);
    Thread::Sleep(5);
    ASSERT_THROW(thread.Interrupt(), ThreadInterruptedException);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenSuspend) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_THROW(thread.Suspend(), ThreadStateException);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenResume) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_THROW(thread.Resume(), ThreadStateException);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenResume) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    thread.Start(counter);
    ASSERT_THROW(thread.Resume(), ThreadStateException);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartStartItSuspendThenResume) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      Thread::Sleep(10);
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    thread.Start(counter);
    thread.Suspend();
    ASSERT_NO_THROW(thread.Resume());
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenStart) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_TRUE(is<Thread>(param));
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_NO_THROW(thread.Start());
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenStartWithThreadStart) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_NO_THROW(thread.Start(counter));
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoin) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_THROW(thread.Join(), ThreadStateException);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoin) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    thread.Start(counter);
    ASSERT_NO_THROW(thread.Join());
    ASSERT_EQ(0, counter);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoinWithBadTimeout) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_THROW(thread.Join(-2), ThreadStateException);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithBadTimeout) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    thread.Start(counter);
    ASSERT_THROW(thread.Join(-2), ArgumentOutOfRangeException);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoinWithInfiniteTimeout) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    thread.Start(counter);
    ASSERT_NO_THROW(thread.Join(Timeout::Infinite));
    ASSERT_EQ(0, counter);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartThenJoinWithTimeout) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    ASSERT_THROW(thread.Join(5), ThreadStateException);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithTimeout) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    thread.Start(counter);
    ASSERT_TRUE(thread.Join(5));
    ASSERT_EQ(0, counter);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithTimeSpanTimeout) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    thread.Start(counter);
    ASSERT_TRUE(thread.Join(TimeSpan::FromMilliseconds(5)));
    ASSERT_EQ(0, counter);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithToShortTimeout) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      Thread::Sleep(20);
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    thread.Start(counter);
    ASSERT_FALSE(thread.Join(2));
    ASSERT_EQ(0, counter);
  }

  TEST(ThreadTest, CreateThreadWithParameterizedThreadStartStartItThenJoinWithToShortTimeSpanTimeout) {
    static Int32 counter;
    counter = 0;
    ParameterizedThreadStart parameterizedThreadStart = _delegate(const object & param) {
      Thread::Sleep(20);
      ASSERT_EQ(0, as<Int32>(param));
    };
    Thread thread(parameterizedThreadStart);
    thread.Start(counter);
    ASSERT_FALSE(thread.Join(TimeSpan::FromMilliseconds(2)));
    ASSERT_EQ(0, counter);
  }
}
