#include <Pcf/System/String.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace TUnit;

namespace {

TEST(NumericalFormat, D99_SByte) {
  EXPECT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", String::Format("{0:D99}", SByte(0)));
  EXPECT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000013", String::Format("{0:D99}", SByte(13)));
  EXPECT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000127", String::Format("{0:D99}", SByte(127)));
  EXPECT_EQ("-000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001", String::Format("{0:D99}", SByte(-1)));
  EXPECT_EQ("-000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000056", String::Format("{0:D99}", SByte(-56)));
  EXPECT_EQ("-000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000128", String::Format("{0:D99}", SByte(-128)));
}

TEST(NumericalFormat, D99_UInt64) {
  EXPECT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", String::Format("{0:D99}", UInt64(0)));
  EXPECT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000654123", String::Format("{0:D99}", UInt64(654123)));
  EXPECT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000018446744073709551615", 
    String::Format("{0:D99}", UInt64(18446744073709551615Lu)));
}

TEST(NumericalFormat, D_SByte) {
  EXPECT_EQ("0", String::Format("{0:D}", SByte(0)));
  EXPECT_EQ("5", String::Format("{0:D}", SByte(5)));
  EXPECT_EQ("127", String::Format("{0:D}", SByte(127)));
  EXPECT_EQ("-1", String::Format("{0:D}", SByte(-1)));
  EXPECT_EQ("-128", String::Format("{0:D}", SByte(-128)));
}

TEST(NumericalFormat, D1_SByte) {
  EXPECT_EQ("0", String::Format("{0:D1}", SByte(0)));
  EXPECT_EQ("5", String::Format("{0:D1}", SByte(5)));
  EXPECT_EQ("127", String::Format("{0:D1}", SByte(127)));
  EXPECT_EQ("-1", String::Format("{0:D1}", SByte(-1)));
  EXPECT_EQ("-128", String::Format("{0:D1}", SByte(-128)));
}

TEST(NumericalFormat, D2_SByte) {
  EXPECT_EQ("00", String::Format("{0:D2}", SByte(0)));
  EXPECT_EQ("05", String::Format("{0:D2}", SByte(5)));
  EXPECT_EQ("127", String::Format("{0:D2}", SByte(127)));
  EXPECT_EQ("-01", String::Format("{0:D2}", SByte(-1)));
  EXPECT_EQ("-128", String::Format("{0:D2}", SByte(-128)));
}

TEST(NumericalFormat, D3_SByte) {
  EXPECT_EQ("000", String::Format("{0:D3}", SByte(0)));
  EXPECT_EQ("005", String::Format("{0:D3}", SByte(5)));
  EXPECT_EQ("127", String::Format("{0:D3}", SByte(127)));
  EXPECT_EQ("-001", String::Format("{0:D3}", SByte(-1)));
  EXPECT_EQ("-128", String::Format("{0:D3}", SByte(-128)));
}

TEST(NumericalFormat, D4_SByte) {
  EXPECT_EQ("0000", String::Format("{0:D4}", SByte(0)));
  EXPECT_EQ("0005", String::Format("{0:D4}", SByte(5)));
  EXPECT_EQ("0127", String::Format("{0:D4}", SByte(127)));
  EXPECT_EQ("-0001", String::Format("{0:D4}", SByte(-1)));
  EXPECT_EQ("-0128", String::Format("{0:D4}", SByte(-128)));
}

TEST(NumericalFormat, D_Int16) {
  EXPECT_EQ("0", String::Format("{0:D}", Int16(0)));
  EXPECT_EQ("5", String::Format("{0:D}", Int16(5)));
  EXPECT_EQ("1279", String::Format("{0:D}", Int16(1279)));
  EXPECT_EQ("32767", String::Format("{0:D}", Int16(32767)));
  EXPECT_EQ("-1", String::Format("{0:D}", Int16(-1)));
  EXPECT_EQ("-32768", String::Format("{0:D}", Int16(-32768)));
}

