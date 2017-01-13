#include <Pcf/System/Int32.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {

TEST(Int32, MaxValue) {
  EXPECT_EQ(0x7FFFFFFF, Int32::MaxValue);
}

TEST(Int32, MinValue) {
  EXPECT_EQ((-2147483647)-1, Int32::MinValue); //  VS2012 does not handle -2147483648 correctly
}

TEST(Int32, DefaultValue) {
  EXPECT_EQ(0, Int32());
}

TEST(Int32, CtorValue) {
  EXPECT_EQ(10, Int32(10));
  EXPECT_EQ(123654, Int32(123654));
  EXPECT_EQ(0, Int32(0));
  EXPECT_EQ(-1, Int32(-1));
  EXPECT_EQ(-159753, Int32(-159753));
}

TEST(Int32, Parse) {
  EXPECT_EQ(0, Int32::Parse("0"));
  EXPECT_EQ(1, Int32::Parse("1"));
  EXPECT_EQ(123, Int32::Parse("123"));
  EXPECT_EQ(123654, Int32::Parse("123654"));
  EXPECT_EQ(-1, Int32::Parse("-1"));
  EXPECT_EQ(-100, Int32::Parse("-100"));
  EXPECT_EQ(-98744, Int32::Parse("-98744"));
}

TEST(Int32, Parse_Leading_Zeros) {
  EXPECT_EQ(0, Int32::Parse("0"));
  EXPECT_EQ(0, Int32::Parse("00"));
  EXPECT_EQ(0, Int32::Parse("000"));
  EXPECT_EQ(1, Int32::Parse("01"));
  EXPECT_EQ(1, Int32::Parse("0001"));
  EXPECT_EQ(99, Int32::Parse("099"));
  EXPECT_EQ(999, Int32::Parse("0000999"));
  EXPECT_EQ(11, Int32::Parse("00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011"));
  EXPECT_THROW(Int32::Parse("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011"), OverflowException);
}

TEST(Int32, Parse_Spaces) {
  EXPECT_EQ(5,Int32::Parse(" 5"));
  EXPECT_EQ(5,Int32::Parse("     5"));
  EXPECT_EQ(5,Int32::Parse("5 "));
  EXPECT_EQ(51,Int32::Parse("51     "));
  EXPECT_EQ(5,Int32::Parse(" 5      "));
  EXPECT_EQ(52,Int32::Parse("        +52 "));  
  EXPECT_EQ(52,Int32::Parse("        +052 "));  
  EXPECT_EQ(-52,Int32::Parse("        -52 "));  
}

TEST(Int32, Parse_FormatException) {
  EXPECT_THROW(Int32::Parse(""), FormatException);
  EXPECT_THROW(Int32::Parse("a56"), FormatException);
  EXPECT_THROW(Int32::Parse("0 0"), FormatException);
  EXPECT_THROW(Int32::Parse("++000"), FormatException);
  EXPECT_THROW(Int32::Parse("+"), FormatException);
  EXPECT_THROW(Int32::Parse("-"), FormatException);
  EXPECT_THROW(Int32::Parse("--5"), FormatException);
  EXPECT_THROW(Int32::Parse("0x53"), FormatException);
  EXPECT_THROW(Int32::Parse("100a"), FormatException);
  EXPECT_THROW(Int32::Parse("10u"), FormatException);
}

TEST(Int32, Parse_OverFlowException) {
  EXPECT_EQ(Int32::MaxValue, Int32::Parse("2147483647"));
  EXPECT_THROW(Int32::Parse("2147483648"), OverflowException);
  EXPECT_EQ(Int32::MinValue, Int32::Parse("-2147483648"));
  EXPECT_THROW(Int32::Parse("-2147483649"), OverflowException);
  EXPECT_THROW(Int32::Parse("4294967296"), OverflowException);
  EXPECT_THROW(Int32::Parse("5294967295"), OverflowException);
}

