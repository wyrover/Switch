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

  _AddTest(SemaphoreTest, CreateSemaphore)
  _AddTest(SemaphoreTest, CreateTwoSemaphore)
  _AddTest(SemaphoreTest, CreateSemaphoreByCopy)
  _AddTest(SemaphoreTest, CreateSemaphoreAndCopy)
  _AddTest(SemaphoreTest, CreateSemaphoreWithCountToZero)
  _AddTest(SemaphoreTest, CreateSemaphoreWithCountToOne)
  _AddTest(SemaphoreTest, CreateSemaphoreWithSameName)
  _AddTest(SemaphoreTest, CreateSemaphoreWithSameNameAndCreatedNew)
  _AddTest(SemaphoreTest, CreateSemaphoreWithDifferentName)
  _AddTest(SemaphoreTest, CreateSemaphoreWithDifferentNameAndCreatedNew)
  _AddTest(SemaphoreTest, Close)
  _AddTest(SemaphoreTest, OpenExistingWithSameName)
  _AddTest(SemaphoreTest, OpenExistingWithDifferentName)
  _AddTest(SemaphoreTest, TryOpenExistingWithSameName)
  _AddTest(SemaphoreTest, TryOpenExistingWithDifferentName)
  _AddTest(SemaphoreTest, WaitAndRealese)
  _AddTest(SemaphoreTest, InitialCountTo0AndWait)
  _AddTest(SemaphoreTest, InitialCountTo1AndWait)
  _AddTest(SemaphoreTest, InitialCountTo2AndWait)
  _AddTest(SemaphoreTest, MaximumCountTo2AndRelease)
  _AddTest(SemaphoreTest, ReleaseAndWait)
}
