#include <Switch/Any.hpp>
#include <Switch/Boxing.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(BoxTest, BoxingBoolean) {
    ASSERT_TRUE(is<Boolean>(Box(true)));
  }
  
  TEST(BoxTest, BoxingByte) {
    ASSERT_TRUE(is<Byte>(Box(byte(42))));
  }
  
  TEST(BoxTest, BoxingChar) {
    ASSERT_TRUE(is<Char>(Box(char('c'))));
  }
  
  TEST(BoxTest, BoxingWChar) {
    ASSERT_TRUE(is<Char>(Box(wchar('c'))));
  }
  
  TEST(BoxTest, BoxingChar16) {
    ASSERT_TRUE(is<Char>(Box(char16('c'))));
  }
  
  TEST(BoxTest, BoxingChar32) {
    ASSERT_TRUE(is<Char>(Box(char32('c'))));
  }
  
  TEST(BoxTest, BoxingDouble) {
    ASSERT_TRUE(is<Double>(Box(double(42))));
  }
  
  TEST(BoxTest, BoxingInt16) {
    ASSERT_TRUE(is<Int16>(Box(int16(42))));
  }
  
  TEST(BoxTest, BoxingInt32) {
    ASSERT_TRUE(is<Int32>(Box(int32(42))));
  }
  
  TEST(BoxTest, BoxingInt64) {
    ASSERT_TRUE(is<Int64>(Box(int64(42))));
  }
  
  TEST(BoxTest, BoxingSByte) {
    ASSERT_TRUE(is<SByte>(Box(sbyte(42))));
  }
  
  TEST(BoxTest, BoxingSingle) {
    ASSERT_TRUE(is<Single>(Box(float(42))));
  }
  
  TEST(BoxTest, BoxingString) {
    ASSERT_TRUE(is<string>(Box(string("Forty two"))));
  }
  
  TEST(BoxTest, BoxingUInt16) {
    ASSERT_TRUE(is<UInt16>(Box(uint16(42))));
  }
  
  TEST(BoxTest, BoxingUInt32) {
    ASSERT_TRUE(is<UInt32>(Box(uint32(42))));
  }
  
  TEST(BoxTest, BoxingUInt64) {
    ASSERT_TRUE(is<UInt64>(Box(uint64(42))));
  }
  
  TEST(BoxTest, BoxingVoidPointer) {
    ASSERT_TRUE(is<IntPtr>(Box((void*)42)));
  }
  
  TEST(BoxTest, BoxingConstCharPointer) {
    ASSERT_TRUE(is<string>(Box("Forty two")));
  }
  
  TEST(BoxTest, BoxingConstWCharPointer) {
    ASSERT_TRUE(is<string>(Box(L"Forty two")));
  }
  
  TEST(BoxTest, BoxingConstChar16Pointer) {
    ASSERT_TRUE(is<string>(Box(u"Forty two")));
  }
  
  TEST(BoxTest, BoxingConstChar32Pointer) {
    ASSERT_TRUE(is<string>(Box(U"Forty two")));
  }
  
  TEST(BoxTest, BoxingTimeSpan) {
    ASSERT_TRUE(is<TimeSpan>(Box(12_h + 24_min + 32_s)));
  }
  
  TEST(BoxTest, BoxingAny) {
    ASSERT_TRUE(is<Int32>(Box(Any(42))));
  }
  
  TEST(BoxTest, BoxingMyStruct) {
    struct MyStruct {};
    ASSERT_TRUE(is<MyStruct>(Box(MyStruct())));
  }
}
