#include <Switch/System/UInt64.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/FormatException.hpp>
#include <Switch/System/OverflowException.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {

  TEST(UInt64Test, MaxValue) {
    ASSERT_EQ(0xFFFFFFFFFFFFFFFFull, UInt64::MaxValue);
  }

  TEST(UInt64Test, MinValue) {
    ASSERT_EQ(0ull, UInt64::MinValue);
  }

  TEST(UInt64Test, DefaultValue) {
    ASSERT_EQ(0ull, UInt64());
  }

  TEST(UInt64Test, CtorValue) {
    ASSERT_EQ(10ull, UInt64(10ull));
    ASSERT_EQ(1236548889ull, UInt64(1236548889ull));
    ASSERT_EQ(0ull, UInt64(0ull));
  }

  TEST(UInt64Test, Parse) {
    ASSERT_EQ(0ull, UInt64::Parse("0"));
    ASSERT_EQ(1ull, UInt64::Parse("1"));
    ASSERT_EQ(123ull, UInt64::Parse("123"));
    ASSERT_EQ(123654ull, UInt64::Parse("123654"));
    ASSERT_EQ(0xFFFFFFFFull, UInt64::Parse("4294967295"));
  }

  TEST(UInt64Test, Parse_Sign) {
    ASSERT_EQ(5ull, UInt64::Parse("+5"));
    ASSERT_EQ(0ull, UInt64::Parse("-0"));
    ASSERT_THROW(UInt64::Parse("-1"), OverflowException);
  }

  TEST(UInt64Test, Parse_Leading_Zeros) {
    ASSERT_EQ(0ull, UInt64::Parse("0"));
    ASSERT_EQ(0ull, UInt64::Parse("00"));
    ASSERT_EQ(0ull, UInt64::Parse("000"));
    ASSERT_EQ(1ull, UInt64::Parse("01"));
    ASSERT_EQ(1ull, UInt64::Parse("0001"));
    ASSERT_EQ(99ull, UInt64::Parse("099"));
    ASSERT_EQ(999ull, UInt64::Parse("0000999"));
  }

  TEST(UInt64Test, Parse_Spaces) {
    ASSERT_EQ(5ull, UInt64::Parse(" 5"));
    ASSERT_EQ(5ull, UInt64::Parse("     5"));
    ASSERT_EQ(5ull, UInt64::Parse("5 "));
    ASSERT_EQ(51ull, UInt64::Parse("51     "));
    ASSERT_EQ(5ull, UInt64::Parse(" 5      "));
    ASSERT_EQ(52ull, UInt64::Parse("        52 "));
  }

  TEST(UInt64Test, Parse_FormatException) {
    ASSERT_THROW(UInt64::Parse(""), FormatException);
    ASSERT_THROW(UInt64::Parse("a56"), FormatException);
    ASSERT_THROW(UInt64::Parse("0 0"), FormatException);
    ASSERT_THROW(UInt64::Parse("++000"), FormatException);
    ASSERT_THROW(UInt64::Parse("+"), FormatException);
    ASSERT_THROW(UInt64::Parse("-"), FormatException);
    ASSERT_THROW(UInt64::Parse("--5"), FormatException);
    ASSERT_THROW(UInt64::Parse("0x53"), FormatException);
    ASSERT_THROW(UInt64::Parse("100a"), FormatException);
    ASSERT_THROW(UInt64::Parse("10u"), FormatException);
  }

  TEST(UInt64Test, Parse_OverflowException) {
    ASSERT_THROW(UInt64::Parse("-1"), OverflowException);
    ASSERT_THROW(UInt64::Parse("-15602"), OverflowException);
    ASSERT_EQ(0xFFFFFFFFFFFFFFFFull, UInt64::Parse("18446744073709551615"));
    ASSERT_EQ(0xFFFFFFFFFFFFFFFFull, UInt64::Parse("018446744073709551615"));
    ASSERT_EQ(0xFFFFFFFFFFFFFFFFull, UInt64::Parse("00018446744073709551615"));
    ASSERT_THROW(UInt64::Parse("18446744073709551616"), OverflowException);
    ASSERT_THROW(UInt64::Parse("28446744073709551615"), OverflowException);
    ASSERT_THROW(UInt64::Parse("1018446744073709551615"), OverflowException);
  }

  TEST(UInt64Test, Parse_Binary) {
    ASSERT_EQ(0ull, UInt64::Parse("0", 2));
    ASSERT_EQ(1ull, UInt64::Parse("1", 2));
    ASSERT_EQ(2ull, UInt64::Parse("10", 2));
    ASSERT_EQ(3ull, UInt64::Parse("11", 2));
    ASSERT_EQ(6ull, UInt64::Parse("110", 2));
  }

  TEST(UInt64Test, Parse_Exceptions_Binary) {
    ASSERT_THROW(UInt64::Parse("", 2), FormatException);
    ASSERT_THROW(UInt64::Parse("2", 2), FormatException);
    ASSERT_THROW(UInt64::Parse("103", 2), FormatException);
    ASSERT_THROW(UInt64::Parse("++0", 2), FormatException);
    ASSERT_THROW(UInt64::Parse("+", 2), FormatException);
    ASSERT_THROW(UInt64::Parse("-", 2), FormatException);
    ASSERT_THROW(UInt64::Parse("--1", 2), FormatException);
    ASSERT_THROW(UInt64::Parse("0x53", 2), FormatException);
    ASSERT_THROW(UInt64::Parse("100a", 2), FormatException);
    ASSERT_THROW(UInt64::Parse("10u", 2), FormatException);
  }

  TEST(UInt64Test, Parse_Octal) {
    ASSERT_EQ(0ull, UInt64::Parse("0", 8));
    ASSERT_EQ(1ull, UInt64::Parse("1", 8));
    ASSERT_EQ(12ull, UInt64::Parse("14", 8));
    ASSERT_EQ(56ull, UInt64::Parse("70", 8));
    ASSERT_EQ(601ull, UInt64::Parse("1131", 8));
  }

  TEST(UInt64Test, Parse_Hexadecimal) {
    ASSERT_EQ(0ull, UInt64::Parse("0", 16));
    ASSERT_EQ(1ull, UInt64::Parse("1", 16));
    ASSERT_EQ(0xCull, UInt64::Parse("C", 16));
    ASSERT_EQ(0x3Cull, UInt64::Parse("3c", 16));
    ASSERT_EQ(0xFE3ull, UInt64::Parse("FE3", 16));
    ASSERT_EQ(0xDEADBEEFull, UInt64::Parse("DeadBeef", 16));
    ASSERT_EQ(0xFFFFFFFFFFFFFFFFull, UInt64::Parse("FFFFFFFFFFFFFFFF", 16));
    ASSERT_EQ(0xFFFFFFFFFFFFFFFFull, UInt64::Parse("0FFFFFFFFFFFFFFFF", 16));
    ASSERT_THROW(UInt64::Parse("10000000000000000", 16), OverflowException);
    ASSERT_THROW(UInt64::Parse("1000000000000000000", 16), OverflowException);
  }

  TEST(UInt64Test, TryParse) {
    uint64 x;
    ASSERT_TRUE(UInt64::TryParse("0", x));
    ASSERT_EQ(0ull, x);
    ASSERT_TRUE(UInt64::TryParse("1", x));
    ASSERT_EQ(1ull, x);
    ASSERT_TRUE(UInt64::TryParse("123", x));
    ASSERT_EQ(123ull, x);
    ASSERT_TRUE(UInt64::TryParse("123654", x));
    ASSERT_EQ(123654ull, x);
    ASSERT_TRUE(UInt64::TryParse("4294967295", x));
    ASSERT_EQ(0xFFFFFFFFull, x);
  }

  TEST(UInt64Test, TryParse_Sign) {
    uint64 x;
    ASSERT_TRUE(UInt64::TryParse("+5", x));
    ASSERT_EQ(5ull, x);
    ASSERT_TRUE(UInt64::TryParse("-0", x));
    ASSERT_EQ(0ull, x);
    ASSERT_FALSE(UInt64::TryParse("-1", x));
  }

  TEST(UInt64Test, TryParse_Leading_Zeros) {
    uint64 x;
    ASSERT_TRUE(UInt64::TryParse("0", x));
    ASSERT_EQ(0ull, x);
    ASSERT_TRUE(UInt64::TryParse("00", x));
    ASSERT_EQ(0ull, x);
    ASSERT_TRUE(UInt64::TryParse("000", x));
    ASSERT_EQ(0ull, x);
    ASSERT_TRUE(UInt64::TryParse("01", x));
    ASSERT_EQ(1ull, x);
    ASSERT_TRUE(UInt64::TryParse("0001", x));
    ASSERT_EQ(1ull, x);
    ASSERT_TRUE(UInt64::TryParse("099", x));
    ASSERT_EQ(99ull, x);
    ASSERT_TRUE(UInt64::TryParse("0000999", x));
    ASSERT_EQ(999ull, x);
  }

  TEST(UInt64Test, TryParse_Spaces) {
    uint64 x;
    ASSERT_TRUE(UInt64::TryParse(" 5", x));
    ASSERT_EQ(5ull, x);
    ASSERT_TRUE(UInt64::TryParse("     5", x));
    ASSERT_EQ(5ull, x);
    ASSERT_TRUE(UInt64::TryParse("5 ", x));
    ASSERT_EQ(5ull, x);
    ASSERT_TRUE(UInt64::TryParse("51     ", x));
    ASSERT_EQ(51ull, x);
    ASSERT_TRUE(UInt64::TryParse(" 5      ", x));
    ASSERT_EQ(5ull, x);
    ASSERT_TRUE(UInt64::TryParse("        52 ", x));
    ASSERT_EQ(52ull, x);
  }

  TEST(UInt64Test, TryParse_FormatException) {
    uint64 x;
    ASSERT_FALSE(UInt64::TryParse("", x));
    ASSERT_FALSE(UInt64::TryParse("a56", x));
    ASSERT_FALSE(UInt64::TryParse("0 0", x));
    ASSERT_FALSE(UInt64::TryParse("++000", x));
    ASSERT_FALSE(UInt64::TryParse("+", x));
    ASSERT_FALSE(UInt64::TryParse("-", x));
    ASSERT_FALSE(UInt64::TryParse("--5", x));
    ASSERT_FALSE(UInt64::TryParse("0x53", x));
    ASSERT_FALSE(UInt64::TryParse("100a", x));
    ASSERT_FALSE(UInt64::TryParse("10u", x));
  }

  TEST(UInt64Test, TryParse_OverflowException) {
    uint64 x;
    ASSERT_FALSE(UInt64::TryParse("-1", x));
    ASSERT_FALSE(UInt64::TryParse("-15602", x));
    ASSERT_TRUE(UInt64::TryParse("18446744073709551615", x));
    ASSERT_EQ(0xFFFFFFFFFFFFFFFFull, x);
    ASSERT_TRUE(UInt64::TryParse("018446744073709551615", x));
    ASSERT_EQ(0xFFFFFFFFFFFFFFFFull, x);
    ASSERT_TRUE(UInt64::TryParse("00018446744073709551615", x));
    ASSERT_EQ(0xFFFFFFFFFFFFFFFFull, x);
    ASSERT_FALSE(UInt64::TryParse("18446744073709551616", x));
    ASSERT_FALSE(UInt64::TryParse("28446744073709551615", x));
    ASSERT_FALSE(UInt64::TryParse("1018446744073709551615", x));
  }

  TEST(UInt64Test, TryParse_Binary) {
    uint64 x;
    ASSERT_TRUE(UInt64::TryParse("0", 2, x));
    ASSERT_EQ(0ull, x);
    ASSERT_TRUE(UInt64::TryParse("1", 2, x));
    ASSERT_EQ(1ull, x);
    ASSERT_TRUE(UInt64::TryParse("10", 2, x));
    ASSERT_EQ(2ull, x);
    ASSERT_TRUE(UInt64::TryParse("11", 2, x));
    ASSERT_EQ(3ull, x);
    ASSERT_TRUE(UInt64::TryParse("110", 2, x));
    ASSERT_EQ(6ull, x);
  }

  TEST(UInt64Test, TryParse_Exceptions_Binary) {
    uint64 x;
    ASSERT_FALSE(UInt64::TryParse("", 2, x));
    ASSERT_FALSE(UInt64::TryParse("2", 2, x));
    ASSERT_FALSE(UInt64::TryParse("103", 2, x));
    ASSERT_FALSE(UInt64::TryParse("++0", 2, x));
    ASSERT_FALSE(UInt64::TryParse("+", 2, x));
    ASSERT_FALSE(UInt64::TryParse("-", 2, x));
    ASSERT_FALSE(UInt64::TryParse("--1", 2, x));
    ASSERT_FALSE(UInt64::TryParse("0x53", 2, x));
    ASSERT_FALSE(UInt64::TryParse("100a", 2, x));
    ASSERT_FALSE(UInt64::TryParse("10u", 2, x));
  }

  TEST(UInt64Test, TryParse_Octal) {
    uint64 x;
    ASSERT_TRUE(UInt64::TryParse("0", 8, x));
    ASSERT_EQ(0ull, x);
    ASSERT_TRUE(UInt64::TryParse("1", 8, x));
    ASSERT_EQ(1ull, x);
    ASSERT_TRUE(UInt64::TryParse("14", 8, x));
    ASSERT_EQ(12ull, x);
    ASSERT_TRUE(UInt64::TryParse("70", 8, x));
    ASSERT_EQ(56ull, x);
    ASSERT_TRUE(UInt64::TryParse("1131", 8, x));
    ASSERT_EQ(601ull, x);
  }

  TEST(UInt64Test, TryParse_Hexadecimal) {
    uint64 x;
    ASSERT_TRUE(UInt64::TryParse("0", 16, x));
    ASSERT_EQ(0ull, x);
    ASSERT_TRUE(UInt64::TryParse("1", 16, x));
    ASSERT_EQ(1ull, x);
    ASSERT_TRUE(UInt64::TryParse("C", 16, x));
    ASSERT_EQ(0xCull, x);
    ASSERT_TRUE(UInt64::TryParse("3c", 16, x));
    ASSERT_EQ(0x3Cull, x);
    ASSERT_TRUE(UInt64::TryParse("FE3", 16, x));
    ASSERT_EQ(0xFE3ull, x);
    ASSERT_TRUE(UInt64::TryParse("DeadBeef", 16, x));
    ASSERT_EQ(0xDEADBEEFull, x);
    ASSERT_TRUE(UInt64::TryParse("FFFFFFFFFFFFFFFF", 16, x));
    ASSERT_EQ(0xFFFFFFFFFFFFFFFFull, x);
    ASSERT_TRUE(UInt64::TryParse("0FFFFFFFFFFFFFFFF", 16, x));
    ASSERT_EQ(0xFFFFFFFFFFFFFFFFull, x);
    ASSERT_FALSE(UInt64::TryParse("10000000000000000",  16, x));
    ASSERT_FALSE(UInt64::TryParse("1000000000000000000",  16, x));
  }

  TEST(UInt64Test, TryParse_UInt64) {
    UInt64 x;
    ASSERT_TRUE(UInt64::TryParse("0", x));
    ASSERT_EQ(0ull, x);
    ASSERT_TRUE(UInt64::TryParse("1", x));
    ASSERT_EQ(1ull, x);
    ASSERT_TRUE(UInt64::TryParse("123", x));
    ASSERT_EQ(123ull, x);
    ASSERT_TRUE(UInt64::TryParse("123654", x));
    ASSERT_EQ(123654ull, x);
    ASSERT_TRUE(UInt64::TryParse("4294967295", x));
    ASSERT_EQ(0xFFFFFFFFull, x);
  }

  TEST(UInt64Test, TryParse_Sign_UInt64) {
    UInt64 x;
    ASSERT_TRUE(UInt64::TryParse("+5", x));
    ASSERT_EQ(5ull, x);
    ASSERT_TRUE(UInt64::TryParse("-0", x));
    ASSERT_EQ(0ull, x);
    ASSERT_FALSE(UInt64::TryParse("-1", x));
  }

  TEST(UInt64Test, TryParse_Leading_Zeros_UInt64) {
    UInt64 x;
    ASSERT_TRUE(UInt64::TryParse("0", x));
    ASSERT_EQ(0ull, x);
    ASSERT_TRUE(UInt64::TryParse("00", x));
    ASSERT_EQ(0ull, x);
    ASSERT_TRUE(UInt64::TryParse("000", x));
    ASSERT_EQ(0ull, x);
    ASSERT_TRUE(UInt64::TryParse("01", x));
    ASSERT_EQ(1ull, x);
    ASSERT_TRUE(UInt64::TryParse("0001", x));
    ASSERT_EQ(1ull, x);
    ASSERT_TRUE(UInt64::TryParse("099", x));
    ASSERT_EQ(99ull, x);
    ASSERT_TRUE(UInt64::TryParse("0000999", x));
    ASSERT_EQ(999ull, x);
  }

  TEST(UInt64Test, TryParse_Spaces_UInt64) {
    UInt64 x;
    ASSERT_TRUE(UInt64::TryParse(" 5", x));
    ASSERT_EQ(5ull, x);
    ASSERT_TRUE(UInt64::TryParse("     5", x));
    ASSERT_EQ(5ull, x);
    ASSERT_TRUE(UInt64::TryParse("5 ", x));
    ASSERT_EQ(5ull, x);
    ASSERT_TRUE(UInt64::TryParse("51     ", x));
    ASSERT_EQ(51ull, x);
    ASSERT_TRUE(UInt64::TryParse(" 5      ", x));
    ASSERT_EQ(5ull, x);
    ASSERT_TRUE(UInt64::TryParse("        52 ", x));
    ASSERT_EQ(52ull, x);
  }

  TEST(UInt64Test, TryParse_FormatException_UInt64) {
    UInt64 x;
    ASSERT_FALSE(UInt64::TryParse("", x));
    ASSERT_FALSE(UInt64::TryParse("a56", x));
    ASSERT_FALSE(UInt64::TryParse("0 0", x));
    ASSERT_FALSE(UInt64::TryParse("++000", x));
    ASSERT_FALSE(UInt64::TryParse("+", x));
    ASSERT_FALSE(UInt64::TryParse("-", x));
    ASSERT_FALSE(UInt64::TryParse("--5", x));
    ASSERT_FALSE(UInt64::TryParse("0x53", x));
    ASSERT_FALSE(UInt64::TryParse("100a", x));
    ASSERT_FALSE(UInt64::TryParse("10u", x));
  }

  TEST(UInt64Test, TryParse_OverflowException_UInt64) {
    UInt64 x;
    ASSERT_FALSE(UInt64::TryParse("-1", x));
    ASSERT_FALSE(UInt64::TryParse("-15602", x));
    ASSERT_TRUE(UInt64::TryParse("18446744073709551615", x));
    ASSERT_EQ(0xFFFFFFFFFFFFFFFFull, x);
    ASSERT_TRUE(UInt64::TryParse("018446744073709551615", x));
    ASSERT_EQ(0xFFFFFFFFFFFFFFFFull, x);
    ASSERT_TRUE(UInt64::TryParse("00018446744073709551615", x));
    ASSERT_EQ(0xFFFFFFFFFFFFFFFFull, x);
    ASSERT_FALSE(UInt64::TryParse("18446744073709551616", x));
    ASSERT_FALSE(UInt64::TryParse("28446744073709551615", x));
    ASSERT_FALSE(UInt64::TryParse("1018446744073709551615", x));
  }

  TEST(UInt64Test, TryParse_Binary_UInt64) {
    UInt64 x;
    ASSERT_TRUE(UInt64::TryParse("0", 2, x));
    ASSERT_EQ(0ull, x);
    ASSERT_TRUE(UInt64::TryParse("1", 2, x));
    ASSERT_EQ(1ull, x);
    ASSERT_TRUE(UInt64::TryParse("10", 2, x));
    ASSERT_EQ(2ull, x);
    ASSERT_TRUE(UInt64::TryParse("11", 2, x));
    ASSERT_EQ(3ull, x);
    ASSERT_TRUE(UInt64::TryParse("110", 2, x));
    ASSERT_EQ(6ull, x);
  }

  TEST(UInt64Test, TryParse_Exceptions_Binary_UInt64) {
    UInt64 x;
    ASSERT_FALSE(UInt64::TryParse("", 2, x));
    ASSERT_FALSE(UInt64::TryParse("2", 2, x));
    ASSERT_FALSE(UInt64::TryParse("103", 2, x));
    ASSERT_FALSE(UInt64::TryParse("++0", 2, x));
    ASSERT_FALSE(UInt64::TryParse("+", 2, x));
    ASSERT_FALSE(UInt64::TryParse("-", 2, x));
    ASSERT_FALSE(UInt64::TryParse("--1", 2, x));
    ASSERT_FALSE(UInt64::TryParse("0x53", 2, x));
    ASSERT_FALSE(UInt64::TryParse("100a", 2, x));
    ASSERT_FALSE(UInt64::TryParse("10u", 2, x));
  }

  TEST(UInt64Test, TryParse_Octal_UInt64) {
    UInt64 x;
    ASSERT_TRUE(UInt64::TryParse("0", 8, x));
    ASSERT_EQ(0ull, x);
    ASSERT_TRUE(UInt64::TryParse("1", 8, x));
    ASSERT_EQ(1ull, x);
    ASSERT_TRUE(UInt64::TryParse("14", 8, x));
    ASSERT_EQ(12ull, x);
    ASSERT_TRUE(UInt64::TryParse("70", 8, x));
    ASSERT_EQ(56ull, x);
    ASSERT_TRUE(UInt64::TryParse("1131", 8, x));
    ASSERT_EQ(601ull, x);
  }

  TEST(UInt64Test, TryParse_Hexadecimal_UInt64) {
    UInt64 x;
    ASSERT_TRUE(UInt64::TryParse("0", 16, x));
    ASSERT_EQ(0ull, x);
    ASSERT_TRUE(UInt64::TryParse("1", 16, x));
    ASSERT_EQ(1ull, x);
    ASSERT_TRUE(UInt64::TryParse("C", 16, x));
    ASSERT_EQ(0xCull, x);
    ASSERT_TRUE(UInt64::TryParse("3c", 16, x));
    ASSERT_EQ(0x3Cull, x);
    ASSERT_TRUE(UInt64::TryParse("FE3", 16, x));
    ASSERT_EQ(0xFE3ull, x);
    ASSERT_TRUE(UInt64::TryParse("DeadBeef", 16, x));
    ASSERT_EQ(0xDEADBEEFull, x);
    ASSERT_TRUE(UInt64::TryParse("FFFFFFFFFFFFFFFF", 16, x));
    ASSERT_EQ(0xFFFFFFFFFFFFFFFFull, x);
    ASSERT_TRUE(UInt64::TryParse("0FFFFFFFFFFFFFFFF", 16, x));
    ASSERT_EQ(0xFFFFFFFFFFFFFFFFull, x);
    ASSERT_FALSE(UInt64::TryParse("10000000000000000",  16, x));
    ASSERT_FALSE(UInt64::TryParse("1000000000000000000",  16, x));
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
        MakeTest<UInt64>(s, 5, "");

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