TEST(NumericalFormat, D1_Int16) {
  EXPECT_EQ("0", String::Format("{0:D1}", Int16(0)));
  EXPECT_EQ("5", String::Format("{0:D1}", Int16(5)));
  EXPECT_EQ("1279", String::Format("{0:D1}", Int16(1279)));
  EXPECT_EQ("32767", String::Format("{0:D1}", Int16(32767)));
  EXPECT_EQ("-1", String::Format("{0:D1}", Int16(-1)));
  EXPECT_EQ("-32768", String::Format("{0:D1}", Int16(-32768)));
}

TEST(NumericalFormat, D3_Int16) {
  EXPECT_EQ("000", String::Format("{0:D3}", Int16(0)));
  EXPECT_EQ("005", String::Format("{0:D3}", Int16(5)));
  EXPECT_EQ("1279", String::Format("{0:D3}", Int16(1279)));
  EXPECT_EQ("32767", String::Format("{0:D3}", Int16(32767)));
  EXPECT_EQ("-001", String::Format("{0:D3}", Int16(-1)));
  EXPECT_EQ("-32768", String::Format("{0:D3}", Int16(-32768)));
}

TEST(NumericalFormat, D4_Int16) {
  EXPECT_EQ("0000", String::Format("{0:D4}", Int16(0)));
  EXPECT_EQ("0005", String::Format("{0:D4}", Int16(5)));
  EXPECT_EQ("1279", String::Format("{0:D4}", Int16(1279)));
  EXPECT_EQ("32767", String::Format("{0:D4}", Int16(32767)));
  EXPECT_EQ("-0001", String::Format("{0:D4}", Int16(-1)));
  EXPECT_EQ("-32768", String::Format("{0:D4}", Int16(-32768)));
}

TEST(NumericalFormat, D8_Int16) {
  EXPECT_EQ("00000000", String::Format("{0:D8}", Int16(0)));
  EXPECT_EQ("00000005", String::Format("{0:D8}", Int16(5)));
  EXPECT_EQ("00001279", String::Format("{0:D8}", Int16(1279)));
  EXPECT_EQ("00032767", String::Format("{0:D8}", Int16(32767)));
  EXPECT_EQ("-00000001", String::Format("{0:D8}", Int16(-1)));
  EXPECT_EQ("-00032768", String::Format("{0:D8}", Int16(-32768)));
}

TEST(NumericalFormat, D_Int32) {
  EXPECT_EQ("0", String::Format("{0:D}", Int32(0)));
  EXPECT_EQ("5", String::Format("{0:D}", Int32(5)));
  EXPECT_EQ("32767", String::Format("{0:D}", Int32(32767)));
  EXPECT_EQ("2147483647", String::Format("{0:D}", Int32(2147483647)));
  EXPECT_EQ("-1", String::Format("{0:D}", Int32(-1)));
  EXPECT_EQ("-66689", String::Format("{0:D}", Int32(-66689)));
  EXPECT_EQ("-2147483647", String::Format("{0:D}", Int32(-2147483647)));
}

TEST(NumericalFormat, D1_Int32) {
  EXPECT_EQ("0", String::Format("{0:D1}", Int32(0)));
  EXPECT_EQ("5", String::Format("{0:D1}", Int32(5)));
  EXPECT_EQ("32767", String::Format("{0:D1}", Int32(32767)));
  EXPECT_EQ("2147483647", String::Format("{0:D1}", Int32(2147483647)));
  EXPECT_EQ("-1", String::Format("{0:D1}", Int32(-1)));
  EXPECT_EQ("-66689", String::Format("{0:D1}", Int32(-66689)));
  EXPECT_EQ("-2147483647", String::Format("{0:D1}", Int32(-2147483647)));
}

