#include <Pcf/System/SByte.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {

TEST(SByte, MaxValue) {
  EXPECT_EQ(127, SByte::MaxValue);
}

TEST(SByte, MinValue) {
  EXPECT_EQ(-128, SByte::MinValue);
}

TEST(SByte, DefaultValue) {
  EXPECT_EQ(0, SByte());
}

TEST(SByte, CtorValue) {
  EXPECT_EQ(10, SByte(10));
  EXPECT_EQ(0, SByte(0));
  EXPECT_EQ(125, SByte(125));
  EXPECT_EQ(-1, SByte(-1));
  EXPECT_EQ(-100, SByte(-100));
}

TEST(SByte, Parse) {
  EXPECT_EQ(0, SByte::Parse("0"));
  EXPECT_EQ(1, SByte::Parse("1"));
  EXPECT_EQ(123, SByte::Parse("123"));
  EXPECT_EQ(-1, SByte::Parse("-1"));
  EXPECT_EQ(-54, SByte::Parse("-54"));
  EXPECT_EQ(-123, SByte::Parse("-123"));
}

TEST(SByte, Parse_Leading_Zeros) {
  EXPECT_EQ(0, SByte::Parse("0"));
  EXPECT_EQ(0, SByte::Parse("00"));
  EXPECT_EQ(0, SByte::Parse("000"));
  EXPECT_EQ(1, SByte::Parse("01"));
  EXPECT_EQ(1, SByte::Parse("0001"));
  EXPECT_EQ(99, SByte::Parse("099"));
  EXPECT_EQ(-99, SByte::Parse("-099"));
}

TEST(SByte, Parse_Spaces) {
  EXPECT_EQ(5,SByte::Parse(" 5"));
  EXPECT_EQ(5,SByte::Parse("     5"));
  EXPECT_EQ(5,SByte::Parse("5 "));
  EXPECT_EQ(51,SByte::Parse("51     "));
  EXPECT_EQ(5,SByte::Parse(" 5      "));
  EXPECT_EQ(52,SByte::Parse("        +52 "));  
  EXPECT_EQ(-52,SByte::Parse("        -52 "));  
}

TEST(SByte, Parse_FormatException) {
  EXPECT_THROW(SByte::Parse(""), FormatException);
  EXPECT_THROW(SByte::Parse("- 5"), FormatException);
  EXPECT_THROW(SByte::Parse("a56"), FormatException);
  EXPECT_THROW(SByte::Parse("0 0"), FormatException);
  EXPECT_THROW(SByte::Parse("++000"), FormatException);
  EXPECT_THROW(SByte::Parse("+"), FormatException);
  EXPECT_THROW(SByte::Parse("-"), FormatException);
  EXPECT_THROW(SByte::Parse("--5"), FormatException);
  EXPECT_THROW(SByte::Parse("0x53"), FormatException);
  EXPECT_THROW(SByte::Parse("100a"), FormatException);
  EXPECT_THROW(SByte::Parse("10u"), FormatException);
}

TEST(SByte, Parse_OverFlowException) {
  EXPECT_EQ(SByte::MaxValue, SByte::Parse("127"));
  EXPECT_THROW(SByte::Parse("128"), OverflowException);
  EXPECT_EQ(SByte::MinValue, SByte::Parse("-128"));
  EXPECT_THROW(SByte::Parse("-129"), OverflowException);
  EXPECT_THROW(SByte::Parse("130"), OverflowException);
  EXPECT_THROW(SByte::Parse("00128"), OverflowException);
}

TEST(SByte, Parse_Binary) {
  EXPECT_EQ(0, SByte::Parse("0",2));
  EXPECT_EQ(1, SByte::Parse("1",2));
  EXPECT_EQ(2, SByte::Parse("10",2));
  EXPECT_EQ(3, SByte::Parse("11",2));
  EXPECT_EQ(6, SByte::Parse("110",2));
  EXPECT_EQ(-1, SByte::Parse("-1",2));
  EXPECT_EQ(-4, SByte::Parse("-100",2));
  EXPECT_EQ(-15, SByte::Parse("-1111",2));
}

