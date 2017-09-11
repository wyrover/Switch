#include <Switch/Switch>

using namespace System;
using namespace TUnit;

namespace UnitTests {
  class UserTest1 : public TestFixture {
  protected:
    // With current information
    void TestWithCurrentInformation() {
      Expect::False(true, _caller);
    }
  };
  
  class UserTest2 : public TestFixture {
  protected:
    // Without current information
    void TestWithoutCurrentInformation() {
      Expect::False(true);
    }
  };
  
  _test(UserTest1, TestWithCurrentInformation);
  _test(UserTest2, TestWithoutCurrentInformation);
}

// This code produces the following output:
//
// Start 2 tests from 2 test cases
//   Start 1 test from UserTest1
// Expected: False
// But was:  True
// error: !---OMITTED---!/AssertCurrentInformation/ExpectCurrentInformation.cpp:11
// *** FAILED UserTest1.TestWithCurrentInformation (3 ms)
//   End 1 test from UserTest1 (3 ms total)
//
//   Start 1 test from UserTest2
// Expected: False
// But was:  True
// *** FAILED UserTest2.TestWithoutCurrentInformation (1 ms)
//   End 1 test from UserTest2 (1 ms total)
//
//   Summary :
//     PASSED 0 tests.
// *** FAILED 2 tests, listed below:
// *** FAILED UserTest1.TestWithCurrentInformation
// *** FAILED UserTest2.TestWithoutCurrentInformation
//
// 2 FAILED TESTS
// End 2 tests from 2 test cases ran. (4 ms total)
