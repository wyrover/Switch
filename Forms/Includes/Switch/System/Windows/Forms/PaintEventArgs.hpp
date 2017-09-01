/// @file
/// @brief Contains Switch::System::Windows::Forms::PaintEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/Graphics.hpp>
#include <Switch/System/Drawing/Rectangle.hpp>

#include "Keys.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @cond
        class Control;
        /// @endcond

        class _public PaintEventArgs : public EventArgs {
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
            _get->const System::Drawing::Rectangle& {return this->clipRectangle;}
          };
          
          Property<System::Drawing::Graphics&, ReadOnly> Graphics {
            _get->System::Drawing::Graphics& {return *this->graphics;}
          };

        private:
          System::Drawing::Rectangle clipRectangle;
          System::Drawing::Graphics* graphics = null;
        };
      }
    }
  }
}
