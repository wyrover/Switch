#include "../../../../../Includes/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../Includes/Switch/System/Windows/Forms/TrackBar.hpp"
#include "../../../../__OS/FormsApi.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void TrackBar::CreateHandle() {
  this->handle = __OS::FormsApi::TrackBar::Create(*this);
  this->Control::CreateHandle();
  __OS::FormsApi::TrackBar::SetLargeChange(*this);
  __OS::FormsApi::TrackBar::SetMaximum(*this);
  __OS::FormsApi::TrackBar::SetMinimum(*this);
  __OS::FormsApi::TrackBar::SetOrientation(*this);
  __OS::FormsApi::TrackBar::SetSmallChange(*this);
  __OS::FormsApi::TrackBar::SetTickFrequency(*this);
  __OS::FormsApi::TrackBar::SetTickStyle(*this);
  __OS::FormsApi::TrackBar::SetValue(*this);
}

void TrackBar::WndProc(Message& message) {
  Control::WndProc(message);
  if (message.Msg == (WM_REFLECT + WM_HSCROLL) || message.Msg == (WM_REFLECT + WM_VSCROLL)) {
    int32 value = this->GetValue();
    if (this->value != value) {
      this->value = value;
      OnScroll(EventArgs::Empty);
      OnValueChanged(EventArgs::Empty);
    }
  }
}

void TrackBar::SetLargeChange(int32 largeChange) {
  if (this->largeChange != largeChange) {
    this->largeChange = largeChange;
    if (this->IsHandleCreated) {
      __OS::FormsApi::TrackBar::SetLargeChange(*this);
    }
  }
}

void TrackBar::SetMaximum(int32 maximum) {
  if (this->maximum != maximum) {
    this->maximum = maximum;
    if (this->IsHandleCreated) {
      __OS::FormsApi::TrackBar::SetMaximum(*this);
      __OS::FormsApi::TrackBar::SetValue(*this);
    }
  }
}

void TrackBar::SetMinimum(int32 minimum) {
  if (this->minimum != minimum) {
    this->minimum = minimum;
    if (this->IsHandleCreated) {
      __OS::FormsApi::TrackBar::SetMinimum(*this);
      __OS::FormsApi::TrackBar::SetValue(*this);
    }
  }
}

void TrackBar::SetOrientation(System::Windows::Forms::Orientation orientation) {
  if (this->orientation != orientation) {
    this->orientation = orientation;
    if (this->IsHandleCreated)
      __OS::FormsApi::TrackBar::SetOrientation(*this);
  }
}

void TrackBar::SetSmallChange(int32 smallChange) {
  if (this->smallChange != smallChange) {
    this->smallChange = smallChange;
    if (this->IsHandleCreated) {
      __OS::FormsApi::TrackBar::SetSmallChange(*this);
    }
  }
}

void TrackBar::SetTickFrequency(int32 tickFrequency) {
  if (tickFrequency < 0)
    throw ArgumentOutOfRangeException(_current_information);
  if (this->tickFrequency != tickFrequency) {
    this->tickFrequency = tickFrequency;
    if (this->IsHandleCreated)
      __OS::FormsApi::TrackBar::SetTickFrequency(*this);
  }
}

void TrackBar::SetTickStyle(System::Windows::Forms::TickStyle style) {
  if (this->style != style) {
    this->style = style;
    if (this->IsHandleCreated)
      __OS::FormsApi::TrackBar::SetTickStyle(*this);
  }
}

int32 TrackBar::GetValue() const {
  if (this->IsHandleCreated)
    return __OS::FormsApi::TrackBar::GetValue(*this);
  return this->value;
}

void TrackBar::SetValue(int32 value) {
  if (this->value != value) {
    this->value = value;
    if (this->IsHandleCreated)
      __OS::FormsApi::TrackBar::SetValue(*this);
    OnValueChanged(EventArgs::Empty);
  }
}
