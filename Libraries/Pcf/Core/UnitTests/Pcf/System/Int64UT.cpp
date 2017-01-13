#include <Pcf/System/Int64.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {

TEST(Int64, MaxValue) {
  EXPECT_EQ(0x7FFFFFFFFFFFFFFFll, Int64::MaxValue);
}

TEST(Int64, MinValue) {
  EXPECT_EQ((int64)-0x8000000000000000ll, Int64::MinValue); //  VS2012 does not handle -2147483648 correctly
}

TEST(Int64, DefaultValue) {
  EXPECT_EQ(0, Int64());
}

TEST(Int64, CtorValue) {
  EXPECT_EQ(10, Int64(10));
  EXPECT_EQ(123654, Int64(123654));
  EXPECT_EQ(0, Int64(0));
  EXPECT_EQ(-1, Int64(-1));
  EXPECT_EQ(-0x7050123654LL, Int64(-0x7050123654LL));
}

TEST(Int64, Parse) {
  EXPECT_EQ(0, Int64::Parse("0"));
  EXPECT_EQ(1, Int64::Parse("1"));
  EXPECT_EQ(123, Int64::Parse("123"));
  EXPECT_EQ(9123654999LL, Int64::Parse("9123654999"));
  EXPECT_EQ(-1, Int64::Parse("-1"));
  EXPECT_EQ(-100, Int64::Parse("-100"));
  EXPECT_EQ(-9981235744, Int64::Parse("-9981235744"));
}

TEST(Int64, Parse_Leading_Zeros) {
  EXPECT_EQ(0, Int64::Parse("0"));
  EXPECT_EQ(0, Int64::Parse("00"));
  EXPECT_EQ(0, Int64::Parse("000"));
  EXPECT_EQ(1, Int64::Parse("01"));
  EXPECT_EQ(1, Int64::Parse("0001"));
  EXPECT_EQ(99, Int64::Parse("099"));
  EXPECT_EQ(999, Int64::Parse("0000999"));
}

TEST(Int64, Parse_Spaces) {
  EXPECT_EQ(5,Int64::Parse(" 5"));
  EXPECT_EQ(5,Int64::Parse("     5"));
  EXPECT_EQ(5,Int64::Parse("5 "));
  EXPECT_EQ(51,Int64::Parse("51     "));
  EXPECT_EQ(5,Int64::Parse(" 5      "));
  EXPECT_EQ(52,Int64::Parse("        52 "));  
}

TEST(Int64, Parse_FormatException) {
  EXPECT_THROW(Int64::Parse(""), FormatException);
  EXPECT_THROW(Int64::Parse("a56"), FormatException);
  EXPECT_THROW(Int64::Parse("0 0"), FormatException);
  EXPECT_THROW(Int64::Parse("++000"), FormatException);
  EXPECT_THROW(Int64::Parse("+"), FormatException);
  EXPECT_THROW(Int64::Parse("-"), FormatException);
  EXPECT_THROW(Int64::Parse("--5"), FormatException);
  EXPECT_THROW(Int64::Parse("0x53"), FormatException);
  EXPECT_THROW(Int64::Parse("100a"), FormatException);
  EXPECT_THROW(Int64::Parse("10u"), FormatException);
}

TEST(Int64, Parse_OverFlowException) { //    987654321.987654321
  EXPECT_EQ(Int64::MaxValue, Int64::Parse("9223372036854775807"));
  EXPECT_THROW(Int64::Parse("9223372036854775808"), OverflowException);
  EXPECT_EQ(Int64::MinValue, Int64::Parse("-9223372036854775808"));
  EXPECT_THROW(Int64::Parse("-9223372036854775809"), OverflowException);
  EXPECT_THROW(Int64::Parse("19223372036854775807"), OverflowException);
  EXPECT_THROW(Int64::Parse("9876549223372036854775807"), OverflowException);
}

TEST(Int64, Parse_Binary) {
  EXPECT_EQ(0, Int64::Parse("0",2));
  EXPECT_EQ(1, Int64::Parse("1",2));
  EXPECT_EQ(2, Int64::Parse("10",2));
  EXPECT_EQ(3, Int64::Parse("11",2));
  EXPECT_EQ(6, Int64::Parse("110",2));
  EXPECT_EQ(-1, Int64::Parse("-1",2));
  EXPECT_EQ(-4, Int64::Parse("-100",2));
  EXPECT_EQ(-15, Int64::Parse("-1111",2));
}

