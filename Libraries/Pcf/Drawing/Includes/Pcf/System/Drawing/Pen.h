/// @file
/// @brief Contains Pcf::System::Drawing::Pen class.
#pragma once

#include <Pcf/System/Object.h>

#include "Brush.h"
#include "SolidBrush.h"
#include "Color.h"

namespace Pcf {
  namespace System {
    namespace Drawing {
      class Pen : public object {
      public:
        Pen() {}

        Pen(const Pen& pen) : brush(pen.brush), width(pen.width) {}

        Pen(const Brush& brush) : brush(as<SolidBrush>(brush)) {}

        Pen(System::Drawing::Color color) : brush(color) {}

        Pen(System::Drawing::Color color, float width) : brush(color), width(width) {}

        Property<System::Drawing::Color, ReadOnly> Color {
          pcf_get {return this->brush.Color();}
        };

        Property<float, ReadOnly> Width {
          pcf_get {return this->width;}
        };

      private:
        SolidBrush brush = System::Drawing::Color::Black;
        float width = 1;
        /// @cond
        /// @endcond
      };
    }
  }
}
