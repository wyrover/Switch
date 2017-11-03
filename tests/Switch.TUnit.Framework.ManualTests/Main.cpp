#include <Switch/Switch.TUnit.Framework>

using namespace TUnit::Framework;
using namespace System;

namespace UnitTets {
  class _test_fixture(Test1) {
    void _one_time_set_up(OneTimeInit) {
    }

    void _one_time_tear_down(OneTimeCleanup) {
    }
    
    void _set_up(Init) {
    }
    
    void _tear_down(Cleanup) {
    }
    
    void _test(TestCase1) {
    }
    
    void _test(TestCase2) {
    }
    
    void _ignore_test(TestCase3) {
    }
  };
  
  _add_test_fixture(Test1)

  class _test_class(Test2) {
    void _test_class_initialize(OneTimeInit) {
    }
    
    void _test_class_cleanup(OneTimeCleanup) {
    }
    
    void _test_initialize(Init) {
    }
    
    void _test_cleanup(Cleanup) {
    }
    
    void _test_method(TestCase1) {
    }
    
    void _test_method(TestCase2) {
    }
    
    void _ignore_test_method(TestCase3) {
    }
  };
  
  _add_test_fixture(Test2)

  class Test3 : public TestFixture {
    OneTimeSetUpAttribute __OneTimeInitAttribute {"OneTimeInit", *this, &Test3::OneTimeInit};
    void OneTimeInit() {
    }
    
    OneTimeTearDownAttribute __OneTimeCleanupAttribute {"OneTimeCleanup", *this, &Test3::OneTimeCleanup};
    void OneTimeCleanup() {
    }
    
    SetUpAttribute __InitAttribute {"Init", *this, &Test3::Init};
    void Init() {
    }
    
    TearDownAttribute __CleanupAttribute {"Cleanup", *this, &Test3::Cleanup};
    void Cleanup() {
    }
    
    TestAttribute __TestCase1Attribute {"TestCase1", *this, &Test3::TestCase1};
    void TestCase1() {
    }
    
    TestAttribute __TestCase2Attribute {"TestCase2", *this, &Test3::TestCase2};
    void TestCase2() {
    }
    
    TestAttribute __TestCase3Attribute {"TestCase3", *this, &Test3::TestCase3, TestState::Ignored};
    void TestCase3() {
    }
  };

  TestFixtureAttribute<Test3> __Test3Attribute {"Test3"};

  class Program {
  public:
    static void Main(const Array<string>& args) {
      TUnit::Framework::UnitTest(args).Run();
    }
  };
}

_startup(UnitTets::Program)

