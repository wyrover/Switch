#include <Switch/System/Convert.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Collections::Generic;

namespace {
  TEST(ConvertTest, ToBooleanFromIConvertibleBoolean) {
    ASSERT_FALSE(Convert::ToBoolean(static_cast<const IConvertible&>(Boolean(false))));
    ASSERT_TRUE(Convert::ToBoolean(static_cast<const IConvertible&>(Boolean(true))));
  }
  
  TEST(ConvertTest, ToBooleanFromIConvertibleByte) {
    ASSERT_FALSE(Convert::ToBoolean(static_cast<const IConvertible&>(Byte(0))));
    ASSERT_TRUE(Convert::ToBoolean(static_cast<const IConvertible&>(Byte(42))));
  }
  
  TEST(ConvertTest, ToBooleanFromIConvertibleInt16) {
    ASSERT_FALSE(Convert::ToBoolean(static_cast<const IConvertible&>(Int16(0))));
    ASSERT_TRUE(Convert::ToBoolean(static_cast<const IConvertible&>(Int16(42))));
  }
  
  TEST(ConvertTest, ToBooleanFromIConvertibleInt32) {
    ASSERT_FALSE(Convert::ToBoolean(static_cast<const IConvertible&>(Int32(0))));
    ASSERT_TRUE(Convert::ToBoolean(static_cast<const IConvertible&>(Int32(42))));
  }
  
  TEST(ConvertTest, ToBooleanFromIConvertibleInt64) {
    ASSERT_FALSE(Convert::ToBoolean(static_cast<const IConvertible&>(Int64(0))));
    ASSERT_TRUE(Convert::ToBoolean(static_cast<const IConvertible&>(Int64(42))));
  }
  
  TEST(ConvertTest, ToBooleanFromIConvertibleChar) {
    ASSERT_THROW(Convert::ToBoolean(static_cast<const IConvertible&>(Char('T'))), InvalidCastException);
  }
  
  TEST(ConvertTest, ToBooleanFromIConvertibleDateTime) {
    ASSERT_THROW(Convert::ToBoolean(static_cast<const IConvertible&>(DateTime::Now())), InvalidCastException);
  }
  
  TEST(ConvertTest, ToBooleanFromIConvertibleDouble) {
    ASSERT_FALSE(Convert::ToBoolean(static_cast<const IConvertible&>(Double(0.0))));
    ASSERT_TRUE(Convert::ToBoolean(static_cast<const IConvertible&>(Double(42.0))));
  }
  
  TEST(ConvertTest, ToBooleanFromIConvertibleSByte) {
    ASSERT_FALSE(Convert::ToBoolean(static_cast<const IConvertible&>(SByte(0))));
    ASSERT_TRUE(Convert::ToBoolean(static_cast<const IConvertible&>(SByte(42))));
  }
  
  TEST(ConvertTest, ToBooleanFromIConvertibleSingle) {
    ASSERT_FALSE(Convert::ToBoolean(static_cast<const IConvertible&>(Single(0.0))));
    ASSERT_TRUE(Convert::ToBoolean(static_cast<const IConvertible&>(Single(42.0))));
  }
  
  TEST(ConvertTest, ToBooleanFromIConvertibleString) {
    ASSERT_FALSE(Convert::ToBoolean(static_cast<const IConvertible&>(string("False"))));
    ASSERT_TRUE(Convert::ToBoolean(static_cast<const IConvertible&>(string("True"))));
  }
  
  TEST(ConvertTest, ToBooleanFromIConvertibleUInt16) {
    ASSERT_FALSE(Convert::ToBoolean(static_cast<const IConvertible&>(UInt16(0))));
    ASSERT_TRUE(Convert::ToBoolean(static_cast<const IConvertible&>(UInt16(42))));
  }
  
  TEST(ConvertTest, ToBooleanFromIConvertibleUInt32) {
    ASSERT_FALSE(Convert::ToBoolean(static_cast<const IConvertible&>(UInt32(0))));
    ASSERT_TRUE(Convert::ToBoolean(static_cast<const IConvertible&>(UInt32(42))));
  }
  
  TEST(ConvertTest, ToBooleanFromIConvertibleUInt64) {
    ASSERT_FALSE(Convert::ToBoolean(static_cast<const IConvertible&>(UInt64(0))));
    ASSERT_TRUE(Convert::ToBoolean(static_cast<const IConvertible&>(UInt64(42))));
  }
  
