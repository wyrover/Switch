#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Collections::Generic;

namespace {

  TEST(NumericalFormatTest, F0_SByte) {
    ASSERT_EQ("0", String::Format("{0:F0}", SByte(0)));
    ASSERT_EQ("65", String::Format("{0:F0}", SByte(65)));
    ASSERT_EQ("127", String::Format("{0:F0}", SByte(127)));
    ASSERT_EQ("-1", String::Format("{0:F0}", SByte(-1)));
    ASSERT_EQ("127", String::Format("{0:F0}", SByte(127)));
  }
  
  TEST(NumericalFormatTest, F_SByte) {
    ASSERT_EQ("0.00", String::Format("{0:F}", SByte(0)));
    ASSERT_EQ("13.00", String::Format("{0:F}", SByte(13)));
    ASSERT_EQ("127.00", String::Format("{0:F}", SByte(127)));
    ASSERT_EQ("-1.00", String::Format("{0:F}", SByte(-1)));
    ASSERT_EQ("-56.00", String::Format("{0:F}", SByte(-56)));
    ASSERT_EQ("-128.00", String::Format("{0:F}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, F1_SByte) {
    ASSERT_EQ("0.0", String::Format("{0:F1}", SByte(0)));
    ASSERT_EQ("13.0", String::Format("{0:F1}", SByte(13)));
    ASSERT_EQ("127.0", String::Format("{0:F1}", SByte(127)));
    ASSERT_EQ("-1.0", String::Format("{0:F1}", SByte(-1)));
    ASSERT_EQ("-56.0", String::Format("{0:F1}", SByte(-56)));
    ASSERT_EQ("-128.0", String::Format("{0:F1}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, F3_SByte) {
    ASSERT_EQ("0.000", String::Format("{0:F3}", SByte(0)));
    ASSERT_EQ("13.000", String::Format("{0:F3}", SByte(13)));
    ASSERT_EQ("127.000", String::Format("{0:F3}", SByte(127)));
    ASSERT_EQ("-1.000", String::Format("{0:F3}", SByte(-1)));
    ASSERT_EQ("-56.000", String::Format("{0:F3}", SByte(-56)));
    ASSERT_EQ("-128.000", String::Format("{0:F3}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, F5_SByte) {
    ASSERT_EQ("0.00000", String::Format("{0:F5}", SByte(0)));
    ASSERT_EQ("13.00000", String::Format("{0:F5}", SByte(13)));
    ASSERT_EQ("127.00000", String::Format("{0:F5}", SByte(127)));
    ASSERT_EQ("-1.00000", String::Format("{0:F5}", SByte(-1)));
    ASSERT_EQ("-56.00000", String::Format("{0:F5}", SByte(-56)));
    ASSERT_EQ("-128.00000", String::Format("{0:F5}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, F10_SByte) {
    ASSERT_EQ("0.0000000000", String::Format("{0:F10}", SByte(0)));
    ASSERT_EQ("13.0000000000", String::Format("{0:F10}", SByte(13)));
    ASSERT_EQ("127.0000000000", String::Format("{0:F10}", SByte(127)));
    ASSERT_EQ("-1.0000000000", String::Format("{0:F10}", SByte(-1)));
    ASSERT_EQ("-56.0000000000", String::Format("{0:F10}", SByte(-56)));
    ASSERT_EQ("-128.0000000000", String::Format("{0:F10}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, F_Int16) {
    ASSERT_EQ("0.00", String::Format("{0:F}", Int16(0)));
    ASSERT_EQ("221.00", String::Format("{0:F}", Int16(221)));
    ASSERT_EQ("22106.00", String::Format("{0:F}", Int16(22106)));
    ASSERT_EQ("32767.00", String::Format("{0:F}", Int16(32767)));
    ASSERT_EQ("-1.00", String::Format("{0:F}", Int16(-1)));
    ASSERT_EQ("-32768.00", String::Format("{0:F}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, F0_Int16) {
    ASSERT_EQ("0", String::Format("{0:F0}", Int16(0)));
    ASSERT_EQ("221", String::Format("{0:F0}", Int16(221)));
    ASSERT_EQ("22106", String::Format("{0:F0}", Int16(22106)));
    ASSERT_EQ("32767", String::Format("{0:F0}", Int16(32767)));
    ASSERT_EQ("-1", String::Format("{0:F0}", Int16(-1)));
    ASSERT_EQ("-32768", String::Format("{0:F0}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, F1_Int16) {
    ASSERT_EQ("0.0", String::Format("{0:F1}", Int16(0)));
    ASSERT_EQ("221.0", String::Format("{0:F1}", Int16(221)));
    ASSERT_EQ("22106.0", String::Format("{0:F1}", Int16(22106)));
    ASSERT_EQ("32767.0", String::Format("{0:F1}", Int16(32767)));
    ASSERT_EQ("-1.0", String::Format("{0:F1}", Int16(-1)));
    ASSERT_EQ("-32768.0", String::Format("{0:F1}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, F2_Int16) {
    ASSERT_EQ("0.00", String::Format("{0:F2}", Int16(0)));
    ASSERT_EQ("221.00", String::Format("{0:F2}", Int16(221)));
    ASSERT_EQ("22106.00", String::Format("{0:F2}", Int16(22106)));
    ASSERT_EQ("32767.00", String::Format("{0:F2}", Int16(32767)));
    ASSERT_EQ("-1.00", String::Format("{0:F2}", Int16(-1)));
    ASSERT_EQ("-32768.00", String::Format("{0:F2}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, F8_Int16) {
    ASSERT_EQ("0.00000000", String::Format("{0:F8}", Int16(0)));
    ASSERT_EQ("221.00000000", String::Format("{0:F8}", Int16(221)));
    ASSERT_EQ("22106.00000000", String::Format("{0:F8}", Int16(22106)));
    ASSERT_EQ("32767.00000000", String::Format("{0:F8}", Int16(32767)));
    ASSERT_EQ("-1.00000000", String::Format("{0:F8}", Int16(-1)));
    ASSERT_EQ("-32768.00000000", String::Format("{0:F8}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, F_Int32) {
    ASSERT_EQ("0.00", String::Format("{0:F}", Int32(0)));
    ASSERT_EQ("2215.00", String::Format("{0:F}", Int32(2215)));
    ASSERT_EQ("221061.00", String::Format("{0:F}", Int32(221061)));
    ASSERT_EQ("2147483647.00", String::Format("{0:F}", Int32::MaxValue));
    ASSERT_EQ("-1.00", String::Format("{0:F}", Int32(-1)));
    ASSERT_EQ("-2147483648.00", String::Format("{0:F}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, F0_Int32) {
    ASSERT_EQ("0", String::Format("{0:F0}", Int32(0)));
    ASSERT_EQ("2215", String::Format("{0:F0}", Int32(2215)));
    ASSERT_EQ("221061", String::Format("{0:F0}", Int32(221061)));
    ASSERT_EQ("2147483647", String::Format("{0:F0}", Int32::MaxValue));
    ASSERT_EQ("-1", String::Format("{0:F0}", Int32(-1)));
    ASSERT_EQ("-2147483648", String::Format("{0:F0}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, F1_Int32) {
    ASSERT_EQ("0.0", String::Format("{0:F1}", Int32(0)));
    ASSERT_EQ("2215.0", String::Format("{0:F1}", Int32(2215)));
    ASSERT_EQ("221061.0", String::Format("{0:F1}", Int32(221061)));
    ASSERT_EQ("2147483647.0", String::Format("{0:F1}", Int32::MaxValue));
    ASSERT_EQ("-1.0", String::Format("{0:F1}", Int32(-1)));
    ASSERT_EQ("-2147483648.0", String::Format("{0:F1}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, F2_Int32) {
    ASSERT_EQ("0.00", String::Format("{0:F2}", Int32(0)));
    ASSERT_EQ("2215.00", String::Format("{0:F2}", Int32(2215)));
    ASSERT_EQ("221061.00", String::Format("{0:F2}", Int32(221061)));
    ASSERT_EQ("2147483647.00", String::Format("{0:F2}", Int32::MaxValue));
    ASSERT_EQ("-1.00", String::Format("{0:F2}", Int32(-1)));
    ASSERT_EQ("-2147483648.00", String::Format("{0:F2}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, F8_Int32) {
    ASSERT_EQ("0.00000000", String::Format("{0:F8}", Int32(0)));
    ASSERT_EQ("2215.00000000", String::Format("{0:F8}", Int32(2215)));
    ASSERT_EQ("221061.00000000", String::Format("{0:F8}", Int32(221061)));
    ASSERT_EQ("2147483647.00000000", String::Format("{0:F8}", Int32::MaxValue));
    ASSERT_EQ("-1.00000000", String::Format("{0:F8}", Int32(-1)));
    ASSERT_EQ("-2147483648.00000000", String::Format("{0:F8}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, F_Int64) {
    ASSERT_EQ("0.00", String::Format("{0:F}", Int64(0)));
    ASSERT_EQ("221512.00", String::Format("{0:F}", Int64(221512)));
    ASSERT_EQ("221061100.00", String::Format("{0:F}", Int64(221061100)));
    ASSERT_EQ("9223372036854775807.00", String::Format("{0:F}", Int64::MaxValue));
    ASSERT_EQ("-1.00", String::Format("{0:F}", Int64(-1)));
    ASSERT_EQ("-9223372036854775808.00", String::Format("{0:F}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, F0_Int64) {
    ASSERT_EQ("0", String::Format("{0:F0}", Int64(0)));
    ASSERT_EQ("221512", String::Format("{0:F0}", Int64(221512)));
    ASSERT_EQ("221061100", String::Format("{0:F0}", Int64(221061100)));
    ASSERT_EQ("9223372036854775807", String::Format("{0:F0}", Int64::MaxValue));
    ASSERT_EQ("-1", String::Format("{0:F0}", Int64(-1)));
    ASSERT_EQ("-9223372036854775808", String::Format("{0:F0}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, F1_Int64) {
    ASSERT_EQ("0.0", String::Format("{0:F1}", Int64(0)));
    ASSERT_EQ("221512.0", String::Format("{0:F1}", Int64(221512)));
    ASSERT_EQ("221061100.0", String::Format("{0:F1}", Int64(221061100)));
    ASSERT_EQ("9223372036854775807.0", String::Format("{0:F1}", Int64::MaxValue));
    ASSERT_EQ("-1.0", String::Format("{0:F1}", Int64(-1)));
    ASSERT_EQ("-9223372036854775808.0", String::Format("{0:F1}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, F2_Int64) {
    ASSERT_EQ("0.00", String::Format("{0:F2}", Int64(0)));
    ASSERT_EQ("221512.00", String::Format("{0:F2}", Int64(221512)));
    ASSERT_EQ("221061100.00", String::Format("{0:F2}", Int64(221061100)));
    ASSERT_EQ("9223372036854775807.00", String::Format("{0:F2}", Int64::MaxValue));
    ASSERT_EQ("-1.00", String::Format("{0:F2}", Int64(-1)));
    ASSERT_EQ("-9223372036854775808.00", String::Format("{0:F2}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, F8_Int64) {
    ASSERT_EQ("0.00000000", String::Format("{0:F8}", Int64(0)));
    ASSERT_EQ("221512.00000000", String::Format("{0:F8}", Int64(221512)));
    ASSERT_EQ("221061100.00000000", String::Format("{0:F8}", Int64(221061100)));
    ASSERT_EQ("9223372036854775807.00000000", String::Format("{0:F8}", Int64::MaxValue));
    ASSERT_EQ("-1.00000000", String::Format("{0:F8}", Int64(-1)));
    ASSERT_EQ("-9223372036854775808.00000000", String::Format("{0:F8}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, F_Byte) {
    ASSERT_EQ("0.00", String::Format("{0:F}", Byte(0)));
    ASSERT_EQ("22.00", String::Format("{0:F}", Byte(22)));
    ASSERT_EQ("208.00", String::Format("{0:F}", Byte(208)));
    ASSERT_EQ("255.00", String::Format("{0:F}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, F0_Byte) {
    ASSERT_EQ("0", String::Format("{0:F0}", Byte(0)));
    ASSERT_EQ("22", String::Format("{0:F0}", Byte(22)));
    ASSERT_EQ("208", String::Format("{0:F0}", Byte(208)));
    ASSERT_EQ("255", String::Format("{0:F0}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, F1_Byte) {
    ASSERT_EQ("0.0", String::Format("{0:F1}", Byte(0)));
    ASSERT_EQ("22.0", String::Format("{0:F1}", Byte(22)));
    ASSERT_EQ("208.0", String::Format("{0:F1}", Byte(208)));
    ASSERT_EQ("255.0", String::Format("{0:F1}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, F2_Byte) {
    ASSERT_EQ("0.00", String::Format("{0:F2}", Byte(0)));
    ASSERT_EQ("22.00", String::Format("{0:F2}", Byte(22)));
    ASSERT_EQ("208.00", String::Format("{0:F2}", Byte(208)));
    ASSERT_EQ("255.00", String::Format("{0:F2}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, F8_Byte) {
    ASSERT_EQ("0.00000000", String::Format("{0:F8}", Byte(0)));
    ASSERT_EQ("22.00000000", String::Format("{0:F8}", Byte(22)));
    ASSERT_EQ("208.00000000", String::Format("{0:F8}", Byte(208)));
    ASSERT_EQ("255.00000000", String::Format("{0:F8}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, F_UInt16) {
    ASSERT_EQ("0.00", String::Format("{0:F}", UInt16(0)));
    ASSERT_EQ("2215.00", String::Format("{0:F}", UInt16(2215)));
    ASSERT_EQ("1221.00", String::Format("{0:F}", UInt16(1221)));
    ASSERT_EQ("65535.00", String::Format("{0:F}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, F0_UInt16) {
    ASSERT_EQ("0", String::Format("{0:F0}", UInt16(0)));
    ASSERT_EQ("2215", String::Format("{0:F0}", UInt16(2215)));
    ASSERT_EQ("1221", String::Format("{0:F0}", UInt16(1221)));
    ASSERT_EQ("65535", String::Format("{0:F0}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, F1_UInt16) {
    ASSERT_EQ("0.0", String::Format("{0:F1}", UInt16(0)));
    ASSERT_EQ("2215.0", String::Format("{0:F1}", UInt16(2215)));
    ASSERT_EQ("1221.0", String::Format("{0:F1}", UInt16(1221)));
    ASSERT_EQ("65535.0", String::Format("{0:F1}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, F2_UInt16) {
    ASSERT_EQ("0.00", String::Format("{0:F2}", UInt16(0)));
    ASSERT_EQ("2215.00", String::Format("{0:F2}", UInt16(2215)));
    ASSERT_EQ("1221.00", String::Format("{0:F2}", UInt16(1221)));
    ASSERT_EQ("65535.00", String::Format("{0:F2}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, F8_UInt16) {
    ASSERT_EQ("0.00000000", String::Format("{0:F8}", UInt16(0)));
    ASSERT_EQ("2215.00000000", String::Format("{0:F8}", UInt16(2215)));
    ASSERT_EQ("1221.00000000", String::Format("{0:F8}", UInt16(1221)));
    ASSERT_EQ("65535.00000000", String::Format("{0:F8}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, F_UInt32) {
    ASSERT_EQ("0.00", String::Format("{0:F}", UInt32(0)));
    ASSERT_EQ("221514.00", String::Format("{0:F}", UInt32(221514)));
    ASSERT_EQ("1221061.00", String::Format("{0:F}", UInt32(1221061)));
    ASSERT_EQ("4294967295.00", String::Format("{0:F}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, F0_UInt32) {
    ASSERT_EQ("0", String::Format("{0:F0}", UInt32(0)));
    ASSERT_EQ("221514", String::Format("{0:F0}", UInt32(221514)));
    ASSERT_EQ("1221061", String::Format("{0:F0}", UInt32(1221061)));
    ASSERT_EQ("4294967295", String::Format("{0:F0}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, F1_UInt32) {
    ASSERT_EQ("0.0", String::Format("{0:F1}", UInt32(0)));
    ASSERT_EQ("221514.0", String::Format("{0:F1}", UInt32(221514)));
    ASSERT_EQ("1221061.0", String::Format("{0:F1}", UInt32(1221061)));
    ASSERT_EQ("4294967295.0", String::Format("{0:F1}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, F2_UInt32) {
    ASSERT_EQ("0.00", String::Format("{0:F2}", UInt32(0)));
    ASSERT_EQ("221514.00", String::Format("{0:F2}", UInt32(221514)));
    ASSERT_EQ("1221061.00", String::Format("{0:F2}", UInt32(1221061)));
    ASSERT_EQ("4294967295.00", String::Format("{0:F2}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, F8_UInt32) {
    ASSERT_EQ("0.00000000", String::Format("{0:F8}", UInt32(0)));
    ASSERT_EQ("221514.00000000", String::Format("{0:F8}", UInt32(221514)));
    ASSERT_EQ("1221061.00000000", String::Format("{0:F8}", UInt32(1221061)));
    ASSERT_EQ("4294967295.00000000", String::Format("{0:F8}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, F_UInt64) {
    ASSERT_EQ("0.00", String::Format("{0:F}", UInt64(0)));
    ASSERT_EQ("221512.00", String::Format("{0:F}", UInt64(221512)));
    ASSERT_EQ("221061100.00", String::Format("{0:F}", UInt64(221061100)));
    ASSERT_EQ("18446744073709551615.00", String::Format("{0:F}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, F0_UInt64) {
    ASSERT_EQ("0", String::Format("{0:F0}", UInt64(0)));
    ASSERT_EQ("221512", String::Format("{0:F0}", UInt64(221512)));
    ASSERT_EQ("221061100", String::Format("{0:F0}", UInt64(221061100)));
    ASSERT_EQ("18446744073709551615", String::Format("{0:F0}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, F1_UInt64) {
    ASSERT_EQ("0.0", String::Format("{0:F1}", UInt64(0)));
    ASSERT_EQ("221512.0", String::Format("{0:F1}", UInt64(221512)));
    ASSERT_EQ("221061100.0", String::Format("{0:F1}", UInt64(221061100)));
    ASSERT_EQ("18446744073709551615.0", String::Format("{0:F1}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, F2_UInt64) {
    ASSERT_EQ("0.00", String::Format("{0:F2}", UInt64(0)));
    ASSERT_EQ("221512.00", String::Format("{0:F2}", UInt64(221512)));
    ASSERT_EQ("221061100.00", String::Format("{0:F2}", UInt64(221061100)));
    ASSERT_EQ("18446744073709551615.00", String::Format("{0:F2}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, F8_UInt64) {
    ASSERT_EQ("0.00000000", String::Format("{0:F8}", UInt64(0)));
    ASSERT_EQ("221512.00000000", String::Format("{0:F8}", UInt64(221512)));
    ASSERT_EQ("221061100.00000000", String::Format("{0:F8}", UInt64(221061100)));
    ASSERT_EQ("18446744073709551615.00000000", String::Format("{0:F8}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, F_Double) {
    ASSERT_EQ("0.00", String::Format("{0:F}", Double(0)));
    ASSERT_EQ("0.90", String::Format("{0:F}", Double(0.9)));
    ASSERT_EQ("11.11", String::Format("{0:F}", Double(11.11116)));
    ASSERT_EQ("98721.50", String::Format("{0:F}", Double(98721.5000001)));
    ASSERT_EQ("-0.10", String::Format("{0:F}", Double(-0.1)));
    ASSERT_EQ("-0.90", String::Format("{0:F}", Double(-0.9)));
    ASSERT_EQ("-19.19", String::Format("{0:F}", Double(-19.19)));
    ASSERT_EQ("-100.56", String::Format("{0:F}", Double(-100.5556)));
  }
  
  TEST(NumericalFormatTest, F0_Doulbe) {
    ASSERT_EQ("0", String::Format("{0:F0}", Double(0)));
    ASSERT_EQ("1", String::Format("{0:F0}", Double(0.9)));
    ASSERT_EQ("11", String::Format("{0:F0}", Double(11.11116)));
    ASSERT_EQ("98722", String::Format("{0:F0}", Double(98721.5000001)));
    ASSERT_EQ("0", String::Format("{0:F0}", Double(-0.1)));
    ASSERT_EQ("-1", String::Format("{0:F0}", Double(-0.9)));
    ASSERT_EQ("-19", String::Format("{0:F0}", Double(-19.19)));
    ASSERT_EQ("-101", String::Format("{0:F0}", Double(-100.5556)));
  }
  
  TEST(NumericalFormatTest, F1_Doulbe) {
    ASSERT_EQ("0.0", String::Format("{0:F1}", Double(0)));
    ASSERT_EQ("0.9", String::Format("{0:F1}", Double(0.9)));
    ASSERT_EQ("11.1", String::Format("{0:F1}", Double(11.11116)));
    ASSERT_EQ("98721.5", String::Format("{0:F1}", Double(98721.5000001)));
    ASSERT_EQ("-0.1", String::Format("{0:F1}", Double(-0.1)));
    ASSERT_EQ("-0.9", String::Format("{0:F1}", Double(-0.9)));
    ASSERT_EQ("-19.2", String::Format("{0:F1}", Double(-19.19)));
    ASSERT_EQ("-100.6", String::Format("{0:F1}", Double(-100.5556)));
  }
  
  TEST(NumericalFormatTest, F2_Doulbe) {
    ASSERT_EQ("0.00", String::Format("{0:F2}", Double(0)));
    ASSERT_EQ("0.90", String::Format("{0:F2}", Double(0.9)));
    ASSERT_EQ("11.11", String::Format("{0:F2}", Double(11.11116)));
    ASSERT_EQ("98721.50", String::Format("{0:F2}", Double(98721.5000001)));
    ASSERT_EQ("-0.10", String::Format("{0:F2}", Double(-0.1)));
    ASSERT_EQ("-0.90", String::Format("{0:F2}", Double(-0.9)));
    ASSERT_EQ("-19.19", String::Format("{0:F2}", Double(-19.19)));
    ASSERT_EQ("-100.56", String::Format("{0:F2}", Double(-100.5556)));
  }
  
  TEST(NumericalFormatTest, F4_Doulbe) {
    ASSERT_EQ("0.0000", String::Format("{0:F4}", Double(0)));
    ASSERT_EQ("0.9000", String::Format("{0:F4}", Double(0.9)));
    ASSERT_EQ("11.1112", String::Format("{0:F4}", Double(11.11116)));
    ASSERT_EQ("98721.5000", String::Format("{0:F4}", Double(98721.5000001)));
    ASSERT_EQ("-0.1000", String::Format("{0:F4}", Double(-0.1)));
    ASSERT_EQ("-0.9000", String::Format("{0:F4}", Double(-0.9)));
    ASSERT_EQ("-19.1900", String::Format("{0:F4}", Double(-19.19)));
    ASSERT_EQ("-100.5556", String::Format("{0:F4}", Double(-100.5556)));
  }
  
  TEST(NumericalFormatTest, F6_Doulbe) {
    ASSERT_EQ("0.000000", String::Format("{0:F6}", Double(0)));
    ASSERT_EQ("0.900000", String::Format("{0:F6}", Double(0.9)));
    ASSERT_EQ("11.111160", String::Format("{0:F6}", Double(11.11116)));
    ASSERT_EQ("98721.500000", String::Format("{0:F6}", Double(98721.5000001)));
    ASSERT_EQ("-0.100000", String::Format("{0:F6}", Double(-0.1)));
    ASSERT_EQ("-0.900000", String::Format("{0:F6}", Double(-0.9)));
    ASSERT_EQ("-19.190000", String::Format("{0:F6}", Double(-19.19)));
    ASSERT_EQ("-100.555600", String::Format("{0:F6}", Double(-100.5556)));
  }
  
  TEST(NumericalFormatTest, F8_Doulbe) {
    ASSERT_EQ("0.00000000", String::Format("{0:F8}", Double(0)));
    ASSERT_EQ("0.90000000", String::Format("{0:F8}", Double(0.9)));
    ASSERT_EQ("11.11116000", String::Format("{0:F8}", Double(11.11116)));
    ASSERT_EQ("98721.50000010", String::Format("{0:F8}", Double(98721.5000001)));
    ASSERT_EQ("-0.10000000", String::Format("{0:F8}", Double(-0.1)));
    ASSERT_EQ("-0.90000000", String::Format("{0:F8}", Double(-0.9)));
    ASSERT_EQ("-19.19000000", String::Format("{0:F8}", Double(-19.19)));
    ASSERT_EQ("-100.55560000", String::Format("{0:F8}", Double(-100.5556)));
  }
  
  TEST(NumericalFormatTest, F_Single) {
    ASSERT_EQ("0.00", String::Format("{0:F}", Single(0.0f)));
    ASSERT_EQ("0.90", String::Format("{0:F}", Single(0.9f)));
    ASSERT_EQ("11.11", String::Format("{0:F}", Single(11.11116f)));
    ASSERT_EQ("98721.50", String::Format("{0:F}", Single(98721.5f)));
  }
  
  TEST(NumericalFormatTest, F0_Single) {
    ASSERT_EQ("0", String::Format("{0:F0}", Single(0.0f)));
    ASSERT_EQ("1", String::Format("{0:F0}", Single(0.9f)));
    ASSERT_EQ("11", String::Format("{0:F0}", Single(11.11116f)));
    ASSERT_EQ("98722", String::Format("{0:F0}", Single(98721.5f)));
  }
  
  TEST(NumericalFormatTest, F1_Single) {
    ASSERT_EQ("0.0", String::Format("{0:F1}", Single(0.0f)));
    ASSERT_EQ("0.9", String::Format("{0:F1}", Single(0.9f)));
    ASSERT_EQ("11.1", String::Format("{0:F1}", Single(11.11116f)));
    ASSERT_EQ("98721.5", String::Format("{0:F1}", Single(98721.5f)));
  }
  
  TEST(NumericalFormatTest, F2_Single) {
    ASSERT_EQ("0.00", String::Format("{0:F2}", Single(0.0f)));
    ASSERT_EQ("0.90", String::Format("{0:F2}", Single(0.9f)));
    ASSERT_EQ("11.11", String::Format("{0:F2}", Single(11.11116f)));
    ASSERT_EQ("98721.50", String::Format("{0:F2}", Single(98721.5f)));
  }
  
  TEST(NumericalFormatTest, F4_Single) {
    ASSERT_EQ("0.0000", String::Format("{0:F4}", Single(0.0f)));
    ASSERT_EQ("0.9000", String::Format("{0:F4}", Single(0.9f)));
    ASSERT_EQ("11.1112", String::Format("{0:F4}", Single(11.11116f)));
    ASSERT_EQ("98721.5000", String::Format("{0:F4}", Single(98721.5f)));
  }
  
  TEST(NumericalFormatTest, F6_Single) {
    ASSERT_EQ("0.000000", String::Format("{0:F6}", Single(0.0f)));
    ASSERT_EQ("0.900000", String::Format("{0:F6}", Single(0.9f)));
    ASSERT_EQ("11.111160", String::Format("{0:F6}", Single(11.11116f)));
    ASSERT_EQ("98721.500000", String::Format("{0:F6}", Single(98721.5f)));
  }
  
  TEST(NumericalFormatTest, F99_Int64) {
    ASSERT_EQ("0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
      String::Format("{0:F99}", Int64(0)));
    ASSERT_EQ("17321.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
      String::Format("{0:F99}", Int64(17321)));
    ASSERT_EQ("1086541.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
      String::Format("{0:F99}", Int64(1086541)));
    ASSERT_EQ("9223372036854775807.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
      String::Format("{0:F99}", Int64::MaxValue));
    ASSERT_EQ("-1.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
      String::Format("{0:F99}", Int64(-1)));
    ASSERT_EQ("-9223372036854775808.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
      String::Format("{0:F99}", Int64::MinValue));
  }
  
}

/*
C# program to generate those tests (replace *type*] by a typename) :

class Program
{
  public static void Main()
  {
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
