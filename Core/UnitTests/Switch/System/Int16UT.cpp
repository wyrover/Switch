#include <Switch/System/Int16.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {

TEST(Int16, MaxValue) {
  EXPECT_EQ(0x7FFF, Int16::MaxValue);
}

TEST(Int16, MinValue) {
  EXPECT_EQ(-0x8000, Int16::MinValue);
}

TEST(Int16, DefaultValue) {
  EXPECT_EQ(0, Int16());
}

TEST(Int16, CtorValue) {
  EXPECT_EQ(10, Int16(10));
  EXPECT_EQ(12654, Int16(12654));
  EXPECT_EQ(0, Int16(0));
  EXPECT_EQ(-1, Int16(-1));
  EXPECT_EQ(-29973, Int16(-29973));
}

TEST(Int16, Parse) {
  EXPECT_EQ(0, Int16::Parse("0"));
  EXPECT_EQ(1, Int16::Parse("1"));
  EXPECT_EQ(123, Int16::Parse("123"));
  EXPECT_EQ(28012, Int16::Parse("28012"));
  EXPECT_EQ(-1, Int16::Parse("-1"));
  EXPECT_EQ(-100, Int16::Parse("-100"));
  EXPECT_EQ(-32768, Int16::Parse("-32768"));
}

TEST(Int16, Parse_Leading_Zeros) {
  EXPECT_EQ(0, Int16::Parse("0"));
  EXPECT_EQ(0, Int16::Parse("00"));
  EXPECT_EQ(0, Int16::Parse("000"));
  EXPECT_EQ(1, Int16::Parse("01"));
  EXPECT_EQ(1, Int16::Parse("0001"));
  EXPECT_EQ(99, Int16::Parse("099"));
  EXPECT_EQ(999, Int16::Parse("0000999"));
}

TEST(Int16, Parse_Spaces) {
  EXPECT_EQ(5,Int16::Parse(" 5"));
  EXPECT_EQ(5,Int16::Parse("     5"));
  EXPECT_EQ(5,Int16::Parse("5 "));
  EXPECT_EQ(51,Int16::Parse("51     "));
  EXPECT_EQ(5,Int16::Parse(" 5      "));
  EXPECT_EQ(52,Int16::Parse("        +52 "));  
  EXPECT_EQ(-52,Int16::Parse("        -052 "));  
}

TEST(Int16, Parse_FormatException) {
  EXPECT_THROW(Int16::Parse(""), FormatException);
  EXPECT_THROW(Int16::Parse("a56"), FormatException);
  EXPECT_THROW(Int16::Parse("0 0"), FormatException);
  EXPECT_THROW(Int16::Parse("++000"), FormatException);
  EXPECT_THROW(Int16::Parse("+"), FormatException);
  EXPECT_THROW(Int16::Parse("-"), FormatException);
  EXPECT_THROW(Int16::Parse("--5"), FormatException);
  EXPECT_THROW(Int16::Parse("0x53"), FormatException);
  EXPECT_THROW(Int16::Parse("100a"), FormatException);
  EXPECT_THROW(Int16::Parse("10u"), FormatException);
}

TEST(Int16, Parse_OverFlowException) {
  EXPECT_EQ(Int16::MaxValue, Int16::Parse("32767"));
  EXPECT_THROW(Int16::Parse("32768"), OverflowException);
  EXPECT_EQ(Int16::MinValue, Int16::Parse("-32768"));
  EXPECT_THROW(Int16::Parse("-32769"), OverflowException);
  EXPECT_THROW(Int16::Parse("45111"), OverflowException);
  EXPECT_THROW(Int16::Parse("870125"), OverflowException);
}

TEST(Int16, Parse_Binary) {
  EXPECT_EQ(0, Int16::Parse("0",2));
  EXPECT_EQ(1, Int16::Parse("1",2));
  EXPECT_EQ(2, Int16::Parse("10",2));
  EXPECT_EQ(3, Int16::Parse("11",2));
  EXPECT_EQ(6, Int16::Parse("110",2));
  EXPECT_EQ(-1, Int16::Parse("-1",2));
  EXPECT_EQ(-4, Int16::Parse("-100",2));
  EXPECT_EQ(-15, Int16::Parse("-1111",2));
  EXPECT_EQ(Int16::MinValue, Int16::Parse("-1000000000000000",2));
}

