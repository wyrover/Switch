#include <Switch/System/Int64.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/FormatException.hpp>
#include <Switch/System/OverflowException.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(Int64Test, MaxValue) {
    ASSERT_EQ(0x7FFFFFFFFFFFFFFFll, Int64::MaxValue);
  }
  
  TEST(Int64Test, MinValue) {
    ASSERT_EQ((int64) - 0x8000000000000000ll, Int64::MinValue); //  VS2012 does not handle -2147483648 correctly
  }
  
  TEST(Int64Test, DefaultValue) {
    ASSERT_EQ(0LL, Int64());
  }
  
  TEST(Int64Test, CtorValue) {
    ASSERT_EQ(10, Int64(10));
    ASSERT_EQ(123654, Int64(123654));
    ASSERT_EQ(0, Int64(0));
    ASSERT_EQ(-1, Int64(-1));
    ASSERT_EQ(-0x7050123654LL, Int64(-0x7050123654LL));
  }
  
  TEST(Int64Test, Parse) {
    ASSERT_EQ(0, Int64::Parse("0"));
    ASSERT_EQ(1, Int64::Parse("1"));
    ASSERT_EQ(123, Int64::Parse("123"));
    ASSERT_EQ(9123654999LL, Int64::Parse("9123654999"));
    ASSERT_EQ(-1, Int64::Parse("-1"));
    ASSERT_EQ(-100, Int64::Parse("-100"));
    ASSERT_EQ(-9981235744, Int64::Parse("-9981235744"));
  }
  
  TEST(Int64Test, Parse_Leading_Zeros) {
    ASSERT_EQ(0, Int64::Parse("0"));
    ASSERT_EQ(0, Int64::Parse("00"));
    ASSERT_EQ(0, Int64::Parse("000"));
    ASSERT_EQ(1, Int64::Parse("01"));
    ASSERT_EQ(1, Int64::Parse("0001"));
    ASSERT_EQ(99, Int64::Parse("099"));
    ASSERT_EQ(999, Int64::Parse("0000999"));
  }
  
  TEST(Int64Test, Parse_Spaces) {
    ASSERT_EQ(5, Int64::Parse(" 5"));
    ASSERT_EQ(5, Int64::Parse("     5"));
    ASSERT_EQ(5, Int64::Parse("5 "));
    ASSERT_EQ(51, Int64::Parse("51     "));
    ASSERT_EQ(5, Int64::Parse(" 5      "));
    ASSERT_EQ(52, Int64::Parse("        52 "));
  }
  
  TEST(Int64Test, Parse_FormatException) {
    ASSERT_THROW(Int64::Parse(""), FormatException);
    ASSERT_THROW(Int64::Parse("a56"), FormatException);
    ASSERT_THROW(Int64::Parse("0 0"), FormatException);
    ASSERT_THROW(Int64::Parse("++000"), FormatException);
    ASSERT_THROW(Int64::Parse("+"), FormatException);
    ASSERT_THROW(Int64::Parse("-"), FormatException);
    ASSERT_THROW(Int64::Parse("--5"), FormatException);
    ASSERT_THROW(Int64::Parse("0x53"), FormatException);
    ASSERT_THROW(Int64::Parse("100a"), FormatException);
    ASSERT_THROW(Int64::Parse("10u"), FormatException);
  }
  
  TEST(Int64Test, Parse_OverFlowException) { //    987654321.987654321
    ASSERT_EQ(Int64::MaxValue, Int64::Parse("9223372036854775807"));
    ASSERT_THROW(Int64::Parse("9223372036854775808"), OverflowException);
    ASSERT_EQ(Int64::MinValue, Int64::Parse("-9223372036854775808"));
    ASSERT_THROW(Int64::Parse("-9223372036854775809"), OverflowException);
    ASSERT_THROW(Int64::Parse("19223372036854775807"), OverflowException);
    ASSERT_THROW(Int64::Parse("9876549223372036854775807"), OverflowException);
  }
  
  TEST(Int64Test, Parse_Binary) {
    ASSERT_EQ(0, Int64::Parse("0", 2));
    ASSERT_EQ(1, Int64::Parse("1", 2));
    ASSERT_EQ(2, Int64::Parse("10", 2));
    ASSERT_EQ(3, Int64::Parse("11", 2));
    ASSERT_EQ(6, Int64::Parse("110", 2));
    ASSERT_EQ(-1, Int64::Parse("-1", 2));
    ASSERT_EQ(-4, Int64::Parse("-100", 2));
    ASSERT_EQ(-15, Int64::Parse("-1111", 2));
  }
  
  TEST(Int64Test, Parse_Binary_Complement) {
    ASSERT_EQ(-1, Int64::Parse("1111111111111111111111111111111111111111111111111111111111111111", 2));
    ASSERT_EQ(Int64::MinValue, Int64::Parse("1000000000000000000000000000000000000000000000000000000000000000", 2));
    ASSERT_EQ(Int64::MinValue, Int64::Parse("-1000000000000000000000000000000000000000000000000000000000000000", 2));
    ASSERT_EQ(-852147, Int64::Parse("1111111111111111111111111111111111111111111100101111111101001101", 2));
  }
  
  TEST(Int64Test, Parse_Binary_Complement_Overflow) {
    ASSERT_THROW(Int64::Parse("-1111111111111111111111111111111111111111111111111111111111111111", 2), OverflowException);
    ASSERT_THROW(Int64::Parse("10000000000000000000000000000000000000000000000000000000000000000", 2), OverflowException);
    ASSERT_THROW(Int64::Parse("-1000000000000000000000000000000000000000000000000000000000000001", 2), OverflowException);
  }
  
  
  TEST(Int64Test, Parse_Exceptions_Binary) {
    ASSERT_THROW(Int64::Parse("", 2), FormatException);
    ASSERT_THROW(Int64::Parse("2", 2), FormatException);
    ASSERT_THROW(Int64::Parse("103", 2), FormatException);
    ASSERT_THROW(Int64::Parse("++0", 2), FormatException);
    ASSERT_THROW(Int64::Parse("+", 2), FormatException);
    ASSERT_THROW(Int64::Parse("-", 2), FormatException);
    ASSERT_THROW(Int64::Parse("--1", 2), FormatException);
    ASSERT_THROW(Int64::Parse("0x53", 2), FormatException);
    ASSERT_THROW(Int64::Parse("100a", 2), FormatException);
    ASSERT_THROW(Int64::Parse("10u", 2), FormatException);
  }
  
  TEST(Int64Test, Parse_Octal) {
    ASSERT_EQ(0, Int64::Parse("0", 8));
    ASSERT_EQ(1, Int64::Parse("1", 8));
    ASSERT_EQ(12, Int64::Parse("14", 8));
    ASSERT_EQ(56, Int64::Parse("70", 8));
    ASSERT_EQ(601, Int64::Parse("1131", 8));
    ASSERT_EQ(-1, Int64::Parse("-1", 8));
    ASSERT_EQ(-4, Int64::Parse("-4", 8));
    ASSERT_EQ(-15, Int64::Parse("-17", 8));
  }
  
  TEST(Int64Test, Parse_Hexadecimal) {
    ASSERT_EQ(0, Int64::Parse("0", 16));
    ASSERT_EQ(1, Int64::Parse("1", 16));
    ASSERT_EQ(0xC, Int64::Parse("C", 16));
    ASSERT_EQ(0x3C, Int64::Parse("3c", 16));
    ASSERT_EQ(0xFE3, Int64::Parse("FE3", 16));
    ASSERT_EQ(-0x4A, Int64::Parse("-4A", 16));
    ASSERT_EQ(-0xABCDE, Int64::Parse("-ABCDE", 16));
    ASSERT_EQ(-0xDEADBEEFDEADLL, Int64::Parse("-DeadBeefDead", 16));
    ASSERT_EQ(Int64::MinValue, Int64::Parse("-8000000000000000", 16));
    ASSERT_EQ(Int64::MaxValue, Int64::Parse("7FFFFFFFFFFFFFFF", 16));
    ASSERT_THROW(Int64::Parse("-08000000000000001", 16), OverflowException);
  }
  
  TEST(Int64Test, Parse_Hexadecimal_Complement) {
    ASSERT_EQ(-1, Int64::Parse("0xFFFFFFFFFFFFFFFF", 16));
    ASSERT_EQ(Int64::MinValue, Int64::Parse("0x8000000000000000", 16));
    ASSERT_EQ(Int64::MinValue, Int64::Parse("-0x8000000000000000", 16));
    ASSERT_EQ(-89147, Int64::Parse("FFFFFFFFFFFEA3C5", 16));
  }
  
  TEST(Int64Test, TryParse) {
    int64 x;
    ASSERT_TRUE(Int64::TryParse("0", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int64::TryParse("1", x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int64::TryParse("123", x));
    ASSERT_EQ(123, x);
    ASSERT_TRUE(Int64::TryParse("9123654999", x));
    ASSERT_EQ(9123654999LL, x);
    ASSERT_TRUE(Int64::TryParse("-1", x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int64::TryParse("-100", x));
    ASSERT_EQ(-100, x);
    ASSERT_TRUE(Int64::TryParse("-9981235744", x));
    ASSERT_EQ(-9981235744, x);
  }
  
  TEST(Int64Test, TryParse_Int64) {
    Int64 x;
    ASSERT_TRUE(Int64::TryParse("0", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int64::TryParse("1", x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int64::TryParse("123", x));
    ASSERT_EQ(123, x);
    ASSERT_TRUE(Int64::TryParse("9123654999", x));
    ASSERT_EQ(9123654999LL, x);
    ASSERT_TRUE(Int64::TryParse("-1", x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int64::TryParse("-100", x));
    ASSERT_EQ(-100, x);
    ASSERT_TRUE(Int64::TryParse("-9981235744", x));
    ASSERT_EQ(-9981235744LL, x);
  }
  
  TEST(Int64Test, TryParse_Leading_Zeros) {
    int64 x;
    ASSERT_TRUE(Int64::TryParse("0", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int64::TryParse("00", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int64::TryParse("000", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int64::TryParse("01", x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int64::TryParse("0001", x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int64::TryParse("099", x));
    ASSERT_EQ(99, x);
    ASSERT_TRUE(Int64::TryParse("0000999", x));
    ASSERT_EQ(999, x);
  }
  
  TEST(Int64Test, TryParse_Leading_Zeros_Int64) {
    Int64 x;
    ASSERT_TRUE(Int64::TryParse("0", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int64::TryParse("00", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int64::TryParse("000", x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int64::TryParse("01", x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int64::TryParse("0001", x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int64::TryParse("099", x));
    ASSERT_EQ(99, x);
    ASSERT_TRUE(Int64::TryParse("0000999", x));
    ASSERT_EQ(999, x);
  }
  
  TEST(Int64Test, TryParse_Spaces) {
    int64 x;
    ASSERT_TRUE(Int64::TryParse(" 5", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int64::TryParse("     5", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int64::TryParse("5 ", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int64::TryParse("51     ", x));
    ASSERT_EQ(51, x);
    ASSERT_TRUE(Int64::TryParse(" 5      ", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int64::TryParse("        52 ", x));
    ASSERT_EQ(52, x);
  }
  
  TEST(Int64Test, TryParse_Spaces_Int64) {
    Int64 x;
    ASSERT_TRUE(Int64::TryParse(" 5", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int64::TryParse("     5", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int64::TryParse("5 ", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int64::TryParse("51     ", x));
    ASSERT_EQ(51, x);
    ASSERT_TRUE(Int64::TryParse(" 5      ", x));
    ASSERT_EQ(5, x);
    ASSERT_TRUE(Int64::TryParse("        52 ", x));
    ASSERT_EQ(52, x);
  }
  
  TEST(Int64Test, TryParse_FormatException) {
    int64 x;
    ASSERT_FALSE(Int64::TryParse("", x));
    ASSERT_FALSE(Int64::TryParse("a56", x));
    ASSERT_FALSE(Int64::TryParse("0 0", x));
    ASSERT_FALSE(Int64::TryParse("++000", x));
    ASSERT_FALSE(Int64::TryParse("+", x));
    ASSERT_FALSE(Int64::TryParse("-", x));
    ASSERT_FALSE(Int64::TryParse("--5", x));
    ASSERT_FALSE(Int64::TryParse("0x53", x));
    ASSERT_FALSE(Int64::TryParse("100a", x));
    ASSERT_FALSE(Int64::TryParse("10u", x));
  }
  
  TEST(Int64Test, TryParse_FormatException_Int64) {
    Int64 x;
    ASSERT_FALSE(Int64::TryParse("", x));
    ASSERT_FALSE(Int64::TryParse("a56", x));
    ASSERT_FALSE(Int64::TryParse("0 0", x));
    ASSERT_FALSE(Int64::TryParse("++000", x));
    ASSERT_FALSE(Int64::TryParse("+", x));
    ASSERT_FALSE(Int64::TryParse("-", x));
    ASSERT_FALSE(Int64::TryParse("--5", x));
    ASSERT_FALSE(Int64::TryParse("0x53", x));
    ASSERT_FALSE(Int64::TryParse("100a", x));
    ASSERT_FALSE(Int64::TryParse("10u", x));
  }
  
  TEST(Int64Test, TryParse_OverFlowException) { //    987654321.987654321
    int64 x;
    ASSERT_TRUE(Int64::TryParse("9223372036854775807", x));
    ASSERT_EQ(Int64::MaxValue, x);
    ASSERT_FALSE(Int64::TryParse("9223372036854775808", x));
    ASSERT_TRUE(Int64::TryParse("-9223372036854775808", x));
    ASSERT_EQ(Int64::MinValue, x);
    ASSERT_FALSE(Int64::TryParse("-9223372036854775809", x));
    ASSERT_FALSE(Int64::TryParse("19223372036854775807", x));
    ASSERT_FALSE(Int64::TryParse("9876549223372036854775807", x));
  }
  
  TEST(Int64Test, TryParse_OverFlowException_Int64) { //    987654321.987654321
    Int64 x;
    ASSERT_TRUE(Int64::TryParse("9223372036854775807", x));
    ASSERT_EQ(Int64::MaxValue, x);
    ASSERT_FALSE(Int64::TryParse("9223372036854775808", x));
    ASSERT_TRUE(Int64::TryParse("-9223372036854775808", x));
    ASSERT_EQ(Int64::MinValue, x);
    ASSERT_FALSE(Int64::TryParse("-9223372036854775809", x));
    ASSERT_FALSE(Int64::TryParse("19223372036854775807", x));
    ASSERT_FALSE(Int64::TryParse("9876549223372036854775807", x));
  }
  
  TEST(Int64Test, TryParse_Binary) {
    int64 x;
    ASSERT_TRUE(Int64::TryParse("0", 2, x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int64::TryParse("1", 2, x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int64::TryParse("10", 2, x));
    ASSERT_EQ(2, x);
    ASSERT_TRUE(Int64::TryParse("11", 2, x));
    ASSERT_EQ(3, x);
    ASSERT_TRUE(Int64::TryParse("110", 2, x));
    ASSERT_EQ(6, x);
    ASSERT_TRUE(Int64::TryParse("-1", 2, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int64::TryParse("-100", 2, x));
    ASSERT_EQ(-4, x);
    ASSERT_TRUE(Int64::TryParse("-1111", 2, x));
    ASSERT_EQ(-15, x);
  }
  
  TEST(Int64Test, TryParse_Binary_Int64) {
    Int64 x;
    ASSERT_TRUE(Int64::TryParse("0", 2, x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int64::TryParse("1", 2, x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int64::TryParse("10", 2, x));
    ASSERT_EQ(2, x);
    ASSERT_TRUE(Int64::TryParse("11", 2, x));
    ASSERT_EQ(3, x);
    ASSERT_TRUE(Int64::TryParse("110", 2, x));
    ASSERT_EQ(6, x);
    ASSERT_TRUE(Int64::TryParse("-1", 2, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int64::TryParse("-100", 2, x));
    ASSERT_EQ(-4, x);
    ASSERT_TRUE(Int64::TryParse("-1111", 2, x));
    ASSERT_EQ(-15, x);
  }
  
  TEST(Int64Test, TryParse_Binary_Complement) {
    int64 x;
    ASSERT_TRUE(Int64::TryParse("1111111111111111111111111111111111111111111111111111111111111111", 2, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int64::TryParse("1000000000000000000000000000000000000000000000000000000000000000", 2, x));
    ASSERT_EQ(Int64::MinValue, x);
    ASSERT_TRUE(Int64::TryParse("-1000000000000000000000000000000000000000000000000000000000000000", 2, x));
    ASSERT_EQ(Int64::MinValue, x);
    ASSERT_TRUE(Int64::TryParse("1111111111111111111111111111111111111111111100101111111101001101", 2, x));
    ASSERT_EQ(-852147, x);
  }
  
  TEST(Int64Test, TryParse_Binary_Complement_Int64) {
    Int64 x;
    ASSERT_TRUE(Int64::TryParse("1111111111111111111111111111111111111111111111111111111111111111", 2, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int64::TryParse("1000000000000000000000000000000000000000000000000000000000000000", 2, x));
    ASSERT_EQ(Int64::MinValue, x);
    ASSERT_TRUE(Int64::TryParse("-1000000000000000000000000000000000000000000000000000000000000000", 2, x));
    ASSERT_EQ(Int64::MinValue, x);
    ASSERT_TRUE(Int64::TryParse("1111111111111111111111111111111111111111111100101111111101001101", 2, x));
    ASSERT_EQ(-852147, x);
  }
  
  TEST(Int64Test, TryParse_Binary_Complement_Overflow) {
    int64 x;
    ASSERT_FALSE(Int64::TryParse("-1111111111111111111111111111111111111111111111111111111111111111", 2, x));
    ASSERT_FALSE(Int64::TryParse("10000000000000000000000000000000000000000000000000000000000000000", 2, x));
    ASSERT_FALSE(Int64::TryParse("-1000000000000000000000000000000000000000000000000000000000000001", 2, x));
  }
  
  TEST(Int64Test, TryParse_Binary_Complement_Overflow_Int64) {
    Int64 x;
    ASSERT_FALSE(Int64::TryParse("-1111111111111111111111111111111111111111111111111111111111111111", 2, x));
    ASSERT_FALSE(Int64::TryParse("10000000000000000000000000000000000000000000000000000000000000000", 2, x));
    ASSERT_FALSE(Int64::TryParse("-1000000000000000000000000000000000000000000000000000000000000001", 2, x));
  }
  
  TEST(Int64Test, TryParse_Exceptions_Binary) {
    int64 x;
    ASSERT_FALSE(Int64::TryParse("", 2, x));
    ASSERT_FALSE(Int64::TryParse("2", 2, x));
    ASSERT_FALSE(Int64::TryParse("103", 2, x));
    ASSERT_FALSE(Int64::TryParse("++0", 2, x));
    ASSERT_FALSE(Int64::TryParse("+", 2, x));
    ASSERT_FALSE(Int64::TryParse("-", 2, x));
    ASSERT_FALSE(Int64::TryParse("--1", 2, x));
    ASSERT_FALSE(Int64::TryParse("0x53", 2, x));
    ASSERT_FALSE(Int64::TryParse("100a", 2, x));
    ASSERT_FALSE(Int64::TryParse("10u", 2, x));
  }
  
  TEST(Int64Test, TryParse_Exceptions_Binary_Int64) {
    Int64 x;
    ASSERT_FALSE(Int64::TryParse("", 2, x));
    ASSERT_FALSE(Int64::TryParse("2", 2, x));
    ASSERT_FALSE(Int64::TryParse("103", 2, x));
    ASSERT_FALSE(Int64::TryParse("++0", 2, x));
    ASSERT_FALSE(Int64::TryParse("+", 2, x));
    ASSERT_FALSE(Int64::TryParse("-", 2, x));
    ASSERT_FALSE(Int64::TryParse("--1", 2, x));
    ASSERT_FALSE(Int64::TryParse("0x53", 2, x));
    ASSERT_FALSE(Int64::TryParse("100a", 2, x));
    ASSERT_FALSE(Int64::TryParse("10u", 2, x));
  }
  
  TEST(Int64Test, TryParse_Octal) {
    int64 x;
    ASSERT_TRUE(Int64::TryParse("0", 8, x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int64::TryParse("1", 8, x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int64::TryParse("14", 8, x));
    ASSERT_EQ(12, x);
    ASSERT_TRUE(Int64::TryParse("70", 8, x));
    ASSERT_EQ(56, x);
    ASSERT_TRUE(Int64::TryParse("1131", 8, x));
    ASSERT_EQ(601, x);
    ASSERT_TRUE(Int64::TryParse("-1", 8, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int64::TryParse("-4", 8, x));
    ASSERT_EQ(-4, x);
    ASSERT_TRUE(Int64::TryParse("-17", 8, x));
    ASSERT_EQ(-15, x);
  }
  
  TEST(Int64Test, TryParse_Octal_Int64) {
    Int64 x;
    ASSERT_TRUE(Int64::TryParse("0", 8, x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int64::TryParse("1", 8, x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int64::TryParse("14", 8, x));
    ASSERT_EQ(12, x);
    ASSERT_TRUE(Int64::TryParse("70", 8, x));
    ASSERT_EQ(56, x);
    ASSERT_TRUE(Int64::TryParse("1131", 8, x));
    ASSERT_EQ(601, x);
    ASSERT_TRUE(Int64::TryParse("-1", 8, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int64::TryParse("-4", 8, x));
    ASSERT_EQ(-4, x);
    ASSERT_TRUE(Int64::TryParse("-17", 8, x));
    ASSERT_EQ(-15, x);
  }
  
  TEST(Int64Test, TryParse_Hexadecimal) {
    int64 x;
    ASSERT_TRUE(Int64::TryParse("0", 16, x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int64::TryParse("1", 16, x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int64::TryParse("C", 16, x));
    ASSERT_EQ(0xC, x);
    ASSERT_TRUE(Int64::TryParse("3c", 16, x));
    ASSERT_EQ(0x3C, x);
    ASSERT_TRUE(Int64::TryParse("FE3", 16, x));
    ASSERT_EQ(0xFE3, x);
    ASSERT_TRUE(Int64::TryParse("-4A", 16, x));
    ASSERT_EQ(-0x4A, x);
    ASSERT_TRUE(Int64::TryParse("-ABCDE", 16, x));
    ASSERT_EQ(-0xABCDE, x);
    ASSERT_TRUE(Int64::TryParse("-DeadBeefDead", 16, x));
    ASSERT_EQ(-0xDEADBEEFDEADLL, x);
    ASSERT_TRUE(Int64::TryParse("-8000000000000000", 16, x));
    ASSERT_EQ(Int64::MinValue, x);
    ASSERT_TRUE(Int64::TryParse("7FFFFFFFFFFFFFFF", 16, x));
    ASSERT_EQ(Int64::MaxValue, x);
    ASSERT_FALSE(Int64::TryParse("-08000000000000001", 16, x));
  }
  
  TEST(Int64Test, TryParse_Hexadecimal_Int64) {
    Int64 x;
    ASSERT_TRUE(Int64::TryParse("0", 16, x));
    ASSERT_EQ(0, x);
    ASSERT_TRUE(Int64::TryParse("1", 16, x));
    ASSERT_EQ(1, x);
    ASSERT_TRUE(Int64::TryParse("C", 16, x));
    ASSERT_EQ(0xC, x);
    ASSERT_TRUE(Int64::TryParse("3c", 16, x));
    ASSERT_EQ(0x3C, x);
    ASSERT_TRUE(Int64::TryParse("FE3", 16, x));
    ASSERT_EQ(0xFE3, x);
    ASSERT_TRUE(Int64::TryParse("-4A", 16, x));
    ASSERT_EQ(-0x4A, x);
    ASSERT_TRUE(Int64::TryParse("-ABCDE", 16, x));
    ASSERT_EQ(-0xABCDE, x);
    ASSERT_TRUE(Int64::TryParse("-DeadBeefDead", 16, x));
    ASSERT_EQ(-0xDEADBEEFDEADLL, x);
    ASSERT_TRUE(Int64::TryParse("-8000000000000000", 16, x));
    ASSERT_EQ(Int64::MinValue, x);
    ASSERT_TRUE(Int64::TryParse("7FFFFFFFFFFFFFFF", 16, x));
    ASSERT_EQ(Int64::MaxValue, x);
    ASSERT_FALSE(Int64::TryParse("-08000000000000001", 16, x));
  }
  
  TEST(Int64Test, TryParse_Hexadecimal_Complement) {
    int64 x;
    ASSERT_TRUE(Int64::TryParse("0xFFFFFFFFFFFFFFFF", 16, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int64::TryParse("0x8000000000000000", 16, x));
    ASSERT_EQ(Int64::MinValue, x);
    ASSERT_TRUE(Int64::TryParse("-0x8000000000000000", 16, x));
    ASSERT_EQ(Int64::MinValue, x);
    ASSERT_TRUE(Int64::TryParse("FFFFFFFFFFFEA3C5", 16, x));
    ASSERT_EQ(-89147, x);
  }
  
  TEST(Int64Test, TryParse_Hexadecimal_Complement_Int64) {
    Int64 x;
    ASSERT_TRUE(Int64::TryParse("0xFFFFFFFFFFFFFFFF", 16, x));
    ASSERT_EQ(-1, x);
    ASSERT_TRUE(Int64::TryParse("0x8000000000000000", 16, x));
    ASSERT_EQ(Int64::MinValue, x);
    ASSERT_TRUE(Int64::TryParse("-0x8000000000000000", 16, x));
    ASSERT_EQ(Int64::MinValue, x);
    ASSERT_TRUE(Int64::TryParse("FFFFFFFFFFFEA3C5", 16, x));
    ASSERT_EQ(-89147, x);
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
        MakeTest<Int64>(s, 5, "");

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
