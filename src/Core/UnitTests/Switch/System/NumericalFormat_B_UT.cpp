#include <Switch/System/String.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {

TEST(NumericalFormat, B_ParsePrecision) {
  EXPECT_EQ("0", String::Format("{0:B}", Int32(0)));
  EXPECT_EQ("10011111101100101011", String::Format("{0:B}", Int32(654123)));
  EXPECT_EQ("1111111111111111111111111111111", String::Format("{0:B}", Int32::MaxValue));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B}", Int32(-1)));
  EXPECT_EQ("11111111111101100000010011010101", String::Format("{0:B}", Int32(-654123)));
  EXPECT_EQ("10000000000000000000000000000000", String::Format("{0:B}", Int32::MinValue));
}

TEST(NumericalFormat, B1_ParsePrecision) {
  EXPECT_EQ("0", String::Format("{0:B1}", Int32(0)));
  EXPECT_EQ("10011111101100101011", String::Format("{0:B1}", Int32(654123)));
  EXPECT_EQ("1111111111111111111111111111111", String::Format("{0:B1}", Int32::MaxValue));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B1}", Int32(-1)));
  EXPECT_EQ("11111111111101100000010011010101", String::Format("{0:B1}", Int32(-654123)));
  EXPECT_EQ("10000000000000000000000000000000", String::Format("{0:B1}", Int32::MinValue));
}

TEST(NumericalFormat, B00_ParsePrecision) {
  EXPECT_EQ("0", String::Format("{0:B00}", Int32(0)));
  EXPECT_EQ("10011111101100101011", String::Format("{0:B00}", Int32(654123)));
  EXPECT_EQ("1111111111111111111111111111111", String::Format("{0:B00}", Int32::MaxValue));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B00}", Int32(-1)));
  EXPECT_EQ("11111111111101100000010011010101", String::Format("{0:B00}", Int32(-654123)));
  EXPECT_EQ("10000000000000000000000000000000", String::Format("{0:B00}", Int32::MinValue));
}

TEST(NumericalFormat, B001_ParsePrecision) {
  EXPECT_EQ("0", String::Format("{0:B001}", Int32(0)));
  EXPECT_EQ("10011111101100101011", String::Format("{0:B001}", Int32(654123)));
  EXPECT_EQ("1111111111111111111111111111111", String::Format("{0:B001}", Int32::MaxValue));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B001}", Int32(-1)));
  EXPECT_EQ("11111111111101100000010011010101", String::Format("{0:B001}", Int32(-654123)));
  EXPECT_EQ("10000000000000000000000000000000", String::Format("{0:B001}", Int32::MinValue));
}

TEST(NumericalFormat, B0000010_ParsePrecision) {
  EXPECT_EQ("0000000000", String::Format("{0:B0000010}", Int32(0)));
  EXPECT_EQ("10011111101100101011", String::Format("{0:B0000010}", Int32(654123)));
  EXPECT_EQ("1111111111111111111111111111111", String::Format("{0:B0000010}", Int32::MaxValue));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B0000010}", Int32(-1)));
  EXPECT_EQ("11111111111101100000010011010101", String::Format("{0:B0000010}", Int32(-654123)));
  EXPECT_EQ("10000000000000000000000000000000", String::Format("{0:B0000010}", Int32::MinValue));
}

TEST(NumericalFormat, B99_Int64) {
  EXPECT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", String::Format("{0:B99}", Int64(0)));
  EXPECT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000010011111101100101011", String::Format("{0:B99}", Int64(654123)));
  EXPECT_EQ("000000000000000000000000000000000000111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B99}", Int64::MaxValue));
  EXPECT_EQ("000000000000000000000000000000000001111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B99}", Int64(-1)));
  EXPECT_EQ("000000000000000000000000000000000001111111111111111111111111111111111111111111101100000010011010101", String::Format("{0:B99}", Int64(-654123)));
  EXPECT_EQ("000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000", String::Format("{0:B99}", Int64::MinValue));
}

TEST(NumericalFormat, B99_UInt64) {
  EXPECT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", String::Format("{0:B99}", UInt64(0)));
  EXPECT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000010011111101100101011", String::Format("{0:B99}", UInt64(654123)));
  EXPECT_EQ("000000000000000000000000000000000001111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B99}", UInt64::MaxValue));
}

TEST(NumericalFormat, B_Byte) {
  EXPECT_EQ("0", String::Format("{0:B}", Byte(0)));
  EXPECT_EQ("1", String::Format("{0:B}", Byte(1)));
  EXPECT_EQ("10", String::Format("{0:B}", Byte(2)));
  EXPECT_EQ("11", String::Format("{0:B}", Byte(3)));
  EXPECT_EQ("100", String::Format("{0:B}", Byte(4)));
  EXPECT_EQ("101", String::Format("{0:B}", Byte(5)));
  EXPECT_EQ("11001101", String::Format("{0:B}", Byte(0xCD)));
  EXPECT_EQ("11111111", String::Format("{0:B}", Byte(0xFF)));
}

TEST(NumericalFormat, B0_Byte) {
  EXPECT_EQ("0", String::Format("{0:B0}", Byte(0)));
  EXPECT_EQ("1", String::Format("{0:B0}", Byte(1)));
  EXPECT_EQ("10", String::Format("{0:B0}", Byte(2)));
  EXPECT_EQ("11", String::Format("{0:B0}", Byte(3)));
  EXPECT_EQ("100", String::Format("{0:B0}", Byte(4)));
  EXPECT_EQ("101", String::Format("{0:B0}", Byte(5)));
  EXPECT_EQ("11001101", String::Format("{0:B0}", Byte(0xCD)));
  EXPECT_EQ("11111111", String::Format("{0:B0}", Byte(0xFF)));
}