TEST(SByte, Parse_Binary_Complement) {
  EXPECT_EQ(-1, SByte::Parse("11111111", 2));
  EXPECT_EQ(-1, SByte::Parse("11111111b", 2));
  EXPECT_EQ(-56, SByte::Parse("11001000", 2));
  EXPECT_EQ(-56, SByte::Parse("11001000b", 2));
  EXPECT_EQ(-111, SByte::Parse("10010001", 2));
  EXPECT_THROW(SByte::Parse("-11111111", 2), OverflowException);
  EXPECT_THROW(SByte::Parse("100000000", 2), OverflowException);
  EXPECT_THROW(SByte::Parse("-11111111b", 2), OverflowException);
}


TEST(SByte, Parse_Binary_Exceptions) {
  EXPECT_THROW(SByte::Parse("",2), FormatException);
  EXPECT_THROW(SByte::Parse("2",2), FormatException);
  EXPECT_THROW(SByte::Parse("103",2), FormatException);
  EXPECT_THROW(SByte::Parse("++0",2), FormatException);
  EXPECT_THROW(SByte::Parse("+",2), FormatException);
  EXPECT_THROW(SByte::Parse("-",2), FormatException);
  EXPECT_THROW(SByte::Parse("--1",2), FormatException);
  EXPECT_THROW(SByte::Parse("0x53",2), FormatException);
  EXPECT_THROW(SByte::Parse("100a",2), FormatException);
  EXPECT_THROW(SByte::Parse("10u",2), FormatException);
}

TEST(SByte, Parse_Binary_Suffix) {
  EXPECT_EQ(0, SByte::Parse("0b",2));
  EXPECT_EQ(1, SByte::Parse("1B",2));
  EXPECT_EQ(2, SByte::Parse("10b",2));
  EXPECT_EQ(3, SByte::Parse("11B",2));
  EXPECT_EQ(6, SByte::Parse("110b",2));
  EXPECT_EQ(-1, SByte::Parse("-1b",2));
  EXPECT_EQ(-4, SByte::Parse("-100b",2));
  EXPECT_EQ(-15, SByte::Parse("-1111B",2));
}

TEST(SByte, Parse_Binary_Suffix_Exceptions) {
  EXPECT_THROW(SByte::Parse("0 b",2), FormatException);
  EXPECT_THROW(SByte::Parse("0x1",2), FormatException);
  EXPECT_THROW(SByte::Parse("10bb",2), FormatException);
  EXPECT_THROW(SByte::Parse("11b0",2), FormatException);
  EXPECT_THROW(SByte::Parse("b",2), FormatException);
  EXPECT_THROW(SByte::Parse("-b",2), FormatException);
  EXPECT_THROW(SByte::Parse("-100a",2), FormatException);
  EXPECT_THROW(SByte::Parse("-11110x",2), FormatException);
}

TEST(SByte, Parse_Octal) {
  EXPECT_EQ(0, SByte::Parse("0",8));
  EXPECT_EQ(1, SByte::Parse("1",8));
  EXPECT_EQ(12, SByte::Parse("14",8));
  EXPECT_EQ(56, SByte::Parse("70",8));
  EXPECT_EQ(-1, SByte::Parse("-1",8));
  EXPECT_EQ(-4, SByte::Parse("-4",8));
  EXPECT_EQ(-15, SByte::Parse("-17",8));
}

TEST(SByte, Parse_Hexadecimal) {
  EXPECT_EQ(0, SByte::Parse("0", 16));
  EXPECT_EQ(1, SByte::Parse("1", 16));
  EXPECT_EQ(0xC, SByte::Parse("C", 16));
  EXPECT_EQ(0x3C, SByte::Parse("3c", 16));
  EXPECT_EQ(-0x4A, SByte::Parse("-4A", 16));
}

