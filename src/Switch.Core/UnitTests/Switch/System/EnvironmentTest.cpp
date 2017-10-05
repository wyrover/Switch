#include <Switch/System/Environment.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class EnvironmentTest : public TestFixture {
  protected:
    void GetEnvironmentVariables() {
      Assert::Greater(Environment::GetEnvironmentVariables().Count, 0, _caller);
    }
    
    void GetEnvironmentVariable() {
      Assert::IsFalse(string::IsNullOrEmpty(Environment::GetEnvironmentVariable("PATH")), _caller);
    }
    
    void SetEnvironmentVariable() {
      Assert::IsTrue(string::IsNullOrEmpty(Environment::GetEnvironmentVariable("TEST_ENVIRONEMENT")), _caller);
      Assert::DoesNotThrows(_delegate {Environment::SetEnvironmentVariable("TEST_ENVIRONEMENT", "1");}, _caller);
      Assert::AreEqual("1", Environment::GetEnvironmentVariable("TEST_ENVIRONEMENT"), _caller);
      Assert::DoesNotThrows(_delegate {Environment::SetEnvironmentVariable("TEST_ENVIRONEMENT", "");}, _caller);
      Assert::IsTrue(string::IsNullOrEmpty(Environment::GetEnvironmentVariable("TEST_ENVIRONEMENT")), _caller);
    }
  };
  
  //_test(EnvironmentTest, GetEnvironmentVariables)
  _test(EnvironmentTest, GetEnvironmentVariable)
  //_test(EnvironmentTest, SetEnvironmentVariable)
}
