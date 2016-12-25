//____________________________________________________________________________________________________________________________________________________________________________
//                                                                                                                                                                DateTime2.cpp
//#pragma once

#include <Pcf/System/Object.h>
#include <Pcf/System/ArgumentOutOfRangeException.h>
#include <Pcf/System/Convert.h>
#include <Pcf/System/DateTimeKind.h>
#include <Pcf/System/DayOfWeek.h>
#include <Pcf/System/TimeZoneInfo.h>

namespace Pcf {
  namespace System {
    class DateTime2 : public object {
    public:
      static Property<DateTime2, ReadOnly> MinValue;
      static Property<DateTime2, ReadOnly> MaxValue;
      
      DateTime2() {}
      
      explicit DateTime2(int64 ticks) {
        if (ticks < MinTicks || ticks > MaxTicks)
          throw ArgumentOutOfRangeException(pcf_current_information);
        this->dateData = Convert::ToUInt64(ticks);
      }
      
      DateTime2(const DateTime2& date) : dateData(date.dateData) {}
      
      DateTime2& operator =(const DateTime2& date ) {
        this->dateData = date.dateData;
        return *this;
      }
      
      DateTime2(int64 ticks, DateTimeKind kind) {
        if (ticks < MinTicks || ticks > MaxTicks)
          throw ArgumentOutOfRangeException(pcf_current_information);
        if (kind < DateTimeKind::Unspecified || kind > DateTimeKind::Local)
          throw ArgumentOutOfRangeException(pcf_current_information);
        this->dateData = Convert::ToUInt64(ticks) | (Convert::ToUInt64(kind) << KindShift);
      }
      
      DateTime2(int32 year, int32 month, int32 day) : dateData(Convert::ToUInt64(DateToTicks(year, month, day))) {}

      DateTime2(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second) : dateData(Convert::ToUInt64(DateToTicks(year, month, day) + TimeToTicks(hour, minute, second))) {}
      
      DateTime2(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second, DateTimeKind kind) : dateData((Convert::ToUInt64(DateToTicks(year, month, day) + TimeToTicks(hour, minute, second)) | (Convert::ToUInt64(kind) << KindShift))) {
        if (kind < DateTimeKind::Unspecified || kind > DateTimeKind::Local)
          throw ArgumentException(pcf_current_information);
      }
      
      Property<DateTime2, ReadOnly> Date {
        pcf_get {
          int64 ticks = this->InternalTicks;
          return DateTime2(Convert::ToUInt64(ticks - ticks % TicksPerDay) | this->InternalKind);
        }
      };
      
      Property<int32, ReadOnly> Day {
        pcf_get {return this->GetDatePart(DatePartDay);}
      };
      
      Property<System::DayOfWeek, ReadOnly> DayOfWeek {
        pcf_get {return (System::DayOfWeek)((this->InternalTicks / TicksPerDay + 1) % 7);}
      };
      
      Property<int32, ReadOnly> DayOfYear {
        pcf_get {return GetDatePart(DatePartDayOfYear);}
      };
      
      Property<int32, ReadOnly> Hour {
        pcf_get {return Convert::ToInt32((this->InternalTicks / TicksPerHour) % 24);}
      };
      
      Property<DateTimeKind, ReadOnly> Kind {
        pcf_get {
          switch (this->InternalKind) {
            case KindUnspecified: return DateTimeKind::Unspecified;
            case KindUtc: return DateTimeKind::Utc;
            default: return DateTimeKind::Local;
          }
        }
      };
      
      Property<int32, ReadOnly> Millisecond {
        pcf_get {return Convert::ToInt32((this->InternalTicks/ TicksPerMillisecond) % 1000);}
      };
      
      Property<int32, ReadOnly> Minute {
        pcf_get {return Convert::ToInt32((InternalTicks / TicksPerMinute) % 60);}
      };
      
      Property<int32, ReadOnly> Month {
        pcf_get {return this->GetDatePart(DatePartMonth);}
      };
      
      static Property<DateTime2, ReadOnly> Now;
      
      Property<int32, ReadOnly> Second {
        pcf_get {return Convert::ToInt32((InternalTicks / TicksPerSecond) % 60);}
      };
      
