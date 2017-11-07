#include <thread>
#include <Switch/Lock.hpp>
#include <Switch/System/Delegate.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(LockGuardTest, SingleLock) {
    int value = 0;
    object lock;
    
    _lock (lock)
    ++value;
    ASSERT_EQ(1, value);
  }
  
  TEST(LockGuardTest, DoubleLockOnDifferentObjects) {
    int value = 0;
    object lock;
    object lock2;
    
    _lock (lock) {
      ++value;
      _lock (lock2)
      ++value;
    }
    
    ASSERT_EQ(2, value);
  }
  
  TEST(LockGuardTest, DoubleLockOnSameObject) {
    int value = 0;
    object lock;
    
    _lock(lock) {
      ++value;
      _lock (lock)
      ++value;
    }
    
    ASSERT_EQ(2, value);
  }
  
  TEST(LockGuardTest, LockDuration) {
    object lock;
    int value = 0;
    int64 start = std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count()/1000000;
    
    _lock (lock)
    ++value;
    
    ASSERT_LE(std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count()/1000000 - start, 1);
  }
  
  TEST(LockGuardTest, Thread) {
    string s;
    object lock;
    std::thread t1(_delegate {
      _lock (lock) {
        for (int i = 0; i < 500; i++)
          s += '1';
      }
    });
    std::thread t2(_delegate {
      _lock (lock) {
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
      ASSERT_FALSE(++i < 500 && o != c);
    }
  }
}

