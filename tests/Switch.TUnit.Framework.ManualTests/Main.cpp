#include <Switch/Switch.TUnit.Framework>

using namespace TUnit::Framework;
using namespace System;

namespace UnitTets {
  _test_fixture(Test) {

    _one_time_set_up(OneTimeInit) {
    }

    _one_time_tear_down(OneTimeCleanup) {
    }
    
    void _set_up(Init)() {
    }
    
    void _tear_down(Cleanup)() {
    }
    
    void _test(TestCase1)() {
    }
    
    void _test(TestCase2)() {
    }
    
    void _ignore_test(TestCase3)() {
    }
  };
  
  _add_test_fixture(Test)

  _test_fixture(Test2) {
    void _test(TestCase1)() {
    }
    
    void _test(TestCase2)() {
    }
    
    void _test(TestCase3)() {
    }
    
    void _test(TestCase4)() {
    }
  };
  
  _add_test_fixture(Test2)

  class Test3 : public TestFixture {
    OneTimeSetUpAttribute oneTimeInit {"OneTimeInit", *this, &Test3::OneTimeInit};
    void OneTimeInit() {
    }
    
    OneTimeTearDownAttribute oneTimeCleanup {"OneTimeCleanup", *this, &Test3::OneTimeCleanup};
    void OneTimeCleanup() {
    }
    
    SetUpAttribute init {"Init", *this, &Test3::Init};
    void Init() {
    }
    
    TearDownAttribute cleanup {"Cleanup", *this, &Test3::Cleanup};
    void Cleanup() {
    }
    
    TestAttribute testCase1 {"TestCase1", *this, &Test3::TestCase1};
    void TestCase1() {
    }
    
    TestAttribute testCase2 {"TestCase2", *this, &Test3::TestCase2};
    void TestCase2() {
    }
    
    TestAttribute testCase3 {"TestCase3", *this, &Test3::TestCase3, true};
    void TestCase3() {
    }
  };

  TestFixtureAttribute<Test3> test3 {"Test3"};

  class Program {
  public:
    static void Main(const Array<string>& args) {
      TUnit::Framework::UnitTest(args).Run();
    }
  };
}

_startup(UnitTets::Program)

