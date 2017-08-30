#include <Pcf/System/BitConverter.hpp>
#include <Pcf/TUnit/Assert.hpp>
#include <Pcf/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

#define EXPECT_B1(b, bytes) \
EXPECT_EQ(1, bytes.Length);\
EXPECT_EQ(b, bytes[0]);

#define EXPECT_B2(b1, b2, bytes) \
EXPECT_EQ(2, bytes.Length);\
if (System::BitConverter::IsLittleEndian()) {\
EXPECT_EQ(b1, bytes[0]);\
EXPECT_EQ(b2, bytes[1]);\
} else {\
EXPECT_EQ(b1, bytes[1]);\
EXPECT_EQ(b2, bytes[0]);\
}

#define EXPECT_B4(b1, b2, b3, b4, bytes) \
EXPECT_EQ(4, bytes.Length);\
if (System::BitConverter::IsLittleEndian()) {\
EXPECT_EQ(b1, bytes[0]);\
EXPECT_EQ(b2, bytes[1]);\
EXPECT_EQ(b3, bytes[2]);\
EXPECT_EQ(b4, bytes[3]);\
} else {\
EXPECT_EQ(b1, bytes[3]);\
EXPECT_EQ(b2, bytes[2]);\
EXPECT_EQ(b3, bytes[1]);\
EXPECT_EQ(b4, bytes[0]);\
}

#define EXPECT_B8(b1, b2, b3, b4, b5, b6, b7, b8, bytes) \
EXPECT_EQ(8, bytes.Length);\
if (System::BitConverter::IsLittleEndian()) {\
EXPECT_EQ(b1, bytes[0]);\
EXPECT_EQ(b2, bytes[1]);\
EXPECT_EQ(b3, bytes[2]);\
EXPECT_EQ(b4, bytes[3]);\
EXPECT_EQ(b5, bytes[4]);\
EXPECT_EQ(b6, bytes[5]);\
EXPECT_EQ(b7, bytes[6]);\
EXPECT_EQ(b8, bytes[7]);\
} else {\
EXPECT_EQ(b1, bytes[7]);\
EXPECT_EQ(b2, bytes[6]);\
EXPECT_EQ(b3, bytes[5]);\
EXPECT_EQ(b4, bytes[4]);\
EXPECT_EQ(b5, bytes[3]);\
EXPECT_EQ(b6, bytes[2]);\
EXPECT_EQ(b7, bytes[1]);\
EXPECT_EQ(b8, bytes[0]);\
}

#define EXPECT_B16(b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, bytes) \
EXPECT_EQ(16, bytes.Length);\
if (System::BitConverter::IsLittleEndian()) {\
EXPECT_EQ(b1, bytes[0]);\
EXPECT_EQ(b2, bytes[1]);\
EXPECT_EQ(b3, bytes[2]);\
EXPECT_EQ(b4, bytes[3]);\
EXPECT_EQ(b5, bytes[4]);\
EXPECT_EQ(b6, bytes[5]);\
EXPECT_EQ(b7, bytes[6]);\
EXPECT_EQ(b8, bytes[7]);\
EXPECT_EQ(b9, bytes[8]);\
EXPECT_EQ(b10, bytes[9]);\
EXPECT_EQ(b11, bytes[10]);\
EXPECT_EQ(b12, bytes[11]);\
EXPECT_EQ(b13, bytes[12]);\
EXPECT_EQ(b14, bytes[13]);\
EXPECT_EQ(b15, bytes[14]);\
EXPECT_EQ(b16, bytes[15]);\
} else {\
EXPECT_EQ(b1, bytes[7]);\
EXPECT_EQ(b2, bytes[6]);\
EXPECT_EQ(b3, bytes[5]);\
EXPECT_EQ(b4, bytes[4]);\
EXPECT_EQ(b5, bytes[3]);\
EXPECT_EQ(b6, bytes[2]);\
EXPECT_EQ(b7, bytes[1]);\
EXPECT_EQ(b8, bytes[0]);\
EXPECT_EQ(b9, bytes[15]);\
EXPECT_EQ(b10, bytes[14]);\
EXPECT_EQ(b11, bytes[13]);\
EXPECT_EQ(b12, bytes[12]);\
EXPECT_EQ(b13, bytes[11]);\
EXPECT_EQ(b14, bytes[10]);\
EXPECT_EQ(b15, bytes[9]);\
EXPECT_EQ(b16, bytes[8]);\
}

