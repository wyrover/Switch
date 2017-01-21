/// @file
/// @brief Contains Pcf::TUnit::Constraints::ConstraintValue class.
#pragma once

#include <Pcf/Any.h>
#include <Pcf/System/Object.h>

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
      class pcf_public ConstraintValue : public object {
      public:
        ConstraintValue() {}
        template <typename T>
        ConstraintValue(const T& value) : value(value) {}
        
        /// @cond
        ConstraintValue(const any& value) : value(value) {}
        ConstraintValue(const ConstraintValue& value) : value(value.value) {}
        ConstraintValue& operator=(const ConstraintValue& value) {this->value = value.value; return *this;}
        /// @endcond
        
        Property<object, ReadOnly> Value {
          pcf_get {return this->value.Value();}
        };
        
        operator const any&() const {return this->value;}
        operator any&() {return this->value;}
        
        string ToString() const override {
          if (is<string>(this->value) && as<string>(this->value).IsEmpty())
            return "<string::Empty>";
          if (is<string>(this->value))
            return string::Format("\"{0}\"", this->value);
          return string::Format("{0}", this->value);
        }
        
      private:
        any value;
      };
    }
  }
  
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// TUnit::Constraints::ContraintValue v = "Test";
  /// string str = as<string>(v);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  template<typename T>
  const T& as(const TUnit::Constraints::ConstraintValue& value) {
    return ((const any&)value).As<T>();
  }
  
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// TUnit::Constraints::ContraintValue v = "Test";
  /// string str = as<string>(v);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  template<typename T>
  T& as(TUnit::Constraints::ConstraintValue& value) {
    return ((any&)value).As<T>();
  }
  
  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// TUnit::Constraints::ContraintValue v = "Test";
  /// bool isString = is<string>(v);
  /// @endcode
  /// @see Pcf::System::Type
  template<typename T>
  bool is(const TUnit::Constraints::ConstraintValue& value) {
    return ((const any&)value).Is<T>();
  }
  
  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// TUnit::Constraints::ContraintValue v = "Test";
  /// bool isString = is<string>(v);
  /// @endcode
  /// @see Pcf::System::Type
  template<typename T>
  bool is(TUnit::Constraints::ConstraintValue& value) {
    return ((any&)value).Is<T>();
  }
}

using namespace Pcf;