      Property<int64, ReadOnly> Ticks {
        pcf_get {return this->InternalTicks();}
      };
      
      Property<TimeSpan, ReadOnly> TimeOfDay {
        pcf_get {return TimeSpan(this->InternalTicks & TicksPerDay);}
      };
      
      static Property<DateTime2, ReadOnly> ToDay;
      
      static Property<DateTime2, ReadOnly> UtcNow;
      
      Property<int32, ReadOnly> Year {
        pcf_get {return this->GetDatePart(DatePartYear);}
      };
      
      bool IsDaylightSavingTime() const {
        if (this->Kind == DateTimeKind::Utc)
          return false;
        //return TimeZoneInfo::Local().IsDaylightSavingTime(*this, TimeZoneInfoOptions::NoThrowOnValidTime);
        return false;
      }
 
      static bool IsLeapYear(int32 year) {
        if (year < 1 || year > 9999)
          throw ArgumentOutOfRangeException(pcf_current_information);
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
      }
      
      string ToString() const override {
        return string::Format("{0}/{1}/{2} {3}:{4}:{5}", this->Day, this->Month, this->Year, this->Hour, this->Minute, this->Second);
      }
      
      static DateTime2 __get_now() {
        DateTime2 utc = DateTime2::UtcNow;
        bool isAmbiguousLocalDst = false;
        //int64 offset = TimeZoneInfo::GetDateTimeNowUtcOffsetFromUtc(utc, isAmbiguousLocalDst).Ticks;
        int64 offset = TimeZoneInfo::Local().BaseUtcOffset().Ticks;
        int64 tick = utc.Ticks + offset + TicksPerHour;
        if (tick > DateTime2::MaxTicks)
          return DateTime2(DateTime2::MaxTicks, DateTimeKind::Local);
        if (tick<DateTime2::MinTicks)
          return DateTime2(DateTime2::MinTicks, DateTimeKind::Local);
        return DateTime2(tick, DateTimeKind::Local, isAmbiguousLocalDst);
      }

      static DateTime2 __create_from_uint64(uint64 dateData) {
        DateTime2 dateTime;
        dateTime.dateData = dateData;
        return dateTime;
      }

    private:
      //DateTime2(uint64 dateData) : dateData(dateData) {}
      
      DateTime2(int64 ticks, DateTimeKind kind, bool isAmbiguousDst) {
        if (ticks < MinTicks || ticks > MaxTicks) {
          throw ArgumentOutOfRangeException(pcf_current_information);
        }
        dateData = (Convert::ToUInt64(ticks) | (isAmbiguousDst ? KindLocalAmbiguousDst : KindLocal));
      }
      
      Property<int64, ReadOnly> InternalTicks {
        pcf_get {return Convert::ToInt64(this->dateData & TicksMask);}
      };
      
      Property<uint64, ReadOnly> InternalKind {
        pcf_get {return this->dateData & FlagsMask;}
      };
      
      // Number of 100ns dateData per time unit
      static constexpr int64 TicksPerMillisecond = 10000;
      static constexpr int64 TicksPerSecond = TicksPerMillisecond * 1000;
      static constexpr int64 TicksPerMinute = TicksPerSecond * 60;
      static constexpr int64 TicksPerHour = TicksPerMinute * 60;
      static constexpr int64 TicksPerDay = TicksPerHour * 24;
      
      // Number of milliseconds per time unit
      static constexpr int32 MillisPerSecond = 1000;
      static constexpr int32 MillisPerMinute = MillisPerSecond * 60;
      static constexpr int32 MillisPerHour = MillisPerMinute * 60;
      static constexpr int32 MillisPerDay = MillisPerHour * 24;
      
      // Number of days in a non-leap year
      static constexpr int32 DaysPerYear = 365;
      // Number of days in 4 years
      static constexpr int32 DaysPer4Years = DaysPerYear * 4 + 1;       // 1461
      // Number of days in 100 years
      static constexpr int32 DaysPer100Years = DaysPer4Years * 25 - 1;  // 36524
      // Number of days in 400 years
      static constexpr int32 DaysPer400Years = DaysPer100Years * 4 + 1; // 146097
      
