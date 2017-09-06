/// @file
/// @brief Contains Switch::Static class and #_static keyword.
#pragma once

#include "Types.hpp"
#include "Allocator.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Represent a static class.
  struct _public Static {
    /// @cond
    Static() = delete;
    Static(const Static&) = delete;
    Static& operator=(const Static&) = delete;
    /// @endcond
  };

  /// @brief This keyword is use to represent a static class.
  /// @par Examples
  /// @code
  /// class Foo _static {
  /// public:
  ///   static string ToString() {return "Foo";}
  /// };
  /// @endcode
  /// @ingroup Switch
  #define _static\
  final : Static
}

using namespace Switch;
