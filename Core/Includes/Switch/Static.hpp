/// @file
/// @brief Contains Switch::Static class and #pcf_static keyword.
#pragma once

#include "Types.hpp"
#include "Allocator.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Represent a static class.
  struct pcf_public Static {
    /// @cond
    Static() = delete;
    Static(const Static&) = delete;
    Static& operator=(const Static&) = delete;
    /// @endcond
  };

  /// @brief This keyword is use to represent a static class.
  /// @par Examples
  /// @code
  /// class Foo pcf_static {
  /// public:
  ///   static string ToString() {return "Foo";}
  /// };
  /// @endcode
  /// @ingroup Switch
  #define pcf_static\
  final : Static
}

using namespace Switch;