  TEST(ConvertTest, ToBooleanFrom_boolean) {
    ASSERT_FALSE(Convert::ToBoolean(false));
    ASSERT_TRUE(Convert::ToBoolean(true));
  }
  
  TEST(ConvertTest, ToBooleanFromBoolean) {
    ASSERT_FALSE(Convert::ToBoolean(Boolean(false)));
    ASSERT_TRUE(Convert::ToBoolean(Boolean(true)));
  }
  
  TEST(ConvertTest, ToBooleanFrom_byte) {
    ASSERT_FALSE(Convert::ToBoolean(byte(0)));
    ASSERT_TRUE(Convert::ToBoolean(byte(1)));
    ASSERT_TRUE(Convert::ToBoolean(byte(173)));
    ASSERT_FALSE(Convert::ToBoolean(Byte::MinValue));
    ASSERT_TRUE(Convert::ToBoolean(Byte::MaxValue));
  }
  
  TEST(ConvertTest, ToBooleanFromByte) {
    ASSERT_FALSE(Convert::ToBoolean(Byte(0)));
    ASSERT_TRUE(Convert::ToBoolean(Byte(1)));
    ASSERT_TRUE(Convert::ToBoolean(Byte(173)));
    ASSERT_FALSE(Convert::ToBoolean(Byte(Byte::MinValue)));
    ASSERT_TRUE(Convert::ToBoolean(Byte(Byte::MaxValue)));
  }
  
  TEST(ConvertTest, ToBooleanFrom_char32) {
    ASSERT_THROW(Convert::ToBoolean(char32('T')), InvalidCastException);
  }
  
  TEST(ConvertTest, ToBooleanFromChar) {
    ASSERT_THROW(Convert::ToBoolean(Char('T')), InvalidCastException);
  }
  
  TEST(ConvertTest, ToBooleanFromDateTime) {
    ASSERT_THROW(Convert::ToBoolean(DateTime::Now), InvalidCastException);
  }
  
  TEST(ConvertTest, ToBooleanFrom_double) {
    ASSERT_FALSE(Convert::ToBoolean(double(0)));
    ASSERT_TRUE(Convert::ToBoolean(double(1)));
    ASSERT_TRUE(Convert::ToBoolean(double(2364.877964)));
    ASSERT_TRUE(Convert::ToBoolean(Double::MinValue));
    ASSERT_TRUE(Convert::ToBoolean(Double::MaxValue));
  }
  
  TEST(ConvertTest, ToBooleanFromDouble) {
    ASSERT_FALSE(Convert::ToBoolean(Double(0)));
    ASSERT_TRUE(Convert::ToBoolean(Double(1)));
    ASSERT_TRUE(Convert::ToBoolean(Double(2364.877964)));
    ASSERT_TRUE(Convert::ToBoolean(Double(Double::MinValue)));
    ASSERT_TRUE(Convert::ToBoolean(Double(Double::MaxValue)));
  }
  
  TEST(ConvertTest, ToBooleanFrom_int16) {
    ASSERT_FALSE(Convert::ToBoolean(int16(0)));
    ASSERT_TRUE(Convert::ToBoolean(int16(1)));
    ASSERT_TRUE(Convert::ToBoolean(int16(2364)));
    ASSERT_TRUE(Convert::ToBoolean(Int16::MinValue));
    ASSERT_TRUE(Convert::ToBoolean(Int16::MaxValue));
  }
  
  TEST(ConvertTest, ToBooleanFromInt16) {
    ASSERT_FALSE(Convert::ToBoolean(Int16(0)));
    ASSERT_TRUE(Convert::ToBoolean(Int16(1)));
    ASSERT_TRUE(Convert::ToBoolean(Int16(2364)));
    ASSERT_TRUE(Convert::ToBoolean(Int16(Int16::MinValue)));
    ASSERT_TRUE(Convert::ToBoolean(Int16(Int16::MaxValue)));
  }
  
  TEST(ConvertTest, ToBooleanFrom_int32) {
    ASSERT_FALSE(Convert::ToBoolean(int32(0)));
    ASSERT_TRUE(Convert::ToBoolean(int32(1)));
    ASSERT_TRUE(Convert::ToBoolean(int32(2364)));
    ASSERT_TRUE(Convert::ToBoolean(Int32::MinValue));
    ASSERT_TRUE(Convert::ToBoolean(Int32::MaxValue));
  }
  
