using System;
using System.Threading;
using NUnit.Framework;

namespace CSharpUnitTests {
  public class TimerTest {
    public TimerTest() {
      this.Number = 0;
      this.Event = new AutoResetEvent(false);
      this.State = null;
    }

    public void Run(object state) {}
    
    public Int32 Number { get; set; }
    
    public AutoResetEvent Event { get; set; }

    public object State { get; set; }
  }

  [TestFixture]
  public class TimerUT {
    [Test]
    public void CreateTimerWithoutDueTimeAndWithoutPeriod() {
      TimerTest test = new TimerTest();
      using (Timer timer = new Timer(test.Run)) {
        Assert.IsFalse(test.Event.WaitOne(10));
        Assert.AreEqual(0, test.Number);
        Assert.IsNull(test.State);
      }
    }
  }
}
