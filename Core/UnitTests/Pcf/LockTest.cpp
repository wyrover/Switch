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
    
    void Thread() {
      string s;
      std::thread t1(pcf_delegate {
        pcf_lock(s) {
          for (int i = 0; i < 500; i++)
            s += '1';
        }
      });
      std::thread t2(pcf_delegate {
        pcf_lock(s) {
          for (int i = 0; i < 500; i++)
            s += '2';
        }
      });
      
      if (t1.joinable())
        t1.join();
      if (t2.joinable())
        t2.join();
      
      char32 o = 0;
      int32 i = 0;
      for (char32 c : s) {
        if (o == 0) o = c;
        Assert::IsFalse(++i < 500 && o != c, pcf_current_information);
      }
      
    }
  };
  
  pcf_test(LockTest, SingleLock)
  pcf_test(LockTest, DoubleLockOnDifferentObjects)
  pcf_test(LockTest, DoubleLockOnSameObject)
  pcf_test(LockTest, LockDuration)
  pcf_test(LockTest, Thread)
}
