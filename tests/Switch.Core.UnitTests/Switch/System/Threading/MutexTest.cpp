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
      Assert::AreEqual("Switch::System::Threading::Mutex", mutex.ToString(), _caller);
    }
    
    void CreateTwoMutex() {
      Mutex mutex1;
      Mutex mutex2;
      Assert::AreNotEqual(mutex1, mutex2, _caller);
    }
    
    void CreateMutexByCopy() {
      Mutex mutex1;
      Mutex mutex2(mutex1);
      Assert::AreEqual(mutex1, mutex2, _caller);
    }
    
    void CreateMutexAndCopy() {
      Mutex mutex1;
      Mutex mutex2;
      Assert::AreNotEqual(mutex1, mutex2, _caller);
      mutex2 = mutex1;
      Assert::AreEqual(mutex1, mutex2, _caller);
    }
    
    void CreateMutexWithInitiallyOwnedToFalse() {
      Mutex mutex(false);
      Thread thread(ThreadStart(_delegate {
        Assert::IsTrue(mutex.WaitOne(0), _caller);
      }));
      thread.Start();
      thread.Join();
    }
    
    void CreateMutexWithInitiallyOwnedToTrue() {
      Mutex mutex(true);
      Thread thread(ThreadStart(_delegate {
        Assert::IsFalse(mutex.WaitOne(0), _caller);
      }));
      thread.Start();
      thread.Join();
    }
    
    void CreateMutexWithSameName() {
      Mutex mutex1(false, "MyMutex");
      Mutex mutex2(false, "MyMutex");
      Assert::AreEqual(mutex1, mutex2, _caller);
    }
    
    void CreateMutexWithSameNameAndCreatedNew() {
      bool createdNew;
      Mutex mutex1(false, "MyMutex", createdNew);
      Assert::IsTrue(createdNew, _caller);
      Mutex mutex2(false, "MyMutex", createdNew);
      Assert::IsFalse(createdNew, _caller);
    }
    
    void CreateMutexWithDifferentName() {
      Mutex mutex1(false, "MyMutex1");
      Mutex mutex2(false, "MyMutex2");
      Assert::AreNotEqual(mutex1, mutex2, _caller);
    }
    
    void CreateMutexWithDifferentNameAndCreatedNew() {
      bool createdNew;
      Mutex mutex1(false, "MyMutex1", createdNew);
      Assert::IsTrue(createdNew, _caller);
      Mutex mutex2(false, "MyMutex2", createdNew);
      Assert::IsTrue(createdNew, _caller);
    }
    
    void Close() {
      Mutex mutex;
      mutex.Close();
      Assert::Throws<ObjectDisposedException>(_delegate {
        mutex.WaitOne();
      }, _caller);
    }
    
    void OpenExistingWithSameName() {
      Mutex mutex1(false, "MyMutex");
      Mutex mutex2 = Mutex::OpenExisting("MyMutex");
      Assert::AreEqual(mutex1, mutex2, _caller);
    }
    
    void OpenExistingWithDifferentName() {
      Mutex mutex1(false, "MyMutex1");
      Assert::Throws<WaitHandleCannotBeOpenedException>(_delegate {
        Mutex mutex2 = Mutex::OpenExisting("MyMutex2");
      }, _caller);
    }
    
    void TryOpenExistingWithSameName() {
      Mutex mutex1(false, "MyMutex");
      Mutex mutex2;
      Assert::IsTrue(Mutex::TryOpenExisting("MyMutex", mutex2), _caller);
      Assert::AreEqual(mutex1, mutex2, _caller);
    }
    
    void TryOpenExistingWithDifferentName() {
      Mutex mutex1(false, "MyMutex1");
      Mutex mutex2;
      Assert::IsFalse(Mutex::TryOpenExisting("MyMutex2", mutex2), _caller);
    }
    
    void WaitAndRealese() {
      Mutex mutex;
      Assert::IsTrue(mutex.WaitOne(0), _caller);
      Assert::DoesNotThrows(_delegate {
        mutex.ReleaseMutex();
      }, _caller);
    }
    
    void MulitpleWaitAndRealese() {
      Mutex mutex;
      Assert::IsTrue(mutex.WaitOne(0), _caller);
      Assert::IsTrue(mutex.WaitOne(0), _caller);
      mutex.ReleaseMutex();
    }
  };
  
  _AddTest(MutexTest, CreateMutex)
  _AddTest(MutexTest, CreateTwoMutex)
  _AddTest(MutexTest, CreateMutexByCopy)
  _AddTest(MutexTest, CreateMutexAndCopy)
  _AddTest(MutexTest, CreateMutexWithInitiallyOwnedToFalse)
  _AddTest(MutexTest, CreateMutexWithInitiallyOwnedToTrue)
  _AddTest(MutexTest, CreateMutexWithSameName)
  _AddTest(MutexTest, CreateMutexWithSameNameAndCreatedNew)
  _AddTest(MutexTest, CreateMutexWithDifferentName)
  _AddTest(MutexTest, CreateMutexWithDifferentNameAndCreatedNew)
  _AddTest(MutexTest, Close)
  _AddTest(MutexTest, OpenExistingWithSameName)
  _AddTest(MutexTest, OpenExistingWithDifferentName)
  _AddTest(MutexTest, TryOpenExistingWithSameName)
  _AddTest(MutexTest, TryOpenExistingWithDifferentName)
  _AddTest(MutexTest, WaitAndRealese)
  _AddTest(MutexTest, MulitpleWaitAndRealese)
}
