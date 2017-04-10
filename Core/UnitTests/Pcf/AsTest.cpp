#include <Pcf/Any.h>
#include <Pcf/As.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class AsTest : public TestFixture {
  protected:
    void StringAsString() {
      string s = "Test";
      string& r = as<string>(s);
      Assert::AreEqual(&s, &r, pcf_current_information);
    }
    
    void StringAsObject() {
      string s = "Test";
      object& r = as<object>(s);
      Assert::AreEqual(&s, &r, pcf_current_information);
    }
    
    void StringAsIComparable() {
      string s = "Test";
      IComparable& r = as<IComparable>(s);
      Assert::AreEqual(&s, &r, pcf_current_information);
    }
    
    void StringAsInt32() {
      string s = "Test";
      Assert::Throws<InvalidCastException>(pcf_delegate {as<Int32>(s);}, pcf_current_information);
    }
    
    void ObjectFromStringAsString() {
      string s = "Test";
      object& o = s;
      string& r = as<string>(o);
      Assert::AreEqual(&s, &r, pcf_current_information);
    }
    
    void ObjectFromStringAsObject() {
      string s = "Test";
      object& o = s;
      object& r = as<object>(o);
      Assert::AreEqual(&s, &r, pcf_current_information);
    }
    
    void ObjectFromStringAsIComparable() {
      string s = "Test";
      object& o = s;
      IComparable& r = as<IComparable>(o);
      Assert::AreEqual(&s, &r, pcf_current_information);
    }
    
    void ObjectFromStringAsInt32() {
      string s = "Test";
      object& o = s;
      Assert::Throws<InvalidCastException>(pcf_delegate {as<Int32>(o);}, pcf_current_information);
    }
  
    void ConstStringAsString() {
      const string s = "Test";
      const string& r = as<string>(s);
      Assert::AreEqual(&s, &r, pcf_current_information);
    }
    
    void ConstStringAsObject() {
      const string s = "Test";
      const object& r = as<object>(s);
      Assert::AreEqual(&s, &r, pcf_current_information);
    }
    
    void ConstStringAsIComparable() {
      const string s = "Test";
      const IComparable& r = as<IComparable>(s);
      Assert::AreEqual(&s, &r, pcf_current_information);
    }
    
    void ConstStringAsInt32() {
      const string s = "Test";
      Assert::Throws<InvalidCastException>(pcf_delegate {as<Int32>(s);}, pcf_current_information);
    }
    
    void ConstObjectFromStringAsString() {
      const string s = "Test";
      const object& o = s;
      const string& r = as<string>(o);
      Assert::AreEqual(&s, &r, pcf_current_information);
    }
    
    void ConstObjectFromConstStringAsObject() {
      const string s = "Test";
      const object& o = s;
      const object& r = as<object>(o);
      Assert::AreEqual(&s, &r, pcf_current_information);
    }
    
    void ConstObjectFromConstStringAsIComparable() {
      const string s = "Test";
      const object& o = s;
      const IComparable& r = as<IComparable>(o);
      Assert::AreEqual(&s, &r, pcf_current_information);
    }
    
    void ConstObjectFromConstStringAsInt32() {
      const string s = "Test";
      const object& o = s;
      Assert::Throws<InvalidCastException>(pcf_delegate {as<Int32>(o);}, pcf_current_information);
    }
    
    void StringPtrAsString() {
      string str = "test";
      string* s = &str;
      string* r = as<string>(s);
      Assert::AreEqual(s, r, pcf_current_information);
    }
    
    void StringPtrAsObject() {
      string str = "test";
      string* s = &str;
      object* r = as<object>(s);
      Assert::AreEqual(s, r, pcf_current_information);
    }
    
    void StringPtrAsIComparable() {
      string str = "test";
      string* s = &str;
      IComparable* r = as<IComparable>(s);
      Assert::AreEqual(s, r, pcf_current_information);
    }
    
    void StringPtrAsInt32() {
      string str = "test";
      string* s = &str;
      Assert::Throws<InvalidCastException>(pcf_delegate {as<Int32>(s);}, pcf_current_information);
    }
    
    void ObjectPtrFromStringPtrAsString() {
      string str = "test";
      string* s = &str;
      object* o = s;
      string* r = as<string>(o);
      Assert::AreEqual(s, r, pcf_current_information);
    }
    
    void ObjectPtrFromStringPtrAsObject() {
      string str = "test";
      string* s = &str;
      object* o = s;
      object* r = as<object>(o);
      Assert::AreEqual(s, r, pcf_current_information);
    }
    
    void ObjectPtrFromStringPtrAsIComparable() {
      string str = "test";
      string* s = &str;
      object* o = s;
      IComparable* r = as<IComparable>(o);
      Assert::AreEqual(s, r, pcf_current_information);
    }
    
    void ObjectPtrFromStringPtrAsInt32() {
      string str = "test";
      string* s = &str;
      object* o = s;
      Assert::Throws<InvalidCastException>(pcf_delegate {as<Int32>(o);}, pcf_current_information);
    }
    
    void StringPtrNullAsString() {
      string* s = null;
      string* r = as<string>(s);
      Assert::IsNull(r, pcf_current_information);
    }
    
    void StringPtrNullAsObject() {
      string* s = null;
      object* r = as<object>(s);
      Assert::IsNull(r, pcf_current_information);
    }
    
    void StringPtrNullAsIComparable() {
      string* s = null;
      IComparable* r = as<IComparable>(s);
      Assert::IsNull(r, pcf_current_information);
    }
    
    void StringPtrNullAsInt32() {
      string* s = null;
      IComparable* r = as<Int32>(s);
      Assert::IsNull(r, pcf_current_information);
    }
    
    void ObjectPtrFromStringPtrNullAsString() {
      string* s = null;
      object* o = s;
      string* r = as<string>(o);
      Assert::IsNull(r, pcf_current_information);
    }
    
    void ObjectPtrFromStringPtrNullAsObject() {
      string* s = null;
      object* o = s;
      object* r = as<object>(o);
      Assert::IsNull(r, pcf_current_information);
    }
    
    void ObjectPtrFromStringPtrNullAsIComparable() {
      string* s = null;
      object* o = s;
      IComparable* r = as<IComparable>(o);
      Assert::IsNull(r, pcf_current_information);
    }
    
    void ObjectPtrFromStringPtrNullAsInt32() {
      string* s = null;
      object* o = s;
      Int32* r = as<Int32>(o);
      Assert::IsNull(r, pcf_current_information);
    }
    
    void ConstStringPtrAsString() {
      string str = "test";
      const string* s = &str;
      const string* r = as<string>(s);
      Assert::AreEqual(s, r, pcf_current_information);
    }
    
    void ConstStringPtrAsObject() {
      string str = "test";
      const string* s = &str;
      const object* r = as<object>(s);
      Assert::AreEqual(s, r, pcf_current_information);
    }
    
    void ConstStringPtrAsIComparable() {
      string str = "test";
      const string* s = &str;
      const IComparable* r = as<IComparable>(s);
      Assert::AreEqual(s, r, pcf_current_information);
    }
    
    void ConstStringPtrAsInt32() {
      string str = "test";
      const string* s = &str;
      Assert::Throws<InvalidCastException>(pcf_delegate {as<Int32>(s);}, pcf_current_information);
    }
    
    void ConstObjectPtrFromStringPtrAsString() {
      string str = "test";
      const string* s = &str;
      const object* o = s;
      const string* r = as<string>(o);
      Assert::AreEqual(s, r, pcf_current_information);
    }
    
    void ConstObjectPtrFromStringPtrAsObject() {
      string str = "test";
      const string* s = &str;
      const object* o = s;
      const object* r = as<object>(o);
      Assert::AreEqual(s, r, pcf_current_information);
    }
    
    void ConstObjectPtrFromStringPtrAsIComparable() {
      string str = "test";
      const string* s = &str;
      const object* o = s;
      const IComparable* r = as<IComparable>(o);
      Assert::AreEqual(s, r, pcf_current_information);
    }
    
    void ConstObjectPtrFromStringPtrAsInt32() {
      string str = "test";
      const string* s = &str;
      const object* o = s;
      Assert::Throws<InvalidCastException>(pcf_delegate {as<Int32>(o);}, pcf_current_information);
    }
    
    void ConstStringPtrNullAsString() {
      const string* s = null;
      const string* r = as<string>(s);
      Assert::IsNull(r, pcf_current_information);
    }
    
    void ConstStringPtrNullAsObject() {
      const string* s = null;
      const object* r = as<object>(s);
      Assert::IsNull(r, pcf_current_information);
    }
    
    void ConstStringPtrNullAsIComparable() {
      const string* s = null;
      const IComparable* r = as<IComparable>(s);
      Assert::IsNull(r, pcf_current_information);
    }
    
    void ConstStringPtrNullAsInt32() {
      const string* s = null;
      const Int32* r = as<Int32>(s);
      Assert::IsNull(r, pcf_current_information);
    }
    
    void ConstObjectPtrFromStringPtrNullAsString() {
      const string* s = null;
      const object* o = s;
      const string* r = as<string>(o);
      Assert::IsNull(r, pcf_current_information);
    }
    
    void ConstObjectPtrFromStringPtrNullAsObject() {
      const string* s = null;
      const object* o = s;
      const object* r = as<object>(o);
      Assert::IsNull(r, pcf_current_information);
    }
    
    void ConstObjectPtrFromStringPtrNullAsIComparable() {
      const string* s = null;
      const object* o = s;
      const IComparable* r = as<IComparable>(o);
      Assert::IsNull(r, pcf_current_information);
    }
    
    void ConstObjectPtrFromStringPtrNullAsInt32() {
      const string* s = null;
      const object* o = s;
      const Int32* r = as<Int32>(o);
      Assert::IsNull(r, pcf_current_information);
    }
    
    void SpStringAsString() {
      RefPtr<string> s = RefPtr<string>::Create("Test");
      RefPtr<string> r = as<string>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void SpStringAsObject() {
      RefPtr<string> s = RefPtr<string>::Create("Test");
      RefPtr<object> r = as<object>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void SpStringAsIComparable() {
      RefPtr<string> s = RefPtr<string>::Create("Test");
      RefPtr<IComparable> r = as<IComparable>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void SpStringAsInt32() {
      RefPtr<string> s = RefPtr<string>::Create("Test");
      RefPtr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void SpObjectFromStringAsString() {
      RefPtr<string> s = RefPtr<string>::Create("Test");
      RefPtr<object> o = as<object>(s);
      RefPtr<string> r = as<string>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void SpObjectFromStringAsObject() {
      RefPtr<string> s = RefPtr<string>::Create("Test");
      RefPtr<object> o = as<object>(s);
      RefPtr<object> r = as<object>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void SpObjectFromStringAsIComparable() {
      RefPtr<string> s = RefPtr<string>::Create("Test");
      RefPtr<object> o = as<object>(s);
      RefPtr<IComparable> r = as<IComparable>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void SpObjectFromStringAsInt32() {
      RefPtr<string> s = RefPtr<string>::Create("Test");
      RefPtr<object> o = as<object>(s);
      RefPtr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void SpStringNullAsString() {
      RefPtr<string> s = RefPtr<string>::Null();
      RefPtr<string> r = as<string>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void SpStringNullAsObject() {
      RefPtr<string> s = RefPtr<string>::Null();
      RefPtr<object> r = as<object>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void SpStringNullAsIComparable() {
      RefPtr<string> s = RefPtr<string>::Null();
      RefPtr<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void SpStringNullAsInt32() {
      RefPtr<string> s = RefPtr<string>::Null();
      RefPtr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void SpObjectFromStringNullAsString() {
      RefPtr<string> s = RefPtr<string>::Null();
      RefPtr<object> o = as<object>(s);
      RefPtr<string> r = as<string>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void SpObjectFromStringNullAsObject() {
      RefPtr<string> s = RefPtr<string>::Null();
      RefPtr<object> o = as<object>(s);
      RefPtr<object> r = as<object>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void SpObjectFromStringNullAsIComparable() {
      RefPtr<string> s = RefPtr<string>::Null();
      RefPtr<object> o = as<object>(s);
      RefPtr<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void SpObjectFromStringNullAsInt32() {
      RefPtr<string> s = RefPtr<string>::Null();
      RefPtr<object> o = as<object>(s);
      RefPtr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstSpStringAsString() {
      const RefPtr<string> s = RefPtr<string>::Create("Test");
      const RefPtr<string> r = as<string>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void ConstSpStringAsObject() {
      const RefPtr<string> s = RefPtr<string>::Create("Test");
      const RefPtr<object> r = as<object>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void ConstSpStringAsIComparable() {
      const RefPtr<string> s = RefPtr<string>::Create("Test");
      const RefPtr<IComparable> r = as<IComparable>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void ConstSpStringAsInt32() {
      const RefPtr<string> s = RefPtr<string>::Create("Test");
      const RefPtr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstSpObjectFromStringAsString() {
      const RefPtr<string> s = RefPtr<string>::Create("Test");
      const RefPtr<object> o = as<object>(s);
      const RefPtr<string> r = as<string>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void ConstSpObjectFromStringAsObject() {
      const RefPtr<string> s = RefPtr<string>::Create("Test");
      const RefPtr<object> o = as<object>(s);
      const RefPtr<object> r = as<object>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void ConstSpObjectFromStringAsIComparable() {
      const RefPtr<string> s = RefPtr<string>::Create("Test");
      const RefPtr<object> o = as<object>(s);
      const RefPtr<IComparable> r = as<IComparable>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void ConstSpObjectFromStringAsInt32() {
      const RefPtr<string> s = RefPtr<string>::Create("Test");
      const RefPtr<object> o = as<object>(s);
      const RefPtr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstSpStringNullAsString() {
      const RefPtr<string> s = RefPtr<string>::Null();
      const RefPtr<string> r = as<string>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstSpStringNullAsObject() {
      const RefPtr<string> s = RefPtr<string>::Null();
      const RefPtr<object> r = as<object>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstSpStringNullAsIComparable() {
      const RefPtr<string> s = RefPtr<string>::Null();
      const RefPtr<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstSpStringNullAsInt32() {
      const RefPtr<string> s = RefPtr<string>::Null();
      const RefPtr<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstSpObjectFromStringNullAsString() {
      const RefPtr<string> s = RefPtr<string>::Null();
      const RefPtr<object> o = as<object>(s);
      const RefPtr<string> r = as<string>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstSpObjectFromStringNullAsObject() {
      const RefPtr<string> s = RefPtr<string>::Null();
      const RefPtr<object> o = as<object>(s);
      const RefPtr<object> r = as<object>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstSpObjectFromStringNullAsIComparable() {
      const RefPtr<string> s = RefPtr<string>::Null();
      const RefPtr<object> o = as<object>(s);
      const RefPtr<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstSpObjectFromStringNullAsInt32() {
      const RefPtr<string> s = RefPtr<string>::Null();
      const RefPtr<object> o = as<object>(s);
      const RefPtr<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void UpStringAsString() {
      UniquePointer<string> s = UniquePointer<string>::Create("Test");
      UniquePointer<string> r = as<string>(s);
      Assert::AreEqual("Test", r->ToString(), pcf_current_information);
    }
    
    void UpStringAsObject() {
      UniquePointer<string> s = UniquePointer<string>::Create("Test");
      UniquePointer<object> r = as<object>(s);
      Assert::AreEqual("Test", r->ToString(), pcf_current_information);
    }
    
    void UpStringAsIComparable() {
      UniquePointer<string> s = UniquePointer<string>::Create("Test");
      UniquePointer<IComparable> r = as<IComparable>(s);
      Assert::AreEqual("Test", as<object>(r)->ToString(), pcf_current_information);
    }
    
    void UpStringAsInt32() {
      UniquePointer<string> s = UniquePointer<string>::Create("Test");
      UniquePointer<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void UpObjectFromStringAsString() {
      UniquePointer<string> s = UniquePointer<string>::Create("Test");
      UniquePointer<object> o = as<object>(s);
      UniquePointer<string> r = as<string>(o);
      Assert::AreEqual("Test", r->ToString(), pcf_current_information);
    }
    
    void UpObjectFromStringAsObject() {
      UniquePointer<string> s = UniquePointer<string>::Create("Test");
      UniquePointer<object> o = as<object>(s);
      UniquePointer<object> r = as<object>(o);
      Assert::AreEqual("Test", r->ToString(), pcf_current_information);
    }
    
    void UpObjectFromStringAsIComparable() {
      UniquePointer<string> s = UniquePointer<string>::Create("Test");
      UniquePointer<object> o = as<object>(s);
      UniquePointer<IComparable> r = as<IComparable>(o);
      Assert::AreEqual("Test", as<object>(r)->ToString(), pcf_current_information);
    }
    
    void UpObjectFromStringAsInt32() {
      UniquePointer<string> s = UniquePointer<string>::Create("Test");
      UniquePointer<object> o = as<object>(s);
      UniquePointer<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void UpStringNullAsString() {
      UniquePointer<string> s = UniquePointer<string>::Null();
      UniquePointer<string> r = as<string>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void UpStringNullAsObject() {
      UniquePointer<string> s = UniquePointer<string>::Null();
      UniquePointer<object> r = as<object>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void UpStringNullAsIComparable() {
      UniquePointer<string> s = UniquePointer<string>::Null();
      UniquePointer<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void UpStringNullAsInt32() {
      UniquePointer<string> s = UniquePointer<string>::Null();
      UniquePointer<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void UpObjectFromStringNullAsString() {
      UniquePointer<string> s = UniquePointer<string>::Null();
      UniquePointer<object> o = as<object>(s);
      UniquePointer<string> r = as<string>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void UpObjectFromStringNullAsObject() {
      UniquePointer<string> s = UniquePointer<string>::Null();
      UniquePointer<object> o = as<object>(s);
      UniquePointer<object> r = as<object>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void UpObjectFromStringNullAsIComparable() {
      UniquePointer<string> s = UniquePointer<string>::Null();
      UniquePointer<object> o = as<object>(s);
      UniquePointer<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void UpObjectFromStringNullAsInt32() {
      UniquePointer<string> s = UniquePointer<string>::Null();
      UniquePointer<object> o = as<object>(s);
      UniquePointer<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void RefStringAsString() {
      string str = "Test";
      Ref<string> s = str;
      Ref<string> r = as<string>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void RefStringAsObject() {
      string str = "Test";
      Ref<string> s = str;
      Ref<object> r = as<object>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void RefStringAsIComparable() {
      string str = "Test";
      Ref<string> s = str;
      Ref<IComparable> r = as<IComparable>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void RefStringAsInt32() {
      string str = "Test";
      Ref<string> s = str;
      Ref<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void RefObjectFromStringAsString() {
      string str = "Test";
      Ref<string> s = str;
      Ref<object> o = as<object>(s);
      Ref<string> r = as<string>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void RefObjectFromStringAsObject() {
      string str = "Test";
      Ref<string> s = str;
      Ref<object> o = as<object>(s);
      Ref<object> r = as<object>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void RefObjectFromStringAsIComparable() {
      string str = "Test";
      Ref<string> s = str;
      Ref<object> o = as<object>(s);
      Ref<IComparable> r = as<IComparable>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void RefObjectFromStringAsInt32() {
      string str = "Test";
      Ref<string> s = str;
      Ref<object> o = as<object>(s);
      Ref<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void RefStringNullAsString() {
      Ref<string> s = Ref<string>::Null();
      Ref<string> r = as<string>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void RefStringNullAsObject() {
      Ref<string> s = Ref<string>::Null();
      Ref<object> r = as<object>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void RefStringNullAsIComparable() {
      Ref<string> s = Ref<string>::Null();
      Ref<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void RefStringNullAsInt32() {
      Ref<string> s = Ref<string>::Null();
      Ref<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void RefObjectFromStringNullAsString() {
      Ref<string> s = Ref<string>::Null();
      Ref<object> o = as<object>(s);
      Ref<string> r = as<string>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void RefObjectFromStringNullAsObject() {
      Ref<string> s = Ref<string>::Null();
      Ref<object> o = as<object>(s);
      Ref<object> r = as<object>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void RefObjectFromStringNullAsIComparable() {
      Ref<string> s = Ref<string>::Null();
      Ref<object> o = as<object>(s);
      Ref<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void RefObjectFromStringNullAsInt32() {
      Ref<string> s = Ref<string>::Null();
      Ref<object> o = as<object>(s);
      Ref<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstRefStringAsString() {
      const string str = "Test";
      const Ref<string> s = str;
      const Ref<string> r = as<string>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void ConstRefStringAsObject() {
      const string str = "Test";
      const Ref<string> s = str;
      const Ref<object> r = as<object>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void ConstRefStringAsIComparable() {
      const string str = "Test";
      const Ref<string> s = str;
      const Ref<IComparable> r = as<IComparable>(s);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void ConstRefStringAsInt32() {
      const string str = "Test";
      const Ref<string> s = str;
      const Ref<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstRefObjectFromStringAsString() {
      const string str = "Test";
      const Ref<string> s = str;
      const Ref<object> o = as<object>(s);
      const Ref<string> r = as<string>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void ConstRefObjectFromStringAsObject() {
      const string str = "Test";
      const Ref<string> s = str;
      const Ref<object> o = as<object>(s);
      const Ref<object> r = as<object>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void ConstRefObjectFromStringAsIComparable() {
      const string str = "Test";
      const Ref<string> s = str;
      const Ref<object> o = as<object>(s);
      const Ref<IComparable> r = as<IComparable>(o);
      Assert::AreEqual(s.ToPointer(), r.ToPointer(), pcf_current_information);
    }
    
    void ConstRefObjectFromStringAsInt32() {
      const string str = "Test";
      const Ref<string> s = str;
      const Ref<object> o = as<object>(s);
      const Ref<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstRefStringNullAsString() {
      const Ref<string> s = Ref<string>::Null();
      const Ref<string> r = as<string>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstRefStringNullAsObject() {
      const Ref<string> s = Ref<string>::Null();
      const Ref<object> r = as<object>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstRefStringNullAsIComparable() {
      const Ref<string> s = Ref<string>::Null();
      const Ref<IComparable> r = as<IComparable>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstRefStringNullAsInt32() {
      const Ref<string> s = Ref<string>::Null();
      const Ref<Int32> r = as<Int32>(s);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstRefObjectFromStringNullAsString() {
      const Ref<string> s = Ref<string>::Null();
      const Ref<object> o = as<object>(s);
      const Ref<string> r = as<string>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstRefObjectFromStringNullAsObject() {
      const Ref<string> s = Ref<string>::Null();
      const Ref<object> o = as<object>(s);
      const Ref<object> r = as<object>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstRefObjectFromStringNullAsIComparable() {
      const Ref<string> s = Ref<string>::Null();
      const Ref<object> o = as<object>(s);
      const Ref<IComparable> r = as<IComparable>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void ConstRefObjectFromStringNullAsInt32() {
      const Ref<string> s = Ref<string>::Null();
      const Ref<object> o = as<object>(s);
      const Ref<Int32> r = as<Int32>(o);
      Assert::IsTrue(r.IsNull(), pcf_current_information);
    }
    
    void AnyInt32ToInt32() {
      Any a = 42;
      int32 b = as<Int32>(a);
      Assert::AreEqual(42, b, pcf_current_information);
    }
    
    void AnyInt32ToString() {
      Any a = 42;
      string b = a.ToString();
      Assert::AreEqual("42", b, pcf_current_information);
    }
    
    void Int32DifferentOfZeroAsBool() {
      int32 a = 42;
      bool b = as<bool>(a);
      Assert::IsTrue(b, pcf_current_information);
    }
    
    void Int32EqualsToZeroAsBool() {
      int32 a = 0;
      bool b = as<bool>(a);
      Assert::IsFalse(b, pcf_current_information);
    }
    
    void Int32AsByte() {
      int32 a = 42;
      byte b = as<int32>(a);
      Assert::AreEqual(42, b, pcf_current_information);
    }
    
    void Int32AsString() {
      int32 a = 42;
      string b = as<string>(a);
      Assert::AreEqual("42", b, pcf_current_information);
    }
  };
 
  pcf_test(AsTest, StringAsString)
  pcf_test(AsTest, StringAsObject)
  pcf_test(AsTest, StringAsIComparable)
  pcf_test(AsTest, StringAsInt32)
  pcf_test(AsTest, ObjectFromStringAsString)
  pcf_test(AsTest, ObjectFromStringAsObject)
  pcf_test(AsTest, ObjectFromStringAsIComparable)
  pcf_test(AsTest, ObjectFromStringAsInt32)
  pcf_test(AsTest, ConstStringAsString)
  pcf_test(AsTest, ConstStringAsObject)
  pcf_test(AsTest, ConstStringAsIComparable)
  pcf_test(AsTest, ConstStringAsInt32)
  pcf_test(AsTest, ConstObjectFromStringAsString)
  pcf_test(AsTest, ConstObjectFromConstStringAsObject)
  pcf_test(AsTest, ConstObjectFromConstStringAsIComparable)
  pcf_test(AsTest, ConstObjectFromConstStringAsInt32)
  pcf_test(AsTest, StringPtrAsString)
  pcf_test(AsTest, StringPtrAsObject)
  pcf_test(AsTest, StringPtrAsIComparable)
  pcf_test(AsTest, StringPtrAsInt32)
  pcf_test(AsTest, ObjectPtrFromStringPtrAsString)
  pcf_test(AsTest, ObjectPtrFromStringPtrAsObject)
  pcf_test(AsTest, ObjectPtrFromStringPtrAsIComparable)
  pcf_test(AsTest, ObjectPtrFromStringPtrAsInt32)
  pcf_test(AsTest, StringPtrNullAsString)
  pcf_test(AsTest, StringPtrNullAsObject)
  pcf_test(AsTest, StringPtrNullAsIComparable)
  pcf_test(AsTest, StringPtrNullAsInt32)
  pcf_test(AsTest, ObjectPtrFromStringPtrNullAsString)
  pcf_test(AsTest, ObjectPtrFromStringPtrNullAsObject)
  pcf_test(AsTest, ObjectPtrFromStringPtrNullAsIComparable)
  pcf_test(AsTest, ObjectPtrFromStringPtrNullAsInt32)
  pcf_test(AsTest, ConstStringPtrAsString)
  pcf_test(AsTest, ConstStringPtrAsObject)
  pcf_test(AsTest, ConstStringPtrAsIComparable)
  pcf_test(AsTest, ConstStringPtrAsInt32)
  pcf_test(AsTest, ConstObjectPtrFromStringPtrAsString)
  pcf_test(AsTest, ConstObjectPtrFromStringPtrAsObject)
  pcf_test(AsTest, ConstObjectPtrFromStringPtrAsIComparable)
  pcf_test(AsTest, ConstObjectPtrFromStringPtrAsInt32)
  pcf_test(AsTest, ConstStringPtrNullAsString)
  pcf_test(AsTest, ConstStringPtrNullAsObject)
  pcf_test(AsTest, ConstStringPtrNullAsIComparable)
  pcf_test(AsTest, ConstStringPtrNullAsInt32)
  pcf_test(AsTest, ConstObjectPtrFromStringPtrNullAsString)
  pcf_test(AsTest, ConstObjectPtrFromStringPtrNullAsObject)
  pcf_test(AsTest, ConstObjectPtrFromStringPtrNullAsIComparable)
  pcf_test(AsTest, ConstObjectPtrFromStringPtrNullAsInt32)
  pcf_test(AsTest, SpStringAsString)
  pcf_test(AsTest, SpStringAsObject)
  pcf_test(AsTest, SpStringAsIComparable)
  pcf_test(AsTest, SpStringAsInt32)
  pcf_test(AsTest, SpObjectFromStringAsString)
  pcf_test(AsTest, SpObjectFromStringAsObject)
  pcf_test(AsTest, SpObjectFromStringAsIComparable)
  pcf_test(AsTest, SpObjectFromStringAsInt32)
  pcf_test(AsTest, SpStringNullAsString)
  pcf_test(AsTest, SpStringNullAsObject)
  pcf_test(AsTest, SpStringNullAsIComparable)
  pcf_test(AsTest, SpStringNullAsInt32)
  pcf_test(AsTest, SpObjectFromStringNullAsString)
  pcf_test(AsTest, SpObjectFromStringNullAsObject)
  pcf_test(AsTest, SpObjectFromStringNullAsIComparable)
  pcf_test(AsTest, SpObjectFromStringNullAsInt32)
  pcf_test(AsTest, ConstSpStringAsString)
  pcf_test(AsTest, ConstSpStringAsObject)
  pcf_test(AsTest, ConstSpStringAsIComparable)
  pcf_test(AsTest, ConstSpStringAsInt32)
  pcf_test(AsTest, ConstSpObjectFromStringAsString)
  pcf_test(AsTest, ConstSpObjectFromStringAsObject)
  pcf_test(AsTest, ConstSpObjectFromStringAsIComparable)
  pcf_test(AsTest, ConstSpObjectFromStringAsInt32)
  pcf_test(AsTest, ConstSpStringNullAsString)
  pcf_test(AsTest, ConstSpStringNullAsObject)
  pcf_test(AsTest, ConstSpStringNullAsIComparable)
  pcf_test(AsTest, ConstSpStringNullAsInt32)
  pcf_test(AsTest, ConstSpObjectFromStringNullAsString)
  pcf_test(AsTest, ConstSpObjectFromStringNullAsObject)
  pcf_test(AsTest, ConstSpObjectFromStringNullAsIComparable)
  pcf_test(AsTest, ConstSpObjectFromStringNullAsInt32)
  pcf_test(AsTest, UpStringAsString)
  pcf_test(AsTest, UpStringAsObject)
  pcf_test(AsTest, UpStringAsIComparable)
  pcf_test(AsTest, UpStringAsInt32)
  pcf_test(AsTest, UpObjectFromStringAsString)
  pcf_test(AsTest, UpObjectFromStringAsObject)
  pcf_test(AsTest, UpObjectFromStringAsIComparable)
  pcf_test(AsTest, UpObjectFromStringAsInt32)
  pcf_test(AsTest, UpStringNullAsString)
  pcf_test(AsTest, UpStringNullAsObject)
  pcf_test(AsTest, UpStringNullAsIComparable)
  pcf_test(AsTest, UpStringNullAsInt32)
  pcf_test(AsTest, UpObjectFromStringNullAsString)
  pcf_test(AsTest, UpObjectFromStringNullAsObject)
  pcf_test(AsTest, UpObjectFromStringNullAsIComparable)
  pcf_test(AsTest, UpObjectFromStringNullAsInt32)
  pcf_test(AsTest, RefStringAsString)
  pcf_test(AsTest, RefStringAsObject)
  pcf_test(AsTest, RefStringAsIComparable)
  pcf_test(AsTest, RefStringAsInt32)
  pcf_test(AsTest, RefObjectFromStringAsString)
  pcf_test(AsTest, RefObjectFromStringAsObject)
  pcf_test(AsTest, RefObjectFromStringAsIComparable)
  pcf_test(AsTest, RefObjectFromStringAsInt32)
  pcf_test(AsTest, RefStringNullAsString)
  pcf_test(AsTest, RefStringNullAsObject)
  pcf_test(AsTest, RefStringNullAsIComparable)
  pcf_test(AsTest, RefStringNullAsInt32)
  pcf_test(AsTest, RefObjectFromStringNullAsString)
  pcf_test(AsTest, RefObjectFromStringNullAsObject)
  pcf_test(AsTest, RefObjectFromStringNullAsIComparable)
  pcf_test(AsTest, RefObjectFromStringNullAsInt32)
  pcf_test(AsTest, ConstRefStringAsString)
  pcf_test(AsTest, ConstRefStringAsObject)
  pcf_test(AsTest, ConstRefStringAsIComparable)
  pcf_test(AsTest, ConstRefStringAsInt32)
  pcf_test(AsTest, ConstRefObjectFromStringAsString)
  pcf_test(AsTest, ConstRefObjectFromStringAsObject)
  pcf_test(AsTest, ConstRefObjectFromStringAsIComparable)
  pcf_test(AsTest, ConstRefObjectFromStringAsInt32)
  pcf_test(AsTest, ConstRefStringNullAsString)
  pcf_test(AsTest, ConstRefStringNullAsObject)
  pcf_test(AsTest, ConstRefStringNullAsIComparable)
  pcf_test(AsTest, ConstRefStringNullAsInt32)
  pcf_test(AsTest, ConstRefObjectFromStringNullAsString)
  pcf_test(AsTest, ConstRefObjectFromStringNullAsObject)
  pcf_test(AsTest, ConstRefObjectFromStringNullAsIComparable)
  pcf_test(AsTest, ConstRefObjectFromStringNullAsInt32)
  pcf_test(AsTest, Int32DifferentOfZeroAsBool)
  pcf_test(AsTest, AnyInt32ToInt32)
  pcf_test(AsTest, AnyInt32ToString)
  pcf_test(AsTest, Int32EqualsToZeroAsBool)
  pcf_test(AsTest, Int32AsByte)
  pcf_test(AsTest, Int32AsString)
}
