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
      Assert::AreEqual("Switch::System::Threading::Semaphore", semaphore.ToString(), sw_current_information);
    }
    
    void CreateTwoSemaphore() {
      Semaphore semaphore1(0, 1);
      Semaphore semaphore2(0, 1);
      Assert::AreNotEqual(semaphore1, semaphore2, sw_current_information);
    }
    
    void CreateSemaphoreByCopy() {
      Semaphore semaphore1(0, 1);
      Semaphore semaphore2(semaphore1);
      Assert::AreEqual(semaphore1, semaphore2, sw_current_information);
    }
    
    void CreateSemaphoreAndCopy() {
      Semaphore semaphore1(0, 1);
      Semaphore semaphore2(0, 1);
      Assert::AreNotEqual(semaphore1, semaphore2, sw_current_information);
      semaphore2 = semaphore1;
      Assert::AreEqual(semaphore1, semaphore2, sw_current_information);
    }
    
    void CreateSemaphoreWithCountToZero() {
      Semaphore semaphore(0, 1);
      Thread thread(ThreadStart(sw_delegate {Assert::IsFalse(semaphore.WaitOne(0), sw_current_information);}));
      thread.Start();
      thread.Join();
    }
    
    void CreateSemaphoreWithCountToOne() {
      Semaphore semaphore(1, 1);
      Thread thread(ThreadStart(sw_delegate {Assert::IsTrue(semaphore.WaitOne(0), sw_current_information);}));
      thread.Start();
      thread.Join();
    }
    
    void CreateSemaphoreWithSameName() {
      Semaphore semaphore1(0, 1, "MySemaphore");
      Semaphore semaphore2(0, 1, "MySemaphore");
      Assert::AreEqual(semaphore1, semaphore2, sw_current_information);
    }
    
    void CreateSemaphoreWithSameNameAndCreatedNew() {
      bool createdNew;
      Semaphore semaphore1(0, 1, "MySemaphore", createdNew);
      Assert::IsTrue(createdNew, sw_current_information);
      Semaphore semaphore2(0, 1, "MySemaphore", createdNew);
      Assert::IsFalse(createdNew, sw_current_information);
    }
    
    void CreateSemaphoreWithDifferentName() {
      Semaphore semaphore1(0, 1, "MySemaphore1");
      Semaphore semaphore2(0, 1, "MySemaphore2");
      Assert::AreNotEqual(semaphore1, semaphore2, sw_current_information);
    }
    
    void CreateSemaphoreWithDifferentNameAndCreatedNew() {
      bool createdNew;
      Semaphore semaphore1(0, 1, "MySemaphore1", createdNew);
      Assert::IsTrue(createdNew, sw_current_information);
      Semaphore semaphore2(0, 1, "MySemaphore2", createdNew);
      Assert::IsTrue(createdNew, sw_current_information);
    }
    
    void Close() {
      Semaphore semaphore(1, 1);
      semaphore.Close();
      Assert::Throws<ObjectClosedException>(sw_delegate {semaphore.WaitOne();}, sw_current_information);
    }
    
    void OpenExistingWithSameName() {
      Semaphore semaphore1(0, 1, "MySemaphore");
      Semaphore semaphore2 = Semaphore::OpenExisting("MySemaphore");
      Assert::AreEqual(semaphore1, semaphore2, sw_current_information);
    }
    
    void OpenExistingWithDifferentName() {
      Semaphore semaphore1(0, 1, "MySemaphore1");
      Assert::Throws<WaitHandleCannotBeOpenedException>(sw_delegate {Semaphore semaphore2 = Semaphore::OpenExisting("MySemaphore2");}, sw_current_information);
    }
    
    void TryOpenExistingWithSameName() {
      Semaphore semaphore1(0, 1, "MySemaphore");
      Semaphore semaphore2;
      Assert::IsTrue(Semaphore::TryOpenExisting("MySemaphore", semaphore2), sw_current_information);
      Assert::AreEqual(semaphore1, semaphore2, sw_current_information);
    }
    
    void TryOpenExistingWithDifferentName() {
      Semaphore semaphore1(0, 1, "Semaphore1");
      Semaphore semaphore2;
      Assert::IsFalse(Semaphore::TryOpenExisting("MyMSemaphore2", semaphore2), sw_current_information);
    }
    
    void WaitAndRealese() {
      Semaphore semaphore(1, 1);
      Assert::IsTrue(semaphore.WaitOne(0), sw_current_information);
      Assert::DoesNotThrows(sw_delegate {semaphore.Release();}, sw_current_information);
    }
    
    void InitialCountTo0AndWait() {
      Semaphore semaphore(0, 1);
      Assert::IsFalse(semaphore.WaitOne(0), sw_current_information);
    }
    
    void InitialCountTo1AndWait() {
      Semaphore semaphore(1, 1);
      Assert::IsTrue(semaphore.WaitOne(0), sw_current_information);
      Assert::IsFalse(semaphore.WaitOne(0), sw_current_information);
    }
    
    void InitialCountTo2AndWait() {
      Semaphore semaphore(2, 2);
      Assert::IsTrue(semaphore.WaitOne(0), sw_current_information);
      Assert::IsTrue(semaphore.WaitOne(0), sw_current_information);
      Assert::IsFalse(semaphore.WaitOne(0), sw_current_information);
    }
    
    void MaximumCountTo2AndRelease() {
      Semaphore semaphore(0, 2);
      Assert::DoesNotThrows(sw_delegate {semaphore.Release();}, sw_current_information);
      Assert::DoesNotThrows(sw_delegate {semaphore.Release();}, sw_current_information);
      Assert::Throws<SemaphoreFullException>(sw_delegate {semaphore.Release();}, sw_current_information);
    }
    
    void ReleaseAndWait() {
      Semaphore semaphore(0, Int32::MaxValue);
      Assert::DoesNotThrows(sw_delegate {semaphore.Release();}, sw_current_information);
      Assert::DoesNotThrows(sw_delegate {semaphore.Release();}, sw_current_information);
      Assert::IsTrue(semaphore.WaitOne(0), sw_current_information);
      Assert::IsTrue(semaphore.WaitOne(0), sw_current_information);
      Assert::IsFalse(semaphore.WaitOne(0), sw_current_information);
    }
  };

  sw_test(SemaphoreTest, CreateSemaphore)
  sw_test(SemaphoreTest, CreateTwoSemaphore)
  sw_test(SemaphoreTest, CreateSemaphoreByCopy)
  sw_test(SemaphoreTest, CreateSemaphoreAndCopy)
  sw_test(SemaphoreTest, CreateSemaphoreWithCountToZero)
  sw_test(SemaphoreTest, CreateSemaphoreWithCountToOne)
  sw_test(SemaphoreTest, CreateSemaphoreWithSameName)
  sw_test(SemaphoreTest, CreateSemaphoreWithSameNameAndCreatedNew)
  sw_test(SemaphoreTest, CreateSemaphoreWithDifferentName)
  sw_test(SemaphoreTest, CreateSemaphoreWithDifferentNameAndCreatedNew)
  sw_test(SemaphoreTest, Close)
  sw_test(SemaphoreTest, OpenExistingWithSameName)
  sw_test(SemaphoreTest, OpenExistingWithDifferentName)
  sw_test(SemaphoreTest, TryOpenExistingWithSameName)
  sw_test(SemaphoreTest, TryOpenExistingWithDifferentName)
  sw_test(SemaphoreTest, WaitAndRealese)
  sw_test(SemaphoreTest, InitialCountTo0AndWait)
  sw_test(SemaphoreTest, InitialCountTo1AndWait)
  sw_test(SemaphoreTest, InitialCountTo2AndWait)
  sw_test(SemaphoreTest, MaximumCountTo2AndRelease)
  sw_test(SemaphoreTest, ReleaseAndWait)
}
