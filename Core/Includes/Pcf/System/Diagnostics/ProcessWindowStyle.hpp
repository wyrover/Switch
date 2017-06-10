/// @file
/// @brief Contains Pcf::System::Diagnostics::ProcessStartInfo class.
#pragma once

#include "../Security/SecureString.hpp"
#include "../Collections/Generic/Dictionary.hpp"
#include "../Environment.hpp"
#include "../Object.hpp"
#include "../String.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Specified how a new window should appear when the system starts a process.
      enum class ProcessWindowStyle {
        /// @brief The normal, visible window style. The system displays a window with Normal style on the screen, in a default location. If a window is visible, the user can supply input to the window and view the window's output. Frequently, an application may initialize a new window to the Hidden style while it customizes the window's appearance, and then make the window style Normal.
        Normal = 0,
        /// @brief The hidden window style. A window can be either visible or hidden. The system displays a hidden window by not drawing it. If a window is hidden, it is effectively disabled. A hidden window can process messages from the system or from other windows, but it cannot process input from the user or display output. Frequently, an application may keep a new window hidden while it customizes the window's appearance, and then make the window style Normal. To use ProcessWindowStyle.Hidden, the ProcessStartInfo.UseShellExecute property must be false.
        Hidden = 1,
        /// @brief The minimized window style. By default, the system reduces a minimized window to the size of its taskbar button and moves the minimized window to the taskbar.
        Minimized = 2,
        /// @brief The maximized window style. By default, the system enlarges a maximized window so that it fills the screen or, in the case of a child window, the parent window's client area. If the window has a title bar, the system automatically moves it to the top of the screen or to the top of the parent window's client area. Also, the system disables the window's sizing border and the window-positioning capability of the title bar so that the user cannot move the window by dragging the title bar.
        Maximized = 3,
      };
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Diagnostics::ProcessWindowStyle> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {
      {(int64)System::Diagnostics::ProcessWindowStyle::Normal, "Normal"},
      {(int64)System::Diagnostics::ProcessWindowStyle::Hidden, "Hidden"},
      {(int64)System::Diagnostics::ProcessWindowStyle::Minimized, "Minimized"},
      {(int64)System::Diagnostics::ProcessWindowStyle::Maximized, "Maximized"},
    };
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
