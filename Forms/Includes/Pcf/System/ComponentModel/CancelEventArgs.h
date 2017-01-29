/// @file
/// @brief Contains Pcf::System::ComponentModel::CancelEventArgs class.
#pragma once

#include <Pcf/System/EventArgs.h>

namespace Pcf {
  namespace System {
    namespace ComponentModel {
      class pcf_public CancelEventArgs : public EventArgs {
      public:
        CancelEventArgs() {}
        CancelEventArgs(const CancelEventArgs& ce) : cancel(ce.cancel) {}
        CancelEventArgs(bool cancel) : cancel(cancel) {}

        Property<bool> Cancel {
          pcf_get {return cancel;},
          pcf_set {this->cancel = value;}
        };
 
      private:
        bool cancel = false;
      };
    }
  }
}
