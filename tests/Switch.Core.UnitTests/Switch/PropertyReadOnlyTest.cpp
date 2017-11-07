#include <Switch/Property.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(PropertyReadOnlyTest, CreatePropertyAndGetItWithImplicitCastOperator) {
    int32 v = 42;
    _property<int32, _readonly> Value {
      _get {return v;}
    };
    
    ASSERT_EQ(42, v);
    ASSERT_EQ(42, Value);
  }
  
  TEST(PropertyReadOnlyTest, CreatePropertyAndGetItWithGetFunction) {
    int32 v = 42;
    _property<int32, _readonly> Value {
      _get {return v;}
    };
    
    ASSERT_EQ(42, v);
    ASSERT_EQ(42, Value.Get());
  }
  
  TEST(PropertyReadOnlyTest, CreatePropertyAndGetItWithFunctor) {
    int32 v = 42;
    _property<int32, _readonly> Value {
      _get {return v;}
    };
    
    ASSERT_EQ(42, v);
    ASSERT_EQ(42, Value());
  }
  
  TEST(PropertyReadOnlyTest, PropertyEqualityOperator) {
    int32 v = 42;
    _property<int32, _readonly> Value {
      _get {return v;}
    };
    
    ASSERT_TRUE(Value == 42);
    ASSERT_FALSE(Value == 24);
  }
  
  TEST(PropertyReadOnlyTest, PropertyInequalityOperator) {
    int32 v = 42;
    _property<int32, _readonly> Value {
      _get {return v;}
    };
    
    ASSERT_TRUE(Value != 24);
    ASSERT_FALSE(Value != 42);
  }
  
  class PropertyTestClass {
  public:
    PropertyTestClass() {}
    PropertyTestClass(const PropertyTestClass& property) : name(property.name) {}
    
    _property<string, _readonly> Name {
      _get {return this->name;}
    };
    
  private:
    string name = "Test property";
  };
  
  TEST(PropertyReadOnlyTest, PropertyCopyConstructor) {
    refptr<PropertyTestClass> p1 = ref_new<PropertyTestClass>();
    refptr<PropertyTestClass> p2 = ref_new<PropertyTestClass>(*p1);
    p1 = null;
    ASSERT_EQ("Test property", p2->Name);
  }
  
  TEST(PropertyReadOnlyTest, PropertyEqualOperator) {
    refptr<PropertyTestClass> p1 = ref_new<PropertyTestClass>();
    refptr<PropertyTestClass> p2 = ref_new<PropertyTestClass>();
    *p2 = *p1;
    p1 = null;
    ASSERT_EQ("Test property", p2->Name);
  }
}

