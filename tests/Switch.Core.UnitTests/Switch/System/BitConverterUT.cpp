#include <Switch/System/BitConverter.hpp>
#include <gtest/gtest.h>

using namespace System;

template<typename T, typename TArray>
void EXPECT_B1(T b, TArray bytes) {
  ASSERT_EQ(1, bytes.Length);
  ASSERT_EQ(b, bytes[0]);
}

template<typename T, typename TArray>
void EXPECT_B2(T b1, T b2, TArray bytes) {
  ASSERT_EQ(2, bytes.Length);
  if(System::BitConverter::IsLittleEndian()) {
    ASSERT_EQ(b1, bytes[0]);
    ASSERT_EQ(b2, bytes[1]);
  } else {
    ASSERT_EQ(b1, bytes[1]);
    ASSERT_EQ(b2, bytes[0]);
  }
}

template<typename T, typename TArray>
void EXPECT_B4(T b1, T b2, T b3, T b4, TArray bytes) {
  ASSERT_EQ(4, bytes.Length);
  if(System::BitConverter::IsLittleEndian()) {
    ASSERT_EQ(b1, bytes[0]);
    ASSERT_EQ(b2, bytes[1]);
    ASSERT_EQ(b3, bytes[2]);
    ASSERT_EQ(b4, bytes[3]);
  } else {
    ASSERT_EQ(b1, bytes[3]);
    ASSERT_EQ(b2, bytes[2]);
    ASSERT_EQ(b3, bytes[1]);
    ASSERT_EQ(b4, bytes[0]);
  }
}

template<typename T, typename TArray>
void EXPECT_B8(T b1, T b2, T b3, T b4, T b5, T b6, T b7, T b8, TArray bytes) {
  ASSERT_EQ(8, bytes.Length);
  if(System::BitConverter::IsLittleEndian()) {
    ASSERT_EQ(b1, bytes[0]);
    ASSERT_EQ(b2, bytes[1]);
    ASSERT_EQ(b3, bytes[2]);
    ASSERT_EQ(b4, bytes[3]);
    ASSERT_EQ(b5, bytes[4]);
    ASSERT_EQ(b6, bytes[5]);
    ASSERT_EQ(b7, bytes[6]);
    ASSERT_EQ(b8, bytes[7]);
  } else {
    ASSERT_EQ(b1, bytes[7]);
    ASSERT_EQ(b2, bytes[6]);
    ASSERT_EQ(b3, bytes[5]);
    ASSERT_EQ(b4, bytes[4]);
    ASSERT_EQ(b5, bytes[3]);
    ASSERT_EQ(b6, bytes[2]);
    ASSERT_EQ(b7, bytes[1]);
    ASSERT_EQ(b8, bytes[0]);
  }
}

template<typename T, typename TArray>
void EXPECT_B16(T b1, T b2, T b3, T b4, T b5, T b6, T b7, T b8, T b9, T b10, T b11, T b12, T b13, T b14, T b15, T b16, TArray bytes) {
  ASSERT_EQ(16, bytes.Length);
  if(System::BitConverter::IsLittleEndian()) {
    ASSERT_EQ(b1, bytes[0]);
    ASSERT_EQ(b2, bytes[1]);
    ASSERT_EQ(b3, bytes[2]);
    ASSERT_EQ(b4, bytes[3]);
    ASSERT_EQ(b5, bytes[4]);
    ASSERT_EQ(b6, bytes[5]);
    ASSERT_EQ(b7, bytes[6]);
    ASSERT_EQ(b8, bytes[7]);
    ASSERT_EQ(b9, bytes[8]);
    ASSERT_EQ(b10, bytes[9]);
    ASSERT_EQ(b11, bytes[10]);
    ASSERT_EQ(b12, bytes[11]);
    ASSERT_EQ(b13, bytes[12]);
    ASSERT_EQ(b14, bytes[13]);
    ASSERT_EQ(b15, bytes[14]);
    ASSERT_EQ(b16, bytes[15]);
  } else {
    ASSERT_EQ(b1, bytes[7]);
    ASSERT_EQ(b2, bytes[6]);
    ASSERT_EQ(b3, bytes[5]);
    ASSERT_EQ(b4, bytes[4]);
    ASSERT_EQ(b5, bytes[3]);
    ASSERT_EQ(b6, bytes[2]);
    ASSERT_EQ(b7, bytes[1]);
    ASSERT_EQ(b8, bytes[0]);
    ASSERT_EQ(b9, bytes[15]);
    ASSERT_EQ(b10, bytes[14]);
    ASSERT_EQ(b11, bytes[13]);
    ASSERT_EQ(b12, bytes[12]);
    ASSERT_EQ(b13, bytes[11]);
    ASSERT_EQ(b14, bytes[10]);
    ASSERT_EQ(b15, bytes[9]);
    ASSERT_EQ(b16, bytes[8]);
  }
}

