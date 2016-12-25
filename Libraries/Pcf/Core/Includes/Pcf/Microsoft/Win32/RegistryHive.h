/// @file
/// @brief Contains Pcf::Microsoft::Win32::RegistryHive enum.
#pragma once

#include "../../System/Enum.h"

namespace Pcf {
  namespace Microsoft {
    namespace Win32 {
      /// @brief Represents the possible values for a top-level node on a foreign machine.
      enum class RegistryHive {
        /// @brief Represents the HKEY_CLASSES_ROOT base key on another computer. This value can be passed to the OpenRemoteBaseKey method, to open this node remotely.
        ClassesRoot = 0,
        /// @brief Represents the HKEY_CURRENT_USER base key on another computer. This value can be passed to the OpenRemoteBaseKey method, to open this node remotely.
        CurrentUser = 1,
        /// @brief Represents the HKEY_LOCAL_MACHINE base key on another computer. This value can be passed to the OpenRemoteBaseKey method, to open this node remotely.
        LocalMachine = 2,
        /// @brief Represents the HKEY_USERS base key on another computer. This value can be passed to the OpenRemoteBaseKey method, to open this node remotely.
        Users = 3,
        /// @brief Represents the HKEY_PERFORMANCE_DATA base key on another computer. This value can be passed to the OpenRemoteBaseKey method, to open this node remotely.
        PerformanceData = 4,
        /// @brief Represents the HKEY_CURRENT_CONFIG base key on another computer. This value can be passed to the OpenRemoteBaseKey method, to open this node remotely.
        CurrentConfig = 5,
        /// @brief Represents the HKEY_DYN_DATA base key on another computer. This value can be passed to the OpenRemoteBaseKey method, to open this node remotely.
        DynData = 6
      };
    }
  }
}

/// @cond
template<>
class EnumToStrings<Microsoft::Win32::RegistryHive> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)Microsoft::Win32::RegistryHive::ClassesRoot, "ClassesRoot"}, {(int64)Microsoft::Win32::RegistryHive::CurrentUser, "CurrentUser"}, {(int64)Microsoft::Win32::RegistryHive::LocalMachine, "LocalMachine"}, {(int64)Microsoft::Win32::RegistryHive::Users, "Users"}, {(int64)Microsoft::Win32::RegistryHive::PerformanceData, "PerformanceData"}, {(int64)Microsoft::Win32::RegistryHive::CurrentConfig, "CurrentConfig"}, {(int64)Microsoft::Win32::RegistryHive::DynData, "DynData"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
