#include <Switch/System/Threading/Timer.hpp>
#include <Switch/System/Threading/Interlocked.hpp>
#include <Switch/System/Double.hpp>
#include <Switch/System/Math.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>
#include <Switch/LiteralOperatorConverter.hpp>

using namespace System;
using namespace System::Threading;
using namespace TUnit;

namespace SwitchUnitTests {
  class InterlockedTest : public TestFixture {
  protected:
    void AddInt32() {
      int32 location = 42;
      Assert::AreEqual(45, Interlocked::Add(location, 3), sw_current_information);
      Assert::AreEqual(45, location, sw_current_information);
    }

    void AddInt64() {
      int64 location = 42;
      Assert::AreEqual(45, Interlocked::Add(location, 3), sw_current_information);
      Assert::AreEqual(45, location, sw_current_information);
    }
    
    void CompareExchangeDoubleIfComparandEqual() {
      double location = 0.42;
      Assert::AreEqual(0.42, Interlocked::CompareExchange(location, 0.24, 0.42), sw_current_information);
      Assert::AreEqual(0.24, location, sw_current_information);
    }
    
    void CompareExchangeDoubleIfComparandDifferent() {
      double location = 0.42;
      Assert::AreEqual(0.42, Interlocked::CompareExchange(location, 0.24, 0.33), sw_current_information);
      Assert::AreEqual(0.42, location, sw_current_information);
    }
    