TEST(Int32, Parse_Binary) {
  EXPECT_EQ(0, Int32::Parse("0",2));
  EXPECT_EQ(1, Int32::Parse("1",2));
  EXPECT_EQ(2, Int32::Parse("10",2));
  EXPECT_EQ(3, Int32::Parse("11",2));
  EXPECT_EQ(6, Int32::Parse("110",2));
  EXPECT_EQ(-1, Int32::Parse("-1",2));
  EXPECT_EQ(-4, Int32::Parse("-100",2));
  EXPECT_EQ(-15, Int32::Parse("-1111",2));
}

TEST(Int32, Parse_Binary_Complement) {
  EXPECT_EQ(-1, Int32::Parse("11111111111111111111111111111111",2));
  EXPECT_EQ(Int32::MinValue, Int32::Parse("10000000000000000000000000000000",2));
  EXPECT_EQ(-294127, Int32::Parse("11111111111110111000001100010001",2));
  EXPECT_EQ(-3452119, Int32::Parse("11111111110010110101001100101001",2));
  EXPECT_EQ(-2011477291, Int32::Parse("10001000000110110100101011010101",2));
  EXPECT_EQ(Int32::MinValue, Int32::Parse("-10000000000000000000000000000000",2));
}

TEST(Int32, Parse_Binary_Complement_Overflow) {
  EXPECT_THROW(Int32::Parse("-11111111111111111111111111111111",2), OverflowException);
  EXPECT_THROW(Int32::Parse("-10000000000000000000000000000001",2), OverflowException);
}

TEST(Int32, Parse_Exceptions_Binary) {
  EXPECT_THROW(Int32::Parse("",2), FormatException);
  EXPECT_THROW(Int32::Parse("2",2), FormatException);
  EXPECT_THROW(Int32::Parse("103",2), FormatException);
  EXPECT_THROW(Int32::Parse("++0",2), FormatException);
  EXPECT_THROW(Int32::Parse("+",2), FormatException);
  EXPECT_THROW(Int32::Parse("-",2), FormatException);
  EXPECT_THROW(Int32::Parse("--1",2), FormatException);
  EXPECT_THROW(Int32::Parse("0x53",2), FormatException);
  EXPECT_THROW(Int32::Parse("100a",2), FormatException);
  EXPECT_THROW(Int32::Parse("10u",2), FormatException);
}

TEST(Int32, Parse_Octal) {
  EXPECT_EQ(0, Int32::Parse("0",8));
  EXPECT_EQ(1, Int32::Parse("1",8));
  EXPECT_EQ(12, Int32::Parse("14",8));
  EXPECT_EQ(56, Int32::Parse("70",8));
  EXPECT_EQ(601, Int32::Parse("1131",8));
  EXPECT_EQ(-1, Int32::Parse("-1",8));
  EXPECT_EQ(-4, Int32::Parse("-4",8));
  EXPECT_EQ(-15, Int32::Parse("-17",8));
}

TEST(Int32, Parse_Hexadecimal) {
  EXPECT_EQ(0, Int32::Parse("0", 16));
  EXPECT_EQ(1, Int32::Parse("1", 16));
  EXPECT_EQ(0xC, Int32::Parse("C", 16));
  EXPECT_EQ(0x3C, Int32::Parse("3c", 16));
  EXPECT_EQ(0xFE3, Int32::Parse("FE3", 16));
  EXPECT_EQ(-0x4A, Int32::Parse("-4A", 16));
  EXPECT_EQ(-0xABCDE, Int32::Parse("-ABCDE", 16));
}

TEST(Int32, Parse_Hexadecimal_Complement) {
  EXPECT_EQ(-1, Int32::Parse("FFFFFFFF", 16));
  EXPECT_EQ(Int32::MinValue, Int32::Parse("80000000", 16));
  EXPECT_EQ(Int32::MinValue, Int32::Parse("-80000000", 16));
  EXPECT_EQ(-5459, Int32::Parse("FFFFEAAD", 16));
  EXPECT_EQ(-545919, Int32::Parse("FFF7AB81", 16));
}

TEST(Int32, Parse_Hexadecimal_Complement_Overflow) {
  EXPECT_THROW(Int32::Parse("-FFFFFFFF", 16), OverflowException);
  EXPECT_THROW(Int32::Parse("-80000001", 16), OverflowException);
}

