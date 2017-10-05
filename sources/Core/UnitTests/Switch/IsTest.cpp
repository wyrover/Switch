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
  
  _test(IsTest, StringIsString)
  _test(IsTest, StringIsObject)
  _test(IsTest, StringIsIComparable)
  _test(IsTest, StringIsInt32)
  _test(IsTest, ObjectFromStringIsString)
  _test(IsTest, ObjectFromStringIsObject)
  _test(IsTest, ObjectFormStringIsIComparable)
  _test(IsTest, ObjectFormStringIsInt32)
  _test(IsTest, ConstStringIsString)
  _test(IsTest, ConstStringIsObject)
  _test(IsTest, ConstStringIsIComparable)
  _test(IsTest, ConstStringIsInt32)
  _test(IsTest, ConstObjectFromStringIsString)
  _test(IsTest, ConstObjectFromStringIsObject)
  _test(IsTest, ConstObjectFormStringIsIComparable)
  _test(IsTest, ConstObjectFormStringIsInt32)
  _test(IsTest, StringPtrIsString)
  _test(IsTest, StringPtrIsObject)
  _test(IsTest, StringPtrIsIComparable)
  _test(IsTest, StringPtrIsInt32)
  _test(IsTest, ObjectPtrFromStringPtrIsString)
  _test(IsTest, ObjectPtrFromStringPtrIsObject)
  _test(IsTest, ObjectPtrFormStringPtrIsIComparable)
  _test(IsTest, ObjectPtrFormStringPtrIsInt32)
  _test(IsTest, StringPtrNullIsString)
  _test(IsTest, StringPtrNullIsObject)
  _test(IsTest, StringPtrNullIsIComparable)
  _test(IsTest, StringPtrNullIsInt32)
  _test(IsTest, ObjectPtrFromStringPtrNullIsString)
  _test(IsTest, ObjectPtrFromStringPtrNullIsObject)
  _test(IsTest, ObjectPtrFormStringPtrNullIsIComparable)
  _test(IsTest, ObjectPtrFormStringPtrNullIsInt32)
  _test(IsTest, ConstStringPtrIsString)
  _test(IsTest, ConstStringPtrIsObject)
  _test(IsTest, ConstStringPtrIsIComparable)
  _test(IsTest, ConstStringPtrIsInt32)
  _test(IsTest, ConstObjectPtrFromStringPtrIsString)
  _test(IsTest, ConstObjectPtrFromStringPtrIsObject)
  _test(IsTest, ConstObjectPtrFormStringPtrIsIComparable)
  _test(IsTest, ConstObjectPtrFormStringPtrIsInt32)
  _test(IsTest, ConstStringPtrNullIsString)
  _test(IsTest, ConstStringPtrNullIsObject)
  _test(IsTest, ConstStringPtrNullIsIComparable)
  _test(IsTest, ConstStringPtrNullIsInt32)
  _test(IsTest, ConstObjectPtrFromStringPtrNullIsString)
  _test(IsTest, ConstObjectPtrFromStringPtrNullIsObject)
  _test(IsTest, ConstObjectPtrFormStringPtrNullIsIComparable)
  _test(IsTest, ConstObjectPtrFormStringPtrNullIsInt32)
  _test(IsTest, SpStringIsString)
  _test(IsTest, SpStringIsObject)
  _test(IsTest, SpStringIsIComparable)
  _test(IsTest, SpStringIsInt32)
  _test(IsTest, SpObjectFromSpStringIsString)
  _test(IsTest, SpObjectFromSpStringIsObject)
  _test(IsTest, SpObjectFormSpStringIsIComparable)
  _test(IsTest, SpObjectFormSpStringIsInt32)
  _test(IsTest, SpStringNullIsString)
  _test(IsTest, SpStringNullIsObject)
  _test(IsTest, SpStringNullIsIComparable)
  _test(IsTest, SpStringNullIsInt32)
  _test(IsTest, SpObjectFromSpStringNullIsString)
  _test(IsTest, SpObjectFromSpStringNullIsObject)
  _test(IsTest, SpObjectFormSpStringNullIsIComparable)
  _test(IsTest, SpObjectFormSpStringNullIsInt32)
  _test(IsTest, ConstSpStringIsString)
  _test(IsTest, ConstSpStringIsObject)
  _test(IsTest, ConstSpStringIsIComparable)
  _test(IsTest, ConstSpStringIsInt32)
  _test(IsTest, ConstSpObjectFromConstSpStringIsString)
  _test(IsTest, ConstSpObjectFromConstSpStringIsObject)
  _test(IsTest, ConstSpObjectFormConstSpStringIsIComparable)
  _test(IsTest, ConstSpObjectFormConstSpStringIsInt32)
  _test(IsTest, ConstSpStringNullIsString)
  _test(IsTest, ConstSpStringNullIsObject)
  _test(IsTest, ConstSpStringNullIsIComparable)
  _test(IsTest, ConstSpStringNullIsInt32)
  _test(IsTest, ConstSpObjectFromConstSpStringNullIsString)
  _test(IsTest, ConstSpObjectFromConstSpStringNullIsObject)
  _test(IsTest, ConstSpObjectFormConstSpStringNullIsIComparable)
  _test(IsTest, ConstSpObjectFormConstSpStringNullIsInt32)
  _test(IsTest, RefStringIsString)
  _test(IsTest, RefStringIsObject)
  _test(IsTest, RefStringIsIComparable)
  _test(IsTest, RefStringIsInt32)
  _test(IsTest, RefObjectFromRefStringIsString)
  _test(IsTest, RefObjectFromRefStringIsObject)
  _test(IsTest, RefObjectFormRefStringIsIComparable)
  _test(IsTest, RefObjectFormRefStringIsInt32)
  _test(IsTest, RefStringNullIsString)
  _test(IsTest, RefStringNullIsObject)
  _test(IsTest, RefStringNullIsIComparable)
  _test(IsTest, RefStringNullIsInt32)
  _test(IsTest, RefObjectFromRefStringNullIsString)
  _test(IsTest, RefObjectFromRefStringNullIsObject)
  _test(IsTest, RefObjectFormRefStringNullIsIComparable)
  _test(IsTest, RefObjectFormRefStringNullIsInt32)
  _test(IsTest, ConstRefStringIsString)
  _test(IsTest, ConstRefStringIsObject)
  _test(IsTest, ConstRefStringIsIComparable)
  _test(IsTest, ConstRefStringIsInt32)
  _test(IsTest, ConstRefObjectFromConstRefStringIsString)
  _test(IsTest, ConstRefObjectFromConstRefStringIsObject)
  _test(IsTest, ConstRefObjectFormConstRefStringIsIComparable)
  _test(IsTest, ConstRefObjectFormConstRefStringIsInt32)
  _test(IsTest, ConstRefStringNullIsString)
  _test(IsTest, ConstRefStringNullIsObject)
  _test(IsTest, ConstRefStringNullIsIComparable)
  _test(IsTest, ConstRefStringNullIsInt32)
  _test(IsTest, ConstRefObjectFromConstRefStringNullIsString)
  _test(IsTest, ConstRefObjectFromConstRefStringNullIsObject)
  _test(IsTest, ConstRefObjectFormConstRefStringNullIsIComparable)
  _test(IsTest, ConstRefObjectFormConstRefStringNullIsInt32)
}
