#include <Switch/Property.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class PropertyReadOnlyTest : public TestFixture {
  protected:
    void ReadOnlyCanRead() {
      Assert::IsTrue(ReadOnly::CanRead, pcf_current_information);
    }
    
    void ReadOnlyCanWrite() {
      Assert::IsFalse(ReadOnly::CanWrite, pcf_current_information);
    }
    
    void PropertyCanRead() {
      Assert::IsTrue(Property<int32, ReadOnly>::CanRead, pcf_current_information);
    }
    
    void PropertyCanWrite() {
      Assert::IsFalse(Property<int32, ReadOnly>::CanWrite, pcf_current_information);
    }
    
    void CreatePropertyAndGetItWithImplicitCastOperator() {
      int32 v = 42;
      Property<int32, ReadOnly> Value {
        pcf_get {return v;}
      };
      
      Assert::AreEqual(42, v, pcf_current_information);
      Assert::AreEqual(42, Value, pcf_current_information);
    }
    
    void CreatePropertyAndGetItWithGetFunction() {
      int32 v = 42;
      Property<int32, ReadOnly> Value {
        pcf_get {return v;}
      };
      
      Assert::AreEqual(42, v, pcf_current_information);
      Assert::AreEqual(42, Value.Get(), pcf_current_information);
    }
    
    void CreatePropertyAndGetItWithFunctor() {
      int32 v = 42;
      Property<int32, ReadOnly> Value {
        pcf_get {return v;}
      };
      
      Assert::AreEqual(42, v, pcf_current_information);
      Assert::AreEqual(42, Value(), pcf_current_information);
    }
    
    void PropertyEqualityOperator() {
      int32 v = 42;
      Property<int32, ReadOnly> Value {
        pcf_get {return v;}
      };
      
      Assert::IsTrue(Value == 42, pcf_current_information);
      Assert::IsFalse(Value == 24, pcf_current_information);
    }
    
    void PropertyInequalityOperator() {
      int32 v = 42;
      Property<int32, ReadOnly> Value {
        pcf_get {return v;}
      };
      
      Assert::IsTrue(Value != 24, pcf_current_information);
      Assert::IsFalse(Value != 42, pcf_current_information);
    }
    
    class PropertyTestClass {
    public:
      PropertyTestClass() {}
      PropertyTestClass(const PropertyTestClass& property) : name(property.name) {}
      
      Property<string, ReadOnly> Name {
        pcf_get {return this->name;}
      };
      
    private:
      string name = "Test property";
    };
    
    void PropertyCopyConstructor() {
      refptr<PropertyTestClass> p1 = pcf_new<PropertyTestClass>();
      refptr<PropertyTestClass> p2 = pcf_new<PropertyTestClass>(*p1);
      p1 = null;
      Assert::AreEqual("Test property", p2->Name, pcf_current_information);
    }
    
    void PropertyEqualOperator() {
      refptr<PropertyTestClass> p1 = pcf_new<PropertyTestClass>();
      refptr<PropertyTestClass> p2 = pcf_new<PropertyTestClass>();
      *p2 = *p1;
      p1 = null;
      Assert::AreEqual("Test property", p2->Name, pcf_current_information);
    }
  };
  
  pcf_test(PropertyReadOnlyTest, ReadOnlyCanRead)
  pcf_test(PropertyReadOnlyTest, ReadOnlyCanWrite)
  pcf_test(PropertyReadOnlyTest, PropertyCanRead)
  pcf_test(PropertyReadOnlyTest, PropertyCanWrite)
  pcf_test(PropertyReadOnlyTest, CreatePropertyAndGetItWithImplicitCastOperator)
  pcf_test(PropertyReadOnlyTest, CreatePropertyAndGetItWithGetFunction)
  pcf_test(PropertyReadOnlyTest, CreatePropertyAndGetItWithFunctor)
  pcf_test(PropertyReadOnlyTest, PropertyEqualityOperator)
  pcf_test(PropertyReadOnlyTest, PropertyInequalityOperator)
  pcf_test(PropertyReadOnlyTest, PropertyCopyConstructor)
  pcf_test(PropertyReadOnlyTest, PropertyEqualOperator)
}
