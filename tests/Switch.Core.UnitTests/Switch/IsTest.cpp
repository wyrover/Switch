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
      Assert::IsTrue(is<string>(s), _caller);
    }

    void StringIsObject() {
      string s = "Test";
      Assert::IsTrue(is<object>(s), _caller);
    }
    
    void StringIsIComparable() {
      string s = "Test";
      Assert::IsTrue(is<IComparable>(s), _caller);
    }
    
    void StringIsInt32() {
      string s = "Test";
      Assert::IsFalse(is<Int32>(s), _caller);
    }
    
    void ObjectFromStringIsString() {
      string s = "Test";
      object& o = s;
      Assert::IsTrue(is<string>(o), _caller);
    }
    
    void ObjectFromStringIsObject() {
      string s = "Test";
      object& o = s;
      Assert::IsTrue(is<object>(o), _caller);
    }
    
    void ObjectFormStringIsIComparable() {
      string s = "Test";
      object& o = s;
      Assert::IsTrue(is<IComparable>(o), _caller);
    }
    
    void ObjectFormStringIsInt32() {
      string s = "Test";
      object& o = s;
      Assert::IsFalse(is<Int32>(o), _caller);
    }
    
    void ConstStringIsString() {
      const string s = "Test";
      Assert::IsTrue(is<string>(s), _caller);
    }
    
    void ConstStringIsObject() {
      const string s = "Test";
      Assert::IsTrue(is<object>(s), _caller);
    }
    
    void ConstStringIsIComparable() {
      const string s = "Test";
      Assert::IsTrue(is<IComparable>(s), _caller);
    }
    
    void ConstStringIsInt32() {
      const string s = "Test";
      Assert::IsFalse(is<Int32>(s), _caller);
    }
    
    void ConstObjectFromStringIsString() {
      const string s = "Test";
      const object& o = s;
      Assert::IsTrue(is<string>(o), _caller);
    }
    
    void ConstObjectFromStringIsObject() {
      const string s = "Test";
      const object& o = s;
      Assert::IsTrue(is<object>(o), _caller);
    }
    
    void ConstObjectFormStringIsIComparable() {
      const string s = "Test";
      const object& o = s;
      Assert::IsTrue(is<IComparable>(o), _caller);
    }
    
    void ConstObjectFormStringIsInt32() {
      const string s = "Test";
      const object& o = s;
      Assert::IsFalse(is<Int32>(o), _caller);
    }
    
    void StringPtrIsString() {
      string s = "Test";
      Assert::IsTrue(is<string>(&s), _caller);
    }
    
    void StringPtrIsObject() {
      string s = "Test";
      Assert::IsTrue(is<object>(&s), _caller);
    }
    
    void StringPtrIsIComparable() {
      string s = "Test";
      Assert::IsTrue(is<IComparable>(&s), _caller);
    }
    
    void StringPtrIsInt32() {
      string s = "Test";
      Assert::IsFalse(is<Int32>(&s), _caller);
    }
    
    void ObjectPtrFromStringPtrIsString() {
      string s = "Test";
      object* o = &s;
      Assert::IsTrue(is<string>(o), _caller);
    }
    
    void ObjectPtrFromStringPtrIsObject() {
      string s = "Test";
      object* o = &s;
      Assert::IsTrue(is<object>(o), _caller);
    }
    
    void ObjectPtrFormStringPtrIsIComparable() {
      string s = "Test";
      object* o = &s;
      Assert::IsTrue(is<IComparable>(o), _caller);
    }
    
    void ObjectPtrFormStringPtrIsInt32() {
      string s = "Test";
      object* o = &s;
      Assert::IsFalse(is<Int32>(o), _caller);
    }
    
    void StringPtrNullIsString() {
      string* s = null;
      Assert::IsFalse(is<string>(s), _caller);
    }
    
    void StringPtrNullIsObject() {
      string* s = null;
      Assert::IsFalse(is<object>(s), _caller);
    }
    
    void StringPtrNullIsIComparable() {
      string* s = null;
      Assert::IsFalse(is<IComparable>(s), _caller);
    }
    
    void StringPtrNullIsInt32() {
      string* s = null;
      Assert::IsFalse(is<Int32>(s), _caller);
    }
    
    void ObjectPtrFromStringPtrNullIsString() {
      string* s = null;
      object* o = s;
      Assert::IsFalse(is<string>(o), _caller);
    }
    
    void ObjectPtrFromStringPtrNullIsObject() {
      string* s = null;
      object* o = s;
      Assert::IsFalse(is<object>(o), _caller);
    }
    
    void ObjectPtrFormStringPtrNullIsIComparable() {
      string* s = null;
      object* o = s;
      Assert::IsFalse(is<IComparable>(o), _caller);
    }
    
    void ObjectPtrFormStringPtrNullIsInt32() {
      string* s = null;
      object* o = s;
      Assert::IsFalse(is<Int32>(o), _caller);
    }
    
    void ConstStringPtrIsString() {
      string s = "Test";
      const string* cs = &s;
      Assert::IsTrue(is<string>(cs), _caller);
    }
    
    void ConstStringPtrIsObject() {
      string s = "Test";
      const string* cs = &s;
      Assert::IsTrue(is<object>(cs), _caller);
    }
    
    void ConstStringPtrIsIComparable() {
      string s = "Test";
      const string* cs = &s;
      Assert::IsTrue(is<IComparable>(cs), _caller);
    }
    
    void ConstStringPtrIsInt32() {
      string s = "Test";
      const string* cs = &s;
      Assert::IsFalse(is<Int32>(cs), _caller);
    }
    
    void ConstObjectPtrFromStringPtrIsString() {
      string s = "Test";
      const object* o = &s;
      Assert::IsTrue(is<string>(o), _caller);
    }
    
    void ConstObjectPtrFromStringPtrIsObject() {
      string s = "Test";
      const object* o = &s;
      Assert::IsTrue(is<object>(o), _caller);
    }
    
    void ConstObjectPtrFormStringPtrIsIComparable() {
      string s = "Test";
      const object* o = &s;
      Assert::IsTrue(is<IComparable>(o), _caller);
    }
    
    void ConstObjectPtrFormStringPtrIsInt32() {
      string s = "Test";
      const object* o = &s;
      Assert::IsFalse(is<Int32>(o), _caller);
    }
    
    void ConstStringPtrNullIsString() {
      const string* s = null;
      Assert::IsFalse(is<string>(s), _caller);
    }
    
    void ConstStringPtrNullIsObject() {
      const string* s = null;
      Assert::IsFalse(is<object>(s), _caller);
    }
    
    void ConstStringPtrNullIsIComparable() {
      const string* s = null;
      Assert::IsFalse(is<IComparable>(s), _caller);
    }
    
    void ConstStringPtrNullIsInt32() {
      const string* s = null;
      Assert::IsFalse(is<Int32>(s), _caller);
    }
    
    void ConstObjectPtrFromStringPtrNullIsString() {
      const string* s = null;
      const object* o = s;
      Assert::IsFalse(is<string>(o), _caller);
    }
    
    void ConstObjectPtrFromStringPtrNullIsObject() {
      const string* s = null;
      const object* o = s;
      Assert::IsFalse(is<object>(o), _caller);
    }
    
    void ConstObjectPtrFormStringPtrNullIsIComparable() {
      const string* s = null;
      const object* o = s;
      Assert::IsFalse(is<IComparable>(o), _caller);
    }
    
    void ConstObjectPtrFormStringPtrNullIsInt32() {
      const string* s = null;
      const object* o = s;
      Assert::IsFalse(is<Int32>(o), _caller);
    }
    
    void SpStringIsString() {
      refptr<string> s = ref_new<String>("Test");
      Assert::IsTrue(is<string>(s), _caller);
    }
    
    void SpStringIsObject() {
      refptr<string> s = ref_new<String>("Test");
      Assert::IsTrue(is<object>(s)), _caller;
    }
    
    void SpStringIsIComparable() {
      refptr<string> s = ref_new<String>("Test");
      Assert::IsTrue(is<IComparable>(s), _caller);
    }
    
    void SpStringIsInt32() {
      refptr<string> s = new String("Test");
      Assert::IsFalse(is<Int32>(s), _caller);
    }
    
    void SpObjectFromSpStringIsString() {
      refptr<object> o = ref_new<string>("Test");
      Assert::IsTrue(is<string>(o), _caller);
    }
    
    void SpObjectFromSpStringIsObject() {
      refptr<object> o = ref_new<string>("Test");
      Assert::IsTrue(is<object>(o), _caller);
    }
    
    void SpObjectFormSpStringIsIComparable() {
      refptr<object> o = ref_new<string>("Test");
      Assert::IsTrue(is<IComparable>(o), _caller);
    }
    
    void SpObjectFormSpStringIsInt32() {
      refptr<object> o = ref_new<string>("Test");
      Assert::IsFalse(is<Int32>(o), _caller);
    }
    
    void SpStringNullIsString() {
      refptr<string> s = refptr<string>::Null();
      Assert::IsFalse(is<string>(s), _caller);
    }
    
    void SpStringNullIsObject() {
      refptr<string> s = refptr<string>::Null();
      Assert::IsFalse(is<object>(s), _caller);
    }
    
    void SpStringNullIsIComparable() {
      refptr<string> s = refptr<string>::Null();
      Assert::IsFalse(is<IComparable>(s), _caller);
    }
    
    void SpStringNullIsInt32() {
      refptr<string> s = refptr<string>::Null();
      Assert::IsFalse(is<Int32>(s), _caller);
    }
    
    void SpObjectFromSpStringNullIsString() {
      refptr<object> o = as<object>(refptr<string>::Null());
      Assert::IsFalse(is<string>(o), _caller);
    }
    
    void SpObjectFromSpStringNullIsObject() {
      refptr<object> o = as<object>(refptr<string>::Null());
      Assert::IsFalse(is<object>(o), _caller);
    }
    
    void SpObjectFormSpStringNullIsIComparable() {
      refptr<object> o = as<object>(refptr<string>::Null());
      Assert::IsFalse(is<IComparable>(o), _caller);
    }
    
    void SpObjectFormSpStringNullIsInt32() {
      refptr<object> o = as<object>(refptr<string>::Null());
      Assert::IsFalse(is<Int32>(o), _caller);
    }
    
    void ConstSpStringIsString() {
      const refptr<string> s = ref_new<String>("Test");
      Assert::IsTrue(is<string>(s), _caller);
    }
    
    void ConstSpStringIsObject() {
      const refptr<string> s = ref_new<String>("Test");
      Assert::IsTrue(is<object>(s), _caller);
    }
    
    void ConstSpStringIsIComparable() {
      const refptr<string> s = ref_new<String>("Test");
      Assert::IsTrue(is<IComparable>(s), _caller);
    }
    
    void ConstSpStringIsInt32() {
      const refptr<string> s = ref_new<String>("Test");
      Assert::IsFalse(is<Int32>(s), _caller);
    }
    
    void ConstSpObjectFromConstSpStringIsString() {
      const refptr<object> o = ref_new<string>("Test");
      Assert::IsTrue(is<string>(o), _caller);
    }
    
    void ConstSpObjectFromConstSpStringIsObject() {
      const refptr<object> o = ref_new<string>("Test");
      Assert::IsTrue(is<object>(o), _caller);
    }
    
    void ConstSpObjectFormConstSpStringIsIComparable() {
      const refptr<object> o = ref_new<string>("Test");
      Assert::IsTrue(is<IComparable>(o), _caller);
    }
    
    void ConstSpObjectFormConstSpStringIsInt32() {
      const refptr<object> o = ref_new<string>("Test");
      Assert::IsFalse(is<Int32>(o), _caller);
    }
    
    void ConstSpStringNullIsString() {
      const refptr<string> s = refptr<string>::Null();
      Assert::IsFalse(is<string>(s), _caller);
    }
    
    void ConstSpStringNullIsObject() {
      const refptr<string> s = refptr<string>::Null();
      Assert::IsFalse(is<object>(s), _caller);
    }
    
    void ConstSpStringNullIsIComparable() {
      const refptr<string> s = refptr<string>::Null();
      Assert::IsFalse(is<IComparable>(s), _caller);
    }
    
    void ConstSpStringNullIsInt32() {
      const refptr<string> s = refptr<string>::Null();
      Assert::IsFalse(is<Int32>(s), _caller);
    }
    
    void ConstSpObjectFromConstSpStringNullIsString() {
      const refptr<object> o = as<object>(refptr<string>::Null());
      Assert::IsFalse(is<string>(o), _caller);
    }
    
    void ConstSpObjectFromConstSpStringNullIsObject() {
      const refptr<object> o = as<object>(refptr<string>::Null());
      Assert::IsFalse(is<object>(o), _caller);
    }
    
    void ConstSpObjectFormConstSpStringNullIsIComparable() {
      const refptr<object> o = as<object>(refptr<string>::Null());
      Assert::IsFalse(is<IComparable>(o), _caller);
    }
    
    void ConstSpObjectFormConstSpStringNullIsInt32() {
      const refptr<object> o = as<object>(refptr<string>::Null());
      Assert::IsFalse(is<Int32>(o), _caller);
    }
    
    void RefStringIsString() {
      string str = "Test";
      ref<string> s = str;
      Assert::IsTrue(is<string>(s), _caller);
    }
    
    void RefStringIsObject() {
      string str = "Test";
      ref<string> s = str;
      Assert::IsTrue(is<object>(s), _caller);
    }
    
    void RefStringIsIComparable() {
      string str = "Test";
      ref<string> s = str;
      Assert::IsTrue(is<IComparable>(s), _caller);
    }
    
    void RefStringIsInt32() {
      string str = "Test";
      ref<string> s = str;
      Assert::IsFalse(is<Int32>(s), _caller);
    }
    
    void RefObjectFromRefStringIsString() {
      string str = "Test";
      ref<object> o = str;
      Assert::IsTrue(is<string>(o), _caller);
    }
    
    void RefObjectFromRefStringIsObject() {
      string str = "Test";
      ref<object> o = str;
      Assert::IsTrue(is<object>(o), _caller);
    }
    
    void RefObjectFormRefStringIsIComparable() {
      string str = "Test";
      ref<object> o = str;
      Assert::IsTrue(is<IComparable>(o), _caller);
    }
    
    void RefObjectFormRefStringIsInt32() {
      string str = "Test";
      ref<object> o = str;
      Assert::IsFalse(is<Int32>(o), _caller);
    }
    
    void RefStringNullIsString() {
      ref<string> s = ref<string>::Null();
      Assert::IsFalse(is<string>(s), _caller);
    }
    
    void RefStringNullIsObject() {
      ref<string> s = ref<string>::Null();
      Assert::IsFalse(is<object>(s), _caller);
    }
    
    void RefStringNullIsIComparable() {
      ref<string> s = ref<string>::Null();
      Assert::IsFalse(is<IComparable>(s), _caller);
    }
    
    void RefStringNullIsInt32() {
      ref<string> s = ref<string>::Null();
      Assert::IsFalse(is<Int32>(s), _caller);
    }
    
    void RefObjectFromRefStringNullIsString() {
      ref<object> o = as<object>(ref<string>::Null());
      Assert::IsFalse(is<string>(o), _caller);
    }
    
    void RefObjectFromRefStringNullIsObject() {
      ref<object> o = as<object>(ref<string>::Null());
      Assert::IsFalse(is<object>(o), _caller);
    }
    
    void RefObjectFormRefStringNullIsIComparable() {
      ref<object> o = as<object>(ref<string>::Null());
      Assert::IsFalse(is<IComparable>(o), _caller);
    }
    
    void RefObjectFormRefStringNullIsInt32() {
      ref<object> o = as<object>(ref<string>::Null());
      Assert::IsFalse(is<Int32>(o), _caller);
    }
    
    void ConstRefStringIsString() {
      const string str = "Test";
      const ref<string> s = str;
      Assert::IsTrue(is<string>(s), _caller);
    }
    
    void ConstRefStringIsObject() {
      const string str = "Test";
      const ref<string> s = str;
      Assert::IsTrue(is<object>(s), _caller);
    }
    
    void ConstRefStringIsIComparable() {
      const string str = "Test";
      const ref<string> s = str;
      Assert::IsTrue(is<IComparable>(s), _caller);
    }
    
    void ConstRefStringIsInt32() {
      const string str = "Test";
      const ref<string> s = str;
      Assert::IsFalse(is<Int32>(s), _caller);
    }
    
    void ConstRefObjectFromConstRefStringIsString() {
      const string str = "Test";
      const ref<object> o = str;
      Assert::IsTrue(is<string>(o), _caller);
    }
    
    void ConstRefObjectFromConstRefStringIsObject() {
      const string str = "Test";
      const ref<object> o = str;
      Assert::IsTrue(is<object>(o), _caller);
    }
    
    void ConstRefObjectFormConstRefStringIsIComparable() {
      const string str = "Test";
      const ref<object> o = str;
      Assert::IsTrue(is<IComparable>(o), _caller);
    }
    
    void ConstRefObjectFormConstRefStringIsInt32() {
      const string str = "Test";
      const ref<object> o = str;
      Assert::IsFalse(is<Int32>(o), _caller);
    }
    
    void ConstRefStringNullIsString() {
      const ref<string> s = ref<string>::Null();
      Assert::IsFalse(is<string>(s), _caller);
    }
    
    void ConstRefStringNullIsObject() {
      const ref<string> s = ref<string>::Null();
      Assert::IsFalse(is<object>(s), _caller);
    }
    
    void ConstRefStringNullIsIComparable() {
      const ref<string> s = ref<string>::Null();
      Assert::IsFalse(is<IComparable>(s), _caller);
    }
    
    void ConstRefStringNullIsInt32() {
      const ref<string> s = ref<string>::Null();
      Assert::IsFalse(is<Int32>(s), _caller);
    }
    
    void ConstRefObjectFromConstRefStringNullIsString() {
      const ref<object> o = as<object>(ref<string>::Null());
      Assert::IsFalse(is<string>(o), _caller);
    }
    
    void ConstRefObjectFromConstRefStringNullIsObject() {
      const ref<object> o = as<object>(ref<string>::Null());
      Assert::IsFalse(is<object>(o), _caller);
    }
    
    void ConstRefObjectFormConstRefStringNullIsIComparable() {
      const ref<object> o = as<object>(ref<string>::Null());
      Assert::IsFalse(is<IComparable>(o), _caller);
    }
    
    void ConstRefObjectFormConstRefStringNullIsInt32() {
      const ref<object> o = as<object>(ref<string>::Null());
      Assert::IsFalse(is<Int32>(o), _caller);
    }
  };
  
  _add_test(IsTest, StringIsString)
  _add_test(IsTest, StringIsObject)
  _add_test(IsTest, StringIsIComparable)
  _add_test(IsTest, StringIsInt32)
  _add_test(IsTest, ObjectFromStringIsString)
  _add_test(IsTest, ObjectFromStringIsObject)
  _add_test(IsTest, ObjectFormStringIsIComparable)
  _add_test(IsTest, ObjectFormStringIsInt32)
  _add_test(IsTest, ConstStringIsString)
  _add_test(IsTest, ConstStringIsObject)
  _add_test(IsTest, ConstStringIsIComparable)
  _add_test(IsTest, ConstStringIsInt32)
  _add_test(IsTest, ConstObjectFromStringIsString)
  _add_test(IsTest, ConstObjectFromStringIsObject)
  _add_test(IsTest, ConstObjectFormStringIsIComparable)
  _add_test(IsTest, ConstObjectFormStringIsInt32)
  _add_test(IsTest, StringPtrIsString)
  _add_test(IsTest, StringPtrIsObject)
  _add_test(IsTest, StringPtrIsIComparable)
  _add_test(IsTest, StringPtrIsInt32)
  _add_test(IsTest, ObjectPtrFromStringPtrIsString)
  _add_test(IsTest, ObjectPtrFromStringPtrIsObject)
  _add_test(IsTest, ObjectPtrFormStringPtrIsIComparable)
  _add_test(IsTest, ObjectPtrFormStringPtrIsInt32)
  _add_test(IsTest, StringPtrNullIsString)
  _add_test(IsTest, StringPtrNullIsObject)
  _add_test(IsTest, StringPtrNullIsIComparable)
  _add_test(IsTest, StringPtrNullIsInt32)
  _add_test(IsTest, ObjectPtrFromStringPtrNullIsString)
  _add_test(IsTest, ObjectPtrFromStringPtrNullIsObject)
  _add_test(IsTest, ObjectPtrFormStringPtrNullIsIComparable)
  _add_test(IsTest, ObjectPtrFormStringPtrNullIsInt32)
  _add_test(IsTest, ConstStringPtrIsString)
  _add_test(IsTest, ConstStringPtrIsObject)
  _add_test(IsTest, ConstStringPtrIsIComparable)
  _add_test(IsTest, ConstStringPtrIsInt32)
  _add_test(IsTest, ConstObjectPtrFromStringPtrIsString)
  _add_test(IsTest, ConstObjectPtrFromStringPtrIsObject)
  _add_test(IsTest, ConstObjectPtrFormStringPtrIsIComparable)
  _add_test(IsTest, ConstObjectPtrFormStringPtrIsInt32)
  _add_test(IsTest, ConstStringPtrNullIsString)
  _add_test(IsTest, ConstStringPtrNullIsObject)
  _add_test(IsTest, ConstStringPtrNullIsIComparable)
  _add_test(IsTest, ConstStringPtrNullIsInt32)
  _add_test(IsTest, ConstObjectPtrFromStringPtrNullIsString)
  _add_test(IsTest, ConstObjectPtrFromStringPtrNullIsObject)
  _add_test(IsTest, ConstObjectPtrFormStringPtrNullIsIComparable)
  _add_test(IsTest, ConstObjectPtrFormStringPtrNullIsInt32)
  _add_test(IsTest, SpStringIsString)
  _add_test(IsTest, SpStringIsObject)
  _add_test(IsTest, SpStringIsIComparable)
  _add_test(IsTest, SpStringIsInt32)
  _add_test(IsTest, SpObjectFromSpStringIsString)
  _add_test(IsTest, SpObjectFromSpStringIsObject)
  _add_test(IsTest, SpObjectFormSpStringIsIComparable)
  _add_test(IsTest, SpObjectFormSpStringIsInt32)
  _add_test(IsTest, SpStringNullIsString)
  _add_test(IsTest, SpStringNullIsObject)
  _add_test(IsTest, SpStringNullIsIComparable)
  _add_test(IsTest, SpStringNullIsInt32)
  _add_test(IsTest, SpObjectFromSpStringNullIsString)
  _add_test(IsTest, SpObjectFromSpStringNullIsObject)
  _add_test(IsTest, SpObjectFormSpStringNullIsIComparable)
  _add_test(IsTest, SpObjectFormSpStringNullIsInt32)
  _add_test(IsTest, ConstSpStringIsString)
  _add_test(IsTest, ConstSpStringIsObject)
  _add_test(IsTest, ConstSpStringIsIComparable)
  _add_test(IsTest, ConstSpStringIsInt32)
  _add_test(IsTest, ConstSpObjectFromConstSpStringIsString)
  _add_test(IsTest, ConstSpObjectFromConstSpStringIsObject)
  _add_test(IsTest, ConstSpObjectFormConstSpStringIsIComparable)
  _add_test(IsTest, ConstSpObjectFormConstSpStringIsInt32)
  _add_test(IsTest, ConstSpStringNullIsString)
  _add_test(IsTest, ConstSpStringNullIsObject)
  _add_test(IsTest, ConstSpStringNullIsIComparable)
  _add_test(IsTest, ConstSpStringNullIsInt32)
  _add_test(IsTest, ConstSpObjectFromConstSpStringNullIsString)
  _add_test(IsTest, ConstSpObjectFromConstSpStringNullIsObject)
  _add_test(IsTest, ConstSpObjectFormConstSpStringNullIsIComparable)
  _add_test(IsTest, ConstSpObjectFormConstSpStringNullIsInt32)
  _add_test(IsTest, RefStringIsString)
  _add_test(IsTest, RefStringIsObject)
  _add_test(IsTest, RefStringIsIComparable)
  _add_test(IsTest, RefStringIsInt32)
  _add_test(IsTest, RefObjectFromRefStringIsString)
  _add_test(IsTest, RefObjectFromRefStringIsObject)
  _add_test(IsTest, RefObjectFormRefStringIsIComparable)
  _add_test(IsTest, RefObjectFormRefStringIsInt32)
  _add_test(IsTest, RefStringNullIsString)
  _add_test(IsTest, RefStringNullIsObject)
  _add_test(IsTest, RefStringNullIsIComparable)
  _add_test(IsTest, RefStringNullIsInt32)
  _add_test(IsTest, RefObjectFromRefStringNullIsString)
  _add_test(IsTest, RefObjectFromRefStringNullIsObject)
  _add_test(IsTest, RefObjectFormRefStringNullIsIComparable)
  _add_test(IsTest, RefObjectFormRefStringNullIsInt32)
  _add_test(IsTest, ConstRefStringIsString)
  _add_test(IsTest, ConstRefStringIsObject)
  _add_test(IsTest, ConstRefStringIsIComparable)
  _add_test(IsTest, ConstRefStringIsInt32)
  _add_test(IsTest, ConstRefObjectFromConstRefStringIsString)
  _add_test(IsTest, ConstRefObjectFromConstRefStringIsObject)
  _add_test(IsTest, ConstRefObjectFormConstRefStringIsIComparable)
  _add_test(IsTest, ConstRefObjectFormConstRefStringIsInt32)
  _add_test(IsTest, ConstRefStringNullIsString)
  _add_test(IsTest, ConstRefStringNullIsObject)
  _add_test(IsTest, ConstRefStringNullIsIComparable)
  _add_test(IsTest, ConstRefStringNullIsInt32)
  _add_test(IsTest, ConstRefObjectFromConstRefStringNullIsString)
  _add_test(IsTest, ConstRefObjectFromConstRefStringNullIsObject)
  _add_test(IsTest, ConstRefObjectFormConstRefStringNullIsIComparable)
  _add_test(IsTest, ConstRefObjectFormConstRefStringNullIsInt32)
}
