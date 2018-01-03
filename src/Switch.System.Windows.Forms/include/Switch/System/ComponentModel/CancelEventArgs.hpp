/// @file
/// @brief Contains Switch::System::ComponentModel::CancelEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>

namespace Switch {
  namespace System {
    namespace ComponentModel {
      class export_ CancelEventArgs : public EventArgs {
      public:
        CancelEventArgs() {}
        CancelEventArgs(const CancelEventArgs& ce) : cancel(ce.cancel) {}
        CancelEventArgs(bool cancel) : cancel(cancel) {}

        property_<bool> Cancel {
          get_ {return cancel;},
          set_ {this->cancel = value;}
        };

      private:
        bool cancel = false;
      };
    }
  }
}
