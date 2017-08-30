#include <Switch/System/Threading/Mutex.hpp>
#include <Switch/System/Threading/Thread.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Threading;
using namespace TUnit;

namespace SwitchUnitTests {
  class MutexTest : public TestFixture {
  protected:
    void CreateMutex() {
      Mutex mutex;
      Assert::AreEqual("Switch::System::Threading::Mutex", mutex.ToString(), sw_current_information);
    }
    
    void CreateTwoMutex() {
      Mutex mutex1;
      Mutex mutex2;
      Assert::AreNotEqual(mutex1, mutex2, sw_current_information);
    }
    
    void CreateMutexByCopy() {
      Mutex mutex1;
      Mutex mutex2(mutex1);
      Assert::AreEqual(mutex1, mutex2, sw_current_information);
    }
    
    void CreateMutexAndCopy() {
      Mutex mutex1;
      Mutex mutex2;
      Assert::AreNotEqual(mutex1, mutex2, sw_current_information);
      mutex2 = mutex1;
      Assert::AreEqual(mutex1, mutex2, sw_current_information);
    }
    
    void CreateMutexWithInitiallyOwnedToFalse() {
      Mutex mutex(false);
      Thread thread(ThreadStart(sw_delegate {
        Assert::IsTrue(mutex.WaitOne(0), sw_current_information);
      }));
      thread.Start();
      thread.Join();
    }
    
    void CreateMutexWithInitiallyOwnedToTrue() {
      Mutex mutex(true);
      Thread thread(ThreadStart(sw_delegate {
        Assert::IsFalse(mutex.WaitOne(0), sw_current_information);
      }));
      thread.Start();
      thread.Join();
    }
    
    void CreateMutexWithSameName() {
      Mutex mutex1(false, "MyMutex");
      Mutex mutex2(false, "MyMutex");
      Assert::AreEqual(mutex1, mutex2, sw_current_information);
    }
    
    void CreateMutexWithSameNameAndCreatedNew() {
      bool createdNew;
      Mutex mutex1(false, "MyMutex", createdNew);
      Assert::IsTrue(createdNew, sw_current_information);
      Mutex mutex2(false, "MyMutex", createdNew);
      Assert::IsFalse(createdNew, sw_current_information);
    }
    
    void CreateMutexWithDifferentName() {
      Mutex mutex1(false, "MyMutex1");
      Mutex mutex2(false, "MyMutex2");
      Assert::AreNotEqual(mutex1, mutex2, sw_current_information);
    }
    
    void CreateMutexWithDifferentNameAndCreatedNew() {
      bool createdNew;
      Mutex mutex1(false, "MyMutex1", createdNew);
      Assert::IsTrue(createdNew, sw_current_information);
      Mutex mutex2(false, "MyMutex2", createdNew);
      Assert::IsTrue(createdNew, sw_current_information);
    }
    
    void Close() {
      Mutex mutex;
      mutex.Close();
      Assert::Throws<ObjectClosedException>(sw_delegate {
        mutex.WaitOne();
      }, sw_current_information);
    }
    
    void OpenExistingWithSameName() {
      Mutex mutex1(false, "MyMutex");
      Mutex mutex2 = Mutex::OpenExisting("MyMutex");
      Assert::AreEqual(mutex1, mutex2, sw_current_information);
    }
    
    void OpenExistingWithDifferentName() {
      Mutex mutex1(false, "MyMutex1");
      Assert::Throws<WaitHandleCannotBeOpenedException>(sw_delegate {
        Mutex mutex2 = Mutex::OpenExisting("MyMutex2");
      }, sw_current_information);
    }
    
    void TryOpenExistingWithSameName() {
      Mutex mutex1(false, "MyMutex");
      Mutex mutex2;
      Assert::IsTrue(Mutex::TryOpenExisting("MyMutex", mutex2), sw_current_information);
      Assert::AreEqual(mutex1, mutex2, sw_current_information);
    }
    
    void TryOpenExistingWithDifferentName() {
      Mutex mutex1(false, "MyMutex1");
      Mutex mutex2;
      Assert::IsFalse(Mutex::TryOpenExisting("MyMutex2", mutex2), sw_current_information);
    }
    
    void WaitAndRealese() {
      Mutex mutex;
      Assert::IsTrue(mutex.WaitOne(0), sw_current_information);
      Assert::DoesNotThrows(sw_delegate {
        mutex.ReleaseMutex();
      }, sw_current_information);
    }
    
    void MulitpleWaitAndRealese() {
      Mutex mutex;
      Assert::IsTrue(mutex.WaitOne(0), sw_current_information);
      Assert::IsTrue(mutex.WaitOne(0), sw_current_information);
      mutex.ReleaseMutex();
    }
  };
  
  sw_test(MutexTest, CreateMutex)
  sw_test(MutexTest, CreateTwoMutex)
  sw_test(MutexTest, CreateMutexByCopy)
  sw_test(MutexTest, CreateMutexAndCopy)
  sw_test(MutexTest, CreateMutexWithInitiallyOwnedToFalse)
  sw_test(MutexTest, CreateMutexWithInitiallyOwnedToTrue)
  sw_test(MutexTest, CreateMutexWithSameName)
  sw_test(MutexTest, CreateMutexWithSameNameAndCreatedNew)
  sw_test(MutexTest, CreateMutexWithDifferentName)
  sw_test(MutexTest, CreateMutexWithDifferentNameAndCreatedNew)
  sw_test(MutexTest, Close)
  sw_test(MutexTest, OpenExistingWithSameName)
  sw_test(MutexTest, OpenExistingWithDifferentName)
  sw_test(MutexTest, TryOpenExistingWithSameName)
  sw_test(MutexTest, TryOpenExistingWithDifferentName)
  sw_test(MutexTest, WaitAndRealese)
  sw_test(MutexTest, MulitpleWaitAndRealese)
}
