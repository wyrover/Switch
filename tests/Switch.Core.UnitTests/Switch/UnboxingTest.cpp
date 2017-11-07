#include <Switch/Boxing.hpp>
#include <Switch/Any.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  bool IsBool(bool) {return true;}
  template<typename T> bool IsBool(T) {return false;}
  bool IsByte(byte) {return true;}
  template<typename T> bool IsByte(T) {return false;}
  bool IsChar(char) {return true;}
  template<typename T> bool IsChar(T) {return false;}
  bool IsWChar(wchar) {return true;}
  template<typename T> bool IsWChar(T) {return false;}
  bool IsChar16(char16) {return true;}
  template<typename T> bool IsChar16(T) {return false;}
  bool IsChar32(char32) {return true;}
  template<typename T> bool IsChar32(T) {return false;}
  bool IsDouble(double) {return true;}
  template<typename T> bool IsDouble(T) {return false;}
  bool IsInt16(int16) {return true;}
  template<typename T> bool IsInt16(T) {return false;}
  bool IsInt32(int32) {return true;}
  template<typename T> bool IsInt32(T) {return false;}
  bool IsInt64(int64) {return true;}
  template<typename T> bool IsInt64(T) {return false;}
  bool IsIntPtr(intptr) {return true;}
  template<typename T> bool IsIntPtr(T) {return false;}
  bool IsSByte(sbyte) {return true;}
  template<typename T> bool IsSByte(T) {return false;}
  bool IsSingle(float) {return true;}
  template<typename T> bool IsSingle(T) {return false;}
  bool IsConstCharPointer(const char*) {return true;}
  template<typename T> bool IsConstCharPointer(T) {return false;}
  bool IsConstWCharPointer(const wchar*) {return true;}
  template<typename T> bool IsConstWCharPointer(T) {return false;}
  bool IsConstChar16Pointer(const char16*) {return true;}
  template<typename T> bool IsConstChar16Pointer(T) {return false;}
  bool IsConstChar32Pointer(const char32*) {return true;}
  template<typename T> bool IsConstChar32Pointer(T) {return false;}
  bool IsUInt16(uint16) {return true;}
  template<typename T> bool IsUInt16(T) {return false;}
  bool IsUInt32(uint32) {return true;}
  template<typename T> bool IsUInt32(T) {return false;}
  bool IsUInt64(uint64) {return true;}
  template<typename T> bool IsUInt64(T) {return false;}
  bool IsUIntPtr(uintptr) {return true;}
  template<typename T> bool IsUIntPtr(T) {return false;}
  bool IsVoidPointer(void*) {return true;}
  template<typename T> bool IsVoidPointer(T) {return false;}
  
  TEST(UnboxTest, UnboxingBoolean) {
    ASSERT_TRUE(IsBool(Unbox(Boolean(true))));
  }
  
  TEST(UnboxTest, UnboxingByte) {
    ASSERT_TRUE(IsByte(Unbox(Byte(42))));
  }
  
  TEST(UnboxTest, UnboxingChar) {
    ASSERT_TRUE(IsChar32(Unbox(Char('c'))));
  }
  
  TEST(UnboxTest, UnboxingDouble) {
    ASSERT_TRUE(IsDouble(Unbox(Double(42))));
  }
  
  TEST(UnboxTest, UnboxingInt16) {
    ASSERT_TRUE(IsInt16(Unbox(Int16(42))));
  }
  
  TEST(UnboxTest, UnboxingInt32) {
    ASSERT_TRUE(IsInt32(Unbox(Int32(42))));
  }
  
  TEST(UnboxTest, UnboxingInt64) {
    ASSERT_TRUE(IsInt64(Unbox(Int64(42))));
  }
  
  TEST(UnboxTest, UnboxingIntPtr) {
    ASSERT_TRUE(IsIntPtr(Unbox(IntPtr((intptr)42))));
  }
  
  TEST(UnboxTest, UnboxingSByte) {
    ASSERT_TRUE(IsSByte(Unbox(SByte(42))));
  }
  
  TEST(UnboxTest, UnboxingSingle) {
    ASSERT_TRUE(IsSingle(Unbox(Single(42))));
  }
  
  TEST(UnboxTest, UnboxingString) {
    ASSERT_TRUE(IsConstCharPointer(Unbox(string("Forty two"))));
  }
  
  TEST(UnboxTest, UnboxingUInt16) {
    ASSERT_TRUE(IsUInt16(Unbox(UInt16(42))));
  }
  
  TEST(UnboxTest, UnboxingUInt32) {
    ASSERT_TRUE(IsUInt32(Unbox(UInt32(42))));
  }
  
  TEST(UnboxTest, UnboxingUInt64) {
    ASSERT_TRUE(IsUInt64(Unbox(UInt64(42))));
  }
  
  TEST(UnboxTest, UnboxingUIntPtr) {
    ASSERT_TRUE(IsUIntPtr(Unbox(UIntPtr((uintptr)42))));
  }
  
  TEST(UnboxTest, UnboxingConstCharPointer) {
    ASSERT_TRUE(IsConstCharPointer(Unbox("Forty two")));
  }
  
  TEST(UnboxTest, UnboxingConstWCharPointer) {
    ASSERT_TRUE(IsConstWCharPointer(Unbox(L"Forty two")));
  }
  
  TEST(UnboxTest, UnboxingConstChar16Pointer) {
    ASSERT_TRUE(IsConstChar16Pointer(Unbox(u"Forty two")));
  }
  
  TEST(UnboxTest, UnboxingConstChar32Pointer) {
    ASSERT_TRUE(IsConstChar32Pointer(Unbox(U"Forty two")));
  }
  
  TEST(UnboxTest, UnboxingTimeSpan) {
    ASSERT_TRUE(is<TimeSpan>(Unbox(12_h + 24_min + 32_s)));
  }
  
  TEST(UnboxTest, UnboxingAny) {
    ASSERT_TRUE(is<Int32>(Unbox(Any(42))));
  }
  
  TEST(UnboxTest, UnboxingMyStruct) {
    struct MyStruct {};
    ASSERT_TRUE(is<MyStruct>(Unbox(MyStruct())));
  }
}

