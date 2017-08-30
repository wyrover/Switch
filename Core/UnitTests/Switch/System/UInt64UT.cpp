#include <Switch/System/UInt64.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {

TEST(UInt64, MaxValue) {
  EXPECT_EQ(0xFFFFFFFFFFFFFFFFull, UInt64::MaxValue);
}

TEST(UInt64, MinValue) {
  EXPECT_EQ(0ull, UInt64::MinValue);
}

TEST(UInt64, DefaultValue) {
  EXPECT_EQ(0ull, UInt64());
}

TEST(UInt64, CtorValue) {
  EXPECT_EQ(10ull, UInt64(10ull));
  EXPECT_EQ(1236548889ull, UInt64(1236548889ull));
  EXPECT_EQ(0ull, UInt64(0ull));
}

TEST(UInt64, Parse) {
  EXPECT_EQ(0ull, UInt64::Parse("0"));
  EXPECT_EQ(1ull, UInt64::Parse("1"));
  EXPECT_EQ(123ull, UInt64::Parse("123"));
  EXPECT_EQ(123654ull, UInt64::Parse("123654"));
  EXPECT_EQ(0xFFFFFFFFull, UInt64::Parse("4294967295"));
}

TEST(UInt64, Parse_Sign) {
  EXPECT_EQ(5ull, UInt64::Parse("+5"));
  EXPECT_EQ(0ull, UInt64::Parse("-0"));
  EXPECT_THROW(UInt64::Parse("-1"), OverflowException);
}

TEST(UInt64, Parse_Leading_Zeros) {
  EXPECT_EQ(0ull, UInt64::Parse("0"));
  EXPECT_EQ(0ull, UInt64::Parse("00"));
  EXPECT_EQ(0ull, UInt64::Parse("000"));
  EXPECT_EQ(1ull, UInt64::Parse("01"));
  EXPECT_EQ(1ull, UInt64::Parse("0001"));
  EXPECT_EQ(99ull, UInt64::Parse("099"));
  EXPECT_EQ(999ull, UInt64::Parse("0000999"));
}

TEST(UInt64, Parse_Spaces) {
  EXPECT_EQ(5ull,UInt64::Parse(" 5"));
  EXPECT_EQ(5ull,UInt64::Parse("     5"));
  EXPECT_EQ(5ull,UInt64::Parse("5 "));
  EXPECT_EQ(51ull,UInt64::Parse("51     "));
  EXPECT_EQ(5ull,UInt64::Parse(" 5      "));
  EXPECT_EQ(52ull,UInt64::Parse("        52 "));
}

TEST(UInt64, Parse_FormatException) {
  EXPECT_THROW(UInt64::Parse(""), FormatException);
  EXPECT_THROW(UInt64::Parse("a56"), FormatException);
  EXPECT_THROW(UInt64::Parse("0 0"), FormatException);
  EXPECT_THROW(UInt64::Parse("++000"), FormatException);
  EXPECT_THROW(UInt64::Parse("+"), FormatException);
  EXPECT_THROW(UInt64::Parse("-"), FormatException);
  EXPECT_THROW(UInt64::Parse("--5"), FormatException);
  EXPECT_THROW(UInt64::Parse("0x53"), FormatException);
  EXPECT_THROW(UInt64::Parse("100a"), FormatException);
  EXPECT_THROW(UInt64::Parse("10u"), FormatException);
}

TEST(UInt64, Parse_OverflowException) {
  EXPECT_THROW(UInt64::Parse("-1"), OverflowException);
  EXPECT_THROW(UInt64::Parse("-15602"), OverflowException);
  EXPECT_EQ(0xFFFFFFFFFFFFFFFFull, UInt64::Parse("18446744073709551615"));
  EXPECT_EQ(0xFFFFFFFFFFFFFFFFull, UInt64::Parse("018446744073709551615"));
  EXPECT_EQ(0xFFFFFFFFFFFFFFFFull, UInt64::Parse("00018446744073709551615"));
  EXPECT_THROW(UInt64::Parse("18446744073709551616"), OverflowException);
  EXPECT_THROW(UInt64::Parse("28446744073709551615"), OverflowException);
  EXPECT_THROW(UInt64::Parse("1018446744073709551615"), OverflowException);
}

