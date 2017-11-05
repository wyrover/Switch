#include <Switch/Switch>

using namespace TUnit;
using namespace System;

namespace UnitTests {
  // The class DirectoryTest must be declared with _TestFixture
  class _TestFixture(DirectoryTest) {
    // This is the method that is called before any tests in a fixture are run.
    void _SetUp(Init) {
      savedCurrentDirecory = Environment::CurrentDirectory;
    }
    
    // This is the method that is called after any tests in a fixture are run.
    void _TearDown(Cleanup) {
      Environment::CurrentDirectory = savedCurrentDirecory;
    }

    void _Test(ChangeCurrentDirectoryWithDownloads) {
      Assert::DoesNotThrows(_delegate {Environment::CurrentDirectory = System::IO::Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::Personal), "Downloads");}, _caller);
    }
    
    void _Test(ChangeCurrentDirectoryWithPotatoes) {
      Assert::DoesNotThrows(_delegate {Environment::CurrentDirectory = System::IO::Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::Personal), "Potatoes");}, _caller);
    }
    
  private:
    string savedCurrentDirecory;
  };

  // Used _Test to add unit test to execute at the unit test suit.
  _AddTestFixture(DirectoryTest);
  _AddTest(DirectoryTest, ChangeCurrentDirectoryWithDownloads);
  _AddTest(DirectoryTest, ChangeCurrentDirectoryWithPotatoes);
}

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
