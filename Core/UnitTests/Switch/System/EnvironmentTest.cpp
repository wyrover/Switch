#include <Switch/System/Environment.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class EnvironmentTest : public TestFixture {
  protected:
    void GetEnvironmentVariables() {
      Assert::Greater(Environment::GetEnvironmentVariables().Count, 0, _current_information);
    }
    
    void GetEnvironmentVariable() {
      Assert::IsFalse(Environment::GetEnvironmentVariable("PATH").IsEmpty(), _current_information);
    }
    
    void SetEnvironmentVariable() {
      Assert::IsTrue(Environment::GetEnvironmentVariable("TEST_ENVIRONEMENT").IsEmpty(), _current_information);
      Assert::DoesNotThrows(_delegate {Environment::SetEnvironmentVariable("TEST_ENVIRONEMENT", "1");}, _current_information);
      Assert::AreEqual("1", Environment::GetEnvironmentVariable("TEST_ENVIRONEMENT"), _current_information);
      Assert::DoesNotThrows(_delegate {Environment::SetEnvironmentVariable("TEST_ENVIRONEMENT", "");}, _current_information);
      Assert::IsTrue(Environment::GetEnvironmentVariable("TEST_ENVIRONEMENT").IsEmpty(), _current_information);
    }
  };
  
  //_test(EnvironmentTest, GetEnvironmentVariables)
  _test(EnvironmentTest, GetEnvironmentVariable)
  //_test(EnvironmentTest, SetEnvironmentVariable)
}
