#include <Switch/System/Threading/Semaphore.hpp>
#include <Switch/System/Threading/Mutex.hpp>
#include <Switch/System/Threading/Thread.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Threading;
using namespace TUnit;

namespace SwitchUnitTests {
  class SemaphoreTest : public TestFixture {
  protected:
    void CreateSemaphore() {
      Semaphore semaphore(0, 1);
      Assert::AreEqual("Switch::System::Threading::Semaphore", semaphore.ToString(), _caller);
    }
    
    void CreateTwoSemaphore() {
      Semaphore semaphore1(0, 1);
      Semaphore semaphore2(0, 1);
      Assert::AreNotEqual(semaphore1, semaphore2, _caller);
    }
    
    void CreateSemaphoreByCopy() {
      Semaphore semaphore1(0, 1);
      Semaphore semaphore2(semaphore1);
      Assert::AreEqual(semaphore1, semaphore2, _caller);
    }
    
    void CreateSemaphoreAndCopy() {
      Semaphore semaphore1(0, 1);
      Semaphore semaphore2(0, 1);
      Assert::AreNotEqual(semaphore1, semaphore2, _caller);
      semaphore2 = semaphore1;
      Assert::AreEqual(semaphore1, semaphore2, _caller);
    }
    
    void CreateSemaphoreWithCountToZero() {
      Semaphore semaphore(0, 1);
      Thread thread(ThreadStart(_delegate {Assert::IsFalse(semaphore.WaitOne(0), _caller);}));
      thread.Start();
      thread.Join();
    }
    
    void CreateSemaphoreWithCountToOne() {
      Semaphore semaphore(1, 1);
      Thread thread(ThreadStart(_delegate {Assert::IsTrue(semaphore.WaitOne(0), _caller);}));
      thread.Start();
      thread.Join();
    }
    
    void CreateSemaphoreWithSameName() {
      Semaphore semaphore1(0, 1, "MySemaphore");
      Semaphore semaphore2(0, 1, "MySemaphore");
      Assert::AreEqual(semaphore1, semaphore2, _caller);
    }
    
    void CreateSemaphoreWithSameNameAndCreatedNew() {
      bool createdNew;
      Semaphore semaphore1(0, 1, "MySemaphore", createdNew);
      Assert::IsTrue(createdNew, _caller);
      Semaphore semaphore2(0, 1, "MySemaphore", createdNew);
      Assert::IsFalse(createdNew, _caller);
    }
    
    void CreateSemaphoreWithDifferentName() {
      Semaphore semaphore1(0, 1, "MySemaphore1");
      Semaphore semaphore2(0, 1, "MySemaphore2");
      Assert::AreNotEqual(semaphore1, semaphore2, _caller);
    }
    
    void CreateSemaphoreWithDifferentNameAndCreatedNew() {
      bool createdNew;
      Semaphore semaphore1(0, 1, "MySemaphore1", createdNew);
      Assert::IsTrue(createdNew, _caller);
      Semaphore semaphore2(0, 1, "MySemaphore2", createdNew);
      Assert::IsTrue(createdNew, _caller);
    }
    
    void Close() {
      Semaphore semaphore(1, 1);
      semaphore.Close();
      Assert::Throws<ObjectDisposedException>(_delegate {semaphore.WaitOne();}, _caller);
    }
    
    void OpenExistingWithSameName() {
      Semaphore semaphore1(0, 1, "MySemaphore");
      Semaphore semaphore2 = Semaphore::OpenExisting("MySemaphore");
      Assert::AreEqual(semaphore1, semaphore2, _caller);
    }
    
    void OpenExistingWithDifferentName() {
      Semaphore semaphore1(0, 1, "MySemaphore1");
      Assert::Throws<WaitHandleCannotBeOpenedException>(_delegate {Semaphore semaphore2 = Semaphore::OpenExisting("MySemaphore2");}, _caller);
    }
    
