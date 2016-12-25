using System;
using System.Drawing;
using NUnit.Framework;

namespace CSharpUnitTests {
  [TestFixture]
  public class ColorTest {
    [Test]
    public void DefaultContructor() {
      Color color = new Color();
      Assert.AreEqual(0, color.A);
      Assert.AreEqual(0, color.R);
      Assert.AreEqual(0, color.G);
      Assert.AreEqual(0, color.B);
      Assert.IsTrue(color.IsEmpty);
      Assert.IsFalse(color.IsKnownColor);
      Assert.IsFalse(color.IsNamedColor);
      Assert.IsFalse(color.IsSystemColor);
      Assert.AreEqual("0", color.Name);
      Assert.AreEqual("Color [Empty]", color.ToString());
    }
  }
}
