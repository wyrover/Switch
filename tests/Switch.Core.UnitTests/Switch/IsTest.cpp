#include <Switch/Is.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(IsTest, StringIsString) {
    string s = "Test";
    ASSERT_TRUE(is<string>(s));
  }
  
  TEST(IsTest, StringIsObject) {
    string s = "Test";
    ASSERT_TRUE(is<object>(s));
  }
  
  TEST(IsTest, StringIsIComparable) {
    string s = "Test";
    ASSERT_TRUE(is<IComparable>(s));
  }
  
  TEST(IsTest, StringIsInt32) {
    string s = "Test";
    ASSERT_FALSE(is<Int32>(s));
  }
  
  TEST(IsTest, ObjectFromStringIsString) {
    string s = "Test";
    object& o = s;
    ASSERT_TRUE(is<string>(o));
  }
  
  TEST(IsTest, ObjectFromStringIsObject) {
    string s = "Test";
    object& o = s;
    ASSERT_TRUE(is<object>(o));
  }
  
  TEST(IsTest, ObjectFormStringIsIComparable) {
    string s = "Test";
    object& o = s;
    ASSERT_TRUE(is<IComparable>(o));
  }
  
  TEST(IsTest, ObjectFormStringIsInt32) {
    string s = "Test";
    object& o = s;
    ASSERT_FALSE(is<Int32>(o));
  }
  
  TEST(IsTest, ConstStringIsString) {
    const string s = "Test";
    ASSERT_TRUE(is<string>(s));
  }
  
  TEST(IsTest, ConstStringIsObject) {
    const string s = "Test";
    ASSERT_TRUE(is<object>(s));
  }
  
  TEST(IsTest, ConstStringIsIComparable) {
    const string s = "Test";
    ASSERT_TRUE(is<IComparable>(s));
  }
  
  TEST(IsTest, ConstStringIsInt32) {
    const string s = "Test";
    ASSERT_FALSE(is<Int32>(s));
  }
  
  TEST(IsTest, ConstObjectFromStringIsString) {
    const string s = "Test";
    const object& o = s;
    ASSERT_TRUE(is<string>(o));
  }
  
  TEST(IsTest, ConstObjectFromStringIsObject) {
    const string s = "Test";
    const object& o = s;
    ASSERT_TRUE(is<object>(o));
  }
  
  TEST(IsTest, ConstObjectFormStringIsIComparable) {
    const string s = "Test";
    const object& o = s;
    ASSERT_TRUE(is<IComparable>(o));
  }
  
  TEST(IsTest, ConstObjectFormStringIsInt32) {
    const string s = "Test";
    const object& o = s;
    ASSERT_FALSE(is<Int32>(o));
  }
  
  TEST(IsTest, StringPtrIsString) {
    string s = "Test";
    ASSERT_TRUE(is<string>(&s));
  }
  
  TEST(IsTest, StringPtrIsObject) {
    string s = "Test";
    ASSERT_TRUE(is<object>(&s));
  }
  
  TEST(IsTest, StringPtrIsIComparable) {
    string s = "Test";
    ASSERT_TRUE(is<IComparable>(&s));
  }
  
  TEST(IsTest, StringPtrIsInt32) {
    string s = "Test";
    ASSERT_FALSE(is<Int32>(&s));
  }
  
  TEST(IsTest, ObjectPtrFromStringPtrIsString) {
    string s = "Test";
    object* o = &s;
    ASSERT_TRUE(is<string>(o));
  }
  
  TEST(IsTest, ObjectPtrFromStringPtrIsObject) {
    string s = "Test";
    object* o = &s;
    ASSERT_TRUE(is<object>(o));
  }
  
  TEST(IsTest, ObjectPtrFormStringPtrIsIComparable) {
    string s = "Test";
    object* o = &s;
    ASSERT_TRUE(is<IComparable>(o));
  }
  
  TEST(IsTest, ObjectPtrFormStringPtrIsInt32) {
    string s = "Test";
    object* o = &s;
    ASSERT_FALSE(is<Int32>(o));
  }
  
  TEST(IsTest, StringPtrNullIsString) {
    string* s = null;
    ASSERT_FALSE(is<string>(s));
  }
  
  TEST(IsTest, StringPtrNullIsObject) {
    string* s = null;
    ASSERT_FALSE(is<object>(s));
  }
  
  TEST(IsTest, StringPtrNullIsIComparable) {
    string* s = null;
    ASSERT_FALSE(is<IComparable>(s));
  }
  
  TEST(IsTest, StringPtrNullIsInt32) {
    string* s = null;
    ASSERT_FALSE(is<Int32>(s));
  }
  
  TEST(IsTest, ObjectPtrFromStringPtrNullIsString) {
    string* s = null;
    object* o = s;
    ASSERT_FALSE(is<string>(o));
  }
  
  TEST(IsTest, ObjectPtrFromStringPtrNullIsObject) {
    string* s = null;
    object* o = s;
    ASSERT_FALSE(is<object>(o));
  }
  
  TEST(IsTest, ObjectPtrFormStringPtrNullIsIComparable) {
    string* s = null;
    object* o = s;
    ASSERT_FALSE(is<IComparable>(o));
  }
  
  TEST(IsTest, ObjectPtrFormStringPtrNullIsInt32) {
    string* s = null;
    object* o = s;
    ASSERT_FALSE(is<Int32>(o));
  }
  
  TEST(IsTest, ConstStringPtrIsString) {
    string s = "Test";
    const string* cs = &s;
    ASSERT_TRUE(is<string>(cs));
  }
  
  TEST(IsTest, ConstStringPtrIsObject) {
    string s = "Test";
    const string* cs = &s;
    ASSERT_TRUE(is<object>(cs));
  }
  
  TEST(IsTest, ConstStringPtrIsIComparable) {
    string s = "Test";
    const string* cs = &s;
    ASSERT_TRUE(is<IComparable>(cs));
  }
  
  TEST(IsTest, ConstStringPtrIsInt32) {
    string s = "Test";
    const string* cs = &s;
    ASSERT_FALSE(is<Int32>(cs));
  }
  
  TEST(IsTest, ConstObjectPtrFromStringPtrIsString) {
    string s = "Test";
    const object* o = &s;
    ASSERT_TRUE(is<string>(o));
  }
  
  TEST(IsTest, ConstObjectPtrFromStringPtrIsObject) {
    string s = "Test";
    const object* o = &s;
    ASSERT_TRUE(is<object>(o));
  }
  
  TEST(IsTest, ConstObjectPtrFormStringPtrIsIComparable) {
    string s = "Test";
    const object* o = &s;
    ASSERT_TRUE(is<IComparable>(o));
  }
  
  TEST(IsTest, ConstObjectPtrFormStringPtrIsInt32) {
    string s = "Test";
    const object* o = &s;
    ASSERT_FALSE(is<Int32>(o));
  }
  
  TEST(IsTest, ConstStringPtrNullIsString) {
    const string* s = null;
    ASSERT_FALSE(is<string>(s));
  }
  
  TEST(IsTest, ConstStringPtrNullIsObject) {
    const string* s = null;
    ASSERT_FALSE(is<object>(s));
  }
  
  TEST(IsTest, ConstStringPtrNullIsIComparable) {
    const string* s = null;
    ASSERT_FALSE(is<IComparable>(s));
  }
  
  TEST(IsTest, ConstStringPtrNullIsInt32) {
    const string* s = null;
    ASSERT_FALSE(is<Int32>(s));
  }
  
  TEST(IsTest, ConstObjectPtrFromStringPtrNullIsString) {
    const string* s = null;
    const object* o = s;
    ASSERT_FALSE(is<string>(o));
  }
  
  TEST(IsTest, ConstObjectPtrFromStringPtrNullIsObject) {
    const string* s = null;
    const object* o = s;
    ASSERT_FALSE(is<object>(o));
  }
  
  TEST(IsTest, ConstObjectPtrFormStringPtrNullIsIComparable) {
    const string* s = null;
    const object* o = s;
    ASSERT_FALSE(is<IComparable>(o));
  }
  
  TEST(IsTest, ConstObjectPtrFormStringPtrNullIsInt32) {
    const string* s = null;
    const object* o = s;
    ASSERT_FALSE(is<Int32>(o));
  }
  
  TEST(IsTest, SpStringIsString) {
    refptr<string> s = ref_new<String>("Test");
    ASSERT_TRUE(is<string>(s));
  }
  
  TEST(IsTest, SpStringIsObject) {
    refptr<string> s = ref_new<String>("Test");
    ASSERT_TRUE(is<object>(s));
  }
  
  TEST(IsTest, SpStringIsIComparable) {
    refptr<string> s = ref_new<String>("Test");
    ASSERT_TRUE(is<IComparable>(s));
  }
  
  TEST(IsTest, SpStringIsInt32) {
    refptr<string> s = new String("Test");
    ASSERT_FALSE(is<Int32>(s));
  }
  
  TEST(IsTest, SpObjectFromSpStringIsString) {
    refptr<object> o = ref_new<string>("Test");
    ASSERT_TRUE(is<string>(o));
  }
  
  TEST(IsTest, SpObjectFromSpStringIsObject) {
    refptr<object> o = ref_new<string>("Test");
    ASSERT_TRUE(is<object>(o));
  }
  
  TEST(IsTest, SpObjectFormSpStringIsIComparable) {
    refptr<object> o = ref_new<string>("Test");
    ASSERT_TRUE(is<IComparable>(o));
  }
  
  TEST(IsTest, SpObjectFormSpStringIsInt32) {
    refptr<object> o = ref_new<string>("Test");
    ASSERT_FALSE(is<Int32>(o));
  }
  
  TEST(IsTest, SpStringNullIsString) {
    refptr<string> s = refptr<string>::Null();
    ASSERT_FALSE(is<string>(s));
  }
  
  TEST(IsTest, SpStringNullIsObject) {
    refptr<string> s = refptr<string>::Null();
    ASSERT_FALSE(is<object>(s));
  }
  
  TEST(IsTest, SpStringNullIsIComparable) {
    refptr<string> s = refptr<string>::Null();
    ASSERT_FALSE(is<IComparable>(s));
  }
  
  TEST(IsTest, SpStringNullIsInt32) {
    refptr<string> s = refptr<string>::Null();
    ASSERT_FALSE(is<Int32>(s));
  }
  
  TEST(IsTest, SpObjectFromSpStringNullIsString) {
    refptr<object> o = as<object>(refptr<string>::Null());
    ASSERT_FALSE(is<string>(o));
  }
  
  TEST(IsTest, SpObjectFromSpStringNullIsObject) {
    refptr<object> o = as<object>(refptr<string>::Null());
    ASSERT_FALSE(is<object>(o));
  }
  
  TEST(IsTest, SpObjectFormSpStringNullIsIComparable) {
    refptr<object> o = as<object>(refptr<string>::Null());
    ASSERT_FALSE(is<IComparable>(o));
  }
  
  TEST(IsTest, SpObjectFormSpStringNullIsInt32) {
    refptr<object> o = as<object>(refptr<string>::Null());
    ASSERT_FALSE(is<Int32>(o));
  }
  
  TEST(IsTest, ConstSpStringIsString) {
    const refptr<string> s = ref_new<String>("Test");
    ASSERT_TRUE(is<string>(s));
  }
  
  TEST(IsTest, ConstSpStringIsObject) {
    const refptr<string> s = ref_new<String>("Test");
    ASSERT_TRUE(is<object>(s));
  }
  
  TEST(IsTest, ConstSpStringIsIComparable) {
    const refptr<string> s = ref_new<String>("Test");
    ASSERT_TRUE(is<IComparable>(s));
  }
  
  TEST(IsTest, ConstSpStringIsInt32) {
    const refptr<string> s = ref_new<String>("Test");
    ASSERT_FALSE(is<Int32>(s));
  }
  
  TEST(IsTest, ConstSpObjectFromConstSpStringIsString) {
    const refptr<object> o = ref_new<string>("Test");
    ASSERT_TRUE(is<string>(o));
  }
  
  TEST(IsTest, ConstSpObjectFromConstSpStringIsObject) {
    const refptr<object> o = ref_new<string>("Test");
    ASSERT_TRUE(is<object>(o));
  }
  
  TEST(IsTest, ConstSpObjectFormConstSpStringIsIComparable) {
    const refptr<object> o = ref_new<string>("Test");
    ASSERT_TRUE(is<IComparable>(o));
  }
  
  TEST(IsTest, ConstSpObjectFormConstSpStringIsInt32) {
    const refptr<object> o = ref_new<string>("Test");
    ASSERT_FALSE(is<Int32>(o));
  }
  
  TEST(IsTest, ConstSpStringNullIsString) {
    const refptr<string> s = refptr<string>::Null();
    ASSERT_FALSE(is<string>(s));
  }
  
  TEST(IsTest, ConstSpStringNullIsObject) {
    const refptr<string> s = refptr<string>::Null();
    ASSERT_FALSE(is<object>(s));
  }
  
  TEST(IsTest, ConstSpStringNullIsIComparable) {
    const refptr<string> s = refptr<string>::Null();
    ASSERT_FALSE(is<IComparable>(s));
  }
  
  TEST(IsTest, ConstSpStringNullIsInt32) {
    const refptr<string> s = refptr<string>::Null();
    ASSERT_FALSE(is<Int32>(s));
  }
  
  TEST(IsTest, ConstSpObjectFromConstSpStringNullIsString) {
    const refptr<object> o = as<object>(refptr<string>::Null());
    ASSERT_FALSE(is<string>(o));
  }
  
  TEST(IsTest, ConstSpObjectFromConstSpStringNullIsObject) {
    const refptr<object> o = as<object>(refptr<string>::Null());
    ASSERT_FALSE(is<object>(o));
  }
  
  TEST(IsTest, ConstSpObjectFormConstSpStringNullIsIComparable) {
    const refptr<object> o = as<object>(refptr<string>::Null());
    ASSERT_FALSE(is<IComparable>(o));
  }
  
  TEST(IsTest, ConstSpObjectFormConstSpStringNullIsInt32) {
    const refptr<object> o = as<object>(refptr<string>::Null());
    ASSERT_FALSE(is<Int32>(o));
  }
  
  TEST(IsTest, RefStringIsString) {
    string str = "Test";
    ref<string> s = str;
    ASSERT_TRUE(is<string>(s));
  }
  
  TEST(IsTest, RefStringIsObject) {
    string str = "Test";
    ref<string> s = str;
    ASSERT_TRUE(is<object>(s));
  }
  
  TEST(IsTest, RefStringIsIComparable) {
    string str = "Test";
    ref<string> s = str;
    ASSERT_TRUE(is<IComparable>(s));
  }
  
  TEST(IsTest, RefStringIsInt32) {
    string str = "Test";
    ref<string> s = str;
    ASSERT_FALSE(is<Int32>(s));
  }
  
  TEST(IsTest, RefObjectFromRefStringIsString) {
    string str = "Test";
    ref<object> o = str;
    ASSERT_TRUE(is<string>(o));
  }
  
  TEST(IsTest, RefObjectFromRefStringIsObject) {
    string str = "Test";
    ref<object> o = str;
    ASSERT_TRUE(is<object>(o));
  }
  
  TEST(IsTest, RefObjectFormRefStringIsIComparable) {
    string str = "Test";
    ref<object> o = str;
    ASSERT_TRUE(is<IComparable>(o));
  }
  
  TEST(IsTest, RefObjectFormRefStringIsInt32) {
    string str = "Test";
    ref<object> o = str;
    ASSERT_FALSE(is<Int32>(o));
  }
  
  TEST(IsTest, RefStringNullIsString) {
    ref<string> s = ref<string>::Null();
    ASSERT_FALSE(is<string>(s));
  }
  
  TEST(IsTest, RefStringNullIsObject) {
    ref<string> s = ref<string>::Null();
    ASSERT_FALSE(is<object>(s));
  }
  
  TEST(IsTest, RefStringNullIsIComparable) {
    ref<string> s = ref<string>::Null();
    ASSERT_FALSE(is<IComparable>(s));
  }
  
  TEST(IsTest, RefStringNullIsInt32) {
    ref<string> s = ref<string>::Null();
    ASSERT_FALSE(is<Int32>(s));
  }
  
  TEST(IsTest, RefObjectFromRefStringNullIsString) {
    ref<object> o = as<object>(ref<string>::Null());
    ASSERT_FALSE(is<string>(o));
  }
  
  TEST(IsTest, RefObjectFromRefStringNullIsObject) {
    ref<object> o = as<object>(ref<string>::Null());
    ASSERT_FALSE(is<object>(o));
  }
  
  TEST(IsTest, RefObjectFormRefStringNullIsIComparable) {
    ref<object> o = as<object>(ref<string>::Null());
    ASSERT_FALSE(is<IComparable>(o));
  }
  
  TEST(IsTest, RefObjectFormRefStringNullIsInt32) {
    ref<object> o = as<object>(ref<string>::Null());
    ASSERT_FALSE(is<Int32>(o));
  }
  
  TEST(IsTest, ConstRefStringIsString) {
    const string str = "Test";
    const ref<string> s = str;
    ASSERT_TRUE(is<string>(s));
  }
  
  TEST(IsTest, ConstRefStringIsObject) {
    const string str = "Test";
    const ref<string> s = str;
    ASSERT_TRUE(is<object>(s));
  }
  
  TEST(IsTest, ConstRefStringIsIComparable) {
    const string str = "Test";
    const ref<string> s = str;
    ASSERT_TRUE(is<IComparable>(s));
  }
  
  TEST(IsTest, ConstRefStringIsInt32) {
    const string str = "Test";
    const ref<string> s = str;
    ASSERT_FALSE(is<Int32>(s));
  }
  
  TEST(IsTest, ConstRefObjectFromConstRefStringIsString) {
    const string str = "Test";
    const ref<object> o = str;
    ASSERT_TRUE(is<string>(o));
  }
  
  TEST(IsTest, ConstRefObjectFromConstRefStringIsObject) {
    const string str = "Test";
    const ref<object> o = str;
    ASSERT_TRUE(is<object>(o));
  }
  
  TEST(IsTest, ConstRefObjectFormConstRefStringIsIComparable) {
    const string str = "Test";
    const ref<object> o = str;
    ASSERT_TRUE(is<IComparable>(o));
  }
  
  TEST(IsTest, ConstRefObjectFormConstRefStringIsInt32) {
    const string str = "Test";
    const ref<object> o = str;
    ASSERT_FALSE(is<Int32>(o));
  }
  
  TEST(IsTest, ConstRefStringNullIsString) {
    const ref<string> s = ref<string>::Null();
    ASSERT_FALSE(is<string>(s));
  }
  
  TEST(IsTest, ConstRefStringNullIsObject) {
    const ref<string> s = ref<string>::Null();
    ASSERT_FALSE(is<object>(s));
  }
  
  TEST(IsTest, ConstRefStringNullIsIComparable) {
    const ref<string> s = ref<string>::Null();
    ASSERT_FALSE(is<IComparable>(s));
  }
  
  TEST(IsTest, ConstRefStringNullIsInt32) {
    const ref<string> s = ref<string>::Null();
    ASSERT_FALSE(is<Int32>(s));
  }
  
  TEST(IsTest, ConstRefObjectFromConstRefStringNullIsString) {
    const ref<object> o = as<object>(ref<string>::Null());
    ASSERT_FALSE(is<string>(o));
  }
  
  TEST(IsTest, ConstRefObjectFromConstRefStringNullIsObject) {
    const ref<object> o = as<object>(ref<string>::Null());
    ASSERT_FALSE(is<object>(o));
  }
  
  TEST(IsTest, ConstRefObjectFormConstRefStringNullIsIComparable) {
    const ref<object> o = as<object>(ref<string>::Null());
    ASSERT_FALSE(is<IComparable>(o));
  }
  
  TEST(IsTest, ConstRefObjectFormConstRefStringNullIsInt32) {
    const ref<object> o = as<object>(ref<string>::Null());
    ASSERT_FALSE(is<Int32>(o));
  }
}

