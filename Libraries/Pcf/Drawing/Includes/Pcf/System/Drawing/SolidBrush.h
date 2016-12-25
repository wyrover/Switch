/// @file
/// @brief Contains Pcf::System::Drawing::SolidBrush class.
#pragma once

#include "Brush.h"
#include "Color.h"

namespace Pcf {
  namespace System {
    namespace Drawing {
      class SolidBrush : public Brush {
      public:
        SolidBrush(const System::Drawing::Color& color) : color(color) {}
        SolidBrush(const SolidBrush& solidBrush) : color(solidBrush.color) {}
        
        Property<System::Drawing::Color, ReadOnly> Color {
          pcf_get {return this->color;}
        };

      private:
        System::Drawing::Color color;
      };
    }
  }
}
