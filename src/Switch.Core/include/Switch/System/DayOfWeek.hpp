/// @file
/// @brief Contains Switch::System::DayOfWeek enum.
#pragma once

#include "../Types.hpp"
#include "Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Specifies the day of the week.
    /// @see DateTime
    enum class DayOfWeek {
      /// @brief Indicates Sunday.
      Sunday,
      /// @brief Indicates Monday.
      Monday,
      /// @brief Indicates Tuesday.
      Tuesday,
      /// @brief Indicates Wednesday.
      Wednesday,
      /// @brief Indicates Thursday.
      Thursday,
      /// @brief Indicates Friday.
      Friday,
      /// @brief Indicates Saturday.
      Saturday,
    };
  }
}

/// @cond
template<>
class EnumToStrings<System::DayOfWeek> {
public:
  void operator ()(System::Collections::Generic::Dictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::DayOfWeek::Sunday, "Sunday"}, {(int64)System::DayOfWeek::Monday, "Monday"}, {(int64)System::DayOfWeek::Tuesday, "Tuesday"}, {(int64)System::DayOfWeek::Wednesday, "Wednesday"}, {(int64)System::DayOfWeek::Thursday, "Thursday"}, {(int64)System::DayOfWeek::Friday, "Friday"}, {(int64)System::DayOfWeek::Saturday, "Saturday"}};
    flags = false;
  }
};
/// @endcond

using namespace Switch;
