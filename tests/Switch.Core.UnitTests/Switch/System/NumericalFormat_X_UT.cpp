#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {

  TEST(NumericalFormatTest, X_ParsePrecision) {
    ASSERT_EQ("0", String::Format("{0:X}", Int32(0)));
    ASSERT_EQ("9FB2B", String::Format("{0:X}", Int32(654123)));
    ASSERT_EQ("7FFFFFFF", String::Format("{0:X}", Int32::MaxValue));
    ASSERT_EQ("FFFFFFFF", String::Format("{0:X}", Int32(-1)));
    ASSERT_EQ("FFF604D5", String::Format("{0:X}", Int32(-654123)));
    ASSERT_EQ("80000000", String::Format("{0:X}", Int32::MinValue));
  }

  TEST(NumericalFormatTest, X1_ParsePrecision) {
    ASSERT_EQ("0", String::Format("{0:X1}", Int32(0)));
    ASSERT_EQ("9FB2B", String::Format("{0:X1}", Int32(654123)));
    ASSERT_EQ("7FFFFFFF", String::Format("{0:X1}", Int32::MaxValue));
    ASSERT_EQ("FFFFFFFF", String::Format("{0:X1}", Int32(-1)));
    ASSERT_EQ("FFF604D5", String::Format("{0:X1}", Int32(-654123)));
    ASSERT_EQ("80000000", String::Format("{0:X1}", Int32::MinValue));
  }

  TEST(NumericalFormatTest, X00_ParsePrecision) {
    ASSERT_EQ("0", String::Format("{0:X00}", Int32(0)));
    ASSERT_EQ("9FB2B", String::Format("{0:X00}", Int32(654123)));
    ASSERT_EQ("7FFFFFFF", String::Format("{0:X00}", Int32::MaxValue));
    ASSERT_EQ("FFFFFFFF", String::Format("{0:X00}", Int32(-1)));
    ASSERT_EQ("FFF604D5", String::Format("{0:X00}", Int32(-654123)));
    ASSERT_EQ("80000000", String::Format("{0:X00}", Int32::MinValue));
  }

  TEST(NumericalFormatTest, X001_ParsePrecision) {
    ASSERT_EQ("0", String::Format("{0:X001}", Int32(0)));
    ASSERT_EQ("9FB2B", String::Format("{0:X001}", Int32(654123)));
    ASSERT_EQ("7FFFFFFF", String::Format("{0:X001}", Int32::MaxValue));
    ASSERT_EQ("FFFFFFFF", String::Format("{0:X001}", Int32(-1)));
    ASSERT_EQ("FFF604D5", String::Format("{0:X001}", Int32(-654123)));
    ASSERT_EQ("80000000", String::Format("{0:X001}", Int32::MinValue));
  }

  TEST(NumericalFormatTest, X0000010_ParsePrecision) {
    ASSERT_EQ("0000000000", String::Format("{0:X0000010}", Int32(0)));
    ASSERT_EQ("000009FB2B", String::Format("{0:X0000010}", Int32(654123)));
    ASSERT_EQ("007FFFFFFF", String::Format("{0:X0000010}", Int32::MaxValue));
    ASSERT_EQ("00FFFFFFFF", String::Format("{0:X0000010}", Int32(-1)));
    ASSERT_EQ("00FFF604D5", String::Format("{0:X0000010}", Int32(-654123)));
    ASSERT_EQ("0080000000", String::Format("{0:X0000010}", Int32::MinValue));
  }

  TEST(NumericalFormatTest, X99_Int64) {
    ASSERT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", String::Format("{0:X99}", Int64(0)));
    ASSERT_EQ("00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000009FB2B", String::Format("{0:X99}", Int64(654123)));
    ASSERT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000007FFFFFFFFFFFFFFF", String::Format("{0:X99}", Int64::MaxValue));
    ASSERT_EQ("00000000000000000000000000000000000000000000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF", String::Format("{0:X99}", Int64(-1)));
    ASSERT_EQ("00000000000000000000000000000000000000000000000000000000000000000000000000000000000FFFFFFFFFFF604D5", String::Format("{0:X99}", Int64(-654123)));
    ASSERT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000008000000000000000", String::Format("{0:X99}", Int64::MinValue));
  }

  TEST(NumericalFormatTest, X99_UInt64) {
    ASSERT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", String::Format("{0:X99}", UInt64(0)));
    ASSERT_EQ("00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000009FB2B", String::Format("{0:X99}", UInt64(654123)));
    ASSERT_EQ("00000000000000000000000000000000000000000000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF", String::Format("{0:X99}", UInt64::MaxValue));
  }

  TEST(NumericalFormatTest, X_Byte) {
    ASSERT_EQ("0", String::Format("{0:X}", Byte(0x0)));
    ASSERT_EQ("5", String::Format("{0:X}", Byte(0x5)));
    ASSERT_EQ("7F", String::Format("{0:X}", Byte(0x7F)));
    ASSERT_EQ("FF", String::Format("{0:X}", Byte(0xFF)));
  }

  TEST(NumericalFormatTest, X0_Byte) {
    ASSERT_EQ("0", String::Format("{0:X0}", Byte(0x0)));
    ASSERT_EQ("5", String::Format("{0:X0}", Byte(0x5)));
    ASSERT_EQ("7F", String::Format("{0:X0}", Byte(0x7F)));
    ASSERT_EQ("FF", String::Format("{0:X0}", Byte(0xFF)));
  }

  TEST(NumericalFormatTest, X1_Byte) {

    ASSERT_EQ("0", String::Format("{0:X1}", Byte(0x0)));
    ASSERT_EQ("5", String::Format("{0:X1}", Byte(0x5)));
    ASSERT_EQ("7F", String::Format("{0:X1}", Byte(0x7F)));
    ASSERT_EQ("FF", String::Format("{0:X1}", Byte(0xFF)));
  }

  TEST(NumericalFormatTest, X4_Byte) {

    ASSERT_EQ("0000", String::Format("{0:X4}", Byte(0x0)));
    ASSERT_EQ("0005", String::Format("{0:X4}", Byte(0x5)));
    ASSERT_EQ("007F", String::Format("{0:X4}", Byte(0x7F)));
    ASSERT_EQ("00FF", String::Format("{0:X4}", Byte(0xFF)));
  }

  TEST(NumericalFormatTest, X8_Byte) {

    ASSERT_EQ("00000000", String::Format("{0:X8}", Byte(0x0)));
    ASSERT_EQ("00000005", String::Format("{0:X8}", Byte(0x5)));
    ASSERT_EQ("0000007F", String::Format("{0:X8}", Byte(0x7F)));
    ASSERT_EQ("000000FF", String::Format("{0:X8}", Byte(0xFF)));
  }

  TEST(NumericalFormatTest, X_SByte) {
    ASSERT_EQ("0", String::Format("{0:X}", SByte(0)));
    ASSERT_EQ("5", String::Format("{0:X}", SByte(5)));
    ASSERT_EQ("7F", String::Format("{0:X}", SByte(127)));
    ASSERT_EQ("FB", String::Format("{0:X}", SByte(-5)));
    ASSERT_EQ("81", String::Format("{0:X}", SByte(-127)));
  }

  TEST(NumericalFormatTest, X0_SByte) {
    ASSERT_EQ("0", String::Format("{0:X0}", SByte(0)));
    ASSERT_EQ("5", String::Format("{0:X0}", SByte(5)));
    ASSERT_EQ("7F", String::Format("{0:X0}", SByte(127)));
    ASSERT_EQ("FB", String::Format("{0:X0}", SByte(-5)));
    ASSERT_EQ("81", String::Format("{0:X0}", SByte(-127)));
  }

  TEST(NumericalFormatTest, X1_SByte) {
    ASSERT_EQ("0", String::Format("{0:X1}", SByte(0)));
    ASSERT_EQ("5", String::Format("{0:X1}", SByte(5)));
    ASSERT_EQ("7F", String::Format("{0:X1}", SByte(127)));
    ASSERT_EQ("FB", String::Format("{0:X1}", SByte(-5)));
    ASSERT_EQ("81", String::Format("{0:X1}", SByte(-127)));
  }

  TEST(NumericalFormatTest, X2_SByte) {
    ASSERT_EQ("00", String::Format("{0:X2}", SByte(0)));
    ASSERT_EQ("05", String::Format("{0:X2}", SByte(5)));
    ASSERT_EQ("7F", String::Format("{0:X2}", SByte(127)));
    ASSERT_EQ("FB", String::Format("{0:X2}", SByte(-5)));
    ASSERT_EQ("81", String::Format("{0:X2}", SByte(-127)));
  }

  TEST(NumericalFormatTest, X3_SByte) {
    ASSERT_EQ("000", String::Format("{0:X3}", SByte(0)));
    ASSERT_EQ("005", String::Format("{0:X3}", SByte(5)));
    ASSERT_EQ("07F", String::Format("{0:X3}", SByte(127)));
    ASSERT_EQ("0FB", String::Format("{0:X3}", SByte(-5)));
    ASSERT_EQ("081", String::Format("{0:X3}", SByte(-127)));
  }

  TEST(NumericalFormatTest, X4_SByte) {
    ASSERT_EQ("0000", String::Format("{0:X4}", SByte(0)));
    ASSERT_EQ("0005", String::Format("{0:X4}", SByte(5)));
    ASSERT_EQ("007F", String::Format("{0:X4}", SByte(127)));
    ASSERT_EQ("00FB", String::Format("{0:X4}", SByte(-5)));
    ASSERT_EQ("0081", String::Format("{0:X4}", SByte(-127)));
  }

  TEST(NumericalFormatTest, X8_SByte) {
    ASSERT_EQ("00000000", String::Format("{0:X8}", SByte(0)));
    ASSERT_EQ("00000005", String::Format("{0:X8}", SByte(5)));
    ASSERT_EQ("0000007F", String::Format("{0:X8}", SByte(127)));
    ASSERT_EQ("000000FB", String::Format("{0:X8}", SByte(-5)));
    ASSERT_EQ("00000081", String::Format("{0:X8}", SByte(-127)));
  }

  TEST(NumericalFormatTest, X_Int16) {
    ASSERT_EQ("0", String::Format("{0:X}", Int16(0)));
    ASSERT_EQ("3", String::Format("{0:X}", Int16(3)));
    ASSERT_EQ("E", String::Format("{0:X}", Int16(14)));
    ASSERT_EQ("E1", String::Format("{0:X}", Int16(225)));
    ASSERT_EQ("C49", String::Format("{0:X}", Int16(3145)));
    ASSERT_EQ("7FFF", String::Format("{0:X}", Int16(32767)));
    ASSERT_EQ("FFFF", String::Format("{0:X}", Int16(-1)));
    ASSERT_EQ("FFF2", String::Format("{0:X}", Int16(-14)));
    ASSERT_EQ("FF1F", String::Format("{0:X}", Int16(-225)));
    ASSERT_EQ("F3B7", String::Format("{0:X}", Int16(-3145)));
    ASSERT_EQ("8000", String::Format("{0:X}", Int16(-32768)));
  }

  TEST(NumericalFormatTest, X0_Int16) {
    ASSERT_EQ("0", String::Format("{0:X0}", Int16(0)));
    ASSERT_EQ("3", String::Format("{0:X0}", Int16(3)));
    ASSERT_EQ("E", String::Format("{0:X0}", Int16(14)));
    ASSERT_EQ("E1", String::Format("{0:X0}", Int16(225)));
    ASSERT_EQ("C49", String::Format("{0:X0}", Int16(3145)));
    ASSERT_EQ("7FFF", String::Format("{0:X0}", Int16(32767)));
    ASSERT_EQ("FFFF", String::Format("{0:X0}", Int16(-1)));
    ASSERT_EQ("FFF2", String::Format("{0:X0}", Int16(-14)));
    ASSERT_EQ("FF1F", String::Format("{0:X0}", Int16(-225)));
    ASSERT_EQ("F3B7", String::Format("{0:X0}", Int16(-3145)));
    ASSERT_EQ("8000", String::Format("{0:X0}", Int16(-32768)));
  }

  TEST(NumericalFormatTest, X1_Int16) {
    ASSERT_EQ("0", String::Format("{0:X1}", Int16(0)));
    ASSERT_EQ("3", String::Format("{0:X1}", Int16(3)));
    ASSERT_EQ("E", String::Format("{0:X1}", Int16(14)));
    ASSERT_EQ("E1", String::Format("{0:X1}", Int16(225)));
    ASSERT_EQ("C49", String::Format("{0:X1}", Int16(3145)));
    ASSERT_EQ("7FFF", String::Format("{0:X1}", Int16(32767)));
    ASSERT_EQ("FFFF", String::Format("{0:X1}", Int16(-1)));
    ASSERT_EQ("FFF2", String::Format("{0:X1}", Int16(-14)));
    ASSERT_EQ("FF1F", String::Format("{0:X1}", Int16(-225)));
    ASSERT_EQ("F3B7", String::Format("{0:X1}", Int16(-3145)));
    ASSERT_EQ("8000", String::Format("{0:X1}", Int16(-32768)));
  }

  TEST(NumericalFormatTest, X4_Int16) {
    ASSERT_EQ("0000", String::Format("{0:X4}", Int16(0)));
    ASSERT_EQ("0003", String::Format("{0:X4}", Int16(3)));
    ASSERT_EQ("000E", String::Format("{0:X4}", Int16(14)));
    ASSERT_EQ("00E1", String::Format("{0:X4}", Int16(225)));
    ASSERT_EQ("0C49", String::Format("{0:X4}", Int16(3145)));
    ASSERT_EQ("7FFF", String::Format("{0:X4}", Int16(32767)));
    ASSERT_EQ("FFFF", String::Format("{0:X4}", Int16(-1)));
    ASSERT_EQ("FFF2", String::Format("{0:X4}", Int16(-14)));
    ASSERT_EQ("FF1F", String::Format("{0:X4}", Int16(-225)));
    ASSERT_EQ("F3B7", String::Format("{0:X4}", Int16(-3145)));
    ASSERT_EQ("8000", String::Format("{0:X4}", Int16(-32768)));
  }

  TEST(NumericalFormatTest, X8_Int16) {
    ASSERT_EQ("00000000", String::Format("{0:X8}", Int16(0)));
    ASSERT_EQ("00000003", String::Format("{0:X8}", Int16(3)));
    ASSERT_EQ("0000000E", String::Format("{0:X8}", Int16(14)));
    ASSERT_EQ("000000E1", String::Format("{0:X8}", Int16(225)));
    ASSERT_EQ("00000C49", String::Format("{0:X8}", Int16(3145)));
    ASSERT_EQ("00007FFF", String::Format("{0:X8}", Int16(32767)));
    ASSERT_EQ("0000FFFF", String::Format("{0:X8}", Int16(-1)));
    ASSERT_EQ("0000FFF2", String::Format("{0:X8}", Int16(-14)));
    ASSERT_EQ("0000FF1F", String::Format("{0:X8}", Int16(-225)));
    ASSERT_EQ("0000F3B7", String::Format("{0:X8}", Int16(-3145)));
    ASSERT_EQ("00008000", String::Format("{0:X8}", Int16(-32768)));
  }

  TEST(NumericalFormatTest, X_UInt16) {
    ASSERT_EQ("0", String::Format("{0:X}", UInt16(0)));
    ASSERT_EQ("3", String::Format("{0:X}", UInt16(3)));
    ASSERT_EQ("E", String::Format("{0:X}", UInt16(14)));
    ASSERT_EQ("E1", String::Format("{0:X}", UInt16(225)));
    ASSERT_EQ("C49", String::Format("{0:X}", UInt16(3145)));
    ASSERT_EQ("7FFF", String::Format("{0:X}", UInt16(32767)));
    ASSERT_EQ("FFFF", String::Format("{0:X}", UInt16(65535)));
  }

  TEST(NumericalFormatTest, X0_UInt16) {
    ASSERT_EQ("0", String::Format("{0:X0}", UInt16(0)));
    ASSERT_EQ("3", String::Format("{0:X0}", UInt16(3)));
    ASSERT_EQ("E", String::Format("{0:X0}", UInt16(14)));
    ASSERT_EQ("E1", String::Format("{0:X0}", UInt16(225)));
    ASSERT_EQ("C49", String::Format("{0:X0}", UInt16(3145)));
    ASSERT_EQ("7FFF", String::Format("{0:X0}", UInt16(32767)));
    ASSERT_EQ("FFFF", String::Format("{0:X0}", UInt16(65535)));
  }

  TEST(NumericalFormatTest, X1_UInt16) {
    ASSERT_EQ("0", String::Format("{0:X1}", UInt16(0)));
    ASSERT_EQ("3", String::Format("{0:X1}", UInt16(3)));
    ASSERT_EQ("E", String::Format("{0:X1}", UInt16(14)));
    ASSERT_EQ("E1", String::Format("{0:X1}", UInt16(225)));
    ASSERT_EQ("C49", String::Format("{0:X1}", UInt16(3145)));
    ASSERT_EQ("7FFF", String::Format("{0:X1}", UInt16(32767)));
    ASSERT_EQ("FFFF", String::Format("{0:X1}", UInt16(65535)));
  }

  TEST(NumericalFormatTest, X4_UInt16) {
    ASSERT_EQ("0000", String::Format("{0:X4}", UInt16(0)));
    ASSERT_EQ("0003", String::Format("{0:X4}", UInt16(3)));
    ASSERT_EQ("000E", String::Format("{0:X4}", UInt16(14)));
    ASSERT_EQ("00E1", String::Format("{0:X4}", UInt16(225)));
    ASSERT_EQ("0C49", String::Format("{0:X4}", UInt16(3145)));
    ASSERT_EQ("7FFF", String::Format("{0:X4}", UInt16(32767)));
    ASSERT_EQ("FFFF", String::Format("{0:X4}", UInt16(65535)));
  }

  TEST(NumericalFormatTest, X8_UInt16) {
    ASSERT_EQ("00000000", String::Format("{0:X8}", UInt16(0)));
    ASSERT_EQ("00000003", String::Format("{0:X8}", UInt16(3)));
    ASSERT_EQ("0000000E", String::Format("{0:X8}", UInt16(14)));
    ASSERT_EQ("000000E1", String::Format("{0:X8}", UInt16(225)));
    ASSERT_EQ("00000C49", String::Format("{0:X8}", UInt16(3145)));
    ASSERT_EQ("00007FFF", String::Format("{0:X8}", UInt16(32767)));
    ASSERT_EQ("0000FFFF", String::Format("{0:X8}", UInt16(65535)));
  }

  TEST(NumericalFormatTest, X_Int32) {
    ASSERT_EQ("0", String::Format("{0:X}", Int32(0)));
    ASSERT_EQ("3", String::Format("{0:X}", Int32(3)));
    ASSERT_EQ("E", String::Format("{0:X}", Int32(14)));
    ASSERT_EQ("7FFF", String::Format("{0:X}", Int32(32767)));
    ASSERT_EQ("7FFFFFFF", String::Format("{0:X}", Int32(2147483647)));
    ASSERT_EQ("FFFFFFFF", String::Format("{0:X}", Int32(-1)));
    ASSERT_EQ("FFFE80FA", String::Format("{0:X}", Int32(-98054)));
    ASSERT_EQ("80000001", String::Format("{0:X}", Int32(-2147483647)));
  }

  TEST(NumericalFormatTest, X2_Int32) {
    ASSERT_EQ("00", String::Format("{0:X2}", Int32(0)));
    ASSERT_EQ("03", String::Format("{0:X2}", Int32(3)));
    ASSERT_EQ("0E", String::Format("{0:X2}", Int32(14)));
    ASSERT_EQ("7FFF", String::Format("{0:X2}", Int32(32767)));
    ASSERT_EQ("7FFFFFFF", String::Format("{0:X2}", Int32(2147483647)));
    ASSERT_EQ("FFFFFFFF", String::Format("{0:X2}", Int32(-1)));
    ASSERT_EQ("FFFE80FA", String::Format("{0:X2}", Int32(-98054)));
    ASSERT_EQ("80000001", String::Format("{0:X2}", Int32(-2147483647)));
  }

  TEST(NumericalFormatTest, X5_Int32) {
    ASSERT_EQ("00000", String::Format("{0:X5}", Int32(0)));
    ASSERT_EQ("00003", String::Format("{0:X5}", Int32(3)));
    ASSERT_EQ("0000E", String::Format("{0:X5}", Int32(14)));
    ASSERT_EQ("07FFF", String::Format("{0:X5}", Int32(32767)));
    ASSERT_EQ("7FFFFFFF", String::Format("{0:X5}", Int32(2147483647)));
    ASSERT_EQ("FFFFFFFF", String::Format("{0:X5}", Int32(-1)));
    ASSERT_EQ("FFFE80FA", String::Format("{0:X5}", Int32(-98054)));
    ASSERT_EQ("80000001", String::Format("{0:X5}", Int32(-2147483647)));
  }

  TEST(NumericalFormatTest, X8_Int32) {
    ASSERT_EQ("00000000", String::Format("{0:X8}", Int32(0)));
    ASSERT_EQ("00000003", String::Format("{0:X8}", Int32(3)));
    ASSERT_EQ("0000000E", String::Format("{0:X8}", Int32(14)));
    ASSERT_EQ("00007FFF", String::Format("{0:X8}", Int32(32767)));
    ASSERT_EQ("7FFFFFFF", String::Format("{0:X8}", Int32(2147483647)));
    ASSERT_EQ("FFFFFFFF", String::Format("{0:X8}", Int32(-1)));
    ASSERT_EQ("FFFE80FA", String::Format("{0:X8}", Int32(-98054)));
    ASSERT_EQ("80000001", String::Format("{0:X8}", Int32(-2147483647)));
  }

  TEST(NumericalFormatTest, X11_Int32) {
    ASSERT_EQ("00000000000", String::Format("{0:X11}", Int32(0)));
    ASSERT_EQ("00000000003", String::Format("{0:X11}", Int32(3)));
    ASSERT_EQ("0000000000E", String::Format("{0:X11}", Int32(14)));
    ASSERT_EQ("00000007FFF", String::Format("{0:X11}", Int32(32767)));
    ASSERT_EQ("0007FFFFFFF", String::Format("{0:X11}", Int32(2147483647)));
    ASSERT_EQ("000FFFFFFFF", String::Format("{0:X11}", Int32(-1)));
    ASSERT_EQ("000FFFE80FA", String::Format("{0:X11}", Int32(-98054)));
    ASSERT_EQ("00080000001", String::Format("{0:X11}", Int32(-2147483647)));
  }

  TEST(NumericalFormatTest, X0_UInt32) {
    ASSERT_EQ("0", String::Format("{0:X}", UInt32(0)));
    ASSERT_EQ("5", String::Format("{0:X}", UInt32(5)));
    ASSERT_EQ("E", String::Format("{0:X}", UInt32(14)));
    ASSERT_EQ("7FFF", String::Format("{0:X}", UInt32(32767)));
    ASSERT_EQ("FFFFFFFF", String::Format("{0:X}", UInt32(4294967295u)));
  }

  TEST(NumericalFormatTest, X5_UInt32) {
    ASSERT_EQ("00000", String::Format("{0:X5}", UInt32(0)));
    ASSERT_EQ("00005", String::Format("{0:X5}", UInt32(5)));
    ASSERT_EQ("0000E", String::Format("{0:X5}", UInt32(14)));
    ASSERT_EQ("07FFF", String::Format("{0:X5}", UInt32(32767)));
    ASSERT_EQ("FFFFFFFF", String::Format("{0:X5}", UInt32(4294967295u)));
  }

  TEST(NumericalFormatTest, X8_UInt32) {
    ASSERT_EQ("00000000", String::Format("{0:X8}", UInt32(0)));
    ASSERT_EQ("00000005", String::Format("{0:X8}", UInt32(5)));
    ASSERT_EQ("0000000E", String::Format("{0:X8}", UInt32(14)));
    ASSERT_EQ("00007FFF", String::Format("{0:X8}", UInt32(32767)));
    ASSERT_EQ("FFFFFFFF", String::Format("{0:X8}", UInt32(4294967295u)));
  }

  TEST(NumericalFormatTest, X11_UInt32) {
    ASSERT_EQ("00000000000", String::Format("{0:X11}", UInt32(0)));
    ASSERT_EQ("00000000005", String::Format("{0:X11}", UInt32(5)));
    ASSERT_EQ("0000000000E", String::Format("{0:X11}", UInt32(14)));
    ASSERT_EQ("00000007FFF", String::Format("{0:X11}", UInt32(32767)));
    ASSERT_EQ("000FFFFFFFF", String::Format("{0:X11}", UInt32(4294967295u)));
  }

  TEST(NumericalFormatTest, X_Int64) {
    ASSERT_EQ("0", String::Format("{0:X}", Int64(0)));
    ASSERT_EQ("5", String::Format("{0:X}", Int64(5)));
    ASSERT_EQ("7FFF", String::Format("{0:X}", Int64(32767)));
    ASSERT_EQ("FFFFFFFF", String::Format("{0:X}", Int64(4294967295u)));
    ASSERT_EQ("68DB8BAC710CB", String::Format("{0:X}", Int64(1844674407370955u)));
    ASSERT_EQ("FFFFFFFFFFFFFFFF", String::Format("{0:X}", Int64(-1)));
    ASSERT_EQ("FFF972474538EF35", String::Format("{0:X}", -Int64(1844674407370955)));
  }

  TEST(NumericalFormatTest, X2_Int64) {
    ASSERT_EQ("00", String::Format("{0:X2}", Int64(0)));
    ASSERT_EQ("05", String::Format("{0:X2}", Int64(5)));
    ASSERT_EQ("7FFF", String::Format("{0:X2}", Int64(32767)));
    ASSERT_EQ("FFFFFFFF", String::Format("{0:X2}", Int64(4294967295u)));
    ASSERT_EQ("68DB8BAC710CB", String::Format("{0:X2}", Int64(1844674407370955u)));
    ASSERT_EQ("FFFFFFFFFFFFFFFF", String::Format("{0:X2}", Int64(-1)));
    ASSERT_EQ("FFF972474538EF35", String::Format("{0:X2}", Int64(-1844674407370955)));
  }

  TEST(NumericalFormatTest, X8_Int64) {
    ASSERT_EQ("00000000", String::Format("{0:X8}", Int64(0)));
    ASSERT_EQ("00000005", String::Format("{0:X8}", Int64(5)));
    ASSERT_EQ("00007FFF", String::Format("{0:X8}", Int64(32767)));
    ASSERT_EQ("FFFFFFFF", String::Format("{0:X8}", Int64(4294967295u)));
    ASSERT_EQ("68DB8BAC710CB", String::Format("{0:X8}", Int64(1844674407370955u)));
    ASSERT_EQ("FFFFFFFFFFFFFFFF", String::Format("{0:X8}", Int64(-1)));
    ASSERT_EQ("FFF972474538EF35", String::Format("{0:X8}", Int64(-1844674407370955)));
  }

  TEST(NumericalFormatTest, X16_Int64) {
    ASSERT_EQ("0000000000000000", String::Format("{0:X16}", Int64(0)));
    ASSERT_EQ("0000000000000005", String::Format("{0:X16}", Int64(5)));
    ASSERT_EQ("0000000000007FFF", String::Format("{0:X16}", Int64(32767)));
    ASSERT_EQ("00000000FFFFFFFF", String::Format("{0:X16}", Int64(4294967295u)));
    ASSERT_EQ("00068DB8BAC710CB", String::Format("{0:X16}", Int64(1844674407370955u)));
    ASSERT_EQ("FFFFFFFFFFFFFFFF", String::Format("{0:X16}", Int64(-1)));
    ASSERT_EQ("FFF972474538EF35", String::Format("{0:X16}", Int64(-1844674407370955)));
  }

  TEST(NumericalFormatTest, X20_Int64) {
    ASSERT_EQ("00000000000000000000", String::Format("{0:X20}", Int64(0)));
    ASSERT_EQ("00000000000000000005", String::Format("{0:X20}", Int64(5)));
    ASSERT_EQ("00000000000000007FFF", String::Format("{0:X20}", Int64(32767)));
    ASSERT_EQ("000000000000FFFFFFFF", String::Format("{0:X20}", Int64(4294967295u)));
    ASSERT_EQ("000000068DB8BAC710CB", String::Format("{0:X20}", Int64(1844674407370955u)));
    ASSERT_EQ("0000FFFFFFFFFFFFFFFF", String::Format("{0:X20}", Int64(-1)));
    ASSERT_EQ("0000FFF972474538EF35", String::Format("{0:X20}", Int64(-1844674407370955)));
  }

  TEST(NumericalFormatTest, X_UInt64) {
    ASSERT_EQ("0", String::Format("{0:X}", UInt64(0)));
    ASSERT_EQ("5", String::Format("{0:X}", UInt64(5)));
    ASSERT_EQ("7FFF", String::Format("{0:X}", UInt64(32767)));
    ASSERT_EQ("FFFFFFFF", String::Format("{0:X}", UInt64(4294967295u)));
    ASSERT_EQ("68DB8BAC710CB", String::Format("{0:X}", UInt64(1844674407370955u)));
    ASSERT_EQ("1999999999999CD3", String::Format("{0:X}", UInt64(1844674407370955987u)));
  }

  TEST(NumericalFormatTest, X15_UInt64) {
    ASSERT_EQ("000000000000000", String::Format("{0:X15}", UInt64(0)));
    ASSERT_EQ("000000000000005", String::Format("{0:X15}", UInt64(5)));
    ASSERT_EQ("000000000007FFF", String::Format("{0:X15}", UInt64(32767)));
    ASSERT_EQ("0000000FFFFFFFF", String::Format("{0:X15}", UInt64(4294967295u)));
    ASSERT_EQ("0068DB8BAC710CB", String::Format("{0:X15}", UInt64(1844674407370955u)));
    ASSERT_EQ("1999999999999CD3", String::Format("{0:X15}", UInt64(1844674407370955987u)));
  }

  TEST(NumericalFormatTest, X16_UInt64) {
    ASSERT_EQ("0000000000000000", String::Format("{0:X16}", UInt64(0)));
    ASSERT_EQ("0000000000000005", String::Format("{0:X16}", UInt64(5)));
    ASSERT_EQ("0000000000007FFF", String::Format("{0:X16}", UInt64(32767)));
    ASSERT_EQ("00000000FFFFFFFF", String::Format("{0:X16}", UInt64(4294967295u)));
    ASSERT_EQ("00068DB8BAC710CB", String::Format("{0:X16}", UInt64(1844674407370955u)));
    ASSERT_EQ("1999999999999CD3", String::Format("{0:X16}", UInt64(1844674407370955987u)));
  }

  TEST(NumericalFormatTest, X22_UInt64) {
    ASSERT_EQ("0000000000000000000000", String::Format("{0:X22}", UInt64(0)));
    ASSERT_EQ("0000000000000000000005", String::Format("{0:X22}", UInt64(5)));
    ASSERT_EQ("0000000000000000007FFF", String::Format("{0:X22}", UInt64(32767)));
    ASSERT_EQ("00000000000000FFFFFFFF", String::Format("{0:X22}", UInt64(4294967295u)));
    ASSERT_EQ("00000000068DB8BAC710CB", String::Format("{0:X22}", UInt64(1844674407370955u)));
    ASSERT_EQ("0000001999999999999CD3", String::Format("{0:X22}", UInt64(1844674407370955987u)));
  }

  TEST(NumericalFormatTest, X_Double) {
    ASSERT_THROW(String::Format("{0:x}", Double(105.132)), FormatException);
    ASSERT_THROW(String::Format("{0:X}", Double(0.0)), FormatException);
    ASSERT_THROW(String::Format("{0:X5}", Double(10.0)), FormatException);
    ASSERT_THROW(String::Format("{0:X8}", Double(10000.132)), FormatException);
    ASSERT_THROW(String::Format("{0:x8}", Double(10000.132)), FormatException);
  }

  TEST(NumericalFormatTest, X_Single) {
    ASSERT_THROW(String::Format("{0:x}", Single(105.132f)), FormatException);
    ASSERT_THROW(String::Format("{0:X}", Single(0.0f)), FormatException);
    ASSERT_THROW(String::Format("{0:X5}", Single(10.0f)), FormatException);
    ASSERT_THROW(String::Format("{0:X8}", Single(1540.132f)), FormatException);
    ASSERT_THROW(String::Format("{0:x8}", Single(100.2540f)), FormatException);
  }

  TEST(NumericalFormatTest, x) {
    ASSERT_EQ("007f", String::Format("{0:x4}", Byte(0x7F)));
    ASSERT_EQ("00fb", String::Format("{0:x4}", SByte(-5)));
    ASSERT_EQ("f3b7", String::Format("{0:x}", Int16(-3145)));
    ASSERT_EQ("0c49", String::Format("{0:x4}", UInt16(3145)));
    ASSERT_EQ("fffe80fa", String::Format("{0:x}", Int32(-98054)));
    ASSERT_EQ("07fff", String::Format("{0:x5}", UInt32(32767)));
    ASSERT_EQ("fff972474538ef35", String::Format("{0:x16}", Int64(-1844674407370955)));
    ASSERT_EQ("0000001999999999999cd3", String::Format("{0:x22}", UInt64(1844674407370955987)));
  }

  TEST(NumericalFormatTest, x_ToString) {
    ASSERT_EQ("007f", Byte(0x7F).ToString("x4"));
    ASSERT_EQ("00fb", SByte(-5).ToString("x4"));
    ASSERT_EQ("f3b7", Int16(-3145).ToString("x"));
    ASSERT_EQ("0c49", UInt16(3145).ToString("x4"));
    ASSERT_EQ("fffe80fa", Int32(-98054).ToString("x"));
    ASSERT_EQ("07fff", UInt32(32767).ToString("x5"));
    ASSERT_EQ("fff972474538ef35", Int64(-1844674407370955).ToString("x16"));
    ASSERT_EQ("0000001999999999999cd3", UInt64(1844674407370955987).ToString("x22"));
  }

}

