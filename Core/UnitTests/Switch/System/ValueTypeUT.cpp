#if !defined(_WIN32)
#pragma GCC diagnostic ignored "-Wsign-compare"
#endif

#include <Switch/System/Int16.hpp>
#include <Switch/System/Int32.hpp>
#include <Switch/System/Int64.hpp>
#include <Switch/System/UInt16.hpp>
#include <Switch/System/UInt32.hpp>
#include <Switch/System/UInt64.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/Expect.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  TEST(ValueType, EqualOperatorOnNatives) {
    int32 a = 10;
    int32 b = 10;
    int16 c = 10;
    uint32 d = 10;
    uint16 e = 10;
    
    EXPECT_TRUE(a == b);
    EXPECT_TRUE(a == c);
    EXPECT_TRUE(a == (signed)d);
    EXPECT_TRUE(a == e);
  }
  
  TEST(ValueType, EqualOperatorOnValueTypes) {
    Int32 a = 10;
    Int32 b = 10;
    Int16 c = 10;
    UInt32 d = 10;
    UInt16 e = 10;
    
    EXPECT_TRUE(a == b);
    EXPECT_TRUE(a == c);
    Expect::True(a == d);
    EXPECT_TRUE(a == e);
  }
  
  TEST(ValueType, Equals) {
    Int32 a = 10;
    Int32 b = 10;
    Int16 c = 10;
    UInt32 d = 10;
    UInt16 e = 10;
    
    EXPECT_TRUE(a.Equals(b));
    EXPECT_FALSE(a.Equals(c));
    EXPECT_FALSE(a.Equals(d));
    EXPECT_FALSE(a.Equals(e));
  }
  
  TEST(ValueType, ByteZeroValueEqualOperator) {
    EXPECT_TRUE(Byte(0) == Byte(0));
    EXPECT_TRUE(Byte(0) == Int16(0));
    EXPECT_TRUE(Byte(0) == Int32(0));
    EXPECT_TRUE(Byte(0) == Int64(0));
    EXPECT_TRUE(Byte(0) == SByte(0));
    EXPECT_TRUE(Byte(0) == UInt16(0));
    EXPECT_TRUE(Byte(0) == UInt32(0));
    EXPECT_TRUE(Byte(0) == UInt64(0));
  }
  
  TEST(ValueType, ByteAnyValueEqualOperator) {
    EXPECT_TRUE(Byte(25) == Byte(25));
    EXPECT_TRUE(Byte(25) == Int16(25));
    EXPECT_TRUE(Byte(25) == Int32(25));
    EXPECT_TRUE(Byte(25) == Int64(25));
    EXPECT_TRUE(Byte(25) == SByte(25));
    EXPECT_TRUE(Byte(25) == UInt16(25));
    EXPECT_TRUE(Byte(25) == UInt32(25));
    EXPECT_TRUE(Byte(25) == UInt64(25));
  }
  
  TEST(ValueType, ByteMinValueEqualOperator) {
    EXPECT_TRUE(Byte(Byte::MinValue) == Byte(Byte::MinValue));
    EXPECT_TRUE(Byte(Byte::MinValue) == Int16(Byte::MinValue));
    EXPECT_TRUE(Byte(Byte::MinValue) == Int32(Byte::MinValue));
    EXPECT_TRUE(Byte(Byte::MinValue) == Int64(Byte::MinValue));
    EXPECT_TRUE(Byte(Byte::MinValue) == SByte(Byte::MinValue));
    EXPECT_TRUE(Byte(Byte::MinValue) == UInt16(Byte::MinValue));
    EXPECT_TRUE(Byte(Byte::MinValue) == UInt32(Byte::MinValue));
    EXPECT_TRUE(Byte(Byte::MinValue) == UInt64(Byte::MinValue));
  }
  
  TEST(ValueType, ByteMaxValueEqualOperator) {
    EXPECT_TRUE(Byte(Byte::MaxValue) == Byte(Byte::MaxValue));
    EXPECT_TRUE(Byte(Byte::MaxValue) == Int16(Byte::MaxValue));
    EXPECT_TRUE(Byte(Byte::MaxValue) == Int32(Byte::MaxValue));
    EXPECT_TRUE(Byte(Byte::MaxValue) == Int64(Byte::MaxValue));
    EXPECT_FALSE(Byte(Byte::MaxValue) == SByte(Byte::MaxValue));
    EXPECT_TRUE(Byte(Byte::MaxValue) == UInt16(Byte::MaxValue));
    EXPECT_TRUE(Byte(Byte::MaxValue) == UInt32(Byte::MaxValue));
    EXPECT_TRUE(Byte(Byte::MaxValue) == UInt64(Byte::MaxValue));
  }
  
  TEST(ValueType, Int16ZeroValueEqualOperator) {
    EXPECT_TRUE(Int16(0) == Byte(0));
    EXPECT_TRUE(Int16(0) == Int16(0));
    EXPECT_TRUE(Int16(0) == Int32(0));
    EXPECT_TRUE(Int16(0) == Int64(0));
    EXPECT_TRUE(Int16(0) == SByte(0));
    EXPECT_TRUE(Int16(0) == UInt16(0));
    EXPECT_TRUE(Int16(0) == UInt32(0));
    EXPECT_TRUE(Int16(0) == UInt64(0));
  }
  
  TEST(ValueType, In16AnyValueEqualOperator) {
    EXPECT_TRUE(Int16(25) == Byte(25));
    EXPECT_TRUE(Int16(25) == Int16(25));
    EXPECT_TRUE(Int16(25) == Int32(25));
    EXPECT_TRUE(Int16(25) == Int64(25));
    EXPECT_TRUE(Int16(25) == SByte(25));
    EXPECT_TRUE(Int16(25) == UInt16(25));
    EXPECT_TRUE(Int16(25) == UInt32(25));
    EXPECT_TRUE(Int16(25) == UInt64(25));

    EXPECT_FALSE(Int16(-30) == Byte(-30));
    EXPECT_TRUE(Int16(-30) == Int16(-30));
    EXPECT_TRUE(Int16(-30) == Int32(-30));
    EXPECT_TRUE(Int16(-30) == Int64(-30));
    EXPECT_TRUE(Int16(-30) == SByte(-30));
    EXPECT_FALSE(Int16(-30) == UInt16(-30));
    EXPECT_TRUE(Int16(-30) == UInt32(-30));
    EXPECT_TRUE(Int16(-30) == UInt64(-30));
}
  
  TEST(ValueType, Int16MinValueEqualOperator) {
    EXPECT_TRUE(Int16(Int16::MinValue) == Int16(Int16::MinValue));
    EXPECT_TRUE(Int16(Int16::MinValue) == Int32(Int16::MinValue));
    EXPECT_TRUE(Int16(Int16::MinValue) == Int64(Int16::MinValue));
    EXPECT_FALSE(Int16(Int16::MinValue) == UInt16(Int16::MinValue));
    EXPECT_TRUE(Int16(Int16::MinValue) == UInt32(Int16::MinValue));
    EXPECT_TRUE(Int16(Int16::MinValue) == UInt64(Int16::MinValue));
  }
  
  TEST(ValueType, Int16MaxValueEqualOperator) {
    EXPECT_TRUE(Int16(Int16::MaxValue) == Int16(Int16::MaxValue));
    EXPECT_TRUE(Int16(Int16::MaxValue) == Int32(Int16::MaxValue));
    EXPECT_TRUE(Int16(Int16::MaxValue) == Int64(Int16::MaxValue));
    EXPECT_TRUE(Int16(Int16::MaxValue) == UInt16(Int16::MaxValue));
    EXPECT_TRUE(Int16(Int16::MaxValue) == UInt32(Int16::MaxValue));
    EXPECT_TRUE(Int16(Int16::MaxValue) == UInt64(Int16::MaxValue));
  }
  
  TEST(ValueType, Int32ZeroValueEqualOperator) {
    EXPECT_TRUE(Int32(0) == Byte(0));
    EXPECT_TRUE(Int32(0) == Int16(0));
    EXPECT_TRUE(Int32(0) == Int32(0));
    EXPECT_TRUE(Int32(0) == Int64(0));
    EXPECT_TRUE(Int32(0) == SByte(0));
    EXPECT_TRUE(Int32(0) == UInt16(0));
    EXPECT_TRUE(Int32(0) == UInt32(0));
    EXPECT_TRUE(Int32(0) == UInt64(0));
  }
  
  TEST(ValueType, In32AnyValueEqualOperator) {
    EXPECT_TRUE(Int32(25) == Byte(25));
    EXPECT_TRUE(Int32(25) == Int16(25));
    EXPECT_TRUE(Int32(25) == Int32(25));
    EXPECT_TRUE(Int32(25) == Int64(25));
    EXPECT_TRUE(Int32(25) == SByte(25));
    EXPECT_TRUE(Int32(25) == UInt16(25));
    EXPECT_TRUE(Int32(25) == UInt32(25));
    EXPECT_TRUE(Int32(25) == UInt64(25));
    
    EXPECT_FALSE(Int32(-30) == Byte(-30));
    EXPECT_TRUE(Int32(-30) == Int16(-30));
    EXPECT_TRUE(Int32(-30) == Int32(-30));
    EXPECT_TRUE(Int32(-30) == Int64(-30));
    EXPECT_TRUE(Int32(-30) == SByte(-30));
    EXPECT_FALSE(Int32(-30) == UInt16(-30));
    EXPECT_TRUE(Int32(-30) == UInt32(-30));
    EXPECT_TRUE(Int32(-30) == UInt64(-30));
  }
  
  TEST(ValueType, Int32MinValueEqualOperator) {
    EXPECT_TRUE(Int32(Int32::MinValue) == Int32(Int32::MinValue));
    EXPECT_TRUE(Int32(Int32::MinValue) == Int64(Int32::MinValue));
    EXPECT_TRUE(Int32(Int32::MinValue) == UInt32(Int32::MinValue));
    EXPECT_TRUE(Int32(Int32::MinValue) == UInt64(Int32::MinValue));
  }
  
  TEST(ValueType, Int32MaxValueEqualOperator) {
    EXPECT_TRUE(Int32(Int32::MaxValue) == Int32(Int32::MaxValue));
    EXPECT_TRUE(Int32(Int32::MaxValue) == Int64(Int32::MaxValue));
    EXPECT_TRUE(Int32(Int32::MaxValue) == UInt32(Int32::MaxValue));
    EXPECT_TRUE(Int32(Int32::MaxValue) == UInt64(Int32::MaxValue));
  }
  
  TEST(ValueType, Int64ZeroValueEqualOperator) {
    EXPECT_TRUE(Int64(0) == Byte(0));
    EXPECT_TRUE(Int64(0) == Int16(0));
    EXPECT_TRUE(Int64(0) == Int32(0));
    EXPECT_TRUE(Int64(0) == Int64(0));
    EXPECT_TRUE(Int64(0) == SByte(0));
    EXPECT_TRUE(Int64(0) == UInt16(0));
    EXPECT_TRUE(Int64(0) == UInt32(0));
    EXPECT_TRUE(Int64(0) == UInt64(0));
  }
  
  TEST(ValueType, In64AnyValueEqualOperator) {
    EXPECT_TRUE(Int64(25) == Byte(25));
    EXPECT_TRUE(Int64(25) == Int16(25));
    EXPECT_TRUE(Int64(25) == Int32(25));
    EXPECT_TRUE(Int64(25) == Int64(25));
    EXPECT_TRUE(Int64(25) == SByte(25));
    EXPECT_TRUE(Int64(25) == UInt16(25));
    EXPECT_TRUE(Int64(25) == UInt32(25));
    EXPECT_TRUE(Int64(25) == UInt64(25));
    
    EXPECT_FALSE(Int64(-30) == Byte(-30));
    EXPECT_TRUE(Int64(-30) == Int16(-30));
    EXPECT_TRUE(Int64(-30) == Int32(-30));
    EXPECT_TRUE(Int64(-30) == Int64(-30));
    EXPECT_TRUE(Int64(-30) == SByte(-30));
    EXPECT_FALSE(Int64(-30) == UInt16(-30));
    EXPECT_FALSE(Int64(-30) == UInt32(-30));
    EXPECT_TRUE(Int64(-30) == UInt64(-30));
  }
  
  TEST(ValueType, Int64MinValueEqualOperator) {
    EXPECT_TRUE(Int64(Int64::MinValue) == Int64(Int64::MinValue));
    EXPECT_TRUE(Int64(Int64::MinValue) == UInt64(Int64::MinValue));
  }
  
  TEST(ValueType, Int64MaxValueEqualOperator) {
    EXPECT_TRUE(Int64(Int64::MaxValue) == Int64(Int64::MaxValue));
    EXPECT_TRUE(Int64(Int64::MaxValue) == UInt64(Int64::MaxValue));
  }
  
  TEST(ValueType, SByteZeroValueEqualOperator) {
    EXPECT_TRUE(SByte(0) == Byte(0));
    EXPECT_TRUE(SByte(0) == Int16(0));
    EXPECT_TRUE(SByte(0) == Int32(0));
    EXPECT_TRUE(SByte(0) == Int64(0));
    EXPECT_TRUE(SByte(0) == SByte(0));
    EXPECT_TRUE(SByte(0) == UInt16(0));
    EXPECT_TRUE(SByte(0) == UInt32(0));
    EXPECT_TRUE(SByte(0) == UInt64(0));
  }
  
  TEST(ValueType, SByteAnyValueEqualOperator) {
    EXPECT_TRUE(SByte(25) == Byte(25));
    EXPECT_TRUE(SByte(25) == Int16(25));
    EXPECT_TRUE(SByte(25) == Int32(25));
    EXPECT_TRUE(SByte(25) == Int64(25));
    EXPECT_TRUE(SByte(25) == SByte(25));
    EXPECT_TRUE(SByte(25) == UInt16(25));
    EXPECT_TRUE(SByte(25) == UInt32(25));
    EXPECT_TRUE(SByte(25) == UInt64(25));

    EXPECT_FALSE(SByte(-30) == Byte(-30));
    EXPECT_TRUE(SByte(-30) == Int16(-30));
    EXPECT_TRUE(SByte(-30) == Int32(-30));
    EXPECT_TRUE(SByte(-30) == Int64(-30));
    EXPECT_TRUE(SByte(-30) == SByte(-30));
    EXPECT_FALSE(SByte(-30) == UInt16(-30));
    EXPECT_TRUE(SByte(-30) == UInt32(-30));
    EXPECT_TRUE(SByte(-30) == UInt64(-30));
}
  
  TEST(ValueType, SByteMinValueEqualOperator) {
    EXPECT_FALSE(SByte(SByte::MinValue) == Byte(SByte::MinValue));
    EXPECT_TRUE(SByte(SByte::MinValue) == Int16(SByte::MinValue));
    EXPECT_TRUE(SByte(SByte::MinValue) == Int32(SByte::MinValue));
    EXPECT_TRUE(SByte(SByte::MinValue) == Int64(SByte::MinValue));
    EXPECT_TRUE(SByte(SByte::MinValue) == SByte(SByte::MinValue));
    EXPECT_FALSE(SByte(SByte::MinValue) == UInt16(SByte::MinValue));
    EXPECT_TRUE(SByte(SByte::MinValue) == UInt32(SByte::MinValue));
    EXPECT_TRUE(SByte(SByte::MinValue) == UInt64(SByte::MinValue));
  }
  
  TEST(ValueType, SByteMaxValueEqualOperator) {
    EXPECT_TRUE(SByte(SByte::MaxValue) == Byte(SByte::MaxValue));
    EXPECT_TRUE(SByte(SByte::MaxValue) == Int16(SByte::MaxValue));
    EXPECT_TRUE(SByte(SByte::MaxValue) == Int32(SByte::MaxValue));
    EXPECT_TRUE(SByte(SByte::MaxValue) == Int64(SByte::MaxValue));
    EXPECT_TRUE(SByte(SByte::MaxValue) == SByte(SByte::MaxValue));
    EXPECT_TRUE(SByte(SByte::MaxValue) == UInt16(SByte::MaxValue));
    EXPECT_TRUE(SByte(SByte::MaxValue) == UInt32(SByte::MaxValue));
    EXPECT_TRUE(SByte(SByte::MaxValue) == UInt64(SByte::MaxValue));
  }
  
  TEST(ValueType, Format) {
    _using(Byte value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(Int16 value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(Int32 value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(Int64 value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(IntPtr value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(SByte value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(UInt16 value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(UInt32 value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(UInt64 value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(UInt64 value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(UIntPtr value = uint32(32)) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(Char value = 32) {
      EXPECT_EQ(" ", string::Format("{0}", value));
    }
    
    _using(Boolean value = true) {
      EXPECT_EQ("True", string::Format("{0}", value));
    }
    
    _using(Single value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(Double value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(string value = "32") {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(byte value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(int16 value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(int32 value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(int64 value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(sbyte value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(uint16 value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(uint32 value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(uint64 value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(uint64 value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(char32 value = 32) {
      EXPECT_EQ(" ", string::Format("{0}", value));
    }
    
    _using(bool value = true) {
      EXPECT_EQ("True", string::Format("{0}", value));
    }
    
    _using(float value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(double value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(char* value = (char*)"32") {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(const char* value = "32") {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(char value = 32) {
      EXPECT_EQ(" ", string::Format("{0}", value));
    }
    
    _using(unsigned char value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(short value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(unsigned short value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(short int value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(unsigned short int value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(int value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(unsigned int value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(long value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(unsigned long value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(long int value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(unsigned long int value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(long long value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
    
    _using(unsigned long long value = 32) {
      EXPECT_EQ("32", string::Format("{0}", value));
    }
  }
}
