/// @file
/// @brief Contains Pcf::TUnit::Is class.
#pragma once

#include "Constraints/Empty.h"
#include "Constraints/EqualTo.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The TUnit namespace contains a unit test framework.
  /// @remarks This example how to use TestFixture class, Assert class and #pcf_test method:
  /// @include Assert.cpp
  /// @remarks This example how to use TestFixture class, Expect class and #pcf_test method:
  /// @include Expect.cpp
  namespace TUnit {
    namespace Is {
      using EqualTo = Constraints::EqualTo;
      
      using Empty = Constraints::Empty;
    }
  }
}

using namespace Pcf;

