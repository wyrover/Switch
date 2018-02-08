/// @file
/// @brief Contains Switch::TUnit::Constraints::Constraint class.
#pragma once

#include <Switch/Abstract.hpp>
#include <Switch/System/Environment.hpp>
#include "ConstraintValue.hpp"
#include "../../TUnitCoreExport.hpp"

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
    /// @brief The TUnit::Constrains conatains ConstraintValue that contain vaule to verify, the base class Contraints, the base class ConstraintExpression, all Constraint inherited classes and all ContraintExpression inherited classes.
    namespace Constraints {
      class tunit_core_export_ Constraint abstract_ {
      public:
        property_< System::Runtime::CompilerServices::Caller> Caller {
          get_ {return this->caller;},
          set_ {this->caller = value;}
        };

        property_<ConstraintValue> Actual {
          get_ {return this->actual;},
          set_ {this->actual = value;}
        };

        property_<ConstraintValue> Expect {
          get_ {return this->expect;},
          set_ {this->expect = value;}
        };

        property_<string, readonly_> Error {
          get_ {return string::Format("Expected: {0}{2}But was:  {1}", ToString(), this->actual, System::Environment::NewLine);}
        };

        property_<string> Message {
          get_ {return this->message;},
          set_ {this->message = value;}
        };

        template<typename T>
        bool Verify(const T& value) const {
          return Verify(ConstraintValue(value));
        }

      protected:
        Constraint() {}
        Constraint(const ConstraintValue& expect) : expect(expect) {}

        virtual bool Verify(const ConstraintValue& actual) const = 0;
        virtual string ToString() const = 0;

        mutable ConstraintValue actual;
        ConstraintValue expect;
        mutable string message;
        mutable System::Runtime::CompilerServices::Caller caller;
      };
    }
  }
}

using namespace Switch;

