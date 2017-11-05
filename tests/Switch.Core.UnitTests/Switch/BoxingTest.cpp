#include <Switch/Boxing.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class BoxTest : public TestFixture {
  protected:
    void BoxingBoolean() {
      Assert::IsInstanceOf<Boolean>(Box(true), _caller);
    }
    
    void BoxingByte() {
      Assert::IsInstanceOf<Byte>(Box(byte(42)), _caller);
    }
    
    void BoxingChar() {
      Assert::IsInstanceOf<Char>(Box(char('c')), _caller);
    }
    
    void BoxingWChar() {
      Assert::IsInstanceOf<Char>(Box(wchar('c')), _caller);
    }
    
    void BoxingChar16() {
      Assert::IsInstanceOf<Char>(Box(char16('c')), _caller);
    }
    
    void BoxingChar32() {
      Assert::IsInstanceOf<Char>(Box(char32('c')), _caller);
    }
    
    void BoxingDouble() {
      Assert::IsInstanceOf<Double>(Box(double(42)), _caller);
    }
    
    void BoxingInt16() {
      Assert::IsInstanceOf<Int16>(Box(int16(42)), _caller);
    }
    
    void BoxingInt32() {
      Assert::IsInstanceOf<Int32>(Box(int32(42)), _caller);
    }
    
    void BoxingInt64() {
      Assert::IsInstanceOf<Int64>(Box(int64(42)), _caller);
    }
    
    void BoxingSByte() {
      Assert::IsInstanceOf<SByte>(Box(sbyte(42)), _caller);
    }
    
    void BoxingSingle() {
      Assert::IsInstanceOf<Single>(Box(float(42)), _caller);
    }
    
    void BoxingString() {
      Assert::IsInstanceOf<string>(Box(string("Forty two")), _caller);
    }
    
    void BoxingUInt16() {
      Assert::IsInstanceOf<UInt16>(Box(uint16(42)), _caller);
    }
    
    void BoxingUInt32() {
      Assert::IsInstanceOf<UInt32>(Box(uint32(42)), _caller);
    }
    
    void BoxingUInt64() {
      Assert::IsInstanceOf<UInt64>(Box(uint64(42)), _caller);
    }
    
    void BoxingVoidPointer() {
      Assert::IsInstanceOf<IntPtr>(Box((void*)42), _caller);
    }
    
    void BoxingConstCharPointer() {
      Assert::IsInstanceOf<string>(Box("Forty two"), _caller);
    }
    
    void BoxingConstWCharPointer() {
      Assert::IsInstanceOf<string>(Box(L"Forty two"), _caller);
    }
    
    void BoxingConstChar16Pointer() {
      Assert::IsInstanceOf<string>(Box(u"Forty two"), _caller);
    }
    
    void BoxingConstChar32Pointer() {
      Assert::IsInstanceOf<string>(Box(U"Forty two"), _caller);
    }
    
    void BoxingTimeSpan() {
      Assert::IsInstanceOf<TimeSpan>(Box(12_h + 24_min + 32_s), _caller);
    }
    
    void BoxingAny() {
      Assert::IsInstanceOf<Int32>(Box(Any(42)), _caller);
    }
    
    void BoxingMyStruct() {
      struct MyStruct {};
      Assert::IsInstanceOf<MyStruct>(Box(MyStruct()), _caller);
    }
  };
  
  _AddTest(BoxTest, BoxingBoolean)
  _AddTest(BoxTest, BoxingByte)
  _AddTest(BoxTest, BoxingChar)
  _AddTest(BoxTest, BoxingWChar)
  _AddTest(BoxTest, BoxingChar16)
  _AddTest(BoxTest, BoxingChar32)
  _AddTest(BoxTest, BoxingDouble)
  _AddTest(BoxTest, BoxingInt16)
  _AddTest(BoxTest, BoxingInt32)
  _AddTest(BoxTest, BoxingInt64)
  _AddTest(BoxTest, BoxingSByte)
  _AddTest(BoxTest, BoxingSingle)
  _AddTest(BoxTest, BoxingString)
  _AddTest(BoxTest, BoxingUInt16)
  _AddTest(BoxTest, BoxingUInt32)
  _AddTest(BoxTest, BoxingUInt64)
  _AddTest(BoxTest, BoxingVoidPointer)
  _AddTest(BoxTest, BoxingConstCharPointer)
  _AddTest(BoxTest, BoxingConstWCharPointer)
  _AddTest(BoxTest, BoxingConstChar16Pointer)
  _AddTest(BoxTest, BoxingConstChar32Pointer)
  _AddTest(BoxTest, BoxingAny)
  _AddTest(BoxTest, BoxingMyStruct)
}
