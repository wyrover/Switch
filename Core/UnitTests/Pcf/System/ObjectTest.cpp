#include <Pcf/System/Object.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class ObjectTest : public TestFixture {
  protected:
    void SetUp() override {}
    void TearDown() override {}
    
    void EqualsWithAnotherObject() {
      TUnit::Assert::IsFalse(Object().Equals(Object()), pcf_current_information);
    }

    void EqualsWithSameObject() {
      Object object1;
      Object& object2 = object1;
      TUnit::Assert::IsTrue(object1.Equals(object2), pcf_current_information);
    }
    
    void EqualsWithNullObject() {
      TUnit::Assert::IsFalse(Object().Equals(ref<Object>::Null()), pcf_current_information);
    }
    
    void EqualsOnDifferentObjects() {
      TUnit::Assert::IsFalse(Object::Equals(Object(), Object()), pcf_current_information);
    }
    
    void EqualsOnSameObjects() {
      Object object1;
      TUnit::Assert::IsTrue(Object::Equals(object1, object1), pcf_current_information);
    }
    
    void EqualsDifferentStrings() {
      TUnit::Assert::IsFalse(Object::Equals(string("One"), string("Two")), pcf_current_information);
    }
    
    void EqualsSameStrings() {
      TUnit::Assert::IsTrue(Object::Equals(string("One"), string("One")), pcf_current_information);
    }
    
    void EqualityOperatorToAnotherObject() {
      TUnit::Assert::IsFalse(Object() == Object(), pcf_current_information);
    }
    
    void EqualityOperatorTheSameObject() {
      Object object1;
      Object& object2 = object1;
      TUnit::Assert::IsTrue(object1 == object2, pcf_current_information);
    }
    
    void EqualityOperatorDifferentStrings() {
      TUnit::Assert::IsFalse(string("One") == string("Two"), pcf_current_information);
    }
    
    void EqualityOperatorSameStrings() {
      TUnit::Assert::IsTrue(string("One") == string("One"), pcf_current_information);
    }
    
    void InequalityOperatorToAnotherObject() {
      TUnit::Assert::IsTrue(Object() != Object(), pcf_current_information);
    }
    
    void InequalityOperatorTheSameObject() {
      Object object1;
      Object& object2 = object1;
      TUnit::Assert::IsFalse(object1 != object2, pcf_current_information);
    }
    
    void InequalityOperatorDifferentStrings() {
      TUnit::Assert::IsTrue(string("One") != string("Two"), pcf_current_information);
    }
    
    void InequalityOperatorSameStrings() {
      TUnit::Assert::IsFalse(string("One") != string("One"), pcf_current_information);
    }
    
    void GetTypeOnObject() {
      TUnit::Assert::AreEqual("Pcf::System::Object", Object().GetType().FullName(), pcf_current_information);
    }
    
    void GetTypeOnString() {
      TUnit::Assert::AreEqual("Pcf::System::String", String().GetType().FullName(), pcf_current_information);
    }
    
    void MemberwiseCloneOnString() {
      refptr<string> str = pcf_new<string>("First");
      refptr<object> clonedStr = str->MemberwiseClone<string>();
      *str = "Second";
      TUnit::Assert::AreEqual("Second", str->ToString(), pcf_current_information);
      TUnit::Assert::AreEqual("First", clonedStr->ToString(), pcf_current_information);
    }
    
    void MemberwiseCloneOnStringAsString() {
      refptr<string> str = pcf_new<string>("First");
      refptr<string> clonedStr = str->MemberwiseClone<string>().As<string>();
      *str = "Second";
      TUnit::Assert::AreEqual("Second", *str, pcf_current_information);
      TUnit::Assert::AreEqual("First", *clonedStr, pcf_current_information);
    }
    
    void ReferenceEqualsOnDifferentObjects() {
      Object object1;
      Object& object2 = object1;
      TUnit::Assert::IsFalse(Object::ReferenceEquals(Object(), object2), pcf_current_information);
    }
    
    void ReferenceEqualsOnSameObjects() {
      Object object1;
      Object& object2 = object1;
      TUnit::Assert::IsTrue(Object::ReferenceEquals(object1, object2), pcf_current_information);
      
    }
    
    void ReferenceEqualsOnNullAndObject() {
      Object object1;
      TUnit::Assert::IsFalse(Object::ReferenceEquals(ref<object>::Null(), object1), pcf_current_information);
    }
    
    void ReferenceEqualsOnTwoDifferentObjects() {
      Object object1;
      Object object4;
      TUnit::Assert::IsFalse(Object::ReferenceEquals(object1, object4), pcf_current_information);
    }
    
    void ObjectToString() {
      TUnit::Assert::AreEqual("Pcf::System::Object", Object().ToString(), pcf_current_information);
    }
    
    void ObjectStringToString() {
      string str = "This is a string";
      Object& obj = str;
      TUnit::Assert::AreEqual("This is a string", obj.ToString(), pcf_current_information);
    }
    
    void ObjectInt32ToString() {
      Int32 i = 4659;
      Object& obj1 = i;
      TUnit::Assert::AreEqual("4659", obj1.ToString(), pcf_current_information);
    }
  };
  
  pcf_test(ObjectTest, EqualsWithAnotherObject)
  pcf_test(ObjectTest, EqualsWithSameObject)
  pcf_test(ObjectTest, EqualsWithNullObject)
  pcf_test(ObjectTest, EqualsOnDifferentObjects)
  pcf_test(ObjectTest, EqualsOnSameObjects)
  pcf_test(ObjectTest, EqualsDifferentStrings)
  pcf_test(ObjectTest, EqualsSameStrings)
  pcf_test(ObjectTest, EqualityOperatorToAnotherObject)
  pcf_test(ObjectTest, EqualityOperatorTheSameObject)
  pcf_test(ObjectTest, EqualityOperatorDifferentStrings)
  pcf_test(ObjectTest, EqualityOperatorSameStrings)
  pcf_test(ObjectTest, InequalityOperatorToAnotherObject)
  pcf_test(ObjectTest, InequalityOperatorTheSameObject)
  pcf_test(ObjectTest, InequalityOperatorDifferentStrings)
  pcf_test(ObjectTest, InequalityOperatorSameStrings)
  pcf_test(ObjectTest, GetTypeOnObject)
  pcf_test(ObjectTest, GetTypeOnString)
  pcf_test(ObjectTest, MemberwiseCloneOnString)
  pcf_test(ObjectTest, MemberwiseCloneOnStringAsString)
  pcf_test(ObjectTest, ReferenceEqualsOnDifferentObjects)
  pcf_test(ObjectTest, ReferenceEqualsOnSameObjects)
  pcf_test(ObjectTest, ReferenceEqualsOnNullAndObject)
  pcf_test(ObjectTest, ReferenceEqualsOnTwoDifferentObjects)
  pcf_test(ObjectTest, ObjectToString)
  pcf_test(ObjectTest, ObjectStringToString)
  pcf_test(ObjectTest, ObjectInt32ToString)
}
