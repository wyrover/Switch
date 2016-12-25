using System;
using System.Text;
using NUnit.Framework;

namespace CSharpUnitTests {
  [TestFixture]
  public class StringBuilderTest {
    [Test]
    public void DefaultContructor() {
      StringBuilder sb = new StringBuilder();
      Assert.AreEqual(0, sb.Length);
      Assert.AreEqual(16, sb.Capacity);
      Assert.AreEqual("", sb.ToString());
    }

    [Test]
    public void ContructorWithCapacity() {
      StringBuilder sb = new StringBuilder(1000);
      Assert.AreEqual(0, sb.Length);
      Assert.GreaterOrEqual(sb.Capacity, 1000);
      Assert.AreEqual("", sb.ToString());
    }
  }
}
