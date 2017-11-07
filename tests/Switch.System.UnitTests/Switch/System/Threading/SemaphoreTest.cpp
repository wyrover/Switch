#include <Switch/System/Threading/Semaphore.hpp>
#include <Switch/System/Threading/Mutex.hpp>
#include <Switch/System/Threading/Thread.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Threading;

namespace SwitchUnitTests {
  TEST(SemaphoreTest, CreateSemaphore) {
    Semaphore semaphore(0, 1);
    ASSERT_EQ("Switch::System::Threading::Semaphore", semaphore.ToString());
  }
  
  TEST(SemaphoreTest, CreateTwoSemaphore) {
    Semaphore semaphore1(0, 1);
    Semaphore semaphore2(0, 1);
    ASSERT_NE(semaphore1, semaphore2);
  }
  
  TEST(SemaphoreTest, CreateSemaphoreByCopy) {
    Semaphore semaphore1(0, 1);
    Semaphore semaphore2(semaphore1);
    ASSERT_EQ(semaphore1, semaphore2);
  }
  
  TEST(SemaphoreTest, CreateSemaphoreAndCopy) {
    Semaphore semaphore1(0, 1);
    Semaphore semaphore2(0, 1);
    ASSERT_NE(semaphore1, semaphore2);
    semaphore2 = semaphore1;
    ASSERT_EQ(semaphore1, semaphore2);
  }
  
  TEST(SemaphoreTest, CreateSemaphoreWithCountToZero) {
    Semaphore semaphore(0, 1);
    Thread thread(ThreadStart(_delegate {ASSERT_FALSE(semaphore.WaitOne(0));}));
    thread.Start();
    thread.Join();
  }
  
  TEST(SemaphoreTest, CreateSemaphoreWithCountToOne) {
    Semaphore semaphore(1, 1);
    Thread thread(ThreadStart(_delegate {ASSERT_TRUE(semaphore.WaitOne(0));}));
    thread.Start();
    thread.Join();
  }
  
  TEST(SemaphoreTest, CreateSemaphoreWithSameName) {
    Semaphore semaphore1(0, 1, "MySemaphore");
    Semaphore semaphore2(0, 1, "MySemaphore");
    ASSERT_EQ(semaphore1, semaphore2);
  }
  
  TEST(SemaphoreTest, CreateSemaphoreWithSameNameAndCreatedNew) {
    bool createdNew;
    Semaphore semaphore1(0, 1, "MySemaphore", createdNew);
    ASSERT_TRUE(createdNew);
    Semaphore semaphore2(0, 1, "MySemaphore", createdNew);
    ASSERT_FALSE(createdNew);
  }
  
  TEST(SemaphoreTest, CreateSemaphoreWithDifferentName) {
    Semaphore semaphore1(0, 1, "MySemaphore1");
    Semaphore semaphore2(0, 1, "MySemaphore2");
    ASSERT_NE(semaphore1, semaphore2);
  }
  
  TEST(SemaphoreTest, CreateSemaphoreWithDifferentNameAndCreatedNew) {
    bool createdNew;
    Semaphore semaphore1(0, 1, "MySemaphore1", createdNew);
    ASSERT_TRUE(createdNew);
    Semaphore semaphore2(0, 1, "MySemaphore2", createdNew);
    ASSERT_TRUE(createdNew);
  }
  
  TEST(SemaphoreTest, Close) {
    Semaphore semaphore(1, 1);
    semaphore.Close();
    ASSERT_THROW(semaphore.WaitOne(), ObjectDisposedException);
  }
  
  TEST(SemaphoreTest, OpenExistingWithSameName) {
    Semaphore semaphore1(0, 1, "MySemaphore");
    Semaphore semaphore2 = Semaphore::OpenExisting("MySemaphore");
    ASSERT_EQ(semaphore1, semaphore2);
  }
  
  TEST(SemaphoreTest, OpenExistingWithDifferentName) {
    Semaphore semaphore1(0, 1, "MySemaphore1");
    ASSERT_THROW(Semaphore semaphore2 = Semaphore::OpenExisting("MySemaphore2"), WaitHandleCannotBeOpenedException);
  }
  
  TEST(SemaphoreTest, TryOpenExistingWithSameName) {
    Semaphore semaphore1(0, 1, "MySemaphore");
    Semaphore semaphore2;
    ASSERT_TRUE(Semaphore::TryOpenExisting("MySemaphore", semaphore2));
    ASSERT_EQ(semaphore1, semaphore2);
  }
  
  TEST(SemaphoreTest, TryOpenExistingWithDifferentName) {
    Semaphore semaphore1(0, 1, "Semaphore1");
    Semaphore semaphore2;
    ASSERT_FALSE(Semaphore::TryOpenExisting("MyMSemaphore2", semaphore2));
  }
  
  TEST(SemaphoreTest, WaitAndRealese) {
    Semaphore semaphore(1, 1);
    ASSERT_TRUE(semaphore.WaitOne(0));
    ASSERT_NO_THROW(semaphore.Release());
  }
  
  TEST(SemaphoreTest, InitialCountTo0AndWait) {
    Semaphore semaphore(0, 1);
    ASSERT_FALSE(semaphore.WaitOne(0));
  }
  
  TEST(SemaphoreTest, InitialCountTo1AndWait) {
    Semaphore semaphore(1, 1);
    ASSERT_TRUE(semaphore.WaitOne(0));
    ASSERT_FALSE(semaphore.WaitOne(0));
  }
  
  TEST(SemaphoreTest, InitialCountTo2AndWait) {
    Semaphore semaphore(2, 2);
    ASSERT_TRUE(semaphore.WaitOne(0));
    ASSERT_TRUE(semaphore.WaitOne(0));
    ASSERT_FALSE(semaphore.WaitOne(0));
  }
  
  TEST(SemaphoreTest, MaximumCountTo2AndRelease) {
    Semaphore semaphore(0, 2);
    ASSERT_NO_THROW(semaphore.Release());
    ASSERT_NO_THROW(semaphore.Release());
    ASSERT_THROW(semaphore.Release(), SemaphoreFullException);
  }
  
  TEST(SemaphoreTest, ReleaseAndWait) {
    Semaphore semaphore(0, Int32::MaxValue);
    ASSERT_NO_THROW(semaphore.Release());
    ASSERT_NO_THROW(semaphore.Release());
    ASSERT_TRUE(semaphore.WaitOne(0));
    ASSERT_TRUE(semaphore.WaitOne(0));
    ASSERT_FALSE(semaphore.WaitOne(0));
  }
}