TEST(NumericalFormat, D5_Int32) {
  EXPECT_EQ("00000", String::Format("{0:D5}", Int32(0)));
  EXPECT_EQ("00005", String::Format("{0:D5}", Int32(5)));
  EXPECT_EQ("32767", String::Format("{0:D5}", Int32(32767)));
  EXPECT_EQ("2147483647", String::Format("{0:D5}", Int32(2147483647)));
  EXPECT_EQ("-00001", String::Format("{0:D5}", Int32(-1)));
  EXPECT_EQ("-66689", String::Format("{0:D5}", Int32(-66689)));
  EXPECT_EQ("-2147483647", String::Format("{0:D5}", Int32(-2147483647)));
}

TEST(NumericalFormat, D12_Int32) {
  EXPECT_EQ("000000000000", String::Format("{0:D12}", Int32(0)));
  EXPECT_EQ("000000000005", String::Format("{0:D12}", Int32(5)));
  EXPECT_EQ("000000032767", String::Format("{0:D12}", Int32(32767)));
  EXPECT_EQ("002147483647", String::Format("{0:D12}", Int32(2147483647)));
  EXPECT_EQ("-000000000001", String::Format("{0:D12}", Int32(-1)));
  EXPECT_EQ("-000000066689", String::Format("{0:D12}", Int32(-66689)));
  EXPECT_EQ("-002147483647", String::Format("{0:D12}", Int32(-2147483647)));
}

TEST(NumericalFormat, D16_Int32) {
  EXPECT_EQ("0000000000000000", String::Format("{0:D16}", Int32(0)));
  EXPECT_EQ("0000000000000005", String::Format("{0:D16}", Int32(5)));
  EXPECT_EQ("0000000000032767", String::Format("{0:D16}", Int32(32767)));
  EXPECT_EQ("0000002147483647", String::Format("{0:D16}", Int32(2147483647)));
  EXPECT_EQ("-0000000000000001", String::Format("{0:D16}", Int32(-1)));
  EXPECT_EQ("-0000000000066689", String::Format("{0:D16}", Int32(-66689)));
  EXPECT_EQ("-0000002147483647", String::Format("{0:D16}", Int32(-2147483647)));
}

TEST(NumericalFormat, D_Int64) {
  EXPECT_EQ("0", String::Format("{0:D}", Int64(0)));
  EXPECT_EQ("5", String::Format("{0:D}", Int64(5)));
  EXPECT_EQ("32767", String::Format("{0:D}", Int64(32767)));
  EXPECT_EQ("21474836471458", String::Format("{0:D}", Int64(21474836471458)));
  EXPECT_EQ("-1", String::Format("{0:D}", Int64(-1)));
  EXPECT_EQ("-66689", String::Format("{0:D}", Int64(-66689)));
  EXPECT_EQ("-21474836471236", String::Format("{0:D}", Int64(-21474836471236)));
}

TEST(NumericalFormat, D1_Int64) {
  EXPECT_EQ("0", String::Format("{0:D1}", Int64(0)));
  EXPECT_EQ("5", String::Format("{0:D1}", Int64(5)));
  EXPECT_EQ("32767", String::Format("{0:D1}", Int64(32767)));
  EXPECT_EQ("21474836471458", String::Format("{0:D1}", Int64(21474836471458)));
  EXPECT_EQ("-1", String::Format("{0:D1}", Int64(-1)));
  EXPECT_EQ("-66689", String::Format("{0:D1}", Int64(-66689)));
  EXPECT_EQ("-21474836471236", String::Format("{0:D1}", Int64(-21474836471236)));
}

TEST(NumericalFormat, D5_Int64) {
  EXPECT_EQ("00000", String::Format("{0:D5}", Int64(0)));
  EXPECT_EQ("00005", String::Format("{0:D5}", Int64(5)));
  EXPECT_EQ("32767", String::Format("{0:D5}", Int64(32767)));
  EXPECT_EQ("21474836471458", String::Format("{0:D5}", Int64(21474836471458)));
  EXPECT_EQ("-00001", String::Format("{0:D5}", Int64(-1)));
  EXPECT_EQ("-66689", String::Format("{0:D5}", Int64(-66689)));
  EXPECT_EQ("-21474836471236", String::Format("{0:D5}", Int64(-21474836471236)));
}

