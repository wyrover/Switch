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
  
  _AddTest(IsTest, StringIsString)
  _AddTest(IsTest, StringIsObject)
  _AddTest(IsTest, StringIsIComparable)
  _AddTest(IsTest, StringIsInt32)
  _AddTest(IsTest, ObjectFromStringIsString)
  _AddTest(IsTest, ObjectFromStringIsObject)
  _AddTest(IsTest, ObjectFormStringIsIComparable)
  _AddTest(IsTest, ObjectFormStringIsInt32)
  _AddTest(IsTest, ConstStringIsString)
  _AddTest(IsTest, ConstStringIsObject)
  _AddTest(IsTest, ConstStringIsIComparable)
  _AddTest(IsTest, ConstStringIsInt32)
  _AddTest(IsTest, ConstObjectFromStringIsString)
  _AddTest(IsTest, ConstObjectFromStringIsObject)
  _AddTest(IsTest, ConstObjectFormStringIsIComparable)
  _AddTest(IsTest, ConstObjectFormStringIsInt32)
  _AddTest(IsTest, StringPtrIsString)
  _AddTest(IsTest, StringPtrIsObject)
  _AddTest(IsTest, StringPtrIsIComparable)
  _AddTest(IsTest, StringPtrIsInt32)
  _AddTest(IsTest, ObjectPtrFromStringPtrIsString)
  _AddTest(IsTest, ObjectPtrFromStringPtrIsObject)
  _AddTest(IsTest, ObjectPtrFormStringPtrIsIComparable)
  _AddTest(IsTest, ObjectPtrFormStringPtrIsInt32)
  _AddTest(IsTest, StringPtrNullIsString)
  _AddTest(IsTest, StringPtrNullIsObject)
  _AddTest(IsTest, StringPtrNullIsIComparable)
  _AddTest(IsTest, StringPtrNullIsInt32)
  _AddTest(IsTest, ObjectPtrFromStringPtrNullIsString)
  _AddTest(IsTest, ObjectPtrFromStringPtrNullIsObject)
  _AddTest(IsTest, ObjectPtrFormStringPtrNullIsIComparable)
  _AddTest(IsTest, ObjectPtrFormStringPtrNullIsInt32)
  _AddTest(IsTest, ConstStringPtrIsString)
  _AddTest(IsTest, ConstStringPtrIsObject)
  _AddTest(IsTest, ConstStringPtrIsIComparable)
  _AddTest(IsTest, ConstStringPtrIsInt32)
  _AddTest(IsTest, ConstObjectPtrFromStringPtrIsString)
  _AddTest(IsTest, ConstObjectPtrFromStringPtrIsObject)
  _AddTest(IsTest, ConstObjectPtrFormStringPtrIsIComparable)
  _AddTest(IsTest, ConstObjectPtrFormStringPtrIsInt32)
  _AddTest(IsTest, ConstStringPtrNullIsString)
  _AddTest(IsTest, ConstStringPtrNullIsObject)
  _AddTest(IsTest, ConstStringPtrNullIsIComparable)
  _AddTest(IsTest, ConstStringPtrNullIsInt32)
  _AddTest(IsTest, ConstObjectPtrFromStringPtrNullIsString)
  _AddTest(IsTest, ConstObjectPtrFromStringPtrNullIsObject)
  _AddTest(IsTest, ConstObjectPtrFormStringPtrNullIsIComparable)
  _AddTest(IsTest, ConstObjectPtrFormStringPtrNullIsInt32)
  _AddTest(IsTest, SpStringIsString)
  _AddTest(IsTest, SpStringIsObject)
  _AddTest(IsTest, SpStringIsIComparable)
  _AddTest(IsTest, SpStringIsInt32)
  _AddTest(IsTest, SpObjectFromSpStringIsString)
  _AddTest(IsTest, SpObjectFromSpStringIsObject)
  _AddTest(IsTest, SpObjectFormSpStringIsIComparable)
  _AddTest(IsTest, SpObjectFormSpStringIsInt32)
  _AddTest(IsTest, SpStringNullIsString)
  _AddTest(IsTest, SpStringNullIsObject)
  _AddTest(IsTest, SpStringNullIsIComparable)
  _AddTest(IsTest, SpStringNullIsInt32)
  _AddTest(IsTest, SpObjectFromSpStringNullIsString)
  _AddTest(IsTest, SpObjectFromSpStringNullIsObject)
  _AddTest(IsTest, SpObjectFormSpStringNullIsIComparable)
  _AddTest(IsTest, SpObjectFormSpStringNullIsInt32)
  _AddTest(IsTest, ConstSpStringIsString)
  _AddTest(IsTest, ConstSpStringIsObject)
  _AddTest(IsTest, ConstSpStringIsIComparable)
  _AddTest(IsTest, ConstSpStringIsInt32)
  _AddTest(IsTest, ConstSpObjectFromConstSpStringIsString)
  _AddTest(IsTest, ConstSpObjectFromConstSpStringIsObject)
  _AddTest(IsTest, ConstSpObjectFormConstSpStringIsIComparable)
  _AddTest(IsTest, ConstSpObjectFormConstSpStringIsInt32)
  _AddTest(IsTest, ConstSpStringNullIsString)
  _AddTest(IsTest, ConstSpStringNullIsObject)
  _AddTest(IsTest, ConstSpStringNullIsIComparable)
  _AddTest(IsTest, ConstSpStringNullIsInt32)
  _AddTest(IsTest, ConstSpObjectFromConstSpStringNullIsString)
  _AddTest(IsTest, ConstSpObjectFromConstSpStringNullIsObject)
  _AddTest(IsTest, ConstSpObjectFormConstSpStringNullIsIComparable)
  _AddTest(IsTest, ConstSpObjectFormConstSpStringNullIsInt32)
  _AddTest(IsTest, RefStringIsString)
  _AddTest(IsTest, RefStringIsObject)
  _AddTest(IsTest, RefStringIsIComparable)
  _AddTest(IsTest, RefStringIsInt32)
  _AddTest(IsTest, RefObjectFromRefStringIsString)
  _AddTest(IsTest, RefObjectFromRefStringIsObject)
  _AddTest(IsTest, RefObjectFormRefStringIsIComparable)
  _AddTest(IsTest, RefObjectFormRefStringIsInt32)
  _AddTest(IsTest, RefStringNullIsString)
  _AddTest(IsTest, RefStringNullIsObject)
  _AddTest(IsTest, RefStringNullIsIComparable)
  _AddTest(IsTest, RefStringNullIsInt32)
  _AddTest(IsTest, RefObjectFromRefStringNullIsString)
  _AddTest(IsTest, RefObjectFromRefStringNullIsObject)
  _AddTest(IsTest, RefObjectFormRefStringNullIsIComparable)
  _AddTest(IsTest, RefObjectFormRefStringNullIsInt32)
  _AddTest(IsTest, ConstRefStringIsString)
  _AddTest(IsTest, ConstRefStringIsObject)
  _AddTest(IsTest, ConstRefStringIsIComparable)
  _AddTest(IsTest, ConstRefStringIsInt32)
  _AddTest(IsTest, ConstRefObjectFromConstRefStringIsString)
  _AddTest(IsTest, ConstRefObjectFromConstRefStringIsObject)
  _AddTest(IsTest, ConstRefObjectFormConstRefStringIsIComparable)
  _AddTest(IsTest, ConstRefObjectFormConstRefStringIsInt32)
  _AddTest(IsTest, ConstRefStringNullIsString)
  _AddTest(IsTest, ConstRefStringNullIsObject)
  _AddTest(IsTest, ConstRefStringNullIsIComparable)
  _AddTest(IsTest, ConstRefStringNullIsInt32)
  _AddTest(IsTest, ConstRefObjectFromConstRefStringNullIsString)
  _AddTest(IsTest, ConstRefObjectFromConstRefStringNullIsObject)
  _AddTest(IsTest, ConstRefObjectFormConstRefStringNullIsIComparable)
  _AddTest(IsTest, ConstRefObjectFormConstRefStringNullIsInt32)
}
