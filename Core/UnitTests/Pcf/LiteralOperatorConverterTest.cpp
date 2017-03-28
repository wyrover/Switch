#include <Pcf/Is.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {
  class LiteralOperatorConverterTest : public TestFixture {
  protected:
    void DoubleTo_byte() {
      Assert::IsTrue(IsByte(1.6_b), pcf_current_information);
      Assert::AreEqual(2, 1.6_b, pcf_current_information);
    }
    
    void UInt64To_byte() {
      Assert::IsTrue(IsByte(42_b), pcf_current_information);
      Assert::AreEqual(42, 42_b, pcf_current_information);
    }
    
    void StringTo_byte() {
      Assert::IsTrue(IsByte("42"_b), pcf_current_information);
      Assert::AreEqual(42, "42"_b, pcf_current_information);
    }
    
    void CharTo_char32() {
      Assert::IsTrue(IsChar32('A'_c), pcf_current_information);
      Assert::AreEqual(U'A', 'A'_c, pcf_current_information);
    }
    
    void Char16To_char32() {
      Assert::IsTrue(IsChar32(u'A'_c), pcf_current_information);
      Assert::AreEqual(U'A', u'A'_c, pcf_current_information);
    }
    
    void Char32To_char32() {
      Assert::IsTrue(IsChar32(U'A'_c), pcf_current_information);
      Assert::AreEqual(U'A', U'A'_c, pcf_current_information);
    }
    
    void WCharTo_char32() {
      Assert::IsTrue(IsChar32(L'A'_c), pcf_current_information);
      Assert::AreEqual(U'A', L'A'_c, pcf_current_information);
    }
    
    void UInt64To_char32() {
      Assert::IsTrue(IsChar32(65_c), pcf_current_information);
      Assert::AreEqual(U'A', 65_c, pcf_current_information);
    }
    
    void DoubleTo_double() {
      Assert::IsTrue(IsDouble(1.6_d), pcf_current_information);
      Assert::AreEqual(1.6, 1.6_d, pcf_current_information);
    }
    
    void UInt64To_double() {
      Assert::IsTrue(IsDouble(42_d), pcf_current_information);
      Assert::AreEqual(42.0, 42_d, pcf_current_information);
    }
    
    void StringTo_double() {
      Assert::IsTrue(IsDouble("1.6"_d), pcf_current_information);
      Assert::AreEqual(1.6, "1.6"_d, pcf_current_information);
    }
    
    void DoubleTo_int16() {
      Assert::IsTrue(IsInt16(1.6_s16), pcf_current_information);
      Assert::AreEqual(2, 1.6_s16, pcf_current_information);
    }
    
    void UInt64To_int16() {
      Assert::IsTrue(IsInt16(42_s16), pcf_current_information);
      Assert::AreEqual(42, 42_s16, pcf_current_information);
    }
    
    void StringTo_int16() {
      Assert::IsTrue(IsInt16("42"_s16), pcf_current_information);
      Assert::AreEqual(42, "42"_s16, pcf_current_information);
    }
    
    void DoubleTo_int32() {
      Assert::IsTrue(IsInt32(1.6_s32), pcf_current_information);
      Assert::AreEqual(2, 1.6_s32, pcf_current_information);
    }
    
    void UInt64To_int32() {
      Assert::IsTrue(IsInt32(42_s32), pcf_current_information);
      Assert::AreEqual(42, 42_s32, pcf_current_information);
    }
    
    void StringTo_int32() {
      Assert::IsTrue(IsInt32("42"_s32), pcf_current_information);
      Assert::AreEqual(42, "42"_s32, pcf_current_information);
    }
    
    void DoubleTo_int64() {
      Assert::IsTrue(IsInt64(1.6_s64), pcf_current_information);
      Assert::AreEqual(2, 1.6_s64, pcf_current_information);
    }
    
    void UInt64To_int64() {
      Assert::IsTrue(IsInt64(42_s64), pcf_current_information);
      Assert::AreEqual(42, 42_s64, pcf_current_information);
    }
    
    void StringTo_int64() {
      Assert::IsTrue(IsInt64("42"_s64), pcf_current_information);
      Assert::AreEqual(42, "42"_s64, pcf_current_information);
    }
    
    void DoubleTo_sbyte() {
      Assert::IsTrue(IsSByte(1.6_sb), pcf_current_information);
      Assert::AreEqual(2, 1.6_sb, pcf_current_information);
    }
    
    void UInt64To_sbyte() {
      Assert::IsTrue(IsSByte(42_sb), pcf_current_information);
      Assert::AreEqual(42, 42_sb, pcf_current_information);
    }
    
    void StringTo_sbyte() {
      Assert::IsTrue(IsSByte("42"_sb), pcf_current_information);
      Assert::AreEqual(42, "42"_sb, pcf_current_information);
    }
    
    void DoubleTo_single() {
      Assert::IsTrue(IsSingle(1.6_f), pcf_current_information);
      Assert::AreEqual(1.6f, 1.6_f, pcf_current_information);
    }
    
    void UInt64To_single() {
      Assert::IsTrue(IsSingle(42_f), pcf_current_information);
      Assert::AreEqual(42.0f, 42_f, pcf_current_information);
    }
    
    void StringTo_single() {
      Assert::IsTrue(IsSingle("1.6"_f), pcf_current_information);
      Assert::AreEqual(1.6f, "1.6"_f, pcf_current_information);
    }
    
    void DoubleTo_uint16() {
      Assert::IsTrue(IsUInt16(1.6_u16), pcf_current_information);
      Assert::AreEqual(2u, 1.6_u16, pcf_current_information);
    }
    
    void UInt64To_uint16() {
      Assert::IsTrue(IsUInt16(42_u16), pcf_current_information);
      Assert::AreEqual(42u, 42_u16, pcf_current_information);
    }
    
    void StringTo_uint16() {
      Assert::IsTrue(IsUInt16("42"_u16), pcf_current_information);
      Assert::AreEqual(42u, "42"_u16, pcf_current_information);
    }
    
    void DoubleTo_uint32() {
      Assert::IsTrue(IsUInt32(1.6_u32), pcf_current_information);
      Assert::AreEqual(2u, 1.6_u32, pcf_current_information);
    }
    
    void UInt64To_uint32() {
      Assert::IsTrue(IsUInt32(42_u32), pcf_current_information);
      Assert::AreEqual(42u, 42_u32, pcf_current_information);
    }
    
    void StringTo_uint32() {
      Assert::IsTrue(IsUInt32("42"_u32), pcf_current_information);
      Assert::AreEqual(42u, "42"_u32, pcf_current_information);
    }
    
    void DoubleTo_uint64() {
      Assert::IsTrue(IsUInt64(1.6_u64), pcf_current_information);
      Assert::AreEqual(2u, 1.6_u64, pcf_current_information);
    }
    
    void UInt64To_uint64() {
      Assert::IsTrue(IsUInt64(42_u64), pcf_current_information);
      Assert::AreEqual(42u, 42_u64, pcf_current_information);
    }
    
    void StringTo_uint64() {
      Assert::IsTrue(IsUInt64("42"_u64), pcf_current_information);
      Assert::AreEqual(42u, "42"_u64, pcf_current_information);
    }
    
    void DoubleToByte() {
      Assert::IsInstanceOfType<Byte>(1.6_B, pcf_current_information);
      Assert::AreEqual(2, 1.6_B, pcf_current_information);
    }
    
    void UInt64ToByte() {
      Assert::IsInstanceOfType<Byte>(42_B, pcf_current_information);
      Assert::AreEqual(42, 42_B, pcf_current_information);
    }
    
    void StringToByte() {
      Assert::IsInstanceOfType<Byte>("42"_B, pcf_current_information);
      Assert::AreEqual(42, "42"_B, pcf_current_information);
    }
    
    void CharToChar() {
      Assert::IsInstanceOfType<Char>('A'_C, pcf_current_information);
      Assert::AreEqual(U'A', 'A'_C, pcf_current_information);
    }
    
    void Char16ToChar() {
      Assert::IsInstanceOfType<Char>(u'A'_C, pcf_current_information);
      Assert::AreEqual(U'A', u'A'_C, pcf_current_information);
    }
    
    void Char32ToChar() {
      Assert::IsInstanceOfType<Char>(U'A'_C, pcf_current_information);
      Assert::AreEqual(U'A', U'A'_C, pcf_current_information);
    }
    
    void WCharToChar() {
      Assert::IsInstanceOfType<Char>(L'A'_C, pcf_current_information);
      Assert::AreEqual(U'A', L'A'_C, pcf_current_information);
    }
    
    void UInt64ToChar() {
      Assert::IsInstanceOfType<Char>(65_C, pcf_current_information);
      Assert::AreEqual(U'A', 65_C, pcf_current_information);
    }
    
    void DoubleToDouble() {
      Assert::IsInstanceOfType<Double>(1.6_D, pcf_current_information);
      Assert::AreEqual(1.6, 1.6_D, pcf_current_information);
    }
    
    void UInt64ToDouble() {
      Assert::IsInstanceOfType<Double>(42_D, pcf_current_information);
      Assert::AreEqual(42.0, 42_D, pcf_current_information);
    }
    
    void StringToDouble() {
      Assert::IsInstanceOfType<Double>("1.6"_D, pcf_current_information);
      Assert::AreEqual(1.6, "1.6"_D, pcf_current_information);
    }
    
    void CharPointerToString() {
      Assert::IsInstanceOfType<String>("Fourty Two"_s, pcf_current_information);
      Assert::AreEqual("Fourty Two", "Fourty Two"_s, pcf_current_information);
      Assert::IsInstanceOfType<String>("Fourty Two"_S, pcf_current_information);
      Assert::AreEqual("Fourty Two", "Fourty Two"_S, pcf_current_information);
    }
    
    void Char16PointerToString() {
      Assert::IsInstanceOfType<String>(u"Fourty Two"_s, pcf_current_information);
      Assert::AreEqual("Fourty Two", u"Fourty Two"_s, pcf_current_information);
      Assert::IsInstanceOfType<String>(u"Fourty Two"_S, pcf_current_information);
      Assert::AreEqual("Fourty Two", u"Fourty Two"_S, pcf_current_information);
    }
    
    void Char32PointerToString() {
      Assert::IsInstanceOfType<String>(U"Fourty Two"_s, pcf_current_information);
      Assert::AreEqual("Fourty Two", U"Fourty Two"_s, pcf_current_information);
      Assert::IsInstanceOfType<String>(U"Fourty Two"_S, pcf_current_information);
      Assert::AreEqual("Fourty Two", U"Fourty Two"_S, pcf_current_information);
    }
    
    void WCharPointerToString() {
      Assert::IsInstanceOfType<String>(L"Fourty Two"_s, pcf_current_information);
      Assert::AreEqual("Fourty Two", L"Fourty Two"_s, pcf_current_information);
      Assert::IsInstanceOfType<String>(L"Fourty Two"_S, pcf_current_information);
      Assert::AreEqual("Fourty Two", L"Fourty Two"_S, pcf_current_information);
    }
    
    void DoubleToInt16() {
      Assert::IsInstanceOfType<Int16>(1.6_S16, pcf_current_information);
      Assert::AreEqual(2, 1.6_S16, pcf_current_information);
    }
    
    void UInt64ToInt16() {
      Assert::IsInstanceOfType<Int16>(42_S16, pcf_current_information);
      Assert::AreEqual(42, 42_S16, pcf_current_information);
    }
    
    void StringToInt16() {
      Assert::IsInstanceOfType<Int16>("42"_S16, pcf_current_information);
      Assert::AreEqual(42, "42"_S16, pcf_current_information);
    }
    
    void DoubleToInt32() {
      Assert::IsInstanceOfType<Int32>(1.6_S32, pcf_current_information);
      Assert::AreEqual(2, 1.6_S32, pcf_current_information);
    }
    
    void UInt64ToInt32() {
      Assert::IsInstanceOfType<Int32>(42_S32, pcf_current_information);
      Assert::AreEqual(42, 42_S32, pcf_current_information);
    }
    
    void StringToInt32() {
      Assert::IsInstanceOfType<Int32>("42"_S32, pcf_current_information);
      Assert::AreEqual(42, "42"_S32, pcf_current_information);
    }
    
    void DoubleToInt64() {
      Assert::IsInstanceOfType<Int64>(1.6_S64, pcf_current_information);
      Assert::AreEqual(2, 1.6_S64, pcf_current_information);
    }
    
    void UInt64ToInt64() {
      Assert::IsInstanceOfType<Int64>(42_S64, pcf_current_information);
      Assert::AreEqual(42, 42_S64, pcf_current_information);
    }
    
    void StringToInt64() {
      Assert::IsInstanceOfType<Int64>("42"_S64, pcf_current_information);
      Assert::AreEqual(42, "42"_S64, pcf_current_information);
    }
    
    void DoubleToSByte() {
      Assert::IsInstanceOfType<SByte>(1.6_SB, pcf_current_information);
      Assert::AreEqual(2, 1.6_SB, pcf_current_information);
    }
    
    void UInt64ToSByte() {
      Assert::IsInstanceOfType<SByte>(42_SB, pcf_current_information);
      Assert::AreEqual(42, 42_SB, pcf_current_information);
    }
    
    void StringToSByte() {
      Assert::IsInstanceOfType<SByte>("42"_SB, pcf_current_information);
      Assert::AreEqual(42, "42"_SB, pcf_current_information);
    }
    
    void DoubleToSingle() {
      Assert::IsInstanceOfType<Single>(1.6_F, pcf_current_information);
      Assert::AreEqual(1.6f, 1.6_F, pcf_current_information);
    }
    
    void UInt64ToSingle() {
      Assert::IsInstanceOfType<Single>(42_F, pcf_current_information);
      Assert::AreEqual(42.0f, 42_F, pcf_current_information);
    }
    
    void StringToSingle() {
      Assert::IsInstanceOfType<Single>("1.6"_F, pcf_current_information);
      Assert::AreEqual(1.6f, "1.6"_F, pcf_current_information);
    }
    
    void DoubleToUInt16() {
      Assert::IsInstanceOfType<UInt16>(1.6_U16, pcf_current_information);
      Assert::AreEqual(2u, 1.6_U16, pcf_current_information);
    }
    
    void UInt64ToUInt16() {
      Assert::IsInstanceOfType<UInt16>(42_U16, pcf_current_information);
      Assert::AreEqual(42u, 42_U16, pcf_current_information);
    }
    
    void StringToUInt16() {
      Assert::IsInstanceOfType<UInt16>("42"_U16, pcf_current_information);
      Assert::AreEqual(42u, "42"_U16, pcf_current_information);
    }
    
    void DoubleToUInt32() {
      Assert::IsInstanceOfType<UInt32>(1.6_U32, pcf_current_information);
      Assert::AreEqual(2u, 1.6_U32, pcf_current_information);
    }
    
    void UInt64ToUInt32() {
      Assert::IsInstanceOfType<UInt32>(42_U32, pcf_current_information);
      Assert::AreEqual(42u, 42_U32, pcf_current_information);
    }
    
    void StringToUInt32() {
      Assert::IsInstanceOfType<UInt32>("42"_U32, pcf_current_information);
      Assert::AreEqual(42u, "42"_U32, pcf_current_information);
    }
    
    void DoubleToUInt64() {
      Assert::IsInstanceOfType<UInt64>(1.6_U64, pcf_current_information);
      Assert::AreEqual(2u, 1.6_U64, pcf_current_information);
    }
    
    void UInt64ToUInt64() {
      Assert::IsInstanceOfType<UInt64>(42_U64, pcf_current_information);
      Assert::AreEqual(42u, 42_U64, pcf_current_information);
    }
    
    void StringToUInt64() {
      Assert::IsInstanceOfType<UInt64>("42"_U64, pcf_current_information);
      Assert::AreEqual(42u, "42"_U64, pcf_current_information);
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
  
  pcf_test(LiteralOperatorConverterTest, DoubleTo_byte)
  pcf_test(LiteralOperatorConverterTest, UInt64To_byte)
  pcf_test(LiteralOperatorConverterTest, StringTo_byte)
  pcf_test(LiteralOperatorConverterTest, CharTo_char32)
  pcf_test(LiteralOperatorConverterTest, Char16To_char32)
  pcf_test(LiteralOperatorConverterTest, Char32To_char32)
  pcf_test(LiteralOperatorConverterTest, WCharTo_char32)
  pcf_test(LiteralOperatorConverterTest, UInt64To_char32)
  pcf_test(LiteralOperatorConverterTest, DoubleTo_double)
  pcf_test(LiteralOperatorConverterTest, UInt64To_double)
  pcf_test(LiteralOperatorConverterTest, StringTo_double)
  pcf_test(LiteralOperatorConverterTest, DoubleTo_int16)
  pcf_test(LiteralOperatorConverterTest, UInt64To_int16)
  pcf_test(LiteralOperatorConverterTest, StringTo_int16)
  pcf_test(LiteralOperatorConverterTest, DoubleTo_int32)
  pcf_test(LiteralOperatorConverterTest, UInt64To_int32)
  pcf_test(LiteralOperatorConverterTest, StringTo_int32)
  pcf_test(LiteralOperatorConverterTest, DoubleTo_int64)
  pcf_test(LiteralOperatorConverterTest, UInt64To_int64)
  pcf_test(LiteralOperatorConverterTest, StringTo_int64)
  pcf_test(LiteralOperatorConverterTest, DoubleTo_sbyte)
  pcf_test(LiteralOperatorConverterTest, UInt64To_sbyte)
  pcf_test(LiteralOperatorConverterTest, StringTo_sbyte)
  pcf_test(LiteralOperatorConverterTest, DoubleTo_single)
  pcf_test(LiteralOperatorConverterTest, UInt64To_single)
  pcf_test(LiteralOperatorConverterTest, StringTo_single)
  pcf_test(LiteralOperatorConverterTest, DoubleTo_uint16)
  pcf_test(LiteralOperatorConverterTest, UInt64To_uint16)
  pcf_test(LiteralOperatorConverterTest, StringTo_uint16)
  pcf_test(LiteralOperatorConverterTest, DoubleTo_uint32)
  pcf_test(LiteralOperatorConverterTest, UInt64To_uint32)
  pcf_test(LiteralOperatorConverterTest, StringTo_uint32)
  pcf_test(LiteralOperatorConverterTest, DoubleTo_uint64)
  pcf_test(LiteralOperatorConverterTest, UInt64To_uint64)
  pcf_test(LiteralOperatorConverterTest, StringTo_uint64)
  pcf_test(LiteralOperatorConverterTest, DoubleToByte)
  pcf_test(LiteralOperatorConverterTest, UInt64ToByte)
  pcf_test(LiteralOperatorConverterTest, StringToByte)
  pcf_test(LiteralOperatorConverterTest, CharToChar)
  pcf_test(LiteralOperatorConverterTest, Char16ToChar)
  pcf_test(LiteralOperatorConverterTest, Char32ToChar)
  pcf_test(LiteralOperatorConverterTest, WCharToChar)
  pcf_test(LiteralOperatorConverterTest, UInt64ToChar)
  pcf_test(LiteralOperatorConverterTest, DoubleToDouble)
  pcf_test(LiteralOperatorConverterTest, UInt64ToDouble)
  pcf_test(LiteralOperatorConverterTest, StringToDouble)
  pcf_test(LiteralOperatorConverterTest, CharPointerToString)
  pcf_test(LiteralOperatorConverterTest, Char16PointerToString)
  pcf_test(LiteralOperatorConverterTest, Char32PointerToString)
  pcf_test(LiteralOperatorConverterTest, WCharPointerToString)
  pcf_test(LiteralOperatorConverterTest, DoubleToInt16)
  pcf_test(LiteralOperatorConverterTest, UInt64ToInt16)
  pcf_test(LiteralOperatorConverterTest, StringToInt16)
  pcf_test(LiteralOperatorConverterTest, DoubleToInt32)
  pcf_test(LiteralOperatorConverterTest, UInt64ToInt32)
  pcf_test(LiteralOperatorConverterTest, StringToInt32)
  pcf_test(LiteralOperatorConverterTest, DoubleToInt64)
  pcf_test(LiteralOperatorConverterTest, UInt64ToInt64)
  pcf_test(LiteralOperatorConverterTest, StringToInt64)
  pcf_test(LiteralOperatorConverterTest, DoubleToSByte)
  pcf_test(LiteralOperatorConverterTest, UInt64ToSByte)
  pcf_test(LiteralOperatorConverterTest, StringToSByte)
  pcf_test(LiteralOperatorConverterTest, DoubleToSingle)
  pcf_test(LiteralOperatorConverterTest, UInt64ToSingle)
  pcf_test(LiteralOperatorConverterTest, StringToSingle)
  pcf_test(LiteralOperatorConverterTest, DoubleToUInt16)
  pcf_test(LiteralOperatorConverterTest, UInt64ToUInt16)
  pcf_test(LiteralOperatorConverterTest, StringToUInt16)
  pcf_test(LiteralOperatorConverterTest, DoubleToUInt32)
  pcf_test(LiteralOperatorConverterTest, UInt64ToUInt32)
  pcf_test(LiteralOperatorConverterTest, StringToUInt32)
  pcf_test(LiteralOperatorConverterTest, DoubleToUInt64)
  pcf_test(LiteralOperatorConverterTest, UInt64ToUInt64)
  pcf_test(LiteralOperatorConverterTest, StringToUInt64)
}