TEST(SByte, Parse_Hexadecimal_Complement) {
  EXPECT_EQ(-1, SByte::Parse("FF", 16));
  EXPECT_EQ(-1, SByte::Parse("0xFF", 16));
  EXPECT_EQ(-56, SByte::Parse("C8", 16));
  EXPECT_EQ(-56, SByte::Parse("0xc8", 16));
  EXPECT_EQ(-111, SByte::Parse("91", 16));
  EXPECT_THROW(SByte::Parse("-FF", 16), OverflowException);
  EXPECT_THROW(SByte::Parse("100", 16), OverflowException);
  EXPECT_THROW(SByte::Parse("-0xFF", 16), OverflowException);
}

TEST(SByte, Parse_Hexadecimal_Prefix) {
  EXPECT_EQ(0, SByte::Parse("0x0", 16));
  EXPECT_EQ(1, SByte::Parse("0x1", 16));
  EXPECT_EQ(0xC, SByte::Parse("0xC", 16));
  EXPECT_EQ(0x3C, SByte::Parse("0X3c", 16));
  EXPECT_EQ(-0x4A, SByte::Parse("-0x4A", 16));
  EXPECT_EQ(0x1B, SByte::Parse("1b",16));
  EXPECT_EQ(0x1B, SByte::Parse("1B",16));
  EXPECT_EQ(0x1B, SByte::Parse("0x1b",16));
}

TEST(SByte, Parse_Hexadecimal_Prefix_Exceptions) {
  EXPECT_THROW(SByte::Parse("- 0xFF",16), FormatException);
  EXPECT_THROW(SByte::Parse("xFF",16), FormatException);
  EXPECT_THROW(SByte::Parse("0 xFF",16), FormatException);
  EXPECT_THROW(SByte::Parse("xxFF",16), FormatException);
  EXPECT_THROW(SByte::Parse("0xxFF",16), FormatException);
  EXPECT_THROW(SByte::Parse("0x FF",16), FormatException);
  EXPECT_THROW(SByte::Parse("x",16), FormatException);
  EXPECT_THROW(SByte::Parse("0zFF",16), FormatException);
  EXPECT_THROW(SByte::Parse("0GFF",16), FormatException);
  EXPECT_THROW(SByte::Parse("0x",16), FormatException);
  EXPECT_THROW(SByte::Parse("00xFF",16), FormatException);
}

