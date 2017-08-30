/// @file
/// @brief Contains Pcf::System::ArraySegment type.
#pragma once

#include "Array.hpp"

namespace Pcf {
  namespace System {
    /// @brief Delimits a section of a one-dimensional array.
    /// @todo Write Decimal class.
    template<typename T, typename TAllocator = Allocator<T>>
    using ArraySegment = Array<T, 1, TAllocator>;
  }
}

using namespace Pcf;
