#include <Switch/System/Predicate.hpp>
#include <Switch/System/String.hpp>
#include <Switch/Using.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  class MyClass : public object {
  public:
    static bool IsEmpty(const string& str) { return string::IsNullOrEmpty(str); }
    bool IsNotEmpty(const string& str) { return !string::IsNullOrEmpty(str); }
  };
  
  TEST(PrediacateTest, Static) {
    _using(Predicate<const string&> p(&MyClass::IsEmpty)) {
      ASSERT_FALSE(p("Not empty"));
      ASSERT_TRUE(p(""));
    }
  }
  
  TEST(PrediacateTest, Member) {
    MyClass m;
    _using(Predicate<const string&> p(m, &MyClass::IsNotEmpty)) {
      ASSERT_TRUE(p("Not empty"));
      ASSERT_FALSE(p(""));
    }
  }
  
  TEST(PrediacateTest, Empty) {
    _using(Predicate<const string&> p) {
      ASSERT_NO_THROW(p("Not empty"));
      ASSERT_NO_THROW(p(""));
    }
  }
}

