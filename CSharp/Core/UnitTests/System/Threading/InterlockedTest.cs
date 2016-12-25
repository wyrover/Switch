using System;
using System.Threading;
using NUnit.Framework;

namespace CSharpUnitTests {
  [TestFixture]
  public class InterlockedTest {
    [Test]
    public void CompareExchangeDoubleIfComparandEqual() {
      double location = 0.42;
      Assert.AreEqual(0.42, Interlocked.CompareExchange(ref location, 0.24, 0.42));
      Assert.AreEqual(0.24, location);
    }

    [Test]
    public void CompareExchangeDoubleIfComparandDifferent() {
      double location = 0.42;
      Assert.AreEqual(0.42, Interlocked.CompareExchange(ref location, 0.24, 0.33));
      Assert.AreEqual(0.42, location);
    }
  }
}