TEST(Int64, Parse_Binary_Complement) {
  EXPECT_EQ(-1, Int64::Parse("1111111111111111111111111111111111111111111111111111111111111111",2));
  EXPECT_EQ(Int64::MinValue, Int64::Parse("1000000000000000000000000000000000000000000000000000000000000000",2));
  EXPECT_EQ(Int64::MinValue, Int64::Parse("-1000000000000000000000000000000000000000000000000000000000000000",2));
  EXPECT_EQ(-852147, Int64::Parse("1111111111111111111111111111111111111111111100101111111101001101",2));
}

TEST(Int64, Parse_Binary_Complement_Overflow) {
  EXPECT_THROW(Int64::Parse("-1111111111111111111111111111111111111111111111111111111111111111",2), OverflowException);
  EXPECT_THROW(Int64::Parse("10000000000000000000000000000000000000000000000000000000000000000",2), OverflowException);
  EXPECT_THROW(Int64::Parse("-1000000000000000000000000000000000000000000000000000000000000001",2), OverflowException);
}


TEST(Int64, Parse_Exceptions_Binary) {
  EXPECT_THROW(Int64::Parse("",2), FormatException);
  EXPECT_THROW(Int64::Parse("2",2), FormatException);
  EXPECT_THROW(Int64::Parse("103",2), FormatException);
  EXPECT_THROW(Int64::Parse("++0",2), FormatException);
  EXPECT_THROW(Int64::Parse("+",2), FormatException);
  EXPECT_THROW(Int64::Parse("-",2), FormatException);
  EXPECT_THROW(Int64::Parse("--1",2), FormatException);
  EXPECT_THROW(Int64::Parse("0x53",2), FormatException);
  EXPECT_THROW(Int64::Parse("100a",2), FormatException);
  EXPECT_THROW(Int64::Parse("10u",2), FormatException);
}

TEST(Int64, Parse_Octal) {
  EXPECT_EQ(0, Int64::Parse("0",8));
  EXPECT_EQ(1, Int64::Parse("1",8));
  EXPECT_EQ(12, Int64::Parse("14",8));
  EXPECT_EQ(56, Int64::Parse("70",8));
  EXPECT_EQ(601, Int64::Parse("1131",8));
  EXPECT_EQ(-1, Int64::Parse("-1",8));
  EXPECT_EQ(-4, Int64::Parse("-4",8));
  EXPECT_EQ(-15, Int64::Parse("-17",8));
}

TEST(Int64, Parse_Hexadecimal) {
  EXPECT_EQ(0, Int64::Parse("0", 16));
  EXPECT_EQ(1, Int64::Parse("1", 16));
  EXPECT_EQ(0xC, Int64::Parse("C", 16));
  EXPECT_EQ(0x3C, Int64::Parse("3c", 16));
  EXPECT_EQ(0xFE3, Int64::Parse("FE3", 16));
  EXPECT_EQ(-0x4A, Int64::Parse("-4A", 16));
  EXPECT_EQ(-0xABCDE, Int64::Parse("-ABCDE", 16));
  EXPECT_EQ(-0xDEADBEEFDEADLL, Int64::Parse("-DeadBeefDead", 16));
  EXPECT_EQ(Int64::MinValue, Int64::Parse("-8000000000000000",16));
  EXPECT_EQ(Int64::MaxValue, Int64::Parse("7FFFFFFFFFFFFFFF",16));
  EXPECT_THROW(Int64::Parse("-08000000000000001",16), OverflowException);
}

TEST(Int64, Parse_Hexadecimal_Complement) {
  EXPECT_EQ(-1, Int64::Parse("0xFFFFFFFFFFFFFFFF", 16));
  EXPECT_EQ(Int64::MinValue, Int64::Parse("0x8000000000000000", 16));
  EXPECT_EQ(Int64::MinValue, Int64::Parse("-0x8000000000000000", 16));
  EXPECT_EQ(-89147, Int64::Parse("FFFFFFFFFFFEA3C5", 16));
}

