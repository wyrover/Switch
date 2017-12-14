#include <Switch/System/Threading/Mutex.hpp>
#include <Switch/System/Threading/Thread.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Threading;

namespace SwitchUnitTests {
  TEST(MutexTest, CreateMutex) {
    Mutex mutex;
    ASSERT_EQ("Switch::System::Threading::Mutex", mutex.ToString());
  }

  TEST(MutexTest, CreateTwoMutex) {
    Mutex mutex1;
    Mutex mutex2;
    ASSERT_NE(mutex1, mutex2);
  }

  TEST(MutexTest, CreateMutexByCopy) {
    Mutex mutex1;
    Mutex mutex2(mutex1);
    ASSERT_EQ(mutex1, mutex2);
  }

  TEST(MutexTest, CreateMutexAndCopy) {
    Mutex mutex1;
    Mutex mutex2;
    ASSERT_NE(mutex1, mutex2);
    mutex2 = mutex1;
    ASSERT_EQ(mutex1, mutex2);
  }

  TEST(MutexTest, CreateMutexWithInitiallyOwnedToFalse) {
    Mutex mutex(false);
    Thread thread(ThreadStart(_delegate {
      ASSERT_TRUE(mutex.WaitOne(0));
    }));
    thread.Start();
    thread.Join();
  }

  TEST(MutexTest, CreateMutexWithInitiallyOwnedToTrue) {
    Mutex mutex(true);
    Thread thread(ThreadStart(_delegate {
      ASSERT_FALSE(mutex.WaitOne(0));
    }));
    thread.Start();
    thread.Join();
  }

  TEST(MutexTest, CreateMutexWithSameName) {
    Mutex mutex1(false, "MyMutex");
    Mutex mutex2(false, "MyMutex");
    ASSERT_EQ(mutex1, mutex2);
  }

  TEST(MutexTest, CreateMutexWithSameNameAndCreatedNew) {
    bool createdNew;
    Mutex mutex1(false, "MyMutex", createdNew);
    ASSERT_TRUE(createdNew);
    Mutex mutex2(false, "MyMutex", createdNew);
    ASSERT_FALSE(createdNew);
  }

  TEST(MutexTest, CreateMutexWithDifferentName) {
    Mutex mutex1(false, "MyMutex1");
    Mutex mutex2(false, "MyMutex2");
    ASSERT_NE(mutex1, mutex2);
  }

  TEST(MutexTest, CreateMutexWithDifferentNameAndCreatedNew) {
    bool createdNew;
    Mutex mutex1(false, "MyMutex1", createdNew);
    ASSERT_TRUE(createdNew);
    Mutex mutex2(false, "MyMutex2", createdNew);
    ASSERT_TRUE(createdNew);
  }

  TEST(MutexTest, Close) {
    Mutex mutex;
    mutex.Close();
    ASSERT_THROW(mutex.WaitOne(), ObjectDisposedException);
  }

  TEST(MutexTest, OpenExistingWithSameName) {
    Mutex mutex1(false, "MyMutex");
    Mutex mutex2 = Mutex::OpenExisting("MyMutex");
    ASSERT_EQ(mutex1, mutex2);
  }

  TEST(MutexTest, OpenExistingWithDifferentName) {
    Mutex mutex1(false, "MyMutex1");
    ASSERT_THROW(Mutex mutex2 = Mutex::OpenExisting("MyMutex2"), WaitHandleCannotBeOpenedException);
  }

  TEST(MutexTest, TryOpenExistingWithSameName) {
    Mutex mutex1(false, "MyMutex");
    Mutex mutex2;
    ASSERT_TRUE(Mutex::TryOpenExisting("MyMutex", mutex2));
    ASSERT_EQ(mutex1, mutex2);
  }

  TEST(MutexTest, TryOpenExistingWithDifferentName) {
    Mutex mutex1(false, "MyMutex1");
    Mutex mutex2;
    ASSERT_FALSE(Mutex::TryOpenExisting("MyMutex2", mutex2));
  }

  TEST(MutexTest, WaitAndRealese) {
    Mutex mutex;
    ASSERT_TRUE(mutex.WaitOne(0));
    ASSERT_NO_THROW(mutex.ReleaseMutex());
  }

  TEST(MutexTest, MulitpleWaitAndRealese) {
    Mutex mutex;
    ASSERT_TRUE(mutex.WaitOne(0));
    ASSERT_TRUE(mutex.WaitOne(0));
    mutex.ReleaseMutex();
  }
}

