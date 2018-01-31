
#include <Switch/ToString.hpp>
#include <Switch/LiteralOperatorConverter.hpp>
#include <Switch/System/TimeSpan.hpp>
#include <Switch/System/Version.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(ToStringTest, ConstVoidPointerToString) {
    ASSERT_EQ("4224", ToString((const void*)4224));
  }

  TEST(ToStringTest, VoidPointerToString) {
    ASSERT_EQ("4224", ToString((void*)4224));
  }

  TEST(ToStringTest, Null) {
    ASSERT_EQ("(null)", ToString(null));
  }

  TEST(ToStringTest, BooleanFalse) {
    ASSERT_EQ("False", ToString(false));
  }

  TEST(ToStringTest, BooleanTrue) {
    ASSERT_EQ("True", ToString(true));
  }

  TEST(ToStringTest, Byte) {
    ASSERT_EQ("42", ToString((byte)42));
  }

  TEST(ToStringTest, Char) {
    ASSERT_EQ("S", ToString('S'));
  }

  TEST(ToStringTest, Char16) {
    ASSERT_EQ("S", ToString(u'S'));
  }

  TEST(ToStringTest, Char32) {
    ASSERT_EQ("S", ToString(U'S'));
  }

  TEST(ToStringTest, WChar) {
    ASSERT_EQ("S", ToString(L'S'));
  }

  TEST(ToStringTest, Int16) {
    ASSERT_EQ("42", ToString((int16)42));
  }

  TEST(ToStringTest, Int32) {
    ASSERT_EQ("42", ToString((int32)42));
  }

  TEST(ToStringTest, Int64) {
    ASSERT_EQ("42", ToString((int64)42));
  }

  TEST(ToStringTest, Intptr) {
    ASSERT_EQ("42", ToString((intptr)42));
  }

  TEST(ToStringTest, SByte) {
    ASSERT_EQ("42", ToString((sbyte)42));
  }

  TEST(ToStringTest, UInt16) {
    ASSERT_EQ("42", ToString((uint16)42));
  }

  TEST(ToStringTest, UInt32) {
    ASSERT_EQ("42", ToString((uint32)42));
  }

  TEST(ToStringTest, UInt64) {
    ASSERT_EQ("42", ToString((uint64)42));
  }

  TEST(ToStringTest, UIntptr) {
    ASSERT_EQ("42", ToString((uintptr)42));
  }

  TEST(ToStringTest, Single) {
    ASSERT_EQ("0.42", ToString(.42f));
  }

  TEST(ToStringTest, Double) {
    ASSERT_EQ("0.42", ToString(.42));
  }

  TEST(ToStringTest, ConstCharPointer) {
    ASSERT_EQ("A string", ToString("A string"));
  }

  TEST(ToStringTest, ConstChar16Pointer) {
    ASSERT_EQ("A string", ToString(u"A string"));
  }

  TEST(ToStringTest, ConstChar32Pointer) {
    ASSERT_EQ("A string", ToString(U"A string"));
  }

  TEST(ToStringTest, ConstWCharPointer) {
    ASSERT_EQ("A string", ToString(L"A string"));
  }

  TEST(ToStringTest, String) {
    ASSERT_EQ("A string", ToString("A string"_s));
  }

  TEST(ToStringTest, ObjectLikeVersion) {
    ASSERT_EQ("1.2.3", ToString(System::Version(1, 2, 3)));
  }

  TEST(ToStringTest, SharedPtr) {
    ASSERT_EQ("10:25:42", ToString(new_<TimeSpan>(10, 25, 42)));
  }

  TEST(ToStringTest, Any) {
    ASSERT_EQ("42", ToString(any(42)));
  }

  class UnknownObjectWithoutOverrideToString : public object {
  public:
    UnknownObjectWithoutOverrideToString() {}
    explicit UnknownObjectWithoutOverrideToString(int32 value) : value(value) {}
    UnknownObjectWithoutOverrideToString(const UnknownObjectWithoutOverrideToString& unknownObjectWithoutOverrideToString) : value(unknownObjectWithoutOverrideToString.value) {}
    UnknownObjectWithoutOverrideToString& operator=(const UnknownObjectWithoutOverrideToString& unknownObjectWithoutOverrideToString) {
      this->value = unknownObjectWithoutOverrideToString.value;
      return *this;
    }

    property_<int32, readonly_> Value {
      get_ {return this->value;}
    };

  private:
    int32 value = 0;
  };

  TEST(ToStringTest, UnknownObjectWithoutOverrideToString) {
    ASSERT_EQ("SwitchUnitTests::UnknownObjectWithoutOverrideToString", ToString(UnknownObjectWithoutOverrideToString(42)));
  }

  TEST(ToStringTest, UnknownObject) {
    class UnknownObject : public object {
    public:
      UnknownObject() {}
      explicit UnknownObject(int32 value) : value(value) {}
      UnknownObject(const UnknownObject& unknownObject) : value(unknownObject.value) {}
      UnknownObject& operator=(const UnknownObject& unknownObject) {
        this->value = unknownObject.value;
        return *this;
      }

      property_<int32, readonly_> Value {
        get_ {return this->value;}
      };

      string ToString() const override {return string::Format("[Value={0}]", this->Value);}

    private:
      int32 value = 0;
    };

    ASSERT_EQ("[Value=42]", ToString(UnknownObject(42)));
  }

  struct UnknownStruct {
    int a;
    float b;
  };

  string ToString(const UnknownStruct& unknownStruct) {
    return string::Format("[a={0}, b={1}]", unknownStruct.a, unknownStruct.b);
  }

  TEST(ToStringTest, UnknownStruct) {
    ASSERT_EQ("[a=42, b=0.24]", ToString(UnknownStruct {42, .24}));
  }

}
