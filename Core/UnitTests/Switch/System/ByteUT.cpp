#include <Pcf/System/Byte.hpp>
#include <Pcf/System/NumberRepresentationBase.hpp>
#include <Pcf/TUnit/Assert.hpp>
#include <Pcf/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {

TEST(Byte, MaxValue) {
  EXPECT_EQ(255, Byte::MaxValue);
}

TEST(Byte, MinValue) {
  EXPECT_EQ(0, Byte::MinValue);
}

TEST(Byte, DefaultValue) {
  EXPECT_EQ(0, Byte());
}

TEST(Byte, CtorValue) {
  EXPECT_EQ(10, Byte(10));
  EXPECT_EQ(123, Byte(123));
  EXPECT_EQ(205, Byte(205));
  EXPECT_EQ(0, Byte(0));
}

TEST(Byte, Parse) {
  EXPECT_EQ(0, Byte::Parse("0"));
  EXPECT_EQ(1, Byte::Parse("1"));
  EXPECT_EQ(18, Byte::Parse("18"));
  EXPECT_EQ(127, Byte::Parse("127"));
  EXPECT_EQ(255, Byte::Parse("255"));
}

TEST(Byte, Parse_Sign) {
  EXPECT_EQ(0, Byte::Parse("+0"));
  EXPECT_EQ(0, Byte::Parse("-0"));
  EXPECT_EQ(12, Byte::Parse("+12"));
  EXPECT_EQ(255, Byte::Parse("+255"));
}

TEST(Byte, Parse_Leading_Zeros) {
  EXPECT_EQ(0, Byte::Parse("0"));
  EXPECT_EQ(0, Byte::Parse("00"));
  EXPECT_EQ(0, Byte::Parse("000"));
  EXPECT_EQ(1, Byte::Parse("01"));
  EXPECT_EQ(1, Byte::Parse("0001"));
  EXPECT_EQ(99, Byte::Parse("099"));
}

TEST(Byte, Parse_Spaces) {
  EXPECT_EQ(5,Byte::Parse(" 5"));
  EXPECT_EQ(5,Byte::Parse("     5"));
  EXPECT_EQ(5,Byte::Parse("5 "));
  EXPECT_EQ(51,Byte::Parse("51     "));
  EXPECT_EQ(5,Byte::Parse(" 5      "));
  EXPECT_EQ(52,Byte::Parse("        52 "));  
}

TEST(Byte, Parse_FormatException) {
  EXPECT_THROW(Byte::Parse(""), FormatException);
  EXPECT_THROW(Byte::Parse("a56"), FormatException);
  EXPECT_THROW(Byte::Parse("0 0"), FormatException);
  EXPECT_THROW(Byte::Parse("++000"), FormatException);
  EXPECT_THROW(Byte::Parse("+"), FormatException);
  EXPECT_THROW(Byte::Parse("-"), FormatException);
  EXPECT_THROW(Byte::Parse("--5"), FormatException);
  EXPECT_THROW(Byte::Parse("0x53"), FormatException);
  EXPECT_THROW(Byte::Parse("100a"), FormatException);
  EXPECT_THROW(Byte::Parse("10u"), FormatException);
}

TEST(Byte, Parse_OverflowException) {
  EXPECT_EQ(0xFF, Byte::Parse("255"));
  EXPECT_THROW(Byte::Parse("256"), OverflowException);
  EXPECT_THROW(Byte::Parse("1233"), OverflowException);
  EXPECT_THROW(Byte::Parse("-1"), OverflowException);
  EXPECT_THROW(Byte::Parse("-2"), OverflowException);
  EXPECT_THROW(Byte::Parse("-256"), OverflowException);
  EXPECT_THROW(Byte::Parse("-300"), OverflowException);
}

TEST(Byte, Parse_Binary) {
  EXPECT_EQ(0, Byte::Parse("0b", (int32)NumberRepresentationBase::Binary));
  EXPECT_EQ(1, Byte::Parse("1", (int32)NumberRepresentationBase::Binary));
  EXPECT_EQ(2, Byte::Parse("10b", (int32)NumberRepresentationBase::Binary));
  EXPECT_EQ(3, Byte::Parse("11", (int32)NumberRepresentationBase::Binary));
  EXPECT_EQ(6, Byte::Parse("110", (int32)NumberRepresentationBase::Binary));
}