TEST(NumericalFormat, B1_Byte) {
  EXPECT_EQ("0", String::Format("{0:B1}", Byte(0)));
  EXPECT_EQ("1", String::Format("{0:B1}", Byte(1)));
  EXPECT_EQ("10", String::Format("{0:B1}", Byte(2)));
  EXPECT_EQ("11", String::Format("{0:B1}", Byte(3)));
  EXPECT_EQ("100", String::Format("{0:B1}", Byte(4)));
  EXPECT_EQ("101", String::Format("{0:B1}", Byte(5)));
  EXPECT_EQ("11001101", String::Format("{0:B1}", Byte(0xCD)));
  EXPECT_EQ("11111111", String::Format("{0:B1}", Byte(0xFF)));
}

TEST(NumericalFormat, B2_Byte) {
  EXPECT_EQ("00", String::Format("{0:B2}", Byte(0)));
  EXPECT_EQ("01", String::Format("{0:B2}", Byte(1)));
  EXPECT_EQ("10", String::Format("{0:B2}", Byte(2)));
  EXPECT_EQ("11", String::Format("{0:B2}", Byte(3)));
  EXPECT_EQ("100", String::Format("{0:B2}", Byte(4)));
  EXPECT_EQ("101", String::Format("{0:B2}", Byte(5)));
  EXPECT_EQ("11001101", String::Format("{0:B2}", Byte(0xCD)));
  EXPECT_EQ("11111111", String::Format("{0:B2}", Byte(0xFF)));
}

TEST(NumericalFormat, B3_Byte) {
  EXPECT_EQ("000", String::Format("{0:B3}", Byte(0)));
  EXPECT_EQ("001", String::Format("{0:B3}", Byte(1)));
  EXPECT_EQ("010", String::Format("{0:B3}", Byte(2)));
  EXPECT_EQ("011", String::Format("{0:B3}", Byte(3)));
  EXPECT_EQ("100", String::Format("{0:B3}", Byte(4)));
  EXPECT_EQ("101", String::Format("{0:B3}", Byte(5)));
  EXPECT_EQ("11001101", String::Format("{0:B3}", Byte(0xCD)));
  EXPECT_EQ("11111111", String::Format("{0:B3}", Byte(0xFF)));
}

TEST(NumericalFormat, B4_Byte) {
  EXPECT_EQ("0000", String::Format("{0:B4}", Byte(0)));
  EXPECT_EQ("0001", String::Format("{0:B4}", Byte(1)));
  EXPECT_EQ("0010", String::Format("{0:B4}", Byte(2)));
  EXPECT_EQ("0011", String::Format("{0:B4}", Byte(3)));
  EXPECT_EQ("0100", String::Format("{0:B4}", Byte(4)));
  EXPECT_EQ("0101", String::Format("{0:B4}", Byte(5)));
  EXPECT_EQ("11001101", String::Format("{0:B4}", Byte(0xCD)));
  EXPECT_EQ("11111111", String::Format("{0:B4}", Byte(0xFF)));
}

TEST(NumericalFormat, B8_Byte) {
  EXPECT_EQ("00000000", String::Format("{0:B8}", Byte(0)));
  EXPECT_EQ("00000001", String::Format("{0:B8}", Byte(1)));
  EXPECT_EQ("00000010", String::Format("{0:B8}", Byte(2)));
  EXPECT_EQ("00000011", String::Format("{0:B8}", Byte(3)));
  EXPECT_EQ("00000100", String::Format("{0:B8}", Byte(4)));
  EXPECT_EQ("00000101", String::Format("{0:B8}", Byte(5)));
  EXPECT_EQ("11001101", String::Format("{0:B8}", Byte(0xCD)));
  EXPECT_EQ("11111111", String::Format("{0:B8}", Byte(0xFF)));
}

TEST(NumericalFormat, B9_Byte) {
  EXPECT_EQ("000000000", String::Format("{0:B9}", Byte(0)));
  EXPECT_EQ("000000001", String::Format("{0:B9}", Byte(1)));
  EXPECT_EQ("000000010", String::Format("{0:B9}", Byte(2)));
  EXPECT_EQ("000000011", String::Format("{0:B9}", Byte(3)));
  EXPECT_EQ("000000100", String::Format("{0:B9}", Byte(4)));
  EXPECT_EQ("000000101", String::Format("{0:B9}", Byte(5)));
  EXPECT_EQ("011001101", String::Format("{0:B9}", Byte(0xCD)));
  EXPECT_EQ("011111111", String::Format("{0:B9}", Byte(0xFF)));
}

TEST(NumericalFormat, B_UInt16) {
  EXPECT_EQ("0", String::Format("{0:B}", UInt16(0)));
  EXPECT_EQ("11", String::Format("{0:B}", UInt16(3)));
  EXPECT_EQ("1110", String::Format("{0:B}", UInt16(14)));
  EXPECT_EQ("11100001", String::Format("{0:B}", UInt16(225)));
  EXPECT_EQ("110001001001", String::Format("{0:B}", UInt16(3145)));
  EXPECT_EQ("111111111111111", String::Format("{0:B}", UInt16(32767)));
  EXPECT_EQ("1111111111111111", String::Format("{0:B}", UInt16(65535)));
}

