#include <Switch/Is.hpp>
#include <Switch/System/Convert.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  template<typename T> bool IsBool(T) {return false;}
  bool IsByte(byte) {return true;}
  template<typename T> bool IsByte(T) {return false;}
  template<typename T> bool IsChar(T) {return false;}
  template<typename T> bool IsWChar(T) {return false;}
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
  template<typename T> bool IsIntPtr(T) {return false;}
  bool IsSByte(sbyte) {return true;}
  template<typename T> bool IsSByte(T) {return false;}
  bool IsSingle(float) {return true;}
  template<typename T> bool IsSingle(T) {return false;}
  template<typename T> bool IsConstCharPointer(T) {return false;}
  template<typename T> bool IsConstWCharPointer(T) {return false;}
  template<typename T> bool IsConstChar16Pointer(T) {return false;}
  template<typename T> bool IsConstChar32Pointer(T) {return false;}
  bool IsUInt16(uint16) {return true;}
  template<typename T> bool IsUInt16(T) {return false;}
  bool IsUInt32(uint32) {return true;}
  template<typename T> bool IsUInt32(T) {return false;}
  bool IsUInt64(uint64) {return true;}
  template<typename T> bool IsUInt64(T) {return false;}
  template<typename T> bool IsUIntPtr(T) {return false;}
  template<typename T> bool IsVoidPointer(T) {return false;}
  
  TEST(LiteralOperatorConverterTest, DoubleTo_byte) {
    ASSERT_TRUE(IsByte(1.6_b));
    ASSERT_EQ(2, 1.6_b);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64To_byte) {
    ASSERT_TRUE(IsByte(42_b));
    ASSERT_EQ(42, 42_b);
  }
  
  TEST(LiteralOperatorConverterTest, StringTo_byte) {
    ASSERT_TRUE(IsByte("42"_b));
    ASSERT_EQ(42, "42"_b);
  }
  
  TEST(LiteralOperatorConverterTest, CharTo_char32) {
    ASSERT_TRUE(IsChar32('A'_c));
    ASSERT_EQ(U'A', 'A'_c);
  }
  
  TEST(LiteralOperatorConverterTest, Char16To_char32) {
    ASSERT_TRUE(IsChar32(u'A'_c));
    ASSERT_EQ(U'A', u'A'_c);
  }
  
  TEST(LiteralOperatorConverterTest, Char32To_char32) {
    ASSERT_TRUE(IsChar32(U'A'_c));
    ASSERT_EQ(U'A', U'A'_c);
  }
  
  TEST(LiteralOperatorConverterTest, WCharTo_char32) {
    ASSERT_TRUE(IsChar32(L'A'_c));
    ASSERT_EQ(U'A', L'A'_c);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64To_char32) {
    ASSERT_TRUE(IsChar32(65_c));
    ASSERT_EQ(U'A', 65_c);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleTo_double) {
    ASSERT_TRUE(IsDouble(1.6_d));
    ASSERT_EQ(1.6, 1.6_d);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64To_double) {
    ASSERT_TRUE(IsDouble(42_d));
    ASSERT_EQ(42.0, 42_d);
  }
  
  TEST(LiteralOperatorConverterTest, StringTo_double) {
    ASSERT_TRUE(IsDouble("1.6"_d));
    ASSERT_EQ(1.6, "1.6"_d);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleTo_int16) {
    ASSERT_TRUE(IsInt16(1.6_s16));
    ASSERT_EQ(2, 1.6_s16);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64To_int16) {
    ASSERT_TRUE(IsInt16(42_s16));
    ASSERT_EQ(42, 42_s16);
  }
  
  TEST(LiteralOperatorConverterTest, StringTo_int16) {
    ASSERT_TRUE(IsInt16("42"_s16));
    ASSERT_EQ(42, "42"_s16);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleTo_int32) {
    ASSERT_TRUE(IsInt32(1.6_s32));
    ASSERT_EQ(2, 1.6_s32);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64To_int32) {
    ASSERT_TRUE(IsInt32(42_s32));
    ASSERT_EQ(42, 42_s32);
  }
  
  TEST(LiteralOperatorConverterTest, StringTo_int32) {
    ASSERT_TRUE(IsInt32("42"_s32));
    ASSERT_EQ(42, "42"_s32);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleTo_int64) {
    ASSERT_TRUE(IsInt64(1.6_s64));
    ASSERT_EQ(2, 1.6_s64);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64To_int64) {
    ASSERT_TRUE(IsInt64(42_s64));
    ASSERT_EQ(42, 42_s64);
  }
  
  TEST(LiteralOperatorConverterTest, StringTo_int64) {
    ASSERT_TRUE(IsInt64("42"_s64));
    ASSERT_EQ(42, "42"_s64);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleTo_sbyte) {
    ASSERT_TRUE(IsSByte(1.6_sb));
    ASSERT_EQ(2, 1.6_sb);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64To_sbyte) {
    ASSERT_TRUE(IsSByte(42_sb));
    ASSERT_EQ(42, 42_sb);
  }
  
  TEST(LiteralOperatorConverterTest, StringTo_sbyte) {
    ASSERT_TRUE(IsSByte("42"_sb));
    ASSERT_EQ(42, "42"_sb);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleTo_single) {
    ASSERT_TRUE(IsSingle(1.6_f));
    ASSERT_EQ(1.6f, 1.6_f);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64To_single) {
    ASSERT_TRUE(IsSingle(42_f));
    ASSERT_EQ(42.0f, 42_f);
  }
  
  TEST(LiteralOperatorConverterTest, StringTo_single) {
    ASSERT_TRUE(IsSingle("1.6"_f));
    ASSERT_EQ(1.6f, "1.6"_f);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleTo_uint16) {
    ASSERT_TRUE(IsUInt16(1.6_u16));
    ASSERT_EQ(2u, 1.6_u16);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64To_uint16) {
    ASSERT_TRUE(IsUInt16(42_u16));
    ASSERT_EQ(42u, 42_u16);
  }
  
  TEST(LiteralOperatorConverterTest, StringTo_uint16) {
    ASSERT_TRUE(IsUInt16("42"_u16));
    ASSERT_EQ(42u, "42"_u16);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleTo_uint32) {
    ASSERT_TRUE(IsUInt32(1.6_u32));
    ASSERT_EQ(2u, 1.6_u32);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64To_uint32) {
    ASSERT_TRUE(IsUInt32(42_u32));
    ASSERT_EQ(42u, 42_u32);
  }
  
  TEST(LiteralOperatorConverterTest, StringTo_uint32) {
    ASSERT_TRUE(IsUInt32("42"_u32));
    ASSERT_EQ(42u, "42"_u32);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleTo_uint64) {
    ASSERT_TRUE(IsUInt64(1.6_u64));
    ASSERT_EQ(2u, 1.6_u64);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64To_uint64) {
    ASSERT_TRUE(IsUInt64(42_u64));
    ASSERT_EQ(42u, 42_u64);
  }
  
  TEST(LiteralOperatorConverterTest, StringTo_uint64) {
    ASSERT_TRUE(IsUInt64("42"_u64));
    ASSERT_EQ(42u, "42"_u64);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleToByte) {
    ASSERT_TRUE(is<Byte>(1.6_B));
    ASSERT_EQ(2, 1.6_B);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64ToByte) {
    ASSERT_TRUE(is<Byte>(42_B));
    ASSERT_EQ(42, 42_B);
  }
  
  TEST(LiteralOperatorConverterTest, StringToByte) {
    ASSERT_TRUE(is<Byte>("42"_B));
    ASSERT_EQ(42, "42"_B);
  }
  
  TEST(LiteralOperatorConverterTest, CharToChar) {
    ASSERT_TRUE(is<Char>('A'_C));
    ASSERT_EQ(U'A', 'A'_C);
  }
  
  TEST(LiteralOperatorConverterTest, Char16ToChar) {
    ASSERT_TRUE(is<Char>(u'A'_C));
    ASSERT_EQ(U'A', u'A'_C);
  }
  
  TEST(LiteralOperatorConverterTest, Char32ToChar) {
    ASSERT_TRUE(is<Char>(U'A'_C));
    ASSERT_EQ(U'A', U'A'_C);
  }
  
  TEST(LiteralOperatorConverterTest, WCharToChar) {
    ASSERT_TRUE(is<Char>(L'A'_C));
    ASSERT_EQ(U'A', L'A'_C);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64ToChar) {
    ASSERT_TRUE(is<Char>(65_C));
    ASSERT_EQ(U'A', 65_C);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleToDouble) {
    ASSERT_TRUE(is<Double>(1.6_D));
    ASSERT_DOUBLE_EQ(1.6, 1.6_D);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64ToDouble) {
    ASSERT_TRUE(is<Double>(42_D));
    ASSERT_DOUBLE_EQ(42.0, 42_D);
  }
  
  TEST(LiteralOperatorConverterTest, StringToDouble) {
    ASSERT_TRUE(is<Double>("1.6"_D));
    ASSERT_DOUBLE_EQ(1.6, "1.6"_D);
  }
  
  TEST(LiteralOperatorConverterTest, CharPointerToString) {
    ASSERT_TRUE(is<String>("Fourty Two"_s));
    ASSERT_EQ("Fourty Two", "Fourty Two"_s);
    ASSERT_TRUE(is<String>("Fourty Two"_S));
    ASSERT_EQ("Fourty Two", "Fourty Two"_S);
  }
  
  TEST(LiteralOperatorConverterTest, Char16PointerToString) {
    ASSERT_TRUE(is<String>(u"Fourty Two"_s));
    ASSERT_EQ("Fourty Two", u"Fourty Two"_s);
    ASSERT_TRUE(is<String>(u"Fourty Two"_S));
    ASSERT_EQ("Fourty Two", u"Fourty Two"_S);
  }
  
  TEST(LiteralOperatorConverterTest, Char32PointerToString) {
    ASSERT_TRUE(is<String>(U"Fourty Two"_s));
    ASSERT_EQ("Fourty Two", U"Fourty Two"_s);
    ASSERT_TRUE(is<String>(U"Fourty Two"_S));
    ASSERT_EQ("Fourty Two", U"Fourty Two"_S);
  }
  
  TEST(LiteralOperatorConverterTest, WCharPointerToString) {
    ASSERT_TRUE(is<String>(L"Fourty Two"_s));
    ASSERT_EQ("Fourty Two", L"Fourty Two"_s);
    ASSERT_TRUE(is<String>(L"Fourty Two"_S));
    ASSERT_EQ("Fourty Two", L"Fourty Two"_S);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleToInt16) {
    ASSERT_TRUE(is<Int16>(1.6_S16));
    ASSERT_EQ(2, 1.6_S16);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64ToInt16) {
    ASSERT_TRUE(is<Int16>(42_S16));
    ASSERT_EQ(42, 42_S16);
  }
  
  TEST(LiteralOperatorConverterTest, StringToInt16) {
    ASSERT_TRUE(is<Int16>("42"_S16));
    ASSERT_EQ(42, "42"_S16);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleToInt32) {
    ASSERT_TRUE(is<Int32>(1.6_S32));
    ASSERT_EQ(2, 1.6_S32);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64ToInt32) {
    ASSERT_TRUE(is<Int32>(42_S32));
    ASSERT_EQ(42, 42_S32);
  }
  
  TEST(LiteralOperatorConverterTest, StringToInt32) {
    ASSERT_TRUE(is<Int32>("42"_S32));
    ASSERT_EQ(42, "42"_S32);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleToInt64) {
    ASSERT_TRUE(is<Int64>(1.6_S64));
    ASSERT_EQ(2, 1.6_S64);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64ToInt64) {
    ASSERT_TRUE(is<Int64>(42_S64));
    ASSERT_EQ(42, 42_S64);
  }
  
  TEST(LiteralOperatorConverterTest, StringToInt64) {
    ASSERT_TRUE(is<Int64>("42"_S64));
    ASSERT_EQ(42, "42"_S64);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleToSByte) {
    ASSERT_TRUE(is<SByte>(1.6_SB));
    ASSERT_EQ(2, 1.6_SB);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64ToSByte) {
    ASSERT_TRUE(is<SByte>(42_SB));
    ASSERT_EQ(42, 42_SB);
  }
  
  TEST(LiteralOperatorConverterTest, StringToSByte) {
    ASSERT_TRUE(is<SByte>("42"_SB));
    ASSERT_EQ(42, "42"_SB);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleToSingle) {
    ASSERT_TRUE(is<Single>(1.6_F));
    ASSERT_FLOAT_EQ(1.6f, 1.6_F);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64ToSingle) {
    ASSERT_TRUE(is<Single>(42_F));
    ASSERT_FLOAT_EQ(42.0f, 42_F);
  }
  
  TEST(LiteralOperatorConverterTest, StringToSingle) {
    ASSERT_TRUE(is<Single>("1.6"_F));
    ASSERT_FLOAT_EQ(1.6f, "1.6"_F);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleToUInt16) {
    ASSERT_TRUE(is<UInt16>(1.6_U16));
    ASSERT_EQ(2u, 1.6_U16);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64ToUInt16) {
    ASSERT_TRUE(is<UInt16>(42_U16));
    ASSERT_EQ(42u, 42_U16);
  }
  
  TEST(LiteralOperatorConverterTest, StringToUInt16) {
    ASSERT_TRUE(is<UInt16>("42"_U16));
    ASSERT_EQ(42u, "42"_U16);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleToUInt32) {
    ASSERT_TRUE(is<UInt32>(1.6_U32));
    ASSERT_EQ(2u, 1.6_U32);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64ToUInt32) {
    ASSERT_TRUE(is<UInt32>(42_U32));
    ASSERT_EQ(42u, 42_U32);
  }
  
  TEST(LiteralOperatorConverterTest, StringToUInt32) {
    ASSERT_TRUE(is<UInt32>("42"_U32));
    ASSERT_EQ(42u, "42"_U32);
  }
  
  TEST(LiteralOperatorConverterTest, DoubleToUInt64) {
    ASSERT_TRUE(is<UInt64>(1.6_U64));
    ASSERT_EQ(2u, 1.6_U64);
  }
  
  TEST(LiteralOperatorConverterTest, UInt64ToUInt64) {
    ASSERT_TRUE(is<UInt64>(42_U64));
    ASSERT_EQ(42u, 42_U64);
  }
  
  TEST(LiteralOperatorConverterTest, StringToUInt64) {
    ASSERT_TRUE(is<UInt64>("42"_U64));
    ASSERT_EQ(42u, "42"_U64);
  }
}
