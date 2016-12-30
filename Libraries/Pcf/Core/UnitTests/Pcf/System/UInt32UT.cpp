#include <Pcf/System/UInt32.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {

TEST(UInt32, MaxValue) {
  EXPECT_EQ(0xFFFFFFFFU, UInt32::MaxValue);
}

TEST(UInt32, MinValue) {
  EXPECT_EQ(0ul, UInt32::MinValue);
}

TEST(UInt32, DefaultValue) {
  EXPECT_EQ(0ul, UInt32());
}

TEST(UInt32, CtorValue) {
  EXPECT_EQ(10ul, UInt32(10ul));
  EXPECT_EQ(123654ul, UInt32(123654ul));
  EXPECT_EQ(0ul, UInt32(0ul));
}

TEST(UInt32, Parse) {
  EXPECT_EQ(0ul, UInt32::Parse("0"));
  EXPECT_EQ(1ul, UInt32::Parse("1"));
  EXPECT_EQ(123ul, UInt32::Parse("123"));
  EXPECT_EQ(123654ul, UInt32::Parse("123654"));
  EXPECT_EQ(0xFFFFFFFFul, UInt32::Parse("4294967295"));
}

TEST(UInt32, Parse_Sign) {
  EXPECT_EQ(5ul, UInt32::Parse("+5"));
  EXPECT_EQ(0ul, UInt32::Parse("-0"));
  EXPECT_THROW(UInt32::Parse("-1"), OverflowException);
}

TEST(UInt32, Parse_Leading_Zeros) {
  EXPECT_EQ(0ul, UInt32::Parse("0"));
  EXPECT_EQ(0ul, UInt32::Parse("00"));
  EXPECT_EQ(0ul, UInt32::Parse("000"));
  EXPECT_EQ(1ul, UInt32::Parse("01"));
  EXPECT_EQ(1ul, UInt32::Parse("0001"));
  EXPECT_EQ(99ul, UInt32::Parse("099"));
  EXPECT_EQ(999ul, UInt32::Parse("0000999"));
}

TEST(UInt32, Parse_Spaces) {
  EXPECT_EQ(5ul, UInt32::Parse(" 5"));
  EXPECT_EQ(5ul, UInt32::Parse("     5"));
  EXPECT_EQ(5ul, UInt32::Parse("5 "));
  EXPECT_EQ(51ul, UInt32::Parse("51     "));
  EXPECT_EQ(5ul, UInt32::Parse(" 5      "));
  EXPECT_EQ(52ul, UInt32::Parse("        52 "));
}

TEST(UInt32, Parse_FormatException) {
  EXPECT_THROW(UInt32::Parse(""), FormatException);
  EXPECT_THROW(UInt32::Parse("a56"), FormatException);
  EXPECT_THROW(UInt32::Parse("0 0"), FormatException);
  EXPECT_THROW(UInt32::Parse("++000"), FormatException);
  EXPECT_THROW(UInt32::Parse("+"), FormatException);
  EXPECT_THROW(UInt32::Parse("-"), FormatException);
  EXPECT_THROW(UInt32::Parse("--5"), FormatException);
  EXPECT_THROW(UInt32::Parse("0x53"), FormatException);
  EXPECT_THROW(UInt32::Parse("100a"), FormatException);
  EXPECT_THROW(UInt32::Parse("10u"), FormatException);
}

TEST(UInt32, Parse_OverflowException) {
  EXPECT_THROW(UInt32::Parse("-1"), OverflowException);
  EXPECT_THROW(UInt32::Parse("-15602"), OverflowException);
  EXPECT_EQ(0xFFFFFFFFul, UInt32::Parse("4294967295"));
  EXPECT_THROW(UInt32::Parse("4294967296"), OverflowException);
  EXPECT_THROW(UInt32::Parse("5294967295"), OverflowException);
}

TEST(UInt32, Parse_Binary) {
  EXPECT_EQ(0ul, UInt32::Parse("0",2));
  EXPECT_EQ(1ul, UInt32::Parse("1",2));
  EXPECT_EQ(2ul, UInt32::Parse("10",2));
  EXPECT_EQ(3ul, UInt32::Parse("11",2));
  EXPECT_EQ(6ul, UInt32::Parse("110",2));
}

