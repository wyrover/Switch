#include <Pcf/Boxing.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class BoxTest : public TestFixture {
  protected:
    void BoxingBoolean() {
      Assert::IsInstanceOf<Boolean>(Box(true), pcf_current_information);
    }
    
    void BoxingByte() {
      Assert::IsInstanceOf<Byte>(Box(byte(42)), pcf_current_information);
    }
    
    void BoxingChar() {
      Assert::IsInstanceOf<Char>(Box(char('c')), pcf_current_information);
    }
    
    void BoxingWChar() {
      Assert::IsInstanceOf<Char>(Box(wchar('c')), pcf_current_information);
    }
    
    void BoxingChar16() {
      Assert::IsInstanceOf<Char>(Box(char16('c')), pcf_current_information);
    }
    
    void BoxingChar32() {
      Assert::IsInstanceOf<Char>(Box(char32('c')), pcf_current_information);
    }
    
    void BoxingDouble() {
      Assert::IsInstanceOf<Double>(Box(double(42)), pcf_current_information);
    }
    
    void BoxingInt16() {
      Assert::IsInstanceOf<Int16>(Box(int16(42)), pcf_current_information);
    }
    
    void BoxingInt32() {
      Assert::IsInstanceOf<Int32>(Box(int32(42)), pcf_current_information);
    }
    
    void BoxingInt64() {
      Assert::IsInstanceOf<Int64>(Box(int64(42)), pcf_current_information);
    }
    
    void BoxingSByte() {
      Assert::IsInstanceOf<SByte>(Box(sbyte(42)), pcf_current_information);
    }
    
    void BoxingSingle() {
      Assert::IsInstanceOf<Single>(Box(float(42)), pcf_current_information);
    }
    
    void BoxingString() {
      Assert::IsInstanceOf<string>(Box(string("Forty two")), pcf_current_information);
    }
    
    void BoxingUInt16() {
      Assert::IsInstanceOf<UInt16>(Box(uint16(42)), pcf_current_information);
    }
    
    void BoxingUInt32() {
      Assert::IsInstanceOf<UInt32>(Box(uint32(42)), pcf_current_information);
    }
    
    void BoxingUInt64() {
      Assert::IsInstanceOf<UInt64>(Box(uint64(42)), pcf_current_information);
    }
    
    void BoxingVoidPointer() {
      Assert::IsInstanceOf<IntPtr>(Box((void*)42), pcf_current_information);
    }
    
    void BoxingConstCharPointer() {
      Assert::IsInstanceOf<string>(Box("Forty two"), pcf_current_information);
    }
    
    void BoxingConstWCharPointer() {
      Assert::IsInstanceOf<string>(Box(L"Forty two"), pcf_current_information);
    }
    
    void BoxingConstChar16Pointer() {
      Assert::IsInstanceOf<string>(Box(u"Forty two"), pcf_current_information);
    }
    
    void BoxingConstChar32Pointer() {
      Assert::IsInstanceOf<string>(Box(U"Forty two"), pcf_current_information);
    }
    
    void BoxingTimeSpan() {
      Assert::IsInstanceOf<TimeSpan>(Box(12_h + 24_min + 32_s), pcf_current_information);
    }
    
    void BoxingAny() {
      Assert::IsInstanceOf<Int32>(Box(Any(42)), pcf_current_information);
    }
    
    void BoxingMyStruct() {
      struct MyStruct {};
      Assert::IsInstanceOf<MyStruct>(Box(MyStruct()), pcf_current_information);
    }
  };
  
  pcf_test(BoxTest, BoxingBoolean)
  pcf_test(BoxTest, BoxingByte)
  pcf_test(BoxTest, BoxingChar)
  pcf_test(BoxTest, BoxingWChar)
  pcf_test(BoxTest, BoxingChar16)
  pcf_test(BoxTest, BoxingChar32)
  pcf_test(BoxTest, BoxingDouble)
  pcf_test(BoxTest, BoxingInt16)
  pcf_test(BoxTest, BoxingInt32)
  pcf_test(BoxTest, BoxingInt64)
  pcf_test(BoxTest, BoxingSByte)
  pcf_test(BoxTest, BoxingSingle)
  pcf_test(BoxTest, BoxingString)
  pcf_test(BoxTest, BoxingUInt16)
  pcf_test(BoxTest, BoxingUInt32)
  pcf_test(BoxTest, BoxingUInt64)
  pcf_test(BoxTest, BoxingVoidPointer)
  pcf_test(BoxTest, BoxingConstCharPointer)
  pcf_test(BoxTest, BoxingConstWCharPointer)
  pcf_test(BoxTest, BoxingConstChar16Pointer)
  pcf_test(BoxTest, BoxingConstChar32Pointer)
  pcf_test(BoxTest, BoxingAny)
  pcf_test(BoxTest, BoxingMyStruct)
}
