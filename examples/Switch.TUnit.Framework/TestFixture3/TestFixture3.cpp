#include <Switch/Switch>

using namespace TUnit::Framework;
using namespace System;

namespace UnitTests {
  // The class DirectoryTest must be declared with _test_fixture
  TEST_CLASS(Test) {
    TEST_CLASS_INITIALIZE(OneTimeInit) {
    }
    
    TEST_CLASS_CLEANUP(OneTimeCleanup) {
    }
    
    // This is the method that is called before any tests in a fixture are run.
    TEST_INITIALIZE(Init) {
    }
    
    // This is the method that is called after any tests in a fixture are run.
    TEST_CLEANUP(Cleanup) {
    }

    TEST_METHOD(TestCase1) {
    }
    
    TEST_METHOD(TestCase2) {
    }
    
    IGNORE_TEST_METHOD(TestCase3) {
    }
  };

  // Used _test to add unit test to execute at the unit test suit.
  ADD_TEST_CLASS(Test);

  class Program _static {
  public:
    static int Main(const Array<string>& args) {
      return UnitTest(args).Run();
    }
  };
  
}

_startup(UnitTests::Program)


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
