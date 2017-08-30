#include <Pcf/Boxing.hpp>
#include <Pcf/TUnit/Assert.hpp>
#include <Pcf/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class UnboxTest : public TestFixture {
  protected:
    void UnboxingBoolean() {
      Assert::IsTrue(IsBool(Unbox(Boolean(true))), pcf_current_information);
    }
    
    void UnboxingByte() {
      Assert::IsTrue(IsByte(Unbox(Byte(42))), pcf_current_information);
    }
    
    void UnboxingChar() {
      Assert::IsTrue(IsChar32(Unbox(Char('c'))), pcf_current_information);
    }
    
    void UnboxingDouble() {
      Assert::IsTrue(IsDouble(Unbox(Double(42))), pcf_current_information);
    }
    
    void UnboxingInt16() {
      Assert::IsTrue(IsInt16(Unbox(Int16(42))), pcf_current_information);
    }
    
    void UnboxingInt32() {
      Assert::IsTrue(IsInt32(Unbox(Int32(42))), pcf_current_information);
    }
    
    void UnboxingInt64() {
      Assert::IsTrue(IsInt64(Unbox(Int64(42))), pcf_current_information);
    }
    
    void UnboxingIntPtr() {
      Assert::IsTrue(IsIntPtr(Unbox(IntPtr((intptr)42))), pcf_current_information);
    }
    
    void UnboxingSByte() {
      Assert::IsTrue(IsSByte(Unbox(SByte(42))), pcf_current_information);
    }
    
    void UnboxingSingle() {
      Assert::IsTrue(IsSingle(Unbox(Single(42))), pcf_current_information);
    }
    
    void UnboxingString() {
      Assert::IsTrue(IsConstCharPointer(Unbox(string("Forty two"))), pcf_current_information);
    }
    
    void UnboxingUInt16() {
      Assert::IsTrue(IsUInt16(Unbox(UInt16(42))), pcf_current_information);
    }
    
    void UnboxingUInt32() {
      Assert::IsTrue(IsUInt32(Unbox(UInt32(42))), pcf_current_information);
    }
    
    void UnboxingUInt64() {
      Assert::IsTrue(IsUInt64(Unbox(UInt64(42))), pcf_current_information);
    }
    
    void UnboxingUIntPtr() {
      Assert::IsTrue(IsUIntPtr(Unbox(UIntPtr((uintptr)42))), pcf_current_information);
    }
    
    void UnboxingConstCharPointer() {
      Assert::IsTrue(IsConstCharPointer(Unbox("Forty two")), pcf_current_information);
    }
    
    void UnboxingConstWCharPointer() {
      Assert::IsTrue(IsConstWCharPointer(Unbox(L"Forty two")), pcf_current_information);
    }
    
    void UnboxingConstChar16Pointer() {
      Assert::IsTrue(IsConstChar16Pointer(Unbox(u"Forty two")), pcf_current_information);
    }
    
    void UnboxingConstChar32Pointer() {
      Assert::IsTrue(IsConstChar32Pointer(Unbox(U"Forty two")), pcf_current_information);
    }
    
    void UnboxingTimeSpan() {
      Assert::IsTrue(is<TimeSpan>(Unbox(12_h + 24_min + 32_s)), pcf_current_information);
    }
    
    void UnboxingAny() {
      Assert::IsTrue(is<Int32>(Unbox(Any(42))), pcf_current_information);
    }
    
    void UnboxingMyStruct() {
      struct MyStruct {};
      Assert::IsTrue(is<MyStruct>(Unbox(MyStruct())), pcf_current_information);
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
  
  pcf_test(UnboxTest, UnboxingBoolean)
  pcf_test(UnboxTest, UnboxingByte)
  pcf_test(UnboxTest, UnboxingChar)
  pcf_test(UnboxTest, UnboxingDouble)
  pcf_test(UnboxTest, UnboxingInt16)
  pcf_test(UnboxTest, UnboxingInt32)
  pcf_test(UnboxTest, UnboxingInt64)
  pcf_test(UnboxTest, UnboxingIntPtr)
  pcf_test(UnboxTest, UnboxingSByte)
  pcf_test(UnboxTest, UnboxingSingle)
  pcf_test(UnboxTest, UnboxingString)
  pcf_test(UnboxTest, UnboxingUInt16)
  pcf_test(UnboxTest, UnboxingUInt32)
  pcf_test(UnboxTest, UnboxingUInt64)
  pcf_test(UnboxTest, UnboxingUIntPtr)
  pcf_test(UnboxTest, UnboxingConstCharPointer)
  pcf_test(UnboxTest, UnboxingConstWCharPointer)
  pcf_test(UnboxTest, UnboxingConstChar16Pointer)
  pcf_test(UnboxTest, UnboxingConstChar32Pointer)
  pcf_test(UnboxTest, UnboxingAny)
  pcf_test(UnboxTest, UnboxingMyStruct)
}
