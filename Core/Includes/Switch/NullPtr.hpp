/// @file
/// @brief Contains Switch::NullPtr struct.
#pragma once

#include <cstddef>
#include "Public.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @cond
  using NullPtr = std::nullptr_t;
  /// @endcond
}

using namespace Switch;
