#include <Switch/System/UInt16.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/FormatException.hpp>
#include <Switch/System/OverflowException.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(UInt16Test, MaxValue) {
    ASSERT_EQ(0xFFFFu, UInt16::MaxValue);
  }

  TEST(UInt16Test, MinValue) {
    ASSERT_EQ(0u, UInt16::MinValue);
  }

  TEST(UInt16Test, DefaultValue) {
    ASSERT_EQ(0u, UInt16());
  }

  TEST(UInt16Test, CtorValue) {
    ASSERT_EQ(10u, UInt16(10u));
    ASSERT_EQ(12654u, UInt16(12654u));
    ASSERT_EQ(0u, UInt16(0u));
  }

  TEST(UInt16Test, Parse) {
    ASSERT_EQ(0u, UInt16::Parse("0"));
    ASSERT_EQ(1u, UInt16::Parse("1"));
    ASSERT_EQ(123u, UInt16::Parse("123"));
    ASSERT_EQ(12365u, UInt16::Parse("12365"));
    ASSERT_EQ(0xFFFFu, UInt16::Parse("65535"));
  }

  TEST(UInt16Test, Parse_Sign) {
    ASSERT_EQ(5u, UInt16::Parse("+5"));
    ASSERT_EQ(0u, UInt16::Parse("-0"));
    ASSERT_THROW(UInt16::Parse("-1"), OverflowException);
  }

  TEST(UInt16Test, Parse_Leading_Zeros) {
    ASSERT_EQ(0u, UInt16::Parse("0"));
    ASSERT_EQ(0u, UInt16::Parse("00"));
    ASSERT_EQ(0u, UInt16::Parse("000"));
    ASSERT_EQ(1u, UInt16::Parse("01"));
    ASSERT_EQ(1u, UInt16::Parse("0001"));
    ASSERT_EQ(99u, UInt16::Parse("099"));
    ASSERT_EQ(999u, UInt16::Parse("0000999"));
  }

  TEST(UInt16Test, Parse_Spaces) {
    ASSERT_EQ(5u, UInt16::Parse(" 5"));
    ASSERT_EQ(5u, UInt16::Parse("     5"));
    ASSERT_EQ(5u, UInt16::Parse("5 "));
    ASSERT_EQ(51u, UInt16::Parse("51     "));
    ASSERT_EQ(5u, UInt16::Parse(" 5      "));
    ASSERT_EQ(52u, UInt16::Parse("        52 "));
  }

  TEST(UInt16Test, Parse_FormatException) {
    ASSERT_THROW(UInt16::Parse(""), FormatException);
    ASSERT_THROW(UInt16::Parse("a56"), FormatException);
    ASSERT_THROW(UInt16::Parse("0 0"), FormatException);
    ASSERT_THROW(UInt16::Parse("++000"), FormatException);
    ASSERT_THROW(UInt16::Parse("+"), FormatException);
    ASSERT_THROW(UInt16::Parse("-"), FormatException);
    ASSERT_THROW(UInt16::Parse("--5"), FormatException);
    ASSERT_THROW(UInt16::Parse("0x53"), FormatException);
    ASSERT_THROW(UInt16::Parse("100a"), FormatException);
    ASSERT_THROW(UInt16::Parse("10u"), FormatException);
  }

  TEST(UInt16Test, Parse_OverflowException) {
    ASSERT_THROW(UInt16::Parse("-1"), OverflowException);
    ASSERT_THROW(UInt16::Parse("-15602"), OverflowException);
    ASSERT_EQ(0xFFFFu, UInt16::Parse("65535"));
    ASSERT_EQ(0xFFFFu, UInt16::Parse("0065535"));
    ASSERT_THROW(UInt16::Parse("65536"), OverflowException);
    ASSERT_THROW(UInt16::Parse("4294967296"), OverflowException);
    ASSERT_THROW(UInt16::Parse("5294967295"), OverflowException);
  }

  TEST(UInt16Test, Parse_Binary) {
    ASSERT_EQ(0u, UInt16::Parse("0", 2));
    ASSERT_EQ(1u, UInt16::Parse("1", 2));
    ASSERT_EQ(2u, UInt16::Parse("10", 2));
    ASSERT_EQ(3u, UInt16::Parse("11", 2));
    ASSERT_EQ(6u, UInt16::Parse("110", 2));
  }

  TEST(UInt16Test, Parse_Exceptions_Binary) {
    ASSERT_THROW(UInt16::Parse("", 2), FormatException);
    ASSERT_THROW(UInt16::Parse("2", 2), FormatException);
    ASSERT_THROW(UInt16::Parse("103", 2), FormatException);
    ASSERT_THROW(UInt16::Parse("++0", 2), FormatException);
    ASSERT_THROW(UInt16::Parse("+", 2), FormatException);
    ASSERT_THROW(UInt16::Parse("-", 2), FormatException);
    ASSERT_THROW(UInt16::Parse("--1", 2), FormatException);
    ASSERT_THROW(UInt16::Parse("0x53", 2), FormatException);
    ASSERT_THROW(UInt16::Parse("100a", 2), FormatException);
    ASSERT_THROW(UInt16::Parse("10u", 2), FormatException);
  }

  TEST(UInt16Test, Parse_Octal) {
    ASSERT_EQ(0u, UInt16::Parse("0", 8));
    ASSERT_EQ(1u, UInt16::Parse("1", 8));
    ASSERT_EQ(12u, UInt16::Parse("14", 8));
    ASSERT_EQ(56u, UInt16::Parse("70", 8));
    ASSERT_EQ(601u, UInt16::Parse("1131", 8));
  }

  TEST(UInt16Test, Parse_Hexadecimal) {
    ASSERT_EQ(0u, UInt16::Parse("0", 16));
    ASSERT_EQ(1u, UInt16::Parse("1", 16));
    ASSERT_EQ(0xCu, UInt16::Parse("C", 16));
    ASSERT_EQ(0x3Cu, UInt16::Parse("3c", 16));
    ASSERT_EQ(0xFE3u, UInt16::Parse("FE3", 16));
    ASSERT_EQ(0xFFFFu, UInt16::Parse("FFFF", 16));
    ASSERT_THROW(UInt16::Parse("10000", 16), OverflowException);
  }

  TEST(UInt16Test, TryParse) {
    uint16 x;
    ASSERT_TRUE(UInt16::TryParse("0", x));
    ASSERT_EQ(0u, x);
    ASSERT_TRUE(UInt16::TryParse("1", x));
    ASSERT_EQ(1u, x);
    ASSERT_TRUE(UInt16::TryParse("123", x));
    ASSERT_EQ(123u, x);
    ASSERT_TRUE(UInt16::TryParse("12365", x));
    ASSERT_EQ(12365u, x);
    ASSERT_TRUE(UInt16::TryParse("65535", x));
    ASSERT_EQ(0xFFFFu, x);
  }

  TEST(UInt16Test, TryParse_Sign) {
    uint16 x;
    ASSERT_TRUE(UInt16::TryParse("+5", x));
    ASSERT_EQ(5u, x);
    ASSERT_TRUE(UInt16::TryParse("-0", x));
    ASSERT_EQ(0u, x);
    ASSERT_FALSE(UInt16::TryParse("-1", x));
  }

  TEST(UInt16Test, TryParse_Leading_Zeros) {
    uint16 x;
    ASSERT_TRUE(UInt16::TryParse("0", x));
    ASSERT_EQ(0u, x);
    ASSERT_TRUE(UInt16::TryParse("00", x));
    ASSERT_EQ(0u, x);
    ASSERT_TRUE(UInt16::TryParse("000", x));
    ASSERT_EQ(0u, x);
    ASSERT_TRUE(UInt16::TryParse("01", x));
    ASSERT_EQ(1u, x);
    ASSERT_TRUE(UInt16::TryParse("0001", x));
    ASSERT_EQ(1u, x);
    ASSERT_TRUE(UInt16::TryParse("099", x));
    ASSERT_EQ(99u, x);
    ASSERT_TRUE(UInt16::TryParse("0000999", x));
    ASSERT_EQ(999u, x);
  }

  TEST(UInt16Test, TryParse_Spaces) {
    uint16 x;
    ASSERT_TRUE(UInt16::TryParse(" 5", x));
    ASSERT_EQ(5u, x);
    ASSERT_TRUE(UInt16::TryParse("     5", x));
    ASSERT_EQ(5u, x);
    ASSERT_TRUE(UInt16::TryParse("5 ", x));
    ASSERT_EQ(5u, x);
    ASSERT_TRUE(UInt16::TryParse("51     ", x));
    ASSERT_EQ(51u, x);
    ASSERT_TRUE(UInt16::TryParse(" 5      ", x));
    ASSERT_EQ(5u, x);
    ASSERT_TRUE(UInt16::TryParse("        52 ", x));
    ASSERT_EQ(52u, x);
  }

  TEST(UInt16Test, TryParse_FormatException) {
    uint16 x;
    ASSERT_FALSE(UInt16::TryParse("", x));
    ASSERT_FALSE(UInt16::TryParse("a56", x));
    ASSERT_FALSE(UInt16::TryParse("0 0", x));
    ASSERT_FALSE(UInt16::TryParse("++000", x));
    ASSERT_FALSE(UInt16::TryParse("+", x));
    ASSERT_FALSE(UInt16::TryParse("-", x));
    ASSERT_FALSE(UInt16::TryParse("--5", x));
    ASSERT_FALSE(UInt16::TryParse("0x53", x));
    ASSERT_FALSE(UInt16::TryParse("100a", x));
    ASSERT_FALSE(UInt16::TryParse("10u", x));
  }

  TEST(UInt16Test, TryParse_OverflowException) {
    uint16 x;
    ASSERT_FALSE(UInt16::TryParse("-1", x));
    ASSERT_FALSE(UInt16::TryParse("-15602", x));
    ASSERT_TRUE(UInt16::TryParse("65535", x));
    ASSERT_EQ(0xFFFFu, x);
    ASSERT_TRUE(UInt16::TryParse("0065535", x));
    ASSERT_EQ(0xFFFFu, x);
    ASSERT_FALSE(UInt16::TryParse("65536", x));
    ASSERT_FALSE(UInt16::TryParse("4294967296", x));
    ASSERT_FALSE(UInt16::TryParse("5294967295", x));
  }

  TEST(UInt16Test, TryParse_Binary) {
    uint16 x;
    ASSERT_TRUE(UInt16::TryParse("0", 2, x));
    ASSERT_EQ(0u, x);
    ASSERT_TRUE(UInt16::TryParse("1", 2, x));
    ASSERT_EQ(1u, x);
    ASSERT_TRUE(UInt16::TryParse("10", 2, x));
    ASSERT_EQ(2u, x);
    ASSERT_TRUE(UInt16::TryParse("11", 2, x));
    ASSERT_EQ(3u, x);
    ASSERT_TRUE(UInt16::TryParse("110", 2, x));
    ASSERT_EQ(6u, x);
  }

  TEST(UInt16Test, TryParse_Exceptions_Binary) {
    uint16 x;
    ASSERT_FALSE(UInt16::TryParse("", 2, x));
    ASSERT_FALSE(UInt16::TryParse("2", 2, x));
    ASSERT_FALSE(UInt16::TryParse("103", 2, x));
    ASSERT_FALSE(UInt16::TryParse("++0", 2, x));
    ASSERT_FALSE(UInt16::TryParse("+", 2, x));
    ASSERT_FALSE(UInt16::TryParse("-", 2, x));
    ASSERT_FALSE(UInt16::TryParse("--1", 2, x));
    ASSERT_FALSE(UInt16::TryParse("0x53", 2, x));
    ASSERT_FALSE(UInt16::TryParse("100a", 2, x));
    ASSERT_FALSE(UInt16::TryParse("10u", 2, x));
  }

  TEST(UInt16Test, TryParse_Octal) {
    uint16 x;
    ASSERT_TRUE(UInt16::TryParse("0", 8, x));
    ASSERT_EQ(0u, x);
    ASSERT_TRUE(UInt16::TryParse("1", 8, x));
    ASSERT_EQ(1u, x);
    ASSERT_TRUE(UInt16::TryParse("14", 8, x));
    ASSERT_EQ(12u, x);
    ASSERT_TRUE(UInt16::TryParse("70", 8, x));
    ASSERT_EQ(56u, x);
    ASSERT_TRUE(UInt16::TryParse("1131", 8, x));
    ASSERT_EQ(601u, x);
  }

  TEST(UInt16Test, TryParse_Hexadecimal) {
    uint16 x;
    ASSERT_TRUE(UInt16::TryParse("0", 16, x));
    ASSERT_EQ(0u, x);
    ASSERT_TRUE(UInt16::TryParse("1", 16, x));
    ASSERT_EQ(1u, x);
    ASSERT_TRUE(UInt16::TryParse("C", 16, x));
    ASSERT_EQ(0xCu, x);
    ASSERT_TRUE(UInt16::TryParse("3c", 16, x));
    ASSERT_EQ(0x3Cu, x);
    ASSERT_TRUE(UInt16::TryParse("FE3", 16, x));
    ASSERT_EQ(0xFE3u, x);
    ASSERT_TRUE(UInt16::TryParse("FFFF", 16, x));
    ASSERT_EQ(0xFFFFu, x);
    ASSERT_FALSE(UInt16::TryParse("10000",  16, x));
  }

  TEST(UInt16Test, TryParse_UInt16) {
    UInt16 x;
    ASSERT_TRUE(UInt16::TryParse("0", x));
    ASSERT_EQ(0u, x);
    ASSERT_TRUE(UInt16::TryParse("1", x));
    ASSERT_EQ(1u, x);
    ASSERT_TRUE(UInt16::TryParse("123", x));
    ASSERT_EQ(123u, x);
    ASSERT_TRUE(UInt16::TryParse("12365", x));
    ASSERT_EQ(12365u, x);
    ASSERT_TRUE(UInt16::TryParse("65535", x));
    ASSERT_EQ(0xFFFFu, x);
  }

  TEST(UInt16Test, TryParse_Sign_UInt16) {
    UInt16 x;
    ASSERT_TRUE(UInt16::TryParse("+5", x));
    ASSERT_EQ(5u, x);
    ASSERT_TRUE(UInt16::TryParse("-0", x));
    ASSERT_EQ(0u, x);
    ASSERT_FALSE(UInt16::TryParse("-1", x));
  }

  TEST(UInt16Test, TryParse_Leading_Zeros_UInt16) {
    UInt16 x;
    ASSERT_TRUE(UInt16::TryParse("0", x));
    ASSERT_EQ(0u, x);
    ASSERT_TRUE(UInt16::TryParse("00", x));
    ASSERT_EQ(0u, x);
    ASSERT_TRUE(UInt16::TryParse("000", x));
    ASSERT_EQ(0u, x);
    ASSERT_TRUE(UInt16::TryParse("01", x));
    ASSERT_EQ(1u, x);
    ASSERT_TRUE(UInt16::TryParse("0001", x));
    ASSERT_EQ(1u, x);
    ASSERT_TRUE(UInt16::TryParse("099", x));
    ASSERT_EQ(99u, x);
    ASSERT_TRUE(UInt16::TryParse("0000999", x));
    ASSERT_EQ(999u, x);
  }

  TEST(UInt16Test, TryParse_Spaces_UInt16) {
    UInt16 x;
    ASSERT_TRUE(UInt16::TryParse(" 5", x));
    ASSERT_EQ(5u, x);
    ASSERT_TRUE(UInt16::TryParse("     5", x));
    ASSERT_EQ(5u, x);
    ASSERT_TRUE(UInt16::TryParse("5 ", x));
    ASSERT_EQ(5u, x);
    ASSERT_TRUE(UInt16::TryParse("51     ", x));
    ASSERT_EQ(51u, x);
    ASSERT_TRUE(UInt16::TryParse(" 5      ", x));
    ASSERT_EQ(5u, x);
    ASSERT_TRUE(UInt16::TryParse("        52 ", x));
    ASSERT_EQ(52u, x);
  }

  TEST(UInt16Test, TryParse_FormatException_UInt16) {
    UInt16 x;
    ASSERT_FALSE(UInt16::TryParse("", x));
    ASSERT_FALSE(UInt16::TryParse("a56", x));
    ASSERT_FALSE(UInt16::TryParse("0 0", x));
    ASSERT_FALSE(UInt16::TryParse("++000", x));
    ASSERT_FALSE(UInt16::TryParse("+", x));
    ASSERT_FALSE(UInt16::TryParse("-", x));
    ASSERT_FALSE(UInt16::TryParse("--5", x));
    ASSERT_FALSE(UInt16::TryParse("0x53", x));
    ASSERT_FALSE(UInt16::TryParse("100a", x));
    ASSERT_FALSE(UInt16::TryParse("10u", x));
  }

  TEST(UInt16Test, TryParse_OverflowException_UInt16) {
    UInt16 x;
    ASSERT_FALSE(UInt16::TryParse("-1", x));
    ASSERT_FALSE(UInt16::TryParse("-15602", x));
    ASSERT_TRUE(UInt16::TryParse("65535", x));
    ASSERT_EQ(0xFFFFu, x);
    ASSERT_TRUE(UInt16::TryParse("0065535", x));
    ASSERT_EQ(0xFFFFu, x);
    ASSERT_FALSE(UInt16::TryParse("65536", x));
    ASSERT_FALSE(UInt16::TryParse("4294967296", x));
    ASSERT_FALSE(UInt16::TryParse("5294967295", x));
  }

  TEST(UInt16Test, TryParse_Binary_UInt16) {
    UInt16 x;
    ASSERT_TRUE(UInt16::TryParse("0", 2, x));
    ASSERT_EQ(0u, x);
    ASSERT_TRUE(UInt16::TryParse("1", 2, x));
    ASSERT_EQ(1u, x);
    ASSERT_TRUE(UInt16::TryParse("10", 2, x));
    ASSERT_EQ(2u, x);
    ASSERT_TRUE(UInt16::TryParse("11", 2, x));
    ASSERT_EQ(3u, x);
    ASSERT_TRUE(UInt16::TryParse("110", 2, x));
    ASSERT_EQ(6u, x);
  }

  TEST(UInt16Test, TryParse_Exceptions_Binary_UInt16) {
    UInt16 x;
    ASSERT_FALSE(UInt16::TryParse("", 2, x));
    ASSERT_FALSE(UInt16::TryParse("2", 2, x));
    ASSERT_FALSE(UInt16::TryParse("103", 2, x));
    ASSERT_FALSE(UInt16::TryParse("++0", 2, x));
    ASSERT_FALSE(UInt16::TryParse("+", 2, x));
    ASSERT_FALSE(UInt16::TryParse("-", 2, x));
    ASSERT_FALSE(UInt16::TryParse("--1", 2, x));
    ASSERT_FALSE(UInt16::TryParse("0x53", 2, x));
    ASSERT_FALSE(UInt16::TryParse("100a", 2, x));
    ASSERT_FALSE(UInt16::TryParse("10u", 2, x));
  }

  TEST(UInt16Test, TryParse_Octal_UInt16) {
    UInt16 x;
    ASSERT_TRUE(UInt16::TryParse("0", 8, x));
    ASSERT_EQ(0u, x);
    ASSERT_TRUE(UInt16::TryParse("1", 8, x));
    ASSERT_EQ(1u, x);
    ASSERT_TRUE(UInt16::TryParse("14", 8, x));
    ASSERT_EQ(12u, x);
    ASSERT_TRUE(UInt16::TryParse("70", 8, x));
    ASSERT_EQ(56u, x);
    ASSERT_TRUE(UInt16::TryParse("1131", 8, x));
    ASSERT_EQ(601u, x);
  }

  TEST(UInt16Test, TryParse_Hexadecimal_UInt16) {
    UInt16 x;
    ASSERT_TRUE(UInt16::TryParse("0", 16, x));
    ASSERT_EQ(0u, x);
    ASSERT_TRUE(UInt16::TryParse("1", 16, x));
    ASSERT_EQ(1u, x);
    ASSERT_TRUE(UInt16::TryParse("C", 16, x));
    ASSERT_EQ(0xCu, x);
    ASSERT_TRUE(UInt16::TryParse("3c", 16, x));
    ASSERT_EQ(0x3Cu, x);
    ASSERT_TRUE(UInt16::TryParse("FE3", 16, x));
    ASSERT_EQ(0xFE3u, x);
    ASSERT_TRUE(UInt16::TryParse("FFFF", 16, x));
    ASSERT_EQ(0xFFFFu, x);
    ASSERT_FALSE(UInt16::TryParse("10000",  16, x));
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
      MakeTest<UInt16>(s, 5, "");

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
