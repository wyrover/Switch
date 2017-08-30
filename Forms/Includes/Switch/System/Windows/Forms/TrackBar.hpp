/// @file
/// @brief Contains Switch::System::Windows::Forms::Button class.
#pragma once

#include <Switch/System/Environment.hpp>
#include "Control.hpp"
#include "Orientation.hpp"
#include "TickStyle.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a standard Windows track bar.
        /// @remarks The TrackBar is a scrollable control similar to the ScrollBar control. You can configure ranges through which the value of the Value property of a track bar scrolls by setting the Minimum property to specify the lower end of the range and the Maximum property to specify the upper end of the range.
        /// @remarks The LargeChange property defines the increment to add or subtract from the Value property when clicks occur on either side of the scroll box. The track bar can be displayed horizontally or vertically.
        /// @remarks You can use this control to input numeric data obtained through the Value property. You can display this numeric data in a control or use it in code.
        class pcf_public TrackBar : public Control {
        public:
          TrackBar() : Control("", 0, 0, 104, 45) {
            this->SetStyle(ControlStyles::UserPaint, false);
            this->TabStop = false;
          }

          Property<int32> LargeChange {
            pcf_get{ return this->largeChange; },
            pcf_set{ this->SetLargeChange(value); },
          };

          Property<Forms::Orientation> Orientation {
            pcf_get{ return this->orientation; },
            pcf_set{ this->SetOrientation(value); },
          };

          Property<int32> Maximum {
            pcf_get{ return this->maximum; },
            pcf_set{ this->SetMaximum(value); },
          };

          Property<int32> Minimum {
            pcf_get{ return this->minimum; },
            pcf_set{ this->SetMinimum(value); },
          };

          Property<int32> SmallChange{
            pcf_get{ return this->smallChange; },
            pcf_set{ this->SetSmallChange(value); },
          };

          Property<TickStyle> Style {
            pcf_get{ return this->style; },
            pcf_set{ this->SetTickStyle(value); },
          };

          Property<int32> TickFrequency {
            pcf_get{ return this->tickFrequency; },
            pcf_set{ this->SetTickFrequency(value); },
          };

          Property<int32> Value {
            pcf_get {
              this->value = this->GetValue();
              return this->value;
            },
            pcf_set{ this->SetValue(value); },
          };

          EventHandler Scroll;
          EventHandler ValueChanged;

          void WndProc(Message& message) override;

        protected:
          void OnScroll(const EventArgs& e) { this->Scroll(*this, e); }
          void OnValueChanged(const EventArgs& e) { this->ValueChanged(*this, e); }

          void CreateHandle() override;
          System::Drawing::Size GetDefaultSize() const override {
            if (this->orientation == Forms::Orientation::Horizontal)
              return System::Drawing::Size(104, 45);
            return System::Drawing::Size(45, 104);
          }
          void SetLargeChange(int32 largeChange);
          void SetMaximum(int32 maximum);
          void SetMinimum(int32 minimum);
          void SetOrientation(Forms::Orientation orientation);
          void SetSmallChange(int32 smallChange);
          void SetTickFrequency(int32 tickFrequency);
          void SetTickStyle(Forms::TickStyle style);
          int32 GetValue() const;
          void SetValue(int32 value);

          /// @cond
          int32 largeChange = 5;
          int32 maximum = 10;
          int32 minimum = 0;
          Forms::Orientation orientation = Forms::Orientation::Horizontal;
          int32 smallChange = 1;
          Forms::TickStyle style = TickStyle::BottomRight;
          int32 tickFrequency = 1;
          int32 value = 0;
          /// @endcond
        };
      }
    }
  }
}
