/// @file
/// @brief Contains Pcf::System::Windows::Forms::PaintEventArgs class.
#pragma once

#include <Pcf/System/EventArgs.h>
#include <Pcf/System/Drawing/Graphics.h>
#include <Pcf/System/Drawing/Rectangle.h>

#include "Keys.h"

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @cond
        class Control;
        /// @endcond

        class PaintEventArgs : public EventArgs {
        public:
          PaintEventArgs() {}
          PaintEventArgs(const System::Drawing::Rectangle& clipRectangle, System::Drawing::Graphics& graphics) : clipRectangle(clipRectangle), graphics(&graphics) {}
          /// @cond
          PaintEventArgs(const PaintEventArgs& paintEventArgs) : clipRectangle(paintEventArgs.clipRectangle), graphics(paintEventArgs.graphics) {}
          PaintEventArgs& operator =(const PaintEventArgs& paintEventArgs) {
            this->clipRectangle = paintEventArgs.clipRectangle;
            this->graphics = paintEventArgs.graphics;
            return *this;
          }
          /// @endcond

          Property<const System::Drawing::Rectangle&, ReadOnly> ClipRectangle {
            pcf_get->const System::Drawing::Rectangle& {return this->clipRectangle;}
          };
          
          Property<System::Drawing::Graphics&, ReadOnly> Graphics {
            pcf_get->System::Drawing::Graphics& {return *this->graphics;}
          };

        private:
          System::Drawing::Rectangle clipRectangle;
          System::Drawing::Graphics* graphics = null;
        };
      }
    }
  }
}
