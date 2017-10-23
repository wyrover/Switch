#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>

// to hpp file

namespace TUnit {
  /// @cond
  class TestFixture;
  class UnitTest;
  
  struct __opaque_registered_test {
  protected:
    friend class UnitTest;
    __opaque_registered_test(refptr<TestFixture> testFixture, delegate<void> test) : testFixture(testFixture), test(test) {RegisteredTests().Add(*this);}
    refptr<TestFixture> testFixture;

  private:
    delegate<void> test;
    static System::Collections::Generic::List<ref<__opaque_registered_test>>& RegisteredTests() {
      static System::Collections::Generic::List<ref<__opaque_registered_test>> registeredTests;
      return registeredTests;
    }
  };
  /// @endcond
  
  /// @brief TestFixture is...
  class TestFixture : public object {
  public:
    TestFixture() {}

    virtual void SetUp() {}
    virtual void TearDown() {}
  };
  
  /// @brief UnitTest is...
  class UnitTest {
  public:
    void Run() {
      for (auto registeredTest : __opaque_registered_test::RegisteredTests()) {
        registeredTest().testFixture->SetUp();
        registeredTest().test();
        registeredTest().testFixture->TearDown();
      }
    }
  };
}

#define _test(fixtureClass, method) \
static struct __opaque_registered_test_##fixtureClass##method : public TUnit::__opaque_registered_test { \
  __opaque_registered_test_##fixtureClass##method() : TUnit::__opaque_registered_test(ref_new<fixtureClass>(), _delegate {as<fixtureClass>(this->testFixture)->method();}) {} \
} __opaque_registered_test_value_##fixtureClass##method;

using namespace System;
using namespace System::Threading;

namespace Examples {
  class TestFixture1 : public TUnit::TestFixture {
  public:
    void SetUp() override {
      Console::WriteLine("{0}::{1}", _typeof(*this), _caller.MemberNamne);
    }
    
    void TearDown() override {
      Console::WriteLine("{0}::{1}", _typeof(*this), _caller.MemberNamne);
    }
    
    void Test1() {
      Console::WriteLine("{0}::{1}", _typeof(*this), _caller.MemberNamne);
    }
  };
  
  _test(TestFixture1, Test1)

  class TestFixture2 : public TUnit::TestFixture {
  public:
    void SetUp() override {
      Console::WriteLine("{0}::{1}", _typeof(*this), _caller.MemberNamne);
    }
    
    void TearDown() override {
      Console::WriteLine("{0}::{1}", _typeof(*this), _caller.MemberNamne);
    }
    
    void Test1() {
      Console::WriteLine("{0}::{1}", _typeof(*this), _caller.MemberNamne);
    }
    
    void Test2() {
      Console::WriteLine("{0}::{1}", _typeof(*this), _caller.MemberNamne);
    }
  };
  
  _test(TestFixture2, Test1)
  _test(TestFixture2, Test2)

  class TestFixture3 : public TUnit::TestFixture {
  public:
    void SetUp() override {
      Console::WriteLine("{0}::{1}", _typeof(*this), _caller.MemberNamne);
    }
    
    void TearDown() override {
      Console::WriteLine("{0}::{1}", _typeof(*this), _caller.MemberNamne);
    }
    
    void Test1() {
      Console::WriteLine("{0}::{1}", _typeof(*this), _caller.MemberNamne);
    }
    
    void Test2() {
      Console::WriteLine("{0}::{1}", _typeof(*this), _caller.MemberNamne);
    }
    
    void Test3() {
      Console::WriteLine("{0}::{1}", _typeof(*this), _caller.MemberNamne);
    }
  };
  
  _test(TestFixture3, Test1)
  _test(TestFixture3, Test2)
  _test(TestFixture3, Test3)

  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      TUnit::UnitTest().Run();
    }
  };
}

_startup (Examples::Program)