TEST(Int64, TryParse) {
  int64 x;
  EXPECT_TRUE(Int64::TryParse("0", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int64::TryParse("1", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int64::TryParse("123", x));
  EXPECT_EQ(123, x);
  EXPECT_TRUE(Int64::TryParse("9123654999", x));
  EXPECT_EQ(9123654999LL, x);
  EXPECT_TRUE(Int64::TryParse("-1", x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int64::TryParse("-100", x));
  EXPECT_EQ(-100, x);
  EXPECT_TRUE(Int64::TryParse("-9981235744", x));
  EXPECT_EQ(-9981235744, x);
}

TEST(Int64, TryParse_Int64) {
  Int64 x;
  EXPECT_TRUE(Int64::TryParse("0", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int64::TryParse("1", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int64::TryParse("123", x));
  EXPECT_EQ(123, x);
  EXPECT_TRUE(Int64::TryParse("9123654999", x));
  EXPECT_EQ(9123654999LL, x);
  EXPECT_TRUE(Int64::TryParse("-1", x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int64::TryParse("-100", x));
  EXPECT_EQ(-100, x);
  EXPECT_TRUE(Int64::TryParse("-9981235744", x));
  EXPECT_EQ(-9981235744, x);
}

TEST(Int64, TryParse_Leading_Zeros) {
  int64 x;
  EXPECT_TRUE(Int64::TryParse("0", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int64::TryParse("00", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int64::TryParse("000", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int64::TryParse("01", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int64::TryParse("0001", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int64::TryParse("099", x));
  EXPECT_EQ(99, x);
  EXPECT_TRUE(Int64::TryParse("0000999", x));
  EXPECT_EQ(999, x);
}

TEST(Int64, TryParse_Leading_Zeros_Int64) {
  Int64 x;
  EXPECT_TRUE(Int64::TryParse("0", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int64::TryParse("00", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int64::TryParse("000", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int64::TryParse("01", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int64::TryParse("0001", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int64::TryParse("099", x));
  EXPECT_EQ(99, x);
  EXPECT_TRUE(Int64::TryParse("0000999", x));
  EXPECT_EQ(999, x);
}

TEST(Int64, TryParse_Spaces) {
  int64 x;
  EXPECT_TRUE(Int64::TryParse(" 5", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int64::TryParse("     5", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int64::TryParse("5 ", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int64::TryParse("51     ", x));
  EXPECT_EQ(51, x);
  EXPECT_TRUE(Int64::TryParse(" 5      ", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int64::TryParse("        52 ", x));
  EXPECT_EQ(52, x);  
}

TEST(Int64, TryParse_Spaces_Int64) {
  Int64 x;
  EXPECT_TRUE(Int64::TryParse(" 5", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int64::TryParse("     5", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int64::TryParse("5 ", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int64::TryParse("51     ", x));
  EXPECT_EQ(51, x);
  EXPECT_TRUE(Int64::TryParse(" 5      ", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int64::TryParse("        52 ", x));
  EXPECT_EQ(52, x);  
}

TEST(Int64, TryParse_FormatException) {
  int64 x;
  EXPECT_FALSE(Int64::TryParse("", x));
  EXPECT_FALSE(Int64::TryParse("a56", x));
  EXPECT_FALSE(Int64::TryParse("0 0", x));
  EXPECT_FALSE(Int64::TryParse("++000", x));
  EXPECT_FALSE(Int64::TryParse("+", x));
  EXPECT_FALSE(Int64::TryParse("-", x));
  EXPECT_FALSE(Int64::TryParse("--5", x));
  EXPECT_FALSE(Int64::TryParse("0x53", x));
  EXPECT_FALSE(Int64::TryParse("100a", x));
  EXPECT_FALSE(Int64::TryParse("10u", x));
}

TEST(Int64, TryParse_FormatException_Int64) {
  Int64 x;
  EXPECT_FALSE(Int64::TryParse("", x));
  EXPECT_FALSE(Int64::TryParse("a56", x));
  EXPECT_FALSE(Int64::TryParse("0 0", x));
  EXPECT_FALSE(Int64::TryParse("++000", x));
  EXPECT_FALSE(Int64::TryParse("+", x));
  EXPECT_FALSE(Int64::TryParse("-", x));
  EXPECT_FALSE(Int64::TryParse("--5", x));
  EXPECT_FALSE(Int64::TryParse("0x53", x));
  EXPECT_FALSE(Int64::TryParse("100a", x));
  EXPECT_FALSE(Int64::TryParse("10u", x));
}

TEST(Int64, TryParse_OverFlowException) { //    987654321.987654321
  int64 x;
  EXPECT_TRUE(Int64::TryParse("9223372036854775807", x));
  EXPECT_EQ(Int64::MaxValue, x);
  EXPECT_FALSE(Int64::TryParse("9223372036854775808", x));
  EXPECT_TRUE(Int64::TryParse("-9223372036854775808", x));
  EXPECT_EQ(Int64::MinValue, x);
  EXPECT_FALSE(Int64::TryParse("-9223372036854775809", x));
  EXPECT_FALSE(Int64::TryParse("19223372036854775807", x));
  EXPECT_FALSE(Int64::TryParse("9876549223372036854775807", x));
}

TEST(Int64, TryParse_OverFlowException_Int64) { //    987654321.987654321
  Int64 x;
  EXPECT_TRUE(Int64::TryParse("9223372036854775807", x));
  EXPECT_EQ(Int64::MaxValue, x);
  EXPECT_FALSE(Int64::TryParse("9223372036854775808", x));
  EXPECT_TRUE(Int64::TryParse("-9223372036854775808", x));
  EXPECT_EQ(Int64::MinValue, x);
  EXPECT_FALSE(Int64::TryParse("-9223372036854775809", x));
  EXPECT_FALSE(Int64::TryParse("19223372036854775807", x));
  EXPECT_FALSE(Int64::TryParse("9876549223372036854775807", x));
}

TEST(Int64, TryParse_Binary) {
  int64 x;
  EXPECT_TRUE(Int64::TryParse("0", 2, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int64::TryParse("1", 2, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int64::TryParse("10", 2, x));
  EXPECT_EQ(2, x);
  EXPECT_TRUE(Int64::TryParse("11", 2, x));
  EXPECT_EQ(3, x);
  EXPECT_TRUE(Int64::TryParse("110", 2, x));
  EXPECT_EQ(6, x);
  EXPECT_TRUE(Int64::TryParse("-1", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int64::TryParse("-100", 2, x));
  EXPECT_EQ(-4, x);
  EXPECT_TRUE(Int64::TryParse("-1111", 2, x));
  EXPECT_EQ(-15, x);
}

TEST(Int64, TryParse_Binary_Int64) {
  Int64 x;
  EXPECT_TRUE(Int64::TryParse("0", 2, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int64::TryParse("1", 2, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int64::TryParse("10", 2, x));
  EXPECT_EQ(2, x);
  EXPECT_TRUE(Int64::TryParse("11", 2, x));
  EXPECT_EQ(3, x);
  EXPECT_TRUE(Int64::TryParse("110", 2, x));
  EXPECT_EQ(6, x);
  EXPECT_TRUE(Int64::TryParse("-1", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int64::TryParse("-100", 2, x));
  EXPECT_EQ(-4, x);
  EXPECT_TRUE(Int64::TryParse("-1111", 2, x));
  EXPECT_EQ(-15, x);
}

TEST(Int64, TryParse_Binary_Complement) {
  int64 x;
  EXPECT_TRUE(Int64::TryParse("1111111111111111111111111111111111111111111111111111111111111111", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int64::TryParse("1000000000000000000000000000000000000000000000000000000000000000", 2, x));
  EXPECT_EQ(Int64::MinValue, x);
  EXPECT_TRUE(Int64::TryParse("-1000000000000000000000000000000000000000000000000000000000000000", 2, x));
  EXPECT_EQ(Int64::MinValue, x);
  EXPECT_TRUE(Int64::TryParse("1111111111111111111111111111111111111111111100101111111101001101", 2, x));
  EXPECT_EQ(-852147, x);
}

TEST(Int64, TryParse_Binary_Complement_Int64) {
  Int64 x;
  EXPECT_TRUE(Int64::TryParse("1111111111111111111111111111111111111111111111111111111111111111", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int64::TryParse("1000000000000000000000000000000000000000000000000000000000000000", 2, x));
  EXPECT_EQ(Int64::MinValue, x);
  EXPECT_TRUE(Int64::TryParse("-1000000000000000000000000000000000000000000000000000000000000000", 2, x));
  EXPECT_EQ(Int64::MinValue, x);
  EXPECT_TRUE(Int64::TryParse("1111111111111111111111111111111111111111111100101111111101001101", 2, x));
  EXPECT_EQ(-852147, x);
}

TEST(Int64, TryParse_Binary_Complement_Overflow) {
  int64 x;
  EXPECT_FALSE(Int64::TryParse("-1111111111111111111111111111111111111111111111111111111111111111", 2, x));
  EXPECT_FALSE(Int64::TryParse("10000000000000000000000000000000000000000000000000000000000000000", 2, x));
  EXPECT_FALSE(Int64::TryParse("-1000000000000000000000000000000000000000000000000000000000000001", 2, x));
}

TEST(Int64, TryParse_Binary_Complement_Overflow_Int64) {
  Int64 x;
  EXPECT_FALSE(Int64::TryParse("-1111111111111111111111111111111111111111111111111111111111111111", 2, x));
  EXPECT_FALSE(Int64::TryParse("10000000000000000000000000000000000000000000000000000000000000000", 2, x));
  EXPECT_FALSE(Int64::TryParse("-1000000000000000000000000000000000000000000000000000000000000001", 2, x));
}

TEST(Int64, TryParse_Exceptions_Binary) {
  int64 x;
  EXPECT_FALSE(Int64::TryParse("", 2, x));
  EXPECT_FALSE(Int64::TryParse("2", 2, x));
  EXPECT_FALSE(Int64::TryParse("103", 2, x));
  EXPECT_FALSE(Int64::TryParse("++0", 2, x));
  EXPECT_FALSE(Int64::TryParse("+", 2, x));
  EXPECT_FALSE(Int64::TryParse("-", 2, x));
  EXPECT_FALSE(Int64::TryParse("--1", 2, x));
  EXPECT_FALSE(Int64::TryParse("0x53", 2, x));
  EXPECT_FALSE(Int64::TryParse("100a", 2, x));
  EXPECT_FALSE(Int64::TryParse("10u", 2, x));
}

TEST(Int64, TryParse_Exceptions_Binary_Int64) {
  Int64 x;
  EXPECT_FALSE(Int64::TryParse("", 2, x));
  EXPECT_FALSE(Int64::TryParse("2", 2, x));
  EXPECT_FALSE(Int64::TryParse("103", 2, x));
  EXPECT_FALSE(Int64::TryParse("++0", 2, x));
  EXPECT_FALSE(Int64::TryParse("+", 2, x));
  EXPECT_FALSE(Int64::TryParse("-", 2, x));
  EXPECT_FALSE(Int64::TryParse("--1", 2, x));
  EXPECT_FALSE(Int64::TryParse("0x53", 2, x));
  EXPECT_FALSE(Int64::TryParse("100a", 2, x));
  EXPECT_FALSE(Int64::TryParse("10u", 2, x));
}

TEST(Int64, TryParse_Octal) {
  int64 x;
  EXPECT_TRUE(Int64::TryParse("0", 8, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int64::TryParse("1", 8, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int64::TryParse("14", 8, x));
  EXPECT_EQ(12, x);
  EXPECT_TRUE(Int64::TryParse("70", 8, x));
  EXPECT_EQ(56, x);
  EXPECT_TRUE(Int64::TryParse("1131", 8, x));
  EXPECT_EQ(601, x);
  EXPECT_TRUE(Int64::TryParse("-1", 8, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int64::TryParse("-4", 8, x));
  EXPECT_EQ(-4, x);
  EXPECT_TRUE(Int64::TryParse("-17", 8, x));
  EXPECT_EQ(-15, x);
}

TEST(Int64, TryParse_Octal_Int64) {
  Int64 x;
  EXPECT_TRUE(Int64::TryParse("0", 8, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int64::TryParse("1", 8, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int64::TryParse("14", 8, x));
  EXPECT_EQ(12, x);
  EXPECT_TRUE(Int64::TryParse("70", 8, x));
  EXPECT_EQ(56, x);
  EXPECT_TRUE(Int64::TryParse("1131", 8, x));
  EXPECT_EQ(601, x);
  EXPECT_TRUE(Int64::TryParse("-1", 8, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int64::TryParse("-4", 8, x));
  EXPECT_EQ(-4, x);
  EXPECT_TRUE(Int64::TryParse("-17", 8, x));
  EXPECT_EQ(-15, x);
}

TEST(Int64, TryParse_Hexadecimal) {
  int64 x;
  EXPECT_TRUE(Int64::TryParse("0", 16, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int64::TryParse("1", 16, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int64::TryParse("C", 16, x));
  EXPECT_EQ(0xC, x);
  EXPECT_TRUE(Int64::TryParse("3c", 16, x));
  EXPECT_EQ(0x3C, x);
  EXPECT_TRUE(Int64::TryParse("FE3", 16, x));
  EXPECT_EQ(0xFE3, x);
  EXPECT_TRUE(Int64::TryParse("-4A", 16, x));
  EXPECT_EQ(-0x4A, x);
  EXPECT_TRUE(Int64::TryParse("-ABCDE", 16, x));
  EXPECT_EQ(-0xABCDE, x);
  EXPECT_TRUE(Int64::TryParse("-DeadBeefDead", 16, x));
  EXPECT_EQ(-0xDEADBEEFDEADLL, x);
  EXPECT_TRUE(Int64::TryParse("-8000000000000000", 16, x));
  EXPECT_EQ(Int64::MinValue, x);
  EXPECT_TRUE(Int64::TryParse("7FFFFFFFFFFFFFFF", 16, x));
  EXPECT_EQ(Int64::MaxValue, x);
  EXPECT_FALSE(Int64::TryParse("-08000000000000001", 16, x));
}

TEST(Int64, TryParse_Hexadecimal_Int64) {
  Int64 x;
  EXPECT_TRUE(Int64::TryParse("0", 16, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int64::TryParse("1", 16, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int64::TryParse("C", 16, x));
  EXPECT_EQ(0xC, x);
  EXPECT_TRUE(Int64::TryParse("3c", 16, x));
  EXPECT_EQ(0x3C, x);
  EXPECT_TRUE(Int64::TryParse("FE3", 16, x));
  EXPECT_EQ(0xFE3, x);
  EXPECT_TRUE(Int64::TryParse("-4A", 16, x));
  EXPECT_EQ(-0x4A, x);
  EXPECT_TRUE(Int64::TryParse("-ABCDE", 16, x));
  EXPECT_EQ(-0xABCDE, x);
  EXPECT_TRUE(Int64::TryParse("-DeadBeefDead", 16, x));
  EXPECT_EQ(-0xDEADBEEFDEADLL, x);
  EXPECT_TRUE(Int64::TryParse("-8000000000000000", 16, x));
  EXPECT_EQ(Int64::MinValue, x);
  EXPECT_TRUE(Int64::TryParse("7FFFFFFFFFFFFFFF", 16, x));
  EXPECT_EQ(Int64::MaxValue, x);
  EXPECT_FALSE(Int64::TryParse("-08000000000000001", 16, x));
}

TEST(Int64, TryParse_Hexadecimal_Complement) {
  int64 x;
  EXPECT_TRUE(Int64::TryParse("0xFFFFFFFFFFFFFFFF", 16, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int64::TryParse("0x8000000000000000", 16, x));
  EXPECT_EQ(Int64::MinValue, x);
  EXPECT_TRUE(Int64::TryParse("-0x8000000000000000", 16, x));
  EXPECT_EQ(Int64::MinValue, x);
  EXPECT_TRUE(Int64::TryParse("FFFFFFFFFFFEA3C5", 16, x));
  EXPECT_EQ(-89147, x);
}

TEST(Int64, TryParse_Hexadecimal_Complement_Int64) {
  Int64 x;
  EXPECT_TRUE(Int64::TryParse("0xFFFFFFFFFFFFFFFF", 16, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int64::TryParse("0x8000000000000000", 16, x));
  EXPECT_EQ(Int64::MinValue, x);
  EXPECT_TRUE(Int64::TryParse("-0x8000000000000000", 16, x));
  EXPECT_EQ(Int64::MinValue, x);
  EXPECT_TRUE(Int64::TryParse("FFFFFFFFFFFEA3C5", 16, x));
  EXPECT_EQ(-89147, x);
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
      String type = pcf_typeof(T).Name;
      String suffix = type == "Single" ? "f" : "";

      try {
        MethodInfo method = pcf_typeof(T).GetMethod("Parse", new Type[] {pcf_typeof(String)});
        T value = (T)method.Invoke(prototype, new object[] {s});
        Console.WriteLine("EXPECT_EQ({0}{3}, {1}::Parse(\"{2}\"));", 
          (value as IFormattable).ToString(fmt, System::Globalization::CultureInfo.CreateSpecificCulture("en-US")), type, s, suffix);
      } catch (System::FormatException) {
        Console.WriteLine("EXPECT_THROW({0}::Parse(\"{1}\"), FormatException);", type, s);
      } catch (System::Reflection.TargetInvocationException x) {
        Console.WriteLine("EXPECT_THROW({0}::Parse(\"{1}\"), {2});", type, s, x.InnerException.GetType().Name);
      }
    }
  }
}
*/
