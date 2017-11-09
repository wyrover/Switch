#include <Switch/Any.hpp>
#include <Switch/Unused.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(AnyTest, HasValueOnEmpty) {
    any a;
    ASSERT_FALSE(a.HasValue);
  }
  
  TEST(AnyTest, ValueOnEmpty) {
    any a;
    ASSERT_THROW(const object& o = a.Value; Unused(o), InvalidOperationException);
  }
  
  TEST(AnyTest, AsInt32OnEmpty) {
    any a;
    ASSERT_THROW(a.As<Int32>(), InvalidOperationException);
  }
  
  TEST(AnyTest, AsStringOnEmpty) {
    any a;
    ASSERT_THROW(a.As<string>(), InvalidOperationException);
  }

  /*
  TEST(AnyTest, EqualsOnEmpty) {
    any a;
    ASSERT_EQ(any(), a);
  }
  */

  TEST(AnyTest, GetHashCodeOnEmpty) {
    any a;
    ASSERT_EQ(0, a.GetHashCode());
  }

  TEST(AnyTest, IsInt32OnEmpty) {
    any a;
    ASSERT_FALSE(a.Is<Int32>());
  }
  
  TEST(AnyTest, IsStringOnEmpty) {
    any a;
    ASSERT_FALSE(a.Is<string>());
  }
  
  TEST(AnyTest, ToStringOnEmpty) {
    any a;
    ASSERT_EQ("", a.ToString());
  }
  
  TEST(AnyTest, ImplicitCastToInt32OnEmpty) {
    any a;
    ASSERT_THROW(int i = a; Unused(i), InvalidOperationException);
  }
  
  TEST(AnyTest, ImplicitCastToStringOnEmpty) {
    any a;
    ASSERT_THROW(string s = a; Unused(s), InvalidOperationException);
  }
  
  TEST(AnyTest, HasValueOnInt32) {
    any a = 42;
    ASSERT_TRUE(a.HasValue);
  }
  
  TEST(AnyTest, ValueOnInt32) {
    any a = 42;
    ASSERT_EQ(42, as<Int32>(a.Value()));
  }
  
  TEST(AnyTest, AsInt32OnInt32) {
    any a = 42;
    ASSERT_NO_THROW(a.As<Int32>());
  }
  
  TEST(AnyTest, AsStringOnInt32) {
    any a = 42;
    ASSERT_THROW(a.As<string>(), InvalidCastException);
  }
  
  /*
  TEST(AnyTest, EqualsOnInt32) {
    any a = 42;
    ASSERT_EQ(any(42), a);
    ASSERT_NE(any(43), a);
  }
  */
  
  TEST(AnyTest, GetHashCodeOnInt32) {
    any a = 42;
    ASSERT_EQ(42, a.GetHashCode());
  }
  
  TEST(AnyTest, IsInt32OnInt32) {
    any a = 42;
    ASSERT_TRUE(a.Is<Int32>());
  }
  
  TEST(AnyTest, IsStringOnInt32) {
    any a = 42;
    ASSERT_FALSE(a.Is<string>());
  }
  
  TEST(AnyTest, ToStringOnInt32) {
    any a = 42;
    ASSERT_EQ("42", a.ToString());
  }
  
  TEST(AnyTest, ImplicitCastToInt32OnInt32) {
    any a = 42;
    int32 i = a;
    ASSERT_EQ(42, i);
  }
  
  TEST(AnyTest, ImplicitCastToStringOnInt32) {
    any a = 42;
    string s = a;
    ASSERT_EQ("42", s);
  }
  
  TEST(AnyTest, HasValueOnString) {
    any a = "Forty two";
    ASSERT_TRUE(a.HasValue);
  }
  
  TEST(AnyTest, ValueOnString) {
    any a = "Forty two";
    ASSERT_EQ("Forty two", as<string>(a.Value()));
  }
  
  TEST(AnyTest, AsInt32OnString) {
    any a = "Forty two";
    ASSERT_THROW(a.As<Int32>(), InvalidCastException);
  }
  
  TEST(AnyTest, AsStringOnString) {
    any a = "Forty two";
    ASSERT_NO_THROW(a.As<string>(););
  }
  
  /*
  TEST(AnyTest, EqualsOnString) {
    any a = "Forty two";
    ASSERT_EQ(any("Forty two"), a);
    ASSERT_NE(any("Forty three"), a);
  }
  */
  
  TEST(AnyTest, GetHashCodeOnString) {
    any a = "Forty two";
    ASSERT_EQ(38242606, a.GetHashCode());
  }
  
  TEST(AnyTest, IsInt32OnString) {
    any a = "Forty two";
    ASSERT_FALSE(a.Is<Int32>());
  }
  
  TEST(AnyTest, IsStringOnString) {
    any a = "Forty two";
    ASSERT_TRUE(a.Is<string>());
  }
  
  TEST(AnyTest, ToStringOnString) {
    any a = "Forty two";
    ASSERT_EQ("Forty two", a.ToString());
  }
  
  TEST(AnyTest, ImplicitCastToStringOnString) {
    any a = "Forty two";
    string s = a;
    ASSERT_EQ("Forty two", s);
  }
  
  TEST(AnyTest, ImplicitCastToInt32OnString) {
    any a = "Forty two";
    ASSERT_THROW(int i = a; Unused(i), InvalidCastException);
  }
  
  TEST(AnyTest, AnyFormInt32ThanFromString) {
    any a= 42;
    ASSERT_EQ(42, as<Int32>(a));
    a = "Forty two";
    ASSERT_EQ("Forty two", as<string>(a));
  }
}
