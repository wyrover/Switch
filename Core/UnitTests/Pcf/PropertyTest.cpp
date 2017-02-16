#include <Pcf/Lock.h>
#include <Pcf/System/Collections/Concurrent/ConcurrentBag.h>
#include <Pcf/System/Collections/Concurrent/ConcurrentQueue.h>
#include <Pcf/System/Collections/Concurrent/ConcurrentStack.h>
#include <Pcf/System/Collections/Generic/Dictionary.h>
#include <Pcf/System/Collections/Generic/HashSet.h>
#include <Pcf/System/Collections/Generic/LinkedList.h>
#include <Pcf/System/Collections/Generic/List.h>
#include <Pcf/System/Collections/Generic/Queue.h>
#include <Pcf/System/Collections/Generic/SortedDictionary.h>
#include <Pcf/System/Collections/Generic/SortedSet.h>
#include <Pcf/System/Collections/Generic/Stack.h>
#include <Pcf/System/Collections/BitArray.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Concurrent;
using namespace System::Collections::Generic;
using namespace TUnit;

namespace PcfUnitTests {
  class PropertyTest : public TestFixture {
  protected:
    void ReadWriteCanRead() {
      Assert::IsTrue(ReadWrite::CanRead, pcf_current_information);
    }
    
    void ReadWriteCanWrite() {
      Assert::IsTrue(ReadWrite::CanWrite, pcf_current_information);
    }
    
    void PropertyCanRead() {
      Assert::IsTrue(Property<int>::CanRead, pcf_current_information);
    }
    
    void PropertyCanWrite() {
      Assert::IsTrue(ReadWrite::CanWrite, pcf_current_information);
    }
    
    void CreateReadWritePropertyAndGetIt() {
      int32 v = 42;
      Property<int32> Value {
        pcf_get {return v;},
        pcf_set {v = value;}
      };
      
      Assert::AreEqual(42, v, pcf_current_information);
      Assert::AreEqual(42, Value, pcf_current_information);
      Assert::AreEqual(42, Value(), pcf_current_information);
      Assert::AreEqual(42, Value.Get(), pcf_current_information);
    }
    
    void CreateReadWritePropertyAndSetItAndGetIt() {
      int32 v = 42;
      Property<int32> Value {
        pcf_get {return v;},
        pcf_set {v = value;}
      };
      
      Value = 24;
      Assert::AreEqual(24, Value, pcf_current_information);
      Assert::AreEqual(24, v, pcf_current_information);
      
      Value(84);
      Assert::AreEqual(84, Value, pcf_current_information);
      Assert::AreEqual(84, v, pcf_current_information);
      
      Value.Set(48);
      Assert::AreEqual(48, Value, pcf_current_information);
      Assert::AreEqual(48, v, pcf_current_information);
    }
    
    void CreateReadOnlyPropertyAndGetIt() {
      int32 v = 42;
      Property<int32, ReadOnly> Value {
        pcf_get {return v;}
      };
      
      Assert::AreEqual(42, v, pcf_current_information);
      Assert::AreEqual(42, Value, pcf_current_information);
      Assert::AreEqual(42, Value(), pcf_current_information);
      Assert::AreEqual(42, Value.Get(), pcf_current_information);
    }
    
    void CreateWriteOnlyPropertyAndSetIt() {
      int32 v = 42;
      Property<int32, WriteOnly> Value {
        pcf_set {v = value;}
      };
      
      Assert::AreEqual(42, v, pcf_current_information);
      
      Value = 24;
      Assert::AreEqual(24, v, pcf_current_information);
      
      Value(84);
      Assert::AreEqual(84, v, pcf_current_information);
      
      Value.Set(48);
      Assert::AreEqual(48, v, pcf_current_information);
    }
    
    class PropertyReadOnly {
    public:
      PropertyReadOnly() {}
      PropertyReadOnly(const PropertyReadOnly& propertyReadOnly) : name(propertyReadOnly.name) {}
      
      Property<string, ReadOnly> Name {
        pcf_get {return this->name;}
      };
      
    private:
      string name = "Test property";
    };
    
    void PropertyReadOnlyAndCopyConstructor() {
      UniquePointer<PropertyReadOnly> propertyReadOnly1 = UniquePointer<PropertyReadOnly>::Create();
      UniquePointer<PropertyReadOnly> propertyReadOnly2 = UniquePointer<PropertyReadOnly>::Create(*propertyReadOnly1);
      propertyReadOnly1 = null;
      Assert::AreEqual("Test property", propertyReadOnly2->Name, pcf_current_information);
    }
    
