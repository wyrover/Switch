#include <Switch/Microsoft/Win32/Registry.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace Microsoft::Win32;

namespace {
  class RegistryKeyUT : public testing::Test {
  protected:
    void SetUp() override {
      Registry::CurrentUser().DeleteSubKeyTree("UnitTest", false);
    }

    void TearDown() override {
      Registry::CurrentUser().DeleteSubKeyTree("UnitTest", false);
    }
  };

  TEST_F(RegistryKeyUT, CreateSubKeyWithEmptySubKeyName) {
    int32 count = Registry::CurrentUser().SubKeyCount();
    RegistryKey key = Registry::CurrentUser().CreateSubKey("");
    ASSERT_EQ(count, Registry::CurrentUser().SubKeyCount());
    ASSERT_EQ("HKEY_CURRENT_USER\\", key.Name());
  }

  TEST_F(RegistryKeyUT, CreateSubKeyWithNotExistingSubKey) {
    int32 count = Registry::CurrentUser().SubKeyCount();
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    ASSERT_EQ(count + 1, Registry::CurrentUser().SubKeyCount());
    ASSERT_EQ("HKEY_CURRENT_USER\\UnitTest", key.Name());
  }

  TEST_F(RegistryKeyUT, CreateSubKeyWithExistingSubKey) {
    int32 count = Registry::CurrentUser().SubKeyCount();
    Registry::CurrentUser().CreateSubKey("UnitTest");
    ASSERT_EQ(count + 1, Registry::CurrentUser().SubKeyCount());
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    ASSERT_EQ(count + 1, Registry::CurrentUser().SubKeyCount());
    ASSERT_EQ("HKEY_CURRENT_USER\\UnitTest", key.Name());
  }

  TEST_F(RegistryKeyUT, CreateSubKeyWithExistingSubKeyAndOtherCast) {
    int32 count = Registry::CurrentUser().SubKeyCount();
    Registry::CurrentUser().CreateSubKey("UnitTest");
    ASSERT_EQ(count + 1, Registry::CurrentUser().SubKeyCount());
    ASSERT_EQ("HKEY_CURRENT_USER\\UNITTEST", Registry::CurrentUser().CreateSubKey("UNITTEST").Name());
    ASSERT_EQ(count + 1, Registry::CurrentUser().SubKeyCount());
    ASSERT_EQ("HKEY_CURRENT_USER\\unittest", Registry::CurrentUser().CreateSubKey("unittest").Name());
    ASSERT_EQ(count + 1, Registry::CurrentUser().SubKeyCount());
    ASSERT_EQ("HKEY_CURRENT_USER\\UnItTeSt", Registry::CurrentUser().CreateSubKey("UnItTeSt").Name());
    ASSERT_EQ(count + 1, Registry::CurrentUser().SubKeyCount());
  }

  TEST_F(RegistryKeyUT, CreateSubKeyInASubKey) {
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest").CreateSubKey("SubKey1");
    ASSERT_EQ("HKEY_CURRENT_USER\\UnitTest\\SubKey1", key.Name());
  }

