/// @file
/// @brief Contains Switch::Static class and #sw_static keyword.
#pragma once

#include "Types.hpp"
#include "Allocator.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Represent a static class.
  struct sw_public Static {
    /// @cond
    Static() = delete;
    Static(const Static&) = delete;
    Static& operator=(const Static&) = delete;
    /// @endcond
  };

  /// @brief This keyword is use to represent a static class.
  /// @par Examples
  /// @code
  /// class Foo sw_static {
  /// public:
  ///   static string ToString() {return "Foo";}
  /// };
  /// @endcode
  /// @ingroup Switch
  #define sw_static\
  final : Static
}

using namespace Switch;
