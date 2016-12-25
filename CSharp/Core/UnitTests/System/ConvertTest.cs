using System;
using NUnit.Framework;

namespace CSharpUnitTests {
  [TestFixture]
  public class ConvertUT {
    [Test]
    public void Test() {
      //Assert.That(true, Is.False);
      Assert.That(true, Is.Not.False);
    }
    [Test]
    public void ToBooleanFromDateTime() {
      Assert.Throws<InvalidCastException>(delegate { Convert.ToBoolean(DateTime.Now); });
    }


    [Test]
    public void ToByteFromDateTime() {
      Assert.Throws<InvalidCastException>(delegate {Convert.ToByte(DateTime.Now);});
    }

    [Test]
    public void ToCharFromDateTime() {
      Assert.Throws<InvalidCastException>(delegate {Convert.ToChar(DateTime.Now);});
     }
  }
}