      // Number of days from 1/1/0001 to 12/31/1600
      static constexpr int32 DaysTo1601 = DaysPer400Years * 4;          // 584388
      // Number of days from 1/1/0001 to 12/30/1899
      static constexpr int32 DaysTo1899 = DaysPer400Years * 4 + DaysPer100Years * 3 - 367;
      // Number of days from 1/1/0001 to 12/31/9999
      static constexpr int32 DaysTo10000 = DaysPer400Years * 25 - 366;  // 3652059
      
      static constexpr int64 FileTimeOffset = DaysTo1601 * TicksPerDay;
      static constexpr int64 DoubleDateOffset = DaysTo1899 * TicksPerDay;
      // The minimum OA date is 0100/01/01 (Note it's year 100).
      // The maximum OA date is 9999/12/31
      static constexpr int64 OADateMinAsTicks = (DaysPer100Years - DaysPerYear) * TicksPerDay;
      // All OA dates must be greater than (not >=) OADateMinAsDouble
      static constexpr double OADateMinAsDouble = -657435.0;
      // All OA dates must be less than (not <=) OADateMaxAsDouble
      static constexpr double OADateMaxAsDouble = 2958466.0;
      
      static constexpr int32 DatePartYear = 0;
      static constexpr int32 DatePartDayOfYear = 1;
      static constexpr int32 DatePartMonth = 2;
      static constexpr int32 DatePartDay = 3;
      
      static constexpr int64 MinTicks = 0;
      static constexpr int64 MaxTicks = DaysTo10000 * TicksPerDay - 1;
      static constexpr int64 MaxMillis = (int64)DaysTo10000 * MillisPerDay;
      
