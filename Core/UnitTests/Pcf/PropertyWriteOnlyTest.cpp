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
      PropertyTestClass(const PropertyTestClass& propertyReadOnly) : name(propertyReadOnly.name) {}
      
      Property<string, ReadOnly> Name {
        pcf_get {return this->name;}
      };
      
    private:
      string name = "Test property";
    };
    
    void PropertyCopyConstructor() {
      UniquePointer<PropertyTestClass> p1 = UniquePointer<PropertyTestClass>::Create();
      UniquePointer<PropertyTestClass> p2 = UniquePointer<PropertyTestClass>::Create(*p1);
      p1 = null;
      Assert::AreEqual("Test property", p2->Name, pcf_current_information);
    }
    
    void PropertyEqualOperator() {
      UniquePointer<PropertyTestClass> p1 = UniquePointer<PropertyTestClass>::Create();
      UniquePointer<PropertyTestClass> p2 = UniquePointer<PropertyTestClass>::Create();
      *p2 = *p1;
      p1 = null;
      Assert::AreEqual("Test property", p2->Name, pcf_current_information);
    }
  };
  
  pcf_test(PropertyWriteOnlyTest, WriteOnlyCanRead)
  pcf_test(PropertyWriteOnlyTest, WriteOnlyCanWrite)
  pcf_test(PropertyWriteOnlyTest, PropertyCanRead)
  pcf_test(PropertyWriteOnlyTest, PropertyCanWrite)
  pcf_test(PropertyWriteOnlyTest, CreatePropertyAndGetItWithImplicitCastOperator)
  pcf_test(PropertyWriteOnlyTest, CreatePropertyAndGetItWithGetFunction)
  pcf_test(PropertyWriteOnlyTest, CreatePropertyAndGetItWithFunctor)
  pcf_test(PropertyWriteOnlyTest, PropertyEqualityOperator)
  pcf_test(PropertyWriteOnlyTest, PropertyInequalityOperator)
  pcf_test(PropertyWriteOnlyTest, PropertyCopyConstructor)
  pcf_test(PropertyWriteOnlyTest, PropertyEqualOperator)
}