  TEST(ConvertTest, ToBooleanFromInt32) {
    ASSERT_FALSE(Convert::ToBoolean(Int32(0)));
    ASSERT_TRUE(Convert::ToBoolean(Int32(1)));
    ASSERT_TRUE(Convert::ToBoolean(Int32(2364)));
    ASSERT_TRUE(Convert::ToBoolean(Int32(Int32::MinValue)));
    ASSERT_TRUE(Convert::ToBoolean(Int32(Int32::MaxValue)));
  }
  
  TEST(ConvertTest, ToBooleanFrom_int64) {
    ASSERT_FALSE(Convert::ToBoolean(int64(0)));
    ASSERT_TRUE(Convert::ToBoolean(int64(1)));
    ASSERT_TRUE(Convert::ToBoolean(int64(2364)));
    ASSERT_TRUE(Convert::ToBoolean(Int64::MinValue));
    ASSERT_TRUE(Convert::ToBoolean(Int64::MaxValue));
  }
  
  TEST(ConvertTest, ToBooleanFromInt64) {
    ASSERT_FALSE(Convert::ToBoolean(Int64(0)));
    ASSERT_TRUE(Convert::ToBoolean(Int64(1)));
    ASSERT_TRUE(Convert::ToBoolean(Int64(2364)));
    ASSERT_TRUE(Convert::ToBoolean(Int64(Int64::MinValue)));
    ASSERT_TRUE(Convert::ToBoolean(Int64(Int64::MaxValue)));
  }
  
  TEST(ConvertTest, ToBooleanFrom_sbyte) {
    ASSERT_FALSE(Convert::ToBoolean(sbyte(0)));
    ASSERT_TRUE(Convert::ToBoolean(sbyte(1)));
    ASSERT_TRUE(Convert::ToBoolean(sbyte(112)));
    ASSERT_TRUE(Convert::ToBoolean(SByte::MinValue));
    ASSERT_TRUE(Convert::ToBoolean(SByte::MaxValue));
  }
  
  TEST(ConvertTest, ToBooleanFromSByte) {
    ASSERT_FALSE(Convert::ToBoolean(SByte(0)));
    ASSERT_TRUE(Convert::ToBoolean(SByte(1)));
    ASSERT_TRUE(Convert::ToBoolean(SByte(112)));
    ASSERT_TRUE(Convert::ToBoolean(SByte(SByte::MinValue)));
    ASSERT_TRUE(Convert::ToBoolean(SByte(SByte::MaxValue)));
  }
  
  TEST(ConvertTest, ToBooleanFrom_single) {
    ASSERT_FALSE(Convert::ToBoolean(float(0)));
    ASSERT_TRUE(Convert::ToBoolean(float(1)));
    ASSERT_TRUE(Convert::ToBoolean(float(2364.877964)));
    ASSERT_TRUE(Convert::ToBoolean(Single::MinValue));
    ASSERT_TRUE(Convert::ToBoolean(Single::MaxValue));
  }
  
  TEST(ConvertTest, ToBooleanFromSingle) {
    ASSERT_FALSE(Convert::ToBoolean(Single(0)));
    ASSERT_TRUE(Convert::ToBoolean(Single(1)));
    ASSERT_TRUE(Convert::ToBoolean(Single(2364.877964f)));
    ASSERT_TRUE(Convert::ToBoolean(Single(Single::MinValue)));
    ASSERT_TRUE(Convert::ToBoolean(Single(Single::MaxValue)));
  }
  
  TEST(ConvertTest, ToBooleanFrom_string) {
    ASSERT_FALSE(Convert::ToBoolean("False"));
    ASSERT_FALSE(Convert::ToBoolean("false"));
    ASSERT_FALSE(Convert::ToBoolean("falSe"));
    ASSERT_FALSE(Convert::ToBoolean("FALSE"));
    ASSERT_FALSE(Convert::ToBoolean("    false"));
    ASSERT_FALSE(Convert::ToBoolean("False    "));
    
    ASSERT_TRUE(Convert::ToBoolean("True"));
    ASSERT_TRUE(Convert::ToBoolean("true"));
    ASSERT_TRUE(Convert::ToBoolean("trUe"));
    ASSERT_TRUE(Convert::ToBoolean("TRUE"));
    ASSERT_TRUE(Convert::ToBoolean("    true"));
    ASSERT_TRUE(Convert::ToBoolean("True    "));
    
    ASSERT_THROW(Convert::ToBoolean("notfalse"), FormatException);
  }
  
