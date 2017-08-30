#include <Switch/Property.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class PropertyWriteOnlyTest : public TestFixture {
  protected:
    void WriteOnlyCanRead() {
      Assert::IsFalse(WriteOnly::CanRead, sw_current_information);
    }
    
    void WriteOnlyCanWrite() {
      Assert::IsTrue(WriteOnly::CanWrite, sw_current_information);
    }

    void PropertyCanRead() {
      Assert::IsFalse(Property<int, WriteOnly>::CanRead, sw_current_information);
    }
    
    void PropertyCanWrite() {
      Assert::IsTrue(Property<int, WriteOnly>::CanWrite, sw_current_information);
    }
    
    void CreatePropertyAndSetItWithEqualOperator() {
      int32 v = 42;
      Property<int32, WriteOnly> Value {
        sw_set {v = value;}
      };

      Value = 24;
      Assert::AreEqual(24, v, sw_current_information);
    }
    
    void CreatePropertyAndSetItWithSetFunction() {
      int32 v = 42;
      Property<int32, WriteOnly> Value {
        sw_set {v = value;}
      };
      
      Value.Set(24);
      Assert::AreEqual(24, v, sw_current_information);
    }
    
    void CreatePropertyAndSetItWithFunctor() {
      int32 v = 42;
      Property<int32, WriteOnly> Value {
        sw_set {v = value;}
      };
      
      Value(24);
      Assert::AreEqual(24, v, sw_current_information);
    }
    
    class PropertyTestClass {
    public:
      PropertyTestClass() {}
      PropertyTestClass(const PropertyTestClass& property) : name(property.name) {}
      
      Property<string, WriteOnly> Name {
        sw_set {this->name = value;}
      };
      
    public:
      string name = "Test property";
    };
    
    void PropertyCopyConstructor() {
      refptr<PropertyTestClass> p1 = sw_new<PropertyTestClass>();
      refptr<PropertyTestClass> p2 = sw_new<PropertyTestClass>(*p1);
      p2->Name = "Other Value";
      p1 = null;
      Assert::AreEqual("Other Value", p2->name, sw_current_information);
    }
    
    void PropertyEqualOperator() {
      refptr<PropertyTestClass> p1 = sw_new<PropertyTestClass>();
      refptr<PropertyTestClass> p2 = sw_new<PropertyTestClass>();
      *p2 = *p1;
      p2->Name = "Other Value";
      p1 = null;
      Assert::AreEqual("Other Value", p2->name, sw_current_information);
    }
  };
  
  sw_test(PropertyWriteOnlyTest, WriteOnlyCanRead)
  sw_test(PropertyWriteOnlyTest, WriteOnlyCanWrite)
  sw_test(PropertyWriteOnlyTest, PropertyCanRead)
  sw_test(PropertyWriteOnlyTest, PropertyCanWrite)
  sw_test(PropertyWriteOnlyTest, CreatePropertyAndSetItWithEqualOperator)
  sw_test(PropertyWriteOnlyTest, CreatePropertyAndSetItWithSetFunction)
  sw_test(PropertyWriteOnlyTest, CreatePropertyAndSetItWithFunctor)
  sw_test(PropertyWriteOnlyTest, PropertyCopyConstructor)
  sw_test(PropertyWriteOnlyTest, PropertyEqualOperator)
}