TEST(UInt64, Parse_Binary) {
  EXPECT_EQ(0ull, UInt64::Parse("0",2));
  EXPECT_EQ(1ull, UInt64::Parse("1",2));
  EXPECT_EQ(2ull, UInt64::Parse("10",2));
  EXPECT_EQ(3ull, UInt64::Parse("11",2));
  EXPECT_EQ(6ull, UInt64::Parse("110",2));
}

TEST(UInt64, Parse_Exceptions_Binary) {
  EXPECT_THROW(UInt64::Parse("",2), FormatException);
  EXPECT_THROW(UInt64::Parse("2",2), FormatException);
  EXPECT_THROW(UInt64::Parse("103",2), FormatException);
  EXPECT_THROW(UInt64::Parse("++0",2), FormatException);
  EXPECT_THROW(UInt64::Parse("+",2), FormatException);
  EXPECT_THROW(UInt64::Parse("-",2), FormatException);
  EXPECT_THROW(UInt64::Parse("--1",2), FormatException);
  EXPECT_THROW(UInt64::Parse("0x53",2), FormatException);
  EXPECT_THROW(UInt64::Parse("100a",2), FormatException);
  EXPECT_THROW(UInt64::Parse("10u",2), FormatException);
}

TEST(UInt64, Parse_Octal) {
  EXPECT_EQ(0ull, UInt64::Parse("0",8));
  EXPECT_EQ(1ull, UInt64::Parse("1",8));
  EXPECT_EQ(12ull, UInt64::Parse("14",8));
  EXPECT_EQ(56ull, UInt64::Parse("70",8));
  EXPECT_EQ(601ull, UInt64::Parse("1131",8));
}

TEST(UInt64, Parse_Hexadecimal) {
  EXPECT_EQ(0ull, UInt64::Parse("0", 16));
  EXPECT_EQ(1ull, UInt64::Parse("1", 16));
  EXPECT_EQ(0xCull, UInt64::Parse("C", 16));
  EXPECT_EQ(0x3Cull, UInt64::Parse("3c", 16));
  EXPECT_EQ(0xFE3ull, UInt64::Parse("FE3", 16));
  EXPECT_EQ(0xDEADBEEFull, UInt64::Parse("DeadBeef", 16));
  EXPECT_EQ(0xFFFFFFFFFFFFFFFFull, UInt64::Parse("FFFFFFFFFFFFFFFF", 16));
  EXPECT_EQ(0xFFFFFFFFFFFFFFFFull, UInt64::Parse("0FFFFFFFFFFFFFFFF", 16));
  EXPECT_THROW(UInt64::Parse("10000000000000000", 16), OverflowException);
   EXPECT_THROW(UInt64::Parse("1000000000000000000", 16), OverflowException);
}

TEST(UInt64, TryParse) {
  uint64 x;
  EXPECT_TRUE(UInt64::TryParse("0", x));
  EXPECT_EQ(0ull, x);
  EXPECT_TRUE(UInt64::TryParse("1", x));
  EXPECT_EQ(1ull, x);
  EXPECT_TRUE(UInt64::TryParse("123", x));
  EXPECT_EQ(123ull, x);
  EXPECT_TRUE(UInt64::TryParse("123654", x));
  EXPECT_EQ(123654ull, x);
  EXPECT_TRUE(UInt64::TryParse("4294967295", x));
  EXPECT_EQ(0xFFFFFFFFull, x);
}

