#include <Switch/Switch>

using namespace System;
using namespace TUnit;

namespace UnitTests {
  class UserTest1 : public TestFixture {
  protected:
    // With your own message
    void TestWithUserMessage() {
      Expect::False(true, "true can never be equal to false", _current_information);
    }
  };
  
  class UserTest2 : public TestFixture {
  protected:
    // Without your own message
    void TestWithoutUserMessage() {
      Expect::False(true, _current_information);
    }
  };
  
  _test(UserTest1, TestWithUserMessage);
  _test(UserTest2, TestWithoutUserMessage);
}

// This code produces the following output:
//
// Start 2 tests from 2 test cases
//   Start 1 test from UserTest1
// true can never be equal to false
// Expected: False
// But was:  True
// error: !---OMITTED---!/AssertMessage/ExpectMessage.cpp:11
// *** FAILED UserTest1.TestWithUserMessage (2 ms)
//   End 1 test from UserTest1 (2 ms total)
//
//   Start 1 test from UserTest2
// Expected: False
// But was:  True
// error: !---OMITTED---!/AssertMessage/ExpectMessage.cpp:19
// *** FAILED UserTest2.TestWithoutUserMessage (0 ms)
//   End 1 test from UserTest2 (0 ms total)
//
//   Summary :
//     PASSED 0 tests.
// *** FAILED 2 tests, listed below:
// *** FAILED UserTest1.TestWithUserMessage
// *** FAILED UserTest2.TestWithoutUserMessage
//
// 2 FAILED TESTS
// End 2 tests from 2 test cases ran. (3 ms total)
