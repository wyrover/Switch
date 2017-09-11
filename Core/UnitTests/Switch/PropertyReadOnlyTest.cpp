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
      
      Assert::AreEqual(42, v, _current_information);
      Assert::AreEqual(42, Value, _current_information);
    }
    
    void CreatePropertyAndGetItWithGetFunction() {
      int32 v = 42;
      _property<int32, _readonly> Value {
        _get {return v;}
      };
      
      Assert::AreEqual(42, v, _current_information);
      Assert::AreEqual(42, Value.Get(), _current_information);
    }
    
    void CreatePropertyAndGetItWithFunctor() {
      int32 v = 42;
      _property<int32, _readonly> Value {
        _get {return v;}
      };
      
      Assert::AreEqual(42, v, _current_information);
      Assert::AreEqual(42, Value(), _current_information);
    }
    
    void PropertyEqualityOperator() {
      int32 v = 42;
      _property<int32, _readonly> Value {
        _get {return v;}
      };
      
      Assert::IsTrue(Value == 42, _current_information);
      Assert::IsFalse(Value == 24, _current_information);
    }
    
    void PropertyInequalityOperator() {
      int32 v = 42;
      _property<int32, _readonly> Value {
        _get {return v;}
      };
      
      Assert::IsTrue(Value != 24, _current_information);
      Assert::IsFalse(Value != 42, _current_information);
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
      Assert::AreEqual("Test property", p2->Name, _current_information);
    }
    
    void PropertyEqualOperator() {
      refptr<PropertyTestClass> p1 = ref_new<PropertyTestClass>();
      refptr<PropertyTestClass> p2 = ref_new<PropertyTestClass>();
      *p2 = *p1;
      p1 = null;
      Assert::AreEqual("Test property", p2->Name, _current_information);
    }
  };
  
  _test(PropertyReadOnlyTest, CreatePropertyAndGetItWithImplicitCastOperator)
  _test(PropertyReadOnlyTest, CreatePropertyAndGetItWithGetFunction)
  _test(PropertyReadOnlyTest, CreatePropertyAndGetItWithFunctor)
  _test(PropertyReadOnlyTest, PropertyEqualityOperator)
  _test(PropertyReadOnlyTest, PropertyInequalityOperator)
  _test(PropertyReadOnlyTest, PropertyCopyConstructor)
  _test(PropertyReadOnlyTest, PropertyEqualOperator)
}
