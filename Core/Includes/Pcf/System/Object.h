/// @file
/// @brief Contains Pcf::System::Object class.
#pragma once

#include <ostream>

#include "../Types.h"
#include "../As.h"
#include "../UniquePointer.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    class Type;
    class String;
    /// @endcond

    /// @brief Supports all classes in the Pcf class hierarchy and provides low-level services to derived classes.
    /// This is the ultimate base class of all classes in the Pcf.
    /// It is the root of the type hierarchy.
    /// @par Examples
    /// The following example defines a Point type derived from the Object class and virtuals many of the virtual methods of the Object class. In addition, the example shows how to call many of the static and instance methods of the Object class.
    /// @include Object.cpp
    class pcf_public Object {
    public:
      /// @brief Create a new instance of the ultimate base class Object
      /// @remarks This constructor is called by constructors in derived classes, but it can also be used to directly create an instance of the Object class.
      Object() noexcept = default;
      
      /// @cond
      Object(const Object&) noexcept = default;
      Object& operator =(const Object&) noexcept = default;
      virtual ~Object() noexcept = default;
      bool operator ==(const Object& obj) const noexcept {return Equals(obj);}
      bool operator !=(const Object& obj) const noexcept {return !this->operator==(obj);}
      /// @endcond
      
      /// @brief Determines whether the specified Object is equal to the current Object.
      /// @param obj The Object to compare with the current Object.
      /// @return bool true if the specified Object is equal to the current Object. otherwise, false.
      /// @par Examples
      /// The following code example compares the current instance with another object.
      /// @include ObjectEquals.cpp
      virtual bool Equals(const Object& obj) const noexcept {return this == &obj;}

      /// @brief Determines whether the specified Object instances are considered equal.
      /// @param objectA The first Object to compare.
      /// @param objectB The second Object to compare.
      /// @return bool true if objectA is the same instance as objectB or if both are null references or if objectA(objectB) returns true. otherwise, false.
      /// @par Examples
      /// The following code example compares different objects.
      /// @include ObjectEquals2.cpp
      static bool Equals(const Object& objectA, const Object& objectB) noexcept {return objectA.Equals(objectB);}

      /// @brief Serves as a hash function for a particular type.
      /// @return int32 A hash code for the current Object.
      virtual int32 GetHashCode() const noexcept {return static_cast<int32>(reinterpret_cast<int64>(this) & 0x00000000FFFFFFFF) ^ static_cast<int32>((reinterpret_cast<int64>(this)>>32) & 0x00000000FFFFFFFF);}
      
      /// @brief Gets the Type of the current instance.
      /// @return Type The Type instance that represents the exact runtime type of the current instance.
      /// @par Examples
      /// The following code example demonstrates that GetType returns the runtime type of the current instance.
      /// @include ObjectGetType.cpp
      virtual Type GetType() const noexcept;

      /// @brief Creates a shallow copy of the current Object.
      /// @return UniquePointer<Object> A shallow copy of the current Object.
      /// @par Examples
      /// The following code example shows how to copy an instance of a class using MemberwiseClone.
      /// @include ObjectMemberwiseClone.cpp
      template<typename T>
      UniquePointer<Object> MemberwiseClone() const noexcept {return new T(as<T>(*this));}

      /// @brief Determines whether the specified Object instances are the same instance.
      /// @param objectA The first Object to compare.
      /// @param objectB The second Object to compare.
      /// @return bool true if objectA is the same instance as objectB or if both are null references; otherwise, false.
      /// @par Examples
      /// The following code example uses ReferenceEquals to determine if two objects are the same instance.
      /// @include ObjectReferenceEquals.cpp
      static bool ReferenceEquals(const Object& objectA, const Object& objectB) noexcept {return &objectA == &objectB;}

      /// @brief Returns a String that represents the current Object.
      /// @return string A string that represents the current Object.
      /// @par Examples
      /// The following code example demonstrates what ToString returns.
      /// @include ObjectToString.cpp
      virtual String ToString() const;
    };
  }

  /// @brief Supports all classes in the Pcf class hierarchy and provides low-level services to derived classes.
  /// @see System::Object
  using object = System::Object;
}

std::ostream& operator<<(std::ostream& os, const System::Object& value) noexcept;

#include "_String.h"
#include "Type.h"

using namespace Pcf;