namespace {
  TEST(BitConverter, GetBytesBoolean) {
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(false)) {
     EXPECT_B1(0, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(true)) {
      EXPECT_B1(1, bytes);
    }
  }
  
  TEST(BitConverter, GetBytesChar) {
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(' ')) {
      EXPECT_B4(0x20, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes('*')) {
      EXPECT_B4(0x2A, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes('3')) {
      EXPECT_B4(0x33, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes('A')) {
      EXPECT_B4(0x41, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes('[')) {
      EXPECT_B4(0x5B, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes('a')) {
      EXPECT_B4(0x61, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes('{')) {
      EXPECT_B4(0x7B, 0x00, 0x00, 0x00, bytes);
    }
  }
  
  TEST(BitConverter, GetBytesDouble) {
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(0.0)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1.0)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3F, bytes);
    }

    pcf_using(Array<byte> bytes = BitConverter::GetBytes(255.0)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x6F, 0x40, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(4294967295.0)) {
      EXPECT_B8(0x00, 0x00, 0xE0, 0xFF, 0xFF, 0xFF, 0xEF, 0x41, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(0.00390625)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x3F, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(0.00000000023283064365386962890625)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3D, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1.23456789012345E-300)) {
      EXPECT_B8(0xDF, 0x88, 0x1E, 0x1C, 0xFE, 0x74, 0xAA, 0x01, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1.2345678901234565)) {
      EXPECT_B8(0xFA, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1.2345678901234567)) {
      EXPECT_B8(0xFB, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1.2345678901234569)) {
      EXPECT_B8(0xFC, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1.23456789012345678E+300)) {
      EXPECT_B8(0x52, 0xD3, 0xBB, 0xBC, 0xE8, 0x7E, 0x3D, 0x7E, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(Double::MinValue)) {
      EXPECT_B8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(Double::MaxValue)) {
      EXPECT_B8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0x7F, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(Double::Epsilon)) {
      EXPECT_B8(0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(Double::NaN)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x7F, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(Double::NegativeInfinity)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(Double::PositiveInfinity)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x7F, bytes);
    }
  }
  
  TEST(BitConverter, GetBytesInt16) {
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(int16(0))) {
      EXPECT_B2(0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(int16(15))) {
      EXPECT_B2(0x0F, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(int16(-15))) {
      EXPECT_B2(0xF1, 0xFF, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(int16(10000))) {
      EXPECT_B2(0x10, 0x27, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(int16(-10000))) {
      EXPECT_B2(0xF0, 0xD8, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(Int16::MinValue)) {
      EXPECT_B2(0x00, 0x80, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(Int16::MaxValue)) {
      EXPECT_B2(0xFF, 0x7F, bytes);
    }
  }
  
  TEST(BitConverter, GetBytesInt32) {
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(0)) {
      EXPECT_B4(0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(15)) {
      EXPECT_B4(0x0F, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(-15)) {
      EXPECT_B4(0xF1, 0xFF, 0xFF, 0xFF, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1048576)) {
      EXPECT_B4(0x00, 0x00, 0x10, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(-1048576)) {
      EXPECT_B4(0x00, 0x00, 0xF0, 0xFF, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1000000000)) {
      EXPECT_B4(0x00, 0xCA, 0x9A, 0x3B, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(-1000000000)) {
      EXPECT_B4(0x00, 0x36, 0x65, 0xC4, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(Int32::MinValue)) {
      EXPECT_B4(0x00, 0x00, 0x00, 0x80, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(Int32::MaxValue)) {
      EXPECT_B4(0xFF, 0xFF, 0xFF, 0x7F, bytes);
    }
  }
  
  TEST(BitConverter, GetBytesInt64) {
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(0LL)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(0xFFFFFFLL)) {
      EXPECT_B8(0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1000000000LL)) {
      EXPECT_B8(0x00, 0xCA, 0x9A, 0x3B, 0x00, 0x00, 0x00, 0x00, bytes);
    }

    pcf_using(Array<byte> bytes = BitConverter::GetBytes(-1000000000LL)) {
      EXPECT_B8(0x00, 0x36, 0x65, 0xC4, 0xFF, 0xFF, 0xFF, 0xFF, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(0x100000000LL)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(-0x100000000LL)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(0xAAAAAAAAAAAALL)) {
      EXPECT_B8(0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(-0xAAAAAAAAAAAALL)) {
      EXPECT_B8(0x56, 0x55, 0x55, 0x55, 0x55, 0x55, 0xFF, 0xFF, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1000000000000000000LL)) {
      EXPECT_B8(0x00, 0x00, 0x64, 0xA7, 0xB3, 0xB6, 0xE0, 0x0D, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(-1000000000000000000LL)) {
      EXPECT_B8(0x00, 0x00, 0x9C, 0x58, 0x4C, 0x49, 0x1F, 0xF2, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(Int64::MinValue)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(Int64::MaxValue)) {
      EXPECT_B8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, bytes);
    }
  }
  
  TEST(BitConverter, GetBytesSingle) {
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(0.0f)) {
      EXPECT_B4(0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1.0f)) {
      EXPECT_B4(0x00, 0x00, 0x80, 0x3F, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(15.0f)) {
      EXPECT_B4(0x00, 0x00, 0x70, 0x41, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(65535.0f)) {
      EXPECT_B4(0x00, 0xFF, 0x7F, 0x47, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(0.00390625f)) {
      EXPECT_B4(0x00, 0x00, 0x80, 0x3B, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(0.00000000023283064365386962890625f)) {
      EXPECT_B4(0x00, 0x00, 0x80, 0x2F, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1.2345E-35f)) {
      EXPECT_B4(0x49, 0x46, 0x83, 0x05, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1.2345671f)) {
      EXPECT_B4(0x4B, 0x06, 0x9E, 0x3F, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1.2345673f)) {
      EXPECT_B4(0x4D, 0x06, 0x9E, 0x3F, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1.2345677f)) {
      EXPECT_B4(0x50, 0x06, 0x9E, 0x3F, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1.23456789E+35f)) {
      EXPECT_B4(0x1E, 0x37, 0xBE, 0x79, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(Single::MinValue)) {
      EXPECT_B4(0xFF, 0xFF, 0x7F, 0xFF, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(Single::MaxValue)) {
      EXPECT_B4(0xFF, 0xFF, 0x7F, 0x7F, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(Single::Epsilon)) {
      EXPECT_B4(0x01, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(Single::NaN)) {
      EXPECT_B4(0x00, 0x00, 0xC0, 0x7F, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(Single::NegativeInfinity)) {
      EXPECT_B4(0x00, 0x00, 0x80, 0xFF, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(Single::PositiveInfinity)) {
      EXPECT_B4(0x00, 0x00, 0x80, 0x7F, bytes);
    }
  }
  
  TEST(BitConverter, GetBytesUInt16) {
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(uint16(15))) {
      EXPECT_B2(0x0F, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(uint16(1023))) {
      EXPECT_B2(0xFF, 0x03, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(uint16(10000))) {
      EXPECT_B2(0x10, 0x27, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(uint16(0))) {
      EXPECT_B2(0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(uint16(Int16::MaxValue))) {
      EXPECT_B2(0xFF, 0x7F, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(UInt16::MaxValue)) {
      EXPECT_B2(0xFF, 0xFF, bytes);
    }
  }
  
  TEST(BitConverter, GetBytesUInt32) {
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(15U)) {
      EXPECT_B4(0x0F, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1023U)) {
      EXPECT_B4(0xFF, 0x03, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(0x100000U)) {
      EXPECT_B4(0x00, 0x00, 0x10, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1000000000U)) {
      EXPECT_B4(0x00, 0xCA, 0x9A, 0x3B, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(UInt32::MinValue)) {
      EXPECT_B4(0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(uint32(Int32::MaxValue))) {
      EXPECT_B4(0xFF, 0xFF, 0xFF, 0x7F, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(UInt32::MaxValue)) {
      EXPECT_B4(0xFF, 0xFF, 0xFF, 0xFF, bytes);
    }
  }
  
  TEST(BitConverter, GetBytesUInt64) {
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(0xFFFFFFULL)) {
      EXPECT_B8(0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1000000000ULL)) {
      EXPECT_B8(0x00, 0xCA, 0x9A, 0x3B, 0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(0x100000000ULL)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(0xAAAAAAAAAAAAULL)) {
      EXPECT_B8(0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(1000000000000000000ULL)) {
      EXPECT_B8(0x00, 0x00, 0x64, 0xA7, 0xB3, 0xB6, 0xE0, 0x0D, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(10000000000000000000ULL)) {
      EXPECT_B8(0x00, 0x00, 0xE8, 0x89, 0x04, 0x23, 0xC7, 0x8A, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(UInt64::MinValue)) {
      EXPECT_B8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(uint64(Int64::MaxValue))) {
      EXPECT_B8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, bytes);
    }
    
    pcf_using(Array<byte> bytes = BitConverter::GetBytes(UInt64::MaxValue)) {
      EXPECT_B8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, bytes);
    }
  }
  
  TEST(BitConverter, ToBoolean) {
    EXPECT_THROW(BitConverter::ToBoolean({0}, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToBoolean({0}, 1), ArgumentOutOfRangeException);

    EXPECT_FALSE(BitConverter::ToBoolean({0}, 0));
    EXPECT_TRUE(BitConverter::ToBoolean({1}, 0));
    EXPECT_TRUE(BitConverter::ToBoolean({2}, 0));
    EXPECT_TRUE(BitConverter::ToBoolean({4}, 0));
    EXPECT_TRUE(BitConverter::ToBoolean({8}, 0));
    EXPECT_TRUE(BitConverter::ToBoolean({16}, 0));
    EXPECT_TRUE(BitConverter::ToBoolean({32}, 0));
    EXPECT_TRUE(BitConverter::ToBoolean({64}, 0));
    EXPECT_TRUE(BitConverter::ToBoolean({128}, 0));
    EXPECT_TRUE(BitConverter::ToBoolean({255}, 0));
  }
  
  TEST(BitConverter, ToChar) {
    EXPECT_THROW(BitConverter::ToChar({0x00, 0x00, 0x00, 0x00}, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToChar({0x00, 0x00, 0x00, 0x00}, 4), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToChar({0x00, 0x00, 0x00, 0x00}, 1), ArgumentException);

    EXPECT_EQ(' ', BitConverter::ToChar({0x20, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ('*', BitConverter::ToChar({0x2A, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ('3', BitConverter::ToChar({0x33, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ('A', BitConverter::ToChar({0x41, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ('[', BitConverter::ToChar({0x5B, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ('a', BitConverter::ToChar({0x61, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ('{', BitConverter::ToChar({0x7B, 0x00, 0x00, 0x00}, 0));
  }
  
  TEST(BitConverter, ToDouble) {
    EXPECT_THROW(BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 8), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 1), ArgumentException);

    EXPECT_EQ(0.0, BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ(1.0, BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3F}, 0));
    EXPECT_EQ(255.0, BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x6F, 0x40}, 0));
    EXPECT_EQ(4294967295.0, BitConverter::ToDouble({0x00, 0x00, 0xE0, 0xFF, 0xFF, 0xFF, 0xEF, 0x41}, 0));
    EXPECT_EQ(0.00390625, BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x3F}, 0));
    EXPECT_EQ(0.00000000023283064365386962890625, BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3D}, 0));
    EXPECT_EQ(1.23456789012345E-300, BitConverter::ToDouble({0xDF, 0x88, 0x1E, 0x1C, 0xFE, 0x74, 0xAA, 0x01}, 0));
    EXPECT_EQ(1.2345678901234565, BitConverter::ToDouble({0xFA, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F}, 0));
    EXPECT_EQ(1.2345678901234567, BitConverter::ToDouble({0xFB, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F}, 0));
    EXPECT_EQ(1.2345678901234569, BitConverter::ToDouble({0xFC, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F}, 0));
    EXPECT_EQ(1.23456789012345678E+300, BitConverter::ToDouble({0x52, 0xD3, 0xBB, 0xBC, 0xE8, 0x7E, 0x3D, 0x7E}, 0));
    EXPECT_EQ(Double::MinValue, BitConverter::ToDouble({0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF}, 0));
    EXPECT_EQ(Double::MaxValue, BitConverter::ToDouble({0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0x7F}, 0));
    EXPECT_EQ(Double::Epsilon, BitConverter::ToDouble({0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
    EXPECT_TRUE(Double::IsNaN(BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x7F}, 0)));
    EXPECT_EQ(Double::NegativeInfinity, BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF}, 0));
    EXPECT_EQ(Double::PositiveInfinity, BitConverter::ToDouble({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x7F}, 0));
  }
  
  TEST(BitConverter, ToInt16) {
    EXPECT_THROW(BitConverter::ToInt16({0x00, 0x00}, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToInt16({0x00, 0x00}, 2), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToInt16({0x00, 0x00}, 1), ArgumentException);
    
    EXPECT_EQ(0, BitConverter::ToInt16({0x00, 0x00}, 0));
    EXPECT_EQ(15, BitConverter::ToInt16({0x0F, 0x00}, 0));
    EXPECT_EQ(-15, BitConverter::ToInt16({0xF1, 0xFF}, 0));
    EXPECT_EQ(10000, BitConverter::ToInt16({0x10, 0x27}, 0));
    EXPECT_EQ(-10000, BitConverter::ToInt16({0xF0, 0xD8}, 0));
    EXPECT_EQ(Int16::MinValue, BitConverter::ToInt16({0x00, 0x80}, 0));
    EXPECT_EQ(Int16::MaxValue, BitConverter::ToInt16({0xFF, 0x7F}, 0));
  }
  
  TEST(BitConverter, ToInt32) {
    EXPECT_THROW(BitConverter::ToInt32({0x00, 0x00, 0x00, 0x00}, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToInt32({0x00, 0x00, 0x00, 0x00}, 4), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToInt32({0x00, 0x00, 0x00, 0x00}, 1), ArgumentException);

    EXPECT_EQ(0, BitConverter::ToInt32({0x00, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ(15, BitConverter::ToInt32({0x0F, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ(-15, BitConverter::ToInt32({0xF1, 0xFF, 0xFF, 0xFF}, 0));
    EXPECT_EQ(1048576, BitConverter::ToInt32({0x00, 0x00, 0x10, 0x00}, 0));
    EXPECT_EQ(-1048576, BitConverter::ToInt32({0x00, 0x00, 0xF0, 0xFF}, 0));
    EXPECT_EQ(1000000000, BitConverter::ToInt32({0x00, 0xCA, 0x9A, 0x3B}, 0));
    EXPECT_EQ(-1000000000, BitConverter::ToInt32({0x00, 0x36, 0x65, 0xC4}, 0));
    EXPECT_EQ(Int32::MinValue, BitConverter::ToInt32({0x00, 0x00, 0x00, 0x80}, 0));
    EXPECT_EQ(Int32::MaxValue, BitConverter::ToInt32({0xFF, 0xFF, 0xFF, 0x7F}, 0));
  }
  
  TEST(BitConverter, ToInt64) {
    EXPECT_THROW(BitConverter::ToInt64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToInt64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 8), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToInt64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 1), ArgumentException);

    EXPECT_EQ(0LL, BitConverter::ToInt64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ(0xFFFFFFLL, BitConverter::ToInt64({0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ(1000000000LL, BitConverter::ToInt64({0x00, 0xCA, 0x9A, 0x3B, 0x00, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ(-1000000000LL, BitConverter::ToInt64({0x00, 0x36, 0x65, 0xC4, 0xFF, 0xFF, 0xFF, 0xFF}, 0));
    EXPECT_EQ(0x100000000LL, BitConverter::ToInt64({0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ(-0x100000000LL, BitConverter::ToInt64({0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF}, 0));
    EXPECT_EQ(0xAAAAAAAAAAAALL, BitConverter::ToInt64({0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00}, 0));
    EXPECT_EQ(-0xAAAAAAAAAAAALL, BitConverter::ToInt64({0x56, 0x55, 0x55, 0x55, 0x55, 0x55, 0xFF, 0xFF}, 0));
    EXPECT_EQ(1000000000000000000LL, BitConverter::ToInt64({0x00, 0x00, 0x64, 0xA7, 0xB3, 0xB6, 0xE0, 0x0D}, 0));
    EXPECT_EQ(-1000000000000000000LL, BitConverter::ToInt64({0x00, 0x00, 0x9C, 0x58, 0x4C, 0x49, 0x1F, 0xF2}, 0));
    EXPECT_EQ(Int64::MinValue, BitConverter::ToInt64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80}, 0));
    EXPECT_EQ(Int64::MaxValue, BitConverter::ToInt64({0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F}, 0));
  }
  
  TEST(BitConverter, ToSingle) {
    EXPECT_THROW(BitConverter::ToSingle({0x00, 0x00, 0x00, 0x00}, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToSingle({0x00, 0x00, 0x00, 0x00}, 4), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToSingle({0x00, 0x00, 0x00, 0x00}, 1), ArgumentException);

    EXPECT_EQ(0.0, BitConverter::ToSingle({0x00, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ(1.0f, BitConverter::ToSingle({0x00, 0x00, 0x80, 0x3F}, 0));
    EXPECT_EQ(15.0f, BitConverter::ToSingle({0x00, 0x00, 0x70, 0x41}, 0));
    EXPECT_EQ(65535.0f, BitConverter::ToSingle({0x00, 0xFF, 0x7F, 0x47}, 0));
    EXPECT_EQ(0.00390625f, BitConverter::ToSingle({0x00, 0x00, 0x80, 0x3B}, 0));
    EXPECT_EQ(0.00000000023283064365386962890625f, BitConverter::ToSingle({0x00, 0x00, 0x80, 0x2F}, 0));
    EXPECT_EQ(1.2345E-35f, BitConverter::ToSingle({0x49, 0x46, 0x83, 0x05}, 0));
    EXPECT_EQ(1.2345671f, BitConverter::ToSingle({0x4B, 0x06, 0x9E, 0x3F}, 0));
    EXPECT_EQ(1.2345673f, BitConverter::ToSingle({0x4D, 0x06, 0x9E, 0x3F}, 0));
    EXPECT_EQ(1.2345677f, BitConverter::ToSingle({0x50, 0x06, 0x9E, 0x3F}, 0));
    EXPECT_EQ(1.23456789E+35f, BitConverter::ToSingle({0x1E, 0x37, 0xBE, 0x79}, 0));
    EXPECT_EQ(Single::MinValue, BitConverter::ToSingle({0xFF, 0xFF, 0x7F, 0xFF}, 0));
    EXPECT_EQ(Single::MaxValue, BitConverter::ToSingle({0xFF, 0xFF, 0x7F, 0x7F}, 0));
    EXPECT_EQ(Single::Epsilon, BitConverter::ToSingle({0x01, 0x00, 0x00, 0x00}, 0));
    EXPECT_TRUE(Single::IsNaN(BitConverter::ToSingle({0x00, 0x00, 0xC0, 0x7F}, 0)));
    EXPECT_EQ(Single::NegativeInfinity, BitConverter::ToSingle({0x00, 0x00, 0x80, 0xFF}, 0));
    EXPECT_EQ(Single::PositiveInfinity, BitConverter::ToSingle({0x00, 0x00, 0x80, 0x7F}, 0));
  }
  
  TEST(BitConverter, ToString) {
    Array<byte> arrayOne = {0, 1, 2, 4, 8, 16, 32, 64, 128, 255};
    EXPECT_EQ("00-01-02-04-08-10-20-40-80-FF", BitConverter::ToString(arrayOne));

    Array<byte> arrayTwo = {32, 0, 0, 42, 0, 65, 0, 125, 0, 197, 0, 168, 3, 41, 4, 172, 32};
    EXPECT_EQ("20-00-00-2A-00-41-00-7D-00-C5-00-A8-03-29-04-AC-20", BitConverter::ToString(arrayTwo));

    Array<byte> arrayThree = {15, 0, 0, 128, 16, 39, 240, 216, 241, 255, 127};
    EXPECT_EQ("0F-00-00-80-10-27-F0-D8-F1-FF-7F", BitConverter::ToString(arrayThree));

    Array<byte> arrayFour = {15, 0, 0, 0, 0, 16, 0, 255, 3, 0, 0, 202, 154, 59, 255, 255, 255, 255, 127};
    EXPECT_EQ("0F-00-00-00-00-10-00-FF-03-00-00-CA-9A-3B-FF-FF-FF-FF-7F", BitConverter::ToString(arrayFour));

    Array<byte> arrayEmpty;
    EXPECT_EQ("", BitConverter::ToString(arrayEmpty));
  }
  
  TEST(BitConverter, ToStringWithStartIndex) {
    Array<byte> arrayOne = {3,6,9};
    EXPECT_THROW(BitConverter::ToString(arrayOne, -1), ArgumentOutOfRangeException);
    EXPECT_EQ("03-06-09", BitConverter::ToString(arrayOne, 0));
    EXPECT_EQ("06-09", BitConverter::ToString(arrayOne, 1));
    EXPECT_EQ("09", BitConverter::ToString(arrayOne, 2));
    EXPECT_THROW(BitConverter::ToString(arrayOne, 3), ArgumentOutOfRangeException);
    
    Array<byte> arrayEmpty;
    EXPECT_EQ("", BitConverter::ToString(arrayEmpty, 0));
    EXPECT_THROW(BitConverter::ToString(arrayEmpty, 1), ArgumentOutOfRangeException);
  }
  
  TEST(BitConverter, ToStringWithStartIndexAndLength) {
    Array<byte> arrayOne = {3,6,9};
    
    EXPECT_THROW(BitConverter::ToString(arrayOne, -1, 1), ArgumentOutOfRangeException);
    
    EXPECT_THROW(BitConverter::ToString(arrayOne, 0, -1), ArgumentException);
    EXPECT_EQ("", BitConverter::ToString(arrayOne, 0, 0));
    EXPECT_EQ("03", BitConverter::ToString(arrayOne, 0, 1));
    EXPECT_EQ("03-06", BitConverter::ToString(arrayOne, 0, 2));
    EXPECT_EQ("03-06-09", BitConverter::ToString(arrayOne, 0, 3));
    EXPECT_THROW(BitConverter::ToString(arrayOne, 0, 4), ArgumentException);
    
    EXPECT_THROW(BitConverter::ToString(arrayOne, 1, -1), ArgumentException);
    EXPECT_EQ("", BitConverter::ToString(arrayOne, 1, 0));
    EXPECT_EQ("06", BitConverter::ToString(arrayOne, 1, 1));
    EXPECT_EQ("06-09", BitConverter::ToString(arrayOne, 1, 2));
    EXPECT_THROW(BitConverter::ToString(arrayOne, 1, 3), ArgumentException);

    EXPECT_THROW(BitConverter::ToString(arrayOne, 2, -1), ArgumentException);
    EXPECT_EQ("", BitConverter::ToString(arrayOne, 2, 0));
    EXPECT_EQ("09", BitConverter::ToString(arrayOne, 2, 1));
    EXPECT_THROW(BitConverter::ToString(arrayOne, 2, 2), ArgumentException);
    
    EXPECT_THROW(BitConverter::ToString(arrayOne, 3, 1), ArgumentOutOfRangeException);
    
    Array<byte> arrayEmpty;
    EXPECT_THROW(BitConverter::ToString(arrayEmpty, 1), ArgumentOutOfRangeException);
  }
  
  TEST(BitConverter, ToUInt16) {
    EXPECT_THROW(BitConverter::ToUInt16({0x00, 0x00}, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToUInt16({0x00, 0x00}, 2), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToUInt16({0x00, 0x00}, 1), ArgumentException);
 
    EXPECT_EQ(15, BitConverter::ToUInt16({0x0F, 0x00}, 0));
    EXPECT_EQ(1023, BitConverter::ToUInt16({0xFF, 0x03}, 0));
    EXPECT_EQ(10000, BitConverter::ToUInt16({0x10, 0x27}, 0));
    EXPECT_EQ(0, BitConverter::ToUInt16({0x00, 0x00}, 0));
    EXPECT_EQ(uint16(Int16::MaxValue), BitConverter::ToUInt16({0xFF, 0x7F}, 0));
    EXPECT_EQ(UInt16::MaxValue, BitConverter::ToUInt16({0xFF, 0xFF}, 0));
  }
  
  TEST(BitConverter, ToUInt32) {
    EXPECT_THROW(BitConverter::ToUInt32({0x00, 0x00, 0x00, 0x00}, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToUInt32({0x00, 0x00, 0x00, 0x00}, 4), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToUInt32({0x00, 0x00, 0x00, 0x00}, 1), ArgumentException);

    EXPECT_EQ(15U, BitConverter::ToUInt32({0x0F, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ(1023U, BitConverter::ToUInt32({0xFF, 0x03, 0x00, 0x00}, 0));
    EXPECT_EQ(0x100000U, BitConverter::ToUInt32({0x00, 0x00, 0x10, 0x00}, 0));
    EXPECT_EQ(1000000000U, BitConverter::ToUInt32({0x00, 0xCA, 0x9A, 0x3B}, 0));
    EXPECT_EQ(UInt32::MinValue, BitConverter::ToUInt32({0x00, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ(uint32(Int32::MaxValue), BitConverter::ToUInt32({0xFF, 0xFF, 0xFF, 0x7F}, 0));
    EXPECT_EQ(UInt32::MaxValue, BitConverter::ToUInt32({0xFF, 0xFF, 0xFF, 0xFF}, 0));
  }
  
  TEST(BitConverter, ToUInt64) {
    EXPECT_THROW(BitConverter::ToUInt64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToUInt64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 8), ArgumentOutOfRangeException);
    EXPECT_THROW(BitConverter::ToUInt64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 1), ArgumentException);

    EXPECT_EQ(0xFFFFFFULL, BitConverter::ToUInt64({0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ(1000000000ULL, BitConverter::ToUInt64({0x00, 0xCA, 0x9A, 0x3B, 0x00, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ(0x100000000ULL, BitConverter::ToUInt64({0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ(0xAAAAAAAAAAAAULL, BitConverter::ToUInt64({0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00}, 0));
    EXPECT_EQ(1000000000000000000ULL, BitConverter::ToUInt64({0x00, 0x00, 0x64, 0xA7, 0xB3, 0xB6, 0xE0, 0x0D}, 0));
    EXPECT_EQ(10000000000000000000ULL, BitConverter::ToUInt64({0x00, 0x00, 0xE8, 0x89, 0x04, 0x23, 0xC7, 0x8A}, 0));
    EXPECT_EQ(UInt64::MinValue, BitConverter::ToUInt64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
    EXPECT_EQ(uint64(Int64::MaxValue), BitConverter::ToUInt64({0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F}, 0));
    EXPECT_EQ(UInt64::MaxValue, BitConverter::ToUInt64({0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 0));
  }
}
