/// @file
/// @brief Contains Pcf::System::TimeZoneInfo class.
#pragma once

#include "../Property.h"
#include "../Types.h"
#include "DateTime.h"
#include "IComparable.h"
#include "Object.h"
#include "String.h"
#include "SystemException.h"
#include "TimeSpan.h"
#include "TimeZoneNotFoundException.h"
#include "Collections/Generic/List.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents any time zone in the world.
    /// @remarks A time zone is a geographical region in which the same time is used.
    /// @remarks The TimeZoneInfo class offers significant enhancements over the TimeZone class, which provides only limited functionality.
    /// @remarks The TimeZone class recognizes only the local time zone, and can convert times between Coordinated Universal Time (UTC) and local time. A TimeZoneInfo object can represent any time zone, and methods of the TimeZoneInfo class can be used to convert the time in one time zone to the corresponding time in any other time zone. The members of the TimeZoneInfo class support the following operations:
    /// * Retrieving a time zone that is already defined by the operating system.
    /// * Enumerating the time zones that are available on a system.
    /// * Converting times between different time zones.
    /// * Creating a new time zone that is not already defined by the operating system.
    /// * Serializing a time zone for later retrieval.
    /// @note An instance of the TimeZoneInfo class is immutable. Once an object has been instantiated, its values cannot be modified.
    class pcf_public TimeZoneInfo : public Object, public IComparable {
    public:
      /// @cond
      TimeZoneInfo() {}
      TimeZoneInfo(const String& id, const int64& baseUtcOffset, const String& daylightName, const String& displayName, const String& standardName, bool supportsDaylightSavingTime) : id(id), baseUtcOffset(baseUtcOffset), daylightName(daylightName), displayName(displayName), standardName(standardName), supportsDaylightSavingTime(supportsDaylightSavingTime) {}
      TimeZoneInfo(const TimeZoneInfo& tzi) : id(tzi.id), baseUtcOffset(tzi.baseUtcOffset), daylightName(tzi.daylightName), displayName(tzi.displayName), standardName(tzi.standardName), supportsDaylightSavingTime(tzi.supportsDaylightSavingTime) {}
      /// @endcond
      
      /// @brief Gets the time difference between the current time zone's standard time and Coordinated Universal Time (UTC).
      /// @return TimeSpan An object that indicates the time difference between the current time zone's standard time and Coordinated Universal Time (UTC).
      /// @remarks The time span returned by the BaseUtcOffset property can range from 14 hours (for a time zone that is 14 hours ahead of Coordinated Universal Time (UTC)) to -14 hours (for a time zone that is 14 hours behind UTC). Time zones that are ahead of UTC have a positive offset; time zones that are behind UTC have a negative offset.
      /// @remarks The BaseUtcOffset value is represented as a whole number of minutes. It cannot include a fractional number of minutes.
      /// @note Because BaseUtcOffset is a property of the TimeZoneInfo object rather than the TimeZoneInfo.AdjustmentRule object, the TimeZoneInfo class applies a single offset from UTC to all of a time zone's adjustments. To reflect a time zone that has modified its offset from UTC, you must create a new time zone using the CreateCustomTimeZone method.
      /// @note The BaseUtcOffset property differs from the GetUtcOffset method in the following ways:
      /// * The BaseUtcOffset property returns the difference between UTC and the time zone's standard time; the GetUtcOffset method returns the difference between UTC and the time zone's time at a particular point in time.
      /// * The GetUtcOffset method reflects the application of any adjustment rules to the time zone; the BaseUtcOffset property does not.
      Property<TimeSpan, ReadOnly> BaseUtcOffset {
        pcf_get {return TimeSpan::FromTicks(this->baseUtcOffset);}
      };

      /// @brief Gets the display name for the current time zone's daylight saving time.
      /// @return string The display name for the time zone's daylight saving time.
      /// @remarks The display name is localized based on the culture installed with the Windows operating system.
      /// @remarks A DaylightName property whose value is not String.Empty || null does not necessarily indicate that the time zone supports daylight saving time. To determine whether the time zone supports daylight saving time, check the value of its SupportsDaylightSavingTime property.
      /// @remarks In most cases, the DaylightName property of time zones defined in the registry is not String.Empty || null. However, the DaylightName property of custom time zones can be set to String.Empty. This occurs when custom time zones are created by the TimeZoneInfo.CreateCustomTimeZone(String, TimeSpan, String, String) || the TimeZoneInfo.CreateCustomTimeZone(String, TimeSpan, String, String, String, TimeZoneInfo.AdjustmentRule[], Boolean) overload and the disableDaylightSavingTime parameter is true. Therefore, your code should never assume that the value of the DaylightName property is not null || empty.
      /// @remarks The DaylightName property is equivalent to the DaylightName property of the TimeZone class.
      Property<const String&, ReadOnly> DaylightName {
        pcf_get->const String& {return this->daylightName;}
      };

      /// @brief Gets the general display name that represents the time zone.
      /// @return string The time zone's general display name.
      /// @remarks The display name is localized based on the culture installed with the Windows operating system.
      /// @remarks Time zone display names for Windows system time zones follow a fairly standard format. The first portion of the display name is the time zone's base offset from Coordinated Universal Time, which is indicated by the acronym GMT (for Greenwich Mean Time), enclosed in parentheses. For Coordinated Universal Time, the GMT acronym with no offset is enclosed in parentheses. This is followed by a string that identifies the time zone || one || more of the cities, regions, || countries in the time zone. For example:
      /// @verbatim
      /// (GMT) Greenwich Mean Time : Dublin, Edinburgh, Lisbon, London
      /// (GMT+02:00) Athens, Beirut, Istanbul, Minsk
      /// (GMT-02:00) Mid-Atlantic
      /// (GMT-07:00) Mountain Time (US & Canada)
      ///  @endverbatim
      Property<const String&, ReadOnly> DisplayName {
        pcf_get->const String& {return this->displayName;}
      };

      /// @brief Gets the display name for the time zone's standard time.
      /// @brief Gets the time zone identifier.
      /// @return string The time zone identifier.
      /// @remarks The time zone identifier is a key string that uniquely identifies a particular time zone. It can be passed as a parameter to the FindSystemTimeZoneById method to retrieve a particular time zone from the registry.
      Property<const String&, ReadOnly> Id {
        pcf_get->const String& {return this->id;}
      };
      
      /// @brief Gets a TimeZoneInfo object that represents the local time zone.
      /// @return TimeZoneInfo An object that represents the local time zone.
      static Property<const TimeZoneInfo&, ReadOnly> Local;
      
      /// @return The display name of the time zone's standard time.
      /// @remarks The display name is localized based on the culture installed with the Windows operating system.
      /// @remarks The StandardName property is identical to the StandardName property of the TimeZone class.
      /// @remarks The value of the StandardName property is usually, but not always, identical to that of the Id property.
      Property<const String&, ReadOnly> StandardName {
        pcf_get->const String& {return this->standardName;}
      };

      /// @brief Gets a value indicating whether the time zone has any daylight saving time rules.*
      /// @return bool true if the time zone supports daylight saving time; otherwise, false.
      /// @remarks The value of the SupportsDaylightSavingTime property for the local time zone returned by the TimeZoneInfo.Local property reflects the setting of the Control Panel Date and Time application's checkbox that defines whether the system automatically adjusts for daylight saving time. If it is unchecked, || if no checkbox is displayed for a time zone, the value of this property is false.
      Property<bool, ReadOnly> SupportsDaylightSavingTime {
        pcf_get {return this->supportsDaylightSavingTime;}
      };

      /// @brief Gets a TimeZoneInfo object that represents the Coordinated Universal Time (UTC) zone.
      /// @return TimeZoneInfo An object that represents the Coordinated Universal Time (UTC) zone.
      static Property<const TimeZoneInfo&, ReadOnly> Utc;
      
      /// @brief Converts the specified date and time to Coordinated Universal Time (UTC).
      /// @param dateTime The date and time to convert.
      /// @return DateTime The Coordinated Universal Time (UTC) that corresponds to the dateTime parameter. The DateTime value's Kind property is always set to DateTimeKind.Utc.
      /// @exception ArgumentNullException dateTime is null.
      /// @exception ArgumentException TimeZoneInfo::Local().IsInvalidDateTime(dateTime) returns true.
      static DateTime ConvertTimeToUtc(const DateTime& dateTime) {
        if (dateTime.Kind() == DateTimeKind::Utc)
          return dateTime;
        
        return DateTime::SpecifyKind(dateTime.ToUniversalTime(), DateTimeKind::Utc);
      }
      
      /// @brief Returns a sorted collection of all the time zones about which information is available on the local system.
      /// @return An read-only Array of TimeZoneInfo objects.
      static const Collections::Generic::List<TimeZoneInfo>& GetSystemTimeZones();

      /// @brief Compares the current instance with another TimeZoneInfo.
      /// @param tzi A TimeZoneInfo to compare with this instance.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared.
      /// The return value has these meanings:
      /// | Value             | Condition                          |
      /// |-------------------|------------------------------------|
      /// | Less than zero    | This instance is less than tzi.    |
      /// | Zero              | This instance is equal to tzi.     |
      /// | Greater than zero | This instance is greater than tzi. |
      int32 CompareTo(const TimeZoneInfo& tzi) const {
        return this->id.CompareTo(tzi.id);
      }

      /// @brief Compares the current instance with another object of the same type.
      /// @param obj An object to compare with this instance.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared.
      /// The return value has these meanings:
      /// | Value             | Condition                          |
      /// |-------------------|------------------------------------|
      /// | Less than zero    | This instance is less than obj.    |
      /// | Zero              | This instance is equal to obj.     |
      /// | Greater than zero | This instance is greater than obj. |
      int32 CompareTo(const IComparable& obj) const override {
        return is<TimeZoneInfo>(obj) && CompareTo(static_cast<const TimeZoneInfo&>(obj));
      }

      /// @brief Retrieves a TimeZoneInfo object from the registry based on its identifier.
      /// @param id The time zone identifier, which corresponds to the Id property.
      /// @return An object whose identifier is the value of the id parameter.
      /// @exception ArgumentNullException The id parameter is null.
      /// @exception TimeZoneNotFoundException The time zone identifier specified by id was not found. This means that a registry key whose name matches id does not exist, || that the key exists but does not contain any time zone data.
      static const TimeZoneInfo& TimeFindSystemTimeZoneById(const String& id);
     
      /// @cond
      static const TimeZoneInfo& __local();
      /// @endcond

    private:
      String id;
      int64 baseUtcOffset = 0;
      String daylightName;
      String displayName;
      String standardName;
      bool supportsDaylightSavingTime = false;
    };
  }
}

using namespace Pcf;
