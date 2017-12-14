#include <Switch/System/TimeSpan.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/FormatException.hpp>
#include <Switch/System/OverflowException.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(TimeSpan, MaxValue) {
    ASSERT_EQ(Int64::MaxValue, TimeSpan::MaxValue.Ticks);
  }

  TEST(TimeSpan, MinValue) {
    ASSERT_EQ(Int64::MinValue, TimeSpan::MinValue.Ticks);
  }

  TEST(TimeSpan, TicksPerDay) {
    ASSERT_EQ(864000000000, TimeSpan::TicksPerDay);
  }

  TEST(TimeSpan, TicksPerHour) {
    ASSERT_EQ(36000000000, TimeSpan::TicksPerHour);
  }

  TEST(TimeSpan, TicksPerMillisecond) {
    ASSERT_EQ(10000, TimeSpan::TicksPerMillisecond);
  }

  TEST(TimeSpan, TicksPerMinute) {
    ASSERT_EQ(600000000, TimeSpan::TicksPerMinute);
  }

  TEST(TimeSpan, TicksPerSecond) {
    ASSERT_EQ(10000000, TimeSpan::TicksPerSecond);
  }

  TEST(TimeSpan, Zero) {
    ASSERT_EQ(0, TimeSpan::Zero().Ticks);
  }

  TEST(TimeSpan, Ctor) {
    ASSERT_EQ(0, TimeSpan().Ticks);
  }

  TEST(TimeSpan, FromDays) {
    ASSERT_EQ(1296000000000, TimeSpan::FromDays(1.5).Ticks);
    ASSERT_EQ(38188800000000, TimeSpan::FromDays(44.2).Ticks);
  }

  TEST(TimeSpan, FromHours) {
    ASSERT_EQ(54000000000, TimeSpan::FromHours(1.5).Ticks);
    ASSERT_EQ(802800000000, TimeSpan::FromHours(22.3).Ticks);
  }

  TEST(TimeSpan, FromMilliseconds) {
    ASSERT_EQ(2570000, TimeSpan::FromMilliseconds(256.7).Ticks);
    ASSERT_EQ(2560000, TimeSpan::FromMilliseconds((int64)256.7).Ticks);
    ASSERT_EQ(290000, TimeSpan::FromMilliseconds((29.0 / 100.0) * 100).Ticks);
    ASSERT_EQ(280000, TimeSpan::FromMilliseconds(int64((29.0 / 100.0) * 100)).Ticks);
    ASSERT_EQ(-10000, TimeSpan::FromMilliseconds(-1).Ticks);
  }

  TEST(TimeSpan, FromMinutes) {
    ASSERT_EQ(458070000000, TimeSpan::FromMinutes(763.45).Ticks);
  }

  TEST(TimeSpan, FromSeconds) {
    ASSERT_EQ(35000000, TimeSpan::FromSeconds(3.5).Ticks);
  }

  TEST(TimeSpan, FromTicks) {
    ASSERT_EQ(678434567745603LL, TimeSpan::FromTicks(678434567745603LL).Ticks);
  }

  TEST(TimeSpan, CtorTicks) {
    ASSERT_EQ(1, TimeSpan(1).Ticks);
    ASSERT_EQ(-1, TimeSpan(-1).Ticks);
    ASSERT_EQ(67843456778903LL, TimeSpan(67843456778903LL).Ticks);
    ASSERT_EQ(Int64::MinValue, TimeSpan(Int64::MinValue).Ticks);
    ASSERT_EQ(Int64::MaxValue, TimeSpan(Int64::MaxValue).Ticks);
  }

  TEST(TimeSpan, CtorCopy) {
    ASSERT_EQ(67843456778903LL, TimeSpan(TimeSpan(67843456778903LL)).Ticks);
  }

  TEST(TimeSpan, CtorHoursMinutesSeconds) {
    ASSERT_EQ(37230000000, TimeSpan(1, 2, 3).Ticks);
    ASSERT_EQ(37830000000, TimeSpan(1, 2, 63).Ticks);
    ASSERT_EQ(73230000000, TimeSpan(1, 62, 3).Ticks);
    ASSERT_EQ(901230000000, TimeSpan(25, 2, 3).Ticks);
  }

  TEST(TimeSpan, CtorDaysHoursMinutesSeconds) {
    ASSERT_EQ(20773230000000, TimeSpan(24, 1, 2, 3).Ticks);
  }

  TEST(TimeSpan, CtorDaysHoursMinutesSecondsMilliSeconds) {
    ASSERT_EQ(20773230720000, TimeSpan(24, 1, 2, 3, 72).Ticks);
  }

  TEST(TimeSpan, ToString) {
    ASSERT_EQ("00:00:00", TimeSpan::Zero().ToString());
    ASSERT_EQ("-14.00:00:00", TimeSpan(-14, 0, 0, 0, 0).ToString());
    ASSERT_EQ("01:02:03", TimeSpan(1, 2, 3).ToString());
    ASSERT_EQ("00:00:00.2500000", TimeSpan(0, 0, 0, 0, 250).ToString());
    ASSERT_EQ("99.23:59:59.9990000", TimeSpan(99, 23, 59, 59, 999).ToString());
    ASSERT_EQ("03:00:00", TimeSpan(3, 0, 0).ToString());
    ASSERT_EQ("00:00:00.0250000", TimeSpan(0, 0, 0, 0, 25).ToString());
    ASSERT_EQ("00:00:00.0000023", TimeSpan(23).ToString());
    ASSERT_EQ("5.01:45:23.3896842", TimeSpan(4383233896842).ToString());
    ASSERT_EQ("-10675199.02:48:05.4775808", TimeSpan::MinValue.ToString());
    ASSERT_EQ("10675199.02:48:05.4775807", TimeSpan::MaxValue.ToString());
  }

  TEST(TimeSpan, Add) {
    TimeSpan time1 = TimeSpan::FromDays(1.5);
    TimeSpan time2 = TimeSpan::FromHours(1.5);
    TimeSpan time3 = TimeSpan::FromHours(-1.5);
    ASSERT_EQ(1350000000000, time1.Add(time2).Ticks);
    ASSERT_EQ(1242000000000, time1.Add(time3).Ticks);
  }

  TEST(TimeSpan, Compare) {
    TimeSpan time1 = TimeSpan::FromDays(1.5);
    TimeSpan time2 = TimeSpan::FromHours(1.5);
    TimeSpan time3 = TimeSpan::FromHours(-1.5);

    ASSERT_EQ(1, TimeSpan::Compare(time1, time2));
    ASSERT_EQ(0, TimeSpan::Compare(time1, time1));
    ASSERT_EQ(-1, TimeSpan::Compare(time3, time2));
  }

  TEST(TimeSpan, CompareTo) {
    TimeSpan time1 = TimeSpan::FromDays(1.5);
    TimeSpan time2 = TimeSpan::FromHours(1.5);
    TimeSpan time3 = TimeSpan::FromHours(-1.5);

    ASSERT_EQ(1, time1.CompareTo(time2));
    ASSERT_EQ(0, time1.CompareTo(time1));
    ASSERT_EQ(-1, time3.CompareTo(time2));
  }

  TEST(TimeSpan, CompareToObject) {
    TimeSpan time1 = TimeSpan::FromHours(1.5);
    TimeSpan time2 = TimeSpan::FromHours(-1.5);
    IComparable& time3 = time1;
    ASSERT_EQ(-1, time2.CompareTo(time3));
  }

  TEST(TimeSpan, Duration) {
    ASSERT_EQ(54000000000, TimeSpan::FromHours(1.5).Duration().Ticks);
    ASSERT_EQ(54000000000, TimeSpan::FromHours(-1.5).Duration().Ticks);
  }

  TEST(TimeSpan, Equals) {
    ASSERT_TRUE(TimeSpan(23456).Equals(TimeSpan(23456)));
    ASSERT_FALSE(TimeSpan(12).Equals(TimeSpan(25)));
  }

  TEST(TimeSpan, EqualsObject) {
    TimeSpan time1 = TimeSpan::FromHours(3);
    TimeSpan time2 = TimeSpan::FromHours(5);
    object& time3 = time1;
    object& time4 = time2;

    ASSERT_TRUE(time1.Equals(time3));
    ASSERT_FALSE(time1.Equals(time4));
  }

  TEST(TimeSpan, EqualsStatic) {
    ASSERT_TRUE(TimeSpan::Equals(TimeSpan(23456), TimeSpan(23456)));
    ASSERT_FALSE(TimeSpan::Equals(TimeSpan(12), TimeSpan(25)));
  }

  TEST(TimeSpan, Negative) {
    ASSERT_EQ(-12, TimeSpan(12).Negative().Ticks);
    ASSERT_EQ(376, TimeSpan(-376).Negative().Ticks);
    ASSERT_EQ(0, TimeSpan(0).Negative().Ticks);
  }

  TEST(TimeSpan, Parse) {
    ASSERT_EQ("6.00:00:00", TimeSpan::Parse("6").ToString());
    ASSERT_EQ("06:12:00", TimeSpan::Parse("6:12").ToString());
    ASSERT_EQ("06:12:14", TimeSpan::Parse("6:12:14").ToString());
    ASSERT_EQ("06:12:14", TimeSpan::Parse("6:12:14").ToString());
    ASSERT_EQ("6.12:14:45", TimeSpan::Parse("6:12:14:45").ToString());
    ASSERT_EQ("6.12:14:45", TimeSpan::Parse("6.12:14:45").ToString());
    ASSERT_EQ("6.12:14:45.3440000", TimeSpan::Parse("6.12:14:45.3440000").ToString());
    ASSERT_EQ("-6.12:14:45.3440000", TimeSpan::Parse("-6.12:14:45.3440000").ToString());

    ASSERT_THROW(TimeSpan::Parse("25:12:00"), OverflowException);
    ASSERT_THROW(TimeSpan::Parse("6:61:00"), OverflowException);
    ASSERT_THROW(TimeSpan::Parse("6:00:61"), OverflowException);

    ASSERT_THROW(TimeSpan::Parse("6.12:14:45.344"), FormatException);
    ASSERT_THROW(TimeSpan::Parse("6.12:14:45.344000"), FormatException);
    ASSERT_THROW(TimeSpan::Parse("6.12:14:45.34400000"), FormatException);
    ASSERT_THROW(TimeSpan::Parse("6.2:12:14:45.3440000"), FormatException);
  }

  TEST(TimeSpan, Subtract) {
    TimeSpan time1 = TimeSpan::FromDays(1.5);
    TimeSpan time2 = TimeSpan::FromHours(1.5);
    TimeSpan time3 = TimeSpan::FromHours(-1.5);
    ASSERT_EQ(1242000000000, time1.Subtract(time2).Ticks);
    ASSERT_EQ(1350000000000, time1.Subtract(time3).Ticks);
  }
}
