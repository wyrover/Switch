#include <Pcf/Reference.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {

TEST(ReferenceTest, SetNullToPointer) {
  Pcf::Reference<int> ptr;
  EXPECT_TRUE(ptr.IsNull());
  EXPECT_THROW(ptr(), std::exception);
  EXPECT_THROW(ptr.ToObject(), std::exception);
  EXPECT_THROW(ptr.ToPointer(), std::exception);
}

TEST(ReferenceTest, SetNotNullToPointer) {
  String str("Test Reference!");
  Pcf::Reference<string> ref(str);
  EXPECT_FALSE(ref.IsNull());
  EXPECT_NO_THROW(ref());
  EXPECT_NO_THROW(ref.ToObject());  
}

TEST(ReferenceTest, SetPointerFromEqual) {
  string str = "Test Reference!";
  Pcf::Reference<string> ptr(str);
  EXPECT_NE((string*)null, ptr.ToPointer());
  EXPECT_FALSE(ptr.IsNull());
  EXPECT_NO_THROW(ptr());
  EXPECT_NO_THROW(ptr.ToObject());
}

TEST(ReferenceTest, SetPointerFromPointer) {
  string s = "Test Reference!";
  Pcf::Reference<string> str(s);
  Pcf::Reference<string> ptr(str);
  EXPECT_NE((string*)null, ptr.ToPointer());
  EXPECT_FALSE(ptr.IsNull());
  EXPECT_NO_THROW(ptr());
  EXPECT_NO_THROW(ptr.ToObject());
  
  EXPECT_EQ(str.ToPointer(), ptr.ToPointer());
}

TEST(ReferenceTest, SetNullToPointerAndReset) {
  Pcf::Reference<string> ptr;
  EXPECT_NO_THROW(ptr.Reset());
  EXPECT_THROW(ptr.ToPointer(), std::exception);
}

TEST(ReferenceTest, SetPointerFromANativePointerAndReset) {
  string str = "Test Reference!";
  Pcf::Reference<string> ptr(str);
  EXPECT_NO_THROW(ptr.Reset());
  EXPECT_THROW(ptr.ToPointer(), std::exception);
}

TEST(ReferenceTest, SetNullToPointerAndCheckIsNullOrEmpty) {
  Pcf::Reference<string> ptr;
  EXPECT_TRUE(ptr.IsNull());
}

TEST(ReferenceTest, SetPointerFromANativePointerAndCheckIsNullOrEmpty) {
  string str = "Test Reference!";
  Pcf::Reference<string> ptr(str);
  EXPECT_FALSE(ptr.IsNull());
}

TEST(ReferenceTest, SetNullToPointerAndResetResetToANativePointer) {
  string str = "Test Reference!";
  Pcf::Reference<string> ptr;
  EXPECT_NO_THROW(ptr.Reset(str));
  EXPECT_EQ(&str, ptr.ToPointer());
}

TEST(ReferenceTest, SetPointerFromANativePointerAndResetToANativePointer) {
  string str = "Test Reference!";
  string str2 = "Another Test Reference!";
  Pcf::Reference<string> ptr(str);
  EXPECT_NO_THROW(ptr.Reset(str2));
  EXPECT_EQ(&str2, ptr.ToPointer());
}

TEST(ReferenceTest, SetTwoPointerFromANativePointerAndSwap) {
  string str = "Test Reference!";
  string str2 = "Another Test Reference!";
  Pcf::Reference<string> ptr(str);
  Pcf::Reference<string> ptr2(str2);
  
  EXPECT_NO_THROW(ptr.Swap(ptr2));
  EXPECT_EQ(&str, ptr2.ToPointer());
  EXPECT_EQ(&str2, ptr.ToPointer());
}

TEST(ReferenceTest, SetPointerFromANativePointerAndGetValue) {
  string str = "Test Reference!";
  Pcf::Reference<string> ptr(str);
  
  EXPECT_EQ(str, ptr.ToObject());
}

TEST(ReferenceTest, SetPointerFromANativePointerAndGetPointer) {
  string str = "Test Reference!";
  Pcf::Reference<string> ptr(str);
  EXPECT_EQ(&str, ptr.ToPointer());
}

TEST(ReferenceTest, SetNullToPointerAndGetToString) {
  Pcf::Reference<string> ptr;
  EXPECT_EQ("Pcf::Reference [Reference=null]", ptr.ToString());
}

TEST(ReferenceTest, SetPointerFromANativePointerAndGetToString) {
  string str = "Test Reference!";
  Pcf::Reference<string> ptr(str);
  EXPECT_TRUE(string(ptr.ToString().c_str()).StartsWith("Pcf::Reference [Reference="));
  EXPECT_TRUE(string(ptr.ToString().c_str()).EndsWith("]"));
  EXPECT_NE("Pcf::Reference [Reference=null]", ptr.ToString());
}

}

