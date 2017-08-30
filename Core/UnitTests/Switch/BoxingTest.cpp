#include <Switch/Boxing.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class BoxTest : public TestFixture {
  protected:
    void BoxingBoolean() {
      Assert::IsInstanceOf<Boolean>(Box(true), sw_current_information);
    }
    
    void BoxingByte() {
      Assert::IsInstanceOf<Byte>(Box(byte(42)), sw_current_information);
    }
    
    void BoxingChar() {
      Assert::IsInstanceOf<Char>(Box(char('c')), sw_current_information);
    }
    
    void BoxingWChar() {
      Assert::IsInstanceOf<Char>(Box(wchar('c')), sw_current_information);
    }
    
    void BoxingChar16() {
      Assert::IsInstanceOf<Char>(Box(char16('c')), sw_current_information);
    }
    
    void BoxingChar32() {
      Assert::IsInstanceOf<Char>(Box(char32('c')), sw_current_information);
    }
    
    void BoxingDouble() {
      Assert::IsInstanceOf<Double>(Box(double(42)), sw_current_information);
    }
    
    void BoxingInt16() {
      Assert::IsInstanceOf<Int16>(Box(int16(42)), sw_current_information);
    }
    
    void BoxingInt32() {
      Assert::IsInstanceOf<Int32>(Box(int32(42)), sw_current_information);
    }
    
    void BoxingInt64() {
      Assert::IsInstanceOf<Int64>(Box(int64(42)), sw_current_information);
    }
    
    void BoxingSByte() {
      Assert::IsInstanceOf<SByte>(Box(sbyte(42)), sw_current_information);
    }
    
    void BoxingSingle() {
      Assert::IsInstanceOf<Single>(Box(float(42)), sw_current_information);
    }
    
    void BoxingString() {
      Assert::IsInstanceOf<string>(Box(string("Forty two")), sw_current_information);
    }
    
    void BoxingUInt16() {
      Assert::IsInstanceOf<UInt16>(Box(uint16(42)), sw_current_information);
    }
    
    void BoxingUInt32() {
      Assert::IsInstanceOf<UInt32>(Box(uint32(42)), sw_current_information);
    }
    
    void BoxingUInt64() {
      Assert::IsInstanceOf<UInt64>(Box(uint64(42)), sw_current_information);
    }
    
    void BoxingVoidPointer() {
      Assert::IsInstanceOf<IntPtr>(Box((void*)42), sw_current_information);
    }
    
    void BoxingConstCharPointer() {
      Assert::IsInstanceOf<string>(Box("Forty two"), sw_current_information);
    }
    
    void BoxingConstWCharPointer() {
      Assert::IsInstanceOf<string>(Box(L"Forty two"), sw_current_information);
    }
    
    void BoxingConstChar16Pointer() {
      Assert::IsInstanceOf<string>(Box(u"Forty two"), sw_current_information);
    }
    
    void BoxingConstChar32Pointer() {
      Assert::IsInstanceOf<string>(Box(U"Forty two"), sw_current_information);
    }
    
    void BoxingTimeSpan() {
      Assert::IsInstanceOf<TimeSpan>(Box(12_h + 24_min + 32_s), sw_current_information);
    }
    
    void BoxingAny() {
      Assert::IsInstanceOf<Int32>(Box(Any(42)), sw_current_information);
    }
    
    void BoxingMyStruct() {
      struct MyStruct {};
      Assert::IsInstanceOf<MyStruct>(Box(MyStruct()), sw_current_information);
    }
  };
  
  sw_test(BoxTest, BoxingBoolean)
  sw_test(BoxTest, BoxingByte)
  sw_test(BoxTest, BoxingChar)
  sw_test(BoxTest, BoxingWChar)
  sw_test(BoxTest, BoxingChar16)
  sw_test(BoxTest, BoxingChar32)
  sw_test(BoxTest, BoxingDouble)
  sw_test(BoxTest, BoxingInt16)
  sw_test(BoxTest, BoxingInt32)
  sw_test(BoxTest, BoxingInt64)
  sw_test(BoxTest, BoxingSByte)
  sw_test(BoxTest, BoxingSingle)
  sw_test(BoxTest, BoxingString)
  sw_test(BoxTest, BoxingUInt16)
  sw_test(BoxTest, BoxingUInt32)
  sw_test(BoxTest, BoxingUInt64)
  sw_test(BoxTest, BoxingVoidPointer)
  sw_test(BoxTest, BoxingConstCharPointer)
  sw_test(BoxTest, BoxingConstWCharPointer)
  sw_test(BoxTest, BoxingConstChar16Pointer)
  sw_test(BoxTest, BoxingConstChar32Pointer)
  sw_test(BoxTest, BoxingAny)
  sw_test(BoxTest, BoxingMyStruct)
}