TEST(Int16, Parse_Binary_Complement) {
  EXPECT_EQ(-1, Int16::Parse("1111111111111111",2));
  EXPECT_EQ(-111, Int16::Parse("1111111110010001",2));
  EXPECT_EQ(-31987, Int16::Parse("1000001100001101",2));
  EXPECT_EQ(Int16::MinValue, Int16::Parse("1000000000000000",2));
}

TEST(Int16, Parse_Binary_Complement_Overflow) {
  EXPECT_THROW(Int16::Parse("10000000000000000",2), OverflowException);
  EXPECT_THROW(Int16::Parse("-1111111111111111",2), OverflowException);
  EXPECT_THROW(Int16::Parse("-1111111110010001",2), OverflowException);
  EXPECT_THROW(Int16::Parse("-1000001100001101",2), OverflowException);
  EXPECT_THROW(Int16::Parse("-10000000000000000",2), OverflowException);
}

TEST(Int16, Parse_Exceptions_Binary) {
  EXPECT_THROW(Int16::Parse("",2), FormatException);
  EXPECT_THROW(Int16::Parse("2",2), FormatException);
  EXPECT_THROW(Int16::Parse("103",2), FormatException);
  EXPECT_THROW(Int16::Parse("++0",2), FormatException);
  EXPECT_THROW(Int16::Parse("+",2), FormatException);
  EXPECT_THROW(Int16::Parse("-",2), FormatException);
  EXPECT_THROW(Int16::Parse("--1",2), FormatException);
  EXPECT_THROW(Int16::Parse("0x53",2), FormatException);
  EXPECT_THROW(Int16::Parse("100a",2), FormatException);
  EXPECT_THROW(Int16::Parse("10u",2), FormatException);
}

TEST(Int16, Parse_Octal) {
  EXPECT_EQ(0, Int16::Parse("0",8));
  EXPECT_EQ(1, Int16::Parse("1",8));
  EXPECT_EQ(12, Int16::Parse("14",8));
  EXPECT_EQ(56, Int16::Parse("70",8));
  EXPECT_EQ(601, Int16::Parse("1131",8));
  EXPECT_EQ(-1, Int16::Parse("-1",8));
  EXPECT_EQ(-4, Int16::Parse("-4",8));
  EXPECT_EQ(-15, Int16::Parse("-17",8));
}

TEST(Int16, Parse_Hexadecimal) {
  EXPECT_EQ(0, Int16::Parse("0", 16));
  EXPECT_EQ(1, Int16::Parse("1", 16));
  EXPECT_EQ(0xC, Int16::Parse("C", 16));
  EXPECT_EQ(0x3C, Int16::Parse("3c", 16));
  EXPECT_EQ(0xFE3, Int16::Parse("FE3", 16));
  EXPECT_EQ(-0x4A, Int16::Parse("-4A", 16));
  EXPECT_EQ(-0x6BCD, Int16::Parse("-6BCD", 16));
}

TEST(Int16, Parse_Hexadecimal_Complement) {
  EXPECT_EQ(-1, Int16::Parse("FFFF", 16));
  EXPECT_EQ(-333, Int16::Parse("0xFEB3", 16));
  EXPECT_EQ(-12587, Int16::Parse("CED5", 16));
  EXPECT_EQ(Int16::MinValue, Int16::Parse("0x8000", 16));
  EXPECT_EQ(Int16::MinValue, Int16::Parse("-0x8000", 16));
}

TEST(Int16, Parse_Hexadecimal_Complement_Overflow) {
  EXPECT_THROW(Int16::Parse("10000", 16), OverflowException);
  EXPECT_THROW(Int16::Parse("0x10100", 16), OverflowException);
}

