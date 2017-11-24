#include <Switch/Switch>

using namespace TUnit;
using namespace System;

namespace UnitTests {
  class _TestFixture(UserTest) {
    // With your own message
    void _Test(TestWithUserMessage) {
      Assert::False(true, "true can never be equal to false", _caller);
    }
    
    // Without your own message
    void _Test(TestWithoutUserMessage) {
      Assert::False(true, _caller);
    }
  };
  
  _AddTestFixture(UserTest);
  _AddTest(UserTest, TestWithUserMessage);
  _AddTest(UserTest, TestWithoutUserMessage);
}

// This code produces the following output:
//
// Start 2 tests from 2 test cases
//   Start 2 test from UserTest
// true can never be equal to false
// Expected: False
// But was:  True
// error: !---OMITTED---!/AssertMessage/AssertMessage.cpp:10
// *** FAILED UserTest.TestWithUserMessage (3 ms)
// Expected: False
// But was:  True
// error: !---OMITTED---!/AssertMessage/AssertMessage.cpp:15
// *** FAILED UserTest.TestWithoutUserMessage (0 ms)
//   End 2 test from UserTest (4 ms total)
//
//   Summary :
//     PASSED 0 tests.
// *** FAILED 2 tests, listed below:
// *** FAILED UserTest.TestWithUserMessage
// *** FAILED UserTest.TestWithoutUserMessage
//
// 2 FAILED TESTS
// End 2 tests from 1 test case ran. (4 ms total)
