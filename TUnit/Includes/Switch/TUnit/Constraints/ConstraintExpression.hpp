/// @file
/// @brief Contains Switch::TUnit::Constraints::ConstraintExpression class.
#pragma once

#include <Switch/Abstract.hpp>

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The TUnit namespace contains a unit test framework.
  /// @par Examples
  /// This example how to use TestFixture class, Assert class and #_test method:
  /// @include Assert.cpp
  /// @par Examples
  /// This example how to use TestFixture class, Expect class and #_test method:
  /// @include Expect.cpp
  namespace TUnit {
    /// @brief The TUnit::Constrains conatains ConstraintValue that contain vaule to verify, the base class Contraints, the base class ConstraintExpression, all Constraint inherited classes and all ContraintExpression inherited classes.
    namespace Constraints {
      class _public ConstraintExpression _abstract {
      public:
        ~ConstraintExpression() = 0;
      };
      
      inline ConstraintExpression::~ConstraintExpression() {}
    }
  }
}

using namespace Switch;

