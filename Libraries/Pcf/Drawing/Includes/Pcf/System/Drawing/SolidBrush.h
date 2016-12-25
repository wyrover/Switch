/// @file
/// @brief Contains Pcf::System::Drawing::SolidBrush class.
#pragma once

#include "Brush.h"
#include "Color.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      class SolidBrush : public Brush {
      public:
        SolidBrush(const System::Drawing::Color& color) : color(color) {}
        SolidBrush(const SolidBrush& solidBrush) : color(solidBrush.color) {}
        
        Property<System::Drawing::Color, ReadOnly> Color {
          pcf_get {return this->color;}
        };

      private:
        System::Drawing::Color color;
      };
    }
  }
}
