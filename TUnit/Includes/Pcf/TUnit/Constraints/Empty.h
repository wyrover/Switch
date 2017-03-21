/// @file
/// @brief Contains Pcf::TUnit::Constraints::Empty class.
#pragma once

#include "Constraint.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The TUnit namespace contains a unit test framework.
  /// @par Examples
  /// This example how to use TestFixture class, Assert class and #pcf_test method:
  /// @include Assert.cpp
  /// @par Examples
  /// This example how to use TestFixture class, Expect class and #pcf_test method:
  /// @include Expect.cpp
  namespace TUnit {
    /// @brief The TUnit::Constrains conatains ConstraintValue that contain vaule to verify, the base class Contraints, the base class ConstraintExpression, all Constraint inherited classes and all ContraintExpression inherited classes.
    namespace Constraints {
      class pcf_public Empty : public Constraint {
      public:
        Empty() {}
        
        string ToString() const noexcept override {return "<empty>";}
        
      private:
        bool Verify(const ConstraintValue& actual) const override {
          if (is<string>(actual) && as<string>(actual).IsEmpty())
            return true;
          //if (is<System::Collections::Generic::ICollection<auto>>(actual) && as<System::Collections::Generic::ICollection<auto>>(actual).Count == 0)
          //  return true;
          return false;
        }
      };
    }
  }
}

using namespace Pcf;

