#include <Switch/System/Object.hpp>
#include <Switch/System/Int32.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
    TEST(ObjectTest, EqualsWithAnotherObject) {
      ASSERT_FALSE(Object().Equals(Object()));
    }

    TEST(ObjectTest, EqualsWithSameObject) {
      Object object1;
      Object& object2 = object1;
      ASSERT_TRUE(object1.Equals(object2));
    }
    
    TEST(ObjectTest, EqualsWithNullObject) {
      ASSERT_FALSE(Object().Equals(ref<Object>::Null()));
    }
    
    TEST(ObjectTest, EqualsOnDifferentObjects) {
      ASSERT_FALSE(Object::Equals(Object(), Object()));
    }
    
    TEST(ObjectTest, EqualsOnSameObjects) {
      Object object1;
      ASSERT_TRUE(Object::Equals(object1, object1));
    }
    
    TEST(ObjectTest, EqualsDifferentStrings) {
      ASSERT_FALSE(Object::Equals(string("One"), string("Two")));
    }
    
    TEST(ObjectTest, EqualsSameStrings) {
      ASSERT_TRUE(Object::Equals(string("One"), string("One")));
    }
    
    TEST(ObjectTest, EqualityOperatorToAnotherObject) {
      ASSERT_FALSE(Object() == Object());
    }
    
    TEST(ObjectTest, EqualityOperatorTheSameObject) {
      Object object1;
      Object& object2 = object1;
      ASSERT_TRUE(object1 == object2);
    }
    
    TEST(ObjectTest, EqualityOperatorDifferentStrings) {
      ASSERT_FALSE(string("One") == string("Two"));
    }
    
    TEST(ObjectTest, EqualityOperatorSameStrings) {
      ASSERT_TRUE(string("One") == string("One"));
    }
    
    TEST(ObjectTest, InequalityOperatorToAnotherObject) {
      ASSERT_TRUE(Object() != Object());
    }
    
    TEST(ObjectTest, InequalityOperatorTheSameObject) {
      Object object1;
      Object& object2 = object1;
      ASSERT_FALSE(object1 != object2);
    }
    
    TEST(ObjectTest, InequalityOperatorDifferentStrings) {
      ASSERT_TRUE(string("One") != string("Two"));
    }
    
    TEST(ObjectTest, InequalityOperatorSameStrings) {
      ASSERT_FALSE(string("One") != string("One"));
    }
    
    TEST(ObjectTest, GetTypeOnObject) {
      ASSERT_EQ("Switch::System::Object", Object().GetType().FullName());
    }
    
    TEST(ObjectTest, GetTypeOnString) {
      ASSERT_EQ("Switch::System::String", String().GetType().FullName());
    }
    
    TEST(ObjectTest, MemberwiseCloneOnString) {
      refptr<string> str = ref_new<string>("First");
      refptr<object> clonedStr = str->MemberwiseClone<string>();
      *str = "Second";
      ASSERT_EQ("Second", str->ToString());
      ASSERT_EQ("First", clonedStr->ToString());
    }
    
    TEST(ObjectTest, MemberwiseCloneOnStringAsString) {
      refptr<string> str = ref_new<string>("First");
      refptr<string> clonedStr = str->MemberwiseClone<string>().As<string>();
      *str = "Second";
      ASSERT_EQ("Second", *str);
      ASSERT_EQ("First", *clonedStr);
    }
    
    TEST(ObjectTest, ReferenceEqualsOnDifferentObjects) {
      Object object1;
      Object& object2 = object1;
      ASSERT_FALSE(Object::ReferenceEquals(Object(), object2));
    }
    
    TEST(ObjectTest, ReferenceEqualsOnSameObjects) {
      Object object1;
      Object& object2 = object1;
      ASSERT_TRUE(Object::ReferenceEquals(object1, object2));
      
    }
    
    TEST(ObjectTest, ReferenceEqualsOnNullAndObject) {
      Object object1;
      ASSERT_FALSE(Object::ReferenceEquals(ref<object>::Null(), object1));
    }
    
    TEST(ObjectTest, ReferenceEqualsOnTwoDifferentObjects) {
      Object object1;
      Object object4;
      ASSERT_FALSE(Object::ReferenceEquals(object1, object4));
    }
    
    TEST(ObjectTest, ObjectToString) {
      ASSERT_EQ("Switch::System::Object", Object().ToString());
    }
    
    TEST(ObjectTest, ObjectStringToString) {
      string str = "This is a string";
      Object& obj = str;
      ASSERT_EQ("This is a string", obj.ToString());
    }
    
    TEST(ObjectTest, ObjectInt32ToString) {
      Int32 i = 4659;
      Object& obj1 = i;
      ASSERT_EQ("4659", obj1.ToString());
    }
}