namespace {
  TEST(BitConverterTest, GetBytesBoolean) {
    _using(Array<byte> bytes = BitConverter::GetBytes(false)) {
      EXPECT_B1(0, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(true)) {
      EXPECT_B1(1, bytes);
    }
  }
  
  TEST(BitConverterTest, GetBytesChar) {
    _using(Array<byte> bytes = BitConverter::GetBytes(' ')) {
      EXPECT_B4(0x20, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes('*')) {
      EXPECT_B4(0x2A, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes('3')) {
      EXPECT_B4(0x33, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes('A')) {
      EXPECT_B4(0x41, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes('[')) {
      EXPECT_B4(0x5B, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes('a')) {
      EXPECT_B4(0x61, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes('{')) {
      EXPECT_B4(0x7B, 0x00, 0x00, 0x00, bytes);
    }
  }
  
  TEST(BitConverterTest, GetBytesDouble) {
    _using(Array<byte> bytes = BitConverter::GetBytes(0.0)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1.0)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3F, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(255.0)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x6F, 0x40, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(4294967295.0)) {
      EXPECT_B8(0x00, 0x00, 0xE0, 0xFF, 0xFF, 0xFF, 0xEF, 0x41, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(0.00390625)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x3F, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(0.00000000023283064365386962890625)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3D, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1.23456789012345E-300)) {
      EXPECT_B8(0xDF, 0x88, 0x1E, 0x1C, 0xFE, 0x74, 0xAA, 0x01, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1.2345678901234565)) {
      EXPECT_B8(0xFA, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1.2345678901234567)) {
      EXPECT_B8(0xFB, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1.2345678901234569)) {
      EXPECT_B8(0xFC, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1.23456789012345678E+300)) {
      EXPECT_B8(0x52, 0xD3, 0xBB, 0xBC, 0xE8, 0x7E, 0x3D, 0x7E, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(Double::MinValue)) {
      EXPECT_B8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(Double::MaxValue)) {
      EXPECT_B8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0x7F, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(Double::Epsilon)) {
      EXPECT_B8(0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(Double::NaN)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x7F, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(Double::NegativeInfinity)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(Double::PositiveInfinity)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x7F, bytes);
    }
  }
  
  TEST(BitConverterTest, GetBytesInt16) {
    _using(Array<byte> bytes = BitConverter::GetBytes(int16(0))) {
      EXPECT_B2(0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(int16(15))) {
      EXPECT_B2(0x0F, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(int16(-15))) {
      EXPECT_B2(0xF1, 0xFF, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(int16(10000))) {
      EXPECT_B2(0x10, 0x27, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(int16(-10000))) {
      EXPECT_B2(0xF0, 0xD8, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(Int16::MinValue)) {
      EXPECT_B2(0x00, 0x80, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(Int16::MaxValue)) {
      EXPECT_B2(0xFF, 0x7F, bytes);
    }
  }
  
  TEST(BitConverterTest, GetBytesInt32) {
    _using(Array<byte> bytes = BitConverter::GetBytes(0)) {
      EXPECT_B4(0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(15)) {
      EXPECT_B4(0x0F, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(-15)) {
      EXPECT_B4(0xF1, 0xFF, 0xFF, 0xFF, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1048576)) {
      EXPECT_B4(0x00, 0x00, 0x10, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(-1048576)) {
      EXPECT_B4(0x00, 0x00, 0xF0, 0xFF, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1000000000)) {
      EXPECT_B4(0x00, 0xCA, 0x9A, 0x3B, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(-1000000000)) {
      EXPECT_B4(0x00, 0x36, 0x65, 0xC4, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(Int32::MinValue)) {
      EXPECT_B4(0x00, 0x00, 0x00, 0x80, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(Int32::MaxValue)) {
      EXPECT_B4(0xFF, 0xFF, 0xFF, 0x7F, bytes);
    }
  }
  
  TEST(BitConverterTest, GetBytesInt64) {
    _using(Array<byte> bytes = BitConverter::GetBytes(0LL)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(0xFFFFFFLL)) {
      EXPECT_B8(0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1000000000LL)) {
      EXPECT_B8(0x00, 0xCA, 0x9A, 0x3B, 0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(-1000000000LL)) {
      EXPECT_B8(0x00, 0x36, 0x65, 0xC4, 0xFF, 0xFF, 0xFF, 0xFF, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(0x100000000LL)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(-0x100000000LL)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(0xAAAAAAAAAAAALL)) {
      EXPECT_B8(0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(-0xAAAAAAAAAAAALL)) {
      EXPECT_B8(0x56, 0x55, 0x55, 0x55, 0x55, 0x55, 0xFF, 0xFF, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1000000000000000000LL)) {
      EXPECT_B8(0x00, 0x00, 0x64, 0xA7, 0xB3, 0xB6, 0xE0, 0x0D, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(-1000000000000000000LL)) {
      EXPECT_B8(0x00, 0x00, 0x9C, 0x58, 0x4C, 0x49, 0x1F, 0xF2, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(Int64::MinValue)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(Int64::MaxValue)) {
      EXPECT_B8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, bytes);
    }
  }
  
  TEST(BitConverterTest, GetBytesSingle) {
    _using(Array<byte> bytes = BitConverter::GetBytes(0.0f)) {
      EXPECT_B4(0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1.0f)) {
      EXPECT_B4(0x00, 0x00, 0x80, 0x3F, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(15.0f)) {
      EXPECT_B4(0x00, 0x00, 0x70, 0x41, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(65535.0f)) {
      EXPECT_B4(0x00, 0xFF, 0x7F, 0x47, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(0.00390625f)) {
      EXPECT_B4(0x00, 0x00, 0x80, 0x3B, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(0.00000000023283064365386962890625f)) {
      EXPECT_B4(0x00, 0x00, 0x80, 0x2F, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1.2345E-35f)) {
      EXPECT_B4(0x49, 0x46, 0x83, 0x05, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1.2345671f)) {
      EXPECT_B4(0x4B, 0x06, 0x9E, 0x3F, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1.2345673f)) {
      EXPECT_B4(0x4D, 0x06, 0x9E, 0x3F, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1.2345677f)) {
      EXPECT_B4(0x50, 0x06, 0x9E, 0x3F, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1.23456789E+35f)) {
      EXPECT_B4(0x1E, 0x37, 0xBE, 0x79, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(Single::MinValue)) {
      EXPECT_B4(0xFF, 0xFF, 0x7F, 0xFF, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(Single::MaxValue)) {
      EXPECT_B4(0xFF, 0xFF, 0x7F, 0x7F, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(Single::Epsilon)) {
      EXPECT_B4(0x01, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(Single::NaN)) {
      EXPECT_B4(0x00, 0x00, 0xC0, 0x7F, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(Single::NegativeInfinity)) {
      EXPECT_B4(0x00, 0x00, 0x80, 0xFF, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(Single::PositiveInfinity)) {
      EXPECT_B4(0x00, 0x00, 0x80, 0x7F, bytes);
    }
  }
  
  TEST(BitConverterTest, GetBytesUInt16) {
    _using(Array<byte> bytes = BitConverter::GetBytes(uint16(15))) {
      EXPECT_B2(0x0F, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(uint16(1023))) {
      EXPECT_B2(0xFF, 0x03, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(uint16(10000))) {
      EXPECT_B2(0x10, 0x27, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(uint16(0))) {
      EXPECT_B2(0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(uint16(Int16::MaxValue))) {
      EXPECT_B2(0xFF, 0x7F, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(UInt16::MaxValue)) {
      EXPECT_B2(0xFF, 0xFF, bytes);
    }
  }
  
  TEST(BitConverterTest, GetBytesUInt32) {
    _using(Array<byte> bytes = BitConverter::GetBytes(15U)) {
      EXPECT_B4(0x0F, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1023U)) {
      EXPECT_B4(0xFF, 0x03, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(0x100000U)) {
      EXPECT_B4(0x00, 0x00, 0x10, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1000000000U)) {
      EXPECT_B4(0x00, 0xCA, 0x9A, 0x3B, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(UInt32::MinValue)) {
      EXPECT_B4(0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(uint32(Int32::MaxValue))) {
      EXPECT_B4(0xFF, 0xFF, 0xFF, 0x7F, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(UInt32::MaxValue)) {
      EXPECT_B4(0xFF, 0xFF, 0xFF, 0xFF, bytes);
    }
  }
  
  TEST(BitConverterTest, GetBytesUInt64) {
    _using(Array<byte> bytes = BitConverter::GetBytes(0xFFFFFFULL)) {
      EXPECT_B8(0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1000000000ULL)) {
      EXPECT_B8(0x00, 0xCA, 0x9A, 0x3B, 0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(0x100000000ULL)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(0xAAAAAAAAAAAAULL)) {
      EXPECT_B8(0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(1000000000000000000ULL)) {
      EXPECT_B8(0x00, 0x00, 0x64, 0xA7, 0xB3, 0xB6, 0xE0, 0x0D, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(10000000000000000000ULL)) {
      EXPECT_B8(0x00, 0x00, 0xE8, 0x89, 0x04, 0x23, 0xC7, 0x8A, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(UInt64::MinValue)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(uint64(Int64::MaxValue))) {
      EXPECT_B8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, bytes);
    }
    
    _using(Array<byte> bytes = BitConverter::GetBytes(UInt64::MaxValue)) {
      EXPECT_B8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, bytes);
    }
  }
  
  TEST(BitConverterTest, ToBoolean) {
    ASSERT_THROW(BitConverter::ToBoolean({0}, -1), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToBoolean({0}, 1), ArgumentOutOfRangeException);
    
    ASSERT_FALSE(BitConverter::ToBoolean({0}, 0));
    ASSERT_TRUE(BitConverter::ToBoolean({1}, 0));
    ASSERT_TRUE(BitConverter::ToBoolean({2}, 0));
    ASSERT_TRUE(BitConverter::ToBoolean({4}, 0));
    ASSERT_TRUE(BitConverter::ToBoolean({8}, 0));
    ASSERT_TRUE(BitConverter::ToBoolean({16}, 0));
    ASSERT_TRUE(BitConverter::ToBoolean({32}, 0));
    ASSERT_TRUE(BitConverter::ToBoolean({64}, 0));
    ASSERT_TRUE(BitConverter::ToBoolean({128}, 0));
    ASSERT_TRUE(BitConverter::ToBoolean({255}, 0));
  }
  
  TEST(BitConverterTest, ToChar) {
    ASSERT_THROW(BitConverter::ToChar({0x00, 0x00, 0x00, 0x00}, -1), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToChar({0x00, 0x00, 0x00, 0x00}, 4), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToChar({0x00, 0x00, 0x00, 0x00}, 1), ArgumentException);
    
    ASSERT_EQ(' ', BitConverter::ToChar({0x20, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ('*', BitConverter::ToChar({0x2A, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ('3', BitConverter::ToChar({0x33, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ('A', BitConverter::ToChar({0x41, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ('[', BitConverter::ToChar({0x5B, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ('a', BitConverter::ToChar({0x61, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ('{', BitConverter::ToChar({0x7B, 0x00, 0x00, 0x00}, 0));
  }
  
  TEST(BitConverterTest, ToDouble) {
    ASSERT_THROW(BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, -1), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 8), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 1), ArgumentException);
    
    ASSERT_EQ(0.0, BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ(1.0, BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3F}, 0));
    ASSERT_EQ(255.0, BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x6F, 0x40}, 0));
    ASSERT_EQ(4294967295.0, BitConverter::ToDouble({0x00, 0x00, 0xE0, 0xFF, 0xFF, 0xFF, 0xEF, 0x41}, 0));
    ASSERT_EQ(0.00390625, BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x3F}, 0));
    ASSERT_EQ(0.00000000023283064365386962890625, BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3D}, 0));
    ASSERT_EQ(1.23456789012345E-300, BitConverter::ToDouble({0xDF, 0x88, 0x1E, 0x1C, 0xFE, 0x74, 0xAA, 0x01}, 0));
    ASSERT_EQ(1.2345678901234565, BitConverter::ToDouble({0xFA, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F}, 0));
    ASSERT_EQ(1.2345678901234567, BitConverter::ToDouble({0xFB, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F}, 0));
    ASSERT_EQ(1.2345678901234569, BitConverter::ToDouble({0xFC, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F}, 0));
    ASSERT_EQ(1.23456789012345678E+300, BitConverter::ToDouble({0x52, 0xD3, 0xBB, 0xBC, 0xE8, 0x7E, 0x3D, 0x7E}, 0));
    ASSERT_EQ(Double::MinValue, BitConverter::ToDouble({0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF}, 0));
    ASSERT_EQ(Double::MaxValue, BitConverter::ToDouble({0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0x7F}, 0));
    ASSERT_EQ(Double::Epsilon, BitConverter::ToDouble({0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
    ASSERT_TRUE(Double::IsNaN(BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x7F}, 0)));
    ASSERT_EQ(Double::NegativeInfinity, BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF}, 0));
    ASSERT_EQ(Double::PositiveInfinity, BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x7F}, 0));
  }
  
  TEST(BitConverterTest, ToInt16) {
    ASSERT_THROW(BitConverter::ToInt16({0x00, 0x00}, -1), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToInt16({0x00, 0x00}, 2), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToInt16({0x00, 0x00}, 1), ArgumentException);
    
    ASSERT_EQ(0, BitConverter::ToInt16({0x00, 0x00}, 0));
    ASSERT_EQ(15, BitConverter::ToInt16({0x0F, 0x00}, 0));
    ASSERT_EQ(-15, BitConverter::ToInt16({0xF1, 0xFF}, 0));
    ASSERT_EQ(10000, BitConverter::ToInt16({0x10, 0x27}, 0));
    ASSERT_EQ(-10000, BitConverter::ToInt16({0xF0, 0xD8}, 0));
    ASSERT_EQ(Int16::MinValue, BitConverter::ToInt16({0x00, 0x80}, 0));
    ASSERT_EQ(Int16::MaxValue, BitConverter::ToInt16({0xFF, 0x7F}, 0));
  }
  
  TEST(BitConverterTest, ToInt32) {
    ASSERT_THROW(BitConverter::ToInt32({0x00, 0x00, 0x00, 0x00}, -1), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToInt32({0x00, 0x00, 0x00, 0x00}, 4), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToInt32({0x00, 0x00, 0x00, 0x00}, 1), ArgumentException);
    
    ASSERT_EQ(0, BitConverter::ToInt32({0x00, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ(15, BitConverter::ToInt32({0x0F, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ(-15, BitConverter::ToInt32({0xF1, 0xFF, 0xFF, 0xFF}, 0));
    ASSERT_EQ(1048576, BitConverter::ToInt32({0x00, 0x00, 0x10, 0x00}, 0));
    ASSERT_EQ(-1048576, BitConverter::ToInt32({0x00, 0x00, 0xF0, 0xFF}, 0));
    ASSERT_EQ(1000000000, BitConverter::ToInt32({0x00, 0xCA, 0x9A, 0x3B}, 0));
    ASSERT_EQ(-1000000000, BitConverter::ToInt32({0x00, 0x36, 0x65, 0xC4}, 0));
    ASSERT_EQ(Int32::MinValue, BitConverter::ToInt32({0x00, 0x00, 0x00, 0x80}, 0));
    ASSERT_EQ(Int32::MaxValue, BitConverter::ToInt32({0xFF, 0xFF, 0xFF, 0x7F}, 0));
  }
  
  TEST(BitConverterTest, ToInt64) {
    ASSERT_THROW(BitConverter::ToInt64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, -1), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToInt64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 8), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToInt64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 1), ArgumentException);
    
    ASSERT_EQ(0LL, BitConverter::ToInt64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ(0xFFFFFFLL, BitConverter::ToInt64({0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ(1000000000LL, BitConverter::ToInt64({0x00, 0xCA, 0x9A, 0x3B, 0x00, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ(-1000000000LL, BitConverter::ToInt64({0x00, 0x36, 0x65, 0xC4, 0xFF, 0xFF, 0xFF, 0xFF}, 0));
    ASSERT_EQ(0x100000000LL, BitConverter::ToInt64({0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ(-0x100000000LL, BitConverter::ToInt64({0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF}, 0));
    ASSERT_EQ(0xAAAAAAAAAAAALL, BitConverter::ToInt64({0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00}, 0));
    ASSERT_EQ(-0xAAAAAAAAAAAALL, BitConverter::ToInt64({0x56, 0x55, 0x55, 0x55, 0x55, 0x55, 0xFF, 0xFF}, 0));
    ASSERT_EQ(1000000000000000000LL, BitConverter::ToInt64({0x00, 0x00, 0x64, 0xA7, 0xB3, 0xB6, 0xE0, 0x0D}, 0));
    ASSERT_EQ(-1000000000000000000LL, BitConverter::ToInt64({0x00, 0x00, 0x9C, 0x58, 0x4C, 0x49, 0x1F, 0xF2}, 0));
    ASSERT_EQ(Int64::MinValue, BitConverter::ToInt64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80}, 0));
    ASSERT_EQ(Int64::MaxValue, BitConverter::ToInt64({0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F}, 0));
  }
  
  TEST(BitConverterTest, ToSingle) {
    ASSERT_THROW(BitConverter::ToSingle({0x00, 0x00, 0x00, 0x00}, -1), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToSingle({0x00, 0x00, 0x00, 0x00}, 4), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToSingle({0x00, 0x00, 0x00, 0x00}, 1), ArgumentException);
    
    ASSERT_EQ(0.0, BitConverter::ToSingle({0x00, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ(1.0f, BitConverter::ToSingle({0x00, 0x00, 0x80, 0x3F}, 0));
    ASSERT_EQ(15.0f, BitConverter::ToSingle({0x00, 0x00, 0x70, 0x41}, 0));
    ASSERT_EQ(65535.0f, BitConverter::ToSingle({0x00, 0xFF, 0x7F, 0x47}, 0));
    ASSERT_EQ(0.00390625f, BitConverter::ToSingle({0x00, 0x00, 0x80, 0x3B}, 0));
    ASSERT_EQ(0.00000000023283064365386962890625f, BitConverter::ToSingle({0x00, 0x00, 0x80, 0x2F}, 0));
    ASSERT_EQ(1.2345E-35f, BitConverter::ToSingle({0x49, 0x46, 0x83, 0x05}, 0));
    ASSERT_EQ(1.2345671f, BitConverter::ToSingle({0x4B, 0x06, 0x9E, 0x3F}, 0));
    ASSERT_EQ(1.2345673f, BitConverter::ToSingle({0x4D, 0x06, 0x9E, 0x3F}, 0));
    ASSERT_EQ(1.2345677f, BitConverter::ToSingle({0x50, 0x06, 0x9E, 0x3F}, 0));
    ASSERT_EQ(1.23456789E+35f, BitConverter::ToSingle({0x1E, 0x37, 0xBE, 0x79}, 0));
    ASSERT_EQ(Single::MinValue, BitConverter::ToSingle({0xFF, 0xFF, 0x7F, 0xFF}, 0));
    ASSERT_EQ(Single::MaxValue, BitConverter::ToSingle({0xFF, 0xFF, 0x7F, 0x7F}, 0));
    ASSERT_EQ(Single::Epsilon, BitConverter::ToSingle({0x01, 0x00, 0x00, 0x00}, 0));
    ASSERT_TRUE(Single::IsNaN(BitConverter::ToSingle({0x00, 0x00, 0xC0, 0x7F}, 0)));
    ASSERT_EQ(Single::NegativeInfinity, BitConverter::ToSingle({0x00, 0x00, 0x80, 0xFF}, 0));
    ASSERT_EQ(Single::PositiveInfinity, BitConverter::ToSingle({0x00, 0x00, 0x80, 0x7F}, 0));
  }
  
  TEST(BitConverterTest, ToString) {
    Array<byte> arrayOne = {0, 1, 2, 4, 8, 16, 32, 64, 128, 255};
    ASSERT_EQ("00-01-02-04-08-10-20-40-80-FF", BitConverter::ToString(arrayOne));
    
    Array<byte> arrayTwo = {32, 0, 0, 42, 0, 65, 0, 125, 0, 197, 0, 168, 3, 41, 4, 172, 32};
    ASSERT_EQ("20-00-00-2A-00-41-00-7D-00-C5-00-A8-03-29-04-AC-20", BitConverter::ToString(arrayTwo));
    
    Array<byte> arrayThree = {15, 0, 0, 128, 16, 39, 240, 216, 241, 255, 127};
    ASSERT_EQ("0F-00-00-80-10-27-F0-D8-F1-FF-7F", BitConverter::ToString(arrayThree));
    
    Array<byte> arrayFour = {15, 0, 0, 0, 0, 16, 0, 255, 3, 0, 0, 202, 154, 59, 255, 255, 255, 255, 127};
    ASSERT_EQ("0F-00-00-00-00-10-00-FF-03-00-00-CA-9A-3B-FF-FF-FF-FF-7F", BitConverter::ToString(arrayFour));
    
    Array<byte> arrayEmpty;
    ASSERT_EQ("", BitConverter::ToString(arrayEmpty));
  }
  
  TEST(BitConverterTest, ToStringWithStartIndex) {
    Array<byte> arrayOne = {3, 6, 9};
    ASSERT_THROW(BitConverter::ToString(arrayOne, -1), ArgumentOutOfRangeException);
    ASSERT_EQ("03-06-09", BitConverter::ToString(arrayOne, 0));
    ASSERT_EQ("06-09", BitConverter::ToString(arrayOne, 1));
    ASSERT_EQ("09", BitConverter::ToString(arrayOne, 2));
    ASSERT_THROW(BitConverter::ToString(arrayOne, 3), ArgumentOutOfRangeException);
    
    Array<byte> arrayEmpty;
    ASSERT_EQ("", BitConverter::ToString(arrayEmpty, 0));
    ASSERT_THROW(BitConverter::ToString(arrayEmpty, 1), ArgumentOutOfRangeException);
  }
  
  TEST(BitConverterTest, ToStringWithStartIndexAndLength) {
    Array<byte> arrayOne = {3, 6, 9};
    
    ASSERT_THROW(BitConverter::ToString(arrayOne, -1, 1), ArgumentOutOfRangeException);
    
    ASSERT_THROW(BitConverter::ToString(arrayOne, 0, -1), ArgumentException);
    ASSERT_EQ("", BitConverter::ToString(arrayOne, 0, 0));
    ASSERT_EQ("03", BitConverter::ToString(arrayOne, 0, 1));
    ASSERT_EQ("03-06", BitConverter::ToString(arrayOne, 0, 2));
    ASSERT_EQ("03-06-09", BitConverter::ToString(arrayOne, 0, 3));
    ASSERT_THROW(BitConverter::ToString(arrayOne, 0, 4), ArgumentException);
    
    ASSERT_THROW(BitConverter::ToString(arrayOne, 1, -1), ArgumentException);
    ASSERT_EQ("", BitConverter::ToString(arrayOne, 1, 0));
    ASSERT_EQ("06", BitConverter::ToString(arrayOne, 1, 1));
    ASSERT_EQ("06-09", BitConverter::ToString(arrayOne, 1, 2));
    ASSERT_THROW(BitConverter::ToString(arrayOne, 1, 3), ArgumentException);
    
    ASSERT_THROW(BitConverter::ToString(arrayOne, 2, -1), ArgumentException);
    ASSERT_EQ("", BitConverter::ToString(arrayOne, 2, 0));
    ASSERT_EQ("09", BitConverter::ToString(arrayOne, 2, 1));
    ASSERT_THROW(BitConverter::ToString(arrayOne, 2, 2), ArgumentException);
    
    ASSERT_THROW(BitConverter::ToString(arrayOne, 3, 1), ArgumentOutOfRangeException);
    
    Array<byte> arrayEmpty;
    ASSERT_THROW(BitConverter::ToString(arrayEmpty, 1), ArgumentOutOfRangeException);
  }
  
  TEST(BitConverterTest, ToUInt16) {
    ASSERT_THROW(BitConverter::ToUInt16({0x00, 0x00}, -1), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToUInt16({0x00, 0x00}, 2), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToUInt16({0x00, 0x00}, 1), ArgumentException);
    
    ASSERT_EQ(15, BitConverter::ToUInt16({0x0F, 0x00}, 0));
    ASSERT_EQ(1023, BitConverter::ToUInt16({0xFF, 0x03}, 0));
    ASSERT_EQ(10000, BitConverter::ToUInt16({0x10, 0x27}, 0));
    ASSERT_EQ(0, BitConverter::ToUInt16({0x00, 0x00}, 0));
    ASSERT_EQ(uint16(Int16::MaxValue), BitConverter::ToUInt16({0xFF, 0x7F}, 0));
    ASSERT_EQ(UInt16::MaxValue, BitConverter::ToUInt16({0xFF, 0xFF}, 0));
  }
  
  TEST(BitConverterTest, ToUInt32) {
    ASSERT_THROW(BitConverter::ToUInt32({0x00, 0x00, 0x00, 0x00}, -1), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToUInt32({0x00, 0x00, 0x00, 0x00}, 4), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToUInt32({0x00, 0x00, 0x00, 0x00}, 1), ArgumentException);
    
    ASSERT_EQ(15U, BitConverter::ToUInt32({0x0F, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ(1023U, BitConverter::ToUInt32({0xFF, 0x03, 0x00, 0x00}, 0));
    ASSERT_EQ(0x100000U, BitConverter::ToUInt32({0x00, 0x00, 0x10, 0x00}, 0));
    ASSERT_EQ(1000000000U, BitConverter::ToUInt32({0x00, 0xCA, 0x9A, 0x3B}, 0));
    ASSERT_EQ(UInt32::MinValue, BitConverter::ToUInt32({0x00, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ(uint32(Int32::MaxValue), BitConverter::ToUInt32({0xFF, 0xFF, 0xFF, 0x7F}, 0));
    ASSERT_EQ(UInt32::MaxValue, BitConverter::ToUInt32({0xFF, 0xFF, 0xFF, 0xFF}, 0));
  }
  
  TEST(BitConverterTest, ToUInt64) {
    ASSERT_THROW(BitConverter::ToUInt64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, -1), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToUInt64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 8), ArgumentOutOfRangeException);
    ASSERT_THROW(BitConverter::ToUInt64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 1), ArgumentException);
    
    ASSERT_EQ(0xFFFFFFULL, BitConverter::ToUInt64({0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ(1000000000ULL, BitConverter::ToUInt64({0x00, 0xCA, 0x9A, 0x3B, 0x00, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ(0x100000000ULL, BitConverter::ToUInt64({0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ(0xAAAAAAAAAAAAULL, BitConverter::ToUInt64({0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00}, 0));
    ASSERT_EQ(1000000000000000000ULL, BitConverter::ToUInt64({0x00, 0x00, 0x64, 0xA7, 0xB3, 0xB6, 0xE0, 0x0D}, 0));
    ASSERT_EQ(10000000000000000000ULL, BitConverter::ToUInt64({0x00, 0x00, 0xE8, 0x89, 0x04, 0x23, 0xC7, 0x8A}, 0));
    ASSERT_EQ(UInt64::MinValue, BitConverter::ToUInt64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ(uint64(Int64::MaxValue), BitConverter::ToUInt64({0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F}, 0));
    ASSERT_EQ(UInt64::MaxValue, BitConverter::ToUInt64({0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 0));
  }
}
