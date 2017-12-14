#include <Switch/System/Collections/Concurrent/ConcurrentBag.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Collections::Concurrent;

namespace SwitchUnitTests {
  TEST(ConcurrentBagTest, Add) {
    ConcurrentBag<int> bag;
    int values[] = {0, 1, 2, 3, 4, 5};
    bag.Add(0);
    bag.Add(1);
    bag.Add(2);
    bag.Add(3);
    bag.Add(4);
    bag.Add(5);
    int index = 0;
    for (int item : bag)
      ASSERT_EQ(values[index++], item);
    ASSERT_EQ(6, index);
  }

  TEST(ConcurrentBagTest, GetEnumerator) {
    ConcurrentBag<int> bag = {0, 1, 2, 3, 4, 5};
    int values[] = {0, 1, 2, 3, 4, 5};
    auto enumerator = bag.GetEnumerator();
    bag.Add(6);
    int index = 0;
    while (enumerator.MoveNext())
      ASSERT_EQ(values[index++], enumerator.Current());
    ASSERT_EQ(6, index);
  }

  TEST(ConcurrentBagTest, TryPeek) {
    ConcurrentBag<int> bag = {0, 1, 2, 3, 4, 5};
    int result;
    ASSERT_TRUE(bag.TryPeek(result));
    ASSERT_EQ(5, result);
  }

  TEST(ConcurrentBagTest, TryTake) {
    ConcurrentBag<int> bag = {0, 1, 2, 3, 4, 5};
    int result;
    ASSERT_TRUE(bag.TryTake(result));
    ASSERT_EQ(5, result);
    ASSERT_EQ(5, bag.Count);
    ASSERT_TRUE(bag.TryTake(result));
    ASSERT_EQ(4, result);
    ASSERT_EQ(4, bag.Count);
    ASSERT_TRUE(bag.TryTake(result));
    ASSERT_EQ(3, result);
    ASSERT_EQ(3, bag.Count);
    ASSERT_TRUE(bag.TryTake(result));
    ASSERT_EQ(2, result);
    ASSERT_EQ(2, bag.Count);
    ASSERT_TRUE(bag.TryTake(result));
    ASSERT_EQ(1, result);
    ASSERT_EQ(1, bag.Count);
    ASSERT_TRUE(bag.TryTake(result));
    ASSERT_EQ(0, result);
    ASSERT_EQ(0, bag.Count);
    ASSERT_FALSE(bag.TryTake(result));
  }
}
