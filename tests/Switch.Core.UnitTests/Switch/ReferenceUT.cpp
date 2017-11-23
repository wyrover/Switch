#include <Switch/Ref.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(ReferenceTest, SetNullToPointer) {
    ref<int> ptr;
    ASSERT_TRUE(ptr == null);
    ASSERT_THROW(ptr(), std::exception);
    ASSERT_THROW(ptr.ToObject(), std::exception);
    ASSERT_THROW(ptr.ToPointer(), std::exception);
  }
  
  TEST(ReferenceTest, SetNotNullToPointer) {
    String str("Test Reference!");
    ref<string> ref(str);
    ASSERT_FALSE(ref == null);
    ASSERT_NO_THROW(ref());
    ASSERT_NO_THROW(ref.ToObject());
  }
  
  TEST(ReferenceTest, SetPointerFromEqual) {
    string str = "Test Reference!";
    ref<string> ptr(str);
    EXPECT_NE((string*)null, ptr.ToPointer());
    ASSERT_FALSE(ptr == null);
    ASSERT_NO_THROW(ptr());
    ASSERT_NO_THROW(ptr.ToObject());
  }
  
  TEST(ReferenceTest, SetPointerFromPointer) {
    string s = "Test Reference!";
    ref<string> str(s);
    ref<string> ptr(str);
    EXPECT_NE((string*)null, ptr.ToPointer());
    ASSERT_FALSE(ptr == null);
    ASSERT_NO_THROW(ptr());
    ASSERT_NO_THROW(ptr.ToObject());
    
    ASSERT_EQ(str.ToPointer(), ptr.ToPointer());
  }
  
  TEST(ReferenceTest, SetNullToPointerAndReset) {
    ref<string> ptr;
    ASSERT_NO_THROW(ptr.Reset());
    ASSERT_THROW(ptr.ToPointer(), std::exception);
  }
  
  TEST(ReferenceTest, SetPointerFromANativePointerAndReset) {
    string str = "Test Reference!";
    ref<string> ptr(str);
    ASSERT_NO_THROW(ptr.Reset());
    ASSERT_THROW(ptr.ToPointer(), std::exception);
  }
  
  TEST(ReferenceTest, SetNullToPointerAndCheckIsNullOrEmpty) {
    ref<string> ptr;
    ASSERT_TRUE(ptr == null);
  }
  
  TEST(ReferenceTest, SetPointerFromANativePointerAndCheckIsNullOrEmpty) {
    string str = "Test Reference!";
    ref<string> ptr(str);
    ASSERT_FALSE(ptr == null);
  }
  
  TEST(ReferenceTest, SetNullToPointerAndResetResetToANativePointer) {
    string str = "Test Reference!";
    ref<string> ptr;
    ASSERT_NO_THROW(ptr.Reset(str));
    ASSERT_EQ(&str, ptr.ToPointer());
  }
  
  TEST(ReferenceTest, SetPointerFromANativePointerAndResetToANativePointer) {
    string str = "Test Reference!";
    string str2 = "Another Test Reference!";
    ref<string> ptr(str);
    ASSERT_NO_THROW(ptr.Reset(str2));
    ASSERT_EQ(&str2, ptr.ToPointer());
  }
  
  TEST(ReferenceTest, SetTwoPointerFromANativePointerAndSwap) {
    string str = "Test Reference!";
    string str2 = "Another Test Reference!";
    ref<string> ptr(str);
    ref<string> ptr2(str2);
    
    ASSERT_NO_THROW(ptr.Swap(ptr2));
    ASSERT_EQ(&str, ptr2.ToPointer());
    ASSERT_EQ(&str2, ptr.ToPointer());
  }
  
  TEST(ReferenceTest, SetPointerFromANativePointerAndGetValue) {
    string str = "Test Reference!";
    ref<string> ptr(str);
    
    ASSERT_EQ(str, ptr.ToObject());
  }
  
  TEST(ReferenceTest, SetPointerFromANativePointerAndGetPointer) {
    string str = "Test Reference!";
    ref<string> ptr(str);
    ASSERT_EQ(&str, ptr.ToPointer());
  }
  
  TEST(ReferenceTest, SetNullToPointerAndGetToString) {
    ref<string> ptr;
    ASSERT_EQ("Switch::Ref [Reference=null]", ptr.ToString());
  }
  
  TEST(ReferenceTest, SetPointerFromANativePointerAndGetToString) {
    string str = "Test Reference!";
    ref<string> ptr(str);
    ASSERT_TRUE(string(ptr.ToString().c_str()).StartsWith("Switch::Ref [Reference="));
    ASSERT_TRUE(string(ptr.ToString().c_str()).EndsWith("]"));
    EXPECT_NE("Switch::Ref [Reference=null]", ptr.ToString());
  }
  
}