  TEST(ConvertTest, ToBooleanFromString) {
    ASSERT_FALSE(Convert::ToBoolean(string("False")));
    ASSERT_FALSE(Convert::ToBoolean(string("false")));
    ASSERT_FALSE(Convert::ToBoolean(string("falSe")));
    ASSERT_FALSE(Convert::ToBoolean(string("FALSE")));
    ASSERT_FALSE(Convert::ToBoolean(string("    false")));
    ASSERT_FALSE(Convert::ToBoolean(string("False    ")));
    
    ASSERT_TRUE(Convert::ToBoolean(string("True")));
    ASSERT_TRUE(Convert::ToBoolean(string("true")));
    ASSERT_TRUE(Convert::ToBoolean(string("trUe")));
    ASSERT_TRUE(Convert::ToBoolean(string("TRUE")));
    ASSERT_TRUE(Convert::ToBoolean(string("    true")));
    ASSERT_TRUE(Convert::ToBoolean(string("True    ")));
    
    ASSERT_THROW(Convert::ToBoolean(string("notfalse")), FormatException);
  }
  
  TEST(ConvertTest, ToBooleanFrom_uint16) {
    ASSERT_FALSE(Convert::ToBoolean(uint16(0)));
    ASSERT_TRUE(Convert::ToBoolean(uint16(1)));
    ASSERT_TRUE(Convert::ToBoolean(uint16(2364)));
    ASSERT_FALSE(Convert::ToBoolean(UInt16::MinValue));
    ASSERT_TRUE(Convert::ToBoolean(UInt16::MaxValue));
  }
  
  TEST(ConvertTest, ToBooleanFromUInt16) {
    ASSERT_FALSE(Convert::ToBoolean(UInt16(0)));
    ASSERT_TRUE(Convert::ToBoolean(UInt16(1)));
    ASSERT_TRUE(Convert::ToBoolean(UInt16(2364)));
    ASSERT_FALSE(Convert::ToBoolean(UInt16(UInt16::MinValue)));
    ASSERT_TRUE(Convert::ToBoolean(UInt16(UInt16::MaxValue)));
  }
  
  TEST(ConvertTest, ToBooleanFrom_uint32) {
    ASSERT_FALSE(Convert::ToBoolean(uint32(0)));
    ASSERT_TRUE(Convert::ToBoolean(uint32(1)));
    ASSERT_TRUE(Convert::ToBoolean(uint32(2364)));
    ASSERT_FALSE(Convert::ToBoolean(UInt32::MinValue));
    ASSERT_TRUE(Convert::ToBoolean(UInt32::MaxValue));
  }
  
  TEST(ConvertTest, ToBooleanFromUInt32) {
    ASSERT_FALSE(Convert::ToBoolean(UInt32(0)));
    ASSERT_TRUE(Convert::ToBoolean(UInt32(1)));
    ASSERT_TRUE(Convert::ToBoolean(UInt32(2364)));
    ASSERT_FALSE(Convert::ToBoolean(UInt32(UInt32::MinValue)));
    ASSERT_TRUE(Convert::ToBoolean(UInt32(UInt32::MaxValue)));
  }
  
  TEST(ConvertTest, ToBooleanFrom_uint64) {
    ASSERT_FALSE(Convert::ToBoolean(uint64(0)));
    ASSERT_TRUE(Convert::ToBoolean(uint64(1)));
    ASSERT_TRUE(Convert::ToBoolean(uint64(2364)));
    ASSERT_FALSE(Convert::ToBoolean(UInt64::MinValue));
    ASSERT_TRUE(Convert::ToBoolean(UInt64::MaxValue));
  }
  
  TEST(ConvertTest, ToBooleanFromUInt64) {
    ASSERT_FALSE(Convert::ToBoolean(UInt64(0)));
    ASSERT_TRUE(Convert::ToBoolean(UInt64(1)));
    ASSERT_TRUE(Convert::ToBoolean(UInt64(2364)));
    ASSERT_FALSE(Convert::ToBoolean(UInt64(UInt64::MinValue)));
    ASSERT_TRUE(Convert::ToBoolean(UInt64(UInt64::MaxValue)));
  }
  
