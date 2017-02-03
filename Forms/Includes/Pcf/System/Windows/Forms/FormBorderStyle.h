/// @file
/// @brief Contains Pcf::System::Windows::Forms::BorderStyle enum.
#pragma once

#include <Pcf/System/Enum.h>

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies the border styles for a form.
        enum class FormBorderStyle {
          /// @brief No border.
          None,
          /// @brief A fixed, single-line border.
          FixedSingle,
          /// @brief A fixed, three-dimensional border.
          Fixed3D,
          /// @brief A thick, fixed dialog-style border.
          FixedDialog = 3,
          /// @brief A resizable border.
          Sizable = 4,
          /// @brief A tool window border
          FixedToolWindow = 5,
          /// @brief A resizable tool window border.
          SizableToolWindow = 6,
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Windows::Forms::FormBorderStyle > {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::Forms::FormBorderStyle::None, "None"}, {(int64)System::Windows::Forms::FormBorderStyle::FixedSingle, "FixedSingle"}, {(int64)System::Windows::Forms::FormBorderStyle::Fixed3D, "Fixed3D"}, {(int64)System::Windows::Forms::FormBorderStyle::FixedDialog, "FixedDialog"}, {(int64)System::Windows::Forms::FormBorderStyle::Sizable, "Sizable"}, {(int64)System::Windows::Forms::FormBorderStyle::FixedToolWindow, "FixedToolWindow"}, {(int64)System::Windows::Forms::FormBorderStyle::Fixed3D, "SizableToolWindow"},};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
