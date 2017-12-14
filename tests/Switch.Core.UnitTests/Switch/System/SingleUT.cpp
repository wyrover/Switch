#include <Switch/System/Single.hpp>
#include <Switch/System/BitConverter.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/FormatException.hpp>
#include <Switch/System/OverflowException.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(SingleTest, Fields) {
    ASSERT_EQ(0x7F7FFFFFul, (uint32)BitConverter::SingleToInt32Bits(Single::MaxValue));
    ASSERT_EQ(0xFF7FFFFFul, (uint32)BitConverter::SingleToInt32Bits(Single::MinValue));
    ASSERT_EQ(0x00000001ul, (uint32)BitConverter::SingleToInt32Bits(Single::Epsilon));
    ASSERT_EQ(0x7FC00000ul, (uint32)BitConverter::SingleToInt32Bits(Single::NaN));

    EXPECT_GT(Single::MaxValue, 0.0f);
    EXPECT_LT(Single::MinValue, 0.0f);
    EXPECT_GT(Single::Epsilon, 0.0f);
    EXPECT_LT(-Single::Epsilon, 0.0f);
  }

  TEST(SingleTest, IsInfinity) {
    ASSERT_FALSE(Single::IsInfinity(0.0f));
    ASSERT_FALSE(Single::IsInfinity(1.0f));
    ASSERT_FALSE(Single::IsInfinity(65535.0f));
    ASSERT_FALSE(Single::IsInfinity(0.00390625f));
    ASSERT_FALSE(Single::IsInfinity(0.00000000023283064365386962890625f));
    ASSERT_FALSE(Single::IsInfinity(1.2345E-35f));
    ASSERT_FALSE(Single::IsInfinity(1.2345671f));
    ASSERT_FALSE(Single::IsInfinity(1.23456789E+35f));
    ASSERT_FALSE(Single::IsInfinity(Single::Epsilon));
    ASSERT_FALSE(Single::IsInfinity(Single::MinValue));
    ASSERT_FALSE(Single::IsInfinity(Single::MaxValue));
    ASSERT_FALSE(Single::IsInfinity(Single::NaN));
    ASSERT_TRUE(Single::IsInfinity(Single::NegativeInfinity));
    ASSERT_TRUE(Single::IsInfinity(Single::PositiveInfinity));
  }

  TEST(SingleTest, IsNegativeInfinity) {
    ASSERT_FALSE(Single::IsNegativeInfinity(0.0f));
    ASSERT_FALSE(Single::IsNegativeInfinity(1.0f));
    ASSERT_FALSE(Single::IsNegativeInfinity(65535.0f));
    ASSERT_FALSE(Single::IsNegativeInfinity(0.00390625f));
    ASSERT_FALSE(Single::IsNegativeInfinity(0.00000000023283064365386962890625f));
    ASSERT_FALSE(Single::IsNegativeInfinity(1.2345E-35f));
    ASSERT_FALSE(Single::IsNegativeInfinity(1.2345671f));
    ASSERT_FALSE(Single::IsNegativeInfinity(1.23456789E+35f));
    ASSERT_FALSE(Single::IsNegativeInfinity(Single::Epsilon));
    ASSERT_FALSE(Single::IsNegativeInfinity(Single::MinValue));
    ASSERT_FALSE(Single::IsNegativeInfinity(Single::MaxValue));
    ASSERT_FALSE(Single::IsNegativeInfinity(Single::NaN));
    ASSERT_TRUE(Single::IsNegativeInfinity(Single::NegativeInfinity));
    ASSERT_FALSE(Single::IsNegativeInfinity(Single::PositiveInfinity));
  }

  TEST(SingleTest, IsPositiveInfinity) {
    ASSERT_FALSE(Single::IsPositiveInfinity(0.0f));
    ASSERT_FALSE(Single::IsPositiveInfinity(1.0f));
    ASSERT_FALSE(Single::IsPositiveInfinity(65535.0f));
    ASSERT_FALSE(Single::IsPositiveInfinity(0.00390625f));
    ASSERT_FALSE(Single::IsPositiveInfinity(0.00000000023283064365386962890625f));
    ASSERT_FALSE(Single::IsPositiveInfinity(1.2345E-35f));
    ASSERT_FALSE(Single::IsPositiveInfinity(1.2345671f));
    ASSERT_FALSE(Single::IsPositiveInfinity(1.23456789E+35f));
    ASSERT_FALSE(Single::IsPositiveInfinity(Single::Epsilon));
    ASSERT_FALSE(Single::IsPositiveInfinity(Single::MinValue));
    ASSERT_FALSE(Single::IsPositiveInfinity(Single::MaxValue));
    ASSERT_FALSE(Single::IsPositiveInfinity(Single::NaN));
    ASSERT_FALSE(Single::IsPositiveInfinity(Single::NegativeInfinity));
    ASSERT_TRUE(Single::IsPositiveInfinity(Single::PositiveInfinity));
  }

  TEST(SingleTest, IsNaN) {
    ASSERT_FALSE(Single::IsNaN(0.0f));
    ASSERT_FALSE(Single::IsNaN(1.0f));
    ASSERT_FALSE(Single::IsNaN(65535.0f));
    ASSERT_FALSE(Single::IsNaN(0.00390625f));
    ASSERT_FALSE(Single::IsNaN(0.00000000023283064365386962890625f));
    ASSERT_FALSE(Single::IsNaN(1.2345E-35f));
    ASSERT_FALSE(Single::IsNaN(1.2345671f));
    ASSERT_FALSE(Single::IsNaN(1.23456789E+35f));
    ASSERT_FALSE(Single::IsNaN(Single::Epsilon));
    ASSERT_FALSE(Single::IsNaN(Single::MinValue));
    ASSERT_FALSE(Single::IsNaN(Single::MaxValue));
    ASSERT_TRUE(Single::IsNaN(Single::NaN));
    ASSERT_FALSE(Single::IsNaN(Single::NegativeInfinity));
    ASSERT_FALSE(Single::IsNaN(Single::PositiveInfinity));
  }

  TEST(SingleTest, ToString) {
    ASSERT_EQ("0", string::Format("{0}", 0.0f));
    ASSERT_EQ("1", string::Format("{0}", 1.0f));
    ASSERT_EQ("65535", string::Format("{0}", 65535.0f));
    ASSERT_EQ("0.00390625", string::Format("{0}", 0.00390625f));
    ASSERT_EQ("2.328306E-10", string::Format("{0}", 0.00000000023283064365386962890625f));
    ASSERT_EQ("1.2345E-35", string::Format("{0}", 1.2345E-35f));
    ASSERT_EQ("1.234567", string::Format("{0}", 1.2345671f));
    ASSERT_EQ("1.234568E+35", string::Format("{0}", 1.23456789E+35f));
    ASSERT_EQ("1.401298E-45", string::Format("{0}", Single::Epsilon));
    ASSERT_EQ("-3.402823E+38", string::Format("{0}", Single::MinValue));
    ASSERT_EQ("3.402823E+38", string::Format("{0}", Single::MaxValue));
    ASSERT_EQ("NaN", string::Format("{0}", Single::NaN));
    ASSERT_EQ("-Infinity", string::Format("{0}", Single::NegativeInfinity));
    ASSERT_EQ("Infinity", string::Format("{0}", Single::PositiveInfinity));
  }
}
