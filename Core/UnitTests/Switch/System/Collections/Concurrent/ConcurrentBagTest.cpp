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
        Assert::AreEqual(values[index++], item, _current_information);
      Assert::AreEqual(6, index, _current_information);
    }

    void GetEnumerator() {
      ConcurrentBag<int> bag = {0, 1, 2, 3, 4, 5};
      int values[] = {0, 1, 2, 3, 4, 5};
      auto enumerator = bag.GetEnumerator();
      bag.Add(6);
      int index = 0;
      while (enumerator.MoveNext())
        Assert::AreEqual(values[index++], enumerator.Current(), _current_information);
      Assert::AreEqual(6, index, _current_information);
    }
    
    void TryPeek() {
      ConcurrentBag<int> bag = {0, 1, 2, 3, 4, 5};
      int result;
      Assert::IsTrue(bag.TryPeek(result), _current_information);
      Assert::AreEqual(5, result, _current_information);
    }
    
    void TryTake() {
      ConcurrentBag<int> bag = {0, 1, 2, 3, 4, 5};
      int result;
      Assert::IsTrue(bag.TryTake(result), _current_information);
      Assert::AreEqual(5, result, _current_information);
      Assert::AreEqual(5, bag.Count, _current_information);
      Assert::IsTrue(bag.TryTake(result), _current_information);
      Assert::AreEqual(4, result, _current_information);
      Assert::AreEqual(4, bag.Count, _current_information);
      Assert::IsTrue(bag.TryTake(result), _current_information);
      Assert::AreEqual(3, result, _current_information);
      Assert::AreEqual(3, bag.Count, _current_information);
      Assert::IsTrue(bag.TryTake(result), _current_information);
      Assert::AreEqual(2, result, _current_information);
      Assert::AreEqual(2, bag.Count, _current_information);
      Assert::IsTrue(bag.TryTake(result), _current_information);
      Assert::AreEqual(1, result, _current_information);
      Assert::AreEqual(1, bag.Count, _current_information);
      Assert::IsTrue(bag.TryTake(result), _current_information);
      Assert::AreEqual(0, result, _current_information);
      Assert::AreEqual(0, bag.Count, _current_information);
      Assert::IsFalse(bag.TryTake(result), _current_information);
    }
    
  };
  
  _test(ConcurrentBagTest, Add)
  _test(ConcurrentBagTest, GetEnumerator)
  _test(ConcurrentBagTest, TryPeek)
  _test(ConcurrentBagTest, TryTake)
}
