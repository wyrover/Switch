/// @file
/// @brief Contains Switch::System::Windows::Forms::VisualStyles::VisualStyleState enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief The Switch::System::Windows::Forms::VisualStyles namespace contains classes for rendering controls and other Windows user interface (UI) elements with visual styles in operating systems that support them.
        namespace VisualStyles {
          /// @brief Enumeration.
          /// Specifies how visual styles are applied to the current application.
          /// @remarks This enumeration is used by the Application::VisualStyleState property to specify whether visual styles are applied to client or nonclient areas of application windows.
          enum class VisualStyleState {
            /// @brief Visual styles are not applied to the application.
            NoneEnabled = 0,
            /// @brief Visual styles are applied only to the nonclient area.
            NonClientAreaEnabled = 1,
            /// @brief Visual styles are applied only to the client area.
            ClientAreaEnabled = 2,
            /// @brief Visual styles are applied to client and nonclient areas.
            ClientAndNonClientAreasEnabled = 3,
          };
        }
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Windows::Forms::VisualStyles::VisualStyleState> {
public:
  void operator()(System::Collections::Generic::Dictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::Forms::VisualStyles::VisualStyleState::NoneEnabled, "NoneEnabled"}, {(int64)System::Windows::Forms::VisualStyles::VisualStyleState::NonClientAreaEnabled, "NonClientAreaEnabled"}, {(int64)System::Windows::Forms::VisualStyles::VisualStyleState::ClientAreaEnabled, "ClientAreaEnabled"}, {(int64)System::Windows::Forms::VisualStyles::VisualStyleState::ClientAndNonClientAreasEnabled, "ClientAndNonClientAreasEnabled"}};
    flags = false;
  }
};
/// @endcond

using namespace Switch;
