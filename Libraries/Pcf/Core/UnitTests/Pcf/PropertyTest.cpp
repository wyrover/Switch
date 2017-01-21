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
    void ReadOnlyCanRead() {
      Assert::IsTrue(ReadOnly::CanRead, pcf_current_information);
    }
   
    void ReadOnlyCanWrite() {
      Assert::IsFalse(ReadOnly::CanWrite, pcf_current_information);
    }

    void WriteOnlyCanRead() {
      Assert::IsFalse(WriteOnly::CanRead, pcf_current_information);
    }
    
    void WriteOnlyCanWrite() {
      Assert::IsTrue(WriteOnly::CanWrite, pcf_current_information);
    }
    
    void ReadWriteCanRead() {
      Assert::IsTrue(ReadWrite::CanRead, pcf_current_information);
    }
    
    void ReadWriteCanWrite() {
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
    
    void PropertyReadOnlyAndCopyConstructor() {
      class Foo {
      public:
        Foo() {}
        Foo(const Foo& foo) : name(foo.name) {}
        
        Property<string, ReadOnly> Name {
          pcf_get {return this->name;}
        };
        
      private:
        string name = "Test property";
      };
      
      UniquePointer<Foo> foo1 = UniquePointer<Foo>::Create();
      UniquePointer<Foo> foo2 = UniquePointer<Foo>::Create(*foo1);
      foo1 = null;
      Assert::AreEqual("Test property", foo2->Name, pcf_current_information);
    }
    
    void PropertyReadOnlyAndEqualOperator() {
      class Foo {
      public:
        Foo() {}
        Foo(const Foo& foo) : name(foo.name) {}
        
        Property<string, ReadOnly> Name {
          pcf_get {return this->name;}
        };
        
      private:
        string name = "Test property";
      };
      
      UniquePointer<Foo> foo1 = UniquePointer<Foo>::Create();
      UniquePointer<Foo> foo2 = UniquePointer<Foo>::Create();
      *foo2 = *foo1;
      foo1 = null;
      Assert::AreEqual("Test property", foo2->Name, pcf_current_information);
    }
  };
  
  pcf_test(PropertyTest, ReadOnlyCanRead)
  pcf_test(PropertyTest, ReadOnlyCanWrite)
  pcf_test(PropertyTest, WriteOnlyCanRead)
  pcf_test(PropertyTest, WriteOnlyCanWrite)
  pcf_test(PropertyTest, ReadWriteCanRead)
  pcf_test(PropertyTest, ReadWriteCanWrite)
  pcf_test(PropertyTest, CreateReadWritePropertyAndGetIt)
  pcf_test(PropertyTest, CreateReadWritePropertyAndSetItAndGetIt)
  pcf_test(PropertyTest, CreateReadOnlyPropertyAndGetIt)
  pcf_test(PropertyTest, CreateWriteOnlyPropertyAndSetIt)
  pcf_test(PropertyTest, PropertyReadOnlyAndCopyConstructor)
  pcf_test(PropertyTest, PropertyReadOnlyAndEqualOperator)
}