TEST(Byte, Parse_Exceptions_Binary) {
  EXPECT_THROW(Byte::Parse("",2), FormatException);
  EXPECT_THROW(Byte::Parse("2",2), FormatException);
  EXPECT_THROW(Byte::Parse("103",2), FormatException);
  EXPECT_THROW(Byte::Parse("++0",2), FormatException);
  EXPECT_THROW(Byte::Parse("+",2), FormatException);
  EXPECT_THROW(Byte::Parse("-",2), FormatException);
  EXPECT_THROW(Byte::Parse("--1",2), FormatException);
  EXPECT_THROW(Byte::Parse("0x53",2), FormatException);
  EXPECT_THROW(Byte::Parse("100a",2), FormatException);
  EXPECT_THROW(Byte::Parse("10u",2), FormatException);
}

TEST(Byte, Parse_Octal) {
  EXPECT_EQ(0, Byte::Parse("0", (int32)NumberRepresentationBase::Octal));
  EXPECT_EQ(1, Byte::Parse("1", (int32)NumberRepresentationBase::Octal));
  EXPECT_EQ(12, Byte::Parse("14", (int32)NumberRepresentationBase::Octal));
  EXPECT_EQ(56, Byte::Parse("70", (int32)NumberRepresentationBase::Octal));
}

TEST(Byte, Parse_Hexadecimal) {
  EXPECT_EQ(0, Byte::Parse("0x0", (int32)NumberRepresentationBase::Hexadecimal));
  EXPECT_EQ(0, Byte::Parse(" 0x0", (int32)NumberRepresentationBase::Hexadecimal));
  EXPECT_EQ(0, Byte::Parse(" 0x000", (int32)NumberRepresentationBase::Hexadecimal));
  EXPECT_EQ(1, Byte::Parse("1", (int32)NumberRepresentationBase::Hexadecimal));
  EXPECT_EQ(0xC, Byte::Parse("C", (int32)NumberRepresentationBase::Hexadecimal));
  EXPECT_EQ(0x3C, Byte::Parse("3c", (int32)NumberRepresentationBase::Hexadecimal));
  EXPECT_EQ(0x3C, Byte::Parse("0x3c", (int32)NumberRepresentationBase::Hexadecimal));
  EXPECT_EQ(0x3C, Byte::Parse("0X3c", (int32)NumberRepresentationBase::Hexadecimal));
  EXPECT_EQ(0x3C, Byte::Parse("0x3C", (int32)NumberRepresentationBase::Hexadecimal));
}

TEST(Byte, Parse_Hexadecimal_Prefix_OverflowExceptions) {
  EXPECT_THROW(Byte::Parse("0x100", (int32)NumberRepresentationBase::Hexadecimal), OverflowException);
}

TEST(Byte, Parse_Hexadecimal_Prefix_Exceptions) {
  EXPECT_THROW(Byte::Parse("x", (int32)NumberRepresentationBase::Hexadecimal), FormatException);
  EXPECT_THROW(Byte::Parse("x0", (int32)NumberRepresentationBase::Hexadecimal), FormatException);
  EXPECT_THROW(Byte::Parse("0x", (int32)NumberRepresentationBase::Hexadecimal), FormatException);
  EXPECT_THROW(Byte::Parse("00x0", (int32)NumberRepresentationBase::Hexadecimal), FormatException);
  EXPECT_THROW(Byte::Parse("0 x0", (int32)NumberRepresentationBase::Hexadecimal), FormatException);
  EXPECT_THROW(Byte::Parse("0x 0", (int32)NumberRepresentationBase::Hexadecimal), FormatException);
  EXPECT_THROW(Byte::Parse("X", (int32)NumberRepresentationBase::Hexadecimal), FormatException);
  EXPECT_THROW(Byte::Parse("X0", (int32)NumberRepresentationBase::Hexadecimal), FormatException);
  EXPECT_THROW(Byte::Parse("0X", (int32)NumberRepresentationBase::Hexadecimal), FormatException);
  EXPECT_THROW(Byte::Parse("00X0", (int32)NumberRepresentationBase::Hexadecimal), FormatException);
  EXPECT_THROW(Byte::Parse("0 X0", (int32)NumberRepresentationBase::Hexadecimal), FormatException);
  EXPECT_THROW(Byte::Parse("0X 0", (int32)NumberRepresentationBase::Hexadecimal), FormatException);
}

