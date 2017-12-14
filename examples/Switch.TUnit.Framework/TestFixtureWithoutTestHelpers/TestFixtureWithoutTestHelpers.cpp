#include <Switch/Switch>

using namespace TUnit::Framework;
using namespace System;

namespace UnitTests {
  // The class DirectoryTest must be declared with _TestFixture
  class Test : public TestFixture {
    OneTimeSetUpAttribute oneTimeInitAttribute {"OneTimeInit", *this, &Test::OneTimeInit};
    void OneTimeInit() {
    }

    OneTimeTearDownAttribute oneTimeCleanupAttribute {"OneTimeCleanup", *this, &Test::OneTimeCleanup};
    void OneTimeCleanup() {
    }

    // This is the method that is called before any tests in a fixture are run.
    SetUpAttribute initAttribute {"Init", *this, &Test::Init};
    void Init() {
    }

    // This is the method that is called after any tests in a fixture are run.
    TearDownAttribute cleanupAttribute {"Cleanup", *this, &Test::Cleanup};
    void Cleanup() {
    }

    TestAttribute testCase1Attribute {"TestCase1", *this, &Test::TestCase1};
    void TestCase1() {
    }

    TestAttribute testCase2Attribute {"TestCase2", *this, &Test::TestCase2};
    void TestCase2() {
    }

    TestAttribute testCase3Attribute {"TestCase3", *this, &Test::TestCase3, TestState::Ignored};
    void TestCase3() {
    }
  };

  // Used TestFixtureAttribute<> to add unit test suit.
  TestFixtureAttribute<Test> testAttribute {"Test"};

  class Program _static {
  public:
    static int Main(const Array<string>& args) {
      return UnitTest(args).Run();
    }
  };

}

_startup(UnitTests::Program)
