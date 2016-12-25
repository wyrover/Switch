using System;
using NUnit.Framework;

namespace CSharpUnitTests {
  [TestFixture]
  public class DateTimetUT {
    [Test]
    public void MinValue() {
      Assert.AreEqual(DateTimeKind.Unspecified, DateTime.MinValue.Kind);
      Assert.AreEqual(0, DateTime.MinValue.Ticks);
      Assert.AreEqual(1, DateTime.MinValue.Year);
      Assert.AreEqual(1, DateTime.MinValue.Month);
      Assert.AreEqual(1, DateTime.MinValue.Day);
      Assert.AreEqual(0, DateTime.MinValue.Hour);
      Assert.AreEqual(0, DateTime.MinValue.Minute);
      Assert.AreEqual(0, DateTime.MinValue.Second);
      Assert.AreEqual(DayOfWeek.Monday, DateTime.MinValue.DayOfWeek);
      Assert.IsFalse(DateTime.MinValue.IsDaylightSavingTime());
    }

    [Test]
    public void MaxValue() {
      Assert.AreEqual(DateTimeKind.Unspecified, DateTime.MaxValue.Kind);
      Assert.AreEqual(3155378975999999999L, DateTime.MaxValue.Ticks);
      Assert.AreEqual(9999, DateTime.MaxValue.Year);
      Assert.AreEqual(12, DateTime.MaxValue.Month);
      Assert.AreEqual(31, DateTime.MaxValue.Day);
      Assert.AreEqual(23, DateTime.MaxValue.Hour);
      Assert.AreEqual(59, DateTime.MaxValue.Minute);
      Assert.AreEqual(59, DateTime.MaxValue.Second);
      Assert.AreEqual(DayOfWeek.Friday, DateTime.MaxValue.DayOfWeek);
      Assert.IsFalse(DateTime.MaxValue.IsDaylightSavingTime());
    }

    [Test]
    public void DefaultConstructor() {
      DateTime dateTime = new DateTime();
      Assert.AreEqual(DayOfWeek.Monday, dateTime.DayOfWeek);
      Assert.AreEqual(0, dateTime.Ticks);
      Assert.AreEqual(1, dateTime.Year);
      Assert.AreEqual(1, dateTime.Month);
      Assert.AreEqual(1, dateTime.Day);
      Assert.AreEqual(0, dateTime.Hour);
      Assert.AreEqual(0, dateTime.Minute);
      Assert.AreEqual(0, dateTime.Second);
      Assert.AreEqual(DateTimeKind.Unspecified, dateTime.Kind);
      Assert.AreEqual(DayOfWeek.Monday, dateTime.DayOfWeek);
      Assert.IsFalse(dateTime.IsDaylightSavingTime());
    }

    [Test]
    public void ConstructorByTicksWith0() {
      DateTime dateTime = new DateTime(0);
      Assert.AreEqual(DateTimeKind.Unspecified, dateTime.Kind);
      Assert.AreEqual(0, dateTime.Ticks);
      Assert.AreEqual(1, dateTime.Year);
      Assert.AreEqual(1, dateTime.Month);
      Assert.AreEqual(1, dateTime.Day);
      Assert.AreEqual(0, dateTime.Hour);
      Assert.AreEqual(0, dateTime.Minute);
      Assert.AreEqual(0, dateTime.Second);
      Assert.AreEqual(DayOfWeek.Monday, dateTime.DayOfWeek);
      Assert.IsFalse(dateTime.IsDaylightSavingTime());
    }

    [Test]
    public void ConstructorByTicksWith0AndDateTimeKinUnspecified()
    {
      DateTime dateTime = new DateTime(0, DateTimeKind.Unspecified);
      Assert.AreEqual(DateTimeKind.Unspecified, dateTime.Kind);
      Assert.AreEqual(0, dateTime.Ticks);
      Assert.AreEqual(1, dateTime.Year);
      Assert.AreEqual(1, dateTime.Month);
      Assert.AreEqual(1, dateTime.Day);
      Assert.AreEqual(0, dateTime.Hour);
      Assert.AreEqual(0, dateTime.Minute);
      Assert.AreEqual(0, dateTime.Second);
      Assert.AreEqual(DayOfWeek.Monday, dateTime.DayOfWeek);
      Assert.IsFalse(dateTime.IsDaylightSavingTime());
    }