TEST(NumericalFormat, B0_UInt16) {
  EXPECT_EQ("0", String::Format("{0:B0}", UInt16(0)));
  EXPECT_EQ("11", String::Format("{0:B0}", UInt16(3)));
  EXPECT_EQ("1110", String::Format("{0:B0}", UInt16(14)));
  EXPECT_EQ("11100001", String::Format("{0:B0}", UInt16(225)));
  EXPECT_EQ("110001001001", String::Format("{0:B0}", UInt16(3145)));
  EXPECT_EQ("111111111111111", String::Format("{0:B0}", UInt16(32767)));
  EXPECT_EQ("1111111111111111", String::Format("{0:B0}", UInt16(65535)));
}

TEST(NumericalFormat, B1_UInt16) {
  EXPECT_EQ("0", String::Format("{0:B1}", UInt16(0)));
  EXPECT_EQ("11", String::Format("{0:B1}", UInt16(3)));
  EXPECT_EQ("1110", String::Format("{0:B1}", UInt16(14)));
  EXPECT_EQ("11100001", String::Format("{0:B1}", UInt16(225)));
  EXPECT_EQ("110001001001", String::Format("{0:B1}", UInt16(3145)));
  EXPECT_EQ("111111111111111", String::Format("{0:B1}", UInt16(32767)));
  EXPECT_EQ("1111111111111111", String::Format("{0:B1}", UInt16(65535)));
}

TEST(NumericalFormat, B4_UInt16) {
  EXPECT_EQ("0000", String::Format("{0:B4}", UInt16(0)));
  EXPECT_EQ("0011", String::Format("{0:B4}", UInt16(3)));
  EXPECT_EQ("1110", String::Format("{0:B4}", UInt16(14)));
  EXPECT_EQ("11100001", String::Format("{0:B4}", UInt16(225)));
  EXPECT_EQ("110001001001", String::Format("{0:B4}", UInt16(3145)));
  EXPECT_EQ("111111111111111", String::Format("{0:B4}", UInt16(32767)));
  EXPECT_EQ("1111111111111111", String::Format("{0:B4}", UInt16(65535)));
}

TEST(NumericalFormat, B8_UInt16) {
  EXPECT_EQ("00000000", String::Format("{0:B8}", UInt16(0)));
  EXPECT_EQ("00000011", String::Format("{0:B8}", UInt16(3)));
  EXPECT_EQ("00001110", String::Format("{0:B8}", UInt16(14)));
  EXPECT_EQ("11100001", String::Format("{0:B8}", UInt16(225)));
  EXPECT_EQ("110001001001", String::Format("{0:B8}", UInt16(3145)));
  EXPECT_EQ("111111111111111", String::Format("{0:B8}", UInt16(32767)));
  EXPECT_EQ("1111111111111111", String::Format("{0:B8}", UInt16(65535)));
}

TEST(NumericalFormat, B17_UInt16) {
  EXPECT_EQ("00000000000000000", String::Format("{0:B17}", UInt16(0)));
  EXPECT_EQ("00000000000000011", String::Format("{0:B17}", UInt16(3)));
  EXPECT_EQ("00000000000001110", String::Format("{0:B17}", UInt16(14)));
  EXPECT_EQ("00000000011100001", String::Format("{0:B17}", UInt16(225)));
  EXPECT_EQ("00000110001001001", String::Format("{0:B17}", UInt16(3145)));
  EXPECT_EQ("00111111111111111", String::Format("{0:B17}", UInt16(32767)));
  EXPECT_EQ("01111111111111111", String::Format("{0:B17}", UInt16(65535)));
}

TEST(NumericalFormat, B_UInt32) {
  EXPECT_EQ("0", String::Format("{0:B}", UInt32(0)));
  EXPECT_EQ("1110", String::Format("{0:B}", UInt32(14)));
  EXPECT_EQ("11100001", String::Format("{0:B}", UInt32(225)));
  EXPECT_EQ("110001001001", String::Format("{0:B}", UInt32(3145)));
  EXPECT_EQ("1111110111111111", String::Format("{0:B}", UInt32(65023)));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B}", UInt32::MaxValue));
}

TEST(NumericalFormat, B0_UInt32) {
  EXPECT_EQ("0", String::Format("{0:B0}", UInt32(0)));
  EXPECT_EQ("1110", String::Format("{0:B0}", UInt32(14)));
  EXPECT_EQ("11100001", String::Format("{0:B0}", UInt32(225)));
  EXPECT_EQ("110001001001", String::Format("{0:B0}", UInt32(3145)));
  EXPECT_EQ("1111110111111111", String::Format("{0:B0}", UInt32(65023)));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B0}", UInt32::MaxValue));
}

TEST(NumericalFormat, B5_UInt32) {
  EXPECT_EQ("00000", String::Format("{0:B5}", UInt32(0)));
  EXPECT_EQ("01110", String::Format("{0:B5}", UInt32(14)));
  EXPECT_EQ("11100001", String::Format("{0:B5}", UInt32(225)));
  EXPECT_EQ("110001001001", String::Format("{0:B5}", UInt32(3145)));
  EXPECT_EQ("1111110111111111", String::Format("{0:B5}", UInt32(65023)));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B5}", UInt32::MaxValue));
}

TEST(NumericalFormat, B8_UInt32) {
  EXPECT_EQ("00000000", String::Format("{0:B8}", UInt32(0)));
  EXPECT_EQ("00001110", String::Format("{0:B8}", UInt32(14)));
  EXPECT_EQ("11100001", String::Format("{0:B8}", UInt32(225)));
  EXPECT_EQ("110001001001", String::Format("{0:B8}", UInt32(3145)));
  EXPECT_EQ("1111110111111111", String::Format("{0:B8}", UInt32(65023)));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B8}", UInt32::MaxValue));
}

