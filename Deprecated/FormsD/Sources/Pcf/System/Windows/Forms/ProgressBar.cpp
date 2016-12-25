#include "FltkWidget.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/ProgressBar.h"

#include <Pcf/System/Drawing/SystemColors.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::FormsD;

namespace {
  using WidgetProgress = Fltk::Widget<Fl_Progress>;
}

ProgressBar::ProgressBar() {
  this->Register(UniquePointer<IWidget>::Create<WidgetProgress>(0, 0, 100, 23, ""));
  this->Minimum = 0;
  this->Maximum = 100;
  this->Value = 0;
#if _WIN32
  this->ForeColor = Color::LimeGreen;
#else
  this->ForeColor = SystemColors::Highlight;
#endif
  WidgetProgress::ToWidget(this->widget()).align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  this->HandleCreated(*this, EventArgs());
}

ProgressBar::~ProgressBar() {
  this->Unregister();
  this->HandleDestroyed(*this, EventArgs());
}

void ProgressBar::SetForeColor(const System::Drawing::Color& color) {
  if (this->foreColor != color) {
    this->foreColor = color;
    WidgetProgress::ToWidget(this->widget()).selection_color(Fltk::Helper::ToFlColor(color));
    this->ForeColorChanged(*this, EventArgs());
  }
}

int32 ProgressBar::GetMaximum() const {
  return WidgetProgress::ToWidget(this->widget()).maximum();
}

void ProgressBar::SetMaximum(int32 maximum) {
  WidgetProgress::ToWidget(this->widget()).maximum(maximum);
}

int32 ProgressBar::GetMinimum() const {
  return WidgetProgress::ToWidget(this->widget()).minimum();
}

void ProgressBar::SetMinimum(int32 minimum) {
  WidgetProgress::ToWidget(this->widget()).minimum(minimum);
}

int32 ProgressBar::GetValue() const {
  return WidgetProgress::ToWidget(this->widget()).value();
}

void ProgressBar::SetValue(int32 value) {
  WidgetProgress::ToWidget(this->widget()).value(value);
}
