#include <Switch/System/Collections/Concurrent/ConcurrentBag.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Collections::Concurrent;
using namespace TUnit;

namespace SwitchUnitTests {
  class ConcurrentBagTest : public TestFixture {
  protected:
    void Add() {
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
        Assert::AreEqual(values[index++], item, _caller);
      Assert::AreEqual(6, index, _caller);
    }

    void GetEnumerator() {
      ConcurrentBag<int> bag = {0, 1, 2, 3, 4, 5};
      int values[] = {0, 1, 2, 3, 4, 5};
      auto enumerator = bag.GetEnumerator();
      bag.Add(6);
      int index = 0;
      while (enumerator.MoveNext())
        Assert::AreEqual(values[index++], enumerator.Current(), _caller);
      Assert::AreEqual(6, index, _caller);
    }
    
    void TryPeek() {
      ConcurrentBag<int> bag = {0, 1, 2, 3, 4, 5};
      int result;
      Assert::IsTrue(bag.TryPeek(result), _caller);
      Assert::AreEqual(5, result, _caller);
    }
    
    void TryTake() {
      ConcurrentBag<int> bag = {0, 1, 2, 3, 4, 5};
      int result;
      Assert::IsTrue(bag.TryTake(result), _caller);
      Assert::AreEqual(5, result, _caller);
      Assert::AreEqual(5, bag.Count, _caller);
      Assert::IsTrue(bag.TryTake(result), _caller);
      Assert::AreEqual(4, result, _caller);
      Assert::AreEqual(4, bag.Count, _caller);
      Assert::IsTrue(bag.TryTake(result), _caller);
      Assert::AreEqual(3, result, _caller);
      Assert::AreEqual(3, bag.Count, _caller);
      Assert::IsTrue(bag.TryTake(result), _caller);
      Assert::AreEqual(2, result, _caller);
      Assert::AreEqual(2, bag.Count, _caller);
      Assert::IsTrue(bag.TryTake(result), _caller);
      Assert::AreEqual(1, result, _caller);
      Assert::AreEqual(1, bag.Count, _caller);
      Assert::IsTrue(bag.TryTake(result), _caller);
      Assert::AreEqual(0, result, _caller);
      Assert::AreEqual(0, bag.Count, _caller);
      Assert::IsFalse(bag.TryTake(result), _caller);
    }
    
  };
  
  _add_test(ConcurrentBagTest, Add)
  _add_test(ConcurrentBagTest, GetEnumerator)
  _add_test(ConcurrentBagTest, TryPeek)
  _add_test(ConcurrentBagTest, TryTake)
}
