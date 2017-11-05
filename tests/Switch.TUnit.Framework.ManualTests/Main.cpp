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
  
  class _TestFixture(Test2) {
    void _OneTimeSetUp(OneTimeInit) {
    }

    void _OneTimeTearDown(OneTimeCleanup) {
    }
    
    void _SetUp(Init) {
    }
    
    void _TearDown(Cleanup) {
    }
    
    void _Test(TestCase1) {
    }
    
    void _Test(TestCase2) {
    }
    
    void _IgnoreTest(TestCase3) {
    }
  };
  
  _AddTestFixture(Test2);
  
  class _TestFixture(Test3) {
    void _OneTimeSetUp(OneTimeInit) {
    }
    
    void _OneTimeTearDown(OneTimeCleanup) {
    }

    void _Test(TestCase1) {
    }
  };
  
  class Test4 : public Test3 {
    void _OneTimeSetUp(OneTimeInit) {
    }
    
    void _OneTimeTearDown(OneTimeCleanup) {
    }

    void _Test(TestCase2) {
    }
  };

  _AddTestFixture(Test4);

  class MainTest {
  public:
    static void Main(const Array<string>& args) {
      TUnit::Framework::UnitTest(args).Run();
    }
  };
}

_startup(UnitTets::MainTest)

