#include <Pcf/Pcf>

using namespace System;
using namespace TUnit;

namespace UnitTests {
  // The class PointTest must be inherited from TestFixture
  class TimeSpanTest : public TestFixture {
  protected:
    // Used Expect::AreEqual method to test value
    void CreateTimeSpanFromDateTime() {
      DateTime n = DateTime(2015, 9, 5, 9, 15, 0);
      TimeSpan ts(n.Ticks);
      Expect::AreEqual(9, ts.Hours, pcf_current_information);
      Expect::AreEqual(15, ts.Minutes, pcf_current_information);
    }

     // Used Expect::IsTrue to virifie if a condition is true
     void TimeSpanIsEqualToAnotherTimeSpan() {
       TimeSpan ts(10, 42, 24);
       Expect::IsTrue(ts.Equals(TimeSpan(10, 42, 24)), pcf_current_information);
     }

    // Used Expect::IsFalse to virifie if a condition is false
    void DefaultTimeSpanIsEqualToZero() {
      Expect::IsFalse(TimeSpan(1) == TimeSpan::Zero, pcf_current_information);
    }
  };

  // Used pcf_test to add unit test to execute at the unit test suit.
  pcf_test(TimeSpanTest, CreateTimeSpanFromDateTime);
  pcf_test(TimeSpanTest, TimeSpanIsEqualToAnotherTimeSpan);
  pcf_test(TimeSpanTest, DefaultTimeSpanIsEqualToZero);
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
