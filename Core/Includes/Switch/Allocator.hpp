/// @file
/// @brief Contains Pcf::System::Allocator <T> class.
#pragma once

#include <cstddef>
#include <memory>

namespace Pcf {
  /// @brief This is the default Allocator used by all Pcf library containers if no user-specified allocator is provided. The default allocator is stateless, that is, all instances of the given allocator are interchangeable, compare equal and can deallocate memory allocated by any other instance of the same allocator type.
  template<typename T>
  using Allocator = std::allocator<T>;
}

using namespace Pcf;
