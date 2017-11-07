#include <Switch/System/BitConverter.hpp>
#include <Switch/System/Double.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(Double, Fields) {
    ASSERT_EQ(0x7FEFFFFFFFFFFFFFull, (uint64)BitConverter::DoubleToInt64Bits(Double::MaxValue));
    ASSERT_EQ(0xFFEFFFFFFFFFFFFFull, (uint64)BitConverter::DoubleToInt64Bits(Double::MinValue));
    ASSERT_EQ(0x0000000000000001ull, (uint64)BitConverter::DoubleToInt64Bits(Double::Epsilon));
    ASSERT_EQ(0x7FF8000000000000ull, (uint64)BitConverter::DoubleToInt64Bits(Double::NaN));
    
    EXPECT_GT(Double::MaxValue, 0.0);
    EXPECT_LT(Double::MinValue, 0.0);
    EXPECT_GT(Double::Epsilon, 0.0);
    EXPECT_LT(-Double::Epsilon, 0.0);
  }
  
  TEST(Double, IsInfinity) {
    ASSERT_FALSE(Double::IsInfinity(0.0));
    ASSERT_FALSE(Double::IsInfinity(1.0));
    ASSERT_FALSE(Double::IsInfinity(255.0));
    ASSERT_FALSE(Double::IsInfinity(4294967295.0));
    ASSERT_FALSE(Double::IsInfinity(0.00390625));
    ASSERT_FALSE(Double::IsInfinity(0.00000000023283064365386962890625));
    ASSERT_FALSE(Double::IsInfinity(1.23456789012345E-300));
    ASSERT_FALSE(Double::IsInfinity(1.2345678901234565));
    ASSERT_FALSE(Double::IsInfinity(1.23456789012345678E+300));
    ASSERT_FALSE(Double::IsInfinity(Double::Epsilon));
    ASSERT_FALSE(Double::IsInfinity(Double::MinValue));
    ASSERT_FALSE(Double::IsInfinity(Double::MaxValue));
    ASSERT_FALSE(Double::IsInfinity(Double::NaN));
    ASSERT_TRUE(Double::IsInfinity(Double::NegativeInfinity));
    ASSERT_TRUE(Double::IsInfinity(Double::PositiveInfinity));
  }
  
  TEST(Double, IsNegativeInfinity) {
    ASSERT_FALSE(Double::IsNegativeInfinity(0.0));
    ASSERT_FALSE(Double::IsNegativeInfinity(1.0));
    ASSERT_FALSE(Double::IsNegativeInfinity(255.0));
    ASSERT_FALSE(Double::IsNegativeInfinity(4294967295.0));
    ASSERT_FALSE(Double::IsNegativeInfinity(0.00390625));
    ASSERT_FALSE(Double::IsNegativeInfinity(0.00000000023283064365386962890625));
    ASSERT_FALSE(Double::IsNegativeInfinity(1.23456789012345E-300));
    ASSERT_FALSE(Double::IsNegativeInfinity(1.2345678901234565));
    ASSERT_FALSE(Double::IsNegativeInfinity(1.23456789012345678E+300));
    ASSERT_FALSE(Double::IsNegativeInfinity(Double::Epsilon));
    ASSERT_FALSE(Double::IsNegativeInfinity(Double::MinValue));
    ASSERT_FALSE(Double::IsNegativeInfinity(Double::MaxValue));
    ASSERT_FALSE(Double::IsNegativeInfinity(Double::NaN));
    ASSERT_TRUE(Double::IsNegativeInfinity(Double::NegativeInfinity));
    ASSERT_FALSE(Double::IsNegativeInfinity(Double::PositiveInfinity));
  }
  
  TEST(Double, IsPositiveInfinity) {
    ASSERT_FALSE(Double::IsPositiveInfinity(0.0));
    ASSERT_FALSE(Double::IsPositiveInfinity(1.0));
    ASSERT_FALSE(Double::IsPositiveInfinity(255.0));
    ASSERT_FALSE(Double::IsPositiveInfinity(4294967295.0));
    ASSERT_FALSE(Double::IsPositiveInfinity(0.00390625));
    ASSERT_FALSE(Double::IsPositiveInfinity(0.00000000023283064365386962890625));
    ASSERT_FALSE(Double::IsPositiveInfinity(1.23456789012345E-300));
    ASSERT_FALSE(Double::IsPositiveInfinity(1.2345678901234565));
    ASSERT_FALSE(Double::IsPositiveInfinity(1.23456789012345678E+300));
    ASSERT_FALSE(Double::IsPositiveInfinity(Double::Epsilon));
    ASSERT_FALSE(Double::IsPositiveInfinity(Double::MinValue));
    ASSERT_FALSE(Double::IsPositiveInfinity(Double::MaxValue));
    ASSERT_FALSE(Double::IsPositiveInfinity(Double::NaN));
    ASSERT_FALSE(Double::IsPositiveInfinity(Double::NegativeInfinity));
    ASSERT_TRUE(Double::IsPositiveInfinity(Double::PositiveInfinity));
  }

  TEST(Double, IsNaN) {
    ASSERT_FALSE(Double::IsNaN(0.0));
    ASSERT_FALSE(Double::IsNaN(1.0));
    ASSERT_FALSE(Double::IsNaN(255.0));
    ASSERT_FALSE(Double::IsNaN(4294967295.0));
    ASSERT_FALSE(Double::IsNaN(0.00390625));
    ASSERT_FALSE(Double::IsNaN(0.00000000023283064365386962890625));
    ASSERT_FALSE(Double::IsNaN(1.23456789012345E-300));
    ASSERT_FALSE(Double::IsNaN(1.2345678901234565));
    ASSERT_FALSE(Double::IsNaN(1.23456789012345678E+300));
    ASSERT_FALSE(Double::IsNaN(Double::Epsilon));
    ASSERT_FALSE(Double::IsNaN(Double::MinValue));
    ASSERT_FALSE(Double::IsNaN(Double::MaxValue));
    ASSERT_TRUE(Double::IsNaN(Double::NaN));
    ASSERT_FALSE(Double::IsNaN(Double::NegativeInfinity));
    ASSERT_FALSE(Double::IsNaN(Double::PositiveInfinity));
  }
  
  TEST(Double, ToString) {
    ASSERT_EQ("0", string::Format("{0}", double(0.0)));
    ASSERT_EQ("1", string::Format("{0}", double(1.0)));
    ASSERT_EQ("255", string::Format("{0}", double(255.0)));
    ASSERT_EQ("4294967295", string::Format("{0}", double(4294967295.0)));
    ASSERT_EQ("0.00390625", string::Format("{0}", double(0.00390625)));
    ASSERT_EQ("2.3283064365387E-10", string::Format("{0}", double(0.00000000023283064365386962890625)));
    ASSERT_EQ("1.23456789012345E-300", string::Format("{0}", double(1.23456789012345E-300)));
    ASSERT_EQ("1.23456789012346", string::Format("{0}", double(1.2345678901234565)));
    ASSERT_EQ("4.94065645841247E-324", string::Format("{0}", Double::Epsilon));
    ASSERT_EQ("-Infinity", string::Format("{0}", Double::NegativeInfinity));
    ASSERT_EQ("Infinity", string::Format("{0}", Double::PositiveInfinity));
  }
}
