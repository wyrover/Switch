#include <Pcf/Is.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {
  class IsTest : public TestFixture {
  protected:
    void StringIsString() {
      string s = "Test";
      Assert::IsTrue(is<string>(s));
    }
  
  };
 
  pcf_test(IsTest, StringIsString);
  
  TEST(Is, StringIsObject) {
    string s = "Test";
    Assert::IsTrue(is<object>(s));
  }
  
  TEST(Is, StringIsIComparable) {
    string s = "Test";
    Assert::IsTrue(is<IComparable>(s));
  }
  
  TEST(Is, StringIsInt32) {
    string s = "Test";
    Assert::IsFalse(is<Int32>(s));
  }
  
  TEST(Is, ObjectFromStringIsString) {
    string s = "Test";
    object& o = s;
    Assert::IsTrue(is<string>(o));
  }
  
  TEST(Is, ObjectFromStringIsObject) {
    string s = "Test";
    object& o = s;
    Assert::IsTrue(is<object>(o));
  }
  
  TEST(Is, ObjectFormStringIsIComparable) {
    string s = "Test";
    object& o = s;
    Assert::IsTrue(is<IComparable>(o));
  }
  
  TEST(Is, ObjectFormStringIsInt32) {
    string s = "Test";
    object& o = s;
    Assert::IsFalse(is<Int32>(o));
  }
  
  TEST(Is, ConstStringIsString) {
    const string s = "Test";
    Assert::IsTrue(is<string>(s));
  }
  
  TEST(Is, ConstStringIsObject) {
    const string s = "Test";
    Assert::IsTrue(is<object>(s));
  }
  
  TEST(Is, ConstStringIsIComparable) {
    const string s = "Test";
    Assert::IsTrue(is<IComparable>(s));
  }
  
  TEST(Is, ConstStringIsInt32) {
    const string s = "Test";
    Assert::IsFalse(is<Int32>(s));
  }
  
  TEST(Is, ConstObjectFromStringIsString) {
    const string s = "Test";
    const object& o = s;
    Assert::IsTrue(is<string>(o));
  }
  
  TEST(Is, ConstObjectFromStringIsObject) {
    const string s = "Test";
    const object& o = s;
    Assert::IsTrue(is<object>(o));
  }
  
  TEST(Is, ConstObjectFormStringIsIComparable) {
    const string s = "Test";
    const object& o = s;
    Assert::IsTrue(is<IComparable>(o));
  }
  
  TEST(Is, ConstObjectFormStringIsInt32) {
    const string s = "Test";
    const object& o = s;
    Assert::IsFalse(is<Int32>(o));
  }
  
  TEST(Is, StringPtrIsString) {
    string s = "Test";
    Assert::IsTrue(is<string>(&s));
  }
  
  TEST(Is, StringPtrIsObject) {
    string s = "Test";
    Assert::IsTrue(is<object>(&s));
  }
  
  TEST(Is, StringPtrIsIComparable) {
    string s = "Test";
    Assert::IsTrue(is<IComparable>(&s));
  }
  
  TEST(Is, StringPtrIsInt32) {
    string s = "Test";
    Assert::IsFalse(is<Int32>(&s));
  }
  
  TEST(Is, ObjectPtrFromStringPtrIsString) {
    string s = "Test";
    object* o = &s;
    Assert::IsTrue(is<string>(o));
  }
  
  TEST(Is, ObjectPtrFromStringPtrIsObject) {
    string s = "Test";
    object* o = &s;
    Assert::IsTrue(is<object>(o));
  }
  
  TEST(Is, ObjectPtrFormStringPtrIsIComparable) {
    string s = "Test";
    object* o = &s;
    Assert::IsTrue(is<IComparable>(o));
  }
  
  TEST(Is, ObjectPtrFormStringPtrIsInt32) {
    string s = "Test";
    object* o = &s;
    Assert::IsFalse(is<Int32>(o));
  }
  
  TEST(Is, StringPtrNullIsString) {
    string* s = null;
    Assert::IsFalse(is<string>(s));
  }
  
  TEST(Is, StringPtrNullIsObject) {
    string* s = null;
    Assert::IsFalse(is<object>(s));
  }
  
  TEST(Is, StringPtrNullIsIComparable) {
    string* s = null;
    Assert::IsFalse(is<IComparable>(s));
  }
  
  TEST(Is, StringPtrNullIsInt32) {
    string* s = null;
    Assert::IsFalse(is<Int32>(s));
  }
  
  TEST(Is, ObjectPtrFromStringPtrNullIsString) {
    string* s = null;
    object* o = s;
    Assert::IsFalse(is<string>(o));
  }
  
  TEST(Is, ObjectPtrFromStringPtrNullIsObject) {
    string* s = null;
    object* o = s;
    Assert::IsFalse(is<object>(o));
  }
  
  TEST(Is, ObjectPtrFormStringPtrNullIsIComparable) {
    string* s = null;
    object* o = s;
    Assert::IsFalse(is<IComparable>(o));
  }
  
  TEST(Is, ObjectPtrFormStringPtrNullIsInt32) {
    string* s = null;
    object* o = s;
    Assert::IsFalse(is<Int32>(o));
  }
  
  TEST(Is, ConstStringPtrIsString) {
    string s = "Test";
    const string* cs = &s;
    Assert::IsTrue(is<string>(cs));
  }
  
  TEST(Is, ConstStringPtrIsObject) {
    string s = "Test";
    const string* cs = &s;
    Assert::IsTrue(is<object>(cs));
  }
  
  TEST(Is, ConstStringPtrIsIComparable) {
    string s = "Test";
    const string* cs = &s;
    Assert::IsTrue(is<IComparable>(cs));
  }
  
  TEST(Is, ConstStringPtrIsInt32) {
    string s = "Test";
    const string* cs = &s;
    Assert::IsFalse(is<Int32>(cs));
  }
  
  TEST(Is, ConstObjectPtrFromStringPtrIsString) {
    string s = "Test";
    const object* o = &s;
    Assert::IsTrue(is<string>(o));
  }
  
  TEST(Is, ConstObjectPtrFromStringPtrIsObject) {
    string s = "Test";
    const object* o = &s;
    Assert::IsTrue(is<object>(o));
  }
  
  TEST(Is, ConstObjectPtrFormStringPtrIsIComparable) {
    string s = "Test";
    const object* o = &s;
    Assert::IsTrue(is<IComparable>(o));
  }
  
  TEST(Is, ConstObjectPtrFormStringPtrIsInt32) {
    string s = "Test";
    const object* o = &s;
    Assert::IsFalse(is<Int32>(o));
  }
  
  TEST(Is, ConstStringPtrNullIsString) {
    const string* s = null;
    Assert::IsFalse(is<string>(s));
  }
  
  TEST(Is, ConstStringPtrNullIsObject) {
    const string* s = null;
    Assert::IsFalse(is<object>(s));
  }
  
  TEST(Is, ConstStringPtrNullIsIComparable) {
    const string* s = null;
    Assert::IsFalse(is<IComparable>(s));
  }
  
  TEST(Is, ConstStringPtrNullIsInt32) {
    const string* s = null;
    Assert::IsFalse(is<Int32>(s));
  }
  
  TEST(Is, ConstObjectPtrFromStringPtrNullIsString) {
    const string* s = null;
    const object* o = s;
    Assert::IsFalse(is<string>(o));
  }
  
  TEST(Is, ConstObjectPtrFromStringPtrNullIsObject) {
    const string* s = null;
    const object* o = s;
    Assert::IsFalse(is<object>(o));
  }
  
  TEST(Is, ConstObjectPtrFormStringPtrNullIsIComparable) {
    const string* s = null;
    const object* o = s;
    Assert::IsFalse(is<IComparable>(o));
  }
  
  TEST(Is, ConstObjectPtrFormStringPtrNullIsInt32) {
    const string* s = null;
    const object* o = s;
    Assert::IsFalse(is<Int32>(o));
  }

  TEST(Is, SpStringIsString) {
    SharedPointer<string> s = SharedPointer<String>::Create("Test");
    Assert::IsTrue(is<string>(s));
  }
  
  TEST(Is, SpStringIsObject) {
    SharedPointer<string> s = SharedPointer<String>::Create("Test");
    Assert::IsTrue(is<object>(s));
  }
  
  TEST(Is, SpStringIsIComparable) {
    SharedPointer<string> s = SharedPointer<String>::Create("Test");
    Assert::IsTrue(is<IComparable>(s));
  }
  
  TEST(Is, SpStringIsInt32) {
    SharedPointer<string> s = new String("Test");
    Assert::IsFalse(is<Int32>(s));
  }
  
  TEST(Is, SpObjectFromSpStringIsString) {
    SharedPointer<object> o = SharedPointer<object>::Create<string>("Test");
    Assert::IsTrue(is<string>(o));
  }
  
  TEST(Is, SpObjectFromSpStringIsObject) {
    SharedPointer<object> o = SharedPointer<object>::Create<string>("Test");
    Assert::IsTrue(is<object>(o));
  }
  
  TEST(Is, SpObjectFormSpStringIsIComparable) {
    SharedPointer<object> o = SharedPointer<object>::Create<string>("Test");
    Assert::IsTrue(is<IComparable>(o));
  }
  
  TEST(Is, SpObjectFormSpStringIsInt32) {
    SharedPointer<object> o = SharedPointer<object>::Create<string>("Test");
    Assert::IsFalse(is<Int32>(o));
  }
  
  TEST(Is, SpStringNullIsString) {
    SharedPointer<string> s = SharedPointer<string>::Null();
    Assert::IsFalse(is<string>(s));
  }
  
  TEST(Is, SpStringNullIsObject) {
    SharedPointer<string> s = SharedPointer<string>::Null();
    Assert::IsFalse(is<object>(s));
  }
  
  TEST(Is, SpStringNullIsIComparable) {
    SharedPointer<string> s = SharedPointer<string>::Null();
    Assert::IsFalse(is<IComparable>(s));
  }
  
  TEST(Is, SpStringNullIsInt32) {
    SharedPointer<string> s = SharedPointer<string>::Null();
    Assert::IsFalse(is<Int32>(s));
  }
  
  TEST(Is, SpObjectFromSpStringNullIsString) {
    SharedPointer<object> o = as<object>(SharedPointer<string>::Null());
    Assert::IsFalse(is<string>(o));
  }
  
  TEST(Is, SpObjectFromSpStringNullIsObject) {
    SharedPointer<object> o = as<object>(SharedPointer<string>::Null());
    Assert::IsFalse(is<object>(o));
  }
  
  TEST(Is, SpObjectFormSpStringNullIsIComparable) {
    SharedPointer<object> o = as<object>(SharedPointer<string>::Null());
    Assert::IsFalse(is<IComparable>(o));
  }
  
  TEST(Is, SpObjectFormSpStringNullIsInt32) {
    SharedPointer<object> o = as<object>(SharedPointer<string>::Null());
    Assert::IsFalse(is<Int32>(o));
  }
  
  TEST(Is, ConstSpStringIsString) {
    const SharedPointer<string> s = SharedPointer<String>::Create("Test");
    Assert::IsTrue(is<string>(s));
  }
  
  TEST(Is, ConstSpStringIsObject) {
    const SharedPointer<string> s = SharedPointer<String>::Create("Test");
    Assert::IsTrue(is<object>(s));
  }
  
  TEST(Is, ConstSpStringIsIComparable) {
    const SharedPointer<string> s = SharedPointer<String>::Create("Test");
    Assert::IsTrue(is<IComparable>(s));
  }
  
  TEST(Is, ConstSpStringIsInt32) {
    const SharedPointer<string> s = SharedPointer<String>::Create("Test");
    Assert::IsFalse(is<Int32>(s));
  }
  
  TEST(Is, ConstSpObjectFromConstSpStringIsString) {
    const SharedPointer<object> o = SharedPointer<object>::Create<string>("Test");
    Assert::IsTrue(is<string>(o));
  }
  
  TEST(Is, ConstSpObjectFromConstSpStringIsObject) {
    const SharedPointer<object> o = SharedPointer<object>::Create<string>("Test");
    Assert::IsTrue(is<object>(o));
  }
  
  TEST(Is, ConstSpObjectFormConstSpStringIsIComparable) {
    const SharedPointer<object> o = SharedPointer<object>::Create<string>("Test");
    Assert::IsTrue(is<IComparable>(o));
  }
  
  TEST(Is, ConstSpObjectFormConstSpStringIsInt32) {
    const SharedPointer<object> o = SharedPointer<object>::Create<string>("Test");
    Assert::IsFalse(is<Int32>(o));
  }
  
  TEST(Is, ConstSpStringNullIsString) {
    const SharedPointer<string> s = SharedPointer<string>::Null();
    Assert::IsFalse(is<string>(s));
  }
  
  TEST(Is, ConstSpStringNullIsObject) {
    const SharedPointer<string> s = SharedPointer<string>::Null();
    Assert::IsFalse(is<object>(s));
  }
  
  TEST(Is, ConstSpStringNullIsIComparable) {
    const SharedPointer<string> s = SharedPointer<string>::Null();
    Assert::IsFalse(is<IComparable>(s));
  }
  
  TEST(Is, ConstSpStringNullIsInt32) {
    const SharedPointer<string> s = SharedPointer<string>::Null();
    Assert::IsFalse(is<Int32>(s));
  }
  
  TEST(Is, ConstSpObjectFromConstSpStringNullIsString) {
    const SharedPointer<object> o = as<object>(SharedPointer<string>::Null());
    Assert::IsFalse(is<string>(o));
  }
  
  TEST(Is, ConstSpObjectFromConstSpStringNullIsObject) {
    const SharedPointer<object> o = as<object>(SharedPointer<string>::Null());
    Assert::IsFalse(is<object>(o));
  }
  
  TEST(Is, ConstSpObjectFormConstSpStringNullIsIComparable) {
    const SharedPointer<object> o = as<object>(SharedPointer<string>::Null());
    Assert::IsFalse(is<IComparable>(o));
  }
  
  TEST(Is, ConstSpObjectFormConstSpStringNullIsInt32) {
    const SharedPointer<object> o = as<object>(SharedPointer<string>::Null());
    Assert::IsFalse(is<Int32>(o));
  }
  
  TEST(Is, UpStringIsString) {
    UniquePointer<string> s = UniquePointer<String>::Create("Test");
    Assert::IsTrue(is<string>(s));
  }
  
  TEST(Is, UpStringIsObject) {
    UniquePointer<string> s = UniquePointer<String>::Create("Test");
    Assert::IsTrue(is<object>(s));
  }
  
  TEST(Is, UpStringIsIComparable) {
    UniquePointer<string> s = UniquePointer<String>::Create("Test");
    Assert::IsTrue(is<IComparable>(s));
  }
  
  TEST(Is, UpStringIsInt32) {
    UniquePointer<string> s = UniquePointer<String>::Create("Test");
    Assert::IsFalse(is<Int32>(s));
  }
  
  TEST(Is, UpObjectFromUpStringIsString) {
    UniquePointer<object> o = UniquePointer<object>::Create<string>("Test");
    Assert::IsTrue(is<string>(o));
  }
  
  TEST(Is, UpObjectFromUpStringIsObject) {
    UniquePointer<object> o = UniquePointer<object>::Create<string>("Test");
    Assert::IsTrue(is<object>(o));
  }
  
  TEST(Is, UpObjectFormUpStringIsIComparable) {
    UniquePointer<object> o = UniquePointer<object>::Create<string>("Test");
    Assert::IsTrue(is<IComparable>(o));
  }
  
  TEST(Is, UpObjectFormUpStringIsInt32) {
    UniquePointer<object> o = UniquePointer<object>::Create<string>("Test");
    Assert::IsFalse(is<Int32>(o));
  }
  
  TEST(Is, UpStringNullIsString) {
    UniquePointer<string> s = UniquePointer<string>::Null();
    Assert::IsFalse(is<string>(s));
  }
  
  TEST(Is, UpStringNullIsObject) {
    UniquePointer<string> s = UniquePointer<string>::Null();
    Assert::IsFalse(is<object>(s));
  }
  
  TEST(Is, UpStringNullIsIComparable) {
    UniquePointer<string> s = UniquePointer<string>::Null();
    Assert::IsFalse(is<IComparable>(s));
  }
  
  TEST(Is, UpStringNullIsInt32) {
    UniquePointer<string> s = UniquePointer<string>::Null();
    Assert::IsFalse(is<Int32>(s));
  }
  
  TEST(Is, UpObjectFromUpStringNullIsString) {
    UniquePointer<string> s = UniquePointer<string>::Null();
    UniquePointer<object> o = as<object>(s);
    Assert::IsFalse(is<string>(o));
  }
  
  TEST(Is, UpObjectFromUpStringNullIsObject) {
    UniquePointer<string> s = UniquePointer<string>::Null();
    UniquePointer<object> o = as<object>(s);
    Assert::IsFalse(is<object>(o));
  }
  
  TEST(Is, UpObjectFormUpStringNullIsIComparable) {
    UniquePointer<string> s = UniquePointer<string>::Null();
    UniquePointer<object> o = as<object>(s);
    Assert::IsFalse(is<IComparable>(o));
  }
  
  TEST(Is, UpObjectFormUpStringNullIsInt32) {
    UniquePointer<string> s = UniquePointer<string>::Null();
    UniquePointer<object> o = as<object>(s);
    Assert::IsFalse(is<Int32>(o));
  }
  
  TEST(Is, RefStringIsString) {
    string str = "Test";
    Reference<string> s = str;
    Assert::IsTrue(is<string>(s));
  }
  
  TEST(Is, RefStringIsObject) {
    string str = "Test";
    Reference<string> s = str;
    Assert::IsTrue(is<object>(s));
  }
  
  TEST(Is, RefStringIsIComparable) {
    string str = "Test";
    Reference<string> s = str;
    Assert::IsTrue(is<IComparable>(s));
  }
  
  TEST(Is, RefStringIsInt32) {
    string str = "Test";
    Reference<string> s = str;
    Assert::IsFalse(is<Int32>(s));
  }
  
  TEST(Is, RefObjectFromRefStringIsString) {
    string str = "Test";
    Reference<object> o = str;
    Assert::IsTrue(is<string>(o));
  }
  
  TEST(Is, RefObjectFromRefStringIsObject) {
    string str = "Test";
    Reference<object> o = str;
    Assert::IsTrue(is<object>(o));
  }
  
  TEST(Is, RefObjectFormRefStringIsIComparable) {
    string str = "Test";
    Reference<object> o = str;
    Assert::IsTrue(is<IComparable>(o));
  }
  
  TEST(Is, RefObjectFormRefStringIsInt32) {
    string str = "Test";
    Reference<object> o = str;
    Assert::IsFalse(is<Int32>(o));
  }
  
  TEST(Is, RefStringNullIsString) {
    Reference<string> s = Reference<string>::Null();
    Assert::IsFalse(is<string>(s));
  }
  
  TEST(Is, RefStringNullIsObject) {
    Reference<string> s = Reference<string>::Null();
    Assert::IsFalse(is<object>(s));
  }
  
  TEST(Is, RefStringNullIsIComparable) {
    Reference<string> s = Reference<string>::Null();
    Assert::IsFalse(is<IComparable>(s));
  }
  
  TEST(Is, RefStringNullIsInt32) {
    Reference<string> s = Reference<string>::Null();
    Assert::IsFalse(is<Int32>(s));
  }
  
  TEST(Is, RefObjectFromRefStringNullIsString) {
    Reference<object> o = as<object>(Reference<string>::Null());
    Assert::IsFalse(is<string>(o));
  }
  
  TEST(Is, RefObjectFromRefStringNullIsObject) {
    Reference<object> o = as<object>(Reference<string>::Null());
    Assert::IsFalse(is<object>(o));
  }
  
  TEST(Is, RefObjectFormRefStringNullIsIComparable) {
    Reference<object> o = as<object>(Reference<string>::Null());
    Assert::IsFalse(is<IComparable>(o));
  }
  
  TEST(Is, RefObjectFormRefStringNullIsInt32) {
    Reference<object> o = as<object>(Reference<string>::Null());
    Assert::IsFalse(is<Int32>(o));
  }
  
  TEST(Is, ConstRefStringIsString) {
    const string str = "Test";
    const Reference<string> s = str;
    Assert::IsTrue(is<string>(s));
  }
  
  TEST(Is, ConstRefStringIsObject) {
    const string str = "Test";
    const Reference<string> s = str;
    Assert::IsTrue(is<object>(s));
  }
  
  TEST(Is, ConstRefStringIsIComparable) {
    const string str = "Test";
    const Reference<string> s = str;
    Assert::IsTrue(is<IComparable>(s));
  }
  
  TEST(Is, ConstRefStringIsInt32) {
    const string str = "Test";
    const Reference<string> s = str;
    Assert::IsFalse(is<Int32>(s));
  }
  
  TEST(Is, ConstRefObjectFromConstRefStringIsString) {
    const string str = "Test";
    const Reference<object> o = str;
    Assert::IsTrue(is<string>(o));
  }
  
  TEST(Is, ConstRefObjectFromConstRefStringIsObject) {
    const string str = "Test";
    const Reference<object> o = str;
    Assert::IsTrue(is<object>(o));
  }
  
  TEST(Is, ConstRefObjectFormConstRefStringIsIComparable) {
    const string str = "Test";
    const Reference<object> o = str;
    Assert::IsTrue(is<IComparable>(o));
  }
  
  TEST(Is, ConstRefObjectFormConstRefStringIsInt32) {
    const string str = "Test";
    const Reference<object> o = str;
    Assert::IsFalse(is<Int32>(o));
  }
  
  TEST(Is, ConstRefStringNullIsString) {
    const Reference<string> s = Reference<string>::Null();
    Assert::IsFalse(is<string>(s));
  }
  
  TEST(Is, ConstRefStringNullIsObject) {
    const Reference<string> s = Reference<string>::Null();
    Assert::IsFalse(is<object>(s));
  }
  
  TEST(Is, ConstRefStringNullIsIComparable) {
    const Reference<string> s = Reference<string>::Null();
    Assert::IsFalse(is<IComparable>(s));
  }
  
  TEST(Is, ConstRefStringNullIsInt32) {
    const Reference<string> s = Reference<string>::Null();
    Assert::IsFalse(is<Int32>(s));
  }
  
  TEST(Is, ConstRefObjectFromConstRefStringNullIsString) {
    const Reference<object> o = as<object>(Reference<string>::Null());
    Assert::IsFalse(is<string>(o));
  }
  
  TEST(Is, ConstRefObjectFromConstRefStringNullIsObject) {
    const Reference<object> o = as<object>(Reference<string>::Null());
    Assert::IsFalse(is<object>(o));
  }
  
  TEST(Is, ConstRefObjectFormConstRefStringNullIsIComparable) {
    const Reference<object> o = as<object>(Reference<string>::Null());
    Assert::IsFalse(is<IComparable>(o));
  }
  
  TEST(Is, ConstRefObjectFormConstRefStringNullIsInt32) {
    const Reference<object> o = as<object>(Reference<string>::Null());
    Assert::IsFalse(is<Int32>(o));
  }
}
