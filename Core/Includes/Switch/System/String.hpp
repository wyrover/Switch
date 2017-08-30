/// @file
/// @brief Contains Pcf::System::String class.
#pragma once

#include "_String.hpp"
#include "_String.h"
#include "Enum.hpp"

/// @cond
template<>
class EnumToStrings<System::StringSplitOptions> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::StringSplitOptions::None, "None"}, {(int64)System::StringSplitOptions::RemoveEmptyEntries, "RemoveEmptyEntries"}};
    flags = false;
  }
};
/// @endcond
