#include <Pcf/System/Threading/Semaphore.h>
#include <Pcf/System/Threading/Mutex.h>
#include <Pcf/System/Threading/Thread.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Threading;
using namespace TUnit;

namespace PcfUnitTests {
  class SemaphoreTest : public TestFixture {
  protected:
    void CreateSemaphore() {
      Semaphore semaphore(0, 1);
      Assert::AreEqual("Pcf::System::Threading::Semaphore", semaphore.ToString(), pcf_current_information);
    }
    
    void CreateTwoSemaphore() {
      Semaphore semaphore1(0, 1);
      Semaphore semaphore2(0, 1);
      Assert::AreNotEqual(semaphore1, semaphore2, pcf_current_information);
    }
    
    void CreateSemaphoreByCopy() {
      Semaphore semaphore1(0, 1);
      Semaphore semaphore2(semaphore1);
      Assert::AreEqual(semaphore1, semaphore2, pcf_current_information);
    }
    
    void CreateSemaphoreAndCopy() {
      Semaphore semaphore1(0, 1);
      Semaphore semaphore2(0, 1);
      Assert::AreNotEqual(semaphore1, semaphore2, pcf_current_information);
      semaphore2 = semaphore1;
      Assert::AreEqual(semaphore1, semaphore2, pcf_current_information);
    }
    
    void CreateSemaphoreWithCountToZero() {
      Semaphore semaphore(0, 1);
      Thread thread(ThreadStart(pcf_delegate {Assert::IsFalse(semaphore.WaitOne(0), pcf_current_information);}));
      thread.Start();
      thread.Join();
    }
    
    void CreateSemaphoreWithCountToOne() {
      Semaphore semaphore(1, 1);
      Thread thread(ThreadStart(pcf_delegate {Assert::IsTrue(semaphore.WaitOne(0), pcf_current_information);}));
      thread.Start();
      thread.Join();
    }
    
    void CreateSemaphoreWithSameName() {
      Semaphore semaphore1(0, 1, "MySemaphore");
      Semaphore semaphore2(0, 1, "MySemaphore");
      Assert::AreEqual(semaphore1, semaphore2, pcf_current_information);
    }
    
    void CreateSemaphoreWithSameNameAndCreatedNew() {
      bool createdNew;
      Semaphore semaphore1(0, 1, "MySemaphore", createdNew);
      Assert::IsTrue(createdNew, pcf_current_information);
      Semaphore semaphore2(0, 1, "MySemaphore", createdNew);
      Assert::IsFalse(createdNew, pcf_current_information);
    }
    
    void CreateSemaphoreWithDifferentName() {
      Semaphore semaphore1(0, 1, "MySemaphore1");
      Semaphore semaphore2(0, 1, "MySemaphore2");
      Assert::AreNotEqual(semaphore1, semaphore2, pcf_current_information);
    }
    
    void CreateSemaphoreWithDifferentNameAndCreatedNew() {
      bool createdNew;
      Semaphore semaphore1(0, 1, "MySemaphore1", createdNew);
      Assert::IsTrue(createdNew, pcf_current_information);
      Semaphore semaphore2(0, 1, "MySemaphore2", createdNew);
      Assert::IsTrue(createdNew, pcf_current_information);
    }
    
    void Close() {
      Semaphore semaphore(1, 1);
      semaphore.Close();
      Assert::Throws<ObjectClosedException>(pcf_delegate {semaphore.WaitOne();}, pcf_current_information);
    }
    
    void OpenExistingWithSameName() {
      Semaphore semaphore1(0, 1, "MySemaphore");
      Semaphore semaphore2 = Semaphore::OpenExisting("MySemaphore");
      Assert::AreEqual(semaphore1, semaphore2, pcf_current_information);
    }
    
    void OpenExistingWithDifferentName() {
      Semaphore semaphore1(0, 1, "MySemaphore1");
      Assert::Throws<WaitHandleCannotBeOpenedException>(pcf_delegate {Semaphore semaphore2 = Semaphore::OpenExisting("MySemaphore2");}, pcf_current_information);
    }
    
