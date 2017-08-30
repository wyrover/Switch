#include <Pcf/System/Double.hpp>
#include <Pcf/TUnit/Assert.hpp>
#include <Pcf/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  TEST(Double, Fields) {
    EXPECT_EQ(0x7FEFFFFFFFFFFFFFull, (uint64)BitConverter::DoubleToInt64Bits(Double::MaxValue));
    EXPECT_EQ(0xFFEFFFFFFFFFFFFFull, (uint64)BitConverter::DoubleToInt64Bits(Double::MinValue));
    EXPECT_EQ(0x0000000000000001ull, (uint64)BitConverter::DoubleToInt64Bits(Double::Epsilon));
    EXPECT_EQ(0x7FF8000000000000ull, (uint64)BitConverter::DoubleToInt64Bits(Double::NaN));
    
    EXPECT_GT(Double::MaxValue, 0.0);
    EXPECT_LT(Double::MinValue, 0.0);
    EXPECT_GT(Double::Epsilon, 0.0);
    EXPECT_LT(-Double::Epsilon, 0.0);
  }
  
  TEST(Double, IsInfinity) {
    EXPECT_FALSE(Double::IsInfinity(0.0));
    EXPECT_FALSE(Double::IsInfinity(1.0));
    EXPECT_FALSE(Double::IsInfinity(255.0));
    EXPECT_FALSE(Double::IsInfinity(4294967295.0));
    EXPECT_FALSE(Double::IsInfinity(0.00390625));
    EXPECT_FALSE(Double::IsInfinity(0.00000000023283064365386962890625));
    EXPECT_FALSE(Double::IsInfinity(1.23456789012345E-300));
    EXPECT_FALSE(Double::IsInfinity(1.2345678901234565));
    EXPECT_FALSE(Double::IsInfinity(1.23456789012345678E+300));
    EXPECT_FALSE(Double::IsInfinity(Double::Epsilon));
    EXPECT_FALSE(Double::IsInfinity(Double::MinValue));
    EXPECT_FALSE(Double::IsInfinity(Double::MaxValue));
    EXPECT_FALSE(Double::IsInfinity(Double::NaN));
    EXPECT_TRUE(Double::IsInfinity(Double::NegativeInfinity));
    EXPECT_TRUE(Double::IsInfinity(Double::PositiveInfinity));
  }
  
  TEST(Double, IsNegativeInfinity) {
    EXPECT_FALSE(Double::IsNegativeInfinity(0.0));
    EXPECT_FALSE(Double::IsNegativeInfinity(1.0));
    EXPECT_FALSE(Double::IsNegativeInfinity(255.0));
    EXPECT_FALSE(Double::IsNegativeInfinity(4294967295.0));
    EXPECT_FALSE(Double::IsNegativeInfinity(0.00390625));
    EXPECT_FALSE(Double::IsNegativeInfinity(0.00000000023283064365386962890625));
    EXPECT_FALSE(Double::IsNegativeInfinity(1.23456789012345E-300));
    EXPECT_FALSE(Double::IsNegativeInfinity(1.2345678901234565));
    EXPECT_FALSE(Double::IsNegativeInfinity(1.23456789012345678E+300));
    EXPECT_FALSE(Double::IsNegativeInfinity(Double::Epsilon));
    EXPECT_FALSE(Double::IsNegativeInfinity(Double::MinValue));
    EXPECT_FALSE(Double::IsNegativeInfinity(Double::MaxValue));
    EXPECT_FALSE(Double::IsNegativeInfinity(Double::NaN));
    EXPECT_TRUE(Double::IsNegativeInfinity(Double::NegativeInfinity));
    EXPECT_FALSE(Double::IsNegativeInfinity(Double::PositiveInfinity));
  }
  
  TEST(Double, IsPositiveInfinity) {
    EXPECT_FALSE(Double::IsPositiveInfinity(0.0));
    EXPECT_FALSE(Double::IsPositiveInfinity(1.0));
    EXPECT_FALSE(Double::IsPositiveInfinity(255.0));
    EXPECT_FALSE(Double::IsPositiveInfinity(4294967295.0));
    EXPECT_FALSE(Double::IsPositiveInfinity(0.00390625));
    EXPECT_FALSE(Double::IsPositiveInfinity(0.00000000023283064365386962890625));
    EXPECT_FALSE(Double::IsPositiveInfinity(1.23456789012345E-300));
    EXPECT_FALSE(Double::IsPositiveInfinity(1.2345678901234565));
    EXPECT_FALSE(Double::IsPositiveInfinity(1.23456789012345678E+300));
    EXPECT_FALSE(Double::IsPositiveInfinity(Double::Epsilon));
    EXPECT_FALSE(Double::IsPositiveInfinity(Double::MinValue));
    EXPECT_FALSE(Double::IsPositiveInfinity(Double::MaxValue));
    EXPECT_FALSE(Double::IsPositiveInfinity(Double::NaN));
    EXPECT_FALSE(Double::IsPositiveInfinity(Double::NegativeInfinity));
    EXPECT_TRUE(Double::IsPositiveInfinity(Double::PositiveInfinity));
  }

  TEST(Double, IsNaN) {
    EXPECT_FALSE(Double::IsNaN(0.0));
    EXPECT_FALSE(Double::IsNaN(1.0));
    EXPECT_FALSE(Double::IsNaN(255.0));
    EXPECT_FALSE(Double::IsNaN(4294967295.0));
    EXPECT_FALSE(Double::IsNaN(0.00390625));
    EXPECT_FALSE(Double::IsNaN(0.00000000023283064365386962890625));
    EXPECT_FALSE(Double::IsNaN(1.23456789012345E-300));
    EXPECT_FALSE(Double::IsNaN(1.2345678901234565));
    EXPECT_FALSE(Double::IsNaN(1.23456789012345678E+300));
    EXPECT_FALSE(Double::IsNaN(Double::Epsilon));
    EXPECT_FALSE(Double::IsNaN(Double::MinValue));
    EXPECT_FALSE(Double::IsNaN(Double::MaxValue));
    EXPECT_TRUE(Double::IsNaN(Double::NaN));
    EXPECT_FALSE(Double::IsNaN(Double::NegativeInfinity));
    EXPECT_FALSE(Double::IsNaN(Double::PositiveInfinity));
  }
  
  TEST(Double, ToString) {
    EXPECT_EQ("0", string::Format("{0}", double(0.0)));
    EXPECT_EQ("1", string::Format("{0}", double(1.0)));
    EXPECT_EQ("255", string::Format("{0}", double(255.0)));
    EXPECT_EQ("4294967295", string::Format("{0}", double(4294967295.0)));
    EXPECT_EQ("0.00390625", string::Format("{0}", double(0.00390625)));
    EXPECT_EQ("2.3283064365387E-10", string::Format("{0}", double(0.00000000023283064365386962890625)));
    EXPECT_EQ("1.23456789012345E-300", string::Format("{0}", double(1.23456789012345E-300)));
    EXPECT_EQ("1.23456789012346", string::Format("{0}", double(1.2345678901234565)));
    EXPECT_EQ("4.94065645841247E-324", string::Format("{0}", Double::Epsilon));
    EXPECT_EQ("-Infinity", string::Format("{0}", Double::NegativeInfinity));
    EXPECT_EQ("Infinity", string::Format("{0}", Double::PositiveInfinity));
  }
}
