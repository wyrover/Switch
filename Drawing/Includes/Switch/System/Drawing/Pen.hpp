/// @file
/// @brief Contains Switch::System::Drawing::Pen class.
#pragma once

#include <Switch/System/Object.hpp>

#include "Drawing2D/DashStyle.hpp"
#include "Brush.hpp"
#include "SolidBrush.hpp"
#include "Color.hpp"

/// @cond
namespace __OS {
  class DrawingApi;
}
/// @endcond

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
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
      class _public Pen : public object {
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

        Pen(System::Drawing::Color color) : brush(as<System::Drawing::Brush>(ref_new<SolidBrush>(color))) { this->Create(); }

        Pen(System::Drawing::Color color, float width) : brush(as<System::Drawing::Brush>(ref_new<SolidBrush>(color))), width(width) { this->Create(); }

        Property<const System::Drawing::Brush&> Brush{
          _get->const System::Drawing::Brush& { return this->brush(); },
          _set {this->brush = as<System::Drawing::Brush>(value.Clone()); }
        };

        Property<System::Drawing::Color, ReadOnly> Color{
          _get{ return as<SolidBrush>(this->brush)().Color(); }
        };

        Property<System::Drawing::Drawing2D::DashStyle> DashStyle {
          _get {return this->dashStyle;},
          _set {
            if (this->dashStyle != value) {
              this->dashStyle = value;
              this->Create();
            }
          }
        };

        Property<float> Width{
          _get {return this->width;},
          _set {this->width = value;}
        };

      private:
        friend class __OS::DrawingApi;
        friend class Windows::Forms::Control;
        intptr GetNativePen() const { return this->pen; }
        void Create();
        void Destroy();
        refptr<System::Drawing::Brush> brush  = as<System::Drawing::Brush>(ref_new<SolidBrush>(System::Drawing::Color::Black()));
        System::Drawing::Drawing2D::DashStyle dashStyle = System::Drawing::Drawing2D::DashStyle::Solid;
        float width = 1;
        intptr pen = IntPtr::Zero;
      };
    }
  }
}
