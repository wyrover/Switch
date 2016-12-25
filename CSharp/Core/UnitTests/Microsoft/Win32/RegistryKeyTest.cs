using System;
using Microsoft.Win32;
using NUnit.Framework;

namespace CSharpUnitTests {
  [TestFixture]
  public class RegistryKeyUT {
    [SetUp()]
    public void SetUp() {
      Registry.CurrentUser.DeleteSubKeyTree("UnitTest", false);
    }

    [TearDown]
    public void TearDown() {
      Registry.CurrentUser.DeleteSubKeyTree("UnitTest", false);
    }

    [Test]
    public void CreateSubKeyWithNullSubKeyName() {
      Assert.Throws<ArgumentNullException>(delegate {
        Registry.CurrentUser.CreateSubKey(null);
      });
    }

    [Test]
    public void CreateSubKeyWithEmptySubKeyName() {
      Int32 count = Registry.CurrentUser.SubKeyCount;
      Registry.CurrentUser.CreateSubKey("");
      Assert.AreEqual(count, Registry.CurrentUser.SubKeyCount);
    }

    [Test]
    public void CreateSubKeyWithNotExistingSubKey() {
      Int32 count = Registry.CurrentUser.SubKeyCount;
      RegistryKey key = Registry.CurrentUser.CreateSubKey("UnitTest");
      Assert.AreEqual(count + 1, Registry.CurrentUser.SubKeyCount);
      Assert.AreEqual("HKEY_CURRENT_USER\\UnitTest".ToLower(), key.Name.ToLower());
    }

    [Test]
    public void CreateSubKeyWithExistingSubKey() {
      Int32 count = Registry.CurrentUser.SubKeyCount;
      Registry.CurrentUser.CreateSubKey("UnitTest");
      Assert.AreEqual(count + 1, Registry.CurrentUser.SubKeyCount);
      RegistryKey key = Registry.CurrentUser.CreateSubKey("UnitTest");
      Assert.AreEqual(count + 1, Registry.CurrentUser.SubKeyCount);
      Assert.AreEqual("HKEY_CURRENT_USER\\UnitTest".ToLower(), key.Name.ToLower());
    }

    [Test]
    public void CreateSubKeyWithExistingSubKeyAndOtherCast() {
      Int32 count = Registry.CurrentUser.SubKeyCount;
      Registry.CurrentUser.CreateSubKey("UnitTest");
      Assert.AreEqual(count + 1, Registry.CurrentUser.SubKeyCount);
      Assert.AreEqual("HKEY_CURRENT_USER\\UNITTEST".ToLower(), Registry.CurrentUser.CreateSubKey("UNITTEST").Name.ToLower());
      Assert.AreEqual(count + 1, Registry.CurrentUser.SubKeyCount);
      Assert.AreEqual("HKEY_CURRENT_USER\\unittest".ToLower(), Registry.CurrentUser.CreateSubKey("unittest").Name.ToLower());
      Assert.AreEqual(count + 1, Registry.CurrentUser.SubKeyCount);
      Assert.AreEqual("HKEY_CURRENT_USER\\UnItTeSt".ToLower(), Registry.CurrentUser.CreateSubKey("UnItTeSt").Name.ToLower());
      Assert.AreEqual(count + 1, Registry.CurrentUser.SubKeyCount);
    }

    [Test]
    public void CreateSubKeyInASubKey() {
      RegistryKey key = Registry.CurrentUser.CreateSubKey("UnitTest").CreateSubKey("SubKey1");
      Assert.AreEqual("HKEY_CURRENT_USER\\UnitTest\\SubKey1".ToLower(), key.Name.ToLower());
    }

    [Test]
    public void CreateSubKeyWithReadPermission() {
      if (Environment.OSVersion.Platform == PlatformID.Win32NT) {
        Assert.Throws<UnauthorizedAccessException>(delegate {
          Registry.CurrentUser.CreateSubKey("UnitTest", RegistryKeyPermissionCheck.ReadSubTree).CreateSubKey("SubKey1");
        });
      }
    }

    [Test]
    public void CreateSubKeyWithReadWritePermission() {
      Registry.CurrentUser.CreateSubKey("UnitTest", RegistryKeyPermissionCheck.ReadWriteSubTree).CreateSubKey("SubKey1");
    }

    [Test]
    public void DeleteSubKeyWithNullSubkey() {
      Assert.Throws<ArgumentNullException>(delegate {
        Registry.CurrentUser.DeleteSubKey(null);
      });
    }

    [Test]
    public void DeleteSubKeyWithEmptySubKey() {
      if (Environment.OSVersion.Platform == PlatformID.Win32NT) {
        Assert.Throws<InvalidOperationException>(delegate {
          Registry.CurrentUser.DeleteSubKey("");
        });
      }
    }

    [Test]
    public void DeleteSubKeyWithBaseSubKey() {
      Assert.Throws<ArgumentException>(delegate {
        Registry.CurrentUser.DeleteSubKey("HKEY_CURRENT_USER");
      });
    }

