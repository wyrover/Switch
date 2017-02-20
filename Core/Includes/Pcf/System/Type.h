/// @file
/// @brief Contains Pcf::System::Type class.
#pragma once

#include "../As.h"
#include "../Is.h"
#include "../Property.h"
#include "ICloneable.h"
#include "IConvertible.h"
#include "Boolean.h"
#include "Object.h"
#include "_String.h"
#include "TypeCode.h"
#include "ValueType.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @cond
  namespace System {
    class Type;
    class Object;
  }
  
  template<typename T> System::Type pcf_typeof();
  template<typename T> System::Type pcf_typeof(const T& value);
  /// @endcond
  
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents type declarations: class types, interface types, array types, value types, enumeration types, type parameters, generic type definitions, and open or closed constructed generic types.
    class pcf_public Type : public Object {
    public:
      /// @cond
      Type(const Type& type);
      /// @endcond
      
      /// @brief Gets the fully qualified name of the Type, including the namespace of the Type.
      /// @return The fully qualified name of the Type, including the namespace of the Type.
      /// @remarks For example, the fully qualified name of the String type is String.
      Property<String, ReadOnly> FullName ;
      
      /// @brief Gets the name of the Type.
      /// @return The name of the Type.
      /// @remarks For example, the name of the String type is String.
      Property<String, ReadOnly> Name;
      
      /// @brief Gets the namespace of the Type.
      /// @return The namespace of the Type.
      /// @remarks For example, the namespace of the String type is System::
      Property<String, ReadOnly> Namespace;
      
      /// @brief Determines whether the specified Object is equal to the current Object.
      /// @param obj The Object to compare with the current Object.
      /// @return bool true if the specified Object is equal to the current Object. otherwise, false.
      bool Equals(const Object& obj) const noexcept override;
      
      /// @brief Determines whether the specified Type is equal to the current Type.
      /// @param type The Type to compare with the current Object.
      /// @return bool true if the specified type is equal to the current Type. otherwise, false.
      bool Equals(const Type& type) const;
      /// @brief Gets the underlying type code of the specified Type
      /// @param value The value of type whose underlying type code to get.
      /// @return The code of the underlying type, or Empty if type is null.
      template<typename T>
      static TypeCode GetTypeCode(const T& value) {
        if (!is<IConvertible>(value))
          return TypeCode::Object;
        
        return dynamic_cast<const IConvertible&>(value).GetTypeCode();
      }
      
      template<typename T>
      static bool IsComparable(T value) { return is<IComparable>(value); }
      
      template<typename T, class TT>
      static bool IsInstanceOfType(TT value) { return is<T>(value); }
      
      template<typename T>
      static bool IsValueType(T obj) { return is<ValueType>(obj); }
      
      /// @brief Returns a String representing the name of the current Type.
      /// @return A String representing the name of the current Type.
      String ToString() const override;
      
    private:
      String GetFullName() const;
      String GetName() const;
      String GetNamespace() const;
      
      template<typename T> friend Type Pcf::pcf_typeof();
      template<typename T> friend Type Pcf::pcf_typeof(const T& value);
      friend class Object;
      
      Type();
      Type(const std::type_info& type);
      Type& operator =(const Type& type);
      
      const std::type_info& type;
    };
  }
  
  /// @brief Used to obtain the type Object for a type. A pcf_typeof expression takes the following form:
  /// @par Examples
  /// @code
  /// Type type = pcf_typeof<Int32>;
  /// @endcode
  /// @par Examples
  /// To obtain the run-time type of an expression, you can use the Pcf method GetType, as in the following example:
  /// @code
  /// Int32 i = 0;
  /// System::Type type = i.GetType();
  /// @endcode
  /// @remarks The pcf_typeof operator cannot be overloaded.
  /// @ingroup Pcf
  template<typename T>
  System::Type pcf_typeof() {
    return System::Type(typeid(T));
  }
  
  /// @brief Used to obtain the type Object for a type. A pcf_typeof expression takes the following form:
  /// @par Examples
  /// @code
  /// @Int32 i = 42;
  /// type atype& = pcf_typeof(i);
  /// @endcode
  /// @par Examples
  /// To obtain the run-time type of an expression, you can use the Pcf method GetType, as in the following example:
  /// @code
  /// Int32 42 = 0;
  /// System::Type Type = i.GetType();
  /// @endcode
  /// @remarks The pcf_typeof operator cannot be overloaded.
  /// @see System::Type
  /// @ingroup Pcf
  template<typename T>
  System::Type pcf_typeof(const T& value) {
    return System::Type(typeid(value));
  }
  
#if __APPLE__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wkeyword-macro"
#define typeof pcf_typeof
#pragma clang diagnostic pop
#elif __linux__
#define typeof pcf_typeof
#else
  template<typename T>
  System::Type typeof() {return pcf_typeof<T>();}

  template<typename T>
  System::Type typeof(const T& value) {return pcf_typeof(value);}
#endif
}

using namespace Pcf;