    [Test]
    public void ConstructorByTicksWith0AndDateTimeKindLocal()
    {
      DateTime dateTime = new DateTime(0, DateTimeKind.Local);
      Assert.AreEqual(DateTimeKind.Local, dateTime.Kind);
      Assert.AreEqual(0, dateTime.Ticks);
      Assert.AreEqual(1, dateTime.Year);
      Assert.AreEqual(1, dateTime.Month);
      Assert.AreEqual(1, dateTime.Day);
      Assert.AreEqual(0, dateTime.Hour);
      Assert.AreEqual(0, dateTime.Minute);
      Assert.AreEqual(0, dateTime.Second);
      Assert.AreEqual(DayOfWeek.Monday, dateTime.DayOfWeek);
      Assert.IsFalse(dateTime.IsDaylightSavingTime());
    }

    [Test]
    public void ConstructorByTicksWith0AndDateTimeKindUtc()
    {
      DateTime dateTime = new DateTime(0, DateTimeKind.Utc);
      Assert.AreEqual(DateTimeKind.Utc, dateTime.Kind);
      Assert.AreEqual(0, dateTime.Ticks);
      Assert.AreEqual(1, dateTime.Year);
      Assert.AreEqual(1, dateTime.Month);
      Assert.AreEqual(1, dateTime.Day);
      Assert.AreEqual(0, dateTime.Hour);
      Assert.AreEqual(0, dateTime.Minute);
      Assert.AreEqual(0, dateTime.Second);
      Assert.AreEqual(DayOfWeek.Monday, dateTime.DayOfWeek);
      Assert.IsFalse(dateTime.IsDaylightSavingTime());
    }

    [Test]
    public void ConstructorByTicksWith31241376000000000L() {
      DateTime dateTime = new DateTime(31241376000000000L);
      Assert.AreEqual(DateTimeKind.Unspecified, dateTime.Kind);
      Assert.AreEqual(31241376000000000L, dateTime.Ticks);
      Assert.AreEqual(100, dateTime.Year);
      Assert.AreEqual(1, dateTime.Month);
      Assert.AreEqual(1, dateTime.Day);
      Assert.AreEqual(0, dateTime.Hour);
      Assert.AreEqual(0, dateTime.Minute);
      Assert.AreEqual(0, dateTime.Second);
      Assert.AreEqual(DayOfWeek.Friday, dateTime.DayOfWeek);
      Assert.IsFalse(dateTime.IsDaylightSavingTime());
    }

    [Test]
    public void ConstructorByTicksWith504911232000000000L() {
      DateTime dateTime = new DateTime(504911232000000000L);
      Assert.AreEqual(DateTimeKind.Unspecified, dateTime.Kind);
      Assert.AreEqual(504911232000000000L, dateTime.Ticks);
      Assert.AreEqual(1601, dateTime.Year);
      Assert.AreEqual(1, dateTime.Month);
      Assert.AreEqual(1, dateTime.Day);
      Assert.AreEqual(0, dateTime.Hour);
      Assert.AreEqual(0, dateTime.Minute);
      Assert.AreEqual(0, dateTime.Second);
      Assert.AreEqual(DayOfWeek.Monday, dateTime.DayOfWeek);
      Assert.IsFalse(dateTime.IsDaylightSavingTime());
    }

