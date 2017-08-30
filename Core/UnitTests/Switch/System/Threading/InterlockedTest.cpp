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
      Assert::AreEqual(45, Interlocked::Add(location, 3), pcf_current_information);
      Assert::AreEqual(45, location, pcf_current_information);
    }

    void AddInt64() {
      int64 location = 42;
      Assert::AreEqual(45, Interlocked::Add(location, 3), pcf_current_information);
      Assert::AreEqual(45, location, pcf_current_information);
    }
    
    void CompareExchangeDoubleIfComparandEqual() {
      double location = 0.42;
      Assert::AreEqual(0.42, Interlocked::CompareExchange(location, 0.24, 0.42), pcf_current_information);
      Assert::AreEqual(0.24, location, pcf_current_information);
    }
    
    void CompareExchangeDoubleIfComparandDifferent() {
      double location = 0.42;
      Assert::AreEqual(0.42, Interlocked::CompareExchange(location, 0.24, 0.33), pcf_current_information);
      Assert::AreEqual(0.42, location, pcf_current_information);
    }
    
    void CompareExchangeInt32IfComparandEqual() {
      int32 location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 42), pcf_current_information);
      Assert::AreEqual(24, location, pcf_current_information);
    }
    
    void CompareExchangeInt32IfComparandDifferent() {
      int32 location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 33), pcf_current_information);
      Assert::AreEqual(42, location, pcf_current_information);
    }
    
    void CompareExchangeInt64IfComparandEqual() {
      int64 location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 42), pcf_current_information);
      Assert::AreEqual(24, location, pcf_current_information);
    }
    
    void CompareExchangeInt64IfComparandDifferent() {
      int64 location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 33), pcf_current_information);
      Assert::AreEqual(42, location, pcf_current_information);
    }
    
    void CompareExchangeIntPtrIfComparandEqual() {
      intptr location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 42), pcf_current_information);
      Assert::AreEqual(24, location, pcf_current_information);
    }
    
    void CompareExchangeIntPtrIfComparandDifferent() {
      intptr location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 33), pcf_current_information);
      Assert::AreEqual(42, location, pcf_current_information);
    }
    
    void CompareExchangeVoidPointerIfComparandEqual() {
      int a = 1;
      int b = 2;
      void* location = &a;
      Assert::AreEqual(&a, Interlocked::CompareExchange(location, &b, &a), pcf_current_information);
      Assert::AreEqual(&b, location, pcf_current_information);
    }
    
    void CompareExchangeVoidPointerIfComparandDifferent() {
      int a = 1;
      int b = 2;
      void* location = &a;
      Assert::AreEqual(&a, Interlocked::CompareExchange(location, &b, &b), pcf_current_information);
      Assert::AreEqual(&a, location, pcf_current_information);
    }
    
    void CompareExchangeSingleIfComparandEqual() {
      float location = 0.42f;
      Assert::AreEqual(0.42f, Interlocked::CompareExchange(location, 0.24f, 0.42f), pcf_current_information);
      Assert::AreEqual(0.24f, location, pcf_current_information);
    }
    
    void CompareExchangeSingleIfComparandDifferent() {
      float location = 0.42f;
      Assert::AreEqual(0.42f, Interlocked::CompareExchange(location, 0.24f, 0.33f), pcf_current_information);
      Assert::AreEqual(0.42f, location, pcf_current_information);
    }
    
    void CompareExchangeTemplateIfComparandEqual() {
      string location = "str1";
      Assert::AreEqual("str1", Interlocked::CompareExchange(location, "str2"_S, "str1"_S), pcf_current_information);
      Assert::AreEqual("str2", location, pcf_current_information);
    }
    
    void CompareExchangeTemplateIfComparandDifferent() {
      string location = "str1";
      Assert::AreEqual("str1", Interlocked::CompareExchange(location, "str2"_S, "str"_S), pcf_current_information);
      Assert::AreEqual("str1", location, pcf_current_information);
    }
    
    void DecrementInt32() {
      int32 location = 42;
      Assert::AreEqual(41, Interlocked::Decrement(location), pcf_current_information);
      Assert::AreEqual(41, location, pcf_current_information);
    }
    
    void DecrementInt64() {
      int64 location = 42;
      Assert::AreEqual(41, Interlocked::Decrement(location), pcf_current_information);
      Assert::AreEqual(41, location, pcf_current_information);
    }

    void ExchangeDouble() {
      double location = 0.42;
      Assert::AreEqual(0.42, Interlocked::Exchange(location, 0.24), pcf_current_information);
      Assert::AreEqual(0.24, location, pcf_current_information);
    }
    
    void ExchangeInt32() {
      int32 location = 42;
      Assert::AreEqual(42, Interlocked::Exchange(location, 24), pcf_current_information);
      Assert::AreEqual(24, location, pcf_current_information);
    }
    
    void ExchangeInt64() {
      int64 location = 42;
      Assert::AreEqual(42, Interlocked::Exchange(location, 24), pcf_current_information);
      Assert::AreEqual(24, location, pcf_current_information);
    }
    
    void ExchangeIntPtr() {
      intptr location = 42;
      Assert::AreEqual(42, Interlocked::Exchange(location, 24), pcf_current_information);
      Assert::AreEqual(24, location, pcf_current_information);
    }
    
    void ExchangeVoidPointer() {
      int a = 1;
      int b = 2;
      void* location = &a;
      Assert::AreEqual(&a, Interlocked::Exchange(location, &b), pcf_current_information);
      Assert::AreEqual(&b, location, pcf_current_information);
    }
    
    void ExchangeSingle() {
      float location = 0.42f;
      Assert::AreEqual(0.42f, Interlocked::Exchange(location, 0.24f), pcf_current_information);
      Assert::AreEqual(0.24f, location, pcf_current_information);
    }
    
    void ExchangeTemplate() {
      string location = "str1";
      Assert::AreEqual("str1", Interlocked::Exchange(location, "str2"_s), pcf_current_information);
      Assert::AreEqual("str2", location, pcf_current_information);
    }
    
    void IncrementInt32() {
      int32 location = 42;
      Assert::AreEqual(43, Interlocked::Increment(location), pcf_current_information);
      Assert::AreEqual(43, location, pcf_current_information);
    }
    
    void IncrementInt64() {
      int64 location = 42;
      Assert::AreEqual(43, Interlocked::Increment(location), pcf_current_information);
      Assert::AreEqual(43, location, pcf_current_information);
    }
  };
  
  pcf_test(InterlockedTest, AddInt32)
  pcf_test(InterlockedTest, AddInt64)
  pcf_test(InterlockedTest, CompareExchangeDoubleIfComparandEqual)
  pcf_test(InterlockedTest, CompareExchangeDoubleIfComparandDifferent)
  pcf_test(InterlockedTest, CompareExchangeInt32IfComparandEqual)
  pcf_test(InterlockedTest, CompareExchangeInt32IfComparandDifferent)
  pcf_test(InterlockedTest, CompareExchangeInt64IfComparandEqual)
  pcf_test(InterlockedTest, CompareExchangeInt64IfComparandDifferent)
  pcf_test(InterlockedTest, CompareExchangeIntPtrIfComparandEqual)
  pcf_test(InterlockedTest, CompareExchangeIntPtrIfComparandDifferent)
  pcf_test(InterlockedTest, CompareExchangeVoidPointerIfComparandEqual)
  pcf_test(InterlockedTest, CompareExchangeVoidPointerIfComparandDifferent)
  pcf_test(InterlockedTest, CompareExchangeSingleIfComparandEqual)
  pcf_test(InterlockedTest, CompareExchangeSingleIfComparandDifferent)
  pcf_test(InterlockedTest, CompareExchangeTemplateIfComparandEqual)
  pcf_test(InterlockedTest, CompareExchangeTemplateIfComparandDifferent)
  pcf_test(InterlockedTest, DecrementInt32)
  pcf_test(InterlockedTest, DecrementInt64)
  pcf_test(InterlockedTest, ExchangeDouble)
  pcf_test(InterlockedTest, ExchangeInt32)
  pcf_test(InterlockedTest, ExchangeInt64)
  pcf_test(InterlockedTest, ExchangeIntPtr)
  pcf_test(InterlockedTest, ExchangeVoidPointer)
  pcf_test(InterlockedTest, ExchangeSingle)
  pcf_test(InterlockedTest, ExchangeTemplate)
}
