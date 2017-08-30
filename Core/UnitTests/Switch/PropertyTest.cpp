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
      Assert::IsTrue(ReadWrite::CanRead, sw_current_information);
    }
    
    void ReadWriteCanWrite() {
      Assert::IsTrue(ReadWrite::CanWrite, sw_current_information);
    }
    
    void PropertyCanRead() {
      Assert::IsTrue(Property<int>::CanRead, sw_current_information);
    }
    
    void PropertyCanWrite() {
      Assert::IsTrue(ReadWrite::CanWrite, sw_current_information);
    }
    
    void CreateReadWritePropertyAndGetIt() {
      int32 v = 42;
      Property<int32> Value {
        sw_get {return v;},
        sw_set {v = value;}
      };
      
      Assert::AreEqual(42, v, sw_current_information);
      Assert::AreEqual(42, Value, sw_current_information);
      Assert::AreEqual(42, Value(), sw_current_information);
      Assert::AreEqual(42, Value.Get(), sw_current_information);
    }
    
    void CreateReadWritePropertyAndSetItAndGetIt() {
      int32 v = 42;
      Property<int32> Value {
        sw_get {return v;},
        sw_set {v = value;}
      };
      
      Value = 24;
      Assert::AreEqual(24, Value, sw_current_information);
      Assert::AreEqual(24, v, sw_current_information);
      
      Value(84);
      Assert::AreEqual(84, Value, sw_current_information);
      Assert::AreEqual(84, v, sw_current_information);
      
      Value.Set(48);
      Assert::AreEqual(48, Value, sw_current_information);
      Assert::AreEqual(48, v, sw_current_information);
    }
    
    void CreateReadOnlyPropertyAndGetIt() {
      int32 v = 42;
      Property<int32, ReadOnly> Value {
        sw_get {return v;}
      };
      
      Assert::AreEqual(42, v, sw_current_information);
      Assert::AreEqual(42, Value, sw_current_information);
      Assert::AreEqual(42, Value(), sw_current_information);
      Assert::AreEqual(42, Value.Get(), sw_current_information);
    }
    
    void CreateWriteOnlyPropertyAndSetIt() {
      int32 v = 42;
      Property<int32, WriteOnly> Value {
        sw_set {v = value;}
      };
      
      Assert::AreEqual(42, v, sw_current_information);
      
      Value = 24;
      Assert::AreEqual(24, v, sw_current_information);
      
      Value(84);
      Assert::AreEqual(84, v, sw_current_information);
      
      Value.Set(48);
      Assert::AreEqual(48, v, sw_current_information);
    }
    
    class PropertyReadOnly {
    public:
      PropertyReadOnly() {}
      PropertyReadOnly(const PropertyReadOnly& propertyReadOnly) : name(propertyReadOnly.name) {}
      
      Property<string, ReadOnly> Name {
        sw_get {return this->name;}
      };
      
    private:
      string name = "Test property";
    };
    
    void PropertyReadOnlyAndCopyConstructor() {
      refptr<PropertyReadOnly> propertyReadOnly1 = sw_new<PropertyReadOnly>();
      refptr<PropertyReadOnly> propertyReadOnly2 = sw_new<PropertyReadOnly>(*propertyReadOnly1);
      propertyReadOnly1 = null;
      Assert::AreEqual("Test property", propertyReadOnly2->Name, sw_current_information);
    }
    
    void PropertyReadOnlyAndEqualOperator() {
      refptr<PropertyReadOnly> propertyReadOnly1 = sw_new<PropertyReadOnly>();
      refptr<PropertyReadOnly> propertyReadOnly2 = sw_new<PropertyReadOnly>();
      *propertyReadOnly2 = *propertyReadOnly1;
      propertyReadOnly1 = null;
      Assert::AreEqual("Test property", propertyReadOnly2->Name, sw_current_information);
    }
    
    class PropertyWriteOnly {
    public:
      PropertyWriteOnly() {}
      PropertyWriteOnly(const PropertyWriteOnly& propertyWriteOnly) : name(propertyWriteOnly.name) {}
      
      Property<string, WriteOnly> Name {
        sw_set {this->name = value;}
      };
      
      string name = "Test property";
    };
    
    void PropertyWriteOnlyAndCopyConstructor() {
      refptr<PropertyWriteOnly> propertyWriteOnly1 = sw_new<PropertyWriteOnly>();
      refptr<PropertyWriteOnly> propertyWriteOnly2 = sw_new<PropertyWriteOnly>(*propertyWriteOnly1);
      propertyWriteOnly1 = null;
      propertyWriteOnly2->Name = "Other thing";
      Assert::AreEqual("Other thing", propertyWriteOnly2->name, sw_current_information);
    }
    
    void PropertyWriteOnlyAndEqualOperator() {
      refptr<PropertyWriteOnly> propertyWriteOnly1 = sw_new<PropertyWriteOnly>();
      refptr<PropertyWriteOnly> propertyWriteOnly2 = sw_new<PropertyWriteOnly>();
      *propertyWriteOnly2 = *propertyWriteOnly1;
      propertyWriteOnly1 = null;
      propertyWriteOnly2->Name = "Other thing";
      Assert::AreEqual("Other thing", propertyWriteOnly2->name, sw_current_information);
    }
    
    class PropertyReadWrite {
    public:
      PropertyReadWrite() {}
      PropertyReadWrite(const PropertyReadWrite& propertyReadWrite) : name(propertyReadWrite.name) {}
      
      Property<string> Name {
        sw_get {return this->name;},
        sw_set {this->name = value;}
      };
      
    private:
      string name = "Test property";
    };
    
    void PropertyReadWriteAndCopyConstructor() {
      refptr<PropertyReadWrite> propertyReadWrite1 = sw_new<PropertyReadWrite>();
      refptr<PropertyReadWrite> propertyReadWrite2 = sw_new<PropertyReadWrite>(*propertyReadWrite1);
      propertyReadWrite1 = null;
      Assert::AreEqual("Test property", propertyReadWrite2->Name, sw_current_information);
      propertyReadWrite2->Name = "Other thing";
      Assert::AreEqual("Other thing", propertyReadWrite2->Name, sw_current_information);
    }
    
    void PropertyReadWriteAndEqualOperator() {
      refptr<PropertyReadWrite> propertyReadWrite1 = sw_new<PropertyReadWrite>();
      refptr<PropertyReadWrite> propertyReadWrite2 = sw_new<PropertyReadWrite>();
      *propertyReadWrite2 = *propertyReadWrite1;
      propertyReadWrite1 = null;
      Assert::AreEqual("Test property", propertyReadWrite2->Name, sw_current_information);
      propertyReadWrite2->Name = "Other thing";
      Assert::AreEqual("Other thing", propertyReadWrite2->Name, sw_current_information);
    }
  };
  
  sw_test(PropertyTest, ReadWriteCanRead)
  sw_test(PropertyTest, ReadWriteCanWrite)
  sw_test(PropertyTest, PropertyCanRead)
  sw_test(PropertyTest, PropertyCanWrite)
  sw_test(PropertyTest, CreateReadWritePropertyAndGetIt)
  sw_test(PropertyTest, CreateReadWritePropertyAndSetItAndGetIt)
  sw_test(PropertyTest, CreateReadOnlyPropertyAndGetIt)
  sw_test(PropertyTest, CreateWriteOnlyPropertyAndSetIt)
  sw_test(PropertyTest, PropertyReadOnlyAndCopyConstructor)
  sw_test(PropertyTest, PropertyReadOnlyAndEqualOperator)
  sw_test(PropertyTest, PropertyWriteOnlyAndCopyConstructor)
  sw_test(PropertyTest, PropertyWriteOnlyAndEqualOperator)
  sw_test(PropertyTest, PropertyReadWriteAndCopyConstructor)
  sw_test(PropertyTest, PropertyReadWriteAndEqualOperator)
}