      static constexpr int32 DaysToMonth365[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
      static constexpr int32 DaysToMonth366[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
      
      static constexpr uint64 TicksMask             = 0x3FFFFFFFFFFFFFFF;
      static constexpr uint64 FlagsMask             = 0xC000000000000000;
      static constexpr uint64 LocalMask             = 0x8000000000000000;
      static constexpr int64 TicksCeiling           = 0x4000000000000000;
      static constexpr uint64 KindUnspecified       = 0x0000000000000000;
      static constexpr uint64 KindUtc               = 0x4000000000000000;
      static constexpr uint64 KindLocal             = 0x8000000000000000;
      static constexpr uint64 KindLocalAmbiguousDst = 0xC000000000000000;
      static constexpr int32 KindShift = 62;
      
      // The data is stored as an unsigned 64-bit integeter
      //   Bits 01-62: The value of 100-nanosecond ticks where 0 represents 1/1/0001 12:00am, up until the value
      //               12/31/9999 23:59:59.9999999
      //   Bits 63-64: A four-state value that describes the DateTimeKind value of the date time, with a 2nd
      //               value for the rare case where the date time is local, but is in an overlapped daylight
      //               savings time hour and it is in daylight savings time. This allows distinction of these
      //               otherwise ambiguous local times and prevents data loss when round tripping from Local to
      //               UTC time.
      uint64 dateData = 0;
      
      static int64 DateToTicks(int32 year, int32 month, int32 day) {
        if (year >= 1 && year <= 9999 && month >= 1 && month <= 12) {
          const int32* days = IsLeapYear(year)? DaysToMonth366 : DaysToMonth365;
          if (day >= 1 && day <= days[month] - days[month - 1]) {
            int y = year - 1;
            int n = y * 365 + y / 4 - y / 100 + y / 400 + days[month - 1] + day - 1;
            return n * TicksPerDay;
          }
        }
        throw ArgumentOutOfRangeException(pcf_current_information);
      }
      
      int32 GetDatePart(int part) const {
        int64 dateData = this->InternalTicks;
        // numberOfDays = number of days since 1/1/0001
        int32 numberOfDays = Convert::ToInt32(dateData / TicksPerDay);
        // numberOf400YearPeriods = number of whole 400-year periods since 1/1/0001
        int32 numberOf400YearPeriods = numberOfDays / DaysPer400Years;
        // numberOfDays = day number within 400-year period
        numberOfDays -= numberOf400YearPeriods * DaysPer400Years;
        // numberPer100Years = number of whole 100-year periods within 400-year period
        int32 numberPer100Years = numberOfDays / DaysPer100Years;
        // Last 100-year period has an extra day, so decrement result if 4
        if (numberPer100Years == 4) numberPer100Years = 3;
        // numberOfDays = day number within 100-year period
        numberOfDays -= numberPer100Years * DaysPer100Years;
        // daysPer4Years = number of whole 4-year periods within 100-year period
        int32 daysPer4Years = numberOfDays / DaysPer4Years;
        // numberOfDays = day number within 4-year period
        numberOfDays -= daysPer4Years * DaysPer4Years;
        // daysPer1Years = number of whole years within 4-year period
        int32 daysPer1Years = numberOfDays / DaysPerYear;
        // Last year has an extra day, so decrement result if 4
        if (daysPer1Years == 4) daysPer1Years = 3;
        // If year was requested, compute and return it
        if (part == DatePartYear) {
          return numberOf400YearPeriods * 400 + numberPer100Years * 100 + daysPer4Years * 4 + daysPer1Years + 1;
        }
        // numberOfDays = day number within year
        numberOfDays -= daysPer1Years * DaysPerYear;
        // If day-of-year was requested, return it
        if (part == DatePartDayOfYear) return numberOfDays + 1;
        // Leap year calculation looks different from IsLeapYear since daysPer1Years, daysPer4Years,
        // and numberPer100Years are relative to year 1, not year 0
        bool leapYear = daysPer1Years == 3 && (daysPer4Years != 24 || numberPer100Years == 3);
        const int32* days = leapYear? DaysToMonth366 : DaysToMonth365;
        // All months have less than 32 days, so numberOfDays >> 5 is a good conservative
        // estimate for the month
        int32 months = (numberOfDays >> 5) + 1;
        // months = 1-based month number
        while (numberOfDays >= days[months]) months++;
        // If month was requested, return it
        if (part == DatePartMonth) return months;
        // Return 1-based day-of-month
        return numberOfDays - days[months - 1] + 1;
      }
   
      static int64 TimeToTicks(int32 hour, int32 minute, int32 second) {
        const int64 MaxSeconds = Int64::MaxValue / TicksPerSecond;
        const int64 MinSeconds = Int64::MinValue / TicksPerSecond;
        //TimeSpan.TimeToTicks is a family access function which does no error checking, so
        //we need to put some error checking out here.
        if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60 && second >=0 && second < 60) {
          int64 totalSeconds = Convert::ToInt64(hour * 3600) + Convert::ToInt64(minute * 60) + Convert::ToInt64(second);
          if (totalSeconds > MaxSeconds || totalSeconds < MinSeconds)
            throw ArgumentOutOfRangeException(pcf_current_information);
          return totalSeconds * TicksPerSecond;
        }
        throw ArgumentOutOfRangeException(pcf_current_information);
      }
    };
  }
}

using namespace Pcf;

//____________________________________________________________________________________________________________________________________________________________________________
//                                                                                                                                                                DateTime2.cpp
#include <chrono>
//#include <../../Include/Pcf/System/DateTime.h>

using namespace System;

Property<DateTime2, ReadOnly> DateTime2::MinValue { 
  [] {return DateTime2(0, DateTimeKind::Unspecified);}
};

Property<DateTime2, ReadOnly> DateTime2::MaxValue{
  [] { return DateTime2((int64)3652059*10000*1000*60*60*24-1, DateTimeKind::Unspecified);}
};

int64 GetSystemTimeAsFileTime() {
  static constexpr int64 TicksSince1601To1970 =  116444736000000000LL;
  return (int64)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count()/100 + TicksSince1601To1970;
}

Property<DateTime2, ReadOnly> DateTime2::Now {
  []()->DateTime2 {
    return DateTime2::__get_now();
  }
};

Property<DateTime2, ReadOnly> DateTime2::ToDay {
  []()->DateTime2 {
    return DateTime2::Now().Date;
  }
};

Property<DateTime2, ReadOnly> DateTime2::UtcNow {
  []()->DateTime2 {
    int64 ticks = GetSystemTimeAsFileTime();
    const int64 kindUtc = 0x4000000000000000;
    const int64 fileTimeOffset = 504911232000000000;
    return DateTime2::__create_from_uint64((Convert::ToUInt64(ticks + fileTimeOffset)) | kindUtc);
  }
};

constexpr int32 DateTime2::DaysToMonth365[13];
constexpr int32 DateTime2::DaysToMonth366[13];

//____________________________________________________________________________________________________________________________________________________________________________
//                                                                                                                                                            DateTimeTest.cpp

#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>
#include <Pcf/System/Console.h>

using namespace System;
using namespace TUnit;

namespace {
  class DateTimeTest : public TestFixture {
  protected:
    void MinValue() {
      Assert::AreEqual(DateTimeKind::Unspecified, DateTime2::MinValue().Kind(), pcf_current_information);
      Assert::AreEqual(0, DateTime2::MinValue().Ticks(), pcf_current_information);
      Assert::AreEqual(1, DateTime2::MinValue().Year(), pcf_current_information);
      Assert::AreEqual(1, DateTime2::MinValue().Month(), pcf_current_information);
      Assert::AreEqual(1, DateTime2::MinValue().Day(), pcf_current_information);
      Assert::AreEqual(0, DateTime2::MinValue().Hour(), pcf_current_information);
      Assert::AreEqual(0, DateTime2::MinValue().Minute(), pcf_current_information);
      Assert::AreEqual(0, DateTime2::MinValue().Second(), pcf_current_information);
      Assert::AreEqual(0, DateTime2::MinValue().Millisecond(), pcf_current_information);
      Assert::AreEqual(DayOfWeek::Monday, DateTime2::MinValue().DayOfWeek(), pcf_current_information);
      Assert::IsFalse(DateTime2::MinValue().IsDaylightSavingTime(), pcf_current_information);
    }

