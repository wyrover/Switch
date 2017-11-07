#include <Switch/System/UInt32.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/FormatException.hpp>
#include <Switch/System/OverflowException.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {

TEST(UInt32Test, MaxValue) {
  ASSERT_EQ(0xFFFFFFFFU, UInt32::MaxValue);
}

TEST(UInt32Test, MinValue) {
  ASSERT_EQ(0ul, UInt32::MinValue);
}

TEST(UInt32Test, DefaultValue) {
  ASSERT_EQ(0ul, UInt32());
}

TEST(UInt32Test, CtorValue) {
  ASSERT_EQ(10ul, UInt32(10ul));
  ASSERT_EQ(123654ul, UInt32(123654ul));
  ASSERT_EQ(0ul, UInt32(0ul));
}

TEST(UInt32Test, Parse) {
  ASSERT_EQ(0ul, UInt32::Parse("0"));
  ASSERT_EQ(1ul, UInt32::Parse("1"));
  ASSERT_EQ(123ul, UInt32::Parse("123"));
  ASSERT_EQ(123654ul, UInt32::Parse("123654"));
  ASSERT_EQ(0xFFFFFFFFul, UInt32::Parse("4294967295"));
}

TEST(UInt32Test, Parse_Sign) {
  ASSERT_EQ(5ul, UInt32::Parse("+5"));
  ASSERT_EQ(0ul, UInt32::Parse("-0"));
  ASSERT_THROW(UInt32::Parse("-1"), OverflowException);
}

TEST(UInt32Test, Parse_Leading_Zeros) {
  ASSERT_EQ(0ul, UInt32::Parse("0"));
  ASSERT_EQ(0ul, UInt32::Parse("00"));
  ASSERT_EQ(0ul, UInt32::Parse("000"));
  ASSERT_EQ(1ul, UInt32::Parse("01"));
  ASSERT_EQ(1ul, UInt32::Parse("0001"));
  ASSERT_EQ(99ul, UInt32::Parse("099"));
  ASSERT_EQ(999ul, UInt32::Parse("0000999"));
}

TEST(UInt32Test, Parse_Spaces) {
  ASSERT_EQ(5ul, UInt32::Parse(" 5"));
  ASSERT_EQ(5ul, UInt32::Parse("     5"));
  ASSERT_EQ(5ul, UInt32::Parse("5 "));
  ASSERT_EQ(51ul, UInt32::Parse("51     "));
  ASSERT_EQ(5ul, UInt32::Parse(" 5      "));
  ASSERT_EQ(52ul, UInt32::Parse("        52 "));
}

TEST(UInt32Test, Parse_FormatException) {
  ASSERT_THROW(UInt32::Parse(""), FormatException);
  ASSERT_THROW(UInt32::Parse("a56"), FormatException);
  ASSERT_THROW(UInt32::Parse("0 0"), FormatException);
  ASSERT_THROW(UInt32::Parse("++000"), FormatException);
  ASSERT_THROW(UInt32::Parse("+"), FormatException);
  ASSERT_THROW(UInt32::Parse("-"), FormatException);
  ASSERT_THROW(UInt32::Parse("--5"), FormatException);
  ASSERT_THROW(UInt32::Parse("0x53"), FormatException);
  ASSERT_THROW(UInt32::Parse("100a"), FormatException);
  ASSERT_THROW(UInt32::Parse("10u"), FormatException);
}

TEST(UInt32Test, Parse_OverflowException) {
  ASSERT_THROW(UInt32::Parse("-1"), OverflowException);
  ASSERT_THROW(UInt32::Parse("-15602"), OverflowException);
  ASSERT_EQ(0xFFFFFFFFul, UInt32::Parse("4294967295"));
  ASSERT_THROW(UInt32::Parse("4294967296"), OverflowException);
  ASSERT_THROW(UInt32::Parse("5294967295"), OverflowException);
}

TEST(UInt32Test, Parse_Binary) {
  ASSERT_EQ(0ul, UInt32::Parse("0",2));
  ASSERT_EQ(1ul, UInt32::Parse("1",2));
  ASSERT_EQ(2ul, UInt32::Parse("10",2));
  ASSERT_EQ(3ul, UInt32::Parse("11",2));
  ASSERT_EQ(6ul, UInt32::Parse("110",2));
}