    [Test]
    public void DeleteSubKeyWithNotExistingSubKey() {
      Assert.Throws<ArgumentException>(delegate {
        Registry.CurrentUser.DeleteSubKey("UnitTest");
      });
    }

    [Test]
    public void DeleteSubKeyWithNotExistingSubKeyAndThrowMissingToTrue() {
      Assert.Throws<ArgumentException>(delegate {
        Registry.CurrentUser.DeleteSubKey("UnitTest", true);
      });
    }

    [Test]
    public void DeleteSubKeyWithNotExistingSubKeyAndThrowMissingToFalse() {
      Registry.CurrentUser.DeleteSubKey("UnitTest", false);
    }

    [Test]
    public void DeleteSubKeyWithExistingSubKey() {
      Registry.CurrentUser.CreateSubKey("UnitTest");
      Int32 count = Registry.CurrentUser.SubKeyCount;
      Registry.CurrentUser.DeleteSubKey("UnitTest");
      Assert.AreEqual(count - 1, Registry.CurrentUser.SubKeyCount);
    }

    [Test]
    public void DeleteSubKeyWithExistingSubKeyAndBadCast() {
      Registry.CurrentUser.CreateSubKey("UnitTest");
      Int32 count = Registry.CurrentUser.SubKeyCount;
      Registry.CurrentUser.DeleteSubKey("UNITTEST");
      Assert.AreEqual(count - 1, Registry.CurrentUser.SubKeyCount);
    }

    [Test]
    public void DeleteSubKeyWithExistingSubKeyNotEmpty() {
      Registry.CurrentUser.CreateSubKey("UnitTest").CreateSubKey("SubKey1");
      Assert.Throws<InvalidOperationException>(delegate {
        Registry.CurrentUser.DeleteSubKey("UnitTest");
      });
    }

    [Test]
    public void DeleteSubKeyTreeWithNullSubkey() {
      Assert.Throws<ArgumentNullException>(delegate {
        Registry.CurrentUser.DeleteSubKeyTree(null);
      });
    }

    [Test]
    public void DeleteSubKeyTreeWithEmptySubKey() {
      if (Environment.OSVersion.Platform == PlatformID.Win32NT) {
        Assert.Throws<ArgumentException>(delegate {
          Registry.CurrentUser.DeleteSubKeyTree("");
        });
      }
    }

    [Test]
    public void DeleteSubKeyTreeWithBaseSubKey() {
      Assert.Throws<ArgumentException>(delegate {
        Registry.CurrentUser.DeleteSubKeyTree("HKEY_CURRENT_USER");
      });
    }

    [Test]
    public void DeleteSubKeyTreeWithNotExistingSubKey() {
      Assert.Throws<ArgumentException>(delegate {
        Registry.CurrentUser.DeleteSubKeyTree("UnitTest");
      });
    }

    [Test]
    public void DeleteSubKeyTreeWithNotExistingSubKeyAndThrowMissingToTrue() {
      Assert.Throws<ArgumentException>(delegate {
        Registry.CurrentUser.DeleteSubKeyTree("UnitTest", true);
      });
    }

    [Test]
    public void DeleteSubKeyTreeWithNotExistingSubKeyAndThrowMissingToFalse() {
      Registry.CurrentUser.DeleteSubKeyTree("UnitTest", false);
    }

    [Test]
    public void DeleteSubKeyTreeWithExistingSubKey() {
      Registry.CurrentUser.CreateSubKey("UnitTest");
      Int32 count = Registry.CurrentUser.SubKeyCount;
      Registry.CurrentUser.DeleteSubKeyTree("UnitTest");
      Assert.AreEqual(count - 1, Registry.CurrentUser.SubKeyCount);
    }

    [Test]
    public void DeleteSubKeyTreeWithExistingSubKeyAndBadCast() {
      Registry.CurrentUser.CreateSubKey("UnitTest");
      Int32 count = Registry.CurrentUser.SubKeyCount;
      Registry.CurrentUser.DeleteSubKeyTree("UNITTEST");
      Assert.AreEqual(count - 1, Registry.CurrentUser.SubKeyCount);
    }

    [Test]
    public void DeleteSubKeyTreeWithExistingSubKeyNotEmpty() {
      Registry.CurrentUser.CreateSubKey("UnitTest").CreateSubKey("SubKey1");
      Int32 count = Registry.CurrentUser.SubKeyCount;
      Registry.CurrentUser.DeleteSubKeyTree("UnitTest");
      Assert.AreEqual(count - 1, Registry.CurrentUser.SubKeyCount);
    }

    [Test]
    public void GetSubKeyNamesWithNoSubKey() {
      RegistryKey key = Registry.CurrentUser.CreateSubKey("UnitTest");
      Assert.AreEqual(0, key.GetSubKeyNames().Length);
    }

