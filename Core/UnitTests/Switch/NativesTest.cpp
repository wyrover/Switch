#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class NativeTest : public TestFixture {
  protected:
    void SizeOfBool() {
      Assert::AreEqual(1u, sizeof(bool), _current_information);
      Assert::AreEqual(1u, sizeof(bool), _current_information);
    }
    
    void SizeOfChar() {
      Assert::AreEqual(4u, sizeof(char32), _current_information);
      Assert::AreEqual(2u, sizeof(char16), _current_information);
      Assert::AreEqual(1u, sizeof(char), _current_information);
    }
    
    void SizeOfByte() {
      Assert::AreEqual(1u, sizeof(byte), _current_information);
      Assert::AreEqual(1u, sizeof(unsigned char), _current_information);
      Assert::AreEqual(1u, sizeof(uint8_t), _current_information);
    }
    
    void SizeOfInt16() {
      Assert::AreEqual(2u, sizeof(int16), _current_information);
      Assert::AreEqual(2u, sizeof(short), _current_information);
      Assert::AreEqual(2u, sizeof(int16_t), _current_information);
    }
    
    void SizeOfInt32() {
      Assert::AreEqual(4u, sizeof(int32), _current_information);
      Assert::AreEqual(4u, sizeof(int), _current_information);
      Assert::AreEqual(4u, sizeof(int32_t), _current_information);
    }
    
    void SizeOfInt64() {
      Assert::AreEqual(8u, sizeof(int64), _current_information);
      //Assert::AreEqual(8u, sizeof(long), _current_information);
      Assert::AreEqual(8u, sizeof(long long), _current_information);
      Assert::AreEqual(8u, sizeof(int64_t), _current_information);
    }
    
    void SizeOfSByte() {
      Assert::AreEqual(1u, sizeof(sbyte), _current_information);
      Assert::AreEqual(1u, sizeof(char), _current_information);
      Assert::AreEqual(1u, sizeof(int8_t), _current_information);
    }
    
    void SizeOfUInt16() {
      Assert::AreEqual(2u, sizeof(uint16), _current_information);
      Assert::AreEqual(2u, sizeof(unsigned short), _current_information);
      Assert::AreEqual(2u, sizeof(uint16_t), _current_information);
    }
    
    void SizeOfUInt32() {
      Assert::AreEqual(4u, sizeof(uint32), _current_information);
      Assert::AreEqual(4u, sizeof(unsigned int), _current_information);
      Assert::AreEqual(4u, sizeof(uint32_t), _current_information);
    }
    
    void SizeOfUInt64() {
      Assert::AreEqual(8u, sizeof(uint64), _current_information);
      //Assert::AreEqual(8u, sizeof(unsigned long), _current_information);
      Assert::AreEqual(8u, sizeof(unsigned long long), _current_information);
      Assert::AreEqual(8u, sizeof(uint64_t), _current_information);
    }
    
    void SizeOfFloat() {
      Assert::AreEqual(4u, sizeof(float), _current_information);
    }
    
    void SizeOfDouble() {
      Assert::AreEqual(8u, sizeof(double), _current_information);
    }
  };
 
  _test(NativeTest, SizeOfBool)
  _test(NativeTest, SizeOfChar)
  _test(NativeTest, SizeOfByte)
  _test(NativeTest, SizeOfInt16)
  _test(NativeTest, SizeOfInt32)
  _test(NativeTest, SizeOfInt64)
  _test(NativeTest, SizeOfSByte)
  _test(NativeTest, SizeOfUInt16)
  _test(NativeTest, SizeOfUInt32)
  _test(NativeTest, SizeOfUInt64)
  _test(NativeTest, SizeOfFloat)
  _test(NativeTest, SizeOfDouble)
}
