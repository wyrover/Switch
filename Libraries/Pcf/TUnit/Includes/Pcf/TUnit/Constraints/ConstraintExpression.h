/// @file
/// @brief Contains Pcf::TUnit::Constraints::ConstraintExpression class.
#pragma once

#include <Pcf/Abstract.h>

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The TUnit namespace contains a unit test framework.
  /// @remarks This example how to use TestFixture class, Assert class and #pcf_test method:
  /// @include Assert.cpp
  /// @remarks This example how to use TestFixture class, Expect class and #pcf_test method:
  /// @include Expect.cpp
  namespace TUnit {
    /// @brief The TUnit::Constrains conatains ConstraintValue that contain vaule to verify, the base class Contraints, the base class ConstraintExpression, all Constraint inherited classes and all ContraintExpression inherited classes.
    namespace Constraints {
      class pcf_public ConstraintExpression pcf_abstract {
      public:
      };
    }
  }
}

using namespace Pcf;

