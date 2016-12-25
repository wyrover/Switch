#include "FltkWidget.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/NumericUpDown.h"

#include <Pcf/System/Drawing/SystemColors.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

using WidgetNumericUpDown = Fltk::Widget<Fl_Spinner>;

NumericUpDown::NumericUpDown() : Control(UniquePointer<IWidget>::Create<WidgetNumericUpDown>()) {
  this->widget().Callback += pcf_delegate(const object& sender, const EventArgs& e) {
    this->value = WidgetNumericUpDown::ToWidget(this->widget()).value();
    this->OnValueChanged(e);
  };

  this->Size = this->DefaultSize;
  this->BackColor = SystemColors::Window;
  this->ForeColor = SystemColors::WindowText;
#if __APPLE__
  WidgetNumericUpDown::ToWidget(this->widget()).selection_color(Fltk::Helper::ToFlColor(Color::FromArgb(100, 163, 205, 255)));
#else
  WidgetNumericUpDown::ToWidget(this->widget()).selection_color(Fltk::Helper::ToFlColor(SystemColors::Highlight));
#endif
  WidgetNumericUpDown::ToWidget(this->widget()).when(FL_WHEN_CHANGED);
  WidgetNumericUpDown::ToWidget(this->widget()).step(this->increment);
  WidgetNumericUpDown::ToWidget(this->widget()).maximum(this->maximum);
  WidgetNumericUpDown::ToWidget(this->widget()).minimum(this->minimum);
  WidgetNumericUpDown::ToWidget(this->widget()).value(this->value);
}

void NumericUpDown::SetDecimalPlaces(int32 decimalPlace) {
  WidgetNumericUpDown::ToWidget(this->widget()).type(decimalPlace == 0 ? FL_INT_INPUT : FL_FLOAT_INPUT);
  this->decimalPlaces = decimalPlace;
  this->strFormat = string::Format("%.{0}f", this->decimalPlaces);
  WidgetNumericUpDown::ToWidget(this->widget()).format(this->strFormat.Data());
}

void NumericUpDown::SetIncrement(double increment) {
  if (this->increment != increment) {
    this->increment = increment;
    WidgetNumericUpDown::ToWidget(this->widget()).step(increment);
  }
}

void NumericUpDown::SetMaximum(double maximum) {
  if (this->maximum != maximum) {
    this->maximum = maximum;
    WidgetNumericUpDown::ToWidget(this->widget()).maximum(maximum);
    if (this->value > this->maximum)
      this->Value = this->maximum;
  }
}

void NumericUpDown::SetMinimum(double minimum) {
  if (this->minimum != minimum) {
    this->minimum = minimum;
    WidgetNumericUpDown::ToWidget(this->widget()).minimum(minimum);
    if (this->value < this->minimum)
      this->Value = this->minimum;
  }
}

void NumericUpDown::SetValue(double value) {
  if (this->value != value) {
    this->value = value;
    WidgetNumericUpDown::ToWidget(this->widget()).value(value);
    this->OnValueChanged(EventArgs());
  }
}
