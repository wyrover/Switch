#include <Switch/Lock.hpp>
#include <Switch/System/Collections/Concurrent/ConcurrentQueue.hpp>
#include <Switch/System/Collections/Concurrent/ConcurrentStack.hpp>
#include <Switch/System/Collections/Generic/Dictionary.hpp>
#include <Switch/System/Collections/Generic/List.hpp>
#include <Switch/System/Collections/BitArray.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Concurrent;
using namespace System::Collections::Generic;

namespace SwitchUnitTests {
  TEST(MoveTest, MoveString) {
    string s1 = "Original String";
    string s2 = Move(s1);
    ASSERT_EQ("", s1);
    ASSERT_EQ("Original String", s2);
  }

  TEST(MoveTest, MoveArray) {
    Array<int32> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Array<int32> a2 = Move(a1);
    ASSERT_EQ(0, a1.Length);
    ASSERT_EQ(10, a2.Length);
  }

  TEST(MoveTest, MoveBitArray) {
    BitArray b1 = {true, false, true, false, true, true, false, true, false, true};
    BitArray b2 = Move(b1);
    ASSERT_EQ(0, b1.Count);
    ASSERT_EQ(10, b2.Count);
  }

  TEST(MoveTest, MoveConcurrentQueue) {
    ConcurrentQueue<int32> cq1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ConcurrentQueue<int32> cq2 = Move(cq1);
    ASSERT_EQ(0, cq1.Count);
    ASSERT_EQ(10, cq2.Count);
  }

  TEST(MoveTest, MoveConcurrentStack) {
    ConcurrentStack<int32> cs1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ConcurrentStack<int32> cs2 = Move(cs1);
    ASSERT_EQ(0, cs1.Count);
    ASSERT_EQ(10, cs2.Count);
  }

  TEST(MoveTest, MoveDictionary) {
    Dictionary<string, int32> d1 = {{"One", 1}, {"Two", 2}, {"Three", 3}, {"Four", 4}, {"Five", 5}, {"Six", 6}, {"Seven", 7}, {"Eigth", 8}, {"Nine", 9}, {"Ten", 10}};
    Dictionary<string, int32> d2 = Move(d1);
    ASSERT_EQ(0, d1.Count);
    ASSERT_EQ(10, d2.Count);
  }

  TEST(MoveTest, MoveList) {
    List<int32> l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    List<int32> l2 = Move(l1);
    ASSERT_EQ(0, l1.Count);
    ASSERT_EQ(10, l2.Count);
  }
}