TEST(UInt32, Parse_Exceptions_Binary) {
  EXPECT_THROW(UInt32::Parse("",2), FormatException);
  EXPECT_THROW(UInt32::Parse("2",2), FormatException);
  EXPECT_THROW(UInt32::Parse("103",2), FormatException);
  EXPECT_THROW(UInt32::Parse("++0",2), FormatException);
  EXPECT_THROW(UInt32::Parse("+",2), FormatException);
  EXPECT_THROW(UInt32::Parse("-",2), FormatException);
  EXPECT_THROW(UInt32::Parse("--1",2), FormatException);
  EXPECT_THROW(UInt32::Parse("0x53",2), FormatException);
  EXPECT_THROW(UInt32::Parse("100a",2), FormatException);
  EXPECT_THROW(UInt32::Parse("10u",2), FormatException);
}

TEST(UInt32, Parse_Octal) {
  EXPECT_EQ(0ul, UInt32::Parse("0",8));
  EXPECT_EQ(1ul, UInt32::Parse("1",8));
  EXPECT_EQ(12ul, UInt32::Parse("14",8));
  EXPECT_EQ(56ul, UInt32::Parse("70",8));
  EXPECT_EQ(601ul, UInt32::Parse("1131",8));
}

TEST(UInt32, Parse_Hexadecimal) {
  EXPECT_EQ(0ul, UInt32::Parse("0", 16));
  EXPECT_EQ(1ul, UInt32::Parse("1", 16));
  EXPECT_EQ(0xCul, UInt32::Parse("C", 16));
  EXPECT_EQ(0x3Cul, UInt32::Parse("3c", 16));
  EXPECT_EQ(0xFE3ul, UInt32::Parse("FE3", 16));
  EXPECT_EQ(0xDEADBEEFul, UInt32::Parse("DeadBeef", 16));
  EXPECT_EQ(0xFFFFFFFFul, UInt32::Parse("FFFFFFFF", 16));
}

TEST(UInt32, TryParse) {
  uint32 x;
  EXPECT_TRUE(UInt32::TryParse("0", x));
  EXPECT_EQ(0ul, x);
  EXPECT_TRUE(UInt32::TryParse("1", x));
  EXPECT_EQ(1ul, x);
  EXPECT_TRUE(UInt32::TryParse("123", x));
  EXPECT_EQ(123ul, x);
  EXPECT_TRUE(UInt32::TryParse("123654", x));
  EXPECT_EQ(123654ul, x);
  EXPECT_TRUE(UInt32::TryParse("4294967295", x));
  EXPECT_EQ(0xFFFFFFFFul, x);
}

TEST(UInt32, TryParse_Sign) {
  uint32 x;
  EXPECT_TRUE(UInt32::TryParse("+5", x));
  EXPECT_EQ(5ul, x);
  EXPECT_TRUE(UInt32::TryParse("-0", x));
  EXPECT_EQ(0ul, x);
  EXPECT_FALSE(UInt32::TryParse("-1", x));
}

TEST(UInt32, TryParse_Leading_Zeros) {
  uint32 x;
  EXPECT_TRUE(UInt32::TryParse("0", x));
  EXPECT_EQ(0ul, x);
  EXPECT_TRUE(UInt32::TryParse("00", x));
  EXPECT_EQ(0ul, x);
  EXPECT_TRUE(UInt32::TryParse("000", x));
  EXPECT_EQ(0ul, x);
  EXPECT_TRUE(UInt32::TryParse("01", x));
  EXPECT_EQ(1ul, x);
  EXPECT_TRUE(UInt32::TryParse("0001", x));
  EXPECT_EQ(1ul, x);
  EXPECT_TRUE(UInt32::TryParse("099", x));
  EXPECT_EQ(99ul, x);
  EXPECT_TRUE(UInt32::TryParse("0000999", x));
  EXPECT_EQ(999ul, x);
}

