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
    RegisteredTest(const string& name, void (T::*test)()) : RegisteredTest(name, test, false) {}
    template<typename T>
    RegisteredTest(const string& name, void (T::*test)(), bool ignore) : name(name.Split(':')[name.Split(':').Length-1]), testFixture(ref_new<T>()), test(as<T>(testFixture)(), test), ignore(ignore) {
      RegisteredTests().Add(*this);
    }

  private:
    friend class UnitTest;
    string name;
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
          System::Console::WriteLine("Running {0}.{1}", registeredTest().testFixture->GetType().Name, registeredTest().name);
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

#define _AddTest(method) \
static struct __concat2(RegisteredTest, __LINE__) : public TUnit::RegisteredTest { \
  __concat2(RegisteredTest, __LINE__)() : TUnit::RegisteredTest(#method, &method) {} \
} __concat2(registeredTest, __LINE__);

#define _add_ignore_test(method) \
static struct __concat2(RegisteredTest, __LINE__) : public TUnit::RegisteredTest { \
  __concat2(RegisteredTest, __LINE__)() : TUnit::RegisteredTest(#method, &method, true) {} \
} __concat2(registeredTest, __LINE__);

#define _TestFixture(name) \
  name : public TUnit::TestFixture

#define _SetUp(name) \
  SetUp() override {name();} \
  void name()

#define _TearDown(name) \
  TearDown() override {name();} \
  void name()

#define _Test(name) \
  name()

using namespace System;
using namespace System::Threading;

namespace Examples {
  class _TestFixture(TestFixture1) {
  public:
    void _SetUp(Begin) {
      Console::WriteLine("{0}::{1}", _typeof(*this).Name, _caller.MemberNamne);
    }
    
    void _TearDown(End) {
      Console::WriteLine("{0}::{1}", _typeof(*this).Name, _caller.MemberNamne);
    }
    
    void _Test(Test1) {
      Console::WriteLine("{0}::{1}", _typeof(*this).Name, _caller.MemberNamne);
    }
  };
 
  static struct RegisteredTest1 : public TUnit::RegisteredTest {
    RegisteredTest1() : TUnit::RegisteredTest("TestFixture1::Test1", &TestFixture1::Test1) {}
  } registeredTest1;
  //_AddTest(TestFixture1::Test1)

  class _TestFixture(TestFixture2) {
  public:
    void _Test(Test1) {
      Console::WriteLine("{0}::{1}", _typeof(*this).Name, _caller.MemberNamne);
    }
    
    void _Test(Test2) {
      Console::WriteLine("{0}::{1}", _typeof(*this).Name, _caller.MemberNamne);
    }
  };
  
  _AddTest(TestFixture2::Test1)
  _AddTest(TestFixture2::Test2)

  class _TestFixture(TestFixture3) {
  public:
    void _Test(Test1) {
      Console::WriteLine("{0}::{1}", _typeof(*this).Name, _caller.MemberNamne);
    }
    
    void _Test(Test2) {
      Console::WriteLine("{0}::{1}", _typeof(*this).Name, _caller.MemberNamne);
    }
    
    void _Test(Test3) {
      Console::WriteLine("{0}::{1}", _typeof(*this).Name, _caller.MemberNamne);
    }
    
    void _Test(Test4) {
      Console::WriteLine("{0}::{1}", _typeof(*this).Name, _caller.MemberNamne);
    }
  };
  
  _AddTest(TestFixture3::Test1)
  _AddTest(TestFixture3::Test2)
  _AddTest(TestFixture3::Test3)
  _add_ignore_test(TestFixture3::Test4)

  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      TUnit::UnitTest().Run();
      TimeSpan duration = 345_s;
      Console::WriteLine("Duration = {0}", duration);
    }
  };
}

_startup(Examples::Program)
