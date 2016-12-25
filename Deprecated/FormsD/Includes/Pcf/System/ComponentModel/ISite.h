/// @file
/// @brief Contains Pcf::System::ComponentModel::ISite interface.
#pragma once

#include <Pcf/Interface.h>

#include "IComponent.h"

namespace Pcf {
  namespace System {
    namespace ComponentModel {
      class IComponenent;
      /// @interface ISite
      /// @brief Provides functionality required by sites.
      class ISite pcf_interface {
      public:
        /// @brief A valid value for this property (that is, the value is not null) indicates that the component has been added to a container.
        virtual const IComponenent& GetComponent() const = 0;
      };
    }
  }
}
