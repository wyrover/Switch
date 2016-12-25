/// @file
/// @brief Contains Pcf::System::Windows::Forms::InvalidateEventArgs class.
#pragma once

#include <Pcf/System/EventArgs.h>
#include <Pcf/System/Drawing/Rectangle.h>

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Provides data for the Invalidated event.
        class InvalidateEventArgs : public EventArgs {
        public:
          /// @brief Initializes a new instance of the InvalidateEventArgs class.
          InvalidateEventArgs() {}
          /// @brief Initializes a new instance of the InvalidateEventArgs class.
          /// @param invalidRect The Rectangle that contains the invalidated window area.
          InvalidateEventArgs(const Pcf::System::Drawing::Rectangle& invalidRect) : invalidRect(invalidRect) {}

          /// @brief Gets the Rectangle that contains the invalidated window area.
          /// @return The invalidated window area.
          const Pcf::System::Drawing::Rectangle& InvalidRect() const { return this->invalidRect; }

        private:
          Pcf::System::Drawing::Rectangle invalidRect;
        };
      }
    }
  }
}
