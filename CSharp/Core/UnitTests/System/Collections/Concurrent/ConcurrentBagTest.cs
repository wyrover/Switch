using System;
using System.Collections.Concurrent;
using NUnit.Framework;

namespace CSharpUnitTests {
  [TestFixture]
  public class ConcurrentBagTest {
    [Test]
    public void TryPeek() {
      ConcurrentBag<int> bag = new ConcurrentBag<int> { 0, 1, 2, 3, 4, 5};
      int result;
      Assert.IsTrue(bag.TryPeek(out result));
      Assert.AreEqual(5, result);
    }

  }
}
