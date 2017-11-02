/// @file
/// @brief Contains Switch::TUnit::Constraints::EqualTo class.
#pragma once

#include "Constraint.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The TUnit namespace contains a unit test framework.
  /// @par Examples
  /// This example how to use TestFixture class, Assert class and #_add_test method:
  /// @include Assert.cpp
  /// @par Examples
  /// This example how to use TestFixture class, Expect class and #_add_test method:
  /// @include Expect.cpp
  namespace TUnit {
    /// @brief The TUnit::Constrains conatains ConstraintValue that contain vaule to verify, the base class Contraints, the base class ConstraintExpression, all Constraint inherited classes and all ContraintExpression inherited classes.
    namespace Constraints {
      class _export EqualTo : public Constraint {
      public:
        template<typename TExpect>
        EqualTo(const TExpect& expect) : Constraint(expect) {}
        
        string ToString() const override {return string::Format("{0}", this->expect);}
        
      private:
        bool Verify(const ConstraintValue& actual) const override {
          return actual.Value() == expect.Value();
        }
      };
    }
  }
}


using namespace Switch;

