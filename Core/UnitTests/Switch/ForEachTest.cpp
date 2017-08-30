#include <Switch/System/Collections/Generic/HashSet.hpp>
#include <Switch/System/Collections/Generic/LinkedList.hpp>
#include <Switch/System/Collections/Generic/SortedSet.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class ForeachTest : public TestFixture {
  protected:
    void Vector() {
      std::vector<Int32> collection(10);
      int32 index = 0;
      for (Int32& item : collection) {
        item = 100 + index++;
      }
      
      index = 0;
      int32 checksum1 = 0;
      int32 checksum2 = 0;
      for (Int32 item : collection) {
        checksum1 += 100 + index;
        checksum2 += item;
        Assert::AreEqual(100 + index++, item, pcf_current_information);
      }
      
      Assert::AreEqual(checksum1, checksum2, pcf_current_information);
    }
    
    void List() {
      System::Collections::Generic::List<int32> collection = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      int32 index = 0;
      for (int32& item : collection) {
        item = 100 + index++;
      }
      
      index = 0;
      int32 checksum1 = 0;
      int32 checksum2 = 0;
      for (int32 item : collection) {
        checksum1 += 100 + index;
        checksum2 += item;
        Assert::AreEqual(100 + index++, item, pcf_current_information);
      }
      
      Assert::AreEqual(checksum1, checksum2, pcf_current_information);
    }
    
    void LinkedList() {
      System::Collections::Generic::LinkedList<int32> collection = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      int32 index = 0;
      for (int32& item : collection) {
        item = 100 + index++;
      }
      
      index = 0;
      int32 checksum1 = 0;
      int32 checksum2 = 0;
      for (int32 item : collection) {
        checksum1 += 100 + index;
        checksum2 += item;
        Assert::AreEqual(100 + index++, item, pcf_current_information);
      }
      
      Assert::AreEqual(checksum1, checksum2, pcf_current_information);
    }
    
    void HashSet() {
      System::Collections::Generic::HashSet<int32> collection = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
      
      int32 index = 0;
      int32 checksum1 = 0;
      int32 checksum2 = 0;
      for (int32 item : collection) {
        checksum1 += 100 + index++;
        checksum2 += item;
      }
      
      Assert::AreEqual(checksum1, checksum2, pcf_current_information);
    }
    
    void SortedSet() {
      System::Collections::Generic::SortedSet<int32> collection = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
      
      int32 index = 0;
      int32 checksum1 = 0;
      int32 checksum2 = 0;
      for (int32 item : collection) {
        checksum1 += 100 + index++;
        checksum2 += item;
      }
      
      Assert::AreEqual(checksum1, checksum2, pcf_current_information);
    }
    
    void SortedDictionary() {
      System::Collections::Generic::SortedDictionary<int32, int32> collection = {{0, 100}, {1, 101}, {2, 102}, {3, 103}, {4, 104}, {5, 105}, {6, 106}, {7, 107}, {8, 108}, {9, 109}};
      
      int32 index = 0;
      int32 checksum1 = 0;
      int32 checksum2 = 0;
      for (auto item : collection) {
        checksum1 += 100 + index++;
        checksum2 += item.Value();
      }
      
      Assert::AreEqual(checksum1, checksum2, pcf_current_information);
    }
    
    void ListT() {
      System::Collections::Generic::List<Int32> testList;
      int32 count, index;
      
      testList.Add(1);
      testList.Add(2);
      testList.Add(3);
      testList.Add(4);
      testList.Add(5);
      
      // test foreach without scope
      index = 1;
      for (Int32 i : testList)
        Assert::AreEqual(index++, i, pcf_current_information);
      
      Assert::AreEqual(index, 6, pcf_current_information);
      
      // test full enumeration
      index = 0;
      count = 0;
      for (Int32 i : testList)  {
        Assert::AreEqual(++index, i, pcf_current_information);
        count++;
      }
      Assert::AreEqual(count, 5, pcf_current_information);
      
      // test break
      index = 0;
      count = 0;
      for (Int32 i : testList) {
        Assert::AreEqual(++index, i, pcf_current_information);
        count++;
        if (count == 2)
          break;
      }
      Assert::AreEqual(count, 2, pcf_current_information);
      
      // test modification
      for (Int32& i : testList) {
        i++;
      }
      
      index = 1;
      for (Int32 i : testList) {
        Assert::AreEqual(++index, i, pcf_current_information);
      }
    }
    
    void Array() {
      System::Array<int32> collection = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      int32 index = 0;
      for (int32& item : collection) {
        item = 100 + index++;
      }
      
      index = 0;
      int32 checksum1 = 0;
      int32 checksum2 = 0;
      for (int32 item : collection) {
        checksum1 += 100 + index;
        checksum2 += item;
        Assert::AreEqual(100 + index++, item, pcf_current_information);
      }
      
      Assert::AreEqual(checksum1, checksum2, pcf_current_information);
    }
    
    void Array2() {
      System::Array<uint32> testArray(5);
      uint32 count, index;
      
      testArray[0] = 1;
      testArray[1] = 2;
      testArray[2] = 3;
      testArray[3] = 4;
      testArray[4] = 5;
      
      // test foreach without scope
      for (uint32 i : testArray)
        index = i;
      
      Assert::AreEqual(index, 5u, pcf_current_information);
      
      // test full enumeration
      index = 0;
      count = 0;
      for (uint32 i : testArray) {
        Assert::AreEqual(++index, i, pcf_current_information);
        count++;
      }
      Assert::AreEqual(count, 5u, pcf_current_information);
      
      // test break
      index = 0;
      count = 0;
      for (uint32 i : testArray) {
        Assert::AreEqual(++index, i, pcf_current_information);
        count++;
        if (count == 2)
          break;
      }
      Assert::AreEqual(count, 2u, pcf_current_information);
      
      // test modification
      for (uint32& i : testArray) {
        i++;
      }
      
      index = 1;
      for (uint32 i : testArray) {
        Assert::AreEqual(++index, i, pcf_current_information);
      }
    }
    
    void Dictionary() {
      System::Collections::Generic::Dictionary<int32, int32> collection = {{0, 100}, {1, 101}, {2, 102}, {3, 103}, {4, 104}, {5, 105}, {6, 106}, {7, 107}, {8, 108}, {9, 109}};
      
      int32 index = 0;
      int32 checksum1 = 0;
      int32 checksum2 = 0;
      for (auto item : collection) {
        checksum1 += 100 + index++;
        checksum2 += item.Value();
      }
      
      Assert::AreEqual(checksum1, checksum2, pcf_current_information);
    }
    
    void Dictionary2() {
      System::Collections::Generic::Dictionary<uint32, string> testDictionary;
      uint32 count = 0u;
      
      testDictionary[1] = "1";
      testDictionary[2] = "2";
      testDictionary[3] = "3";
      testDictionary[4] = "4";
      testDictionary[5] = "5";
      
      // test foreach without scope
      for (auto i : testDictionary)
        count += i.Key();
      Assert::AreEqual(15u, count, pcf_current_information);
      
      // test full enumeration
      count = 0u;
      for (auto i : testDictionary) {
        Assert::GreaterOrEqual(i.Key(), 1u, pcf_current_information);
        Assert::LessOrEqual(i.Key(), 5u, pcf_current_information);
        Assert::AreEqual(UInt32(i.Key()).ToString(), i.Value(), pcf_current_information);
        count++;
      }
      Assert::AreEqual(5u, count, pcf_current_information);
      
      // test break
      count = 0u;
      for (auto i : testDictionary) {
        if (++count == 2u)
          break;
      }
      
      Assert::AreEqual(count, 2u, pcf_current_information);
    }
    
    void String() {
      string collection = "Hello, World!";
      
      int32 index = 0;
      int32 checksum1 = 0;
      int32 checksum2 = 0;
      for (char32 item : collection) {
        checksum1 += collection[index++];
        checksum2 += item;
      }
      
      Assert::AreEqual(checksum1, checksum2, pcf_current_information);
    }
    
    
    void NativeArray() {
      const byte bytes[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
      
      byte i = 0;
      for (byte b : bytes) {
        Assert::AreEqual(i++, b, pcf_current_information);
      }
    }
  };
  
  pcf_test(ForeachTest, Vector)
  pcf_test(ForeachTest, List)
  pcf_test(ForeachTest, LinkedList)
  pcf_test(ForeachTest, HashSet)
  pcf_test(ForeachTest, SortedSet)
  pcf_test(ForeachTest, SortedDictionary)
  pcf_test(ForeachTest, ListT)
  pcf_test(ForeachTest, Array)
  pcf_test(ForeachTest, Array2)
  pcf_test(ForeachTest, Dictionary)
  pcf_test(ForeachTest, Dictionary2)
  pcf_test(ForeachTest, String)
  pcf_test(ForeachTest, NativeArray)
}
