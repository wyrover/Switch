#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Collections::Generic;

namespace {
  
  TEST(NumericalFormatTest, N_SByte) {
    ASSERT_EQ("0.00", String::Format("{0:N}", SByte(0)));
    ASSERT_EQ("17.00", String::Format("{0:N}", SByte(17)));
    ASSERT_EQ("108.00", String::Format("{0:N}", SByte(108)));
    ASSERT_EQ("127.00", String::Format("{0:N}", SByte(127)));
    ASSERT_EQ("-1.00", String::Format("{0:N}", SByte(-1)));
    ASSERT_EQ("-128.00", String::Format("{0:N}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, N0_SByte) {
    ASSERT_EQ("0", String::Format("{0:N0}", SByte(0)));
    ASSERT_EQ("17", String::Format("{0:N0}", SByte(17)));
    ASSERT_EQ("108", String::Format("{0:N0}", SByte(108)));
    ASSERT_EQ("127", String::Format("{0:N0}", SByte(127)));
    ASSERT_EQ("-1", String::Format("{0:N0}", SByte(-1)));
    ASSERT_EQ("-128", String::Format("{0:N0}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, N1_SByte) {
    ASSERT_EQ("0.0", String::Format("{0:N1}", SByte(0)));
    ASSERT_EQ("17.0", String::Format("{0:N1}", SByte(17)));
    ASSERT_EQ("108.0", String::Format("{0:N1}", SByte(108)));
    ASSERT_EQ("127.0", String::Format("{0:N1}", SByte(127)));
    ASSERT_EQ("-1.0", String::Format("{0:N1}", SByte(-1)));
    ASSERT_EQ("-128.0", String::Format("{0:N1}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, N2_SByte) {
    ASSERT_EQ("0.00", String::Format("{0:N2}", SByte(0)));
    ASSERT_EQ("17.00", String::Format("{0:N2}", SByte(17)));
    ASSERT_EQ("108.00", String::Format("{0:N2}", SByte(108)));
    ASSERT_EQ("127.00", String::Format("{0:N2}", SByte(127)));
    ASSERT_EQ("-1.00", String::Format("{0:N2}", SByte(-1)));
    ASSERT_EQ("-128.00", String::Format("{0:N2}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, N8_SByte) {
    ASSERT_EQ("0.00000000", String::Format("{0:N8}", SByte(0)));
    ASSERT_EQ("17.00000000", String::Format("{0:N8}", SByte(17)));
    ASSERT_EQ("108.00000000", String::Format("{0:N8}", SByte(108)));
    ASSERT_EQ("127.00000000", String::Format("{0:N8}", SByte(127)));
    ASSERT_EQ("-1.00000000", String::Format("{0:N8}", SByte(-1)));
    ASSERT_EQ("-128.00000000", String::Format("{0:N8}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, N_Int16) {
    ASSERT_EQ("0.00", String::Format("{0:N}", Int16(0)));
    ASSERT_EQ("17.00", String::Format("{0:N}", Int16(17)));
    ASSERT_EQ("16,789.00", String::Format("{0:N}", Int16(16789)));
    ASSERT_EQ("32,767.00", String::Format("{0:N}", Int16(32767)));
    ASSERT_EQ("-1.00", String::Format("{0:N}", Int16(-1)));
    ASSERT_EQ("-32,768.00", String::Format("{0:N}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, N0_Int16) {
    ASSERT_EQ("0", String::Format("{0:N0}", Int16(0)));
    ASSERT_EQ("17", String::Format("{0:N0}", Int16(17)));
    ASSERT_EQ("16,789", String::Format("{0:N0}", Int16(16789)));
    ASSERT_EQ("32,767", String::Format("{0:N0}", Int16(32767)));
    ASSERT_EQ("-1", String::Format("{0:N0}", Int16(-1)));
    ASSERT_EQ("-32,768", String::Format("{0:N0}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, N1_Int16) {
    ASSERT_EQ("0.0", String::Format("{0:N1}", Int16(0)));
    ASSERT_EQ("17.0", String::Format("{0:N1}", Int16(17)));
    ASSERT_EQ("16,789.0", String::Format("{0:N1}", Int16(16789)));
    ASSERT_EQ("32,767.0", String::Format("{0:N1}", Int16(32767)));
    ASSERT_EQ("-1.0", String::Format("{0:N1}", Int16(-1)));
    ASSERT_EQ("-32,768.0", String::Format("{0:N1}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, N2_Int16) {
    ASSERT_EQ("0.00", String::Format("{0:N2}", Int16(0)));
    ASSERT_EQ("17.00", String::Format("{0:N2}", Int16(17)));
    ASSERT_EQ("16,789.00", String::Format("{0:N2}", Int16(16789)));
    ASSERT_EQ("32,767.00", String::Format("{0:N2}", Int16(32767)));
    ASSERT_EQ("-1.00", String::Format("{0:N2}", Int16(-1)));
    ASSERT_EQ("-32,768.00", String::Format("{0:N2}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, N8_Int16) {
    ASSERT_EQ("0.00000000", String::Format("{0:N8}", Int16(0)));
    ASSERT_EQ("17.00000000", String::Format("{0:N8}", Int16(17)));
    ASSERT_EQ("16,789.00000000", String::Format("{0:N8}", Int16(16789)));
    ASSERT_EQ("32,767.00000000", String::Format("{0:N8}", Int16(32767)));
    ASSERT_EQ("-1.00000000", String::Format("{0:N8}", Int16(-1)));
    ASSERT_EQ("-32,768.00000000", String::Format("{0:N8}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, N_Int32) {
    ASSERT_EQ("0.00", String::Format("{0:N}", Int32(0)));
    ASSERT_EQ("1,751.00", String::Format("{0:N}", Int32(1751)));
    ASSERT_EQ("654,789.00", String::Format("{0:N}", Int32(654789)));
    ASSERT_EQ("2,147,483,647.00", String::Format("{0:N}", Int32(2147483647)));
    ASSERT_EQ("-1.00", String::Format("{0:N}", Int32(-1)));
    ASSERT_EQ("-2,147,483,648.00", String::Format("{0:N}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, N0_Int32) {
    ASSERT_EQ("0", String::Format("{0:N0}", Int32(0)));
    ASSERT_EQ("1,751", String::Format("{0:N0}", Int32(1751)));
    ASSERT_EQ("654,789", String::Format("{0:N0}", Int32(654789)));
    ASSERT_EQ("2,147,483,647", String::Format("{0:N0}", Int32(2147483647)));
    ASSERT_EQ("-1", String::Format("{0:N0}", Int32(-1)));
    ASSERT_EQ("-2,147,483,648", String::Format("{0:N0}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, N1_Int32) {
    ASSERT_EQ("0.0", String::Format("{0:N1}", Int32(0)));
    ASSERT_EQ("1,751.0", String::Format("{0:N1}", Int32(1751)));
    ASSERT_EQ("654,789.0", String::Format("{0:N1}", Int32(654789)));
    ASSERT_EQ("2,147,483,647.0", String::Format("{0:N1}", Int32(2147483647)));
    ASSERT_EQ("-1.0", String::Format("{0:N1}", Int32(-1)));
    ASSERT_EQ("-2,147,483,648.0", String::Format("{0:N1}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, N2_Int32) {
    ASSERT_EQ("0.00", String::Format("{0:N2}", Int32(0)));
    ASSERT_EQ("1,751.00", String::Format("{0:N2}", Int32(1751)));
    ASSERT_EQ("654,789.00", String::Format("{0:N2}", Int32(654789)));
    ASSERT_EQ("2,147,483,647.00", String::Format("{0:N2}", Int32(2147483647)));
    ASSERT_EQ("-1.00", String::Format("{0:N2}", Int32(-1)));
    ASSERT_EQ("-2,147,483,648.00", String::Format("{0:N2}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, N8_Int32) {
    ASSERT_EQ("0.00000000", String::Format("{0:N8}", Int32(0)));
    ASSERT_EQ("1,751.00000000", String::Format("{0:N8}", Int32(1751)));
    ASSERT_EQ("654,789.00000000", String::Format("{0:N8}", Int32(654789)));
    ASSERT_EQ("2,147,483,647.00000000", String::Format("{0:N8}", Int32(2147483647)));
    ASSERT_EQ("-1.00000000", String::Format("{0:N8}", Int32(-1)));
    ASSERT_EQ("-2,147,483,648.00000000", String::Format("{0:N8}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, N_Int64) {
    ASSERT_EQ("0.00", String::Format("{0:N}", Int64(0)));
    ASSERT_EQ("1,751,123.00", String::Format("{0:N}", Int64(1751123)));
    ASSERT_EQ("654,789,321.00", String::Format("{0:N}", Int64(654789321)));
    ASSERT_EQ("9,223,372,036,854,775,807.00", String::Format("{0:N}", Int64::MaxValue));
    ASSERT_EQ("-1.00", String::Format("{0:N}", Int64(-1)));
    ASSERT_EQ("-9,223,372,036,854,775,808.00", String::Format("{0:N}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, N0_Int64) {
    ASSERT_EQ("0", String::Format("{0:N0}", Int64(0)));
    ASSERT_EQ("1,751,123", String::Format("{0:N0}", Int64(1751123)));
    ASSERT_EQ("654,789,321", String::Format("{0:N0}", Int64(654789321)));
    ASSERT_EQ("9,223,372,036,854,775,807", String::Format("{0:N0}", Int64::MaxValue));
    ASSERT_EQ("-1", String::Format("{0:N0}", Int64(-1)));
    ASSERT_EQ("-9,223,372,036,854,775,808", String::Format("{0:N0}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, N1_Int64) {
    ASSERT_EQ("0.0", String::Format("{0:N1}", Int64(0)));
    ASSERT_EQ("1,751,123.0", String::Format("{0:N1}", Int64(1751123)));
    ASSERT_EQ("654,789,321.0", String::Format("{0:N1}", Int64(654789321)));
    ASSERT_EQ("9,223,372,036,854,775,807.0", String::Format("{0:N1}", Int64::MaxValue));
    ASSERT_EQ("-1.0", String::Format("{0:N1}", Int64(-1)));
    ASSERT_EQ("-9,223,372,036,854,775,808.0", String::Format("{0:N1}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, N2_Int64) {
    ASSERT_EQ("0.00", String::Format("{0:N2}", Int64(0)));
    ASSERT_EQ("1,751,123.00", String::Format("{0:N2}", Int64(1751123)));
    ASSERT_EQ("654,789,321.00", String::Format("{0:N2}", Int64(654789321)));
    ASSERT_EQ("9,223,372,036,854,775,807.00", String::Format("{0:N2}", Int64::MaxValue));
    ASSERT_EQ("-1.00", String::Format("{0:N2}", Int64(-1)));
    ASSERT_EQ("-9,223,372,036,854,775,808.00", String::Format("{0:N2}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, N8_Int64) {
    ASSERT_EQ("0.00000000", String::Format("{0:N8}", Int64(0)));
    ASSERT_EQ("1,751,123.00000000", String::Format("{0:N8}", Int64(1751123)));
    ASSERT_EQ("654,789,321.00000000", String::Format("{0:N8}", Int64(654789321)));
    ASSERT_EQ("9,223,372,036,854,775,807.00000000", String::Format("{0:N8}", Int64::MaxValue));
    ASSERT_EQ("-1.00000000", String::Format("{0:N8}", Int64(-1)));
    ASSERT_EQ("-9,223,372,036,854,775,808.00000000", String::Format("{0:N8}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, N_Byte) {
    ASSERT_EQ("0.00", String::Format("{0:N}", Byte(0)));
    ASSERT_EQ("22.00", String::Format("{0:N}", Byte(22)));
    ASSERT_EQ("121.00", String::Format("{0:N}", Byte(121)));
    ASSERT_EQ("255.00", String::Format("{0:N}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, N0_Byte) {
    ASSERT_EQ("0", String::Format("{0:N0}", Byte(0)));
    ASSERT_EQ("22", String::Format("{0:N0}", Byte(22)));
    ASSERT_EQ("121", String::Format("{0:N0}", Byte(121)));
    ASSERT_EQ("255", String::Format("{0:N0}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, N1_Byte) {
    ASSERT_EQ("0.0", String::Format("{0:N1}", Byte(0)));
    ASSERT_EQ("22.0", String::Format("{0:N1}", Byte(22)));
    ASSERT_EQ("121.0", String::Format("{0:N1}", Byte(121)));
    ASSERT_EQ("255.0", String::Format("{0:N1}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, N2_Byte) {
    ASSERT_EQ("0.00", String::Format("{0:N2}", Byte(0)));
    ASSERT_EQ("22.00", String::Format("{0:N2}", Byte(22)));
    ASSERT_EQ("121.00", String::Format("{0:N2}", Byte(121)));
    ASSERT_EQ("255.00", String::Format("{0:N2}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, N8_Byte) {
    ASSERT_EQ("0.00000000", String::Format("{0:N8}", Byte(0)));
    ASSERT_EQ("22.00000000", String::Format("{0:N8}", Byte(22)));
    ASSERT_EQ("121.00000000", String::Format("{0:N8}", Byte(121)));
    ASSERT_EQ("255.00000000", String::Format("{0:N8}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, N_UInt16) {
    ASSERT_EQ("0.00", String::Format("{0:N}", UInt16(0)));
    ASSERT_EQ("175.00", String::Format("{0:N}", UInt16(175)));
    ASSERT_EQ("45,047.00", String::Format("{0:N}", UInt16(45047)));
    ASSERT_EQ("65,535.00", String::Format("{0:N}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, N0_UInt16) {
    ASSERT_EQ("0", String::Format("{0:N0}", UInt16(0)));
    ASSERT_EQ("175", String::Format("{0:N0}", UInt16(175)));
    ASSERT_EQ("45,047", String::Format("{0:N0}", UInt16(45047)));
    ASSERT_EQ("65,535", String::Format("{0:N0}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, N1_UInt16) {
    ASSERT_EQ("0.0", String::Format("{0:N1}", UInt16(0)));
    ASSERT_EQ("175.0", String::Format("{0:N1}", UInt16(175)));
    ASSERT_EQ("45,047.0", String::Format("{0:N1}", UInt16(45047)));
    ASSERT_EQ("65,535.0", String::Format("{0:N1}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, N2_UInt16) {
    ASSERT_EQ("0.00", String::Format("{0:N2}", UInt16(0)));
    ASSERT_EQ("175.00", String::Format("{0:N2}", UInt16(175)));
    ASSERT_EQ("45,047.00", String::Format("{0:N2}", UInt16(45047)));
    ASSERT_EQ("65,535.00", String::Format("{0:N2}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, N8_UInt16) {
    ASSERT_EQ("0.00000000", String::Format("{0:N8}", UInt16(0)));
    ASSERT_EQ("175.00000000", String::Format("{0:N8}", UInt16(175)));
    ASSERT_EQ("45,047.00000000", String::Format("{0:N8}", UInt16(45047)));
    ASSERT_EQ("65,535.00000000", String::Format("{0:N8}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, N_UInt32) {
    ASSERT_EQ("0.00", String::Format("{0:N}", UInt32(0)));
    ASSERT_EQ("1,751.00", String::Format("{0:N}", UInt32(1751)));
    ASSERT_EQ("654,789.00", String::Format("{0:N}", UInt32(654789)));
    ASSERT_EQ("4,294,967,295.00", String::Format("{0:N}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, N0_UInt32) {
    ASSERT_EQ("0", String::Format("{0:N0}", UInt32(0)));
    ASSERT_EQ("1,751", String::Format("{0:N0}", UInt32(1751)));
    ASSERT_EQ("654,789", String::Format("{0:N0}", UInt32(654789)));
    ASSERT_EQ("4,294,967,295", String::Format("{0:N0}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, N1_UInt32) {
    ASSERT_EQ("0.0", String::Format("{0:N1}", UInt32(0)));
    ASSERT_EQ("1,751.0", String::Format("{0:N1}", UInt32(1751)));
    ASSERT_EQ("654,789.0", String::Format("{0:N1}", UInt32(654789)));
    ASSERT_EQ("4,294,967,295.0", String::Format("{0:N1}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, N2_UInt32) {
    ASSERT_EQ("0.00", String::Format("{0:N2}", UInt32(0)));
    ASSERT_EQ("1,751.00", String::Format("{0:N2}", UInt32(1751)));
    ASSERT_EQ("654,789.00", String::Format("{0:N2}", UInt32(654789)));
    ASSERT_EQ("4,294,967,295.00", String::Format("{0:N2}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, N8_UInt32) {
    ASSERT_EQ("0.00000000", String::Format("{0:N8}", UInt32(0)));
    ASSERT_EQ("1,751.00000000", String::Format("{0:N8}", UInt32(1751)));
    ASSERT_EQ("654,789.00000000", String::Format("{0:N8}", UInt32(654789)));
    ASSERT_EQ("4,294,967,295.00000000", String::Format("{0:N8}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, N_UInt64) {
    ASSERT_EQ("0.00", String::Format("{0:N}", UInt64(0)));
    ASSERT_EQ("1,751,123.00", String::Format("{0:N}", UInt64(1751123)));
    ASSERT_EQ("654,789,321.00", String::Format("{0:N}", UInt64(654789321)));
    ASSERT_EQ("18,446,744,073,709,551,615.00", String::Format("{0:N}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, N0_UInt64) {
    ASSERT_EQ("0", String::Format("{0:N0}", UInt64(0)));
    ASSERT_EQ("1,751,123", String::Format("{0:N0}", UInt64(1751123)));
    ASSERT_EQ("654,789,321", String::Format("{0:N0}", UInt64(654789321)));
    ASSERT_EQ("18,446,744,073,709,551,615", String::Format("{0:N0}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, N1_UInt64) {
    ASSERT_EQ("0.0", String::Format("{0:N1}", UInt64(0)));
    ASSERT_EQ("1,751,123.0", String::Format("{0:N1}", UInt64(1751123)));
    ASSERT_EQ("654,789,321.0", String::Format("{0:N1}", UInt64(654789321)));
    ASSERT_EQ("18,446,744,073,709,551,615.0", String::Format("{0:N1}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, N2_UInt64) {
    ASSERT_EQ("0.00", String::Format("{0:N2}", UInt64(0)));
    ASSERT_EQ("1,751,123.00", String::Format("{0:N2}", UInt64(1751123)));
    ASSERT_EQ("654,789,321.00", String::Format("{0:N2}", UInt64(654789321)));
    ASSERT_EQ("18,446,744,073,709,551,615.00", String::Format("{0:N2}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, N8_UInt64) {
    ASSERT_EQ("0.00000000", String::Format("{0:N8}", UInt64(0)));
    ASSERT_EQ("1,751,123.00000000", String::Format("{0:N8}", UInt64(1751123)));
    ASSERT_EQ("654,789,321.00000000", String::Format("{0:N8}", UInt64(654789321)));
    ASSERT_EQ("18,446,744,073,709,551,615.00000000", String::Format("{0:N8}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, N_Double) {
    ASSERT_EQ("0.00", String::Format("{0:N}", Double(0)));
    ASSERT_EQ("11.20", String::Format("{0:N}", Double(11.197)));
    ASSERT_EQ("10,000.00", String::Format("{0:N}", Double(9999.99991)));
    ASSERT_EQ("-0.90", String::Format("{0:N}", Double(-0.9)));
    ASSERT_EQ("-100.00", String::Format("{0:N}", Double(-100.0001)));
    ASSERT_EQ("-321.00", String::Format("{0:N}", Double(-321.0000999)));
  }
  
  TEST(NumericalFormatTest, N0_Double) {
    ASSERT_EQ("0", String::Format("{0:N0}", Double(0)));
    ASSERT_EQ("11", String::Format("{0:N0}", Double(11.197)));
    ASSERT_EQ("10,000", String::Format("{0:N0}", Double(9999.99991)));
    ASSERT_EQ("-1", String::Format("{0:N0}", Double(-0.9)));
    ASSERT_EQ("-100", String::Format("{0:N0}", Double(-100.0001)));
    ASSERT_EQ("-321", String::Format("{0:N0}", Double(-321.0000999)));
  }
  
  TEST(NumericalFormatTest, N1_Double) {
    ASSERT_EQ("0.0", String::Format("{0:N1}", Double(0)));
    ASSERT_EQ("11.2", String::Format("{0:N1}", Double(11.197)));
    ASSERT_EQ("10,000.0", String::Format("{0:N1}", Double(9999.99991)));
    ASSERT_EQ("-0.9", String::Format("{0:N1}", Double(-0.9)));
    ASSERT_EQ("-100.0", String::Format("{0:N1}", Double(-100.0001)));
    ASSERT_EQ("-321.0", String::Format("{0:N1}", Double(-321.0000999)));
  }
  
  TEST(NumericalFormatTest, N2_Double) {
    ASSERT_EQ("0.00", String::Format("{0:N2}", Double(0)));
    ASSERT_EQ("11.20", String::Format("{0:N2}", Double(11.197)));
    ASSERT_EQ("10,000.00", String::Format("{0:N2}", Double(9999.99991)));
    ASSERT_EQ("-0.90", String::Format("{0:N2}", Double(-0.9)));
    ASSERT_EQ("-100.00", String::Format("{0:N2}", Double(-100.0001)));
    ASSERT_EQ("-321.00", String::Format("{0:N2}", Double(-321.0000999)));
  }
  
  TEST(NumericalFormatTest, N8_Double) {
    ASSERT_EQ("0.00000000", String::Format("{0:N8}", Double(0)));
    ASSERT_EQ("11.19700000", String::Format("{0:N8}", Double(11.197)));
    ASSERT_EQ("9,999.99991000", String::Format("{0:N8}", Double(9999.99991)));
    ASSERT_EQ("-0.90000000", String::Format("{0:N8}", Double(-0.9)));
    ASSERT_EQ("-100.00010000", String::Format("{0:N8}", Double(-100.0001)));
    ASSERT_EQ("-321.00009990", String::Format("{0:N8}", Double(-321.0000999)));
  }
  
  TEST(NumericalFormatTest, N_Single) {
    ASSERT_EQ("0.00", String::Format("{0:N}", Single(0.0f)));
    ASSERT_EQ("11.20", String::Format("{0:N}", Single(11.197f)));
    ASSERT_EQ("10,000.00", String::Format("{0:N}", Single(10000.0f)));
    ASSERT_EQ("-0.90", String::Format("{0:N}", Single(-0.9f)));
    ASSERT_EQ("-100.00", String::Format("{0:N}", Single(-100.0001f)));
    ASSERT_EQ("-321.00", String::Format("{0:N}", Single(-321.0001f)));
  }
  
  TEST(NumericalFormatTest, N0_Single) {
    ASSERT_EQ("0", String::Format("{0:N0}", Single(0.0f)));
    ASSERT_EQ("11", String::Format("{0:N0}", Single(11.197f)));
    ASSERT_EQ("10,000", String::Format("{0:N0}", Single(10000.0f)));
    ASSERT_EQ("-1", String::Format("{0:N0}", Single(-0.9f)));
    ASSERT_EQ("-100", String::Format("{0:N0}", Single(-100.0001f)));
    ASSERT_EQ("-321", String::Format("{0:N0}", Single(-321.0001f)));
  }
  
  TEST(NumericalFormatTest, N1_Single) {
    ASSERT_EQ("0.0", String::Format("{0:N1}", Single(0.0f)));
    ASSERT_EQ("11.2", String::Format("{0:N1}", Single(11.197f)));
    ASSERT_EQ("10,000.0", String::Format("{0:N1}", Single(10000.0f)));
    ASSERT_EQ("-0.9", String::Format("{0:N1}", Single(-0.9f)));
    ASSERT_EQ("-100.0", String::Format("{0:N1}", Single(-100.0001f)));
    ASSERT_EQ("-321.0", String::Format("{0:N1}", Single(-321.0001f)));
  }
  
  TEST(NumericalFormatTest, N2_Single) {
    ASSERT_EQ("0.00", String::Format("{0:N2}", Single(0.0f)));
    ASSERT_EQ("11.20", String::Format("{0:N2}", Single(11.197f)));
    ASSERT_EQ("10,000.00", String::Format("{0:N2}", Single(10000.0f)));
    ASSERT_EQ("-0.90", String::Format("{0:N2}", Single(-0.9f)));
    ASSERT_EQ("-100.00", String::Format("{0:N2}", Single(-100.0001f)));
    ASSERT_EQ("-321.00", String::Format("{0:N2}", Single(-321.0001f)));
  }
  
  TEST(NumericalFormatTest, N_OverflowTest) {
    ASSERT_EQ("-9,223,372,036,854,775,808.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
              String::Format("{0:N99}", Int64::MinValue));
    ASSERT_EQ("9,223,372,036,854,775,807.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
              String::Format("{0:N99}", Int64(9223372036854775807)));
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