TEST(UInt32, TryParse_Spaces) {
  uint32 x;
  EXPECT_TRUE(UInt32::TryParse(" 5", x));
  EXPECT_EQ(5ul, x);
  EXPECT_TRUE(UInt32::TryParse("     5", x));
  EXPECT_EQ(5ul, x);
  EXPECT_TRUE(UInt32::TryParse("5 ", x));
  EXPECT_EQ(5ul, x);
  EXPECT_TRUE(UInt32::TryParse("51     ", x));
  EXPECT_EQ(51ul, x);
  EXPECT_TRUE(UInt32::TryParse(" 5      ", x));
  EXPECT_EQ(5ul, x);
  EXPECT_TRUE(UInt32::TryParse("        52 ", x));
  EXPECT_EQ(52ul, x);
}

TEST(UInt32, TryParse_FormatException) {
  uint32 x;
  EXPECT_FALSE(UInt32::TryParse("", x));
  EXPECT_FALSE(UInt32::TryParse("a56", x));
  EXPECT_FALSE(UInt32::TryParse("0 0", x));
  EXPECT_FALSE(UInt32::TryParse("++000", x));
  EXPECT_FALSE(UInt32::TryParse("+", x));
  EXPECT_FALSE(UInt32::TryParse("-", x));
  EXPECT_FALSE(UInt32::TryParse("--5", x));
  EXPECT_FALSE(UInt32::TryParse("0x53", x));
  EXPECT_FALSE(UInt32::TryParse("100a", x));
  EXPECT_FALSE(UInt32::TryParse("10u", x));
}

TEST(UInt32, TryParse_OverflowException) {
  uint32 x;
  EXPECT_FALSE(UInt32::TryParse("-1", x));
  EXPECT_FALSE(UInt32::TryParse("-15602", x));
  EXPECT_TRUE(UInt32::TryParse("4294967295", x));
  EXPECT_EQ(0xFFFFFFFFul, x);
  EXPECT_FALSE(UInt32::TryParse("4294967296", x));
  EXPECT_FALSE(UInt32::TryParse("5294967295", x));
}

TEST(UInt32, TryParse_Binary) {
  uint32 x;
  EXPECT_TRUE(UInt32::TryParse("0", 2, x));
  EXPECT_EQ(0ul, x);
  EXPECT_TRUE(UInt32::TryParse("1", 2, x));
  EXPECT_EQ(1ul, x);
  EXPECT_TRUE(UInt32::TryParse("10", 2, x));
  EXPECT_EQ(2ul, x);
  EXPECT_TRUE(UInt32::TryParse("11", 2, x));
  EXPECT_EQ(3ul, x);
  EXPECT_TRUE(UInt32::TryParse("110", 2, x));
  EXPECT_EQ(6ul, x);
}

TEST(UInt32, TryParse_Exceptions_Binary) {
  uint32 x;
  EXPECT_FALSE(UInt32::TryParse("", 2, x));
  EXPECT_FALSE(UInt32::TryParse("2", 2, x));
  EXPECT_FALSE(UInt32::TryParse("103", 2, x));
  EXPECT_FALSE(UInt32::TryParse("++0", 2, x));
  EXPECT_FALSE(UInt32::TryParse("+", 2, x));
  EXPECT_FALSE(UInt32::TryParse("-", 2, x));
  EXPECT_FALSE(UInt32::TryParse("--1", 2, x));
  EXPECT_FALSE(UInt32::TryParse("0x53", 2, x));
  EXPECT_FALSE(UInt32::TryParse("100a", 2, x));
  EXPECT_FALSE(UInt32::TryParse("10u", 2, x));
}

TEST(UInt32, TryParse_Octal) {
  uint32 x;
  EXPECT_TRUE(UInt32::TryParse("0", 8, x));
  EXPECT_EQ(0ul, x);
  EXPECT_TRUE(UInt32::TryParse("1", 8, x));
  EXPECT_EQ(1ul, x);
  EXPECT_TRUE(UInt32::TryParse("14", 8, x));
  EXPECT_EQ(12ul, x);
  EXPECT_TRUE(UInt32::TryParse("70", 8, x));
  EXPECT_EQ(56ul, x);
  EXPECT_TRUE(UInt32::TryParse("1131", 8, x));
  EXPECT_EQ(601ul, x);
}

