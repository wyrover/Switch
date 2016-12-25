#pragma once

#include "../../../Includes/Pcf/Types.h"
#include "../../../Includes/Pcf/System/String.h"

/// @cond
namespace Pcf {
  namespace Os {
    /// @brief Represents a Os object that provides the access date and time API.
    /// This class cannot be inherited.
    /// Internal used only.
    struct DateTime final {
    public:
      /// @brief Gets the current time in each parameters.
      /// Internal used only.
      /// @param seconds pointer to Seconds since midnight (00:00:00), January 1, 1970, coordinated universal time (UTC).
      /// @param milliseconds pointer to Fraction of a second in milliseconds
      /// @param timeZone pointer to Difference in minutes, moving westward, between UTC and local time. The value of timezone is set from the value of the global variable timezone.
      /// @return int32 Zero if successful, an error code on failure.
      static int32 Ftime(int64& seconds, int32& milliseconds, int32& timeZone, bool& daylight);
      
      /// @brief Converts a time value and corrects for the universal time zone.
      /// Internal used only.
      /// @param time The number of seconds since 00/00/00, January 1, 1970, UTC
      /// @param year reference on Year (current year minus 1900).
      /// @param month reference on Month (0-11; January = 0).
      /// @param day reference on Day of month (1-31).
      /// @param hour reference on Hours since midnight (0-23).
      /// @param minute reference on Minutes after hour (0-59).
      /// @param second reference on Seconds after minute (0-59).
      /// @param dayOfYear reference on Day of year (0-365).
      /// @param dayOfWeek reference on Day of week (0 - 6; Sunday = 0).
      /// @return int32 Zero if successful. The return value is an error code if there is a failure
      /// @remarks Return -1 if references a date after 23:59:59, December 31, 3000, UTC
      static int32 Gmtime(int64 time, int32& year, int32& month, int32& day, int32& hour, int32& minute, int32& second, int32& dayOfYear, int32& dayOfWeek);
      
      /// @brief Converts a time value and corrects for the local time zone.
      /// Internal used only.
      /// @param time The number of seconds since 00/00/00, January 1, 1970, UTC
      /// @param year reference on Year (current year minus 1900).
      /// @param month reference on Month (0-11; January = 0).
      /// @param day reference on Day of month (1-31).
      /// @param hour reference on Hours since midnight (0-23).
      /// @param minute reference on Minutes after hour (0-59).
      /// @param second reference on Seconds after minute (0-59).
      /// @param dayOfYear reference on Day of year (0-365).
      /// @param dayOfWeek reference on Day of week (0 - 6; Sunday = 0).
      /// @return int32 Zero if successful. The return value is an error code if there is a failure
      /// @remarks Return -1 if references a date after 23:59:59, December 31, 3000, UTC
      static int32 Localtime(int64 time, int32& year, int32& month, int32& day, int32& hour, int32& minute, int32& second, int32& dayOfYear, int32& dayOfWeek);
      
      /// @brief Convert the universal time to a calendar value.
      /// Internal used only.
      /// @param year Year (current year minus 1900).
      /// @param month Month (0-11; January = 0).
      /// @param day Day of month (1-31).
      /// @param hour Hours since midnight (0-23).
      /// @param minute Minutes after hour (0-59).
      /// @param second Seconds after minute (0-59).
      /// @return int64 The number of seconds since 00/00/00, January 1, 1970, UTC.
      /// @remarks Return -1 if references a date after 23:59:59, December 31, 3000, UTC
      static int64 Mkgmtime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second);
      
      /// @brief Convert the local time to a calendar value.
      /// Internal used only.
      /// @param year Year (current year minus 1900).
      /// @param month Month (0-11; January = 0).
      /// @param day Day of month (1-31).
      /// @param hour Hours since midnight (0-23).
      /// @param minute Minutes after hour (0-59).
      /// @param second Seconds after minute (0-59).
      /// @return Int64 The number of seconds since 00/00/00, January 1, 1970, UTC.
      /// @remarks Return -1 if references a date after 23:59:59, December 31, 3000, UTC
      static int64 Mktime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second);
      
      /// @brief Format a time string.
      /// Internal used only.
      /// @param output Output string
      /// @param format The number of seconds since 00/00/00, January 1, 1970, UTC
      /// @param year Year (current year minus 1900).
      /// @param month Month (0-11; January = 0).
      /// @param day Day of month (1-31).
      /// @param hour Hours since midnight (0-23).
      /// @param minute Minutes after hour (0-59).
      /// @param second Seconds after minute (0-59).
      /// @param dayOfYear Day of year (0-365).
      /// @param dayOfWeek Day of week (0 - 6; Sunday = 0).
      /// @param daylight Nonzero if daylight savings time is currently in effect for the local time zone.
      /// @return String A output String
      /// @remarks The format argument consists of one or more codes; as in printf, the formatting codes are preceded by a percent sign (%).
      /// @remarks Characters that do not begin with % are copied unchanged to strDest. The LC_TIME category of the current locale affects the output formatting of strftime.
      /// @remarks (For more information on LC_TIME, see setlocale.) The functions without the _l suffix use the currently set locale.
      /// @remarks The versions of these functions with the _l suffix are identical except that they take the locale as a parameter and use that instead of the currently set locale.
      /// @remarks The formatting codes for strftime are listed below:
      /// | Format     | behavior                                                                                                                   |
      /// |------------|----------------------------------------------------------------------------------------------------------------------------|
      /// | "%a"       | Abbreviated weekday name                                                                                                   |
      /// | "%A"       | Full weekday name                                                                                                          |
      /// | "%b"       | Abbreviated month name                                                                                                     |
      /// | "%B"       | Full month name                                                                                                            |
      /// | "%c"       | Date and time representation appropriate for locale                                                                        |
      /// | "%d"       | Day of month as decimal number (01 - 31)                                                                                   |
      /// | "%H"       | Hour in 24-hour format (00 - 23)                                                                                           |
      /// | "%I"       | Hour in 12-hour format (01 - 12)                                                                                           |
      /// | "%j"       | Day of year as decimal number (001 - 366)                                                                                  |
      /// | "%m"       | Month as decimal number (01 - 12)                                                                                          |
      /// | "%M"       | Minute as decimal number (00 - 59)                                                                                         |
      /// | "%p"       | Current locale's A.M./P.M. indicator for 12-hour clock                                                                     |
      /// | "%S"       | Second as decimal number (00 - 59)                                                                                         |
      /// | "%U"       | Week of year as decimal number, with Sunday as first day of week (00 - 53)                                                 |
      /// | "%w"       | Weekday as decimal number (0 - 6; Sunday is 0)                                                                             |
      /// | "%W"       | Week of year as decimal number, with Monday as first day of week (00 - 53)                                                 |
      /// | "%x"       | Date representation for current locale                                                                                     |
      /// | "%X"       | Time representation for current locale                                                                                     |
      /// | "%y"       | Year without century, as decimal number (00 - 99)                                                                          |
      /// | "%Y"       | Year with century, as decimal number                                                                                       |
      /// | "%z", "%Z" | Either the time-zone name or time zone abbreviation, depending on registry settings; no characters if time zone is unknown |
      /// | "%%"       | Percent sign                                                                                                               |
      static int32 Strftime(string& output, const string& format, int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second, int32 dayOfYear, int32 dayOfWeek, bool daylight);

      static bool IsDaylight(int64 localTime);

    private:
      DateTime() = delete;
    };
  }
}

using namespace Pcf;
/// @endcond

