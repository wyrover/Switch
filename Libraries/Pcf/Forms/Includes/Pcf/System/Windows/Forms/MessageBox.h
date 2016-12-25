/// @file
/// @brief Contains Pcf::System::Windows::Forms::MessageBox class.
#pragma once

#include "Button.h"
#include "DialogResult.h"
#include "Form.h"
#include "Label.h"
#include "MessageBoxButtons.h"
#include "MessageBoxIcon.h"
#include "Panel.h"
#include "PictureBox.h"
#include "Screen.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a window or dialog box that makes up an application's user interface.
        class MessageBox : public Form {
        public:
          /// @cond
          ~MessageBox() {}
          /// @endcond

          static DialogResult Show(const string& message);
          static DialogResult Show(const string& message, const string& caption);
          static DialogResult Show(const string& message, const string& caption, MessageBoxButtons buttons);
          static DialogResult Show(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon);

        private:
          MessageBox();

          void OnKeyDown(KeyEventArgs& e) override {
            if (e.KeyCode == Keys::Escape)
              this->OnButtonCancelClick(*this, EventArgs());
           }

          static void CreateButtons(MessageBox& messageBox);
          static Drawing::Size ComputeSize(MessageBox& messageBox);

          void OnButtonAbortClick(const object& sender, const EventArgs& e);
          void OnButtonCancelClick(const object& sender, const EventArgs& e);
          void OnButtonIgnoreClick(const object& sender, const EventArgs& e);
          void OnButtonNoClick(const object& sender, const EventArgs& e);
          void OnButtonOkClick(const object& sender, const EventArgs& e);
          void OnButtonRetryClick(const object& sender, const EventArgs& e);
          void OnButtonYesClick(const object& sender, const EventArgs& e);

          MessageBoxButtons buttons = MessageBoxButtons::OK;
          UniquePointer<PictureBox> icon;
          UniquePointer<Panel> panel;
          UniquePointer<Label> message;
          UniquePointer<Button> buttonAbort;
          UniquePointer<Button> buttonCancel;
          UniquePointer<Button> buttonIgnore;
          UniquePointer<Button> buttonNo;
          UniquePointer<Button> buttonOk;
          UniquePointer<Button> buttonRetry;
          UniquePointer<Button> buttonYes;
        };
      }
    }
  }
}
