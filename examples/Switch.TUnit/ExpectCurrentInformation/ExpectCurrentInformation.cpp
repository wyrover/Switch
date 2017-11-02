#include <Switch/Switch>

using namespace System;
using namespace TUnit;

namespace UnitTests {
  class _test_fixture (UserTest) {
    // With current information
    void TestWithCurrentInformation() {
      Expect::False(true, _caller);
    }

    // Without current information
    void TestWithoutCurrentInformation() {
      Expect::False(true);
    }
  };
  
  _add_test (UserTest, TestWithCurrentInformation);
  _add_test (UserTest, TestWithoutCurrentInformation);
}

// This code produces the following output:
//
// Start 2 tests from 2 test cases
//   Start 2 test from UserTest
// Expected: False
// But was:  True
// error: !---OMITTED---!/AssertCurrentInformation/ExpectCurrentInformation.cpp:10
// *** FAILED UserTest.TestWithCurrentInformation (3 ms)
// Expected: False
// But was:  True
// *** FAILED UserTest.TestWithoutCurrentInformation (1 ms)
//   End 2 test from UserTest (4 ms total)
//
//   Summary :
//     PASSED 0 tests.
// *** FAILED 2 tests, listed below:
// *** FAILED UserTest.TestWithCurrentInformation
// *** FAILED UserTest.TestWithoutCurrentInformation
//
// 2 FAILED TESTS
// End 2 tests from 1 test case ran. (4 ms total)