TEST(NumericalFormat, B33_UInt32) {
  EXPECT_EQ("000000000000000000000000000000000", String::Format("{0:B33}", UInt32(0)));
  EXPECT_EQ("000000000000000000000000000001110", String::Format("{0:B33}", UInt32(14)));
  EXPECT_EQ("000000000000000000000000011100001", String::Format("{0:B33}", UInt32(225)));
  EXPECT_EQ("000000000000000000000110001001001", String::Format("{0:B33}", UInt32(3145)));
  EXPECT_EQ("000000000000000001111110111111111", String::Format("{0:B33}", UInt32(65023)));
  EXPECT_EQ("011111111111111111111111111111111", String::Format("{0:B33}", UInt32::MaxValue));
}

TEST(NumericalFormat, B_UInt64) {
  EXPECT_EQ("0", String::Format("{0:B}", UInt64(0)));
  EXPECT_EQ("1110", String::Format("{0:B}", UInt64(14)));
  EXPECT_EQ("111111011111111", String::Format("{0:B}", UInt64(32511)));
  EXPECT_EQ("11110111111101111111011111110111", String::Format("{0:B}", UInt64(4160223223u)));
  EXPECT_EQ("110100011011011100010111010110001110001000011001011", String::Format("{0:B}", UInt64(1844674407370955u)));
  EXPECT_EQ("1111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B}", UInt64::MaxValue));
}

TEST(NumericalFormat, B15_UInt64) {
  EXPECT_EQ("000000000000000", String::Format("{0:B15}", UInt64(0)));
  EXPECT_EQ("000000000001110", String::Format("{0:B15}", UInt64(14)));
  EXPECT_EQ("111111011111111", String::Format("{0:B15}", UInt64(32511)));
  EXPECT_EQ("11110111111101111111011111110111", String::Format("{0:B15}", UInt64(4160223223u)));
  EXPECT_EQ("110100011011011100010111010110001110001000011001011", String::Format("{0:B15}", UInt64(1844674407370955u)));
  EXPECT_EQ("1111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B15}", UInt64::MaxValue));
}

TEST(NumericalFormat, B36_UInt64) {
  EXPECT_EQ("000000000000000000000000000000000000", String::Format("{0:B36}", UInt64(0)));
  EXPECT_EQ("000000000000000000000000000000001110", String::Format("{0:B36}", UInt64(14)));
  EXPECT_EQ("000000000000000000000111111011111111", String::Format("{0:B36}", UInt64(32511)));
  EXPECT_EQ("000011110111111101111111011111110111", String::Format("{0:B36}", UInt64(4160223223u)));
  EXPECT_EQ("110100011011011100010111010110001110001000011001011", String::Format("{0:B36}", UInt64(1844674407370955u)));
  EXPECT_EQ("1111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B36}", UInt64::MaxValue));
}

TEST(NumericalFormat, B65_UInt64) {
  EXPECT_EQ("00000000000000000000000000000000000000000000000000000000000000000", String::Format("{0:B65}", UInt64(0)));
  EXPECT_EQ("00000000000000000000000000000000000000000000000000000000000001110", String::Format("{0:B65}", UInt64(14)));
  EXPECT_EQ("00000000000000000000000000000000000000000000000000111111011111111", String::Format("{0:B65}", UInt64(32511)));
  EXPECT_EQ("00000000000000000000000000000000011110111111101111111011111110111", String::Format("{0:B65}", UInt64(4160223223u)));
  EXPECT_EQ("00000000000000110100011011011100010111010110001110001000011001011", String::Format("{0:B65}", UInt64(1844674407370955u)));
  EXPECT_EQ("01111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B65}", UInt64::MaxValue));
}

TEST(NumericalFormat, B_SByte) {
  EXPECT_EQ("0", String::Format("{0:B}", SByte(0)));
  EXPECT_EQ("101", String::Format("{0:B}", SByte(5)));
  EXPECT_EQ("1111111", String::Format("{0:B}", SByte(127)));
  EXPECT_EQ("11111011", String::Format("{0:B}", SByte(-5)));
  EXPECT_EQ("10000001", String::Format("{0:B}", SByte(-127)));
}

TEST(NumericalFormat, B0_SByte) {
  EXPECT_EQ("0", String::Format("{0:B0}", SByte(0)));
  EXPECT_EQ("101", String::Format("{0:B0}", SByte(5)));
  EXPECT_EQ("1111111", String::Format("{0:B0}", SByte(127)));
  EXPECT_EQ("11111011", String::Format("{0:B0}", SByte(-5)));
  EXPECT_EQ("10000001", String::Format("{0:B0}", SByte(-127)));
}

TEST(NumericalFormat, B1_SByte) {
  EXPECT_EQ("0", String::Format("{0:B1}", SByte(0)));
  EXPECT_EQ("101", String::Format("{0:B1}", SByte(5)));
  EXPECT_EQ("1111111", String::Format("{0:B1}", SByte(127)));
  EXPECT_EQ("11111011", String::Format("{0:B1}", SByte(-5)));
  EXPECT_EQ("10000001", String::Format("{0:B1}", SByte(-127)));
}

TEST(NumericalFormat, B2_SByte) {
  EXPECT_EQ("00", String::Format("{0:B2}", SByte(0)));
  EXPECT_EQ("101", String::Format("{0:B2}", SByte(5)));
  EXPECT_EQ("1111111", String::Format("{0:B2}", SByte(127)));
  EXPECT_EQ("11111011", String::Format("{0:B2}", SByte(-5)));
  EXPECT_EQ("10000001", String::Format("{0:B2}", SByte(-127)));
}

