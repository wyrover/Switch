#include <Pcf/Lock.h>
#include <Pcf/System/Diagnostics/Stopwatch.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Threading;
using namespace System::Diagnostics;
using namespace TUnit;

namespace PcfUnitTests {
  class LockTest : public TestFixture {
  protected:
    void SingleLock() {
      int value = 0;
      object lock;
      
      pcf_lock (lock) {
        ++value;
      }
      
      Assert::AreEqual(1, value, pcf_current_information);
    }
    
    void DoubleLockOnDifferentObjects() {
      int value = 0;
      object lock;
      object lock2;
      
      pcf_lock (lock) {
        ++value;
        pcf_lock (lock2) {
          ++value;
        }
      }
      
      Assert::AreEqual(2, value, pcf_current_information);
    }
    
    void DoubleLockOnSameObject() {
      int value = 0;
      object lock;
      
      pcf_lock (lock) {
        ++value;
        pcf_lock (lock) {
          ++value;
        }
      }
      
      Assert::AreEqual(2, value, pcf_current_information);
    }
    
    void LockDuration() {
      object lock;
      int value = 0;
      Stopwatch duration = Stopwatch::StartNew();
      pcf_lock (lock) {
        ++value;
      }
      duration.Stop();
      Assert::LessOrEqual(duration.ElapsedMilliseconds(), 1, pcf_current_information);
    }
  };
  
  pcf_test(LockTest, SingleLock)
  pcf_test(LockTest, DoubleLockOnDifferentObjects)
  pcf_test(LockTest, DoubleLockOnSameObject)
  pcf_test(LockTest, LockDuration)
}
