/// @file
/// @brief Contains Switch::TUnit::Constraints::Constraint class.
#pragma once

#include <Switch/Abstract.hpp>
#include <Switch/System/Environment.hpp>
#include "ConstraintValue.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The TUnit namespace contains a unit test framework.
  /// @par Examples
  /// This example how to use TestFixture class, Assert class and #sw_test method:
  /// @include Assert.cpp
  /// @par Examples
  /// This example how to use TestFixture class, Expect class and #sw_test method:
  /// @include Expect.cpp
  namespace TUnit {
    /// @brief The TUnit::Constrains conatains ConstraintValue that contain vaule to verify, the base class Contraints, the base class ConstraintExpression, all Constraint inherited classes and all ContraintExpression inherited classes.
    namespace Constraints {
      class sw_public Constraint sw_abstract {
      public:
        Property<::CurrentInformation> CurrentInformation {
          sw_get {return this->currentInformation;},
          sw_set {this->currentInformation = value;}
        };
        
        Property<ConstraintValue> Actual {
          sw_get {return this->actual;},
          sw_set {this->actual = value;}
        };
        
        Property<ConstraintValue> Expect {
          sw_get {return this->expect;},
          sw_set {this->expect = value;}
        };
        
        Property<string, ReadOnly> Error {
          sw_get {return string::Format("Expected: {0}{2}But was: {1}", ToString(), this->actual, System::Environment::NewLine);}
        };
        
        Property<string> Message {
          sw_get {return this->message;},
          sw_set {this->message = value;}
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
        mutable ::CurrentInformation currentInformation;
      };
    }
  }
}

using namespace Switch;