TEST(Int16, TryParse) {
  int16 x;
  EXPECT_TRUE(Int16::TryParse("0", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int16::TryParse("1", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int16::TryParse("123", x));
  EXPECT_EQ(123, x);
  EXPECT_TRUE(Int16::TryParse("28012", x));
  EXPECT_EQ(28012, x);
  EXPECT_TRUE(Int16::TryParse("-1", x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int16::TryParse("-100", x));
  EXPECT_EQ(-100, x);
  EXPECT_TRUE(Int16::TryParse("-32768", x));
  EXPECT_EQ(-32768, x);
}

TEST(Int16, TryParse_Int16) {
  Int16 x;
  EXPECT_TRUE(Int16::TryParse("0", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int16::TryParse("1", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int16::TryParse("123", x));
  EXPECT_EQ(123, x);
  EXPECT_TRUE(Int16::TryParse("28012", x));
  EXPECT_EQ(28012, x);
  EXPECT_TRUE(Int16::TryParse("-1", x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int16::TryParse("-100", x));
  EXPECT_EQ(-100, x);
  EXPECT_TRUE(Int16::TryParse("-32768", x));
  EXPECT_EQ(-32768, x);
}

TEST(Int16, TryParse_Leading_Zeros) {
  int16 x;
  EXPECT_TRUE(Int16::TryParse("0", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int16::TryParse("00", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int16::TryParse("000", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int16::TryParse("01", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int16::TryParse("0001", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int16::TryParse("099", x));
  EXPECT_EQ(99, x);
  EXPECT_TRUE(Int16::TryParse("0000999", x));
  EXPECT_EQ(999, x);
}

TEST(Int16, TryParse_Leading_Zeros_Int16) {
  Int16 x;
  EXPECT_TRUE(Int16::TryParse("0", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int16::TryParse("00", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int16::TryParse("000", x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int16::TryParse("01", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int16::TryParse("0001", x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int16::TryParse("099", x));
  EXPECT_EQ(99, x);
  EXPECT_TRUE(Int16::TryParse("0000999", x));
  EXPECT_EQ(999, x);
}

TEST(Int16, TryParse_Spaces) {
  int16 x;
  EXPECT_TRUE(Int16::TryParse(" 5", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int16::TryParse("     5", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int16::TryParse("5 ", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int16::TryParse("51     ", x));
  EXPECT_EQ(51, x);
  EXPECT_TRUE(Int16::TryParse(" 5      ", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int16::TryParse("        +52 ", x));
  EXPECT_EQ(52, x);
  EXPECT_TRUE(Int16::TryParse("        -052 ", x));
  EXPECT_EQ(-52, x);
}

TEST(Int16, TryParse_Spaces_Int16) {
  Int16 x;
  EXPECT_TRUE(Int16::TryParse(" 5", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int16::TryParse("     5", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int16::TryParse("5 ", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int16::TryParse("51     ", x));
  EXPECT_EQ(51, x);
  EXPECT_TRUE(Int16::TryParse(" 5      ", x));
  EXPECT_EQ(5, x);
  EXPECT_TRUE(Int16::TryParse("        +52 ", x));
  EXPECT_EQ(52, x);
  EXPECT_TRUE(Int16::TryParse("        -052 ", x));
  EXPECT_EQ(-52, x);
}

TEST(Int16, TryParse_FormatException) {
  int16 x;
  EXPECT_FALSE(Int16::TryParse("",x));
  EXPECT_FALSE(Int16::TryParse("a56",x));
  EXPECT_FALSE(Int16::TryParse("0 0",x));
  EXPECT_FALSE(Int16::TryParse("++000",x));
  EXPECT_FALSE(Int16::TryParse("+",x));
  EXPECT_FALSE(Int16::TryParse("-",x));
  EXPECT_FALSE(Int16::TryParse("--5",x));
  EXPECT_FALSE(Int16::TryParse("0x53",x));
  EXPECT_FALSE(Int16::TryParse("100a",x));
  EXPECT_FALSE(Int16::TryParse("10u",x));
}

TEST(Int16, TryParse_FormatException_Int16) {
  Int16 x;
  EXPECT_FALSE(Int16::TryParse("",x));
  EXPECT_FALSE(Int16::TryParse("a56",x));
  EXPECT_FALSE(Int16::TryParse("0 0",x));
  EXPECT_FALSE(Int16::TryParse("++000",x));
  EXPECT_FALSE(Int16::TryParse("+",x));
  EXPECT_FALSE(Int16::TryParse("-",x));
  EXPECT_FALSE(Int16::TryParse("--5",x));
  EXPECT_FALSE(Int16::TryParse("0x53",x));
  EXPECT_FALSE(Int16::TryParse("100a",x));
  EXPECT_FALSE(Int16::TryParse("10u",x));
}

TEST(Int16, TryParse_OverFlowException) {
  int16 x;
  EXPECT_TRUE(Int16::TryParse("32767",x));
  EXPECT_EQ(Int16::MaxValue, x);
  EXPECT_FALSE(Int16::TryParse("32768",x));
  EXPECT_TRUE(Int16::TryParse("-32768",x));
  EXPECT_EQ(Int16::MinValue, x);
  EXPECT_FALSE(Int16::TryParse("-32769",x));
  EXPECT_FALSE(Int16::TryParse("45111",x));
  EXPECT_FALSE(Int16::TryParse("870125",x));
}

TEST(Int16, TryParse_Binary) {
  int16 x;
  EXPECT_TRUE(Int16::TryParse("0", 2, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int16::TryParse("1", 2, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int16::TryParse("10", 2, x));
  EXPECT_EQ(2, x);
  EXPECT_TRUE(Int16::TryParse("11", 2, x));
  EXPECT_EQ(3, x);
  EXPECT_TRUE(Int16::TryParse("110", 2, x));
  EXPECT_EQ(6, x);
  EXPECT_TRUE(Int16::TryParse("-1", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int16::TryParse("-100", 2, x));
  EXPECT_EQ(-4, x);
  EXPECT_TRUE(Int16::TryParse("-1111", 2, x));
  EXPECT_EQ(-15, x);
  EXPECT_TRUE(Int16::TryParse("-1000000000000000",2,x));
  EXPECT_EQ(Int16::MinValue, x);
}

TEST(Int16, TryParse_Binary_Int16) {
  Int16 x;
  EXPECT_TRUE(Int16::TryParse("0", 2, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int16::TryParse("1", 2, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int16::TryParse("10", 2, x));
  EXPECT_EQ(2, x);
  EXPECT_TRUE(Int16::TryParse("11", 2, x));
  EXPECT_EQ(3, x);
  EXPECT_TRUE(Int16::TryParse("110", 2, x));
  EXPECT_EQ(6, x);
  EXPECT_TRUE(Int16::TryParse("-1", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int16::TryParse("-100", 2, x));
  EXPECT_EQ(-4, x);
  EXPECT_TRUE(Int16::TryParse("-1111", 2, x));
  EXPECT_EQ(-15, x);
  EXPECT_TRUE(Int16::TryParse("-1000000000000000",2,x));
  EXPECT_EQ(Int16::MinValue, x);
}

TEST(Int16, TryParse_Binary_Complement) {
  int16 x;
  EXPECT_TRUE(Int16::TryParse("1111111111111111", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int16::TryParse("1111111110010001", 2, x));
  EXPECT_EQ(-111, x);
  EXPECT_TRUE(Int16::TryParse("1000001100001101", 2, x));
  EXPECT_EQ(-31987, x);
  EXPECT_TRUE(Int16::TryParse("1000000000000000",2,x));
  EXPECT_EQ(Int16::MinValue, x);
}

TEST(Int16, TryParse_Binary_Complement_Int16) {
  Int16 x;
  EXPECT_TRUE(Int16::TryParse("1111111111111111", 2, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int16::TryParse("1111111110010001", 2, x));
  EXPECT_EQ(-111, x);
  EXPECT_TRUE(Int16::TryParse("1000001100001101", 2, x));
  EXPECT_EQ(-31987, x);
  EXPECT_TRUE(Int16::TryParse("1000000000000000",2,x));
  EXPECT_EQ(Int16::MinValue, x);
}

TEST(Int16, TryParse_Binary_Complement_Overflow) {
  int16 x;
  EXPECT_FALSE(Int16::TryParse("10000000000000000", 2, x));
  EXPECT_FALSE(Int16::TryParse("-1111111111111111", 2, x));
  EXPECT_FALSE(Int16::TryParse("-1111111110010001", 2, x));
  EXPECT_FALSE(Int16::TryParse("-1000001100001101", 2, x));
  EXPECT_FALSE(Int16::TryParse("-10000000000000000", 2, x));
}

TEST(Int16, TryParse_Binary_Complement_Overflow_Int16) {
  Int16 x;
  EXPECT_FALSE(Int16::TryParse("10000000000000000", 2, x));
  EXPECT_FALSE(Int16::TryParse("-1111111111111111", 2, x));
  EXPECT_FALSE(Int16::TryParse("-1111111110010001", 2, x));
  EXPECT_FALSE(Int16::TryParse("-1000001100001101", 2, x));
  EXPECT_FALSE(Int16::TryParse("-10000000000000000", 2, x));
}

TEST(Int16, TryParse_Exceptions_Binary) {
  int16 x;
  EXPECT_FALSE(Int16::TryParse("",2,x));
  EXPECT_FALSE(Int16::TryParse("2", 2, x));
  EXPECT_FALSE(Int16::TryParse("103", 2, x));
  EXPECT_FALSE(Int16::TryParse("++0", 2, x));
  EXPECT_FALSE(Int16::TryParse("+", 2, x));
  EXPECT_FALSE(Int16::TryParse("-", 2, x));
  EXPECT_FALSE(Int16::TryParse("--1", 2, x));
  EXPECT_FALSE(Int16::TryParse("0x53", 2, x));
  EXPECT_FALSE(Int16::TryParse("100a", 2, x));
  EXPECT_FALSE(Int16::TryParse("10u", 2, x));
}

TEST(Int16, TryParse_Exceptions_Binary_Int16) {
  Int16 x;
  EXPECT_FALSE(Int16::TryParse("",2,x));
  EXPECT_FALSE(Int16::TryParse("2", 2, x));
  EXPECT_FALSE(Int16::TryParse("103", 2, x));
  EXPECT_FALSE(Int16::TryParse("++0", 2, x));
  EXPECT_FALSE(Int16::TryParse("+", 2, x));
  EXPECT_FALSE(Int16::TryParse("-", 2, x));
  EXPECT_FALSE(Int16::TryParse("--1", 2, x));
  EXPECT_FALSE(Int16::TryParse("0x53", 2, x));
  EXPECT_FALSE(Int16::TryParse("100a", 2, x));
  EXPECT_FALSE(Int16::TryParse("10u", 2, x));
}

TEST(Int16, TryParse_Octal) {
  int16 x;
  EXPECT_TRUE(Int16::TryParse("0", 8, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int16::TryParse("1", 8, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int16::TryParse("14", 8, x));
  EXPECT_EQ(12, x);
  EXPECT_TRUE(Int16::TryParse("70", 8, x));
  EXPECT_EQ(56, x);
  EXPECT_TRUE(Int16::TryParse("1131", 8, x));
  EXPECT_EQ(601, x);
  EXPECT_TRUE(Int16::TryParse("-1", 8, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int16::TryParse("-4", 8, x));
  EXPECT_EQ(-4, x);
  EXPECT_TRUE(Int16::TryParse("-17", 8, x));
  EXPECT_EQ(-15, x);
}

TEST(Int16, TryParse_Octal_Int16) {
  Int16 x;
  EXPECT_TRUE(Int16::TryParse("0", 8, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int16::TryParse("1", 8, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int16::TryParse("14", 8, x));
  EXPECT_EQ(12, x);
  EXPECT_TRUE(Int16::TryParse("70", 8, x));
  EXPECT_EQ(56, x);
  EXPECT_TRUE(Int16::TryParse("1131", 8, x));
  EXPECT_EQ(601, x);
  EXPECT_TRUE(Int16::TryParse("-1", 8, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int16::TryParse("-4", 8, x));
  EXPECT_EQ(-4, x);
  EXPECT_TRUE(Int16::TryParse("-17", 8, x));
  EXPECT_EQ(-15, x);
}

TEST(Int16, TryParse_Hexadecimal) {
  int16 x;
  EXPECT_TRUE(Int16::TryParse("0", 16, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int16::TryParse("1", 16, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int16::TryParse("C", 16, x));
  EXPECT_EQ(12, x);
  EXPECT_TRUE(Int16::TryParse("3c", 16, x));
  EXPECT_EQ(60, x);
  EXPECT_TRUE(Int16::TryParse("FE3", 16, x));
  EXPECT_EQ(4067, x);
  EXPECT_TRUE(Int16::TryParse("-4A", 16, x));
  EXPECT_EQ(-74, x);
  EXPECT_TRUE(Int16::TryParse("-6BCD", 16, x));
  EXPECT_EQ(-27597, x);
}

TEST(Int16, TryParse_Hexadecimal_Int16) {
  Int16 x;
  EXPECT_TRUE(Int16::TryParse("0", 16, x));
  EXPECT_EQ(0, x);
  EXPECT_TRUE(Int16::TryParse("1", 16, x));
  EXPECT_EQ(1, x);
  EXPECT_TRUE(Int16::TryParse("C", 16, x));
  EXPECT_EQ(12, x);
  EXPECT_TRUE(Int16::TryParse("3c", 16, x));
  EXPECT_EQ(60, x);
  EXPECT_TRUE(Int16::TryParse("FE3", 16, x));
  EXPECT_EQ(4067, x);
  EXPECT_TRUE(Int16::TryParse("-4A", 16, x));
  EXPECT_EQ(-74, x);
  EXPECT_TRUE(Int16::TryParse("-6BCD", 16, x));
  EXPECT_EQ(-27597, x);
}


TEST(Int16, TryParse_Hexadecimal_Complement) {
  int16 x;
  EXPECT_TRUE(Int16::TryParse("FFFF", 16, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int16::TryParse("0xFEB3", 16, x));
  EXPECT_EQ(-333, x);
  EXPECT_TRUE(Int16::TryParse("CED5", 16, x));
  EXPECT_EQ(-12587, x);
  EXPECT_TRUE(Int16::TryParse("0x8000", 16,x));
  EXPECT_EQ(Int16::MinValue, x);
  EXPECT_TRUE(Int16::TryParse("-0x8000", 16,x));
  EXPECT_EQ(Int16::MinValue, x);
}

TEST(Int16, TryParse_Hexadecimal_Complement_Int16) {
  Int16 x;
  EXPECT_TRUE(Int16::TryParse("FFFF", 16, x));
  EXPECT_EQ(-1, x);
  EXPECT_TRUE(Int16::TryParse("0xFEB3", 16, x));
  EXPECT_EQ(-333, x);
  EXPECT_TRUE(Int16::TryParse("CED5", 16, x));
  EXPECT_EQ(-12587, x);
  EXPECT_TRUE(Int16::TryParse("0x8000", 16,x));
  EXPECT_EQ(Int16::MinValue, x);
  EXPECT_TRUE(Int16::TryParse("-0x8000", 16,x));
  EXPECT_EQ(Int16::MinValue, x);
}

TEST(Int16, TryParse_Hexadecimal_Complement_Overflow) {
  int16 x;
  EXPECT_FALSE(Int16::TryParse("10000", 16,x));
  EXPECT_FALSE(Int16::TryParse("0x10100", 16,x));
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
      String type = sw_typeof(T).Name;
      String suffix = type == "Single" ? "f" : "";

      try {
        MethodInfo method = sw_typeof(T).GetMethod("Parse", new Type[] {sw_typeof(String)});
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
