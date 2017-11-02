#include <Switch/Switch>

using namespace TUnit;
using namespace System;

namespace UnitTests {
  class _test_fixture (UserTest) {
    void _test (PassedTestAreEqual)() {
      string s = "One";
      Expect::AreEqual("One", s, _caller);
    }

    void _test (FailedTestAreEqual)() {
      int32 i = 42;
      Expect::AreEqual(123, i, _caller);
    }
  };

  _add_test (UserTest, PassedTestAreEqual);
  _add_test (UserTest, FailedTestAreEqual);
}

// This code produces the following output:
//
// Start 2 tests from 1 test case
//   Start 2 tests from UserTest
//     PASSED UserTest.PassedTestAreEqual (0 ms)
// Expected: 123
// But was:  42
// error: !---OMITTED---!/AssertAreEqual/ExpectAreEqual.cpp:15
// *** FAILED UserTest.FailedTestAreEqual (1 ms)
//   End 2 tests from UserTest (2 ms total)
//
//   Summary :
//     PASSED 1 test.
// *** FAILED 1 test, listed below:
// *** FAILED UserTest.FailedTestAreEqual
//
// 1 FAILED TEST
// End 2 tests from 1 test case ran. (3 ms total)
