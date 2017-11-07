#include <Switch/Property.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(PropertyTest, CreateReadWritePropertyAndGetIt) {
    int32 v = 42;
    _property<int32> Value {
      _get {return v;},
      _set {v = value;}
    };
    
    ASSERT_EQ(42, v);
    ASSERT_EQ(42, Value);
    ASSERT_EQ(42, Value());
    ASSERT_EQ(42, Value.Get());
  }
  
  TEST(PropertyTest, CreateReadWritePropertyAndSetItAndGetIt) {
    int32 v = 42;
    _property<int32> Value {
      _get {return v;},
      _set {v = value;}
    };
    
    Value = 24;
    ASSERT_EQ(24, Value);
    ASSERT_EQ(24, v);
    
    Value(84);
    ASSERT_EQ(84, Value);
    ASSERT_EQ(84, v);
    
    Value.Set(48);
    ASSERT_EQ(48, Value);
    ASSERT_EQ(48, v);
  }
  
  TEST(PropertyTest, CreateReadOnlyPropertyAndGetIt) {
    int32 v = 42;
    _property<int32, _readonly> Value {
      _get {return v;}
    };
    
    ASSERT_EQ(42, v);
    ASSERT_EQ(42, Value);
    ASSERT_EQ(42, Value());
    ASSERT_EQ(42, Value.Get());
  }
  
  TEST(PropertyTest, CreateWriteOnlyPropertyAndSetIt) {
    int32 v = 42;
    _property<int32, _writeonly> Value {
      _set {v = value;}
    };
    
    ASSERT_EQ(42, v);
    
    Value = 24;
    ASSERT_EQ(24, v);
    
    Value(84);
    ASSERT_EQ(84, v);
    
    Value.Set(48);
    ASSERT_EQ(48, v);
  }
  
  class PropertyReadOnly {
  public:
    PropertyReadOnly() {}
    PropertyReadOnly(const PropertyReadOnly& propertyReadOnly) : name(propertyReadOnly.name) {}
    
    _property<string, _readonly> Name {
      _get {return this->name;}
    };
    
  private:
    string name = "Test property";
  };
  
  TEST(PropertyTest, PropertyReadOnlyAndCopyConstructor) {
    refptr<PropertyReadOnly> propertyReadOnly1 = ref_new<PropertyReadOnly>();
    refptr<PropertyReadOnly> propertyReadOnly2 = ref_new<PropertyReadOnly>(*propertyReadOnly1);
    propertyReadOnly1 = null;
    ASSERT_EQ("Test property", propertyReadOnly2->Name);
  }
  
  TEST(PropertyTest, PropertyReadOnlyAndEqualOperator) {
    refptr<PropertyReadOnly> propertyReadOnly1 = ref_new<PropertyReadOnly>();
    refptr<PropertyReadOnly> propertyReadOnly2 = ref_new<PropertyReadOnly>();
    *propertyReadOnly2 = *propertyReadOnly1;
    propertyReadOnly1 = null;
    ASSERT_EQ("Test property", propertyReadOnly2->Name);
  }
  
  class PropertyWriteOnly {
  public:
    PropertyWriteOnly() {}
    PropertyWriteOnly(const PropertyWriteOnly& propertyWriteOnly) : name(propertyWriteOnly.name) {}
    
    _property<string, _writeonly> Name {
      _set {this->name = value;}
    };
    
    string name = "Test property";
  };
  
  TEST(PropertyTest, PropertyWriteOnlyAndCopyConstructor) {
    refptr<PropertyWriteOnly> propertyWriteOnly1 = ref_new<PropertyWriteOnly>();
    refptr<PropertyWriteOnly> propertyWriteOnly2 = ref_new<PropertyWriteOnly>(*propertyWriteOnly1);
    propertyWriteOnly1 = null;
    propertyWriteOnly2->Name = "Other thing";
    ASSERT_EQ("Other thing", propertyWriteOnly2->name);
  }
  
  TEST(PropertyTest, PropertyWriteOnlyAndEqualOperator) {
    refptr<PropertyWriteOnly> propertyWriteOnly1 = ref_new<PropertyWriteOnly>();
    refptr<PropertyWriteOnly> propertyWriteOnly2 = ref_new<PropertyWriteOnly>();
    *propertyWriteOnly2 = *propertyWriteOnly1;
    propertyWriteOnly1 = null;
    propertyWriteOnly2->Name = "Other thing";
    ASSERT_EQ("Other thing", propertyWriteOnly2->name);
  }
  
  class PropertyReadWrite {
  public:
    PropertyReadWrite() {}
    PropertyReadWrite(const PropertyReadWrite& propertyReadWrite) : name(propertyReadWrite.name) {}

    _property<string> Name {
      _get {return this->name;},
      _set {this->name = value;}
    };
    
  private:
    string name = "Test property";
  };
  
  TEST(PropertyTest, PropertyReadWriteAndCopyConstructor) {
    refptr<PropertyReadWrite> propertyReadWrite1 = ref_new<PropertyReadWrite>();
    refptr<PropertyReadWrite> propertyReadWrite2 = ref_new<PropertyReadWrite>(*propertyReadWrite1);
    propertyReadWrite1 = null;
    ASSERT_EQ("Test property", propertyReadWrite2->Name);
    propertyReadWrite2->Name = "Other thing";
    ASSERT_EQ("Other thing", propertyReadWrite2->Name);
  }
  
  TEST(PropertyTest, PropertyReadWriteAndEqualOperator) {
    refptr<PropertyReadWrite> propertyReadWrite1 = ref_new<PropertyReadWrite>();
    refptr<PropertyReadWrite> propertyReadWrite2 = ref_new<PropertyReadWrite>();
    *propertyReadWrite2 = *propertyReadWrite1;
    propertyReadWrite1 = null;
    ASSERT_EQ("Test property", propertyReadWrite2->Name);
    propertyReadWrite2->Name = "Other thing";
    ASSERT_EQ("Other thing", propertyReadWrite2->Name);
  }
}
