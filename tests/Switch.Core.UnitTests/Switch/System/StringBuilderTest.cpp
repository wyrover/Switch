#include <Switch/System/Text/StringBuilder.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Text;

namespace SwitchUnitTests {
  TEST (StringBuilderTest, DefaultConstructor) {
    StringBuilder sb;
    ASSERT_EQ(0, sb.Length());
    ASSERT_GE(sb.Capacity(), 16);
    ASSERT_EQ(Int32::MaxValue, sb.MaxCapacity());
    ASSERT_EQ("", sb.ToString());
  }
  
  TEST (StringBuilderTest, ConstructorWithCapacity) {
    StringBuilder sb(1000);
    ASSERT_EQ(0, sb.Length());
    ASSERT_GE(sb.Capacity(), 1000);
    ASSERT_EQ(Int32::MaxValue, sb.MaxCapacity());
    ASSERT_EQ("", sb.ToString());
  }
  
  TEST (StringBuilderTest, ConstructorWithCapacityLesserThanZero) {
    ASSERT_THROW(StringBuilder sb(-1), ArgumentOutOfRangeException);
  }
  
  TEST (StringBuilderTest, ConstructorWithCapacityAndMaxCapacity) {
    StringBuilder sb(1000, 2000);
    ASSERT_EQ(0, sb.Length());
    ASSERT_GE(sb.Capacity(), 1000);
    ASSERT_EQ(2000, sb.MaxCapacity());
    ASSERT_EQ("", sb.ToString());
  }
  
  TEST (StringBuilderTest, ConstructorWithCapacityLesserThanZeroAndMaxCapacity) {
    ASSERT_THROW(StringBuilder sb(1000, 500), ArgumentOutOfRangeException);
  }
  
  TEST (StringBuilderTest, ConstructorWithCapacityAndMaxCapacityLesserThanOne) {
    ASSERT_THROW(StringBuilder sb(0, 0), ArgumentOutOfRangeException);
  }
  
  TEST (StringBuilderTest, ConstructorWithCapacityAndMaxCapacityLesserThanCapacity) {
    ASSERT_THROW(StringBuilder sb(1000, 500), ArgumentOutOfRangeException);
  }
  
  TEST (StringBuilderTest, ConstructorString) {
    ASSERT_EQ("Hello StringBuilder", StringBuilder(String("Hello StringBuilder")).ToString());
    ASSERT_EQ("Goodbye", StringBuilder("Goodbye").ToString());
  }
  
  TEST (StringBuilderTest, ConstructorStringAndCapacity) {
    StringBuilder sb(String("Hello StringBuilder"), 255);
    ASSERT_EQ("Hello StringBuilder", sb.ToString());
    ASSERT_GE(sb.Capacity, 255);
  }
  
  TEST (StringBuilderTest, ConstructorWithStringStartIndexLengthAndCapacity) {
    StringBuilder sb("Hello there", 0, 4, 255);
    ASSERT_EQ("Hell", sb.ToString());
    ASSERT_GE(sb.Capacity(), 255);
  }
  
  TEST (StringBuilderTest, ConstructorWithStringStartIndexEqualZeroLengthEqualZeroAndCapacity) {
    StringBuilder sb("Hello there", 0, 0, 255);
    ASSERT_EQ("", sb.ToString());
    ASSERT_GE(sb.Capacity(), 255);
  }
  
  TEST (StringBuilderTest, ConstructorWithStringEmptyStartIndexEqualZeroLengthEqualZeroAndCapacity) {
    ASSERT_EQ("", StringBuilder("", 0, 0, 255).ToString());
  }
  
  TEST (StringBuilderTest, ConstructorWithStringStartIndexEqualZeroLengthLesserThanZeroAndCapacity) {
    ASSERT_THROW(StringBuilder sb("Hello", 0, -1, 255),ArgumentOutOfRangeException);
  }
  
  TEST (StringBuilderTest, ConstructorWithStringStartIndexLesserThanZeroLengthLEqualZeroAndCapacity) {
    ASSERT_THROW(StringBuilder sb("Hello", -1, 0, 255), ArgumentOutOfRangeException);
  }
  
