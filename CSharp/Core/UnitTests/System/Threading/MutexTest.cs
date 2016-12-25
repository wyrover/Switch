using System;
using System.Threading;
using NUnit.Framework;

namespace CSharpUnitTests {
  [TestFixture]
  public class MutexTest {
    [Test]
    public void Close() {
      Mutex mutex = new Mutex();
      mutex.Close();
      Assert.Throws<ObjectDisposedException>(delegate {
        mutex.WaitOne();
      });
    }
  }
}
