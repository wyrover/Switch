#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class NativeTest : public TestFixture {
  protected:
    void SizeOfBool() {
      Assert::AreEqual(1u, sizeof(bool), sw_current_information);
      Assert::AreEqual(1u, sizeof(bool), sw_current_information);
    }
    
    void SizeOfChar() {
      Assert::AreEqual(4u, sizeof(char32), sw_current_information);
      Assert::AreEqual(2u, sizeof(char16), sw_current_information);
      Assert::AreEqual(1u, sizeof(char), sw_current_information);
    }
    
    void SizeOfByte() {
      Assert::AreEqual(1u, sizeof(byte), sw_current_information);
      Assert::AreEqual(1u, sizeof(unsigned char), sw_current_information);
      Assert::AreEqual(1u, sizeof(uint8_t), sw_current_information);
    }
    
    void SizeOfInt16() {
      Assert::AreEqual(2u, sizeof(int16), sw_current_information);
      Assert::AreEqual(2u, sizeof(short), sw_current_information);
      Assert::AreEqual(2u, sizeof(int16_t), sw_current_information);
    }
    
    void SizeOfInt32() {
      Assert::AreEqual(4u, sizeof(int32), sw_current_information);
      Assert::AreEqual(4u, sizeof(int), sw_current_information);
      Assert::AreEqual(4u, sizeof(int32_t), sw_current_information);
    }
    
    void SizeOfInt64() {
      Assert::AreEqual(8u, sizeof(int64), sw_current_information);
      //Assert::AreEqual(8u, sizeof(long), sw_current_information);
      Assert::AreEqual(8u, sizeof(long long), sw_current_information);
      Assert::AreEqual(8u, sizeof(int64_t), sw_current_information);
    }
    
    void SizeOfSByte() {
      Assert::AreEqual(1u, sizeof(sbyte), sw_current_information);
      Assert::AreEqual(1u, sizeof(char), sw_current_information);
      Assert::AreEqual(1u, sizeof(int8_t), sw_current_information);
    }
    
    void SizeOfUInt16() {
      Assert::AreEqual(2u, sizeof(uint16), sw_current_information);
      Assert::AreEqual(2u, sizeof(unsigned short), sw_current_information);
      Assert::AreEqual(2u, sizeof(uint16_t), sw_current_information);
    }
    
    void SizeOfUInt32() {
      Assert::AreEqual(4u, sizeof(uint32), sw_current_information);
      Assert::AreEqual(4u, sizeof(unsigned int), sw_current_information);
      Assert::AreEqual(4u, sizeof(uint32_t), sw_current_information);
    }
    
    void SizeOfUInt64() {
      Assert::AreEqual(8u, sizeof(uint64), sw_current_information);
      //Assert::AreEqual(8u, sizeof(unsigned long), sw_current_information);
      Assert::AreEqual(8u, sizeof(unsigned long long), sw_current_information);
      Assert::AreEqual(8u, sizeof(uint64_t), sw_current_information);
    }
    
    void SizeOfFloat() {
      Assert::AreEqual(4u, sizeof(float), sw_current_information);
    }
    
    void SizeOfDouble() {
      Assert::AreEqual(8u, sizeof(double), sw_current_information);
    }
  };
 
  sw_test(NativeTest, SizeOfBool)
  sw_test(NativeTest, SizeOfChar)
  sw_test(NativeTest, SizeOfByte)
  sw_test(NativeTest, SizeOfInt16)
  sw_test(NativeTest, SizeOfInt32)
  sw_test(NativeTest, SizeOfInt64)
  sw_test(NativeTest, SizeOfSByte)
  sw_test(NativeTest, SizeOfUInt16)
  sw_test(NativeTest, SizeOfUInt32)
  sw_test(NativeTest, SizeOfUInt64)
  sw_test(NativeTest, SizeOfFloat)
  sw_test(NativeTest, SizeOfDouble)
}