    [Test]
    public void GetSubKeyNamesWithOneSubKey() {
      RegistryKey key = Registry.CurrentUser.CreateSubKey("UnitTest");
      key.CreateSubKey("SubKey1");
      Assert.AreEqual(1, key.GetSubKeyNames().Length);
      Assert.AreEqual("SubKey1".ToLower(), key.GetSubKeyNames()[0].ToLower());
    }

    [Test]
    public void GetSubKeyNamesWithSubKeys() {
      RegistryKey key = Registry.CurrentUser.CreateSubKey("UnitTest");
      key.CreateSubKey("SubKey1");
      key.CreateSubKey("SubKey2");
      key.CreateSubKey("SubKey3");
      Assert.AreEqual(3, key.GetSubKeyNames().Length);
      Assert.AreEqual("SubKey1".ToLower(), key.GetSubKeyNames()[0].ToLower());
      Assert.AreEqual("SubKey2".ToLower(), key.GetSubKeyNames()[1].ToLower());
      Assert.AreEqual("SubKey3".ToLower(), key.GetSubKeyNames()[2].ToLower());
    }

    [Test]
    public void OpenBaseKeyClassesRoot() {
      Assert.AreEqual("HKEY_CLASSES_ROOT", RegistryKey.OpenBaseKey(RegistryHive.ClassesRoot, RegistryView.Default).Name);
    }

    [Test]
    public void OpenBaseKeyCurrentConfig() {
      Assert.AreEqual("HKEY_CURRENT_CONFIG", RegistryKey.OpenBaseKey(RegistryHive.CurrentConfig, RegistryView.Default).Name);
    }

    [Test]
    public void OpenBaseKeyCurrentUser() {
      Assert.AreEqual("HKEY_CURRENT_USER", RegistryKey.OpenBaseKey(RegistryHive.CurrentUser, RegistryView.Default).Name);
    }

    [Test]
    public void OpenBaseKeyDynData() {
      Assert.AreEqual("HKEY_DYN_DATA", RegistryKey.OpenBaseKey(RegistryHive.DynData, RegistryView.Default).Name);
    }

    [Test]
    public void OpenBaseKeyLocalMachine() {
      Assert.AreEqual("HKEY_LOCAL_MACHINE", RegistryKey.OpenBaseKey(RegistryHive.LocalMachine, RegistryView.Default).Name);
    }

    [Test]
    public void OpenBaseKeyPerformanceData() {
      Assert.AreEqual("HKEY_PERFORMANCE_DATA", RegistryKey.OpenBaseKey(RegistryHive.PerformanceData, RegistryView.Default).Name);
    }

    [Test]
    public void OpenBaseKeyUsers() {
      Assert.AreEqual("HKEY_USERS", RegistryKey.OpenBaseKey(RegistryHive.Users, RegistryView.Default).Name);
    }
    [Test]
    public void OpenSubKeywWithoutExistingSubKey() {
      Assert.AreEqual(null, Registry.CurrentUser.OpenSubKey("UnitTest"));
    }

    [Test]
    public void SetValueString() {
      RegistryKey key = Registry.CurrentUser.CreateSubKey("UnitTest");

      key.SetValue("Key1", "Value1");

      Assert.AreEqual("Value1", (String)key.GetValue("Key1"));
    }

    [Test]
    public void SetValueDWord() {
      RegistryKey key = Registry.CurrentUser.CreateSubKey("UnitTest");

      key.SetValue("Key1", 42);

      Assert.AreEqual(42, (Int32)key.GetValue("Key1"));
    }

    [Test]
    public void SetValueBinary() {
      RegistryKey key = Registry.CurrentUser.CreateSubKey("UnitTest");

      key.SetValue("Key1", new byte[] { 1, 2, 3, 4 });

      Assert.AreEqual(1, ((byte[])key.GetValue("Key1"))[0]);
    }

    [Test]
    public void SetValueWithRegistryValueKindString() {
      RegistryKey key = Registry.CurrentUser.CreateSubKey("UnitTest");

      key.SetValue("Key1", "Value1");

      Assert.AreEqual("Value1", (String)key.GetValue("Key1"));
    }

    [Test]
    public void SetValueWithRegistryValueKindDWord() {
      RegistryKey key = Registry.CurrentUser.CreateSubKey("UnitTest");

      key.SetValue("Key1", 42);

      Assert.AreEqual(42, (Int32)key.GetValue("Key1"));
    }

    [Test]
    public void SetValueWithRegistryValueKindQWord() {
      RegistryKey key = Registry.CurrentUser.CreateSubKey("UnitTest");

      key.SetValue("Key1", 42, RegistryValueKind.QWord);

      Assert.AreEqual(42, (Int64)key.GetValue("Key1"));
    }

    [Test]
    public void SetValueWithRegistryValueKindBinary() {
      RegistryKey key = Registry.CurrentUser.CreateSubKey("UnitTest");

      key.SetValue("Key1", new byte[] { 1, 2, 3, 4 }, RegistryValueKind.Binary);

      Assert.AreEqual(1, ((byte[])key.GetValue("Key1"))[0]);
    }
  }
}