TEST(UInt32Test, Parse_Exceptions_Binary) {
  ASSERT_THROW(UInt32::Parse("",2), FormatException);
  ASSERT_THROW(UInt32::Parse("2",2), FormatException);
  ASSERT_THROW(UInt32::Parse("103",2), FormatException);
  ASSERT_THROW(UInt32::Parse("++0",2), FormatException);
  ASSERT_THROW(UInt32::Parse("+",2), FormatException);
  ASSERT_THROW(UInt32::Parse("-",2), FormatException);
  ASSERT_THROW(UInt32::Parse("--1",2), FormatException);
  ASSERT_THROW(UInt32::Parse("0x53",2), FormatException);
  ASSERT_THROW(UInt32::Parse("100a",2), FormatException);
  ASSERT_THROW(UInt32::Parse("10u",2), FormatException);
}

TEST(UInt32Test, Parse_Octal) {
  ASSERT_EQ(0ul, UInt32::Parse("0",8));
  ASSERT_EQ(1ul, UInt32::Parse("1",8));
  ASSERT_EQ(12ul, UInt32::Parse("14",8));
  ASSERT_EQ(56ul, UInt32::Parse("70",8));
  ASSERT_EQ(601ul, UInt32::Parse("1131",8));
}

TEST(UInt32Test, Parse_Hexadecimal) {
  ASSERT_EQ(0ul, UInt32::Parse("0", 16));
  ASSERT_EQ(1ul, UInt32::Parse("1", 16));
  ASSERT_EQ(0xCul, UInt32::Parse("C", 16));
  ASSERT_EQ(0x3Cul, UInt32::Parse("3c", 16));
  ASSERT_EQ(0xFE3ul, UInt32::Parse("FE3", 16));
  ASSERT_EQ(0xDEADBEEFul, UInt32::Parse("DeadBeef", 16));
  ASSERT_EQ(0xFFFFFFFFul, UInt32::Parse("FFFFFFFF", 16));
}

TEST(UInt32Test, TryParse) {
  uint32 x;
  ASSERT_TRUE(UInt32::TryParse("0", x));
  ASSERT_EQ(0ul, x);
  ASSERT_TRUE(UInt32::TryParse("1", x));
  ASSERT_EQ(1ul, x);
  ASSERT_TRUE(UInt32::TryParse("123", x));
  ASSERT_EQ(123ul, x);
  ASSERT_TRUE(UInt32::TryParse("123654", x));
  ASSERT_EQ(123654ul, x);
  ASSERT_TRUE(UInt32::TryParse("4294967295", x));
  ASSERT_EQ(0xFFFFFFFFul, x);
}

TEST(UInt32Test, TryParse_Sign) {
  uint32 x;
  ASSERT_TRUE(UInt32::TryParse("+5", x));
  ASSERT_EQ(5ul, x);
  ASSERT_TRUE(UInt32::TryParse("-0", x));
  ASSERT_EQ(0ul, x);
  ASSERT_FALSE(UInt32::TryParse("-1", x));
}

TEST(UInt32Test, TryParse_Leading_Zeros) {
  uint32 x;
  ASSERT_TRUE(UInt32::TryParse("0", x));
  ASSERT_EQ(0ul, x);
  ASSERT_TRUE(UInt32::TryParse("00", x));
  ASSERT_EQ(0ul, x);
  ASSERT_TRUE(UInt32::TryParse("000", x));
  ASSERT_EQ(0ul, x);
  ASSERT_TRUE(UInt32::TryParse("01", x));
  ASSERT_EQ(1ul, x);
  ASSERT_TRUE(UInt32::TryParse("0001", x));
  ASSERT_EQ(1ul, x);
  ASSERT_TRUE(UInt32::TryParse("099", x));
  ASSERT_EQ(99ul, x);
  ASSERT_TRUE(UInt32::TryParse("0000999", x));
  ASSERT_EQ(999ul, x);
}