TEST(SByte, TryParse) {
  sbyte x;
  EXPECT_TRUE(SByte::TryParse("0", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(SByte::TryParse("1", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(SByte::TryParse("123", x));
  EXPECT_EQ(123, x);
  EXPECT_TRUE(SByte::TryParse("-1", x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(SByte::TryParse("-54", x));
  EXPECT_EQ(-54, x);
  EXPECT_TRUE(SByte::TryParse("-123", x));
  EXPECT_EQ(-123, x);
}

TEST(SByte, TryParse_Leading_Zeros) {
  sbyte x;
  EXPECT_TRUE(SByte::TryParse("0", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(SByte::TryParse("00", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(SByte::TryParse("000", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(SByte::TryParse("01", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(SByte::TryParse("0001", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(SByte::TryParse("099", x));
  EXPECT_EQ(99, x);
  EXPECT_TRUE(SByte::TryParse("-099", x));
  EXPECT_EQ(-99, x);
}

TEST(SByte, TryParse_Spaces) {
  sbyte x;
  EXPECT_TRUE(SByte::TryParse(" 5", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(SByte::TryParse("     5", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(SByte::TryParse("5 ", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(SByte::TryParse("51     ", x));
  EXPECT_EQ(51, x);
  EXPECT_TRUE(SByte::TryParse(" 5      ", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(SByte::TryParse("        +52 ", x));
  EXPECT_EQ(52, x);  
  EXPECT_TRUE(SByte::TryParse("        -52 ", x));
  EXPECT_EQ(-52, x);  
}

TEST(SByte, TryParse_FormatException) {
  sbyte x;
  EXPECT_FALSE(SByte::TryParse("", x));
  EXPECT_FALSE(SByte::TryParse("- 5", x));
  EXPECT_FALSE(SByte::TryParse("a56", x));
  EXPECT_FALSE(SByte::TryParse("0 0", x));
  EXPECT_FALSE(SByte::TryParse("++000", x));
  EXPECT_FALSE(SByte::TryParse("+", x));
  EXPECT_FALSE(SByte::TryParse("-", x));
  EXPECT_FALSE(SByte::TryParse("--5", x));
  EXPECT_FALSE(SByte::TryParse("0x53", x));
  EXPECT_FALSE(SByte::TryParse("100a", x));
  EXPECT_FALSE(SByte::TryParse("10u", x));
}

TEST(SByte, TryParse_OverFlowException) {
  sbyte x;
  EXPECT_TRUE(SByte::TryParse("127", x));
  EXPECT_EQ(SByte::MaxValue, x);
  EXPECT_FALSE(SByte::TryParse("128", x));
  EXPECT_TRUE(SByte::TryParse("-128", x));
  EXPECT_EQ(SByte::MinValue, x);
  EXPECT_FALSE(SByte::TryParse("-129", x));
  EXPECT_FALSE(SByte::TryParse("130", x));
  EXPECT_FALSE(SByte::TryParse("00128", x));
}

TEST(SByte, TryParse_Binary) {
  sbyte x;
  EXPECT_TRUE(SByte::TryParse("0", 2, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(SByte::TryParse("1", 2, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(SByte::TryParse("10", 2, x));
  EXPECT_EQ(2, x);
  EXPECT_TRUE(SByte::TryParse("11", 2, x));
  EXPECT_EQ(3, x);
  EXPECT_TRUE(SByte::TryParse("110", 2, x));
  EXPECT_EQ(6, x);
  EXPECT_TRUE(SByte::TryParse("-1", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(SByte::TryParse("-100", 2, x));
  EXPECT_EQ(-4, x);
  EXPECT_TRUE(SByte::TryParse("-1111", 2, x));
  EXPECT_EQ(-15, x);
}

TEST(SByte, TryParse_Binary_Complement) {
  sbyte x;
  EXPECT_TRUE(SByte::TryParse("11111111", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(SByte::TryParse("11111111b", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(SByte::TryParse("11001000", 2, x));
  EXPECT_EQ(-56, x);
  EXPECT_TRUE(SByte::TryParse("11001000b", 2, x));
  EXPECT_EQ(-56, x);
  EXPECT_TRUE(SByte::TryParse("10010001", 2, x));
  EXPECT_EQ(-111, x);
  EXPECT_FALSE(SByte::TryParse("-11111111",  2, x));
  EXPECT_FALSE(SByte::TryParse("100000000",  2, x));
  EXPECT_FALSE(SByte::TryParse("-11111111b",  2, x));
}


TEST(SByte, TryParse_Binary_Exceptions) {
  sbyte x;
  EXPECT_FALSE(SByte::TryParse("", 2, x));
  EXPECT_FALSE(SByte::TryParse("2", 2, x));
  EXPECT_FALSE(SByte::TryParse("103", 2, x));
  EXPECT_FALSE(SByte::TryParse("++0", 2, x));
  EXPECT_FALSE(SByte::TryParse("+", 2, x));
  EXPECT_FALSE(SByte::TryParse("-", 2, x));
  EXPECT_FALSE(SByte::TryParse("--1", 2, x));
  EXPECT_FALSE(SByte::TryParse("0x53", 2, x));
  EXPECT_FALSE(SByte::TryParse("100a", 2, x));
  EXPECT_FALSE(SByte::TryParse("10u", 2, x));
}

TEST(SByte, TryParse_Binary_Suffix) {
  sbyte x;
  EXPECT_TRUE(SByte::TryParse("0b", 2, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(SByte::TryParse("1B", 2, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(SByte::TryParse("10b", 2, x));
  EXPECT_EQ(2, x);
  EXPECT_TRUE(SByte::TryParse("11B", 2, x));
  EXPECT_EQ(3, x);
  EXPECT_TRUE(SByte::TryParse("110b", 2, x));
  EXPECT_EQ(6, x);
  EXPECT_TRUE(SByte::TryParse("-1b", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(SByte::TryParse("-100b", 2, x));
  EXPECT_EQ(-4, x);
  EXPECT_TRUE(SByte::TryParse("-1111B", 2, x));
  EXPECT_EQ(-15, x);
}

TEST(SByte, TryParse_Binary_Suffix_Exceptions) {
  sbyte x;
  EXPECT_FALSE(SByte::TryParse("0 b", 2, x));
  EXPECT_FALSE(SByte::TryParse("0x1", 2, x));
  EXPECT_FALSE(SByte::TryParse("10bb", 2, x));
  EXPECT_FALSE(SByte::TryParse("11b0", 2, x));
  EXPECT_FALSE(SByte::TryParse("b", 2, x));
  EXPECT_FALSE(SByte::TryParse("-b", 2, x));
  EXPECT_FALSE(SByte::TryParse("-100a", 2, x));
  EXPECT_FALSE(SByte::TryParse("-11110x", 2, x));
}

TEST(SByte, TryParse_Octal) {
  sbyte x;
  EXPECT_TRUE(SByte::TryParse("0", 8, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(SByte::TryParse("1", 8, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(SByte::TryParse("14", 8, x));
  EXPECT_EQ(12, x);
  EXPECT_TRUE(SByte::TryParse("70", 8, x));
  EXPECT_EQ(56, x);
  EXPECT_TRUE(SByte::TryParse("-1", 8, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(SByte::TryParse("-4", 8, x));
  EXPECT_EQ(-4, x);
  EXPECT_TRUE(SByte::TryParse("-17", 8, x));
  EXPECT_EQ(-15, x);
}

TEST(SByte, TryParse_Hexadecimal) {
  sbyte x;
  EXPECT_TRUE(SByte::TryParse("0", 16, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(SByte::TryParse("1", 16, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(SByte::TryParse("C", 16, x));
  EXPECT_EQ(0xC, x);
  EXPECT_TRUE(SByte::TryParse("3c", 16, x));
  EXPECT_EQ(0x3C, x);
  EXPECT_TRUE(SByte::TryParse("-4A", 16, x));
  EXPECT_EQ(-0x4A, x);
}

TEST(SByte, TryParse_Hexadecimal_Complement) {
  sbyte x;
  EXPECT_TRUE(SByte::TryParse("FF", 16, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(SByte::TryParse("0xFF", 16, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(SByte::TryParse("C8", 16, x));
  EXPECT_EQ(-56, x);
  EXPECT_TRUE(SByte::TryParse("0xc8", 16, x));
  EXPECT_EQ(-56, x);
  EXPECT_TRUE(SByte::TryParse("91", 16, x));
  EXPECT_EQ(-111, x);
  EXPECT_FALSE(SByte::TryParse("-FF",  16, x));
  EXPECT_FALSE(SByte::TryParse("100",  16, x));
  EXPECT_FALSE(SByte::TryParse("-0xFF",  16, x));
}

TEST(SByte, TryParse_Hexadecimal_Prefix) {
  sbyte x;
  EXPECT_TRUE(SByte::TryParse("0x0", 16, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(SByte::TryParse("0x1", 16, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(SByte::TryParse("0xC", 16, x));
  EXPECT_EQ(0xC, x);
  EXPECT_TRUE(SByte::TryParse("0X3c", 16, x));
  EXPECT_EQ(0x3C, x);
  EXPECT_TRUE(SByte::TryParse("-0x4A", 16, x));
  EXPECT_EQ(-0x4A, x);
  EXPECT_TRUE(SByte::TryParse("1b", 16, x));
  EXPECT_EQ(0x1B, x);
  EXPECT_TRUE(SByte::TryParse("1B", 16, x));
  EXPECT_EQ(0x1B, x);
  EXPECT_TRUE(SByte::TryParse("0x1b", 16, x));
  EXPECT_EQ(0x1B, x);
}

TEST(SByte, TryParse_Hexadecimal_Prefix_Exceptions) {
  sbyte x;
  EXPECT_FALSE(SByte::TryParse("- 0xFF", 16, x));
  EXPECT_FALSE(SByte::TryParse("xFF", 16, x));
  EXPECT_FALSE(SByte::TryParse("0 xFF", 16, x));
  EXPECT_FALSE(SByte::TryParse("xxFF", 16, x));
  EXPECT_FALSE(SByte::TryParse("0xxFF", 16, x));
  EXPECT_FALSE(SByte::TryParse("0x FF", 16, x));
  EXPECT_FALSE(SByte::TryParse("x", 16, x));
  EXPECT_FALSE(SByte::TryParse("0zFF", 16, x));
  EXPECT_FALSE(SByte::TryParse("0GFF", 16, x));
  EXPECT_FALSE(SByte::TryParse("0x", 16, x));
  EXPECT_FALSE(SByte::TryParse("00xFF", 16, x));
}

TEST(SByte, TryParse_SByte) {
  SByte x;
  EXPECT_TRUE(SByte::TryParse("0", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(SByte::TryParse("1", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(SByte::TryParse("123", x));
  EXPECT_EQ(123, x);
  EXPECT_TRUE(SByte::TryParse("-1", x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(SByte::TryParse("-54", x));
  EXPECT_EQ(-54, x);
  EXPECT_TRUE(SByte::TryParse("-123", x));
  EXPECT_EQ(-123, x);
}

TEST(SByte, TryParse_Leading_Zeros_SByte) {
  SByte x;
  EXPECT_TRUE(SByte::TryParse("0", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(SByte::TryParse("00", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(SByte::TryParse("000", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(SByte::TryParse("01", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(SByte::TryParse("0001", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(SByte::TryParse("099", x));
  EXPECT_EQ(99, x);
  EXPECT_TRUE(SByte::TryParse("-099", x));
  EXPECT_EQ(-99, x);
}

TEST(SByte, TryParse_Spaces_SByte) {
  SByte x;
  EXPECT_TRUE(SByte::TryParse(" 5", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(SByte::TryParse("     5", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(SByte::TryParse("5 ", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(SByte::TryParse("51     ", x));
  EXPECT_EQ(51, x);
  EXPECT_TRUE(SByte::TryParse(" 5      ", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(SByte::TryParse("        +52 ", x));
  EXPECT_EQ(52, x);  
  EXPECT_TRUE(SByte::TryParse("        -52 ", x));
  EXPECT_EQ(-52, x);  
}

TEST(SByte, TryParse_FormatException_SByte) {
  SByte x;
  EXPECT_FALSE(SByte::TryParse("", x));
  EXPECT_FALSE(SByte::TryParse("- 5", x));
  EXPECT_FALSE(SByte::TryParse("a56", x));
  EXPECT_FALSE(SByte::TryParse("0 0", x));
  EXPECT_FALSE(SByte::TryParse("++000", x));
  EXPECT_FALSE(SByte::TryParse("+", x));
  EXPECT_FALSE(SByte::TryParse("-", x));
  EXPECT_FALSE(SByte::TryParse("--5", x));
  EXPECT_FALSE(SByte::TryParse("0x53", x));
  EXPECT_FALSE(SByte::TryParse("100a", x));
  EXPECT_FALSE(SByte::TryParse("10u", x));
}

TEST(SByte, TryParse_OverFlowException_SByte) {
  SByte x;
  EXPECT_TRUE(SByte::TryParse("127", x));
  EXPECT_EQ(SByte::MaxValue, x);
  EXPECT_FALSE(SByte::TryParse("128", x));
  EXPECT_TRUE(SByte::TryParse("-128", x));
  EXPECT_EQ(SByte::MinValue, x);
  EXPECT_FALSE(SByte::TryParse("-129", x));
  EXPECT_FALSE(SByte::TryParse("130", x));
  EXPECT_FALSE(SByte::TryParse("00128", x));
}

TEST(SByte, TryParse_Binary_SByte) {
  SByte x;
  EXPECT_TRUE(SByte::TryParse("0", 2, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(SByte::TryParse("1", 2, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(SByte::TryParse("10", 2, x));
  EXPECT_EQ(2, x);
  EXPECT_TRUE(SByte::TryParse("11", 2, x));
  EXPECT_EQ(3, x);
  EXPECT_TRUE(SByte::TryParse("110", 2, x));
  EXPECT_EQ(6, x);
  EXPECT_TRUE(SByte::TryParse("-1", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(SByte::TryParse("-100", 2, x));
  EXPECT_EQ(-4, x);
  EXPECT_TRUE(SByte::TryParse("-1111", 2, x));
  EXPECT_EQ(-15, x);
}

TEST(SByte, TryParse_Binary_Complement_SByte) {
  SByte x;
  EXPECT_TRUE(SByte::TryParse("11111111", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(SByte::TryParse("11111111b", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(SByte::TryParse("11001000", 2, x));
  EXPECT_EQ(-56, x);
  EXPECT_TRUE(SByte::TryParse("11001000b", 2, x));
  EXPECT_EQ(-56, x);
  EXPECT_TRUE(SByte::TryParse("10010001", 2, x));
  EXPECT_EQ(-111, x);
  EXPECT_FALSE(SByte::TryParse("-11111111",  2, x));
  EXPECT_FALSE(SByte::TryParse("100000000",  2, x));
  EXPECT_FALSE(SByte::TryParse("-11111111b",  2, x));
}


TEST(SByte, TryParse_Binary_Exceptions_SByte) {
  SByte x;
  EXPECT_FALSE(SByte::TryParse("", 2, x));
  EXPECT_FALSE(SByte::TryParse("2", 2, x));
  EXPECT_FALSE(SByte::TryParse("103", 2, x));
  EXPECT_FALSE(SByte::TryParse("++0", 2, x));
  EXPECT_FALSE(SByte::TryParse("+", 2, x));
  EXPECT_FALSE(SByte::TryParse("-", 2, x));
  EXPECT_FALSE(SByte::TryParse("--1", 2, x));
  EXPECT_FALSE(SByte::TryParse("0x53", 2, x));
  EXPECT_FALSE(SByte::TryParse("100a", 2, x));
  EXPECT_FALSE(SByte::TryParse("10u", 2, x));
}

TEST(SByte, TryParse_Binary_Suffix_SByte) {
  SByte x;
  EXPECT_TRUE(SByte::TryParse("0b", 2, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(SByte::TryParse("1B", 2, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(SByte::TryParse("10b", 2, x));
  EXPECT_EQ(2, x);
  EXPECT_TRUE(SByte::TryParse("11B", 2, x));
  EXPECT_EQ(3, x);
  EXPECT_TRUE(SByte::TryParse("110b", 2, x));
  EXPECT_EQ(6, x);
  EXPECT_TRUE(SByte::TryParse("-1b", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(SByte::TryParse("-100b", 2, x));
  EXPECT_EQ(-4, x);
  EXPECT_TRUE(SByte::TryParse("-1111B", 2, x));
  EXPECT_EQ(-15, x);
}

TEST(SByte, TryParse_Binary_Suffix_Exceptions_SByte) {
  SByte x;
  EXPECT_FALSE(SByte::TryParse("0 b", 2, x));
  EXPECT_FALSE(SByte::TryParse("0x1", 2, x));
  EXPECT_FALSE(SByte::TryParse("10bb", 2, x));
  EXPECT_FALSE(SByte::TryParse("11b0", 2, x));
  EXPECT_FALSE(SByte::TryParse("b", 2, x));
  EXPECT_FALSE(SByte::TryParse("-b", 2, x));
  EXPECT_FALSE(SByte::TryParse("-100a", 2, x));
  EXPECT_FALSE(SByte::TryParse("-11110x", 2, x));
}

TEST(SByte, TryParse_Octal_SByte) {
  SByte x;
  EXPECT_TRUE(SByte::TryParse("0", 8, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(SByte::TryParse("1", 8, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(SByte::TryParse("14", 8, x));
  EXPECT_EQ(12, x);
  EXPECT_TRUE(SByte::TryParse("70", 8, x));
  EXPECT_EQ(56, x);
  EXPECT_TRUE(SByte::TryParse("-1", 8, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(SByte::TryParse("-4", 8, x));
  EXPECT_EQ(-4, x);
  EXPECT_TRUE(SByte::TryParse("-17", 8, x));
  EXPECT_EQ(-15, x);
}

TEST(SByte, TryParse_Hexadecimal_SByte) {
  SByte x;
  EXPECT_TRUE(SByte::TryParse("0", 16, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(SByte::TryParse("1", 16, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(SByte::TryParse("C", 16, x));
  EXPECT_EQ(0xC, x);
  EXPECT_TRUE(SByte::TryParse("3c", 16, x));
  EXPECT_EQ(0x3C, x);
  EXPECT_TRUE(SByte::TryParse("-4A", 16, x));
  EXPECT_EQ(-0x4A, x);
}

TEST(SByte, TryParse_Hexadecimal_Complement_SByte) {
  SByte x;
  EXPECT_TRUE(SByte::TryParse("FF", 16, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(SByte::TryParse("0xFF", 16, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(SByte::TryParse("C8", 16, x));
  EXPECT_EQ(-56, x);
  EXPECT_TRUE(SByte::TryParse("0xc8", 16, x));
  EXPECT_EQ(-56, x);
  EXPECT_TRUE(SByte::TryParse("91", 16, x));
  EXPECT_EQ(-111, x);
  EXPECT_FALSE(SByte::TryParse("-FF",  16, x));
  EXPECT_FALSE(SByte::TryParse("100",  16, x));
  EXPECT_FALSE(SByte::TryParse("-0xFF",  16, x));
}

TEST(SByte, TryParse_Hexadecimal_Prefix_SByte) {
  SByte x;
  EXPECT_TRUE(SByte::TryParse("0x0", 16, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(SByte::TryParse("0x1", 16, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(SByte::TryParse("0xC", 16, x));
  EXPECT_EQ(0xC, x);
  EXPECT_TRUE(SByte::TryParse("0X3c", 16, x));
  EXPECT_EQ(0x3C, x);
  EXPECT_TRUE(SByte::TryParse("-0x4A", 16, x));
  EXPECT_EQ(-0x4A, x);
  EXPECT_TRUE(SByte::TryParse("1b", 16, x));
  EXPECT_EQ(0x1B, x);
  EXPECT_TRUE(SByte::TryParse("1B", 16, x));
  EXPECT_EQ(0x1B, x);
  EXPECT_TRUE(SByte::TryParse("0x1b", 16, x));
  EXPECT_EQ(0x1B, x);
}

TEST(SByte, TryParse_Hexadecimal_Prefix_Exceptions_SByte) {
  SByte x;
  EXPECT_FALSE(SByte::TryParse("- 0xFF", 16, x));
  EXPECT_FALSE(SByte::TryParse("xFF", 16, x));
  EXPECT_FALSE(SByte::TryParse("0 xFF", 16, x));
  EXPECT_FALSE(SByte::TryParse("xxFF", 16, x));
  EXPECT_FALSE(SByte::TryParse("0xxFF", 16, x));
  EXPECT_FALSE(SByte::TryParse("0x FF", 16, x));
  EXPECT_FALSE(SByte::TryParse("x", 16, x));
  EXPECT_FALSE(SByte::TryParse("0zFF", 16, x));
  EXPECT_FALSE(SByte::TryParse("0GFF", 16, x));
  EXPECT_FALSE(SByte::TryParse("0x", 16, x));
  EXPECT_FALSE(SByte::TryParse("00xFF", 16, x));
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
        MakeTest<SByte>(s, 5, "");

      Console.ReadKey(true);
    }

    static void MakeTest<T>(String s, T prototype, String fmt) {
      String type = typeof(T).Name;
      String suffix = type == "Single" ? "f" : "";

      try {
        MethodInfo method = typeof(T).GetMethod("Parse", new Type[] {typeof(String)});
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