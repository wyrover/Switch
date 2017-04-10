#include <Pcf/Pcf>

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
      Assert::AreEqual(9, ts.Hours, pcf_current_information);
      Assert::AreEqual(15, ts.Minutes, pcf_current_information);
    }

    // Used Assert::Throws to verifie if method throw effectively an exception
    void CreateTimeSpanFromNullTimeSpan() {
      Assert::Throws<ArgumentNullException>(pcf_delegate {
        TimeSpan timeSpan(Ref<TimeSpan>::Null());
      }, pcf_current_information);
    }

    // Used Assert::IsTrue to virifie if a condition is true
    void TimeSpanIsEqualToAnotherTimeSpan() {
      TimeSpan ts(10, 42, 24);
      Assert::IsTrue(ts.Equals(TimeSpan(10, 42, 24)), pcf_current_information);
    }

    // Used Assert::IsFalse to virifie if a condition is false
    void DefaultTimeSpanIsEqualToZero() {
      Assert::IsFalse(TimeSpan(1) == TimeSpan::Zero, pcf_current_information);
    }
  };

  // Used pcf_test to add unit test to execute at the unit test suit.
  pcf_test(TimeSpanTest, CreateTimeSpanFromDateTime);
  pcf_test(TimeSpanTest, CreateTimeSpanFromNullTimeSpan);
  pcf_test(TimeSpanTest, TimeSpanIsEqualToAnotherTimeSpan);
  pcf_test(TimeSpanTest, DefaultTimeSpanIsEqualToZero);
}

// This code produces the following output:
//
// Start 4 tests from 1 test case
//   Start 4 tests from TimeSpanTest
//     PASSED TimeSpanTest.CreateTimeSpanFromDateTime (1 ms)
//     PASSED TimeSpanTest.CreateTimeSpanFromNullTimeSpan (7 ms)
//     PASSED TimeSpanTest.TimeSpanIsEqualToAnotherTimeSpan (0 ms)
//     PASSED TimeSpanTest.DefaultTimeSpanIsEqualToZero (0 ms)
//   End 4 tests from TimeSpanTest (45 ms total)
//
//   Summary :
//     PASSED 4 tests.
// End 4 tests from 1 test case ran. (45 ms total)