TEST(UInt32, TryParse_Hexadecimal) {
  uint32 x;
  EXPECT_TRUE(UInt32::TryParse("0", 16, x));
  EXPECT_EQ(0ul, x);
  EXPECT_TRUE(UInt32::TryParse("1", 16, x));
  EXPECT_EQ(1ul, x);
  EXPECT_TRUE(UInt32::TryParse("C", 16, x));
  EXPECT_EQ(0xCul, x);
  EXPECT_TRUE(UInt32::TryParse("3c", 16, x));
  EXPECT_EQ(0x3Cul, x);
  EXPECT_TRUE(UInt32::TryParse("FE3", 16, x));
  EXPECT_EQ(0xFE3ul, x);
  EXPECT_TRUE(UInt32::TryParse("DeadBeef", 16, x));
  EXPECT_EQ(0xDEADBEEFul, x);
  EXPECT_TRUE(UInt32::TryParse("FFFFFFFF", 16, x));
  EXPECT_EQ(0xFFFFFFFFul, x);
}

TEST(UInt32, TryParse_UInt32) {
  UInt32 x;
  EXPECT_TRUE(UInt32::TryParse("0", x));
  EXPECT_EQ(0ul, x);
  EXPECT_TRUE(UInt32::TryParse("1", x));
  EXPECT_EQ(1ul, x);
  EXPECT_TRUE(UInt32::TryParse("123", x));
  EXPECT_EQ(123ul, x);
  EXPECT_TRUE(UInt32::TryParse("123654", x));
  EXPECT_EQ(123654ul, x);
  EXPECT_TRUE(UInt32::TryParse("4294967295", x));
  EXPECT_EQ(0xFFFFFFFFul, x);
}

TEST(UInt32, TryParse_Sign_UInt32) {
  UInt32 x;
  EXPECT_TRUE(UInt32::TryParse("+5", x));
  EXPECT_EQ(5ul, x);
  EXPECT_TRUE(UInt32::TryParse("-0", x));
  EXPECT_EQ(0ul, x);
  EXPECT_FALSE(UInt32::TryParse("-1", x));
}

TEST(UInt32, TryParse_Leading_Zeros_UInt32) {
  UInt32 x;
  EXPECT_TRUE(UInt32::TryParse("0", x));
  EXPECT_EQ(0ul, x);
  EXPECT_TRUE(UInt32::TryParse("00", x));
  EXPECT_EQ(0ul, x);
  EXPECT_TRUE(UInt32::TryParse("000", x));
  EXPECT_EQ(0ul, x);
  EXPECT_TRUE(UInt32::TryParse("01", x));
  EXPECT_EQ(1ul, x);
  EXPECT_TRUE(UInt32::TryParse("0001", x));
  EXPECT_EQ(1ul, x);
  EXPECT_TRUE(UInt32::TryParse("099", x));
  EXPECT_EQ(99ul, x);
  EXPECT_TRUE(UInt32::TryParse("0000999", x));
  EXPECT_EQ(999ul, x);
}

TEST(UInt32, TryParse_Spaces_UInt32) {
  UInt32 x;
  EXPECT_TRUE(UInt32::TryParse(" 5", x));
  EXPECT_EQ(5ul, x);
  EXPECT_TRUE(UInt32::TryParse("     5", x));
  EXPECT_EQ(5ul, x);
  EXPECT_TRUE(UInt32::TryParse("5 ", x));
  EXPECT_EQ(5ul, x);
  EXPECT_TRUE(UInt32::TryParse("51     ", x));
  EXPECT_EQ(51ul, x);
  EXPECT_TRUE(UInt32::TryParse(" 5      ", x));
  EXPECT_EQ(5ul, x);
  EXPECT_TRUE(UInt32::TryParse("        52 ", x));
  EXPECT_EQ(52ul, x);
}

TEST(UInt32, TryParse_FormatException_UInt32) {
  UInt32 x;
  EXPECT_FALSE(UInt32::TryParse("", x));
  EXPECT_FALSE(UInt32::TryParse("a56", x));
  EXPECT_FALSE(UInt32::TryParse("0 0", x));
  EXPECT_FALSE(UInt32::TryParse("++000", x));
  EXPECT_FALSE(UInt32::TryParse("+", x));
  EXPECT_FALSE(UInt32::TryParse("-", x));
  EXPECT_FALSE(UInt32::TryParse("--5", x));
  EXPECT_FALSE(UInt32::TryParse("0x53", x));
  EXPECT_FALSE(UInt32::TryParse("100a", x));
  EXPECT_FALSE(UInt32::TryParse("10u", x));
}

