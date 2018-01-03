#include <Switch/Switch>

using namespace TUnit::Framework;
using namespace System;

namespace UnitTests {
  // The class DirectoryTest must be declared with TestFixture_
  class TestFixture_(Test) {
    void _OneTimeSetUp(OneTimeInit) {
    }

    void _OneTimeTearDown(OneTimeCleanup) {
    }

    // This is the method that is called before any tests in a fixture are run.
    void SetUp_(Init) {
    }

    // This is the method that is called after any tests in a fixture are run.
    void TearDown_(Cleanup) {
    }

    void Test_(TestCase1) {
    }

    void Test_(TestCase2) {
    }

    void IgnoreTest_(TestCase3) {
    }
  };

  // Used AddTestFixture_ to add unit test suit.
  AddTestFixture_(Test);

  class Program static_ {
  public:
    static int Main(const Array<string>& args) {
      return UnitTest(args).Run();
    }
  };

}

startup_(UnitTests::Program)


// This code produces the following output if directory Downloads exists and Potatos doesn't exist in your home direcory:
//
// Start 2 tests from 1 test case
//   Start 2 tests from DirectoryTest
//     PASSED DirectoryTest.ChangeCurrentDirectoryWithDownloads (2 ms)
// Expected: No Exception to be thrown
// But was:  <Switch::System::IO::DirectoryNotFoundException>
// error: !---OMITTED---!/TestFixture/Sources/TestFixture.cpp:24
// *** FAILED DirectoryTest.ChangeCurrentDirectoryWithPotatoes (4 ms)
//   End 2 tests from DirectoryTest (8 ms total)
//
//   Summary :
//     PASSED 1 test.
// *** FAILED 1 test, listed below:
// *** FAILED DirectoryTest.ChangeCurrentDirectoryWithPotatoes
//
// 1 FAILED TEST
// End 2 tests from 1 test case ran. (9 ms total)
