/// @file
/// @brief Contains Pcf::System::IO::SeekOrigin enum.
#pragma once

#include "../Enum.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Enumeration.
      /// Provides the fields that represent reference points in streams for seeking.
      /// @see Stream
      enum class SeekOrigin {
        /// @brief Specifies the beginning of a stream.
        Begin,
        /// @brief Specifies the current position within a stream.
        Current,
        /// @brief Specifies the end of a stream.
        End,
      };
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::IO::SeekOrigin> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::IO::SeekOrigin::Begin, "Begin"}, {(int64)System::IO::SeekOrigin::Current, "Current"}, {(int64)System::IO::SeekOrigin::End, "End"}};
    flags =  false;
  }
};
/// @endcond

using namespace Pcf;