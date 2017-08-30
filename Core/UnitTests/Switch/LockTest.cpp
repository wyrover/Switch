#include <Switch/Lock.hpp>
#include <Switch/System/Diagnostics/Stopwatch.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Threading;
using namespace System::Diagnostics;
using namespace TUnit;

namespace SwitchUnitTests {
  class LockTest : public TestFixture {
  protected:
    void SingleLock() {
      int value = 0;
      object lock;
      
      sw_lock (lock) {
        ++value;
      }
      
      Assert::AreEqual(1, value, sw_current_information);
    }
    
    void DoubleLockOnDifferentObjects() {
      int value = 0;
      object lock;
      object lock2;
      
      sw_lock (lock) {
        ++value;
        sw_lock (lock2) {
          ++value;
        }
      }
      
      Assert::AreEqual(2, value, sw_current_information);
    }
    
    void DoubleLockOnSameObject() {
      int value = 0;
      object lock;
      
      sw_lock (lock) {
        ++value;
        sw_lock (lock) {
          ++value;
        }
      }
      
      Assert::AreEqual(2, value, sw_current_information);
    }
    
    void LockDuration() {
      object lock;
      int value = 0;
      Stopwatch duration = Stopwatch::StartNew();
      sw_lock (lock) {
        ++value;
      }
      duration.Stop();
      Assert::LessOrEqual(duration.ElapsedMilliseconds(), 1, sw_current_information);
    }
    
    void Thread() {
      string s;
      std::thread t1(sw_delegate {
        sw_lock(s) {
          for (int i = 0; i < 500; i++)
            s += '1';
        }
      });
      std::thread t2(sw_delegate {
        sw_lock(s) {
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
        Assert::IsFalse(++i < 500 && o != c, sw_current_information);
      }
      
    }
  };
  
  sw_test(LockTest, SingleLock)
  sw_test(LockTest, DoubleLockOnDifferentObjects)
  sw_test(LockTest, DoubleLockOnSameObject)
  sw_test(LockTest, LockDuration)
  sw_test(LockTest, Thread)
}