  TEST(ConvertTest, ToByteFromIConvertibleBoolean) {
    ASSERT_EQ(0, Convert::ToByte(static_cast<const IConvertible&>(Boolean(false))));
    ASSERT_EQ(1, Convert::ToByte(static_cast<const IConvertible&>(Boolean(true))));
  }
  
  TEST(ConvertTest, ToByteFromIConvertibleByte) {
    ASSERT_EQ(0, Convert::ToByte(static_cast<const IConvertible&>(Byte(0))));
    ASSERT_EQ(42, Convert::ToByte(static_cast<const IConvertible&>(Byte(42))));
  }
  
  TEST(ConvertTest, ToByteFromIConvertibleInt16) {
    ASSERT_EQ(0, Convert::ToByte(static_cast<const IConvertible&>(Int16(0))));
    ASSERT_EQ(42, Convert::ToByte(static_cast<const IConvertible&>(Int16(42))));
  }
  
  TEST(ConvertTest, ToByteFromIConvertibleInt32) {
    ASSERT_EQ(0, Convert::ToByte(static_cast<const IConvertible&>(Int32(0))));
    ASSERT_EQ(42, Convert::ToByte(static_cast<const IConvertible&>(Int32(42))));
  }
  
  TEST(ConvertTest, ToByteFromIConvertibleInt64) {
    ASSERT_EQ(0, Convert::ToByte(static_cast<const IConvertible&>(Int64(0))));
    ASSERT_EQ(42, Convert::ToByte(static_cast<const IConvertible&>(Int64(42))));
  }
  
  TEST(ConvertTest, ToByteFromIConvertibleChar) {
    ASSERT_EQ(0, Convert::ToByte(static_cast<const IConvertible&>(Char(0))));
    ASSERT_EQ(84, Convert::ToByte(static_cast<const IConvertible&>(Char('T'))));
  }
  
  TEST(ConvertTest, ToByteFromBoolean) {
    ASSERT_EQ(0, Convert::ToByte(false));
    ASSERT_EQ(1, Convert::ToByte(true));
  }
  
  TEST(ConvertTest, ToByteFromByte) {
    ASSERT_EQ(0, Convert::ToByte((byte)0));
    ASSERT_EQ(1, Convert::ToByte((byte)1));
    ASSERT_EQ(173, Convert::ToByte((byte)173));
    ASSERT_EQ(Byte::MinValue, Convert::ToByte(Byte::MinValue));
    ASSERT_EQ(Byte::MaxValue, Convert::ToByte(Byte::MaxValue));
  }
  
  TEST(ConvertTest, ToByteFromChar) {
    ASSERT_EQ(0, Convert::ToByte((char32)0));
    ASSERT_EQ(1, Convert::ToByte((char32)1));
    ASSERT_EQ(84, Convert::ToByte((char32)'T'));
    ASSERT_EQ(Char::MinValue, Convert::ToByte(Char::MinValue));
    ASSERT_THROW(Convert::ToByte(Char::MaxValue), OverflowException);
  }
  
  TEST(ConvertTest, ToByteFromDateTime) {
    ASSERT_THROW(Convert::ToByte(DateTime::Now()), InvalidCastException);
  }
  
  TEST(ConvertTest, ToByteFromDouble) {
    ASSERT_EQ(0, Convert::ToByte((double)0));
    ASSERT_EQ(1, Convert::ToByte((double)1));
    ASSERT_EQ(13, (byte)13.7896);
    ASSERT_EQ(14, Convert::ToByte((double)13.7896));
    ASSERT_THROW(Convert::ToByte(Double::MinValue), OverflowException);
    ASSERT_THROW(Convert::ToByte(Double::MaxValue), OverflowException);
  }
  
  TEST(ConvertTest, ToByteFromInt16) {
    ASSERT_EQ(0, Convert::ToByte((int16)0));
    ASSERT_EQ(1, Convert::ToByte((int16)1));
    ASSERT_EQ(167, Convert::ToByte((int16)167));
    ASSERT_THROW(Convert::ToByte(Int16::MinValue), OverflowException);
    ASSERT_THROW(Convert::ToByte(Int16::MaxValue), OverflowException);
  }
  
