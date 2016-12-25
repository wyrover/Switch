/// @file
/// @brief Contains Pcf::System::Decimal struct.
#pragma once

#include <limits>

#include "../Property.h"
#include "Object.h"
#include "../Types.h"
#include "_String.h"
#include "IComparable.h"
#include "IConvertible.h"
#include "IFormattable.h"
#include "TypeCode.h"
#include "ValueType.h"

#include "Double.h"

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
