/// @file
/// @brief Contains Pcf::System::Windows::Forms::MouseButtons enum.
#pragma once

#include <Pcf/System/Enum.hpp>

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies the mode to start the computer in.
        enum class BootMode {
          /// @brief Starts the computer in standard mode.
          Normal = 0,
          /// @brief Starts the computer by using only the basic files and drivers.
          FailSafe = 1,
          /// @brief Starts the computer by using the basic files, drivers and the services and drivers necessary to start networking.
          FailSafeWithNetwork = 2,
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Windows::Forms::BootMode> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::Forms::BootMode::Normal, "Normal"}, {(int64)System::Windows::Forms::BootMode::FailSafe, "FailSafe"}, {(int64)System::Windows::Forms::BootMode::FailSafeWithNetwork, "FailSafeWithNetwork"},};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
