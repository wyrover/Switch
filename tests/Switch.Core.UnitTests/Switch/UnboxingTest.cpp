#include <Switch/Boxing.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class UnboxTest : public TestFixture {
  protected:
    void UnboxingBoolean() {
      Assert::IsTrue(IsBool(Unbox(Boolean(true))), _caller);
    }
    
    void UnboxingByte() {
      Assert::IsTrue(IsByte(Unbox(Byte(42))), _caller);
    }
    
    void UnboxingChar() {
      Assert::IsTrue(IsChar32(Unbox(Char('c'))), _caller);
    }
    
    void UnboxingDouble() {
      Assert::IsTrue(IsDouble(Unbox(Double(42))), _caller);
    }
    
    void UnboxingInt16() {
      Assert::IsTrue(IsInt16(Unbox(Int16(42))), _caller);
    }
    
    void UnboxingInt32() {
      Assert::IsTrue(IsInt32(Unbox(Int32(42))), _caller);
    }
    
    void UnboxingInt64() {
      Assert::IsTrue(IsInt64(Unbox(Int64(42))), _caller);
    }
    
    void UnboxingIntPtr() {
      Assert::IsTrue(IsIntPtr(Unbox(IntPtr((intptr)42))), _caller);
    }
    
    void UnboxingSByte() {
      Assert::IsTrue(IsSByte(Unbox(SByte(42))), _caller);
    }
    
    void UnboxingSingle() {
      Assert::IsTrue(IsSingle(Unbox(Single(42))), _caller);
    }
    
    void UnboxingString() {
      Assert::IsTrue(IsConstCharPointer(Unbox(string("Forty two"))), _caller);
    }
    
    void UnboxingUInt16() {
      Assert::IsTrue(IsUInt16(Unbox(UInt16(42))), _caller);
    }
    
    void UnboxingUInt32() {
      Assert::IsTrue(IsUInt32(Unbox(UInt32(42))), _caller);
    }
    
    void UnboxingUInt64() {
      Assert::IsTrue(IsUInt64(Unbox(UInt64(42))), _caller);
    }
    
    void UnboxingUIntPtr() {
      Assert::IsTrue(IsUIntPtr(Unbox(UIntPtr((uintptr)42))), _caller);
    }
    
    void UnboxingConstCharPointer() {
      Assert::IsTrue(IsConstCharPointer(Unbox("Forty two")), _caller);
    }
    
    void UnboxingConstWCharPointer() {
      Assert::IsTrue(IsConstWCharPointer(Unbox(L"Forty two")), _caller);
    }
    
    void UnboxingConstChar16Pointer() {
      Assert::IsTrue(IsConstChar16Pointer(Unbox(u"Forty two")), _caller);
    }
    
    void UnboxingConstChar32Pointer() {
      Assert::IsTrue(IsConstChar32Pointer(Unbox(U"Forty two")), _caller);
    }
    
    void UnboxingTimeSpan() {
      Assert::IsTrue(is<TimeSpan>(Unbox(12_h + 24_min + 32_s)), _caller);
    }
    
    void UnboxingAny() {
      Assert::IsTrue(is<Int32>(Unbox(Any(42))), _caller);
    }
    
    void UnboxingMyStruct() {
      struct MyStruct {};
      Assert::IsTrue(is<MyStruct>(Unbox(MyStruct())), _caller);
    }

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
  };
  
  _add_test (UnboxTest, UnboxingBoolean)
  _add_test (UnboxTest, UnboxingByte)
  _add_test (UnboxTest, UnboxingChar)
  _add_test (UnboxTest, UnboxingDouble)
  _add_test (UnboxTest, UnboxingInt16)
  _add_test (UnboxTest, UnboxingInt32)
  _add_test (UnboxTest, UnboxingInt64)
  _add_test (UnboxTest, UnboxingIntPtr)
  _add_test (UnboxTest, UnboxingSByte)
  _add_test (UnboxTest, UnboxingSingle)
  _add_test (UnboxTest, UnboxingString)
  _add_test (UnboxTest, UnboxingUInt16)
  _add_test (UnboxTest, UnboxingUInt32)
  _add_test (UnboxTest, UnboxingUInt64)
  _add_test (UnboxTest, UnboxingUIntPtr)
  _add_test (UnboxTest, UnboxingConstCharPointer)
  _add_test (UnboxTest, UnboxingConstWCharPointer)
  _add_test (UnboxTest, UnboxingConstChar16Pointer)
  _add_test (UnboxTest, UnboxingConstChar32Pointer)
  _add_test (UnboxTest, UnboxingAny)
  _add_test (UnboxTest, UnboxingMyStruct)
}
