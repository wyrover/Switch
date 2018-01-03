#include <Switch/Switch>

using namespace TUnit;
using namespace System;

namespace UnitTests {
  // The class DirectoryTest must be declared with TestFixture_
  class TestFixture_(DirectoryTest) {
    // This is the method that is called before any tests in a fixture are run.
    void SetUp_(Init) {
      savedCurrentDirecory = Environment::CurrentDirectory;
    }

    // This is the method that is called after any tests in a fixture are run.
    void TearDown_(Cleanup) {
      Environment::CurrentDirectory = savedCurrentDirecory;
    }

    void Test_(ChangeCurrentDirectoryWithDownloads) {
      Assert::DoesNotThrows(delegate_ {Environment::CurrentDirectory = System::IO::Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::Personal), "Downloads");}, caller_);
    }

    void Test_(ChangeCurrentDirectoryWithPotatoes) {
      Assert::DoesNotThrows(delegate_ {Environment::CurrentDirectory = System::IO::Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::Personal), "Potatoes");}, caller_);
    }

  private:
    string savedCurrentDirecory;
  };

  // Used Test_ to add unit test to execute at the unit test suit.
  AddTestFixture_(DirectoryTest);
  AddTest_(DirectoryTest, ChangeCurrentDirectoryWithDownloads);
  AddTest_(DirectoryTest, ChangeCurrentDirectoryWithPotatoes);
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
