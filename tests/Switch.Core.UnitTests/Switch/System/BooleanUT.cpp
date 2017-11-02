#include <Switch/System/Boolean.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class BooleanTest : public TestFixture {
  protected:
    void SetUp() override {}
    
    void TearDown() override {}
    
    void ConstructorDefault() {
      TUnit::Assert::IsFalse(Boolean(), _caller);
    }
    
    void ConstructorWithFalse() {
      TUnit::Assert::IsFalse(Boolean(false), _caller);
    }
    
    void ConstructorWithTrue() {
      TUnit::Assert::IsTrue(Boolean(true), _caller);
    }
    
    void ConstructorWith0() {
      TUnit::Assert::IsFalse(Boolean(0), _caller);
    }
    
    void ConstructorWith1() {
      TUnit::Assert::IsTrue(Boolean(1), _caller);
    }
    
    void ConstructorWithBooleanFalse() {
      TUnit::Assert::IsFalse(Boolean(Boolean::False), _caller);
    }
    
    void ConstructorWithBooleanTrue() {
      TUnit::Assert::IsTrue(Boolean(Boolean::True), _caller);
    }
    
    void ConstructorByCopyWithBooleanFalse() {
      TUnit::Assert::IsFalse(Boolean(Boolean(false)), _caller);
    }
    
    void ConstructorByCopyWithBooleanTrue() {
      TUnit::Assert::IsTrue(Boolean(Boolean(true)), _caller);
    }
    
    void ParseBooleanFalseString() {
      TUnit::Assert::IsFalse(Boolean::Parse(Boolean::FalseString()));
    }
    
    void ParseBooleanTrueString() {
      TUnit::Assert::IsTrue(Boolean::Parse(Boolean::TrueString()));
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
      TUnit::Assert::Throws<FormatException>(_delegate {Boolean::Parse("fal se");});
    }
    
    void ParseABadFormatTrueString() {
      TUnit::Assert::Throws<FormatException>(_delegate {Boolean::Parse("tru e");});
    }
    
    void ParseABadFormatString() {
      TUnit::Assert::Throws<FormatException>(_delegate {Boolean::Parse("Not true or false");});
    }
    
  };
  
  _add_test(BooleanTest, ConstructorDefault)
  _add_test(BooleanTest, ConstructorWithFalse)
  _add_test(BooleanTest, ConstructorWithTrue)
  _add_test(BooleanTest, ConstructorWith0)
  _add_test(BooleanTest, ConstructorWith1)
  _add_test(BooleanTest, ConstructorWithBooleanFalse)
  _add_test(BooleanTest, ConstructorWithBooleanTrue)
  _add_test(BooleanTest, ConstructorByCopyWithBooleanFalse)
  _add_test(BooleanTest, ConstructorByCopyWithBooleanTrue)
  _add_test(BooleanTest, ParseBooleanFalseString)
  _add_test(BooleanTest, ParseBooleanTrueString)
  _add_test(BooleanTest, ParseFalseString)
  _add_test(BooleanTest, ParseTrueString)
  _add_test(BooleanTest, ParseTrailedWithSpaceFalseString)
  _add_test(BooleanTest, ParseTrailedWithSpaceTrueString)
  _add_test(BooleanTest, ParsePrecededWithSpaceFalseString)
  _add_test(BooleanTest, ParsePrecededWithSpaceTrueString)
  _add_test(BooleanTest, ParseLowerCaseFalseString)
  _add_test(BooleanTest, ParseLowerCaseTrueString)
  _add_test(BooleanTest, ParseUpperCaseFalseString)
  _add_test(BooleanTest, ParseUpperCaseTrueString)
  _add_test(BooleanTest, ParseAnyCaseFalseString)
  _add_test(BooleanTest, ParseAnyCaseTrueString)
  _add_test(BooleanTest, ParseBadFormatFalseString)
  _add_test(BooleanTest, ParseABadFormatTrueString)
  _add_test(BooleanTest, ParseABadFormatString)
  
  TEST(Boolean, TryParse) {
    bool result;
    TUnit::Assert::IsTrue(Boolean::TryParse(Boolean::TrueString(), result));
    TUnit::Assert::IsTrue(result);
    
    TUnit::Assert::IsTrue(Boolean::TryParse(Boolean::FalseString(), result));
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
  
#if defined(_WIN32)
#pragma warning(push)
#pragma warning(disable:4305)
#endif

  TEST(Boolean, Equals) {
    TUnit::Assert::IsTrue(Boolean(true).Equals(Boolean(true)));
    TUnit::Assert::IsFalse(Boolean(true).Equals(Boolean(false)));
    TUnit::Assert::IsTrue(Boolean(false).Equals(Boolean(false)));
    TUnit::Assert::IsFalse(Boolean(false).Equals(Boolean(true)));
    
    TUnit::Assert::IsTrue(Boolean(false).Equals((const Object &)Boolean(false)));
    TUnit::Assert::IsFalse(Boolean(false).Equals((const Object &)Boolean(true)));
    TUnit::Assert::IsFalse(Boolean(false).Equals(int32(24)));    
  }

#if defined(_WIN32)
#pragma warning(pop)
#endif
  
  TEST(Boolean, GetHashCode) {
    TUnit::Assert::AreEqual(Boolean(true).GetHashCode(), int32(1));
    TUnit::Assert::AreEqual(Boolean(false).GetHashCode(), int32(0));
    
    Boolean bool1(true);
    object* obj = &bool1;
    TUnit::Assert::AreEqual(obj->GetHashCode(), int32(1));
    
    Boolean bool2(false);
    object* obj1 = &bool2;
    TUnit::Assert::AreEqual(obj1->GetHashCode(), int32(0));
  }
  
  TEST(Boolean, ToString) {
    TUnit::Assert::AreEqual("False", Boolean().ToString());
    TUnit::Assert::AreEqual("True", Boolean(true).ToString());
    TUnit::Assert::AreEqual("False", Boolean(false).ToString());
    TUnit::Assert::AreEqual("True", string(Boolean::TrueString()));
    TUnit::Assert::AreEqual("False", string(Boolean::FalseString()));
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
