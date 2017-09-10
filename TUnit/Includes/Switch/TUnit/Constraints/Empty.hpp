/// @file
/// @brief Contains Switch::TUnit::Constraints::Empty class.
#pragma once

#include "Constraint.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
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
      class _public Empty : public Constraint {
      public:
        Empty() {}
        
        string ToString() const override {return "<empty>";}
        
      private:
        bool Verify(const ConstraintValue& actual) const override {
          if (is<string>(actual) && string::IsNullOrEmpty(as<string>(actual)))
            return true;
          //if (is<System::Collections::Generic::ICollection<auto>>(actual) && as<System::Collections::Generic::ICollection<auto>>(actual).Count == 0)
          //  return true;
          return false;
        }
      };
    }
  }
}

using namespace Switch;