TEST(NumericalFormat, B3_SByte) {
  EXPECT_EQ("000", String::Format("{0:B3}", SByte(0)));
  EXPECT_EQ("101", String::Format("{0:B3}", SByte(5)));
  EXPECT_EQ("1111111", String::Format("{0:B3}", SByte(127)));
  EXPECT_EQ("11111011", String::Format("{0:B3}", SByte(-5)));
  EXPECT_EQ("10000001", String::Format("{0:B3}", SByte(-127)));
}

TEST(NumericalFormat, B4_SByte) {
  EXPECT_EQ("0000", String::Format("{0:B4}", SByte(0)));
  EXPECT_EQ("0101", String::Format("{0:B4}", SByte(5)));
  EXPECT_EQ("1111111", String::Format("{0:B4}", SByte(127)));
  EXPECT_EQ("11111011", String::Format("{0:B4}", SByte(-5)));
  EXPECT_EQ("10000001", String::Format("{0:B4}", SByte(-127)));
}

TEST(NumericalFormat, B8_SByte) {
  EXPECT_EQ("00000000", String::Format("{0:B8}", SByte(0)));
  EXPECT_EQ("00000101", String::Format("{0:B8}", SByte(5)));
  EXPECT_EQ("01111111", String::Format("{0:B8}", SByte(127)));
  EXPECT_EQ("11111011", String::Format("{0:B8}", SByte(-5)));
  EXPECT_EQ("10000001", String::Format("{0:B8}", SByte(-127)));
}

TEST(NumericalFormat, B12_SByte) {
  EXPECT_EQ("000000000000", String::Format("{0:B12}", SByte(0)));
  EXPECT_EQ("000000000101", String::Format("{0:B12}", SByte(5)));
  EXPECT_EQ("000001111111", String::Format("{0:B12}", SByte(127)));
  EXPECT_EQ("000011111011", String::Format("{0:B12}", SByte(-5)));
  EXPECT_EQ("000010000001", String::Format("{0:B12}", SByte(-127)));
}

TEST(NumericalFormat, B_Int16) {
  EXPECT_EQ("0", String::Format("{0:B}", Int16(0)));
  EXPECT_EQ("11", String::Format("{0:B}", Int16(3)));
  EXPECT_EQ("1110", String::Format("{0:B}", Int16(14)));
  EXPECT_EQ("11100001", String::Format("{0:B}", Int16(225)));
  EXPECT_EQ("110001001001", String::Format("{0:B}", Int16(3145)));
  EXPECT_EQ("111111111111111", String::Format("{0:B}", Int16(32767)));
  EXPECT_EQ("1111111111111111", String::Format("{0:B}", Int16(-1)));
  EXPECT_EQ("1111111111110010", String::Format("{0:B}", Int16(-14)));
  EXPECT_EQ("1111111100011111", String::Format("{0:B}", Int16(-225)));
  EXPECT_EQ("1111001110110111", String::Format("{0:B}", Int16(-3145)));
  EXPECT_EQ("1000000000000000", String::Format("{0:B}", Int16(-32768)));
}

TEST(NumericalFormat, B0_Int16) {
  EXPECT_EQ("0", String::Format("{0:B0}", Int16(0)));
  EXPECT_EQ("11", String::Format("{0:B0}", Int16(3)));
  EXPECT_EQ("1110", String::Format("{0:B0}", Int16(14)));
  EXPECT_EQ("11100001", String::Format("{0:B0}", Int16(225)));
  EXPECT_EQ("110001001001", String::Format("{0:B0}", Int16(3145)));
  EXPECT_EQ("111111111111111", String::Format("{0:B0}", Int16(32767)));
  EXPECT_EQ("1111111111111111", String::Format("{0:B0}", Int16(-1)));
  EXPECT_EQ("1111111111110010", String::Format("{0:B0}", Int16(-14)));
  EXPECT_EQ("1111111100011111", String::Format("{0:B0}", Int16(-225)));
  EXPECT_EQ("1111001110110111", String::Format("{0:B0}", Int16(-3145)));
  EXPECT_EQ("1000000000000000", String::Format("{0:B0}", Int16(-32768)));
}

TEST(NumericalFormat, B1_Int16) {
  EXPECT_EQ("0", String::Format("{0:B1}", Int16(0)));
  EXPECT_EQ("11", String::Format("{0:B1}", Int16(3)));
  EXPECT_EQ("1110", String::Format("{0:B1}", Int16(14)));
  EXPECT_EQ("11100001", String::Format("{0:B1}", Int16(225)));
  EXPECT_EQ("110001001001", String::Format("{0:B1}", Int16(3145)));
  EXPECT_EQ("111111111111111", String::Format("{0:B1}", Int16(32767)));
  EXPECT_EQ("1111111111111111", String::Format("{0:B1}", Int16(-1)));
  EXPECT_EQ("1111111111110010", String::Format("{0:B1}", Int16(-14)));
  EXPECT_EQ("1111111100011111", String::Format("{0:B1}", Int16(-225)));
  EXPECT_EQ("1111001110110111", String::Format("{0:B1}", Int16(-3145)));
  EXPECT_EQ("1000000000000000", String::Format("{0:B1}", Int16(-32768)));
}

