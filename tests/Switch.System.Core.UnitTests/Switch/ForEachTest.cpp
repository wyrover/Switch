#include <Switch/System/Collections/Generic/HashSet.hpp>
#include <Switch/System/Collections/Generic/LinkedList.hpp>
#include <Switch/System/Collections/Generic/SortedDictionary.hpp>
#include <Switch/System/Collections/Generic/SortedSet.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(ForeachTest, Vector) {
    std::vector<Int32> collection(10);
    int32 index = 0;
    for (Int32& item : collection)
      item = 100 + index++;

    index = 0;
    int32 checksum1 = 0;
    int32 checksum2 = 0;
    for (Int32 item : collection) {
      checksum1 += 100 + index;
      checksum2 += item;
      ASSERT_EQ(100 + index++, item);
    }

    ASSERT_EQ(checksum1, checksum2);
  }

  TEST(ForeachTest, List) {
    System::Collections::Generic::List<int32> collection = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int32 index = 0;
    for (int32& item : collection)
      item = 100 + index++;

    index = 0;
    int32 checksum1 = 0;
    int32 checksum2 = 0;
    for (int32 item : collection) {
      checksum1 += 100 + index;
      checksum2 += item;
      ASSERT_EQ(100 + index++, item);
    }

    ASSERT_EQ(checksum1, checksum2);
  }

  TEST(ForeachTest, LinkedList) {
    System::Collections::Generic::LinkedList<int32> collection = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int32 index = 0;
    for (int32& item : collection)
      item = 100 + index++;

    index = 0;
    int32 checksum1 = 0;
    int32 checksum2 = 0;
    for (int32 item : collection) {
      checksum1 += 100 + index;
      checksum2 += item;
      ASSERT_EQ(100 + index++, item);
    }

    ASSERT_EQ(checksum1, checksum2);
  }

  TEST(ForeachTest, HashSet) {
    System::Collections::Generic::HashSet<int32> collection = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};

    int32 index = 0;
    int32 checksum1 = 0;
    int32 checksum2 = 0;
    for (int32 item : collection) {
      checksum1 += 100 + index++;
      checksum2 += item;
    }

    ASSERT_EQ(checksum1, checksum2);
  }

  TEST(ForeachTest, SortedSet) {
    System::Collections::Generic::SortedSet<int32> collection = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};

    int32 index = 0;
    int32 checksum1 = 0;
    int32 checksum2 = 0;
    for (int32 item : collection) {
      checksum1 += 100 + index++;
      checksum2 += item;
    }

    ASSERT_EQ(checksum1, checksum2);
  }

  TEST(ForeachTest, SortedDictionary) {
    System::Collections::Generic::SortedDictionary<int32, int32> collection = {{0, 100}, {1, 101}, {2, 102}, {3, 103}, {4, 104}, {5, 105}, {6, 106}, {7, 107}, {8, 108}, {9, 109}};

    int32 index = 0;
    int32 checksum1 = 0;
    int32 checksum2 = 0;
    for (auto item : collection) {
      checksum1 += 100 + index++;
      checksum2 += item.Value();
    }

    ASSERT_EQ(checksum1, checksum2);
  }

  TEST(ForeachTest, ListT) {
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
      ASSERT_EQ(index++, i);

    ASSERT_EQ(index, 6);

    // test full enumeration
    index = 0;
    count = 0;
    for (Int32 i : testList)  {
      ASSERT_EQ(++index, i);
      count++;
    }
    ASSERT_EQ(count, 5);

    // test break
    index = 0;
    count = 0;
    for (Int32 i : testList) {
      ASSERT_EQ(++index, i);
      count++;
      if (count == 2)
        break;
    }
    ASSERT_EQ(count, 2);

    // test modification
    for (Int32& i : testList)
      i++;

    index = 1;
    for (Int32 i : testList)
      ASSERT_EQ(++index, i);
  }

  TEST(ForeachTest, Array) {
    System::Array<int32> collection = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int32 index = 0;
    for (int32& item : collection)
      item = 100 + index++;

    index = 0;
    int32 checksum1 = 0;
    int32 checksum2 = 0;
    for (int32 item : collection) {
      checksum1 += 100 + index;
      checksum2 += item;
      ASSERT_EQ(100 + index++, item);
    }

    ASSERT_EQ(checksum1, checksum2);
  }

  TEST(ForeachTest, Array2) {
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

    ASSERT_EQ(index, 5u);

    // test full enumeration
    index = 0;
    count = 0;
    for (uint32 i : testArray) {
      ASSERT_EQ(++index, i);
      count++;
    }
    ASSERT_EQ(count, 5u);

    // test break
    index = 0;
    count = 0;
    for (uint32 i : testArray) {
      ASSERT_EQ(++index, i);
      count++;
      if (count == 2)
        break;
    }
    ASSERT_EQ(count, 2u);

    // test modification
    for (uint32& i : testArray)
      i++;

    index = 1;
    for (uint32 i : testArray)
      ASSERT_EQ(++index, i);
  }

  TEST(ForeachTest, Dictionary) {
    System::Collections::Generic::Dictionary<int32, int32> collection = {{0, 100}, {1, 101}, {2, 102}, {3, 103}, {4, 104}, {5, 105}, {6, 106}, {7, 107}, {8, 108}, {9, 109}};

    int32 index = 0;
    int32 checksum1 = 0;
    int32 checksum2 = 0;
    for (auto item : collection) {
      checksum1 += 100 + index++;
      checksum2 += item.Value();
    }

    ASSERT_EQ(checksum1, checksum2);
  }

  TEST(ForeachTest, Dictionary2) {
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
    ASSERT_EQ(15u, count);

    // test full enumeration
    count = 0u;
    for (auto i : testDictionary) {
      ASSERT_GE(i.Key(), 1u);
      ASSERT_LE(i.Key(), 5u);
      ASSERT_EQ(UInt32(i.Key()).ToString(), i.Value());
      count++;
    }
    ASSERT_EQ(5u, count);

    // test break
    count = 0u;
    for (auto i : testDictionary) {
      if (++count == 2u)
        break;
    }

    ASSERT_EQ(count, 2u);
  }

  TEST(ForeachTest, String) {
    string collection = "Hello, World!";

    int32 index = 0;
    int32 checksum1 = 0;
    int32 checksum2 = 0;
    for (char32 item : collection) {
      checksum1 += collection[index++];
      checksum2 += item;
    }

    ASSERT_EQ(checksum1, checksum2);
  }


  TEST(ForeachTest, NativeArray) {
    const byte bytes[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    byte i = 0;
    for (byte b : bytes)
      ASSERT_EQ(i++, b);
  }
}