TEST(Byte, TryParse) {
  byte b;
  EXPECT_TRUE(Byte::TryParse("0", b));
  EXPECT_EQ(0, b);
  EXPECT_TRUE(Byte::TryParse("1", b));
  EXPECT_EQ(1, b);
  EXPECT_TRUE(Byte::TryParse("18", b));
  EXPECT_EQ(18, b);
  EXPECT_TRUE(Byte::TryParse("127", b));
  EXPECT_EQ(127, b);
  EXPECT_TRUE(Byte::TryParse("255", b));
  EXPECT_EQ(255, b);
}

TEST(Byte, TryParse_Sign) {
  byte b;
  EXPECT_TRUE(Byte::TryParse("+0", b));
  EXPECT_EQ(0, b);
  EXPECT_TRUE(Byte::TryParse("-0", b));
  EXPECT_EQ(0, b);
  EXPECT_TRUE(Byte::TryParse("+12", b));
  EXPECT_EQ(12, b);
  EXPECT_TRUE(Byte::TryParse("+255", b));
  EXPECT_EQ(255, b);
}

TEST(Byte, TryParse_Leading_Zeros) {
  byte b;
  EXPECT_TRUE(Byte::TryParse("0", b));
  EXPECT_EQ(0, b);
  EXPECT_TRUE(Byte::TryParse("00", b));
  EXPECT_EQ(0, b);
  EXPECT_TRUE(Byte::TryParse("000", b));
  EXPECT_EQ(0, b);
  EXPECT_TRUE(Byte::TryParse("01", b));
  EXPECT_EQ(1, b);
  EXPECT_TRUE(Byte::TryParse("0001", b));
  EXPECT_EQ(1, b);
  EXPECT_TRUE(Byte::TryParse("099", b));
  EXPECT_EQ(99, b);
}

TEST(Byte, TryParse_Spaces) {
  byte b;
  EXPECT_TRUE(Byte::TryParse(" 5", b));
  EXPECT_EQ(5, b);
  EXPECT_TRUE(Byte::TryParse("     5", b));
  EXPECT_EQ(5, b);
  EXPECT_TRUE(Byte::TryParse("5 ", b));
  EXPECT_EQ(5, b);
  EXPECT_TRUE(Byte::TryParse("51     ", b));
  EXPECT_EQ(51, b);
  EXPECT_TRUE(Byte::TryParse(" 5      ", b));
  EXPECT_EQ(5, b);
  EXPECT_TRUE(Byte::TryParse("        52 ", b));  
  EXPECT_EQ(52, b);
}

TEST(Byte, TryParse_Fail_Format) {
  byte b;
  EXPECT_FALSE(Byte::TryParse("", b));
  EXPECT_FALSE(Byte::TryParse("a56", b));
  EXPECT_FALSE(Byte::TryParse("0 0", b));
  EXPECT_FALSE(Byte::TryParse("++000", b));
  EXPECT_FALSE(Byte::TryParse("+", b));
  EXPECT_FALSE(Byte::TryParse("-", b));
  EXPECT_FALSE(Byte::TryParse("--5", b));
  EXPECT_FALSE(Byte::TryParse("0x53", b));
  EXPECT_FALSE(Byte::TryParse("100a", b));
  EXPECT_FALSE(Byte::TryParse("10u", b));
}

TEST(Byte, TryParse_Fail_Overflow) {
  byte b;
  EXPECT_TRUE(Byte::TryParse("255",b));
  EXPECT_EQ(0xFF, b);
  EXPECT_FALSE(Byte::TryParse("256", b));
  EXPECT_FALSE(Byte::TryParse("1233", b));
  EXPECT_FALSE(Byte::TryParse("-1", b));
  EXPECT_FALSE(Byte::TryParse("-2", b));
  EXPECT_FALSE(Byte::TryParse("-256", b));
  EXPECT_FALSE(Byte::TryParse("-300", b));
}

TEST(Byte, TryParse_Binary) {
  byte b;
  EXPECT_TRUE(Byte::TryParse("0b", (int32)NumberRepresentationBase::Binary, b));
  EXPECT_EQ(0, b);
  EXPECT_TRUE(Byte::TryParse("1", (int32)NumberRepresentationBase::Binary, b));
  EXPECT_EQ(1, b);
  EXPECT_TRUE(Byte::TryParse("10b", (int32)NumberRepresentationBase::Binary, b));
  EXPECT_EQ(2, b);
  EXPECT_TRUE(Byte::TryParse("11", (int32)NumberRepresentationBase::Binary, b));
  EXPECT_EQ(3, b);
  EXPECT_TRUE(Byte::TryParse("110", (int32)NumberRepresentationBase::Binary, b));
  EXPECT_EQ(6, b);
}

