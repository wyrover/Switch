/// @file
/// @brief Contains Pcf::System::Windows::Forms::PictureBox class.
#pragma once

#include <Pcf/System/Drawing/Image.h>

#include "BorderStyle.h"
#include "Control.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace FormsD {
        /// @brief Represents a standard Windows label.
        class PictureBox : public Control {
        public:
          PictureBox();

          /// @cond
          ~PictureBox();
          /// @endcond

          Property<System::Windows::FormsD::BorderStyle> BorderStyle {
            pcf_get {return this->GetBorderStyle();},
            pcf_set {this->SetBorderStyle(value);}
          };
          
          Property<const System::Drawing::Image&> Image {
            pcf_get->const System::Drawing::Image& {return this->image;},
            pcf_set {
              this->SetImage(value);
            }
          };

        private:
          System::Windows::FormsD::BorderStyle GetBorderStyle() const;
          void SetBorderStyle(System::Windows::FormsD::BorderStyle borderStyle);
          void SetImage(const System::Drawing::Image& image);
          
          System::Drawing::Image image;
          void* handle = null;
          bool transparent = false;
        };
      }
    }
  }
}
