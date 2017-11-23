#include <Switch/System/Collections/Generic/Stack.hpp>
#include <Switch/System/Threading/AutoResetEvent.hpp>
#include <Switch/System/Threading/Thread.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Threading;
using namespace TUnit;

namespace {

  TEST(Stack, Constructor) {
    Stack<Int32> Stack1;
    EXPECT_EQ(Stack1.Count, 0);
    
    Stack<Int32> Stack2(7);
    EXPECT_EQ(Stack2.Count, 0);
    
    Int32 NatArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Array<Int32> Array(NatArray, 10);
    Stack<Int32> Stack3(Array);
    EXPECT_EQ(Stack3.Count, 10);
  }
  
  TEST(Stack, Clear) {
    Int32 NatArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Array<Int32> Array(NatArray, 10);
    Stack<Int32> Stack(Array);
    EXPECT_EQ(Stack.Count, 10);
    Stack.Clear();
    EXPECT_EQ(Stack.Count, 0);
  }
  
  TEST(Stack, Contains) {
    Int32 NatArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Array<Int32> Array(NatArray, 10);
    Stack<Int32> Stack(Array);
    EXPECT_EQ(Stack.Contains(5), true);
    EXPECT_EQ(Stack.Contains(24), false);
  }
  
  TEST(Stack, CopyTo) {
    Int32 natArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Array<Int32> array(natArray, 10);
    Stack<Int32> stack(array);
    Array<Int32> array2(10);
    stack.CopyTo(array2);
    EXPECT_EQ((array2[0]), 10);
    EXPECT_EQ((array2[1]), 9);
    EXPECT_EQ((array2[2]), 8);
    EXPECT_EQ((array2[3]), 7);
    EXPECT_EQ((array2[4]), 6);
    EXPECT_EQ((array2[5]), 5);
    EXPECT_EQ((array2[6]), 4);
    EXPECT_EQ((array2[7]), 3);
    EXPECT_EQ((array2[8]), 2);
    EXPECT_EQ((array2[9]), 1);
  }
  
  TEST(Stack, Pop) {
    Int32 natArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Array<Int32> array(natArray, 10);
    Stack<Int32> stack(array);
    EXPECT_EQ(stack.Pop(), 10);
    EXPECT_EQ(stack.Pop(), 9);
    EXPECT_EQ(stack.Pop(), 8);
    EXPECT_EQ(stack.Pop(), 7);
    EXPECT_EQ(stack.Pop(), 6);
    EXPECT_EQ(stack.Pop(), 5);
    EXPECT_EQ(stack.Pop(), 4);
    EXPECT_EQ(stack.Pop(), 3);
    EXPECT_EQ(stack.Pop(), 2);
    EXPECT_EQ(stack.Pop(), 1);
    EXPECT_THROW(stack.Pop(), InvalidOperationException);
  }
  
  TEST(Stack, Push) {
    Stack<Int32> stack(10);
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    stack.Push(6);
    stack.Push(7);
    stack.Push(8);
    stack.Push(9);
    stack.Push(10);
    stack.Push(11);
    stack.Push(12);
    EXPECT_EQ(stack.Count, 12);
  }
  
  TEST(Stack, GetEnumerator) {
    Stack<Int32> stack(10);
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    stack.Push(6);
    stack.Push(7);
    stack.Push(8);
    stack.Push(9);
    stack.Push(10);
    stack.Push(11);
    stack.Push(12);
    Enumerator<Int32> enumerator = stack.GetEnumerator();
    Int32 index = 0;
    while (enumerator.MoveNext())
      EXPECT_EQ(enumerator.Current(), 12 - index++);
    EXPECT_EQ(index, 12);
  }
  
  TEST(Stack, GetSyncRoot) {
    Stack<Int32> stack(10);
    _lock(stack.SyncRoot) {
      stack.Push(1);
      stack.Push(2);
      stack.Push(3);
      stack.Push(4);
      stack.Push(5);
      stack.Push(6);
      stack.Push(7);
      stack.Push(8);
      stack.Push(9);
      stack.Push(10);
      stack.Push(11);
      stack.Push(12);
    }
    
    Enumerator<Int32> enumerator = stack.GetEnumerator();
    Int32 index = 0;
    while (enumerator.MoveNext())
      EXPECT_EQ(enumerator.Current(), 12 - index++);
    EXPECT_EQ(index, 12);
  }
  
  TEST(Stack, Peek) {
    Int32 natArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Array<Int32> array(natArray, 10);
    Stack<Int32> stack(array);
    EXPECT_EQ(stack.Count, 10);
    EXPECT_EQ(stack.Peek(), 10);
    EXPECT_EQ(stack.Count, 10);
  }
  
  TEST(Stack, ToArray) {
    Int32 natArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Array<Int32> array(natArray, 10);
    Stack<Int32> stack(array);
    
    Array<Int32> arrayDest = stack.ToArray();
    EXPECT_EQ(arrayDest.Length, 10);
    
    Enumerator<Int32> Enumerator = arrayDest.GetEnumerator();
    Int32 index = 0;
    while (Enumerator.MoveNext())
      EXPECT_EQ(Enumerator.Current(), 10 - index++);
    EXPECT_EQ(index, 10);
  }
  
  TEST(Stack, TrimExcess) {
    Stack<Int32> stack(10);
    stack.Push(1);
    stack.Push(2);
    stack.TrimExcess();
    EXPECT_EQ(stack.Count, 2);
  }
  
  class ThreadingHelper : public object {
  
  public:
    ThreadingHelper() : mEvent(false) { }
    
    static void PushThread(const Object& args);
    static void PopThread(const Object& args);
    
  private:
    Stack<Int32> mStack;
    AutoResetEvent mEvent;
  };
  
  /*
  void ThreadingHelper::PushThread(const Object& args) {
    int32 index = 0;
    ThreadingHelper *threadingHelper = &(ThreadingHelper&)args;
    while (index < 10) {
      _lock (threadingHelper->mStack.SyncRoot) {
        Thread::Sleep(20 + index); // Simulate threatment
        threadingHelper->mStack.Push(index++);
      }
      threadingHelper->mEvent.Set();
    }
    EXPECT_EQ(index, 10);
  }
  
  void ThreadingHelper::PopThread(const Object& args) {
    int32 index = 0;
    ThreadingHelper *threadingHelper = &(ThreadingHelper&)args;
  
    while (index < 10) {
      threadingHelper->mEvent.WaitOne();
      _lock (threadingHelper->mStack.SyncRoot) {
        EXPECT_EQ(threadingHelper->mStack.Pop(), index++);
        Thread::Sleep(10 + index); // Simulate threatment
      }
    }
    EXPECT_EQ(index, 10);
  }
  
  TEST(Stack, Threading) {
    ThreadingHelper threadingHelper;
  
    Thread PushThread(ThreadingHelper::PushThread);
    Thread PopThread(ThreadingHelper::PopThread);
  
    PushThread.Start(threadingHelper);
    PopThread.Start(threadingHelper);
  
    PushThread.Join();
    PushThread.Close();
    PopThread.Join();
    PopThread.Close();
  }
   */
}