TEST(UInt64, TryParse_Sign) {
  uint64 x;
  EXPECT_TRUE(UInt64::TryParse("+5", x));
  EXPECT_EQ(5ull, x);
  EXPECT_TRUE(UInt64::TryParse("-0", x));
  EXPECT_EQ(0ull, x);
  EXPECT_FALSE(UInt64::TryParse("-1", x));
}

TEST(UInt64, TryParse_Leading_Zeros) {
  uint64 x;
  EXPECT_TRUE(UInt64::TryParse("0", x));
  EXPECT_EQ(0ull, x);
  EXPECT_TRUE(UInt64::TryParse("00", x));
  EXPECT_EQ(0ull, x);
  EXPECT_TRUE(UInt64::TryParse("000", x));
  EXPECT_EQ(0ull, x);
  EXPECT_TRUE(UInt64::TryParse("01", x));
  EXPECT_EQ(1ull, x);
  EXPECT_TRUE(UInt64::TryParse("0001", x));
  EXPECT_EQ(1ull, x);
  EXPECT_TRUE(UInt64::TryParse("099", x));
  EXPECT_EQ(99ull, x);
  EXPECT_TRUE(UInt64::TryParse("0000999", x));
  EXPECT_EQ(999ull, x);
}

TEST(UInt64, TryParse_Spaces) {
  uint64 x;
  EXPECT_TRUE(UInt64::TryParse(" 5", x));
  EXPECT_EQ(5ull, x);
  EXPECT_TRUE(UInt64::TryParse("     5", x));
  EXPECT_EQ(5ull, x);
  EXPECT_TRUE(UInt64::TryParse("5 ", x));
  EXPECT_EQ(5ull, x);
  EXPECT_TRUE(UInt64::TryParse("51     ", x));
  EXPECT_EQ(51ull, x);
  EXPECT_TRUE(UInt64::TryParse(" 5      ", x));
  EXPECT_EQ(5ull, x);
  EXPECT_TRUE(UInt64::TryParse("        52 ", x));
  EXPECT_EQ(52ull, x);
}

TEST(UInt64, TryParse_FormatException) {
  uint64 x;
  EXPECT_FALSE(UInt64::TryParse("", x));
  EXPECT_FALSE(UInt64::TryParse("a56", x));
  EXPECT_FALSE(UInt64::TryParse("0 0", x));
  EXPECT_FALSE(UInt64::TryParse("++000", x));
  EXPECT_FALSE(UInt64::TryParse("+", x));
  EXPECT_FALSE(UInt64::TryParse("-", x));
  EXPECT_FALSE(UInt64::TryParse("--5", x));
  EXPECT_FALSE(UInt64::TryParse("0x53", x));
  EXPECT_FALSE(UInt64::TryParse("100a", x));
  EXPECT_FALSE(UInt64::TryParse("10u", x));
}

TEST(UInt64, TryParse_OverflowException) {
  uint64 x;
  EXPECT_FALSE(UInt64::TryParse("-1", x));
  EXPECT_FALSE(UInt64::TryParse("-15602", x));
  EXPECT_TRUE(UInt64::TryParse("18446744073709551615", x));
  EXPECT_EQ(0xFFFFFFFFFFFFFFFFull, x);
  EXPECT_TRUE(UInt64::TryParse("018446744073709551615", x));
  EXPECT_EQ(0xFFFFFFFFFFFFFFFFull, x);
  EXPECT_TRUE(UInt64::TryParse("00018446744073709551615", x));
  EXPECT_EQ(0xFFFFFFFFFFFFFFFFull, x);
  EXPECT_FALSE(UInt64::TryParse("18446744073709551616", x));
  EXPECT_FALSE(UInt64::TryParse("28446744073709551615", x));
  EXPECT_FALSE(UInt64::TryParse("1018446744073709551615", x));
}

