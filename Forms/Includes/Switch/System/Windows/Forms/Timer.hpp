/// @file
/// @brief Contains Switch::System::Windows::Forms::Timer class.
#pragma once

#include <Switch/System/EventHandler.hpp>

#include "../../ComponentModel/Component.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        class Timer : public System::ComponentModel::Component {
        public:
          Timer() {}

          /// @cond
          ~Timer() {this->Enabled = false;}
          /// @endcond

          Property<bool> Enabled {
            _get {return this->enabled;},
            _set {this->SetEnabled(value);}
          };
          
          Property<int32> Interval {
            _get {return this->interval;},
            _set {this->SetInterval(value);}
          };
          
          Switch::System::EventHandler Tick;

        private:
          void SetEnabled(bool enabled);
          void SetInterval(int32 interval);
          
          int32 interval = 100;
          bool enabled = false;
          intptr handle = IntPtr::Zero;
          delegate<void> tick = _delegate {
            Tick(*this, System::EventArgs::Empty);
          };
        };
      }
    }
  }
}
