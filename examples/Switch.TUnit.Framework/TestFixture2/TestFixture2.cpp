#include <Switch/Switch>

using namespace TUnit::Framework;
using namespace System;

namespace UnitTests {
  // The class DirectoryTest must be declared with _TestFixture
  class _TestFixture(Test) {
    void _OneTimeSetUp(OneTimeInit) {
    }
    
    void _OneTimeTearDown(OneTimeCleanup) {
    }
    
    // This is the method that is called before any tests in a fixture are run.
    void _SetUp(Init) {
    }
    
    // This is the method that is called after any tests in a fixture are run.
    void _TearDown(Cleanup) {
    }
    
    void _Test(TestCase1) {
    }
    
    void _Test(TestCase2) {
    }
    
    void _IgnoreTest(TestCase3) {
    }
  };
  
  // Used _AddTestFixture to add unit test suit.
  _AddTestFixture(Test);
  
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
