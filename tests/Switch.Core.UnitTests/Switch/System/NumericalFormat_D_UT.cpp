#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Collections::Generic;

namespace {

  TEST(NumericalFormatTest, D99_SByte) {
    ASSERT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", String::Format("{0:D99}", SByte(0)));
    ASSERT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000013", String::Format("{0:D99}", SByte(13)));
    ASSERT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000127", String::Format("{0:D99}", SByte(127)));
    ASSERT_EQ("-000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001", String::Format("{0:D99}", SByte(-1)));
    ASSERT_EQ("-000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000056", String::Format("{0:D99}", SByte(-56)));
    ASSERT_EQ("-000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000128", String::Format("{0:D99}", SByte(-128)));
  }

  TEST(NumericalFormatTest, D99_UInt64) {
    ASSERT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", String::Format("{0:D99}", UInt64(0)));
    ASSERT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000654123", String::Format("{0:D99}", UInt64(654123)));
    ASSERT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000018446744073709551615",
      String::Format("{0:D99}", UInt64(18446744073709551615Lu)));
  }

  TEST(NumericalFormatTest, D_SByte) {
    ASSERT_EQ("0", String::Format("{0:D}", SByte(0)));
    ASSERT_EQ("5", String::Format("{0:D}", SByte(5)));
    ASSERT_EQ("127", String::Format("{0:D}", SByte(127)));
    ASSERT_EQ("-1", String::Format("{0:D}", SByte(-1)));
    ASSERT_EQ("-128", String::Format("{0:D}", SByte(-128)));
  }

  TEST(NumericalFormatTest, D1_SByte) {
    ASSERT_EQ("0", String::Format("{0:D1}", SByte(0)));
    ASSERT_EQ("5", String::Format("{0:D1}", SByte(5)));
    ASSERT_EQ("127", String::Format("{0:D1}", SByte(127)));
    ASSERT_EQ("-1", String::Format("{0:D1}", SByte(-1)));
    ASSERT_EQ("-128", String::Format("{0:D1}", SByte(-128)));
  }

  TEST(NumericalFormatTest, D2_SByte) {
    ASSERT_EQ("00", String::Format("{0:D2}", SByte(0)));
    ASSERT_EQ("05", String::Format("{0:D2}", SByte(5)));
    ASSERT_EQ("127", String::Format("{0:D2}", SByte(127)));
    ASSERT_EQ("-01", String::Format("{0:D2}", SByte(-1)));
    ASSERT_EQ("-128", String::Format("{0:D2}", SByte(-128)));
  }

  TEST(NumericalFormatTest, D3_SByte) {
    ASSERT_EQ("000", String::Format("{0:D3}", SByte(0)));
    ASSERT_EQ("005", String::Format("{0:D3}", SByte(5)));
    ASSERT_EQ("127", String::Format("{0:D3}", SByte(127)));
    ASSERT_EQ("-001", String::Format("{0:D3}", SByte(-1)));
    ASSERT_EQ("-128", String::Format("{0:D3}", SByte(-128)));
  }

  TEST(NumericalFormatTest, D4_SByte) {
    ASSERT_EQ("0000", String::Format("{0:D4}", SByte(0)));
    ASSERT_EQ("0005", String::Format("{0:D4}", SByte(5)));
    ASSERT_EQ("0127", String::Format("{0:D4}", SByte(127)));
    ASSERT_EQ("-0001", String::Format("{0:D4}", SByte(-1)));
    ASSERT_EQ("-0128", String::Format("{0:D4}", SByte(-128)));
  }

  TEST(NumericalFormatTest, D_Int16) {
    ASSERT_EQ("0", String::Format("{0:D}", Int16(0)));
    ASSERT_EQ("5", String::Format("{0:D}", Int16(5)));
    ASSERT_EQ("1279", String::Format("{0:D}", Int16(1279)));
    ASSERT_EQ("32767", String::Format("{0:D}", Int16(32767)));
    ASSERT_EQ("-1", String::Format("{0:D}", Int16(-1)));
    ASSERT_EQ("-32768", String::Format("{0:D}", Int16(-32768)));
  }

  TEST(NumericalFormatTest, D1_Int16) {
    ASSERT_EQ("0", String::Format("{0:D1}", Int16(0)));
    ASSERT_EQ("5", String::Format("{0:D1}", Int16(5)));
    ASSERT_EQ("1279", String::Format("{0:D1}", Int16(1279)));
    ASSERT_EQ("32767", String::Format("{0:D1}", Int16(32767)));
    ASSERT_EQ("-1", String::Format("{0:D1}", Int16(-1)));
    ASSERT_EQ("-32768", String::Format("{0:D1}", Int16(-32768)));
  }

  TEST(NumericalFormatTest, D3_Int16) {
    ASSERT_EQ("000", String::Format("{0:D3}", Int16(0)));
    ASSERT_EQ("005", String::Format("{0:D3}", Int16(5)));
    ASSERT_EQ("1279", String::Format("{0:D3}", Int16(1279)));
    ASSERT_EQ("32767", String::Format("{0:D3}", Int16(32767)));
    ASSERT_EQ("-001", String::Format("{0:D3}", Int16(-1)));
    ASSERT_EQ("-32768", String::Format("{0:D3}", Int16(-32768)));
  }

  TEST(NumericalFormatTest, D4_Int16) {
    ASSERT_EQ("0000", String::Format("{0:D4}", Int16(0)));
    ASSERT_EQ("0005", String::Format("{0:D4}", Int16(5)));
    ASSERT_EQ("1279", String::Format("{0:D4}", Int16(1279)));
    ASSERT_EQ("32767", String::Format("{0:D4}", Int16(32767)));
    ASSERT_EQ("-0001", String::Format("{0:D4}", Int16(-1)));
    ASSERT_EQ("-32768", String::Format("{0:D4}", Int16(-32768)));
  }

  TEST(NumericalFormatTest, D8_Int16) {
    ASSERT_EQ("00000000", String::Format("{0:D8}", Int16(0)));
    ASSERT_EQ("00000005", String::Format("{0:D8}", Int16(5)));
    ASSERT_EQ("00001279", String::Format("{0:D8}", Int16(1279)));
    ASSERT_EQ("00032767", String::Format("{0:D8}", Int16(32767)));
    ASSERT_EQ("-00000001", String::Format("{0:D8}", Int16(-1)));
    ASSERT_EQ("-00032768", String::Format("{0:D8}", Int16(-32768)));
  }

  TEST(NumericalFormatTest, D_Int32) {
    ASSERT_EQ("0", String::Format("{0:D}", Int32(0)));
    ASSERT_EQ("5", String::Format("{0:D}", Int32(5)));
    ASSERT_EQ("32767", String::Format("{0:D}", Int32(32767)));
    ASSERT_EQ("2147483647", String::Format("{0:D}", Int32(2147483647)));
    ASSERT_EQ("-1", String::Format("{0:D}", Int32(-1)));
    ASSERT_EQ("-66689", String::Format("{0:D}", Int32(-66689)));
    ASSERT_EQ("-2147483647", String::Format("{0:D}", Int32(-2147483647)));
  }

  TEST(NumericalFormatTest, D1_Int32) {
    ASSERT_EQ("0", String::Format("{0:D1}", Int32(0)));
    ASSERT_EQ("5", String::Format("{0:D1}", Int32(5)));
    ASSERT_EQ("32767", String::Format("{0:D1}", Int32(32767)));
    ASSERT_EQ("2147483647", String::Format("{0:D1}", Int32(2147483647)));
    ASSERT_EQ("-1", String::Format("{0:D1}", Int32(-1)));
    ASSERT_EQ("-66689", String::Format("{0:D1}", Int32(-66689)));
    ASSERT_EQ("-2147483647", String::Format("{0:D1}", Int32(-2147483647)));
  }

  TEST(NumericalFormatTest, D5_Int32) {
    ASSERT_EQ("00000", String::Format("{0:D5}", Int32(0)));
    ASSERT_EQ("00005", String::Format("{0:D5}", Int32(5)));
    ASSERT_EQ("32767", String::Format("{0:D5}", Int32(32767)));
    ASSERT_EQ("2147483647", String::Format("{0:D5}", Int32(2147483647)));
    ASSERT_EQ("-00001", String::Format("{0:D5}", Int32(-1)));
    ASSERT_EQ("-66689", String::Format("{0:D5}", Int32(-66689)));
    ASSERT_EQ("-2147483647", String::Format("{0:D5}", Int32(-2147483647)));
  }

  TEST(NumericalFormatTest, D12_Int32) {
    ASSERT_EQ("000000000000", String::Format("{0:D12}", Int32(0)));
    ASSERT_EQ("000000000005", String::Format("{0:D12}", Int32(5)));
    ASSERT_EQ("000000032767", String::Format("{0:D12}", Int32(32767)));
    ASSERT_EQ("002147483647", String::Format("{0:D12}", Int32(2147483647)));
    ASSERT_EQ("-000000000001", String::Format("{0:D12}", Int32(-1)));
    ASSERT_EQ("-000000066689", String::Format("{0:D12}", Int32(-66689)));
    ASSERT_EQ("-002147483647", String::Format("{0:D12}", Int32(-2147483647)));
  }

  TEST(NumericalFormatTest, D16_Int32) {
    ASSERT_EQ("0000000000000000", String::Format("{0:D16}", Int32(0)));
    ASSERT_EQ("0000000000000005", String::Format("{0:D16}", Int32(5)));
    ASSERT_EQ("0000000000032767", String::Format("{0:D16}", Int32(32767)));
    ASSERT_EQ("0000002147483647", String::Format("{0:D16}", Int32(2147483647)));
    ASSERT_EQ("-0000000000000001", String::Format("{0:D16}", Int32(-1)));
    ASSERT_EQ("-0000000000066689", String::Format("{0:D16}", Int32(-66689)));
    ASSERT_EQ("-0000002147483647", String::Format("{0:D16}", Int32(-2147483647)));
  }

  TEST(NumericalFormatTest, D_Int64) {
    ASSERT_EQ("0", String::Format("{0:D}", Int64(0)));
    ASSERT_EQ("5", String::Format("{0:D}", Int64(5)));
    ASSERT_EQ("32767", String::Format("{0:D}", Int64(32767)));
    ASSERT_EQ("21474836471458", String::Format("{0:D}", Int64(21474836471458)));
    ASSERT_EQ("-1", String::Format("{0:D}", Int64(-1)));
    ASSERT_EQ("-66689", String::Format("{0:D}", Int64(-66689)));
    ASSERT_EQ("-21474836471236", String::Format("{0:D}", Int64(-21474836471236)));
  }

  TEST(NumericalFormatTest, D1_Int64) {
    ASSERT_EQ("0", String::Format("{0:D1}", Int64(0)));
    ASSERT_EQ("5", String::Format("{0:D1}", Int64(5)));
    ASSERT_EQ("32767", String::Format("{0:D1}", Int64(32767)));
    ASSERT_EQ("21474836471458", String::Format("{0:D1}", Int64(21474836471458)));
    ASSERT_EQ("-1", String::Format("{0:D1}", Int64(-1)));
    ASSERT_EQ("-66689", String::Format("{0:D1}", Int64(-66689)));
    ASSERT_EQ("-21474836471236", String::Format("{0:D1}", Int64(-21474836471236)));
  }

  TEST(NumericalFormatTest, D5_Int64) {
    ASSERT_EQ("00000", String::Format("{0:D5}", Int64(0)));
    ASSERT_EQ("00005", String::Format("{0:D5}", Int64(5)));
    ASSERT_EQ("32767", String::Format("{0:D5}", Int64(32767)));
    ASSERT_EQ("21474836471458", String::Format("{0:D5}", Int64(21474836471458)));
    ASSERT_EQ("-00001", String::Format("{0:D5}", Int64(-1)));
    ASSERT_EQ("-66689", String::Format("{0:D5}", Int64(-66689)));
    ASSERT_EQ("-21474836471236", String::Format("{0:D5}", Int64(-21474836471236)));
  }

  TEST(NumericalFormatTest, D12_Int64) {
    ASSERT_EQ("000000000000", String::Format("{0:D12}", Int64(0)));
    ASSERT_EQ("000000000005", String::Format("{0:D12}", Int64(5)));
    ASSERT_EQ("000000032767", String::Format("{0:D12}", Int64(32767)));
    ASSERT_EQ("21474836471458", String::Format("{0:D12}", Int64(21474836471458)));
    ASSERT_EQ("-000000000001", String::Format("{0:D12}", Int64(-1)));
    ASSERT_EQ("-000000066689", String::Format("{0:D12}", Int64(-66689)));
    ASSERT_EQ("-21474836471236", String::Format("{0:D12}", Int64(-21474836471236)));
  }

  TEST(NumericalFormatTest, D16_Int64) {
    ASSERT_EQ("0000000000000000", String::Format("{0:D16}", Int64(0)));
    ASSERT_EQ("0000000000000005", String::Format("{0:D16}", Int64(5)));
    ASSERT_EQ("0000000000032767", String::Format("{0:D16}", Int64(32767)));
    ASSERT_EQ("0021474836471458", String::Format("{0:D16}", Int64(21474836471458)));
    ASSERT_EQ("-0000000000000001", String::Format("{0:D16}", Int64(-1)));
    ASSERT_EQ("-0000000000066689", String::Format("{0:D16}", Int64(-66689)));
    ASSERT_EQ("-0021474836471236", String::Format("{0:D16}", Int64(-21474836471236)));
  }

  TEST(NumericalFormatTest, D_Byte) {
    ASSERT_EQ("0", String::Format("{0:D}", Byte(0)));
    ASSERT_EQ("5", String::Format("{0:D}", Byte(5)));
    ASSERT_EQ("123", String::Format("{0:D}", Byte(123)));
    ASSERT_EQ("255", String::Format("{0:D}", Byte(255)));
  }

  TEST(NumericalFormatTest, D1_Byte) {
    ASSERT_EQ("0", String::Format("{0:D1}", Byte(0)));
    ASSERT_EQ("5", String::Format("{0:D1}", Byte(5)));
    ASSERT_EQ("123", String::Format("{0:D1}", Byte(123)));
    ASSERT_EQ("255", String::Format("{0:D1}", Byte(255)));
  }

  TEST(NumericalFormatTest, D2_Byte) {
    ASSERT_EQ("00", String::Format("{0:D2}", Byte(0)));
    ASSERT_EQ("05", String::Format("{0:D2}", Byte(5)));
    ASSERT_EQ("123", String::Format("{0:D2}", Byte(123)));
    ASSERT_EQ("255", String::Format("{0:D2}", Byte(255)));
  }

  TEST(NumericalFormatTest, D3_Byte) {
    ASSERT_EQ("000", String::Format("{0:D3}", Byte(0)));
    ASSERT_EQ("005", String::Format("{0:D3}", Byte(5)));
    ASSERT_EQ("123", String::Format("{0:D3}", Byte(123)));
    ASSERT_EQ("255", String::Format("{0:D3}", Byte(255)));
  }

  TEST(NumericalFormatTest, D4_Byte) {
    ASSERT_EQ("0000", String::Format("{0:D4}", Byte(0)));
    ASSERT_EQ("0005", String::Format("{0:D4}", Byte(5)));
    ASSERT_EQ("0123", String::Format("{0:D4}", Byte(123)));
    ASSERT_EQ("0255", String::Format("{0:D4}", Byte(255)));
  }

  TEST(NumericalFormatTest, D_UInt16) {
    ASSERT_EQ("0", String::Format("{0:D}", UInt16(0)));
    ASSERT_EQ("5", String::Format("{0:D}", UInt16(5)));
    ASSERT_EQ("2147", String::Format("{0:D}", UInt16(2147)));
    ASSERT_EQ("65535", String::Format("{0:D}", UInt16(65535)));
  }

  TEST(NumericalFormatTest, D1_UInt16) {
    ASSERT_EQ("0", String::Format("{0:D1}", UInt16(0)));
    ASSERT_EQ("5", String::Format("{0:D1}", UInt16(5)));
    ASSERT_EQ("2147", String::Format("{0:D1}", UInt16(2147)));
    ASSERT_EQ("65535", String::Format("{0:D1}", UInt16(65535)));
  }

  TEST(NumericalFormatTest, D4_UInt16) {
    ASSERT_EQ("0000", String::Format("{0:D4}", UInt16(0)));
    ASSERT_EQ("0005", String::Format("{0:D4}", UInt16(5)));
    ASSERT_EQ("2147", String::Format("{0:D4}", UInt16(2147)));
    ASSERT_EQ("65535", String::Format("{0:D4}", UInt16(65535)));
  }

  TEST(NumericalFormatTest, D8_UInt16) {
    ASSERT_EQ("00000000", String::Format("{0:D8}", UInt16(0)));
    ASSERT_EQ("00000005", String::Format("{0:D8}", UInt16(5)));
    ASSERT_EQ("00002147", String::Format("{0:D8}", UInt16(2147)));
    ASSERT_EQ("00065535", String::Format("{0:D8}", UInt16(65535)));
  }

  TEST(NumericalFormatTest, D_UInt32) {
    ASSERT_EQ("0", String::Format("{0:D}", UInt32(0)));
    ASSERT_EQ("5", String::Format("{0:D}", UInt32(5)));
    ASSERT_EQ("2147", String::Format("{0:D}", UInt32(2147)));
    ASSERT_EQ("32767", String::Format("{0:D}", UInt32(32767)));
    ASSERT_EQ("4294967295", String::Format("{0:D}", UInt32(4294967295u)));
  }

  TEST(NumericalFormatTest, D1_UInt32) {
    ASSERT_EQ("0", String::Format("{0:D1}", UInt32(0)));
    ASSERT_EQ("5", String::Format("{0:D1}", UInt32(5)));
    ASSERT_EQ("2147", String::Format("{0:D1}", UInt32(2147)));
    ASSERT_EQ("32767", String::Format("{0:D1}", UInt32(32767)));
    ASSERT_EQ("4294967295", String::Format("{0:D1}", UInt32(4294967295u)));
  }

  TEST(NumericalFormatTest, D4_UInt32) {
    ASSERT_EQ("0000", String::Format("{0:D4}", UInt32(0)));
    ASSERT_EQ("0005", String::Format("{0:D4}", UInt32(5)));
    ASSERT_EQ("2147", String::Format("{0:D4}", UInt32(2147)));
    ASSERT_EQ("32767", String::Format("{0:D4}", UInt32(32767)));
    ASSERT_EQ("4294967295", String::Format("{0:D4}", UInt32(4294967295u)));
  }

  TEST(NumericalFormatTest, D8_UInt32) {
    ASSERT_EQ("00000000", String::Format("{0:D8}", UInt32(0)));
    ASSERT_EQ("00000005", String::Format("{0:D8}", UInt32(5)));
    ASSERT_EQ("00002147", String::Format("{0:D8}", UInt32(2147)));
    ASSERT_EQ("00032767", String::Format("{0:D8}", UInt32(32767)));
    ASSERT_EQ("4294967295", String::Format("{0:D8}", UInt32(4294967295u)));
  }

  TEST(NumericalFormatTest, D11_UInt32) {
    ASSERT_EQ("00000000000", String::Format("{0:D11}", UInt32(0)));
    ASSERT_EQ("00000000005", String::Format("{0:D11}", UInt32(5)));
    ASSERT_EQ("00000002147", String::Format("{0:D11}", UInt32(2147)));
    ASSERT_EQ("00000032767", String::Format("{0:D11}", UInt32(32767)));
    ASSERT_EQ("04294967295", String::Format("{0:D11}", UInt32(4294967295u)));
  }

  TEST(NumericalFormatTest, D_UInt64) {
    ASSERT_EQ("0", String::Format("{0:D}", UInt64(0)));
    ASSERT_EQ("5", String::Format("{0:D}", UInt64(5)));
    ASSERT_EQ("32767", String::Format("{0:D}", UInt64(32767)));
    ASSERT_EQ("2147483647", String::Format("{0:D}", UInt64(2147483647)));
    ASSERT_EQ("2147483647654", String::Format("{0:D}", UInt64(2147483647654)));
  }

  TEST(NumericalFormatTest, D1_UInt64) {
    ASSERT_EQ("0", String::Format("{0:D1}", UInt64(0)));
    ASSERT_EQ("5", String::Format("{0:D1}", UInt64(5)));
    ASSERT_EQ("32767", String::Format("{0:D1}", UInt64(32767)));
    ASSERT_EQ("2147483647", String::Format("{0:D1}", UInt64(2147483647)));
    ASSERT_EQ("2147483647654", String::Format("{0:D1}", UInt64(2147483647654)));
  }

  TEST(NumericalFormatTest, D5_UInt64) {
    ASSERT_EQ("00000", String::Format("{0:D5}", UInt64(0)));
    ASSERT_EQ("00005", String::Format("{0:D5}", UInt64(5)));
    ASSERT_EQ("32767", String::Format("{0:D5}", UInt64(32767)));
    ASSERT_EQ("2147483647654", String::Format("{0:D5}", UInt64(2147483647654)));
  }

  TEST(NumericalFormatTest, D12_UInt64) {
    ASSERT_EQ("000000000000", String::Format("{0:D12}", UInt64(0)));
    ASSERT_EQ("000000000005", String::Format("{0:D12}", UInt64(5)));
    ASSERT_EQ("000000032767", String::Format("{0:D12}", UInt64(32767)));
    ASSERT_EQ("2147483647654", String::Format("{0:D12}", UInt64(2147483647654)));
  }

  TEST(NumericalFormatTest, D16_UInt64) {
    ASSERT_EQ("0000000000000000", String::Format("{0:D16}", UInt64(0)));
    ASSERT_EQ("0000000000000005", String::Format("{0:D16}", UInt64(5)));
    ASSERT_EQ("0000000000032767", String::Format("{0:D16}", UInt64(32767)));
    ASSERT_EQ("0002147483647654", String::Format("{0:D16}", UInt64(2147483647654)));
  }

  TEST(NumericalFormatTest, D_Double) {
    ASSERT_THROW(String::Format("{0:d}", Double(105.132)), FormatException);
    ASSERT_THROW(String::Format("{0:D}", Double(0.0)), FormatException);
    ASSERT_THROW(String::Format("{0:D5}", Double(10.0)), FormatException);
    ASSERT_THROW(String::Format("{0:D8}", Double(10000.132)), FormatException);
    ASSERT_THROW(String::Format("{0:d8}", Double(10000.132)), FormatException);
  }

  TEST(NumericalFormatTest, D_Single) {
    ASSERT_THROW(String::Format("{0:d}", Single(105.132f)), FormatException);
    ASSERT_THROW(String::Format("{0:D}", Single(0.0f)), FormatException);
    ASSERT_THROW(String::Format("{0:D5}", Single(10.0f)), FormatException);
    ASSERT_THROW(String::Format("{0:D8}", Single(1540.132f)), FormatException);
    ASSERT_THROW(String::Format("{0:d8}", Single(100.2540f)), FormatException);
  }

}

/*
C# program to generate those tests (replace *type*] by a typename) :

class Program {
  public static void Main() {
    *type*[] t = { 0, 5, 2147, 65535 };
    String[] f = { "D", "D1", "D4", "D8" };
    Generate<*type*>(f,t);
  }

  static void Generate<T>(String[] f, T[] t) {
    for (String fmt : f) {
      for (T i : t) {
        MAKE<T>(fmt, (IFormattable)i);
      }
      Console.WriteLine();
    }

    int a = 74;
  }

  static void MAKE<T>(String format, IFormattable value) {
    String[] split = value.GetType().ToString().Split('.');
    String type = split[split.Length-1];

    Console.WriteLine("  ASSERT_EQ(\"{0}\", String::Format(\"{{0:{1}}}\", {3}({2}))); ", value.ToString(format,null), format, value, type);
  }
}
*/
