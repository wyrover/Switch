/// @file
/// @brief Contains Switch::Microsoft::Win32::RegistryValueOptions enum.
#pragma once

#include "../../System/Enum.hpp"

namespace Switch {
  /// @brief The Microsoft namespace provide Microsoft specific classes.
  namespace Microsoft {
    /// @brief The Microsoft::Win32 namespace provides two types of classes: those that handle events raised by the operating system and those that manipulate the system registry.
    namespace Win32 {
      /// @brief Specifies optional behavior when retrieving name/value pairs from a registry key.
      /// @remarks Use the DoNotExpandEnvironmentNames flag with the RegistryKey::GetValue(String, Object, RegistryValueOptions) method overload.
      enum class RegistryValueOptions {
        /// @brief No optional behavior is specified.This is the default.
        None = 0,
        /// @brief A value of type RegistryValueKind::ExpandString is retrieved without expanding its embedded environment variables. .
        DoNotExpandEnvironmentNames = 1
      };
    }
  }
}

/// @cond
template<>
class EnumToStrings<Microsoft::Win32::RegistryValueOptions> {
public:
  void operator ()(System::Collections::Generic::Dictionary<int64, string>& values, bool& flags) {
    values = {{(int64)Microsoft::Win32::RegistryValueOptions::None, "None"}, {(int64)Microsoft::Win32::RegistryValueOptions::DoNotExpandEnvironmentNames, "DoNotExpandEnvironmentNames"}};
    flags = false;
  }
};
/// @endcond

using namespace Switch;