TEST(UInt32Test, TryParse_Spaces) {
  uint32 x;
  ASSERT_TRUE(UInt32::TryParse(" 5", x));
  ASSERT_EQ(5ul, x);
  ASSERT_TRUE(UInt32::TryParse("     5", x));
  ASSERT_EQ(5ul, x);
  ASSERT_TRUE(UInt32::TryParse("5 ", x));
  ASSERT_EQ(5ul, x);
  ASSERT_TRUE(UInt32::TryParse("51     ", x));
  ASSERT_EQ(51ul, x);
  ASSERT_TRUE(UInt32::TryParse(" 5      ", x));
  ASSERT_EQ(5ul, x);
  ASSERT_TRUE(UInt32::TryParse("        52 ", x));
  ASSERT_EQ(52ul, x);
}

TEST(UInt32Test, TryParse_FormatException) {
  uint32 x;
  ASSERT_FALSE(UInt32::TryParse("", x));
  ASSERT_FALSE(UInt32::TryParse("a56", x));
  ASSERT_FALSE(UInt32::TryParse("0 0", x));
  ASSERT_FALSE(UInt32::TryParse("++000", x));
  ASSERT_FALSE(UInt32::TryParse("+", x));
  ASSERT_FALSE(UInt32::TryParse("-", x));
  ASSERT_FALSE(UInt32::TryParse("--5", x));
  ASSERT_FALSE(UInt32::TryParse("0x53", x));
  ASSERT_FALSE(UInt32::TryParse("100a", x));
  ASSERT_FALSE(UInt32::TryParse("10u", x));
}

TEST(UInt32Test, TryParse_OverflowException) {
  uint32 x;
  ASSERT_FALSE(UInt32::TryParse("-1", x));
  ASSERT_FALSE(UInt32::TryParse("-15602", x));
  ASSERT_TRUE(UInt32::TryParse("4294967295", x));
  ASSERT_EQ(0xFFFFFFFFul, x);
  ASSERT_FALSE(UInt32::TryParse("4294967296", x));
  ASSERT_FALSE(UInt32::TryParse("5294967295", x));
}

TEST(UInt32Test, TryParse_Binary) {
  uint32 x;
  ASSERT_TRUE(UInt32::TryParse("0", 2, x));
  ASSERT_EQ(0ul, x);
  ASSERT_TRUE(UInt32::TryParse("1", 2, x));
  ASSERT_EQ(1ul, x);
  ASSERT_TRUE(UInt32::TryParse("10", 2, x));
  ASSERT_EQ(2ul, x);
  ASSERT_TRUE(UInt32::TryParse("11", 2, x));
  ASSERT_EQ(3ul, x);
  ASSERT_TRUE(UInt32::TryParse("110", 2, x));
  ASSERT_EQ(6ul, x);
}

TEST(UInt32Test, TryParse_Exceptions_Binary) {
  uint32 x;
  ASSERT_FALSE(UInt32::TryParse("", 2, x));
  ASSERT_FALSE(UInt32::TryParse("2", 2, x));
  ASSERT_FALSE(UInt32::TryParse("103", 2, x));
  ASSERT_FALSE(UInt32::TryParse("++0", 2, x));
  ASSERT_FALSE(UInt32::TryParse("+", 2, x));
  ASSERT_FALSE(UInt32::TryParse("-", 2, x));
  ASSERT_FALSE(UInt32::TryParse("--1", 2, x));
  ASSERT_FALSE(UInt32::TryParse("0x53", 2, x));
  ASSERT_FALSE(UInt32::TryParse("100a", 2, x));
  ASSERT_FALSE(UInt32::TryParse("10u", 2, x));
}

TEST(UInt32Test, TryParse_Octal) {
  uint32 x;
  ASSERT_TRUE(UInt32::TryParse("0", 8, x));
  ASSERT_EQ(0ul, x);
  ASSERT_TRUE(UInt32::TryParse("1", 8, x));
  ASSERT_EQ(1ul, x);
  ASSERT_TRUE(UInt32::TryParse("14", 8, x));
  ASSERT_EQ(12ul, x);
  ASSERT_TRUE(UInt32::TryParse("70", 8, x));
  ASSERT_EQ(56ul, x);
  ASSERT_TRUE(UInt32::TryParse("1131", 8, x));
  ASSERT_EQ(601ul, x);
}