TEST(NumericalFormat, B4_Int16) {
  EXPECT_EQ("0000", String::Format("{0:B4}", Int16(0)));
  EXPECT_EQ("0011", String::Format("{0:B4}", Int16(3)));
  EXPECT_EQ("1110", String::Format("{0:B4}", Int16(14)));
  EXPECT_EQ("11100001", String::Format("{0:B4}", Int16(225)));
  EXPECT_EQ("110001001001", String::Format("{0:B4}", Int16(3145)));
  EXPECT_EQ("111111111111111", String::Format("{0:B4}", Int16(32767)));
  EXPECT_EQ("1111111111111111", String::Format("{0:B4}", Int16(-1)));
  EXPECT_EQ("1111111111110010", String::Format("{0:B4}", Int16(-14)));
  EXPECT_EQ("1111111100011111", String::Format("{0:B4}", Int16(-225)));
  EXPECT_EQ("1111001110110111", String::Format("{0:B4}", Int16(-3145)));
  EXPECT_EQ("1000000000000000", String::Format("{0:B4}", Int16(-32768)));
}

TEST(NumericalFormat, B8_Int16) {
  EXPECT_EQ("00000000", String::Format("{0:B8}", Int16(0)));
  EXPECT_EQ("00000011", String::Format("{0:B8}", Int16(3)));
  EXPECT_EQ("00001110", String::Format("{0:B8}", Int16(14)));
  EXPECT_EQ("11100001", String::Format("{0:B8}", Int16(225)));
  EXPECT_EQ("110001001001", String::Format("{0:B8}", Int16(3145)));
  EXPECT_EQ("111111111111111", String::Format("{0:B8}", Int16(32767)));
  EXPECT_EQ("1111111111111111", String::Format("{0:B8}", Int16(-1)));
  EXPECT_EQ("1111111111110010", String::Format("{0:B8}", Int16(-14)));
  EXPECT_EQ("1111111100011111", String::Format("{0:B8}", Int16(-225)));
  EXPECT_EQ("1111001110110111", String::Format("{0:B8}", Int16(-3145)));
  EXPECT_EQ("1000000000000000", String::Format("{0:B8}", Int16(-32768)));
}

TEST(NumericalFormat, B17_Int16) {
  EXPECT_EQ("00000000000000000", String::Format("{0:B17}", Int16(0)));
  EXPECT_EQ("00000000000000011", String::Format("{0:B17}", Int16(3)));
  EXPECT_EQ("00000000000001110", String::Format("{0:B17}", Int16(14)));
  EXPECT_EQ("00000000011100001", String::Format("{0:B17}", Int16(225)));
  EXPECT_EQ("00000110001001001", String::Format("{0:B17}", Int16(3145)));
  EXPECT_EQ("00111111111111111", String::Format("{0:B17}", Int16(32767)));
  EXPECT_EQ("01111111111111111", String::Format("{0:B17}", Int16(-1)));
  EXPECT_EQ("01111111111110010", String::Format("{0:B17}", Int16(-14)));
  EXPECT_EQ("01111111100011111", String::Format("{0:B17}", Int16(-225)));
  EXPECT_EQ("01111001110110111", String::Format("{0:B17}", Int16(-3145)));
  EXPECT_EQ("01000000000000000", String::Format("{0:B17}", Int16(-32768)));
}

TEST(NumericalFormat, B_Int32) {
  EXPECT_EQ("0", String::Format("{0:B}", Int32(0)));
  EXPECT_EQ("11", String::Format("{0:B}", Int32(3)));
  EXPECT_EQ("1110", String::Format("{0:B}", Int32(14)));
  EXPECT_EQ("111111111111111", String::Format("{0:B}", Int32(32767)));
  EXPECT_EQ("1111111111111111111111111111111", String::Format("{0:B}", Int32(2147483647)));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B}", Int32(-1)));
  EXPECT_EQ("11111111111111101000000011111010", String::Format("{0:B}", Int32(-98054)));
  EXPECT_EQ("10000000000000000000000000000001", String::Format("{0:B}", Int32(-2147483647)));
}

TEST(NumericalFormat, B2_Int32) {
  EXPECT_EQ("00", String::Format("{0:B2}", Int32(0)));
  EXPECT_EQ("11", String::Format("{0:B2}", Int32(3)));
  EXPECT_EQ("1110", String::Format("{0:B2}", Int32(14)));
  EXPECT_EQ("111111111111111", String::Format("{0:B2}", Int32(32767)));
  EXPECT_EQ("1111111111111111111111111111111", String::Format("{0:B2}", Int32(2147483647)));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B2}", Int32(-1)));
  EXPECT_EQ("11111111111111101000000011111010", String::Format("{0:B2}", Int32(-98054)));
  EXPECT_EQ("10000000000000000000000000000001", String::Format("{0:B2}", Int32(-2147483647)));
}

TEST(NumericalFormat, B5_Int32) {
  EXPECT_EQ("00000", String::Format("{0:B5}", Int32(0)));
  EXPECT_EQ("00011", String::Format("{0:B5}", Int32(3)));
  EXPECT_EQ("01110", String::Format("{0:B5}", Int32(14)));
  EXPECT_EQ("111111111111111", String::Format("{0:B5}", Int32(32767)));
  EXPECT_EQ("1111111111111111111111111111111", String::Format("{0:B5}", Int32(2147483647)));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B5}", Int32(-1)));
  EXPECT_EQ("11111111111111101000000011111010", String::Format("{0:B5}", Int32(-98054)));
  EXPECT_EQ("10000000000000000000000000000001", String::Format("{0:B5}", Int32(-2147483647)));
}

