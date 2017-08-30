#include <Switch/Is.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  class IsTest : public TestFixture {
  protected:
    void StringIsString() {
      string s = "Test";
      Assert::IsTrue(is<string>(s), sw_current_information);
    }

    void StringIsObject() {
      string s = "Test";
      Assert::IsTrue(is<object>(s), sw_current_information);
    }
    
    void StringIsIComparable() {
      string s = "Test";
      Assert::IsTrue(is<IComparable>(s), sw_current_information);
    }
    
    void StringIsInt32() {
      string s = "Test";
      Assert::IsFalse(is<Int32>(s), sw_current_information);
    }
    
    void ObjectFromStringIsString() {
      string s = "Test";
      object& o = s;
      Assert::IsTrue(is<string>(o), sw_current_information);
    }
    
    void ObjectFromStringIsObject() {
      string s = "Test";
      object& o = s;
      Assert::IsTrue(is<object>(o), sw_current_information);
    }
    
    void ObjectFormStringIsIComparable() {
      string s = "Test";
      object& o = s;
      Assert::IsTrue(is<IComparable>(o), sw_current_information);
    }
    
    void ObjectFormStringIsInt32() {
      string s = "Test";
      object& o = s;
      Assert::IsFalse(is<Int32>(o), sw_current_information);
    }
    
    void ConstStringIsString() {
      const string s = "Test";
      Assert::IsTrue(is<string>(s), sw_current_information);
    }
    
    void ConstStringIsObject() {
      const string s = "Test";
      Assert::IsTrue(is<object>(s), sw_current_information);
    }
    
    void ConstStringIsIComparable() {
      const string s = "Test";
      Assert::IsTrue(is<IComparable>(s), sw_current_information);
    }
    
    void ConstStringIsInt32() {
      const string s = "Test";
      Assert::IsFalse(is<Int32>(s), sw_current_information);
    }
    
    void ConstObjectFromStringIsString() {
      const string s = "Test";
      const object& o = s;
      Assert::IsTrue(is<string>(o), sw_current_information);
    }
    
    void ConstObjectFromStringIsObject() {
      const string s = "Test";
      const object& o = s;
      Assert::IsTrue(is<object>(o), sw_current_information);
    }
    
    void ConstObjectFormStringIsIComparable() {
      const string s = "Test";
      const object& o = s;
      Assert::IsTrue(is<IComparable>(o), sw_current_information);
    }
    
    void ConstObjectFormStringIsInt32() {
      const string s = "Test";
      const object& o = s;
      Assert::IsFalse(is<Int32>(o), sw_current_information);
    }
    
    void StringPtrIsString() {
      string s = "Test";
      Assert::IsTrue(is<string>(&s), sw_current_information);
    }
    
    void StringPtrIsObject() {
      string s = "Test";
      Assert::IsTrue(is<object>(&s), sw_current_information);
    }
    
    void StringPtrIsIComparable() {
      string s = "Test";
      Assert::IsTrue(is<IComparable>(&s), sw_current_information);
    }
    
    void StringPtrIsInt32() {
      string s = "Test";
      Assert::IsFalse(is<Int32>(&s), sw_current_information);
    }
    
    void ObjectPtrFromStringPtrIsString() {
      string s = "Test";
      object* o = &s;
      Assert::IsTrue(is<string>(o), sw_current_information);
    }
    
    void ObjectPtrFromStringPtrIsObject() {
      string s = "Test";
      object* o = &s;
      Assert::IsTrue(is<object>(o), sw_current_information);
    }
    
    void ObjectPtrFormStringPtrIsIComparable() {
      string s = "Test";
      object* o = &s;
      Assert::IsTrue(is<IComparable>(o), sw_current_information);
    }
    
    void ObjectPtrFormStringPtrIsInt32() {
      string s = "Test";
      object* o = &s;
      Assert::IsFalse(is<Int32>(o), sw_current_information);
    }
    
    void StringPtrNullIsString() {
      string* s = null;
      Assert::IsFalse(is<string>(s), sw_current_information);
    }
    
    void StringPtrNullIsObject() {
      string* s = null;
      Assert::IsFalse(is<object>(s), sw_current_information);
    }
    
    void StringPtrNullIsIComparable() {
      string* s = null;
      Assert::IsFalse(is<IComparable>(s), sw_current_information);
    }
    
    void StringPtrNullIsInt32() {
      string* s = null;
      Assert::IsFalse(is<Int32>(s), sw_current_information);
    }
    
    void ObjectPtrFromStringPtrNullIsString() {
      string* s = null;
      object* o = s;
      Assert::IsFalse(is<string>(o), sw_current_information);
    }
    
    void ObjectPtrFromStringPtrNullIsObject() {
      string* s = null;
      object* o = s;
      Assert::IsFalse(is<object>(o), sw_current_information);
    }
    
    void ObjectPtrFormStringPtrNullIsIComparable() {
      string* s = null;
      object* o = s;
      Assert::IsFalse(is<IComparable>(o), sw_current_information);
    }
    
    void ObjectPtrFormStringPtrNullIsInt32() {
      string* s = null;
      object* o = s;
      Assert::IsFalse(is<Int32>(o), sw_current_information);
    }
    
    void ConstStringPtrIsString() {
      string s = "Test";
      const string* cs = &s;
      Assert::IsTrue(is<string>(cs), sw_current_information);
    }
    
    void ConstStringPtrIsObject() {
      string s = "Test";
      const string* cs = &s;
      Assert::IsTrue(is<object>(cs), sw_current_information);
    }
    
    void ConstStringPtrIsIComparable() {
      string s = "Test";
      const string* cs = &s;
      Assert::IsTrue(is<IComparable>(cs), sw_current_information);
    }
    
    void ConstStringPtrIsInt32() {
      string s = "Test";
      const string* cs = &s;
      Assert::IsFalse(is<Int32>(cs), sw_current_information);
    }
    
    void ConstObjectPtrFromStringPtrIsString() {
      string s = "Test";
      const object* o = &s;
      Assert::IsTrue(is<string>(o), sw_current_information);
    }
    
    void ConstObjectPtrFromStringPtrIsObject() {
      string s = "Test";
      const object* o = &s;
      Assert::IsTrue(is<object>(o), sw_current_information);
    }
    
    void ConstObjectPtrFormStringPtrIsIComparable() {
      string s = "Test";
      const object* o = &s;
      Assert::IsTrue(is<IComparable>(o), sw_current_information);
    }
    
    void ConstObjectPtrFormStringPtrIsInt32() {
      string s = "Test";
      const object* o = &s;
      Assert::IsFalse(is<Int32>(o), sw_current_information);
    }
    
    void ConstStringPtrNullIsString() {
      const string* s = null;
      Assert::IsFalse(is<string>(s), sw_current_information);
    }
    
    void ConstStringPtrNullIsObject() {
      const string* s = null;
      Assert::IsFalse(is<object>(s), sw_current_information);
    }
    
    void ConstStringPtrNullIsIComparable() {
      const string* s = null;
      Assert::IsFalse(is<IComparable>(s), sw_current_information);
    }
    
    void ConstStringPtrNullIsInt32() {
      const string* s = null;
      Assert::IsFalse(is<Int32>(s), sw_current_information);
    }
    
    void ConstObjectPtrFromStringPtrNullIsString() {
      const string* s = null;
      const object* o = s;
      Assert::IsFalse(is<string>(o), sw_current_information);
    }
    
    void ConstObjectPtrFromStringPtrNullIsObject() {
      const string* s = null;
      const object* o = s;
      Assert::IsFalse(is<object>(o), sw_current_information);
    }
    
    void ConstObjectPtrFormStringPtrNullIsIComparable() {
      const string* s = null;
      const object* o = s;
      Assert::IsFalse(is<IComparable>(o), sw_current_information);
    }
    
    void ConstObjectPtrFormStringPtrNullIsInt32() {
      const string* s = null;
      const object* o = s;
      Assert::IsFalse(is<Int32>(o), sw_current_information);
    }
    
    void SpStringIsString() {
      refptr<string> s = sw_new<String>("Test");
      Assert::IsTrue(is<string>(s), sw_current_information);
    }
    
    void SpStringIsObject() {
      refptr<string> s = sw_new<String>("Test");
      Assert::IsTrue(is<object>(s)), sw_current_information;
    }
    
    void SpStringIsIComparable() {
      refptr<string> s = sw_new<String>("Test");
      Assert::IsTrue(is<IComparable>(s), sw_current_information);
    }
    
    void SpStringIsInt32() {
      refptr<string> s = new String("Test");
      Assert::IsFalse(is<Int32>(s), sw_current_information);
    }
    
    void SpObjectFromSpStringIsString() {
      refptr<object> o = sw_new<string>("Test");
      Assert::IsTrue(is<string>(o), sw_current_information);
    }
    
    void SpObjectFromSpStringIsObject() {
      refptr<object> o = sw_new<string>("Test");
      Assert::IsTrue(is<object>(o), sw_current_information);
    }
    
    void SpObjectFormSpStringIsIComparable() {
      refptr<object> o = sw_new<string>("Test");
      Assert::IsTrue(is<IComparable>(o), sw_current_information);
    }
    
    void SpObjectFormSpStringIsInt32() {
      refptr<object> o = sw_new<string>("Test");
      Assert::IsFalse(is<Int32>(o), sw_current_information);
    }
    
    void SpStringNullIsString() {
      refptr<string> s = refptr<string>::Null();
      Assert::IsFalse(is<string>(s), sw_current_information);
    }
    
    void SpStringNullIsObject() {
      refptr<string> s = refptr<string>::Null();
      Assert::IsFalse(is<object>(s), sw_current_information);
    }
    
    void SpStringNullIsIComparable() {
      refptr<string> s = refptr<string>::Null();
      Assert::IsFalse(is<IComparable>(s), sw_current_information);
    }
    
    void SpStringNullIsInt32() {
      refptr<string> s = refptr<string>::Null();
      Assert::IsFalse(is<Int32>(s), sw_current_information);
    }
    
    void SpObjectFromSpStringNullIsString() {
      refptr<object> o = as<object>(refptr<string>::Null());
      Assert::IsFalse(is<string>(o), sw_current_information);
    }
    
    void SpObjectFromSpStringNullIsObject() {
      refptr<object> o = as<object>(refptr<string>::Null());
      Assert::IsFalse(is<object>(o), sw_current_information);
    }
    
    void SpObjectFormSpStringNullIsIComparable() {
      refptr<object> o = as<object>(refptr<string>::Null());
      Assert::IsFalse(is<IComparable>(o), sw_current_information);
    }
    
    void SpObjectFormSpStringNullIsInt32() {
      refptr<object> o = as<object>(refptr<string>::Null());
      Assert::IsFalse(is<Int32>(o), sw_current_information);
    }
    
    void ConstSpStringIsString() {
      const refptr<string> s = sw_new<String>("Test");
      Assert::IsTrue(is<string>(s), sw_current_information);
    }
    
    void ConstSpStringIsObject() {
      const refptr<string> s = sw_new<String>("Test");
      Assert::IsTrue(is<object>(s), sw_current_information);
    }
    
    void ConstSpStringIsIComparable() {
      const refptr<string> s = sw_new<String>("Test");
      Assert::IsTrue(is<IComparable>(s), sw_current_information);
    }
    
    void ConstSpStringIsInt32() {
      const refptr<string> s = sw_new<String>("Test");
      Assert::IsFalse(is<Int32>(s), sw_current_information);
    }
    
    void ConstSpObjectFromConstSpStringIsString() {
      const refptr<object> o = sw_new<string>("Test");
      Assert::IsTrue(is<string>(o), sw_current_information);
    }
    
    void ConstSpObjectFromConstSpStringIsObject() {
      const refptr<object> o = sw_new<string>("Test");
      Assert::IsTrue(is<object>(o), sw_current_information);
    }
    
    void ConstSpObjectFormConstSpStringIsIComparable() {
      const refptr<object> o = sw_new<string>("Test");
      Assert::IsTrue(is<IComparable>(o), sw_current_information);
    }
    
    void ConstSpObjectFormConstSpStringIsInt32() {
      const refptr<object> o = sw_new<string>("Test");
      Assert::IsFalse(is<Int32>(o), sw_current_information);
    }
    
    void ConstSpStringNullIsString() {
      const refptr<string> s = refptr<string>::Null();
      Assert::IsFalse(is<string>(s), sw_current_information);
    }
    
    void ConstSpStringNullIsObject() {
      const refptr<string> s = refptr<string>::Null();
      Assert::IsFalse(is<object>(s), sw_current_information);
    }
    
    void ConstSpStringNullIsIComparable() {
      const refptr<string> s = refptr<string>::Null();
      Assert::IsFalse(is<IComparable>(s), sw_current_information);
    }
    
    void ConstSpStringNullIsInt32() {
      const refptr<string> s = refptr<string>::Null();
      Assert::IsFalse(is<Int32>(s), sw_current_information);
    }
    
    void ConstSpObjectFromConstSpStringNullIsString() {
      const refptr<object> o = as<object>(refptr<string>::Null());
      Assert::IsFalse(is<string>(o), sw_current_information);
    }
    
    void ConstSpObjectFromConstSpStringNullIsObject() {
      const refptr<object> o = as<object>(refptr<string>::Null());
      Assert::IsFalse(is<object>(o), sw_current_information);
    }
    
    void ConstSpObjectFormConstSpStringNullIsIComparable() {
      const refptr<object> o = as<object>(refptr<string>::Null());
      Assert::IsFalse(is<IComparable>(o), sw_current_information);
    }
    
    void ConstSpObjectFormConstSpStringNullIsInt32() {
      const refptr<object> o = as<object>(refptr<string>::Null());
      Assert::IsFalse(is<Int32>(o), sw_current_information);
    }
    
    void UpStringIsString() {
      UniquePtr<string> s = MakeUnique<String>("Test");
      Assert::IsTrue(is<string>(s), sw_current_information);
    }
    
    void UpStringIsObject() {
      UniquePtr<string> s = MakeUnique<String>("Test");
      Assert::IsTrue(is<object>(s), sw_current_information);
    }
    
    void UpStringIsIComparable() {
      UniquePtr<string> s = MakeUnique<String>("Test");
      Assert::IsTrue(is<IComparable>(s), sw_current_information);
    }
    
    void UpStringIsInt32() {
      UniquePtr<string> s = MakeUnique<String>("Test");
      Assert::IsFalse(is<Int32>(s), sw_current_information);
    }
    
    void UpObjectFromUpStringIsString() {
      UniquePtr<object> o = MakeUnique<string>("Test");
      Assert::IsTrue(is<string>(o), sw_current_information);
    }
    
    void UpObjectFromUpStringIsObject() {
      UniquePtr<object> o = MakeUnique<string>("Test");
      Assert::IsTrue(is<object>(o), sw_current_information);
    }
    
    void UpObjectFormUpStringIsIComparable() {
      UniquePtr<object> o = MakeUnique<string>("Test");
      Assert::IsTrue(is<IComparable>(o), sw_current_information);
    }
    
    void UpObjectFormUpStringIsInt32() {
      UniquePtr<object> o = MakeUnique<string>("Test");
      Assert::IsFalse(is<Int32>(o), sw_current_information);
    }
    
    void UpStringNullIsString() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      Assert::IsFalse(is<string>(s), sw_current_information);
    }
    
    void UpStringNullIsObject() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      Assert::IsFalse(is<object>(s), sw_current_information);
    }
    
    void UpStringNullIsIComparable() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      Assert::IsFalse(is<IComparable>(s), sw_current_information);
    }
    
    void UpStringNullIsInt32() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      Assert::IsFalse(is<Int32>(s), sw_current_information);
    }
    
    void UpObjectFromUpStringNullIsString() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<object> o = as<object>(s);
      Assert::IsFalse(is<string>(o), sw_current_information);
    }
    
    void UpObjectFromUpStringNullIsObject() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<object> o = as<object>(s);
      Assert::IsFalse(is<object>(o), sw_current_information);
    }
    
    void UpObjectFormUpStringNullIsIComparable() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<object> o = as<object>(s);
      Assert::IsFalse(is<IComparable>(o), sw_current_information);
    }
    
    void UpObjectFormUpStringNullIsInt32() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<object> o = as<object>(s);
      Assert::IsFalse(is<Int32>(o), sw_current_information);
    }
    
    void RefStringIsString() {
      string str = "Test";
      ref<string> s = str;
      Assert::IsTrue(is<string>(s), sw_current_information);
    }
    
    void RefStringIsObject() {
      string str = "Test";
      ref<string> s = str;
      Assert::IsTrue(is<object>(s), sw_current_information);
    }
    
    void RefStringIsIComparable() {
      string str = "Test";
      ref<string> s = str;
      Assert::IsTrue(is<IComparable>(s), sw_current_information);
    }
    
    void RefStringIsInt32() {
      string str = "Test";
      ref<string> s = str;
      Assert::IsFalse(is<Int32>(s), sw_current_information);
    }
    
    void RefObjectFromRefStringIsString() {
      string str = "Test";
      ref<object> o = str;
      Assert::IsTrue(is<string>(o), sw_current_information);
    }
    
    void RefObjectFromRefStringIsObject() {
      string str = "Test";
      ref<object> o = str;
      Assert::IsTrue(is<object>(o), sw_current_information);
    }
    
    void RefObjectFormRefStringIsIComparable() {
      string str = "Test";
      ref<object> o = str;
      Assert::IsTrue(is<IComparable>(o), sw_current_information);
    }
    
    void RefObjectFormRefStringIsInt32() {
      string str = "Test";
      ref<object> o = str;
      Assert::IsFalse(is<Int32>(o), sw_current_information);
    }
    
    void RefStringNullIsString() {
      ref<string> s = ref<string>::Null();
      Assert::IsFalse(is<string>(s), sw_current_information);
    }
    
    void RefStringNullIsObject() {
      ref<string> s = ref<string>::Null();
      Assert::IsFalse(is<object>(s), sw_current_information);
    }
    
    void RefStringNullIsIComparable() {
      ref<string> s = ref<string>::Null();
      Assert::IsFalse(is<IComparable>(s), sw_current_information);
    }
    
    void RefStringNullIsInt32() {
      ref<string> s = ref<string>::Null();
      Assert::IsFalse(is<Int32>(s), sw_current_information);
    }
    
    void RefObjectFromRefStringNullIsString() {
      ref<object> o = as<object>(ref<string>::Null());
      Assert::IsFalse(is<string>(o), sw_current_information);
    }
    
    void RefObjectFromRefStringNullIsObject() {
      ref<object> o = as<object>(ref<string>::Null());
      Assert::IsFalse(is<object>(o), sw_current_information);
    }
    
    void RefObjectFormRefStringNullIsIComparable() {
      ref<object> o = as<object>(ref<string>::Null());
      Assert::IsFalse(is<IComparable>(o), sw_current_information);
    }
    
    void RefObjectFormRefStringNullIsInt32() {
      ref<object> o = as<object>(ref<string>::Null());
      Assert::IsFalse(is<Int32>(o), sw_current_information);
    }
    
    void ConstRefStringIsString() {
      const string str = "Test";
      const ref<string> s = str;
      Assert::IsTrue(is<string>(s), sw_current_information);
    }
    
    void ConstRefStringIsObject() {
      const string str = "Test";
      const ref<string> s = str;
      Assert::IsTrue(is<object>(s), sw_current_information);
    }
    
    void ConstRefStringIsIComparable() {
      const string str = "Test";
      const ref<string> s = str;
      Assert::IsTrue(is<IComparable>(s), sw_current_information);
    }
    
    void ConstRefStringIsInt32() {
      const string str = "Test";
      const ref<string> s = str;
      Assert::IsFalse(is<Int32>(s), sw_current_information);
    }
    
    void ConstRefObjectFromConstRefStringIsString() {
      const string str = "Test";
      const ref<object> o = str;
      Assert::IsTrue(is<string>(o), sw_current_information);
    }
    
    void ConstRefObjectFromConstRefStringIsObject() {
      const string str = "Test";
      const ref<object> o = str;
      Assert::IsTrue(is<object>(o), sw_current_information);
    }
    
    void ConstRefObjectFormConstRefStringIsIComparable() {
      const string str = "Test";
      const ref<object> o = str;
      Assert::IsTrue(is<IComparable>(o), sw_current_information);
    }
    
    void ConstRefObjectFormConstRefStringIsInt32() {
      const string str = "Test";
      const ref<object> o = str;
      Assert::IsFalse(is<Int32>(o), sw_current_information);
    }
    
    void ConstRefStringNullIsString() {
      const ref<string> s = ref<string>::Null();
      Assert::IsFalse(is<string>(s), sw_current_information);
    }
    
    void ConstRefStringNullIsObject() {
      const ref<string> s = ref<string>::Null();
      Assert::IsFalse(is<object>(s), sw_current_information);
    }
    
    void ConstRefStringNullIsIComparable() {
      const ref<string> s = ref<string>::Null();
      Assert::IsFalse(is<IComparable>(s), sw_current_information);
    }
    
    void ConstRefStringNullIsInt32() {
      const ref<string> s = ref<string>::Null();
      Assert::IsFalse(is<Int32>(s), sw_current_information);
    }
    
    void ConstRefObjectFromConstRefStringNullIsString() {
      const ref<object> o = as<object>(ref<string>::Null());
      Assert::IsFalse(is<string>(o), sw_current_information);
    }
    
    void ConstRefObjectFromConstRefStringNullIsObject() {
      const ref<object> o = as<object>(ref<string>::Null());
      Assert::IsFalse(is<object>(o), sw_current_information);
    }
    
    void ConstRefObjectFormConstRefStringNullIsIComparable() {
      const ref<object> o = as<object>(ref<string>::Null());
      Assert::IsFalse(is<IComparable>(o), sw_current_information);
    }
    
    void ConstRefObjectFormConstRefStringNullIsInt32() {
      const ref<object> o = as<object>(ref<string>::Null());
      Assert::IsFalse(is<Int32>(o), sw_current_information);
    }
  };
  
  sw_test(IsTest, StringIsString)
  sw_test(IsTest, StringIsObject)
  sw_test(IsTest, StringIsIComparable)
  sw_test(IsTest, StringIsInt32)
  sw_test(IsTest, ObjectFromStringIsString)
  sw_test(IsTest, ObjectFromStringIsObject)
  sw_test(IsTest, ObjectFormStringIsIComparable)
  sw_test(IsTest, ObjectFormStringIsInt32)
  sw_test(IsTest, ConstStringIsString)
  sw_test(IsTest, ConstStringIsObject)
  sw_test(IsTest, ConstStringIsIComparable)
  sw_test(IsTest, ConstStringIsInt32)
  sw_test(IsTest, ConstObjectFromStringIsString)
  sw_test(IsTest, ConstObjectFromStringIsObject)
  sw_test(IsTest, ConstObjectFormStringIsIComparable)
  sw_test(IsTest, ConstObjectFormStringIsInt32)
  sw_test(IsTest, StringPtrIsString)
  sw_test(IsTest, StringPtrIsObject)
  sw_test(IsTest, StringPtrIsIComparable)
  sw_test(IsTest, StringPtrIsInt32)
  sw_test(IsTest, ObjectPtrFromStringPtrIsString)
  sw_test(IsTest, ObjectPtrFromStringPtrIsObject)
  sw_test(IsTest, ObjectPtrFormStringPtrIsIComparable)
  sw_test(IsTest, ObjectPtrFormStringPtrIsInt32)
  sw_test(IsTest, StringPtrNullIsString)
  sw_test(IsTest, StringPtrNullIsObject)
  sw_test(IsTest, StringPtrNullIsIComparable)
  sw_test(IsTest, StringPtrNullIsInt32)
  sw_test(IsTest, ObjectPtrFromStringPtrNullIsString)
  sw_test(IsTest, ObjectPtrFromStringPtrNullIsObject)
  sw_test(IsTest, ObjectPtrFormStringPtrNullIsIComparable)
  sw_test(IsTest, ObjectPtrFormStringPtrNullIsInt32)
  sw_test(IsTest, ConstStringPtrIsString)
  sw_test(IsTest, ConstStringPtrIsObject)
  sw_test(IsTest, ConstStringPtrIsIComparable)
  sw_test(IsTest, ConstStringPtrIsInt32)
  sw_test(IsTest, ConstObjectPtrFromStringPtrIsString)
  sw_test(IsTest, ConstObjectPtrFromStringPtrIsObject)
  sw_test(IsTest, ConstObjectPtrFormStringPtrIsIComparable)
  sw_test(IsTest, ConstObjectPtrFormStringPtrIsInt32)
  sw_test(IsTest, ConstStringPtrNullIsString)
  sw_test(IsTest, ConstStringPtrNullIsObject)
  sw_test(IsTest, ConstStringPtrNullIsIComparable)
  sw_test(IsTest, ConstStringPtrNullIsInt32)
  sw_test(IsTest, ConstObjectPtrFromStringPtrNullIsString)
  sw_test(IsTest, ConstObjectPtrFromStringPtrNullIsObject)
  sw_test(IsTest, ConstObjectPtrFormStringPtrNullIsIComparable)
  sw_test(IsTest, ConstObjectPtrFormStringPtrNullIsInt32)
  sw_test(IsTest, SpStringIsString)
  sw_test(IsTest, SpStringIsObject)
  sw_test(IsTest, SpStringIsIComparable)
  sw_test(IsTest, SpStringIsInt32)
  sw_test(IsTest, SpObjectFromSpStringIsString)
  sw_test(IsTest, SpObjectFromSpStringIsObject)
  sw_test(IsTest, SpObjectFormSpStringIsIComparable)
  sw_test(IsTest, SpObjectFormSpStringIsInt32)
  sw_test(IsTest, SpStringNullIsString)
  sw_test(IsTest, SpStringNullIsObject)
  sw_test(IsTest, SpStringNullIsIComparable)
  sw_test(IsTest, SpStringNullIsInt32)
  sw_test(IsTest, SpObjectFromSpStringNullIsString)
  sw_test(IsTest, SpObjectFromSpStringNullIsObject)
  sw_test(IsTest, SpObjectFormSpStringNullIsIComparable)
  sw_test(IsTest, SpObjectFormSpStringNullIsInt32)
  sw_test(IsTest, ConstSpStringIsString)
  sw_test(IsTest, ConstSpStringIsObject)
  sw_test(IsTest, ConstSpStringIsIComparable)
  sw_test(IsTest, ConstSpStringIsInt32)
  sw_test(IsTest, ConstSpObjectFromConstSpStringIsString)
  sw_test(IsTest, ConstSpObjectFromConstSpStringIsObject)
  sw_test(IsTest, ConstSpObjectFormConstSpStringIsIComparable)
  sw_test(IsTest, ConstSpObjectFormConstSpStringIsInt32)
  sw_test(IsTest, ConstSpStringNullIsString)
  sw_test(IsTest, ConstSpStringNullIsObject)
  sw_test(IsTest, ConstSpStringNullIsIComparable)
  sw_test(IsTest, ConstSpStringNullIsInt32)
  sw_test(IsTest, ConstSpObjectFromConstSpStringNullIsString)
  sw_test(IsTest, ConstSpObjectFromConstSpStringNullIsObject)
  sw_test(IsTest, ConstSpObjectFormConstSpStringNullIsIComparable)
  sw_test(IsTest, ConstSpObjectFormConstSpStringNullIsInt32)
  sw_test(IsTest, UpStringIsString)
  sw_test(IsTest, UpStringIsObject)
  sw_test(IsTest, UpStringIsIComparable)
  sw_test(IsTest, UpStringIsInt32)
  sw_test(IsTest, UpObjectFromUpStringIsString)
  sw_test(IsTest, UpObjectFromUpStringIsObject)
  sw_test(IsTest, UpObjectFormUpStringIsIComparable)
  sw_test(IsTest, UpObjectFormUpStringIsInt32)
  sw_test(IsTest, UpStringNullIsString)
  sw_test(IsTest, UpStringNullIsObject)
  sw_test(IsTest, UpStringNullIsIComparable)
  sw_test(IsTest, UpStringNullIsInt32)
  sw_test(IsTest, UpObjectFromUpStringNullIsString)
  sw_test(IsTest, UpObjectFromUpStringNullIsObject)
  sw_test(IsTest, UpObjectFormUpStringNullIsIComparable)
  sw_test(IsTest, UpObjectFormUpStringNullIsInt32)
  sw_test(IsTest, RefStringIsString)
  sw_test(IsTest, RefStringIsObject)
  sw_test(IsTest, RefStringIsIComparable)
  sw_test(IsTest, RefStringIsInt32)
  sw_test(IsTest, RefObjectFromRefStringIsString)
  sw_test(IsTest, RefObjectFromRefStringIsObject)
  sw_test(IsTest, RefObjectFormRefStringIsIComparable)
  sw_test(IsTest, RefObjectFormRefStringIsInt32)
  sw_test(IsTest, RefStringNullIsString)
  sw_test(IsTest, RefStringNullIsObject)
  sw_test(IsTest, RefStringNullIsIComparable)
  sw_test(IsTest, RefStringNullIsInt32)
  sw_test(IsTest, RefObjectFromRefStringNullIsString)
  sw_test(IsTest, RefObjectFromRefStringNullIsObject)
  sw_test(IsTest, RefObjectFormRefStringNullIsIComparable)
  sw_test(IsTest, RefObjectFormRefStringNullIsInt32)
  sw_test(IsTest, ConstRefStringIsString)
  sw_test(IsTest, ConstRefStringIsObject)
  sw_test(IsTest, ConstRefStringIsIComparable)
  sw_test(IsTest, ConstRefStringIsInt32)
  sw_test(IsTest, ConstRefObjectFromConstRefStringIsString)
  sw_test(IsTest, ConstRefObjectFromConstRefStringIsObject)
  sw_test(IsTest, ConstRefObjectFormConstRefStringIsIComparable)
  sw_test(IsTest, ConstRefObjectFormConstRefStringIsInt32)
  sw_test(IsTest, ConstRefStringNullIsString)
  sw_test(IsTest, ConstRefStringNullIsObject)
  sw_test(IsTest, ConstRefStringNullIsIComparable)
  sw_test(IsTest, ConstRefStringNullIsInt32)
  sw_test(IsTest, ConstRefObjectFromConstRefStringNullIsString)
  sw_test(IsTest, ConstRefObjectFromConstRefStringNullIsObject)
  sw_test(IsTest, ConstRefObjectFormConstRefStringNullIsIComparable)
  sw_test(IsTest, ConstRefObjectFormConstRefStringNullIsInt32)
}
