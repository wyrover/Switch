#include <Switch/Switch.TUnit.Framework>

using namespace TUnit::Framework;
using namespace System;

namespace UnitTets {
  class Test1 : public TestFixture {
    OneTimeSetUpAttribute __OneTimeInitAttribute {"OneTimeInit", *this, &Test1::OneTimeInit};
    void OneTimeInit() {
    }
    
    OneTimeTearDownAttribute __OneTimeCleanupAttribute {"OneTimeCleanup", *this, &Test1::OneTimeCleanup};
    void OneTimeCleanup() {
    }
    
    SetUpAttribute __InitAttribute {"Init", *this, &Test1::Init};
    void Init() {
    }
    
    TearDownAttribute __CleanupAttribute {"Cleanup", *this, &Test1::Cleanup};
    void Cleanup() {
    }
    
    TestAttribute __TestCase1Attribute {"TestCase1", *this, &Test1::TestCase1};
    void TestCase1() {
    }
    
    TestAttribute __TestCase2Attribute {"TestCase2", *this, &Test1::TestCase2};
    void TestCase2() {
    }
    
    TestAttribute __TestCase3Attribute {"TestCase3", *this, &Test1::TestCase3, TestState::Ignored};
    void TestCase3() {
    }
  };
  
  TestFixtureAttribute<Test1> __Test1Attribute {"Test1"};
  
  class _test_fixture(Test2) {
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
  
  _add_test_fixture(Test2)

  TEST_CLASS(Test3) {
    TEST_CLASS_INITIALIZE(OneTimeInit) {
    }
    
    TEST_CLASS_CLEANUP(OneTimeCleanup) {
    }
    
    TEST_INITIALIZE(Init) {
    }
    
    TEST_CLEANUP(Cleanup) {
    }
    
    TEST_METHOD(TestCase1) {
    }
    
    TEST_METHOD(TestCase2) {
    }
    
    IGNORE_TEST_METHOD(TestCase3) {
    }
  };
  
  ADD_TEST_CLASS(Test3)
  
  class _test_fixture(Test4) {
    void _one_time_set_up(OneTimeInit) {
    }
    
    void _one_time_tear_down(OneTimeCleanup) {
    }

    void _test(TestCase1) {
    }
  };
  
  class Test5 : public Test4 {
    void _one_time_set_up(OneTimeInit) {
    }
    
    void _one_time_tear_down(OneTimeCleanup) {
    }

    void _test(TestCase2) {
    }
  };

  _add_test_fixture(Test5)

  class MainTest {
  public:
    static void Main(const Array<string>& args) {
      TUnit::Framework::UnitTest(args).Run();
    }
  };
}

_startup(UnitTets::MainTest)

