/// @file
/// @brief Contains Switch::System::Windows::Forms::MouseEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/Point.hpp>

#include "MouseButtons.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @cond
        class Control;
        /// @endcond

        class _export MouseEventArgs : public EventArgs {
        public:
          MouseEventArgs() {}

          MouseEventArgs(MouseButtons button, const System::Drawing::Point& location, int32 clicks, int32 delta) : button(button), location(location), clicks(clicks), delta(delta) {}
          MouseEventArgs(MouseButtons button, int32 x, int32 y, int32 clicks, int32 delta) : button(button), location(x, y), clicks(clicks), delta(delta) {}
          
          /// @cond
          MouseEventArgs(const MouseEventArgs& mouseEventArgs) : button(mouseEventArgs.button), location(mouseEventArgs.location), clicks(mouseEventArgs.clicks), delta(mouseEventArgs.delta) {}
          MouseEventArgs& operator =(const MouseEventArgs& mouseEventArgs) {
            this->button = mouseEventArgs.button;
            this->location = mouseEventArgs.location;
            this->clicks = mouseEventArgs.clicks;
            this->delta = mouseEventArgs.delta;
            return *this;
          }
          /// @endcond

          property<MouseButtons, readonly> Button {
            _get {return this->button;}
          };

          property<const System::Drawing::Point&, readonly> Location {
            _get->const System::Drawing::Point& {return this->location;}
          };

          property<int32, readonly> Clicks {
            _get {return this->clicks;}
          };

          property<int32, readonly> Delta {
            _get {return this->delta;}
          };

          property<int32, readonly> X {
            _get {return this->Location().X();}
          };

          property<int32, readonly> Y {
            _get {return this->Location().Y();}
          };

        private:
          MouseButtons button;
          System::Drawing::Point location;
          int32 clicks = 0;
          int32 delta = 0;
        };
      }
    }
  }
}
