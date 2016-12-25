/// @file
/// @brief Contains Pcf::System::Drawing::FontFamily class.
#pragma once

#include <Pcf/System/Object.h>
#include <Pcf/System/String.h>
#include "FontStyle.h"

namespace Pcf {
  namespace System {
    namespace Drawing {
      class FontFamily : public object {
      public:
        FontFamily() {}
        FontFamily(const string& name) : name(name) {}

        bool IsStyleAvaible(FontStyle style) const {
          return ((int32)this->style & (int32)style) == (int32)style;
        }
        
        /// @cond
        FontFamily(const string& name, int32 id) : name(name), id(id) {}
        FontFamily(const FontFamily& fontFamily) : name(fontFamily.name), id(fontFamily.id) {}
        FontFamily& operator =(const FontFamily& fontFamily) {
          this->name = fontFamily.name;
          this->id = fontFamily.id;
          return *this;
        }
        /// @endcond

        Property<const string&, ReadOnly> Name {
          pcf_get->const string& {return this->name;}
        };

        static Property<Array<FontFamily>, ReadOnly> Families;

        const static Property<FontFamily, ReadOnly> GenericMonospace;

        const static Property<FontFamily, ReadOnly> GenericSansSerif;

        const static Property<FontFamily, ReadOnly> GenericSerif;

        /// @cond
        static Array<FontFamily> __Families__();
        /// @endcond

      private:
        string name;
        int32 id = 0;
        FontStyle style = FontStyle::Regular;
      };
    }
  }
}
