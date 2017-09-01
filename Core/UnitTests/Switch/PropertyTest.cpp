#include <Switch/Lock.hpp>
#include <Switch/System/Collections/Concurrent/ConcurrentBag.hpp>
#include <Switch/System/Collections/Concurrent/ConcurrentQueue.hpp>
#include <Switch/System/Collections/Concurrent/ConcurrentStack.hpp>
#include <Switch/System/Collections/Generic/Dictionary.hpp>
#include <Switch/System/Collections/Generic/HashSet.hpp>
#include <Switch/System/Collections/Generic/LinkedList.hpp>
#include <Switch/System/Collections/Generic/List.hpp>
#include <Switch/System/Collections/Generic/Queue.hpp>
#include <Switch/System/Collections/Generic/SortedDictionary.hpp>
#include <Switch/System/Collections/Generic/SortedSet.hpp>
#include <Switch/System/Collections/Generic/Stack.hpp>
#include <Switch/System/Collections/BitArray.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Concurrent;
using namespace System::Collections::Generic;
using namespace TUnit;

namespace SwitchUnitTests {
  class PropertyTest : public TestFixture {
  protected:
    void ReadWriteCanRead() {
      Assert::IsTrue(ReadWrite::CanRead, _current_information);
    }
    
    void ReadWriteCanWrite() {
      Assert::IsTrue(ReadWrite::CanWrite, _current_information);
    }
    
    void PropertyCanRead() {
      Assert::IsTrue(Property<int>::CanRead, _current_information);
    }
    
    void PropertyCanWrite() {
      Assert::IsTrue(ReadWrite::CanWrite, _current_information);
    }
    
    void CreateReadWritePropertyAndGetIt() {
      int32 v = 42;
      Property<int32> Value {
        _get {return v;},
        _set {v = value;}
      };
      
      Assert::AreEqual(42, v, _current_information);
      Assert::AreEqual(42, Value, _current_information);
      Assert::AreEqual(42, Value(), _current_information);
      Assert::AreEqual(42, Value.Get(), _current_information);
    }
    
    void CreateReadWritePropertyAndSetItAndGetIt() {
      int32 v = 42;
      Property<int32> Value {
        _get {return v;},
        _set {v = value;}
      };
      
      Value = 24;
      Assert::AreEqual(24, Value, _current_information);
      Assert::AreEqual(24, v, _current_information);
      
      Value(84);
      Assert::AreEqual(84, Value, _current_information);
      Assert::AreEqual(84, v, _current_information);
      
      Value.Set(48);
      Assert::AreEqual(48, Value, _current_information);
      Assert::AreEqual(48, v, _current_information);
    }
    
    void CreateReadOnlyPropertyAndGetIt() {
      int32 v = 42;
      Property<int32, ReadOnly> Value {
        _get {return v;}
      };
      
      Assert::AreEqual(42, v, _current_information);
      Assert::AreEqual(42, Value, _current_information);
      Assert::AreEqual(42, Value(), _current_information);
      Assert::AreEqual(42, Value.Get(), _current_information);
    }
    
    void CreateWriteOnlyPropertyAndSetIt() {
      int32 v = 42;
      Property<int32, WriteOnly> Value {
        _set {v = value;}
      };
      
      Assert::AreEqual(42, v, _current_information);
      
      Value = 24;
      Assert::AreEqual(24, v, _current_information);
      
      Value(84);
      Assert::AreEqual(84, v, _current_information);
      
      Value.Set(48);
      Assert::AreEqual(48, v, _current_information);
    }
    
    class PropertyReadOnly {
    public:
      PropertyReadOnly() {}
      PropertyReadOnly(const PropertyReadOnly& propertyReadOnly) : name(propertyReadOnly.name) {}
      
      Property<string, ReadOnly> Name {
        _get {return this->name;}
      };
      
    private:
      string name = "Test property";
    };
    
    void PropertyReadOnlyAndCopyConstructor() {
      refptr<PropertyReadOnly> propertyReadOnly1 = ref_new<PropertyReadOnly>();
      refptr<PropertyReadOnly> propertyReadOnly2 = ref_new<PropertyReadOnly>(*propertyReadOnly1);
      propertyReadOnly1 = null;
      Assert::AreEqual("Test property", propertyReadOnly2->Name, _current_information);
    }
    
