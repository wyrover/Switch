/// @file
/// @brief Contains Pcf::System::Windows::Forms::Timer class.
#pragma once

#include <Pcf/System/EventHandler.h>

#include "../../ComponentModel/Component.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace FormsD {
        class Timer : public System::ComponentModel::Component {
        public:
          Timer() {}

          /// @cond
          ~Timer() {this->Enabled = false;}
          /// @endcond

          Property<bool> Enabled {
            pcf_get {return this->enabled;},
            pcf_set {this->SetEnabled(value);}
          };
          
          Property<int32> Interval {
            pcf_get {return this->interval;},
            pcf_set {this->SetInterval(value);}
          };
          
          Pcf::System::EventHandler Tick;

        private:
          void SetEnabled(bool enabled);
          void SetInterval(int32 interval);
          
          int32 interval = 100;
          bool enabled = false;
          
          static void TimerTick(void* timer);
        };
      }
    }
  }
}
