#include <Switch/System/Boolean.hpp>
#include <Switch/System/FormatException.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(BooleanTest, ConstructorDefault) {
    ASSERT_FALSE(Boolean());
  }

  TEST(BooleanTest, ConstructorWithFalse) {
    ASSERT_FALSE(Boolean(false));
  }

  TEST(BooleanTest, ConstructorWithTrue) {
    ASSERT_TRUE(Boolean(true));
  }

  TEST(BooleanTest, ConstructorWith0) {
    ASSERT_FALSE(Boolean(0));
  }

  TEST(BooleanTest, ConstructorWith1) {
    ASSERT_TRUE(Boolean(1));
  }

  TEST(BooleanTest, ConstructorWithBooleanFalse) {
    ASSERT_FALSE(Boolean(Boolean::False));
  }

  TEST(BooleanTest, ConstructorWithBooleanTrue) {
    ASSERT_TRUE(Boolean(Boolean::True));
  }

  TEST(BooleanTest, ConstructorByCopyWithBooleanFalse) {
    ASSERT_FALSE(Boolean(Boolean(false)));
  }

  TEST(BooleanTest, ConstructorByCopyWithBooleanTrue) {
    ASSERT_TRUE(Boolean(Boolean(true)));
  }

  TEST(BooleanTest, ParseBooleanFalseString) {
    ASSERT_FALSE(Boolean::Parse(Boolean::FalseString));
  }

  TEST(BooleanTest, ParseBooleanTrueString) {
    ASSERT_TRUE(Boolean::Parse(Boolean::TrueString));
  }

  TEST(BooleanTest, ParseFalseString) {
    ASSERT_FALSE(Boolean::Parse("False"));
  }

  TEST(BooleanTest, ParseTrueString) {
    ASSERT_TRUE(Boolean::Parse("True"));
  }

  TEST(BooleanTest, ParseTrailedWithSpaceFalseString) {
    ASSERT_FALSE(Boolean::Parse("False     "));
  }

  TEST(BooleanTest, ParseTrailedWithSpaceTrueString) {
    ASSERT_TRUE(Boolean::Parse("True       "));
  }

  TEST(BooleanTest, ParsePrecededWithSpaceFalseString) {
    ASSERT_FALSE(Boolean::Parse("     False"));
  }

  TEST(BooleanTest, ParsePrecededWithSpaceTrueString) {
    ASSERT_TRUE(Boolean::Parse("       True"));
  }

  TEST(BooleanTest, ParseLowerCaseFalseString) {
    ASSERT_FALSE(Boolean::Parse("false"));
  }

  TEST(BooleanTest, ParseLowerCaseTrueString) {
    ASSERT_TRUE(Boolean::Parse("true"));
  }

  TEST(BooleanTest, ParseUpperCaseFalseString) {
    ASSERT_FALSE(Boolean::Parse("FALSE"));
  }

  TEST(BooleanTest, ParseUpperCaseTrueString) {
    ASSERT_TRUE(Boolean::Parse("TRUE"));
  }

  TEST(BooleanTest, ParseAnyCaseFalseString) {
    ASSERT_FALSE(Boolean::Parse("FaLsE"));
  }

  TEST(BooleanTest, ParseAnyCaseTrueString) {
    ASSERT_TRUE(Boolean::Parse("tRuE"));
  }

  TEST(BooleanTest, ParseBadFormatFalseString) {
    ASSERT_THROW(Boolean::Parse("fal se"), FormatException);
  }

  TEST(BooleanTest, ParseABadFormatTrueString) {
    ASSERT_THROW(Boolean::Parse("tru e"), FormatException);
  }

  TEST(BooleanTest, ParseABadFormatString) {
    ASSERT_THROW(Boolean::Parse("Not true or false"), FormatException);
  }

  TEST(BooleanTest, TryParse) {
    bool result;
    ASSERT_TRUE(Boolean::TryParse(Boolean::TrueString, result));
    ASSERT_TRUE(result);

    ASSERT_TRUE(Boolean::TryParse(Boolean::FalseString, result));
    ASSERT_FALSE(result);

    ASSERT_TRUE(Boolean::TryParse("True", result));
    ASSERT_TRUE(result);

    ASSERT_TRUE(Boolean::TryParse("False", result));
    ASSERT_FALSE(result);

    ASSERT_TRUE(Boolean::TryParse("true", result));
    ASSERT_TRUE(result);

    ASSERT_TRUE(Boolean::TryParse("false", result));
    ASSERT_FALSE(result);

    ASSERT_TRUE(Boolean::TryParse("TRUE", result));
    ASSERT_TRUE(result);

    ASSERT_TRUE(Boolean::TryParse("FALSE", result));
    ASSERT_FALSE(result);

    ASSERT_TRUE(Boolean::TryParse("true      ", result));
    ASSERT_TRUE(result);

    ASSERT_TRUE(Boolean::TryParse("    false", result));
    ASSERT_FALSE(result);

    ASSERT_FALSE(Boolean::TryParse("Not true or false", result));
  }

  #if defined(_WIN32)
#pragma warning(push)
#pragma warning(disable:4305)
  #endif

  TEST(BooleanTest, Equals) {
    ASSERT_TRUE(Boolean(true).Equals(Boolean(true)));
    ASSERT_FALSE(Boolean(true).Equals(Boolean(false)));
    ASSERT_TRUE(Boolean(false).Equals(Boolean(false)));
    ASSERT_FALSE(Boolean(false).Equals(Boolean(true)));

    ASSERT_TRUE(Boolean(false).Equals((const Object&)Boolean(false)));
    ASSERT_FALSE(Boolean(false).Equals((const Object&)Boolean(true)));
    ASSERT_FALSE(Boolean(false).Equals(int32(24)));
  }

  #if defined(_WIN32)
#pragma warning(pop)
  #endif

  TEST(BooleanTest, GetHashCode) {
    ASSERT_EQ(Boolean(true).GetHashCode(), int32(1));
    ASSERT_EQ(Boolean(false).GetHashCode(), int32(0));

    Boolean bool1(true);
    object* obj = &bool1;
    ASSERT_EQ(obj->GetHashCode(), int32(1));

    Boolean bool2(false);
    object* obj1 = &bool2;
    ASSERT_EQ(obj1->GetHashCode(), int32(0));
  }

  TEST(BooleanTest, ToString) {
    ASSERT_EQ("False", Boolean().ToString());
    ASSERT_EQ("True", Boolean(true).ToString());
    ASSERT_EQ("False", Boolean(false).ToString());
    ASSERT_EQ("True", string(Boolean::TrueString));
    ASSERT_EQ("False", string(Boolean::FalseString));
  }

  TEST(BooleanTest, CompareTo) {
    ASSERT_LE(Boolean(false).CompareTo(Boolean(true)), 0);
    ASSERT_GE(Boolean(true).CompareTo(Boolean(false)), 0);
    ASSERT_EQ(Boolean(false).CompareTo(Boolean(false)), 0);
    ASSERT_EQ(Boolean(true).CompareTo(Boolean(true)), 0);
    ASSERT_EQ(Boolean(false).CompareTo((const IComparable&)Boolean(false)), 0);
    ASSERT_EQ(Boolean(false).CompareTo(0), 0);
    ASSERT_GE(Boolean(true).CompareTo(0), 0);
  }

  TEST(BooleanTest, GetTypeCode) {
    ASSERT_EQ(TypeCode::Boolean, Boolean().GetTypeCode());
  }
}

