#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class NativeTest : public TestFixture {
  protected:
    void SizeOfBool() {
      EXPECT_EQ(1u, sizeof(bool));
      EXPECT_EQ(1u, sizeof(bool));
    }
    
    void SizeOfChar() {
      EXPECT_EQ(4u, sizeof(char32));
      EXPECT_EQ(2u, sizeof(char16));
      EXPECT_EQ(1u, sizeof(char));
    }
    
    void SizeOfByte() {
      EXPECT_EQ(1u, sizeof(byte));
      EXPECT_EQ(1u, sizeof(unsigned char));
      EXPECT_EQ(1u, sizeof(uint8_t));
    }
    
    void SizeOfInt16() {
      EXPECT_EQ(2u, sizeof(int16));
      EXPECT_EQ(2u, sizeof(short));
      EXPECT_EQ(2u, sizeof(int16_t));
    }
    
    void SizeOfInt32() {
      EXPECT_EQ(4u, sizeof(int32));
      EXPECT_EQ(4u, sizeof(int));
      EXPECT_EQ(4u, sizeof(int32_t));
    }
    
    void SizeOfInt64() {
      EXPECT_EQ(8u, sizeof(int64));
      //EXPECT_EQ(8u, sizeof(long));
      EXPECT_EQ(8u, sizeof(long long));
      EXPECT_EQ(8u, sizeof(int64_t));
    }
    
    void SizeOfSByte() {
      EXPECT_EQ(1u, sizeof(sbyte));
      EXPECT_EQ(1u, sizeof(char));
      EXPECT_EQ(1u, sizeof(int8_t));
    }
    
    void SizeOfUInt16() {
      EXPECT_EQ(2u, sizeof(uint16));
      EXPECT_EQ(2u, sizeof(unsigned short));
      EXPECT_EQ(2u, sizeof(uint16_t));
    }
    
    void SizeOfUInt32() {
      EXPECT_EQ(4u, sizeof(uint32));
      EXPECT_EQ(4u, sizeof(unsigned int));
      EXPECT_EQ(4u, sizeof(uint32_t));
    }
    
    void SizeOfUInt64() {
      EXPECT_EQ(8u, sizeof(uint64));
      //EXPECT_EQ(8u, sizeof(unsigned long));
      EXPECT_EQ(8u, sizeof(unsigned long long));
      EXPECT_EQ(8u, sizeof(uint64_t));
    }
    
    void SizeOfFloat() {
      EXPECT_EQ(4u, sizeof(float));
    }
    
    void SizeOfDouble() {
      EXPECT_EQ(8u, sizeof(double));
    }
  };
 
  pcf_test(NativeTest, SizeOfBool);
  pcf_test(NativeTest, SizeOfChar);
  pcf_test(NativeTest, SizeOfByte);
  pcf_test(NativeTest, SizeOfInt16);
  pcf_test(NativeTest, SizeOfInt32);
  pcf_test(NativeTest, SizeOfInt64);
  pcf_test(NativeTest, SizeOfSByte);
  pcf_test(NativeTest, SizeOfUInt16);
  pcf_test(NativeTest, SizeOfUInt32);
  pcf_test(NativeTest, SizeOfUInt64);
  pcf_test(NativeTest, SizeOfFloat);
  pcf_test(NativeTest, SizeOfDouble);
}
