#include <Pcf/System/Text/StringBuilder.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Text;
using namespace TUnit;

namespace PcfUnitTests {
  class StringBuilderTest : public TestFixture {
  protected:
    void DefaultConstructor() {
      StringBuilder sb;
      Assert::AreEqual(0, sb.Length(), pcf_current_information);
      Assert::GreaterOrEqual(sb.Capacity(), 16, pcf_current_information);
      Assert::AreEqual(Int32::MaxValue, sb.MaxCapacity(), pcf_current_information);
      Assert::AreEqual("", sb.ToString(), pcf_current_information);
    }
    
    void ConstructorWithCapacity() {
      StringBuilder sb(1000);
      Assert::AreEqual(0, sb.Length(), pcf_current_information);
      Assert::GreaterOrEqual(sb.Capacity(), 1000, pcf_current_information);
      Assert::AreEqual(Int32::MaxValue, sb.MaxCapacity(), pcf_current_information);
      Assert::AreEqual("", sb.ToString(), pcf_current_information);
    }
    
    void ConstructorWithCapacityLesserThanZero() {
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {StringBuilder sb(-1);}, pcf_current_information);
    }
    
    void ConstructorWithCapacityAndMaxCapacity() {
      StringBuilder sb(1000, 2000);
      Assert::AreEqual(0, sb.Length(), pcf_current_information);
      Assert::GreaterOrEqual(sb.Capacity(), 1000, pcf_current_information);
      Assert::AreEqual(2000, sb.MaxCapacity(), pcf_current_information);
      Assert::AreEqual("", sb.ToString(), pcf_current_information);
    }
    
