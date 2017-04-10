/// @file
/// @brief Contains Pcf::System::Drawing::Pen class.
#pragma once

#include <Pcf/System/Object.h>

#include "Drawing2D/DashStyle.h"
#include "Brush.h"
#include "SolidBrush.h"
#include "Color.h"

/// @cond
namespace __OS {
  class DrawingApi;
}
/// @endcond

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    namespace Windows {
      namespace Forms {
        class Control;
      }
    }
    /// @endcond

    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      class pcf_public Pen : public object {
      public:
        Pen() {}

        /// @cond
        ~Pen() { this->Destroy(); }
        Pen(const Pen& pen) : brush(pen.brush), dashStyle(pen.dashStyle), width(pen.width) { this->Create(); }
        Pen& operator=(const Pen& pen) {
          this->brush = pen.brush;
          this->dashStyle = pen.dashStyle;
          this->width = pen.width;
          this->Create();
          return *this;
        }
        /// @endconds

        Pen(const Brush& brush) : brush(as<System::Drawing::Brush>(brush.Clone())) { this->Create(); }

        Pen(const Brush& brush, float width) : brush(as<System::Drawing::Brush>(brush.Clone())), width(width) { this->Create(); }

        Pen(System::Drawing::Color color) : brush(as<System::Drawing::Brush>(RefPtr<SolidBrush>::Create(color))) { this->Create(); }

        Pen(System::Drawing::Color color, float width) : brush(as<System::Drawing::Brush>(RefPtr<SolidBrush>::Create(color))), width(width) { this->Create(); }

        Property<const System::Drawing::Brush&> Brush{
          pcf_get->const System::Drawing::Brush& { return this->brush(); },
          pcf_set {this->brush = as<System::Drawing::Brush>(value.Clone()); }
        };

        Property<System::Drawing::Color, ReadOnly> Color{
          pcf_get{ return as<SolidBrush>(this->brush)().Color(); }
        };

        Property<System::Drawing::Drawing2D::DashStyle> DashStyle {
          pcf_get {return this->dashStyle;},
          pcf_set {
            if (this->dashStyle != value) {
              this->dashStyle = value;
              this->Create();
            }
          }
        };

        Property<float> Width{
          pcf_get {return this->width;},
          pcf_set {this->width = value;}
        };

      private:
        friend class __OS::DrawingApi;
        friend class Windows::Forms::Control;
        intptr GetNativePen() const { return this->pen; }
        void Create();
        void Destroy();
        RefPtr<System::Drawing::Brush> brush  = as<System::Drawing::Brush>(RefPtr<SolidBrush>::Create(System::Drawing::Color::Black()));
        System::Drawing::Drawing2D::DashStyle dashStyle = System::Drawing::Drawing2D::DashStyle::Solid;
        float width = 1;
        intptr pen = IntPtr::Zero;
      };
    }
  }
}
