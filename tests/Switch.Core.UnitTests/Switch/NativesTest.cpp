#include <Switch/Types.hpp>
#include <gtest/gtest.h>

namespace SwitchUnitTests {
  TEST(NativeTest, SizeOfBool) {
    ASSERT_EQ(1u, sizeof(bool));
    ASSERT_EQ(1u, sizeof(bool));
  }

  TEST(NativeTest, SizeOfChar) {
    ASSERT_EQ(4u, sizeof(char32));
    ASSERT_EQ(2u, sizeof(char16));
    ASSERT_EQ(1u, sizeof(char));
  }

  TEST(NativeTest, SizeOfByte) {
    ASSERT_EQ(1u, sizeof(byte));
    ASSERT_EQ(1u, sizeof(unsigned char));
    ASSERT_EQ(1u, sizeof(uint8_t));
  }

  TEST(NativeTest, SizeOfInt16) {
    ASSERT_EQ(2u, sizeof(int16));
    ASSERT_EQ(2u, sizeof(short));
    ASSERT_EQ(2u, sizeof(int16_t));
  }

  TEST(NativeTest, SizeOfInt32) {
    ASSERT_EQ(4u, sizeof(int32));
    ASSERT_EQ(4u, sizeof(int));
    ASSERT_EQ(4u, sizeof(int32_t));
  }

  TEST(NativeTest, SizeOfInt64) {
    ASSERT_EQ(8u, sizeof(int64));
    //ASSERT_EQ(8u, sizeof(long));
    ASSERT_EQ(8u, sizeof(long long));
    ASSERT_EQ(8u, sizeof(int64_t));
  }

  TEST(NativeTest, SizeOfSByte) {
    ASSERT_EQ(1u, sizeof(sbyte));
    ASSERT_EQ(1u, sizeof(char));
    ASSERT_EQ(1u, sizeof(int8_t));
  }

  TEST(NativeTest, SizeOfUInt16) {
    ASSERT_EQ(2u, sizeof(uint16));
    ASSERT_EQ(2u, sizeof(unsigned short));
    ASSERT_EQ(2u, sizeof(uint16_t));
  }

  TEST(NativeTest, SizeOfUInt32) {
    ASSERT_EQ(4u, sizeof(uint32));
    ASSERT_EQ(4u, sizeof(unsigned int));
    ASSERT_EQ(4u, sizeof(uint32_t));
  }

  TEST(NativeTest, SizeOfUInt64) {
    ASSERT_EQ(8u, sizeof(uint64));
    //ASSERT_EQ(8u, sizeof(unsigned long));
    ASSERT_EQ(8u, sizeof(unsigned long long));
    ASSERT_EQ(8u, sizeof(uint64_t));
  }

  TEST(NativeTest, SizeOfFloat) {
    ASSERT_EQ(4u, sizeof(float));
  }

  TEST(NativeTest, SizeOfDouble) {
    ASSERT_EQ(8u, sizeof(double));
  }
}