    void PropertyReadOnlyAndEqualOperator() {
      refptr<PropertyReadOnly> propertyReadOnly1 = ref_new<PropertyReadOnly>();
      refptr<PropertyReadOnly> propertyReadOnly2 = ref_new<PropertyReadOnly>();
      *propertyReadOnly2 = *propertyReadOnly1;
      propertyReadOnly1 = null;
      Assert::AreEqual("Test property", propertyReadOnly2->Name, _current_information);
    }
    
    class PropertyWriteOnly {
    public:
      PropertyWriteOnly() {}
      PropertyWriteOnly(const PropertyWriteOnly& propertyWriteOnly) : name(propertyWriteOnly.name) {}
      
      Property<string, WriteOnly> Name {
        _set {this->name = value;}
      };
      
      string name = "Test property";
    };
    
    void PropertyWriteOnlyAndCopyConstructor() {
      refptr<PropertyWriteOnly> propertyWriteOnly1 = ref_new<PropertyWriteOnly>();
      refptr<PropertyWriteOnly> propertyWriteOnly2 = ref_new<PropertyWriteOnly>(*propertyWriteOnly1);
      propertyWriteOnly1 = null;
      propertyWriteOnly2->Name = "Other thing";
      Assert::AreEqual("Other thing", propertyWriteOnly2->name, _current_information);
    }
    
    void PropertyWriteOnlyAndEqualOperator() {
      refptr<PropertyWriteOnly> propertyWriteOnly1 = ref_new<PropertyWriteOnly>();
      refptr<PropertyWriteOnly> propertyWriteOnly2 = ref_new<PropertyWriteOnly>();
      *propertyWriteOnly2 = *propertyWriteOnly1;
      propertyWriteOnly1 = null;
      propertyWriteOnly2->Name = "Other thing";
      Assert::AreEqual("Other thing", propertyWriteOnly2->name, _current_information);
    }
    
    class PropertyReadWrite {
    public:
      PropertyReadWrite() {}
      PropertyReadWrite(const PropertyReadWrite& propertyReadWrite) : name(propertyReadWrite.name) {}
      
      Property<string> Name {
        _get {return this->name;},
        _set {this->name = value;}
      };
      
    private:
      string name = "Test property";
    };
    
    void PropertyReadWriteAndCopyConstructor() {
      refptr<PropertyReadWrite> propertyReadWrite1 = ref_new<PropertyReadWrite>();
      refptr<PropertyReadWrite> propertyReadWrite2 = ref_new<PropertyReadWrite>(*propertyReadWrite1);
      propertyReadWrite1 = null;
      Assert::AreEqual("Test property", propertyReadWrite2->Name, _current_information);
      propertyReadWrite2->Name = "Other thing";
      Assert::AreEqual("Other thing", propertyReadWrite2->Name, _current_information);
    }
    
    void PropertyReadWriteAndEqualOperator() {
      refptr<PropertyReadWrite> propertyReadWrite1 = ref_new<PropertyReadWrite>();
      refptr<PropertyReadWrite> propertyReadWrite2 = ref_new<PropertyReadWrite>();
      *propertyReadWrite2 = *propertyReadWrite1;
      propertyReadWrite1 = null;
      Assert::AreEqual("Test property", propertyReadWrite2->Name, _current_information);
      propertyReadWrite2->Name = "Other thing";
      Assert::AreEqual("Other thing", propertyReadWrite2->Name, _current_information);
    }
  };
  
  _test(PropertyTest, ReadWriteCanRead)
  _test(PropertyTest, ReadWriteCanWrite)
  _test(PropertyTest, PropertyCanRead)
  _test(PropertyTest, PropertyCanWrite)
  _test(PropertyTest, CreateReadWritePropertyAndGetIt)
  _test(PropertyTest, CreateReadWritePropertyAndSetItAndGetIt)
  _test(PropertyTest, CreateReadOnlyPropertyAndGetIt)
  _test(PropertyTest, CreateWriteOnlyPropertyAndSetIt)
  _test(PropertyTest, PropertyReadOnlyAndCopyConstructor)
  _test(PropertyTest, PropertyReadOnlyAndEqualOperator)
  _test(PropertyTest, PropertyWriteOnlyAndCopyConstructor)
  _test(PropertyTest, PropertyWriteOnlyAndEqualOperator)
  _test(PropertyTest, PropertyReadWriteAndCopyConstructor)
  _test(PropertyTest, PropertyReadWriteAndEqualOperator)
}
