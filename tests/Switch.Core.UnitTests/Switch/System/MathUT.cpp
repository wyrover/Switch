#include <Switch/System/Math.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  static bool IsApproximatelyEquals(double value1, double value2, double epsilon) {
    // If they are equal anyway, just return True.
    if (value1 == value2)
      return true;

    // Handle NaN, Infinity.
    if (Double::IsInfinity(value1) || Double::IsNaN(value1))
      return value1 == value2;
    else if (Double::IsInfinity(value2) || Double::IsNaN(value2))
      return value1 == value2;

    // Handle zero to avoid division by zero
    double divisor = Math::Max(value1, value2);
    if (divisor == 0.0)
      divisor = Math::Min(value1, value2);

    return Math::Abs(value1 - value2) / divisor <= epsilon;
  }

  static bool IsApproximatelyEquals(double value1, double value2) {
    return IsApproximatelyEquals(value1, value2, 0.0000000001);
  }

  static double ToRadians(double degrees) {
    return degrees * (Math::PI / 180);
  }

  static double ToDegrees(double radian) {
    return radian * (180 / Math::PI);
  }

  TEST(MathTest, IsApproximatelyEquals) {
    double one1 = .1 * 10;
    double one2 = 0;
    for (int ctr = 1; ctr <= 10; ctr++)
      one2 += .1;

    ASSERT_FALSE(one1 == one2);
    ASSERT_TRUE(IsApproximatelyEquals(one1, one2, .000000001));
  }

  TEST(MathTest, ToRadians) {
    ASSERT_TRUE(IsApproximatelyEquals(-6.28318530717959, ToRadians(-360), .000000000000001));
    ASSERT_TRUE(IsApproximatelyEquals(-4.71238898038469, ToRadians(-270), .000000000000001));
    ASSERT_TRUE(IsApproximatelyEquals(-3.14159265358979, ToRadians(-180), .000000000000001));
    ASSERT_TRUE(IsApproximatelyEquals(-1.5707963267949, ToRadians(-90), .00000000000001));
    ASSERT_EQ(0, ToRadians(0));
    ASSERT_TRUE(IsApproximatelyEquals(1.5707963267949, ToRadians(90), .00000000000001));
    ASSERT_TRUE(IsApproximatelyEquals(3.14159265358979, ToRadians(180), .000000000000001));
    ASSERT_TRUE(IsApproximatelyEquals(4.71238898038469, ToRadians(270), .000000000000001));
    ASSERT_TRUE(IsApproximatelyEquals(6.28318530717959, ToRadians(360), .000000000000001));
  }

  TEST(MathTest, ToDegrees) {
    ASSERT_TRUE(IsApproximatelyEquals(-360, ToDegrees(-6.28318530717959), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(-270, ToDegrees(-4.71238898038469), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(-180, ToDegrees(-3.14159265358979), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(-90, ToDegrees(-1.5707963267949), .000000001));
    ASSERT_EQ(0, ToDegrees(0));
    ASSERT_TRUE(IsApproximatelyEquals(90, ToDegrees(1.5707963267949), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(180, ToDegrees(3.14159265358979), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(270, ToDegrees(4.71238898038469), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(360, ToDegrees(6.28318530717959), .000000001));
  }

  TEST(MathTest, ToDegreesToRadians) {
    ASSERT_EQ(-360, ToDegrees(ToRadians(-360)));
    ASSERT_EQ(-270, ToDegrees(ToRadians(-270)));
    ASSERT_EQ(-180, ToDegrees(ToRadians(-180)));
    ASSERT_EQ(-90, ToDegrees(ToRadians(-90)));
    ASSERT_EQ(0, ToDegrees(ToRadians(0)));
    ASSERT_EQ(90, ToDegrees(ToRadians(90)));
    ASSERT_EQ(180, ToDegrees(ToRadians(180)));
    ASSERT_EQ(270, ToDegrees(ToRadians(270)));
    ASSERT_EQ(360, ToDegrees(ToRadians(360)));
  }

  TEST(MathTest, E) {
    ASSERT_EQ(2.7182818284590452354, Math::E);
  }

  TEST(MathTest, PI) {
    ASSERT_EQ(3.14159265358979323846, Math::PI);
  }

  TEST(MathTest, AbsDouble) {
    ASSERT_EQ(Double::MaxValue, Math::Abs(Double::MaxValue));
    ASSERT_EQ(double(1.6354E-16), Math::Abs(double(1.6354E-16)));
    ASSERT_EQ(double(15.098123), Math::Abs(double(15.098123)));
    ASSERT_EQ(double(.0), Math::Abs(double(.0)));
    ASSERT_EQ(double(19.069713), Math::Abs(double(-19.069713)));
    ASSERT_EQ(double(15.058e18), Math::Abs(double(-15.058e18)));
    ASSERT_EQ(-Double::MinValue, Math::Abs(Double::MinValue));
  }

  TEST(MathTest, AbsInt16) {
    ASSERT_EQ(Int16::MaxValue, Math::Abs(Int16::MaxValue));
    ASSERT_EQ(int16(10328), Math::Abs(int16(10328)));
    ASSERT_EQ(int16(0), Math::Abs(int16(0)));
    ASSERT_EQ(int16(1476), Math::Abs(int16(-1476)));
    ASSERT_THROW(Math::Abs(Int16::MinValue), OverflowException);
  }

  TEST(MathTest, AbsInt32) {
    ASSERT_EQ(Int32::MaxValue, Math::Abs(Int32::MaxValue));
    ASSERT_EQ(16921, Math::Abs(16921));
    ASSERT_EQ(0, Math::Abs(0));
    ASSERT_EQ(804128, Math::Abs(-804128));
    ASSERT_THROW(Math::Abs(Int32::MinValue), OverflowException);
  }

  TEST(MathTest, AbsInt64) {
    ASSERT_EQ(Int64::MaxValue, Math::Abs(Int64::MaxValue));
    ASSERT_EQ(int64(109013), Math::Abs(int64(109013)));
    ASSERT_EQ(int64(0), Math::Abs(int64(0)));
    ASSERT_EQ(int64(6871982), Math::Abs(int64(-6871982)));
    ASSERT_THROW(Math::Abs(Int64::MinValue), OverflowException);
  }

  TEST(MathTest, AbsSByte) {
    ASSERT_EQ(SByte::MaxValue, Math::Abs(SByte::MaxValue));
    ASSERT_EQ(sbyte(98), Math::Abs(sbyte(98)));
    ASSERT_EQ(sbyte(0), Math::Abs(sbyte(0)));
    ASSERT_EQ(sbyte(32), Math::Abs(sbyte(-32)));
    ASSERT_THROW(Math::Abs(SByte::MinValue), OverflowException);
  }

  TEST(MathTest, AbsSingle) {
    ASSERT_EQ(Single::MaxValue, Math::Abs(Single::MaxValue));
    ASSERT_EQ(16.354e-12f, Math::Abs(16.354e-12f));
    ASSERT_EQ(15.098123f, Math::Abs(15.098123f));
    ASSERT_EQ(.0f, Math::Abs(.0f));
    ASSERT_EQ(19.069713f, Math::Abs(-19.069713f));
    ASSERT_EQ(15.058e17f, Math::Abs(-15.058e17f));
    ASSERT_EQ(-Single::MinValue, Math::Abs(Single::MinValue));
  }

  TEST(MathTest, Acos) {
    ASSERT_TRUE(Double::IsNaN(Math::Acos(-1.1)));
    ASSERT_TRUE(IsApproximatelyEquals(3.14159265358979, Math::Acos(-1), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(2.0943951023932, Math::Acos(-.5), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(1.5707963267949, Math::Acos(.0), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(1.0471975511966, Math::Acos(.5), .000000001));
    ASSERT_EQ(.0, Math::Acos(1));
    ASSERT_TRUE(Double::IsNaN(Math::Acos(1.1)));
  }

  TEST(MathTest, Asin) {
    ASSERT_TRUE(Double::IsNaN(Math::Asin(-1.1)));
    ASSERT_TRUE(IsApproximatelyEquals(-1.5707963267949, Math::Asin(-1), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(-0.523598775598299, Math::Asin(-.5), .000000001));
    ASSERT_EQ(.0, Math::Asin(.0));
    ASSERT_TRUE(IsApproximatelyEquals(0.523598775598299, Math::Asin(.5), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(1.5707963267949, Math::Asin(1), .000000001));
    ASSERT_TRUE(Double::IsNaN(Math::Asin(1.1)));
  }

  TEST(MathTest, Atan) {
    ASSERT_TRUE(Double::IsNaN(Math::Atan(Double::NaN)));
    ASSERT_TRUE(IsApproximatelyEquals(-1.5707963267949, Math::Atan(Double::NegativeInfinity), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(-1.41296513650674, Math::Atan(ToRadians(-360)), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(-1.36169168297116, Math::Atan(ToRadians(-270)), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(-1.26262725567891, Math::Atan(ToRadians(-180)), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(-1.00388482185389, Math::Atan(ToRadians(-90)), .000000001));
    ASSERT_EQ(.0, Math::Atan(.0));
    ASSERT_TRUE(IsApproximatelyEquals(1.00388482185389, Math::Atan(ToRadians(90)), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(1.26262725567891, Math::Atan(ToRadians(180)), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(1.36169168297116, Math::Atan(ToRadians(270)), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(1.41296513650674, Math::Atan(ToRadians(360)), .000000001));
    ASSERT_TRUE(IsApproximatelyEquals(1.5707963267949, Math::Atan(Double::PositiveInfinity), .000000001));
  }

  TEST(MathTest, Atan2) {
    ASSERT_TRUE(IsApproximatelyEquals(0.463647609000806, Math::Atan2(1, 2), .000000000000001));
    ASSERT_TRUE(IsApproximatelyEquals(0.839287844473872, Math::Atan2(127, 114), .000000000000001));
    ASSERT_EQ(0, Math::Atan2(0, 1));
    ASSERT_EQ(Math::PI, Math::Atan2(0, -1));
    ASSERT_EQ(Math::PI / 2, Math::Atan2(1, 0));
    ASSERT_EQ(-Math::PI / 2, Math::Atan2(-1, 0));
    ASSERT_TRUE(Double::IsNaN(Math::Atan2(Double::NaN, 1)));
    ASSERT_TRUE(Double::IsNaN(Math::Atan2(1, Double::NaN)));
    ASSERT_TRUE(Double::IsNaN(Math::Atan2(Double::PositiveInfinity, Double::PositiveInfinity)));
    ASSERT_TRUE(Double::IsNaN(Math::Atan2(Double::PositiveInfinity, Double::NegativeInfinity)));
    ASSERT_TRUE(Double::IsNaN(Math::Atan2(Double::NegativeInfinity, Double::NegativeInfinity)));
    ASSERT_TRUE(Double::IsNaN(Math::Atan2(Double::NegativeInfinity, Double::PositiveInfinity)));
  }

  TEST(MathTest, BigMul) {
    ASSERT_EQ(4611686014132420609LL, Math::BigMul(Int32::MaxValue, Int32::MaxValue));
  }

  TEST(MathTest, Ceiling) {
    ASSERT_EQ(8, Math::Ceiling(7.03));
    ASSERT_EQ(8, Math::Ceiling(7.64));
    ASSERT_EQ(1, Math::Ceiling(0.12));
    ASSERT_EQ(0, Math::Ceiling(-0.12));
    ASSERT_EQ(-7, Math::Ceiling(-7.1));
    ASSERT_EQ(-7, Math::Ceiling(-7.6));
  }

  TEST(MathTest, Cos) {
    ASSERT_EQ(1, Math::Cos(ToRadians(0)));
    ASSERT_TRUE(IsApproximatelyEquals(6.12303176911189E-17, Math::Cos(ToRadians(90)), .0001));
    ASSERT_TRUE(Double::IsNaN(Math::Cos(Double::NaN)));
    ASSERT_TRUE(Double::IsNaN(Math::Cos(Double::NegativeInfinity)));
    ASSERT_TRUE(Double::IsNaN(Math::Cos(Double::PositiveInfinity)));
  }

  TEST(MathTest, Cosh) {
    ASSERT_EQ(1, Math::Cosh(0));
    ASSERT_TRUE(IsApproximatelyEquals(10.0676619957778, Math::Cosh(3), .00000000000001));
    ASSERT_TRUE(IsApproximatelyEquals(11013.2329201033, Math::Cosh(10), .00000000001));
    ASSERT_TRUE(Double::IsPositiveInfinity(Math::Cosh(Double::PositiveInfinity)));
    ASSERT_TRUE(Double::IsPositiveInfinity(Math::Cosh(Double::NegativeInfinity)));
    ASSERT_TRUE(Double::IsNaN(Math::Cosh(Double::NaN)));
  }

  TEST(MathTest, DivRemInt32) {
    using_(int32 remainder = 0) {
      ASSERT_EQ(1073741, Math::DivRem(Int32::MaxValue, int32(2000), remainder));
      ASSERT_EQ(1647, remainder);
    }

    using_(int32 remainder = 0) {
      ASSERT_EQ(6, Math::DivRem(int32(13952), int32(2000), remainder));
      ASSERT_EQ(1952, remainder);
    }

    using_(int32 remainder = 0) {
      ASSERT_EQ(0, Math::DivRem(int32(0), int32(2000), remainder));
      ASSERT_EQ(0, remainder);
    }

    using_(int32 remainder = 0) {
      ASSERT_EQ(-7, Math::DivRem(int32(-14032), int32(2000), remainder));
      ASSERT_EQ(-32, remainder);
    }

    using_(int32 remainder = 0) {
      ASSERT_EQ(-1073741, Math::DivRem(Int32::MinValue, int32(2000), remainder));
      ASSERT_EQ(-1648, remainder);
    }

    using_(int32 remainder = 0) {
      ASSERT_EQ(-1073741, Math::DivRem(Int32::MaxValue, int32(-2000), remainder));
      ASSERT_EQ(1647, remainder);
    }

    using_(int32 remainder = 0) {
      ASSERT_EQ(-6, Math::DivRem(int32(13952), int32(-2000), remainder));
      ASSERT_EQ(1952, remainder);
    }

    using_(int32 remainder = 0) {
      ASSERT_EQ(0, Math::DivRem(int32(0), int32(-2000), remainder));
      ASSERT_EQ(0, remainder);
    }

    using_(int32 remainder = 0) {
      ASSERT_EQ(7, Math::DivRem(int32(-14032), int32(-2000), remainder));
      ASSERT_EQ(-32, remainder);
    }

    using_(int32 remainder = 0) {
      ASSERT_EQ(1073741, Math::DivRem(Int32::MinValue, int32(-2000), remainder));
      ASSERT_EQ(-1648, remainder);
    }
  }

  TEST(MathTest, DivRemInt64) {
    using_(int64 remainder = 0) {
      ASSERT_EQ(4611686018427387LL, Math::DivRem(Int64::MaxValue, int64(2000), remainder));
      ASSERT_EQ(1807, remainder);
    }

    using_(int64 remainder = 0) {
      ASSERT_EQ(6, Math::DivRem(int64(13952), int64(2000), remainder));
      ASSERT_EQ(1952, remainder);
    }

    using_(int64 remainder = 0) {
      ASSERT_EQ(0, Math::DivRem(int64(0), int64(2000), remainder));
      ASSERT_EQ(0, remainder);
    }

    using_(int64 remainder = 0) {
      ASSERT_EQ(-7, Math::DivRem(int64(-14032), int64(2000), remainder));
      ASSERT_EQ(-32, remainder);
    }

    using_(int64 remainder = 0) {
      ASSERT_EQ(-4611686018427387LL, Math::DivRem(Int64::MinValue, int64(2000), remainder));
      ASSERT_EQ(-1808, remainder);
    }

    using_(int64 remainder = 0) {
      ASSERT_EQ(-4611686018427387LL, Math::DivRem(Int64::MaxValue, int64(-2000), remainder));
      ASSERT_EQ(1807, remainder);
    }

    using_(int64 remainder = 0) {
      ASSERT_EQ(-6, Math::DivRem(int64(13952), int64(-2000), remainder));
      ASSERT_EQ(1952, remainder);
    }

    using_(int64 remainder = 0) {
      ASSERT_EQ(0, Math::DivRem(int64(0), int64(-2000), remainder));
      ASSERT_EQ(0, remainder);
    }

    using_(int64 remainder = 0) {
      ASSERT_EQ(7, Math::DivRem(int64(-14032), int64(-2000), remainder));
      ASSERT_EQ(-32, remainder);
    }

    using_(int64 remainder = 0) {
      ASSERT_EQ(4611686018427387LL, Math::DivRem(Int64::MinValue, int64(-2000), remainder));
      ASSERT_EQ(-1808, remainder);
    }
  }

  TEST(MathTest, Exp) {
    ASSERT_EQ(1, Math::Exp(0));
    ASSERT_TRUE(IsApproximatelyEquals(148.413159, Math::Exp(5), .000001));
    ASSERT_TRUE(Double::IsNaN(Math::Exp(Double::NaN)));
    ASSERT_TRUE(Double::IsPositiveInfinity(Math::Exp(Double::PositiveInfinity)));
    ASSERT_EQ(0, Math::Exp(Double::NegativeInfinity));
  }

  TEST(MathTest, IEEERemainder) {
    ASSERT_EQ(-1, Math::IEEERemainder(3, 2));
    ASSERT_EQ(0, Math::IEEERemainder(4, 2));
    ASSERT_EQ(1, Math::IEEERemainder(10, 3));
    ASSERT_EQ(-1, Math::IEEERemainder(11, 3));
    ASSERT_EQ(-1, Math::IEEERemainder(27, 4));
    ASSERT_EQ(-2, Math::IEEERemainder(28, 5));
    ASSERT_TRUE(IsApproximatelyEquals(1.8, Math::IEEERemainder(17.8, 4), .000000000000001));
    ASSERT_TRUE(IsApproximatelyEquals(1.4, Math::IEEERemainder(17.8, 4.1), .00000000000001));
    ASSERT_TRUE(IsApproximatelyEquals(0.0999999999999979, Math::IEEERemainder(-16.3, 4.1), .000000000000001));
    ASSERT_TRUE(IsApproximatelyEquals(1.4, Math::IEEERemainder(17.8, -4.1), .00000000000001));
    ASSERT_TRUE(IsApproximatelyEquals(-1.4, Math::IEEERemainder(-17.8, -4.1), .00000000000001));
    ASSERT_TRUE(Double::IsNaN(Math::IEEERemainder(12, 0)));
  }

  TEST(MathTest, Floor) {
    ASSERT_EQ(7, Math::Floor(7.03));
    ASSERT_EQ(7, Math::Floor(7.64));
    ASSERT_EQ(0, Math::Floor(0.12));
    ASSERT_EQ(-1, Math::Floor(-0.12));
    ASSERT_EQ(-8, Math::Floor(-7.1));
    ASSERT_EQ(-8, Math::Floor(-7.6));
  }

  TEST(MathTest, Log) {
    ASSERT_TRUE(IsApproximatelyEquals(0.18232155679395459, Math::Log(1.2), 0.0000000000000001));
    ASSERT_TRUE(Double::IsNegativeInfinity(Math::Log(0)));
    ASSERT_TRUE(Double::IsNaN(Math::Log(-1)));
    ASSERT_TRUE(Double::IsNaN(Math::Log(Double::NaN)));
    ASSERT_TRUE(Double::IsPositiveInfinity(Math::Log(Double::PositiveInfinity)));
  }

  TEST(MathTest, LogNewBase) {
    ASSERT_TRUE(IsApproximatelyEquals(3.0, Math::Log(8.0, 2.0)));
    ASSERT_TRUE(IsApproximatelyEquals(2.0, Math::Log(100.0, 10.0)));
    ASSERT_TRUE(IsApproximatelyEquals(4.0, Math::Log(65536, 16)));
    ASSERT_TRUE(Double::IsNaN(Math::Log(-1, 10)));
    ASSERT_TRUE(Double::IsNaN(Math::Log(100, -1)));
    ASSERT_TRUE(Double::IsNaN(Math::Log(2, 0)));
    ASSERT_TRUE(Double::IsNaN(Math::Log(2, Double::PositiveInfinity)));
    ASSERT_TRUE(Double::IsNaN(Math::Log(Double::NaN, 10)));
    ASSERT_TRUE(Double::IsNaN(Math::Log(100, Double::NaN)));
    ASSERT_TRUE(Double::IsNaN(Math::Log(100, 1)));
    ASSERT_TRUE(Double::IsPositiveInfinity(Math::Log(0, 0.5)));
    ASSERT_TRUE(Double::IsPositiveInfinity(Math::Log(Double::PositiveInfinity, 2)));
    ASSERT_TRUE(Double::IsNegativeInfinity(Math::Log(0, 2)));
    ASSERT_TRUE(Double::IsNegativeInfinity(Math::Log(Double::PositiveInfinity, 0.5)));
  }

  TEST(MathTest, Log10) {
    ASSERT_TRUE(IsApproximatelyEquals(0.0, Math::Log10(1)));
    ASSERT_TRUE(IsApproximatelyEquals(1, Math::Log10(10)));
    ASSERT_EQ(3, Math::Log10(1000));
    ASSERT_TRUE(Double::IsNegativeInfinity(Math::Log10(0)));
    ASSERT_TRUE(Double::IsNaN(Math::Log10(-1)));
    ASSERT_TRUE(Double::IsNaN(Math::Log10(Double::NaN)));
    ASSERT_TRUE(Double::IsPositiveInfinity(Math::Log10(Double::PositiveInfinity)));
  }

  TEST(MathTest, MaxByte) {
    ASSERT_EQ(52u, Math::Max(byte(2), byte(52)));
    ASSERT_EQ(22u, Math::Max(byte(22), byte(5)));
    ASSERT_EQ(16u, Math::Max(byte(16), byte(16)));
  }

  TEST(MathTest, MaxDouble) {
    ASSERT_EQ(52, Math::Max(double(2.0), double(52.0)));
    ASSERT_EQ(22, Math::Max(double(22.0), double(5.0)));
    ASSERT_EQ(16, Math::Max(double(16.0), double(16.0)));
  }

  TEST(MathTest, MaxInt16) {
    ASSERT_EQ(52, Math::Max(int16(2), int16(52)));
    ASSERT_EQ(22, Math::Max(int16(22), int16(5)));
    ASSERT_EQ(16, Math::Max(int16(16), int16(16)));
  }

  TEST(MathTest, MaxInt32) {
    ASSERT_EQ(52, Math::Max(int32(2), int32(52)));
    ASSERT_EQ(22, Math::Max(int32(22), int32(5)));
    ASSERT_EQ(16, Math::Max(int32(16), int32(16)));
  }

  TEST(MathTest, MaxInt64) {
    ASSERT_EQ(52, Math::Max(int64(2), int64(52)));
    ASSERT_EQ(22, Math::Max(int64(22), int64(5)));
    ASSERT_EQ(16, Math::Max(int64(16), int64(16)));
  }

  TEST(MathTest, MaxSByte) {
    ASSERT_EQ(52, Math::Max(sbyte(2), sbyte(52)));
    ASSERT_EQ(22, Math::Max(sbyte(22), sbyte(5)));
    ASSERT_EQ(16, Math::Max(sbyte(16), sbyte(16)));
  }

  TEST(MathTest, MaxSingle) {
    ASSERT_EQ(52, Math::Max(float(2.0), float(52.0)));
    ASSERT_EQ(22, Math::Max(float(22.0), float(5.0)));
    ASSERT_EQ(16, Math::Max(float(16.0), float(16.0)));
  }

  TEST(MathTest, MaxUInt16) {
    ASSERT_EQ(52u, Math::Max(uint16(2), uint16(52)));
    ASSERT_EQ(22u, Math::Max(uint16(22), uint16(5)));
    ASSERT_EQ(16u, Math::Max(uint16(16), uint16(16)));
  }

  TEST(MathTest, MaxUInt32) {
    ASSERT_EQ(52u, Math::Max(uint32(2), uint32(52)));
    ASSERT_EQ(22u, Math::Max(uint32(22), uint32(5)));
    ASSERT_EQ(16u, Math::Max(uint32(16), uint32(16)));
  }

  TEST(MathTest, MaxUInt64) {
    ASSERT_EQ(52u, Math::Max(uint64(2), uint64(52)));
    ASSERT_EQ(22u, Math::Max(uint64(22), uint64(5)));
    ASSERT_EQ(16u, Math::Max(uint64(16), uint64(16)));
  }

  TEST(MathTest, MinByte) {
    ASSERT_EQ(2u, Math::Min(byte(2), byte(52)));
    ASSERT_EQ(5u, Math::Min(byte(22), byte(5)));
    ASSERT_EQ(16u, Math::Min(byte(16), byte(16)));
  }

  TEST(MathTest, MinDouble) {
    ASSERT_EQ(2, Math::Min(double(2.0), double(52.0)));
    ASSERT_EQ(5, Math::Min(double(22.0), double(5.0)));
    ASSERT_EQ(16, Math::Min(double(16.0), double(16.0)));
  }

  TEST(MathTest, MinInt16) {
    ASSERT_EQ(2, Math::Min(int16(2), int16(52)));
    ASSERT_EQ(5, Math::Min(int16(22), int16(5)));
    ASSERT_EQ(16, Math::Min(int16(16), int16(16)));
  }

  TEST(MathTest, MinInt32) {
    ASSERT_EQ(2, Math::Min(int32(2), int32(52)));
    ASSERT_EQ(5, Math::Min(int32(22), int32(5)));
    ASSERT_EQ(16, Math::Min(int32(16), int32(16)));
  }

  TEST(MathTest, MinInt64) {
    ASSERT_EQ(2, Math::Min(int64(2), int64(52)));
    ASSERT_EQ(5, Math::Min(int64(22), int64(5)));
    ASSERT_EQ(16, Math::Min(int64(16), int64(16)));
  }

  TEST(MathTest, MinSByte) {
    ASSERT_EQ(2, Math::Min(sbyte(2), sbyte(52)));
    ASSERT_EQ(5, Math::Min(sbyte(22), sbyte(5)));
    ASSERT_EQ(16, Math::Min(sbyte(16), sbyte(16)));
  }

  TEST(MathTest, MinSingle) {
    ASSERT_EQ(2, Math::Min(float(2.0), float(52.0)));
    ASSERT_EQ(5, Math::Min(float(22.0), float(5.0)));
    ASSERT_EQ(16, Math::Min(float(16.0), float(16.0)));
  }

  TEST(MathTest, MinUInt16) {
    ASSERT_EQ(2u, Math::Min(uint16(2), uint16(52)));
    ASSERT_EQ(5u, Math::Min(uint16(22), uint16(5)));
    ASSERT_EQ(16u, Math::Min(uint16(16), uint16(16)));
  }

  TEST(MathTest, MinUInt32) {
    ASSERT_EQ(2u, Math::Min(uint32(2), uint32(52)));
    ASSERT_EQ(5u, Math::Min(uint32(22), uint32(5)));
    ASSERT_EQ(16u, Math::Min(uint32(16), uint32(16)));
  }

  TEST(MathTest, MinUInt64) {
    ASSERT_EQ(2u, Math::Min(uint64(2), uint64(52)));
    ASSERT_EQ(5u, Math::Min(uint64(22), uint64(5)));
    ASSERT_EQ(16u, Math::Min(uint64(16), uint64(16)));
  }

  TEST(MathTest, Pow) {
    ASSERT_EQ(8, Math::Pow(2, 3));
    ASSERT_TRUE(Double::IsNaN(Math::Pow(Double::NaN, 3)));
    ASSERT_TRUE(Double::IsNaN(Math::Pow(2, Double::NaN)));
    ASSERT_EQ(1, Math::Pow(2, 0));
    ASSERT_EQ(0, Math::Pow(Double::NegativeInfinity, -1));
    ASSERT_TRUE(Double::IsNegativeInfinity(Math::Pow(Double::NegativeInfinity, 11)));
    ASSERT_TRUE(Double::IsPositiveInfinity(Math::Pow(Double::NegativeInfinity, 10)));
    ASSERT_TRUE(Double::IsNaN(Math::Pow(-1, 0.5)));
    ASSERT_TRUE(Double::IsPositiveInfinity(Math::Pow(0, Double::NegativeInfinity)));
    ASSERT_EQ(0, Math::Pow(0, Double::PositiveInfinity));
    ASSERT_EQ(0, Math::Pow(-2, Double::NegativeInfinity));
    ASSERT_EQ(0, Math::Pow(2, Double::NegativeInfinity));
    ASSERT_TRUE(Double::IsPositiveInfinity(Math::Pow(-2, Double::PositiveInfinity)));
    ASSERT_TRUE(Double::IsPositiveInfinity(Math::Pow(2, Double::PositiveInfinity)));
    ASSERT_TRUE(Double::IsPositiveInfinity(Math::Pow(0, -1)));
    ASSERT_EQ(0, Math::Pow(0, 1));
    ASSERT_EQ(1, Math::Pow(1, 3));
    ASSERT_EQ(0, Math::Pow(Double::PositiveInfinity, -1));
    ASSERT_TRUE(Double::IsPositiveInfinity(Math::Pow(Double::PositiveInfinity, 1)));
  }

  TEST(MathTest, Round) {
    ASSERT_TRUE(IsApproximatelyEquals(11, Math::Round(11.1)));
    ASSERT_TRUE(IsApproximatelyEquals(11, Math::Round(11.4)));
    ASSERT_TRUE(IsApproximatelyEquals(12, Math::Round(11.5)));
    ASSERT_TRUE(IsApproximatelyEquals(12, Math::Round(11.9)));
  }

  TEST(MathTest, RoundDecimals) {
    ASSERT_TRUE(IsApproximatelyEquals(11.58, Math::Round(11.581, 2)));
    ASSERT_TRUE(IsApproximatelyEquals(11.58, Math::Round(11.584, 2)));
    ASSERT_TRUE(IsApproximatelyEquals(11.59, Math::Round(11.585, 2)));
    ASSERT_TRUE(IsApproximatelyEquals(11.59, Math::Round(11.589, 2)));
  }

  TEST(MathTest, SignDouble) {
    ASSERT_EQ(-1, Math::Sign(double(-10)));
    ASSERT_EQ(0, Math::Sign(double(0)));
    ASSERT_EQ(1, Math::Sign(double(10)));
    ASSERT_THROW(Math::Sign(Double::NaN), ArithmeticException);
  }

  TEST(MathTest, SignInt16) {
    ASSERT_EQ(-1, Math::Sign(int16(-10)));
    ASSERT_EQ(0, Math::Sign(int16(0)));
    ASSERT_EQ(1, Math::Sign(int16(10)));
  }

  TEST(MathTest, SignInt32) {
    ASSERT_EQ(-1, Math::Sign(int32(-10)));
    ASSERT_EQ(0, Math::Sign(int32(0)));
    ASSERT_EQ(1, Math::Sign(int32(10)));
  }

  TEST(MathTest, SignInt64) {
    ASSERT_EQ(-1, Math::Sign(int64(-10)));
    ASSERT_EQ(0, Math::Sign(int64(0)));
    ASSERT_EQ(1, Math::Sign(int64(10)));
  }

  TEST(MathTest, SignSByte) {
    ASSERT_EQ(-1, Math::Sign(sbyte(-10)));
    ASSERT_EQ(0, Math::Sign(sbyte(0)));
    ASSERT_EQ(1, Math::Sign(sbyte(10)));
  }

  TEST(MathTest, SignSingle) {
    ASSERT_EQ(-1, Math::Sign(float(-10)));
    ASSERT_EQ(0, Math::Sign(float(0)));
    ASSERT_EQ(1, Math::Sign(float(10)));
    ASSERT_THROW(Math::Sign(Single::NaN), ArithmeticException);
  }

  TEST(MathTest, Sin) {
    ASSERT_EQ(0, Math::Sin(ToRadians(0)));
    ASSERT_TRUE(IsApproximatelyEquals(0.707106781186547, Math::Sin(ToRadians(45)), .0000000001));
    ASSERT_EQ(1, Math::Sin(ToRadians(90)));
    ASSERT_TRUE(Double::IsNaN(Math::Sin(Double::NaN)));
    ASSERT_TRUE(Double::IsNaN(Math::Sin(Double::NegativeInfinity)));
    ASSERT_TRUE(Double::IsNaN(Math::Sin(Double::PositiveInfinity)));
  }

  TEST(MathTest, Sinh) {
    ASSERT_EQ(0, Math::Sinh(0));
    ASSERT_TRUE(IsApproximatelyEquals(2.30129890230729, Math::Sinh(ToRadians(90)), .00000000000001));
    ASSERT_TRUE(Double::IsPositiveInfinity(Math::Sinh(Double::PositiveInfinity)));
    ASSERT_TRUE(Double::IsNegativeInfinity(Math::Sinh(Double::NegativeInfinity)));
    ASSERT_TRUE(Double::IsNaN(Math::Sinh(Double::NaN)));
  }

  TEST(MathTest, Sqrt) {
    ASSERT_TRUE(IsApproximatelyEquals(0, Math::Sqrt(0)));
    ASSERT_TRUE(IsApproximatelyEquals(1, Math::Sqrt(1)));
    ASSERT_TRUE(IsApproximatelyEquals(2, Math::Sqrt(4)));
    ASSERT_TRUE(IsApproximatelyEquals(3, Math::Sqrt(9)));
    ASSERT_TRUE(Double::IsNaN(Math::Sqrt(-1)));
    ASSERT_TRUE(Double::IsNaN(Math::Sqrt(Double::NaN)));
    ASSERT_TRUE(Double::IsPositiveInfinity(Math::Sqrt(Double::PositiveInfinity)));
  }

  TEST(MathTest, Tan) {
    ASSERT_TRUE(IsApproximatelyEquals(0.0, Math::Tan(0.0)));
    ASSERT_TRUE(IsApproximatelyEquals(1.63317787283838E+16, Math::Tan(ToRadians(90)), .0001));
    ASSERT_TRUE(Double::IsNaN(Math::Tan(Double::NaN)));
    ASSERT_TRUE(Double::IsNaN(Math::Tan(Double::NegativeInfinity)));
    ASSERT_TRUE(Double::IsNaN(Math::Tan(Double::PositiveInfinity)));
  }

  TEST(MathTest, Tanh) {
    ASSERT_TRUE(IsApproximatelyEquals(-1.0, Math::Tanh(Double::NegativeInfinity)));
    ASSERT_TRUE(IsApproximatelyEquals(1.0, Math::Tanh(Double::PositiveInfinity)));
    ASSERT_TRUE(Double::IsNaN(Math::Tanh(Double::NaN)));
  }

  TEST(MathTest, Truncate) {
    ASSERT_TRUE(IsApproximatelyEquals(0, Math::Truncate(0.0)));
    ASSERT_TRUE(IsApproximatelyEquals(1, Math::Truncate(1.0)));
    ASSERT_TRUE(IsApproximatelyEquals(2, Math::Truncate(2.4)));
    ASSERT_TRUE(IsApproximatelyEquals(2, Math::Truncate(2.8)));
    ASSERT_TRUE(IsApproximatelyEquals(-1, Math::Truncate(-1.0)));
    ASSERT_TRUE(IsApproximatelyEquals(-2, Math::Truncate(-2.4)));
  }
}
