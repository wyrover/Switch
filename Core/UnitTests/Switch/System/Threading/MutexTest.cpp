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
      Assert::AreEqual("Switch::System::Threading::Mutex", mutex.ToString(), pcf_current_information);
    }
    
    void CreateTwoMutex() {
      Mutex mutex1;
      Mutex mutex2;
      Assert::AreNotEqual(mutex1, mutex2, pcf_current_information);
    }
    
    void CreateMutexByCopy() {
      Mutex mutex1;
      Mutex mutex2(mutex1);
      Assert::AreEqual(mutex1, mutex2, pcf_current_information);
    }
    
    void CreateMutexAndCopy() {
      Mutex mutex1;
      Mutex mutex2;
      Assert::AreNotEqual(mutex1, mutex2, pcf_current_information);
      mutex2 = mutex1;
      Assert::AreEqual(mutex1, mutex2, pcf_current_information);
    }
    
    void CreateMutexWithInitiallyOwnedToFalse() {
      Mutex mutex(false);
      Thread thread(ThreadStart(pcf_delegate {
        Assert::IsTrue(mutex.WaitOne(0), pcf_current_information);
      }));
      thread.Start();
      thread.Join();
    }
    
    void CreateMutexWithInitiallyOwnedToTrue() {
      Mutex mutex(true);
      Thread thread(ThreadStart(pcf_delegate {
        Assert::IsFalse(mutex.WaitOne(0), pcf_current_information);
      }));
      thread.Start();
      thread.Join();
    }
    
    void CreateMutexWithSameName() {
      Mutex mutex1(false, "MyMutex");
      Mutex mutex2(false, "MyMutex");
      Assert::AreEqual(mutex1, mutex2, pcf_current_information);
    }
    
    void CreateMutexWithSameNameAndCreatedNew() {
      bool createdNew;
      Mutex mutex1(false, "MyMutex", createdNew);
      Assert::IsTrue(createdNew, pcf_current_information);
      Mutex mutex2(false, "MyMutex", createdNew);
      Assert::IsFalse(createdNew, pcf_current_information);
    }
    
    void CreateMutexWithDifferentName() {
      Mutex mutex1(false, "MyMutex1");
      Mutex mutex2(false, "MyMutex2");
      Assert::AreNotEqual(mutex1, mutex2, pcf_current_information);
    }
    
    void CreateMutexWithDifferentNameAndCreatedNew() {
      bool createdNew;
      Mutex mutex1(false, "MyMutex1", createdNew);
      Assert::IsTrue(createdNew, pcf_current_information);
      Mutex mutex2(false, "MyMutex2", createdNew);
      Assert::IsTrue(createdNew, pcf_current_information);
    }
    
    void Close() {
      Mutex mutex;
      mutex.Close();
      Assert::Throws<ObjectClosedException>(pcf_delegate {
        mutex.WaitOne();
      }, pcf_current_information);
    }
    
    void OpenExistingWithSameName() {
      Mutex mutex1(false, "MyMutex");
      Mutex mutex2 = Mutex::OpenExisting("MyMutex");
      Assert::AreEqual(mutex1, mutex2, pcf_current_information);
    }
    
    void OpenExistingWithDifferentName() {
      Mutex mutex1(false, "MyMutex1");
      Assert::Throws<WaitHandleCannotBeOpenedException>(pcf_delegate {
        Mutex mutex2 = Mutex::OpenExisting("MyMutex2");
      }, pcf_current_information);
    }
    
    void TryOpenExistingWithSameName() {
      Mutex mutex1(false, "MyMutex");
      Mutex mutex2;
      Assert::IsTrue(Mutex::TryOpenExisting("MyMutex", mutex2), pcf_current_information);
      Assert::AreEqual(mutex1, mutex2, pcf_current_information);
    }
    
    void TryOpenExistingWithDifferentName() {
      Mutex mutex1(false, "MyMutex1");
      Mutex mutex2;
      Assert::IsFalse(Mutex::TryOpenExisting("MyMutex2", mutex2), pcf_current_information);
    }
    
    void WaitAndRealese() {
      Mutex mutex;
      Assert::IsTrue(mutex.WaitOne(0), pcf_current_information);
      Assert::DoesNotThrows(pcf_delegate {
        mutex.ReleaseMutex();
      }, pcf_current_information);
    }
    
    void MulitpleWaitAndRealese() {
      Mutex mutex;
      Assert::IsTrue(mutex.WaitOne(0), pcf_current_information);
      Assert::IsTrue(mutex.WaitOne(0), pcf_current_information);
      mutex.ReleaseMutex();
    }
  };
  
  pcf_test(MutexTest, CreateMutex)
  pcf_test(MutexTest, CreateTwoMutex)
  pcf_test(MutexTest, CreateMutexByCopy)
  pcf_test(MutexTest, CreateMutexAndCopy)
  pcf_test(MutexTest, CreateMutexWithInitiallyOwnedToFalse)
  pcf_test(MutexTest, CreateMutexWithInitiallyOwnedToTrue)
  pcf_test(MutexTest, CreateMutexWithSameName)
  pcf_test(MutexTest, CreateMutexWithSameNameAndCreatedNew)
  pcf_test(MutexTest, CreateMutexWithDifferentName)
  pcf_test(MutexTest, CreateMutexWithDifferentNameAndCreatedNew)
  pcf_test(MutexTest, Close)
  pcf_test(MutexTest, OpenExistingWithSameName)
  pcf_test(MutexTest, OpenExistingWithDifferentName)
  pcf_test(MutexTest, TryOpenExistingWithSameName)
  pcf_test(MutexTest, TryOpenExistingWithDifferentName)
  pcf_test(MutexTest, WaitAndRealese)
  pcf_test(MutexTest, MulitpleWaitAndRealese)
}
