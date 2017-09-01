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
      Assert::AreEqual("Switch::System::Threading::Mutex", mutex.ToString(), _current_information);
    }
    
    void CreateTwoMutex() {
      Mutex mutex1;
      Mutex mutex2;
      Assert::AreNotEqual(mutex1, mutex2, _current_information);
    }
    
    void CreateMutexByCopy() {
      Mutex mutex1;
      Mutex mutex2(mutex1);
      Assert::AreEqual(mutex1, mutex2, _current_information);
    }
    
    void CreateMutexAndCopy() {
      Mutex mutex1;
      Mutex mutex2;
      Assert::AreNotEqual(mutex1, mutex2, _current_information);
      mutex2 = mutex1;
      Assert::AreEqual(mutex1, mutex2, _current_information);
    }
    
    void CreateMutexWithInitiallyOwnedToFalse() {
      Mutex mutex(false);
      Thread thread(ThreadStart(_delegate {
        Assert::IsTrue(mutex.WaitOne(0), _current_information);
      }));
      thread.Start();
      thread.Join();
    }
    
    void CreateMutexWithInitiallyOwnedToTrue() {
      Mutex mutex(true);
      Thread thread(ThreadStart(_delegate {
        Assert::IsFalse(mutex.WaitOne(0), _current_information);
      }));
      thread.Start();
      thread.Join();
    }
    
    void CreateMutexWithSameName() {
      Mutex mutex1(false, "MyMutex");
      Mutex mutex2(false, "MyMutex");
      Assert::AreEqual(mutex1, mutex2, _current_information);
    }
    
    void CreateMutexWithSameNameAndCreatedNew() {
      bool createdNew;
      Mutex mutex1(false, "MyMutex", createdNew);
      Assert::IsTrue(createdNew, _current_information);
      Mutex mutex2(false, "MyMutex", createdNew);
      Assert::IsFalse(createdNew, _current_information);
    }
    
    void CreateMutexWithDifferentName() {
      Mutex mutex1(false, "MyMutex1");
      Mutex mutex2(false, "MyMutex2");
      Assert::AreNotEqual(mutex1, mutex2, _current_information);
    }
    
    void CreateMutexWithDifferentNameAndCreatedNew() {
      bool createdNew;
      Mutex mutex1(false, "MyMutex1", createdNew);
      Assert::IsTrue(createdNew, _current_information);
      Mutex mutex2(false, "MyMutex2", createdNew);
      Assert::IsTrue(createdNew, _current_information);
    }
    
    void Close() {
      Mutex mutex;
      mutex.Close();
      Assert::Throws<ObjectClosedException>(_delegate {
        mutex.WaitOne();
      }, _current_information);
    }
    
    void OpenExistingWithSameName() {
      Mutex mutex1(false, "MyMutex");
      Mutex mutex2 = Mutex::OpenExisting("MyMutex");
      Assert::AreEqual(mutex1, mutex2, _current_information);
    }
    
    void OpenExistingWithDifferentName() {
      Mutex mutex1(false, "MyMutex1");
      Assert::Throws<WaitHandleCannotBeOpenedException>(_delegate {
        Mutex mutex2 = Mutex::OpenExisting("MyMutex2");
      }, _current_information);
    }
    
    void TryOpenExistingWithSameName() {
      Mutex mutex1(false, "MyMutex");
      Mutex mutex2;
      Assert::IsTrue(Mutex::TryOpenExisting("MyMutex", mutex2), _current_information);
      Assert::AreEqual(mutex1, mutex2, _current_information);
    }
    
    void TryOpenExistingWithDifferentName() {
      Mutex mutex1(false, "MyMutex1");
      Mutex mutex2;
      Assert::IsFalse(Mutex::TryOpenExisting("MyMutex2", mutex2), _current_information);
    }
    
    void WaitAndRealese() {
      Mutex mutex;
      Assert::IsTrue(mutex.WaitOne(0), _current_information);
      Assert::DoesNotThrows(_delegate {
        mutex.ReleaseMutex();
      }, _current_information);
    }
    
    void MulitpleWaitAndRealese() {
      Mutex mutex;
      Assert::IsTrue(mutex.WaitOne(0), _current_information);
      Assert::IsTrue(mutex.WaitOne(0), _current_information);
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