TEST(UInt32Test, TryParse_Hexadecimal) {
  uint32 x;
  ASSERT_TRUE(UInt32::TryParse("0", 16, x));
  ASSERT_EQ(0ul, x);
  ASSERT_TRUE(UInt32::TryParse("1", 16, x));
  ASSERT_EQ(1ul, x);
  ASSERT_TRUE(UInt32::TryParse("C", 16, x));
  ASSERT_EQ(0xCul, x);
  ASSERT_TRUE(UInt32::TryParse("3c", 16, x));
  ASSERT_EQ(0x3Cul, x);
  ASSERT_TRUE(UInt32::TryParse("FE3", 16, x));
  ASSERT_EQ(0xFE3ul, x);
  ASSERT_TRUE(UInt32::TryParse("DeadBeef", 16, x));
  ASSERT_EQ(0xDEADBEEFul, x);
  ASSERT_TRUE(UInt32::TryParse("FFFFFFFF", 16, x));
  ASSERT_EQ(0xFFFFFFFFul, x);
}

TEST(UInt32Test, TryParse_UInt32) {
  UInt32 x;
  ASSERT_TRUE(UInt32::TryParse("0", x));
  ASSERT_EQ(0ul, x);
  ASSERT_TRUE(UInt32::TryParse("1", x));
  ASSERT_EQ(1ul, x);
  ASSERT_TRUE(UInt32::TryParse("123", x));
  ASSERT_EQ(123ul, x);
  ASSERT_TRUE(UInt32::TryParse("123654", x));
  ASSERT_EQ(123654ul, x);
  ASSERT_TRUE(UInt32::TryParse("4294967295", x));
  ASSERT_EQ(0xFFFFFFFFul, x);
}

TEST(UInt32Test, TryParse_Sign_UInt32) {
  UInt32 x;
  ASSERT_TRUE(UInt32::TryParse("+5", x));
  ASSERT_EQ(5ul, x);
  ASSERT_TRUE(UInt32::TryParse("-0", x));
  ASSERT_EQ(0ul, x);
  ASSERT_FALSE(UInt32::TryParse("-1", x));
}

TEST(UInt32Test, TryParse_Leading_Zeros_UInt32) {
  UInt32 x;
  ASSERT_TRUE(UInt32::TryParse("0", x));
  ASSERT_EQ(0ul, x);
  ASSERT_TRUE(UInt32::TryParse("00", x));
  ASSERT_EQ(0ul, x);
  ASSERT_TRUE(UInt32::TryParse("000", x));
  ASSERT_EQ(0ul, x);
  ASSERT_TRUE(UInt32::TryParse("01", x));
  ASSERT_EQ(1ul, x);
  ASSERT_TRUE(UInt32::TryParse("0001", x));
  ASSERT_EQ(1ul, x);
  ASSERT_TRUE(UInt32::TryParse("099", x));
  ASSERT_EQ(99ul, x);
  ASSERT_TRUE(UInt32::TryParse("0000999", x));
  ASSERT_EQ(999ul, x);
}

TEST(UInt32Test, TryParse_Spaces_UInt32) {
  UInt32 x;
  ASSERT_TRUE(UInt32::TryParse(" 5", x));
  ASSERT_EQ(5ul, x);
  ASSERT_TRUE(UInt32::TryParse("     5", x));
  ASSERT_EQ(5ul, x);
  ASSERT_TRUE(UInt32::TryParse("5 ", x));
  ASSERT_EQ(5ul, x);
  ASSERT_TRUE(UInt32::TryParse("51     ", x));
  ASSERT_EQ(51ul, x);
  ASSERT_TRUE(UInt32::TryParse(" 5      ", x));
  ASSERT_EQ(5ul, x);
  ASSERT_TRUE(UInt32::TryParse("        52 ", x));
  ASSERT_EQ(52ul, x);
}

TEST(UInt32Test, TryParse_FormatException_UInt32) {
  UInt32 x;
  ASSERT_FALSE(UInt32::TryParse("", x));
  ASSERT_FALSE(UInt32::TryParse("a56", x));
  ASSERT_FALSE(UInt32::TryParse("0 0", x));
  ASSERT_FALSE(UInt32::TryParse("++000", x));
  ASSERT_FALSE(UInt32::TryParse("+", x));
  ASSERT_FALSE(UInt32::TryParse("-", x));
  ASSERT_FALSE(UInt32::TryParse("--5", x));
  ASSERT_FALSE(UInt32::TryParse("0x53", x));
  ASSERT_FALSE(UInt32::TryParse("100a", x));
  ASSERT_FALSE(UInt32::TryParse("10u", x));
}