TEST(NumericalFormat, B8_Int32) {
  EXPECT_EQ("00000000", String::Format("{0:B8}", Int32(0)));
  EXPECT_EQ("00000011", String::Format("{0:B8}", Int32(3)));
  EXPECT_EQ("00001110", String::Format("{0:B8}", Int32(14)));
  EXPECT_EQ("111111111111111", String::Format("{0:B8}", Int32(32767)));
  EXPECT_EQ("1111111111111111111111111111111", String::Format("{0:B8}", Int32(2147483647)));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B8}", Int32(-1)));
  EXPECT_EQ("11111111111111101000000011111010", String::Format("{0:B8}", Int32(-98054)));
  EXPECT_EQ("10000000000000000000000000000001", String::Format("{0:B8}", Int32(-2147483647)));
}

TEST(NumericalFormat, B11_Int32) {
  EXPECT_EQ("00000000000", String::Format("{0:B11}", Int32(0)));
  EXPECT_EQ("00000000011", String::Format("{0:B11}", Int32(3)));
  EXPECT_EQ("00000001110", String::Format("{0:B11}", Int32(14)));
  EXPECT_EQ("111111111111111", String::Format("{0:B11}", Int32(32767)));
  EXPECT_EQ("1111111111111111111111111111111", String::Format("{0:B11}", Int32(2147483647)));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B11}", Int32(-1)));
  EXPECT_EQ("11111111111111101000000011111010", String::Format("{0:B11}", Int32(-98054)));
  EXPECT_EQ("10000000000000000000000000000001", String::Format("{0:B11}", Int32(-2147483647)));
}

TEST(NumericalFormat, B33_Int32) {
  EXPECT_EQ("000000000000000000000000000000000", String::Format("{0:B33}", Int32(0)));
  EXPECT_EQ("000000000000000000000000000000011", String::Format("{0:B33}", Int32(3)));
  EXPECT_EQ("000000000000000000000000000001110", String::Format("{0:B33}", Int32(14)));
  EXPECT_EQ("000000000000000000111111111111111", String::Format("{0:B33}", Int32(32767)));
  EXPECT_EQ("001111111111111111111111111111111", String::Format("{0:B33}", Int32(2147483647)));
  EXPECT_EQ("011111111111111111111111111111111", String::Format("{0:B33}", Int32(-1)));
  EXPECT_EQ("011111111111111101000000011111010", String::Format("{0:B33}", Int32(-98054)));
  EXPECT_EQ("010000000000000000000000000000001", String::Format("{0:B33}", Int32(-2147483647)));
}

TEST(NumericalFormat, B_Int64) {
  EXPECT_EQ("0", String::Format("{0:B}", Int64(0)));
  EXPECT_EQ("101", String::Format("{0:B}", Int64(5)));
  EXPECT_EQ("111111111111111", String::Format("{0:B}", Int64(32767)));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B}", Int64(4294967295ll)));
  EXPECT_EQ("110100011011011100010111010110001110001000011001011", String::Format("{0:B}", Int64(1844674407370955ll)));
  EXPECT_EQ("1111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B}", Int64(-1)));
  EXPECT_EQ("1111111111111001011100100100011101000101001110001110111100110101", String::Format("{0:B}", -Int64(1844674407370955ll)));
}

TEST(NumericalFormat, B2_Int64) {
  EXPECT_EQ("00", String::Format("{0:B2}", Int64(0)));
  EXPECT_EQ("101", String::Format("{0:B2}", Int64(5)));
  EXPECT_EQ("111111111111111", String::Format("{0:B2}", Int64(32767)));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B2}", Int64(4294967295ll)));
  EXPECT_EQ("110100011011011100010111010110001110001000011001011", String::Format("{0:B2}", Int64(1844674407370955ll)));
  EXPECT_EQ("1111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B2}", Int64(-1)));
  EXPECT_EQ("1111111111111001011100100100011101000101001110001110111100110101", String::Format("{0:B2}", -Int64(1844674407370955ll)));
}

TEST(NumericalFormat, B8_Int64) {
  EXPECT_EQ("00000000", String::Format("{0:B8}", Int64(0)));
  EXPECT_EQ("00000101", String::Format("{0:B8}", Int64(5)));
  EXPECT_EQ("111111111111111", String::Format("{0:B8}", Int64(32767)));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B8}", Int64(4294967295ll)));
  EXPECT_EQ("110100011011011100010111010110001110001000011001011", String::Format("{0:B8}", Int64(1844674407370955ll)));
  EXPECT_EQ("1111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B8}", Int64(-1)));
  EXPECT_EQ("1111111111111001011100100100011101000101001110001110111100110101", String::Format("{0:B8}", -Int64(1844674407370955ll)));
}

TEST(NumericalFormat, B16_Int64) {
  EXPECT_EQ("0000000000000000", String::Format("{0:B16}", Int64(0)));
  EXPECT_EQ("0000000000000101", String::Format("{0:B16}", Int64(5)));
  EXPECT_EQ("0111111111111111", String::Format("{0:B16}", Int64(32767)));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B16}", Int64(4294967295ll)));
  EXPECT_EQ("110100011011011100010111010110001110001000011001011", String::Format("{0:B16}", Int64(1844674407370955ll)));
  EXPECT_EQ("1111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B16}", Int64(-1)));
  EXPECT_EQ("1111111111111001011100100100011101000101001110001110111100110101", String::Format("{0:B16}", -Int64(1844674407370955ll)));
}

