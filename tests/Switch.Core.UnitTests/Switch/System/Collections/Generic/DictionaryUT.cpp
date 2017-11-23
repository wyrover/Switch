#include <Switch/System/Collections/Generic/Dictionary.hpp>
#include <Switch/System/Int32.hpp>
#include <Switch/System/IntPtr.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Collections::Generic;

namespace {
  TEST(DictionaryTest, Constructor) {
    Dictionary<string, string> dictionary;
    ASSERT_EQ(0, dictionary.Count);
  }
  
  TEST(DictionaryTest, AddKeyValRef) {
    Dictionary<Int32, string> dictionary;
    dictionary.Add(Int32(1), "Test1");
    dictionary.Add(Int32(2), "Test2");
    dictionary.Add(Int32(3), "Test3");
    dictionary.Add(Int32(4), "Test4");
    ASSERT_TRUE(dictionary.ContainsKey(Int32(1)));
    ASSERT_TRUE(dictionary.ContainsValue(string("Test4")));
    ASSERT_EQ(dictionary[Int32(4)], "Test4");
  }
  
  TEST(DictionaryTest, AddSpPairRef) {
    Dictionary<Int32, string> dictionary;
    refptr<KeyValuePair<Int32, string>> pair(new KeyValuePair<Int32, string>(Int32(42), "Hello"));
    
    dictionary.Add(*pair);
    ASSERT_TRUE(dictionary.ContainsKey(Int32(42)));
    ASSERT_TRUE(dictionary.ContainsValue(string("Hello")));
    ASSERT_EQ(dictionary[Int32(42)], string("Hello"));
  }
  
  TEST(DictionaryTest, AddPairPtr) {
    Dictionary<Int32, string> dictionary;
    dictionary.Add(KeyValuePair<Int32, string>(Int32(42), "Hello"));
    ASSERT_TRUE(dictionary.ContainsKey(Int32(42)));
    ASSERT_TRUE(dictionary.ContainsValue(string("Hello")));
    ASSERT_EQ(dictionary[Int32(42)], "Hello");
  }
  
  TEST(DictionaryTest, IntPtr) {
    Dictionary<IntPtr, IntPtr> dictionary;
    dictionary.Add(IntPtr(Int32(1)), IntPtr(Int32(2)));
    dictionary.Add(IntPtr(Int32(2)), IntPtr(Int32(3)));
    IntPtr res = dictionary[IntPtr(Int32(2))];
    ASSERT_EQ(res, IntPtr(Int32(3)));
  }
  
  TEST(DictionaryTest, Enumerator) {
    Dictionary<int32, string> ints;
    ints[5] = "five";
    ints[1] = "one";
    ints[2] = "two";
    
    bool seen[6] = { false, false, false, false, false, false };
    
    Dictionary<int32, string>::Enumerator e(ints);
    while(e.MoveNext()) {
      KeyValuePair<int32, string> pair = e.Current;
      int32 key = pair.Key();
      ASSERT_GE(key, 0);
      ASSERT_LT(key, 6);
      ASSERT_FALSE(seen[key]);
      seen[key] = true;
      if(key == 1) ASSERT_EQ("one", pair.Value());
      if(key == 2) ASSERT_EQ("two", pair.Value());
      if(key == 5) ASSERT_EQ("five", pair.Value());
    }
    ASSERT_FALSE(seen[0]);
    ASSERT_FALSE(seen[3]);
    ASSERT_FALSE(seen[4]);
  }
  
  TEST(DictionaryTest, Enumerator_Empty) {
    Dictionary<int32, string> ints;
    Dictionary<int32, string>::Enumerator e(ints);
    while(e.MoveNext())
      ASSERT_FALSE(true);
  }
  
}
