#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>

namespace TUnit {
  /// @brief TestFixture is...
  class TestFixture : public object {
  public:
    virtual void SetUp() {}
    virtual void TearDown() {}
  };

  /// @cond
  class UnitTest;
  /// @endcond

  struct RegisteredTest {
  protected:
    template<typename T>
    RegisteredTest(void (T::*test)()) : RegisteredTest(test, false) {}
    template<typename T>
    RegisteredTest(void (T::*test)(), bool ignore) : testFixture(ref_new<T>()), test(as<T>(testFixture)(), test), ignore(ignore) {RegisteredTests().Add(*this);}

  private:
    friend class UnitTest;
    refptr<TUnit::TestFixture> testFixture;
    delegate<void> test;
    bool ignore = false;
    static System::Collections::Generic::List<ref<RegisteredTest>>& RegisteredTests() {
      static System::Collections::Generic::List<ref<RegisteredTest>> registeredTests;
      return registeredTests;
    }
  };

  /// @brief UnitTest is...
  class UnitTest {
  public:
    void Run() {
      for (auto registeredTest : RegisteredTest::RegisteredTests()) {
        if (!registeredTest().ignore) {
          registeredTest().testFixture().SetUp();
          registeredTest().test();
          registeredTest().testFixture().TearDown();
        }
      }
    }
  };
}

#define __concat(value1, value2) value1 ## value2
#define __concat2(value1, value2) __concat(value1, value2)

#define _test(method) \
static struct __concat2(RegisteredTest, __LINE__) : public TUnit::RegisteredTest { \
  __concat2(RegisteredTest, __LINE__)() : TUnit::RegisteredTest(&method) {} \
} __concat2(registeredTest, __LINE__);

#define _ignore_test(method) \
static struct __concat2(RegisteredTest, __LINE__) : public TUnit::RegisteredTest { \
  __concat2(RegisteredTest, __LINE__)() : TUnit::RegisteredTest(&method, true) {} \
} __concat2(registeredTest, __LINE__);

using namespace System;
using namespace System::Threading;

namespace Examples {
  class TestFixture1 : public TUnit::TestFixture {
  public:
    void SetUp() override {
      Console::WriteLine("{0}::{1}", _typeof(*this).Name, _caller.MemberNamne);
    }
    
    void TearDown() override {
      Console::WriteLine("{0}::{1}", _typeof(*this).Name, _caller.MemberNamne);
    }
    
    void Test1() {
      Console::WriteLine("{0}::{1}", _typeof(*this).Name, _caller.MemberNamne);
    }
  };
 
  static struct RegisteredTest1 : public TUnit::RegisteredTest {
    RegisteredTest1() : TUnit::RegisteredTest(&TestFixture1::Test1) {}
  } registeredTest1;
  //_test(TestFixture1::Test1)

  class TestFixture2 : public TUnit::TestFixture {
  public:
    void Test1() {
      Console::WriteLine("{0}::{1}", _typeof(*this).Name, _caller.MemberNamne);
    }
    
    void Test2() {
      Console::WriteLine("{0}::{1}", _typeof(*this).Name, _caller.MemberNamne);
    }
  };
  
  _test(TestFixture2::Test1)
  _test(TestFixture2::Test2)

  class TestFixture3 : public TUnit::TestFixture {
  public:
    void Test1() {
      Console::WriteLine("{0}::{1}", _typeof(*this).Name, _caller.MemberNamne);
    }
    
    void Test2() {
      Console::WriteLine("{0}::{1}", _typeof(*this).Name, _caller.MemberNamne);
    }
    
    void Test3() {
      Console::WriteLine("{0}::{1}", _typeof(*this).Name, _caller.MemberNamne);
    }
    
    void Test4() {
      Console::WriteLine("{0}::{1}", _typeof(*this).Name, _caller.MemberNamne);
    }
  };
  
  _test(TestFixture3::Test1)
  _test(TestFixture3::Test2)
  _test(TestFixture3::Test3)
  _ignore_test(TestFixture3::Test4)

  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      TUnit::UnitTest().Run();
    }
  };
}

_startup (Examples::Program)