TEST(NumericalFormat, D12_Int64) {
  EXPECT_EQ("000000000000", String::Format("{0:D12}", Int64(0)));
  EXPECT_EQ("000000000005", String::Format("{0:D12}", Int64(5)));
  EXPECT_EQ("000000032767", String::Format("{0:D12}", Int64(32767)));
  EXPECT_EQ("21474836471458", String::Format("{0:D12}", Int64(21474836471458)));
  EXPECT_EQ("-000000000001", String::Format("{0:D12}", Int64(-1)));
  EXPECT_EQ("-000000066689", String::Format("{0:D12}", Int64(-66689)));
  EXPECT_EQ("-21474836471236", String::Format("{0:D12}", Int64(-21474836471236)));
}

TEST(NumericalFormat, D16_Int64) {
  EXPECT_EQ("0000000000000000", String::Format("{0:D16}", Int64(0)));
  EXPECT_EQ("0000000000000005", String::Format("{0:D16}", Int64(5)));
  EXPECT_EQ("0000000000032767", String::Format("{0:D16}", Int64(32767)));
  EXPECT_EQ("0021474836471458", String::Format("{0:D16}", Int64(21474836471458)));
  EXPECT_EQ("-0000000000000001", String::Format("{0:D16}", Int64(-1)));
  EXPECT_EQ("-0000000000066689", String::Format("{0:D16}", Int64(-66689)));
  EXPECT_EQ("-0021474836471236", String::Format("{0:D16}", Int64(-21474836471236)));
}

TEST(NumericalFormat, D_Byte) {
  EXPECT_EQ("0", String::Format("{0:D}", Byte(0)));
  EXPECT_EQ("5", String::Format("{0:D}", Byte(5)));
  EXPECT_EQ("123", String::Format("{0:D}", Byte(123)));
  EXPECT_EQ("255", String::Format("{0:D}", Byte(255)));
}

TEST(NumericalFormat, D1_Byte) {
  EXPECT_EQ("0", String::Format("{0:D1}", Byte(0)));
  EXPECT_EQ("5", String::Format("{0:D1}", Byte(5)));
  EXPECT_EQ("123", String::Format("{0:D1}", Byte(123)));
  EXPECT_EQ("255", String::Format("{0:D1}", Byte(255)));
}

TEST(NumericalFormat, D2_Byte) {
  EXPECT_EQ("00", String::Format("{0:D2}", Byte(0)));
  EXPECT_EQ("05", String::Format("{0:D2}", Byte(5)));
  EXPECT_EQ("123", String::Format("{0:D2}", Byte(123)));
  EXPECT_EQ("255", String::Format("{0:D2}", Byte(255)));
}

TEST(NumericalFormat, D3_Byte) {
  EXPECT_EQ("000", String::Format("{0:D3}", Byte(0)));
  EXPECT_EQ("005", String::Format("{0:D3}", Byte(5)));
  EXPECT_EQ("123", String::Format("{0:D3}", Byte(123)));
  EXPECT_EQ("255", String::Format("{0:D3}", Byte(255)));
}

TEST(NumericalFormat, D4_Byte) {
  EXPECT_EQ("0000", String::Format("{0:D4}", Byte(0)));
  EXPECT_EQ("0005", String::Format("{0:D4}", Byte(5)));
  EXPECT_EQ("0123", String::Format("{0:D4}", Byte(123)));
  EXPECT_EQ("0255", String::Format("{0:D4}", Byte(255)));
}

