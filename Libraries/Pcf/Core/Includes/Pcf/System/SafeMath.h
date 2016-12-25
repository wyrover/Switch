/// @file
/// @brief Contains Pcf::System::SafeMath class.
#pragma once

#include "../Static.h"
#include "../Types.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    // class that provides basic arithmetic that generates OverflowException when
    // arithmetic overflows happens.
    class SafeMath pcf_static {
    public:
      static uint64 ShiftToUInt64(int64 x);
      static uint64 Add(uint64 x, uint64 y);
      static uint64 Mul(uint64 x, uint64 y);
      static uint64 PositivePower(uint32 x, uint32 p);
    };
  }
}

using namespace Pcf;
