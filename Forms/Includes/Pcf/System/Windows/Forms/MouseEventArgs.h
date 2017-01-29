/// @file
/// @brief Contains Pcf::System::Windows::Forms::MouseEventArgs class.
#pragma once

#include <Pcf/System/EventArgs.h>
#include <Pcf/System/Drawing/Point.h>

#include "MouseButtons.h"

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @cond
        class Control;
        /// @endcond

        class pcf_public MouseEventArgs : public EventArgs {
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

          Property<MouseButtons, ReadOnly> Button {
            pcf_get {return this->button;}
          };

          Property<const System::Drawing::Point&, ReadOnly> Location {
            pcf_get->const System::Drawing::Point& {return this->location;}
          };

          Property<int32, ReadOnly> Clicks {
            pcf_get {return this->clicks;}
          };

          Property<int32, ReadOnly> Delta {
            pcf_get {return this->delta;}
          };

          Property<int32, ReadOnly> X {
            pcf_get {return this->Location().X();}
          };

          Property<int32, ReadOnly> Y {
            pcf_get {return this->Location().Y();}
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