  TEST(ConvertTest, ToByteFromInt32) {
    ASSERT_EQ(0, Convert::ToByte((int32)0));
    ASSERT_EQ(1, Convert::ToByte((int32)1));
    ASSERT_EQ(189, Convert::ToByte((int32)189));
    ASSERT_THROW(Convert::ToByte(Int32::MinValue), OverflowException);
    ASSERT_THROW(Convert::ToByte(Int32::MaxValue), OverflowException);
  }
  
  TEST(ConvertTest, ToByteFromInt64) {
    ASSERT_EQ(0, Convert::ToByte((int64)0));
    ASSERT_EQ(1, Convert::ToByte((int64)1));
    ASSERT_EQ(255, Convert::ToByte((int64)255));
    ASSERT_THROW(Convert::ToByte(Int64::MinValue), OverflowException);
    ASSERT_THROW(Convert::ToByte(Int64::MaxValue), OverflowException);
  }
  
  TEST(ConvertTest, ToByteFromSByte) {
    ASSERT_EQ(0, Convert::ToByte((sbyte)0));
    ASSERT_EQ(1, Convert::ToByte((sbyte)1));
    ASSERT_EQ(112, Convert::ToByte((sbyte)112));
    ASSERT_THROW(Convert::ToByte(SByte::MinValue), OverflowException);
    ASSERT_EQ(SByte::MaxValue, Convert::ToByte(SByte::MaxValue));
  }
  
  TEST(ConvertTest, ToByteFromSingle) {
    ASSERT_EQ(0, Convert::ToByte((float)0));
    ASSERT_EQ(1, Convert::ToByte((float)1));
    ASSERT_EQ(125, (byte)125.8997);
    ASSERT_EQ(126, Convert::ToByte((float)125.8997));
    ASSERT_THROW(Convert::ToByte(Single::MinValue), OverflowException);
    ASSERT_THROW(Convert::ToByte(Single::MaxValue), OverflowException);
  }
  
  TEST(ConvertTest, ToByteFromString) {
    ASSERT_EQ(0, Convert::ToByte(string("0")));
    ASSERT_EQ(1, Convert::ToByte(string("1")));
    ASSERT_EQ(121, Convert::ToByte(string("121")));
    ASSERT_EQ(255, Convert::ToByte(string("255")));
    
    ASSERT_THROW(Convert::ToByte(string("256")), OverflowException);
  }
  
  TEST(ConvertTest, ToByteFromConstChar) {
    ASSERT_EQ(0, Convert::ToByte("0"));
    ASSERT_EQ(1, Convert::ToByte("1"));
    ASSERT_EQ(121, Convert::ToByte("121"));
    ASSERT_EQ(255, Convert::ToByte("255"));
    
    ASSERT_THROW(Convert::ToByte("256"), OverflowException);
  }
  
  TEST(ConvertTest, ToByteFromUInt16) {
    ASSERT_EQ(0, Convert::ToByte((uint16)0));
    ASSERT_EQ(1, Convert::ToByte((uint16)1));
    ASSERT_EQ(167, Convert::ToByte((uint16)167));
    ASSERT_EQ(UInt16::MinValue, Convert::ToByte(UInt16::MinValue));
    ASSERT_THROW(Convert::ToByte(UInt16::MaxValue), OverflowException);
  }
  
  TEST(ConvertTest, ToByteFromUInt32) {
    ASSERT_EQ(0, Convert::ToByte((uint32)0));
    ASSERT_EQ(1, Convert::ToByte((uint32)1));
    ASSERT_EQ(189, Convert::ToByte((uint32)189));
    ASSERT_EQ(UInt32::MinValue, Convert::ToByte(UInt32::MinValue));
    ASSERT_THROW(Convert::ToByte(UInt32::MaxValue), OverflowException);
  }
  
  TEST(ConvertTest, ToByteFromUInt64) {
    ASSERT_EQ(0, Convert::ToByte((uint64)0));
    ASSERT_EQ(1, Convert::ToByte((uint64)1));
    ASSERT_EQ(255, Convert::ToByte((uint64)255));
    ASSERT_EQ(UInt64::MinValue, Convert::ToByte(UInt64::MinValue));
    ASSERT_THROW(Convert::ToByte(UInt64::MaxValue), OverflowException);
  }
  
