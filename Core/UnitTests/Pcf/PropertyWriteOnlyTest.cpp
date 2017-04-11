#include <Pcf/Property.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class PropertyWriteOnlyTest : public TestFixture {
  protected:
    void WriteOnlyCanRead() {
      Assert::IsFalse(WriteOnly::CanRead, pcf_current_information);
    }
    
    void WriteOnlyCanWrite() {
      Assert::IsTrue(WriteOnly::CanWrite, pcf_current_information);
    }

    void PropertyCanRead() {
      Assert::IsFalse(Property<int, WriteOnly>::CanRead, pcf_current_information);
    }
    
    void PropertyCanWrite() {
      Assert::IsTrue(Property<int, WriteOnly>::CanWrite, pcf_current_information);
    }
    
    void CreatePropertyAndSetItWithEqualOperator() {
      int32 v = 42;
      Property<int32, WriteOnly> Value {
        pcf_set {v = value;}
      };

      Value = 24;
      Assert::AreEqual(24, v, pcf_current_information);
    }
    
    void CreatePropertyAndSetItWithSetFunction() {
      int32 v = 42;
      Property<int32, WriteOnly> Value {
        pcf_set {v = value;}
      };
      
      Value.Set(24);
      Assert::AreEqual(24, v, pcf_current_information);
    }
    
    void CreatePropertyAndSetItWithFunctor() {
      int32 v = 42;
      Property<int32, WriteOnly> Value {
        pcf_set {v = value;}
      };
      
      Value(24);
      Assert::AreEqual(24, v, pcf_current_information);
    }
    
    class PropertyTestClass {
    public:
      PropertyTestClass() {}
      PropertyTestClass(const PropertyTestClass& property) : name(property.name) {}
      
      Property<string, WriteOnly> Name {
        pcf_set {this->name = value;}
      };
      
    public:
      string name = "Test property";
    };
    
    void PropertyCopyConstructor() {
      refptr<PropertyTestClass> p1 = pcf_new<PropertyTestClass>();
      refptr<PropertyTestClass> p2 = pcf_new<PropertyTestClass>(*p1);
      p2->Name = "Other Value";
      p1 = null;
      Assert::AreEqual("Other Value", p2->name, pcf_current_information);
    }
    
    void PropertyEqualOperator() {
      refptr<PropertyTestClass> p1 = pcf_new<PropertyTestClass>();
      refptr<PropertyTestClass> p2 = pcf_new<PropertyTestClass>();
      *p2 = *p1;
      p2->Name = "Other Value";
      p1 = null;
      Assert::AreEqual("Other Value", p2->name, pcf_current_information);
    }
  };
  
  pcf_test(PropertyWriteOnlyTest, WriteOnlyCanRead)
  pcf_test(PropertyWriteOnlyTest, WriteOnlyCanWrite)
  pcf_test(PropertyWriteOnlyTest, PropertyCanRead)
  pcf_test(PropertyWriteOnlyTest, PropertyCanWrite)
  pcf_test(PropertyWriteOnlyTest, CreatePropertyAndSetItWithEqualOperator)
  pcf_test(PropertyWriteOnlyTest, CreatePropertyAndSetItWithSetFunction)
  pcf_test(PropertyWriteOnlyTest, CreatePropertyAndSetItWithFunctor)
  pcf_test(PropertyWriteOnlyTest, PropertyCopyConstructor)
  pcf_test(PropertyWriteOnlyTest, PropertyEqualOperator)
}
