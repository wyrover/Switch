using System;
using NUnit.Framework;

namespace CSharpUnitTests {
  [TestFixture]
  public class MathUT {
    [Test]
    public void Exp() {
      Assert.AreEqual(1, Math.Exp(.0));
      Assert.IsTrue(Double.IsNaN(Math.Exp(Double.NaN)));
      Assert.IsTrue(Double.IsPositiveInfinity(Math.Exp(Double.PositiveInfinity)));
      Assert.AreEqual(0, Math.Exp(Double.NegativeInfinity));
    }
  }
}
