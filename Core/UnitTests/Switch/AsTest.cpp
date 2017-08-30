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
      Assert::AreEqual(&s, &r, sw_current_information);
    }
    
    void StringAsObject() {
      string s = "Test";
      object& r = as<object>(s);
      Assert::AreEqual(&s, &r, sw_current_information);
    }
    
    void StringAsIComparable() {
      string s = "Test";
      IComparable& r = as<IComparable>(s);
      Assert::AreEqual(&s, &r, sw_current_information);
    }
    
    void StringAsInt32() {
      string s = "Test";
      Assert::Throws<InvalidCastException>(sw_delegate {as<Int32>(s);}, sw_current_information);
    }
    
    void ObjectFromStringAsString() {
      string s = "Test";
      object& o = s;
      string& r = as<string>(o);
      Assert::AreEqual(&s, &r, sw_current_information);
    }
    
    void ObjectFromStringAsObject() {
      string s = "Test";
      object& o = s;
      object& r = as<object>(o);
      Assert::AreEqual(&s, &r, sw_current_information);
    }
    
    void ObjectFromStringAsIComparable() {
      string s = "Test";
      object& o = s;
      IComparable& r = as<IComparable>(o);
      Assert::AreEqual(&s, &r, sw_current_information);
    }
    
    void ObjectFromStringAsInt32() {
      string s = "Test";
      object& o = s;
      Assert::Throws<InvalidCastException>(sw_delegate {as<Int32>(o);}, sw_current_information);
    }
  
    void ConstStringAsString() {
      const string s = "Test";
      const string& r = as<string>(s);
      Assert::AreEqual(&s, &r, sw_current_information);
    }
    
    void ConstStringAsObject() {
      const string s = "Test";
      const object& r = as<object>(s);
      Assert::AreEqual(&s, &r, sw_current_information);
    }
    
    void ConstStringAsIComparable() {
      const string s = "Test";
      const IComparable& r = as<IComparable>(s);
      Assert::AreEqual(&s, &r, sw_current_information);
    }
    
    void ConstStringAsInt32() {
      const string s = "Test";
      Assert::Throws<InvalidCastException>(sw_delegate {as<Int32>(s);}, sw_current_information);
    }
    
    void ConstObjectFromStringAsString() {
      const string s = "Test";
      const object& o = s;
      const string& r = as<string>(o);
      Assert::AreEqual(&s, &r, sw_current_information);
    }
    
    void ConstObjectFromConstStringAsObject() {
      const string s = "Test";
      const object& o = s;
      const object& r = as<object>(o);
      Assert::AreEqual(&s, &r, sw_current_information);
    }
    
    void ConstObjectFromConstStringAsIComparable() {
      const string s = "Test";
      const object& o = s;
      const IComparable& r = as<IComparable>(o);
      Assert::AreEqual(&s, &r, sw_current_information);
    }
    
    void ConstObjectFromConstStringAsInt32() {
      const string s = "Test";
      const object& o = s;
      Assert::Throws<InvalidCastException>(sw_delegate {as<Int32>(o);}, sw_current_information);
    }
    
    void StringPtrAsString() {
      string str = "test";
      string* s = &str;
      string* r = as<string>(s);
      Assert::AreEqual(s, r, sw_current_information);
    }
    
    void StringPtrAsObject() {
      string str = "test";
      string* s = &str;
      object* r = as<object>(s);
      Assert::AreEqual(s, r, sw_current_information);
    }
    
    void StringPtrAsIComparable() {
      string str = "test";
      string* s = &str;
      IComparable* r = as<IComparable>(s);
      Assert::AreEqual(s, r, sw_current_information);
    }
    
    void StringPtrAsInt32() {
      string str = "test";
      string* s = &str;
      Assert::Throws<InvalidCastException>(sw_delegate {as<Int32>(s);}, sw_current_information);
    }
    
    void ObjectPtrFromStringPtrAsString() {
      string str = "test";
      string* s = &str;
      object* o = s;
      string* r = as<string>(o);
      Assert::AreEqual(s, r, sw_current_information);
    }
    
    void ObjectPtrFromStringPtrAsObject() {
      string str = "test";
      string* s = &str;
      object* o = s;
      object* r = as<object>(o);
      Assert::AreEqual(s, r, sw_current_information);
    }
    
    void ObjectPtrFromStringPtrAsIComparable() {
      string str = "test";
      string* s = &str;
      object* o = s;
      IComparable* r = as<IComparable>(o);
      Assert::AreEqual(s, r, sw_current_information);
    }
    
    void ObjectPtrFromStringPtrAsInt32() {
      string str = "test";
      string* s = &str;
      object* o = s;
      Assert::Throws<InvalidCastException>(sw_delegate {as<Int32>(o);}, sw_current_information);
    }
    
    void StringPtrNullAsString() {
      string* s = null;
      string* r = as<string>(s);
      Assert::IsNull(r, sw_current_information);
    }
    
    void StringPtrNullAsObject() {
      string* s = null;
      object* r = as<object>(s);
      Assert::IsNull(r, sw_current_information);
    }
    
    void StringPtrNullAsIComparable() {
      string* s = null;
      IComparable* r = as<IComparable>(s);
      Assert::IsNull(r, sw_current_information);
    }
    
    void StringPtrNullAsInt32() {
      string* s = null;
      IComparable* r = as<Int32>(s);
      Assert::IsNull(r, sw_current_information);
    }
    
    void ObjectPtrFromStringPtrNullAsString() {
      string* s = null;
      object* o = s;
      string* r = as<string>(o);
      Assert::IsNull(r, sw_current_information);
    }
    
    void ObjectPtrFromStringPtrNullAsObject() {
      string* s = null;
      object* o = s;
      object* r = as<object>(o);
      Assert::IsNull(r, sw_current_information);
    }
    
    void ObjectPtrFromStringPtrNullAsIComparable() {
      string* s = null;
      object* o = s;
      IComparable* r = as<IComparable>(o);
      Assert::IsNull(r, sw_current_information);
    }
    
    void ObjectPtrFromStringPtrNullAsInt32() {
      string* s = null;
      object* o = s;
      Int32* r = as<Int32>(o);
      Assert::IsNull(r, sw_current_information);
    }
    
    void ConstStringPtrAsString() {
      string str = "test";
      const string* s = &str;
      const string* r = as<string>(s);
      Assert::AreEqual(s, r, sw_current_information);
    }
    
    void ConstStringPtrAsObject() {
      string str = "test";
      const string* s = &str;
      const object* r = as<object>(s);
      Assert::AreEqual(s, r, sw_current_information);
    }
    
    void ConstStringPtrAsIComparable() {
      string str = "test";
      const string* s = &str;
      const IComparable* r = as<IComparable>(s);
      Assert::AreEqual(s, r, sw_current_information);
    }
    
    void ConstStringPtrAsInt32() {
      string str = "test";
      const string* s = &str;
      Assert::Throws<InvalidCastException>(sw_delegate {as<Int32>(s);}, sw_current_information);
    }
    
    void ConstObjectPtrFromStringPtrAsString() {
      string str = "test";
      const string* s = &str;
      const object* o = s;
      const string* r = as<string>(o);
      Assert::AreEqual(s, r, sw_current_information);
    }
    
    void ConstObjectPtrFromStringPtrAsObject() {
      string str = "test";
      const string* s = &str;
      const object* o = s;
      const object* r = as<object>(o);
      Assert::AreEqual(s, r, sw_current_information);
    }
    
    void ConstObjectPtrFromStringPtrAsIComparable() {
      string str = "test";
      const string* s = &str;
      const object* o = s;
      const IComparable* r = as<IComparable>(o);
      Assert::AreEqual(s, r, sw_current_information);
    }
    
    void ConstObjectPtrFromStringPtrAsInt32() {
      string str = "test";
      const string* s = &str;
      const object* o = s;
      Assert::Throws<InvalidCastException>(sw_delegate {as<Int32>(o);}, sw_current_information);
    }
    
    void ConstStringPtrNullAsString() {
      const string* s = null;
      const string* r = as<string>(s);
      Assert::IsNull(r, sw_current_information);
    }
    
    void ConstStringPtrNullAsObject() {
      const string* s = null;
      const object* r = as<object>(s);
      Assert::IsNull(r, sw_current_information);
    }
    
    void ConstStringPtrNullAsIComparable() {
      const string* s = null;
      const IComparable* r = as<IComparable>(s);
      Assert::IsNull(r, sw_current_information);
    }
    
    void ConstStringPtrNullAsInt32() {
      const string* s = null;
      const Int32* r = as<Int32>(s);
      Assert::IsNull(r, sw_current_information);
    }
    
    void ConstObjectPtrFromStringPtrNullAsString() {
      const string* s = null;
      const object* o = s;
      const string* r = as<string>(o);
      Assert::IsNull(r, sw_current_information);
    }
    
    void ConstObjectPtrFromStringPtrNullAsObject() {
      const string* s = null;
      const object* o = s;
      const object* r = as<object>(o);
      Assert::IsNull(r, sw_current_information);
    }
    
    void ConstObjectPtrFromStringPtrNullAsIComparable() {
      const string* s = null;
      const object* o = s;
      const IComparable* r = as<IComparable>(o);
      Assert::IsNull(r, sw_current_information);
    }
    
    void ConstObjectPtrFromStringPtrNullAsInt32() {
      const string* s = null;
      const object* o = s;
      const Int32* r = as<Int32>(o);
      Assert::IsNull(r, sw_current_information);
    }
    
    void SpStringAsString() {
      refptr<string> s = sw_new<string>("Test");
      refptr<string> r = as<string>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void SpStringAsObject() {
      refptr<string> s = sw_new<string>("Test");
      refptr<object> r = as<object>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void SpStringAsIComparable() {
      refptr<string> s = sw_new<string>("Test");
      refptr<IComparable> r = as<IComparable>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void SpStringAsInt32() {
      refptr<string> s = sw_new<string>("Test");
      refptr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void SpObjectFromStringAsString() {
      refptr<string> s = sw_new<string>("Test");
      refptr<object> o = as<object>(s);
      refptr<string> r = as<string>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void SpObjectFromStringAsObject() {
      refptr<string> s = sw_new<string>("Test");
      refptr<object> o = as<object>(s);
      refptr<object> r = as<object>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void SpObjectFromStringAsIComparable() {
      refptr<string> s = sw_new<string>("Test");
      refptr<object> o = as<object>(s);
      refptr<IComparable> r = as<IComparable>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void SpObjectFromStringAsInt32() {
      refptr<string> s = sw_new<string>("Test");
      refptr<object> o = as<object>(s);
      refptr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void SpStringNullAsString() {
      refptr<string> s = refptr<string>::Null();
      refptr<string> r = as<string>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void SpStringNullAsObject() {
      refptr<string> s = refptr<string>::Null();
      refptr<object> r = as<object>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void SpStringNullAsIComparable() {
      refptr<string> s = refptr<string>::Null();
      refptr<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void SpStringNullAsInt32() {
      refptr<string> s = refptr<string>::Null();
      refptr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void SpObjectFromStringNullAsString() {
      refptr<string> s = refptr<string>::Null();
      refptr<object> o = as<object>(s);
      refptr<string> r = as<string>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void SpObjectFromStringNullAsObject() {
      refptr<string> s = refptr<string>::Null();
      refptr<object> o = as<object>(s);
      refptr<object> r = as<object>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void SpObjectFromStringNullAsIComparable() {
      refptr<string> s = refptr<string>::Null();
      refptr<object> o = as<object>(s);
      refptr<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void SpObjectFromStringNullAsInt32() {
      refptr<string> s = refptr<string>::Null();
      refptr<object> o = as<object>(s);
      refptr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstSpStringAsString() {
      const refptr<string> s = sw_new<string>("Test");
      const refptr<string> r = as<string>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void ConstSpStringAsObject() {
      const refptr<string> s = sw_new<string>("Test");
      const refptr<object> r = as<object>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void ConstSpStringAsIComparable() {
      const refptr<string> s = sw_new<string>("Test");
      const refptr<IComparable> r = as<IComparable>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void ConstSpStringAsInt32() {
      const refptr<string> s = sw_new<string>("Test");
      const refptr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstSpObjectFromStringAsString() {
      const refptr<string> s = sw_new<string>("Test");
      const refptr<object> o = as<object>(s);
      const refptr<string> r = as<string>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void ConstSpObjectFromStringAsObject() {
      const refptr<string> s = sw_new<string>("Test");
      const refptr<object> o = as<object>(s);
      const refptr<object> r = as<object>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void ConstSpObjectFromStringAsIComparable() {
      const refptr<string> s = sw_new<string>("Test");
      const refptr<object> o = as<object>(s);
      const refptr<IComparable> r = as<IComparable>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void ConstSpObjectFromStringAsInt32() {
      const refptr<string> s = sw_new<string>("Test");
      const refptr<object> o = as<object>(s);
      const refptr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstSpStringNullAsString() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<string> r = as<string>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstSpStringNullAsObject() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<object> r = as<object>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstSpStringNullAsIComparable() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstSpStringNullAsInt32() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstSpObjectFromStringNullAsString() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<object> o = as<object>(s);
      const refptr<string> r = as<string>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstSpObjectFromStringNullAsObject() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<object> o = as<object>(s);
      const refptr<object> r = as<object>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstSpObjectFromStringNullAsIComparable() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<object> o = as<object>(s);
      const refptr<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstSpObjectFromStringNullAsInt32() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<object> o = as<object>(s);
      const refptr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void UpStringAsString() {
      UniquePtr<string> s = MakeUnique<string>("Test");
      UniquePtr<string> r = as<string>(s);
      Assert::AreEqual("Test", r->ToString(), sw_current_information);
    }
    
    void UpStringAsObject() {
      UniquePtr<string> s = MakeUnique<string>("Test");
      UniquePtr<object> r = as<object>(s);
      Assert::AreEqual("Test", r->ToString(), sw_current_information);
    }
    
    void UpStringAsIComparable() {
      UniquePtr<string> s = MakeUnique<string>("Test");
      UniquePtr<IComparable> r = as<IComparable>(s);
      Assert::AreEqual("Test", as<object>(r)->ToString(), sw_current_information);
    }
    
    void UpStringAsInt32() {
      UniquePtr<string> s = MakeUnique<string>("Test");
      UniquePtr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void UpObjectFromStringAsString() {
      UniquePtr<string> s = MakeUnique<string>("Test");
      UniquePtr<object> o = as<object>(s);
      UniquePtr<string> r = as<string>(o);
      Assert::AreEqual("Test", r->ToString(), sw_current_information);
    }
    
    void UpObjectFromStringAsObject() {
      UniquePtr<string> s = MakeUnique<string>("Test");
      UniquePtr<object> o = as<object>(s);
      UniquePtr<object> r = as<object>(o);
      Assert::AreEqual("Test", r->ToString(), sw_current_information);
    }
    
    void UpObjectFromStringAsIComparable() {
      UniquePtr<string> s = MakeUnique<string>("Test");
      UniquePtr<object> o = as<object>(s);
      UniquePtr<IComparable> r = as<IComparable>(o);
      Assert::AreEqual("Test", as<object>(r)->ToString(), sw_current_information);
    }
    
    void UpObjectFromStringAsInt32() {
      UniquePtr<string> s = MakeUnique<string>("Test");
      UniquePtr<object> o = as<object>(s);
      UniquePtr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void UpStringNullAsString() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<string> r = as<string>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void UpStringNullAsObject() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<object> r = as<object>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void UpStringNullAsIComparable() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void UpStringNullAsInt32() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void UpObjectFromStringNullAsString() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<object> o = as<object>(s);
      UniquePtr<string> r = as<string>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void UpObjectFromStringNullAsObject() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<object> o = as<object>(s);
      UniquePtr<object> r = as<object>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void UpObjectFromStringNullAsIComparable() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<object> o = as<object>(s);
      UniquePtr<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void UpObjectFromStringNullAsInt32() {
      UniquePtr<string> s = UniquePtr<string>::Null();
      UniquePtr<object> o = as<object>(s);
      UniquePtr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void RefStringAsString() {
      string str = "Test";
      ref<string> s = str;
      ref<string> r = as<string>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void RefStringAsObject() {
      string str = "Test";
      ref<string> s = str;
      ref<object> r = as<object>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void RefStringAsIComparable() {
      string str = "Test";
      ref<string> s = str;
      ref<IComparable> r = as<IComparable>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void RefStringAsInt32() {
      string str = "Test";
      ref<string> s = str;
      ref<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void RefObjectFromStringAsString() {
      string str = "Test";
      ref<string> s = str;
      ref<object> o = as<object>(s);
      ref<string> r = as<string>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void RefObjectFromStringAsObject() {
      string str = "Test";
      ref<string> s = str;
      ref<object> o = as<object>(s);
      ref<object> r = as<object>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void RefObjectFromStringAsIComparable() {
      string str = "Test";
      ref<string> s = str;
      ref<object> o = as<object>(s);
      ref<IComparable> r = as<IComparable>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void RefObjectFromStringAsInt32() {
      string str = "Test";
      ref<string> s = str;
      ref<object> o = as<object>(s);
      ref<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void RefStringNullAsString() {
      ref<string> s = ref<string>::Null();
      ref<string> r = as<string>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void RefStringNullAsObject() {
      ref<string> s = ref<string>::Null();
      ref<object> r = as<object>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void RefStringNullAsIComparable() {
      ref<string> s = ref<string>::Null();
      ref<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void RefStringNullAsInt32() {
      ref<string> s = ref<string>::Null();
      ref<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void RefObjectFromStringNullAsString() {
      ref<string> s = ref<string>::Null();
      ref<object> o = as<object>(s);
      ref<string> r = as<string>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void RefObjectFromStringNullAsObject() {
      ref<string> s = ref<string>::Null();
      ref<object> o = as<object>(s);
      ref<object> r = as<object>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void RefObjectFromStringNullAsIComparable() {
      ref<string> s = ref<string>::Null();
      ref<object> o = as<object>(s);
      ref<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void RefObjectFromStringNullAsInt32() {
      ref<string> s = ref<string>::Null();
      ref<object> o = as<object>(s);
      ref<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstRefStringAsString() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<string> r = as<string>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void ConstRefStringAsObject() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<object> r = as<object>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void ConstRefStringAsIComparable() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<IComparable> r = as<IComparable>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void ConstRefStringAsInt32() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstRefObjectFromStringAsString() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<object> o = as<object>(s);
      const ref<string> r = as<string>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void ConstRefObjectFromStringAsObject() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<object> o = as<object>(s);
      const ref<object> r = as<object>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void ConstRefObjectFromStringAsIComparable() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<object> o = as<object>(s);
      const ref<IComparable> r = as<IComparable>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), sw_current_information);
    }
    
    void ConstRefObjectFromStringAsInt32() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<object> o = as<object>(s);
      const ref<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstRefStringNullAsString() {
      const ref<string> s = ref<string>::Null();
      const ref<string> r = as<string>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstRefStringNullAsObject() {
      const ref<string> s = ref<string>::Null();
      const ref<object> r = as<object>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstRefStringNullAsIComparable() {
      const ref<string> s = ref<string>::Null();
      const ref<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstRefStringNullAsInt32() {
      const ref<string> s = ref<string>::Null();
      const ref<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstRefObjectFromStringNullAsString() {
      const ref<string> s = ref<string>::Null();
      const ref<object> o = as<object>(s);
      const ref<string> r = as<string>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstRefObjectFromStringNullAsObject() {
      const ref<string> s = ref<string>::Null();
      const ref<object> o = as<object>(s);
      const ref<object> r = as<object>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstRefObjectFromStringNullAsIComparable() {
      const ref<string> s = ref<string>::Null();
      const ref<object> o = as<object>(s);
      const ref<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void ConstRefObjectFromStringNullAsInt32() {
      const ref<string> s = ref<string>::Null();
      const ref<object> o = as<object>(s);
      const ref<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), sw_current_information);
    }
    
    void AnyInt32ToInt32() {
      Any a = 42;
      int32 b = as<Int32>(a);
      Assert::AreEqual(42, b, sw_current_information);
    }
    
    void AnyInt32ToString() {
      Any a = 42;
      string b = a.ToString();
      Assert::AreEqual("42", b, sw_current_information);
    }
    
    void Int32DifferentOfZeroAsBool() {
      int32 a = 42;
      bool b = as<bool>(a);
      Assert::IsTrue(b, sw_current_information);
    }
    
    void Int32EqualsToZeroAsBool() {
      int32 a = 0;
      bool b = as<bool>(a);
      Assert::IsFalse(b, sw_current_information);
    }
    
    void Int32AsByte() {
      int32 a = 42;
      byte b = as<int32>(a);
      Assert::AreEqual(42, b, sw_current_information);
    }
    
    void Int32AsString() {
      int32 a = 42;
      string b = as<string>(a);
      Assert::AreEqual("42", b, sw_current_information);
    }
  };
 
  sw_test(AsTest, StringAsString)
  sw_test(AsTest, StringAsObject)
  sw_test(AsTest, StringAsIComparable)
  sw_test(AsTest, StringAsInt32)
  sw_test(AsTest, ObjectFromStringAsString)
  sw_test(AsTest, ObjectFromStringAsObject)
  sw_test(AsTest, ObjectFromStringAsIComparable)
  sw_test(AsTest, ObjectFromStringAsInt32)
  sw_test(AsTest, ConstStringAsString)
  sw_test(AsTest, ConstStringAsObject)
  sw_test(AsTest, ConstStringAsIComparable)
  sw_test(AsTest, ConstStringAsInt32)
  sw_test(AsTest, ConstObjectFromStringAsString)
  sw_test(AsTest, ConstObjectFromConstStringAsObject)
  sw_test(AsTest, ConstObjectFromConstStringAsIComparable)
  sw_test(AsTest, ConstObjectFromConstStringAsInt32)
  sw_test(AsTest, StringPtrAsString)
  sw_test(AsTest, StringPtrAsObject)
  sw_test(AsTest, StringPtrAsIComparable)
  sw_test(AsTest, StringPtrAsInt32)
  sw_test(AsTest, ObjectPtrFromStringPtrAsString)
  sw_test(AsTest, ObjectPtrFromStringPtrAsObject)
  sw_test(AsTest, ObjectPtrFromStringPtrAsIComparable)
  sw_test(AsTest, ObjectPtrFromStringPtrAsInt32)
  sw_test(AsTest, StringPtrNullAsString)
  sw_test(AsTest, StringPtrNullAsObject)
  sw_test(AsTest, StringPtrNullAsIComparable)
  sw_test(AsTest, StringPtrNullAsInt32)
  sw_test(AsTest, ObjectPtrFromStringPtrNullAsString)
  sw_test(AsTest, ObjectPtrFromStringPtrNullAsObject)
  sw_test(AsTest, ObjectPtrFromStringPtrNullAsIComparable)
  sw_test(AsTest, ObjectPtrFromStringPtrNullAsInt32)
  sw_test(AsTest, ConstStringPtrAsString)
  sw_test(AsTest, ConstStringPtrAsObject)
  sw_test(AsTest, ConstStringPtrAsIComparable)
  sw_test(AsTest, ConstStringPtrAsInt32)
  sw_test(AsTest, ConstObjectPtrFromStringPtrAsString)
  sw_test(AsTest, ConstObjectPtrFromStringPtrAsObject)
  sw_test(AsTest, ConstObjectPtrFromStringPtrAsIComparable)
  sw_test(AsTest, ConstObjectPtrFromStringPtrAsInt32)
  sw_test(AsTest, ConstStringPtrNullAsString)
  sw_test(AsTest, ConstStringPtrNullAsObject)
  sw_test(AsTest, ConstStringPtrNullAsIComparable)
  sw_test(AsTest, ConstStringPtrNullAsInt32)
  sw_test(AsTest, ConstObjectPtrFromStringPtrNullAsString)
  sw_test(AsTest, ConstObjectPtrFromStringPtrNullAsObject)
  sw_test(AsTest, ConstObjectPtrFromStringPtrNullAsIComparable)
  sw_test(AsTest, ConstObjectPtrFromStringPtrNullAsInt32)
  sw_test(AsTest, SpStringAsString)
  sw_test(AsTest, SpStringAsObject)
  sw_test(AsTest, SpStringAsIComparable)
  sw_test(AsTest, SpStringAsInt32)
  sw_test(AsTest, SpObjectFromStringAsString)
  sw_test(AsTest, SpObjectFromStringAsObject)
  sw_test(AsTest, SpObjectFromStringAsIComparable)
  sw_test(AsTest, SpObjectFromStringAsInt32)
  sw_test(AsTest, SpStringNullAsString)
  sw_test(AsTest, SpStringNullAsObject)
  sw_test(AsTest, SpStringNullAsIComparable)
  sw_test(AsTest, SpStringNullAsInt32)
  sw_test(AsTest, SpObjectFromStringNullAsString)
  sw_test(AsTest, SpObjectFromStringNullAsObject)
  sw_test(AsTest, SpObjectFromStringNullAsIComparable)
  sw_test(AsTest, SpObjectFromStringNullAsInt32)
  sw_test(AsTest, ConstSpStringAsString)
  sw_test(AsTest, ConstSpStringAsObject)
  sw_test(AsTest, ConstSpStringAsIComparable)
  sw_test(AsTest, ConstSpStringAsInt32)
  sw_test(AsTest, ConstSpObjectFromStringAsString)
  sw_test(AsTest, ConstSpObjectFromStringAsObject)
  sw_test(AsTest, ConstSpObjectFromStringAsIComparable)
  sw_test(AsTest, ConstSpObjectFromStringAsInt32)
  sw_test(AsTest, ConstSpStringNullAsString)
  sw_test(AsTest, ConstSpStringNullAsObject)
  sw_test(AsTest, ConstSpStringNullAsIComparable)
  sw_test(AsTest, ConstSpStringNullAsInt32)
  sw_test(AsTest, ConstSpObjectFromStringNullAsString)
  sw_test(AsTest, ConstSpObjectFromStringNullAsObject)
  sw_test(AsTest, ConstSpObjectFromStringNullAsIComparable)
  sw_test(AsTest, ConstSpObjectFromStringNullAsInt32)
  sw_test(AsTest, UpStringAsString)
  sw_test(AsTest, UpStringAsObject)
  sw_test(AsTest, UpStringAsIComparable)
  sw_test(AsTest, UpStringAsInt32)
  sw_test(AsTest, UpObjectFromStringAsString)
  sw_test(AsTest, UpObjectFromStringAsObject)
  sw_test(AsTest, UpObjectFromStringAsIComparable)
  sw_test(AsTest, UpObjectFromStringAsInt32)
  sw_test(AsTest, UpStringNullAsString)
  sw_test(AsTest, UpStringNullAsObject)
  sw_test(AsTest, UpStringNullAsIComparable)
  sw_test(AsTest, UpStringNullAsInt32)
  sw_test(AsTest, UpObjectFromStringNullAsString)
  sw_test(AsTest, UpObjectFromStringNullAsObject)
  sw_test(AsTest, UpObjectFromStringNullAsIComparable)
  sw_test(AsTest, UpObjectFromStringNullAsInt32)
  sw_test(AsTest, RefStringAsString)
  sw_test(AsTest, RefStringAsObject)
  sw_test(AsTest, RefStringAsIComparable)
  sw_test(AsTest, RefStringAsInt32)
  sw_test(AsTest, RefObjectFromStringAsString)
  sw_test(AsTest, RefObjectFromStringAsObject)
  sw_test(AsTest, RefObjectFromStringAsIComparable)
  sw_test(AsTest, RefObjectFromStringAsInt32)
  sw_test(AsTest, RefStringNullAsString)
  sw_test(AsTest, RefStringNullAsObject)
  sw_test(AsTest, RefStringNullAsIComparable)
  sw_test(AsTest, RefStringNullAsInt32)
  sw_test(AsTest, RefObjectFromStringNullAsString)
  sw_test(AsTest, RefObjectFromStringNullAsObject)
  sw_test(AsTest, RefObjectFromStringNullAsIComparable)
  sw_test(AsTest, RefObjectFromStringNullAsInt32)
  sw_test(AsTest, ConstRefStringAsString)
  sw_test(AsTest, ConstRefStringAsObject)
  sw_test(AsTest, ConstRefStringAsIComparable)
  sw_test(AsTest, ConstRefStringAsInt32)
  sw_test(AsTest, ConstRefObjectFromStringAsString)
  sw_test(AsTest, ConstRefObjectFromStringAsObject)
  sw_test(AsTest, ConstRefObjectFromStringAsIComparable)
  sw_test(AsTest, ConstRefObjectFromStringAsInt32)
  sw_test(AsTest, ConstRefStringNullAsString)
  sw_test(AsTest, ConstRefStringNullAsObject)
  sw_test(AsTest, ConstRefStringNullAsIComparable)
  sw_test(AsTest, ConstRefStringNullAsInt32)
  sw_test(AsTest, ConstRefObjectFromStringNullAsString)
  sw_test(AsTest, ConstRefObjectFromStringNullAsObject)
  sw_test(AsTest, ConstRefObjectFromStringNullAsIComparable)
  sw_test(AsTest, ConstRefObjectFromStringNullAsInt32)
  sw_test(AsTest, Int32DifferentOfZeroAsBool)
  sw_test(AsTest, AnyInt32ToInt32)
  sw_test(AsTest, AnyInt32ToString)
  sw_test(AsTest, Int32EqualsToZeroAsBool)
  sw_test(AsTest, Int32AsByte)
  sw_test(AsTest, Int32AsString)
}
