/// @file
/// @brief Contains Pcf::System::Windows::Forms::Form class.
#pragma once

#include "Button.h"
#include "ContainerControl.h"
#include "DialogResult.h"
#include "FormClosedEventHandler.h"
#include "FormClosingEventHandler.h"
#include "FormStartPosition.h"
#include "KeyEventArgs.h"
#include "MainMenu.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace FormsD {
        /// @brief Represents a window or dialog box that makes up an application's user interface.
        class Form : public ContainerControl {
        public:
          Form();

          Property<const Button&> AcceptButton {
            pcf_get->const Button& {return this->acceptButton();},
            pcf_set {return this->SetAcceptButton(value);}
          };

          Property<const Button&> CancelButton {
            pcf_get->const Button& {return this->cancelButton();},
            pcf_set {return this->SetCancelButton(value);}
          };
          
          Property<bool> KeyPreview {
            pcf_get {return this->keyPreview;},
            pcf_set {this->keyPreview = value;}
          };
          
          Property<bool> MaximizeBox {
            pcf_get {return this->GetMaximizeBox();},
            pcf_set {this->SetMaximizeBox(value);}
          };
          
          Property<MainMenu&> Menu {
            pcf_get->MainMenu& {return this->GetMenu();},
            [&](MainMenu& value) {return this->SetMenu(value);}
          };
          
          Property<FormStartPosition> StartPosition {
            pcf_get {return this->startPosition;},
            pcf_set {this->SetStartPosition(value);}
          };
          
          FormClosingEventHandler FormClosing;
          FormClosedEventHandler FormClosed;

          void CenterToParent();
          
          void CenterToScreen();
          
          void Close() override;

          void Show() override;
          
          virtual DialogResult ShowDialog();
          
         protected:
          virtual void OnFormClosing(FormClosingEventArgs& e) {
            this->FormClosing(*this, e);
          }
        
          virtual void OnFormClosed(const FormClosedEventArgs& e) {
            this->FormClosed(*this, e);
          }
          
          virtual void OnKeyDown(KeyEventArgs& e) override {
            if (this->keyPreview == false)
              return;
            this->Control::KeyDown(*this, e);}

          virtual void OnKeyPress(KeyPressEventArgs& e) override {
            if (this->keyPreview == false)
              return;
            this->Control::KeyPress(*this, e);
          }
          
          virtual void OnKeyUp(KeyEventArgs& e) override {
            if(!this->acceptButton.IsNull() && e.KeyCode == Keys::Enter)
              this->acceptButton().PerformClick();
            if (!this->cancelButton.IsNull() && e.KeyCode == Keys::Escape)
              this->cancelButton().PerformClick();
            if (this->keyPreview == false)
              return;
            this->Control::KeyUp(*this, e);
          }
          
          void SetAcceptButton(const Button& button);
          
          void SetCancelButton(const Button& button);
          
          Drawing::Size GetDecorationSize() const override;
          
          System::Drawing::Size GetDefaultSize() const override {return System::Drawing::Size(300, 300);}

          bool SetFocus(Control& control);
          
          virtual bool GetMaximizeBox() const;
          virtual void SetMaximizeBox(bool maximize);
          
          virtual void SetStartPosition(FormStartPosition startPosition);

          void SetText(const string& text) override;

          MainMenu& GetMenu();
          void SetMenu(MainMenu& mainMenu);
          
          int32 GetMenuHeight() const;

          Reference<Button> acceptButton;
          Reference<Button> cancelButton;
          UniquePointer<MainMenu> menu;
          CloseReason closeReason = CloseReason::None;
          DialogResult dialogResult = DialogResult::OK;
          bool keyPreview = false;
          FormStartPosition startPosition = FormStartPosition::WindowsDefaultLocation;
          mutable int32 borderWidth;
          mutable int32 titleHeight;
        };
      }
    }
  }
}