  TEST(ConvertTest, ToCharFromIConvertible) {
    ASSERT_EQ(0, Convert::ToChar(static_cast<const IConvertible&>(Int32(0))));
    ASSERT_EQ(1, Convert::ToChar(static_cast<const IConvertible&>(SByte(1))));
    ASSERT_EQ(129, Convert::ToChar(static_cast<const IConvertible&>(UInt64(129))));
    ASSERT_EQ('T', Convert::ToChar(static_cast<const IConvertible&>(String("T"))));
    ASSERT_EQ('\n', Convert::ToChar(static_cast<const IConvertible&>(String("\n"))));
  }
  
  TEST(ConvertTest, ToCharFromBoolean) {
    ASSERT_EQ('0', Convert::ToChar(false));
    ASSERT_EQ('1', Convert::ToChar(true));
  }
  
  TEST(ConvertTest, ToCharFromByte) {
    ASSERT_EQ(0, Convert::ToChar((byte)0));
    ASSERT_EQ(1, Convert::ToChar((byte)1));
    ASSERT_EQ('T', Convert::ToChar((byte)84));
    ASSERT_EQ(Byte::MinValue, Convert::ToChar(Byte::MinValue));
    ASSERT_EQ(Byte::MaxValue, Convert::ToChar(Byte::MaxValue));
  }
  
  TEST(ConvertTest, ToCharFromChar) {
    ASSERT_EQ(0, Convert::ToChar((char32)0));
    ASSERT_EQ(1, Convert::ToChar((char32)1));
    ASSERT_EQ('T', Convert::ToChar((char32)'T'));
    ASSERT_EQ(Char::MinValue, Convert::ToChar(Char::MinValue));
    ASSERT_EQ(Char::MaxValue, Convert::ToChar(Char::MaxValue));
  }
  
  TEST(ConvertTest, ToCharFromDateTime) {
    ASSERT_THROW(Convert::ToChar(DateTime::Now()), InvalidCastException);
  }
  
  TEST(ConvertTest, ToCharFromDouble) {
    ASSERT_EQ(0, Convert::ToChar((double)0));
    ASSERT_EQ(1, Convert::ToChar((double)1));
    ASSERT_EQ(14, Convert::ToChar(13.7896));
    ASSERT_THROW(Convert::ToChar(Double::MinValue), OverflowException);
    ASSERT_THROW(Convert::ToChar(Double::MaxValue), OverflowException);
  }
  
  TEST(ConvertTest, ToCharFromInt16) {
    ASSERT_EQ(0, Convert::ToChar((int16)0));
    ASSERT_EQ(1, Convert::ToChar((int16)1));
    ASSERT_EQ(167, Convert::ToChar((int16)167));
    ASSERT_THROW(Convert::ToChar(Int16::MinValue), OverflowException);
    ASSERT_EQ(Int16::MaxValue, Convert::ToInt32(Convert::ToChar(Int16::MaxValue)));
  }
  
  TEST(ConvertTest, ToCharFromInt32) {
    ASSERT_EQ(0, Convert::ToChar((int32)0));
    ASSERT_EQ(1, Convert::ToChar((int32)1));
    ASSERT_EQ(189, Convert::ToChar((int32)189));
    ASSERT_THROW(Convert::ToChar(Int32::MinValue), OverflowException);
    ASSERT_THROW(Convert::ToChar(Int32::MaxValue), OverflowException);
  }
  
