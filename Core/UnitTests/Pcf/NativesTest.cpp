#include <Pcf/TUnit/Assert.hpp>
#include <Pcf/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class NativeTest : public TestFixture {
  protected:
    void SizeOfBool() {
      Assert::AreEqual(1u, sizeof(bool), pcf_current_information);
      Assert::AreEqual(1u, sizeof(bool), pcf_current_information);
    }
    
    void SizeOfChar() {
      Assert::AreEqual(4u, sizeof(char32), pcf_current_information);
      Assert::AreEqual(2u, sizeof(char16), pcf_current_information);
      Assert::AreEqual(1u, sizeof(char), pcf_current_information);
    }
    
    void SizeOfByte() {
      Assert::AreEqual(1u, sizeof(byte), pcf_current_information);
      Assert::AreEqual(1u, sizeof(unsigned char), pcf_current_information);
      Assert::AreEqual(1u, sizeof(uint8_t), pcf_current_information);
    }
    
    void SizeOfInt16() {
      Assert::AreEqual(2u, sizeof(int16), pcf_current_information);
      Assert::AreEqual(2u, sizeof(short), pcf_current_information);
      Assert::AreEqual(2u, sizeof(int16_t), pcf_current_information);
    }
    
    void SizeOfInt32() {
      Assert::AreEqual(4u, sizeof(int32), pcf_current_information);
      Assert::AreEqual(4u, sizeof(int), pcf_current_information);
      Assert::AreEqual(4u, sizeof(int32_t), pcf_current_information);
    }
    
    void SizeOfInt64() {
      Assert::AreEqual(8u, sizeof(int64), pcf_current_information);
      //Assert::AreEqual(8u, sizeof(long), pcf_current_information);
      Assert::AreEqual(8u, sizeof(long long), pcf_current_information);
      Assert::AreEqual(8u, sizeof(int64_t), pcf_current_information);
    }
    
    void SizeOfSByte() {
      Assert::AreEqual(1u, sizeof(sbyte), pcf_current_information);
      Assert::AreEqual(1u, sizeof(char), pcf_current_information);
      Assert::AreEqual(1u, sizeof(int8_t), pcf_current_information);
    }
    
    void SizeOfUInt16() {
      Assert::AreEqual(2u, sizeof(uint16), pcf_current_information);
      Assert::AreEqual(2u, sizeof(unsigned short), pcf_current_information);
      Assert::AreEqual(2u, sizeof(uint16_t), pcf_current_information);
    }
    
    void SizeOfUInt32() {
      Assert::AreEqual(4u, sizeof(uint32), pcf_current_information);
      Assert::AreEqual(4u, sizeof(unsigned int), pcf_current_information);
      Assert::AreEqual(4u, sizeof(uint32_t), pcf_current_information);
    }
    
    void SizeOfUInt64() {
      Assert::AreEqual(8u, sizeof(uint64), pcf_current_information);
      //Assert::AreEqual(8u, sizeof(unsigned long), pcf_current_information);
      Assert::AreEqual(8u, sizeof(unsigned long long), pcf_current_information);
      Assert::AreEqual(8u, sizeof(uint64_t), pcf_current_information);
    }
    
    void SizeOfFloat() {
      Assert::AreEqual(4u, sizeof(float), pcf_current_information);
    }
    
    void SizeOfDouble() {
      Assert::AreEqual(8u, sizeof(double), pcf_current_information);
    }
  };
 
  pcf_test(NativeTest, SizeOfBool)
  pcf_test(NativeTest, SizeOfChar)
  pcf_test(NativeTest, SizeOfByte)
  pcf_test(NativeTest, SizeOfInt16)
  pcf_test(NativeTest, SizeOfInt32)
  pcf_test(NativeTest, SizeOfInt64)
  pcf_test(NativeTest, SizeOfSByte)
  pcf_test(NativeTest, SizeOfUInt16)
  pcf_test(NativeTest, SizeOfUInt32)
  pcf_test(NativeTest, SizeOfUInt64)
  pcf_test(NativeTest, SizeOfFloat)
  pcf_test(NativeTest, SizeOfDouble)
}