TEST(UInt32Test, TryParse_OverflowException_UInt32) {
  UInt32 x;
  ASSERT_FALSE(UInt32::TryParse("-1", x));
  ASSERT_FALSE(UInt32::TryParse("-15602", x));
  ASSERT_TRUE(UInt32::TryParse("4294967295", x));
  ASSERT_EQ(0xFFFFFFFFul, x);
  ASSERT_FALSE(UInt32::TryParse("4294967296", x));
  ASSERT_FALSE(UInt32::TryParse("5294967295", x));
}

TEST(UInt32Test, TryParse_Binary_UInt32) {
  UInt32 x;
  ASSERT_TRUE(UInt32::TryParse("0", 2, x));
  ASSERT_EQ(0ul, x);
  ASSERT_TRUE(UInt32::TryParse("1", 2, x));
  ASSERT_EQ(1ul, x);
  ASSERT_TRUE(UInt32::TryParse("10", 2, x));
  ASSERT_EQ(2ul, x);
  ASSERT_TRUE(UInt32::TryParse("11", 2, x));
  ASSERT_EQ(3ul, x);
  ASSERT_TRUE(UInt32::TryParse("110", 2, x));
  ASSERT_EQ(6ul, x);
}

TEST(UInt32Test, TryParse_Exceptions_Binary_UInt32) {
  UInt32 x;
  ASSERT_FALSE(UInt32::TryParse("", 2, x));
  ASSERT_FALSE(UInt32::TryParse("2", 2, x));
  ASSERT_FALSE(UInt32::TryParse("103", 2, x));
  ASSERT_FALSE(UInt32::TryParse("++0", 2, x));
  ASSERT_FALSE(UInt32::TryParse("+", 2, x));
  ASSERT_FALSE(UInt32::TryParse("-", 2, x));
  ASSERT_FALSE(UInt32::TryParse("--1", 2, x));
  ASSERT_FALSE(UInt32::TryParse("0x53", 2, x));
  ASSERT_FALSE(UInt32::TryParse("100a", 2, x));
  ASSERT_FALSE(UInt32::TryParse("10u", 2, x));
}

TEST(UInt32Test, TryParse_Octal_UInt32) {
  UInt32 x;
  ASSERT_TRUE(UInt32::TryParse("0", 8, x));
  ASSERT_EQ(0ul, x);
  ASSERT_TRUE(UInt32::TryParse("1", 8, x));
  ASSERT_EQ(1ul, x);
  ASSERT_TRUE(UInt32::TryParse("14", 8, x));
  ASSERT_EQ(12ul, x);
  ASSERT_TRUE(UInt32::TryParse("70", 8, x));
  ASSERT_EQ(56ul, x);
  ASSERT_TRUE(UInt32::TryParse("1131", 8, x));
  ASSERT_EQ(601ul, x);
}

TEST(UInt32Test, TryParse_Hexadecimal_UInt32) {
  UInt32 x;
  ASSERT_TRUE(UInt32::TryParse("0", 16, x));
  ASSERT_EQ(0ul, x);
  ASSERT_TRUE(UInt32::TryParse("1", 16, x));
  ASSERT_EQ(1ul, x);
  ASSERT_TRUE(UInt32::TryParse("C", 16, x));
  ASSERT_EQ(0xCul, x);
  ASSERT_TRUE(UInt32::TryParse("3c", 16, x));
  ASSERT_EQ(0x3Cul, x);
  ASSERT_TRUE(UInt32::TryParse("FE3", 16, x));
  ASSERT_EQ(0xFE3ul, x);
  ASSERT_TRUE(UInt32::TryParse("DeadBeef", 16, x));
  ASSERT_EQ(0xDEADBEEFul, x);
  ASSERT_TRUE(UInt32::TryParse("FFFFFFFF", 16, x));
  ASSERT_EQ(0xFFFFFFFFul, x);
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
        MakeTest<UInt32>(s, 5, "");

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
