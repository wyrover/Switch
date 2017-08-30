#include <Switch/System/Collections/Generic/Dictionary.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Collections::Generic;
using namespace TUnit;

namespace {
  TEST(Dictionary, Constructor) {
    Dictionary<string, string> dictionary;
    EXPECT_EQ(0,dictionary.Count);
  }

  TEST(Dictionary, AddKeyValRef) {
    Dictionary<Int32, string> dictionary;
    dictionary.Add(Int32(1), "Test1");
    dictionary.Add(Int32(2), "Test2");
    dictionary.Add(Int32(3), "Test3");
    dictionary.Add(Int32(4), "Test4");
    EXPECT_TRUE(dictionary.ContainsKey(Int32(1)));
    EXPECT_TRUE(dictionary.ContainsValue(string("Test4")));
    EXPECT_EQ(dictionary[Int32(4)], "Test4");
  }

  TEST(Dictionary, AddSpPairRef) {
    Dictionary<Int32, string> dictionary;
    refptr<KeyValuePair<Int32, string>> pair(new KeyValuePair<Int32, string>(Int32(42), "Hello"));

    dictionary.Add(*pair);
    EXPECT_TRUE(dictionary.ContainsKey(Int32(42)));
    EXPECT_TRUE(dictionary.ContainsValue(string("Hello")));
    EXPECT_EQ(dictionary[Int32(42)], string("Hello"));
  }

  TEST(Dictionary, AddPairPtr) {
    Dictionary<Int32, string> dictionary;
    dictionary.Add(KeyValuePair<Int32, string>(Int32(42), "Hello"));
    EXPECT_TRUE(dictionary.ContainsKey(Int32(42)));
    EXPECT_TRUE(dictionary.ContainsValue(string("Hello")));
    EXPECT_EQ(dictionary[Int32(42)], "Hello");
  }

  TEST(Dictionary, IntPtr) {
    Dictionary<IntPtr, IntPtr> dictionary;
    dictionary.Add(IntPtr(Int32(1)), IntPtr(Int32(2)));
    dictionary.Add(IntPtr(Int32(2)), IntPtr(Int32(3)));
    IntPtr res= dictionary[IntPtr(Int32(2))];
    EXPECT_EQ(res, IntPtr(Int32(3)));
  }

  TEST(Dictionary, Enumerator) {
    Dictionary<int32, string> ints;
    ints[5] = "five";
    ints[1] = "one";
    ints[2] = "two";

    bool seen[6] = { false, false, false, false, false, false };

    Dictionary<int32, string>::Enumerator e(ints);
    while (e.MoveNext()) {
      KeyValuePair<int32, string> pair = e.Current;
      int32 key = pair.Key();
      ASSERT_GE(key, 0);
      ASSERT_LT(key, 6);
      EXPECT_FALSE(seen[key]);
      seen[key] = true;
      if (key == 1) EXPECT_EQ("one", pair.Value());
      if (key == 2) EXPECT_EQ("two", pair.Value());
      if (key == 5) EXPECT_EQ("five", pair.Value());
    }
    EXPECT_FALSE(seen[0]);
    EXPECT_FALSE(seen[3]);
    EXPECT_FALSE(seen[4]);
  }

  TEST(Dictionary, Enumerator_Empty) {
    Dictionary<int32, string> ints;
    Dictionary<int32, string>::Enumerator e(ints);
    while (e.MoveNext()) {
      EXPECT_FALSE(true);
    }
  }

}