    void MaxValue() {
      Assert::AreEqual(DateTimeKind::Unspecified, DateTime2::MaxValue().Kind(), pcf_current_information);
      Assert::AreEqual(3155378975999999999LL, DateTime2::MaxValue().Ticks(), pcf_current_information);
      Assert::AreEqual(9999, DateTime2::MaxValue().Year(), pcf_current_information);
      Assert::AreEqual(12, DateTime2::MaxValue().Month(), pcf_current_information);
      Assert::AreEqual(31, DateTime2::MaxValue().Day(), pcf_current_information);
      Assert::AreEqual(23, DateTime2::MaxValue().Hour(), pcf_current_information);
      Assert::AreEqual(59, DateTime2::MaxValue().Minute(), pcf_current_information);
      Assert::AreEqual(59, DateTime2::MaxValue().Second(), pcf_current_information);
      Assert::AreEqual(999, DateTime2::MaxValue().Millisecond(), pcf_current_information);
      Assert::AreEqual(DayOfWeek::Friday, DateTime2::MaxValue().DayOfWeek(), pcf_current_information);
      Assert::IsFalse(DateTime2::MaxValue().IsDaylightSavingTime(), pcf_current_information);
    }
    
    void DefaultConstructor() {
      DateTime2 dateTime;
      Assert::AreEqual(DateTimeKind::Unspecified, dateTime.Kind(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Ticks(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Year(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Month(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Day(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Hour(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Minute(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Second(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Millisecond(), pcf_current_information);
      Assert::AreEqual(DayOfWeek::Monday, dateTime.DayOfWeek(), pcf_current_information);
      Assert::IsFalse(dateTime.IsDaylightSavingTime(), pcf_current_information);
    }
    
    void ConstructorByTicksWith0() {
      DateTime2 dateTime(0LL);
      Assert::AreEqual(DateTimeKind::Unspecified, dateTime.Kind(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Ticks(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Year(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Month(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Day(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Hour(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Minute(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Second(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Millisecond(), pcf_current_information);
      Assert::AreEqual(DayOfWeek::Monday, dateTime.DayOfWeek(), pcf_current_information);
      Assert::IsFalse(dateTime.IsDaylightSavingTime(), pcf_current_information);
    }
    
    void ConstructorByTicksWith0AndDateTimeKindUnspecified() {
      DateTime2 dateTime(0LL, DateTimeKind::Unspecified);
      Assert::AreEqual(DateTimeKind::Unspecified, dateTime.Kind(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Ticks(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Year(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Month(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Day(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Hour(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Minute(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Second(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Millisecond(), pcf_current_information);
      Assert::AreEqual(DayOfWeek::Monday, dateTime.DayOfWeek(), pcf_current_information);
      Assert::IsFalse(dateTime.IsDaylightSavingTime(), pcf_current_information);
    }
    
    void ConstructorByTicksWith0AndDateTimeKindLocal() {
      DateTime2 dateTime(0LL, DateTimeKind::Local);
      Assert::AreEqual(DateTimeKind::Local, dateTime.Kind(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Ticks(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Year(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Month(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Day(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Hour(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Minute(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Second(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Millisecond(), pcf_current_information);
      Assert::AreEqual(DayOfWeek::Monday, dateTime.DayOfWeek(), pcf_current_information);
      Assert::IsFalse(dateTime.IsDaylightSavingTime(), pcf_current_information);
    }
    
    void ConstructorByTicksWith0AndDateTimeKindUtc() {
      DateTime2 dateTime(0LL, DateTimeKind::Utc);
      Assert::AreEqual(DateTimeKind::Utc, dateTime.Kind(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Ticks(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Year(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Month(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Day(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Hour(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Minute(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Second(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Millisecond(), pcf_current_information);
      Assert::AreEqual(DayOfWeek::Monday, dateTime.DayOfWeek(), pcf_current_information);
      Assert::IsFalse(dateTime.IsDaylightSavingTime(), pcf_current_information);
    }
    
    void ConstructorByTicksWith31241376000000000LL() {
      DateTime2 dateTime(31241376000000000LL);
      Assert::AreEqual(DateTimeKind::Unspecified, dateTime.Kind(), pcf_current_information);
      Assert::AreEqual(31241376000000000LL, dateTime.Ticks(), pcf_current_information);
      Assert::AreEqual(100, dateTime.Year(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Month(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Day(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Hour(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Minute(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Second(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Millisecond(), pcf_current_information);
      Assert::AreEqual(DayOfWeek::Friday, dateTime.DayOfWeek(), pcf_current_information);
      Assert::IsFalse(dateTime.IsDaylightSavingTime(), pcf_current_information);
    }
    
    void ConstructorByTicksWith504911232000000000LL() {
      System::DateTime2 dateTime(504911232000000000LL);
      Assert::AreEqual(DateTimeKind::Unspecified, dateTime.Kind(), pcf_current_information);
      Assert::AreEqual(504911232000000000LL, dateTime.Ticks(), pcf_current_information);
      Assert::AreEqual(1601, dateTime.Year(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Month(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Day(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Hour(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Minute(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Second(), pcf_current_information);
      Assert::AreEqual(DayOfWeek::Monday, dateTime.DayOfWeek(), pcf_current_information);
      Assert::IsFalse(dateTime.IsDaylightSavingTime(), pcf_current_information);
    }
    
    void ConstructorByTicksWith633452274520000000LLAndKindSetToLocal() {
      System::DateTime2 dateTime(633452274520000000LL, DateTimeKind::Local);
      Assert::AreEqual(DateTimeKind::Local, dateTime.Kind(), pcf_current_information);
      Assert::AreEqual(633452274520000000LL, dateTime.Ticks(), pcf_current_information);
      Assert::AreEqual(2008, dateTime.Year(), pcf_current_information);
      Assert::AreEqual(5, dateTime.Month(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Day(), pcf_current_information);
      Assert::AreEqual(8, dateTime.Hour(), pcf_current_information);
      Assert::AreEqual(30, dateTime.Minute(), pcf_current_information);
      Assert::AreEqual(52, dateTime.Second(), pcf_current_information);
      Assert::AreEqual(DayOfWeek::Thursday, dateTime.DayOfWeek(), pcf_current_information);
      Assert::IsTrue(dateTime.IsDaylightSavingTime(), pcf_current_information);
    }
    
    void ConstructorByTicksWith633452274520000000LLAndKindSetToUtc() {
      System::DateTime2 dateTime(633452274520000000LL, DateTimeKind::Utc);
      Assert::AreEqual(633452274520000000LL, dateTime.Ticks(), pcf_current_information);
      Assert::AreEqual(2008, dateTime.Year(), pcf_current_information);
      Assert::AreEqual(5, dateTime.Month(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Day(), pcf_current_information);
      Assert::AreEqual(8, dateTime.Hour(), pcf_current_information);
      Assert::AreEqual(30, dateTime.Minute(), pcf_current_information);
      Assert::AreEqual(52, dateTime.Second(), pcf_current_information);
      Assert::AreEqual(DateTimeKind::Utc, dateTime.Kind(), pcf_current_information);
      Assert::IsFalse(dateTime.IsDaylightSavingTime(), pcf_current_information);
    }
    
    void ConstructorByYearMonthDayWithValue() {
      DateTime2 dateTime(2011, 10, 30);
      Assert::AreEqual(2011, dateTime.Year(), pcf_current_information);
      Assert::AreEqual(10, dateTime.Month(), pcf_current_information);
      Assert::AreEqual(30, dateTime.Day(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Hour(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Minute(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Second(), pcf_current_information);
      Assert::AreEqual(DateTimeKind::Unspecified, dateTime.Kind(), pcf_current_information);
      Assert::IsFalse(dateTime.IsDaylightSavingTime(), pcf_current_information);
    }
    
    void ConstructorByYearMonthDayHourMinuteSecondWithValue() {
      DateTime2 dateTime(2011, 10, 30, 1, 59, 59);
      Assert::AreEqual(2011, dateTime.Year(), pcf_current_information);
      Assert::AreEqual(10, dateTime.Month(), pcf_current_information);
      Assert::AreEqual(30, dateTime.Day(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Hour(), pcf_current_information);
      Assert::AreEqual(59, dateTime.Minute(), pcf_current_information);
      Assert::AreEqual(59, dateTime.Second(), pcf_current_information);
      Assert::AreEqual(DateTimeKind::Unspecified, dateTime.Kind(), pcf_current_information);
      Assert::IsFalse(dateTime.IsDaylightSavingTime(), pcf_current_information);
    }
    
    void ConstructorByYearMonthDayHourMinuteSecondKindWithkindToLocalAndValueWithDayligthSet() {
      DateTime2 dateTime(2011, 10, 30, 1, 59, 59, DateTimeKind::Local);
      Assert::AreEqual(2011, dateTime.Year(), pcf_current_information);
      Assert::AreEqual(10, dateTime.Month(), pcf_current_information);
      Assert::AreEqual(30, dateTime.Day(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Hour(), pcf_current_information);
      Assert::AreEqual(59, dateTime.Minute(), pcf_current_information);
      Assert::AreEqual(59, dateTime.Second(), pcf_current_information);
      Assert::AreEqual(DateTimeKind::Local, dateTime.Kind(), pcf_current_information);
      Assert::IsTrue(dateTime.IsDaylightSavingTime(), pcf_current_information);
    }
    
    void ConstructorByYearMonthDayHourMinuteSecondKindWithkindToUtcAndValueWithDayligthSet() {
      DateTime2 dateTime(2011, 10, 30, 1, 59, 59, DateTimeKind::Utc);
      Assert::AreEqual(2011, dateTime.Year(), pcf_current_information);
      Assert::AreEqual(10, dateTime.Month(), pcf_current_information);
      Assert::AreEqual(30, dateTime.Day(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Hour(), pcf_current_information);
      Assert::AreEqual(59, dateTime.Minute(), pcf_current_information);
      Assert::AreEqual(59, dateTime.Second(), pcf_current_information);
      Assert::AreEqual(DateTimeKind::Utc, dateTime.Kind(), pcf_current_information);
      Assert::IsFalse(dateTime.IsDaylightSavingTime(), pcf_current_information);
    }
    
    void ConstructorByYearMonthDayHourMinuteSecondKindWithkindToLocalAndValueWithoutDayligthSet() {
      DateTime2 dateTime(2011, 10, 30, 3, 0, 1, DateTimeKind::Local);
      Assert::AreEqual(2011, dateTime.Year(), pcf_current_information);
      Assert::AreEqual(10, dateTime.Month(), pcf_current_information);
      Assert::AreEqual(30, dateTime.Day(), pcf_current_information);
      Assert::AreEqual(3, dateTime.Hour(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Minute(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Second(), pcf_current_information);
      Assert::AreEqual(DateTimeKind::Local, dateTime.Kind(), pcf_current_information);
      Assert::IsFalse(dateTime.IsDaylightSavingTime(), pcf_current_information);
    }
    
    void ConstructorByYearMonthDayHourMinuteSecondKindWithkindToUtcAndValueWithoutDayligthSet() {
      DateTime2 dateTime(2011, 10, 30, 3, 0, 1, DateTimeKind::Utc);
      Assert::AreEqual(2011, dateTime.Year(), pcf_current_information);
      Assert::AreEqual(10, dateTime.Month(), pcf_current_information);
      Assert::AreEqual(30, dateTime.Day(), pcf_current_information);
      Assert::AreEqual(3, dateTime.Hour(), pcf_current_information);
      Assert::AreEqual(0, dateTime.Minute(), pcf_current_information);
      Assert::AreEqual(1, dateTime.Second(), pcf_current_information);
      Assert::AreEqual(DateTimeKind::Utc, dateTime.Kind(), pcf_current_information);
      Assert::IsFalse(dateTime.IsDaylightSavingTime(), pcf_current_information);
    }
    
    void Constructor() {
      EXPECT_THROW(DateTime2(DateTime2::MaxValue().Ticks()+TimeSpan::TicksPerSecond), ArgumentOutOfRangeException);
      EXPECT_THROW(DateTime2(DateTime2::MinValue().Ticks()-TimeSpan::TicksPerSecond), ArgumentOutOfRangeException);
    }
    
    void Now() {
      DateTime2 now = DateTime2::Now;
      Console::WriteLine("now    ({0}) {1}", now.Ticks, now);
      DateTime2 utcNow = DateTime2::UtcNow;
      Console::WriteLine("utcNow ({0}) {1}", utcNow.Ticks, utcNow);
    }
  };
  
  pcf_test(DateTimeTest, MinValue);
  pcf_test(DateTimeTest, MaxValue);
  pcf_test(DateTimeTest, DefaultConstructor);
  pcf_test(DateTimeTest, ConstructorByTicksWith0);
  pcf_test(DateTimeTest, ConstructorByTicksWith0AndDateTimeKindUnspecified);
  pcf_test(DateTimeTest, ConstructorByTicksWith0AndDateTimeKindLocal);
  pcf_test(DateTimeTest, ConstructorByTicksWith0AndDateTimeKindUtc);
  pcf_test(DateTimeTest, ConstructorByTicksWith31241376000000000LL);
  pcf_test(DateTimeTest, ConstructorByTicksWith504911232000000000LL);
  //pcf_ignore_test(DateTimeTest, ConstructorByTicksWith633452274520000000LLAndKindSetToLocal);
  pcf_test(DateTimeTest, ConstructorByTicksWith633452274520000000LLAndKindSetToUtc);
  pcf_test(DateTimeTest, ConstructorByYearMonthDayWithValue);
  pcf_test(DateTimeTest, ConstructorByYearMonthDayHourMinuteSecondWithValue);
  //pcf_ignore_test(DateTimeTest, ConstructorByYearMonthDayHourMinuteSecondKindWithkindToLocalAndValueWithDayligthSet);
  pcf_test(DateTimeTest, ConstructorByYearMonthDayHourMinuteSecondKindWithkindToUtcAndValueWithDayligthSet);
  pcf_test(DateTimeTest, ConstructorByYearMonthDayHourMinuteSecondKindWithkindToLocalAndValueWithoutDayligthSet);
  pcf_test(DateTimeTest, ConstructorByYearMonthDayHourMinuteSecondKindWithkindToUtcAndValueWithoutDayligthSet);
  pcf_test(DateTimeTest, Constructor);
  //pcf_ignore_test(DateTimeTest, Now);
}
