#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Collections::Generic;

namespace {

  TEST(NumericalFormatTest, G_SByte) {
    ASSERT_EQ("0", String::Format("{0:G}", SByte(0)));
    ASSERT_EQ("5", String::Format("{0:G}", SByte(5)));
    ASSERT_EQ("127", String::Format("{0:G}", SByte(127)));
    ASSERT_EQ("-1", String::Format("{0:G}", SByte(-1)));
    ASSERT_EQ("-25", String::Format("{0:G}", SByte(-25)));
    ASSERT_EQ("-128", String::Format("{0:G}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, G1_SByte) {
    ASSERT_EQ("0", String::Format("{0:G1}", SByte(0)));
    ASSERT_EQ("5", String::Format("{0:G1}", SByte(5)));
    ASSERT_EQ("1E+02", String::Format("{0:G1}", SByte(127)));
    ASSERT_EQ("-1", String::Format("{0:G1}", SByte(-1)));
    ASSERT_EQ("-2E+01", String::Format("{0:G1}", SByte(-19)));
    ASSERT_EQ("-1E+02", String::Format("{0:G1}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, G2_SByte) {
    ASSERT_EQ("0", String::Format("{0:G2}", SByte(0)));
    ASSERT_EQ("5", String::Format("{0:G2}", SByte(5)));
    ASSERT_EQ("1.3E+02", String::Format("{0:G2}", SByte(127)));
    ASSERT_EQ("-1", String::Format("{0:G2}", SByte(-1)));
    ASSERT_EQ("-25", String::Format("{0:G2}", SByte(-25)));
    ASSERT_EQ("-1.3E+02", String::Format("{0:G2}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, G3_SByte) {
    ASSERT_EQ("0", String::Format("{0:G3}", SByte(0)));
    ASSERT_EQ("5", String::Format("{0:G3}", SByte(5)));
    ASSERT_EQ("127", String::Format("{0:G3}", SByte(127)));
    ASSERT_EQ("-1", String::Format("{0:G3}", SByte(-1)));
    ASSERT_EQ("-25", String::Format("{0:G3}", SByte(-25)));
    ASSERT_EQ("-128", String::Format("{0:G3}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, G4_SByte) {
    ASSERT_EQ("0", String::Format("{0:G4}", SByte(0)));
    ASSERT_EQ("5", String::Format("{0:G4}", SByte(5)));
    ASSERT_EQ("127", String::Format("{0:G4}", SByte(127)));
    ASSERT_EQ("-1", String::Format("{0:G4}", SByte(-1)));
    ASSERT_EQ("-25", String::Format("{0:G4}", SByte(-25)));
    ASSERT_EQ("-128", String::Format("{0:G4}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, G_Int16) {
    ASSERT_EQ("0", String::Format("{0:G}", Int16(0)));
    ASSERT_EQ("127", String::Format("{0:G}", Int16(127)));
    ASSERT_EQ("9877", String::Format("{0:G}", Int16(9877)));
    ASSERT_EQ("32767", String::Format("{0:G}", Int16(32767)));
    ASSERT_EQ("-1", String::Format("{0:G}", Int16(-1)));
    ASSERT_EQ("-32768", String::Format("{0:G}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, G1_Int16) {
    ASSERT_EQ("0", String::Format("{0:G1}", Int16(0)));
    ASSERT_EQ("1E+02", String::Format("{0:G1}", Int16(127)));
    ASSERT_EQ("1E+04", String::Format("{0:G1}", Int16(9877)));
    ASSERT_EQ("3E+04", String::Format("{0:G1}", Int16(32767)));
    ASSERT_EQ("-1", String::Format("{0:G1}", Int16(-1)));
    ASSERT_EQ("-3E+04", String::Format("{0:G1}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, G2_Int16) {
    ASSERT_EQ("0", String::Format("{0:G2}", Int16(0)));
    ASSERT_EQ("1.3E+02", String::Format("{0:G2}", Int16(127)));
    ASSERT_EQ("9.9E+03", String::Format("{0:G2}", Int16(9877)));
    ASSERT_EQ("3.3E+04", String::Format("{0:G2}", Int16(32767)));
    ASSERT_EQ("-1", String::Format("{0:G2}", Int16(-1)));
    ASSERT_EQ("-3.3E+04", String::Format("{0:G2}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, G3_Int16) {
    ASSERT_EQ("0", String::Format("{0:G3}", Int16(0)));
    ASSERT_EQ("127", String::Format("{0:G3}", Int16(127)));
    ASSERT_EQ("9.88E+03", String::Format("{0:G3}", Int16(9877)));
    ASSERT_EQ("3.28E+04", String::Format("{0:G3}", Int16(32767)));
    ASSERT_EQ("-1", String::Format("{0:G3}", Int16(-1)));
    ASSERT_EQ("-3.28E+04", String::Format("{0:G3}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, G4_Int16) {
    ASSERT_EQ("0", String::Format("{0:G4}", Int16(0)));
    ASSERT_EQ("127", String::Format("{0:G4}", Int16(127)));
    ASSERT_EQ("9877", String::Format("{0:G4}", Int16(9877)));
    ASSERT_EQ("3.277E+04", String::Format("{0:G4}", Int16(32767)));
    ASSERT_EQ("-1", String::Format("{0:G4}", Int16(-1)));
    ASSERT_EQ("-3.277E+04", String::Format("{0:G4}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, G8_Int16) {
    ASSERT_EQ("0", String::Format("{0:G8}", Int16(0)));
    ASSERT_EQ("127", String::Format("{0:G8}", Int16(127)));
    ASSERT_EQ("9877", String::Format("{0:G8}", Int16(9877)));
    ASSERT_EQ("32767", String::Format("{0:G8}", Int16(32767)));
    ASSERT_EQ("-1", String::Format("{0:G8}", Int16(-1)));
    ASSERT_EQ("-32768", String::Format("{0:G8}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, G_Int32) {
    ASSERT_EQ("0", String::Format("{0:G}", Int32(0)));
    ASSERT_EQ("9877", String::Format("{0:G}", Int32(9877)));
    ASSERT_EQ("2147483647", String::Format("{0:G}", Int32(2147483647)));
    ASSERT_EQ("-1", String::Format("{0:G}", Int32(-1)));
    ASSERT_EQ("-148910", String::Format("{0:G}", Int32(-148910)));
    ASSERT_EQ("-2147483647", String::Format("{0:G}", Int32(-2147483647)));
  }
  
  TEST(NumericalFormatTest, G1_Int32) {
    ASSERT_EQ("0", String::Format("{0:G1}", Int32(0)));
    ASSERT_EQ("1E+04", String::Format("{0:G1}", Int32(9877)));
    ASSERT_EQ("2E+09", String::Format("{0:G1}", Int32(2147483647)));
    ASSERT_EQ("-1", String::Format("{0:G1}", Int32(-1)));
    ASSERT_EQ("-1E+05", String::Format("{0:G1}", Int32(-148910)));
    ASSERT_EQ("-2E+09", String::Format("{0:G1}", Int32(-2147483647)));
  }
  
  TEST(NumericalFormatTest, G2_Int32) {
    ASSERT_EQ("0", String::Format("{0:G2}", Int32(0)));
    ASSERT_EQ("9.9E+03", String::Format("{0:G2}", Int32(9877)));
    ASSERT_EQ("2.1E+09", String::Format("{0:G2}", Int32(2147483647)));
    ASSERT_EQ("-1", String::Format("{0:G2}", Int32(-1)));
    ASSERT_EQ("-1.5E+05", String::Format("{0:G2}", Int32(-148910)));
    ASSERT_EQ("-2.1E+09", String::Format("{0:G2}", Int32(-2147483647)));
  }
  
  TEST(NumericalFormatTest, G4_Int32) {
    ASSERT_EQ("0", String::Format("{0:G4}", Int32(0)));
    ASSERT_EQ("9877", String::Format("{0:G4}", Int32(9877)));
    ASSERT_EQ("2.147E+09", String::Format("{0:G4}", Int32(2147483647)));
    ASSERT_EQ("-1", String::Format("{0:G4}", Int32(-1)));
    ASSERT_EQ("-1.489E+05", String::Format("{0:G4}", Int32(-148910)));
    ASSERT_EQ("-2.147E+09", String::Format("{0:G4}", Int32(-2147483647)));
  }
  
  TEST(NumericalFormatTest, G8_Int32) {
    ASSERT_EQ("0", String::Format("{0:G8}", Int32(0)));
    ASSERT_EQ("9877", String::Format("{0:G8}", Int32(9877)));
    ASSERT_EQ("2.1474836E+09", String::Format("{0:G8}", Int32(2147483647)));
    ASSERT_EQ("-1", String::Format("{0:G8}", Int32(-1)));
    ASSERT_EQ("-148910", String::Format("{0:G8}", Int32(-148910)));
    ASSERT_EQ("-2.1474836E+09", String::Format("{0:G8}", Int32(-2147483647)));
  }
  
  TEST(NumericalFormatTest, G12_Int32) {
    ASSERT_EQ("0", String::Format("{0:G12}", Int32(0)));
    ASSERT_EQ("9877", String::Format("{0:G12}", Int32(9877)));
    ASSERT_EQ("2147483647", String::Format("{0:G12}", Int32(2147483647)));
    ASSERT_EQ("-1", String::Format("{0:G12}", Int32(-1)));
    ASSERT_EQ("-148910", String::Format("{0:G12}", Int32(-148910)));
    ASSERT_EQ("-2147483647", String::Format("{0:G12}", Int32(-2147483647)));
  }
  
  TEST(NumericalFormatTest, G_Int64) {
    ASSERT_EQ("1404454305138", String::Format("{0:G}", Int64(1404454305138)));
    ASSERT_EQ("-1", String::Format("{0:G}", Int64(-1)));
    ASSERT_EQ("-2147483647", String::Format("{0:G}", Int64(-2147483647)));
    ASSERT_EQ("-1404454305138", String::Format("{0:G}", Int64(-1404454305138)));
  }
  
  TEST(NumericalFormatTest, G1_Int64) {
    ASSERT_EQ("0", String::Format("{0:G1}", Int64(0)));
    ASSERT_EQ("2E+09", String::Format("{0:G1}", Int64(2147483647)));
    ASSERT_EQ("1E+12", String::Format("{0:G1}", Int64(1404454305138)));
    ASSERT_EQ("-1", String::Format("{0:G1}", Int64(-1)));
    ASSERT_EQ("-2E+09", String::Format("{0:G1}", Int64(-2147483647)));
    ASSERT_EQ("-1E+12", String::Format("{0:G1}", Int64(-1404454305138)));
  }
  
  TEST(NumericalFormatTest, G2_Int64) {
    ASSERT_EQ("0", String::Format("{0:G2}", Int64(0)));
    ASSERT_EQ("2.1E+09", String::Format("{0:G2}", Int64(2147483647)));
    ASSERT_EQ("1.4E+12", String::Format("{0:G2}", Int64(1404454305138)));
    ASSERT_EQ("-1", String::Format("{0:G2}", Int64(-1)));
    ASSERT_EQ("-2.1E+09", String::Format("{0:G2}", Int64(-2147483647)));
    ASSERT_EQ("-1.4E+12", String::Format("{0:G2}", Int64(-1404454305138)));
  }
  
  TEST(NumericalFormatTest, G8_Int64) {
    ASSERT_EQ("0", String::Format("{0:G8}", Int64(0)));
    ASSERT_EQ("2.1474836E+09", String::Format("{0:G8}", Int64(2147483647)));
    ASSERT_EQ("1.4044543E+12", String::Format("{0:G8}", Int64(1404454305138)));
    ASSERT_EQ("-1", String::Format("{0:G8}", Int64(-1)));
    ASSERT_EQ("-2.1474836E+09", String::Format("{0:G8}", Int64(-2147483647)));
    ASSERT_EQ("-1.4044543E+12", String::Format("{0:G8}", Int64(-1404454305138)));
  }
  
  TEST(NumericalFormatTest, G16_Int64) {
    ASSERT_EQ("0", String::Format("{0:G16}", Int64(0)));
    ASSERT_EQ("2147483647", String::Format("{0:G16}", Int64(2147483647)));
    ASSERT_EQ("1404454305138", String::Format("{0:G16}", Int64(1404454305138)));
    ASSERT_EQ("-1", String::Format("{0:G16}", Int64(-1)));
    ASSERT_EQ("-2147483647", String::Format("{0:G16}", Int64(-2147483647)));
    ASSERT_EQ("-1404454305138", String::Format("{0:G16}", Int64(-1404454305138)));
  }
  
  TEST(NumericalFormatTest, G25_Int64) {
    ASSERT_EQ("0", String::Format("{0:G25}", Int64(0)));
    ASSERT_EQ("2147483647", String::Format("{0:G25}", Int64(2147483647)));
    ASSERT_EQ("1404454305138", String::Format("{0:G25}", Int64(1404454305138)));
    ASSERT_EQ("-1", String::Format("{0:G25}", Int64(-1)));
    ASSERT_EQ("-2147483647", String::Format("{0:G25}", Int64(-2147483647)));
    ASSERT_EQ("-1404454305138", String::Format("{0:G25}", Int64(-1404454305138)));
  }
  
  TEST(NumericalFormatTest, G_Byte) {
    ASSERT_EQ("0", String::Format("{0:G}", Byte(0)));
    ASSERT_EQ("13", String::Format("{0:G}", Byte(13)));
    ASSERT_EQ("128", String::Format("{0:G}", Byte(128)));
    ASSERT_EQ("207", String::Format("{0:G}", Byte(207)));
    ASSERT_EQ("255", String::Format("{0:G}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, G1_Byte) {
    ASSERT_EQ("0", String::Format("{0:G1}", Byte(0)));
    ASSERT_EQ("1E+01", String::Format("{0:G1}", Byte(13)));
    ASSERT_EQ("1E+02", String::Format("{0:G1}", Byte(128)));
    ASSERT_EQ("2E+02", String::Format("{0:G1}", Byte(207)));
    ASSERT_EQ("3E+02", String::Format("{0:G1}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, G2_Byte) {
    ASSERT_EQ("0", String::Format("{0:G2}", Byte(0)));
    ASSERT_EQ("13", String::Format("{0:G2}", Byte(13)));
    ASSERT_EQ("1.3E+02", String::Format("{0:G2}", Byte(128)));
    ASSERT_EQ("2.1E+02", String::Format("{0:G2}", Byte(207)));
    ASSERT_EQ("2.6E+02", String::Format("{0:G2}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, G3_Byte) {
    ASSERT_EQ("0", String::Format("{0:G3}", Byte(0)));
    ASSERT_EQ("13", String::Format("{0:G3}", Byte(13)));
    ASSERT_EQ("128", String::Format("{0:G3}", Byte(128)));
    ASSERT_EQ("207", String::Format("{0:G3}", Byte(207)));
    ASSERT_EQ("255", String::Format("{0:G3}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, G4_Byte) {
    ASSERT_EQ("0", String::Format("{0:G4}", Byte(0)));
    ASSERT_EQ("13", String::Format("{0:G4}", Byte(13)));
    ASSERT_EQ("128", String::Format("{0:G4}", Byte(128)));
    ASSERT_EQ("207", String::Format("{0:G4}", Byte(207)));
    ASSERT_EQ("255", String::Format("{0:G4}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, G10_Byte) {
    ASSERT_EQ("0", String::Format("{0:G10}", Byte(0)));
    ASSERT_EQ("13", String::Format("{0:G10}", Byte(13)));
    ASSERT_EQ("128", String::Format("{0:G10}", Byte(128)));
    ASSERT_EQ("207", String::Format("{0:G10}", Byte(207)));
    ASSERT_EQ("255", String::Format("{0:G10}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, G_UInt16) {
    ASSERT_EQ("0", String::Format("{0:G}", UInt16(0)));
    ASSERT_EQ("5666", String::Format("{0:G}", UInt16(5666)));
    ASSERT_EQ("36712", String::Format("{0:G}", UInt16(36712)));
    ASSERT_EQ("65535", String::Format("{0:G}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, G1_UInt16) {
    ASSERT_EQ("0", String::Format("{0:G1}", UInt16(0)));
    ASSERT_EQ("6E+03", String::Format("{0:G1}", UInt16(5666)));
    ASSERT_EQ("4E+04", String::Format("{0:G1}", UInt16(36712)));
    ASSERT_EQ("7E+04", String::Format("{0:G1}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, G2_UInt16) {
    ASSERT_EQ("0", String::Format("{0:G2}", UInt16(0)));
    ASSERT_EQ("5.7E+03", String::Format("{0:G2}", UInt16(5666)));
    ASSERT_EQ("3.7E+04", String::Format("{0:G2}", UInt16(36712)));
    ASSERT_EQ("6.6E+04", String::Format("{0:G2}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, G3_UInt16) {
    ASSERT_EQ("0", String::Format("{0:G3}", UInt16(0)));
    ASSERT_EQ("5.67E+03", String::Format("{0:G3}", UInt16(5666)));
    ASSERT_EQ("3.67E+04", String::Format("{0:G3}", UInt16(36712)));
    ASSERT_EQ("6.55E+04", String::Format("{0:G3}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, G4_UInt16) {
    ASSERT_EQ("0", String::Format("{0:G4}", UInt16(0)));
    ASSERT_EQ("5666", String::Format("{0:G4}", UInt16(5666)));
    ASSERT_EQ("3.671E+04", String::Format("{0:G4}", UInt16(36712)));
    ASSERT_EQ("6.554E+04", String::Format("{0:G4}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, G10_UInt16) {
    ASSERT_EQ("0", String::Format("{0:G10}", UInt16(0)));
    ASSERT_EQ("5666", String::Format("{0:G10}", UInt16(5666)));
    ASSERT_EQ("36712", String::Format("{0:G10}", UInt16(36712)));
    ASSERT_EQ("65535", String::Format("{0:G10}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, G_UInt32) {
    ASSERT_EQ("0", String::Format("{0:G}", UInt32(0)));
    ASSERT_EQ("452", String::Format("{0:G}", UInt32(452)));
    ASSERT_EQ("78966", String::Format("{0:G}", UInt32(78966)));
    ASSERT_EQ("4294967295", String::Format("{0:G}", UInt32(4294967295u)));
  }
  
  TEST(NumericalFormatTest, G1_UInt32) {
    ASSERT_EQ("0", String::Format("{0:G1}", UInt32(0)));
    ASSERT_EQ("5E+02", String::Format("{0:G1}", UInt32(452)));
    ASSERT_EQ("8E+04", String::Format("{0:G1}", UInt32(78966)));
    ASSERT_EQ("4E+09", String::Format("{0:G1}", UInt32(4294967295u)));
  }
  
  TEST(NumericalFormatTest, G2_UInt32) {
    ASSERT_EQ("0", String::Format("{0:G2}", UInt32(0)));
    ASSERT_EQ("4.5E+02", String::Format("{0:G2}", UInt32(452)));
    ASSERT_EQ("7.9E+04", String::Format("{0:G2}", UInt32(78966)));
    ASSERT_EQ("4.3E+09", String::Format("{0:G2}", UInt32(4294967295u)));
  }
  
  TEST(NumericalFormatTest, G3_UInt32) {
    ASSERT_EQ("0", String::Format("{0:G3}", UInt32(0)));
    ASSERT_EQ("452", String::Format("{0:G3}", UInt32(452)));
    ASSERT_EQ("7.9E+04", String::Format("{0:G3}", UInt32(78966)));
    ASSERT_EQ("4.29E+09", String::Format("{0:G3}", UInt32(4294967295u)));
  }
  
  TEST(NumericalFormatTest, G4_UInt32) {
    ASSERT_EQ("0", String::Format("{0:G4}", UInt32(0)));
    ASSERT_EQ("452", String::Format("{0:G4}", UInt32(452)));
    ASSERT_EQ("7.897E+04", String::Format("{0:G4}", UInt32(78966)));
    ASSERT_EQ("4.295E+09", String::Format("{0:G4}", UInt32(4294967295u)));
  }
  
  TEST(NumericalFormatTest, G10_UInt32) {
    ASSERT_EQ("0", String::Format("{0:G10}", UInt32(0)));
    ASSERT_EQ("452", String::Format("{0:G10}", UInt32(452)));
    ASSERT_EQ("78966", String::Format("{0:G10}", UInt32(78966)));
    ASSERT_EQ("4294967295", String::Format("{0:G10}", UInt32(4294967295u)));
  }
  
  TEST(NumericalFormatTest, G_UInt64) {
    ASSERT_EQ("0", String::Format("{0:G}", UInt64(0)));
    ASSERT_EQ("452", String::Format("{0:G}", UInt64(452)));
    ASSERT_EQ("4294967295", String::Format("{0:G}", UInt64(4294967295u)));
    ASSERT_EQ("6544294967295", String::Format("{0:G}", UInt64(6544294967295u)));
  }
  
  TEST(NumericalFormatTest, G1_UInt64) {
    ASSERT_EQ("0", String::Format("{0:G1}", UInt64(0)));
    ASSERT_EQ("5E+02", String::Format("{0:G1}", UInt64(452)));
    ASSERT_EQ("4E+09", String::Format("{0:G1}", UInt64(4294967295u)));
    ASSERT_EQ("7E+12", String::Format("{0:G1}", UInt64(6544294967295u)));
  }
  
  TEST(NumericalFormatTest, G2_UInt64) {
    ASSERT_EQ("0", String::Format("{0:G2}", UInt64(0)));
    ASSERT_EQ("4.5E+02", String::Format("{0:G2}", UInt64(452)));
    ASSERT_EQ("4.3E+09", String::Format("{0:G2}", UInt64(4294967295u)));
    ASSERT_EQ("6.5E+12", String::Format("{0:G2}", UInt64(6544294967295u)));
  }
  
  TEST(NumericalFormatTest, G3_UInt64) {
    ASSERT_EQ("0", String::Format("{0:G3}", UInt64(0)));
    ASSERT_EQ("452", String::Format("{0:G3}", UInt64(452)));
    ASSERT_EQ("4.29E+09", String::Format("{0:G3}", UInt64(4294967295u)));
    ASSERT_EQ("6.54E+12", String::Format("{0:G3}", UInt64(6544294967295u)));
  }
  
  TEST(NumericalFormatTest, G4_UInt64) {
    ASSERT_EQ("0", String::Format("{0:G4}", UInt64(0)));
    ASSERT_EQ("452", String::Format("{0:G4}", UInt64(452)));
    ASSERT_EQ("4.295E+09", String::Format("{0:G4}", UInt64(4294967295u)));
    ASSERT_EQ("6.544E+12", String::Format("{0:G4}", UInt64(6544294967295u)));
  }
  
  TEST(NumericalFormatTest, G5_UInt64) {
    ASSERT_EQ("0", String::Format("{0:G5}", UInt64(0)));
    ASSERT_EQ("452", String::Format("{0:G5}", UInt64(452)));
    ASSERT_EQ("4.295E+09", String::Format("{0:G5}", UInt64(4294967295u)));
    ASSERT_EQ("6.5443E+12", String::Format("{0:G5}", UInt64(6544294967295u)));
  }
  
  TEST(NumericalFormatTest, G8_UInt64) {
    ASSERT_EQ("0", String::Format("{0:G8}", UInt64(0)));
    ASSERT_EQ("452", String::Format("{0:G8}", UInt64(452)));
    ASSERT_EQ("4.2949673E+09", String::Format("{0:G8}", UInt64(4294967295u)));
    ASSERT_EQ("6.544295E+12", String::Format("{0:G8}", UInt64(6544294967295u)));
  }
  
  TEST(NumericalFormatTest, G20_UInt64) {
    ASSERT_EQ("0", String::Format("{0:G20}", UInt64(0)));
    ASSERT_EQ("452", String::Format("{0:G20}", UInt64(452)));
    ASSERT_EQ("4294967295", String::Format("{0:G20}", UInt64(4294967295u)));
    ASSERT_EQ("6544294967295", String::Format("{0:G20}", UInt64(6544294967295u)));
  }
  
  TEST(NumericalFormatTest, G_Double) {
    ASSERT_EQ("0", String::Format("{0:G}", Double(0.0)));
    ASSERT_EQ("0.14", String::Format("{0:G}", Double(0.14)));
    ASSERT_EQ("1000", String::Format("{0:G}", Double(1000.0)));
    ASSERT_EQ("9874.000023", String::Format("{0:G}", Double(9874.000023)));
  }
  
  TEST(NumericalFormatTest, G1_Double) {
    ASSERT_EQ("0", String::Format("{0:G1}", Double(0.0)));
    ASSERT_EQ("0.1", String::Format("{0:G1}", Double(0.14)));
    ASSERT_EQ("1E+03", String::Format("{0:G1}", Double(1000.0)));
    ASSERT_EQ("1E+04", String::Format("{0:G1}", Double(9874.000023)));
  }
  
  TEST(NumericalFormatTest, G2_Double) {
    ASSERT_EQ("0", String::Format("{0:G2}", Double(0.0)));
    ASSERT_EQ("0.14", String::Format("{0:G2}", Double(0.14)));
    ASSERT_EQ("1E+03", String::Format("{0:G2}", Double(1000.0)));
    ASSERT_EQ("9.9E+03", String::Format("{0:G2}", Double(9874.000023)));
  }
  
  TEST(NumericalFormatTest, G3_Double) {
    ASSERT_EQ("0", String::Format("{0:G3}", Double(0.0)));
    ASSERT_EQ("0.14", String::Format("{0:G3}", Double(0.14)));
    ASSERT_EQ("1E+03", String::Format("{0:G3}", Double(1000.0)));
    ASSERT_EQ("9.87E+03", String::Format("{0:G3}", Double(9874.000023)));
  }
  
  TEST(NumericalFormatTest, G4_Double) {
    ASSERT_EQ("0", String::Format("{0:G4}", Double(0.0)));
    ASSERT_EQ("0.14", String::Format("{0:G4}", Double(0.14)));
    ASSERT_EQ("1000", String::Format("{0:G4}", Double(1000.0)));
    ASSERT_EQ("9874", String::Format("{0:G4}", Double(9874.000023)));
  }
  
  TEST(NumericalFormatTest, G5_Double) {
    ASSERT_EQ("0", String::Format("{0:G5}", Double(0.0)));
    ASSERT_EQ("0.14", String::Format("{0:G5}", Double(0.14)));
    ASSERT_EQ("1000", String::Format("{0:G5}", Double(1000.0)));
    ASSERT_EQ("9874", String::Format("{0:G5}", Double(9874.000023)));
  }
  
  TEST(NumericalFormatTest, G8_Double) {
    ASSERT_EQ("0", String::Format("{0:G8}", Double(0.0)));
    ASSERT_EQ("0.14", String::Format("{0:G8}", Double(0.14)));
    ASSERT_EQ("1000", String::Format("{0:G8}", Double(1000.0)));
    ASSERT_EQ("9874", String::Format("{0:G8}", Double(9874.000023)));
  }
  
  TEST(NumericalFormatTest, G16_Double) {
    ASSERT_EQ("0", String::Format("{0:G16}", Double(0.0)));
    ASSERT_EQ("0.14", String::Format("{0:G16}", Double(0.14)));
    ASSERT_EQ("1000", String::Format("{0:G16}", Double(1000.0)));
    ASSERT_EQ("9874.000023000001", String::Format("{0:G16}", Double(9874.000023)));
  }
  
  TEST(NumericalFormatTest, G_Single) {
    ASSERT_EQ("0", String::Format("{0:G}", Single(0.0f)));
    ASSERT_EQ("0.11", String::Format("{0:G}", Single(0.11f)));
    ASSERT_EQ("1000", String::Format("{0:G}", Single(1000.0f)));
    ASSERT_EQ("9874", String::Format("{0:G}", Single(9874.0f)));
  }
  
  TEST(NumericalFormatTest, G1_Single) {
    ASSERT_EQ("0", String::Format("{0:G1}", Single(0.0f)));
    ASSERT_EQ("0.1", String::Format("{0:G1}", Single(0.11f)));
    ASSERT_EQ("1E+03", String::Format("{0:G1}", Single(1000.0f)));
    ASSERT_EQ("1E+04", String::Format("{0:G1}", Single(9874.0f)));
  }
  
  TEST(NumericalFormatTest, G2_Single) {
    ASSERT_EQ("0", String::Format("{0:G2}", Single(0.0f)));
    ASSERT_EQ("0.11", String::Format("{0:G2}", Single(0.11f)));
    ASSERT_EQ("1E+03", String::Format("{0:G2}", Single(1000.0f)));
    ASSERT_EQ("9.9E+03", String::Format("{0:G2}", Single(9874.0f)));
  }
  
  TEST(NumericalFormatTest, G3_Single) {
    ASSERT_EQ("0", String::Format("{0:G3}", Single(0.0f)));
    ASSERT_EQ("0.11", String::Format("{0:G3}", Single(0.11f)));
    ASSERT_EQ("1E+03", String::Format("{0:G3}", Single(1000.0f)));
    ASSERT_EQ("9.87E+03", String::Format("{0:G3}", Single(9874.0f)));
  }
  
  TEST(NumericalFormatTest, G4_Single) {
    ASSERT_EQ("0", String::Format("{0:G4}", Single(0.0f)));
    ASSERT_EQ("0.11", String::Format("{0:G4}", Single(0.11f)));
    ASSERT_EQ("1000", String::Format("{0:G4}", Single(1000.0f)));
    ASSERT_EQ("9874", String::Format("{0:G4}", Single(9874.0f)));
  }
  
  TEST(NumericalFormatTest, G5_Single) {
    ASSERT_EQ("0", String::Format("{0:G5}", Single(0.0f)));
    ASSERT_EQ("0.11", String::Format("{0:G5}", Single(0.11f)));
    ASSERT_EQ("1000", String::Format("{0:G5}", Single(1000.0f)));
    ASSERT_EQ("9874", String::Format("{0:G5}", Single(9874.0f)));
  }
  
  TEST(NumericalFormatTest, G8_Single) {
    ASSERT_EQ("0", String::Format("{0:G8}", Single(0.0f)));
    ASSERT_EQ("0.11", String::Format("{0:G8}", Single(0.11f)));
    ASSERT_EQ("1000", String::Format("{0:G8}", Single(1000.0f)));
    ASSERT_EQ("9874", String::Format("{0:G8}", Single(9874.0f)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G_SByte) {
    ASSERT_EQ("0", String::Format("{0:G}", SByte(0)));
    ASSERT_EQ("12", String::Format("{0:G}", SByte(12)));
    ASSERT_EQ("98", String::Format("{0:G}", SByte(98)));
    ASSERT_EQ("127", String::Format("{0:G}", SByte(127)));
    ASSERT_EQ("-1", String::Format("{0:G}", SByte(-1)));
    ASSERT_EQ("-128", String::Format("{0:G}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G1_SByte) {
    ASSERT_EQ("0", String::Format("{0:G1}", SByte(0)));
    ASSERT_EQ("1E+01", String::Format("{0:G1}", SByte(12)));
    ASSERT_EQ("1E+02", String::Format("{0:G1}", SByte(98)));
    ASSERT_EQ("1E+02", String::Format("{0:G1}", SByte(127)));
    ASSERT_EQ("-1", String::Format("{0:G1}", SByte(-1)));
    ASSERT_EQ("-1E+02", String::Format("{0:G1}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G00_SByte) {
    ASSERT_EQ("0", String::Format("{0:G00}", SByte(0)));
    ASSERT_EQ("12", String::Format("{0:G00}", SByte(12)));
    ASSERT_EQ("98", String::Format("{0:G00}", SByte(98)));
    ASSERT_EQ("127", String::Format("{0:G00}", SByte(127)));
    ASSERT_EQ("-1", String::Format("{0:G00}", SByte(-1)));
    ASSERT_EQ("-128", String::Format("{0:G00}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G001_SByte) {
    ASSERT_EQ("0", String::Format("{0:G001}", SByte(0)));
    ASSERT_EQ("1E+01", String::Format("{0:G001}", SByte(12)));
    ASSERT_EQ("1E+02", String::Format("{0:G001}", SByte(98)));
    ASSERT_EQ("1E+02", String::Format("{0:G001}", SByte(127)));
    ASSERT_EQ("-1", String::Format("{0:G001}", SByte(-1)));
    ASSERT_EQ("-1E+02", String::Format("{0:G001}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G0000010_SByte) {
    ASSERT_EQ("0", String::Format("{0:G0000010}", SByte(0)));
    ASSERT_EQ("12", String::Format("{0:G0000010}", SByte(12)));
    ASSERT_EQ("98", String::Format("{0:G0000010}", SByte(98)));
    ASSERT_EQ("127", String::Format("{0:G0000010}", SByte(127)));
    ASSERT_EQ("-1", String::Format("{0:G0000010}", SByte(-1)));
    ASSERT_EQ("-128", String::Format("{0:G0000010}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G_Int16) {
    ASSERT_EQ("0", String::Format("{0:G}", Int16(0)));
    ASSERT_EQ("654", String::Format("{0:G}", Int16(654)));
    ASSERT_EQ("19881", String::Format("{0:G}", Int16(19881)));
    ASSERT_EQ("32767", String::Format("{0:G}", Int16(32767)));
    ASSERT_EQ("-1", String::Format("{0:G}", Int16(-1)));
    ASSERT_EQ("-32768", String::Format("{0:G}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G1_Int16) {
    ASSERT_EQ("0", String::Format("{0:G1}", Int16(0)));
    ASSERT_EQ("7E+02", String::Format("{0:G1}", Int16(654)));
    ASSERT_EQ("2E+04", String::Format("{0:G1}", Int16(19881)));
    ASSERT_EQ("3E+04", String::Format("{0:G1}", Int16(32767)));
    ASSERT_EQ("-1", String::Format("{0:G1}", Int16(-1)));
    ASSERT_EQ("-3E+04", String::Format("{0:G1}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G00_Int16) {
    ASSERT_EQ("0", String::Format("{0:G00}", Int16(0)));
    ASSERT_EQ("654", String::Format("{0:G00}", Int16(654)));
    ASSERT_EQ("19881", String::Format("{0:G00}", Int16(19881)));
    ASSERT_EQ("32767", String::Format("{0:G00}", Int16(32767)));
    ASSERT_EQ("-1", String::Format("{0:G00}", Int16(-1)));
    ASSERT_EQ("-32768", String::Format("{0:G00}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G001_Int16) {
    ASSERT_EQ("0", String::Format("{0:G001}", Int16(0)));
    ASSERT_EQ("7E+02", String::Format("{0:G001}", Int16(654)));
    ASSERT_EQ("2E+04", String::Format("{0:G001}", Int16(19881)));
    ASSERT_EQ("3E+04", String::Format("{0:G001}", Int16(32767)));
    ASSERT_EQ("-1", String::Format("{0:G001}", Int16(-1)));
    ASSERT_EQ("-3E+04", String::Format("{0:G001}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G0000010_Int16) {
    ASSERT_EQ("0", String::Format("{0:G0000010}", Int16(0)));
    ASSERT_EQ("654", String::Format("{0:G0000010}", Int16(654)));
    ASSERT_EQ("19881", String::Format("{0:G0000010}", Int16(19881)));
    ASSERT_EQ("32767", String::Format("{0:G0000010}", Int16(32767)));
    ASSERT_EQ("-1", String::Format("{0:G0000010}", Int16(-1)));
    ASSERT_EQ("-32768", String::Format("{0:G0000010}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G_Int32) {
    ASSERT_EQ("0", String::Format("{0:G}", Int32(0)));
    ASSERT_EQ("654123", String::Format("{0:G}", Int32(654123)));
    ASSERT_EQ("2147483647", String::Format("{0:G}", Int32::MaxValue));
    ASSERT_EQ("-1", String::Format("{0:G}", Int32(-1)));
    ASSERT_EQ("-654123", String::Format("{0:G}", Int32(-654123)));
    ASSERT_EQ("-2147483648", String::Format("{0:G}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G1_Int32) {
    ASSERT_EQ("0", String::Format("{0:G1}", Int32(0)));
    ASSERT_EQ("7E+05", String::Format("{0:G1}", Int32(654123)));
    ASSERT_EQ("2E+09", String::Format("{0:G1}", Int32::MaxValue));
    ASSERT_EQ("-1", String::Format("{0:G1}", Int32(-1)));
    ASSERT_EQ("-7E+05", String::Format("{0:G1}", Int32(-654123)));
    ASSERT_EQ("-2E+09", String::Format("{0:G1}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G00_Int32) {
    ASSERT_EQ("0", String::Format("{0:G00}", Int32(0)));
    ASSERT_EQ("654123", String::Format("{0:G00}", Int32(654123)));
    ASSERT_EQ("2147483647", String::Format("{0:G00}", Int32::MaxValue));
    ASSERT_EQ("-1", String::Format("{0:G00}", Int32(-1)));
    ASSERT_EQ("-654123", String::Format("{0:G00}", Int32(-654123)));
    ASSERT_EQ("-2147483648", String::Format("{0:G00}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G001_Int32) {
    ASSERT_EQ("0", String::Format("{0:G001}", Int32(0)));
    ASSERT_EQ("7E+05", String::Format("{0:G001}", Int32(654123)));
    ASSERT_EQ("2E+09", String::Format("{0:G001}", Int32::MaxValue));
    ASSERT_EQ("-1", String::Format("{0:G001}", Int32(-1)));
    ASSERT_EQ("-7E+05", String::Format("{0:G001}", Int32(-654123)));
    ASSERT_EQ("-2E+09", String::Format("{0:G001}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G0000010_Int32) {
    ASSERT_EQ("0", String::Format("{0:G0000010}", Int32(0)));
    ASSERT_EQ("654123", String::Format("{0:G0000010}", Int32(654123)));
    ASSERT_EQ("2147483647", String::Format("{0:G0000010}", Int32::MaxValue));
    ASSERT_EQ("-1", String::Format("{0:G0000010}", Int32(-1)));
    ASSERT_EQ("-654123", String::Format("{0:G0000010}", Int32(-654123)));
    ASSERT_EQ("-2147483648", String::Format("{0:G0000010}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G_Int64) {
    ASSERT_EQ("0", String::Format("{0:G}", Int64(0)));
    ASSERT_EQ("321456", String::Format("{0:G}", Int64(321456)));
    ASSERT_EQ("9223372036854775807", String::Format("{0:G}", Int64::MaxValue));
    ASSERT_EQ("-1", String::Format("{0:G}", Int64(-1)));
    ASSERT_EQ("-9223372036854775808", String::Format("{0:G}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G1_Int64) {
    ASSERT_EQ("0", String::Format("{0:G1}", Int64(0)));
    ASSERT_EQ("3E+05", String::Format("{0:G1}", Int64(321456)));
    ASSERT_EQ("9E+18", String::Format("{0:G1}", Int64::MaxValue));
    ASSERT_EQ("-1", String::Format("{0:G1}", Int64(-1)));
    ASSERT_EQ("-9E+18", String::Format("{0:G1}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G00_Int64) {
    ASSERT_EQ("0", String::Format("{0:G00}", Int64(0)));
    ASSERT_EQ("321456", String::Format("{0:G00}", Int64(321456)));
    ASSERT_EQ("9223372036854775807", String::Format("{0:G00}", Int64::MaxValue));
    ASSERT_EQ("-1", String::Format("{0:G00}", Int64(-1)));
    ASSERT_EQ("-9223372036854775808", String::Format("{0:G00}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G001_Int64) {
    ASSERT_EQ("0", String::Format("{0:G001}", Int64(0)));
    ASSERT_EQ("3E+05", String::Format("{0:G001}", Int64(321456)));
    ASSERT_EQ("9E+18", String::Format("{0:G001}", Int64::MaxValue));
    ASSERT_EQ("-1", String::Format("{0:G001}", Int64(-1)));
    ASSERT_EQ("-9E+18", String::Format("{0:G001}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G0000010_Int64) {
    ASSERT_EQ("0", String::Format("{0:G0000010}", Int64(0)));
    ASSERT_EQ("321456", String::Format("{0:G0000010}", Int64(321456)));
    ASSERT_EQ("9.223372037E+18", String::Format("{0:G0000010}", Int64::MaxValue));
    ASSERT_EQ("-1", String::Format("{0:G0000010}", Int64(-1)));
    ASSERT_EQ("-9.223372037E+18", String::Format("{0:G0000010}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G_Byte) {
    ASSERT_EQ("0", String::Format("{0:G}", Byte(0)));
    ASSERT_EQ("146", String::Format("{0:G}", Byte(146)));
    ASSERT_EQ("255", String::Format("{0:G}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G1_Byte) {
    ASSERT_EQ("0", String::Format("{0:G1}", Byte(0)));
    ASSERT_EQ("1E+02", String::Format("{0:G1}", Byte(146)));
    ASSERT_EQ("3E+02", String::Format("{0:G1}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G00_Byte) {
    ASSERT_EQ("0", String::Format("{0:G00}", Byte(0)));
    ASSERT_EQ("146", String::Format("{0:G00}", Byte(146)));
    ASSERT_EQ("255", String::Format("{0:G00}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G001_Byte) {
    ASSERT_EQ("0", String::Format("{0:G001}", Byte(0)));
    ASSERT_EQ("1E+02", String::Format("{0:G001}", Byte(146)));
    ASSERT_EQ("3E+02", String::Format("{0:G001}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G0000010_Byte) {
    ASSERT_EQ("0", String::Format("{0:G0000010}", Byte(0)));
    ASSERT_EQ("146", String::Format("{0:G0000010}", Byte(146)));
    ASSERT_EQ("255", String::Format("{0:G0000010}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G_UInt16) {
    ASSERT_EQ("0", String::Format("{0:G}", UInt16(0)));
    ASSERT_EQ("2146", String::Format("{0:G}", UInt16(2146)));
    ASSERT_EQ("65535", String::Format("{0:G}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G1_UInt16) {
    ASSERT_EQ("0", String::Format("{0:G1}", UInt16(0)));
    ASSERT_EQ("2E+03", String::Format("{0:G1}", UInt16(2146)));
    ASSERT_EQ("7E+04", String::Format("{0:G1}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G00_UInt16) {
    ASSERT_EQ("0", String::Format("{0:G00}", UInt16(0)));
    ASSERT_EQ("2146", String::Format("{0:G00}", UInt16(2146)));
    ASSERT_EQ("65535", String::Format("{0:G00}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G001_UInt16) {
    ASSERT_EQ("0", String::Format("{0:G001}", UInt16(0)));
    ASSERT_EQ("2E+03", String::Format("{0:G001}", UInt16(2146)));
    ASSERT_EQ("7E+04", String::Format("{0:G001}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G0000010_UInt16) {
    ASSERT_EQ("0", String::Format("{0:G0000010}", UInt16(0)));
    ASSERT_EQ("2146", String::Format("{0:G0000010}", UInt16(2146)));
    ASSERT_EQ("65535", String::Format("{0:G0000010}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G_UInt32) {
    ASSERT_EQ("0", String::Format("{0:G}", UInt32(0)));
    ASSERT_EQ("21456", String::Format("{0:G}", UInt32(21456)));
    ASSERT_EQ("4294967295", String::Format("{0:G}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G1_UInt32) {
    ASSERT_EQ("0", String::Format("{0:G1}", UInt32(0)));
    ASSERT_EQ("2E+04", String::Format("{0:G1}", UInt32(21456)));
    ASSERT_EQ("4E+09", String::Format("{0:G1}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G00_UInt32) {
    ASSERT_EQ("0", String::Format("{0:G00}", UInt32(0)));
    ASSERT_EQ("21456", String::Format("{0:G00}", UInt32(21456)));
    ASSERT_EQ("4294967295", String::Format("{0:G00}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G001_UInt32) {
    ASSERT_EQ("0", String::Format("{0:G001}", UInt32(0)));
    ASSERT_EQ("2E+04", String::Format("{0:G001}", UInt32(21456)));
    ASSERT_EQ("4E+09", String::Format("{0:G001}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G0000010_UInt32) {
    ASSERT_EQ("0", String::Format("{0:G0000010}", UInt32(0)));
    ASSERT_EQ("21456", String::Format("{0:G0000010}", UInt32(21456)));
    ASSERT_EQ("4294967295", String::Format("{0:G0000010}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G_UInt64) {
    ASSERT_EQ("0", String::Format("{0:G}", UInt64(0)));
    ASSERT_EQ("214456", String::Format("{0:G}", UInt64(214456)));
    ASSERT_EQ("18446744073709551615", String::Format("{0:G}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G1_UInt64) {
    ASSERT_EQ("0", String::Format("{0:G1}", UInt64(0)));
    ASSERT_EQ("2E+05", String::Format("{0:G1}", UInt64(214456)));
    ASSERT_EQ("2E+19", String::Format("{0:G1}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G00_UInt64) {
    ASSERT_EQ("0", String::Format("{0:G00}", UInt64(0)));
    ASSERT_EQ("214456", String::Format("{0:G00}", UInt64(214456)));
    ASSERT_EQ("18446744073709551615", String::Format("{0:G00}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G001_UInt64) {
    ASSERT_EQ("0", String::Format("{0:G001}", UInt64(0)));
    ASSERT_EQ("2E+05", String::Format("{0:G001}", UInt64(214456)));
    ASSERT_EQ("2E+19", String::Format("{0:G001}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, ParsePrecision_G0000010_UInt64) {
    ASSERT_EQ("0", String::Format("{0:G0000010}", UInt64(0)));
    ASSERT_EQ("214456", String::Format("{0:G0000010}", UInt64(214456)));
    ASSERT_EQ("1.844674407E+19", String::Format("{0:G0000010}", UInt64::MaxValue));
  }
}

