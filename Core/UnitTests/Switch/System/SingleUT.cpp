#include <Switch/System/Single.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  TEST(Single, Fields) {
    EXPECT_EQ(0x7F7FFFFFul, (uint32)BitConverter::SingleToInt32Bits(Single::MaxValue));
    EXPECT_EQ(0xFF7FFFFFul, (uint32)BitConverter::SingleToInt32Bits(Single::MinValue));
    EXPECT_EQ(0x00000001ul, (uint32)BitConverter::SingleToInt32Bits(Single::Epsilon));
    EXPECT_EQ(0x7FC00000ul, (uint32)BitConverter::SingleToInt32Bits(Single::NaN));
    
    EXPECT_GT(Single::MaxValue, 0.0f);
    EXPECT_LT(Single::MinValue, 0.0f);
    EXPECT_GT(Single::Epsilon, 0.0f);
    EXPECT_LT(-Single::Epsilon, 0.0f);
  }
  
  TEST(Single, IsInfinity) {
    EXPECT_FALSE(Single::IsInfinity(0.0f));
    EXPECT_FALSE(Single::IsInfinity(1.0f));
    EXPECT_FALSE(Single::IsInfinity(65535.0f));
    EXPECT_FALSE(Single::IsInfinity(0.00390625f));
    EXPECT_FALSE(Single::IsInfinity(0.00000000023283064365386962890625f));
    EXPECT_FALSE(Single::IsInfinity(1.2345E-35f));
    EXPECT_FALSE(Single::IsInfinity(1.2345671f));
    EXPECT_FALSE(Single::IsInfinity(1.23456789E+35f));
    EXPECT_FALSE(Single::IsInfinity(Single::Epsilon));
    EXPECT_FALSE(Single::IsInfinity(Single::MinValue));
    EXPECT_FALSE(Single::IsInfinity(Single::MaxValue));
    EXPECT_FALSE(Single::IsInfinity(Single::NaN));
    EXPECT_TRUE(Single::IsInfinity(Single::NegativeInfinity));
    EXPECT_TRUE(Single::IsInfinity(Single::PositiveInfinity));
  }
  
  TEST(Single, IsNegativeInfinity) {
    EXPECT_FALSE(Single::IsNegativeInfinity(0.0f));
    EXPECT_FALSE(Single::IsNegativeInfinity(1.0f));
    EXPECT_FALSE(Single::IsNegativeInfinity(65535.0f));
    EXPECT_FALSE(Single::IsNegativeInfinity(0.00390625f));
    EXPECT_FALSE(Single::IsNegativeInfinity(0.00000000023283064365386962890625f));
    EXPECT_FALSE(Single::IsNegativeInfinity(1.2345E-35f));
    EXPECT_FALSE(Single::IsNegativeInfinity(1.2345671f));
    EXPECT_FALSE(Single::IsNegativeInfinity(1.23456789E+35f));
    EXPECT_FALSE(Single::IsNegativeInfinity(Single::Epsilon));
    EXPECT_FALSE(Single::IsNegativeInfinity(Single::MinValue));
    EXPECT_FALSE(Single::IsNegativeInfinity(Single::MaxValue));
    EXPECT_FALSE(Single::IsNegativeInfinity(Single::NaN));
    EXPECT_TRUE(Single::IsNegativeInfinity(Single::NegativeInfinity));
    EXPECT_FALSE(Single::IsNegativeInfinity(Single::PositiveInfinity));
  }
  
  TEST(Single, IsPositiveInfinity) {
    EXPECT_FALSE(Single::IsPositiveInfinity(0.0f));
    EXPECT_FALSE(Single::IsPositiveInfinity(1.0f));
    EXPECT_FALSE(Single::IsPositiveInfinity(65535.0f));
    EXPECT_FALSE(Single::IsPositiveInfinity(0.00390625f));
    EXPECT_FALSE(Single::IsPositiveInfinity(0.00000000023283064365386962890625f));
    EXPECT_FALSE(Single::IsPositiveInfinity(1.2345E-35f));
    EXPECT_FALSE(Single::IsPositiveInfinity(1.2345671f));
    EXPECT_FALSE(Single::IsPositiveInfinity(1.23456789E+35f));
    EXPECT_FALSE(Single::IsPositiveInfinity(Single::Epsilon));
    EXPECT_FALSE(Single::IsPositiveInfinity(Single::MinValue));
    EXPECT_FALSE(Single::IsPositiveInfinity(Single::MaxValue));
    EXPECT_FALSE(Single::IsPositiveInfinity(Single::NaN));
    EXPECT_FALSE(Single::IsPositiveInfinity(Single::NegativeInfinity));
    EXPECT_TRUE(Single::IsPositiveInfinity(Single::PositiveInfinity));
  }

  TEST(Single, IsNaN) {
    EXPECT_FALSE(Single::IsNaN(0.0f));
    EXPECT_FALSE(Single::IsNaN(1.0f));
    EXPECT_FALSE(Single::IsNaN(65535.0f));
    EXPECT_FALSE(Single::IsNaN(0.00390625f));
    EXPECT_FALSE(Single::IsNaN(0.00000000023283064365386962890625f));
    EXPECT_FALSE(Single::IsNaN(1.2345E-35f));
    EXPECT_FALSE(Single::IsNaN(1.2345671f));
    EXPECT_FALSE(Single::IsNaN(1.23456789E+35f));
    EXPECT_FALSE(Single::IsNaN(Single::Epsilon));
    EXPECT_FALSE(Single::IsNaN(Single::MinValue));
    EXPECT_FALSE(Single::IsNaN(Single::MaxValue));
    EXPECT_TRUE(Single::IsNaN(Single::NaN));
    EXPECT_FALSE(Single::IsNaN(Single::NegativeInfinity));
    EXPECT_FALSE(Single::IsNaN(Single::PositiveInfinity));
  }
  
  TEST(Single, ToString) {
    EXPECT_EQ("0", string::Format("{0}", 0.0f));
    EXPECT_EQ("1", string::Format("{0}", 1.0f));
    EXPECT_EQ("65535", string::Format("{0}", 65535.0f));
    EXPECT_EQ("0.00390625", string::Format("{0}", 0.00390625f));
    EXPECT_EQ("2.328306E-10", string::Format("{0}", 0.00000000023283064365386962890625f));
    EXPECT_EQ("1.2345E-35", string::Format("{0}", 1.2345E-35f));
    EXPECT_EQ("1.234567", string::Format("{0}", 1.2345671f));
    EXPECT_EQ("1.234568E+35", string::Format("{0}", 1.23456789E+35f));
    EXPECT_EQ("1.401298E-45", string::Format("{0}", Single::Epsilon));
    EXPECT_EQ("-3.402823E+38", string::Format("{0}", Single::MinValue));
    EXPECT_EQ("3.402823E+38", string::Format("{0}", Single::MaxValue));
    EXPECT_EQ("NaN", string::Format("{0}", Single::NaN));
    EXPECT_EQ("-Infinity", string::Format("{0}", Single::NegativeInfinity));
    EXPECT_EQ("Infinity", string::Format("{0}", Single::PositiveInfinity));
  }
}