    void CompareExchangeInt32IfComparandEqual() {
      int32 location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 42), sw_current_information);
      Assert::AreEqual(24, location, sw_current_information);
    }
    
    void CompareExchangeInt32IfComparandDifferent() {
      int32 location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 33), sw_current_information);
      Assert::AreEqual(42, location, sw_current_information);
    }
    
    void CompareExchangeInt64IfComparandEqual() {
      int64 location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 42), sw_current_information);
      Assert::AreEqual(24, location, sw_current_information);
    }
    
    void CompareExchangeInt64IfComparandDifferent() {
      int64 location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 33), sw_current_information);
      Assert::AreEqual(42, location, sw_current_information);
    }
    
    void CompareExchangeIntPtrIfComparandEqual() {
      intptr location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 42), sw_current_information);
      Assert::AreEqual(24, location, sw_current_information);
    }
    
    void CompareExchangeIntPtrIfComparandDifferent() {
      intptr location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 33), sw_current_information);
      Assert::AreEqual(42, location, sw_current_information);
    }
    
    void CompareExchangeVoidPointerIfComparandEqual() {
      int a = 1;
      int b = 2;
      void* location = &a;
      Assert::AreEqual(&a, Interlocked::CompareExchange(location, &b, &a), sw_current_information);
      Assert::AreEqual(&b, location, sw_current_information);
    }
    
    void CompareExchangeVoidPointerIfComparandDifferent() {
      int a = 1;
      int b = 2;
      void* location = &a;
      Assert::AreEqual(&a, Interlocked::CompareExchange(location, &b, &b), sw_current_information);
      Assert::AreEqual(&a, location, sw_current_information);
    }
    
    void CompareExchangeSingleIfComparandEqual() {
      float location = 0.42f;
      Assert::AreEqual(0.42f, Interlocked::CompareExchange(location, 0.24f, 0.42f), sw_current_information);
      Assert::AreEqual(0.24f, location, sw_current_information);
    }
    
    void CompareExchangeSingleIfComparandDifferent() {
      float location = 0.42f;
      Assert::AreEqual(0.42f, Interlocked::CompareExchange(location, 0.24f, 0.33f), sw_current_information);
      Assert::AreEqual(0.42f, location, sw_current_information);
    }
    
    void CompareExchangeTemplateIfComparandEqual() {
      string location = "str1";
      Assert::AreEqual("str1", Interlocked::CompareExchange(location, "str2"_S, "str1"_S), sw_current_information);
      Assert::AreEqual("str2", location, sw_current_information);
    }
    
    void CompareExchangeTemplateIfComparandDifferent() {
      string location = "str1";
      Assert::AreEqual("str1", Interlocked::CompareExchange(location, "str2"_S, "str"_S), sw_current_information);
      Assert::AreEqual("str1", location, sw_current_information);
    }
    
    void DecrementInt32() {
      int32 location = 42;
      Assert::AreEqual(41, Interlocked::Decrement(location), sw_current_information);
      Assert::AreEqual(41, location, sw_current_information);
    }
    
    void DecrementInt64() {
      int64 location = 42;
      Assert::AreEqual(41, Interlocked::Decrement(location), sw_current_information);
      Assert::AreEqual(41, location, sw_current_information);
    }

    void ExchangeDouble() {
      double location = 0.42;
      Assert::AreEqual(0.42, Interlocked::Exchange(location, 0.24), sw_current_information);
      Assert::AreEqual(0.24, location, sw_current_information);
    }
    
    void ExchangeInt32() {
      int32 location = 42;
      Assert::AreEqual(42, Interlocked::Exchange(location, 24), sw_current_information);
      Assert::AreEqual(24, location, sw_current_information);
    }
    
    void ExchangeInt64() {
      int64 location = 42;
      Assert::AreEqual(42, Interlocked::Exchange(location, 24), sw_current_information);
      Assert::AreEqual(24, location, sw_current_information);
    }
    
    void ExchangeIntPtr() {
      intptr location = 42;
      Assert::AreEqual(42, Interlocked::Exchange(location, 24), sw_current_information);
      Assert::AreEqual(24, location, sw_current_information);
    }
    
    void ExchangeVoidPointer() {
      int a = 1;
      int b = 2;
      void* location = &a;
      Assert::AreEqual(&a, Interlocked::Exchange(location, &b), sw_current_information);
      Assert::AreEqual(&b, location, sw_current_information);
    }
    
    void ExchangeSingle() {
      float location = 0.42f;
      Assert::AreEqual(0.42f, Interlocked::Exchange(location, 0.24f), sw_current_information);
      Assert::AreEqual(0.24f, location, sw_current_information);
    }
    
    void ExchangeTemplate() {
      string location = "str1";
      Assert::AreEqual("str1", Interlocked::Exchange(location, "str2"_s), sw_current_information);
      Assert::AreEqual("str2", location, sw_current_information);
    }
    
    void IncrementInt32() {
      int32 location = 42;
      Assert::AreEqual(43, Interlocked::Increment(location), sw_current_information);
      Assert::AreEqual(43, location, sw_current_information);
    }
    
    void IncrementInt64() {
      int64 location = 42;
      Assert::AreEqual(43, Interlocked::Increment(location), sw_current_information);
      Assert::AreEqual(43, location, sw_current_information);
    }
  };
  
  sw_test(InterlockedTest, AddInt32)
  sw_test(InterlockedTest, AddInt64)
  sw_test(InterlockedTest, CompareExchangeDoubleIfComparandEqual)
  sw_test(InterlockedTest, CompareExchangeDoubleIfComparandDifferent)
  sw_test(InterlockedTest, CompareExchangeInt32IfComparandEqual)
  sw_test(InterlockedTest, CompareExchangeInt32IfComparandDifferent)
  sw_test(InterlockedTest, CompareExchangeInt64IfComparandEqual)
  sw_test(InterlockedTest, CompareExchangeInt64IfComparandDifferent)
  sw_test(InterlockedTest, CompareExchangeIntPtrIfComparandEqual)
  sw_test(InterlockedTest, CompareExchangeIntPtrIfComparandDifferent)
  sw_test(InterlockedTest, CompareExchangeVoidPointerIfComparandEqual)
  sw_test(InterlockedTest, CompareExchangeVoidPointerIfComparandDifferent)
  sw_test(InterlockedTest, CompareExchangeSingleIfComparandEqual)
  sw_test(InterlockedTest, CompareExchangeSingleIfComparandDifferent)
  sw_test(InterlockedTest, CompareExchangeTemplateIfComparandEqual)
  sw_test(InterlockedTest, CompareExchangeTemplateIfComparandDifferent)
  sw_test(InterlockedTest, DecrementInt32)
  sw_test(InterlockedTest, DecrementInt64)
  sw_test(InterlockedTest, ExchangeDouble)
  sw_test(InterlockedTest, ExchangeInt32)
  sw_test(InterlockedTest, ExchangeInt64)
  sw_test(InterlockedTest, ExchangeIntPtr)
  sw_test(InterlockedTest, ExchangeVoidPointer)
  sw_test(InterlockedTest, ExchangeSingle)
  sw_test(InterlockedTest, ExchangeTemplate)
}
