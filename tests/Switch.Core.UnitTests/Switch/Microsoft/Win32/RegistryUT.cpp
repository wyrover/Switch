#include <Switch/Microsoft/Win32/Registry.hpp>
#include <gtest/gtest.h>

using namespace Microsoft::Win32;
using namespace System;

namespace {
  class RegistryUT : public testing::Test {
  protected:

    void SetUp() override {
      Registry::CurrentUser().DeleteSubKeyTree("UnitTest", false);
    }

    void TearDown() override {
      Registry::CurrentUser().DeleteSubKeyTree("UnitTest", false);
    }
  };

  TEST_F(RegistryUT, ClassesRoot) {
    ASSERT_EQ("HKEY_CLASSES_ROOT", Registry::ClassesRoot().Name());
  }

  TEST_F(RegistryUT, CurrentConfig) {
    ASSERT_EQ("HKEY_CURRENT_CONFIG", Registry::CurrentConfig().Name());
  }

  TEST_F(RegistryUT, CurrentUser) {
    ASSERT_EQ("HKEY_CURRENT_USER", Registry::CurrentUser().Name());
  }

  TEST_F(RegistryUT, LocalMachine) {
    ASSERT_EQ("HKEY_LOCAL_MACHINE", Registry::LocalMachine().Name());
  }

  TEST_F(RegistryUT, PerformanceData) {
    ASSERT_EQ("HKEY_PERFORMANCE_DATA", Registry::PerformanceData().Name());
  }

  TEST_F(RegistryUT, Users) {
    ASSERT_EQ("HKEY_USERS", Registry::Users().Name());
  }

  /*
  TEST_F(RegistryUT, GetValueInBaseKey) {
    Registry::CurrentUser().SetValue("Key1", "Value1");
    ASSERT_EQ("Value1", static_cast<const string&>(Registry::GetValue("HKEY_CURRENT_USER", "Key1", "None")));
    Registry::CurrentUser().DeleteValue("Key1");
  }*/

  TEST_F(RegistryUT, GetNoPresentsValueInBaseKey) {
    const string& value =  static_cast<const string&>(Registry::GetValue("HKEY_CURRENT_USER", "Key1", "None"));
    ASSERT_EQ("None", value);
  }

  /*
  TEST_F(RegistryUT, GetValueInSubKey) {
    Registry::CurrentUser().CreateSubKey("UnitTest").SetValue("Key1", "Value1");
    ASSERT_EQ("Value1", static_cast<const string&>(Registry::GetValue("HKEY_CURRENT_USER\\UnitTest", "Key1", "None")));
  }*/

  TEST_F(RegistryUT, GetNoPresentsValueInSubKey) {
    Registry::CurrentUser().CreateSubKey("UnitTest");
    ASSERT_EQ("None", static_cast<const string&>(Registry::GetValue("HKEY_CURRENT_USER\\UnitTest", "Key1", "None")));
  }

  /*
  TEST_F(RegistryUT, GetValueInSubKeyInSubKey) {
    Registry::CurrentUser().CreateSubKey("UnitTest").CreateSubKey("Test2").SetValue("Key1", "Value1");
    ASSERT_EQ("Value1", static_cast<const string&>(Registry::GetValue("HKEY_CURRENT_USER\\UnitTest\\Test2", "Key1", "None")));
  }*/

  TEST_F(RegistryUT, GetNoPresentsValueInSubKeyInSubKey) {
    Registry::CurrentUser().CreateSubKey("UnitTest").CreateSubKey("Test2");
    ASSERT_EQ("None", static_cast<const string&>(Registry::GetValue("HKEY_CURRENT_USER\\UnitTest\\Test2", "Key1", "None")));
  }
}
