/// @file
/// @brief Contains Switch::System::ComponentModel::CancelEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>

namespace Switch {
  namespace System {
    namespace ComponentModel {
      class _export CancelEventArgs : public EventArgs {
      public:
        CancelEventArgs() {}
        CancelEventArgs(const CancelEventArgs& ce) : cancel(ce.cancel) {}
        CancelEventArgs(bool cancel) : cancel(cancel) {}
        
        _property<bool> Cancel {
          _get {return cancel;},
          _set {this->cancel = value;}
        };
        
      private:
        bool cancel = false;
      };
    }
  }
}
