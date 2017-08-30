#include <Switch/Property.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class PropertyReadOnlyTest : public TestFixture {
  protected:
    void ReadOnlyCanRead() {
      Assert::IsTrue(ReadOnly::CanRead, sw_current_information);
    }
    
    void ReadOnlyCanWrite() {
      Assert::IsFalse(ReadOnly::CanWrite, sw_current_information);
    }
    
    void PropertyCanRead() {
      Assert::IsTrue(Property<int32, ReadOnly>::CanRead, sw_current_information);
    }
    
    void PropertyCanWrite() {
      Assert::IsFalse(Property<int32, ReadOnly>::CanWrite, sw_current_information);
    }
    
    void CreatePropertyAndGetItWithImplicitCastOperator() {
      int32 v = 42;
      Property<int32, ReadOnly> Value {
        sw_get {return v;}
      };
      
      Assert::AreEqual(42, v, sw_current_information);
      Assert::AreEqual(42, Value, sw_current_information);
    }
    
    void CreatePropertyAndGetItWithGetFunction() {
      int32 v = 42;
      Property<int32, ReadOnly> Value {
        sw_get {return v;}
      };
      
      Assert::AreEqual(42, v, sw_current_information);
      Assert::AreEqual(42, Value.Get(), sw_current_information);
    }
    
    void CreatePropertyAndGetItWithFunctor() {
      int32 v = 42;
      Property<int32, ReadOnly> Value {
        sw_get {return v;}
      };
      
      Assert::AreEqual(42, v, sw_current_information);
      Assert::AreEqual(42, Value(), sw_current_information);
    }
    
    void PropertyEqualityOperator() {
      int32 v = 42;
      Property<int32, ReadOnly> Value {
        sw_get {return v;}
      };
      
      Assert::IsTrue(Value == 42, sw_current_information);
      Assert::IsFalse(Value == 24, sw_current_information);
    }
    
    void PropertyInequalityOperator() {
      int32 v = 42;
      Property<int32, ReadOnly> Value {
        sw_get {return v;}
      };
      
      Assert::IsTrue(Value != 24, sw_current_information);
      Assert::IsFalse(Value != 42, sw_current_information);
    }
    
    class PropertyTestClass {
    public:
      PropertyTestClass() {}
      PropertyTestClass(const PropertyTestClass& property) : name(property.name) {}
      
      Property<string, ReadOnly> Name {
        sw_get {return this->name;}
      };
      
    private:
      string name = "Test property";
    };
    
    void PropertyCopyConstructor() {
      refptr<PropertyTestClass> p1 = sw_new<PropertyTestClass>();
      refptr<PropertyTestClass> p2 = sw_new<PropertyTestClass>(*p1);
      p1 = null;
      Assert::AreEqual("Test property", p2->Name, sw_current_information);
    }
    
    void PropertyEqualOperator() {
      refptr<PropertyTestClass> p1 = sw_new<PropertyTestClass>();
      refptr<PropertyTestClass> p2 = sw_new<PropertyTestClass>();
      *p2 = *p1;
      p1 = null;
      Assert::AreEqual("Test property", p2->Name, sw_current_information);
    }
  };
  
  sw_test(PropertyReadOnlyTest, ReadOnlyCanRead)
  sw_test(PropertyReadOnlyTest, ReadOnlyCanWrite)
  sw_test(PropertyReadOnlyTest, PropertyCanRead)
  sw_test(PropertyReadOnlyTest, PropertyCanWrite)
  sw_test(PropertyReadOnlyTest, CreatePropertyAndGetItWithImplicitCastOperator)
  sw_test(PropertyReadOnlyTest, CreatePropertyAndGetItWithGetFunction)
  sw_test(PropertyReadOnlyTest, CreatePropertyAndGetItWithFunctor)
  sw_test(PropertyReadOnlyTest, PropertyEqualityOperator)
  sw_test(PropertyReadOnlyTest, PropertyInequalityOperator)
  sw_test(PropertyReadOnlyTest, PropertyCopyConstructor)
  sw_test(PropertyReadOnlyTest, PropertyEqualOperator)
}