  TEST (StringBuilderTest, ConstructorWithStringStartIndexEqualZeroLengthAboveStringLengthAndCapacity) {
    ASSERT_THROW(StringBuilder sb("Hello", 0, 6, 255), ArgumentOutOfRangeException);
  }
  
  TEST (StringBuilderTest, GetCapacity) {
    ASSERT_GE(StringBuilder("").Capacity(), 16);
    ASSERT_GE(StringBuilder("Hello").Capacity(), 16);
    ASSERT_GE(StringBuilder(1000).Capacity(), 1000);
  }
  
  TEST (StringBuilderTest, SetCapacity) {
    StringBuilder sb;
    sb.Capacity = 200;
    ASSERT_EQ(0, sb.Length());
    ASSERT_GE(sb.Capacity(), 200);
    ASSERT_EQ(Int32::MaxValue, sb.MaxCapacity());
  }
  
  TEST (StringBuilderTest, SetCapacityBetweenLengthAndMaxCapacity) {
    StringBuilder sb(100, 500);
    sb.Length = 100;
    sb.Capacity = 200;
    ASSERT_EQ(100, sb.Length());
    ASSERT_GE(sb.Capacity(), 200);
    ASSERT_EQ(500, sb.MaxCapacity());
  }
  
  TEST (StringBuilderTest, SetCapacityLesserThanLength) {
    StringBuilder sb(100, 500);
    sb.Length = 100;
    ASSERT_THROW(sb.Capacity = 99, ArgumentOutOfRangeException);
  }
  
  TEST (StringBuilderTest, SetCapacityAboveMaxCapacity) {
    StringBuilder sb(100, 500);
    sb.Length = 100;
    ASSERT_THROW(sb.Capacity = 501, ArgumentOutOfRangeException);
  }
  
  TEST (StringBuilderTest, GetChar) {
    StringBuilder sb("Hello, world!");
    ASSERT_EQ(U'o', sb[4]);
  }
  
  TEST (StringBuilderTest, GetChar32) {
#if !defined(_WIN32)
    StringBuilder sb(U"こんにちは世界!");
    ASSERT_EQ(U'\U0000306f', sb[4]);
#endif
  }
  
  TEST (StringBuilderTest, SetChar) {
    StringBuilder sb("Hello, world!");
    sb[4] = 'O';
    ASSERT_EQ(U'O', sb[4]);
  }
  
  TEST (StringBuilderTest, SetChar32) {
#if !defined(_WIN32)
    StringBuilder sb(U"こんにちは世界!");
    sb[4] = U'こ';
    ASSERT_EQ(U'こ', sb[4]);
#endif
  }
  
  TEST (StringBuilderTest, GetCharsLesserThanZero) {
    StringBuilder sb("Hello");
    ASSERT_THROW(sb[-1], ArgumentOutOfRangeException);
  }
  
  TEST (StringBuilderTest, SetCharsLesserThanZero) {
    StringBuilder sb("Hello");
    ASSERT_THROW(sb[-1] = 'a', ArgumentOutOfRangeException);
  }
  
  TEST (StringBuilderTest, GetCharsAboveLength) {
    StringBuilder sb("Hello");
    ASSERT_THROW(sb[5], ArgumentOutOfRangeException);
  }
  
  TEST (StringBuilderTest, SetCharsAboveLength) {
    StringBuilder sb("Hello");
    ASSERT_THROW(sb[5] = 'a', ArgumentOutOfRangeException);
  }
  
  TEST (StringBuilderTest, GetLength) {
    ASSERT_EQ(0, StringBuilder("").Length());
    ASSERT_EQ(1, StringBuilder("0").Length());
    ASSERT_EQ(5, StringBuilder("Hello").Length());
  }
  
  TEST (StringBuilderTest, SetLength) {
    StringBuilder sb;
    sb.Length = 5;
    ASSERT_EQ(5, sb.Length());
    ASSERT_GE(sb.Capacity(), 16);
    ASSERT_EQ(Int32::MaxValue, sb.MaxCapacity());
    ASSERT_EQ("", sb.ToString());
    ASSERT_EQ(U'\0', sb[0]);
    ASSERT_EQ(U'\0', sb[1]);
    ASSERT_EQ(U'\0', sb[2]);
    ASSERT_EQ(U'\0', sb[3]);
    ASSERT_EQ(U'\0', sb[4]);
    ASSERT_THROW(sb[5], ArgumentOutOfRangeException);
  }
  