TEST(Byte, TryParse_Binary_Fail) {
  byte b;
  EXPECT_FALSE(Byte::TryParse("",2, b));
  EXPECT_FALSE(Byte::TryParse("2",2, b));
  EXPECT_FALSE(Byte::TryParse("103",2, b));
  EXPECT_FALSE(Byte::TryParse("++0",2, b));
  EXPECT_FALSE(Byte::TryParse("+",2, b));
  EXPECT_FALSE(Byte::TryParse("-",2, b));
  EXPECT_FALSE(Byte::TryParse("--1",2, b));
  EXPECT_FALSE(Byte::TryParse("0x53",2, b));
  EXPECT_FALSE(Byte::TryParse("100a",2, b));
  EXPECT_FALSE(Byte::TryParse("10u",2, b));
}

TEST(Byte, TryParse_Octal) {
  byte b;
  EXPECT_TRUE(Byte::TryParse("0", (int32)NumberRepresentationBase::Octal, b));
  EXPECT_EQ(0, b);
  EXPECT_TRUE(Byte::TryParse("1", (int32)NumberRepresentationBase::Octal, b));
  EXPECT_EQ(1, b);
  EXPECT_TRUE(Byte::TryParse("14", (int32)NumberRepresentationBase::Octal, b));
  EXPECT_EQ(12, b);
  EXPECT_TRUE(Byte::TryParse("70", (int32)NumberRepresentationBase::Octal, b));
  EXPECT_EQ(56, b);
}

TEST(Byte, TryParse_Hexadecimal) {
  byte b;
  EXPECT_TRUE(Byte::TryParse("0x0", (int32)NumberRepresentationBase::Hexadecimal,b));
  EXPECT_EQ(0, b);
  EXPECT_TRUE(Byte::TryParse(" 0x0", (int32)NumberRepresentationBase::Hexadecimal,b));
  EXPECT_EQ(0, b);
  EXPECT_TRUE(Byte::TryParse(" 0x000", (int32)NumberRepresentationBase::Hexadecimal,b));
  EXPECT_EQ(0, b);
  EXPECT_TRUE(Byte::TryParse("1", (int32)NumberRepresentationBase::Hexadecimal,b));
  EXPECT_EQ(1, b);
  EXPECT_TRUE(Byte::TryParse("C", (int32)NumberRepresentationBase::Hexadecimal,b));
  EXPECT_EQ(0xC, b);
  EXPECT_TRUE(Byte::TryParse("3c", (int32)NumberRepresentationBase::Hexadecimal,b));
  EXPECT_EQ(0x3C, b);
  EXPECT_TRUE(Byte::TryParse("0x3c", (int32)NumberRepresentationBase::Hexadecimal,b));
  EXPECT_EQ(0x3C, b);
  EXPECT_TRUE(Byte::TryParse("0x3C", (int32)NumberRepresentationBase::Hexadecimal,b));
  EXPECT_EQ(0x3C, b);
}

TEST(Byte, TryParse_Hexadecimal_Fail) {
  byte b;
  EXPECT_FALSE(Byte::TryParse("x", (int32)NumberRepresentationBase::Hexadecimal, b));
  EXPECT_FALSE(Byte::TryParse("x0", (int32)NumberRepresentationBase::Hexadecimal, b));
  EXPECT_FALSE(Byte::TryParse("0x", (int32)NumberRepresentationBase::Hexadecimal, b));
  EXPECT_FALSE(Byte::TryParse("00x0", (int32)NumberRepresentationBase::Hexadecimal, b));
  EXPECT_FALSE(Byte::TryParse("0 x0", (int32)NumberRepresentationBase::Hexadecimal, b));
  EXPECT_FALSE(Byte::TryParse("0x 0", (int32)NumberRepresentationBase::Hexadecimal, b));
  EXPECT_FALSE(Byte::TryParse("X", (int32)NumberRepresentationBase::Hexadecimal, b));
  EXPECT_FALSE(Byte::TryParse("X0", (int32)NumberRepresentationBase::Hexadecimal, b));
  EXPECT_FALSE(Byte::TryParse("0X", (int32)NumberRepresentationBase::Hexadecimal, b));
  EXPECT_FALSE(Byte::TryParse("00X0", (int32)NumberRepresentationBase::Hexadecimal, b));
  EXPECT_FALSE(Byte::TryParse("0 X0", (int32)NumberRepresentationBase::Hexadecimal, b));
  EXPECT_FALSE(Byte::TryParse("0X 0", (int32)NumberRepresentationBase::Hexadecimal,b));
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
