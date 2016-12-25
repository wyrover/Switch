/// @file
/// @brief Contains Pcf::System::Drawing::Imaging::ColorPalette class.
#pragma once

#include <Pcf/System/Object.h>
#include <Pcf/System/Array.h>
#include "../Color.h"

namespace Pcf {
  namespace System {
    namespace Drawing {
      /// @cond
      class Bmp;
      class Image;
      /// @endcond
      namespace Imaging {
        class ColorPalette : public object {
        public:
          /// @cond
          ColorPalette(const ColorPalette& colorPalette) : entries(colorPalette.entries), flags(colorPalette.flags) {}
          /// @endcond
          Property<Array<Color>, ReadOnly> Entries {
            pcf_get {return this->entries;}
          };

          Property<int32, ReadOnly> Falgs {
            pcf_get {return this->flags;}
          };

        private:
          friend class Pcf::System::Drawing::Bmp;
          friend class Pcf::System::Drawing::Image;
          ColorPalette() : flags(0) {}

          Array<Color> entries;
          int32 flags;
        };
      }
    }
  }
}
