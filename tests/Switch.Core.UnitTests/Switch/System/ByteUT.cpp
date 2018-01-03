#include <Switch/System/Byte.hpp>
#include <Switch/System/FormatException.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {

  TEST(ByteTest, MaxValue) {
    ASSERT_EQ(255, Byte::MaxValue);
  }

  TEST(ByteTest, MinValue) {
    ASSERT_EQ(0, Byte::MinValue);
  }

  TEST(ByteTest, DefaultValue) {
    ASSERT_EQ(0, Byte());
  }

  TEST(ByteTest, CtorValue) {
    ASSERT_EQ(10, Byte(10));
    ASSERT_EQ(123, Byte(123));
    ASSERT_EQ(205, Byte(205));
    ASSERT_EQ(0, Byte(0));
  }

  TEST(ByteTest, Parse) {
    ASSERT_EQ(0, Byte::Parse("0"));
    ASSERT_EQ(1, Byte::Parse("1"));
    ASSERT_EQ(18, Byte::Parse("18"));
    ASSERT_EQ(127, Byte::Parse("127"));
    ASSERT_EQ(255, Byte::Parse("255"));
  }

  TEST(ByteTest, Parse_Sign) {
    ASSERT_EQ(0, Byte::Parse("+0"));
    ASSERT_EQ(0, Byte::Parse("-0"));
    ASSERT_EQ(12, Byte::Parse("+12"));
    ASSERT_EQ(255, Byte::Parse("+255"));
  }

  TEST(ByteTest, Parse_Leading_Zeros) {
    ASSERT_EQ(0, Byte::Parse("0"));
    ASSERT_EQ(0, Byte::Parse("00"));
    ASSERT_EQ(0, Byte::Parse("000"));
    ASSERT_EQ(1, Byte::Parse("01"));
    ASSERT_EQ(1, Byte::Parse("0001"));
    ASSERT_EQ(99, Byte::Parse("099"));
  }

  TEST(ByteTest, Parse_Spaces) {
    ASSERT_EQ(5, Byte::Parse(" 5"));
    ASSERT_EQ(5, Byte::Parse("     5"));
    ASSERT_EQ(5, Byte::Parse("5 "));
    ASSERT_EQ(51, Byte::Parse("51     "));
    ASSERT_EQ(5, Byte::Parse(" 5      "));
    ASSERT_EQ(52, Byte::Parse("        52 "));
  }

  TEST(ByteTest, Parse_FormatException) {
    ASSERT_THROW(Byte::Parse(""), FormatException);
    ASSERT_THROW(Byte::Parse("a56"), FormatException);
    ASSERT_THROW(Byte::Parse("0 0"), FormatException);
    ASSERT_THROW(Byte::Parse("++000"), FormatException);
    ASSERT_THROW(Byte::Parse("+"), FormatException);
    ASSERT_THROW(Byte::Parse("-"), FormatException);
    ASSERT_THROW(Byte::Parse("--5"), FormatException);
    ASSERT_THROW(Byte::Parse("0x53"), FormatException);
    ASSERT_THROW(Byte::Parse("100a"), FormatException);
    ASSERT_THROW(Byte::Parse("10u"), FormatException);
  }

  TEST(ByteTest, Parse_OverflowException) {
    ASSERT_EQ(0xFF, Byte::Parse("255"));
    ASSERT_THROW(Byte::Parse("256"), OverflowException);
    ASSERT_THROW(Byte::Parse("1233"), OverflowException);
    ASSERT_THROW(Byte::Parse("-1"), OverflowException);
    ASSERT_THROW(Byte::Parse("-2"), OverflowException);
    ASSERT_THROW(Byte::Parse("-256"), OverflowException);
    ASSERT_THROW(Byte::Parse("-300"), OverflowException);
  }

  TEST(ByteTest, Parse_Binary) {
    ASSERT_EQ(0, Byte::Parse("0b", 2));
    ASSERT_EQ(1, Byte::Parse("1", 2));
    ASSERT_EQ(2, Byte::Parse("10b", 2));
    ASSERT_EQ(3, Byte::Parse("11", 2));
    ASSERT_EQ(6, Byte::Parse("110", 2));
  }

  TEST(ByteTest, Parse_Exceptions_Binary) {
    ASSERT_THROW(Byte::Parse("", 2), FormatException);
    ASSERT_THROW(Byte::Parse("2", 2), FormatException);
    ASSERT_THROW(Byte::Parse("103", 2), FormatException);
    ASSERT_THROW(Byte::Parse("++0", 2), FormatException);
    ASSERT_THROW(Byte::Parse("+", 2), FormatException);
    ASSERT_THROW(Byte::Parse("-", 2), FormatException);
    ASSERT_THROW(Byte::Parse("--1", 2), FormatException);
    ASSERT_THROW(Byte::Parse("0x53", 2), FormatException);
    ASSERT_THROW(Byte::Parse("100a", 2), FormatException);
    ASSERT_THROW(Byte::Parse("10u", 2), FormatException);
  }

  TEST(ByteTest, Parse_Octal) {
    ASSERT_EQ(0, Byte::Parse("0", 8));
    ASSERT_EQ(1, Byte::Parse("1", 8));
    ASSERT_EQ(12, Byte::Parse("14", 8));
    ASSERT_EQ(56, Byte::Parse("70", 8));
  }

  TEST(ByteTest, Parse_Hexadecimal) {
    ASSERT_EQ(0, Byte::Parse("0x0", 16));
    ASSERT_EQ(0, Byte::Parse(" 0x0", 16));
    ASSERT_EQ(0, Byte::Parse(" 0x000", 16));
    ASSERT_EQ(1, Byte::Parse("1", 16));
    ASSERT_EQ(0xC, Byte::Parse("C", 16));
    ASSERT_EQ(0x3C, Byte::Parse("3c", 16));
    ASSERT_EQ(0x3C, Byte::Parse("0x3c", 16));
    ASSERT_EQ(0x3C, Byte::Parse("0X3c", 16));
    ASSERT_EQ(0x3C, Byte::Parse("0x3C", 16));
  }

  TEST(ByteTest, Parse_Hexadecimal_Prefix_OverflowExceptions) {
    ASSERT_THROW(Byte::Parse("0x100", 16), OverflowException);
  }

  TEST(ByteTest, Parse_Hexadecimal_Prefix_Exceptions) {
    ASSERT_THROW(Byte::Parse("x", 16), FormatException);
    ASSERT_THROW(Byte::Parse("x0", 16), FormatException);
    ASSERT_THROW(Byte::Parse("0x", 16), FormatException);
    ASSERT_THROW(Byte::Parse("00x0", 16), FormatException);
    ASSERT_THROW(Byte::Parse("0 x0", 16), FormatException);
    ASSERT_THROW(Byte::Parse("0x 0", 16), FormatException);
    ASSERT_THROW(Byte::Parse("X", 16), FormatException);
    ASSERT_THROW(Byte::Parse("X0", 16), FormatException);
    ASSERT_THROW(Byte::Parse("0X", 16), FormatException);
    ASSERT_THROW(Byte::Parse("00X0", 16), FormatException);
    ASSERT_THROW(Byte::Parse("0 X0", 16), FormatException);
    ASSERT_THROW(Byte::Parse("0X 0", 16), FormatException);
  }

  TEST(ByteTest, TryParse) {
    byte b;
    ASSERT_TRUE(Byte::TryParse("0", b));
    ASSERT_EQ(0, b);
    ASSERT_TRUE(Byte::TryParse("1", b));
    ASSERT_EQ(1, b);
    ASSERT_TRUE(Byte::TryParse("18", b));
    ASSERT_EQ(18, b);
    ASSERT_TRUE(Byte::TryParse("127", b));
    ASSERT_EQ(127, b);
    ASSERT_TRUE(Byte::TryParse("255", b));
    ASSERT_EQ(255, b);
  }

  TEST(ByteTest, TryParse_Sign) {
    byte b;
    ASSERT_TRUE(Byte::TryParse("+0", b));
    ASSERT_EQ(0, b);
    ASSERT_TRUE(Byte::TryParse("-0", b));
    ASSERT_EQ(0, b);
    ASSERT_TRUE(Byte::TryParse("+12", b));
    ASSERT_EQ(12, b);
    ASSERT_TRUE(Byte::TryParse("+255", b));
    ASSERT_EQ(255, b);
  }

  TEST(ByteTest, TryParse_Leading_Zeros) {
    byte b;
    ASSERT_TRUE(Byte::TryParse("0", b));
    ASSERT_EQ(0, b);
    ASSERT_TRUE(Byte::TryParse("00", b));
    ASSERT_EQ(0, b);
    ASSERT_TRUE(Byte::TryParse("000", b));
    ASSERT_EQ(0, b);
    ASSERT_TRUE(Byte::TryParse("01", b));
    ASSERT_EQ(1, b);
    ASSERT_TRUE(Byte::TryParse("0001", b));
    ASSERT_EQ(1, b);
    ASSERT_TRUE(Byte::TryParse("099", b));
    ASSERT_EQ(99, b);
  }

  TEST(ByteTest, TryParse_Spaces) {
    byte b;
    ASSERT_TRUE(Byte::TryParse(" 5", b));
    ASSERT_EQ(5, b);
    ASSERT_TRUE(Byte::TryParse("     5", b));
    ASSERT_EQ(5, b);
    ASSERT_TRUE(Byte::TryParse("5 ", b));
    ASSERT_EQ(5, b);
    ASSERT_TRUE(Byte::TryParse("51     ", b));
    ASSERT_EQ(51, b);
    ASSERT_TRUE(Byte::TryParse(" 5      ", b));
    ASSERT_EQ(5, b);
    ASSERT_TRUE(Byte::TryParse("        52 ", b));
    ASSERT_EQ(52, b);
  }

  TEST(ByteTest, TryParse_Fail_Format) {
    byte b;
    ASSERT_FALSE(Byte::TryParse("", b));
    ASSERT_FALSE(Byte::TryParse("a56", b));
    ASSERT_FALSE(Byte::TryParse("0 0", b));
    ASSERT_FALSE(Byte::TryParse("++000", b));
    ASSERT_FALSE(Byte::TryParse("+", b));
    ASSERT_FALSE(Byte::TryParse("-", b));
    ASSERT_FALSE(Byte::TryParse("--5", b));
    ASSERT_FALSE(Byte::TryParse("0x53", b));
    ASSERT_FALSE(Byte::TryParse("100a", b));
    ASSERT_FALSE(Byte::TryParse("10u", b));
  }

  TEST(ByteTest, TryParse_Fail_Overflow) {
    byte b;
    ASSERT_TRUE(Byte::TryParse("255", b));
    ASSERT_EQ(0xFF, b);
    ASSERT_FALSE(Byte::TryParse("256", b));
    ASSERT_FALSE(Byte::TryParse("1233", b));
    ASSERT_FALSE(Byte::TryParse("-1", b));
    ASSERT_FALSE(Byte::TryParse("-2", b));
    ASSERT_FALSE(Byte::TryParse("-256", b));
    ASSERT_FALSE(Byte::TryParse("-300", b));
  }

  TEST(ByteTest, TryParse_Binary) {
    byte b;
    ASSERT_TRUE(Byte::TryParse("0b", 2, b));
    ASSERT_EQ(0, b);
    ASSERT_TRUE(Byte::TryParse("1", 2, b));
    ASSERT_EQ(1, b);
    ASSERT_TRUE(Byte::TryParse("10b", 2, b));
    ASSERT_EQ(2, b);
    ASSERT_TRUE(Byte::TryParse("11", 2, b));
    ASSERT_EQ(3, b);
    ASSERT_TRUE(Byte::TryParse("110", 2, b));
    ASSERT_EQ(6, b);
  }

  TEST(ByteTest, TryParse_Binary_Fail) {
    byte b;
    ASSERT_FALSE(Byte::TryParse("", 2, b));
    ASSERT_FALSE(Byte::TryParse("2", 2, b));
    ASSERT_FALSE(Byte::TryParse("103", 2, b));
    ASSERT_FALSE(Byte::TryParse("++0", 2, b));
    ASSERT_FALSE(Byte::TryParse("+", 2, b));
    ASSERT_FALSE(Byte::TryParse("-", 2, b));
    ASSERT_FALSE(Byte::TryParse("--1", 2, b));
    ASSERT_FALSE(Byte::TryParse("0x53", 2, b));
    ASSERT_FALSE(Byte::TryParse("100a", 2, b));
    ASSERT_FALSE(Byte::TryParse("10u", 2, b));
  }

  TEST(ByteTest, TryParse_Octal) {
    byte b;
    ASSERT_TRUE(Byte::TryParse("0", 8, b));
    ASSERT_EQ(0, b);
    ASSERT_TRUE(Byte::TryParse("1", 8, b));
    ASSERT_EQ(1, b);
    ASSERT_TRUE(Byte::TryParse("14", 8, b));
    ASSERT_EQ(12, b);
    ASSERT_TRUE(Byte::TryParse("70", 8, b));
    ASSERT_EQ(56, b);
  }

  TEST(ByteTest, TryParse_Hexadecimal) {
    byte b;
    ASSERT_TRUE(Byte::TryParse("0x0", 16, b));
    ASSERT_EQ(0, b);
    ASSERT_TRUE(Byte::TryParse(" 0x0", 16, b));
    ASSERT_EQ(0, b);
    ASSERT_TRUE(Byte::TryParse(" 0x000", 16, b));
    ASSERT_EQ(0, b);
    ASSERT_TRUE(Byte::TryParse("1", 16, b));
    ASSERT_EQ(1, b);
    ASSERT_TRUE(Byte::TryParse("C", 16, b));
    ASSERT_EQ(0xC, b);
    ASSERT_TRUE(Byte::TryParse("3c", 16, b));
    ASSERT_EQ(0x3C, b);
    ASSERT_TRUE(Byte::TryParse("0x3c", 16, b));
    ASSERT_EQ(0x3C, b);
    ASSERT_TRUE(Byte::TryParse("0x3C", 16, b));
    ASSERT_EQ(0x3C, b);
  }

  TEST(ByteTest, TryParse_Hexadecimal_Fail) {
    byte b;
    ASSERT_FALSE(Byte::TryParse("x", 16, b));
    ASSERT_FALSE(Byte::TryParse("x0", 16, b));
    ASSERT_FALSE(Byte::TryParse("0x", 16, b));
    ASSERT_FALSE(Byte::TryParse("00x0", 16, b));
    ASSERT_FALSE(Byte::TryParse("0 x0", 16, b));
    ASSERT_FALSE(Byte::TryParse("0x 0", 16, b));
    ASSERT_FALSE(Byte::TryParse("X", 16, b));
    ASSERT_FALSE(Byte::TryParse("X0", 16, b));
    ASSERT_FALSE(Byte::TryParse("0X", 16, b));
    ASSERT_FALSE(Byte::TryParse("00X0", 16, b));
    ASSERT_FALSE(Byte::TryParse("0 X0", 16, b));
    ASSERT_FALSE(Byte::TryParse("0X 0", 16, b));
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
        MakeTest<Byte>(s, 5, "");

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
