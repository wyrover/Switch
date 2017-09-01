#include <Switch/Boxing.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class BoxTest : public TestFixture {
  protected:
    void BoxingBoolean() {
      Assert::IsInstanceOf<Boolean>(Box(true), _current_information);
    }
    
    void BoxingByte() {
      Assert::IsInstanceOf<Byte>(Box(byte(42)), _current_information);
    }
    
    void BoxingChar() {
      Assert::IsInstanceOf<Char>(Box(char('c')), _current_information);
    }
    
    void BoxingWChar() {
      Assert::IsInstanceOf<Char>(Box(wchar('c')), _current_information);
    }
    
    void BoxingChar16() {
      Assert::IsInstanceOf<Char>(Box(char16('c')), _current_information);
    }
    
    void BoxingChar32() {
      Assert::IsInstanceOf<Char>(Box(char32('c')), _current_information);
    }
    
    void BoxingDouble() {
      Assert::IsInstanceOf<Double>(Box(double(42)), _current_information);
    }
    
    void BoxingInt16() {
      Assert::IsInstanceOf<Int16>(Box(int16(42)), _current_information);
    }
    
    void BoxingInt32() {
      Assert::IsInstanceOf<Int32>(Box(int32(42)), _current_information);
    }
    
    void BoxingInt64() {
      Assert::IsInstanceOf<Int64>(Box(int64(42)), _current_information);
    }
    
    void BoxingSByte() {
      Assert::IsInstanceOf<SByte>(Box(sbyte(42)), _current_information);
    }
    
    void BoxingSingle() {
      Assert::IsInstanceOf<Single>(Box(float(42)), _current_information);
    }
    
    void BoxingString() {
      Assert::IsInstanceOf<string>(Box(string("Forty two")), _current_information);
    }
    
    void BoxingUInt16() {
      Assert::IsInstanceOf<UInt16>(Box(uint16(42)), _current_information);
    }
    
    void BoxingUInt32() {
      Assert::IsInstanceOf<UInt32>(Box(uint32(42)), _current_information);
    }
    
    void BoxingUInt64() {
      Assert::IsInstanceOf<UInt64>(Box(uint64(42)), _current_information);
    }
    
    void BoxingVoidPointer() {
      Assert::IsInstanceOf<IntPtr>(Box((void*)42), _current_information);
    }
    
    void BoxingConstCharPointer() {
      Assert::IsInstanceOf<string>(Box("Forty two"), _current_information);
    }
    
    void BoxingConstWCharPointer() {
      Assert::IsInstanceOf<string>(Box(L"Forty two"), _current_information);
    }
    
    void BoxingConstChar16Pointer() {
      Assert::IsInstanceOf<string>(Box(u"Forty two"), _current_information);
    }
    
    void BoxingConstChar32Pointer() {
      Assert::IsInstanceOf<string>(Box(U"Forty two"), _current_information);
    }
    
    void BoxingTimeSpan() {
      Assert::IsInstanceOf<TimeSpan>(Box(12_h + 24_min + 32_s), _current_information);
    }
    
    void BoxingAny() {
      Assert::IsInstanceOf<Int32>(Box(Any(42)), _current_information);
    }
    
    void BoxingMyStruct() {
      struct MyStruct {};
      Assert::IsInstanceOf<MyStruct>(Box(MyStruct()), _current_information);
    }
  };
  
  _test(BoxTest, BoxingBoolean)
  _test(BoxTest, BoxingByte)
  _test(BoxTest, BoxingChar)
  _test(BoxTest, BoxingWChar)
  _test(BoxTest, BoxingChar16)
  _test(BoxTest, BoxingChar32)
  _test(BoxTest, BoxingDouble)
  _test(BoxTest, BoxingInt16)
  _test(BoxTest, BoxingInt32)
  _test(BoxTest, BoxingInt64)
  _test(BoxTest, BoxingSByte)
  _test(BoxTest, BoxingSingle)
  _test(BoxTest, BoxingString)
  _test(BoxTest, BoxingUInt16)
  _test(BoxTest, BoxingUInt32)
  _test(BoxTest, BoxingUInt64)
  _test(BoxTest, BoxingVoidPointer)
  _test(BoxTest, BoxingConstCharPointer)
  _test(BoxTest, BoxingConstWCharPointer)
  _test(BoxTest, BoxingConstChar16Pointer)
  _test(BoxTest, BoxingConstChar32Pointer)
  _test(BoxTest, BoxingAny)
  _test(BoxTest, BoxingMyStruct)
}
