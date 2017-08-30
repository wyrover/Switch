/// @file
/// @brief Contains Switch::System::Drawing::FontFamily class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include "FontStyle.hpp"
#include "Text/GenericFontFamilies.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Defines a group of type faces having a similar basic design and certain variations in styles. This class cannot be inherited.
      class pcf_public FontFamily final : public object {
      public:
        FontFamily(const string& name);
        FontFamily(System::Drawing::Text::GenericFontFamilies genericFamily);

        /// @cond
        FontFamily() {}
        FontFamily(const FontFamily& fontFamily) : data(fontFamily.data) {}
        FontFamily(intptr handle) { this->data().handle = handle; }
        ~FontFamily();
        /// @endcond

        /// @brief Returns an array that contains all the FontFamily objects associated with the current graphics context.
        /// @return Array<FontFamily> An array of FontFamily objects associated with the current graphics context.
        static Property<Array<FontFamily>, ReadOnly> Families;

        static Property<FontFamily, ReadOnly> GenericMonospace;

        static Property<FontFamily, ReadOnly> GenericSansSerif;

        static Property<FontFamily, ReadOnly> GenericSerif;

        Property<string, ReadOnly> Name{
          pcf_get {return this->GetName();}
        };

        bool IsStyleAvailable(FontStyle style) const;
        
      private:
        string GetName() const;
        struct FontFamilyData {
          intptr handle = 0;
        };
        refptr<FontFamilyData> data = pcf_new<FontFamilyData>();
      };
    }
  }
}
