#include <Switch/Lock.hpp>
#include <Switch/System/Collections/Concurrent/ConcurrentQueue.hpp>
#include <Switch/System/Collections/Concurrent/ConcurrentStack.hpp>
#include <Switch/System/Collections/Generic/Dictionary.hpp>
#include <Switch/System/Collections/Generic/HashSet.hpp>
#include <Switch/System/Collections/Generic/LinkedList.hpp>
#include <Switch/System/Collections/Generic/List.hpp>
#include <Switch/System/Collections/Generic/Queue.hpp>
#include <Switch/System/Collections/Generic/SortedDictionary.hpp>
#include <Switch/System/Collections/Generic/SortedSet.hpp>
#include <Switch/System/Collections/Generic/Stack.hpp>
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
  
  TEST(MoveTest, MoveHashSet) {
    HashSet<int32> hs1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    HashSet<int32> hs2 = Move(hs1);
    ASSERT_EQ(0, hs1.Count);
    ASSERT_EQ(10, hs2.Count);
  }
  
  TEST(MoveTest, MoveLinkedList) {
    LinkedList<int32> ll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LinkedList<int32> ll2 = Move(ll1);
    ASSERT_EQ(0, ll1.Count);
    ASSERT_EQ(10, ll2.Count);
  }
  
  TEST(MoveTest, MoveList) {
    List<int32> l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    List<int32> l2 = Move(l1);
    ASSERT_EQ(0, l1.Count);
    ASSERT_EQ(10, l2.Count);
  }
  
  TEST(MoveTest, MoveQueue) {
    Queue<int32> q1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Queue<int32> q2 = Move(q1);
    ASSERT_EQ(0, q1.Count);
    ASSERT_EQ(10, q2.Count);
  }
  
  TEST(MoveTest, MoveSortedDictionary) {
    SortedDictionary<string, int32> sd1 = {{"One", 1}, {"Two", 2}, {"Three", 3}, {"Four", 4}, {"Five", 5}, {"Six", 6}, {"Seven", 7}, {"Eigth", 8}, {"Nine", 9}, {"Ten", 10}};
    SortedDictionary<string, int32> sd2 = Move(sd1);
    ASSERT_EQ(0, sd1.Count);
    ASSERT_EQ(10, sd2.Count);
  }
  
  TEST(MoveTest, MoveSortedSet) {
    SortedSet<int32> ss1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SortedSet<int32> ss2 = Move(ss1);
    ASSERT_EQ(0, ss1.Count);
    ASSERT_EQ(10, ss2.Count);
  }
  
  TEST(MoveTest, MoveStack) {
    Stack<int32> s1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Stack<int32> s2 = Move(s1);
    ASSERT_EQ(0, s1.Count);
    ASSERT_EQ(10, s2.Count);
  }
}
