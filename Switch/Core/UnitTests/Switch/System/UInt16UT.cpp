#include <Switch/System/UInt16.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  TEST(UInt16, MaxValue) {
    EXPECT_EQ(0xFFFFu, UInt16::MaxValue);
  }
  
  TEST(UInt16, MinValue) {
    EXPECT_EQ(0u, UInt16::MinValue);
  }
  
  TEST(UInt16, DefaultValue) {
    EXPECT_EQ(0u, UInt16());
  }
  
  TEST(UInt16, CtorValue) {
    EXPECT_EQ(10u, UInt16(10u));
    EXPECT_EQ(12654u, UInt16(12654u));
    EXPECT_EQ(0u, UInt16(0u));
  }
  
  TEST(UInt16, Parse) {
    EXPECT_EQ(0u, UInt16::Parse("0"));
    EXPECT_EQ(1u, UInt16::Parse("1"));
    EXPECT_EQ(123u, UInt16::Parse("123"));
    EXPECT_EQ(12365u, UInt16::Parse("12365"));
    EXPECT_EQ(0xFFFFu, UInt16::Parse("65535"));
  }
  
  TEST(UInt16, Parse_Sign) {
    EXPECT_EQ(5u, UInt16::Parse("+5"));
    EXPECT_EQ(0u, UInt16::Parse("-0"));
    EXPECT_THROW(UInt16::Parse("-1"), OverflowException);
  }
  
  TEST(UInt16, Parse_Leading_Zeros) {
    EXPECT_EQ(0u, UInt16::Parse("0"));
    EXPECT_EQ(0u, UInt16::Parse("00"));
    EXPECT_EQ(0u, UInt16::Parse("000"));
    EXPECT_EQ(1u, UInt16::Parse("01"));
    EXPECT_EQ(1u, UInt16::Parse("0001"));
    EXPECT_EQ(99u, UInt16::Parse("099"));
    EXPECT_EQ(999u, UInt16::Parse("0000999"));
  }
  
  TEST(UInt16, Parse_Spaces) {
    EXPECT_EQ(5u,UInt16::Parse(" 5"));
    EXPECT_EQ(5u,UInt16::Parse("     5"));
    EXPECT_EQ(5u,UInt16::Parse("5 "));
    EXPECT_EQ(51u,UInt16::Parse("51     "));
    EXPECT_EQ(5u,UInt16::Parse(" 5      "));
    EXPECT_EQ(52u,UInt16::Parse("        52 "));
  }
  
  TEST(UInt16, Parse_FormatException) {
    EXPECT_THROW(UInt16::Parse(""), FormatException);
    EXPECT_THROW(UInt16::Parse("a56"), FormatException);
    EXPECT_THROW(UInt16::Parse("0 0"), FormatException);
    EXPECT_THROW(UInt16::Parse("++000"), FormatException);
    EXPECT_THROW(UInt16::Parse("+"), FormatException);
    EXPECT_THROW(UInt16::Parse("-"), FormatException);
    EXPECT_THROW(UInt16::Parse("--5"), FormatException);
    EXPECT_THROW(UInt16::Parse("0x53"), FormatException);
    EXPECT_THROW(UInt16::Parse("100a"), FormatException);
    EXPECT_THROW(UInt16::Parse("10u"), FormatException);
  }
  
  TEST(UInt16, Parse_OverflowException) {
    EXPECT_THROW(UInt16::Parse("-1"), OverflowException);
    EXPECT_THROW(UInt16::Parse("-15602"), OverflowException);
    EXPECT_EQ(0xFFFFu, UInt16::Parse("65535"));
    EXPECT_EQ(0xFFFFu, UInt16::Parse("0065535"));
    EXPECT_THROW(UInt16::Parse("65536"), OverflowException);
    EXPECT_THROW(UInt16::Parse("4294967296"), OverflowException);
    EXPECT_THROW(UInt16::Parse("5294967295"), OverflowException);
  }
  
  TEST(UInt16, Parse_Binary) {
    EXPECT_EQ(0u, UInt16::Parse("0",2));
    EXPECT_EQ(1u, UInt16::Parse("1",2));
    EXPECT_EQ(2u, UInt16::Parse("10",2));
    EXPECT_EQ(3u, UInt16::Parse("11",2));
    EXPECT_EQ(6u, UInt16::Parse("110",2));
  }
  
  TEST(UInt16, Parse_Exceptions_Binary) {
    EXPECT_THROW(UInt16::Parse("",2), FormatException);
    EXPECT_THROW(UInt16::Parse("2",2), FormatException);
    EXPECT_THROW(UInt16::Parse("103",2), FormatException);
    EXPECT_THROW(UInt16::Parse("++0",2), FormatException);
    EXPECT_THROW(UInt16::Parse("+",2), FormatException);
    EXPECT_THROW(UInt16::Parse("-",2), FormatException);
    EXPECT_THROW(UInt16::Parse("--1",2), FormatException);
    EXPECT_THROW(UInt16::Parse("0x53",2), FormatException);
    EXPECT_THROW(UInt16::Parse("100a",2), FormatException);
    EXPECT_THROW(UInt16::Parse("10u",2), FormatException);
  }
  
  TEST(UInt16, Parse_Octal) {
    EXPECT_EQ(0u, UInt16::Parse("0",8));
    EXPECT_EQ(1u, UInt16::Parse("1",8));
    EXPECT_EQ(12u, UInt16::Parse("14",8));
    EXPECT_EQ(56u, UInt16::Parse("70",8));
    EXPECT_EQ(601u, UInt16::Parse("1131",8));
  }
  
  TEST(UInt16, Parse_Hexadecimal) {
    EXPECT_EQ(0u, UInt16::Parse("0", 16));
    EXPECT_EQ(1u, UInt16::Parse("1", 16));
    EXPECT_EQ(0xCu, UInt16::Parse("C", 16));
    EXPECT_EQ(0x3Cu, UInt16::Parse("3c", 16));
    EXPECT_EQ(0xFE3u, UInt16::Parse("FE3", 16));
    EXPECT_EQ(0xFFFFu, UInt16::Parse("FFFF", 16));
    EXPECT_THROW(UInt16::Parse("10000", 16), OverflowException);
  }

  TEST(UInt16, TryParse) {
    uint16 x;
    EXPECT_TRUE(UInt16::TryParse("0", x));
    EXPECT_EQ(0u, x);
    EXPECT_TRUE(UInt16::TryParse("1", x));
    EXPECT_EQ(1u, x);
    EXPECT_TRUE(UInt16::TryParse("123", x));
    EXPECT_EQ(123u, x);
    EXPECT_TRUE(UInt16::TryParse("12365", x));
    EXPECT_EQ(12365u, x);
    EXPECT_TRUE(UInt16::TryParse("65535", x));
    EXPECT_EQ(0xFFFFu, x);
  }
  
  TEST(UInt16, TryParse_Sign) {
    uint16 x;
    EXPECT_TRUE(UInt16::TryParse("+5", x));
    EXPECT_EQ(5u, x);
    EXPECT_TRUE(UInt16::TryParse("-0", x));
    EXPECT_EQ(0u, x);
    EXPECT_FALSE(UInt16::TryParse("-1", x));
  }
  
  TEST(UInt16, TryParse_Leading_Zeros) {
    uint16 x;
    EXPECT_TRUE(UInt16::TryParse("0", x));
    EXPECT_EQ(0u, x);
    EXPECT_TRUE(UInt16::TryParse("00", x));
    EXPECT_EQ(0u, x);
    EXPECT_TRUE(UInt16::TryParse("000", x));
    EXPECT_EQ(0u, x);
    EXPECT_TRUE(UInt16::TryParse("01", x));
    EXPECT_EQ(1u, x);
    EXPECT_TRUE(UInt16::TryParse("0001", x));
    EXPECT_EQ(1u, x);
    EXPECT_TRUE(UInt16::TryParse("099", x));
    EXPECT_EQ(99u, x);
    EXPECT_TRUE(UInt16::TryParse("0000999", x));
    EXPECT_EQ(999u, x);
  }
  
  TEST(UInt16, TryParse_Spaces) {
    uint16 x;
    EXPECT_TRUE(UInt16::TryParse(" 5", x));
    EXPECT_EQ(5u, x);
    EXPECT_TRUE(UInt16::TryParse("     5", x));
    EXPECT_EQ(5u, x);
    EXPECT_TRUE(UInt16::TryParse("5 ", x));
    EXPECT_EQ(5u, x);
    EXPECT_TRUE(UInt16::TryParse("51     ", x));
    EXPECT_EQ(51u, x);
    EXPECT_TRUE(UInt16::TryParse(" 5      ", x));
    EXPECT_EQ(5u, x);
    EXPECT_TRUE(UInt16::TryParse("        52 ", x));
    EXPECT_EQ(52u, x);
  }
  
  TEST(UInt16, TryParse_FormatException) {
    uint16 x;
    EXPECT_FALSE(UInt16::TryParse("", x));
    EXPECT_FALSE(UInt16::TryParse("a56", x));
    EXPECT_FALSE(UInt16::TryParse("0 0", x));
    EXPECT_FALSE(UInt16::TryParse("++000", x));
    EXPECT_FALSE(UInt16::TryParse("+", x));
    EXPECT_FALSE(UInt16::TryParse("-", x));
    EXPECT_FALSE(UInt16::TryParse("--5", x));
    EXPECT_FALSE(UInt16::TryParse("0x53", x));
    EXPECT_FALSE(UInt16::TryParse("100a", x));
    EXPECT_FALSE(UInt16::TryParse("10u", x));
  }
  
  TEST(UInt16, TryParse_OverflowException) {
    uint16 x;
    EXPECT_FALSE(UInt16::TryParse("-1", x));
    EXPECT_FALSE(UInt16::TryParse("-15602", x));
    EXPECT_TRUE(UInt16::TryParse("65535", x));
    EXPECT_EQ(0xFFFFu, x);
    EXPECT_TRUE(UInt16::TryParse("0065535", x));
    EXPECT_EQ(0xFFFFu, x);
    EXPECT_FALSE(UInt16::TryParse("65536", x));
    EXPECT_FALSE(UInt16::TryParse("4294967296", x));
    EXPECT_FALSE(UInt16::TryParse("5294967295", x));
  }
  
  TEST(UInt16, TryParse_Binary) {
    uint16 x;
    EXPECT_TRUE(UInt16::TryParse("0", 2, x));
    EXPECT_EQ(0u, x);
    EXPECT_TRUE(UInt16::TryParse("1", 2, x));
    EXPECT_EQ(1u, x);
    EXPECT_TRUE(UInt16::TryParse("10", 2, x));
    EXPECT_EQ(2u, x);
    EXPECT_TRUE(UInt16::TryParse("11", 2, x));
    EXPECT_EQ(3u, x);
    EXPECT_TRUE(UInt16::TryParse("110", 2, x));
    EXPECT_EQ(6u, x);
  }
  
  TEST(UInt16, TryParse_Exceptions_Binary) {
    uint16 x;
    EXPECT_FALSE(UInt16::TryParse("", 2, x));
    EXPECT_FALSE(UInt16::TryParse("2", 2, x));
    EXPECT_FALSE(UInt16::TryParse("103", 2, x));
    EXPECT_FALSE(UInt16::TryParse("++0", 2, x));
    EXPECT_FALSE(UInt16::TryParse("+", 2, x));
    EXPECT_FALSE(UInt16::TryParse("-", 2, x));
    EXPECT_FALSE(UInt16::TryParse("--1", 2, x));
    EXPECT_FALSE(UInt16::TryParse("0x53", 2, x));
    EXPECT_FALSE(UInt16::TryParse("100a", 2, x));
    EXPECT_FALSE(UInt16::TryParse("10u", 2, x));
  }
  
  TEST(UInt16, TryParse_Octal) {
    uint16 x;
    EXPECT_TRUE(UInt16::TryParse("0", 8, x));
    EXPECT_EQ(0u, x);
    EXPECT_TRUE(UInt16::TryParse("1", 8, x));
    EXPECT_EQ(1u, x);
    EXPECT_TRUE(UInt16::TryParse("14", 8, x));
    EXPECT_EQ(12u, x);
    EXPECT_TRUE(UInt16::TryParse("70", 8, x));
    EXPECT_EQ(56u, x);
    EXPECT_TRUE(UInt16::TryParse("1131", 8, x));
    EXPECT_EQ(601u, x);
  }
  
  TEST(UInt16, TryParse_Hexadecimal) {
    uint16 x;
    EXPECT_TRUE(UInt16::TryParse("0", 16, x));
    EXPECT_EQ(0u, x);
    EXPECT_TRUE(UInt16::TryParse("1", 16, x));
    EXPECT_EQ(1u, x);
    EXPECT_TRUE(UInt16::TryParse("C", 16, x));
    EXPECT_EQ(0xCu, x);
    EXPECT_TRUE(UInt16::TryParse("3c", 16, x));
    EXPECT_EQ(0x3Cu, x);
    EXPECT_TRUE(UInt16::TryParse("FE3", 16, x));
    EXPECT_EQ(0xFE3u, x);
    EXPECT_TRUE(UInt16::TryParse("FFFF", 16, x));
    EXPECT_EQ(0xFFFFu, x);
    EXPECT_FALSE(UInt16::TryParse("10000",  16, x));
  }
 
  TEST(UInt16, TryParse_UInt16) {
    UInt16 x;
    EXPECT_TRUE(UInt16::TryParse("0", x));
    EXPECT_EQ(0u, x);
    EXPECT_TRUE(UInt16::TryParse("1", x));
    EXPECT_EQ(1u, x);
    EXPECT_TRUE(UInt16::TryParse("123", x));
    EXPECT_EQ(123u, x);
    EXPECT_TRUE(UInt16::TryParse("12365", x));
    EXPECT_EQ(12365u, x);
    EXPECT_TRUE(UInt16::TryParse("65535", x));
    EXPECT_EQ(0xFFFFu, x);
  }
  
  TEST(UInt16, TryParse_Sign_UInt16) {
    UInt16 x;
    EXPECT_TRUE(UInt16::TryParse("+5", x));
    EXPECT_EQ(5u, x);
    EXPECT_TRUE(UInt16::TryParse("-0", x));
    EXPECT_EQ(0u, x);
    EXPECT_FALSE(UInt16::TryParse("-1", x));
  }
  
  TEST(UInt16, TryParse_Leading_Zeros_UInt16) {
    UInt16 x;
    EXPECT_TRUE(UInt16::TryParse("0", x));
    EXPECT_EQ(0u, x);
    EXPECT_TRUE(UInt16::TryParse("00", x));
    EXPECT_EQ(0u, x);
    EXPECT_TRUE(UInt16::TryParse("000", x));
    EXPECT_EQ(0u, x);
    EXPECT_TRUE(UInt16::TryParse("01", x));
    EXPECT_EQ(1u, x);
    EXPECT_TRUE(UInt16::TryParse("0001", x));
    EXPECT_EQ(1u, x);
    EXPECT_TRUE(UInt16::TryParse("099", x));
    EXPECT_EQ(99u, x);
    EXPECT_TRUE(UInt16::TryParse("0000999", x));
    EXPECT_EQ(999u, x);
  }
  
  TEST(UInt16, TryParse_Spaces_UInt16) {
    UInt16 x;
    EXPECT_TRUE(UInt16::TryParse(" 5", x));
    EXPECT_EQ(5u, x);
    EXPECT_TRUE(UInt16::TryParse("     5", x));
    EXPECT_EQ(5u, x);
    EXPECT_TRUE(UInt16::TryParse("5 ", x));
    EXPECT_EQ(5u, x);
    EXPECT_TRUE(UInt16::TryParse("51     ", x));
    EXPECT_EQ(51u, x);
    EXPECT_TRUE(UInt16::TryParse(" 5      ", x));
    EXPECT_EQ(5u, x);
    EXPECT_TRUE(UInt16::TryParse("        52 ", x));
    EXPECT_EQ(52u, x);
  }
  
  TEST(UInt16, TryParse_FormatException_UInt16) {
    UInt16 x;
    EXPECT_FALSE(UInt16::TryParse("", x));
    EXPECT_FALSE(UInt16::TryParse("a56", x));
    EXPECT_FALSE(UInt16::TryParse("0 0", x));
    EXPECT_FALSE(UInt16::TryParse("++000", x));
    EXPECT_FALSE(UInt16::TryParse("+", x));
    EXPECT_FALSE(UInt16::TryParse("-", x));
    EXPECT_FALSE(UInt16::TryParse("--5", x));
    EXPECT_FALSE(UInt16::TryParse("0x53", x));
    EXPECT_FALSE(UInt16::TryParse("100a", x));
    EXPECT_FALSE(UInt16::TryParse("10u", x));
  }
  
  TEST(UInt16, TryParse_OverflowException_UInt16) {
    UInt16 x;
    EXPECT_FALSE(UInt16::TryParse("-1", x));
    EXPECT_FALSE(UInt16::TryParse("-15602", x));
    EXPECT_TRUE(UInt16::TryParse("65535", x));
    EXPECT_EQ(0xFFFFu, x);
    EXPECT_TRUE(UInt16::TryParse("0065535", x));
    EXPECT_EQ(0xFFFFu, x);
    EXPECT_FALSE(UInt16::TryParse("65536", x));
    EXPECT_FALSE(UInt16::TryParse("4294967296", x));
    EXPECT_FALSE(UInt16::TryParse("5294967295", x));
  }
  
  TEST(UInt16, TryParse_Binary_UInt16) {
    UInt16 x;
    EXPECT_TRUE(UInt16::TryParse("0", 2, x));
    EXPECT_EQ(0u, x);
    EXPECT_TRUE(UInt16::TryParse("1", 2, x));
    EXPECT_EQ(1u, x);
    EXPECT_TRUE(UInt16::TryParse("10", 2, x));
    EXPECT_EQ(2u, x);
    EXPECT_TRUE(UInt16::TryParse("11", 2, x));
    EXPECT_EQ(3u, x);
    EXPECT_TRUE(UInt16::TryParse("110", 2, x));
    EXPECT_EQ(6u, x);
  }
  
  TEST(UInt16, TryParse_Exceptions_Binary_UInt16) {
    UInt16 x;
    EXPECT_FALSE(UInt16::TryParse("", 2, x));
    EXPECT_FALSE(UInt16::TryParse("2", 2, x));
    EXPECT_FALSE(UInt16::TryParse("103", 2, x));
    EXPECT_FALSE(UInt16::TryParse("++0", 2, x));
    EXPECT_FALSE(UInt16::TryParse("+", 2, x));
    EXPECT_FALSE(UInt16::TryParse("-", 2, x));
    EXPECT_FALSE(UInt16::TryParse("--1", 2, x));
    EXPECT_FALSE(UInt16::TryParse("0x53", 2, x));
    EXPECT_FALSE(UInt16::TryParse("100a", 2, x));
    EXPECT_FALSE(UInt16::TryParse("10u", 2, x));
  }
  
  TEST(UInt16, TryParse_Octal_UInt16) {
    UInt16 x;
    EXPECT_TRUE(UInt16::TryParse("0", 8, x));
    EXPECT_EQ(0u, x);
    EXPECT_TRUE(UInt16::TryParse("1", 8, x));
    EXPECT_EQ(1u, x);
    EXPECT_TRUE(UInt16::TryParse("14", 8, x));
    EXPECT_EQ(12u, x);
    EXPECT_TRUE(UInt16::TryParse("70", 8, x));
    EXPECT_EQ(56u, x);
    EXPECT_TRUE(UInt16::TryParse("1131", 8, x));
    EXPECT_EQ(601u, x);
  }
  
  TEST(UInt16, TryParse_Hexadecimal_UInt16) {
    UInt16 x;
    EXPECT_TRUE(UInt16::TryParse("0", 16, x));
    EXPECT_EQ(0u, x);
    EXPECT_TRUE(UInt16::TryParse("1", 16, x));
    EXPECT_EQ(1u, x);
    EXPECT_TRUE(UInt16::TryParse("C", 16, x));
    EXPECT_EQ(0xCu, x);
    EXPECT_TRUE(UInt16::TryParse("3c", 16, x));
    EXPECT_EQ(0x3Cu, x);
    EXPECT_TRUE(UInt16::TryParse("FE3", 16, x));
    EXPECT_EQ(0xFE3u, x);
    EXPECT_TRUE(UInt16::TryParse("FFFF", 16, x));
    EXPECT_EQ(0xFFFFu, x);
    EXPECT_FALSE(UInt16::TryParse("10000",  16, x));
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
 String type = _typeof(T).Name;
 String suffix = type == "Single" ? "f" : "";
 
 try {
 MethodInfo method = _typeof(T).GetMethod("Parse", new Type[] {_typeof(String)});
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
