#include <Pcf/Pcf>

using namespace System;
using namespace TUnit;

namespace UnitTests {
  // The class DirectoryTest must be inherited from TestFixture
  class DirectoryTest : public TestFixture {
  protected:
    // This is the method that is called before any tests in a fixture are run.
    void SetUp() override {
      savedCurrentDirecory = Environment::CurrentDirectory;
    }
    
    // This is the method that is called after any tests in a fixture are run.
    void TearDown() override {
      Environment::CurrentDirectory = savedCurrentDirecory;
    }
    
    void ChangeCurrentDirecoryWithDownloads() {
      Assert::DoesNotThrows(pcf_delegate {Environment::CurrentDirectory = System::IO::Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::Personal), "Downloads");}, pcf_current_information);
    }
    
    void ChangeCurrentDirecoryWithPotatos() {
      Assert::DoesNotThrows(pcf_delegate {Environment::CurrentDirectory = System::IO::Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::Personal), "Potatos");}, pcf_current_information);
    }
    
  private:
    string savedCurrentDirecory;
  };

  // Used pcf_test to add unit test to execute at the unit test suit.
  pcf_test(DirectoryTest, ChangeCurrentDirecoryWithDownloads);
  pcf_test(DirectoryTest, ChangeCurrentDirecoryWithPotatos);
}

// This code produces the following output if directory Downloads exists and Potatos doesn't exist in your home direcory:
//
// Start 2 tests from 1 test case
//   Start 2 tests from DirectoryTest
//     PASSED DirectoryTest.ChangeCurrentDirecoryWithDownloads (1 ms)
// error: /YourFolder/TUnit/TestFixture/Sources/TestFixture.cpp:25
// Expected: statement doesn't throws an exception.
//   Actual: it throws Pcf::System::IO::DirectoryNotFoundException.
// *** FAILED DirectoryTest.ChangeCurrentDirecoryWithPotatos (11 ms)
//   End 2 tests from DirectoryTest (45 ms total)
//
//   Summary :
//     PASSED 1 test.
// *** FAILED 1 test, listed below:
// *** FAILED DirectoryTest.ChangeCurrentDirecoryWithPotatos
//
// 1 FAILED TEST
// End 2 tests from 1 test case ran. (45 ms total)
