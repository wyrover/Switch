/// @file
/// @brief Contains Switch::System::Windows::Forms::KeyPressEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>

#include "Keys.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @cond
        class Control;
        /// @endcond

        class _public KeyPressEventArgs : public EventArgs {
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

          property<bool> Handled {
            _get {return this->handled;},
            _set {this->handled = value;}
          };

          property<char32, readonly> KeyChar {
            _get {return this->keyChar;}
          };

        private:
          char32 keyChar = 0;
          bool handled = false;
        };
      }
    }
  }
}
