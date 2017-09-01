#include <Switch/Switch>

using namespace System;
using namespace TUnit;

namespace UnitTests {
  // The class TimeSpanTest must be inherited from TestFixture
  class TimeSpanTest : public TestFixture {
  protected:
    // Used Assert::AreEqual method to test value
    void CreateTimeSpanFromDateTime() {
      DateTime n = DateTime(2015, 9, 5, 9, 15, 0);
      TimeSpan ts(n.Ticks);
      Assert::AreEqual(9, ts.Hours, _current_information);
      Assert::AreEqual(15, ts.Minutes, _current_information);
    }

    // Used Assert::IsTrue to virifie if a condition is true
    void TimeSpanIsEqualToAnotherTimeSpan() {
      TimeSpan ts(10, 42, 24);
      Assert::IsTrue(ts.Equals(TimeSpan(10, 42, 24)), _current_information);
    }

    // Used Assert::IsFalse to virifie if a condition is false
    void DefaultTimeSpanIsEqualToZero() {
      Assert::IsFalse(TimeSpan(1) == TimeSpan::Zero, _current_information);
    }
  };

  // Used _test to add unit test to execute at the unit test suit.
  _test(TimeSpanTest, CreateTimeSpanFromDateTime);
  _test(TimeSpanTest, TimeSpanIsEqualToAnotherTimeSpan);
  _test(TimeSpanTest, DefaultTimeSpanIsEqualToZero);
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
