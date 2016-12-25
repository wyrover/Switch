/// @file
/// @brief Contains Pcf::System::Windows::Forms::OpenFileDialog class.
#pragma once

#include <Pcf/System/Array.h>
#include <Pcf/System/IO/Path.h>

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
      namespace FormsD {
        class OpenFileDialog : public System::ComponentModel::Component {
        public:
          using Handle = void*;
          
          OpenFileDialog();
          
          /// @cond
          ~OpenFileDialog();
          /// @endcond
          
          Property<string> InitialDirectory {
            pcf_get {return this->GetInitialDirectory();},
            pcf_set {this->SetInitialDirectory(value);}
          };

          Property<string, ReadOnly> FileName {
            pcf_get {return this->GetFileName();}
          };

          Property<Array<string>, ReadOnly> FileNames {
            pcf_get {return this->GetFileNames();}
          };
          
          Property<string> Filter {
            pcf_get {return this->GetFilter();},
            pcf_set {this->SetFilter(value);}
          };

          Property<int32> FilterIndex {
            pcf_get {return this->GetFilterIndex();},
            pcf_set {this->SetFilterIndex(value);}
          };

          Property<bool> Multiselect {
            pcf_get {return this->GetMultiselect();},
            pcf_set {this->SetMultiselect(value);}
          };

          Property<string, ReadOnly> SafeFileName {
            pcf_get {return Pcf::System::IO::Path::GetFileName(this->FileName());}
          };

          Property<Array<string>, ReadOnly> SafeFileNames {
            pcf_get {
              System::Collections::Generic::List<string> fileNames;
              for(string fullFileName : this->GetFileNames())
                fileNames.Add(Pcf::System::IO::Path::GetFileName(fullFileName));

              return fileNames.ToArray();
            }
          };

          Property<string> Title {
            pcf_get {return this->GetTitle();},
            pcf_set {this->SetTitle(value);}
          };

          DialogResult ShowDialog();
          
          ComponentModel::CancelEventHandler Click;

        private:
          OpenFileDialog(const OpenFileDialog& ofd) = delete;
          OpenFileDialog& operator =(const OpenFileDialog& ofd) = delete;
          string GetInitialDirectory() const;
          void SetInitialDirectory(const string& directory);
          string GetFileName() const;
          Array<string> GetFileNames() const;
          string GetFilter() const;
          void SetFilter(const string& filter);
          int32 GetFilterIndex() const;
          void SetFilterIndex(int32 index);
          bool GetMultiselect() const;
          void SetMultiselect(bool multiselect);
          string GetTitle() const;
          void SetTitle(const string& title);
          Handle handle;
        };
      }
    }
  }
}
