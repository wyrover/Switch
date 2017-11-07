#if !defined(_WIN32)
#pragma GCC diagnostic ignored "-Wsign-compare"
#endif

#include <Switch/Using.hpp>
#include <Switch/System/Byte.hpp>
#include <Switch/System/Char.hpp>
#include <Switch/System/Double.hpp>
#include <Switch/System/Int16.hpp>
#include <Switch/System/Int32.hpp>
#include <Switch/System/Int64.hpp>
#include <Switch/System/IntPtr.hpp>
#include <Switch/System/SByte.hpp>
#include <Switch/System/Single.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/UInt16.hpp>
#include <Switch/System/UInt32.hpp>
#include <Switch/System/UInt64.hpp>
#include <Switch/System/UIntPtr.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(ValueTypeTest, EqualOperatorOnNatives) {
    int32 a = 10;
    int32 b = 10;
    int16 c = 10;
    uint32 d = 10;
    uint16 e = 10;
    
    ASSERT_TRUE(a == b);
    ASSERT_TRUE(a == c);
    ASSERT_TRUE(a == (signed)d);
    ASSERT_TRUE(a == e);
  }
  
  TEST(ValueTypeTest, EqualOperatorOnValueTypes) {
    Int32 a = 10;
    Int32 b = 10;
    Int16 c = 10;
    UInt32 d = 10;
    UInt16 e = 10;
    
    ASSERT_TRUE(a == b);
    ASSERT_TRUE(a == c);
    ASSERT_TRUE(a == d);
    ASSERT_TRUE(a == e);
  }
  
  TEST(ValueTypeTest, Equals) {
    Int32 a = 10;
    Int32 b = 10;
    Int16 c = 10;
    UInt32 d = 10;
    UInt16 e = 10;
    
    ASSERT_TRUE(a.Equals(b));
    ASSERT_FALSE(a.Equals(c));
    ASSERT_FALSE(a.Equals(d));
    ASSERT_FALSE(a.Equals(e));
  }
  
  TEST(ValueTypeTest, ByteZeroValueEqualOperator) {
    ASSERT_TRUE(Byte(0) == Byte(0));
    ASSERT_TRUE(Byte(0) == Int16(0));
    ASSERT_TRUE(Byte(0) == Int32(0));
    ASSERT_TRUE(Byte(0) == Int64(0));
    ASSERT_TRUE(Byte(0) == SByte(0));
    ASSERT_TRUE(Byte(0) == UInt16(0));
    ASSERT_TRUE(Byte(0) == UInt32(0));
    ASSERT_TRUE(Byte(0) == UInt64(0));
  }
  
  TEST(ValueTypeTest, ByteAnyValueEqualOperator) {
    ASSERT_TRUE(Byte(25) == Byte(25));
    ASSERT_TRUE(Byte(25) == Int16(25));
    ASSERT_TRUE(Byte(25) == Int32(25));
    ASSERT_TRUE(Byte(25) == Int64(25));
    ASSERT_TRUE(Byte(25) == SByte(25));
    ASSERT_TRUE(Byte(25) == UInt16(25));
    ASSERT_TRUE(Byte(25) == UInt32(25));
    ASSERT_TRUE(Byte(25) == UInt64(25));
  }
  
  TEST(ValueTypeTest, ByteMinValueEqualOperator) {
    ASSERT_TRUE(Byte(Byte::MinValue) == Byte(Byte::MinValue));
    ASSERT_TRUE(Byte(Byte::MinValue) == Int16(Byte::MinValue));
    ASSERT_TRUE(Byte(Byte::MinValue) == Int32(Byte::MinValue));
    ASSERT_TRUE(Byte(Byte::MinValue) == Int64(Byte::MinValue));
    ASSERT_TRUE(Byte(Byte::MinValue) == SByte(Byte::MinValue));
    ASSERT_TRUE(Byte(Byte::MinValue) == UInt16(Byte::MinValue));
    ASSERT_TRUE(Byte(Byte::MinValue) == UInt32(Byte::MinValue));
    ASSERT_TRUE(Byte(Byte::MinValue) == UInt64(Byte::MinValue));
  }
  
  TEST(ValueTypeTest, ByteMaxValueEqualOperator) {
    ASSERT_TRUE(Byte(Byte::MaxValue) == Byte(Byte::MaxValue));
    ASSERT_TRUE(Byte(Byte::MaxValue) == Int16(Byte::MaxValue));
    ASSERT_TRUE(Byte(Byte::MaxValue) == Int32(Byte::MaxValue));
    ASSERT_TRUE(Byte(Byte::MaxValue) == Int64(Byte::MaxValue));
    ASSERT_FALSE(Byte(Byte::MaxValue) == SByte(Byte::MaxValue));
    ASSERT_TRUE(Byte(Byte::MaxValue) == UInt16(Byte::MaxValue));
    ASSERT_TRUE(Byte(Byte::MaxValue) == UInt32(Byte::MaxValue));
    ASSERT_TRUE(Byte(Byte::MaxValue) == UInt64(Byte::MaxValue));
  }
  
  TEST(ValueTypeTest, Int16ZeroValueEqualOperator) {
    ASSERT_TRUE(Int16(0) == Byte(0));
    ASSERT_TRUE(Int16(0) == Int16(0));
    ASSERT_TRUE(Int16(0) == Int32(0));
    ASSERT_TRUE(Int16(0) == Int64(0));
    ASSERT_TRUE(Int16(0) == SByte(0));
    ASSERT_TRUE(Int16(0) == UInt16(0));
    ASSERT_TRUE(Int16(0) == UInt32(0));
    ASSERT_TRUE(Int16(0) == UInt64(0));
  }
  
  TEST(ValueTypeTest, In16AnyValueEqualOperator) {
    ASSERT_TRUE(Int16(25) == Byte(25));
    ASSERT_TRUE(Int16(25) == Int16(25));
    ASSERT_TRUE(Int16(25) == Int32(25));
    ASSERT_TRUE(Int16(25) == Int64(25));
    ASSERT_TRUE(Int16(25) == SByte(25));
    ASSERT_TRUE(Int16(25) == UInt16(25));
    ASSERT_TRUE(Int16(25) == UInt32(25));
    ASSERT_TRUE(Int16(25) == UInt64(25));

    ASSERT_FALSE(Int16(-30) == Byte(-30));
    ASSERT_TRUE(Int16(-30) == Int16(-30));
    ASSERT_TRUE(Int16(-30) == Int32(-30));
    ASSERT_TRUE(Int16(-30) == Int64(-30));
    ASSERT_TRUE(Int16(-30) == SByte(-30));
    ASSERT_FALSE(Int16(-30) == UInt16(-30));
    ASSERT_TRUE(Int16(-30) == UInt32(-30));
    ASSERT_TRUE(Int16(-30) == UInt64(-30));
}
  
  TEST(ValueTypeTest, Int16MinValueEqualOperator) {
    ASSERT_TRUE(Int16(Int16::MinValue) == Int16(Int16::MinValue));
    ASSERT_TRUE(Int16(Int16::MinValue) == Int32(Int16::MinValue));
    ASSERT_TRUE(Int16(Int16::MinValue) == Int64(Int16::MinValue));
    ASSERT_FALSE(Int16(Int16::MinValue) == UInt16(Int16::MinValue));
    ASSERT_TRUE(Int16(Int16::MinValue) == UInt32(Int16::MinValue));
    ASSERT_TRUE(Int16(Int16::MinValue) == UInt64(Int16::MinValue));
  }
  
  TEST(ValueTypeTest, Int16MaxValueEqualOperator) {
    ASSERT_TRUE(Int16(Int16::MaxValue) == Int16(Int16::MaxValue));
    ASSERT_TRUE(Int16(Int16::MaxValue) == Int32(Int16::MaxValue));
    ASSERT_TRUE(Int16(Int16::MaxValue) == Int64(Int16::MaxValue));
    ASSERT_TRUE(Int16(Int16::MaxValue) == UInt16(Int16::MaxValue));
    ASSERT_TRUE(Int16(Int16::MaxValue) == UInt32(Int16::MaxValue));
    ASSERT_TRUE(Int16(Int16::MaxValue) == UInt64(Int16::MaxValue));
  }
  
  TEST(ValueTypeTest, Int32ZeroValueEqualOperator) {
    ASSERT_TRUE(Int32(0) == Byte(0));
    ASSERT_TRUE(Int32(0) == Int16(0));
    ASSERT_TRUE(Int32(0) == Int32(0));
    ASSERT_TRUE(Int32(0) == Int64(0));
    ASSERT_TRUE(Int32(0) == SByte(0));
    ASSERT_TRUE(Int32(0) == UInt16(0));
    ASSERT_TRUE(Int32(0) == UInt32(0));
    ASSERT_TRUE(Int32(0) == UInt64(0));
  }
  
  TEST(ValueTypeTest, In32AnyValueEqualOperator) {
    ASSERT_TRUE(Int32(25) == Byte(25));
    ASSERT_TRUE(Int32(25) == Int16(25));
    ASSERT_TRUE(Int32(25) == Int32(25));
    ASSERT_TRUE(Int32(25) == Int64(25));
    ASSERT_TRUE(Int32(25) == SByte(25));
    ASSERT_TRUE(Int32(25) == UInt16(25));
    ASSERT_TRUE(Int32(25) == UInt32(25));
    ASSERT_TRUE(Int32(25) == UInt64(25));
    
    ASSERT_FALSE(Int32(-30) == Byte(-30));
    ASSERT_TRUE(Int32(-30) == Int16(-30));
    ASSERT_TRUE(Int32(-30) == Int32(-30));
    ASSERT_TRUE(Int32(-30) == Int64(-30));
    ASSERT_TRUE(Int32(-30) == SByte(-30));
    ASSERT_FALSE(Int32(-30) == UInt16(-30));
    ASSERT_TRUE(Int32(-30) == UInt32(-30));
    ASSERT_TRUE(Int32(-30) == UInt64(-30));
  }
  
  TEST(ValueTypeTest, Int32MinValueEqualOperator) {
    ASSERT_TRUE(Int32(Int32::MinValue) == Int32(Int32::MinValue));
    ASSERT_TRUE(Int32(Int32::MinValue) == Int64(Int32::MinValue));
    ASSERT_TRUE(Int32(Int32::MinValue) == UInt32(Int32::MinValue));
    ASSERT_TRUE(Int32(Int32::MinValue) == UInt64(Int32::MinValue));
  }
  
  TEST(ValueTypeTest, Int32MaxValueEqualOperator) {
    ASSERT_TRUE(Int32(Int32::MaxValue) == Int32(Int32::MaxValue));
    ASSERT_TRUE(Int32(Int32::MaxValue) == Int64(Int32::MaxValue));
    ASSERT_TRUE(Int32(Int32::MaxValue) == UInt32(Int32::MaxValue));
    ASSERT_TRUE(Int32(Int32::MaxValue) == UInt64(Int32::MaxValue));
  }
  
  TEST(ValueTypeTest, Int64ZeroValueEqualOperator) {
    ASSERT_TRUE(Int64(0) == Byte(0));
    ASSERT_TRUE(Int64(0) == Int16(0));
    ASSERT_TRUE(Int64(0) == Int32(0));
    ASSERT_TRUE(Int64(0) == Int64(0));
    ASSERT_TRUE(Int64(0) == SByte(0));
    ASSERT_TRUE(Int64(0) == UInt16(0));
    ASSERT_TRUE(Int64(0) == UInt32(0));
    ASSERT_TRUE(Int64(0) == UInt64(0));
  }
  
  TEST(ValueTypeTest, In64AnyValueEqualOperator) {
    ASSERT_TRUE(Int64(25) == Byte(25));
    ASSERT_TRUE(Int64(25) == Int16(25));
    ASSERT_TRUE(Int64(25) == Int32(25));
    ASSERT_TRUE(Int64(25) == Int64(25));
    ASSERT_TRUE(Int64(25) == SByte(25));
    ASSERT_TRUE(Int64(25) == UInt16(25));
    ASSERT_TRUE(Int64(25) == UInt32(25));
    ASSERT_TRUE(Int64(25) == UInt64(25));
    
    ASSERT_FALSE(Int64(-30) == Byte(-30));
    ASSERT_TRUE(Int64(-30) == Int16(-30));
    ASSERT_TRUE(Int64(-30) == Int32(-30));
    ASSERT_TRUE(Int64(-30) == Int64(-30));
    ASSERT_TRUE(Int64(-30) == SByte(-30));
    ASSERT_FALSE(Int64(-30) == UInt16(-30));
    ASSERT_FALSE(Int64(-30) == UInt32(-30));
    ASSERT_TRUE(Int64(-30) == UInt64(-30));
  }
  
  TEST(ValueTypeTest, Int64MinValueEqualOperator) {
    ASSERT_TRUE(Int64(Int64::MinValue) == Int64(Int64::MinValue));
    ASSERT_TRUE(Int64(Int64::MinValue) == UInt64(Int64::MinValue));
  }
  
  TEST(ValueTypeTest, Int64MaxValueEqualOperator) {
    ASSERT_TRUE(Int64(Int64::MaxValue) == Int64(Int64::MaxValue));
    ASSERT_TRUE(Int64(Int64::MaxValue) == UInt64(Int64::MaxValue));
  }
  
  TEST(ValueTypeTest, SByteZeroValueEqualOperator) {
    ASSERT_TRUE(SByte(0) == Byte(0));
    ASSERT_TRUE(SByte(0) == Int16(0));
    ASSERT_TRUE(SByte(0) == Int32(0));
    ASSERT_TRUE(SByte(0) == Int64(0));
    ASSERT_TRUE(SByte(0) == SByte(0));
    ASSERT_TRUE(SByte(0) == UInt16(0));
    ASSERT_TRUE(SByte(0) == UInt32(0));
    ASSERT_TRUE(SByte(0) == UInt64(0));
  }
  
  TEST(ValueTypeTest, SByteAnyValueEqualOperator) {
    ASSERT_TRUE(SByte(25) == Byte(25));
    ASSERT_TRUE(SByte(25) == Int16(25));
    ASSERT_TRUE(SByte(25) == Int32(25));
    ASSERT_TRUE(SByte(25) == Int64(25));
    ASSERT_TRUE(SByte(25) == SByte(25));
    ASSERT_TRUE(SByte(25) == UInt16(25));
    ASSERT_TRUE(SByte(25) == UInt32(25));
    ASSERT_TRUE(SByte(25) == UInt64(25));

    ASSERT_FALSE(SByte(-30) == Byte(-30));
    ASSERT_TRUE(SByte(-30) == Int16(-30));
    ASSERT_TRUE(SByte(-30) == Int32(-30));
    ASSERT_TRUE(SByte(-30) == Int64(-30));
    ASSERT_TRUE(SByte(-30) == SByte(-30));
    ASSERT_FALSE(SByte(-30) == UInt16(-30));
    ASSERT_TRUE(SByte(-30) == UInt32(-30));
    ASSERT_TRUE(SByte(-30) == UInt64(-30));
}
  
  TEST(ValueTypeTest, SByteMinValueEqualOperator) {
    ASSERT_FALSE(SByte(SByte::MinValue) == Byte(SByte::MinValue));
    ASSERT_TRUE(SByte(SByte::MinValue) == Int16(SByte::MinValue));
    ASSERT_TRUE(SByte(SByte::MinValue) == Int32(SByte::MinValue));
    ASSERT_TRUE(SByte(SByte::MinValue) == Int64(SByte::MinValue));
    ASSERT_TRUE(SByte(SByte::MinValue) == SByte(SByte::MinValue));
    ASSERT_FALSE(SByte(SByte::MinValue) == UInt16(SByte::MinValue));
    ASSERT_TRUE(SByte(SByte::MinValue) == UInt32(SByte::MinValue));
    ASSERT_TRUE(SByte(SByte::MinValue) == UInt64(SByte::MinValue));
  }
  
  TEST(ValueTypeTest, SByteMaxValueEqualOperator) {
    ASSERT_TRUE(SByte(SByte::MaxValue) == Byte(SByte::MaxValue));
    ASSERT_TRUE(SByte(SByte::MaxValue) == Int16(SByte::MaxValue));
    ASSERT_TRUE(SByte(SByte::MaxValue) == Int32(SByte::MaxValue));
    ASSERT_TRUE(SByte(SByte::MaxValue) == Int64(SByte::MaxValue));
    ASSERT_TRUE(SByte(SByte::MaxValue) == SByte(SByte::MaxValue));
    ASSERT_TRUE(SByte(SByte::MaxValue) == UInt16(SByte::MaxValue));
    ASSERT_TRUE(SByte(SByte::MaxValue) == UInt32(SByte::MaxValue));
    ASSERT_TRUE(SByte(SByte::MaxValue) == UInt64(SByte::MaxValue));
  }
  
  TEST(ValueTypeTest, Format) {
    _using(Byte value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(Int16 value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(Int32 value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(Int64 value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(IntPtr value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(SByte value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(UInt16 value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(UInt32 value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(UInt64 value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(UInt64 value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(UIntPtr value = uint32(32)) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(Char value = 32) {
      ASSERT_EQ(" ", string::Format("{0}", value));
    }
    
    _using(Boolean value = true) {
      ASSERT_EQ("True", string::Format("{0}", value));
    }
    
    _using(Single value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(Double value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(string value = "32") {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(byte value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(int16 value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(int32 value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(int64 value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(sbyte value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(uint16 value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(uint32 value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(uint64 value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(uint64 value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(char32 value = 32) {
      ASSERT_EQ(" ", string::Format("{0}", value));
    }
    
    _using(bool value = true) {
      ASSERT_EQ("True", string::Format("{0}", value));
    }
    
    _using(float value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(double value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(char* value = (char*)"32") {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(const char* value = "32") {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(char value = 32) {
      ASSERT_EQ(" ", string::Format("{0}", value));
    }
    
    _using(unsigned char value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(short value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(unsigned short value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(short int value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(unsigned short int value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(int value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(unsigned int value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(long value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(unsigned long value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(long int value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(unsigned long int value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(long long value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
    
    _using(unsigned long long value = 32) {
      ASSERT_EQ("32", string::Format("{0}", value));
    }
  }
}
