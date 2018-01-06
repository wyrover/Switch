#include <Switch/Switch.TUnit.Framework>

using namespace TUnit::Framework;
using namespace System;

namespace ManualTests {
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

  class TestFixture_(Test2) {
    void _OneTimeSetUp(OneTimeInit) {
    }

    void _OneTimeTearDown(OneTimeCleanup) {
    }

    void SetUp_(Init) {
    }

    void TearDown_(Cleanup) {
    }

    void Test_(TestCase1) {
    }

    void Test_(TestCase2) {
    }

    void IgnoreTest_(TestCase3) {
    }
  };

  AddTestFixture_(Test2);

  class TestFixture_(Test3) {
    void _OneTimeSetUp(OneTimeInit) {
    }

    void _OneTimeTearDown(OneTimeCleanup) {
    }

    void Test_(TestCase1) {
    }
  };

  class Test4 : public Test3 {
    void _OneTimeSetUp(OneTimeInit) {
    }

    void _OneTimeTearDown(OneTimeCleanup) {
    }

    void Test_(TestCase2) {
    }
  };

  AddTestFixture_(Test4);

  class MainTest {
  public:
    static void Main(const Array<string>& args) {
      TUnit::Framework::UnitTest(args).Run();
    }
  };
}

startup_(ManualTests::MainTest);