TEST(NumericalFormat, D_UInt16) {
  EXPECT_EQ("0", String::Format("{0:D}", UInt16(0)));
  EXPECT_EQ("5", String::Format("{0:D}", UInt16(5)));
  EXPECT_EQ("2147", String::Format("{0:D}", UInt16(2147)));
  EXPECT_EQ("65535", String::Format("{0:D}", UInt16(65535)));
}

TEST(NumericalFormat, D1_UInt16) {
  EXPECT_EQ("0", String::Format("{0:D1}", UInt16(0)));
  EXPECT_EQ("5", String::Format("{0:D1}", UInt16(5)));
  EXPECT_EQ("2147", String::Format("{0:D1}", UInt16(2147)));
  EXPECT_EQ("65535", String::Format("{0:D1}", UInt16(65535)));
}

TEST(NumericalFormat, D4_UInt16) {
  EXPECT_EQ("0000", String::Format("{0:D4}", UInt16(0)));
  EXPECT_EQ("0005", String::Format("{0:D4}", UInt16(5)));
  EXPECT_EQ("2147", String::Format("{0:D4}", UInt16(2147)));
  EXPECT_EQ("65535", String::Format("{0:D4}", UInt16(65535)));
}

TEST(NumericalFormat, D8_UInt16) {
  EXPECT_EQ("00000000", String::Format("{0:D8}", UInt16(0)));
  EXPECT_EQ("00000005", String::Format("{0:D8}", UInt16(5)));
  EXPECT_EQ("00002147", String::Format("{0:D8}", UInt16(2147)));
  EXPECT_EQ("00065535", String::Format("{0:D8}", UInt16(65535)));
}

TEST(NumericalFormat, D_UInt32) {
  EXPECT_EQ("0", String::Format("{0:D}", UInt32(0)));
  EXPECT_EQ("5", String::Format("{0:D}", UInt32(5)));
  EXPECT_EQ("2147", String::Format("{0:D}", UInt32(2147)));
  EXPECT_EQ("32767", String::Format("{0:D}", UInt32(32767)));
  EXPECT_EQ("4294967295", String::Format("{0:D}", UInt32(4294967295u)));
}

TEST(NumericalFormat, D1_UInt32) {
  EXPECT_EQ("0", String::Format("{0:D1}", UInt32(0)));
  EXPECT_EQ("5", String::Format("{0:D1}", UInt32(5)));
  EXPECT_EQ("2147", String::Format("{0:D1}", UInt32(2147)));
  EXPECT_EQ("32767", String::Format("{0:D1}", UInt32(32767)));
  EXPECT_EQ("4294967295", String::Format("{0:D1}", UInt32(4294967295u)));
}

TEST(NumericalFormat, D4_UInt32) {
  EXPECT_EQ("0000", String::Format("{0:D4}", UInt32(0)));
  EXPECT_EQ("0005", String::Format("{0:D4}", UInt32(5)));
  EXPECT_EQ("2147", String::Format("{0:D4}", UInt32(2147)));
  EXPECT_EQ("32767", String::Format("{0:D4}", UInt32(32767)));
  EXPECT_EQ("4294967295", String::Format("{0:D4}", UInt32(4294967295u)));
}

TEST(NumericalFormat, D8_UInt32) {
  EXPECT_EQ("00000000", String::Format("{0:D8}", UInt32(0)));
  EXPECT_EQ("00000005", String::Format("{0:D8}", UInt32(5)));
  EXPECT_EQ("00002147", String::Format("{0:D8}", UInt32(2147)));
  EXPECT_EQ("00032767", String::Format("{0:D8}", UInt32(32767)));
  EXPECT_EQ("4294967295", String::Format("{0:D8}", UInt32(4294967295u)));
}

TEST(NumericalFormat, D11_UInt32) {
  EXPECT_EQ("00000000000", String::Format("{0:D11}", UInt32(0)));
  EXPECT_EQ("00000000005", String::Format("{0:D11}", UInt32(5)));
  EXPECT_EQ("00000002147", String::Format("{0:D11}", UInt32(2147)));
  EXPECT_EQ("00000032767", String::Format("{0:D11}", UInt32(32767)));
  EXPECT_EQ("04294967295", String::Format("{0:D11}", UInt32(4294967295u)));
}