  TEST_F(RegistryKeyUT, CreateSubKeyWithReadPermission) {
    ASSERT_THROW(RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest", Microsoft::Win32::RegistryKeyPermissionCheck(Microsoft::Win32::RegistryKeyPermissionCheck::ReadSubTree)).CreateSubKey("SubKey1"), UnauthorizedAccessException);
  }

  TEST_F(RegistryKeyUT, CreateSubKeyWithReadWritePermission) {
    ASSERT_NO_THROW(RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest", Microsoft::Win32::RegistryKeyPermissionCheck(Microsoft::Win32::RegistryKeyPermissionCheck::ReadWriteSubTree)).CreateSubKey("SubKey1"));
  }

  TEST_F(RegistryKeyUT, DeleteSubKeyWithEmptySubKey) {
    ASSERT_THROW(Registry::CurrentUser().DeleteSubKey(""), InvalidOperationException);
  }

  TEST_F(RegistryKeyUT, DeleteSubKeyWithBaseSubKey) {
    ASSERT_THROW(Registry::CurrentUser().DeleteSubKey("HKEY_CURRENT_USER"), ArgumentException);
  }

  TEST_F(RegistryKeyUT, DeleteSubKeyWithNotExistingSubKey) {
    ASSERT_THROW(Registry::CurrentUser().DeleteSubKey("UnitTest"), ArgumentException);
  }

  TEST_F(RegistryKeyUT, DeleteSubKeyWithNotExistingSubKeyAndThrowMissingToTrue) {
    ASSERT_THROW(Registry::CurrentUser().DeleteSubKey("UnitTest", true), ArgumentException);
  }

  TEST_F(RegistryKeyUT, DeleteSubKeyWithNotExistingSubKeyAndThrowMissingToFalse) {
    ASSERT_NO_THROW(Registry::CurrentUser().DeleteSubKey("UnitTest", false));
  }

  TEST_F(RegistryKeyUT, DeleteSubKeyWithExistingSubKey) {
    Registry::CurrentUser().CreateSubKey("UnitTest");
    int32 count = Registry::CurrentUser().SubKeyCount();
    ASSERT_NO_THROW(Registry::CurrentUser().DeleteSubKey("UnitTest"));
    ASSERT_EQ(count - 1, Registry::CurrentUser().SubKeyCount());
  }

  TEST_F(RegistryKeyUT, DeleteSubKeyWithExistingSubKeyAndBadCast) {
    Registry::CurrentUser().CreateSubKey("UnitTest");
    int32 count = Registry::CurrentUser().SubKeyCount();
    ASSERT_NO_THROW(Registry::CurrentUser().DeleteSubKey("UNITTEST"));
    ASSERT_EQ(count - 1, Registry::CurrentUser().SubKeyCount());
  }

  //TEST_F(RegistryKeyUT, DeleteSubKeyWithExistingSubKeyNotEmpty) {
  //  Registry::CurrentUser().CreateSubKey("UnitTest").CreateSubKey("SubKey1");
  //  ASSERT_THROW(Registry::CurrentUser().DeleteSubKey("UnitTest"), System::InvalidOperationException);
  //}

  TEST_F(RegistryKeyUT, DeleteSubKeyTreeWithEmptySubKey) {
    ASSERT_THROW(Registry::CurrentUser().DeleteSubKeyTree(""), ArgumentException);
  }

  TEST_F(RegistryKeyUT, DeleteSubKeyTreeWithNotExistingSubKey) {
    ASSERT_THROW(Registry::CurrentUser().DeleteSubKeyTree("UnitTest"), ArgumentException);
  }

  TEST_F(RegistryKeyUT, DeleteSubKeyTreeWithBaseSubKey) {
    ASSERT_THROW(Registry::CurrentUser().DeleteSubKeyTree("HKEY_CURRENT_USER"), ArgumentException);
  }

  TEST_F(RegistryKeyUT, DeleteSubKeyTreeWithNotExistingSubKeyAndThrowMissingToTrue) {
    ASSERT_THROW(Registry::CurrentUser().DeleteSubKeyTree("UnitTest", true), ArgumentException);
  }

  TEST_F(RegistryKeyUT, DeleteSubKeyTreeWithNotExistingSubKeyAndThrowMissingToFalse) {
    ASSERT_NO_THROW(Registry::CurrentUser().DeleteSubKeyTree("UnitTest", false));
  }

  TEST_F(RegistryKeyUT, DeleteSubKeyTreeWithExistingSubKey) {
    Registry::CurrentUser().CreateSubKey("UnitTest");
    int32 count = Registry::CurrentUser().SubKeyCount();
    ASSERT_NO_THROW(Registry::CurrentUser().DeleteSubKeyTree("UnitTest"));
    ASSERT_EQ(count - 1, Registry::CurrentUser().SubKeyCount());
  }

  TEST_F(RegistryKeyUT, DeleteSubKeyTreeWithExistingSubKeyAndBadCast) {
    Registry::CurrentUser().CreateSubKey("UnitTest");
    int32 count = Registry::CurrentUser().SubKeyCount();
    ASSERT_NO_THROW(Registry::CurrentUser().DeleteSubKeyTree("UNITTEST"));
    ASSERT_EQ(count - 1, Registry::CurrentUser().SubKeyCount());
  }

  TEST_F(RegistryKeyUT, DeleteSubKeyTreeWithExistingSubKeyNotEmpty) {
    Registry::CurrentUser().CreateSubKey("UnitTest").CreateSubKey("SubKey1");
    int32 count = Registry::CurrentUser().SubKeyCount();
    ASSERT_NO_THROW(Registry::CurrentUser().DeleteSubKeyTree("UnitTest"));
    ASSERT_EQ(count - 1, Registry::CurrentUser().SubKeyCount());
  }

  TEST_F(RegistryKeyUT, GetSubKeyNamesWithNoSubKey) {
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    ASSERT_EQ(0, key.GetSubKeyNames().Count);
  }

  TEST_F(RegistryKeyUT, GetSubKeyNamesWithOneSubKey) {
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    key.CreateSubKey("SubKey1");
    ASSERT_EQ(1, key.GetSubKeyNames().Count);
    ASSERT_EQ("SubKey1", key.GetSubKeyNames()[0]);
  }

  TEST_F(RegistryKeyUT, GetSubKeyNamesWithSubKeys) {
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    key.CreateSubKey("SubKey1");
    key.CreateSubKey("SubKey2");
    key.CreateSubKey("SubKey3");
    ASSERT_EQ(3, key.GetSubKeyNames().Count);
    ASSERT_EQ("SubKey1", key.GetSubKeyNames()[0]);
    ASSERT_EQ("SubKey2", key.GetSubKeyNames()[1]);
    ASSERT_EQ("SubKey3", key.GetSubKeyNames()[2]);
  }

  TEST_F(RegistryKeyUT, GetValuesWithNoKey) {
    Registry::CurrentUser().CreateSubKey("UnitTest");
    ASSERT_EQ(RegistryKey::Null, Registry::CurrentUser().OpenSubKey("UnitTest").GetValue("Key1"));
  }

  TEST_F(RegistryKeyUT, GetValuesWithEmptyKey) {
    Registry::CurrentUser().CreateSubKey("UnitTest");
    ASSERT_EQ(RegistryKey::Null, Registry::CurrentUser().OpenSubKey("UnitTest").GetValue(""));
  }

  //TEST_F(RegistryKeyUT, GetValuesWithInBaseKey) {
  //  Registry::CurrentUser().SetValue("Key1", "Value1");
  //  ASSERT_EQ("Value1", static_cast<const string&>(Registry::CurrentUser().GetValue("Key1")));
  //  Registry::CurrentUser().DeleteValue("Key1");
  //}

  TEST_F(RegistryKeyUT, GetValuesWithInSubKey) {
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    key.SetValue("Key1", "Value1");
    ASSERT_EQ("Value1", static_cast<const string&>(key.GetValue("Key1", "None")));
  }

  TEST_F(RegistryKeyUT, OpenBaseKeyClassesRoot) {
    ASSERT_EQ("HKEY_CLASSES_ROOT", RegistryKey::OpenBaseKey(RegistryHive::ClassesRoot).Name());
  }

  TEST_F(RegistryKeyUT, OpenBaseKeyCurrentConfig) {
    ASSERT_EQ("HKEY_CURRENT_CONFIG", RegistryKey::OpenBaseKey(RegistryHive::CurrentConfig).Name());
  }

  TEST_F(RegistryKeyUT, OpenBaseKeyCurrentUser) {
    ASSERT_EQ("HKEY_CURRENT_USER", RegistryKey::OpenBaseKey(RegistryHive::CurrentUser).Name());
  }

  TEST_F(RegistryKeyUT, OpenBaseKeyDynData) {
    ASSERT_EQ("HKEY_DYN_DATA", RegistryKey::OpenBaseKey(RegistryHive::DynData).Name());
  }

  TEST_F(RegistryKeyUT, OpenBaseKeyLocalMachine) {
    ASSERT_EQ("HKEY_LOCAL_MACHINE", RegistryKey::OpenBaseKey(RegistryHive::LocalMachine).Name());
  }

  TEST_F(RegistryKeyUT, OpenBaseKeyPerformanceData) {
    ASSERT_EQ("HKEY_PERFORMANCE_DATA", RegistryKey::OpenBaseKey(RegistryHive::PerformanceData).Name());
  }

  TEST_F(RegistryKeyUT, OpenBaseKeyUsers) {
    ASSERT_EQ("HKEY_USERS", RegistryKey::OpenBaseKey(RegistryHive::Users).Name());
  }

  TEST_F(RegistryKeyUT, SetValueString) {
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    key.SetValue("Key1", "Value1");
    ASSERT_EQ("Value1", static_cast<const String&>(key.GetValue("Key1")));
  }

  TEST_F(RegistryKeyUT, SetValueExpandString) {
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    key.SetValue("Key1", "Value%1%");
    ASSERT_EQ("Value%1%", static_cast<const String&>(key.GetValue("Key1")));
  }

  TEST_F(RegistryKeyUT, SetValueBinary) {
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    key.SetValue("Key1", Array<byte> {42, 84, 21, 126});
    ASSERT_EQ(4, static_cast<const Array<byte>&>(key.GetValue("Key1")).Length);
    ASSERT_EQ(42, static_cast<const Array<byte>&>(key.GetValue("Key1"))[0]);
    ASSERT_EQ(84, static_cast<const Array<byte>&>(key.GetValue("Key1"))[1]);
    ASSERT_EQ(21, static_cast<const Array<byte>&>(key.GetValue("Key1"))[2]);
    ASSERT_EQ(126, static_cast<const Array<byte>&>(key.GetValue("Key1"))[3]);
  }

  TEST_F(RegistryKeyUT, SetAndGetValueDWord) {
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    key.SetValue("Key1", 42);
    ASSERT_EQ(42, as<Int32>(key.GetValue("Key1")));
  }

  TEST_F(RegistryKeyUT, SetValueMultiString) {
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    key.SetValue("Key1", Array<string> {"One", "Two", "Three"});
    ASSERT_EQ(3, as<Array<String>>(key.GetValue("Key1")).Length);
    ASSERT_EQ("One", as<Array<String>>(key.GetValue("Key1"))[0]);
    ASSERT_EQ("Two", as<Array<String>>(key.GetValue("Key1"))[1]);
    ASSERT_EQ("Three", as<Array<String>>(key.GetValue("Key1"))[2]);
  }

  TEST_F(RegistryKeyUT, SetAndGetValueAny) {
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    key.SetValue("Key1", TimeSpan(2, 4, 32));
    ASSERT_EQ(TimeSpan(2, 4, 32), TimeSpan::Parse(key.GetValue("Key1").ToString()));
  }

  TEST_F(RegistryKeyUT, SetAndGetValueWithRegistryValueKindString) {
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    key.SetValue("Key1", "Value1", RegistryValueKind::String);
    ASSERT_EQ("Value1", static_cast<const String&>(key.GetValue("Key1")));
  }

  TEST_F(RegistryKeyUT, SetAndGetValueWithRegistryValueKindExpandString) {
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    key.SetValue("Key1", "Value%1%", RegistryValueKind::ExpandString);
    ASSERT_EQ("Value%1%", static_cast<const String&>(key.GetValue("Key1")));
  }

  TEST_F(RegistryKeyUT, SetValueKindBinary) {
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    key.SetValue("Key1", Array<byte> {42, 84, 21, 126}, RegistryValueKind::Binary);
    ASSERT_EQ(4, static_cast<const Array<byte>&>(key.GetValue("Key1")).Length);
    ASSERT_EQ(42, static_cast<const Array<byte>&>(key.GetValue("Key1"))[0]);
    ASSERT_EQ(84, static_cast<const Array<byte>&>(key.GetValue("Key1"))[1]);
    ASSERT_EQ(21, static_cast<const Array<byte>&>(key.GetValue("Key1"))[2]);
    ASSERT_EQ(126, static_cast<const Array<byte>&>(key.GetValue("Key1"))[3]);
  }

  TEST_F(RegistryKeyUT, SetAndGetValueWithRegistryValueKindDWord) {
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    key.SetValue("Key1", 42, RegistryValueKind::DWord);
    ASSERT_EQ(42, static_cast<const Int32&>(key.GetValue("Key1")));
  }

  TEST_F(RegistryKeyUT, SetValueKindMultiString) {
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    key.SetValue("Key1", Array<string> {"One", "Two", "Three"}, RegistryValueKind::MultiString);
    ASSERT_EQ(3, static_cast<const Array<String>&>(key.GetValue("Key1")).Length);
    ASSERT_EQ("One", static_cast<const Array<String>&>(key.GetValue("Key1"))[0]);
    ASSERT_EQ("Two", static_cast<const Array<String>&>(key.GetValue("Key1"))[1]);
    ASSERT_EQ("Three", static_cast<const Array<String>&>(key.GetValue("Key1"))[2]);
  }

  TEST_F(RegistryKeyUT, SetAndGetValueWithRegistryValueKindQWord) {
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    key.SetValue("Key1", 42, RegistryValueKind::QWord);
    ASSERT_EQ(42, Int64::Parse(key.GetValue("Key1").ToString()));
  }

  TEST_F(RegistryKeyUT, SetAndGetValueWithRegistryValueKindUnknown) {
    RegistryKey key = Registry::CurrentUser().CreateSubKey("UnitTest");
    key.SetValue("Key1", TimeSpan(2, 4, 32), RegistryValueKind::Unknown);
    ASSERT_EQ(TimeSpan(2, 4, 32), TimeSpan::Parse(key.GetValue("Key1").ToString()));
  }
}
