#include <Switch/Is.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  class LiteralOperatorConverterTest : public TestFixture {
  protected:
    void DoubleTo_byte() {
      Assert::IsTrue(IsByte(1.6_b), _caller);
      Assert::AreEqual(2, 1.6_b, _caller);
    }
    
    void UInt64To_byte() {
      Assert::IsTrue(IsByte(42_b), _caller);
      Assert::AreEqual(42, 42_b, _caller);
    }
    
    void StringTo_byte() {
      Assert::IsTrue(IsByte("42"_b), _caller);
      Assert::AreEqual(42, "42"_b, _caller);
    }
    
    void CharTo_char32() {
      Assert::IsTrue(IsChar32('A'_c), _caller);
      Assert::AreEqual(U'A', 'A'_c, _caller);
    }
    
    void Char16To_char32() {
      Assert::IsTrue(IsChar32(u'A'_c), _caller);
      Assert::AreEqual(U'A', u'A'_c, _caller);
    }
    
    void Char32To_char32() {
      Assert::IsTrue(IsChar32(U'A'_c), _caller);
      Assert::AreEqual(U'A', U'A'_c, _caller);
    }
    
    void WCharTo_char32() {
      Assert::IsTrue(IsChar32(L'A'_c), _caller);
      Assert::AreEqual(U'A', L'A'_c, _caller);
    }
    
    void UInt64To_char32() {
      Assert::IsTrue(IsChar32(65_c), _caller);
      Assert::AreEqual(U'A', 65_c, _caller);
    }
    
    void DoubleTo_double() {
      Assert::IsTrue(IsDouble(1.6_d), _caller);
      Assert::AreEqual(1.6, 1.6_d, _caller);
    }
    
    void UInt64To_double() {
      Assert::IsTrue(IsDouble(42_d), _caller);
      Assert::AreEqual(42.0, 42_d, _caller);
    }
    
    void StringTo_double() {
      Assert::IsTrue(IsDouble("1.6"_d), _caller);
      Assert::AreEqual(1.6, "1.6"_d, _caller);
    }
    
    void DoubleTo_int16() {
      Assert::IsTrue(IsInt16(1.6_s16), _caller);
      Assert::AreEqual(2, 1.6_s16, _caller);
    }
    
    void UInt64To_int16() {
      Assert::IsTrue(IsInt16(42_s16), _caller);
      Assert::AreEqual(42, 42_s16, _caller);
    }
    
    void StringTo_int16() {
      Assert::IsTrue(IsInt16("42"_s16), _caller);
      Assert::AreEqual(42, "42"_s16, _caller);
    }
    
    void DoubleTo_int32() {
      Assert::IsTrue(IsInt32(1.6_s32), _caller);
      Assert::AreEqual(2, 1.6_s32, _caller);
    }
    
    void UInt64To_int32() {
      Assert::IsTrue(IsInt32(42_s32), _caller);
      Assert::AreEqual(42, 42_s32, _caller);
    }
    
    void StringTo_int32() {
      Assert::IsTrue(IsInt32("42"_s32), _caller);
      Assert::AreEqual(42, "42"_s32, _caller);
    }
    
    void DoubleTo_int64() {
      Assert::IsTrue(IsInt64(1.6_s64), _caller);
      Assert::AreEqual(2, 1.6_s64, _caller);
    }
    
    void UInt64To_int64() {
      Assert::IsTrue(IsInt64(42_s64), _caller);
      Assert::AreEqual(42, 42_s64, _caller);
    }
    
    void StringTo_int64() {
      Assert::IsTrue(IsInt64("42"_s64), _caller);
      Assert::AreEqual(42, "42"_s64, _caller);
    }
    
    void DoubleTo_sbyte() {
      Assert::IsTrue(IsSByte(1.6_sb), _caller);
      Assert::AreEqual(2, 1.6_sb, _caller);
    }
    
    void UInt64To_sbyte() {
      Assert::IsTrue(IsSByte(42_sb), _caller);
      Assert::AreEqual(42, 42_sb, _caller);
    }
    
    void StringTo_sbyte() {
      Assert::IsTrue(IsSByte("42"_sb), _caller);
      Assert::AreEqual(42, "42"_sb, _caller);
    }
    
    void DoubleTo_single() {
      Assert::IsTrue(IsSingle(1.6_f), _caller);
      Assert::AreEqual(1.6f, 1.6_f, _caller);
    }
    
    void UInt64To_single() {
      Assert::IsTrue(IsSingle(42_f), _caller);
      Assert::AreEqual(42.0f, 42_f, _caller);
    }
    
    void StringTo_single() {
      Assert::IsTrue(IsSingle("1.6"_f), _caller);
      Assert::AreEqual(1.6f, "1.6"_f, _caller);
    }
    
    void DoubleTo_uint16() {
      Assert::IsTrue(IsUInt16(1.6_u16), _caller);
      Assert::AreEqual(2u, 1.6_u16, _caller);
    }
    
    void UInt64To_uint16() {
      Assert::IsTrue(IsUInt16(42_u16), _caller);
      Assert::AreEqual(42u, 42_u16, _caller);
    }
    
    void StringTo_uint16() {
      Assert::IsTrue(IsUInt16("42"_u16), _caller);
      Assert::AreEqual(42u, "42"_u16, _caller);
    }
    
    void DoubleTo_uint32() {
      Assert::IsTrue(IsUInt32(1.6_u32), _caller);
      Assert::AreEqual(2u, 1.6_u32, _caller);
    }
    
    void UInt64To_uint32() {
      Assert::IsTrue(IsUInt32(42_u32), _caller);
      Assert::AreEqual(42u, 42_u32, _caller);
    }
    
    void StringTo_uint32() {
      Assert::IsTrue(IsUInt32("42"_u32), _caller);
      Assert::AreEqual(42u, "42"_u32, _caller);
    }
    
    void DoubleTo_uint64() {
      Assert::IsTrue(IsUInt64(1.6_u64), _caller);
      Assert::AreEqual(2u, 1.6_u64, _caller);
    }
    
    void UInt64To_uint64() {
      Assert::IsTrue(IsUInt64(42_u64), _caller);
      Assert::AreEqual(42u, 42_u64, _caller);
    }
    
    void StringTo_uint64() {
      Assert::IsTrue(IsUInt64("42"_u64), _caller);
      Assert::AreEqual(42u, "42"_u64, _caller);
    }
    
    void DoubleToByte() {
      Assert::IsInstanceOfType<Byte>(1.6_B, _caller);
      Assert::AreEqual(2, 1.6_B, _caller);
    }
    
    void UInt64ToByte() {
      Assert::IsInstanceOfType<Byte>(42_B, _caller);
      Assert::AreEqual(42, 42_B, _caller);
    }
    
    void StringToByte() {
      Assert::IsInstanceOfType<Byte>("42"_B, _caller);
      Assert::AreEqual(42, "42"_B, _caller);
    }
    
    void CharToChar() {
      Assert::IsInstanceOfType<Char>('A'_C, _caller);
      Assert::AreEqual(U'A', 'A'_C, _caller);
    }
    
    void Char16ToChar() {
      Assert::IsInstanceOfType<Char>(u'A'_C, _caller);
      Assert::AreEqual(U'A', u'A'_C, _caller);
    }
    
    void Char32ToChar() {
      Assert::IsInstanceOfType<Char>(U'A'_C, _caller);
      Assert::AreEqual(U'A', U'A'_C, _caller);
    }
    
    void WCharToChar() {
      Assert::IsInstanceOfType<Char>(L'A'_C, _caller);
      Assert::AreEqual(U'A', L'A'_C, _caller);
    }
    
    void UInt64ToChar() {
      Assert::IsInstanceOfType<Char>(65_C, _caller);
      Assert::AreEqual(U'A', 65_C, _caller);
    }
    
    void DoubleToDouble() {
      Assert::IsInstanceOfType<Double>(1.6_D, _caller);
      Assert::AreEqual(1.6, 1.6_D, _caller);
    }
    
    void UInt64ToDouble() {
      Assert::IsInstanceOfType<Double>(42_D, _caller);
      Assert::AreEqual(42.0, 42_D, _caller);
    }
    
    void StringToDouble() {
      Assert::IsInstanceOfType<Double>("1.6"_D, _caller);
      Assert::AreEqual(1.6, "1.6"_D, _caller);
    }
    
    void CharPointerToString() {
      Assert::IsInstanceOfType<String>("Fourty Two"_s, _caller);
      Assert::AreEqual("Fourty Two", "Fourty Two"_s, _caller);
      Assert::IsInstanceOfType<String>("Fourty Two"_S, _caller);
      Assert::AreEqual("Fourty Two", "Fourty Two"_S, _caller);
    }
    
    void Char16PointerToString() {
      Assert::IsInstanceOfType<String>(u"Fourty Two"_s, _caller);
      Assert::AreEqual("Fourty Two", u"Fourty Two"_s, _caller);
      Assert::IsInstanceOfType<String>(u"Fourty Two"_S, _caller);
      Assert::AreEqual("Fourty Two", u"Fourty Two"_S, _caller);
    }
    
    void Char32PointerToString() {
      Assert::IsInstanceOfType<String>(U"Fourty Two"_s, _caller);
      Assert::AreEqual("Fourty Two", U"Fourty Two"_s, _caller);
      Assert::IsInstanceOfType<String>(U"Fourty Two"_S, _caller);
      Assert::AreEqual("Fourty Two", U"Fourty Two"_S, _caller);
    }
    
    void WCharPointerToString() {
      Assert::IsInstanceOfType<String>(L"Fourty Two"_s, _caller);
      Assert::AreEqual("Fourty Two", L"Fourty Two"_s, _caller);
      Assert::IsInstanceOfType<String>(L"Fourty Two"_S, _caller);
      Assert::AreEqual("Fourty Two", L"Fourty Two"_S, _caller);
    }
    
    void DoubleToInt16() {
      Assert::IsInstanceOfType<Int16>(1.6_S16, _caller);
      Assert::AreEqual(2, 1.6_S16, _caller);
    }
    
    void UInt64ToInt16() {
      Assert::IsInstanceOfType<Int16>(42_S16, _caller);
      Assert::AreEqual(42, 42_S16, _caller);
    }
    
    void StringToInt16() {
      Assert::IsInstanceOfType<Int16>("42"_S16, _caller);
      Assert::AreEqual(42, "42"_S16, _caller);
    }
    
    void DoubleToInt32() {
      Assert::IsInstanceOfType<Int32>(1.6_S32, _caller);
      Assert::AreEqual(2, 1.6_S32, _caller);
    }
    
    void UInt64ToInt32() {
      Assert::IsInstanceOfType<Int32>(42_S32, _caller);
      Assert::AreEqual(42, 42_S32, _caller);
    }
    
    void StringToInt32() {
      Assert::IsInstanceOfType<Int32>("42"_S32, _caller);
      Assert::AreEqual(42, "42"_S32, _caller);
    }
    
    void DoubleToInt64() {
      Assert::IsInstanceOfType<Int64>(1.6_S64, _caller);
      Assert::AreEqual(2, 1.6_S64, _caller);
    }
    
    void UInt64ToInt64() {
      Assert::IsInstanceOfType<Int64>(42_S64, _caller);
      Assert::AreEqual(42, 42_S64, _caller);
    }
    
    void StringToInt64() {
      Assert::IsInstanceOfType<Int64>("42"_S64, _caller);
      Assert::AreEqual(42, "42"_S64, _caller);
    }
    
    void DoubleToSByte() {
      Assert::IsInstanceOfType<SByte>(1.6_SB, _caller);
      Assert::AreEqual(2, 1.6_SB, _caller);
    }
    
    void UInt64ToSByte() {
      Assert::IsInstanceOfType<SByte>(42_SB, _caller);
      Assert::AreEqual(42, 42_SB, _caller);
    }
    
    void StringToSByte() {
      Assert::IsInstanceOfType<SByte>("42"_SB, _caller);
      Assert::AreEqual(42, "42"_SB, _caller);
    }
    
    void DoubleToSingle() {
      Assert::IsInstanceOfType<Single>(1.6_F, _caller);
      Assert::AreEqual(1.6f, 1.6_F, _caller);
    }
    
    void UInt64ToSingle() {
      Assert::IsInstanceOfType<Single>(42_F, _caller);
      Assert::AreEqual(42.0f, 42_F, _caller);
    }
    
    void StringToSingle() {
      Assert::IsInstanceOfType<Single>("1.6"_F, _caller);
      Assert::AreEqual(1.6f, "1.6"_F, _caller);
    }
    
    void DoubleToUInt16() {
      Assert::IsInstanceOfType<UInt16>(1.6_U16, _caller);
      Assert::AreEqual(2u, 1.6_U16, _caller);
    }
    
    void UInt64ToUInt16() {
      Assert::IsInstanceOfType<UInt16>(42_U16, _caller);
      Assert::AreEqual(42u, 42_U16, _caller);
    }
    
    void StringToUInt16() {
      Assert::IsInstanceOfType<UInt16>("42"_U16, _caller);
      Assert::AreEqual(42u, "42"_U16, _caller);
    }
    
    void DoubleToUInt32() {
      Assert::IsInstanceOfType<UInt32>(1.6_U32, _caller);
      Assert::AreEqual(2u, 1.6_U32, _caller);
    }
    
    void UInt64ToUInt32() {
      Assert::IsInstanceOfType<UInt32>(42_U32, _caller);
      Assert::AreEqual(42u, 42_U32, _caller);
    }
    
    void StringToUInt32() {
      Assert::IsInstanceOfType<UInt32>("42"_U32, _caller);
      Assert::AreEqual(42u, "42"_U32, _caller);
    }
    
    void DoubleToUInt64() {
      Assert::IsInstanceOfType<UInt64>(1.6_U64, _caller);
      Assert::AreEqual(2u, 1.6_U64, _caller);
    }
    
    void UInt64ToUInt64() {
      Assert::IsInstanceOfType<UInt64>(42_U64, _caller);
      Assert::AreEqual(42u, 42_U64, _caller);
    }
    
    void StringToUInt64() {
      Assert::IsInstanceOfType<UInt64>("42"_U64, _caller);
      Assert::AreEqual(42u, "42"_U64, _caller);
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
  
  _test(LiteralOperatorConverterTest, DoubleTo_byte)
  _test(LiteralOperatorConverterTest, UInt64To_byte)
  _test(LiteralOperatorConverterTest, StringTo_byte)
  _test(LiteralOperatorConverterTest, CharTo_char32)
  _test(LiteralOperatorConverterTest, Char16To_char32)
  _test(LiteralOperatorConverterTest, Char32To_char32)
  _test(LiteralOperatorConverterTest, WCharTo_char32)
  _test(LiteralOperatorConverterTest, UInt64To_char32)
  _test(LiteralOperatorConverterTest, DoubleTo_double)
  _test(LiteralOperatorConverterTest, UInt64To_double)
  _test(LiteralOperatorConverterTest, StringTo_double)
  _test(LiteralOperatorConverterTest, DoubleTo_int16)
  _test(LiteralOperatorConverterTest, UInt64To_int16)
  _test(LiteralOperatorConverterTest, StringTo_int16)
  _test(LiteralOperatorConverterTest, DoubleTo_int32)
  _test(LiteralOperatorConverterTest, UInt64To_int32)
  _test(LiteralOperatorConverterTest, StringTo_int32)
  _test(LiteralOperatorConverterTest, DoubleTo_int64)
  _test(LiteralOperatorConverterTest, UInt64To_int64)
  _test(LiteralOperatorConverterTest, StringTo_int64)
  _test(LiteralOperatorConverterTest, DoubleTo_sbyte)
  _test(LiteralOperatorConverterTest, UInt64To_sbyte)
  _test(LiteralOperatorConverterTest, StringTo_sbyte)
  _test(LiteralOperatorConverterTest, DoubleTo_single)
  _test(LiteralOperatorConverterTest, UInt64To_single)
  _test(LiteralOperatorConverterTest, StringTo_single)
  _test(LiteralOperatorConverterTest, DoubleTo_uint16)
  _test(LiteralOperatorConverterTest, UInt64To_uint16)
  _test(LiteralOperatorConverterTest, StringTo_uint16)
  _test(LiteralOperatorConverterTest, DoubleTo_uint32)
  _test(LiteralOperatorConverterTest, UInt64To_uint32)
  _test(LiteralOperatorConverterTest, StringTo_uint32)
  _test(LiteralOperatorConverterTest, DoubleTo_uint64)
  _test(LiteralOperatorConverterTest, UInt64To_uint64)
  _test(LiteralOperatorConverterTest, StringTo_uint64)
  _test(LiteralOperatorConverterTest, DoubleToByte)
  _test(LiteralOperatorConverterTest, UInt64ToByte)
  _test(LiteralOperatorConverterTest, StringToByte)
  _test(LiteralOperatorConverterTest, CharToChar)
  _test(LiteralOperatorConverterTest, Char16ToChar)
  _test(LiteralOperatorConverterTest, Char32ToChar)
  _test(LiteralOperatorConverterTest, WCharToChar)
  _test(LiteralOperatorConverterTest, UInt64ToChar)
  _test(LiteralOperatorConverterTest, DoubleToDouble)
  _test(LiteralOperatorConverterTest, UInt64ToDouble)
  _test(LiteralOperatorConverterTest, StringToDouble)
  _test(LiteralOperatorConverterTest, CharPointerToString)
  _test(LiteralOperatorConverterTest, Char16PointerToString)
  _test(LiteralOperatorConverterTest, Char32PointerToString)
  _test(LiteralOperatorConverterTest, WCharPointerToString)
  _test(LiteralOperatorConverterTest, DoubleToInt16)
  _test(LiteralOperatorConverterTest, UInt64ToInt16)
  _test(LiteralOperatorConverterTest, StringToInt16)
  _test(LiteralOperatorConverterTest, DoubleToInt32)
  _test(LiteralOperatorConverterTest, UInt64ToInt32)
  _test(LiteralOperatorConverterTest, StringToInt32)
  _test(LiteralOperatorConverterTest, DoubleToInt64)
  _test(LiteralOperatorConverterTest, UInt64ToInt64)
  _test(LiteralOperatorConverterTest, StringToInt64)
  _test(LiteralOperatorConverterTest, DoubleToSByte)
  _test(LiteralOperatorConverterTest, UInt64ToSByte)
  _test(LiteralOperatorConverterTest, StringToSByte)
  _test(LiteralOperatorConverterTest, DoubleToSingle)
  _test(LiteralOperatorConverterTest, UInt64ToSingle)
  _test(LiteralOperatorConverterTest, StringToSingle)
  _test(LiteralOperatorConverterTest, DoubleToUInt16)
  _test(LiteralOperatorConverterTest, UInt64ToUInt16)
  _test(LiteralOperatorConverterTest, StringToUInt16)
  _test(LiteralOperatorConverterTest, DoubleToUInt32)
  _test(LiteralOperatorConverterTest, UInt64ToUInt32)
  _test(LiteralOperatorConverterTest, StringToUInt32)
  _test(LiteralOperatorConverterTest, DoubleToUInt64)
  _test(LiteralOperatorConverterTest, UInt64ToUInt64)
  _test(LiteralOperatorConverterTest, StringToUInt64)
}
