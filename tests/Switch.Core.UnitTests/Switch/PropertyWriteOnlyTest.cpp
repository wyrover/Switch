#include <Switch/Property.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class PropertyWriteOnlyTest : public TestFixture {
  protected:
    void CreatePropertyAndSetItWithEqualOperator() {
      int32 v = 42;
      _property<int32, _writeonly> Value {
        _set {v = value;}
      };

      Value = 24;
      Assert::AreEqual(24, v, _caller);
    }
    
    void CreatePropertyAndSetItWithSetFunction() {
      int32 v = 42;
      _property<int32, _writeonly> Value {
        _set {v = value;}
      };
      
      Value.Set(24);
      Assert::AreEqual(24, v, _caller);
    }
    
    void CreatePropertyAndSetItWithFunctor() {
      int32 v = 42;
      _property<int32, _writeonly> Value {
        _set {v = value;}
      };
      
      Value(24);
      Assert::AreEqual(24, v, _caller);
    }
    
    class PropertyTestClass {
    public:
      PropertyTestClass() {}
      PropertyTestClass(const PropertyTestClass& property) : name(property.name) {}
      
      _property<string, _writeonly> Name {
        _set {this->name = value;}
      };
      
    public:
      string name = "Test property";
    };
    
    void PropertyCopyConstructor() {
      refptr<PropertyTestClass> p1 = ref_new<PropertyTestClass>();
      refptr<PropertyTestClass> p2 = ref_new<PropertyTestClass>(*p1);
      p2->Name = "Other Value";
      p1 = null;
      Assert::AreEqual("Other Value", p2->name, _caller);
    }
    
    void PropertyEqualOperator() {
      refptr<PropertyTestClass> p1 = ref_new<PropertyTestClass>();
      refptr<PropertyTestClass> p2 = ref_new<PropertyTestClass>();
      *p2 = *p1;
      p2->Name = "Other Value";
      p1 = null;
      Assert::AreEqual("Other Value", p2->name, _caller);
    }
  };
  
  _AddTest(PropertyWriteOnlyTest, CreatePropertyAndSetItWithEqualOperator)
  _AddTest(PropertyWriteOnlyTest, CreatePropertyAndSetItWithSetFunction)
  _AddTest(PropertyWriteOnlyTest, CreatePropertyAndSetItWithFunctor)
  _AddTest(PropertyWriteOnlyTest, PropertyCopyConstructor)
  _AddTest(PropertyWriteOnlyTest, PropertyEqualOperator)
}
