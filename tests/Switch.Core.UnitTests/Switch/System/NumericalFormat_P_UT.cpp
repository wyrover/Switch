#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Collections::Generic;

namespace {

  TEST(NumericalFormatTest, P_SByte) {
    ASSERT_EQ("0.00 %", String::Format("{0:P}", SByte(0)));
    ASSERT_EQ("500.00 %", String::Format("{0:P}", SByte(5)));
    ASSERT_EQ("7,100.00 %", String::Format("{0:P}", SByte(71)));
    ASSERT_EQ("12,700.00 %", String::Format("{0:P}", SByte(127)));
    ASSERT_EQ("-100.00 %", String::Format("{0:P}", SByte(-1)));
    ASSERT_EQ("-2,300.00 %", String::Format("{0:P}", SByte(-23)));
    ASSERT_EQ("-12,800.00 %", String::Format("{0:P}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, P0_SByte) {
    ASSERT_EQ("0 %", String::Format("{0:P0}", SByte(0)));
    ASSERT_EQ("500 %", String::Format("{0:P0}", SByte(5)));
    ASSERT_EQ("7,100 %", String::Format("{0:P0}", SByte(71)));
    ASSERT_EQ("12,700 %", String::Format("{0:P0}", SByte(127)));
    ASSERT_EQ("-100 %", String::Format("{0:P0}", SByte(-1)));
    ASSERT_EQ("-2,300 %", String::Format("{0:P0}", SByte(-23)));
    ASSERT_EQ("-12,800 %", String::Format("{0:P0}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, P1_SByte) {
    ASSERT_EQ("0.0 %", String::Format("{0:P1}", SByte(0)));
    ASSERT_EQ("500.0 %", String::Format("{0:P1}", SByte(5)));
    ASSERT_EQ("7,100.0 %", String::Format("{0:P1}", SByte(71)));
    ASSERT_EQ("12,700.0 %", String::Format("{0:P1}", SByte(127)));
    ASSERT_EQ("-100.0 %", String::Format("{0:P1}", SByte(-1)));
    ASSERT_EQ("-2,300.0 %", String::Format("{0:P1}", SByte(-23)));
    ASSERT_EQ("-12,800.0 %", String::Format("{0:P1}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, P2_SByte) {
    ASSERT_EQ("0.00 %", String::Format("{0:P2}", SByte(0)));
    ASSERT_EQ("500.00 %", String::Format("{0:P2}", SByte(5)));
    ASSERT_EQ("7,100.00 %", String::Format("{0:P2}", SByte(71)));
    ASSERT_EQ("12,700.00 %", String::Format("{0:P2}", SByte(127)));
    ASSERT_EQ("-100.00 %", String::Format("{0:P2}", SByte(-1)));
    ASSERT_EQ("-2,300.00 %", String::Format("{0:P2}", SByte(-23)));
    ASSERT_EQ("-12,800.00 %", String::Format("{0:P2}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, P8_SByte) {
    ASSERT_EQ("0.00000000 %", String::Format("{0:P8}", SByte(0)));
    ASSERT_EQ("500.00000000 %", String::Format("{0:P8}", SByte(5)));
    ASSERT_EQ("7,100.00000000 %", String::Format("{0:P8}", SByte(71)));
    ASSERT_EQ("12,700.00000000 %", String::Format("{0:P8}", SByte(127)));
    ASSERT_EQ("-100.00000000 %", String::Format("{0:P8}", SByte(-1)));
    ASSERT_EQ("-2,300.00000000 %", String::Format("{0:P8}", SByte(-23)));
    ASSERT_EQ("-12,800.00000000 %", String::Format("{0:P8}", SByte(-128)));
  }
  
  TEST(NumericalFormatTest, P_Int16) {
    ASSERT_EQ("0.00 %", String::Format("{0:P}", Int16(0)));
    ASSERT_EQ("19,600.00 %", String::Format("{0:P}", Int16(196)));
    ASSERT_EQ("1,891,100.00 %", String::Format("{0:P}", Int16(18911)));
    ASSERT_EQ("3,276,700.00 %", String::Format("{0:P}", Int16(32767)));
    ASSERT_EQ("-100.00 %", String::Format("{0:P}", Int16(-1)));
    ASSERT_EQ("-587,400.00 %", String::Format("{0:P}", Int16(-5874)));
    ASSERT_EQ("-3,276,800.00 %", String::Format("{0:P}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, P0_Int16) {
    ASSERT_EQ("0 %", String::Format("{0:P0}", Int16(0)));
    ASSERT_EQ("19,600 %", String::Format("{0:P0}", Int16(196)));
    ASSERT_EQ("1,891,100 %", String::Format("{0:P0}", Int16(18911)));
    ASSERT_EQ("3,276,700 %", String::Format("{0:P0}", Int16(32767)));
    ASSERT_EQ("-100 %", String::Format("{0:P0}", Int16(-1)));
    ASSERT_EQ("-587,400 %", String::Format("{0:P0}", Int16(-5874)));
    ASSERT_EQ("-3,276,800 %", String::Format("{0:P0}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, P1_Int16) {
    ASSERT_EQ("0.0 %", String::Format("{0:P1}", Int16(0)));
    ASSERT_EQ("19,600.0 %", String::Format("{0:P1}", Int16(196)));
    ASSERT_EQ("1,891,100.0 %", String::Format("{0:P1}", Int16(18911)));
    ASSERT_EQ("3,276,700.0 %", String::Format("{0:P1}", Int16(32767)));
    ASSERT_EQ("-100.0 %", String::Format("{0:P1}", Int16(-1)));
    ASSERT_EQ("-587,400.0 %", String::Format("{0:P1}", Int16(-5874)));
    ASSERT_EQ("-3,276,800.0 %", String::Format("{0:P1}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, P2_Int16) {
    ASSERT_EQ("0.00 %", String::Format("{0:P2}", Int16(0)));
    ASSERT_EQ("19,600.00 %", String::Format("{0:P2}", Int16(196)));
    ASSERT_EQ("1,891,100.00 %", String::Format("{0:P2}", Int16(18911)));
    ASSERT_EQ("3,276,700.00 %", String::Format("{0:P2}", Int16(32767)));
    ASSERT_EQ("-100.00 %", String::Format("{0:P2}", Int16(-1)));
    ASSERT_EQ("-587,400.00 %", String::Format("{0:P2}", Int16(-5874)));
    ASSERT_EQ("-3,276,800.00 %", String::Format("{0:P2}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, P8_Int16) {
    ASSERT_EQ("0.00000000 %", String::Format("{0:P8}", Int16(0)));
    ASSERT_EQ("19,600.00000000 %", String::Format("{0:P8}", Int16(196)));
    ASSERT_EQ("1,891,100.00000000 %", String::Format("{0:P8}", Int16(18911)));
    ASSERT_EQ("3,276,700.00000000 %", String::Format("{0:P8}", Int16(32767)));
    ASSERT_EQ("-100.00000000 %", String::Format("{0:P8}", Int16(-1)));
    ASSERT_EQ("-587,400.00000000 %", String::Format("{0:P8}", Int16(-5874)));
    ASSERT_EQ("-3,276,800.00000000 %", String::Format("{0:P8}", Int16(-32768)));
  }
  
  TEST(NumericalFormatTest, P_Int32) {
    ASSERT_EQ("0.00 %", String::Format("{0:P}", Int32(0)));
    ASSERT_EQ("196,100.00 %", String::Format("{0:P}", Int32(1961)));
    ASSERT_EQ("212,398,700.00 %", String::Format("{0:P}", Int32(2123987)));
    ASSERT_EQ("214,748,364,700.00 %", String::Format("{0:P}", Int32(2147483647)));
    ASSERT_EQ("-100.00 %", String::Format("{0:P}", Int32(-1)));
    ASSERT_EQ("-15,548,200.00 %", String::Format("{0:P}", Int32(-155482)));
    ASSERT_EQ("-214,748,364,800.00 %", String::Format("{0:P}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, P0_Int32) {
    ASSERT_EQ("0 %", String::Format("{0:P0}", Int32(0)));
    ASSERT_EQ("196,100 %", String::Format("{0:P0}", Int32(1961)));
    ASSERT_EQ("212,398,700 %", String::Format("{0:P0}", Int32(2123987)));
    ASSERT_EQ("214,748,364,700 %", String::Format("{0:P0}", Int32(2147483647)));
    ASSERT_EQ("-100 %", String::Format("{0:P0}", Int32(-1)));
    ASSERT_EQ("-15,548,200 %", String::Format("{0:P0}", Int32(-155482)));
    ASSERT_EQ("-214,748,364,800 %", String::Format("{0:P0}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, P1_Int32) {
    ASSERT_EQ("0.0 %", String::Format("{0:P1}", Int32(0)));
    ASSERT_EQ("196,100.0 %", String::Format("{0:P1}", Int32(1961)));
    ASSERT_EQ("212,398,700.0 %", String::Format("{0:P1}", Int32(2123987)));
    ASSERT_EQ("214,748,364,700.0 %", String::Format("{0:P1}", Int32(2147483647)));
    ASSERT_EQ("-100.0 %", String::Format("{0:P1}", Int32(-1)));
    ASSERT_EQ("-15,548,200.0 %", String::Format("{0:P1}", Int32(-155482)));
    ASSERT_EQ("-214,748,364,800.0 %", String::Format("{0:P1}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, P2_Int32) {
    ASSERT_EQ("0.00 %", String::Format("{0:P2}", Int32(0)));
    ASSERT_EQ("196,100.00 %", String::Format("{0:P2}", Int32(1961)));
    ASSERT_EQ("212,398,700.00 %", String::Format("{0:P2}", Int32(2123987)));
    ASSERT_EQ("214,748,364,700.00 %", String::Format("{0:P2}", Int32(2147483647)));
    ASSERT_EQ("-100.00 %", String::Format("{0:P2}", Int32(-1)));
    ASSERT_EQ("-15,548,200.00 %", String::Format("{0:P2}", Int32(-155482)));
    ASSERT_EQ("-214,748,364,800.00 %", String::Format("{0:P2}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, P8_Int32) {
    ASSERT_EQ("0.00000000 %", String::Format("{0:P8}", Int32(0)));
    ASSERT_EQ("196,100.00000000 %", String::Format("{0:P8}", Int32(1961)));
    ASSERT_EQ("212,398,700.00000000 %", String::Format("{0:P8}", Int32(2123987)));
    ASSERT_EQ("214,748,364,700.00000000 %", String::Format("{0:P8}", Int32(2147483647)));
    ASSERT_EQ("-100.00000000 %", String::Format("{0:P8}", Int32(-1)));
    ASSERT_EQ("-15,548,200.00000000 %", String::Format("{0:P8}", Int32(-155482)));
    ASSERT_EQ("-214,748,364,800.00000000 %", String::Format("{0:P8}", Int32::MinValue));
  }
  
  TEST(NumericalFormatTest, P_Int64) {
    ASSERT_EQ("0.00 %", String::Format("{0:P}", Int64(0)));
    ASSERT_EQ("19,611,200.00 %", String::Format("{0:P}", Int64(196112)));
    ASSERT_EQ("212,398,745,600.00 %", String::Format("{0:P}", Int64(2123987456)));
    ASSERT_EQ("922,337,203,685,477,580,700.00 %", String::Format("{0:P}", Int64::MaxValue));
    ASSERT_EQ("-100.00 %", String::Format("{0:P}", Int64(-1)));
    ASSERT_EQ("-1,554,824,400.00 %", String::Format("{0:P}", Int64(-15548244)));
    ASSERT_EQ("-922,337,203,685,477,580,800.00 %", String::Format("{0:P}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, P0_Int64) {
    ASSERT_EQ("0 %", String::Format("{0:P0}", Int64(0)));
    ASSERT_EQ("19,611,200 %", String::Format("{0:P0}", Int64(196112)));
    ASSERT_EQ("212,398,745,600 %", String::Format("{0:P0}", Int64(2123987456)));
    ASSERT_EQ("922,337,203,685,477,580,700 %", String::Format("{0:P0}", Int64::MaxValue));
    ASSERT_EQ("-100 %", String::Format("{0:P0}", Int64(-1)));
    ASSERT_EQ("-1,554,824,400 %", String::Format("{0:P0}", Int64(-15548244)));
    ASSERT_EQ("-922,337,203,685,477,580,800 %", String::Format("{0:P0}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, P1_Int64) {
    ASSERT_EQ("0.0 %", String::Format("{0:P1}", Int64(0)));
    ASSERT_EQ("19,611,200.0 %", String::Format("{0:P1}", Int64(196112)));
    ASSERT_EQ("212,398,745,600.0 %", String::Format("{0:P1}", Int64(2123987456)));
    ASSERT_EQ("922,337,203,685,477,580,700.0 %", String::Format("{0:P1}", Int64::MaxValue));
    ASSERT_EQ("-100.0 %", String::Format("{0:P1}", Int64(-1)));
    ASSERT_EQ("-1,554,824,400.0 %", String::Format("{0:P1}", Int64(-15548244)));
    ASSERT_EQ("-922,337,203,685,477,580,800.0 %", String::Format("{0:P1}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, P2_Int64) {
    ASSERT_EQ("0.00 %", String::Format("{0:P2}", Int64(0)));
    ASSERT_EQ("19,611,200.00 %", String::Format("{0:P2}", Int64(196112)));
    ASSERT_EQ("212,398,745,600.00 %", String::Format("{0:P2}", Int64(2123987456)));
    ASSERT_EQ("922,337,203,685,477,580,700.00 %", String::Format("{0:P2}", Int64::MaxValue));
    ASSERT_EQ("-100.00 %", String::Format("{0:P2}", Int64(-1)));
    ASSERT_EQ("-1,554,824,400.00 %", String::Format("{0:P2}", Int64(-15548244)));
    ASSERT_EQ("-922,337,203,685,477,580,800.00 %", String::Format("{0:P2}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, P8_Int64) {
    ASSERT_EQ("0.00000000 %", String::Format("{0:P8}", Int64(0)));
    ASSERT_EQ("19,611,200.00000000 %", String::Format("{0:P8}", Int64(196112)));
    ASSERT_EQ("212,398,745,600.00000000 %", String::Format("{0:P8}", Int64(2123987456)));
    ASSERT_EQ("922,337,203,685,477,580,700.00000000 %", String::Format("{0:P8}", Int64::MaxValue));
    ASSERT_EQ("-100.00000000 %", String::Format("{0:P8}", Int64(-1)));
    ASSERT_EQ("-1,554,824,400.00000000 %", String::Format("{0:P8}", Int64(-15548244)));
    ASSERT_EQ("-922,337,203,685,477,580,800.00000000 %", String::Format("{0:P8}", Int64::MinValue));
  }
  
  TEST(NumericalFormatTest, P_Byte) {
    ASSERT_EQ("0.00 %", String::Format("{0:P}", Byte(0)));
    ASSERT_EQ("1,900.00 %", String::Format("{0:P}", Byte(19)));
    ASSERT_EQ("20,100.00 %", String::Format("{0:P}", Byte(201)));
    ASSERT_EQ("25,500.00 %", String::Format("{0:P}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, P0_Byte) {
    ASSERT_EQ("0 %", String::Format("{0:P0}", Byte(0)));
    ASSERT_EQ("1,900 %", String::Format("{0:P0}", Byte(19)));
    ASSERT_EQ("20,100 %", String::Format("{0:P0}", Byte(201)));
    ASSERT_EQ("25,500 %", String::Format("{0:P0}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, P1_Byte) {
    ASSERT_EQ("0.0 %", String::Format("{0:P1}", Byte(0)));
    ASSERT_EQ("1,900.0 %", String::Format("{0:P1}", Byte(19)));
    ASSERT_EQ("20,100.0 %", String::Format("{0:P1}", Byte(201)));
    ASSERT_EQ("25,500.0 %", String::Format("{0:P1}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, P2_Byte) {
    ASSERT_EQ("0.00 %", String::Format("{0:P2}", Byte(0)));
    ASSERT_EQ("1,900.00 %", String::Format("{0:P2}", Byte(19)));
    ASSERT_EQ("20,100.00 %", String::Format("{0:P2}", Byte(201)));
    ASSERT_EQ("25,500.00 %", String::Format("{0:P2}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, P8_Byte) {
    ASSERT_EQ("0.00000000 %", String::Format("{0:P8}", Byte(0)));
    ASSERT_EQ("1,900.00000000 %", String::Format("{0:P8}", Byte(19)));
    ASSERT_EQ("20,100.00000000 %", String::Format("{0:P8}", Byte(201)));
    ASSERT_EQ("25,500.00000000 %", String::Format("{0:P8}", Byte(255)));
  }
  
  TEST(NumericalFormatTest, P_UInt16) {
    ASSERT_EQ("0.00 %", String::Format("{0:P}", UInt16(0)));
    ASSERT_EQ("196,100.00 %", String::Format("{0:P}", UInt16(1961)));
    ASSERT_EQ("2,123,900.00 %", String::Format("{0:P}", UInt16(21239)));
    ASSERT_EQ("6,553,500.00 %", String::Format("{0:P}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, P0_UInt16) {
    ASSERT_EQ("0 %", String::Format("{0:P0}", UInt16(0)));
    ASSERT_EQ("196,100 %", String::Format("{0:P0}", UInt16(1961)));
    ASSERT_EQ("2,123,900 %", String::Format("{0:P0}", UInt16(21239)));
    ASSERT_EQ("6,553,500 %", String::Format("{0:P0}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, P1_UInt16) {
    ASSERT_EQ("0.0 %", String::Format("{0:P1}", UInt16(0)));
    ASSERT_EQ("196,100.0 %", String::Format("{0:P1}", UInt16(1961)));
    ASSERT_EQ("2,123,900.0 %", String::Format("{0:P1}", UInt16(21239)));
    ASSERT_EQ("6,553,500.0 %", String::Format("{0:P1}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, P2_UInt16) {
    ASSERT_EQ("0.00 %", String::Format("{0:P2}", UInt16(0)));
    ASSERT_EQ("196,100.00 %", String::Format("{0:P2}", UInt16(1961)));
    ASSERT_EQ("2,123,900.00 %", String::Format("{0:P2}", UInt16(21239)));
    ASSERT_EQ("6,553,500.00 %", String::Format("{0:P2}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, P8_UInt16) {
    ASSERT_EQ("0.00000000 %", String::Format("{0:P8}", UInt16(0)));
    ASSERT_EQ("196,100.00000000 %", String::Format("{0:P8}", UInt16(1961)));
    ASSERT_EQ("2,123,900.00000000 %", String::Format("{0:P8}", UInt16(21239)));
    ASSERT_EQ("6,553,500.00000000 %", String::Format("{0:P8}", UInt16(65535)));
  }
  
  TEST(NumericalFormatTest, P_UInt32) {
    ASSERT_EQ("0.00 %", String::Format("{0:P}", UInt32(0)));
    ASSERT_EQ("196,100.00 %", String::Format("{0:P}", UInt32(1961)));
    ASSERT_EQ("212,398,700.00 %", String::Format("{0:P}", UInt32(2123987)));
    ASSERT_EQ("429,496,729,500.00 %", String::Format("{0:P}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, P0_UInt32) {
    ASSERT_EQ("0 %", String::Format("{0:P0}", UInt32(0)));
    ASSERT_EQ("196,100 %", String::Format("{0:P0}", UInt32(1961)));
    ASSERT_EQ("212,398,700 %", String::Format("{0:P0}", UInt32(2123987)));
    ASSERT_EQ("429,496,729,500 %", String::Format("{0:P0}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, P1_UInt32) {
    ASSERT_EQ("0.0 %", String::Format("{0:P1}", UInt32(0)));
    ASSERT_EQ("196,100.0 %", String::Format("{0:P1}", UInt32(1961)));
    ASSERT_EQ("212,398,700.0 %", String::Format("{0:P1}", UInt32(2123987)));
    ASSERT_EQ("429,496,729,500.0 %", String::Format("{0:P1}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, P2_UInt32) {
    ASSERT_EQ("0.00 %", String::Format("{0:P2}", UInt32(0)));
    ASSERT_EQ("196,100.00 %", String::Format("{0:P2}", UInt32(1961)));
    ASSERT_EQ("212,398,700.00 %", String::Format("{0:P2}", UInt32(2123987)));
    ASSERT_EQ("429,496,729,500.00 %", String::Format("{0:P2}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, P8_UInt32) {
    ASSERT_EQ("0.00000000 %", String::Format("{0:P8}", UInt32(0)));
    ASSERT_EQ("196,100.00000000 %", String::Format("{0:P8}", UInt32(1961)));
    ASSERT_EQ("212,398,700.00000000 %", String::Format("{0:P8}", UInt32(2123987)));
    ASSERT_EQ("429,496,729,500.00000000 %", String::Format("{0:P8}", UInt32::MaxValue));
  }
  
  TEST(NumericalFormatTest, P_UInt64) {
    ASSERT_EQ("0.00 %", String::Format("{0:P}", UInt64(0)));
    ASSERT_EQ("19,611,200.00 %", String::Format("{0:P}", UInt64(196112)));
    ASSERT_EQ("212,398,745,600.00 %", String::Format("{0:P}", UInt64(2123987456)));
    ASSERT_EQ("1,844,674,407,370,955,161,500.00 %", String::Format("{0:P}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, P0_UInt64) {
    ASSERT_EQ("0 %", String::Format("{0:P0}", UInt64(0)));
    ASSERT_EQ("19,611,200 %", String::Format("{0:P0}", UInt64(196112)));
    ASSERT_EQ("212,398,745,600 %", String::Format("{0:P0}", UInt64(2123987456)));
    ASSERT_EQ("1,844,674,407,370,955,161,500 %", String::Format("{0:P0}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, P1_UInt64) {
    ASSERT_EQ("0.0 %", String::Format("{0:P1}", UInt64(0)));
    ASSERT_EQ("19,611,200.0 %", String::Format("{0:P1}", UInt64(196112)));
    ASSERT_EQ("212,398,745,600.0 %", String::Format("{0:P1}", UInt64(2123987456)));
    ASSERT_EQ("1,844,674,407,370,955,161,500.0 %", String::Format("{0:P1}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, P2_UInt64) {
    ASSERT_EQ("0.00 %", String::Format("{0:P2}", UInt64(0)));
    ASSERT_EQ("19,611,200.00 %", String::Format("{0:P2}", UInt64(196112)));
    ASSERT_EQ("212,398,745,600.00 %", String::Format("{0:P2}", UInt64(2123987456)));
    ASSERT_EQ("1,844,674,407,370,955,161,500.00 %", String::Format("{0:P2}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, P8_UInt64) {
    ASSERT_EQ("0.00000000 %", String::Format("{0:P8}", UInt64(0)));
    ASSERT_EQ("19,611,200.00000000 %", String::Format("{0:P8}", UInt64(196112)));
    ASSERT_EQ("212,398,745,600.00000000 %", String::Format("{0:P8}", UInt64(2123987456)));
    ASSERT_EQ("1,844,674,407,370,955,161,500.00000000 %", String::Format("{0:P8}", UInt64::MaxValue));
  }
  
  TEST(NumericalFormatTest, P_Double) {
    ASSERT_EQ("0.00 %", String::Format("{0:P}", Double(0)));
    ASSERT_EQ("21.32 %", String::Format("{0:P}", Double(0.2132)));
    ASSERT_EQ("-99.87 %", String::Format("{0:P}", Double(-0.9987)));
    ASSERT_EQ("121.00 %", String::Format("{0:P}", Double(1.21)));
    ASSERT_EQ("65,412,312.37 %", String::Format("{0:P}", Double(654123.123654)));
  }
  
  TEST(NumericalFormatTest, P0_Double) {
    ASSERT_EQ("0 %", String::Format("{0:P0}", Double(0)));
    ASSERT_EQ("21 %", String::Format("{0:P0}", Double(0.2132)));
    ASSERT_EQ("-100 %", String::Format("{0:P0}", Double(-0.9987)));
    ASSERT_EQ("121 %", String::Format("{0:P0}", Double(1.21)));
    ASSERT_EQ("65,412,312 %", String::Format("{0:P0}", Double(654123.123654)));
  }
  
  TEST(NumericalFormatTest, P1_Double) {
    ASSERT_EQ("0.0 %", String::Format("{0:P1}", Double(0)));
    ASSERT_EQ("21.3 %", String::Format("{0:P1}", Double(0.2132)));
    ASSERT_EQ("-99.9 %", String::Format("{0:P1}", Double(-0.9987)));
    ASSERT_EQ("121.0 %", String::Format("{0:P1}", Double(1.21)));
    ASSERT_EQ("65,412,312.4 %", String::Format("{0:P1}", Double(654123.123654)));
  }
  
  TEST(NumericalFormatTest, P2_Double) {
    ASSERT_EQ("0.00 %", String::Format("{0:P2}", Double(0)));
    ASSERT_EQ("21.32 %", String::Format("{0:P2}", Double(0.2132)));
    ASSERT_EQ("-99.87 %", String::Format("{0:P2}", Double(-0.9987)));
    ASSERT_EQ("121.00 %", String::Format("{0:P2}", Double(1.21)));
    ASSERT_EQ("65,412,312.37 %", String::Format("{0:P2}", Double(654123.123654)));
  }
  
  TEST(NumericalFormatTest, P8_Double) {
    ASSERT_EQ("0.00000000 %", String::Format("{0:P8}", Double(0)));
    ASSERT_EQ("21.32000000 %", String::Format("{0:P8}", Double(0.2132)));
    ASSERT_EQ("-99.87000000 %", String::Format("{0:P8}", Double(-0.9987)));
    ASSERT_EQ("121.00000000 %", String::Format("{0:P8}", Double(1.21)));
    ASSERT_EQ("65,412,312.36540000 %", String::Format("{0:P8}", Double(654123.123654)));
  }
  
  TEST(NumericalFormatTest, P_Single) {
    ASSERT_EQ("0.00 %", String::Format("{0:P}", Single(0.0f)));
    ASSERT_EQ("21.32 %", String::Format("{0:P}", Single(0.2132f)));
    ASSERT_EQ("-99.87 %", String::Format("{0:P}", Single(-0.9987f)));
    ASSERT_EQ("121.00 %", String::Format("{0:P}", Single(1.21f)));
    ASSERT_EQ("123,301.20 %", String::Format("{0:P}", Single(1233.012f)));
  }
  
  TEST(NumericalFormatTest, P0_Single) {
    ASSERT_EQ("0 %", String::Format("{0:P0}", Single(0.0f)));
    ASSERT_EQ("21 %", String::Format("{0:P0}", Single(0.2132f)));
    ASSERT_EQ("-100 %", String::Format("{0:P0}", Single(-0.9987f)));
    ASSERT_EQ("121 %", String::Format("{0:P0}", Single(1.21f)));
    ASSERT_EQ("123,301 %", String::Format("{0:P0}", Single(1233.012f)));
  }
  
  TEST(NumericalFormatTest, P1_Single) {
    ASSERT_EQ("0.0 %", String::Format("{0:P1}", Single(0.0f)));
    ASSERT_EQ("21.3 %", String::Format("{0:P1}", Single(0.2132f)));
    ASSERT_EQ("-99.9 %", String::Format("{0:P1}", Single(-0.9987f)));
    ASSERT_EQ("121.0 %", String::Format("{0:P1}", Single(1.21f)));
    ASSERT_EQ("123,301.2 %", String::Format("{0:P1}", Single(1233.012f)));
  }
  
  TEST(NumericalFormatTest, P2_Single) {
    ASSERT_EQ("0.00 %", String::Format("{0:P2}", Single(0.0f)));
    ASSERT_EQ("21.32 %", String::Format("{0:P2}", Single(0.2132f)));
    ASSERT_EQ("-99.87 %", String::Format("{0:P2}", Single(-0.9987f)));
    ASSERT_EQ("121.00 %", String::Format("{0:P2}", Single(1.21f)));
    ASSERT_EQ("123,301.20 %", String::Format("{0:P2}", Single(1233.012f)));
  }
  
  TEST(NumericalFormatTest, P4_Single) {
    ASSERT_EQ("0.0000 %", String::Format("{0:P4}", Single(0.0f)));
    ASSERT_EQ("21.3200 %", String::Format("{0:P4}", Single(0.2132f)));
    ASSERT_EQ("-99.8700 %", String::Format("{0:P4}", Single(-0.9987f)));
    ASSERT_EQ("121.0000 %", String::Format("{0:P4}", Single(1.21f)));
    ASSERT_EQ("12,301.100 %", String::Format("{0:P3}", Single(123.011f)));
  }
  
}

/*
C# program to generate those tests (replace *type*] by a typename) :

  class Program
  {
    public static void Main()
    {
      Single[] t = { 0.0f, 0.2132f, -0.9987f, 1.21f, 1233.0123f };
      String[] f = { "P", "P0", "P1", "P2", "P4" };
      Generate<Single>(f, t);

      int a = 74;
    }

    static void Generate<T>(String[] f, T[] t) {

      for (String fmt : f) {
        for (T i : t) {
          MAKE<T>(fmt, (IFormattable)i);
        }
        Console.WriteLine();
      }
    }

    static void MAKE<T>(String format, IFormattable value) {
      String[] split = value.GetType().ToString().Split('.');
      String type = split[split.Length-1];
      String tested_value = value.ToString("G",System::Globalization::CultureInfo.CreateSpecificCulture("en-US"));
      if (type == "Single") {
        if (!tested_value.Contains('.')) tested_value += ".0f";
        else                             tested_value += "f";
      } else if (type == "Double" && !tested_value.Contains('.')) tested_value += ".0";
      Console.WriteLine("  ASSERT_EQ(\"{0}\", String::Format(\"{{0:{1}}}\", {3}({2}))); ", value.ToString(format, System::Globalization::CultureInfo.CreateSpecificCulture("en-US")), format, tested_value, type);
    }
  }
*/