    void TryOpenExistingWithSameName() {
      Semaphore semaphore1(0, 1, "MySemaphore");
      Semaphore semaphore2;
      Assert::IsTrue(Semaphore::TryOpenExisting("MySemaphore", semaphore2), _caller);
      Assert::AreEqual(semaphore1, semaphore2, _caller);
    }
    
    void TryOpenExistingWithDifferentName() {
      Semaphore semaphore1(0, 1, "Semaphore1");
      Semaphore semaphore2;
      Assert::IsFalse(Semaphore::TryOpenExisting("MyMSemaphore2", semaphore2), _caller);
    }
    
    void WaitAndRealese() {
      Semaphore semaphore(1, 1);
      Assert::IsTrue(semaphore.WaitOne(0), _caller);
      Assert::DoesNotThrows(_delegate {semaphore.Release();}, _caller);
    }
    
    void InitialCountTo0AndWait() {
      Semaphore semaphore(0, 1);
      Assert::IsFalse(semaphore.WaitOne(0), _caller);
    }
    
    void InitialCountTo1AndWait() {
      Semaphore semaphore(1, 1);
      Assert::IsTrue(semaphore.WaitOne(0), _caller);
      Assert::IsFalse(semaphore.WaitOne(0), _caller);
    }
    
    void InitialCountTo2AndWait() {
      Semaphore semaphore(2, 2);
      Assert::IsTrue(semaphore.WaitOne(0), _caller);
      Assert::IsTrue(semaphore.WaitOne(0), _caller);
      Assert::IsFalse(semaphore.WaitOne(0), _caller);
    }
    
    void MaximumCountTo2AndRelease() {
      Semaphore semaphore(0, 2);
      Assert::DoesNotThrows(_delegate {semaphore.Release();}, _caller);
      Assert::DoesNotThrows(_delegate {semaphore.Release();}, _caller);
      Assert::Throws<SemaphoreFullException>(_delegate {semaphore.Release();}, _caller);
    }
    
    void ReleaseAndWait() {
      Semaphore semaphore(0, Int32::MaxValue);
      Assert::DoesNotThrows(_delegate {semaphore.Release();}, _caller);
      Assert::DoesNotThrows(_delegate {semaphore.Release();}, _caller);
      Assert::IsTrue(semaphore.WaitOne(0), _caller);
      Assert::IsTrue(semaphore.WaitOne(0), _caller);
      Assert::IsFalse(semaphore.WaitOne(0), _caller);
    }
  };

  _add_test (SemaphoreTest, CreateSemaphore)
  _add_test (SemaphoreTest, CreateTwoSemaphore)
  _add_test (SemaphoreTest, CreateSemaphoreByCopy)
  _add_test (SemaphoreTest, CreateSemaphoreAndCopy)
  _add_test (SemaphoreTest, CreateSemaphoreWithCountToZero)
  _add_test (SemaphoreTest, CreateSemaphoreWithCountToOne)
  _add_test (SemaphoreTest, CreateSemaphoreWithSameName)
  _add_test (SemaphoreTest, CreateSemaphoreWithSameNameAndCreatedNew)
  _add_test (SemaphoreTest, CreateSemaphoreWithDifferentName)
  _add_test (SemaphoreTest, CreateSemaphoreWithDifferentNameAndCreatedNew)
  _add_test (SemaphoreTest, Close)
  _add_test (SemaphoreTest, OpenExistingWithSameName)
  _add_test (SemaphoreTest, OpenExistingWithDifferentName)
  _add_test (SemaphoreTest, TryOpenExistingWithSameName)
  _add_test (SemaphoreTest, TryOpenExistingWithDifferentName)
  _add_test (SemaphoreTest, WaitAndRealese)
  _add_test (SemaphoreTest, InitialCountTo0AndWait)
  _add_test (SemaphoreTest, InitialCountTo1AndWait)
  _add_test (SemaphoreTest, InitialCountTo2AndWait)
  _add_test (SemaphoreTest, MaximumCountTo2AndRelease)
  _add_test (SemaphoreTest, ReleaseAndWait)
}
