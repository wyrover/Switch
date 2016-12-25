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
    /// The following example defines a Point type derived from the Object class and virtuals many of the virtual methods of the Object class. In addition, the example shows how to call many of the static and instance methods of the Object class.
    /// @include Object.cpp
    class Object {
    public:
      /// @brief Create a new instance of the ultimate base class Object
      /// @remarks This constructor is called by constructors in derived classes, but it can also be used to directly create an instance of the Object class.
      Object() {}

      /// @brief Determines whether the specified Object is equal to the current Object.
      /// @param obj The Object to compare with the current Object.
      /// @return bool true if the specified Object is equal to the current Object. otherwise, false.
      /// The following code example compares the current instance with another object.
      /// @include ObjectEquals.cpp
      virtual bool Equals(const Object& obj) const { return this == &obj; }

      /// @brief Determines whether the specified Object instances are considered equal.
      /// @param objectA The first Object to compare.
      /// @param objectB The second Object to compare.
      /// @return bool true if objectA is the same instance as objectB or if both are null references or if objectA(objectB) returns true. otherwise, false.
      /// The following code example compares different objects.
      /// @include ObjectEquals2.cpp
      static bool Equals(const Object& objectA, const Object& objectB) { return objectA.Equals(objectB); }

      /// @brief Gets the Type of the current instance.
      /// @return Type The Type instance that represents the exact runtime type of the current instance.
      /// The following code example demonstrates that GetType returns the runtime type of the current instance.
      /// @include ObjectGetType.cpp
      Type GetType() const;

      /// @brief Creates a shallow copy of the current Object.
      /// @return UniquePointer<Object> A shallow copy of the current Object.
      /// The following code example shows how to copy an instance of a class using MemberwiseClone.
      /// @include ObjectMemberwiseClone.cpp
      template<typename T>
      UniquePointer<Object> MemberwiseClone() const { return new T(as<T>(*this)); }

      /// @brief Determines whether the specified Object instances are the same instance.
      /// @param objectA The first Object to compare.
      /// @param objectB The second Object to compare.
      /// @return bool true if objectA is the same instance as objectB or if both are null references; otherwise, false.
      /// The following code example uses ReferenceEquals to determine if two objects are the same instance.
      /// @include ObjectReferenceEquals.cpp
      static bool ReferenceEquals(const Object& objectA, const Object& objectB) { return &objectA == &objectB; }

      /// @brief Returns a String that represents the current Object.
      /// @return string A string that represents the current Object.
      /// The following code example demonstrates what ToString returns.
      /// @include ObjectToString.cpp
      virtual String ToString() const;

      /// @cond
      Object(const Object&) {}
      Object& operator =(const Object&) {return *this;}
      virtual ~Object() {}
      bool operator ==(const Object& obj) const { return Equals(obj); }
      bool operator !=(const Object& obj) const { return !Equals(obj); }
      /// @endcond
    };
  }

  /// @brief Supports all classes in the Pcf class hierarchy and provides low-level services to derived classes.
  /// @see System::Object
  using object = System::Object;
}

std::ostream& operator<<(std::ostream& os, const System::Object& value);

#include "_String.h"
#include "Type.h"

using namespace Pcf;
