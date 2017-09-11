// Remarks : To add your own main entry point, you must link with Switch.TUnit nor Switch.TUnit.Main. (see CMakeLists.txt)

#include <Switch/Switch>

using namespace System;
using namespace TUnit;

namespace UnitTests {
  // The class DirectoryTest must be inherited from TestFixture
  class UserTest : public TestFixture {
  protected:
    void AnyTest() {
      Assert::Null(null, _caller);
    }
  };
  
  // Used _test to add unit test to execute at the unit test suit.
  _test(UserTest, AnyTest);
  
  class MainClass {
  public:
    // The main entry point for the test application.
    static int Main(const Array<string>& args) {
      // You can add your own code here.

      // Create UnitTest and run it
      return TUnit::UnitTest(args).Run();
    }
  };
}

_startup (UnitTests::MainClass)

// This code produces the following output if directory Downloads exists and Potatos doesn't exist in your home direcory:
//
// Start 1 test from 1 test case
//   Start 1 test from UserTest
//     PASSED UserTest.AnyTest (1 ms)
//   End 1 test from UserTest (3 ms total)
//
//   Summary :
//     PASSED 1 test.
// End 1 test from 1 test case ran. (3 ms total)
