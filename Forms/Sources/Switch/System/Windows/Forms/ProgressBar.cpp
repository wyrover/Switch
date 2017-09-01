#include "../../../../../Includes/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../Includes/Switch/System/Windows/Forms/ProgressBar.hpp"
#include "../../../../__OS/FormsApi.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void ProgressBar::CreateHandle() {
  this->handle = __OS::FormsApi::ProgressBar::Create(*this);
  this->Control::CreateHandle();
  __OS::FormsApi::ProgressBar::SetMaximum(*this);
  __OS::FormsApi::ProgressBar::SetMinimum(*this);
  __OS::FormsApi::ProgressBar::SetValue(*this);
  __OS::FormsApi::ProgressBar::SetMarquee(*this);
}

void ProgressBar::SetMarqueeAnimationSpeed(int32 marqueeAnimationSpeed) {
  if (marqueeAnimationSpeed < 0)
    throw ArgumentOutOfRangeException(_current_information);
  if (this->marqueeAnimationSpeed != marqueeAnimationSpeed) {
    this->marqueeAnimationSpeed = marqueeAnimationSpeed;
    if (this->IsHandleCreated)
      __OS::FormsApi::ProgressBar::SetMarquee(*this);
  }
}

void ProgressBar::SetMaximum(int32 maximum) {
  if (this->maximum != maximum) {
    this->maximum = maximum;
    if (this->IsHandleCreated) {
      __OS::FormsApi::ProgressBar::SetMaximum(*this);
      __OS::FormsApi::ProgressBar::SetValue(*this);
    }
  }
}

void ProgressBar::SetMinimum(int32 minimum) {
  if (this->minimum != minimum) {
    this->minimum = minimum;
    if (this->IsHandleCreated) {
      __OS::FormsApi::ProgressBar::SetMinimum(*this);
      __OS::FormsApi::ProgressBar::SetValue(*this);
    }
  }
}

void ProgressBar::SetProgressStyle(ProgressBarStyle style) {
  if (this->style != style) {
    this->style = style;
    if (this->IsHandleCreated)
      __OS::FormsApi::ProgressBar::SetMarquee(*this);
  }
}

void ProgressBar::SetValue(int32 value) {
  if (this->value != value) {
    this->value = value;
    if (this->IsHandleCreated)
      __OS::FormsApi::ProgressBar::SetValue(*this);
  }
}