    void TryOpenExistingWithSameName() {
      Semaphore semaphore1(0, 1, "MySemaphore");
      Semaphore semaphore2;
      Assert::IsTrue(Semaphore::TryOpenExisting("MySemaphore", semaphore2), pcf_current_information);
      Assert::AreEqual(semaphore1, semaphore2, pcf_current_information);
    }
    
    void TryOpenExistingWithDifferentName() {
      Semaphore semaphore1(0, 1, "Semaphore1");
      Semaphore semaphore2;
      Assert::IsFalse(Semaphore::TryOpenExisting("MyMSemaphore2", semaphore2), pcf_current_information);
    }
    
    void WaitAndRealese() {
      Semaphore semaphore(1, 1);
      Assert::IsTrue(semaphore.WaitOne(0), pcf_current_information);
      Assert::DoesNotThrows(pcf_delegate {semaphore.Release();}, pcf_current_information);
    }
    
    void InitialCountTo0AndWait() {
      Semaphore semaphore(0, 1);
      Assert::IsFalse(semaphore.WaitOne(0), pcf_current_information);
    }
    
    void InitialCountTo1AndWait() {
      Semaphore semaphore(1, 1);
      Assert::IsTrue(semaphore.WaitOne(0), pcf_current_information);
      Assert::IsFalse(semaphore.WaitOne(0), pcf_current_information);
    }
    
    void InitialCountTo2AndWait() {
      Semaphore semaphore(2, 2);
      Assert::IsTrue(semaphore.WaitOne(0), pcf_current_information);
      Assert::IsTrue(semaphore.WaitOne(0), pcf_current_information);
      Assert::IsFalse(semaphore.WaitOne(0), pcf_current_information);
    }
    
    void MaximumCountTo2AndRelease() {
      Semaphore semaphore(0, 2);
      Assert::DoesNotThrows(pcf_delegate {semaphore.Release();}, pcf_current_information);
      Assert::DoesNotThrows(pcf_delegate {semaphore.Release();}, pcf_current_information);
      Assert::Throws<SemaphoreFullException>(pcf_delegate {semaphore.Release();}, pcf_current_information);
    }
    
    void ReleaseAndWait() {
      Semaphore semaphore(0, Int32::MaxValue);
      Assert::DoesNotThrows(pcf_delegate {semaphore.Release();}, pcf_current_information);
      Assert::DoesNotThrows(pcf_delegate {semaphore.Release();}, pcf_current_information);
      Assert::IsTrue(semaphore.WaitOne(0), pcf_current_information);
      Assert::IsTrue(semaphore.WaitOne(0), pcf_current_information);
      Assert::IsFalse(semaphore.WaitOne(0), pcf_current_information);
    }
  };

  pcf_test(SemaphoreTest, CreateSemaphore);
  pcf_test(SemaphoreTest, CreateTwoSemaphore);
  pcf_test(SemaphoreTest, CreateSemaphoreByCopy);
  pcf_test(SemaphoreTest, CreateSemaphoreAndCopy);
  pcf_test(SemaphoreTest, CreateSemaphoreWithCountToZero);
  pcf_test(SemaphoreTest, CreateSemaphoreWithCountToOne);
  pcf_test(SemaphoreTest, CreateSemaphoreWithSameName);
  pcf_test(SemaphoreTest, CreateSemaphoreWithSameNameAndCreatedNew);
  pcf_test(SemaphoreTest, CreateSemaphoreWithDifferentName);
  pcf_test(SemaphoreTest, CreateSemaphoreWithDifferentNameAndCreatedNew);
  pcf_test(SemaphoreTest, Close);
  pcf_test(SemaphoreTest, OpenExistingWithSameName);
  pcf_test(SemaphoreTest, OpenExistingWithDifferentName);
  pcf_test(SemaphoreTest, TryOpenExistingWithSameName);
  pcf_test(SemaphoreTest, TryOpenExistingWithDifferentName);
  pcf_test(SemaphoreTest, WaitAndRealese);
  pcf_test(SemaphoreTest, InitialCountTo0AndWait);
  pcf_test(SemaphoreTest, InitialCountTo1AndWait);
  pcf_test(SemaphoreTest, InitialCountTo2AndWait);
  pcf_test(SemaphoreTest, MaximumCountTo2AndRelease);
  pcf_test(SemaphoreTest, ReleaseAndWait);
}