  /*
   TEST(ConvertTest, ToCharFromInt64)
   {
   ASSERT_EQ(0, Convert::ToChar((int64)0));
   ASSERT_EQ(1, Convert::ToChar((int64)1));
   ASSERT_EQ(255, Convert::ToChar((int64)255));
   ASSERT_THROW(Convert::ToChar(Int64::MinValue), OverflowException);
   ASSERT_THROW(Convert::ToChar(Int64::MaxValue), OverflowException);
   }
  
   TEST(ConvertTest, ToCharFromSByte)
   {
   ASSERT_EQ(0, Convert::ToChar((sbyte)0));
   ASSERT_EQ(1, Convert::ToChar((sbyte)1));
   ASSERT_EQ(112, Convert::ToChar((sbyte)112));
   ASSERT_THROW(Convert::ToChar(SByte::MinValue), OverflowException);
   ASSERT_EQ(SByte::MaxValue(), Convert::ToChar(SByte::MaxValue));
   }
  
   TEST(ConvertTest, ToCharFromSingle)
   {
   ASSERT_EQ(0, Convert::ToChar((float)0));
   ASSERT_EQ(1, Convert::ToChar((float)1));
   ASSERT_EQ(125, Convert::ToChar((float)125.8997));
   ASSERT_THROW(Convert::ToChar(Single::MinValue), OverflowException);
   ASSERT_THROW(Convert::ToChar(Single::MaxValue), OverflowException);
   }
  
   TEST(ConvertTest, ToCharFromString)
   {
   ASSERT_EQ(0, Convert::ToChar("0"_S));
   ASSERT_EQ(1, Convert::ToChar("1"_S));
   ASSERT_EQ(121, Convert::ToChar("121"_S));
   ASSERT_EQ(255, Convert::ToChar("255"_S));
  
   ASSERT_THROW(Convert::ToChar("256"_S), OverflowException);
   }
  
   TEST(ConvertTest, ToCharFromConstChar)
   {
   ASSERT_EQ(0, Convert::ToChar("0"));
   ASSERT_EQ(1, Convert::ToChar("1"));
   ASSERT_EQ(121, Convert::ToChar("121"));
   ASSERT_EQ(255, Convert::ToChar("255"));
  
   ASSERT_THROW(Convert::ToChar("256"), OverflowException);
  
   const char* nullStr = null;
   ASSERT_THROW(Convert::ToChar(nullStr), ArgumentNullException);
   }
  
   TEST(ConvertTest, ToCharFromUInt16)
   {
   ASSERT_EQ(0, Convert::ToChar((uint16)0));
   ASSERT_EQ(1, Convert::ToChar((uint16)1));
   ASSERT_EQ(167, Convert::ToChar((uint16)167));
   ASSERT_EQ(UInt16::MinValue, Convert::ToChar(UInt16::MinValue));
   ASSERT_THROW(Convert::ToChar(UInt16::MaxValue), OverflowException);
   }
  
   TEST(ConvertTest, ToCharFromUInt32)
   {
   ASSERT_EQ(0, Convert::ToChar((uint32)0));
   ASSERT_EQ(1, Convert::ToChar((uint32)1));
   ASSERT_EQ(189, Convert::ToChar((uint32)189));
   ASSERT_EQ(UInt32::MinValue, Convert::ToChar(UInt32::MinValue));
   ASSERT_THROW(Convert::ToChar(UInt32::MaxValue), OverflowException);
   }
  
   TEST(ConvertTest, ToCharFromUInt64)
   {
   ASSERT_EQ(0, Convert::ToChar((uint64)0));
   ASSERT_EQ(1, Convert::ToChar((uint64)1));
   ASSERT_EQ(255, Convert::ToChar((uint64)255));
   ASSERT_EQ(UInt64::MinValue, Convert::ToChar(UInt64::MinValue));
   ASSERT_THROW(Convert::ToChar(UInt64::MaxValue), OverflowException);
   }
   */
  
  TEST(ConvertTest, PrimitiveTypes) {
  
    byte  valueU8 = 123;
    uint16 valueU16 = 12345;
    uint32 valueU32 = 123456789;
    uint64 valueU64 = 12345678910L;
    sbyte  valueS8 = -123;
    int16 valueS16 = -12345;
    int32 valueS32 = -123456789;
    int64 valueS64 = -12345678910;
    bool valueB = false;
    float valueS = 0.1f;
    double valueD = 0.00001;
    
    KeyValuePair< string, string > keyPair("My name is Bond", "James Bond");
    
    ASSERT_EQ(Convert::ToString(valueU8), "123");
    ASSERT_EQ(Convert::ToString(valueU16), "12345");
    ASSERT_EQ(Convert::ToString(valueU32), "123456789");
    ASSERT_EQ(Convert::ToString(valueU64), "12345678910");
    ASSERT_EQ(Convert::ToString(valueS8), "-123");
    ASSERT_EQ(Convert::ToString(valueS16), "-12345");
    ASSERT_EQ(Convert::ToString(valueS32), "-123456789");
    ASSERT_EQ(Convert::ToString(valueS64), "-12345678910");
    ASSERT_EQ(Convert::ToString(valueB), "False");
    ASSERT_EQ(Convert::ToString(valueS), "0.1");
    ASSERT_EQ(Convert::ToDouble(Convert::ToString(valueD)), valueD);
    
    ASSERT_EQ("[My name is Bond, James Bond]", Convert::ToString(keyPair));
  }
  
}
