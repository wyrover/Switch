/// @file
/// @brief Contains Pcf::System::Decimal struct.
#pragma once

#include <limits>

#include "../Property.hpp"
#include "Object.hpp"
#include "../Types.hpp"
#include "_String.hpp"
#include "IComparable.hpp"
#include "IConvertible.hpp"
#include "IFormattable.hpp"
#include "TypeCode.hpp"
#include "ValueType.hpp"

#include "Double.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    namespace Threading {
      class Interlocked;
    }
    /// @endcond
    /// @brief Represents a decimal number.
    /// @todo Write Decimal class.
    using Decimal=Double;
  }
}

using namespace Pcf;
