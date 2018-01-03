#include <thread>
#include <Switch/Lock.hpp>
#include <Switch/System/Delegate.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(LockTest, SingleLock) {
    int value = 0;
    object lock;

    lock_(lock) {
      ++value;
    }

    ASSERT_EQ(1, value);
  }

  TEST(LockTest, DoubleLockOnDifferentObjects) {
    int value = 0;
    object lock;
    object lock2;

    lock_(lock) {
      ++value;
      lock_(lock2) {
        ++value;
      }
    }

    ASSERT_EQ(2, value);
  }

  TEST(LockTest, DoubleLockOnSameObject) {
    int value = 0;
    object lock;

    lock_(lock) {
      ++value;
      lock_(lock) {
        ++value;
      }
    }

    ASSERT_EQ(2, value);
  }

  TEST(LockTest, LockDuration) {
    object lock;
    int value = 0;
    int64 start = std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000;
    lock_(lock) {
      ++value;
    }
    ASSERT_LE(std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000 - start, 1);
  }

  TEST(LockTest, Thread) {
    string s;
    object lock;
    std::thread t1(delegate_ {
      lock_(lock) {
        for (int i = 0; i < 500; i++)
          s += '1';
      }
    });
    std::thread t2(delegate_ {
      lock_(lock) {
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

