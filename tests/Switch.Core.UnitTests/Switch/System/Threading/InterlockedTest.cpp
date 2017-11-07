#include <Switch/System/Threading/Timer.hpp>
#include <Switch/System/Threading/Interlocked.hpp>
#include <Switch/System/Double.hpp>
#include <Switch/System/Math.hpp>
#include <gtest/gtest.h>
#include <Switch/LiteralOperatorConverter.hpp>

using namespace System;
using namespace System::Threading;

namespace SwitchUnitTests {
  TEST(InterlockedTest, AddInt32) {
    int32 location = 42;
    ASSERT_EQ(45, Interlocked::Add(location, 3));
    ASSERT_EQ(45, location);
  }
  
  TEST(InterlockedTest, AddInt64) {
    int64 location = 42;
    ASSERT_EQ(45, Interlocked::Add(location, 3));
    ASSERT_EQ(45, location);
  }
  
  TEST(InterlockedTest, CompareExchangeDoubleIfComparandEqual) {
    double location = 0.42;
    ASSERT_EQ(0.42, Interlocked::CompareExchange(location, 0.24, 0.42));
    ASSERT_EQ(0.24, location);
  }
  
  TEST(InterlockedTest, CompareExchangeDoubleIfComparandDifferent) {
    double location = 0.42;
    ASSERT_EQ(0.42, Interlocked::CompareExchange(location, 0.24, 0.33));
    ASSERT_EQ(0.42, location);
  }
  
  TEST(InterlockedTest, CompareExchangeInt32IfComparandEqual) {
    int32 location = 42;
    ASSERT_EQ(42, Interlocked::CompareExchange(location, 24, 42));
    ASSERT_EQ(24, location);
  }
  
  TEST(InterlockedTest, CompareExchangeInt32IfComparandDifferent) {
    int32 location = 42;
    ASSERT_EQ(42, Interlocked::CompareExchange(location, 24, 33));
    ASSERT_EQ(42, location);
  }
  
  TEST(InterlockedTest, CompareExchangeInt64IfComparandEqual) {
    int64 location = 42;
    ASSERT_EQ(42, Interlocked::CompareExchange(location, 24, 42));
    ASSERT_EQ(24, location);
  }
  
  TEST(InterlockedTest, CompareExchangeInt64IfComparandDifferent) {
    int64 location = 42;
    ASSERT_EQ(42, Interlocked::CompareExchange(location, 24, 33));
    ASSERT_EQ(42, location);
  }
  
  TEST(InterlockedTest, CompareExchangeIntPtrIfComparandEqual) {
    intptr location = 42;
    ASSERT_EQ(42, Interlocked::CompareExchange(location, 24, 42));
    ASSERT_EQ(24, location);
  }
  
  TEST(InterlockedTest, CompareExchangeIntPtrIfComparandDifferent) {
    intptr location = 42;
    ASSERT_EQ(42, Interlocked::CompareExchange(location, 24, 33));
    ASSERT_EQ(42, location);
  }
  
  TEST(InterlockedTest, CompareExchangeVoidPointerIfComparandEqual) {
    int a = 1;
    int b = 2;
    void* location = &a;
    ASSERT_EQ(&a, Interlocked::CompareExchange(location, &b, &a));
    ASSERT_EQ(&b, location);
  }
  
  TEST(InterlockedTest, CompareExchangeVoidPointerIfComparandDifferent) {
    int a = 1;
    int b = 2;
    void* location = &a;
    ASSERT_EQ(&a, Interlocked::CompareExchange(location, &b, &b));
    ASSERT_EQ(&a, location);
  }
  
  TEST(InterlockedTest, CompareExchangeSingleIfComparandEqual) {
    float location = 0.42f;
    ASSERT_EQ(0.42f, Interlocked::CompareExchange(location, 0.24f, 0.42f));
    ASSERT_EQ(0.24f, location);
  }
  
  TEST(InterlockedTest, CompareExchangeSingleIfComparandDifferent) {
    float location = 0.42f;
    ASSERT_EQ(0.42f, Interlocked::CompareExchange(location, 0.24f, 0.33f));
    ASSERT_EQ(0.42f, location);
  }
  
  TEST(InterlockedTest, CompareExchangeTemplateIfComparandEqual) {
    string location = "str1";
    ASSERT_EQ("str1", Interlocked::CompareExchange(location, "str2"_S, "str1"_S));
    ASSERT_EQ("str2", location);
  }
  
  TEST(InterlockedTest, CompareExchangeTemplateIfComparandDifferent) {
    string location = "str1";
    ASSERT_EQ("str1", Interlocked::CompareExchange(location, "str2"_S, "str"_S));
    ASSERT_EQ("str1", location);
  }
  
  TEST(InterlockedTest, DecrementInt32) {
    int32 location = 42;
    ASSERT_EQ(41, Interlocked::Decrement(location));
    ASSERT_EQ(41, location);
  }
  
  TEST(InterlockedTest, DecrementInt64) {
    int64 location = 42;
    ASSERT_EQ(41, Interlocked::Decrement(location));
    ASSERT_EQ(41, location);
  }
  
  TEST(InterlockedTest, ExchangeDouble) {
    double location = 0.42;
    ASSERT_EQ(0.42, Interlocked::Exchange(location, 0.24));
    ASSERT_EQ(0.24, location);
  }
  
  TEST(InterlockedTest, ExchangeInt32) {
    int32 location = 42;
    ASSERT_EQ(42, Interlocked::Exchange(location, 24));
    ASSERT_EQ(24, location);
  }
  
  TEST(InterlockedTest, ExchangeInt64) {
    int64 location = 42;
    ASSERT_EQ(42, Interlocked::Exchange(location, 24));
    ASSERT_EQ(24, location);
  }
  
  TEST(InterlockedTest, ExchangeIntPtr) {
    intptr location = 42;
    ASSERT_EQ(42, Interlocked::Exchange(location, 24));
    ASSERT_EQ(24, location);
  }
  
  TEST(InterlockedTest, ExchangeVoidPointer) {
    int a = 1;
    int b = 2;
    void* location = &a;
    ASSERT_EQ(&a, Interlocked::Exchange(location, &b));
    ASSERT_EQ(&b, location);
  }
  
  TEST(InterlockedTest, ExchangeSingle) {
    float location = 0.42f;
    ASSERT_EQ(0.42f, Interlocked::Exchange(location, 0.24f));
    ASSERT_EQ(0.24f, location);
  }
  
  TEST(InterlockedTest, ExchangeTemplate) {
    string location = "str1";
    ASSERT_EQ("str1", Interlocked::Exchange(location, "str2"_s));
    ASSERT_EQ("str2", location);
  }
  
  TEST(InterlockedTest, IncrementInt32) {
    int32 location = 42;
    ASSERT_EQ(43, Interlocked::Increment(location));
    ASSERT_EQ(43, location);
  }
  
  TEST(InterlockedTest, IncrementInt64) {
    int64 location = 42;
    ASSERT_EQ(43, Interlocked::Increment(location));
    ASSERT_EQ(43, location);
  }
}

