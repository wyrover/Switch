#include <Switch/Property.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class PropertyReadOnlyTest : public TestFixture {
  protected:
    void CreatePropertyAndGetItWithImplicitCastOperator() {
      int32 v = 42;
      _property<int32, _readonly> Value {
        _get {return v;}
      };
      
      Assert::AreEqual(42, v, _caller);
      Assert::AreEqual(42, Value, _caller);
    }
    
    void CreatePropertyAndGetItWithGetFunction() {
      int32 v = 42;
      _property<int32, _readonly> Value {
        _get {return v;}
      };
      
      Assert::AreEqual(42, v, _caller);
      Assert::AreEqual(42, Value.Get(), _caller);
    }
    
    void CreatePropertyAndGetItWithFunctor() {
      int32 v = 42;
      _property<int32, _readonly> Value {
        _get {return v;}
      };
      
      Assert::AreEqual(42, v, _caller);
      Assert::AreEqual(42, Value(), _caller);
    }
    
    void PropertyEqualityOperator() {
      int32 v = 42;
      _property<int32, _readonly> Value {
        _get {return v;}
      };
      
      Assert::IsTrue(Value == 42, _caller);
      Assert::IsFalse(Value == 24, _caller);
    }
    
    void PropertyInequalityOperator() {
      int32 v = 42;
      _property<int32, _readonly> Value {
        _get {return v;}
      };
      
      Assert::IsTrue(Value != 24, _caller);
      Assert::IsFalse(Value != 42, _caller);
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
    
    void PropertyCopyConstructor() {
      refptr<PropertyTestClass> p1 = ref_new<PropertyTestClass>();
      refptr<PropertyTestClass> p2 = ref_new<PropertyTestClass>(*p1);
      p1 = null;
      Assert::AreEqual("Test property", p2->Name, _caller);
    }
    
    void PropertyEqualOperator() {
      refptr<PropertyTestClass> p1 = ref_new<PropertyTestClass>();
      refptr<PropertyTestClass> p2 = ref_new<PropertyTestClass>();
      *p2 = *p1;
      p1 = null;
      Assert::AreEqual("Test property", p2->Name, _caller);
    }
  };
  
  _add_test (PropertyReadOnlyTest, CreatePropertyAndGetItWithImplicitCastOperator)
  _add_test (PropertyReadOnlyTest, CreatePropertyAndGetItWithGetFunction)
  _add_test (PropertyReadOnlyTest, CreatePropertyAndGetItWithFunctor)
  _add_test (PropertyReadOnlyTest, PropertyEqualityOperator)
  _add_test (PropertyReadOnlyTest, PropertyInequalityOperator)
  _add_test (PropertyReadOnlyTest, PropertyCopyConstructor)
  _add_test (PropertyReadOnlyTest, PropertyEqualOperator)
}
