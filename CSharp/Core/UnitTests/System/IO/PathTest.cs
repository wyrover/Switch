using System;
using NUnit.Framework;

namespace CSharpUnitTests {
  [TestFixture]
  public class PathUT {
    [Test]
    public void ChangeExtensionFileNameWithExtensionAndExtensionWithPeriod() {
      Assert.AreEqual("file.jpg", System.IO.Path.ChangeExtension("file.txt", ".jpg"));
    }

    [Test]
    public void ChangeExtensionFileNameWithExtensionAndExtensionWithoutPeriod() {
      Assert.AreEqual("file.jpg", System.IO.Path.ChangeExtension("file.txt", "jpg"));
    }

    [Test]
    public void ChangeExtensionFileNameWithExtensionAndEmptyExtension() {
      Assert.AreEqual("file.", System.IO.Path.ChangeExtension("file.txt", ""));
    }

    [Test]
    public void ChangeExtensionFileNameEndWithPeriodAndExtensionWithPeriod() {
      Assert.AreEqual("file.jpg", System.IO.Path.ChangeExtension("file.", ".jpg"));
    }

    [Test]
    public void ChangeExtensionFileNameEndWithPeriodAndExtensionWithoutPeriod() {
      Assert.AreEqual("file.jpg", System.IO.Path.ChangeExtension("file.", "jpg"));
    }

    [Test]
    public void ChangeExtensionFileNameEndWithPeriodAndEmptyExtension() {
      Assert.AreEqual("file.", System.IO.Path.ChangeExtension("file.", ""));
    }

    [Test]
    public void ChangeExtensionFileNameWithoutExtensionAndExtensionWithPeriod() {
      Assert.AreEqual("file.jpg", System.IO.Path.ChangeExtension("file", ".jpg"));
    }

    [Test]
    public void ChangeExtensionFileNameWithoutExtensionAndExtensionWithoutPeriod() {
      Assert.AreEqual("file.jpg", System.IO.Path.ChangeExtension("file", "jpg"));
    }

    [Test]
    public void ChangeExtensionFileNameWithoutExtensionAndEmptyExtension() {
      Assert.AreEqual("file.", System.IO.Path.ChangeExtension("file", ""));
    }

    [Test]
    public void ChangeExtensionEmptyFileNameAndExtensionWithPeriod() {
      Assert.AreEqual("", System.IO.Path.ChangeExtension("", ".jpg"));
    }

    [Test]
    public void ChangeExtensionEmptyFileNameAndExtensionWithoutPeriod() {
      Assert.AreEqual("", System.IO.Path.ChangeExtension("", "jpg"));
    }

    [Test]
    public void ChangeExtensionElptyFileNameAndEmptyExtension() {
      Assert.AreEqual(".", System.IO.Path.ChangeExtension("", ""));
    }

    [Test]
    public void GetExtentionFromFileWithoutExtension() {
      string path = "MyFile";
      Assert.AreEqual("", System.IO.Path.GetExtension(path));
    }

    [Test]
    public void GetExtentionFromFileWithExtension() {
      string path = "MyFile.ext";
      Assert.AreEqual(".ext", System.IO.Path.GetExtension(path));
    }

    [Test]
    public void GetExtentionFromPathFileWithExtension() {
      string path = "Path/MyFile.ext";
      Assert.AreEqual(".ext", System.IO.Path.GetExtension(path));
    }

    [Test]
    public void GetExtentionFromAbsolutePathFileWithExtension() {
      string path = "/Path/MyFile.ext";
      Assert.AreEqual(".ext", System.IO.Path.GetExtension(path));
    }

    [Test]
    public void GetExtentionFromAbsolutePathFilePatternExtension() {
      string path = "/Users/Test/MyPath/MyFile.Pattern.ext";
      Assert.AreEqual(".ext", System.IO.Path.GetExtension(path));
    }
  }
}