TEST(UInt64, TryParse_Binary) {
  uint64 x;
  EXPECT_TRUE(UInt64::TryParse("0", 2, x));
  EXPECT_EQ(0ull, x);
  EXPECT_TRUE(UInt64::TryParse("1", 2, x));
  EXPECT_EQ(1ull, x);
  EXPECT_TRUE(UInt64::TryParse("10", 2, x));
  EXPECT_EQ(2ull, x);
  EXPECT_TRUE(UInt64::TryParse("11", 2, x));
  EXPECT_EQ(3ull, x);
  EXPECT_TRUE(UInt64::TryParse("110", 2, x));
  EXPECT_EQ(6ull, x);
}

TEST(UInt64, TryParse_Exceptions_Binary) {
  uint64 x;
  EXPECT_FALSE(UInt64::TryParse("", 2, x));
  EXPECT_FALSE(UInt64::TryParse("2", 2, x));
  EXPECT_FALSE(UInt64::TryParse("103", 2, x));
  EXPECT_FALSE(UInt64::TryParse("++0", 2, x));
  EXPECT_FALSE(UInt64::TryParse("+", 2, x));
  EXPECT_FALSE(UInt64::TryParse("-", 2, x));
  EXPECT_FALSE(UInt64::TryParse("--1", 2, x));
  EXPECT_FALSE(UInt64::TryParse("0x53", 2, x));
  EXPECT_FALSE(UInt64::TryParse("100a", 2, x));
  EXPECT_FALSE(UInt64::TryParse("10u", 2, x));
}

TEST(UInt64, TryParse_Octal) {
  uint64 x;
  EXPECT_TRUE(UInt64::TryParse("0", 8, x));
  EXPECT_EQ(0ull, x);
  EXPECT_TRUE(UInt64::TryParse("1", 8, x));
  EXPECT_EQ(1ull, x);
  EXPECT_TRUE(UInt64::TryParse("14", 8, x));
  EXPECT_EQ(12ull, x);
  EXPECT_TRUE(UInt64::TryParse("70", 8, x));
  EXPECT_EQ(56ull, x);
  EXPECT_TRUE(UInt64::TryParse("1131", 8, x));
  EXPECT_EQ(601ull, x);
}

TEST(UInt64, TryParse_Hexadecimal) {
  uint64 x;
  EXPECT_TRUE(UInt64::TryParse("0", 16, x));
  EXPECT_EQ(0ull, x);
  EXPECT_TRUE(UInt64::TryParse("1", 16, x));
  EXPECT_EQ(1ull, x);
  EXPECT_TRUE(UInt64::TryParse("C", 16, x));
  EXPECT_EQ(0xCull, x);
  EXPECT_TRUE(UInt64::TryParse("3c", 16, x));
  EXPECT_EQ(0x3Cull, x);
  EXPECT_TRUE(UInt64::TryParse("FE3", 16, x));
  EXPECT_EQ(0xFE3ull, x);
  EXPECT_TRUE(UInt64::TryParse("DeadBeef", 16, x));
  EXPECT_EQ(0xDEADBEEFull, x);
  EXPECT_TRUE(UInt64::TryParse("FFFFFFFFFFFFFFFF", 16, x));
  EXPECT_EQ(0xFFFFFFFFFFFFFFFFull, x);
  EXPECT_TRUE(UInt64::TryParse("0FFFFFFFFFFFFFFFF", 16, x));
  EXPECT_EQ(0xFFFFFFFFFFFFFFFFull, x);
  EXPECT_FALSE(UInt64::TryParse("10000000000000000",  16, x));
  EXPECT_FALSE(UInt64::TryParse("1000000000000000000",  16, x));
}

TEST(UInt64, TryParse_UInt64) {
  UInt64 x;
  EXPECT_TRUE(UInt64::TryParse("0", x));
  EXPECT_EQ(0ull, x);
  EXPECT_TRUE(UInt64::TryParse("1", x));
  EXPECT_EQ(1ull, x);
  EXPECT_TRUE(UInt64::TryParse("123", x));
  EXPECT_EQ(123ull, x);
  EXPECT_TRUE(UInt64::TryParse("123654", x));
  EXPECT_EQ(123654ull, x);
  EXPECT_TRUE(UInt64::TryParse("4294967295", x));
  EXPECT_EQ(0xFFFFFFFFull, x);
}