  TEST (StringBuilderTest, SetLengthLesserThanZero) {
    StringBuilder sb;
    ASSERT_THROW(sb.Length = -1, ArgumentOutOfRangeException);
  }
  
  TEST (StringBuilderTest, SetLengthAboveMaxCapacity) {
    StringBuilder sb(100, 200);
    ASSERT_THROW(sb.Length = 201, ArgumentOutOfRangeException);
  }
  
  TEST (StringBuilderTest, SetLengthLesserThanLegnth) {
    StringBuilder sb("Hello, World!");
    sb.Length = 5;
    ASSERT_EQ(5, sb.Length());
    ASSERT_EQ("Hello", sb.ToString());
  }
  
  TEST (StringBuilderTest, SetLengthAboveCapacity) {
    StringBuilder sb(100);
    sb.Length = 105;
    ASSERT_GE(sb.Capacity(), 105);
  }
  
  TEST (StringBuilderTest, MaxCapacity) {
    ASSERT_EQ(Int32::MaxValue, StringBuilder("").MaxCapacity());
    ASSERT_EQ(1, StringBuilder("0").Length());
    ASSERT_EQ(5, StringBuilder("Hello").Length());
  }
  
  TEST (StringBuilderTest, AppendBoolean) {
    ASSERT_EQ("String Builder True", StringBuilder("String Builder ").Append(true).ToString());
  }
  
  TEST (StringBuilderTest, AppendByte) {
    ASSERT_EQ(U"String Builder 255", StringBuilder("String Builder ").Append(Byte::MaxValue).ToString());
  }
  
  TEST (StringBuilderTest, AppendChar) {
    ASSERT_EQ("String Builder Y", StringBuilder("String Builder ").Append('Y').ToString());
  }
  
  TEST (StringBuilderTest, AppendChar32) {
#if !defined(_WIN32)
    ASSERT_EQ(U"String Builder こ", StringBuilder("String Builder ").Append(U'こ').ToString());
#endif
  }
  
  TEST (StringBuilderTest, AppendCharPointer) {
    const char test[] {'a' , 'b', 'c', 'd'};
    ASSERT_EQ("String Builder abcd", StringBuilder("String Builder ").Append(test, 4).ToString());
  }
  
  TEST (StringBuilderTest, AppendChar32Pointer) {
#if !defined(_WIN32)
    const char32 test[] {U'こ' , U'ん', U'に', U'ち'};
    ASSERT_EQ(U"String Builder こんにち", StringBuilder("String Builder ").Append(test, 4).ToString());
#endif
  }
  
  TEST (StringBuilderTest, AppendChar32WithRepeatCount) {
    ASSERT_EQ("String Builder ******", StringBuilder("String Builder ").Append(U'*', 6).ToString());
  }
  
  TEST (StringBuilderTest, AppendArrayChar32) {
    ASSERT_EQ("String Builder abcd", StringBuilder("String Builder ").Append(Array<char32> {'a' , 'b', 'c', 'd'}).ToString());
  }
  
  TEST (StringBuilderTest, AppendArrayChar32WithIndexAndCount) {
    ASSERT_EQ("String Builder bc", StringBuilder("String Builder ").Append(Array<char32> {'a' , 'b', 'c', 'd'}, 1, 2).ToString());
  }
  
  TEST (StringBuilderTest, AppendDecimal) {
    ASSERT_EQ("String Builder 12.3", StringBuilder("String Builder ").Append(decimal(12.3)).ToString());
  }
  
  TEST (StringBuilderTest, AppendDouble) {
    ASSERT_EQ("String Builder 12.3", StringBuilder("String Builder ").Append(double(12.3)).ToString());
  }
  
  TEST (StringBuilderTest, AppendInt16) {
    ASSERT_EQ("String Builder 32767", StringBuilder("String Builder ").Append(Int16::MaxValue).ToString());
  }
  
  TEST (StringBuilderTest, AppendInt32) {
    ASSERT_EQ("String Builder 2147483647", StringBuilder("String Builder ").Append(Int32::MaxValue).ToString());
  }
  