TEST(NumericalFormat, B20_Int64) {
  EXPECT_EQ("00000000000000000000", String::Format("{0:B20}", Int64(0)));
  EXPECT_EQ("00000000000000000101", String::Format("{0:B20}", Int64(5)));
  EXPECT_EQ("00000111111111111111", String::Format("{0:B20}", Int64(32767)));
  EXPECT_EQ("11111111111111111111111111111111", String::Format("{0:B20}", Int64(4294967295ll)));
  EXPECT_EQ("110100011011011100010111010110001110001000011001011", String::Format("{0:B20}", Int64(1844674407370955ll)));
  EXPECT_EQ("1111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B20}", Int64(-1)));
  EXPECT_EQ("1111111111111001011100100100011101000101001110001110111100110101", String::Format("{0:B20}", -Int64(1844674407370955ll)));
}

TEST(NumericalFormat, B64_Int64) {
  EXPECT_EQ("0000000000000000000000000000000000000000000000000000000000000000", String::Format("{0:B64}", Int64(0)));
  EXPECT_EQ("0000000000000000000000000000000000000000000000000000000000000101", String::Format("{0:B64}", Int64(5)));
  EXPECT_EQ("0000000000000000000000000000000000000000000000000111111111111111", String::Format("{0:B64}", Int64(32767)));
  EXPECT_EQ("0000000000000000000000000000000011111111111111111111111111111111", String::Format("{0:B64}", Int64(4294967295ll)));
  EXPECT_EQ("0000000000000110100011011011100010111010110001110001000011001011", String::Format("{0:B64}", Int64(1844674407370955ll)));
  EXPECT_EQ("1111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B64}", Int64(-1)));
  EXPECT_EQ("1111111111111001011100100100011101000101001110001110111100110101", String::Format("{0:B64}", -Int64(1844674407370955ll)));
}

TEST(NumericalFormat, B65_Int64) {
  EXPECT_EQ("00000000000000000000000000000000000000000000000000000000000000000", String::Format("{0:B65}", Int64(0)));
  EXPECT_EQ("00000000000000000000000000000000000000000000000000000000000000101", String::Format("{0:B65}", Int64(5)));
  EXPECT_EQ("00000000000000000000000000000000000000000000000000111111111111111", String::Format("{0:B65}", Int64(32767)));
  EXPECT_EQ("00000000000000000000000000000000011111111111111111111111111111111", String::Format("{0:B65}", Int64(4294967295ll)));
  EXPECT_EQ("00000000000000110100011011011100010111010110001110001000011001011", String::Format("{0:B65}", Int64(1844674407370955ll)));
  EXPECT_EQ("01111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B65}", Int64(-1)));
  EXPECT_EQ("01111111111111001011100100100011101000101001110001110111100110101", String::Format("{0:B65}", -Int64(1844674407370955ll)));
}


TEST(NumericalFormat, B_Double) {
  EXPECT_THROW(String::Format("{0:B}", Double(105.132)), FormatException);
  EXPECT_THROW(String::Format("{0:B}", Double(0.0)), FormatException);
  EXPECT_THROW(String::Format("{0:B5}", Double(10.0)), FormatException);
  EXPECT_THROW(String::Format("{0:B8}", Double(10000.132)), FormatException);
  EXPECT_THROW(String::Format("{0:B8}", Double(10000.132)), FormatException);
}

TEST(NumericalFormat, B_Single) {
  EXPECT_THROW(String::Format("{0:B}", Single(105.132f)), FormatException);
  EXPECT_THROW(String::Format("{0:B}", Single(0.0f)), FormatException);
  EXPECT_THROW(String::Format("{0:B5}", Single(10.0f)), FormatException);
  EXPECT_THROW(String::Format("{0:B8}", Single(1540.132f)), FormatException);
  EXPECT_THROW(String::Format("{0:B8}", Single(100.2540f)), FormatException);  
}

TEST(NumericalFormat, b) {
  EXPECT_EQ("1111111", String::Format("{0:b4}", Byte(0x7F)));
  EXPECT_EQ("11111011", String::Format("{0:b4}", SByte(-5)));
  EXPECT_EQ("1111001110110111", String::Format("{0:b}", Int16(-3145)));
  EXPECT_EQ("110001001001", String::Format("{0:b4}", UInt16(3145)));
  EXPECT_EQ("11111111111111101000000011111010", String::Format("{0:b}", Int32(-98054)));
  EXPECT_EQ("111111111111111", String::Format("{0:b5}", UInt32(32767)));
  EXPECT_EQ("1111111111111001011100100100011101000101001110001110111100110101", String::Format("{0:b16}", Int64(-1844674407370955ll)));
  EXPECT_EQ("1100110011001100110011001100110011001100110011001110011010011", String::Format("{0:b22}", UInt64(1844674407370955987ull)));
}

TEST(NumericalFormat, b_ToString) {
  EXPECT_EQ("1111111", Byte(0x7F).ToString("b4"));
  EXPECT_EQ("11111011", SByte(-5).ToString("b4"));
  EXPECT_EQ("1111001110110111", Int16(-3145).ToString("b"));
  EXPECT_EQ("110001001001", UInt16(3145).ToString("b4"));
  EXPECT_EQ("11111111111111101000000011111010", Int32(-98054).ToString("b"));
  EXPECT_EQ("111111111111111", UInt32(32767).ToString("b5"));
  EXPECT_EQ("1111111111111001011100100100011101000101001110001110111100110101", Int64(-1844674407370955ll).ToString("b16"));
  EXPECT_EQ("1100110011001100110011001100110011001100110011001110011010011", UInt64(1844674407370955987ull).ToString("b22"));
}

}
