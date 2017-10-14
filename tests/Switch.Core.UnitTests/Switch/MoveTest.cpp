#include <Switch/Lock.hpp>
#include <Switch/System/Collections/Concurrent/ConcurrentQueue.hpp>
#include <Switch/System/Collections/Concurrent/ConcurrentStack.hpp>
#include <Switch/System/Collections/Generic/Dictionary.hpp>
#include <Switch/System/Collections/Generic/List.hpp>
#include <Switch/System/Collections/Generic/SortedDictionary.hpp>
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
      Assert::AreEqual("", s1, _caller);
      Assert::AreEqual("Original String", s2, _caller);
    }
    
    void MoveArray() {
      Array<int32> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      Array<int32> a2 = Move(a1);
      Assert::AreEqual(0, a1.Length, _caller);
      Assert::AreEqual(10, a2.Length, _caller);
    }
    
    void MoveBitArray() {
      BitArray b1 = {true, false, true, false, true, true, false, true, false, true};
      BitArray b2 = Move(b1);
      Assert::AreEqual(0, b1.Count, _caller);
      Assert::AreEqual(10, b2.Count, _caller);
    }
    
    void MoveConcurrentQueue() {
      ConcurrentQueue<int32> cq1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      ConcurrentQueue<int32> cq2 = Move(cq1);
      Assert::AreEqual(0, cq1.Count, _caller);
      Assert::AreEqual(10, cq2.Count, _caller);
    }
    
    void MoveConcurrentStack() {
      ConcurrentStack<int32> cs1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      ConcurrentStack<int32> cs2 = Move(cs1);
      Assert::AreEqual(0, cs1.Count, _caller);
      Assert::AreEqual(10, cs2.Count, _caller);
    }
    
    void MoveDictionary() {
      Dictionary<string, int32> d1 = {{"One", 1}, {"Two", 2}, {"Three", 3}, {"Four", 4}, {"Five", 5}, {"Six", 6}, {"Seven", 7}, {"Eigth", 8}, {"Nine", 9}, {"Ten", 10}};
      Dictionary<string, int32> d2 = Move(d1);
      Assert::AreEqual(0, d1.Count, _caller);
      Assert::AreEqual(10, d2.Count, _caller);
    }
    
    void MoveList() {
      List<int32> l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      List<int32> l2 = Move(l1);
      Assert::AreEqual(0, l1.Count, _caller);
      Assert::AreEqual(10, l2.Count, _caller);
    }
    
    void MoveSortedDictionary() {
      SortedDictionary<string, int32> sd1 = {{"One", 1}, {"Two", 2}, {"Three", 3}, {"Four", 4}, {"Five", 5}, {"Six", 6}, {"Seven", 7}, {"Eigth", 8}, {"Nine", 9}, {"Ten", 10}};
      SortedDictionary<string, int32> sd2 = Move(sd1);
      Assert::AreEqual(0, sd1.Count, _caller);
      Assert::AreEqual(10, sd2.Count, _caller);
    }
 };
  
  _test(MoveTest, MoveString)
  _test(MoveTest, MoveArray)
  _test(MoveTest, MoveBitArray)
  _test(MoveTest, MoveConcurrentQueue)
  _test(MoveTest, MoveConcurrentStack)
  _test(MoveTest, MoveDictionary)
  _test(MoveTest, MoveSortedDictionary)
}
