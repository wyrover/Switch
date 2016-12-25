#include <Pcf/System/Boolean.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class BooleanTest : public TestFixture {
  protected:
    void SetUp() override {}
    
    void TearDown() override {}
    
    void ConstructorDefault() {
      TUnit::Assert::IsFalse(Boolean(), pcf_current_information);
    }
    
    void ConstructorWithFalse() {
      TUnit::Assert::IsFalse(Boolean(false), pcf_current_information);
    }
    
    void ConstructorWithTrue() {
      TUnit::Assert::IsTrue(Boolean(true), pcf_current_information);
    }
    
    void ConstructorWith0() {
      TUnit::Assert::IsFalse(Boolean(0), pcf_current_information);
    }
    
    void ConstructorWith1() {
      TUnit::Assert::IsTrue(Boolean(1), pcf_current_information);
    }
    
    void ConstructorWithBooleanFalse() {
      TUnit::Assert::IsFalse(Boolean(Boolean::False), pcf_current_information);
    }
    
    void ConstructorWithBooleanTrue() {
      TUnit::Assert::IsTrue(Boolean(Boolean::True), pcf_current_information);
    }
    
    void ConstructorByCopyWithBooleanFalse() {
      TUnit::Assert::IsFalse(Boolean(Boolean(false)), pcf_current_information);
    }
    
    void ConstructorByCopyWithBooleanTrue() {
      TUnit::Assert::IsTrue(Boolean(Boolean(true)), pcf_current_information);
    }
    
    void ParseBooleanFalseString() {
      TUnit::Assert::IsFalse(Boolean::Parse(Boolean::FalseString));
    }
    
    void ParseBooleanTrueString() {
      TUnit::Assert::IsTrue(Boolean::Parse(Boolean::TrueString));
    }
    
    void ParseFalseString() {
      TUnit::Assert::IsFalse(Boolean::Parse("False"));
    }
    
    void ParseTrueString() {
      TUnit::Assert::IsTrue(Boolean::Parse("True"));
    }
    
    void ParseTrailedWithSpaceFalseString() {
      TUnit::Assert::IsFalse(Boolean::Parse("False     "));
    }
    
    void ParseTrailedWithSpaceTrueString() {
      TUnit::Assert::IsTrue(Boolean::Parse("True       "));
    }
    
    void ParsePrecededWithSpaceFalseString() {
      TUnit::Assert::IsFalse(Boolean::Parse("     False"));
    }
    
    void ParsePrecededWithSpaceTrueString() {
      TUnit::Assert::IsTrue(Boolean::Parse("       True"));
    }
    
    void ParseLowerCaseFalseString() {
      TUnit::Assert::IsFalse(Boolean::Parse("false"));
    }
    
    void ParseLowerCaseTrueString() {
      TUnit::Assert::IsTrue(Boolean::Parse("true"));
    }
    
    void ParseUpperCaseFalseString() {
      TUnit::Assert::IsFalse(Boolean::Parse("FALSE"));
    }
    
    void ParseUpperCaseTrueString() {
      TUnit::Assert::IsTrue(Boolean::Parse("TRUE"));
    }
    
    void ParseAnyCaseFalseString() {
      TUnit::Assert::IsFalse(Boolean::Parse("FaLsE"));
    }
    
    void ParseAnyCaseTrueString() {
      TUnit::Assert::IsTrue(Boolean::Parse("tRuE"));
    }
    
    void ParseBadFormatFalseString() {
      TUnit::Assert::Throws<FormatException>(pcf_delegate {Boolean::Parse("fal se");});
    }
    
    void ParseABadFormatTrueString() {
      TUnit::Assert::Throws<FormatException>(pcf_delegate {Boolean::Parse("tru e");});
    }
    
    void ParseABadFormatString() {
      TUnit::Assert::Throws<FormatException>(pcf_delegate {Boolean::Parse("Not true or false");});
    }
    
  };
  
  pcf_test(BooleanTest, ConstructorDefault);
  pcf_test(BooleanTest, ConstructorWithFalse);
  pcf_test(BooleanTest, ConstructorWithTrue);
  pcf_test(BooleanTest, ConstructorWith0);
  pcf_test(BooleanTest, ConstructorWith1);
  pcf_test(BooleanTest, ConstructorWithBooleanFalse);
  pcf_test(BooleanTest, ConstructorWithBooleanTrue);
  pcf_test(BooleanTest, ConstructorByCopyWithBooleanFalse);
  pcf_test(BooleanTest, ConstructorByCopyWithBooleanTrue);
  pcf_test(BooleanTest, ParseBooleanFalseString);
  pcf_test(BooleanTest, ParseBooleanTrueString);
  pcf_test(BooleanTest, ParseFalseString);
  pcf_test(BooleanTest, ParseTrueString);
  pcf_test(BooleanTest, ParseTrailedWithSpaceFalseString);
  pcf_test(BooleanTest, ParseTrailedWithSpaceTrueString);
  pcf_test(BooleanTest, ParsePrecededWithSpaceFalseString);
  pcf_test(BooleanTest, ParsePrecededWithSpaceTrueString);
  pcf_test(BooleanTest, ParseLowerCaseFalseString);
  pcf_test(BooleanTest, ParseLowerCaseTrueString);
  pcf_test(BooleanTest, ParseUpperCaseFalseString);
  pcf_test(BooleanTest, ParseUpperCaseTrueString);
  pcf_test(BooleanTest, ParseAnyCaseFalseString);
  pcf_test(BooleanTest, ParseAnyCaseTrueString);
  pcf_test(BooleanTest, ParseBadFormatFalseString);
  pcf_test(BooleanTest, ParseABadFormatTrueString);
  pcf_test(BooleanTest, ParseABadFormatString);
  
  TEST(Boolean, TryParse) {
    bool result;
    TUnit::Assert::IsTrue(Boolean::TryParse(Boolean::TrueString, result));
    TUnit::Assert::IsTrue(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse(Boolean::FalseString, result));
    TUnit::Assert::IsFalse(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse("True", result));
    TUnit::Assert::IsTrue(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse("False", result));
    TUnit::Assert::IsFalse(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse("true", result));
    TUnit::Assert::IsTrue(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse("false", result));
    TUnit::Assert::IsFalse(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse("TRUE", result));
    TUnit::Assert::IsTrue(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse("FALSE", result));
    TUnit::Assert::IsFalse(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse("true      ", result));
    TUnit::Assert::IsTrue(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse("    false", result));
    TUnit::Assert::IsFalse(result);
    
    TUnit::Assert::IsFalse(Boolean::TryParse("Not true or false", result));    
  }
  
  TEST(Boolean, Equals) {
    TUnit::Assert::IsTrue(Boolean(true).Equals(Boolean(true)));
    TUnit::Assert::IsFalse(Boolean(true).Equals(Boolean(false)));
    TUnit::Assert::IsTrue(Boolean(false).Equals(Boolean(false)));
    TUnit::Assert::IsFalse(Boolean(false).Equals(Boolean(true)));
    
    TUnit::Assert::IsTrue(Boolean(false).Equals((const Object &)Boolean(false)));
    TUnit::Assert::IsFalse(Boolean(false).Equals((const Object &)Boolean(true)));
    TUnit::Assert::IsFalse(Boolean(false).Equals(int32(24)));    
  }
  
  TEST(Boolean, GetHashCode) {
    TUnit::Assert::AreEqual(Boolean(true).GetHashCode(), int32(1));
    TUnit::Assert::AreEqual(Boolean(false).GetHashCode(), int32(0));
    
    Boolean bool1(true);
    IHashable* obj = &bool1;
    TUnit::Assert::AreEqual(obj->GetHashCode(), int32(1));
    
    Boolean bool2(false);
    IHashable* obj1 = &bool2;
    TUnit::Assert::AreEqual(obj1->GetHashCode(), int32(0));
  }
  
  TEST(Boolean, ToString) {
    TUnit::Assert::AreEqual("False", Boolean().ToString());
    TUnit::Assert::AreEqual("True", Boolean(true).ToString());
    TUnit::Assert::AreEqual("False", Boolean(false).ToString());
    TUnit::Assert::AreEqual("True", string(Boolean::TrueString));
    TUnit::Assert::AreEqual("False", string(Boolean::FalseString));
  }
  
  TEST(Boolean, CompareTo) {
    TUnit::Assert::LessOrEqual(Boolean(false).CompareTo(Boolean(true)), 0);
    TUnit::Assert::GreaterOrEqual(Boolean(true).CompareTo(Boolean(false)), 0);
    TUnit::Assert::AreEqual(Boolean(false).CompareTo(Boolean(false)), 0);
    TUnit::Assert::AreEqual(Boolean(true).CompareTo(Boolean(true)), 0);
    TUnit::Assert::AreEqual(Boolean(false).CompareTo((const IComparable&)Boolean(false)), 0);
    TUnit::Assert::AreEqual(Boolean(false).CompareTo(0), 0);
    TUnit::Assert::GreaterOrEqual(Boolean(true).CompareTo(0),0);    
  }
  
  TEST(Boolean,GetTypeCode) {
    TUnit::Assert::AreEqual(TypeCode::Boolean, Boolean().GetTypeCode());
  }
  
}