TEST(NumericalFormat, D_UInt64) {
  EXPECT_EQ("0", String::Format("{0:D}", UInt64(0)));
  EXPECT_EQ("5", String::Format("{0:D}", UInt64(5)));
  EXPECT_EQ("32767", String::Format("{0:D}", UInt64(32767)));
  EXPECT_EQ("2147483647", String::Format("{0:D}", UInt64(2147483647)));
  EXPECT_EQ("2147483647654", String::Format("{0:D}", UInt64(2147483647654)));
}

TEST(NumericalFormat, D1_UInt64) {
  EXPECT_EQ("0", String::Format("{0:D1}", UInt64(0)));
  EXPECT_EQ("5", String::Format("{0:D1}", UInt64(5)));
  EXPECT_EQ("32767", String::Format("{0:D1}", UInt64(32767)));
  EXPECT_EQ("2147483647", String::Format("{0:D1}", UInt64(2147483647)));
  EXPECT_EQ("2147483647654", String::Format("{0:D1}", UInt64(2147483647654)));
}

TEST(NumericalFormat, D5_UInt64) {
  EXPECT_EQ("00000", String::Format("{0:D5}", UInt64(0)));
  EXPECT_EQ("00005", String::Format("{0:D5}", UInt64(5)));
  EXPECT_EQ("32767", String::Format("{0:D5}", UInt64(32767)));
  EXPECT_EQ("2147483647654", String::Format("{0:D5}", UInt64(2147483647654)));
}

TEST(NumericalFormat, D12_UInt64) {
  EXPECT_EQ("000000000000", String::Format("{0:D12}", UInt64(0)));
  EXPECT_EQ("000000000005", String::Format("{0:D12}", UInt64(5)));
  EXPECT_EQ("000000032767", String::Format("{0:D12}", UInt64(32767)));
  EXPECT_EQ("2147483647654", String::Format("{0:D12}", UInt64(2147483647654)));
}

TEST(NumericalFormat, D16_UInt64) {
  EXPECT_EQ("0000000000000000", String::Format("{0:D16}", UInt64(0)));
  EXPECT_EQ("0000000000000005", String::Format("{0:D16}", UInt64(5)));
  EXPECT_EQ("0000000000032767", String::Format("{0:D16}", UInt64(32767)));
  EXPECT_EQ("0002147483647654", String::Format("{0:D16}", UInt64(2147483647654)));
}

TEST(NumericalFormat, D_Double) {
  EXPECT_THROW(String::Format("{0:d}", Double(105.132)), FormatException);
  EXPECT_THROW(String::Format("{0:D}", Double(0.0)), FormatException);
  EXPECT_THROW(String::Format("{0:D5}", Double(10.0)), FormatException);
  EXPECT_THROW(String::Format("{0:D8}", Double(10000.132)), FormatException);
  EXPECT_THROW(String::Format("{0:d8}", Double(10000.132)), FormatException);
}

TEST(NumericalFormat, D_Single) {
  EXPECT_THROW(String::Format("{0:d}", Single(105.132f)), FormatException);
  EXPECT_THROW(String::Format("{0:D}", Single(0.0f)), FormatException);
  EXPECT_THROW(String::Format("{0:D5}", Single(10.0f)), FormatException);
  EXPECT_THROW(String::Format("{0:D8}", Single(1540.132f)), FormatException);
  EXPECT_THROW(String::Format("{0:d8}", Single(100.2540f)), FormatException);  
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
      
    Console.WriteLine("  EXPECT_EQ(\"{0}\", String::Format(\"{{0:{1}}}\", {3}({2}))); ", value.ToString(format,null), format, value, type);
  }
}
*/