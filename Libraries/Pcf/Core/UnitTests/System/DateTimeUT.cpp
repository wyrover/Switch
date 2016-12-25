#include <Pcf/System/DateTime.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {
  class DateTime : public testing::Test {
  protected:
  };

  TEST_F(DateTime, MinValue) {
    ASSERT_EQ(0, System::DateTime::MinValue.Ticks);
    ASSERT_EQ(1, System::DateTime::MinValue.Year);
    ASSERT_EQ(1, System::DateTime::MinValue.Month);
    ASSERT_EQ(1, System::DateTime::MinValue.Day);
    ASSERT_EQ(0, System::DateTime::MinValue.Hour);
    ASSERT_EQ(0, System::DateTime::MinValue.Minute);
    ASSERT_EQ(0, System::DateTime::MinValue.Second);
    ASSERT_EQ(DateTimeKind::Unspecified, System::DateTime::MinValue.Kind());
    ASSERT_FALSE(System::DateTime::MinValue.IsDaylightSavingTime());
  }
  
  TEST_F(DateTime, MaxValue) {
    ASSERT_EQ(3155378975999999999L, System::DateTime::MaxValue.Ticks);
    ASSERT_EQ(9999, System::DateTime::MaxValue.Year);
    ASSERT_EQ(12, System::DateTime::MaxValue.Month);
    ASSERT_EQ(31, System::DateTime::MaxValue.Day);
    ASSERT_EQ(23, System::DateTime::MaxValue.Hour);
    ASSERT_EQ(59, System::DateTime::MaxValue.Minute);
    ASSERT_EQ(59, System::DateTime::MaxValue.Second);
    ASSERT_EQ(DateTimeKind::Unspecified, System::DateTime::MaxValue.Kind());
    ASSERT_FALSE(System::DateTime::MaxValue.IsDaylightSavingTime());
  }
  
  TEST_F(DateTime, DefaultConstructor) {
    System::DateTime d;
    ASSERT_EQ(0, d.Ticks);
    ASSERT_EQ(1, d.Year);
    ASSERT_EQ(1, d.Month);
    ASSERT_EQ(1, d.Day);
    ASSERT_EQ(0, d.Hour);
    ASSERT_EQ(0, d.Minute);
    ASSERT_EQ(0, d.Second);
    ASSERT_EQ(DateTimeKind::Unspecified, d.Kind());
    ASSERT_FALSE(d.IsDaylightSavingTime());
  }
  
  TEST_F(DateTime, ConstructorByTicksWith0) {
    System::DateTime d(0);
    ASSERT_EQ(0, d.Ticks);
    ASSERT_EQ(1, d.Year);
    ASSERT_EQ(1, d.Month);
    ASSERT_EQ(1, d.Day);
    ASSERT_EQ(0, d.Hour);
    ASSERT_EQ(0, d.Minute);
    ASSERT_EQ(0, d.Second);
    ASSERT_EQ(DateTimeKind::Unspecified, d.Kind());
    ASSERT_FALSE(d.IsDaylightSavingTime());
  }
  
  /*
  TEST_F(DateTime, ConstructorByTicksWith504911232000000000LL) {
    System::DateTime d(504911232000000000LL);
    ASSERT_EQ(504911232000000000LL, d.Ticks);
    ASSERT_EQ(1601, d.Year);
    ASSERT_EQ(1, d.Month);
    ASSERT_EQ(1, d.Day);
    ASSERT_EQ(0, d.Hour);
    ASSERT_EQ(0, d.Minute);
    ASSERT_EQ(0, d.Second);
    ASSERT_EQ(DateTimeKind::Unspecified, d.Kind());
    ASSERT_FALSE(d.IsDaylightSavingTime());
  }*/
  
  /*
  TEST_F(DateTime, ConstructorByTicksWith633452274520000000LLAndKindSetToLocal) {
    System::DateTime d(633452274520000000LL, DateTimeKind::Local);
    ASSERT_EQ(633452274520000000LL, d.Ticks);
    ASSERT_EQ(2008, d.Year);
    ASSERT_EQ(5, d.Month);
    ASSERT_EQ(1, d.Day);
    ASSERT_EQ(8+TimeZoneInfo::Local().BaseUtcOffset().Hours() + (d.IsDaylightSavingTime() ? 1 : 0), d.Hour);
    ASSERT_EQ(30, d.Minute);
    ASSERT_EQ(52, d.Second);
    ASSERT_EQ(DateTimeKind::Local, d.Kind());
    ASSERT_TRUE(d.IsDaylightSavingTime());
  }
  */
  
  TEST_F(DateTime, ConstructorByTicksWith633452274520000000LLAndKindSetToUtc) {
    System::DateTime d(633452274520000000LL, DateTimeKind::Utc);
    ASSERT_EQ(633452274520000000LL, d.Ticks);
    ASSERT_EQ(2008, d.Year);
    ASSERT_EQ(5, d.Month);
    ASSERT_EQ(1, d.Day);
    ASSERT_EQ(8, d.Hour);
    ASSERT_EQ(30, d.Minute);
    ASSERT_EQ(52, d.Second);
    ASSERT_EQ(DateTimeKind::Utc, d.Kind());
    ASSERT_FALSE(d.IsDaylightSavingTime());
  }
  
  TEST_F(DateTime, ConstructorByYearMonthDayWithValue) {
    System::DateTime d(2011, 10, 30);
    ASSERT_EQ(2011, d.Year);
    ASSERT_EQ(10, d.Month);
    ASSERT_EQ(30, d.Day);
    ASSERT_EQ(0, d.Hour);
    ASSERT_EQ(0, d.Minute);
    ASSERT_EQ(0, d.Second);
    ASSERT_EQ(DateTimeKind::Unspecified, d.Kind());
    ASSERT_FALSE(d.IsDaylightSavingTime());
  }
  
  TEST_F(DateTime, ConstructorByYearMonthDayHourMinuteSecondWithValue) {
    System::DateTime d(2011, 10, 30, 1, 59, 59);
    ASSERT_EQ(2011, d.Year);
    ASSERT_EQ(10, d.Month);
    ASSERT_EQ(30, d.Day);
    ASSERT_EQ(1, d.Hour);
    ASSERT_EQ(59, d.Minute);
    ASSERT_EQ(59, d.Second);
    ASSERT_EQ(DateTimeKind::Unspecified, d.Kind());
    ASSERT_FALSE(d.IsDaylightSavingTime());
  }
  
  TEST_F(DateTime, ConstructorByYearMonthDayHourMinuteSecondKindWithkindToLocalAndValueWithDayligthSet) {
    System::DateTime d(2011, 10, 30, 1, 59, 59, (DateTimeKind)DateTimeKind::Local);
    ASSERT_EQ(2011, d.Year);
    ASSERT_EQ(10, d.Month);
    ASSERT_EQ(30, d.Day);
    ASSERT_EQ(1, d.Hour);
    ASSERT_EQ(59, d.Minute);
    ASSERT_EQ(59, d.Second);
    ASSERT_EQ(DateTimeKind::Local, d.Kind());
    ASSERT_TRUE(d.IsDaylightSavingTime());
  }
  
  TEST_F(DateTime, ConstructorByYearMonthDayHourMinuteSecondKindWithkindToUtcAndValueWithDayligthSet) {
    System::DateTime d(2011, 10, 30, 1, 59, 59, (DateTimeKind)DateTimeKind::Utc);
    ASSERT_EQ(2011, d.Year);
    ASSERT_EQ(10, d.Month);
    ASSERT_EQ(30, d.Day);
    ASSERT_EQ(1, d.Hour);
    ASSERT_EQ(59, d.Minute);
    ASSERT_EQ(59, d.Second);
    ASSERT_EQ(DateTimeKind::Utc, d.Kind());
    ASSERT_FALSE(d.IsDaylightSavingTime());
  }
  
  TEST_F(DateTime, ConstructorByYearMonthDayHourMinuteSecondKindWithkindToLocalAndValueWithoutDayligthSet) {
    System::DateTime d(2011, 10, 30, 3, 0, 1, (DateTimeKind)DateTimeKind::Local);
    ASSERT_EQ(2011, d.Year);
    ASSERT_EQ(10, d.Month);
    ASSERT_EQ(30, d.Day);
    ASSERT_EQ(3, d.Hour);
    ASSERT_EQ(0, d.Minute);
    ASSERT_EQ(1, d.Second);
    ASSERT_EQ(DateTimeKind::Local, d.Kind());
    ASSERT_FALSE(d.IsDaylightSavingTime());
  }
  
  TEST_F(DateTime, ConstructorByYearMonthDayHourMinuteSecondKindWithkindToUtcAndValueWithoutDayligthSet) {
    System::DateTime d(2011, 10, 30, 3, 0, 1, (DateTimeKind)DateTimeKind::Utc);
    ASSERT_EQ(2011, d.Year);
    ASSERT_EQ(10, d.Month);
    ASSERT_EQ(30, d.Day);
    ASSERT_EQ(3, d.Hour);
    ASSERT_EQ(0, d.Minute);
    ASSERT_EQ(1, d.Second);
    ASSERT_EQ(DateTimeKind::Utc, d.Kind());
    ASSERT_FALSE(d.IsDaylightSavingTime());
  }
  
  TEST_F(DateTime, Constructor) {
    EXPECT_THROW(System::DateTime(System::DateTime::MaxValue.Ticks()+TimeSpan::TicksPerSecond), ArgumentOutOfRangeException);
    EXPECT_THROW(System::DateTime(System::DateTime::MinValue.Ticks()-TimeSpan::TicksPerSecond), ArgumentOutOfRangeException);
  }
  
  /*!
   Description
   Be careful test on date is written in the zone GMT+1 so it must be executed with this zone to be correct.
   */
  /*
  TEST_F(DateTime, ToLocalTime) {
    EXPECT_EQ("24/05/2011 12:05:05", System::DateTime(2011, 5, 24, 12, 5, 5, System::DateTimeKind(System::DateTimeKind::Local)).ToLocalTime().ToString());
    EXPECT_EQ("24/05/2011 14:05:05", System::DateTime(2011, 5, 24, 12, 5, 5, System::DateTimeKind(System::DateTimeKind::Utc)).ToLocalTime().ToString());
    EXPECT_EQ("24/05/2011 14:05:05", System::DateTime(2011, 5, 24, 12, 5, 5, System::DateTimeKind(System::DateTimeKind::Unspecified)).ToLocalTime().ToString());
  }
  */
  
  /*!
   Description
   Be careful test on date is written in the zone GMT+1 so it must be executed with this zone to be correct.
   */
   /*
  TEST_F(DateTime, ToUniversalTime) {
    EXPECT_EQ("24/05/2011 10:05:05", System::DateTime(2011, 5, 24, 12, 5, 5, System::DateTimeKind(System::DateTimeKind::Local)).ToUniversalTime().ToString());
    EXPECT_EQ("24/05/2011 12:05:05", System::DateTime(2011, 5, 24, 12, 5, 5, System::DateTimeKind(System::DateTimeKind::Utc)).ToUniversalTime().ToString());
    EXPECT_EQ("24/05/2011 10:05:05", System::DateTime(2011, 5, 24, 12, 5, 5, System::DateTimeKind(System::DateTimeKind::Unspecified)).ToUniversalTime().ToString());
  }
  */
  
  TEST_F(DateTime, ToString) {
    EXPECT_EQ("Monday 02 May 2011", System::DateTime(2011, 5, 2, 8, 5, 5, System::DateTimeKind(System::DateTimeKind::Local)).ToLongDateString().ToString());
    EXPECT_EQ("08:05:05", System::DateTime(2011, 5, 2, 8, 5, 5, System::DateTimeKind(System::DateTimeKind::Local)).ToLongTimeString().ToString());
    EXPECT_EQ("02/05/2011", System::DateTime(2011, 5, 2, 8, 5, 5, System::DateTimeKind(System::DateTimeKind::Local)).ToShortDateString().ToString());
    EXPECT_EQ("08:05", System::DateTime(2011, 5, 1, 8, 5, 5, System::DateTimeKind(System::DateTimeKind::Local)).ToShortTimeString().ToString());
  }
  
  TEST_F(DateTime, Add) {
	  EXPECT_EQ("24/05/2011 16:55:52", System::DateTime(2011, 5, 24, 14, 31, 0).Add(TimeSpan(2, 24, 52)).ToString());
    EXPECT_EQ("25/06/2011 14:31:00", System::DateTime(2011, 5, 24, 14, 31, 0).AddDays(32).ToString());
    EXPECT_EQ("25/05/2011 22:31:00", System::DateTime(2011, 5, 24, 14, 31, 0).AddHours(32).ToString());
    EXPECT_EQ("24/05/2011 14:31:50", System::DateTime(2011, 5, 24, 14, 31, 0).AddMilliseconds(50000).ToString());
    EXPECT_EQ("24/05/2011 16:35:00", System::DateTime(2011, 5, 24, 14, 31, 0).AddMinutes(124).ToString());
  }
  
  /*
  TEST_F(DateTime, SpecifyKind) {
    EXPECT_EQ("24/05/2011 12:05:05", System::DateTime::SpecifyKind(System::DateTime(2011, 5, 24, 12, 5, 5, System::DateTimeKind(System::DateTimeKind::Local)), System::DateTimeKind::Local).ToString());
    EXPECT_EQ("24/05/2011 10:05:05", System::DateTime::SpecifyKind(System::DateTime(2011, 5, 24, 12, 5, 5, System::DateTimeKind(System::DateTimeKind::Local)), System::DateTimeKind::Utc).ToString());
    EXPECT_EQ("24/05/2011 14:05:05", System::DateTime::SpecifyKind(System::DateTime(2011, 5, 24, 12, 5, 5, System::DateTimeKind(System::DateTimeKind::Utc)), System::DateTimeKind::Local).ToString());
    EXPECT_EQ("24/05/2011 12:05:05", System::DateTime::SpecifyKind(System::DateTime(2011, 5, 24, 12, 5, 5, System::DateTimeKind(System::DateTimeKind::Utc)), System::DateTimeKind::Utc).ToString());
    EXPECT_EQ("24/05/2011 14:05:05", System::DateTime::SpecifyKind(System::DateTime(2011, 5, 24, 12, 5, 5, System::DateTimeKind(System::DateTimeKind::Unspecified)), System::DateTimeKind::Local).ToString());
    EXPECT_EQ("24/05/2011 10:05:05", System::DateTime::SpecifyKind(System::DateTime(2011, 5, 24, 12, 5, 5, System::DateTimeKind(System::DateTimeKind::Unspecified)), System::DateTimeKind::Utc).ToString());
  }
  */
  
  TEST_F(DateTime, Binary) {
    EXPECT_EQ("24/05/2011 12:05:05", System::DateTime::FromBinary(System::DateTime(2011, 5, 24, 12, 5, 5, System::DateTimeKind(System::DateTimeKind::Local)).ToBinary()).ToString());
  }
  
  TEST_F(DateTime, Get) {
    EXPECT_EQ("24/05/2011 00:00:00", System::DateTime(2011, 5, 24, 12, 5, 5, System::DateTimeKind(System::DateTimeKind::Local)).Date().ToString());
    EXPECT_EQ(System::DateTime(2011, 5, 24, 12, 5, 5, System::DateTimeKind(System::DateTimeKind::Local)).Day(),24);
    EXPECT_EQ(System::DateTime(2011, 5, 24, 12, 5, 5, System::DateTimeKind(System::DateTimeKind::Local)).DayOfYear(),144);
    EXPECT_EQ(System::DateTime(2011, 5, 24, 12, 5, 5, System::DateTimeKind(System::DateTimeKind::Local)).TimeOfDay(),TimeSpan(12,5,5));
  }
  
  /*
   Test not covered yet
   Console::WriteLine("System::DateTime::Now                                      : " + System::DateTime::Now);
   Console::WriteLine("System::DateTime::GetUtcNow()                                   : " + System::DateTime::GetUtcNow());
   Console::WriteLine("System::DateTime::GetToday()                                    : " + System::DateTime::GetToday());
   */
  
  TEST_F(DateTime, GetTypeCode) {
    EXPECT_EQ(TypeCode::DateTime, System::DateTime().GetTypeCode());
  }
  
}
