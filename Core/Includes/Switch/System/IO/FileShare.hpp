/// @file
/// @brief Contains Switch::System::IO::FileShare enum.
#pragma once

#include "../Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Contains constants for controlling the kind of access other System::IO::FileStream objects can have to the same file.
      /// @see FileStream
      enum class FileShare {
        /// @brief Declines sharing of the current file. Any request to open the file (by this process or another process) will fail until the file is closed.
        None = 0,
        /// @brief Allows subsequent opening of the file for reading. If this flag is not specified, any request to open the file for reading (by this process or another process) will fail until the file is closed. However, even if this flag is specified, additional permissions might still be needed to access the file.
        Read = 1,
        /// @brief Allows subsequent opening of the file for writing. If this flag is not specified, any request to open the file for writing (by this process or another process) will fail until the file is closed. However, even if this flag is specified, additional permissions might still be needed to access the file.
        Write = 2,
        /// @brief Allows subsequent opening of the file for reading or writing. If this flag is not specified, any request to open the file for reading or writing (by this process or another process) will fail until the file is closed. However, even if this flag is specified, additional permissions might still be needed to access the file.
        ReadWrite = 3,
        /// @brief Allows subsequent deleting of a file.
        Delete = 4,
        /// @brief Makes the file handle inheritable by child processes. This is not directly supported by Win32.
        Inheritable = 16,
      };
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::IO::FileShare> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::IO::FileShare::None, "None"}, {(int64)System::IO::FileShare::Read, "Read"}, {(int64)System::IO::FileShare::Write, "Write"}, {(int64)System::IO::FileShare::ReadWrite, "ReadWrite"}, {(int64)System::IO::FileShare::Delete, "Delete"}, {(int64)System::IO::FileShare::Inheritable, "Inheritable"}};
    flags = false;
  }
};
/// @endcond

using namespace Switch;
