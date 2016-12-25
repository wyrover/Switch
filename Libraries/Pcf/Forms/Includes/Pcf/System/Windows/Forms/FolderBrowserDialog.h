/// @file
/// @brief Contains Pcf::System::Windows::Forms::FolderBrowserDialog class.
#pragma once

#include "../../ComponentModel/Component.h"
#include "../../ComponentModel/CancelEventHandler.h"
#include "DialogResult.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace Forms {
        class FolderBrowserDialog : public System::ComponentModel::Component {
        public:
          using Handle = void*;
          FolderBrowserDialog();

          /// @cond
          ~FolderBrowserDialog();
          /// @endcond

          Property<string> Description {
            pcf_get {return this->GetDescription();},
            pcf_set {this->SetDescription(value);}
          };

          Property<string> SelectedPath {
            pcf_get {return this->GetSelectedPath();},
            pcf_set {this->SetSelectedPath(value);}
          };

          Property<bool> ShowNewFolderButton {
            pcf_get {return this->GetShowNewFolderButton();},
            pcf_set {this->SetShowNewFolderButton(value);}
          };

          DialogResult ShowDialog();

          ComponentModel::CancelEventHandler Click;

        private:
          FolderBrowserDialog(const FolderBrowserDialog&) = delete;
          FolderBrowserDialog& operator =(const FolderBrowserDialog&) = delete;
          string GetDescription() const;
          void SetDescription(const string& description);
          string GetSelectedPath() const;
          void SetSelectedPath(const string& description);
          bool GetShowNewFolderButton() const;
          void SetShowNewFolderButton(bool show);
          Handle handle;
        };
      }
    }
  }
}
