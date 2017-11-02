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
      Assert::AreEqual(45, Interlocked::Add(location, 3), _caller);
      Assert::AreEqual(45, location, _caller);
    }

    void AddInt64() {
      int64 location = 42;
      Assert::AreEqual(45, Interlocked::Add(location, 3), _caller);
      Assert::AreEqual(45, location, _caller);
    }
    
    void CompareExchangeDoubleIfComparandEqual() {
      double location = 0.42;
      Assert::AreEqual(0.42, Interlocked::CompareExchange(location, 0.24, 0.42), _caller);
      Assert::AreEqual(0.24, location, _caller);
    }
    
    void CompareExchangeDoubleIfComparandDifferent() {
      double location = 0.42;
      Assert::AreEqual(0.42, Interlocked::CompareExchange(location, 0.24, 0.33), _caller);
      Assert::AreEqual(0.42, location, _caller);
    }
    
    void CompareExchangeInt32IfComparandEqual() {
      int32 location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 42), _caller);
      Assert::AreEqual(24, location, _caller);
    }
    
    void CompareExchangeInt32IfComparandDifferent() {
      int32 location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 33), _caller);
      Assert::AreEqual(42, location, _caller);
    }
    
    void CompareExchangeInt64IfComparandEqual() {
      int64 location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 42), _caller);
      Assert::AreEqual(24, location, _caller);
    }
    
    void CompareExchangeInt64IfComparandDifferent() {
      int64 location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 33), _caller);
      Assert::AreEqual(42, location, _caller);
    }
    
    void CompareExchangeIntPtrIfComparandEqual() {
      intptr location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 42), _caller);
      Assert::AreEqual(24, location, _caller);
    }
    
    void CompareExchangeIntPtrIfComparandDifferent() {
      intptr location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 33), _caller);
      Assert::AreEqual(42, location, _caller);
    }
    
    void CompareExchangeVoidPointerIfComparandEqual() {
      int a = 1;
      int b = 2;
      void* location = &a;
      Assert::AreEqual(&a, Interlocked::CompareExchange(location, &b, &a), _caller);
      Assert::AreEqual(&b, location, _caller);
    }
    
    void CompareExchangeVoidPointerIfComparandDifferent() {
      int a = 1;
      int b = 2;
      void* location = &a;
      Assert::AreEqual(&a, Interlocked::CompareExchange(location, &b, &b), _caller);
      Assert::AreEqual(&a, location, _caller);
    }
    
    void CompareExchangeSingleIfComparandEqual() {
      float location = 0.42f;
      Assert::AreEqual(0.42f, Interlocked::CompareExchange(location, 0.24f, 0.42f), _caller);
      Assert::AreEqual(0.24f, location, _caller);
    }
    
    void CompareExchangeSingleIfComparandDifferent() {
      float location = 0.42f;
      Assert::AreEqual(0.42f, Interlocked::CompareExchange(location, 0.24f, 0.33f), _caller);
      Assert::AreEqual(0.42f, location, _caller);
    }
    
    void CompareExchangeTemplateIfComparandEqual() {
      string location = "str1";
      Assert::AreEqual("str1", Interlocked::CompareExchange(location, "str2"_S, "str1"_S), _caller);
      Assert::AreEqual("str2", location, _caller);
    }
    
    void CompareExchangeTemplateIfComparandDifferent() {
      string location = "str1";
      Assert::AreEqual("str1", Interlocked::CompareExchange(location, "str2"_S, "str"_S), _caller);
      Assert::AreEqual("str1", location, _caller);
    }
    
    void DecrementInt32() {
      int32 location = 42;
      Assert::AreEqual(41, Interlocked::Decrement(location), _caller);
      Assert::AreEqual(41, location, _caller);
    }
    
    void DecrementInt64() {
      int64 location = 42;
      Assert::AreEqual(41, Interlocked::Decrement(location), _caller);
      Assert::AreEqual(41, location, _caller);
    }

    void ExchangeDouble() {
      double location = 0.42;
      Assert::AreEqual(0.42, Interlocked::Exchange(location, 0.24), _caller);
      Assert::AreEqual(0.24, location, _caller);
    }
    
    void ExchangeInt32() {
      int32 location = 42;
      Assert::AreEqual(42, Interlocked::Exchange(location, 24), _caller);
      Assert::AreEqual(24, location, _caller);
    }
    
    void ExchangeInt64() {
      int64 location = 42;
      Assert::AreEqual(42, Interlocked::Exchange(location, 24), _caller);
      Assert::AreEqual(24, location, _caller);
    }
    
    void ExchangeIntPtr() {
      intptr location = 42;
      Assert::AreEqual(42, Interlocked::Exchange(location, 24), _caller);
      Assert::AreEqual(24, location, _caller);
    }
    
    void ExchangeVoidPointer() {
      int a = 1;
      int b = 2;
      void* location = &a;
      Assert::AreEqual(&a, Interlocked::Exchange(location, &b), _caller);
      Assert::AreEqual(&b, location, _caller);
    }
    
    void ExchangeSingle() {
      float location = 0.42f;
      Assert::AreEqual(0.42f, Interlocked::Exchange(location, 0.24f), _caller);
      Assert::AreEqual(0.24f, location, _caller);
    }
    
    void ExchangeTemplate() {
      string location = "str1";
      Assert::AreEqual("str1", Interlocked::Exchange(location, "str2"_s), _caller);
      Assert::AreEqual("str2", location, _caller);
    }
    
    void IncrementInt32() {
      int32 location = 42;
      Assert::AreEqual(43, Interlocked::Increment(location), _caller);
      Assert::AreEqual(43, location, _caller);
    }
    
    void IncrementInt64() {
      int64 location = 42;
      Assert::AreEqual(43, Interlocked::Increment(location), _caller);
      Assert::AreEqual(43, location, _caller);
    }
  };
  
  _add_test(InterlockedTest, AddInt32)
  _add_test(InterlockedTest, AddInt64)
  _add_test(InterlockedTest, CompareExchangeDoubleIfComparandEqual)
  _add_test(InterlockedTest, CompareExchangeDoubleIfComparandDifferent)
  _add_test(InterlockedTest, CompareExchangeInt32IfComparandEqual)
  _add_test(InterlockedTest, CompareExchangeInt32IfComparandDifferent)
  _add_test(InterlockedTest, CompareExchangeInt64IfComparandEqual)
  _add_test(InterlockedTest, CompareExchangeInt64IfComparandDifferent)
  _add_test(InterlockedTest, CompareExchangeIntPtrIfComparandEqual)
  _add_test(InterlockedTest, CompareExchangeIntPtrIfComparandDifferent)
  _add_test(InterlockedTest, CompareExchangeVoidPointerIfComparandEqual)
  _add_test(InterlockedTest, CompareExchangeVoidPointerIfComparandDifferent)
  _add_test(InterlockedTest, CompareExchangeSingleIfComparandEqual)
  _add_test(InterlockedTest, CompareExchangeSingleIfComparandDifferent)
  _add_test(InterlockedTest, CompareExchangeTemplateIfComparandEqual)
  _add_test(InterlockedTest, CompareExchangeTemplateIfComparandDifferent)
  _add_test(InterlockedTest, DecrementInt32)
  _add_test(InterlockedTest, DecrementInt64)
  _add_test(InterlockedTest, ExchangeDouble)
  _add_test(InterlockedTest, ExchangeInt32)
  _add_test(InterlockedTest, ExchangeInt64)
  _add_test(InterlockedTest, ExchangeIntPtr)
  _add_test(InterlockedTest, ExchangeVoidPointer)
  _add_test(InterlockedTest, ExchangeSingle)
  _add_test(InterlockedTest, ExchangeTemplate)
}
