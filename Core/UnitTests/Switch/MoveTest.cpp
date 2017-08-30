#include <Switch/Lock.hpp>
#include <Switch/System/Collections/Concurrent/ConcurrentBag.hpp>
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
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Concurrent;
using namespace System::Collections::Generic;
using namespace TUnit;

namespace SwitchUnitTests {
  class MoveTest : public TestFixture {
  protected:
    void MoveString() {
      string s1 = "Original String";
      string s2 = Move(s1);
      Assert::AreEqual("", s1, pcf_current_information);
      Assert::AreEqual("Original String", s2, pcf_current_information);
    }
    
    void MoveArray() {
      Array<int32> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      Array<int32> a2 = Move(a1);
      Assert::AreEqual(0, a1.Length, pcf_current_information);
      Assert::AreEqual(10, a2.Length, pcf_current_information);
    }
    
    void MoveBitArray() {
      BitArray b1 = {true, false, true, false, true, true, false, true, false, true};
      BitArray b2 = Move(b1);
      Assert::AreEqual(0, b1.Count, pcf_current_information);
      Assert::AreEqual(10, b2.Count, pcf_current_information);
    }
    
    void MoveConcurrentBag() {
      ConcurrentBag<int32> cb1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      ConcurrentBag<int32> cb2 = Move(cb1);
      Assert::AreEqual(0, cb1.Count, pcf_current_information);
      Assert::AreEqual(10, cb2.Count, pcf_current_information);
    }
    
    void MoveConcurrentQueue() {
      ConcurrentQueue<int32> cq1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      ConcurrentQueue<int32> cq2 = Move(cq1);
      Assert::AreEqual(0, cq1.Count, pcf_current_information);
      Assert::AreEqual(10, cq2.Count, pcf_current_information);
    }
    
    void MoveConcurrentStack() {
      ConcurrentStack<int32> cs1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      ConcurrentStack<int32> cs2 = Move(cs1);
      Assert::AreEqual(0, cs1.Count, pcf_current_information);
      Assert::AreEqual(10, cs2.Count, pcf_current_information);
    }
    
    void MoveDictionary() {
      Dictionary<string, int32> d1 = {{"One", 1}, {"Two", 2}, {"Three", 3}, {"Four", 4}, {"Five", 5}, {"Six", 6}, {"Seven", 7}, {"Eigth", 8}, {"Nine", 9}, {"Ten", 10}};
      Dictionary<string, int32> d2 = Move(d1);
      Assert::AreEqual(0, d1.Count, pcf_current_information);
      Assert::AreEqual(10, d2.Count, pcf_current_information);
    }
    
    void MoveHashSet() {
      HashSet<int32> hs1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      HashSet<int32> hs2 = Move(hs1);
      Assert::AreEqual(0, hs1.Count, pcf_current_information);
      Assert::AreEqual(10, hs2.Count, pcf_current_information);
    }
    
    void MoveLinkedList() {
      LinkedList<int32> ll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      LinkedList<int32> ll2 = Move(ll1);
      Assert::AreEqual(0, ll1.Count, pcf_current_information);
      Assert::AreEqual(10, ll2.Count, pcf_current_information);
    }
    
    void MoveList() {
      List<int32> l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      List<int32> l2 = Move(l1);
      Assert::AreEqual(0, l1.Count, pcf_current_information);
      Assert::AreEqual(10, l2.Count, pcf_current_information);
    }
    
    void MoveQueue() {
      Queue<int32> q1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      Queue<int32> q2 = Move(q1);
      Assert::AreEqual(0, q1.Count, pcf_current_information);
      Assert::AreEqual(10, q2.Count, pcf_current_information);
    }
    
    void MoveSortedDictionary() {
      SortedDictionary<string, int32> sd1 = {{"One", 1}, {"Two", 2}, {"Three", 3}, {"Four", 4}, {"Five", 5}, {"Six", 6}, {"Seven", 7}, {"Eigth", 8}, {"Nine", 9}, {"Ten", 10}};
      SortedDictionary<string, int32> sd2 = Move(sd1);
      Assert::AreEqual(0, sd1.Count, pcf_current_information);
      Assert::AreEqual(10, sd2.Count, pcf_current_information);
    }
    
    void MoveSortedSet() {
      SortedSet<int32> ss1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      SortedSet<int32> ss2 = Move(ss1);
      Assert::AreEqual(0, ss1.Count, pcf_current_information);
      Assert::AreEqual(10, ss2.Count, pcf_current_information);
    }
    
    void MoveStack() {
      Stack<int32> s1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      Stack<int32> s2 = Move(s1);
      Assert::AreEqual(0, s1.Count, pcf_current_information);
      Assert::AreEqual(10, s2.Count, pcf_current_information);
    }
 };
  
  pcf_test(MoveTest, MoveString)
  pcf_test(MoveTest, MoveArray)
  pcf_test(MoveTest, MoveBitArray)
  pcf_test(MoveTest, MoveConcurrentBag)
  pcf_test(MoveTest, MoveConcurrentQueue)
  pcf_test(MoveTest, MoveConcurrentStack)
  pcf_test(MoveTest, MoveDictionary)
  pcf_test(MoveTest, MoveHashSet)
  pcf_test(MoveTest, MoveLinkedList)
  pcf_test(MoveTest, MoveList)
  pcf_test(MoveTest, MoveQueue)
  pcf_test(MoveTest, MoveSortedDictionary)
  pcf_test(MoveTest, MoveSortedSet)
  pcf_test(MoveTest, MoveStack)
}
