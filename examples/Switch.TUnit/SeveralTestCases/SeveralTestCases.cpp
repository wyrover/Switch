#include <Switch/Switch>

using namespace TUnit;
using namespace System;

namespace UnitTests {
  class TestFixture_(TeastCase1) {
    void Test_(TestOne) {
      Assert::IsTrue(true, caller_);
    }

    void Test_(TestTwo) {
      Assert::IsFalse(false, caller_);
    }

    void Test_(TestThree) {
      Assert::IsEmpty("", caller_);
    }
  };

  class TestFixture_(TeastCase2) {
    void Test_(TestOne) {
      Assert::IsTrue(true, caller_);
    }

    void Test_(TestTwo) {
      Assert::IsFalse(false, caller_);
    }

    void Test_(TestThree) {
      Assert::IsEmpty("", caller_);
    }

    void Test_(TestFour) {
      Assert::IsEmpty({}, caller_);
    }
  };

  class TestFixture_(TeastCase3) {
    void Test_(TestOne) {
      Assert::IsNull(null, caller_);
    }

    void Test_(TestTwo) {
      $<string> str;
      Assert::IsNull(str, caller_);
    }
  };

  // Used Test_ to add unit test to execute at the unit test suit.
  AddTestFixture_(TeastCase1);
  AddTest_(TeastCase1, TestOne);
  AddTest_(TeastCase1, TestTwo);
  AddTest_(TeastCase1, TestThree);
  AddTestFixture_(TeastCase2);
  AddTest_(TeastCase2, TestOne);
  AddTest_(TeastCase2, TestTwo);
  AddTest_(TeastCase2, TestThree);
  AddTest_(TeastCase2, TestFour);
  AddTestFixture_(TeastCase3);
  AddTest_(TeastCase3, TestOne);
  AddTest_(TeastCase3, TestTwo);
}

// This code produces the following output:
//
// Start 9 tests from 3 test cases
//   Start 3 tests from TeastCase1
//     PASSED TeastCase1.TestOne (0 ms)
//     PASSED TeastCase1.TestTwo (0 ms)
//     PASSED TeastCase1.TestThree (0 ms)
//   End 3 tests from TeastCase1 (3 ms total)
//
//   Start 4 tests from TeastCase2
//     PASSED TeastCase2.TestOne (0 ms)
//     PASSED TeastCase2.TestTwo (0 ms)
//     PASSED TeastCase2.TestThree (0 ms)
//     PASSED TeastCase2.TestFour (0 ms)
//   End 4 tests from TeastCase2 (0 ms total)
//
//   Start 2 tests from TeastCase3
//     PASSED TeastCase3.TestOne (0 ms)
//     PASSED TeastCase3.TestTwo (0 ms)
//   End 2 tests from TeastCase3 (1 ms total)
//
//   Summary :
//     PASSED 9 tests.
// End 9 tests from 3 test cases ran. (5 ms total)
