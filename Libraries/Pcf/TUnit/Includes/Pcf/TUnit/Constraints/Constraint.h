/// @file
/// @brief Contains Pcf::TUnit::Constraints::Constraint class.
#pragma once

#include <Pcf/Abstract.h>
#include <Pcf/System/Environment.h>
#include "ConstraintValue.h"

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
      class Constraint pcf_abstract {
      public:
        Property<::CurrentInformation> CurrentInformation {
          pcf_get {return this->currentInformation;},
          pcf_set {this->currentInformation = value;}
        };
        
        Property<ConstraintValue> Actual {
          pcf_get {return this->actual;},
          pcf_set {this->actual = value;}
        };
        
        Property<ConstraintValue> Expect {
          pcf_get {return this->expect;},
          pcf_set {this->expect = value;}
        };
        
        Property<string, ReadOnly> Error {
          pcf_get {return string::Format("Expected: {0}{2}But was: {1}", ToString(), this->actual, System::Environment::NewLine);}
        };
        
        Property<string> Message {
          pcf_get {return this->message;},
          pcf_set {this->message = value;}
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

using namespace Pcf;