    void ConstructorWithCapacityLesserThanZeroAndMaxCapacity() {
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {StringBuilder sb(1000, 500);}, pcf_current_information);
    }
    
    void ConstructorWithCapacityAndMaxCapacityLesserThanOne() {
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {StringBuilder sb(0, 0);}, pcf_current_information);
    }
    
    void ConstructorWithCapacityAndMaxCapacityLesserThanCapacity() {
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {StringBuilder sb(1000, 500);}, pcf_current_information);
    }
    
    void ConstructorString() {
      Assert::AreEqual("Hello StringBuilder", StringBuilder(String("Hello StringBuilder")).ToString(), pcf_current_information);
      Assert::AreEqual("Goodbye", StringBuilder("Goodbye").ToString(), pcf_current_information);
    }
    
    void ConstructorStringAndCapacity() {
      StringBuilder sb(String("Hello StringBuilder"), 255);
      Assert::AreEqual("Hello StringBuilder", sb.ToString(), pcf_current_information);
      Assert::GreaterOrEqual(sb.Capacity, 255, pcf_current_information);
    }
    
    void ConstructorWithStringStartIndexLengthAndCapacity() {
      StringBuilder sb("Hello there", 0, 4, 255);
      Assert::AreEqual("Hell", sb.ToString(), pcf_current_information);
      Assert::GreaterOrEqual(sb.Capacity(), 255, pcf_current_information);
    }
    
    void ConstructorWithStringStartIndexEqualZeroLengthEqualZeroAndCapacity() {
      StringBuilder sb("Hello there", 0, 0, 255);
      Assert::AreEqual("", sb.ToString(), pcf_current_information);
      Assert::GreaterOrEqual(sb.Capacity(), 255, pcf_current_information);
    }
    
    void ConstructorWithStringEmptyStartIndexEqualZeroLengthEqualZeroAndCapacity() {
      Assert::AreEqual("", StringBuilder("", 0, 0, 255).ToString(), pcf_current_information);
    }
    
    void ConstructorWithStringStartIndexEqualZeroLengthLesserThanZeroAndCapacity() {
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {StringBuilder sb("Hello", 0, -1, 255);}, pcf_current_information);
    }
    
    void ConstructorWithStringStartIndexLesserThanZeroLengthLEqualZeroAndCapacity() {
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {StringBuilder sb("Hello", -1, 0, 255);}, pcf_current_information);
    }
    
    void ConstructorWithStringStartIndexEqualZeroLengthAboveStringLengthAndCapacity() {
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {StringBuilder sb("Hello", 0, 6, 255);}, pcf_current_information);
    }
    
    void GetCapacity() {
      Assert::GreaterOrEqual(StringBuilder("").Capacity(), 16, pcf_current_information);
      Assert::GreaterOrEqual(StringBuilder("Hello").Capacity(), 16, pcf_current_information);
      Assert::GreaterOrEqual(StringBuilder(1000).Capacity(), 1000, pcf_current_information);
    }
    
    void SetCapacity() {
      StringBuilder sb;
      sb.Capacity = 200;
      Assert::AreEqual(0, sb.Length(), pcf_current_information);
      Assert::GreaterOrEqual(sb.Capacity(), 200, pcf_current_information);
      Assert::AreEqual(Int32::MaxValue, sb.MaxCapacity(), pcf_current_information);
    }
    
    void SetCapacityBetweenLengthAndMaxCapacity() {
      StringBuilder sb(100, 500);
      sb.Length = 100;
      sb.Capacity = 200;
      Assert::AreEqual(100, sb.Length(), pcf_current_information);
      Assert::GreaterOrEqual(sb.Capacity(), 200, pcf_current_information);
      Assert::AreEqual(500, sb.MaxCapacity(), pcf_current_information);
    }
    
    void SetCapacityLesserThanLength() {
      StringBuilder sb(100, 500);
      sb.Length = 100;
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {sb.Capacity = 99;}, pcf_current_information);
    }
    
    void SetCapacityAboveMaxCapacity() {
      StringBuilder sb(100, 500);
      sb.Length = 100;
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {sb.Capacity = 501;}, pcf_current_information);
    }
    
    void GetChar() {
      StringBuilder sb("Hello, world!");
      Assert::AreEqual(U'o', sb[4], pcf_current_information);
    }
    
    void GetChar32() {
#if !_WIN32
      StringBuilder sb(U"こんにちは世界!");
      Assert::AreEqual(U'\U0000306f', sb[4], pcf_current_information);
#endif
    }
    
    void SetChar() {
      StringBuilder sb("Hello, world!");
      sb[4] = 'O';
      Assert::AreEqual(U'O', sb[4], pcf_current_information);
    }
    
    void SetChar32() {
#if !_WIN32
      StringBuilder sb(U"こんにちは世界!");
      sb[4] = U'こ';
      Assert::AreEqual(U'こ', sb[4], pcf_current_information);
#endif
    }
    
    void GetCharsLesserThanZero() {
      StringBuilder sb("Hello");
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {sb[-1];}, pcf_current_information);
    }
    
    void SetCharsLesserThanZero() {
      StringBuilder sb("Hello");
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {sb[-1] = 'a';}, pcf_current_information);
    }
    
    void GetCharsAboveLength() {
      StringBuilder sb("Hello");
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {sb[5];}, pcf_current_information);
    }
    
    void SetCharsAboveLength() {
      StringBuilder sb("Hello");
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {sb[5] = 'a';}, pcf_current_information);
    }
    
    void GetLength() {
      Assert::AreEqual(0, StringBuilder("").Length(), pcf_current_information);
      Assert::AreEqual(1, StringBuilder("0").Length(), pcf_current_information);
      Assert::AreEqual(5, StringBuilder("Hello").Length(), pcf_current_information);
    }
    
    void SetLength() {
      StringBuilder sb;
      sb.Length = 5;
      Assert::AreEqual(5, sb.Length(), pcf_current_information);
      Assert::GreaterOrEqual(sb.Capacity(), 16, pcf_current_information);
      Assert::AreEqual(Int32::MaxValue, sb.MaxCapacity(), pcf_current_information);
      Assert::AreEqual("", sb.ToString(), pcf_current_information);
      Assert::AreEqual(U'\0', sb[0], pcf_current_information);
      Assert::AreEqual(U'\0', sb[1], pcf_current_information);
      Assert::AreEqual(U'\0', sb[2], pcf_current_information);
      Assert::AreEqual(U'\0', sb[3], pcf_current_information);
      Assert::AreEqual(U'\0', sb[4], pcf_current_information);
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {sb[5];}, pcf_current_information);
    }
    
    void SetLengthLesserThanZero() {
      StringBuilder sb;
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {sb.Length = -1;}, pcf_current_information);
    }
    
    void SetLengthAboveMaxCapacity() {
      StringBuilder sb(100, 200);
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {sb.Length = 201;}, pcf_current_information);
    }
    
    void SetLengthLesserThanLegnth() {
      StringBuilder sb("Hello, World!");
      sb.Length = 5;
      Assert::AreEqual(5, sb.Length(), pcf_current_information);
      Assert::AreEqual("Hello", sb.ToString(), pcf_current_information);
    }
    
    void SetLengthAboveCapacity() {
      StringBuilder sb(100);
      sb.Length = 105;
      Assert::GreaterOrEqual(sb.Capacity(), 105, pcf_current_information);
    }
    
    void MaxCapacity() {
      Assert::AreEqual(Int32::MaxValue, StringBuilder("").MaxCapacity(), pcf_current_information);
      Assert::AreEqual(1, StringBuilder("0").Length(), pcf_current_information);
      Assert::AreEqual(5, StringBuilder("Hello").Length(), pcf_current_information);
    }
    
    void AppendBoolean() {
      Assert::AreEqual("String Builder True", StringBuilder("String Builder ").Append(true).ToString(), pcf_current_information);
    }
    
    void AppendByte() {
      Assert::AreEqual(U"String Builder 255", StringBuilder("String Builder ").Append(Byte::MaxValue).ToString(), pcf_current_information);
    }
    
    void AppendChar() {
      Assert::AreEqual("String Builder Y", StringBuilder("String Builder ").Append('Y').ToString(), pcf_current_information);
    }
   
    void AppendChar32() {
#if !_WIN32
      Assert::AreEqual(U"String Builder こ", StringBuilder("String Builder ").Append(U'こ').ToString(), pcf_current_information);
#endif
    }
    
    void AppendCharPointer() {
      const char test[] {'a' , 'b', 'c', 'd'};
      Assert::AreEqual("String Builder abcd", StringBuilder("String Builder ").Append(test, 4).ToString(), pcf_current_information);
    }
    
    void AppendChar32Pointer() {
#if !_WIN32
      const char32 test[] {U'こ' , U'ん', U'に', U'ち'};
      Assert::AreEqual(U"String Builder こんにち", StringBuilder("String Builder ").Append(test, 4).ToString(), pcf_current_information);
#endif
    }
    
    void AppendChar32WithRepeatCount() {
      Assert::AreEqual("String Builder ******", StringBuilder("String Builder ").Append(U'*', 6).ToString(), pcf_current_information);
    }
    
    void AppendArrayChar32() {
      Assert::AreEqual("String Builder abcd", StringBuilder("String Builder ").Append(Array<char32> {'a' , 'b', 'c', 'd'}).ToString(), pcf_current_information);
    }
    
    void AppendArrayChar32WithIndexAndCount() {
      Assert::AreEqual("String Builder bc", StringBuilder("String Builder ").Append(Array<char32> {'a' , 'b', 'c', 'd'}, 1, 2).ToString(), pcf_current_information);
    }
    
    void AppendDecimal() {
      Assert::AreEqual("String Builder 12.3", StringBuilder("String Builder ").Append(decimal(12.3)).ToString(), pcf_current_information);
    }
    
    void AppendDouble() {
      Assert::AreEqual("String Builder 12.3", StringBuilder("String Builder ").Append(double(12.3)).ToString(), pcf_current_information);
    }
    
    void AppendInt16() {
      Assert::AreEqual("String Builder 32767", StringBuilder("String Builder ").Append(Int16::MaxValue).ToString(), pcf_current_information);
    }
    
    void AppendInt32() {
      Assert::AreEqual("String Builder 2147483647", StringBuilder("String Builder ").Append(Int32::MaxValue).ToString(), pcf_current_information);
    }
    
    void AppendInt64() {
      Assert::AreEqual("String Builder 9223372036854775807", StringBuilder("String Builder ").Append(Int64::MaxValue).ToString(), pcf_current_information);
    }
    
    void AppendObject() {
      class MyObject : public object {
      public:
        string ToString() const override {return "MyObject string";}
      };
      Assert::AreEqual("String Builder MyObject string", StringBuilder("String Builder ").Append(MyObject()).ToString(), pcf_current_information);
    }
    
    void AppendAnyClass() {
      class AnyClass {
      public:
        string ToString() const {return "AnyClass string";}
      };
      Assert::AreEqual(U"String Builder AnyClass string", StringBuilder("String Builder ").Append(AnyClass()).ToString(), pcf_current_information);
    }
    
    void AppendSByte() {
      Assert::AreEqual("String Builder 127", StringBuilder("String Builder ").Append(SByte::MaxValue).ToString(), pcf_current_information);
    }
    
    void AppendSingle() {
      Assert::AreEqual("String Builder 12.3", StringBuilder("String Builder ").Append(float(12.3)).ToString(), pcf_current_information);
    }
    
    void AppendString() {
      Assert::AreEqual("String Builder other", StringBuilder("String Builder ").Append(string("other")).ToString(), pcf_current_information);
    }
    
    void AppendStringToExceedMaxMaxValue() {
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {StringBuilder(10, 20).Append("This is a long string");}, pcf_current_information);
    }
    
    void AppendcString() {
      Assert::AreEqual("String Builder other", StringBuilder("String Builder ").Append("other").ToString(), pcf_current_information);
    }
    
    void AppendwString() {
      Assert::AreEqual("String Builder other", StringBuilder(L"String Builder ").Append("other").ToString(), pcf_current_information);
    }
    
    void AppenduString() {
      Assert::AreEqual("String Builder other", StringBuilder(u"String Builder ").Append("other").ToString(), pcf_current_information);
    }
    
    void AppendUString() {
      Assert::AreEqual("String Builder other", StringBuilder(U"String Builder ").Append("other").ToString(), pcf_current_information);
    }
    
    void AppendUInt16() {
      Assert::AreEqual("String Builder 65535", StringBuilder("String Builder ").Append(UInt16::MaxValue).ToString(), pcf_current_information);
    }
    
    void AppendUInt32() {
      Assert::AreEqual("String Builder 4294967295", StringBuilder("String Builder ").Append(UInt32::MaxValue).ToString(), pcf_current_information);
    }
    
    void AppendUInt64() {
      Assert::AreEqual("String Builder 18446744073709551615", StringBuilder("String Builder ").Append(UInt64::MaxValue).ToString(), pcf_current_information);
    }
    
    void AppendFormatT1() {
      Assert::AreEqual("String Builder 65535", StringBuilder("String Builder ").AppendFormat("{0}", UInt16::MaxValue).ToString(), pcf_current_information);
    }
    
    void AppendFormatT2() {
      Assert::AreEqual("String Builder 65535 4294967295", StringBuilder("String Builder ").AppendFormat("{0} {1}", UInt16::MaxValue, UInt32::MaxValue).ToString(), pcf_current_information);
    }
    
    void AppendFormatT3() {
      Assert::AreEqual("String Builder 65535 4294967295 12.3", StringBuilder("String Builder ").AppendFormat("{0} {1} {2}", UInt16::MaxValue, UInt32::MaxValue, 12.3).ToString(), pcf_current_information);
    }
    
    void AppendFormatT4() {
      Assert::AreEqual("String Builder 65535 4294967295 12.3 True", StringBuilder("String Builder ").AppendFormat("{0} {1} {2} {3}", UInt16::MaxValue, UInt32::MaxValue, 12.3, true).ToString(), pcf_current_information);
    }
    
    void AppendFormatT5() {
      Assert::AreEqual("String Builder 65535 4294967295 12.3 True Info", StringBuilder("String Builder ").AppendFormat("{0} {1} {2} {3} {4}", UInt16::MaxValue, UInt32::MaxValue, 12.3, true, "Info").ToString(), pcf_current_information);
    }
    
  };
  
  pcf_test(StringBuilderTest, DefaultConstructor)
  pcf_test(StringBuilderTest, ConstructorWithCapacity)
  pcf_test(StringBuilderTest, ConstructorWithCapacityLesserThanZero)
  pcf_test(StringBuilderTest, ConstructorWithCapacityAndMaxCapacity)
  pcf_test(StringBuilderTest, ConstructorWithCapacityLesserThanZeroAndMaxCapacity)
  pcf_test(StringBuilderTest, ConstructorWithCapacityAndMaxCapacityLesserThanOne)
  pcf_test(StringBuilderTest, ConstructorWithCapacityAndMaxCapacityLesserThanCapacity)
  pcf_test(StringBuilderTest, ConstructorString)
  pcf_test(StringBuilderTest, ConstructorStringAndCapacity)
  pcf_test(StringBuilderTest, ConstructorWithStringStartIndexLengthAndCapacity)
  pcf_test(StringBuilderTest, ConstructorWithStringStartIndexEqualZeroLengthEqualZeroAndCapacity)
  pcf_test(StringBuilderTest, ConstructorWithStringEmptyStartIndexEqualZeroLengthEqualZeroAndCapacity)
  pcf_test(StringBuilderTest, ConstructorWithStringStartIndexEqualZeroLengthLesserThanZeroAndCapacity)
  pcf_test(StringBuilderTest, ConstructorWithStringStartIndexLesserThanZeroLengthLEqualZeroAndCapacity)
  pcf_test(StringBuilderTest, ConstructorWithStringStartIndexEqualZeroLengthAboveStringLengthAndCapacity)
  pcf_test(StringBuilderTest, GetCapacity)
  pcf_test(StringBuilderTest, SetCapacity)
  pcf_test(StringBuilderTest, SetCapacityBetweenLengthAndMaxCapacity)
  pcf_test(StringBuilderTest, SetCapacityLesserThanLength)
  pcf_test(StringBuilderTest, SetCapacityAboveMaxCapacity)
  pcf_test(StringBuilderTest, GetChar)
  pcf_test(StringBuilderTest, GetChar32)
  pcf_test(StringBuilderTest, SetChar)
  pcf_test(StringBuilderTest, SetChar32)
  pcf_test(StringBuilderTest, GetCharsLesserThanZero)
  pcf_test(StringBuilderTest, SetCharsLesserThanZero)
  pcf_test(StringBuilderTest, GetCharsAboveLength)
  pcf_test(StringBuilderTest, SetCharsAboveLength)
  pcf_test(StringBuilderTest, GetLength)
  pcf_test(StringBuilderTest, SetLength)
  pcf_test(StringBuilderTest, SetLengthLesserThanZero)
  pcf_test(StringBuilderTest, SetLengthAboveMaxCapacity)
  pcf_test(StringBuilderTest, SetLengthLesserThanLegnth)
  pcf_test(StringBuilderTest, SetLengthAboveCapacity)
  pcf_test(StringBuilderTest, MaxCapacity)
  pcf_test(StringBuilderTest, AppendBoolean)
  pcf_test(StringBuilderTest, AppendByte)
  pcf_test(StringBuilderTest, AppendChar)
  pcf_test(StringBuilderTest, AppendChar32)
  pcf_test(StringBuilderTest, AppendCharPointer)
  pcf_test(StringBuilderTest, AppendChar32Pointer)
  pcf_test(StringBuilderTest, AppendChar32WithRepeatCount)
  pcf_test(StringBuilderTest, AppendArrayChar32)
  pcf_test(StringBuilderTest, AppendArrayChar32WithIndexAndCount)
  pcf_test(StringBuilderTest, AppendDecimal)
  pcf_test(StringBuilderTest, AppendDouble)
  pcf_test(StringBuilderTest, AppendInt16)
  pcf_test(StringBuilderTest, AppendInt32)
  pcf_test(StringBuilderTest, AppendInt64)
  pcf_test(StringBuilderTest, AppendObject)
  pcf_test(StringBuilderTest, AppendAnyClass)
  pcf_test(StringBuilderTest, AppendSByte)
  pcf_test(StringBuilderTest, AppendSingle)
  pcf_test(StringBuilderTest, AppendString)
  pcf_test(StringBuilderTest, AppendStringToExceedMaxMaxValue)
  pcf_test(StringBuilderTest, AppendcString)
  pcf_test(StringBuilderTest, AppendwString)
  pcf_test(StringBuilderTest, AppenduString)
  pcf_test(StringBuilderTest, AppendUString)
  pcf_test(StringBuilderTest, AppendUInt16)
  pcf_test(StringBuilderTest, AppendUInt32)
  pcf_test(StringBuilderTest, AppendUInt64)
  pcf_test(StringBuilderTest, AppendFormatT1)
  pcf_test(StringBuilderTest, AppendFormatT2)
  pcf_test(StringBuilderTest, AppendFormatT3)
  pcf_test(StringBuilderTest, AppendFormatT4)
  pcf_test(StringBuilderTest, AppendFormatT5)
  
}
