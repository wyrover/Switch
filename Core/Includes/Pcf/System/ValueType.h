/// @file
/// @brief Contains Pcf::System::ValueType class.
#pragma once

#include "Object.h"

/// @brief The Pcf namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    class String;
    /// @endcond

    /// @brief Provides the base class for value types.
    class pcf_public ValueType : public Object {
    public:
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      virtual bool Equals(const ValueType& valueType) const;

      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const Object& obj) const override;

      /// @brief Returns a string that represents the current object.
      /// @return string A string that represents the current object.
      String ToString() const override = 0;

      /// @brief Creates a shallow copy of the current object.
      /// @return ValueType* A shallow copy of the current object.
      /// @par Examples
      /// The following code example shows how to copy an instance of a class using MemberwiseClone.
      /// @include ObjectMemberwiseClone.cpp
      //template<typename T>
      //ValueType* MemberwiseClone() const;

    private:
      virtual bool IsSigned() const {return false;}
    };
  }
}

#include "_String.h"

using namespace Pcf;