TEST(UInt32, TryParse_OverflowException_UInt32) {
  UInt32 x;
  EXPECT_FALSE(UInt32::TryParse("-1", x));
  EXPECT_FALSE(UInt32::TryParse("-15602", x));
  EXPECT_TRUE(UInt32::TryParse("4294967295", x));
  EXPECT_EQ(0xFFFFFFFFul, x);
  EXPECT_FALSE(UInt32::TryParse("4294967296", x));
  EXPECT_FALSE(UInt32::TryParse("5294967295", x));
}

TEST(UInt32, TryParse_Binary_UInt32) {
  UInt32 x;
  EXPECT_TRUE(UInt32::TryParse("0", 2, x));
  EXPECT_EQ(0ul, x);
  EXPECT_TRUE(UInt32::TryParse("1", 2, x));
  EXPECT_EQ(1ul, x);
  EXPECT_TRUE(UInt32::TryParse("10", 2, x));
  EXPECT_EQ(2ul, x);
  EXPECT_TRUE(UInt32::TryParse("11", 2, x));
  EXPECT_EQ(3ul, x);
  EXPECT_TRUE(UInt32::TryParse("110", 2, x));
  EXPECT_EQ(6ul, x);
}

TEST(UInt32, TryParse_Exceptions_Binary_UInt32) {
  UInt32 x;
  EXPECT_FALSE(UInt32::TryParse("", 2, x));
  EXPECT_FALSE(UInt32::TryParse("2", 2, x));
  EXPECT_FALSE(UInt32::TryParse("103", 2, x));
  EXPECT_FALSE(UInt32::TryParse("++0", 2, x));
  EXPECT_FALSE(UInt32::TryParse("+", 2, x));
  EXPECT_FALSE(UInt32::TryParse("-", 2, x));
  EXPECT_FALSE(UInt32::TryParse("--1", 2, x));
  EXPECT_FALSE(UInt32::TryParse("0x53", 2, x));
  EXPECT_FALSE(UInt32::TryParse("100a", 2, x));
  EXPECT_FALSE(UInt32::TryParse("10u", 2, x));
}

TEST(UInt32, TryParse_Octal_UInt32) {
  UInt32 x;
  EXPECT_TRUE(UInt32::TryParse("0", 8, x));
  EXPECT_EQ(0ul, x);
  EXPECT_TRUE(UInt32::TryParse("1", 8, x));
  EXPECT_EQ(1ul, x);
  EXPECT_TRUE(UInt32::TryParse("14", 8, x));
  EXPECT_EQ(12ul, x);
  EXPECT_TRUE(UInt32::TryParse("70", 8, x));
  EXPECT_EQ(56ul, x);
  EXPECT_TRUE(UInt32::TryParse("1131", 8, x));
  EXPECT_EQ(601ul, x);
}

TEST(UInt32, TryParse_Hexadecimal_UInt32) {
  UInt32 x;
  EXPECT_TRUE(UInt32::TryParse("0", 16, x));
  EXPECT_EQ(0ul, x);
  EXPECT_TRUE(UInt32::TryParse("1", 16, x));
  EXPECT_EQ(1ul, x);
  EXPECT_TRUE(UInt32::TryParse("C", 16, x));
  EXPECT_EQ(0xCul, x);
  EXPECT_TRUE(UInt32::TryParse("3c", 16, x));
  EXPECT_EQ(0x3Cul, x);
  EXPECT_TRUE(UInt32::TryParse("FE3", 16, x));
  EXPECT_EQ(0xFE3ul, x);
  EXPECT_TRUE(UInt32::TryParse("DeadBeef", 16, x));
  EXPECT_EQ(0xDEADBEEFul, x);
  EXPECT_TRUE(UInt32::TryParse("FFFFFFFF", 16, x));
  EXPECT_EQ(0xFFFFFFFFul, x);
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