TEST(Int32, TryParse) {
  int32 x;
  EXPECT_TRUE(Int32::TryParse("0", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int32::TryParse("1", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int32::TryParse("123", x));
  EXPECT_EQ(123, x);
  EXPECT_TRUE(Int32::TryParse("123654", x));
  EXPECT_EQ(123654, x);
  EXPECT_TRUE(Int32::TryParse("-1", x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int32::TryParse("-100", x));
  EXPECT_EQ(-100, x);
  EXPECT_TRUE(Int32::TryParse("-98744", x));
  EXPECT_EQ(-98744, x);
}

TEST(Int32, TryParse_Int32) {
  Int32 x;
  EXPECT_TRUE(Int32::TryParse("0", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int32::TryParse("1", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int32::TryParse("123", x));
  EXPECT_EQ(123, x);
  EXPECT_TRUE(Int32::TryParse("123654", x));
  EXPECT_EQ(123654, x);
  EXPECT_TRUE(Int32::TryParse("-1", x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int32::TryParse("-100", x));
  EXPECT_EQ(-100, x);
  EXPECT_TRUE(Int32::TryParse("-98744", x));
  EXPECT_EQ(-98744, x);
}


TEST(Int32, TryParse_Leading_Zeros) {
  int32 x;
  EXPECT_TRUE(Int32::TryParse("0", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int32::TryParse("00", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int32::TryParse("000", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int32::TryParse("01", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int32::TryParse("0001", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int32::TryParse("099", x));
  EXPECT_EQ(99, x);
  EXPECT_TRUE(Int32::TryParse("0000999", x));
  EXPECT_EQ(999, x);
}

TEST(Int32, TryParse_Leading_Zeros_Int32) {
  Int32 x;
  EXPECT_TRUE(Int32::TryParse("0", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int32::TryParse("00", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int32::TryParse("000", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int32::TryParse("01", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int32::TryParse("0001", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int32::TryParse("099", x));
  EXPECT_EQ(99, x);
  EXPECT_TRUE(Int32::TryParse("0000999", x));
  EXPECT_EQ(999, x);
}

TEST(Int32, TryParse_Spaces) {
  int32 x;
  EXPECT_TRUE(Int32::TryParse(" 5", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int32::TryParse("     5", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int32::TryParse("5 ", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int32::TryParse("51     ", x));
  EXPECT_EQ(51, x);
  EXPECT_TRUE(Int32::TryParse(" 5      ", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int32::TryParse("        +52 ", x));
  EXPECT_EQ(52, x);  
  EXPECT_TRUE(Int32::TryParse("        +052 ", x));
  EXPECT_EQ(52, x);  
  EXPECT_TRUE(Int32::TryParse("        -52 ", x));
  EXPECT_EQ(-52, x);  
}

TEST(Int32, TryParse_Spaces_Int32) {
  Int32 x;
  EXPECT_TRUE(Int32::TryParse(" 5", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int32::TryParse("     5", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int32::TryParse("5 ", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int32::TryParse("51     ", x));
  EXPECT_EQ(51, x);
  EXPECT_TRUE(Int32::TryParse(" 5      ", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int32::TryParse("        +52 ", x));
  EXPECT_EQ(52, x);  
  EXPECT_TRUE(Int32::TryParse("        +052 ", x));
  EXPECT_EQ(52, x);  
  EXPECT_TRUE(Int32::TryParse("        -52 ", x));
  EXPECT_EQ(-52, x);  
}

TEST(Int32, TryParse_FormatException) {
  int32 x;
  EXPECT_FALSE(Int32::TryParse("", x));
  EXPECT_FALSE(Int32::TryParse("a56", x));
  EXPECT_FALSE(Int32::TryParse("0 0", x));
  EXPECT_FALSE(Int32::TryParse("++000", x));
  EXPECT_FALSE(Int32::TryParse("+", x));
  EXPECT_FALSE(Int32::TryParse("-", x));
  EXPECT_FALSE(Int32::TryParse("--5", x));
  EXPECT_FALSE(Int32::TryParse("0x53", x));
  EXPECT_FALSE(Int32::TryParse("100a", x));
  EXPECT_FALSE(Int32::TryParse("10u", x));
}

TEST(Int32, TryParse_FormatException_Int32) {
  Int32 x;
  EXPECT_FALSE(Int32::TryParse("", x));
  EXPECT_FALSE(Int32::TryParse("a56", x));
  EXPECT_FALSE(Int32::TryParse("0 0", x));
  EXPECT_FALSE(Int32::TryParse("++000", x));
  EXPECT_FALSE(Int32::TryParse("+", x));
  EXPECT_FALSE(Int32::TryParse("-", x));
  EXPECT_FALSE(Int32::TryParse("--5", x));
  EXPECT_FALSE(Int32::TryParse("0x53", x));
  EXPECT_FALSE(Int32::TryParse("100a", x));
  EXPECT_FALSE(Int32::TryParse("10u", x));
}

TEST(Int32, TryParse_OverFlowException) {
  int32 x;
  EXPECT_TRUE(Int32::TryParse("2147483647", x));
  EXPECT_EQ(Int32::MaxValue, x);
  EXPECT_FALSE(Int32::TryParse("2147483648", x));
  EXPECT_TRUE(Int32::TryParse("-2147483648", x));
  EXPECT_EQ(Int32::MinValue, x);
  EXPECT_FALSE(Int32::TryParse("-2147483649", x));
  EXPECT_FALSE(Int32::TryParse("4294967296", x));
  EXPECT_FALSE(Int32::TryParse("5294967295", x));
}

TEST(Int32, TryParse_OverFlowException_Int32) {
  Int32 x;
  EXPECT_TRUE(Int32::TryParse("2147483647", x));
  EXPECT_EQ(Int32::MaxValue, x);
  EXPECT_FALSE(Int32::TryParse("2147483648", x));
  EXPECT_TRUE(Int32::TryParse("-2147483648", x));
  EXPECT_EQ(Int32::MinValue, x);
  EXPECT_FALSE(Int32::TryParse("-2147483649", x));
  EXPECT_FALSE(Int32::TryParse("4294967296", x));
  EXPECT_FALSE(Int32::TryParse("5294967295", x));
}

TEST(Int32, TryParse_Binary) {
  int32 x;
  EXPECT_TRUE(Int32::TryParse("0", 2, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int32::TryParse("1", 2, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int32::TryParse("10", 2, x));
  EXPECT_EQ(2, x);
  EXPECT_TRUE(Int32::TryParse("11", 2, x));
  EXPECT_EQ(3, x);
  EXPECT_TRUE(Int32::TryParse("110", 2, x));
  EXPECT_EQ(6, x);
  EXPECT_TRUE(Int32::TryParse("-1", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int32::TryParse("-100", 2, x));
  EXPECT_EQ(-4, x);
  EXPECT_TRUE(Int32::TryParse("-1111", 2, x));
  EXPECT_EQ(-15, x);
}

TEST(Int32, TryParse_Binary_Int32) {
  Int32 x;
  EXPECT_TRUE(Int32::TryParse("0", 2, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int32::TryParse("1", 2, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int32::TryParse("10", 2, x));
  EXPECT_EQ(2, x);
  EXPECT_TRUE(Int32::TryParse("11", 2, x));
  EXPECT_EQ(3, x);
  EXPECT_TRUE(Int32::TryParse("110", 2, x));
  EXPECT_EQ(6, x);
  EXPECT_TRUE(Int32::TryParse("-1", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int32::TryParse("-100", 2, x));
  EXPECT_EQ(-4, x);
  EXPECT_TRUE(Int32::TryParse("-1111", 2, x));
  EXPECT_EQ(-15, x);
}

TEST(Int32, TryParse_Binary_Complement) {
  int32 x;
  EXPECT_TRUE(Int32::TryParse("11111111111111111111111111111111", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int32::TryParse("10000000000000000000000000000000",2, x));
  EXPECT_EQ(Int32::MinValue, x);
  EXPECT_TRUE(Int32::TryParse("11111111111110111000001100010001", 2, x));
  EXPECT_EQ(-294127, x);
  EXPECT_TRUE(Int32::TryParse("11111111110010110101001100101001", 2, x));
  EXPECT_EQ(-3452119, x);
  EXPECT_TRUE(Int32::TryParse("10001000000110110100101011010101", 2, x));
  EXPECT_EQ(-2011477291, x);
  EXPECT_TRUE(Int32::TryParse("-10000000000000000000000000000000",2, x));
  EXPECT_EQ(Int32::MinValue, x);
}

TEST(Int32, TryParse_Binary_Complement_Int32) {
  Int32 x;
  EXPECT_TRUE(Int32::TryParse("11111111111111111111111111111111", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int32::TryParse("10000000000000000000000000000000",2, x));
  EXPECT_EQ(Int32::MinValue, x);
  EXPECT_TRUE(Int32::TryParse("11111111111110111000001100010001", 2, x));
  EXPECT_EQ(-294127, x);
  EXPECT_TRUE(Int32::TryParse("11111111110010110101001100101001", 2, x));
  EXPECT_EQ(-3452119, x);
  EXPECT_TRUE(Int32::TryParse("10001000000110110100101011010101", 2, x));
  EXPECT_EQ(-2011477291, x);
  EXPECT_TRUE(Int32::TryParse("-10000000000000000000000000000000",2, x));
  EXPECT_EQ(Int32::MinValue, x);
}

TEST(Int32, TryParse_Binary_Complement_Overflow) {
  int32 x;
  EXPECT_FALSE(Int32::TryParse("-11111111111111111111111111111111",2,x));
  EXPECT_FALSE(Int32::TryParse("-10000000000000000000000000000001",2,x));
}

TEST(Int32, TryParse_Binary_Complement_Overflow_Int32) {
  Int32 x;
  EXPECT_FALSE(Int32::TryParse("-11111111111111111111111111111111",2,x));
  EXPECT_FALSE(Int32::TryParse("-10000000000000000000000000000001",2,x));
}

TEST(Int32, TryParse_Exceptions_Binary) {
  int32 x;
  EXPECT_FALSE(Int32::TryParse("",2,x));
  EXPECT_FALSE(Int32::TryParse("2",2,x));
  EXPECT_FALSE(Int32::TryParse("103",2,x));
  EXPECT_FALSE(Int32::TryParse("++0",2,x));
  EXPECT_FALSE(Int32::TryParse("+",2,x));
  EXPECT_FALSE(Int32::TryParse("-",2,x));
  EXPECT_FALSE(Int32::TryParse("--1",2,x));
  EXPECT_FALSE(Int32::TryParse("0x53",2,x));
  EXPECT_FALSE(Int32::TryParse("100a",2,x));
  EXPECT_FALSE(Int32::TryParse("10u",2,x));
}

TEST(Int32, TryParse_Exceptions_Binary_Int32) {
  Int32 x;
  EXPECT_FALSE(Int32::TryParse("",2,x));
  EXPECT_FALSE(Int32::TryParse("2",2,x));
  EXPECT_FALSE(Int32::TryParse("103",2,x));
  EXPECT_FALSE(Int32::TryParse("++0",2,x));
  EXPECT_FALSE(Int32::TryParse("+",2,x));
  EXPECT_FALSE(Int32::TryParse("-",2,x));
  EXPECT_FALSE(Int32::TryParse("--1",2,x));
  EXPECT_FALSE(Int32::TryParse("0x53",2,x));
  EXPECT_FALSE(Int32::TryParse("100a",2,x));
  EXPECT_FALSE(Int32::TryParse("10u",2,x));
}

TEST(Int32, TryParse_Octal) {
  int32 x;
  EXPECT_TRUE(Int32::TryParse("0", 8, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int32::TryParse("1", 8, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int32::TryParse("14", 8, x));
  EXPECT_EQ(12, x);
  EXPECT_TRUE(Int32::TryParse("70", 8, x));
  EXPECT_EQ(56, x);
  EXPECT_TRUE(Int32::TryParse("1131", 8, x));
  EXPECT_EQ(601, x);
  EXPECT_TRUE(Int32::TryParse("-1", 8, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int32::TryParse("-4", 8, x));
  EXPECT_EQ(-4, x);
  EXPECT_TRUE(Int32::TryParse("-17", 8, x));
  EXPECT_EQ(-15, x);
}

TEST(Int32, TryParse_Octal_Int32) {
  Int32 x;
  EXPECT_TRUE(Int32::TryParse("0", 8, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int32::TryParse("1", 8, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int32::TryParse("14", 8, x));
  EXPECT_EQ(12, x);
  EXPECT_TRUE(Int32::TryParse("70", 8, x));
  EXPECT_EQ(56, x);
  EXPECT_TRUE(Int32::TryParse("1131", 8, x));
  EXPECT_EQ(601, x);
  EXPECT_TRUE(Int32::TryParse("-1", 8, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int32::TryParse("-4", 8, x));
  EXPECT_EQ(-4, x);
  EXPECT_TRUE(Int32::TryParse("-17", 8, x));
  EXPECT_EQ(-15, x);
}

TEST(Int32, TryParse_Hexadecimal) {
  int32 x;
  EXPECT_TRUE(Int32::TryParse("0", 16, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int32::TryParse("1", 16, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int32::TryParse("C", 16, x));
  EXPECT_EQ(12, x);
  EXPECT_TRUE(Int32::TryParse("3c", 16, x));
  EXPECT_EQ(60, x);
  EXPECT_TRUE(Int32::TryParse("FE3", 16, x));
  EXPECT_EQ(0xFE3, x);
  EXPECT_TRUE(Int32::TryParse("-4A", 16, x));
  EXPECT_EQ(-0x4A, x);
  EXPECT_TRUE(Int32::TryParse("-ABCDE", 16, x));
  EXPECT_EQ(-0xABCDE, x);
}

TEST(Int32, TryParse_Hexadecimal_Int32) {
  Int32 x;
  EXPECT_TRUE(Int32::TryParse("0", 16, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int32::TryParse("1", 16, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int32::TryParse("C", 16, x));
  EXPECT_EQ(12, x);
  EXPECT_TRUE(Int32::TryParse("3c", 16, x));
  EXPECT_EQ(60, x);
  EXPECT_TRUE(Int32::TryParse("FE3", 16, x));
  EXPECT_EQ(0xFE3, x);
  EXPECT_TRUE(Int32::TryParse("-4A", 16, x));
  EXPECT_EQ(-0x4A, x);
  EXPECT_TRUE(Int32::TryParse("-ABCDE", 16, x));
  EXPECT_EQ(-0xABCDE, x);
}

TEST(Int32, TryParse_Hexadecimal_Complement) {
  int32 x;
  EXPECT_TRUE(Int32::TryParse("FFFFFFFF", 16, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int32::TryParse("80000000", 16, x));
  EXPECT_EQ(Int32::MinValue, x);
  EXPECT_TRUE(Int32::TryParse("-80000000", 16, x));
  EXPECT_EQ(Int32::MinValue, x);
  EXPECT_TRUE(Int32::TryParse("FFFFEAAD", 16, x));
  EXPECT_EQ(-5459, x);
  EXPECT_TRUE(Int32::TryParse("FFF7AB81", 16, x));
  EXPECT_EQ(-545919, x);
}

TEST(Int32, TryParse_Hexadecimal_Complement_Int32) {
  Int32 x;
  EXPECT_TRUE(Int32::TryParse("FFFFFFFF", 16, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int32::TryParse("80000000", 16, x));
  EXPECT_EQ(Int32::MinValue, x);
  EXPECT_TRUE(Int32::TryParse("-80000000", 16, x));
  EXPECT_EQ(Int32::MinValue, x);
  EXPECT_TRUE(Int32::TryParse("FFFFEAAD", 16, x));
  EXPECT_EQ(-5459, x);
  EXPECT_TRUE(Int32::TryParse("FFF7AB81", 16, x));
  EXPECT_EQ(-545919, x);
}

TEST(Int32, TryParse_Hexadecimal_Complement_Overflow) {
  int32 x;
  EXPECT_FALSE(Int32::TryParse("-FFFFFFFF", 16, x));
  EXPECT_FALSE(Int32::TryParse("-80000001", 16, x));
}

TEST(Int32, TryParse_Hexadecimal_Complement_Overflow_Int32) {
  Int32 x;
  EXPECT_FALSE(Int32::TryParse("-FFFFFFFF", 16, x));
  EXPECT_FALSE(Int32::TryParse("-80000001", 16, x));
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

