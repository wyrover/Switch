/// @file
/// @brief Contains Switch::System::Drawing::FontStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types,
  /// events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief The System::Drawing::Text namespace provides advanced GDI+ typography functionality.
      namespace Text {
        /// @brief Specifies a generic FontFamily object.
        enum class GenericFontFamilies {
          /// @brief A generic Serif FontFamily object.
          Serif,
          /// @brief A generic SansSerif FontFamily object.
          SansSerif,
          /// @brief A generic Monospace FontFamily object.
          Monospace
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Drawing::Text::GenericFontFamilies> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Drawing::Text::GenericFontFamilies::Serif, "Serif"}, {(int64)System::Drawing::Text::GenericFontFamilies::SansSerif, "SansSerif"}, {(int64)System::Drawing::Text::GenericFontFamilies::Monospace, "Monospace"},};
    flags = false;
  }
};
/// @endcond

using namespace Switch;
