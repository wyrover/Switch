#include <Switch/Switch>

using namespace System;
using namespace TUnit;

namespace UnitTests {
  class HelloWorldTest : public TestFixture {
  protected:
    void CreateStringFromLiteral() {
      string s = "Hello, World!";
      Assert::AreEqual("Hello, World!", s);
    }
    
    void CreateStringFromChar32Array() {
      string s = string(Array<char32> {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'});
      Assert::AreEqual("Hello, World!", s);
    }
  };
  
  sw_test (HelloWorldTest, CreateStringFromLiteral)
  sw_test (HelloWorldTest, CreateStringFromChar32Array)
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
