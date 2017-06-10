#include <Pcf/System/Environment.hpp>
#include <Pcf/TUnit/Assert.hpp>
#include <Pcf/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class EnvironmentTest : public TestFixture {
  protected:
    void GetEnvironmentVariables() {
      Assert::Greater(Environment::GetEnvironmentVariables().Count, 0, pcf_current_information);
    }
    
    void GetEnvironmentVariable() {
      Assert::IsFalse(Environment::GetEnvironmentVariable("PATH").IsEmpty(), pcf_current_information);
    }
    
    void SetEnvironmentVariable() {
      Assert::IsTrue(Environment::GetEnvironmentVariable("TEST_ENVIRONEMENT").IsEmpty(), pcf_current_information);
      Assert::DoesNotThrows(pcf_delegate {Environment::SetEnvironmentVariable("TEST_ENVIRONEMENT", "1");}, pcf_current_information);
      Assert::AreEqual("1", Environment::GetEnvironmentVariable("TEST_ENVIRONEMENT"), pcf_current_information);
      Assert::DoesNotThrows(pcf_delegate {Environment::SetEnvironmentVariable("TEST_ENVIRONEMENT", "");}, pcf_current_information);
      Assert::IsTrue(Environment::GetEnvironmentVariable("TEST_ENVIRONEMENT").IsEmpty(), pcf_current_information);
    }
  };
  
  //pcf_test(EnvironmentTest, GetEnvironmentVariables)
  pcf_test(EnvironmentTest, GetEnvironmentVariable)
  //pcf_test(EnvironmentTest, SetEnvironmentVariable)
}
