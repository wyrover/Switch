#include <Switch/System/Object.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class ObjectTest : public TestFixture {
  protected:
    void SetUp() override {}
    void TearDown() override {}
    
    void EqualsWithAnotherObject() {
      TUnit::Assert::IsFalse(Object().Equals(Object()), _caller);
    }

    void EqualsWithSameObject() {
      Object object1;
      Object& object2 = object1;
      TUnit::Assert::IsTrue(object1.Equals(object2), _caller);
    }
    
    void EqualsWithNullObject() {
      TUnit::Assert::IsFalse(Object().Equals(ref<Object>::Null()), _caller);
    }
    
    void EqualsOnDifferentObjects() {
      TUnit::Assert::IsFalse(Object::Equals(Object(), Object()), _caller);
    }
    
    void EqualsOnSameObjects() {
      Object object1;
      TUnit::Assert::IsTrue(Object::Equals(object1, object1), _caller);
    }
    
    void EqualsDifferentStrings() {
      TUnit::Assert::IsFalse(Object::Equals(string("One"), string("Two")), _caller);
    }
    
    void EqualsSameStrings() {
      TUnit::Assert::IsTrue(Object::Equals(string("One"), string("One")), _caller);
    }
    
    void EqualityOperatorToAnotherObject() {
      TUnit::Assert::IsFalse(Object() == Object(), _caller);
    }
    
    void EqualityOperatorTheSameObject() {
      Object object1;
      Object& object2 = object1;
      TUnit::Assert::IsTrue(object1 == object2, _caller);
    }
    
    void EqualityOperatorDifferentStrings() {
      TUnit::Assert::IsFalse(string("One") == string("Two"), _caller);
    }
    
    void EqualityOperatorSameStrings() {
      TUnit::Assert::IsTrue(string("One") == string("One"), _caller);
    }
    
    void InequalityOperatorToAnotherObject() {
      TUnit::Assert::IsTrue(Object() != Object(), _caller);
    }
    
    void InequalityOperatorTheSameObject() {
      Object object1;
      Object& object2 = object1;
      TUnit::Assert::IsFalse(object1 != object2, _caller);
    }
    
    void InequalityOperatorDifferentStrings() {
      TUnit::Assert::IsTrue(string("One") != string("Two"), _caller);
    }
    
    void InequalityOperatorSameStrings() {
      TUnit::Assert::IsFalse(string("One") != string("One"), _caller);
    }
    
    void GetTypeOnObject() {
      TUnit::Assert::AreEqual("Switch::System::Object", Object().GetType().FullName(), _caller);
    }
    
    void GetTypeOnString() {
      TUnit::Assert::AreEqual("Switch::System::String", String().GetType().FullName(), _caller);
    }
    
    void MemberwiseCloneOnString() {
      refptr<string> str = ref_new<string>("First");
      refptr<object> clonedStr = str->MemberwiseClone<string>();
      *str = "Second";
      TUnit::Assert::AreEqual("Second", str->ToString(), _caller);
      TUnit::Assert::AreEqual("First", clonedStr->ToString(), _caller);
    }
    
    void MemberwiseCloneOnStringAsString() {
      refptr<string> str = ref_new<string>("First");
      refptr<string> clonedStr = str->MemberwiseClone<string>().As<string>();
      *str = "Second";
      TUnit::Assert::AreEqual("Second", *str, _caller);
      TUnit::Assert::AreEqual("First", *clonedStr, _caller);
    }
    
    void ReferenceEqualsOnDifferentObjects() {
      Object object1;
      Object& object2 = object1;
      TUnit::Assert::IsFalse(Object::ReferenceEquals(Object(), object2), _caller);
    }
    
    void ReferenceEqualsOnSameObjects() {
      Object object1;
      Object& object2 = object1;
      TUnit::Assert::IsTrue(Object::ReferenceEquals(object1, object2), _caller);
      
    }
    
    void ReferenceEqualsOnNullAndObject() {
      Object object1;
      TUnit::Assert::IsFalse(Object::ReferenceEquals(ref<object>::Null(), object1), _caller);
    }
    
    void ReferenceEqualsOnTwoDifferentObjects() {
      Object object1;
      Object object4;
      TUnit::Assert::IsFalse(Object::ReferenceEquals(object1, object4), _caller);
    }
    
    void ObjectToString() {
      TUnit::Assert::AreEqual("Switch::System::Object", Object().ToString(), _caller);
    }
    
    void ObjectStringToString() {
      string str = "This is a string";
      Object& obj = str;
      TUnit::Assert::AreEqual("This is a string", obj.ToString(), _caller);
    }
    
    void ObjectInt32ToString() {
      Int32 i = 4659;
      Object& obj1 = i;
      TUnit::Assert::AreEqual("4659", obj1.ToString(), _caller);
    }
  };
  
  _test(ObjectTest, EqualsWithAnotherObject)
  _test(ObjectTest, EqualsWithSameObject)
  _test(ObjectTest, EqualsWithNullObject)
  _test(ObjectTest, EqualsOnDifferentObjects)
  _test(ObjectTest, EqualsOnSameObjects)
  _test(ObjectTest, EqualsDifferentStrings)
  _test(ObjectTest, EqualsSameStrings)
  _test(ObjectTest, EqualityOperatorToAnotherObject)
  _test(ObjectTest, EqualityOperatorTheSameObject)
  _test(ObjectTest, EqualityOperatorDifferentStrings)
  _test(ObjectTest, EqualityOperatorSameStrings)
  _test(ObjectTest, InequalityOperatorToAnotherObject)
  _test(ObjectTest, InequalityOperatorTheSameObject)
  _test(ObjectTest, InequalityOperatorDifferentStrings)
  _test(ObjectTest, InequalityOperatorSameStrings)
  _test(ObjectTest, GetTypeOnObject)
  _test(ObjectTest, GetTypeOnString)
  _test(ObjectTest, MemberwiseCloneOnString)
  _test(ObjectTest, MemberwiseCloneOnStringAsString)
  _test(ObjectTest, ReferenceEqualsOnDifferentObjects)
  _test(ObjectTest, ReferenceEqualsOnSameObjects)
  _test(ObjectTest, ReferenceEqualsOnNullAndObject)
  _test(ObjectTest, ReferenceEqualsOnTwoDifferentObjects)
  _test(ObjectTest, ObjectToString)
  _test(ObjectTest, ObjectStringToString)
  _test(ObjectTest, ObjectInt32ToString)
}