#include <Switch/System/Int32.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/FormatException.hpp>
#include <Switch/System/OverflowException.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(Int32Test, MaxValue) {
    ASSERT_EQ(0x7FFFFFFF, Int32::MaxValue);
  }
  
  TEST(Int32Test, MinValue) {
    ASSERT_EQ((-2147483647) - 1, Int32::MinValue); //  VS2012 does not handle -2147483648 correctly
  }
  
  TEST(Int32Test, DefaultValue) {
    ASSERT_EQ(0, Int32());
  }
  
  TEST(Int32Test, CtorValue) {
    ASSERT_EQ(10, Int32(10));
    ASSERT_EQ(123654, Int32(123654));
    ASSERT_EQ(0, Int32(0));
    ASSERT_EQ(-1, Int32(-1));
    ASSERT_EQ(-159753, Int32(-159753));
  }
  
  TEST(Int32Test, Parse) {
    ASSERT_EQ(0, Int32::Parse("0"));
    ASSERT_EQ(1, Int32::Parse("1"));
    ASSERT_EQ(123, Int32::Parse("123"));
    ASSERT_EQ(123654, Int32::Parse("123654"));
    ASSERT_EQ(-1, Int32::Parse("-1"));
    ASSERT_EQ(-100, Int32::Parse("-100"));
    ASSERT_EQ(-98744, Int32::Parse("-98744"));
  }
  
  TEST(Int32Test, Parse_Leading_Zeros) {
    ASSERT_EQ(0, Int32::Parse("0"));
    ASSERT_EQ(0, Int32::Parse("00"));
    ASSERT_EQ(0, Int32::Parse("000"));
    ASSERT_EQ(1, Int32::Parse("01"));
    ASSERT_EQ(1, Int32::Parse("0001"));
    ASSERT_EQ(99, Int32::Parse("099"));
    ASSERT_EQ(999, Int32::Parse("0000999"));
    ASSERT_EQ(11, Int32::Parse("00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011"));
    ASSERT_THROW(Int32::Parse("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011"), OverflowException);
  }
  
  TEST(Int32Test, Parse_Spaces) {
    ASSERT_EQ(5, Int32::Parse(" 5"));
    ASSERT_EQ(5, Int32::Parse("     5"));
    ASSERT_EQ(5, Int32::Parse("5 "));
    ASSERT_EQ(51, Int32::Parse("51     "));
    ASSERT_EQ(5, Int32::Parse(" 5      "));
    ASSERT_EQ(52, Int32::Parse("        +52 "));
    ASSERT_EQ(52, Int32::Parse("        +052 "));
    ASSERT_EQ(-52, Int32::Parse("        -52 "));
  }
  
  TEST(Int32Test, Parse_FormatException) {
    ASSERT_THROW(Int32::Parse(""), FormatException);
    ASSERT_THROW(Int32::Parse("a56"), FormatException);
    ASSERT_THROW(Int32::Parse("0 0"), FormatException);
    ASSERT_THROW(Int32::Parse("++000"), FormatException);
    ASSERT_THROW(Int32::Parse("+"), FormatException);
    ASSERT_THROW(Int32::Parse("-"), FormatException);
    ASSERT_THROW(Int32::Parse("--5"), FormatException);
    ASSERT_THROW(Int32::Parse("0x53"), FormatException);
    ASSERT_THROW(Int32::Parse("100a"), FormatException);
    ASSERT_THROW(Int32::Parse("10u"), FormatException);
  }
  
  TEST(Int32Test, Parse_OverFlowException) {
    ASSERT_EQ(Int32::MaxValue, Int32::Parse("2147483647"));
    ASSERT_THROW(Int32::Parse("2147483648"), OverflowException);
    ASSERT_EQ(Int32::MinValue, Int32::Parse("-2147483648"));
    ASSERT_THROW(Int32::Parse("-2147483649"), OverflowException);
    ASSERT_THROW(Int32::Parse("4294967296"), OverflowException);
    ASSERT_THROW(Int32::Parse("5294967295"), OverflowException);
  }
  
  TEST(Int32Test, Parse_Binary) {
    ASSERT_EQ(0, Int32::Parse("0", 2));
    ASSERT_EQ(1, Int32::Parse("1", 2));
    ASSERT_EQ(2, Int32::Parse("10", 2));
    ASSERT_EQ(3, Int32::Parse("11", 2));
    ASSERT_EQ(6, Int32::Parse("110", 2));
    ASSERT_EQ(-1, Int32::Parse("-1", 2));
    ASSERT_EQ(-4, Int32::Parse("-100", 2));
    ASSERT_EQ(-15, Int32::Parse("-1111", 2));
  }
  
  TEST(Int32Test, Parse_Binary_Complement) {
    ASSERT_EQ(-1, Int32::Parse("11111111111111111111111111111111", 2));
    ASSERT_EQ(Int32::MinValue, Int32::Parse("10000000000000000000000000000000", 2));
    ASSERT_EQ(-294127, Int32::Parse("11111111111110111000001100010001", 2));
    ASSERT_EQ(-3452119, Int32::Parse("11111111110010110101001100101001", 2));
    ASSERT_EQ(-2011477291, Int32::Parse("10001000000110110100101011010101", 2));
    ASSERT_EQ(Int32::MinValue, Int32::Parse("-10000000000000000000000000000000", 2));
  }
  
  TEST(Int32Test, Parse_Binary_Complement_Overflow) {
    ASSERT_THROW(Int32::Parse("-11111111111111111111111111111111", 2), OverflowException);
    ASSERT_THROW(Int32::Parse("-10000000000000000000000000000001", 2), OverflowException);
  }
  
  TEST(Int32Test, Parse_Exceptions_Binary) {
    ASSERT_THROW(Int32::Parse("", 2), FormatException);
    ASSERT_THROW(Int32::Parse("2", 2), FormatException);
    ASSERT_THROW(Int32::Parse("103", 2), FormatException);
    ASSERT_THROW(Int32::Parse("++0", 2), FormatException);
    ASSERT_THROW(Int32::Parse("+", 2), FormatException);
    ASSERT_THROW(Int32::Parse("-", 2), FormatException);
    ASSERT_THROW(Int32::Parse("--1", 2), FormatException);
    ASSERT_THROW(Int32::Parse("0x53", 2), FormatException);
    ASSERT_THROW(Int32::Parse("100a", 2), FormatException);
    ASSERT_THROW(Int32::Parse("10u", 2), FormatException);
  }
  
  TEST(Int32Test, Parse_Octal) {
    ASSERT_EQ(0, Int32::Parse("0", 8));
    ASSERT_EQ(1, Int32::Parse("1", 8));
    ASSERT_EQ(12, Int32::Parse("14", 8));
    ASSERT_EQ(56, Int32::Parse("70", 8));
    ASSERT_EQ(601, Int32::Parse("1131", 8));
    ASSERT_EQ(-1, Int32::Parse("-1", 8));
    ASSERT_EQ(-4, Int32::Parse("-4", 8));
    ASSERT_EQ(-15, Int32::Parse("-17", 8));
  }
  
  TEST(Int32Test, Parse_Hexadecimal) {
    ASSERT_EQ(0, Int32::Parse("0", 16));
    ASSERT_EQ(1, Int32::Parse("1", 16));
    ASSERT_EQ(0xC, Int32::Parse("C", 16));
    ASSERT_EQ(0x3C, Int32::Parse("3c", 16));
    ASSERT_EQ(0xFE3, Int32::Parse("FE3", 16));
    ASSERT_EQ(-0x4A, Int32::Parse("-4A", 16));
    ASSERT_EQ(-0xABCDE, Int32::Parse("-ABCDE", 16));
  }
  
  TEST(Int32Test, Parse_Hexadecimal_Complement) {
    ASSERT_EQ(-1, Int32::Parse("FFFFFFFF", 16));
    ASSERT_EQ(Int32::MinValue, Int32::Parse("80000000", 16));
    ASSERT_EQ(Int32::MinValue, Int32::Parse("-80000000", 16));
    ASSERT_EQ(-5459, Int32::Parse("FFFFEAAD", 16));
    ASSERT_EQ(-545919, Int32::Parse("FFF7AB81", 16));
  }
  
  TEST(Int32Test, Parse_Hexadecimal_Complement_Overflow) {
    ASSERT_THROW(Int32::Parse("-FFFFFFFF", 16), OverflowException);
    ASSERT_THROW(Int32::Parse("-80000001", 16), OverflowException);
  }
  
  TEST(Int32Test, TryParse) {
    int32 x;
    ASSERT_TRUE(Int32::TryParse("0", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int32::TryParse("1", x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int32::TryParse("123", x));
    ASSERT_EQ(123, x);
    ASSERT_TRUE(Int32::TryParse("123654", x));
    ASSERT_EQ(123654, x);
    ASSERT_TRUE(Int32::TryParse("-1", x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int32::TryParse("-100", x));
    ASSERT_EQ(-100, x);
    ASSERT_TRUE(Int32::TryParse("-98744", x));
    ASSERT_EQ(-98744, x);
  }
  
  TEST(Int32Test, TryParse_Int32) {
    Int32 x;
    ASSERT_TRUE(Int32::TryParse("0", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int32::TryParse("1", x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int32::TryParse("123", x));
    ASSERT_EQ(123, x);
    ASSERT_TRUE(Int32::TryParse("123654", x));
    ASSERT_EQ(123654, x);
    ASSERT_TRUE(Int32::TryParse("-1", x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int32::TryParse("-100", x));
    ASSERT_EQ(-100, x);
    ASSERT_TRUE(Int32::TryParse("-98744", x));
    ASSERT_EQ(-98744, x);
  }
  
  
  TEST(Int32Test, TryParse_Leading_Zeros) {
    int32 x;
    ASSERT_TRUE(Int32::TryParse("0", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int32::TryParse("00", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int32::TryParse("000", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int32::TryParse("01", x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int32::TryParse("0001", x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int32::TryParse("099", x));
    ASSERT_EQ(99, x);
    ASSERT_TRUE(Int32::TryParse("0000999", x));
    ASSERT_EQ(999, x);
  }
  
  TEST(Int32Test, TryParse_Leading_Zeros_Int32) {
    Int32 x;
    ASSERT_TRUE(Int32::TryParse("0", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int32::TryParse("00", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int32::TryParse("000", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int32::TryParse("01", x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int32::TryParse("0001", x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int32::TryParse("099", x));
    ASSERT_EQ(99, x);
    ASSERT_TRUE(Int32::TryParse("0000999", x));
    ASSERT_EQ(999, x);
  }
  
  TEST(Int32Test, TryParse_Spaces) {
    int32 x;
    ASSERT_TRUE(Int32::TryParse(" 5", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int32::TryParse("     5", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int32::TryParse("5 ", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int32::TryParse("51     ", x));
    ASSERT_EQ(51, x);
    ASSERT_TRUE(Int32::TryParse(" 5      ", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int32::TryParse("        +52 ", x));
    ASSERT_EQ(52, x);
    ASSERT_TRUE(Int32::TryParse("        +052 ", x));
    ASSERT_EQ(52, x);
    ASSERT_TRUE(Int32::TryParse("        -52 ", x));
    ASSERT_EQ(-52, x);
  }
  
  TEST(Int32Test, TryParse_Spaces_Int32) {
    Int32 x;
    ASSERT_TRUE(Int32::TryParse(" 5", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int32::TryParse("     5", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int32::TryParse("5 ", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int32::TryParse("51     ", x));
    ASSERT_EQ(51, x);
    ASSERT_TRUE(Int32::TryParse(" 5      ", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int32::TryParse("        +52 ", x));
    ASSERT_EQ(52, x);
    ASSERT_TRUE(Int32::TryParse("        +052 ", x));
    ASSERT_EQ(52, x);
    ASSERT_TRUE(Int32::TryParse("        -52 ", x));
    ASSERT_EQ(-52, x);
  }
  
  TEST(Int32Test, TryParse_FormatException) {
    int32 x;
    ASSERT_FALSE(Int32::TryParse("", x));
    ASSERT_FALSE(Int32::TryParse("a56", x));
    ASSERT_FALSE(Int32::TryParse("0 0", x));
    ASSERT_FALSE(Int32::TryParse("++000", x));
    ASSERT_FALSE(Int32::TryParse("+", x));
    ASSERT_FALSE(Int32::TryParse("-", x));
    ASSERT_FALSE(Int32::TryParse("--5", x));
    ASSERT_FALSE(Int32::TryParse("0x53", x));
    ASSERT_FALSE(Int32::TryParse("100a", x));
    ASSERT_FALSE(Int32::TryParse("10u", x));
  }
  
  TEST(Int32Test, TryParse_FormatException_Int32) {
    Int32 x;
    ASSERT_FALSE(Int32::TryParse("", x));
    ASSERT_FALSE(Int32::TryParse("a56", x));
    ASSERT_FALSE(Int32::TryParse("0 0", x));
    ASSERT_FALSE(Int32::TryParse("++000", x));
    ASSERT_FALSE(Int32::TryParse("+", x));
    ASSERT_FALSE(Int32::TryParse("-", x));
    ASSERT_FALSE(Int32::TryParse("--5", x));
    ASSERT_FALSE(Int32::TryParse("0x53", x));
    ASSERT_FALSE(Int32::TryParse("100a", x));
    ASSERT_FALSE(Int32::TryParse("10u", x));
  }
  
  TEST(Int32Test, TryParse_OverFlowException) {
    int32 x;
    ASSERT_TRUE(Int32::TryParse("2147483647", x));
    ASSERT_EQ(Int32::MaxValue, x);
    ASSERT_FALSE(Int32::TryParse("2147483648", x));
    ASSERT_TRUE(Int32::TryParse("-2147483648", x));
    ASSERT_EQ(Int32::MinValue, x);
    ASSERT_FALSE(Int32::TryParse("-2147483649", x));
    ASSERT_FALSE(Int32::TryParse("4294967296", x));
    ASSERT_FALSE(Int32::TryParse("5294967295", x));
  }
  
  TEST(Int32Test, TryParse_OverFlowException_Int32) {
    Int32 x;
    ASSERT_TRUE(Int32::TryParse("2147483647", x));
    ASSERT_EQ(Int32::MaxValue, x);
    ASSERT_FALSE(Int32::TryParse("2147483648", x));
    ASSERT_TRUE(Int32::TryParse("-2147483648", x));
    ASSERT_EQ(Int32::MinValue, x);
    ASSERT_FALSE(Int32::TryParse("-2147483649", x));
    ASSERT_FALSE(Int32::TryParse("4294967296", x));
    ASSERT_FALSE(Int32::TryParse("5294967295", x));
  }
  
  TEST(Int32Test, TryParse_Binary) {
    int32 x;
    ASSERT_TRUE(Int32::TryParse("0", 2, x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int32::TryParse("1", 2, x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int32::TryParse("10", 2, x));
    ASSERT_EQ(2, x);
    ASSERT_TRUE(Int32::TryParse("11", 2, x));
    ASSERT_EQ(3, x);
    ASSERT_TRUE(Int32::TryParse("110", 2, x));
    ASSERT_EQ(6, x);
    ASSERT_TRUE(Int32::TryParse("-1", 2, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int32::TryParse("-100", 2, x));
    ASSERT_EQ(-4, x);
    ASSERT_TRUE(Int32::TryParse("-1111", 2, x));
    ASSERT_EQ(-15, x);
  }
  
  TEST(Int32Test, TryParse_Binary_Int32) {
    Int32 x;
    ASSERT_TRUE(Int32::TryParse("0", 2, x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int32::TryParse("1", 2, x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int32::TryParse("10", 2, x));
    ASSERT_EQ(2, x);
    ASSERT_TRUE(Int32::TryParse("11", 2, x));
    ASSERT_EQ(3, x);
    ASSERT_TRUE(Int32::TryParse("110", 2, x));
    ASSERT_EQ(6, x);
    ASSERT_TRUE(Int32::TryParse("-1", 2, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int32::TryParse("-100", 2, x));
    ASSERT_EQ(-4, x);
    ASSERT_TRUE(Int32::TryParse("-1111", 2, x));
    ASSERT_EQ(-15, x);
  }
  
  TEST(Int32Test, TryParse_Binary_Complement) {
    int32 x;
    ASSERT_TRUE(Int32::TryParse("11111111111111111111111111111111", 2, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int32::TryParse("10000000000000000000000000000000", 2, x));
    ASSERT_EQ(Int32::MinValue, x);
    ASSERT_TRUE(Int32::TryParse("11111111111110111000001100010001", 2, x));
    ASSERT_EQ(-294127, x);
    ASSERT_TRUE(Int32::TryParse("11111111110010110101001100101001", 2, x));
    ASSERT_EQ(-3452119, x);
    ASSERT_TRUE(Int32::TryParse("10001000000110110100101011010101", 2, x));
    ASSERT_EQ(-2011477291, x);
    ASSERT_TRUE(Int32::TryParse("-10000000000000000000000000000000", 2, x));
    ASSERT_EQ(Int32::MinValue, x);
  }
  
  TEST(Int32Test, TryParse_Binary_Complement_Int32) {
    Int32 x;
    ASSERT_TRUE(Int32::TryParse("11111111111111111111111111111111", 2, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int32::TryParse("10000000000000000000000000000000", 2, x));
    ASSERT_EQ(Int32::MinValue, x);
    ASSERT_TRUE(Int32::TryParse("11111111111110111000001100010001", 2, x));
    ASSERT_EQ(-294127, x);
    ASSERT_TRUE(Int32::TryParse("11111111110010110101001100101001", 2, x));
    ASSERT_EQ(-3452119, x);
    ASSERT_TRUE(Int32::TryParse("10001000000110110100101011010101", 2, x));
    ASSERT_EQ(-2011477291, x);
    ASSERT_TRUE(Int32::TryParse("-10000000000000000000000000000000", 2, x));
    ASSERT_EQ(Int32::MinValue, x);
  }
  
  TEST(Int32Test, TryParse_Binary_Complement_Overflow) {
    int32 x;
    ASSERT_FALSE(Int32::TryParse("-11111111111111111111111111111111", 2, x));
    ASSERT_FALSE(Int32::TryParse("-10000000000000000000000000000001", 2, x));
  }
  
  TEST(Int32Test, TryParse_Binary_Complement_Overflow_Int32) {
    Int32 x;
    ASSERT_FALSE(Int32::TryParse("-11111111111111111111111111111111", 2, x));
    ASSERT_FALSE(Int32::TryParse("-10000000000000000000000000000001", 2, x));
  }
  
  TEST(Int32Test, TryParse_Exceptions_Binary) {
    int32 x;
    ASSERT_FALSE(Int32::TryParse("", 2, x));
    ASSERT_FALSE(Int32::TryParse("2", 2, x));
    ASSERT_FALSE(Int32::TryParse("103", 2, x));
    ASSERT_FALSE(Int32::TryParse("++0", 2, x));
    ASSERT_FALSE(Int32::TryParse("+", 2, x));
    ASSERT_FALSE(Int32::TryParse("-", 2, x));
    ASSERT_FALSE(Int32::TryParse("--1", 2, x));
    ASSERT_FALSE(Int32::TryParse("0x53", 2, x));
    ASSERT_FALSE(Int32::TryParse("100a", 2, x));
    ASSERT_FALSE(Int32::TryParse("10u", 2, x));
  }
  
  TEST(Int32Test, TryParse_Exceptions_Binary_Int32) {
    Int32 x;
    ASSERT_FALSE(Int32::TryParse("", 2, x));
    ASSERT_FALSE(Int32::TryParse("2", 2, x));
    ASSERT_FALSE(Int32::TryParse("103", 2, x));
    ASSERT_FALSE(Int32::TryParse("++0", 2, x));
    ASSERT_FALSE(Int32::TryParse("+", 2, x));
    ASSERT_FALSE(Int32::TryParse("-", 2, x));
    ASSERT_FALSE(Int32::TryParse("--1", 2, x));
    ASSERT_FALSE(Int32::TryParse("0x53", 2, x));
    ASSERT_FALSE(Int32::TryParse("100a", 2, x));
    ASSERT_FALSE(Int32::TryParse("10u", 2, x));
  }
  
  TEST(Int32Test, TryParse_Octal) {
    int32 x;
    ASSERT_TRUE(Int32::TryParse("0", 8, x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int32::TryParse("1", 8, x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int32::TryParse("14", 8, x));
    ASSERT_EQ(12, x);
    ASSERT_TRUE(Int32::TryParse("70", 8, x));
    ASSERT_EQ(56, x);
    ASSERT_TRUE(Int32::TryParse("1131", 8, x));
    ASSERT_EQ(601, x);
    ASSERT_TRUE(Int32::TryParse("-1", 8, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int32::TryParse("-4", 8, x));
    ASSERT_EQ(-4, x);
    ASSERT_TRUE(Int32::TryParse("-17", 8, x));
    ASSERT_EQ(-15, x);
  }
  
  TEST(Int32Test, TryParse_Octal_Int32) {
    Int32 x;
    ASSERT_TRUE(Int32::TryParse("0", 8, x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int32::TryParse("1", 8, x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int32::TryParse("14", 8, x));
    ASSERT_EQ(12, x);
    ASSERT_TRUE(Int32::TryParse("70", 8, x));
    ASSERT_EQ(56, x);
    ASSERT_TRUE(Int32::TryParse("1131", 8, x));
    ASSERT_EQ(601, x);
    ASSERT_TRUE(Int32::TryParse("-1", 8, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int32::TryParse("-4", 8, x));
    ASSERT_EQ(-4, x);
    ASSERT_TRUE(Int32::TryParse("-17", 8, x));
    ASSERT_EQ(-15, x);
  }
  
  TEST(Int32Test, TryParse_Hexadecimal) {
    int32 x;
    ASSERT_TRUE(Int32::TryParse("0", 16, x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int32::TryParse("1", 16, x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int32::TryParse("C", 16, x));
    ASSERT_EQ(12, x);
    ASSERT_TRUE(Int32::TryParse("3c", 16, x));
    ASSERT_EQ(60, x);
    ASSERT_TRUE(Int32::TryParse("FE3", 16, x));
    ASSERT_EQ(0xFE3, x);
    ASSERT_TRUE(Int32::TryParse("-4A", 16, x));
    ASSERT_EQ(-0x4A, x);
    ASSERT_TRUE(Int32::TryParse("-ABCDE", 16, x));
    ASSERT_EQ(-0xABCDE, x);
  }
  
  TEST(Int32Test, TryParse_Hexadecimal_Int32) {
    Int32 x;
    ASSERT_TRUE(Int32::TryParse("0", 16, x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int32::TryParse("1", 16, x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int32::TryParse("C", 16, x));
    ASSERT_EQ(12, x);
    ASSERT_TRUE(Int32::TryParse("3c", 16, x));
    ASSERT_EQ(60, x);
    ASSERT_TRUE(Int32::TryParse("FE3", 16, x));
    ASSERT_EQ(0xFE3, x);
    ASSERT_TRUE(Int32::TryParse("-4A", 16, x));
    ASSERT_EQ(-0x4A, x);
    ASSERT_TRUE(Int32::TryParse("-ABCDE", 16, x));
    ASSERT_EQ(-0xABCDE, x);
  }
  
  TEST(Int32Test, TryParse_Hexadecimal_Complement) {
    int32 x;
    ASSERT_TRUE(Int32::TryParse("FFFFFFFF", 16, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int32::TryParse("80000000", 16, x));
    ASSERT_EQ(Int32::MinValue, x);
    ASSERT_TRUE(Int32::TryParse("-80000000", 16, x));
    ASSERT_EQ(Int32::MinValue, x);
    ASSERT_TRUE(Int32::TryParse("FFFFEAAD", 16, x));
    ASSERT_EQ(-5459, x);
    ASSERT_TRUE(Int32::TryParse("FFF7AB81", 16, x));
    ASSERT_EQ(-545919, x);
  }
  
  TEST(Int32Test, TryParse_Hexadecimal_Complement_Int32) {
    Int32 x;
    ASSERT_TRUE(Int32::TryParse("FFFFFFFF", 16, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int32::TryParse("80000000", 16, x));
    ASSERT_EQ(Int32::MinValue, x);
    ASSERT_TRUE(Int32::TryParse("-80000000", 16, x));
    ASSERT_EQ(Int32::MinValue, x);
    ASSERT_TRUE(Int32::TryParse("FFFFEAAD", 16, x));
    ASSERT_EQ(-5459, x);
    ASSERT_TRUE(Int32::TryParse("FFF7AB81", 16, x));
    ASSERT_EQ(-545919, x);
  }
  
  TEST(Int32Test, TryParse_Hexadecimal_Complement_Overflow) {
    int32 x;
    ASSERT_FALSE(Int32::TryParse("-FFFFFFFF", 16, x));
    ASSERT_FALSE(Int32::TryParse("-80000001", 16, x));
  }
  
  TEST(Int32Test, TryParse_Hexadecimal_Complement_Overflow_Int32) {
    Int32 x;
    ASSERT_FALSE(Int32::TryParse("-FFFFFFFF", 16, x));
    ASSERT_FALSE(Int32::TryParse("-80000001", 16, x));
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
        MakeTest<Int32>(s, 5, "");

      Console.ReadKey(true);
    }

    static void MakeTest<T>(String s, T prototype, String fmt) {
      String type = _typeof(T).Name;
      String suffix = type == "Single" ? "f" : "";

      try {
        MethodInfo method = _typeof(T).GetMethod("Parse", new Type[] {_typeof(String)});
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

