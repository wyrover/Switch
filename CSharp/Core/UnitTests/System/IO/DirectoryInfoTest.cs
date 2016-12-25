using System;
using NUnit.Framework;

namespace CSharpUnitTests {
  [TestFixture]
  public class DirectoryInfoUT {
    [SetUp]
    protected void SetUp() {
      System.IO.Directory.CreateDirectory(workPath);
    }

    [TearDown]
    protected void TearDown() {
      System.IO.Directory.Delete(workPath, true);
    }

    [Test]
    public void Create() {
      string path = "MyFile";
      Assert.AreEqual("", System.IO.Path.GetExtension(path));
    }

    private string workPath = System.IO.Path.Combine(System.IO.Directory.GetCurrentDirectory(), "TestUnit");
  }
}
