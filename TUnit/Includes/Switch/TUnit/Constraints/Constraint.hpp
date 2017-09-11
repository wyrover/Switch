/// @file
/// @brief Contains Switch::TUnit::Constraints::Constraint class.
#pragma once

#include <Switch/Abstract.hpp>
#include <Switch/System/Environment.hpp>
#include "ConstraintValue.hpp"

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
      class _export Constraint _abstract {
      public:
        _property<::CurrentInformation> CurrentInformation {
          _get {return this->currentInformation;},
          _set {this->currentInformation = value;}
        };
        
        _property<ConstraintValue> Actual {
          _get {return this->actual;},
          _set {this->actual = value;}
        };
        
        _property<ConstraintValue> Expect {
          _get {return this->expect;},
          _set {this->expect = value;}
        };
        
        _property<string, _readonly> Error {
          _get {return string::Format("Expected: {0}{2}But was:  {1}", ToString(), this->actual, System::Environment::NewLine);}
        };
        
        _property<string> Message {
          _get {return this->message;},
          _set {this->message = value;}
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

