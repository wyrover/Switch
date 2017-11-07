#include <Switch/Any.hpp>
#include <Switch/As.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(AsTest, StringAsString) {
    string s = "Test";
    string& r = as<string>(s);
    GTEST_ASSERT_EQ(&s, &r);
  }
  
  TEST(AsTest, StringAsObject) {
    string s = "Test";
    object& r = as<object>(s);
    GTEST_ASSERT_EQ(&s, &r);
  }
  
  TEST(AsTest, StringAsIComparable) {
    string s = "Test";
    IComparable& r = as<IComparable>(s);
    GTEST_ASSERT_EQ(&s, &r);
  }
  
  TEST(AsTest, StringAsInt32) {
    string s = "Test";
    ASSERT_THROW(as<Int32>(s), InvalidCastException);
  }
  
  TEST(AsTest, ObjectFromStringAsString) {
    string s = "Test";
    object& o = s;
    string& r = as<string>(o);
    GTEST_ASSERT_EQ(&s, &r);
  }
  
  TEST(AsTest, ObjectFromStringAsObject) {
    string s = "Test";
    object& o = s;
    object& r = as<object>(o);
    GTEST_ASSERT_EQ(&s, &r);
  }
  
  TEST(AsTest, ObjectFromStringAsIComparable) {
    string s = "Test";
    object& o = s;
    IComparable& r = as<IComparable>(o);
    GTEST_ASSERT_EQ(&s, &r);
  }
  
  
  TEST(AsTest, ObjectFromStringAsInt32) {
    string s = "Test";
    object& o = s;
    ASSERT_THROW(as<Int32>(o), InvalidCastException);
  }
  
  TEST(AsTest, ConstStringAsString) {
    const string s = "Test";
    const string& r = as<string>(s);
    GTEST_ASSERT_EQ(&s, &r);
  }
  
  TEST(AsTest, ConstStringAsObject) {
    const string s = "Test";
    const object& r = as<object>(s);
    GTEST_ASSERT_EQ(&s, &r);
  }
  
  TEST(AsTest, ConstStringAsIComparable) {
    const string s = "Test";
    const IComparable& r = as<IComparable>(s);
    GTEST_ASSERT_EQ(&s, &r);
  }
  
  TEST(AsTest, ConstStringAsInt32) {
    const string s = "Test";
    ASSERT_THROW(as<Int32>(s), InvalidCastException);
  }
  
  TEST(AsTest, ConstObjectFromStringAsString) {
    const string s = "Test";
    const object& o = s;
    const string& r = as<string>(o);
    GTEST_ASSERT_EQ(&s, &r);
  }
  
  TEST(AsTest, ConstObjectFromConstStringAsObject) {
    const string s = "Test";
    const object& o = s;
    const object& r = as<object>(o);
    GTEST_ASSERT_EQ(&s, &r);
  }
  
  TEST(AsTest, ConstObjectFromConstStringAsIComparable) {
    const string s = "Test";
    const object& o = s;
    const IComparable& r = as<IComparable>(o);
    GTEST_ASSERT_EQ(&s, &r);
  }
  
  TEST(AsTest, ConstObjectFromConstStringAsInt32) {
    const string s = "Test";
    const object& o = s;
    ASSERT_THROW(as<Int32>(o), InvalidCastException);
  }
  
  TEST(AsTest, StringPtrAsString) {
    string str = "test";
    string* s = &str;
    string* r = as<string>(s);
    GTEST_ASSERT_EQ(s, r);
  }
  
  TEST(AsTest, StringPtrAsObject) {
    string str = "test";
    string* s = &str;
    object* r = as<object>(s);
    GTEST_ASSERT_EQ(s, r);
  }
  
  TEST(AsTest, StringPtrAsIComparable) {
    string str = "test";
    string* s = &str;
    IComparable* r = as<IComparable>(s);
    GTEST_ASSERT_EQ(s, r);
  }
  
  TEST(AsTest, StringPtrAsInt32) {
    string str = "test";
    string* s = &str;
    ASSERT_THROW(as<Int32>(s), InvalidCastException);
  }
  
  TEST(AsTest, ObjectPtrFromStringPtrAsString) {
    string str = "test";
    string* s = &str;
    object* o = s;
    string* r = as<string>(o);
    GTEST_ASSERT_EQ(s, r);
  }
  
  TEST(AsTest, ObjectPtrFromStringPtrAsObject) {
    string str = "test";
    string* s = &str;
    object* o = s;
    object* r = as<object>(o);
    GTEST_ASSERT_EQ(s, r);
  }
  
  TEST(AsTest, ObjectPtrFromStringPtrAsIComparable) {
    string str = "test";
    string* s = &str;
    object* o = s;
    IComparable* r = as<IComparable>(o);
    GTEST_ASSERT_EQ(s, r);
  }
  
  TEST(AsTest, ObjectPtrFromStringPtrAsInt32) {
    string str = "test";
    string* s = &str;
    object* o = s;
    ASSERT_THROW(as<Int32>(o), InvalidCastException);
  }
  
  TEST(AsTest, StringPtrNullAsString) {
    string* s = null;
    string* r = as<string>(s);
    ASSERT_EQ(null, r);
  }
  
  TEST(AsTest, StringPtrNullAsObject) {
    string* s = null;
    object* r = as<object>(s);
    ASSERT_EQ(null, r);
  }
  
  TEST(AsTest, StringPtrNullAsIComparable) {
    string* s = null;
    IComparable* r = as<IComparable>(s);
    ASSERT_EQ(null, r);
  }
  
  TEST(AsTest, StringPtrNullAsInt32) {
    string* s = null;
    IComparable* r = as<Int32>(s);
    ASSERT_EQ(null, r);
  }
  
  TEST(AsTest, ObjectPtrFromStringPtrNullAsString) {
    string* s = null;
    object* o = s;
    string* r = as<string>(o);
    ASSERT_EQ(null, r);
  }
  
  TEST(AsTest, ObjectPtrFromStringPtrNullAsObject) {
    string* s = null;
    object* o = s;
    object* r = as<object>(o);
    ASSERT_EQ(null, r);
  }
  
  TEST(AsTest, ObjectPtrFromStringPtrNullAsIComparable) {
    string* s = null;
    object* o = s;
    IComparable* r = as<IComparable>(o);
    ASSERT_EQ(null, r);
  }
  
  TEST(AsTest, ObjectPtrFromStringPtrNullAsInt32) {
    string* s = null;
    object* o = s;
    Int32* r = as<Int32>(o);
    ASSERT_EQ(null, r);
  }
  
  TEST(AsTest, ConstStringPtrAsString) {
    string str = "test";
    const string* s = &str;
    const string* r = as<string>(s);
    GTEST_ASSERT_EQ(s, r);
  }
  
  TEST(AsTest, ConstStringPtrAsObject) {
    string str = "test";
    const string* s = &str;
    const object* r = as<object>(s);
    GTEST_ASSERT_EQ(s, r);
  }
  
  TEST(AsTest, ConstStringPtrAsIComparable) {
    string str = "test";
    const string* s = &str;
    const IComparable* r = as<IComparable>(s);
    GTEST_ASSERT_EQ(s, r);
  }
  
  TEST(AsTest, ConstStringPtrAsInt32) {
    string str = "test";
    const string* s = &str;
    ASSERT_THROW(as<Int32>(s), InvalidCastException);
  }
  
  TEST(AsTest, ConstObjectPtrFromStringPtrAsString) {
    string str = "test";
    const string* s = &str;
    const object* o = s;
    const string* r = as<string>(o);
    GTEST_ASSERT_EQ(s, r);
  }
  
  TEST(AsTest, ConstObjectPtrFromStringPtrAsObject) {
    string str = "test";
    const string* s = &str;
    const object* o = s;
    const object* r = as<object>(o);
    GTEST_ASSERT_EQ(s, r);
  }
  
  TEST(AsTest, ConstObjectPtrFromStringPtrAsIComparable) {
    string str = "test";
    const string* s = &str;
    const object* o = s;
    const IComparable* r = as<IComparable>(o);
    GTEST_ASSERT_EQ(s, r);
  }
  
  TEST(AsTest, ConstObjectPtrFromStringPtrAsInt32) {
    string str = "test";
    const string* s = &str;
    const object* o = s;
    ASSERT_THROW(as<Int32>(o), InvalidCastException);
  }
  
  TEST(AsTest, ConstStringPtrNullAsString) {
    const string* s = null;
    const string* r = as<string>(s);
    ASSERT_EQ(null, r);
  }
  
  TEST(AsTest, ConstStringPtrNullAsObject) {
    const string* s = null;
    const object* r = as<object>(s);
    ASSERT_EQ(null, r);
  }
  
  TEST(AsTest, ConstStringPtrNullAsIComparable) {
    const string* s = null;
    const IComparable* r = as<IComparable>(s);
    ASSERT_EQ(null, r);
  }
  
  TEST(AsTest, ConstStringPtrNullAsInt32) {
    const string* s = null;
    const Int32* r = as<Int32>(s);
    ASSERT_EQ(null, r);
  }
  
  TEST(AsTest, ConstObjectPtrFromStringPtrNullAsString) {
    const string* s = null;
    const object* o = s;
    const string* r = as<string>(o);
    ASSERT_EQ(null, r);
  }
  
  TEST(AsTest, ConstObjectPtrFromStringPtrNullAsObject) {
    const string* s = null;
    const object* o = s;
    const object* r = as<object>(o);
    ASSERT_EQ(null, r);
  }
  
  TEST(AsTest, ConstObjectPtrFromStringPtrNullAsIComparable) {
    const string* s = null;
    const object* o = s;
    const IComparable* r = as<IComparable>(o);
    ASSERT_EQ(null, r);
  }
  
  TEST(AsTest, ConstObjectPtrFromStringPtrNullAsInt32) {
    const string* s = null;
    const object* o = s;
    const Int32* r = as<Int32>(o);
    ASSERT_EQ(null, r);
  }
  
  TEST(AsTest, RefPtrStringAsString) {
    refptr<string> s = ref_new<string>("Test");
    refptr<string> r = as<string>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, RefPtrStringAsObject) {
    refptr<string> s = ref_new<string>("Test");
    refptr<object> r = as<object>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, RefPtrStringAsIComparable) {
    refptr<string> s = ref_new<string>("Test");
    refptr<IComparable> r = as<IComparable>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, RefPtrStringAsInt32) {
    refptr<string> s = ref_new<string>("Test");
    refptr<Int32> r = as<Int32>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefPtrObjectFromStringAsString) {
    refptr<string> s = ref_new<string>("Test");
    refptr<object> o = as<object>(s);
    refptr<string> r = as<string>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, RefPtrObjectFromStringAsObject) {
    refptr<string> s = ref_new<string>("Test");
    refptr<object> o = as<object>(s);
    refptr<object> r = as<object>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, RefPtrObjectFromStringAsIComparable) {
    refptr<string> s = ref_new<string>("Test");
    refptr<object> o = as<object>(s);
    refptr<IComparable> r = as<IComparable>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, RefPtrObjectFromStringAsInt32) {
    refptr<string> s = ref_new<string>("Test");
    refptr<object> o = as<object>(s);
    refptr<Int32> r = as<Int32>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefPtrStringNullAsString) {
    refptr<string> s = refptr<string>::Null();
    refptr<string> r = as<string>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefPtrStringNullAsObject) {
    refptr<string> s = refptr<string>::Null();
    refptr<object> r = as<object>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefPtrStringNullAsIComparable) {
    refptr<string> s = refptr<string>::Null();
    refptr<IComparable> r = as<IComparable>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefPtrStringNullAsInt32) {
    refptr<string> s = refptr<string>::Null();
    refptr<Int32> r = as<Int32>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefPtrObjectFromStringNullAsString) {
    refptr<string> s = refptr<string>::Null();
    refptr<object> o = as<object>(s);
    refptr<string> r = as<string>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefPtrObjectFromStringNullAsObject) {
    refptr<string> s = refptr<string>::Null();
    refptr<object> o = as<object>(s);
    refptr<object> r = as<object>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefPtrObjectFromStringNullAsIComparable) {
    refptr<string> s = refptr<string>::Null();
    refptr<object> o = as<object>(s);
    refptr<IComparable> r = as<IComparable>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefPtrObjectFromStringNullAsInt32) {
    refptr<string> s = refptr<string>::Null();
    refptr<object> o = as<object>(s);
    refptr<Int32> r = as<Int32>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstSpStringAsString) {
    const refptr<string> s = ref_new<string>("Test");
    const refptr<string> r = as<string>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, ConstSpStringAsObject) {
    const refptr<string> s = ref_new<string>("Test");
    const refptr<object> r = as<object>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, ConstSpStringAsIComparable) {
    const refptr<string> s = ref_new<string>("Test");
    const refptr<IComparable> r = as<IComparable>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, ConstSpStringAsInt32) {
    const refptr<string> s = ref_new<string>("Test");
    const refptr<Int32> r = as<Int32>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstSpObjectFromStringAsString) {
    const refptr<string> s = ref_new<string>("Test");
    const refptr<object> o = as<object>(s);
    const refptr<string> r = as<string>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, ConstSpObjectFromStringAsObject) {
    const refptr<string> s = ref_new<string>("Test");
    const refptr<object> o = as<object>(s);
    const refptr<object> r = as<object>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, ConstSpObjectFromStringAsIComparable) {
    const refptr<string> s = ref_new<string>("Test");
    const refptr<object> o = as<object>(s);
    const refptr<IComparable> r = as<IComparable>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, ConstSpObjectFromStringAsInt32) {
    const refptr<string> s = ref_new<string>("Test");
    const refptr<object> o = as<object>(s);
    const refptr<Int32> r = as<Int32>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstSpStringNullAsString) {
    const refptr<string> s = refptr<string>::Null();
    const refptr<string> r = as<string>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstSpStringNullAsObject) {
    const refptr<string> s = refptr<string>::Null();
    const refptr<object> r = as<object>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstSpStringNullAsIComparable) {
    const refptr<string> s = refptr<string>::Null();
    const refptr<IComparable> r = as<IComparable>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstSpStringNullAsInt32) {
    const refptr<string> s = refptr<string>::Null();
    const refptr<Int32> r = as<Int32>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstSpObjectFromStringNullAsString) {
    const refptr<string> s = refptr<string>::Null();
    const refptr<object> o = as<object>(s);
    const refptr<string> r = as<string>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstSpObjectFromStringNullAsObject) {
    const refptr<string> s = refptr<string>::Null();
    const refptr<object> o = as<object>(s);
    const refptr<object> r = as<object>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstSpObjectFromStringNullAsIComparable) {
    const refptr<string> s = refptr<string>::Null();
    const refptr<object> o = as<object>(s);
    const refptr<IComparable> r = as<IComparable>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstSpObjectFromStringNullAsInt32) {
    const refptr<string> s = refptr<string>::Null();
    const refptr<object> o = as<object>(s);
    const refptr<Int32> r = as<Int32>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefStringAsString) {
    string str = "Test";
    ref<string> s = str;
    ref<string> r = as<string>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, RefStringAsObject) {
    string str = "Test";
    ref<string> s = str;
    ref<object> r = as<object>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, RefStringAsIComparable) {
    string str = "Test";
    ref<string> s = str;
    ref<IComparable> r = as<IComparable>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, RefStringAsInt32) {
    string str = "Test";
    ref<string> s = str;
    ref<Int32> r = as<Int32>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefObjectFromStringAsString) {
    string str = "Test";
    ref<string> s = str;
    ref<object> o = as<object>(s);
    ref<string> r = as<string>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, RefObjectFromStringAsObject) {
    string str = "Test";
    ref<string> s = str;
    ref<object> o = as<object>(s);
    ref<object> r = as<object>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, RefObjectFromStringAsIComparable) {
    string str = "Test";
    ref<string> s = str;
    ref<object> o = as<object>(s);
    ref<IComparable> r = as<IComparable>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, RefObjectFromStringAsInt32) {
    string str = "Test";
    ref<string> s = str;
    ref<object> o = as<object>(s);
    ref<Int32> r = as<Int32>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefStringNullAsString) {
    ref<string> s = ref<string>::Null();
    ref<string> r = as<string>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefStringNullAsObject) {
    ref<string> s = ref<string>::Null();
    ref<object> r = as<object>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefStringNullAsIComparable) {
    ref<string> s = ref<string>::Null();
    ref<IComparable> r = as<IComparable>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefStringNullAsInt32) {
    ref<string> s = ref<string>::Null();
    ref<Int32> r = as<Int32>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefObjectFromStringNullAsString) {
    ref<string> s = ref<string>::Null();
    ref<object> o = as<object>(s);
    ref<string> r = as<string>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefObjectFromStringNullAsObject) {
    ref<string> s = ref<string>::Null();
    ref<object> o = as<object>(s);
    ref<object> r = as<object>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefObjectFromStringNullAsIComparable) {
    ref<string> s = ref<string>::Null();
    ref<object> o = as<object>(s);
    ref<IComparable> r = as<IComparable>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, RefObjectFromStringNullAsInt32) {
    ref<string> s = ref<string>::Null();
    ref<object> o = as<object>(s);
    ref<Int32> r = as<Int32>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstRefStringAsString) {
    const string str = "Test";
    const ref<string> s = str;
    const ref<string> r = as<string>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, ConstRefStringAsObject) {
    const string str = "Test";
    const ref<string> s = str;
    const ref<object> r = as<object>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, ConstRefStringAsIComparable) {
    const string str = "Test";
    const ref<string> s = str;
    const ref<IComparable> r = as<IComparable>(s);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, ConstRefStringAsInt32) {
    const string str = "Test";
    const ref<string> s = str;
    const ref<Int32> r = as<Int32>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstRefObjectFromStringAsString) {
    const string str = "Test";
    const ref<string> s = str;
    const ref<object> o = as<object>(s);
    const ref<string> r = as<string>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, ConstRefObjectFromStringAsObject) {
    const string str = "Test";
    const ref<string> s = str;
    const ref<object> o = as<object>(s);
    const ref<object> r = as<object>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, ConstRefObjectFromStringAsIComparable) {
    const string str = "Test";
    const ref<string> s = str;
    const ref<object> o = as<object>(s);
    const ref<IComparable> r = as<IComparable>(o);
    GTEST_ASSERT_EQ(s.ToPointer(), r.ToPointer());
  }
  
  TEST(AsTest, ConstRefObjectFromStringAsInt32) {
    const string str = "Test";
    const ref<string> s = str;
    const ref<object> o = as<object>(s);
    const ref<Int32> r = as<Int32>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstRefStringNullAsString) {
    const ref<string> s = ref<string>::Null();
    const ref<string> r = as<string>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstRefStringNullAsObject) {
    const ref<string> s = ref<string>::Null();
    const ref<object> r = as<object>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstRefStringNullAsIComparable) {
    const ref<string> s = ref<string>::Null();
    const ref<IComparable> r = as<IComparable>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstRefStringNullAsInt32) {
    const ref<string> s = ref<string>::Null();
    const ref<Int32> r = as<Int32>(s);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstRefObjectFromStringNullAsString) {
    const ref<string> s = ref<string>::Null();
    const ref<object> o = as<object>(s);
    const ref<string> r = as<string>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstRefObjectFromStringNullAsObject) {
    const ref<string> s = ref<string>::Null();
    const ref<object> o = as<object>(s);
    const ref<object> r = as<object>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstRefObjectFromStringNullAsIComparable) {
    const ref<string> s = ref<string>::Null();
    const ref<object> o = as<object>(s);
    const ref<IComparable> r = as<IComparable>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, ConstRefObjectFromStringNullAsInt32) {
    const ref<string> s = ref<string>::Null();
    const ref<object> o = as<object>(s);
    const ref<Int32> r = as<Int32>(o);
    ASSERT_TRUE(r == null);
  }
  
  TEST(AsTest, AnyInt32ToInt32) {
    Any a = 42;
    int32 b = as<Int32>(a);
    GTEST_ASSERT_EQ(42, b);
  }
  
  TEST(AsTest, AnyInt32ToString) {
    Any a = 42;
    string b = a.ToString();
    GTEST_ASSERT_EQ("42", b);
  }
  
  TEST(AsTest, Int32DifferentOfZeroAsBool) {
    int32 a = 42;
    bool b = as<bool>(a);
    ASSERT_TRUE(b);
  }
  
  TEST(AsTest, Int32EqualsToZeroAsBool) {
    int32 a = 0;
    bool b = as<bool>(a);
    ASSERT_FALSE(b);
  }
  
  TEST(AsTest, Int32AsByte) {
    int32 a = 42;
    byte b = as<byte>(a);
    GTEST_ASSERT_EQ(42, b);
  }
  
  TEST(AsTest, Int32AsString) {
    int32 a = 42;
    string b = as<string>(a);
    GTEST_ASSERT_EQ("42", b);
  }
}
