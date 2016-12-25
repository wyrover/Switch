/// @file
/// @brief Contains Pcf::System::Windows::Forms::KeyPressEventArgs class.
#pragma once

#include <Pcf/System/EventArgs.h>

#include "Keys.h"

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @cond
        class Control;
        /// @endcond

        class KeyPressEventArgs : public EventArgs {
        public:
          KeyPressEventArgs() {}
          KeyPressEventArgs(char32 keyChar) : keyChar(keyChar), handled(false) {}
          
          /// @cond
          KeyPressEventArgs(const KeyPressEventArgs& keyPressEventArgs): keyChar(keyPressEventArgs.keyChar), handled(keyPressEventArgs.handled) {}
          KeyPressEventArgs& operator =(const KeyPressEventArgs& keyPressEventArgs) {
            this->keyChar = keyPressEventArgs.keyChar;
            this->handled = keyPressEventArgs.handled;
            return *this;
          }
          /// @endcond

          Property<bool> Handled {
            pcf_get {return this->handled;},
            pcf_set {this->handled = value;}
          };

          Property<char32, ReadOnly> KeyChar {
            pcf_get {return this->keyChar;}
          };

        private:
          char32 keyChar = 0;
          bool handled = false;
        };
      }
    }
  }
}
