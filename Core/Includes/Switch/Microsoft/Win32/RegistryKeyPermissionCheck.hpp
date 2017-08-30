/// @file
/// @brief Contains Switch::Microsoft::Win32::RegistryKeyPermissionCheck enum.
#pragma once

#include "../../System/Enum.hpp"

namespace Switch {
  namespace Microsoft {
    namespace Win32 {
      /// @brief Specifies whether security checks are performed when opening registry keys and accessing their name/value pairs.
      enum class RegistryKeyPermissionCheck {
        /// @brief A non-volatile key. This is the default.
        Default = 0,
        /// @brief A volatile key. The information is stored in memory and is not preserved when the corresponding registry hive is unloaded.
        ReadSubTree = 1,
        /// @brief Security checks are not performed when accessing subkeys or values. A security check is performed when trying to open the current key, unless the parent was opened with ReadWriteSubTree.
        ReadWriteSubTree = 2
      };
    }
  }
}

/// @cond
template<>
class EnumToStrings<Microsoft::Win32::RegistryKeyPermissionCheck> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)Microsoft::Win32::RegistryKeyPermissionCheck::Default, "Default"}, {(int64)Microsoft::Win32::RegistryKeyPermissionCheck::ReadSubTree, "ReadSubTree"}, {(int64)Microsoft::Win32::RegistryKeyPermissionCheck::ReadWriteSubTree, "ReadWriteSubTree"}};
    flags = false;
  }
};
/// @endcond

using namespace Switch;