TEST(UInt64, TryParse_Sign_UInt64) {
  UInt64 x;
  EXPECT_TRUE(UInt64::TryParse("+5", x));
  EXPECT_EQ(5ull, x);
  EXPECT_TRUE(UInt64::TryParse("-0", x));
  EXPECT_EQ(0ull, x);
  EXPECT_FALSE(UInt64::TryParse("-1", x));
}

TEST(UInt64, TryParse_Leading_Zeros_UInt64) {
  UInt64 x;
  EXPECT_TRUE(UInt64::TryParse("0", x));
  EXPECT_EQ(0ull, x);
  EXPECT_TRUE(UInt64::TryParse("00", x));
  EXPECT_EQ(0ull, x);
  EXPECT_TRUE(UInt64::TryParse("000", x));
  EXPECT_EQ(0ull, x);
  EXPECT_TRUE(UInt64::TryParse("01", x));
  EXPECT_EQ(1ull, x);
  EXPECT_TRUE(UInt64::TryParse("0001", x));
  EXPECT_EQ(1ull, x);
  EXPECT_TRUE(UInt64::TryParse("099", x));
  EXPECT_EQ(99ull, x);
  EXPECT_TRUE(UInt64::TryParse("0000999", x));
  EXPECT_EQ(999ull, x);
}

TEST(UInt64, TryParse_Spaces_UInt64) {
  UInt64 x;
  EXPECT_TRUE(UInt64::TryParse(" 5", x));
  EXPECT_EQ(5ull, x);
  EXPECT_TRUE(UInt64::TryParse("     5", x));
  EXPECT_EQ(5ull, x);
  EXPECT_TRUE(UInt64::TryParse("5 ", x));
  EXPECT_EQ(5ull, x);
  EXPECT_TRUE(UInt64::TryParse("51     ", x));
  EXPECT_EQ(51ull, x);
  EXPECT_TRUE(UInt64::TryParse(" 5      ", x));
  EXPECT_EQ(5ull, x);
  EXPECT_TRUE(UInt64::TryParse("        52 ", x));
  EXPECT_EQ(52ull, x);
}

TEST(UInt64, TryParse_FormatException_UInt64) {
  UInt64 x;
  EXPECT_FALSE(UInt64::TryParse("", x));
  EXPECT_FALSE(UInt64::TryParse("a56", x));
  EXPECT_FALSE(UInt64::TryParse("0 0", x));
  EXPECT_FALSE(UInt64::TryParse("++000", x));
  EXPECT_FALSE(UInt64::TryParse("+", x));
  EXPECT_FALSE(UInt64::TryParse("-", x));
  EXPECT_FALSE(UInt64::TryParse("--5", x));
  EXPECT_FALSE(UInt64::TryParse("0x53", x));
  EXPECT_FALSE(UInt64::TryParse("100a", x));
  EXPECT_FALSE(UInt64::TryParse("10u", x));
}

TEST(UInt64, TryParse_OverflowException_UInt64) {
  UInt64 x;
  EXPECT_FALSE(UInt64::TryParse("-1", x));
  EXPECT_FALSE(UInt64::TryParse("-15602", x));
  EXPECT_TRUE(UInt64::TryParse("18446744073709551615", x));
  EXPECT_EQ(0xFFFFFFFFFFFFFFFFull, x);
  EXPECT_TRUE(UInt64::TryParse("018446744073709551615", x));
  EXPECT_EQ(0xFFFFFFFFFFFFFFFFull, x);
  EXPECT_TRUE(UInt64::TryParse("00018446744073709551615", x));
  EXPECT_EQ(0xFFFFFFFFFFFFFFFFull, x);
  EXPECT_FALSE(UInt64::TryParse("18446744073709551616", x));
  EXPECT_FALSE(UInt64::TryParse("28446744073709551615", x));
  EXPECT_FALSE(UInt64::TryParse("1018446744073709551615", x));
}

