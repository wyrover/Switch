using System;
using Microsoft.Win32;
using NUnit.Framework;

namespace CSharpUnitTests {
  [TestFixture]
  public class RegistryUT {
    [Test]
    public void ClassesRoot() {
      Assert.AreEqual("HKEY_CLASSES_ROOT", Registry.ClassesRoot.Name);
    }

    [Test]
    public void CurrentConfig() {
      Assert.AreEqual("HKEY_CURRENT_CONFIG", Registry.CurrentConfig.Name);
    }

    [Test]
    public void CurrentUser() {
      Assert.AreEqual("HKEY_CURRENT_USER", Registry.CurrentUser.Name);
    }

    [Test]
    public void LocalMachine() {
      Assert.AreEqual("HKEY_LOCAL_MACHINE", Registry.LocalMachine.Name);
    }

    [Test]
    public void PerformanceData() {
      Assert.AreEqual("HKEY_PERFORMANCE_DATA", Registry.PerformanceData.Name);
    }

    [Test]
    public void Users() {
      Assert.AreEqual("HKEY_USERS", Registry.Users.Name);
    }

    [Test]
    public void StringDefaultConstructor() {
      if (Environment.OSVersion.Platform == PlatformID.Win32NT) {
        string str1 = null;
        Assert.Throws<System.NullReferenceException>(delegate {
          new string(str1.ToCharArray());
        });
      }
    }
  }
}
