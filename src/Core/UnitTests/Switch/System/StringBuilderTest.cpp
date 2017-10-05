#include <Switch/System/Text/StringBuilder.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Text;
using namespace TUnit;

namespace SwitchUnitTests {
  class StringBuilderTest : public TestFixture {
  protected:
    void DefaultConstructor() {
      StringBuilder sb;
      Assert::AreEqual(0, sb.Length(), _caller);
      Assert::GreaterOrEqual(sb.Capacity(), 16, _caller);
      Assert::AreEqual(Int32::MaxValue, sb.MaxCapacity(), _caller);
      Assert::AreEqual("", sb.ToString(), _caller);
    }
    
    void ConstructorWithCapacity() {
      StringBuilder sb(1000);
      Assert::AreEqual(0, sb.Length(), _caller);
      Assert::GreaterOrEqual(sb.Capacity(), 1000, _caller);
      Assert::AreEqual(Int32::MaxValue, sb.MaxCapacity(), _caller);
      Assert::AreEqual("", sb.ToString(), _caller);
    }
    
    void ConstructorWithCapacityLesserThanZero() {
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {StringBuilder sb(-1);}, _caller);
    }
    
    void ConstructorWithCapacityAndMaxCapacity() {
      StringBuilder sb(1000, 2000);
      Assert::AreEqual(0, sb.Length(), _caller);
      Assert::GreaterOrEqual(sb.Capacity(), 1000, _caller);
      Assert::AreEqual(2000, sb.MaxCapacity(), _caller);
      Assert::AreEqual("", sb.ToString(), _caller);
    }
    
