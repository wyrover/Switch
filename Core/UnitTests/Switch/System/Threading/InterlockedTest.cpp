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
      Assert::AreEqual(45, Interlocked::Add(location, 3), _current_information);
      Assert::AreEqual(45, location, _current_information);
    }

    void AddInt64() {
      int64 location = 42;
      Assert::AreEqual(45, Interlocked::Add(location, 3), _current_information);
      Assert::AreEqual(45, location, _current_information);
    }
    
    void CompareExchangeDoubleIfComparandEqual() {
      double location = 0.42;
      Assert::AreEqual(0.42, Interlocked::CompareExchange(location, 0.24, 0.42), _current_information);
      Assert::AreEqual(0.24, location, _current_information);
    }
    
    void CompareExchangeDoubleIfComparandDifferent() {
      double location = 0.42;
      Assert::AreEqual(0.42, Interlocked::CompareExchange(location, 0.24, 0.33), _current_information);
      Assert::AreEqual(0.42, location, _current_information);
    }
    
    void CompareExchangeInt32IfComparandEqual() {
      int32 location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 42), _current_information);
      Assert::AreEqual(24, location, _current_information);
    }
    
    void CompareExchangeInt32IfComparandDifferent() {
      int32 location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 33), _current_information);
      Assert::AreEqual(42, location, _current_information);
    }
    
    void CompareExchangeInt64IfComparandEqual() {
      int64 location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 42), _current_information);
      Assert::AreEqual(24, location, _current_information);
    }
    
    void CompareExchangeInt64IfComparandDifferent() {
      int64 location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 33), _current_information);
      Assert::AreEqual(42, location, _current_information);
    }
    
    void CompareExchangeIntPtrIfComparandEqual() {
      intptr location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 42), _current_information);
      Assert::AreEqual(24, location, _current_information);
    }
    
    void CompareExchangeIntPtrIfComparandDifferent() {
      intptr location = 42;
      Assert::AreEqual(42, Interlocked::CompareExchange(location, 24, 33), _current_information);
      Assert::AreEqual(42, location, _current_information);
    }
    
    void CompareExchangeVoidPointerIfComparandEqual() {
      int a = 1;
      int b = 2;
      void* location = &a;
      Assert::AreEqual(&a, Interlocked::CompareExchange(location, &b, &a), _current_information);
      Assert::AreEqual(&b, location, _current_information);
    }
    
    void CompareExchangeVoidPointerIfComparandDifferent() {
      int a = 1;
      int b = 2;
      void* location = &a;
      Assert::AreEqual(&a, Interlocked::CompareExchange(location, &b, &b), _current_information);
      Assert::AreEqual(&a, location, _current_information);
    }
    
    void CompareExchangeSingleIfComparandEqual() {
      float location = 0.42f;
      Assert::AreEqual(0.42f, Interlocked::CompareExchange(location, 0.24f, 0.42f), _current_information);
      Assert::AreEqual(0.24f, location, _current_information);
    }
    
    void CompareExchangeSingleIfComparandDifferent() {
      float location = 0.42f;
      Assert::AreEqual(0.42f, Interlocked::CompareExchange(location, 0.24f, 0.33f), _current_information);
      Assert::AreEqual(0.42f, location, _current_information);
    }
    
    void CompareExchangeTemplateIfComparandEqual() {
      string location = "str1";
      Assert::AreEqual("str1", Interlocked::CompareExchange(location, "str2"_S, "str1"_S), _current_information);
      Assert::AreEqual("str2", location, _current_information);
    }
    
    void CompareExchangeTemplateIfComparandDifferent() {
      string location = "str1";
      Assert::AreEqual("str1", Interlocked::CompareExchange(location, "str2"_S, "str"_S), _current_information);
      Assert::AreEqual("str1", location, _current_information);
    }
    
    void DecrementInt32() {
      int32 location = 42;
      Assert::AreEqual(41, Interlocked::Decrement(location), _current_information);
      Assert::AreEqual(41, location, _current_information);
    }
    
    void DecrementInt64() {
      int64 location = 42;
      Assert::AreEqual(41, Interlocked::Decrement(location), _current_information);
      Assert::AreEqual(41, location, _current_information);
    }

    void ExchangeDouble() {
      double location = 0.42;
      Assert::AreEqual(0.42, Interlocked::Exchange(location, 0.24), _current_information);
      Assert::AreEqual(0.24, location, _current_information);
    }
    
    void ExchangeInt32() {
      int32 location = 42;
      Assert::AreEqual(42, Interlocked::Exchange(location, 24), _current_information);
      Assert::AreEqual(24, location, _current_information);
    }
    
    void ExchangeInt64() {
      int64 location = 42;
      Assert::AreEqual(42, Interlocked::Exchange(location, 24), _current_information);
      Assert::AreEqual(24, location, _current_information);
    }
    
    void ExchangeIntPtr() {
      intptr location = 42;
      Assert::AreEqual(42, Interlocked::Exchange(location, 24), _current_information);
      Assert::AreEqual(24, location, _current_information);
    }
    
    void ExchangeVoidPointer() {
      int a = 1;
      int b = 2;
      void* location = &a;
      Assert::AreEqual(&a, Interlocked::Exchange(location, &b), _current_information);
      Assert::AreEqual(&b, location, _current_information);
    }
    
    void ExchangeSingle() {
      float location = 0.42f;
      Assert::AreEqual(0.42f, Interlocked::Exchange(location, 0.24f), _current_information);
      Assert::AreEqual(0.24f, location, _current_information);
    }
    
    void ExchangeTemplate() {
      string location = "str1";
      Assert::AreEqual("str1", Interlocked::Exchange(location, "str2"_s), _current_information);
      Assert::AreEqual("str2", location, _current_information);
    }
    
    void IncrementInt32() {
      int32 location = 42;
      Assert::AreEqual(43, Interlocked::Increment(location), _current_information);
      Assert::AreEqual(43, location, _current_information);
    }
    
    void IncrementInt64() {
      int64 location = 42;
      Assert::AreEqual(43, Interlocked::Increment(location), _current_information);
      Assert::AreEqual(43, location, _current_information);
    }
  };
  
  _test(InterlockedTest, AddInt32)
  _test(InterlockedTest, AddInt64)
  _test(InterlockedTest, CompareExchangeDoubleIfComparandEqual)
  _test(InterlockedTest, CompareExchangeDoubleIfComparandDifferent)
  _test(InterlockedTest, CompareExchangeInt32IfComparandEqual)
  _test(InterlockedTest, CompareExchangeInt32IfComparandDifferent)
  _test(InterlockedTest, CompareExchangeInt64IfComparandEqual)
  _test(InterlockedTest, CompareExchangeInt64IfComparandDifferent)
  _test(InterlockedTest, CompareExchangeIntPtrIfComparandEqual)
  _test(InterlockedTest, CompareExchangeIntPtrIfComparandDifferent)
  _test(InterlockedTest, CompareExchangeVoidPointerIfComparandEqual)
  _test(InterlockedTest, CompareExchangeVoidPointerIfComparandDifferent)
  _test(InterlockedTest, CompareExchangeSingleIfComparandEqual)
  _test(InterlockedTest, CompareExchangeSingleIfComparandDifferent)
  _test(InterlockedTest, CompareExchangeTemplateIfComparandEqual)
  _test(InterlockedTest, CompareExchangeTemplateIfComparandDifferent)
  _test(InterlockedTest, DecrementInt32)
  _test(InterlockedTest, DecrementInt64)
  _test(InterlockedTest, ExchangeDouble)
  _test(InterlockedTest, ExchangeInt32)
  _test(InterlockedTest, ExchangeInt64)
  _test(InterlockedTest, ExchangeIntPtr)
  _test(InterlockedTest, ExchangeVoidPointer)
  _test(InterlockedTest, ExchangeSingle)
  _test(InterlockedTest, ExchangeTemplate)
}
