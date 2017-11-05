/// @file
/// @brief Contains Switch::TUnit::Constraints::ConstraintExpression class.
#pragma once

#include <Switch/Abstract.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The TUnit namespace contains a unit test framework.
  /// @par Examples
  /// This example how to use TestFixture class, Assert class and #_AddTest method:
  /// @include Assert.cpp
  /// @par Examples
  /// This example how to use TestFixture class, Expect class and #_AddTest method:
  /// @include Expect.cpp
  namespace TUnit {
    /// @brief The TUnit::Constrains conatains ConstraintValue that contain vaule to verify, the base class Contraints, the base class ConstraintExpression, all Constraint inherited classes and all ContraintExpression inherited classes.
    namespace Constraints {
      class _export ConstraintExpression _abstract {
      public:
        ~ConstraintExpression() = 0;
      };
      
      inline ConstraintExpression::~ConstraintExpression() {}
    }
  }
}

using namespace Switch;