    void PropertyReadOnlyAndEqualOperator() {
      UniquePointer<PropertyReadOnly> propertyReadOnly1 = UniquePointer<PropertyReadOnly>::Create();
      UniquePointer<PropertyReadOnly> propertyReadOnly2 = UniquePointer<PropertyReadOnly>::Create();
      *propertyReadOnly2 = *propertyReadOnly1;
      propertyReadOnly1 = null;
      Assert::AreEqual("Test property", propertyReadOnly2->Name, pcf_current_information);
    }
    
    class PropertyWriteOnly {
    public:
      PropertyWriteOnly() {}
      PropertyWriteOnly(const PropertyWriteOnly& propertyWriteOnly) : name(propertyWriteOnly.name) {}
      
      Property<string, WriteOnly> Name {
        pcf_set {this->name = value;}
      };
      
      string name = "Test property";
    };
    
    void PropertyWriteOnlyAndCopyConstructor() {
      UniquePointer<PropertyWriteOnly> propertyWriteOnly1 = UniquePointer<PropertyWriteOnly>::Create();
      UniquePointer<PropertyWriteOnly> propertyWriteOnly2 = UniquePointer<PropertyWriteOnly>::Create(*propertyWriteOnly1);
      propertyWriteOnly1 = null;
      propertyWriteOnly2->Name = "Other thing";
      Assert::AreEqual("Other thing", propertyWriteOnly2->name, pcf_current_information);
    }
    
    void PropertyWriteOnlyAndEqualOperator() {
      UniquePointer<PropertyWriteOnly> propertyWriteOnly1 = UniquePointer<PropertyWriteOnly>::Create();
      UniquePointer<PropertyWriteOnly> propertyWriteOnly2 = UniquePointer<PropertyWriteOnly>::Create();
      *propertyWriteOnly2 = *propertyWriteOnly1;
      propertyWriteOnly1 = null;
      propertyWriteOnly2->Name = "Other thing";
      Assert::AreEqual("Other thing", propertyWriteOnly2->name, pcf_current_information);
    }
    
    class PropertyReadWrite {
    public:
      PropertyReadWrite() {}
      PropertyReadWrite(const PropertyReadWrite& propertyReadWrite) : name(propertyReadWrite.name) {}
      
      Property<string> Name {
        pcf_get {return this->name;},
        pcf_set {this->name = value;}
      };
      
    private:
      string name = "Test property";
    };
    
    void PropertyReadWriteAndCopyConstructor() {
      UniquePointer<PropertyReadWrite> propertyReadWrite1 = UniquePointer<PropertyReadWrite>::Create();
      UniquePointer<PropertyReadWrite> propertyReadWrite2 = UniquePointer<PropertyReadWrite>::Create(*propertyReadWrite1);
      propertyReadWrite1 = null;
      Assert::AreEqual("Test property", propertyReadWrite2->Name, pcf_current_information);
      propertyReadWrite2->Name = "Other thing";
      Assert::AreEqual("Other thing", propertyReadWrite2->Name, pcf_current_information);
    }
    
    void PropertyReadWriteAndEqualOperator() {
      UniquePointer<PropertyReadWrite> propertyReadWrite1 = UniquePointer<PropertyReadWrite>::Create();
      UniquePointer<PropertyReadWrite> propertyReadWrite2 = UniquePointer<PropertyReadWrite>::Create();
      *propertyReadWrite2 = *propertyReadWrite1;
      propertyReadWrite1 = null;
      Assert::AreEqual("Test property", propertyReadWrite2->Name, pcf_current_information);
      propertyReadWrite2->Name = "Other thing";
      Assert::AreEqual("Other thing", propertyReadWrite2->Name, pcf_current_information);
    }
  };
  
  pcf_test(PropertyTest, ReadWriteCanRead)
  pcf_test(PropertyTest, ReadWriteCanWrite)
  pcf_test(PropertyTest, PropertyCanRead)
  pcf_test(PropertyTest, PropertyCanWrite)
  pcf_test(PropertyTest, CreateReadWritePropertyAndGetIt)
  pcf_test(PropertyTest, CreateReadWritePropertyAndSetItAndGetIt)
  pcf_test(PropertyTest, CreateReadOnlyPropertyAndGetIt)
  pcf_test(PropertyTest, CreateWriteOnlyPropertyAndSetIt)
  pcf_test(PropertyTest, PropertyReadOnlyAndCopyConstructor)
  pcf_test(PropertyTest, PropertyReadOnlyAndEqualOperator)
  pcf_test(PropertyTest, PropertyWriteOnlyAndCopyConstructor)
  pcf_test(PropertyTest, PropertyWriteOnlyAndEqualOperator)
  pcf_test(PropertyTest, PropertyReadWriteAndCopyConstructor)
  pcf_test(PropertyTest, PropertyReadWriteAndEqualOperator)
}