TEST(UInt64, TryParse_Binary_UInt64) {
  UInt64 x;
  EXPECT_TRUE(UInt64::TryParse("0", 2, x));
  EXPECT_EQ(0ull, x);
  EXPECT_TRUE(UInt64::TryParse("1", 2, x));
  EXPECT_EQ(1ull, x);
  EXPECT_TRUE(UInt64::TryParse("10", 2, x));
  EXPECT_EQ(2ull, x);
  EXPECT_TRUE(UInt64::TryParse("11", 2, x));
  EXPECT_EQ(3ull, x);
  EXPECT_TRUE(UInt64::TryParse("110", 2, x));
  EXPECT_EQ(6ull, x);
}

TEST(UInt64, TryParse_Exceptions_Binary_UInt64) {
  UInt64 x;
  EXPECT_FALSE(UInt64::TryParse("", 2, x));
  EXPECT_FALSE(UInt64::TryParse("2", 2, x));
  EXPECT_FALSE(UInt64::TryParse("103", 2, x));
  EXPECT_FALSE(UInt64::TryParse("++0", 2, x));
  EXPECT_FALSE(UInt64::TryParse("+", 2, x));
  EXPECT_FALSE(UInt64::TryParse("-", 2, x));
  EXPECT_FALSE(UInt64::TryParse("--1", 2, x));
  EXPECT_FALSE(UInt64::TryParse("0x53", 2, x));
  EXPECT_FALSE(UInt64::TryParse("100a", 2, x));
  EXPECT_FALSE(UInt64::TryParse("10u", 2, x));
}

TEST(UInt64, TryParse_Octal_UInt64) {
  UInt64 x;
  EXPECT_TRUE(UInt64::TryParse("0", 8, x));
  EXPECT_EQ(0ull, x);
  EXPECT_TRUE(UInt64::TryParse("1", 8, x));
  EXPECT_EQ(1ull, x);
  EXPECT_TRUE(UInt64::TryParse("14", 8, x));
  EXPECT_EQ(12ull, x);
  EXPECT_TRUE(UInt64::TryParse("70", 8, x));
  EXPECT_EQ(56ull, x);
  EXPECT_TRUE(UInt64::TryParse("1131", 8, x));
  EXPECT_EQ(601ull, x);
}

TEST(UInt64, TryParse_Hexadecimal_UInt64) {
  UInt64 x;
  EXPECT_TRUE(UInt64::TryParse("0", 16, x));
  EXPECT_EQ(0ull, x);
  EXPECT_TRUE(UInt64::TryParse("1", 16, x));
  EXPECT_EQ(1ull, x);
  EXPECT_TRUE(UInt64::TryParse("C", 16, x));
  EXPECT_EQ(0xCull, x);
  EXPECT_TRUE(UInt64::TryParse("3c", 16, x));
  EXPECT_EQ(0x3Cull, x);
  EXPECT_TRUE(UInt64::TryParse("FE3", 16, x));
  EXPECT_EQ(0xFE3ull, x);
  EXPECT_TRUE(UInt64::TryParse("DeadBeef", 16, x));
  EXPECT_EQ(0xDEADBEEFull, x);
  EXPECT_TRUE(UInt64::TryParse("FFFFFFFFFFFFFFFF", 16, x));
  EXPECT_EQ(0xFFFFFFFFFFFFFFFFull, x);
  EXPECT_TRUE(UInt64::TryParse("0FFFFFFFFFFFFFFFF", 16, x));
  EXPECT_EQ(0xFFFFFFFFFFFFFFFFull, x);
  EXPECT_FALSE(UInt64::TryParse("10000000000000000",  16, x));
  EXPECT_FALSE(UInt64::TryParse("1000000000000000000",  16, x));
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
