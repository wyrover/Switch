/// @file
/// @brief Contains Switch::TUnit::Is class.
#pragma once

#include "Constraints/Empty.hpp"
#include "Constraints/EqualTo.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The TUnit namespace contains a unit test framework.
  /// @par Examples
  /// This example how to use TestFixture class, Assert class and #AddTest_ method:
  /// @include Assert.cpp
  /// @par Examples
  /// This example how to use TestFixture class, Expect class and #AddTest_ method:
  /// @include Expect.cpp
  namespace TUnit {
    namespace Is {
      using EqualTo = Constraints::EqualTo;

      using Empty = Constraints::Empty;
    }
  }
}

using namespace Switch;