    void ConstructorWithCapacityLesserThanZeroAndMaxCapacity() {
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {StringBuilder sb(1000, 500);}, _caller);
    }
    
    void ConstructorWithCapacityAndMaxCapacityLesserThanOne() {
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {StringBuilder sb(0, 0);}, _caller);
    }
    
    void ConstructorWithCapacityAndMaxCapacityLesserThanCapacity() {
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {StringBuilder sb(1000, 500);}, _caller);
    }
    
    void ConstructorString() {
      Assert::AreEqual("Hello StringBuilder", StringBuilder(String("Hello StringBuilder")).ToString(), _caller);
      Assert::AreEqual("Goodbye", StringBuilder("Goodbye").ToString(), _caller);
    }
    
    void ConstructorStringAndCapacity() {
      StringBuilder sb(String("Hello StringBuilder"), 255);
      Assert::AreEqual("Hello StringBuilder", sb.ToString(), _caller);
      Assert::GreaterOrEqual(sb.Capacity, 255, _caller);
    }
    
    void ConstructorWithStringStartIndexLengthAndCapacity() {
      StringBuilder sb("Hello there", 0, 4, 255);
      Assert::AreEqual("Hell", sb.ToString(), _caller);
      Assert::GreaterOrEqual(sb.Capacity(), 255, _caller);
    }
    
    void ConstructorWithStringStartIndexEqualZeroLengthEqualZeroAndCapacity() {
      StringBuilder sb("Hello there", 0, 0, 255);
      Assert::AreEqual("", sb.ToString(), _caller);
      Assert::GreaterOrEqual(sb.Capacity(), 255, _caller);
    }
    
    void ConstructorWithStringEmptyStartIndexEqualZeroLengthEqualZeroAndCapacity() {
      Assert::AreEqual("", StringBuilder("", 0, 0, 255).ToString(), _caller);
    }
    
    void ConstructorWithStringStartIndexEqualZeroLengthLesserThanZeroAndCapacity() {
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {StringBuilder sb("Hello", 0, -1, 255);}, _caller);
    }
    
    void ConstructorWithStringStartIndexLesserThanZeroLengthLEqualZeroAndCapacity() {
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {StringBuilder sb("Hello", -1, 0, 255);}, _caller);
    }
    
    void ConstructorWithStringStartIndexEqualZeroLengthAboveStringLengthAndCapacity() {
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {StringBuilder sb("Hello", 0, 6, 255);}, _caller);
    }
    
    void GetCapacity() {
      Assert::GreaterOrEqual(StringBuilder("").Capacity(), 16, _caller);
      Assert::GreaterOrEqual(StringBuilder("Hello").Capacity(), 16, _caller);
      Assert::GreaterOrEqual(StringBuilder(1000).Capacity(), 1000, _caller);
    }
    
    void SetCapacity() {
      StringBuilder sb;
      sb.Capacity = 200;
      Assert::AreEqual(0, sb.Length(), _caller);
      Assert::GreaterOrEqual(sb.Capacity(), 200, _caller);
      Assert::AreEqual(Int32::MaxValue, sb.MaxCapacity(), _caller);
    }
    
    void SetCapacityBetweenLengthAndMaxCapacity() {
      StringBuilder sb(100, 500);
      sb.Length = 100;
      sb.Capacity = 200;
      Assert::AreEqual(100, sb.Length(), _caller);
      Assert::GreaterOrEqual(sb.Capacity(), 200, _caller);
      Assert::AreEqual(500, sb.MaxCapacity(), _caller);
    }
    
    void SetCapacityLesserThanLength() {
      StringBuilder sb(100, 500);
      sb.Length = 100;
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {sb.Capacity = 99;}, _caller);
    }
    
    void SetCapacityAboveMaxCapacity() {
      StringBuilder sb(100, 500);
      sb.Length = 100;
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {sb.Capacity = 501;}, _caller);
    }
    
    void GetChar() {
      StringBuilder sb("Hello, world!");
      Assert::AreEqual(U'o', sb[4], _caller);
    }
    
    void GetChar32() {
#if !defined(_WIN32)
      StringBuilder sb(U"こんにちは世界!");
      Assert::AreEqual(U'\U0000306f', sb[4], _caller);
#endif
    }
    
    void SetChar() {
      StringBuilder sb("Hello, world!");
      sb[4] = 'O';
      Assert::AreEqual(U'O', sb[4], _caller);
    }
    
    void SetChar32() {
#if !defined(_WIN32)
      StringBuilder sb(U"こんにちは世界!");
      sb[4] = U'こ';
      Assert::AreEqual(U'こ', sb[4], _caller);
#endif
    }
    
    void GetCharsLesserThanZero() {
      StringBuilder sb("Hello");
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {sb[-1];}, _caller);
    }
    
    void SetCharsLesserThanZero() {
      StringBuilder sb("Hello");
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {sb[-1] = 'a';}, _caller);
    }
    
    void GetCharsAboveLength() {
      StringBuilder sb("Hello");
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {sb[5];}, _caller);
    }
    
    void SetCharsAboveLength() {
      StringBuilder sb("Hello");
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {sb[5] = 'a';}, _caller);
    }
    
    void GetLength() {
      Assert::AreEqual(0, StringBuilder("").Length(), _caller);
      Assert::AreEqual(1, StringBuilder("0").Length(), _caller);
      Assert::AreEqual(5, StringBuilder("Hello").Length(), _caller);
    }
    
    void SetLength() {
      StringBuilder sb;
      sb.Length = 5;
      Assert::AreEqual(5, sb.Length(), _caller);
      Assert::GreaterOrEqual(sb.Capacity(), 16, _caller);
      Assert::AreEqual(Int32::MaxValue, sb.MaxCapacity(), _caller);
      Assert::AreEqual("", sb.ToString(), _caller);
      Assert::AreEqual(U'\0', sb[0], _caller);
      Assert::AreEqual(U'\0', sb[1], _caller);
      Assert::AreEqual(U'\0', sb[2], _caller);
      Assert::AreEqual(U'\0', sb[3], _caller);
      Assert::AreEqual(U'\0', sb[4], _caller);
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {sb[5];}, _caller);
    }
    
    void SetLengthLesserThanZero() {
      StringBuilder sb;
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {sb.Length = -1;}, _caller);
    }
    
    void SetLengthAboveMaxCapacity() {
      StringBuilder sb(100, 200);
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {sb.Length = 201;}, _caller);
    }
    
    void SetLengthLesserThanLegnth() {
      StringBuilder sb("Hello, World!");
      sb.Length = 5;
      Assert::AreEqual(5, sb.Length(), _caller);
      Assert::AreEqual("Hello", sb.ToString(), _caller);
    }
    
    void SetLengthAboveCapacity() {
      StringBuilder sb(100);
      sb.Length = 105;
      Assert::GreaterOrEqual(sb.Capacity(), 105, _caller);
    }
    
    void MaxCapacity() {
      Assert::AreEqual(Int32::MaxValue, StringBuilder("").MaxCapacity(), _caller);
      Assert::AreEqual(1, StringBuilder("0").Length(), _caller);
      Assert::AreEqual(5, StringBuilder("Hello").Length(), _caller);
    }
    
    void AppendBoolean() {
      Assert::AreEqual("String Builder True", StringBuilder("String Builder ").Append(true).ToString(), _caller);
    }
    
    void AppendByte() {
      Assert::AreEqual(U"String Builder 255", StringBuilder("String Builder ").Append(Byte::MaxValue).ToString(), _caller);
    }
    
    void AppendChar() {
      Assert::AreEqual("String Builder Y", StringBuilder("String Builder ").Append('Y').ToString(), _caller);
    }
   
    void AppendChar32() {
#if !defined(_WIN32)
      Assert::AreEqual(U"String Builder こ", StringBuilder("String Builder ").Append(U'こ').ToString(), _caller);
#endif
    }
    
    void AppendCharPointer() {
      const char test[] {'a' , 'b', 'c', 'd'};
      Assert::AreEqual("String Builder abcd", StringBuilder("String Builder ").Append(test, 4).ToString(), _caller);
    }
    
    void AppendChar32Pointer() {
#if !defined(_WIN32)
      const char32 test[] {U'こ' , U'ん', U'に', U'ち'};
      Assert::AreEqual(U"String Builder こんにち", StringBuilder("String Builder ").Append(test, 4).ToString(), _caller);
#endif
    }
    
    void AppendChar32WithRepeatCount() {
      Assert::AreEqual("String Builder ******", StringBuilder("String Builder ").Append(U'*', 6).ToString(), _caller);
    }
    
    void AppendArrayChar32() {
      Assert::AreEqual("String Builder abcd", StringBuilder("String Builder ").Append(Array<char32> {'a' , 'b', 'c', 'd'}).ToString(), _caller);
    }
    
    void AppendArrayChar32WithIndexAndCount() {
      Assert::AreEqual("String Builder bc", StringBuilder("String Builder ").Append(Array<char32> {'a' , 'b', 'c', 'd'}, 1, 2).ToString(), _caller);
    }
    
    void AppendDecimal() {
      Assert::AreEqual("String Builder 12.3", StringBuilder("String Builder ").Append(decimal(12.3)).ToString(), _caller);
    }
    
    void AppendDouble() {
      Assert::AreEqual("String Builder 12.3", StringBuilder("String Builder ").Append(double(12.3)).ToString(), _caller);
    }
    
    void AppendInt16() {
      Assert::AreEqual("String Builder 32767", StringBuilder("String Builder ").Append(Int16::MaxValue).ToString(), _caller);
    }
    
    void AppendInt32() {
      Assert::AreEqual("String Builder 2147483647", StringBuilder("String Builder ").Append(Int32::MaxValue).ToString(), _caller);
    }
    
    void AppendInt64() {
      Assert::AreEqual("String Builder 9223372036854775807", StringBuilder("String Builder ").Append(Int64::MaxValue).ToString(), _caller);
    }
    
    void AppendObject() {
      class MyObject : public object {
      public:
        String ToString() const override {return "MyObject string";}
      };
      Assert::AreEqual("String Builder MyObject string", StringBuilder("String Builder ").Append(MyObject()).ToString(), _caller);
    }
    
    void AppendAnyClass() {
      class AnyClass {
      public:
        String ToString() const {return "AnyClass string";}
      };
      Assert::AreEqual(U"String Builder AnyClass string", StringBuilder("String Builder ").Append(AnyClass()).ToString(), _caller);
    }
    
    void AppendSByte() {
      Assert::AreEqual("String Builder 127", StringBuilder("String Builder ").Append(SByte::MaxValue).ToString(), _caller);
    }
    
    void AppendSingle() {
      Assert::AreEqual("String Builder 12.3", StringBuilder("String Builder ").Append(float(12.3)).ToString(), _caller);
    }
    
    void AppendString() {
      Assert::AreEqual("String Builder other", StringBuilder("String Builder ").Append(string("other")).ToString(), _caller);
    }
    
    void AppendStringToExceedMaxMaxValue() {
      Assert::Throws<ArgumentOutOfRangeException>(_delegate {StringBuilder(10, 20).Append("This is a long string");}, _caller);
    }
    
    void AppendcString() {
      Assert::AreEqual("String Builder other", StringBuilder("String Builder ").Append("other").ToString(), _caller);
    }
    
    void AppendwString() {
      Assert::AreEqual("String Builder other", StringBuilder(L"String Builder ").Append("other").ToString(), _caller);
    }
    
    void AppenduString() {
      Assert::AreEqual("String Builder other", StringBuilder(u"String Builder ").Append("other").ToString(), _caller);
    }
    
    void AppendUString() {
      Assert::AreEqual("String Builder other", StringBuilder(U"String Builder ").Append("other").ToString(), _caller);
    }
    
    void AppendUInt16() {
      Assert::AreEqual("String Builder 65535", StringBuilder("String Builder ").Append(UInt16::MaxValue).ToString(), _caller);
    }
    
    void AppendUInt32() {
      Assert::AreEqual("String Builder 4294967295", StringBuilder("String Builder ").Append(UInt32::MaxValue).ToString(), _caller);
    }
    
    void AppendUInt64() {
      Assert::AreEqual("String Builder 18446744073709551615", StringBuilder("String Builder ").Append(UInt64::MaxValue).ToString(), _caller);
    }
    
    void AppendFormatT1() {
      Assert::AreEqual("String Builder 65535", StringBuilder("String Builder ").AppendFormat("{0}", UInt16::MaxValue).ToString(), _caller);
    }
    
    void AppendFormatT2() {
      Assert::AreEqual("String Builder 65535 4294967295", StringBuilder("String Builder ").AppendFormat("{0} {1}", UInt16::MaxValue, UInt32::MaxValue).ToString(), _caller);
    }
    
    void AppendFormatT3() {
      Assert::AreEqual("String Builder 65535 4294967295 12.3", StringBuilder("String Builder ").AppendFormat("{0} {1} {2}", UInt16::MaxValue, UInt32::MaxValue, 12.3).ToString(), _caller);
    }
    
    void AppendFormatT4() {
      Assert::AreEqual("String Builder 65535 4294967295 12.3 True", StringBuilder("String Builder ").AppendFormat("{0} {1} {2} {3}", UInt16::MaxValue, UInt32::MaxValue, 12.3, true).ToString(), _caller);
    }
    
    void AppendFormatT5() {
      Assert::AreEqual("String Builder 65535 4294967295 12.3 True Info", StringBuilder("String Builder ").AppendFormat("{0} {1} {2} {3} {4}", UInt16::MaxValue, UInt32::MaxValue, 12.3, true, "Info").ToString(), _caller);
    }
    
  };
  
  _test(StringBuilderTest, DefaultConstructor)
  _test(StringBuilderTest, ConstructorWithCapacity)
  _test(StringBuilderTest, ConstructorWithCapacityLesserThanZero)
  _test(StringBuilderTest, ConstructorWithCapacityAndMaxCapacity)
  _test(StringBuilderTest, ConstructorWithCapacityLesserThanZeroAndMaxCapacity)
  _test(StringBuilderTest, ConstructorWithCapacityAndMaxCapacityLesserThanOne)
  _test(StringBuilderTest, ConstructorWithCapacityAndMaxCapacityLesserThanCapacity)
  _test(StringBuilderTest, ConstructorString)
  _test(StringBuilderTest, ConstructorStringAndCapacity)
  _test(StringBuilderTest, ConstructorWithStringStartIndexLengthAndCapacity)
  _test(StringBuilderTest, ConstructorWithStringStartIndexEqualZeroLengthEqualZeroAndCapacity)
  _test(StringBuilderTest, ConstructorWithStringEmptyStartIndexEqualZeroLengthEqualZeroAndCapacity)
  _test(StringBuilderTest, ConstructorWithStringStartIndexEqualZeroLengthLesserThanZeroAndCapacity)
  _test(StringBuilderTest, ConstructorWithStringStartIndexLesserThanZeroLengthLEqualZeroAndCapacity)
  _test(StringBuilderTest, ConstructorWithStringStartIndexEqualZeroLengthAboveStringLengthAndCapacity)
  _test(StringBuilderTest, GetCapacity)
  _test(StringBuilderTest, SetCapacity)
  _test(StringBuilderTest, SetCapacityBetweenLengthAndMaxCapacity)
  _test(StringBuilderTest, SetCapacityLesserThanLength)
  _test(StringBuilderTest, SetCapacityAboveMaxCapacity)
  _test(StringBuilderTest, GetChar)
  _test(StringBuilderTest, GetChar32)
  _test(StringBuilderTest, SetChar)
  _test(StringBuilderTest, SetChar32)
  _test(StringBuilderTest, GetCharsLesserThanZero)
  _test(StringBuilderTest, SetCharsLesserThanZero)
  _test(StringBuilderTest, GetCharsAboveLength)
  _test(StringBuilderTest, SetCharsAboveLength)
  _test(StringBuilderTest, GetLength)
  _test(StringBuilderTest, SetLength)
  _test(StringBuilderTest, SetLengthLesserThanZero)
  _test(StringBuilderTest, SetLengthAboveMaxCapacity)
  _test(StringBuilderTest, SetLengthLesserThanLegnth)
  _test(StringBuilderTest, SetLengthAboveCapacity)
  _test(StringBuilderTest, MaxCapacity)
  _test(StringBuilderTest, AppendBoolean)
  _test(StringBuilderTest, AppendByte)
  _test(StringBuilderTest, AppendChar)
  _test(StringBuilderTest, AppendChar32)
  _test(StringBuilderTest, AppendCharPointer)
  _test(StringBuilderTest, AppendChar32Pointer)
  _test(StringBuilderTest, AppendChar32WithRepeatCount)
  _test(StringBuilderTest, AppendArrayChar32)
  _test(StringBuilderTest, AppendArrayChar32WithIndexAndCount)
  _test(StringBuilderTest, AppendDecimal)
  _test(StringBuilderTest, AppendDouble)
  _test(StringBuilderTest, AppendInt16)
  _test(StringBuilderTest, AppendInt32)
  _test(StringBuilderTest, AppendInt64)
  _test(StringBuilderTest, AppendObject)
  _test(StringBuilderTest, AppendAnyClass)
  _test(StringBuilderTest, AppendSByte)
  _test(StringBuilderTest, AppendSingle)
  _test(StringBuilderTest, AppendString)
  _test(StringBuilderTest, AppendStringToExceedMaxMaxValue)
  _test(StringBuilderTest, AppendcString)
  _test(StringBuilderTest, AppendwString)
  _test(StringBuilderTest, AppenduString)
  _test(StringBuilderTest, AppendUString)
  _test(StringBuilderTest, AppendUInt16)
  _test(StringBuilderTest, AppendUInt32)
  _test(StringBuilderTest, AppendUInt64)
  _test(StringBuilderTest, AppendFormatT1)
  _test(StringBuilderTest, AppendFormatT2)
  _test(StringBuilderTest, AppendFormatT3)
  _test(StringBuilderTest, AppendFormatT4)
  _test(StringBuilderTest, AppendFormatT5)
  
}
