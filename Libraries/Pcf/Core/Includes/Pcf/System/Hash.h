/// @file
/// @brief Contains Pcf::System::Hash class.
#pragma once

#include "../Any.h"
#include "../Static.h"
#include "../Types.h"
#include "../SharedPointer.h"
#include "IHashable.h"
#include "NullType.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// Represents API to calculate Hash for object and primitive types.
    /// This class cannot be inherited.
    class Hash pcf_static {
    public:
      /// @brief
      ///   Generate a hash code for generic type T.
      /// @param[in] value
      ///   For which the hashcode is generated.
      /// @return int32
      ///   An integer value being the generated hashcode.
      /// @exception System::ArgumentNullException
      ///   The parameters converter is null.
      static int32 GetHashCode(const IHashable& value);
      
      /// @brief
      ///   Generate a hash code for generic type T.
      /// @param[in] value
      ///   For which the hashcode is generated.
      /// @return int32
      ///   An integer value being the generated hashcode.
      /// @exception System::ArgumentNullException The parameters converter is null.
      template<typename T>
      static int32 GetHashCode(const SharedPointer<T>& value) {
        return *((int32*)value.ToPointer());
      }

      /// @brief
      ///   Generate a hash code for void*.
      /// @param[in] value
      ///   For which the hashcode is generated.
      /// @return int32
      ///   An integer value being the generated hashcode.
      /// @exception System::ArgumentNullException
      ///   The parameters converter is null.
      static int32 GetHashCode(const void* e);

      /// @brief
      ///   Generate a hash code for NullType.
      /// @param[in] value
      ///   For which the hashcode is generated.
      /// @return int32
      ///   An integer value being the generated hashcode.
      /// @exception System::ArgumentNullException
      ///   The parameters converter is null.
      static int32 GetHashCode(const NullType& value);

      /// @brief
      ///   Generate a hash code for bool.
      /// @param[in] value
      ///   For which the hashcode is generated.
      /// @return int32
      ///   An integer value being the generated hashcode.
      /// @exception System::ArgumentNullException
      ///   The parameters converter is null.
      static int32 GetHashCode(const bool& value);

      /// @brief
      ///   Generate a hash code for signed 8-bit integer.
      /// @param[in] value
      ///   For which the hashcode is generated.
      /// @return int32
      ///   An integer value being the generated hashcode.
      /// @exception System::ArgumentNullException
      ///   The parameters converter is null.
      static int32 GetHashCode(const sbyte& value);

      /// @brief
      ///   Generate a hash code for signed 16-bit integer.
      /// @param[in] value
      ///   For which the hashcode is generated.
      /// @return int32
      ///   An integer value being the generated hashcode.
      /// @exception System::ArgumentNullException
      ///   The parameters converter is null.
      static int32 GetHashCode(const int16& value);

      /// @brief
      ///   Generate a hash code for signed 32-bit integer.
      /// @param[in] value
      ///   For which the hashcode is generated.
      /// @return int32
      ///   An integer value being the generated hashcode.
      /// @exception System::ArgumentNullException
      ///   The parameters converter is null.
      static int32 GetHashCode(const int32& value);

      /// @brief
      ///   Generate a hash code for signed 64-bit integer.
      /// @param[in] value
      ///   For which the hashcode is generated.
      /// @return int32
      ///   An integer value being the generated hashcode.
      /// @exception System::ArgumentNullException
      ///   The parameters converter is null.
      static int32 GetHashCode(const int64& value);

      /// @brief
      ///   Generate a hash code for unsigned 8-bit integer.
      /// @param[in] value
      ///   For which the hashcode is generated.
      /// @return int32
      ///   An integer value being the generated hashcode.
      /// @exception System::ArgumentNullException
      ///   The parameters converter is null.
      static int32 GetHashCode(const byte& value);

      /// @brief
      ///   Generate a hash code for unsigned 16-bit integer.
      /// @param[in] value
      ///   For which the hashcode is generated.
      /// @return int32
      ///   An integer value being the generated hashcode.
      /// @exception System::ArgumentNullException
      ///   The parameters converter is null.
      static int32 GetHashCode(const uint16& value);

      /// @brief
      ///   Generate a hash code for unsigned 32-bit integer.
      /// @param[in] value
      ///   For which the hashcode is generated.
      /// @return int32
      ///   An integer value being the generated hashcode.
      /// @exception System::ArgumentNullException
      ///   The parameters converter is null.
      static int32 GetHashCode(const uint32& value);

      /// @brief
      ///   Generate a hash code for unsigned 64-bit integer.
      /// @param[in] value
      ///   For which the hashcode is generated.
      /// @return int32
      ///   An integer value being the generated hashcode.
      /// @exception System::ArgumentNullException
      ///   The parameters converter is null.
      static int32 GetHashCode(const uint64& value);

      /// @brief
      ///   Generate a hash code for double-precision floating-point number.
      /// @param[in] value
      ///   For which the hashcode is generated.
      /// @return int32
      ///   An integer value being the generated hashcode.
      /// @exception System::ArgumentNullException
      ///   The parameters converter is null.
      static int32 GetHashCode(const double& value);

      /// @brief
      ///   Generate a hash code for signle-precision floating-point number.
      /// @param[in] value
      ///   For which the hashcode is generated.
      /// @return int32
      ///   An integer value being the generated hashcode.
      /// @exception System::ArgumentNullException
      ///   The parameters converter is null.
      static int32 GetHashCode(const float& value);
    };
  }
}

using namespace Pcf;
