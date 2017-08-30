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
        Assert::AreEqual(values[index++], item, pcf_current_information);
      Assert::AreEqual(6, index, pcf_current_information);
    }

    void GetEnumerator() {
      ConcurrentBag<int> bag = {0, 1, 2, 3, 4, 5};
      int values[] = {0, 1, 2, 3, 4, 5};
      auto enumerator = bag.GetEnumerator();
      bag.Add(6);
      int index = 0;
      while (enumerator.MoveNext())
        Assert::AreEqual(values[index++], enumerator.Current(), pcf_current_information);
      Assert::AreEqual(6, index, pcf_current_information);
    }
    
    void TryPeek() {
      ConcurrentBag<int> bag = {0, 1, 2, 3, 4, 5};
      int result;
      Assert::IsTrue(bag.TryPeek(result), pcf_current_information);
      Assert::AreEqual(5, result, pcf_current_information);
    }
    
    void TryTake() {
      ConcurrentBag<int> bag = {0, 1, 2, 3, 4, 5};
      int result;
      Assert::IsTrue(bag.TryTake(result), pcf_current_information);
      Assert::AreEqual(5, result, pcf_current_information);
      Assert::AreEqual(5, bag.Count, pcf_current_information);
      Assert::IsTrue(bag.TryTake(result), pcf_current_information);
      Assert::AreEqual(4, result, pcf_current_information);
      Assert::AreEqual(4, bag.Count, pcf_current_information);
      Assert::IsTrue(bag.TryTake(result), pcf_current_information);
      Assert::AreEqual(3, result, pcf_current_information);
      Assert::AreEqual(3, bag.Count, pcf_current_information);
      Assert::IsTrue(bag.TryTake(result), pcf_current_information);
      Assert::AreEqual(2, result, pcf_current_information);
      Assert::AreEqual(2, bag.Count, pcf_current_information);
      Assert::IsTrue(bag.TryTake(result), pcf_current_information);
      Assert::AreEqual(1, result, pcf_current_information);
      Assert::AreEqual(1, bag.Count, pcf_current_information);
      Assert::IsTrue(bag.TryTake(result), pcf_current_information);
      Assert::AreEqual(0, result, pcf_current_information);
      Assert::AreEqual(0, bag.Count, pcf_current_information);
      Assert::IsFalse(bag.TryTake(result), pcf_current_information);
    }
    
  };
  
  pcf_test(ConcurrentBagTest, Add)
  pcf_test(ConcurrentBagTest, GetEnumerator)
  pcf_test(ConcurrentBagTest, TryPeek)
  pcf_test(ConcurrentBagTest, TryTake)
}