  TEST (StringBuilderTest, AppendInt64) {
    ASSERT_EQ("String Builder 9223372036854775807", StringBuilder("String Builder ").Append(Int64::MaxValue).ToString());
  }
  
  TEST (StringBuilderTest, AppendObject) {
    class MyObject : public object {
    public:
      String ToString() const override {return "MyObject string";}
    };
    ASSERT_EQ("String Builder MyObject string", StringBuilder("String Builder ").Append(MyObject()).ToString());
  }
  
  TEST (StringBuilderTest, AppendAnyClass) {
    class AnyClass {
    public:
      String ToString() const {return "AnyClass string";}
    };
    ASSERT_EQ(U"String Builder AnyClass string", StringBuilder("String Builder ").Append(AnyClass()).ToString());
  }
  
  TEST (StringBuilderTest, AppendSByte) {
    ASSERT_EQ("String Builder 127", StringBuilder("String Builder ").Append(SByte::MaxValue).ToString());
  }
  
  TEST (StringBuilderTest, AppendSingle) {
    ASSERT_EQ("String Builder 12.3", StringBuilder("String Builder ").Append(float(12.3)).ToString());
  }
  
  TEST (StringBuilderTest, AppendString) {
    ASSERT_EQ("String Builder other", StringBuilder("String Builder ").Append(string("other")).ToString());
  }
  
  TEST (StringBuilderTest, AppendStringToExceedMaxMaxValue) {
    ASSERT_THROW(StringBuilder(10, 20).Append("This is a long string"), ArgumentOutOfRangeException);
  }
  
  TEST (StringBuilderTest, AppendcString) {
    ASSERT_EQ("String Builder other", StringBuilder("String Builder ").Append("other").ToString());
  }
  
  TEST (StringBuilderTest, AppendwString) {
    ASSERT_EQ("String Builder other", StringBuilder(L"String Builder ").Append("other").ToString());
  }
  
  TEST (StringBuilderTest, AppenduString) {
    ASSERT_EQ("String Builder other", StringBuilder(u"String Builder ").Append("other").ToString());
  }
  
  TEST (StringBuilderTest, AppendUString) {
    ASSERT_EQ("String Builder other", StringBuilder(U"String Builder ").Append("other").ToString());
  }
  
  TEST (StringBuilderTest, AppendUInt16) {
    ASSERT_EQ("String Builder 65535", StringBuilder("String Builder ").Append(UInt16::MaxValue).ToString());
  }
  
  TEST (StringBuilderTest, AppendUInt32) {
    ASSERT_EQ("String Builder 4294967295", StringBuilder("String Builder ").Append(UInt32::MaxValue).ToString());
  }
  
  TEST (StringBuilderTest, AppendUInt64) {
    ASSERT_EQ("String Builder 18446744073709551615", StringBuilder("String Builder ").Append(UInt64::MaxValue).ToString());
  }
  
  TEST (StringBuilderTest, AppendFormatT1) {
    ASSERT_EQ("String Builder 65535", StringBuilder("String Builder ").AppendFormat("{0}", UInt16::MaxValue).ToString());
  }
  
  TEST (StringBuilderTest, AppendFormatT2) {
    ASSERT_EQ("String Builder 65535 4294967295", StringBuilder("String Builder ").AppendFormat("{0} {1}", UInt16::MaxValue, UInt32::MaxValue).ToString());
  }
  
  TEST (StringBuilderTest, AppendFormatT3) {
    ASSERT_EQ("String Builder 65535 4294967295 12.3", StringBuilder("String Builder ").AppendFormat("{0} {1} {2}", UInt16::MaxValue, UInt32::MaxValue, 12.3).ToString());
  }
  
  TEST (StringBuilderTest, AppendFormatT4) {
    ASSERT_EQ("String Builder 65535 4294967295 12.3 True", StringBuilder("String Builder ").AppendFormat("{0} {1} {2} {3}", UInt16::MaxValue, UInt32::MaxValue, 12.3, true).ToString());
  }
  
  TEST (StringBuilderTest, AppendFormatT5) {
    ASSERT_EQ("String Builder 65535 4294967295 12.3 True Info", StringBuilder("String Builder ").AppendFormat("{0} {1} {2} {3} {4}", UInt16::MaxValue, UInt32::MaxValue, 12.3, true, "Info").ToString());
  }
}
