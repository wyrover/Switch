#include <Switch/Switch>

using namespace TUnit;
using namespace System;

namespace UnitTests {
  class _TestFixture(HelloWorldTest) {
    void _Test(CreateStringFromLiteral) {
      string s = "Hello, World!";
      Assert::AreEqual("Hello, World!", s);
    }
    
    void _Test(CreateStringFromChars) {
      string s = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
      Assert::AreEqual("Hello, World!", s);
    }
  };
  
  _AddTestFixture(HelloWorldTest)
  _AddTest(HelloWorldTest, CreateStringFromLiteral)
  _AddTest(HelloWorldTest, CreateStringFromChars)
}

// This code produces the following output:
//
// Start 2 tests from 1 test case
//   Start 2 tests from HelloWorldTest
//     PASSED HelloWorldTest.CreateStringFromLiteral (0 ms)
//     PASSED HelloWorldTest.CreateStringFromChar32Array (0 ms)
//   End 2 tests from HelloWorldTest (3 ms total)
//
//   Summary :
//     PASSED 2 tests.
// End 2 tests from 1 test case ran. (4 ms total)
