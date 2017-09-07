#include <Switch/Switch>

using namespace System;
using namespace TUnit;

namespace UnitTests {
  class TeastCase1 : public TestFixture {
  protected:
    void TestOne() {
      Assert::IsTrue(true);
    }
    
    void TestTwo() {
      Assert::IsFalse(false);
    }
    
    void TestThree() {
      Assert::IsEmpty("");
    }
  };
  
  class TeastCase2 : public TestFixture {
  protected:
    void TestOne() {
      Assert::IsTrue(true);
    }
    
    void TestTwo() {
      Assert::IsFalse(false);
    }
    
    void TestThree() {
      Assert::IsEmpty("");
    }
    
    void TestFour() {
      Assert::IsEmpty({});
    }
  };
  
  class TeastCase3 : public TestFixture {
  protected:
    void TestOne() {
      Assert::IsNull(null);
    }
    
    void TestTwo() {
      _<string> str;
      Assert::IsNull(str);
    }
  };
  
  // Used _test to add unit test to execute at the unit test suit.
  _test(TeastCase1, TestOne);
  _test(TeastCase1, TestTwo);
  _test(TeastCase1, TestThree);
  _test(TeastCase2, TestOne);
  _test(TeastCase2, TestTwo);
  _test(TeastCase2, TestThree);
  _test(TeastCase2, TestFour);
  _test(TeastCase3, TestOne);
  _test(TeastCase3, TestTwo);
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
