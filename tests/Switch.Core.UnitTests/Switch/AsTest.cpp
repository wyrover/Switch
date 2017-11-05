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
      Assert::AreEqual(&s, &r, _caller);
    }
    
    void StringAsObject() {
      string s = "Test";
      object& r = as<object>(s);
      Assert::AreEqual(&s, &r, _caller);
    }
    
    void StringAsIComparable() {
      string s = "Test";
      IComparable& r = as<IComparable>(s);
      Assert::AreEqual(&s, &r, _caller);
    }
    
    void StringAsInt32() {
      string s = "Test";
      Assert::Throws<InvalidCastException>(_delegate {as<Int32>(s);}, _caller);
    }
    
    void ObjectFromStringAsString() {
      string s = "Test";
      object& o = s;
      string& r = as<string>(o);
      Assert::AreEqual(&s, &r, _caller);
    }
    
    void ObjectFromStringAsObject() {
      string s = "Test";
      object& o = s;
      object& r = as<object>(o);
      Assert::AreEqual(&s, &r, _caller);
    }
    
    void ObjectFromStringAsIComparable() {
      string s = "Test";
      object& o = s;
      IComparable& r = as<IComparable>(o);
      Assert::AreEqual(&s, &r, _caller);
    }
    
    void ObjectFromStringAsInt32() {
      string s = "Test";
      object& o = s;
      Assert::Throws<InvalidCastException>(_delegate {as<Int32>(o);}, _caller);
    }
  
    void ConstStringAsString() {
      const string s = "Test";
      const string& r = as<string>(s);
      Assert::AreEqual(&s, &r, _caller);
    }
    
    void ConstStringAsObject() {
      const string s = "Test";
      const object& r = as<object>(s);
      Assert::AreEqual(&s, &r, _caller);
    }
    
    void ConstStringAsIComparable() {
      const string s = "Test";
      const IComparable& r = as<IComparable>(s);
      Assert::AreEqual(&s, &r, _caller);
    }
    
    void ConstStringAsInt32() {
      const string s = "Test";
      Assert::Throws<InvalidCastException>(_delegate {as<Int32>(s);}, _caller);
    }
    
    void ConstObjectFromStringAsString() {
      const string s = "Test";
      const object& o = s;
      const string& r = as<string>(o);
      Assert::AreEqual(&s, &r, _caller);
    }
    
    void ConstObjectFromConstStringAsObject() {
      const string s = "Test";
      const object& o = s;
      const object& r = as<object>(o);
      Assert::AreEqual(&s, &r, _caller);
    }
    
    void ConstObjectFromConstStringAsIComparable() {
      const string s = "Test";
      const object& o = s;
      const IComparable& r = as<IComparable>(o);
      Assert::AreEqual(&s, &r, _caller);
    }
    
    void ConstObjectFromConstStringAsInt32() {
      const string s = "Test";
      const object& o = s;
      Assert::Throws<InvalidCastException>(_delegate {as<Int32>(o);}, _caller);
    }
    
    void StringPtrAsString() {
      string str = "test";
      string* s = &str;
      string* r = as<string>(s);
      Assert::AreEqual(s, r, _caller);
    }
    
    void StringPtrAsObject() {
      string str = "test";
      string* s = &str;
      object* r = as<object>(s);
      Assert::AreEqual(s, r, _caller);
    }
    
    void StringPtrAsIComparable() {
      string str = "test";
      string* s = &str;
      IComparable* r = as<IComparable>(s);
      Assert::AreEqual(s, r, _caller);
    }
    
    void StringPtrAsInt32() {
      string str = "test";
      string* s = &str;
      Assert::Throws<InvalidCastException>(_delegate {as<Int32>(s);}, _caller);
    }
    
    void ObjectPtrFromStringPtrAsString() {
      string str = "test";
      string* s = &str;
      object* o = s;
      string* r = as<string>(o);
      Assert::AreEqual(s, r, _caller);
    }
    
    void ObjectPtrFromStringPtrAsObject() {
      string str = "test";
      string* s = &str;
      object* o = s;
      object* r = as<object>(o);
      Assert::AreEqual(s, r, _caller);
    }
    
    void ObjectPtrFromStringPtrAsIComparable() {
      string str = "test";
      string* s = &str;
      object* o = s;
      IComparable* r = as<IComparable>(o);
      Assert::AreEqual(s, r, _caller);
    }
    
    void ObjectPtrFromStringPtrAsInt32() {
      string str = "test";
      string* s = &str;
      object* o = s;
      Assert::Throws<InvalidCastException>(_delegate {as<Int32>(o);}, _caller);
    }
    
    void StringPtrNullAsString() {
      string* s = null;
      string* r = as<string>(s);
      Assert::IsNull(r, _caller);
    }
    
    void StringPtrNullAsObject() {
      string* s = null;
      object* r = as<object>(s);
      Assert::IsNull(r, _caller);
    }
    
    void StringPtrNullAsIComparable() {
      string* s = null;
      IComparable* r = as<IComparable>(s);
      Assert::IsNull(r, _caller);
    }
    
    void StringPtrNullAsInt32() {
      string* s = null;
      IComparable* r = as<Int32>(s);
      Assert::IsNull(r, _caller);
    }
    
    void ObjectPtrFromStringPtrNullAsString() {
      string* s = null;
      object* o = s;
      string* r = as<string>(o);
      Assert::IsNull(r, _caller);
    }
    
    void ObjectPtrFromStringPtrNullAsObject() {
      string* s = null;
      object* o = s;
      object* r = as<object>(o);
      Assert::IsNull(r, _caller);
    }
    
    void ObjectPtrFromStringPtrNullAsIComparable() {
      string* s = null;
      object* o = s;
      IComparable* r = as<IComparable>(o);
      Assert::IsNull(r, _caller);
    }
    
    void ObjectPtrFromStringPtrNullAsInt32() {
      string* s = null;
      object* o = s;
      Int32* r = as<Int32>(o);
      Assert::IsNull(r, _caller);
    }
    
    void ConstStringPtrAsString() {
      string str = "test";
      const string* s = &str;
      const string* r = as<string>(s);
      Assert::AreEqual(s, r, _caller);
    }
    
    void ConstStringPtrAsObject() {
      string str = "test";
      const string* s = &str;
      const object* r = as<object>(s);
      Assert::AreEqual(s, r, _caller);
    }
    
    void ConstStringPtrAsIComparable() {
      string str = "test";
      const string* s = &str;
      const IComparable* r = as<IComparable>(s);
      Assert::AreEqual(s, r, _caller);
    }
    
    void ConstStringPtrAsInt32() {
      string str = "test";
      const string* s = &str;
      Assert::Throws<InvalidCastException>(_delegate {as<Int32>(s);}, _caller);
    }
    
    void ConstObjectPtrFromStringPtrAsString() {
      string str = "test";
      const string* s = &str;
      const object* o = s;
      const string* r = as<string>(o);
      Assert::AreEqual(s, r, _caller);
    }
    
    void ConstObjectPtrFromStringPtrAsObject() {
      string str = "test";
      const string* s = &str;
      const object* o = s;
      const object* r = as<object>(o);
      Assert::AreEqual(s, r, _caller);
    }
    
    void ConstObjectPtrFromStringPtrAsIComparable() {
      string str = "test";
      const string* s = &str;
      const object* o = s;
      const IComparable* r = as<IComparable>(o);
      Assert::AreEqual(s, r, _caller);
    }
    
    void ConstObjectPtrFromStringPtrAsInt32() {
      string str = "test";
      const string* s = &str;
      const object* o = s;
      Assert::Throws<InvalidCastException>(_delegate {as<Int32>(o);}, _caller);
    }
    
    void ConstStringPtrNullAsString() {
      const string* s = null;
      const string* r = as<string>(s);
      Assert::IsNull(r, _caller);
    }
    
    void ConstStringPtrNullAsObject() {
      const string* s = null;
      const object* r = as<object>(s);
      Assert::IsNull(r, _caller);
    }
    
    void ConstStringPtrNullAsIComparable() {
      const string* s = null;
      const IComparable* r = as<IComparable>(s);
      Assert::IsNull(r, _caller);
    }
    
    void ConstStringPtrNullAsInt32() {
      const string* s = null;
      const Int32* r = as<Int32>(s);
      Assert::IsNull(r, _caller);
    }
    
    void ConstObjectPtrFromStringPtrNullAsString() {
      const string* s = null;
      const object* o = s;
      const string* r = as<string>(o);
      Assert::IsNull(r, _caller);
    }
    
    void ConstObjectPtrFromStringPtrNullAsObject() {
      const string* s = null;
      const object* o = s;
      const object* r = as<object>(o);
      Assert::IsNull(r, _caller);
    }
    
    void ConstObjectPtrFromStringPtrNullAsIComparable() {
      const string* s = null;
      const object* o = s;
      const IComparable* r = as<IComparable>(o);
      Assert::IsNull(r, _caller);
    }
    
    void ConstObjectPtrFromStringPtrNullAsInt32() {
      const string* s = null;
      const object* o = s;
      const Int32* r = as<Int32>(o);
      Assert::IsNull(r, _caller);
    }
    
    void RefPtrStringAsString() {
      refptr<string> s = ref_new<string>("Test");
      refptr<string> r = as<string>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void RefPtrStringAsObject() {
      refptr<string> s = ref_new<string>("Test");
      refptr<object> r = as<object>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void RefPtrStringAsIComparable() {
      refptr<string> s = ref_new<string>("Test");
      refptr<IComparable> r = as<IComparable>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void RefPtrStringAsInt32() {
      refptr<string> s = ref_new<string>("Test");
      refptr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void RefPtrObjectFromStringAsString() {
      refptr<string> s = ref_new<string>("Test");
      refptr<object> o = as<object>(s);
      refptr<string> r = as<string>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void RefPtrObjectFromStringAsObject() {
      refptr<string> s = ref_new<string>("Test");
      refptr<object> o = as<object>(s);
      refptr<object> r = as<object>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void RefPtrObjectFromStringAsIComparable() {
      refptr<string> s = ref_new<string>("Test");
      refptr<object> o = as<object>(s);
      refptr<IComparable> r = as<IComparable>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void RefPtrObjectFromStringAsInt32() {
      refptr<string> s = ref_new<string>("Test");
      refptr<object> o = as<object>(s);
      refptr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void RefPtrStringNullAsString() {
      refptr<string> s = refptr<string>::Null();
      refptr<string> r = as<string>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void RefPtrStringNullAsObject() {
      refptr<string> s = refptr<string>::Null();
      refptr<object> r = as<object>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void RefPtrStringNullAsIComparable() {
      refptr<string> s = refptr<string>::Null();
      refptr<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void RefPtrStringNullAsInt32() {
      refptr<string> s = refptr<string>::Null();
      refptr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void RefPtrObjectFromStringNullAsString() {
      refptr<string> s = refptr<string>::Null();
      refptr<object> o = as<object>(s);
      refptr<string> r = as<string>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void RefPtrObjectFromStringNullAsObject() {
      refptr<string> s = refptr<string>::Null();
      refptr<object> o = as<object>(s);
      refptr<object> r = as<object>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void RefPtrObjectFromStringNullAsIComparable() {
      refptr<string> s = refptr<string>::Null();
      refptr<object> o = as<object>(s);
      refptr<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void RefPtrObjectFromStringNullAsInt32() {
      refptr<string> s = refptr<string>::Null();
      refptr<object> o = as<object>(s);
      refptr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstSpStringAsString() {
      const refptr<string> s = ref_new<string>("Test");
      const refptr<string> r = as<string>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void ConstSpStringAsObject() {
      const refptr<string> s = ref_new<string>("Test");
      const refptr<object> r = as<object>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void ConstSpStringAsIComparable() {
      const refptr<string> s = ref_new<string>("Test");
      const refptr<IComparable> r = as<IComparable>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void ConstSpStringAsInt32() {
      const refptr<string> s = ref_new<string>("Test");
      const refptr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstSpObjectFromStringAsString() {
      const refptr<string> s = ref_new<string>("Test");
      const refptr<object> o = as<object>(s);
      const refptr<string> r = as<string>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void ConstSpObjectFromStringAsObject() {
      const refptr<string> s = ref_new<string>("Test");
      const refptr<object> o = as<object>(s);
      const refptr<object> r = as<object>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void ConstSpObjectFromStringAsIComparable() {
      const refptr<string> s = ref_new<string>("Test");
      const refptr<object> o = as<object>(s);
      const refptr<IComparable> r = as<IComparable>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void ConstSpObjectFromStringAsInt32() {
      const refptr<string> s = ref_new<string>("Test");
      const refptr<object> o = as<object>(s);
      const refptr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstSpStringNullAsString() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<string> r = as<string>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstSpStringNullAsObject() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<object> r = as<object>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstSpStringNullAsIComparable() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstSpStringNullAsInt32() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstSpObjectFromStringNullAsString() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<object> o = as<object>(s);
      const refptr<string> r = as<string>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstSpObjectFromStringNullAsObject() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<object> o = as<object>(s);
      const refptr<object> r = as<object>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstSpObjectFromStringNullAsIComparable() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<object> o = as<object>(s);
      const refptr<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstSpObjectFromStringNullAsInt32() {
      const refptr<string> s = refptr<string>::Null();
      const refptr<object> o = as<object>(s);
      const refptr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r == null, _caller);
    }
        
    void RefStringAsString() {
      string str = "Test";
      ref<string> s = str;
      ref<string> r = as<string>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void RefStringAsObject() {
      string str = "Test";
      ref<string> s = str;
      ref<object> r = as<object>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void RefStringAsIComparable() {
      string str = "Test";
      ref<string> s = str;
      ref<IComparable> r = as<IComparable>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void RefStringAsInt32() {
      string str = "Test";
      ref<string> s = str;
      ref<Int32> r = as<Int32>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void RefObjectFromStringAsString() {
      string str = "Test";
      ref<string> s = str;
      ref<object> o = as<object>(s);
      ref<string> r = as<string>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void RefObjectFromStringAsObject() {
      string str = "Test";
      ref<string> s = str;
      ref<object> o = as<object>(s);
      ref<object> r = as<object>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void RefObjectFromStringAsIComparable() {
      string str = "Test";
      ref<string> s = str;
      ref<object> o = as<object>(s);
      ref<IComparable> r = as<IComparable>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void RefObjectFromStringAsInt32() {
      string str = "Test";
      ref<string> s = str;
      ref<object> o = as<object>(s);
      ref<Int32> r = as<Int32>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void RefStringNullAsString() {
      ref<string> s = ref<string>::Null();
      ref<string> r = as<string>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void RefStringNullAsObject() {
      ref<string> s = ref<string>::Null();
      ref<object> r = as<object>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void RefStringNullAsIComparable() {
      ref<string> s = ref<string>::Null();
      ref<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void RefStringNullAsInt32() {
      ref<string> s = ref<string>::Null();
      ref<Int32> r = as<Int32>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void RefObjectFromStringNullAsString() {
      ref<string> s = ref<string>::Null();
      ref<object> o = as<object>(s);
      ref<string> r = as<string>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void RefObjectFromStringNullAsObject() {
      ref<string> s = ref<string>::Null();
      ref<object> o = as<object>(s);
      ref<object> r = as<object>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void RefObjectFromStringNullAsIComparable() {
      ref<string> s = ref<string>::Null();
      ref<object> o = as<object>(s);
      ref<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void RefObjectFromStringNullAsInt32() {
      ref<string> s = ref<string>::Null();
      ref<object> o = as<object>(s);
      ref<Int32> r = as<Int32>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstRefStringAsString() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<string> r = as<string>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void ConstRefStringAsObject() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<object> r = as<object>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void ConstRefStringAsIComparable() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<IComparable> r = as<IComparable>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void ConstRefStringAsInt32() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<Int32> r = as<Int32>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstRefObjectFromStringAsString() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<object> o = as<object>(s);
      const ref<string> r = as<string>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void ConstRefObjectFromStringAsObject() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<object> o = as<object>(s);
      const ref<object> r = as<object>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void ConstRefObjectFromStringAsIComparable() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<object> o = as<object>(s);
      const ref<IComparable> r = as<IComparable>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), _caller);
    }
    
    void ConstRefObjectFromStringAsInt32() {
      const string str = "Test";
      const ref<string> s = str;
      const ref<object> o = as<object>(s);
      const ref<Int32> r = as<Int32>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstRefStringNullAsString() {
      const ref<string> s = ref<string>::Null();
      const ref<string> r = as<string>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstRefStringNullAsObject() {
      const ref<string> s = ref<string>::Null();
      const ref<object> r = as<object>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstRefStringNullAsIComparable() {
      const ref<string> s = ref<string>::Null();
      const ref<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstRefStringNullAsInt32() {
      const ref<string> s = ref<string>::Null();
      const ref<Int32> r = as<Int32>(s);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstRefObjectFromStringNullAsString() {
      const ref<string> s = ref<string>::Null();
      const ref<object> o = as<object>(s);
      const ref<string> r = as<string>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstRefObjectFromStringNullAsObject() {
      const ref<string> s = ref<string>::Null();
      const ref<object> o = as<object>(s);
      const ref<object> r = as<object>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstRefObjectFromStringNullAsIComparable() {
      const ref<string> s = ref<string>::Null();
      const ref<object> o = as<object>(s);
      const ref<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void ConstRefObjectFromStringNullAsInt32() {
      const ref<string> s = ref<string>::Null();
      const ref<object> o = as<object>(s);
      const ref<Int32> r = as<Int32>(o);
      Assert::IsTrue(r == null, _caller);
    }
    
    void AnyInt32ToInt32() {
      Any a = 42;
      int32 b = as<Int32>(a);
      Assert::AreEqual(42, b, _caller);
    }
    
    void AnyInt32ToString() {
      Any a = 42;
      string b = a.ToString();
      Assert::AreEqual("42", b, _caller);
    }
    
    void Int32DifferentOfZeroAsBool() {
      int32 a = 42;
      bool b = as<bool>(a);
      Assert::IsTrue(b, _caller);
    }
    
    void Int32EqualsToZeroAsBool() {
      int32 a = 0;
      bool b = as<bool>(a);
      Assert::IsFalse(b, _caller);
    }
    
    void Int32AsByte() {
      int32 a = 42;
      byte b = as<byte>(a);
      Assert::AreEqual(42, b, _caller);
    }
    
    void Int32AsString() {
      int32 a = 42;
      string b = as<string>(a);
      Assert::AreEqual("42", b, _caller);
    }
  };
 
  _AddTest(AsTest, StringAsString)
  _AddTest(AsTest, StringAsObject)
  _AddTest(AsTest, StringAsIComparable)
  _AddTest(AsTest, StringAsInt32)
  _AddTest(AsTest, ObjectFromStringAsString)
  _AddTest(AsTest, ObjectFromStringAsObject)
  _AddTest(AsTest, ObjectFromStringAsIComparable)
  _AddTest(AsTest, ObjectFromStringAsInt32)
  _AddTest(AsTest, ConstStringAsString)
  _AddTest(AsTest, ConstStringAsObject)
  _AddTest(AsTest, ConstStringAsIComparable)
  _AddTest(AsTest, ConstStringAsInt32)
  _AddTest(AsTest, ConstObjectFromStringAsString)
  _AddTest(AsTest, ConstObjectFromConstStringAsObject)
  _AddTest(AsTest, ConstObjectFromConstStringAsIComparable)
  _AddTest(AsTest, ConstObjectFromConstStringAsInt32)
  _AddTest(AsTest, StringPtrAsString)
  _AddTest(AsTest, StringPtrAsObject)
  _AddTest(AsTest, StringPtrAsIComparable)
  _AddTest(AsTest, StringPtrAsInt32)
  _AddTest(AsTest, ObjectPtrFromStringPtrAsString)
  _AddTest(AsTest, ObjectPtrFromStringPtrAsObject)
  _AddTest(AsTest, ObjectPtrFromStringPtrAsIComparable)
  _AddTest(AsTest, ObjectPtrFromStringPtrAsInt32)
  _AddTest(AsTest, StringPtrNullAsString)
  _AddTest(AsTest, StringPtrNullAsObject)
  _AddTest(AsTest, StringPtrNullAsIComparable)
  _AddTest(AsTest, StringPtrNullAsInt32)
  _AddTest(AsTest, ObjectPtrFromStringPtrNullAsString)
  _AddTest(AsTest, ObjectPtrFromStringPtrNullAsObject)
  _AddTest(AsTest, ObjectPtrFromStringPtrNullAsIComparable)
  _AddTest(AsTest, ObjectPtrFromStringPtrNullAsInt32)
  _AddTest(AsTest, ConstStringPtrAsString)
  _AddTest(AsTest, ConstStringPtrAsObject)
  _AddTest(AsTest, ConstStringPtrAsIComparable)
  _AddTest(AsTest, ConstStringPtrAsInt32)
  _AddTest(AsTest, ConstObjectPtrFromStringPtrAsString)
  _AddTest(AsTest, ConstObjectPtrFromStringPtrAsObject)
  _AddTest(AsTest, ConstObjectPtrFromStringPtrAsIComparable)
  _AddTest(AsTest, ConstObjectPtrFromStringPtrAsInt32)
  _AddTest(AsTest, ConstStringPtrNullAsString)
  _AddTest(AsTest, ConstStringPtrNullAsObject)
  _AddTest(AsTest, ConstStringPtrNullAsIComparable)
  _AddTest(AsTest, ConstStringPtrNullAsInt32)
  _AddTest(AsTest, ConstObjectPtrFromStringPtrNullAsString)
  _AddTest(AsTest, ConstObjectPtrFromStringPtrNullAsObject)
  _AddTest(AsTest, ConstObjectPtrFromStringPtrNullAsIComparable)
  _AddTest(AsTest, ConstObjectPtrFromStringPtrNullAsInt32)
  _AddTest(AsTest, RefPtrStringAsString)
  _AddTest(AsTest, RefPtrStringAsObject)
  _AddTest(AsTest, RefPtrStringAsIComparable)
  _AddTest(AsTest, RefPtrStringAsInt32)
  _AddTest(AsTest, RefPtrObjectFromStringAsString)
  _AddTest(AsTest, RefPtrObjectFromStringAsObject)
  _AddTest(AsTest, RefPtrObjectFromStringAsIComparable)
  _AddTest(AsTest, RefPtrObjectFromStringAsInt32)
  _AddTest(AsTest, RefPtrStringNullAsString)
  _AddTest(AsTest, RefPtrStringNullAsObject)
  _AddTest(AsTest, RefPtrStringNullAsIComparable)
  _AddTest(AsTest, RefPtrStringNullAsInt32)
  _AddTest(AsTest, RefPtrObjectFromStringNullAsString)
  _AddTest(AsTest, RefPtrObjectFromStringNullAsObject)
  _AddTest(AsTest, RefPtrObjectFromStringNullAsIComparable)
  _AddTest(AsTest, RefPtrObjectFromStringNullAsInt32)
  _AddTest(AsTest, ConstSpStringAsString)
  _AddTest(AsTest, ConstSpStringAsObject)
  _AddTest(AsTest, ConstSpStringAsIComparable)
  _AddTest(AsTest, ConstSpStringAsInt32)
  _AddTest(AsTest, ConstSpObjectFromStringAsString)
  _AddTest(AsTest, ConstSpObjectFromStringAsObject)
  _AddTest(AsTest, ConstSpObjectFromStringAsIComparable)
  _AddTest(AsTest, ConstSpObjectFromStringAsInt32)
  _AddTest(AsTest, ConstSpStringNullAsString)
  _AddTest(AsTest, ConstSpStringNullAsObject)
  _AddTest(AsTest, ConstSpStringNullAsIComparable)
  _AddTest(AsTest, ConstSpStringNullAsInt32)
  _AddTest(AsTest, ConstSpObjectFromStringNullAsString)
  _AddTest(AsTest, ConstSpObjectFromStringNullAsObject)
  _AddTest(AsTest, ConstSpObjectFromStringNullAsIComparable)
  _AddTest(AsTest, ConstSpObjectFromStringNullAsInt32)
  _AddTest(AsTest, RefStringAsString)
  _AddTest(AsTest, RefStringAsObject)
  _AddTest(AsTest, RefStringAsIComparable)
  _AddTest(AsTest, RefStringAsInt32)
  _AddTest(AsTest, RefObjectFromStringAsString)
  _AddTest(AsTest, RefObjectFromStringAsObject)
  _AddTest(AsTest, RefObjectFromStringAsIComparable)
  _AddTest(AsTest, RefObjectFromStringAsInt32)
  _AddTest(AsTest, RefStringNullAsString)
  _AddTest(AsTest, RefStringNullAsObject)
  _AddTest(AsTest, RefStringNullAsIComparable)
  _AddTest(AsTest, RefStringNullAsInt32)
  _AddTest(AsTest, RefObjectFromStringNullAsString)
  _AddTest(AsTest, RefObjectFromStringNullAsObject)
  _AddTest(AsTest, RefObjectFromStringNullAsIComparable)
  _AddTest(AsTest, RefObjectFromStringNullAsInt32)
  _AddTest(AsTest, ConstRefStringAsString)
  _AddTest(AsTest, ConstRefStringAsObject)
  _AddTest(AsTest, ConstRefStringAsIComparable)
  _AddTest(AsTest, ConstRefStringAsInt32)
  _AddTest(AsTest, ConstRefObjectFromStringAsString)
  _AddTest(AsTest, ConstRefObjectFromStringAsObject)
  _AddTest(AsTest, ConstRefObjectFromStringAsIComparable)
  _AddTest(AsTest, ConstRefObjectFromStringAsInt32)
  _AddTest(AsTest, ConstRefStringNullAsString)
  _AddTest(AsTest, ConstRefStringNullAsObject)
  _AddTest(AsTest, ConstRefStringNullAsIComparable)
  _AddTest(AsTest, ConstRefStringNullAsInt32)
  _AddTest(AsTest, ConstRefObjectFromStringNullAsString)
  _AddTest(AsTest, ConstRefObjectFromStringNullAsObject)
  _AddTest(AsTest, ConstRefObjectFromStringNullAsIComparable)
  _AddTest(AsTest, ConstRefObjectFromStringNullAsInt32)
  _AddTest(AsTest, Int32DifferentOfZeroAsBool)
  _AddTest(AsTest, AnyInt32ToInt32)
  _AddTest(AsTest, AnyInt32ToString)
  _AddTest(AsTest, Int32EqualsToZeroAsBool)
  _AddTest(AsTest, Int32AsByte)
  _AddTest(AsTest, Int32AsString)
}
