#include <Switch/Switch>

using namespace TUnit::Framework;
using namespace System;

namespace UnitTests {
  // The class DirectoryTest must be declared with _test_fixture
  class Test : public TestFixture {
    OneTimeSetUpAttribute __OneTimeInitAttribute {"OneTimeInit", *this, &Test::OneTimeInit};
    void OneTimeInit() {
    }
    
    OneTimeTearDownAttribute __OneTimeCleanupAttribute {"OneTimeCleanup", *this, &Test::OneTimeCleanup};
    void OneTimeCleanup() {
    }
    
    // This is the method that is called before any tests in a fixture are run.
    SetUpAttribute __InitAttribute {"Init", *this, &Test::Init};
    void Init() {
    }
    
    // This is the method that is called after any tests in a fixture are run.
    TearDownAttribute __CleanupAttribute {"Cleanup", *this, &Test::Cleanup};
    void Cleanup() {
    }
    
    TestAttribute __TestCase1Attribute {"TestCase1", *this, &Test::TestCase1};
    void TestCase1() {
    }
    
    TestAttribute __TestCase2Attribute {"TestCase2", *this, &Test::TestCase2};
    void TestCase2() {
    }
    
    TestAttribute __TestCase3Attribute {"TestCase3", *this, &Test::TestCase3, TestState::Ignored};
    void TestCase3() {
    }
  };

  // Used _test to add unit test to execute at the unit test suit.
  TestFixtureAttribute<Test> __TestAttribute {"Test"};

  class Program _static {
  public:
    static int Main(const Array<string>& args) {
      return UnitTest(args).Run();
    }
  };
  
}

_startup(UnitTests::Program)
