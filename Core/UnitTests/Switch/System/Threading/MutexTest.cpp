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
      Assert::Throws<ObjectClosedException>(_delegate {
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
  
  _test(MutexTest, CreateMutex)
  _test(MutexTest, CreateTwoMutex)
  _test(MutexTest, CreateMutexByCopy)
  _test(MutexTest, CreateMutexAndCopy)
  _test(MutexTest, CreateMutexWithInitiallyOwnedToFalse)
  _test(MutexTest, CreateMutexWithInitiallyOwnedToTrue)
  _test(MutexTest, CreateMutexWithSameName)
  _test(MutexTest, CreateMutexWithSameNameAndCreatedNew)
  _test(MutexTest, CreateMutexWithDifferentName)
  _test(MutexTest, CreateMutexWithDifferentNameAndCreatedNew)
  _test(MutexTest, Close)
  _test(MutexTest, OpenExistingWithSameName)
  _test(MutexTest, OpenExistingWithDifferentName)
  _test(MutexTest, TryOpenExistingWithSameName)
  _test(MutexTest, TryOpenExistingWithDifferentName)
  _test(MutexTest, WaitAndRealese)
  _test(MutexTest, MulitpleWaitAndRealese)
}
