/// @file
/// @brief Contains Pcf::System::Drawing::Font class.
#pragma once

#include <Pcf/System/String.h>

#include "FontFamily.h"
#include "FontStyle.h"

namespace Pcf {
  namespace System {
    namespace Drawing {
      class Font : public object {
      public:
        Font() {}

        Font(const Font& font) : name(font.name), style(font.style), hfont(font.hfont), size(font.size) {}

        Font(const string& name) {this->FromName(name, this->size, this->style);}

        Font(const string& name, float size) {this->FromName(name, size, this->style);}

        Font(const string& name, float size, const FontStyle& style) {this->FromName(name, size, style);}

        Font(const FontFamily& fontFamily) {this->FromName(fontFamily.Name, this->size, this->style);}

        Property<const string&, ReadOnly> Name {
          pcf_get->const string& {return this->name;}
        };

        Property<FontStyle, ReadOnly> Style {
          pcf_get {return this->style;}
        };

        Property<float, ReadOnly> Size {
          pcf_get {return this->size;}
        };

        bool IsStyleAvaible(const FontStyle& style) const {
          if (style == FontStyle::Regular)
            return true;
          return FontStyle(int(this->style) & int(style)) == style;
        }

        static Font FromHFont(intptr hfont);

        intptr ToHFont() const {return this->hfont;}
  
      private:
        void FromName(const string& name, float size, FontStyle style);

        string name;
        FontStyle style = FontStyle::Regular;
        intptr hfont = 0;
        float size = 14.0f;
      };
    }
  }
}
