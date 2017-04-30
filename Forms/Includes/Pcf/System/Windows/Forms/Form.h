/// @file
/// @brief Contains Pcf::System::Windows::Forms::Form class.
#pragma once

#include <Pcf/System/Diagnostics/Debug.h>
#include "ContainerControl.h"
#include "FormBorderStyle.h"
#include "FormClosedEventHandler.h"
#include "FormClosingEventHandler.h"
#include "FormStartPosition.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a window or dialog box that makes up an application's user interface.
        class pcf_public Form : public ContainerControl {
        public:
          Form() {
            this->visible = false;
            this->SetStyle(ControlStyles::UserPaint, false);
            //this->BackColor = System::Drawing::SystemColors::Window;
          }

          Property<System::Windows::Forms::FormBorderStyle> FormBorderStyle {
            pcf_get{return this->formBorderStyle;},
            pcf_set{this->formBorderStyle = value;}
          };
          
          Property<bool> MaximizeBox {
            pcf_get {return this->maximizeBox;},
            pcf_set {this->maximizeBox = value;}
          };
          
          Property<bool> MinimizeBox {
            pcf_get {return this->minimizeBox;},
            pcf_set {this->minimizeBox = value;}
          };
          
		      Property<FormStartPosition> StartPosition{
			      pcf_get{return this->startPosition;},
			      pcf_set{this->startPosition = value;}
		      };

          void Close() override;

          void WndProc(Message& message) override;

          FormClosedEventHandler FormClosed;

          FormClosingEventHandler FormClosing;

        protected:
          void CreateHandle() override;
          System::Drawing::Size GetDefaultSize() const override { return System::Drawing::Size(300, 300); }

          virtual void OnFormClosed(const FormClosedEventArgs& e) { this->FormClosed(*this, e); }
          virtual void OnFormClosing(FormClosingEventArgs& e) { this->FormClosing(*this, e); }

          /// @cond
          System::Windows::Forms::FormBorderStyle formBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
          bool maximizeBox = true;
          bool minimizeBox = true;
          System::Windows::Forms::FormStartPosition startPosition = FormStartPosition::WindowsDefaultLocation;
          System::Collections::Generic::Dictionary<int32, Action<Message&>> messageActions;
          /// @endcond

        private:
          void WmClose(Message& message);
        };
      }
    }
  }
}
