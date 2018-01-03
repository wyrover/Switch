#include <Switch/Switch>

using namespace TUnit;
using namespace System;

namespace UnitTests {
  // The class TimeSpanTest must be inherited from TestFixture
  class TestFixture_(TimeSpanTest) {
    // Used Assert::AreEqual method to test value
    void Test_(CreateTimeSpanFromDateTime) {
      DateTime n = DateTime(2015, 9, 5, 9, 15, 0);
      TimeSpan ts(n.Ticks);
      Assert::AreEqual(9, ts.Hours, caller_);
      Assert::AreEqual(15, ts.Minutes, caller_);
    }

    // Used Assert::IsTrue to virifie if a condition is true
    void Test_(TimeSpanIsEqualToAnotherTimeSpan) {
      TimeSpan ts(10, 42, 24);
      Assert::IsTrue(ts.Equals(TimeSpan(10, 42, 24)), caller_);
    }

    // Used Assert::IsFalse to virifie if a condition is false
    void Test_(DefaultTimeSpanIsEqualToZero) {
      Assert::IsFalse(TimeSpan(1) == TimeSpan::Zero(), caller_);
    }
  };

  // Used AddTest_ to add unit test to execute at the unit test suit.
  AddTestFixture_(TimeSpanTest);
  AddTest_(TimeSpanTest, CreateTimeSpanFromDateTime);
  AddTest_(TimeSpanTest, TimeSpanIsEqualToAnotherTimeSpan);
  AddTest_(TimeSpanTest, DefaultTimeSpanIsEqualToZero);
}

// This code produces the following output:
//
// Start 3 tests from 1 test case
//   Start 3 tests from TimeSpanTest
//     PASSED TimeSpanTest.CreateTimeSpanFromDateTime (1 ms)
//     PASSED TimeSpanTest.TimeSpanIsEqualToAnotherTimeSpan (0 ms)
//     PASSED TimeSpanTest.DefaultTimeSpanIsEqualToZero (0 ms)
//   End 3 tests from TimeSpanTest (4 ms total)
//
//   Summary :
//     PASSED 3 tests.
// End 3 tests from 1 test case ran. (5 ms total)
