#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class NativeTest : public TestFixture {
  protected:
    void SizeOfBool() {
      Assert::AreEqual(1u, sizeof(bool), _caller);
      Assert::AreEqual(1u, sizeof(bool), _caller);
    }
    
    void SizeOfChar() {
      Assert::AreEqual(4u, sizeof(char32), _caller);
      Assert::AreEqual(2u, sizeof(char16), _caller);
      Assert::AreEqual(1u, sizeof(char), _caller);
    }
    
    void SizeOfByte() {
      Assert::AreEqual(1u, sizeof(byte), _caller);
      Assert::AreEqual(1u, sizeof(unsigned char), _caller);
      Assert::AreEqual(1u, sizeof(uint8_t), _caller);
    }
    
    void SizeOfInt16() {
      Assert::AreEqual(2u, sizeof(int16), _caller);
      Assert::AreEqual(2u, sizeof(short), _caller);
      Assert::AreEqual(2u, sizeof(int16_t), _caller);
    }
    
    void SizeOfInt32() {
      Assert::AreEqual(4u, sizeof(int32), _caller);
      Assert::AreEqual(4u, sizeof(int), _caller);
      Assert::AreEqual(4u, sizeof(int32_t), _caller);
    }
    
    void SizeOfInt64() {
      Assert::AreEqual(8u, sizeof(int64), _caller);
      //Assert::AreEqual(8u, sizeof(long), _caller);
      Assert::AreEqual(8u, sizeof(long long), _caller);
      Assert::AreEqual(8u, sizeof(int64_t), _caller);
    }
    
    void SizeOfSByte() {
      Assert::AreEqual(1u, sizeof(sbyte), _caller);
      Assert::AreEqual(1u, sizeof(char), _caller);
      Assert::AreEqual(1u, sizeof(int8_t), _caller);
    }
    
    void SizeOfUInt16() {
      Assert::AreEqual(2u, sizeof(uint16), _caller);
      Assert::AreEqual(2u, sizeof(unsigned short), _caller);
      Assert::AreEqual(2u, sizeof(uint16_t), _caller);
    }
    
    void SizeOfUInt32() {
      Assert::AreEqual(4u, sizeof(uint32), _caller);
      Assert::AreEqual(4u, sizeof(unsigned int), _caller);
      Assert::AreEqual(4u, sizeof(uint32_t), _caller);
    }
    
    void SizeOfUInt64() {
      Assert::AreEqual(8u, sizeof(uint64), _caller);
      //Assert::AreEqual(8u, sizeof(unsigned long), _caller);
      Assert::AreEqual(8u, sizeof(unsigned long long), _caller);
      Assert::AreEqual(8u, sizeof(uint64_t), _caller);
    }
    
    void SizeOfFloat() {
      Assert::AreEqual(4u, sizeof(float), _caller);
    }
    
    void SizeOfDouble() {
      Assert::AreEqual(8u, sizeof(double), _caller);
    }
  };
 
  _add_test(NativeTest, SizeOfBool)
  _add_test(NativeTest, SizeOfChar)
  _add_test(NativeTest, SizeOfByte)
  _add_test(NativeTest, SizeOfInt16)
  _add_test(NativeTest, SizeOfInt32)
  _add_test(NativeTest, SizeOfInt64)
  _add_test(NativeTest, SizeOfSByte)
  _add_test(NativeTest, SizeOfUInt16)
  _add_test(NativeTest, SizeOfUInt32)
  _add_test(NativeTest, SizeOfUInt64)
  _add_test(NativeTest, SizeOfFloat)
  _add_test(NativeTest, SizeOfDouble)
}
