#include <Switch/System/Random.hpp>
#include <Switch/System/Collections/Generic/List.hpp>
#include <Switch/Using.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(RandomTest, Next) {
    System::Collections::Generic::List<int> values(100);
    using_(Random rand(1)) {
      for (int i = 0; i < 100; i++) {
        int value = rand.Next();
        ASSERT_GE(value, 0);
        ASSERT_LE(value, Int32::MaxValue);
        values.Add(value);
      }
    }

    using_(Random rand(1)) {
      for (int i = 0; i < 100; i++)
        ASSERT_EQ(values[i], rand.Next());
    }
  }

  TEST(RandomTest, NextWithRange0To10) {
    System::Collections::Generic::List<int> values(100);
    using_(Random rand(5)) {
      for (int i = 0; i < 100; i++) {
        int value = rand.Next(11);
        ASSERT_GE(value, 0);
        ASSERT_LE(value, Int32::MaxValue);
        values.Add(value);
      }
    }

    using_(Random rand(5)) {
      for (int i = 0; i < 100; i++)
        ASSERT_EQ(values[i], rand.Next(0, 11));
    }
  }

  TEST(RandomTest, NextBytes) {
    Array<byte> bytes(100);
    using_(Random rand(42))
    rand.NextBytes(bytes);

    using_(Random rand(42)) {
      for (int i = 0; i < 100; i++)
        ASSERT_EQ(bytes[i], rand.Next(Byte::MaxValue + 1));
    }
  }
}
