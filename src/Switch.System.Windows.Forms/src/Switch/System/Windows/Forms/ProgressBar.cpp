#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/ProgressBar.hpp"
#include "../../../../Native/FormsApi.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void ProgressBar::CreateHandle() {
  this->handle = Native::FormsApi::ProgressBar::Create(*this);
  this->Control::CreateHandle();
  Native::FormsApi::ProgressBar::SetMaximum(*this);
  Native::FormsApi::ProgressBar::SetMinimum(*this);
  Native::FormsApi::ProgressBar::SetValue(*this);
  Native::FormsApi::ProgressBar::SetMarquee(*this);
}

void ProgressBar::SetMarqueeAnimationSpeed(int32 marqueeAnimationSpeed) {
  if (marqueeAnimationSpeed < 0)
    throw ArgumentOutOfRangeException(_caller);
  if (this->marqueeAnimationSpeed != marqueeAnimationSpeed) {
    this->marqueeAnimationSpeed = marqueeAnimationSpeed;
    if (this->IsHandleCreated)
      Native::FormsApi::ProgressBar::SetMarquee(*this);
  }
}

void ProgressBar::SetMaximum(int32 maximum) {
  if (this->maximum != maximum) {
    this->maximum = maximum;
    if (this->IsHandleCreated) {
      Native::FormsApi::ProgressBar::SetMaximum(*this);
      Native::FormsApi::ProgressBar::SetValue(*this);
    }
  }
}

void ProgressBar::SetMinimum(int32 minimum) {
  if (this->minimum != minimum) {
    this->minimum = minimum;
    if (this->IsHandleCreated) {
      Native::FormsApi::ProgressBar::SetMinimum(*this);
      Native::FormsApi::ProgressBar::SetValue(*this);
    }
  }
}

void ProgressBar::SetProgressStyle(ProgressBarStyle style) {
  if (this->style != style) {
    this->style = style;
    if (this->IsHandleCreated)
      Native::FormsApi::ProgressBar::SetMarquee(*this);
  }
}

void ProgressBar::SetValue(int32 value) {
  if (this->value != value) {
    this->value = value;
    if (this->IsHandleCreated)
      Native::FormsApi::ProgressBar::SetValue(*this);
  }
}
