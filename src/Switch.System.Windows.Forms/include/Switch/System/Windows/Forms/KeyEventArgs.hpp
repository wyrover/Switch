/// @file
/// @brief Contains Switch::System::Windows::Forms::KeyEventArgs class.
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
        
        /// @brief Provides data for the KeyDown or KeyUp event.
        /// @remarks A KeyEventArgs, which specifies the key the user pressed and whether any modifier keys (CTRL, ALT, and SHIFT) were pressed at the same time, is passed with each KeyDown or KeyUp event.
        /// @remarks The KeyDown event occurs when the user presses any key. The KeyUp event occurs when the user releases the key. Duplicate KeyDown events occur each time the key repeats, if the key is held down, but only one KeyUp event is generated when the user releases the key.
        /// @remarks The KeyPress event also occurs when a key is pressed. A KeyPressEventArgs is passed with each KeyPress event, and specifies the character that was composed as a result of each key press.
        /// @remarks For information about the event model, see Handling and Raising Events.
        class _export KeyEventArgs : public EventArgs {
        public:
          /// @brief Initializes a new instance of the KeyEventArgs class.
          KeyEventArgs() {}
          /// @brief Initializes a new instance of the KeyEventArgs class for the specified keys.
          /// @param keyData A Keys representing the key that was pressed, combined with any modifier flags that indicate which CTRL, SHIFT, and ALT keys were pressed at the same time. Possible values are obtained be applying the bitwise OR (|) operator to constants from the Keys enumeration.
          KeyEventArgs(const Keys& keyData) : keyData(keyData), handled(false), suppressKeyPress(false) {}
          
          /// @cond
          KeyEventArgs(const KeyEventArgs& keyEventArgs) : keyData(keyEventArgs.keyData), handled(keyEventArgs.handled), suppressKeyPress(keyEventArgs.suppressKeyPress) {}
          KeyEventArgs& operator =(const KeyEventArgs& keyEventArgs) {
            this->keyData = keyEventArgs.keyData;
            this->handled = keyEventArgs.handled;
            this->suppressKeyPress = keyEventArgs.suppressKeyPress;
            return *this;
          }
          /// @endcond
          
          _property<bool, _readonly> Alt {
            _get {return Enum<Keys>(this->keyData).HasFlag(Keys::Alt);}
          };
          
          _property<bool, _readonly> Command {
            _get {return Enum<Keys>(this->keyData).HasFlag(Keys::Command);}
          };
          
          _property<bool, _readonly> Control {
            _get {return Enum<Keys>(this->keyData).HasFlag(Keys::Control);}
          };
          
          _property<bool> Handled {
            _get {return this->handled;},
            _set {this->handled = value;}
          };
          
          _property<Keys, _readonly> KeyCode {
            _get {return Keys(this->keyData & Keys::KeyCode);}
          };
          
          /// @brief Gets the key data for a KeyDown or KeyUp event.
          /// @return A Keys representing the key code for the key that was pressed, combined with modifier flags that indicate which combination of CTRL, SHIFT, and ALT keys was pressed at the same time.
          /// @remarks You can use constants from Keys to extract information from the KeyData property. Use the bitwise AND operator to compare data returned by KeyData with constants in Keys to obtain information about which keys the user pressed. To determine whether a specific modifier key was pressed, use the Control, Shift, and Alt properties.
          _property<Keys, _readonly> KeyData {
            _get {return this->keyData;}
          };
          
          _property<int32, _readonly> KeyValue {
            _get {return (int32)(this->keyData) & 0xFFFF;}
          };
          
          _property<Keys, _readonly> Modifiers {
            _get {return Keys(this->keyData & Keys::Modifiers);}
          };
          
          _property<bool, _readonly> Shift {
            _get {return Enum<Keys>(this->keyData).HasFlag(Keys::Shift);}
          };
          
          _property<bool> SuppressKeyPress {
            _get {return this->suppressKeyPress;},
            _set {this->suppressKeyPress = value;}
          };
          
        private:
          Keys keyData;
          bool handled = false;
          bool suppressKeyPress = false;
        };
      }
    }
  }
}
