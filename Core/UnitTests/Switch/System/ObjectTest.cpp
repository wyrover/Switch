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
      TUnit::Assert::IsFalse(Object().Equals(Object()), sw_current_information);
    }

    void EqualsWithSameObject() {
      Object object1;
      Object& object2 = object1;
      TUnit::Assert::IsTrue(object1.Equals(object2), sw_current_information);
    }
    
    void EqualsWithNullObject() {
      TUnit::Assert::IsFalse(Object().Equals(ref<Object>::Null()), sw_current_information);
    }
    
    void EqualsOnDifferentObjects() {
      TUnit::Assert::IsFalse(Object::Equals(Object(), Object()), sw_current_information);
    }
    
    void EqualsOnSameObjects() {
      Object object1;
      TUnit::Assert::IsTrue(Object::Equals(object1, object1), sw_current_information);
    }
    
    void EqualsDifferentStrings() {
      TUnit::Assert::IsFalse(Object::Equals(string("One"), string("Two")), sw_current_information);
    }
    
    void EqualsSameStrings() {
      TUnit::Assert::IsTrue(Object::Equals(string("One"), string("One")), sw_current_information);
    }
    
    void EqualityOperatorToAnotherObject() {
      TUnit::Assert::IsFalse(Object() == Object(), sw_current_information);
    }
    
    void EqualityOperatorTheSameObject() {
      Object object1;
      Object& object2 = object1;
      TUnit::Assert::IsTrue(object1 == object2, sw_current_information);
    }
    
    void EqualityOperatorDifferentStrings() {
      TUnit::Assert::IsFalse(string("One") == string("Two"), sw_current_information);
    }
    
    void EqualityOperatorSameStrings() {
      TUnit::Assert::IsTrue(string("One") == string("One"), sw_current_information);
    }
    
    void InequalityOperatorToAnotherObject() {
      TUnit::Assert::IsTrue(Object() != Object(), sw_current_information);
    }
    
    void InequalityOperatorTheSameObject() {
      Object object1;
      Object& object2 = object1;
      TUnit::Assert::IsFalse(object1 != object2, sw_current_information);
    }
    
    void InequalityOperatorDifferentStrings() {
      TUnit::Assert::IsTrue(string("One") != string("Two"), sw_current_information);
    }
    
    void InequalityOperatorSameStrings() {
      TUnit::Assert::IsFalse(string("One") != string("One"), sw_current_information);
    }
    
    void GetTypeOnObject() {
      TUnit::Assert::AreEqual("Switch::System::Object", Object().GetType().FullName(), sw_current_information);
    }
    
    void GetTypeOnString() {
      TUnit::Assert::AreEqual("Switch::System::String", String().GetType().FullName(), sw_current_information);
    }
    
    void MemberwiseCloneOnString() {
      refptr<string> str = sw_new<string>("First");
      refptr<object> clonedStr = str->MemberwiseClone<string>();
      *str = "Second";
      TUnit::Assert::AreEqual("Second", str->ToString(), sw_current_information);
      TUnit::Assert::AreEqual("First", clonedStr->ToString(), sw_current_information);
    }
    
    void MemberwiseCloneOnStringAsString() {
      refptr<string> str = sw_new<string>("First");
      refptr<string> clonedStr = str->MemberwiseClone<string>().As<string>();
      *str = "Second";
      TUnit::Assert::AreEqual("Second", *str, sw_current_information);
      TUnit::Assert::AreEqual("First", *clonedStr, sw_current_information);
    }
    
    void ReferenceEqualsOnDifferentObjects() {
      Object object1;
      Object& object2 = object1;
      TUnit::Assert::IsFalse(Object::ReferenceEquals(Object(), object2), sw_current_information);
    }
    
    void ReferenceEqualsOnSameObjects() {
      Object object1;
      Object& object2 = object1;
      TUnit::Assert::IsTrue(Object::ReferenceEquals(object1, object2), sw_current_information);
      
    }
    
    void ReferenceEqualsOnNullAndObject() {
      Object object1;
      TUnit::Assert::IsFalse(Object::ReferenceEquals(ref<object>::Null(), object1), sw_current_information);
    }
    
    void ReferenceEqualsOnTwoDifferentObjects() {
      Object object1;
      Object object4;
      TUnit::Assert::IsFalse(Object::ReferenceEquals(object1, object4), sw_current_information);
    }
    
    void ObjectToString() {
      TUnit::Assert::AreEqual("Switch::System::Object", Object().ToString(), sw_current_information);
    }
    
    void ObjectStringToString() {
      string str = "This is a string";
      Object& obj = str;
      TUnit::Assert::AreEqual("This is a string", obj.ToString(), sw_current_information);
    }
    
    void ObjectInt32ToString() {
      Int32 i = 4659;
      Object& obj1 = i;
      TUnit::Assert::AreEqual("4659", obj1.ToString(), sw_current_information);
    }
  };
  
  sw_test(ObjectTest, EqualsWithAnotherObject)
  sw_test(ObjectTest, EqualsWithSameObject)
  sw_test(ObjectTest, EqualsWithNullObject)
  sw_test(ObjectTest, EqualsOnDifferentObjects)
  sw_test(ObjectTest, EqualsOnSameObjects)
  sw_test(ObjectTest, EqualsDifferentStrings)
  sw_test(ObjectTest, EqualsSameStrings)
  sw_test(ObjectTest, EqualityOperatorToAnotherObject)
  sw_test(ObjectTest, EqualityOperatorTheSameObject)
  sw_test(ObjectTest, EqualityOperatorDifferentStrings)
  sw_test(ObjectTest, EqualityOperatorSameStrings)
  sw_test(ObjectTest, InequalityOperatorToAnotherObject)
  sw_test(ObjectTest, InequalityOperatorTheSameObject)
  sw_test(ObjectTest, InequalityOperatorDifferentStrings)
  sw_test(ObjectTest, InequalityOperatorSameStrings)
  sw_test(ObjectTest, GetTypeOnObject)
  sw_test(ObjectTest, GetTypeOnString)
  sw_test(ObjectTest, MemberwiseCloneOnString)
  sw_test(ObjectTest, MemberwiseCloneOnStringAsString)
  sw_test(ObjectTest, ReferenceEqualsOnDifferentObjects)
  sw_test(ObjectTest, ReferenceEqualsOnSameObjects)
  sw_test(ObjectTest, ReferenceEqualsOnNullAndObject)
  sw_test(ObjectTest, ReferenceEqualsOnTwoDifferentObjects)
  sw_test(ObjectTest, ObjectToString)
  sw_test(ObjectTest, ObjectStringToString)
  sw_test(ObjectTest, ObjectInt32ToString)
}
