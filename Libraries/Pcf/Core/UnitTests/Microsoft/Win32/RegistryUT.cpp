#include <Pcf/Microsoft/Win32/Registry.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace Microsoft::Win32;
using namespace System;
using namespace TUnit;

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
    EXPECT_EQ("HKEY_CLASSES_ROOT", Registry::ClassesRoot().Name());
  }
  
  TEST_F(RegistryUT, CurrentConfig) {
    EXPECT_EQ("HKEY_CURRENT_CONFIG", Registry::CurrentConfig().Name());
  }
  
  TEST_F(RegistryUT, CurrentUser) {
    EXPECT_EQ("HKEY_CURRENT_USER", Registry::CurrentUser().Name());
  }
  
  TEST_F(RegistryUT, LocalMachine) {
    EXPECT_EQ("HKEY_LOCAL_MACHINE", Registry::LocalMachine().Name());
  }
  
  TEST_F(RegistryUT, PerformanceData) {
    EXPECT_EQ("HKEY_PERFORMANCE_DATA", Registry::PerformanceData().Name());
  }
  
  TEST_F(RegistryUT, Users) {
    EXPECT_EQ("HKEY_USERS", Registry::Users().Name());
  }
  
  /*
  TEST_F(RegistryUT, GetValueInBaseKey) {
    Registry::CurrentUser().SetValue("Key1", "Value1");
    EXPECT_EQ("Value1", static_cast<const string&>(Registry::GetValue("HKEY_CURRENT_USER", "Key1", "None")));
    Registry::CurrentUser().DeleteValue("Key1");
  }*/
  
  TEST_F(RegistryUT, GetNoPresentsValueInBaseKey) {
    const string& value =  static_cast<const string&>(Registry::GetValue("HKEY_CURRENT_USER", "Key1", "None"));
    EXPECT_EQ("None", value);
  }
  
  /*
  TEST_F(RegistryUT, GetValueInSubKey) {
    Registry::CurrentUser().CreateSubKey("UnitTest").SetValue("Key1", "Value1");
    EXPECT_EQ("Value1", static_cast<const string&>(Registry::GetValue("HKEY_CURRENT_USER\\UnitTest", "Key1", "None")));
  }*/
  
  TEST_F(RegistryUT, GetNoPresentsValueInSubKey) {
    Registry::CurrentUser().CreateSubKey("UnitTest");
    EXPECT_EQ("None", static_cast<const string&>(Registry::GetValue("HKEY_CURRENT_USER\\UnitTest", "Key1", "None")));
  }
  
  /*
  TEST_F(RegistryUT, GetValueInSubKeyInSubKey) {
    Registry::CurrentUser().CreateSubKey("UnitTest").CreateSubKey("Test2").SetValue("Key1", "Value1");
    EXPECT_EQ("Value1", static_cast<const string&>(Registry::GetValue("HKEY_CURRENT_USER\\UnitTest\\Test2", "Key1", "None")));
  }*/
  
  TEST_F(RegistryUT, GetNoPresentsValueInSubKeyInSubKey) {
    Registry::CurrentUser().CreateSubKey("UnitTest").CreateSubKey("Test2");
    EXPECT_EQ("None", static_cast<const string&>(Registry::GetValue("HKEY_CURRENT_USER\\UnitTest\\Test2", "Key1", "None")));
  }
}
