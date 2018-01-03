#include <Switch/System/Int16.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/FormatException.hpp>
#include <Switch/System/OverflowException.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {

  TEST(Int16Test, MaxValue) {
    ASSERT_EQ(0x7FFF, Int16::MaxValue);
  }

  TEST(Int16Test, MinValue) {
    ASSERT_EQ(-0x8000, Int16::MinValue);
  }

  TEST(Int16Test, DefaultValue) {
    ASSERT_EQ(0, Int16());
  }

  TEST(Int16Test, CtorValue) {
    ASSERT_EQ(10, Int16(10));
    ASSERT_EQ(12654, Int16(12654));
    ASSERT_EQ(0, Int16(0));
    ASSERT_EQ(-1, Int16(-1));
    ASSERT_EQ(-29973, Int16(-29973));
  }

  TEST(Int16Test, Parse) {
    ASSERT_EQ(0, Int16::Parse("0"));
    ASSERT_EQ(1, Int16::Parse("1"));
    ASSERT_EQ(123, Int16::Parse("123"));
    ASSERT_EQ(28012, Int16::Parse("28012"));
    ASSERT_EQ(-1, Int16::Parse("-1"));
    ASSERT_EQ(-100, Int16::Parse("-100"));
    ASSERT_EQ(-32768, Int16::Parse("-32768"));
  }

  TEST(Int16Test, Parse_Leading_Zeros) {
    ASSERT_EQ(0, Int16::Parse("0"));
    ASSERT_EQ(0, Int16::Parse("00"));
    ASSERT_EQ(0, Int16::Parse("000"));
    ASSERT_EQ(1, Int16::Parse("01"));
    ASSERT_EQ(1, Int16::Parse("0001"));
    ASSERT_EQ(99, Int16::Parse("099"));
    ASSERT_EQ(999, Int16::Parse("0000999"));
  }

  TEST(Int16Test, Parse_Spaces) {
    ASSERT_EQ(5, Int16::Parse(" 5"));
    ASSERT_EQ(5, Int16::Parse("     5"));
    ASSERT_EQ(5, Int16::Parse("5 "));
    ASSERT_EQ(51, Int16::Parse("51     "));
    ASSERT_EQ(5, Int16::Parse(" 5      "));
    ASSERT_EQ(52, Int16::Parse("        +52 "));
    ASSERT_EQ(-52, Int16::Parse("        -052 "));
  }

  TEST(Int16Test, Parse_FormatException) {
    ASSERT_THROW(Int16::Parse(""), FormatException);
    ASSERT_THROW(Int16::Parse("a56"), FormatException);
    ASSERT_THROW(Int16::Parse("0 0"), FormatException);
    ASSERT_THROW(Int16::Parse("++000"), FormatException);
    ASSERT_THROW(Int16::Parse("+"), FormatException);
    ASSERT_THROW(Int16::Parse("-"), FormatException);
    ASSERT_THROW(Int16::Parse("--5"), FormatException);
    ASSERT_THROW(Int16::Parse("0x53"), FormatException);
    ASSERT_THROW(Int16::Parse("100a"), FormatException);
    ASSERT_THROW(Int16::Parse("10u"), FormatException);
  }

  TEST(Int16Test, Parse_OverFlowException) {
    ASSERT_EQ(Int16::MaxValue, Int16::Parse("32767"));
    ASSERT_THROW(Int16::Parse("32768"), OverflowException);
    ASSERT_EQ(Int16::MinValue, Int16::Parse("-32768"));
    ASSERT_THROW(Int16::Parse("-32769"), OverflowException);
    ASSERT_THROW(Int16::Parse("45111"), OverflowException);
    ASSERT_THROW(Int16::Parse("870125"), OverflowException);
  }

  TEST(Int16Test, Parse_Binary) {
    ASSERT_EQ(0, Int16::Parse("0", 2));
    ASSERT_EQ(1, Int16::Parse("1", 2));
    ASSERT_EQ(2, Int16::Parse("10", 2));
    ASSERT_EQ(3, Int16::Parse("11", 2));
    ASSERT_EQ(6, Int16::Parse("110", 2));
    ASSERT_EQ(-1, Int16::Parse("-1", 2));
    ASSERT_EQ(-4, Int16::Parse("-100", 2));
    ASSERT_EQ(-15, Int16::Parse("-1111", 2));
    ASSERT_EQ(Int16::MinValue, Int16::Parse("-1000000000000000", 2));
  }

  TEST(Int16Test, Parse_Binary_Complement) {
    ASSERT_EQ(-1, Int16::Parse("1111111111111111", 2));
    ASSERT_EQ(-111, Int16::Parse("1111111110010001", 2));
    ASSERT_EQ(-31987, Int16::Parse("1000001100001101", 2));
    ASSERT_EQ(Int16::MinValue, Int16::Parse("1000000000000000", 2));
  }

  TEST(Int16Test, Parse_Binary_Complement_Overflow) {
    ASSERT_THROW(Int16::Parse("10000000000000000", 2), OverflowException);
    ASSERT_THROW(Int16::Parse("-1111111111111111", 2), OverflowException);
    ASSERT_THROW(Int16::Parse("-1111111110010001", 2), OverflowException);
    ASSERT_THROW(Int16::Parse("-1000001100001101", 2), OverflowException);
    ASSERT_THROW(Int16::Parse("-10000000000000000", 2), OverflowException);
  }

  TEST(Int16Test, Parse_Exceptions_Binary) {
    ASSERT_THROW(Int16::Parse("", 2), FormatException);
    ASSERT_THROW(Int16::Parse("2", 2), FormatException);
    ASSERT_THROW(Int16::Parse("103", 2), FormatException);
    ASSERT_THROW(Int16::Parse("++0", 2), FormatException);
    ASSERT_THROW(Int16::Parse("+", 2), FormatException);
    ASSERT_THROW(Int16::Parse("-", 2), FormatException);
    ASSERT_THROW(Int16::Parse("--1", 2), FormatException);
    ASSERT_THROW(Int16::Parse("0x53", 2), FormatException);
    ASSERT_THROW(Int16::Parse("100a", 2), FormatException);
    ASSERT_THROW(Int16::Parse("10u", 2), FormatException);
  }

  TEST(Int16Test, Parse_Octal) {
    ASSERT_EQ(0, Int16::Parse("0", 8));
    ASSERT_EQ(1, Int16::Parse("1", 8));
    ASSERT_EQ(12, Int16::Parse("14", 8));
    ASSERT_EQ(56, Int16::Parse("70", 8));
    ASSERT_EQ(601, Int16::Parse("1131", 8));
    ASSERT_EQ(-1, Int16::Parse("-1", 8));
    ASSERT_EQ(-4, Int16::Parse("-4", 8));
    ASSERT_EQ(-15, Int16::Parse("-17", 8));
  }

  TEST(Int16Test, Parse_Hexadecimal) {
    ASSERT_EQ(0, Int16::Parse("0", 16));
    ASSERT_EQ(1, Int16::Parse("1", 16));
    ASSERT_EQ(0xC, Int16::Parse("C", 16));
    ASSERT_EQ(0x3C, Int16::Parse("3c", 16));
    ASSERT_EQ(0xFE3, Int16::Parse("FE3", 16));
    ASSERT_EQ(-0x4A, Int16::Parse("-4A", 16));
    ASSERT_EQ(-0x6BCD, Int16::Parse("-6BCD", 16));
  }

  TEST(Int16Test, Parse_Hexadecimal_Complement) {
    ASSERT_EQ(-1, Int16::Parse("FFFF", 16));
    ASSERT_EQ(-333, Int16::Parse("0xFEB3", 16));
    ASSERT_EQ(-12587, Int16::Parse("CED5", 16));
    ASSERT_EQ(Int16::MinValue, Int16::Parse("0x8000", 16));
    ASSERT_EQ(Int16::MinValue, Int16::Parse("-0x8000", 16));
  }

  TEST(Int16Test, Parse_Hexadecimal_Complement_Overflow) {
    ASSERT_THROW(Int16::Parse("10000", 16), OverflowException);
    ASSERT_THROW(Int16::Parse("0x10100", 16), OverflowException);
  }

  TEST(Int16Test, TryParse) {
    int16 x;
    ASSERT_TRUE(Int16::TryParse("0", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int16::TryParse("1", x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int16::TryParse("123", x));
    ASSERT_EQ(123, x);
    ASSERT_TRUE(Int16::TryParse("28012", x));
    ASSERT_EQ(28012, x);
    ASSERT_TRUE(Int16::TryParse("-1", x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int16::TryParse("-100", x));
    ASSERT_EQ(-100, x);
    ASSERT_TRUE(Int16::TryParse("-32768", x));
    ASSERT_EQ(-32768, x);
  }

  TEST(Int16Test, TryParse_Int16) {
    Int16 x;
    ASSERT_TRUE(Int16::TryParse("0", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int16::TryParse("1", x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int16::TryParse("123", x));
    ASSERT_EQ(123, x);
    ASSERT_TRUE(Int16::TryParse("28012", x));
    ASSERT_EQ(28012, x);
    ASSERT_TRUE(Int16::TryParse("-1", x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int16::TryParse("-100", x));
    ASSERT_EQ(-100, x);
    ASSERT_TRUE(Int16::TryParse("-32768", x));
    ASSERT_EQ(-32768, x);
  }

  TEST(Int16Test, TryParse_Leading_Zeros) {
    int16 x;
    ASSERT_TRUE(Int16::TryParse("0", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int16::TryParse("00", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int16::TryParse("000", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int16::TryParse("01", x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int16::TryParse("0001", x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int16::TryParse("099", x));
    ASSERT_EQ(99, x);
    ASSERT_TRUE(Int16::TryParse("0000999", x));
    ASSERT_EQ(999, x);
  }

  TEST(Int16Test, TryParse_Leading_Zeros_Int16) {
    Int16 x;
    ASSERT_TRUE(Int16::TryParse("0", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int16::TryParse("00", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int16::TryParse("000", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int16::TryParse("01", x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int16::TryParse("0001", x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int16::TryParse("099", x));
    ASSERT_EQ(99, x);
    ASSERT_TRUE(Int16::TryParse("0000999", x));
    ASSERT_EQ(999, x);
  }

  TEST(Int16Test, TryParse_Spaces) {
    int16 x;
    ASSERT_TRUE(Int16::TryParse(" 5", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int16::TryParse("     5", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int16::TryParse("5 ", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int16::TryParse("51     ", x));
    ASSERT_EQ(51, x);
    ASSERT_TRUE(Int16::TryParse(" 5      ", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int16::TryParse("        +52 ", x));
    ASSERT_EQ(52, x);
    ASSERT_TRUE(Int16::TryParse("        -052 ", x));
    ASSERT_EQ(-52, x);
  }

  TEST(Int16Test, TryParse_Spaces_Int16) {
    Int16 x;
    ASSERT_TRUE(Int16::TryParse(" 5", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int16::TryParse("     5", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int16::TryParse("5 ", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int16::TryParse("51     ", x));
    ASSERT_EQ(51, x);
    ASSERT_TRUE(Int16::TryParse(" 5      ", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int16::TryParse("        +52 ", x));
    ASSERT_EQ(52, x);
    ASSERT_TRUE(Int16::TryParse("        -052 ", x));
    ASSERT_EQ(-52, x);
  }

  TEST(Int16Test, TryParse_FormatException) {
    int16 x;
    ASSERT_FALSE(Int16::TryParse("", x));
    ASSERT_FALSE(Int16::TryParse("a56", x));
    ASSERT_FALSE(Int16::TryParse("0 0", x));
    ASSERT_FALSE(Int16::TryParse("++000", x));
    ASSERT_FALSE(Int16::TryParse("+", x));
    ASSERT_FALSE(Int16::TryParse("-", x));
    ASSERT_FALSE(Int16::TryParse("--5", x));
    ASSERT_FALSE(Int16::TryParse("0x53", x));
    ASSERT_FALSE(Int16::TryParse("100a", x));
    ASSERT_FALSE(Int16::TryParse("10u", x));
  }

  TEST(Int16Test, TryParse_FormatException_Int16) {
    Int16 x;
    ASSERT_FALSE(Int16::TryParse("", x));
    ASSERT_FALSE(Int16::TryParse("a56", x));
    ASSERT_FALSE(Int16::TryParse("0 0", x));
    ASSERT_FALSE(Int16::TryParse("++000", x));
    ASSERT_FALSE(Int16::TryParse("+", x));
    ASSERT_FALSE(Int16::TryParse("-", x));
    ASSERT_FALSE(Int16::TryParse("--5", x));
    ASSERT_FALSE(Int16::TryParse("0x53", x));
    ASSERT_FALSE(Int16::TryParse("100a", x));
    ASSERT_FALSE(Int16::TryParse("10u", x));
  }

  TEST(Int16Test, TryParse_OverFlowException) {
    int16 x;
    ASSERT_TRUE(Int16::TryParse("32767", x));
    ASSERT_EQ(Int16::MaxValue, x);
    ASSERT_FALSE(Int16::TryParse("32768", x));
    ASSERT_TRUE(Int16::TryParse("-32768", x));
    ASSERT_EQ(Int16::MinValue, x);
    ASSERT_FALSE(Int16::TryParse("-32769", x));
    ASSERT_FALSE(Int16::TryParse("45111", x));
    ASSERT_FALSE(Int16::TryParse("870125", x));
  }

  TEST(Int16Test, TryParse_Binary) {
    int16 x;
    ASSERT_TRUE(Int16::TryParse("0", 2, x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int16::TryParse("1", 2, x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int16::TryParse("10", 2, x));
    ASSERT_EQ(2, x);
    ASSERT_TRUE(Int16::TryParse("11", 2, x));
    ASSERT_EQ(3, x);
    ASSERT_TRUE(Int16::TryParse("110", 2, x));
    ASSERT_EQ(6, x);
    ASSERT_TRUE(Int16::TryParse("-1", 2, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int16::TryParse("-100", 2, x));
    ASSERT_EQ(-4, x);
    ASSERT_TRUE(Int16::TryParse("-1111", 2, x));
    ASSERT_EQ(-15, x);
    ASSERT_TRUE(Int16::TryParse("-1000000000000000", 2, x));
    ASSERT_EQ(Int16::MinValue, x);
  }

  TEST(Int16Test, TryParse_Binary_Int16) {
    Int16 x;
    ASSERT_TRUE(Int16::TryParse("0", 2, x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int16::TryParse("1", 2, x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int16::TryParse("10", 2, x));
    ASSERT_EQ(2, x);
    ASSERT_TRUE(Int16::TryParse("11", 2, x));
    ASSERT_EQ(3, x);
    ASSERT_TRUE(Int16::TryParse("110", 2, x));
    ASSERT_EQ(6, x);
    ASSERT_TRUE(Int16::TryParse("-1", 2, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int16::TryParse("-100", 2, x));
    ASSERT_EQ(-4, x);
    ASSERT_TRUE(Int16::TryParse("-1111", 2, x));
    ASSERT_EQ(-15, x);
    ASSERT_TRUE(Int16::TryParse("-1000000000000000", 2, x));
    ASSERT_EQ(Int16::MinValue, x);
  }

  TEST(Int16Test, TryParse_Binary_Complement) {
    int16 x;
    ASSERT_TRUE(Int16::TryParse("1111111111111111", 2, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int16::TryParse("1111111110010001", 2, x));
    ASSERT_EQ(-111, x);
    ASSERT_TRUE(Int16::TryParse("1000001100001101", 2, x));
    ASSERT_EQ(-31987, x);
    ASSERT_TRUE(Int16::TryParse("1000000000000000", 2, x));
    ASSERT_EQ(Int16::MinValue, x);
  }

  TEST(Int16Test, TryParse_Binary_Complement_Int16) {
    Int16 x;
    ASSERT_TRUE(Int16::TryParse("1111111111111111", 2, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int16::TryParse("1111111110010001", 2, x));
    ASSERT_EQ(-111, x);
    ASSERT_TRUE(Int16::TryParse("1000001100001101", 2, x));
    ASSERT_EQ(-31987, x);
    ASSERT_TRUE(Int16::TryParse("1000000000000000", 2, x));
    ASSERT_EQ(Int16::MinValue, x);
  }

  TEST(Int16Test, TryParse_Binary_Complement_Overflow) {
    int16 x;
    ASSERT_FALSE(Int16::TryParse("10000000000000000", 2, x));
    ASSERT_FALSE(Int16::TryParse("-1111111111111111", 2, x));
    ASSERT_FALSE(Int16::TryParse("-1111111110010001", 2, x));
    ASSERT_FALSE(Int16::TryParse("-1000001100001101", 2, x));
    ASSERT_FALSE(Int16::TryParse("-10000000000000000", 2, x));
  }

  TEST(Int16Test, TryParse_Binary_Complement_Overflow_Int16) {
    Int16 x;
    ASSERT_FALSE(Int16::TryParse("10000000000000000", 2, x));
    ASSERT_FALSE(Int16::TryParse("-1111111111111111", 2, x));
    ASSERT_FALSE(Int16::TryParse("-1111111110010001", 2, x));
    ASSERT_FALSE(Int16::TryParse("-1000001100001101", 2, x));
    ASSERT_FALSE(Int16::TryParse("-10000000000000000", 2, x));
  }

  TEST(Int16Test, TryParse_Exceptions_Binary) {
    int16 x;
    ASSERT_FALSE(Int16::TryParse("", 2, x));
    ASSERT_FALSE(Int16::TryParse("2", 2, x));
    ASSERT_FALSE(Int16::TryParse("103", 2, x));
    ASSERT_FALSE(Int16::TryParse("++0", 2, x));
    ASSERT_FALSE(Int16::TryParse("+", 2, x));
    ASSERT_FALSE(Int16::TryParse("-", 2, x));
    ASSERT_FALSE(Int16::TryParse("--1", 2, x));
    ASSERT_FALSE(Int16::TryParse("0x53", 2, x));
    ASSERT_FALSE(Int16::TryParse("100a", 2, x));
    ASSERT_FALSE(Int16::TryParse("10u", 2, x));
  }

  TEST(Int16Test, TryParse_Exceptions_Binary_Int16) {
    Int16 x;
    ASSERT_FALSE(Int16::TryParse("", 2, x));
    ASSERT_FALSE(Int16::TryParse("2", 2, x));
    ASSERT_FALSE(Int16::TryParse("103", 2, x));
    ASSERT_FALSE(Int16::TryParse("++0", 2, x));
    ASSERT_FALSE(Int16::TryParse("+", 2, x));
    ASSERT_FALSE(Int16::TryParse("-", 2, x));
    ASSERT_FALSE(Int16::TryParse("--1", 2, x));
    ASSERT_FALSE(Int16::TryParse("0x53", 2, x));
    ASSERT_FALSE(Int16::TryParse("100a", 2, x));
    ASSERT_FALSE(Int16::TryParse("10u", 2, x));
  }

  TEST(Int16Test, TryParse_Octal) {
    int16 x;
    ASSERT_TRUE(Int16::TryParse("0", 8, x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int16::TryParse("1", 8, x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int16::TryParse("14", 8, x));
    ASSERT_EQ(12, x);
    ASSERT_TRUE(Int16::TryParse("70", 8, x));
    ASSERT_EQ(56, x);
    ASSERT_TRUE(Int16::TryParse("1131", 8, x));
    ASSERT_EQ(601, x);
    ASSERT_TRUE(Int16::TryParse("-1", 8, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int16::TryParse("-4", 8, x));
    ASSERT_EQ(-4, x);
    ASSERT_TRUE(Int16::TryParse("-17", 8, x));
    ASSERT_EQ(-15, x);
  }

  TEST(Int16Test, TryParse_Octal_Int16) {
    Int16 x;
    ASSERT_TRUE(Int16::TryParse("0", 8, x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int16::TryParse("1", 8, x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int16::TryParse("14", 8, x));
    ASSERT_EQ(12, x);
    ASSERT_TRUE(Int16::TryParse("70", 8, x));
    ASSERT_EQ(56, x);
    ASSERT_TRUE(Int16::TryParse("1131", 8, x));
    ASSERT_EQ(601, x);
    ASSERT_TRUE(Int16::TryParse("-1", 8, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int16::TryParse("-4", 8, x));
    ASSERT_EQ(-4, x);
    ASSERT_TRUE(Int16::TryParse("-17", 8, x));
    ASSERT_EQ(-15, x);
  }

  TEST(Int16Test, TryParse_Hexadecimal) {
    int16 x;
    ASSERT_TRUE(Int16::TryParse("0", 16, x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int16::TryParse("1", 16, x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int16::TryParse("C", 16, x));
    ASSERT_EQ(12, x);
    ASSERT_TRUE(Int16::TryParse("3c", 16, x));
    ASSERT_EQ(60, x);
    ASSERT_TRUE(Int16::TryParse("FE3", 16, x));
    ASSERT_EQ(4067, x);
    ASSERT_TRUE(Int16::TryParse("-4A", 16, x));
    ASSERT_EQ(-74, x);
    ASSERT_TRUE(Int16::TryParse("-6BCD", 16, x));
    ASSERT_EQ(-27597, x);
  }

  TEST(Int16Test, TryParse_Hexadecimal_Int16) {
    Int16 x;
    ASSERT_TRUE(Int16::TryParse("0", 16, x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int16::TryParse("1", 16, x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int16::TryParse("C", 16, x));
    ASSERT_EQ(12, x);
    ASSERT_TRUE(Int16::TryParse("3c", 16, x));
    ASSERT_EQ(60, x);
    ASSERT_TRUE(Int16::TryParse("FE3", 16, x));
    ASSERT_EQ(4067, x);
    ASSERT_TRUE(Int16::TryParse("-4A", 16, x));
    ASSERT_EQ(-74, x);
    ASSERT_TRUE(Int16::TryParse("-6BCD", 16, x));
    ASSERT_EQ(-27597, x);
  }


  TEST(Int16Test, TryParse_Hexadecimal_Complement) {
    int16 x;
    ASSERT_TRUE(Int16::TryParse("FFFF", 16, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int16::TryParse("0xFEB3", 16, x));
    ASSERT_EQ(-333, x);
    ASSERT_TRUE(Int16::TryParse("CED5", 16, x));
    ASSERT_EQ(-12587, x);
    ASSERT_TRUE(Int16::TryParse("0x8000", 16, x));
    ASSERT_EQ(Int16::MinValue, x);
    ASSERT_TRUE(Int16::TryParse("-0x8000", 16, x));
    ASSERT_EQ(Int16::MinValue, x);
  }

  TEST(Int16Test, TryParse_Hexadecimal_Complement_Int16) {
    Int16 x;
    ASSERT_TRUE(Int16::TryParse("FFFF", 16, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int16::TryParse("0xFEB3", 16, x));
    ASSERT_EQ(-333, x);
    ASSERT_TRUE(Int16::TryParse("CED5", 16, x));
    ASSERT_EQ(-12587, x);
    ASSERT_TRUE(Int16::TryParse("0x8000", 16, x));
    ASSERT_EQ(Int16::MinValue, x);
    ASSERT_TRUE(Int16::TryParse("-0x8000", 16, x));
    ASSERT_EQ(Int16::MinValue, x);
  }

  TEST(Int16Test, TryParse_Hexadecimal_Complement_Overflow) {
    int16 x;
    ASSERT_FALSE(Int16::TryParse("10000", 16, x));
    ASSERT_FALSE(Int16::TryParse("0x10100", 16, x));
  }
}

/*

 C# program used to generate this unit test :

 using System;
 using System::Collections::Generic;
 using System::Linq;
 using System::Text;
 using System::Threading::Tasks;
 using System::Reflection;

 namespace Natives {
 class Program {
 static void Main(string[] args) {
 //String[] tests = { "0", "00", "000", "01", "0001", "099", "0000999" };
 String[] tests = { "--56", "00", "000", "01", "0001", "099", "0000999" };

 for (String s : tests)
 MakeTest<Int16>(s, 5, "");

 Console.ReadKey(true);
 }

 static void MakeTest<T>(String s, T prototype, String fmt) {
 String type = typeof_(T).Name;
 String suffix = type == "Single" ? "f" : "";

 try {
 MethodInfo method = typeof_(T).GetMethod("Parse", new Type[] {typeof_(String)});
 T value = (T)method.Invoke(prototype, new object[] {s});
 Console.WriteLine("ASSERT_EQ({0}{3}, {1}::Parse(\"{2}\"));",
 (value as IFormattable).ToString(fmt, System::Globalization::CultureInfo.CreateSpecificCulture("en-US")), type, s, suffix);
 } catch (System::FormatException) {
 Console.WriteLine("ASSERT_THROW({0}::Parse(\"{1}\"), FormatException);", type, s);
 } catch (System::Reflection.TargetInvocationException x) {
 Console.WriteLine("ASSERT_THROW({0}::Parse(\"{1}\"), {2});", type, s, x.InnerException.GetType().Name);
 }
 }
 }
 }
 */

