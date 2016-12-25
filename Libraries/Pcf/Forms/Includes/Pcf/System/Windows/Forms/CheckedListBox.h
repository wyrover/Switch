/// @file
/// @brief Contains Pcf::System::Windows::Forms::CheckedListBox class.
#pragma once

#include <Pcf/System/Delegate.h>
#include <Pcf/System/Collections/Generic/List.h>

#include "BorderStyle.h"
#include "ListControl.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a standard Windows label.
        class CheckedListBox : public ListControl {
        public:
          class ObjectCollection : public System::Collections::Generic::List<SharedPointer<object>> {
          public:
            using ListBoxItemEventHandler = TEventHandler<const object&>;
            using AddListBoxItemEventHandler = System::Delegate<void, const object&, const object&, bool>;
            
            template<typename T>
            void Add(const T& value) {
              System::Collections::Generic::List<SharedPointer<object>>::Add(SharedPointer<object>(new T(value)));
              ListBoxItemAdded(*this, value, false);
            }
            
            template<typename T>
            void Add(const T& value, bool checked) {
              System::Collections::Generic::List<SharedPointer<object>>::Add(SharedPointer<object>(new T(value)));
              ListBoxItemAdded(*this, value, checked);
            }
            
            void Add(const char* value) {
              System::Collections::Generic::List<SharedPointer<object>>::Add(new string(value));
              ListBoxItemAdded(*this, string(value), false);
            }
            
            void Add(const char* value, bool checked) {
              System::Collections::Generic::List<SharedPointer<object>>::Add(new string(value));
              ListBoxItemAdded(*this, string(value), checked);
            }
            
            void Add(const string& value) {
              System::Collections::Generic::List<SharedPointer<object>>::Add(new string(value));
              ListBoxItemAdded(*this, value, false);
            }
            
            void Add(const string& value, bool checked) {
              System::Collections::Generic::List<SharedPointer<object>>::Add(new string(value));
              ListBoxItemAdded(*this, value, checked);
            }
            
            void Add(const SharedPointer<object>& value) {
              System::Collections::Generic::List<SharedPointer<object>>::Add(value);
              ListBoxItemAdded(*this, *value, false);
            }
            
            void Add(const SharedPointer<object>& value, bool checked) {
              System::Collections::Generic::List<SharedPointer<object>>::Add(value);
              ListBoxItemAdded(*this, *value, checked);
            }
            
            template<typename T>
            void AddRange(const System::Collections::Generic::IEnumerable<T>& values) {
              for (T value : values)
                Add(value);
            }
            
            void AddRange(const InitializerList<const char*>& values) {
              for (const char* value : values)
                Add(value);
            }
            
            void AddRange(const System::Collections::Generic::IEnumerable<const char*>& values) {
              for (const char* value : values)
                Add(value);
            }
            
            void AddRange(const System::Collections::Generic::IEnumerable<string>& values) {
              for (string value : values)
                Add(value);
            }
            
            void AddRange(const System::Collections::Generic::IEnumerable<SharedPointer<object>>& values) {
              for (SharedPointer<object> value : values)
                Add(value);
            }
            
            void Clear() {
              System::Collections::Generic::List<SharedPointer<object>>::Clear();
              ListBoxItemCleared(*this, *this);
            }
            
            int32 IndexOf(const SharedPointer<object>& value) const {
              return IndexOf(value->ToString());
            }
            
            int32 IndexOf(const SharedPointer<object>& value, int32 startIndex) const {
              return IndexOf(value->ToString(), startIndex);
            }
            
            int32 IndexOf(const SharedPointer<object>& value, int32 startIndex, int32 length) const {
              return IndexOf(value->ToString(), startIndex, length);
            }
            
            int32 IndexOf(const object& value) const {
              return IndexOf(value.ToString());
            }
            
            int32 IndexOf(const string& value) const {
              int32 index = 0;
              for (SharedPointer<object> item : *this) {
                if (item->ToString() == value) return index;
                index++;
              }
              return -1;
            }
            
            int32 IndexOf(const string& value, int32 startIndex) const {
              int32 index = 0;
              for (SharedPointer<object> item : *this) {
                if (item->ToString() == value) return index;
                index++;
              }
              return -1;
            }
            
            int32 IndexOf(const string& value, int32 startIndex, int32 length) const {
              int32 index = 0;
              for (SharedPointer<object> item : *this) {
                if (item->ToString() == value) return index;
                index++;
              }
              return -1;
            }
            
            template<typename T>
            bool Remove(const T& value) {
              Int32 index = IndexOf(value.ToString());
              if (index < 0) return false;
              System::Collections::Generic::List<SharedPointer<object>>::RemoveAt(index);
              ListBoxItemRemoved(*this, index);
              return true;
            }
            
            bool Remove(const char* value) {
              Int32 index = IndexOf(value);
              if (index < 0) return false;
              System::Collections::Generic::List<SharedPointer<object>>::RemoveAt(index);
              ListBoxItemRemoved(*this, index);
              return true;
            }
            
            bool Remove(const string& value) {
              Int32 index = IndexOf(value);
              if (index < 0) return false;
              System::Collections::Generic::List<SharedPointer<object>>::RemoveAt(index);
              ListBoxItemRemoved(*this, index);
              return true;
            }
            
            bool Remove(const SharedPointer<object>& value) {
              Int32 index = IndexOf(value);
              if (index < 0) return false;
              System::Collections::Generic::List<SharedPointer<object>>::RemoveAt(index);
              ListBoxItemRemoved(*this, index);
              return true;
            }
            
            AddListBoxItemEventHandler ListBoxItemAdded;
            ListBoxItemEventHandler ListBoxItemCleared;
            ListBoxItemEventHandler ListBoxItemRemoved;
          };
          
          CheckedListBox();
          
          Property<System::Windows::Forms::BorderStyle> BorderStyle {
            pcf_get {return this->GetBorderStyle();},
            pcf_set {this->SetBorderStyle(value);}
          };
          
          Property<int32, ReadOnly> SelectedIndex {
            pcf_get {return this->GetSelectedIndex();}
          };
          
          Property<const object&, ReadOnly> SelectedItem {
            pcf_get->const object& {return this->GetSelectedItem();}
          };
          
          Property<ObjectCollection&> Items {
            pcf_get->ObjectCollection& {return this->items;},
            pcf_set {this->items = value;}
          };

        private:
          System::Windows::Forms::BorderStyle GetBorderStyle() const;
          void SetBorderStyle(System::Windows::Forms::BorderStyle borderStyle);
          bool GetCanFocus() const override {return true;}
          System::Drawing::Size GetDefaultSize() const override {return System::Drawing::Size(120, 95);}
          int32 GetSelectedIndex() const;
          void SetSelectedIndex(int32 selectedIndex);
          const object& GetSelectedItem() const;
          
          bool HasClickRaised(MouseButtons button) const override {
            switch (button) {
              case MouseButtons::Left: return true;
              case MouseButtons::Right: return false;
              case MouseButtons::Middle: return false;
              case MouseButtons::XButton1: return false;
              case MouseButtons::XButton2: return false;
              default: return false;
            }
          }

          bool HasClickReplaceDoubleClick(MouseButtons button) const override {
            switch (button) {
              case MouseButtons::Left: return false;
              case MouseButtons::Right: return false;
              case MouseButtons::Middle: return false;
              case MouseButtons::XButton1: return false;
              case MouseButtons::XButton2: return false;
              default: return false;
            }
          }

          bool HasDoubleClickRaised(MouseButtons button) const override {
            switch (button) {
              case MouseButtons::Left: return true;
              case MouseButtons::Right: return false;
              case MouseButtons::Middle: return false;
              case MouseButtons::XButton1: return false;
              case MouseButtons::XButton2: return false;
              default: return false;
            }
          }

          void OnListBoxItemAdded(const object& sender, const object& item, bool checked);
          void OnListBoxItemCleared(const object& sender, const object&);
          void OnListBoxItemRemoved(const object& sender, const object& index);
          
          ObjectCollection items;
       };
      }
    }
  }
}