    [Test]
    public void ConstructorByTicksWith633452274520000000LAndKindSetToLocal() {
      System.DateTime dateTime = new System.DateTime(633452274520000000L, DateTimeKind.Local);
      Assert.AreEqual(DateTimeKind.Local, dateTime.Kind);
      Assert.AreEqual(633452274520000000L, dateTime.Ticks);
      Assert.AreEqual(2008, dateTime.Year);
      Assert.AreEqual(5, dateTime.Month);
      Assert.AreEqual(1, dateTime.Day);
      //Assert.AreEqual(8+TimeZoneInfo.Local.BaseUtcOffset.Hours + (dateTime.IsDaylightSavingTime() ? 1 : 0), dateTime.Hour);
      Assert.AreEqual(8, dateTime.Hour);
      Assert.AreEqual(30, dateTime.Minute);
      Assert.AreEqual(52, dateTime.Second);
      Assert.AreEqual(DayOfWeek.Thursday, dateTime.DayOfWeek);
      Assert.IsTrue(dateTime.IsDaylightSavingTime());
    }

    [Test]
    public void ConstructorByTicksWith633452274520000000LAndKindSetToUtc() {
      DateTime dateTime = new DateTime(633452274520000000L, DateTimeKind.Utc);
      Assert.AreEqual(633452274520000000L, dateTime.Ticks);
      Assert.AreEqual(2008, dateTime.Year);
      Assert.AreEqual(5, dateTime.Month);
      Assert.AreEqual(1, dateTime.Day);
      Assert.AreEqual(8, dateTime.Hour);
      Assert.AreEqual(30, dateTime.Minute);
      Assert.AreEqual(52, dateTime.Second);
      Assert.AreEqual(DateTimeKind.Utc, dateTime.Kind);
      Assert.IsFalse(dateTime.IsDaylightSavingTime());
    }

    [Test]
    public void ConstructorByYearMonthDayHourMinuteSecondWithValueWithDayligthSet() {
      DateTime dateTime = new DateTime(2011, 10, 30, 1, 59, 58);
      Assert.AreEqual(DateTimeKind.Unspecified, dateTime.Kind);
      Assert.AreEqual(2011, dateTime.Year);
      Assert.AreEqual(10, dateTime.Month);
      Assert.AreEqual(30, dateTime.Day);
      Assert.AreEqual(1, dateTime.Hour);
      Assert.AreEqual(59, dateTime.Minute);
      Assert.AreEqual(58, dateTime.Second);
      Assert.IsTrue(dateTime.IsDaylightSavingTime());
    }

    [Test]
    public void ConstructorByYearMonthDayHourMinuteSecondKindWithkindToLocalAndValueWithDayligthSet() {
      DateTime dateTime = new DateTime(2011, 10, 30, 1, 59, 58, DateTimeKind.Local);
      Assert.AreEqual(DateTimeKind.Local, dateTime.Kind);
      Assert.AreEqual(2011, dateTime.Year);
      Assert.AreEqual(10, dateTime.Month);
      Assert.AreEqual(30, dateTime.Day);
      Assert.AreEqual(1, dateTime.Hour);
      Assert.AreEqual(59, dateTime.Minute);
      Assert.AreEqual(58, dateTime.Second);
      Assert.IsTrue(dateTime.IsDaylightSavingTime());
    }

    [Test]
    public void ConstructorByYearMonthDayHourMinuteSecondKindWithkindToUtcAndValueWithDayligthSet() {
      DateTime dateTime = new DateTime(2011, 10, 30, 1, 59, 58, DateTimeKind.Utc);
      Assert.AreEqual(DateTimeKind.Utc, dateTime.Kind);
      Assert.AreEqual(2011, dateTime.Year);
      Assert.AreEqual(10, dateTime.Month);
      Assert.AreEqual(30, dateTime.Day);
      Assert.AreEqual(1, dateTime.Hour);
      Assert.AreEqual(59, dateTime.Minute);
      Assert.AreEqual(58, dateTime.Second);
      Assert.IsFalse(dateTime.IsDaylightSavingTime());
    }

    //[Test, Ignore]
    public void Now() {
      DateTime now = DateTime.Now;
      Console.WriteLine("now    ({0}) {1}", now.Ticks, now);
      DateTime utcNow = DateTime.UtcNow;
      Console.WriteLine("utcNow ({0}) {1}", utcNow.Ticks, utcNow);
    }

  }
}
