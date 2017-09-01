#include <Switch/Any.hpp>
#include <Switch/As.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class AsTest : public TestFixture {
  protected:
    void StringAsString() {
      string s = "Test";
      string& r = as<string>(s);
      Assert::AreEqual(&s, &r, _current_information);
    }
    
    void StringAsObject() {
      string s = "Test";
      object& r = as<object>(s);
      Assert::AreEqual(&s, &r, _current_information);
    }
    
    void StringAsIComparable() {
      string s = "Test";
      IComparable& r = as<IComparable>(s);
      Assert::AreEqual(&s, &r, _current_information);
    }
    
    void StringAsInt32() {
      string s = "Test";
      Assert::Throws<InvalidCastException>(_delegate {as<Int32>(s);}, _current_information);
    }
    
    void ObjectFromStringAsString() {
      string s = "Test";
      object& o = s;
      string& r = as<string>(o);
      Assert::AreEqual(&s, &r, _current_information);
    }
    
    void ObjectFromStringAsObject() {
      string s = "Test";
      object& o = s;
      object& r = as<object>(o);
      Assert::AreEqual(&s, &r, _current_information);
    }
    
    void ObjectFromStringAsIComparable() {
      string s = "Test";
      object& o = s;
      IComparable& r = as<IComparable>(o);
      Assert::AreEqual(&s, &r, _current_information);
    }
    
    void ObjectFromStringAsInt32() {
      string s = "Test";
      object& o = s;
      Assert::Throws<InvalidCastException>(_delegate {as<Int32>(o);}, _current_information);
    }
  
    void ConstStringAsString() {
      const string s = "Test";
      const string& r = as<string>(s);
      Assert::AreEqual(&s, &r, _current_information);
    }
    
    void ConstStringAsObject() {
      const string s = "Test";
      const object& r = as<object>(s);
      Assert::AreEqual(&s, &r, _current_information);
    }
    
    void ConstStringAsIComparable() {
      const string s = "Test";
      const IComparable& r = as<IComparable>(s);
      Assert::AreEqual(&s, &r, _current_information);
    }
    
    void ConstStringAsInt32() {
      const string s = "Test";
      Assert::Throws<InvalidCastException>(_delegate {as<Int32>(s);}, _current_information);
    }
    
    void ConstObjectFromStringAsString() {
      const string s = "Test";
      const object& o = s;
      const string& r = as<string>(o);
      Assert::AreEqual(&s, &r, _current_information);
    }
    
    void ConstObjectFromConstStringAsObject() {
      const string s = "Test";
      const object& o = s;
      const object& r = as<object>(o);
      Assert::AreEqual(&s, &r, _current_information);
    }
    
    void ConstObjectFromConstStringAsIComparable() {
      const string s = "Test";
      const object& o = s;
      const IComparable& r = as<IComparable>(o);
      Assert::AreEqual(&s, &r, _current_information);
    }
    
    void ConstObjectFromConstStringAsInt32() {
      const string s = "Test";
      const object& o = s;
      Assert::Throws<InvalidCastException>(_delegate {as<Int32>(o);}, _current_information);
    }
    
    void StringPtrAsString() {
      string str = "test";
      string* s = &str;
      string* r = as<string>(s);
      Assert::AreEqual(s, r, _current_information);
    }
    
    void StringPtrAsObject() {
      string str = "test";
      string* s = &str;
      object* r = as<object>(s);
      Assert::AreEqual(s, r, _current_information);
    }
    
    void StringPtrAsIComparable() {
      string str = "test";
      string* s = &str;
      IComparable* r = as<IComparable>(s);
      Assert::AreEqual(s, r, _current_information);
    }
    
    void StringPtrAsInt32() {
      string str = "test";
      string* s = &str;
      Assert::Throws<InvalidCastException>(_delegate {as<Int32>(s);}, _current_information);
    }
    
    void ObjectPtrFromStringPtrAsString() {
      string str = "test";
      string* s = &str;
      object* o = s;
      string* r = as<string>(o);
      Assert::AreEqual(s, r, _current_information);
    }
    
    void ObjectPtrFromStringPtrAsObject() {
      string str = "test";
      string* s = &str;
      object* o = s;
      object* r = as<object>(o);
      Assert::AreEqual(s, r, _current_information);
    }
    
    void ObjectPtrFromStringPtrAsIComparable() {
      string str = "test";
      string* s = &str;
      object* o = s;
      IComparable* r = as<IComparable>(o);
      Assert::AreEqual(s, r, _current_information);
    }
    
    void ObjectPtrFromStringPtrAsInt32() {
      string str = "test";
      string* s = &str;
      object* o = s;
      Assert::Throws<InvalidCastException>(_delegate {as<Int32>(o);}, _current_information);
    }
    
    void StringPtrNullAsString() {
      string* s = null;
      string* r = as<string>(s);
      Assert::IsNull(r, _current_information);
    }
    
    void StringPtrNullAsObject() {
      string* s = null;
      object* r = as<object>(s);
      Assert::IsNull(r, _current_information);
    }
    
    void StringPtrNullAsIComparable() {
      string* s = null;
      IComparable* r = as<IComparable>(s);
      Assert::IsNull(r, _current_information);
    }
    
    void StringPtrNullAsInt32() {
      string* s = null;
      IComparable* r = as<Int32>(s);
      Assert::IsNull(r, _current_information);
    }
    
    void ObjectPtrFromStringPtrNullAsString() {
      string* s = null;
      object* o = s;
      string* r = as<string>(o);
      Assert::IsNull(r, _current_information);
    }
    
    void ObjectPtrFromStringPtrNullAsObject() {
      string* s = null;
      object* o = s;
      object* r = as<object>(o);
      Assert::IsNull(r, _current_information);
    }
    
    void ObjectPtrFromStringPtrNullAsIComparable() {
      string* s = null;
      object* o = s;
      IComparable* r = as<IComparable>(o);
      Assert::IsNull(r, _current_information);
    }
    
    void ObjectPtrFromStringPtrNullAsInt32() {
      string* s = null;
      object* o = s;
      Int32* r = as<Int32>(o);
      Assert::IsNull(r, _current_information);
    }
    
    void ConstStringPtrAsString() {
      string str = "test";
      const string* s = &str;
      const string* r = as<string>(s);
      Assert::AreEqual(s, r, _current_information);
    }
    
    void ConstStringPtrAsObject() {
      string str = "test";
      const string* s = &str;
      const object* r = as<object>(s);
      Assert::AreEqual(s, r, _current_information);
    }
    
    void ConstStringPtrAsIComparable() {
      string str = "test";
      const string* s = &str;
      const IComparable* r = as<IComparable>(s);
      Assert::AreEqual(s, r, _current_information);
    }
    
    void ConstStringPtrAsInt32() {
      string str = "test";
      const string* s = &str;
      Assert::Throws<InvalidCastException>(_delegate {as<Int32>(s);}, _current_information);
    }
    
    void ConstObjectPtrFromStringPtrAsString() {
      string str = "test";
      const string* s = &str;
      const object* o = s;
      const string* r = as<string>(o);
      Assert::AreEqual(s, r, _current_information);
    }
    
    void ConstObjectPtrFromStringPtrAsObject() {
      string str = "test";
      const string* s = &str;
      const object* o = s;
      const object* r = as<object>(o);
      Assert::AreEqual(s, r, _current_information);
    }
    
    void ConstObjectPtrFromStringPtrAsIComparable() {
      string str = "test";
      const string* s = &str;
      const object* o = s;
      const IComparable* r = as<IComparable>(o);
      Assert::AreEqual(s, r, _current_information);
    }
    
    void ConstObjectPtrFromStringPtrAsInt32() {
      string str = "test";
      const string* s = &str;
      const object* o = s;
      Assert::Throws<InvalidCastException>(_delegate {as<Int32>(o);}, _current_information);
    }
    
    void ConstStringPtrNullAsString() {
      const string* s = null;
      const string* r = as<string>(s);
      Assert::IsNull(r, _current_information);
    }
    
    void ConstStringPtrNullAsObject() {
      const string* s = null;
      const object* r = as<object>(s);
      Assert::IsNull(r, _current_information);
    }
    
    void ConstStringPtrNullAsIComparable() {
      const string* s = null;
      const IComparable* r = as<IComparable>(s);
      Assert::IsNull(r, _current_information);
    }
    
    void ConstStringPtrNullAsInt32() {
      const string* s = null;
      const Int32* r = as<Int32>(s);
      Assert::IsNull(r, _current_information);
    }
    
    void ConstObjectPtrFromStringPtrNullAsString() {
      const string* s = null;
      const object* o = s;
      const string* r = as<string>(o);
      Assert::IsNull(r, _current_information);
    }
    
    void ConstObjectPtrFromStringPtrNullAsObject() {
      const string* s = null;
      const object* o = s;
      const object* r = as<object>(o);
      Assert::IsNull(r, _current_information);
    }
    
    void ConstObjectPtrFromStringPtrNullAsIComparable() {
      const string* s = null;
      const object* o = s;
      const IComparable* r = as<IComparable>(o);
      Assert::IsNull(r, _current_information);
    }
    
    void ConstObjectPtrFromStringPtrNullAsInt32() {
      const string* s = null;
      const object* o = s;
      const Int32* r = as<Int32>(o);
      Assert::IsNull(r, _current_information);
    }
    
    void SpStringAsString() {
      refptr<string> s = ref_new<string>("Test");
      refptr<string> r = as<string>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void SpStringAsObject() {
      refptr<string> s = ref_new<string>("Test");
      refptr<object> r = as<object>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void SpStringAsIComparable() {
      refptr<string> s = ref_new<string>("Test");
      refptr<IComparable> r = as<IComparable>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void SpStringAsInt32() {
      refptr<string> s = ref_new<string>("Test");
      refptr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void SpObjectFromStringAsString() {
      refptr<string> s = ref_new<string>("Test");
      refptr<object> o = as<object>(s);
      refptr<string> r = as<string>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void SpObjectFromStringAsObject() {
      refptr<string> s = ref_new<string>("Test");
      refptr<object> o = as<object>(s);
      refptr<object> r = as<object>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void SpObjectFromStringAsIComparable() {
      refptr<string> s = ref_new<string>("Test");
      refptr<object> o = as<object>(s);
      refptr<IComparable> r = as<IComparable>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void SpObjectFromStringAsInt32() {
      refptr<string> s = ref_new<string>("Test");
      refptr<object> o = as<object>(s);
      refptr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void SpStringNullAsString() {
      refptr<string> s = refptr<string>::Null();
      refptr<string> r = as<string>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void SpStringNullAsObject() {
      refptr<string> s = refptr<string>::Null();
      refptr<object> r = as<object>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void SpStringNullAsIComparable() {
      refptr<string> s = refptr<string>::Null();
      refptr<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void SpStringNullAsInt32() {
      refptr<string> s = refptr<string>::Null();
      refptr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void SpObjectFromStringNullAsString() {
      refptr<string> s = refptr<string>::Null();
      refptr<object> o = as<object>(s);
      refptr<string> r = as<string>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void SpObjectFromStringNullAsObject() {
      refptr<string> s = refptr<string>::Null();
      refptr<object> o = as<object>(s);
      refptr<object> r = as<object>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void SpObjectFromStringNullAsIComparable() {
      refptr<string> s = refptr<string>::Null();
      refptr<object> o = as<object>(s);
      refptr<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void SpObjectFromStringNullAsInt32() {
      refptr<string> s = refptr<string>::Null();
      refptr<object> o = as<object>(s);
      refptr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstSpStringAsString() {
      const refptr<string> s = ref_new<string>("Test");
      const refptr<string> r = as<string>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void ConstSpStringAsObject() {
      const refptr<string> s = ref_new<string>("Test");
      const refptr<object> r = as<object>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void ConstSpStringAsIComparable() {
      const refptr<string> s = ref_new<string>("Test");
      const refptr<IComparable> r = as<IComparable>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void ConstSpStringAsInt32() {
      const refptr<string> s = ref_new<string>("Test");
      const refptr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstSpObjectFromStringAsString() {
      const refptr<string> s = ref_new<string>("Test");
      const refptr<object> o = as<object>(s);
      const refptr<string> r = as<string>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void ConstSpObjectFromStringAsObject() {
      const refptr<string> s = ref_new<string>("Test");
      const refptr<object> o = as<object>(s);
      const refptr<object> r = as<object>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void ConstSpObjectFromStringAsIComparable() {
      const refptr<string> s = ref_new<string>("Test");
      const refptr<object> o = as<object>(s);
      const refptr<IComparable> r = as<IComparable>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void ConstSpObjectFromStringAsInt32() {
      const refptr<string> s = ref_new<string>("Test");
      const refptr<object> o = as<object>(s);
      const refptr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstSpStringNullAsString() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<string> r = as<string>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstSpStringNullAsObject() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<object> r = as<object>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstSpStringNullAsIComparable() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstSpStringNullAsInt32() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstSpObjectFromStringNullAsString() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<object> o = as<object>(s);
      const refptr<string> r = as<string>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstSpObjectFromStringNullAsObject() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<object> o = as<object>(s);
      const refptr<object> r = as<object>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstSpObjectFromStringNullAsIComparable() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<object> o = as<object>(s);
      const refptr<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstSpObjectFromStringNullAsInt32() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<object> o = as<object>(s);
      const refptr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void UpStringAsString() {
      UniquePtr<string> s = MakeUnique<string>("Test");
      UniquePtr<string> r = as<string>(s);
      Assert::AreEqual("Test", r->ToString(), _current_information);
    }
    
    void UpStringAsObject() {
      UniquePtr<string> s = MakeUnique<string>("Test");
      UniquePtr<object> r = as<object>(s);
      Assert::AreEqual("Test", r->ToString(), _current_information);
    }
    
    void UpStringAsIComparable() {
      UniquePtr<string> s = MakeUnique<string>("Test");
      UniquePtr<IComparable> r = as<IComparable>(s);
      Assert::AreEqual("Test", as<object>(r)->ToString(), _current_information);
    }
    
    void UpStringAsInt32() {
      UniquePtr<string> s = MakeUnique<string>("Test");
      UniquePtr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void UpObjectFromStringAsString() {
      UniquePtr<string> s = MakeUnique<string>("Test");
      UniquePtr<object> o = as<object>(s);
      UniquePtr<string> r = as<string>(o);
      Assert::AreEqual("Test", r->ToString(), _current_information);
    }
    
    void UpObjectFromStringAsObject() {
      UniquePtr<string> s = MakeUnique<string>("Test");
      UniquePtr<object> o = as<object>(s);
      UniquePtr<object> r = as<object>(o);
      Assert::AreEqual("Test", r->ToString(), _current_information);
    }
    
    void UpObjectFromStringAsIComparable() {
      UniquePtr<string> s = MakeUnique<string>("Test");
      UniquePtr<object> o = as<object>(s);
      UniquePtr<IComparable> r = as<IComparable>(o);
      Assert::AreEqual("Test", as<object>(r)->ToString(), _current_information);
    }
    
    void UpObjectFromStringAsInt32() {
      UniquePtr<string> s = MakeUnique<string>("Test");
      UniquePtr<object> o = as<object>(s);
      UniquePtr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void UpStringNullAsString() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<string> r = as<string>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void UpStringNullAsObject() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<object> r = as<object>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void UpStringNullAsIComparable() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void UpStringNullAsInt32() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void UpObjectFromStringNullAsString() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<object> o = as<object>(s);
      UniquePtr<string> r = as<string>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void UpObjectFromStringNullAsObject() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<object> o = as<object>(s);
      UniquePtr<object> r = as<object>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void UpObjectFromStringNullAsIComparable() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<object> o = as<object>(s);
      UniquePtr<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void UpObjectFromStringNullAsInt32() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<object> o = as<object>(s);
      UniquePtr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void RefStringAsString() {
      string str = "Test";
      ref<string> s = str;
      ref<string> r = as<string>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void RefStringAsObject() {
      string str = "Test";
      ref<string> s = str;
      ref<object> r = as<object>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void RefStringAsIComparable() {
      string str = "Test";
      ref<string> s = str;
      ref<IComparable> r = as<IComparable>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void RefStringAsInt32() {
      string str = "Test";
      ref<string> s = str;
      ref<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void RefObjectFromStringAsString() {
      string str = "Test";
      ref<string> s = str;
      ref<object> o = as<object>(s);
      ref<string> r = as<string>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void RefObjectFromStringAsObject() {
      string str = "Test";
      ref<string> s = str;
      ref<object> o = as<object>(s);
      ref<object> r = as<object>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void RefObjectFromStringAsIComparable() {
      string str = "Test";
      ref<string> s = str;
      ref<object> o = as<object>(s);
      ref<IComparable> r = as<IComparable>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void RefObjectFromStringAsInt32() {
      string str = "Test";
      ref<string> s = str;
      ref<object> o = as<object>(s);
      ref<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void RefStringNullAsString() {
      ref<string> s = ref<string>::Null();
      ref<string> r = as<string>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void RefStringNullAsObject() {
      ref<string> s = ref<string>::Null();
      ref<object> r = as<object>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void RefStringNullAsIComparable() {
      ref<string> s = ref<string>::Null();
      ref<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void RefStringNullAsInt32() {
      ref<string> s = ref<string>::Null();
      ref<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void RefObjectFromStringNullAsString() {
      ref<string> s = ref<string>::Null();
      ref<object> o = as<object>(s);
      ref<string> r = as<string>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void RefObjectFromStringNullAsObject() {
      ref<string> s = ref<string>::Null();
      ref<object> o = as<object>(s);
      ref<object> r = as<object>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void RefObjectFromStringNullAsIComparable() {
      ref<string> s = ref<string>::Null();
      ref<object> o = as<object>(s);
      ref<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void RefObjectFromStringNullAsInt32() {
      ref<string> s = ref<string>::Null();
      ref<object> o = as<object>(s);
      ref<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstRefStringAsString() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<string> r = as<string>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void ConstRefStringAsObject() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<object> r = as<object>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void ConstRefStringAsIComparable() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<IComparable> r = as<IComparable>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void ConstRefStringAsInt32() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstRefObjectFromStringAsString() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<object> o = as<object>(s);
      const ref<string> r = as<string>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void ConstRefObjectFromStringAsObject() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<object> o = as<object>(s);
      const ref<object> r = as<object>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void ConstRefObjectFromStringAsIComparable() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<object> o = as<object>(s);
      const ref<IComparable> r = as<IComparable>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _current_information);
    }
    
    void ConstRefObjectFromStringAsInt32() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<object> o = as<object>(s);
      const ref<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstRefStringNullAsString() {
      const ref<string> s = ref<string>::Null();
      const ref<string> r = as<string>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstRefStringNullAsObject() {
      const ref<string> s = ref<string>::Null();
      const ref<object> r = as<object>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstRefStringNullAsIComparable() {
      const ref<string> s = ref<string>::Null();
      const ref<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstRefStringNullAsInt32() {
      const ref<string> s = ref<string>::Null();
      const ref<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstRefObjectFromStringNullAsString() {
      const ref<string> s = ref<string>::Null();
      const ref<object> o = as<object>(s);
      const ref<string> r = as<string>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstRefObjectFromStringNullAsObject() {
      const ref<string> s = ref<string>::Null();
      const ref<object> o = as<object>(s);
      const ref<object> r = as<object>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstRefObjectFromStringNullAsIComparable() {
      const ref<string> s = ref<string>::Null();
      const ref<object> o = as<object>(s);
      const ref<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void ConstRefObjectFromStringNullAsInt32() {
      const ref<string> s = ref<string>::Null();
      const ref<object> o = as<object>(s);
      const ref<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), _current_information);
    }
    
    void AnyInt32ToInt32() {
      Any a = 42;
      int32 b = as<Int32>(a);
      Assert::AreEqual(42, b, _current_information);
    }
    
    void AnyInt32ToString() {
      Any a = 42;
      string b = a.ToString();
      Assert::AreEqual("42", b, _current_information);
    }
    
    void Int32DifferentOfZeroAsBool() {
      int32 a = 42;
      bool b = as<bool>(a);
      Assert::IsTrue(b, _current_information);
    }
    
    void Int32EqualsToZeroAsBool() {
      int32 a = 0;
      bool b = as<bool>(a);
      Assert::IsFalse(b, _current_information);
    }
    
    void Int32AsByte() {
      int32 a = 42;
      byte b = as<int32>(a);
      Assert::AreEqual(42, b, _current_information);
    }
    
    void Int32AsString() {
      int32 a = 42;
      string b = as<string>(a);
      Assert::AreEqual("42", b, _current_information);
    }
  };
 
  _test(AsTest, StringAsString)
  _test(AsTest, StringAsObject)
  _test(AsTest, StringAsIComparable)
  _test(AsTest, StringAsInt32)
  _test(AsTest, ObjectFromStringAsString)
  _test(AsTest, ObjectFromStringAsObject)
  _test(AsTest, ObjectFromStringAsIComparable)
  _test(AsTest, ObjectFromStringAsInt32)
  _test(AsTest, ConstStringAsString)
  _test(AsTest, ConstStringAsObject)
  _test(AsTest, ConstStringAsIComparable)
  _test(AsTest, ConstStringAsInt32)
  _test(AsTest, ConstObjectFromStringAsString)
  _test(AsTest, ConstObjectFromConstStringAsObject)
  _test(AsTest, ConstObjectFromConstStringAsIComparable)
  _test(AsTest, ConstObjectFromConstStringAsInt32)
  _test(AsTest, StringPtrAsString)
  _test(AsTest, StringPtrAsObject)
  _test(AsTest, StringPtrAsIComparable)
  _test(AsTest, StringPtrAsInt32)
  _test(AsTest, ObjectPtrFromStringPtrAsString)
  _test(AsTest, ObjectPtrFromStringPtrAsObject)
  _test(AsTest, ObjectPtrFromStringPtrAsIComparable)
  _test(AsTest, ObjectPtrFromStringPtrAsInt32)
  _test(AsTest, StringPtrNullAsString)
  _test(AsTest, StringPtrNullAsObject)
  _test(AsTest, StringPtrNullAsIComparable)
  _test(AsTest, StringPtrNullAsInt32)
  _test(AsTest, ObjectPtrFromStringPtrNullAsString)
  _test(AsTest, ObjectPtrFromStringPtrNullAsObject)
  _test(AsTest, ObjectPtrFromStringPtrNullAsIComparable)
  _test(AsTest, ObjectPtrFromStringPtrNullAsInt32)
  _test(AsTest, ConstStringPtrAsString)
  _test(AsTest, ConstStringPtrAsObject)
  _test(AsTest, ConstStringPtrAsIComparable)
  _test(AsTest, ConstStringPtrAsInt32)
  _test(AsTest, ConstObjectPtrFromStringPtrAsString)
  _test(AsTest, ConstObjectPtrFromStringPtrAsObject)
  _test(AsTest, ConstObjectPtrFromStringPtrAsIComparable)
  _test(AsTest, ConstObjectPtrFromStringPtrAsInt32)
  _test(AsTest, ConstStringPtrNullAsString)
  _test(AsTest, ConstStringPtrNullAsObject)
  _test(AsTest, ConstStringPtrNullAsIComparable)
  _test(AsTest, ConstStringPtrNullAsInt32)
  _test(AsTest, ConstObjectPtrFromStringPtrNullAsString)
  _test(AsTest, ConstObjectPtrFromStringPtrNullAsObject)
  _test(AsTest, ConstObjectPtrFromStringPtrNullAsIComparable)
  _test(AsTest, ConstObjectPtrFromStringPtrNullAsInt32)
  _test(AsTest, SpStringAsString)
  _test(AsTest, SpStringAsObject)
  _test(AsTest, SpStringAsIComparable)
  _test(AsTest, SpStringAsInt32)
  _test(AsTest, SpObjectFromStringAsString)
  _test(AsTest, SpObjectFromStringAsObject)
  _test(AsTest, SpObjectFromStringAsIComparable)
  _test(AsTest, SpObjectFromStringAsInt32)
  _test(AsTest, SpStringNullAsString)
  _test(AsTest, SpStringNullAsObject)
  _test(AsTest, SpStringNullAsIComparable)
  _test(AsTest, SpStringNullAsInt32)
  _test(AsTest, SpObjectFromStringNullAsString)
  _test(AsTest, SpObjectFromStringNullAsObject)
  _test(AsTest, SpObjectFromStringNullAsIComparable)
  _test(AsTest, SpObjectFromStringNullAsInt32)
  _test(AsTest, ConstSpStringAsString)
  _test(AsTest, ConstSpStringAsObject)
  _test(AsTest, ConstSpStringAsIComparable)
  _test(AsTest, ConstSpStringAsInt32)
  _test(AsTest, ConstSpObjectFromStringAsString)
  _test(AsTest, ConstSpObjectFromStringAsObject)
  _test(AsTest, ConstSpObjectFromStringAsIComparable)
  _test(AsTest, ConstSpObjectFromStringAsInt32)
  _test(AsTest, ConstSpStringNullAsString)
  _test(AsTest, ConstSpStringNullAsObject)
  _test(AsTest, ConstSpStringNullAsIComparable)
  _test(AsTest, ConstSpStringNullAsInt32)
  _test(AsTest, ConstSpObjectFromStringNullAsString)
  _test(AsTest, ConstSpObjectFromStringNullAsObject)
  _test(AsTest, ConstSpObjectFromStringNullAsIComparable)
  _test(AsTest, ConstSpObjectFromStringNullAsInt32)
  _test(AsTest, UpStringAsString)
  _test(AsTest, UpStringAsObject)
  _test(AsTest, UpStringAsIComparable)
  _test(AsTest, UpStringAsInt32)
  _test(AsTest, UpObjectFromStringAsString)
  _test(AsTest, UpObjectFromStringAsObject)
  _test(AsTest, UpObjectFromStringAsIComparable)
  _test(AsTest, UpObjectFromStringAsInt32)
  _test(AsTest, UpStringNullAsString)
  _test(AsTest, UpStringNullAsObject)
  _test(AsTest, UpStringNullAsIComparable)
  _test(AsTest, UpStringNullAsInt32)
  _test(AsTest, UpObjectFromStringNullAsString)
  _test(AsTest, UpObjectFromStringNullAsObject)
  _test(AsTest, UpObjectFromStringNullAsIComparable)
  _test(AsTest, UpObjectFromStringNullAsInt32)
  _test(AsTest, RefStringAsString)
  _test(AsTest, RefStringAsObject)
  _test(AsTest, RefStringAsIComparable)
  _test(AsTest, RefStringAsInt32)
  _test(AsTest, RefObjectFromStringAsString)
  _test(AsTest, RefObjectFromStringAsObject)
  _test(AsTest, RefObjectFromStringAsIComparable)
  _test(AsTest, RefObjectFromStringAsInt32)
  _test(AsTest, RefStringNullAsString)
  _test(AsTest, RefStringNullAsObject)
  _test(AsTest, RefStringNullAsIComparable)
  _test(AsTest, RefStringNullAsInt32)
  _test(AsTest, RefObjectFromStringNullAsString)
  _test(AsTest, RefObjectFromStringNullAsObject)
  _test(AsTest, RefObjectFromStringNullAsIComparable)
  _test(AsTest, RefObjectFromStringNullAsInt32)
  _test(AsTest, ConstRefStringAsString)
  _test(AsTest, ConstRefStringAsObject)
  _test(AsTest, ConstRefStringAsIComparable)
  _test(AsTest, ConstRefStringAsInt32)
  _test(AsTest, ConstRefObjectFromStringAsString)
  _test(AsTest, ConstRefObjectFromStringAsObject)
  _test(AsTest, ConstRefObjectFromStringAsIComparable)
  _test(AsTest, ConstRefObjectFromStringAsInt32)
  _test(AsTest, ConstRefStringNullAsString)
  _test(AsTest, ConstRefStringNullAsObject)
  _test(AsTest, ConstRefStringNullAsIComparable)
  _test(AsTest, ConstRefStringNullAsInt32)
  _test(AsTest, ConstRefObjectFromStringNullAsString)
  _test(AsTest, ConstRefObjectFromStringNullAsObject)
  _test(AsTest, ConstRefObjectFromStringNullAsIComparable)
  _test(AsTest, ConstRefObjectFromStringNullAsInt32)
  _test(AsTest, Int32DifferentOfZeroAsBool)
  _test(AsTest, AnyInt32ToInt32)
  _test(AsTest, AnyInt32ToString)
  _test(AsTest, Int32EqualsToZeroAsBool)
  _test(AsTest, Int32AsByte)
  _test(AsTest, Int32AsString)
}
