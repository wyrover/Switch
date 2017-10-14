#include <Switch/Lock.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Threading;
using namespace TUnit;

namespace SwitchUnitTests {
  class LockTest : public TestFixture {
  protected:
    void SingleLock() {
      int value = 0;
      object lock;
      
      _lock (lock) {
        ++value;
      }
      
      Assert::AreEqual(1, value, _caller);
    }
    
    void DoubleLockOnDifferentObjects() {
      int value = 0;
      object lock;
      object lock2;
      
      _lock (lock) {
        ++value;
        _lock (lock2) {
          ++value;
        }
      }
      
      Assert::AreEqual(2, value, _caller);
    }
    
    void DoubleLockOnSameObject() {
      int value = 0;
      object lock;
      
      _lock (lock) {
        ++value;
        _lock (lock) {
          ++value;
        }
      }
      
      Assert::AreEqual(2, value, _caller);
    }
    
    void LockDuration() {
      object lock;
      int value = 0;
      int64 start = std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count()/1000000;
      _lock (lock) {
        ++value;
      }
      Assert::LessOrEqual(std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count()/1000000 - start, 1, _caller);
    }
    
    void Thread() {
      string s;
      object lock;
      std::thread t1(_delegate {
        _lock(lock) {
          for (int i = 0; i < 500; i++)
            s += '1';
        }
      });
      std::thread t2(_delegate {
        _lock(lock) {
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
        Assert::IsFalse(++i < 500 && o != c, _caller);
      }
      
    }
  };
  
  _test(LockTest, SingleLock)
  _test(LockTest, DoubleLockOnDifferentObjects)
  _test(LockTest, DoubleLockOnSameObject)
  _test(LockTest, LockDuration)
  _test(LockTest, Thread)
}
