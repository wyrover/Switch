#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/ProgressBar.h"
#include "../../../../__OS/FormsApi.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void ProgressBar::CreateHandle() {
  this->handle = __OS::FormsApi::ProgressBar::Create(*this);
  this->Control::CreateHandle();
  __OS::FormsApi::ProgressBar::SetMaximum(*this);
  __OS::FormsApi::ProgressBar::SetMinimum(*this);
  __OS::FormsApi::ProgressBar::SetValue(*this);
}

void ProgressBar::SetMaximum(int32 maximum) {
  this->maximum = maximum;
  if (this->IsHandleCreated) {
    __OS::FormsApi::ProgressBar::SetMaximum(*this);
    __OS::FormsApi::ProgressBar::SetValue(*this);
  }
}

void ProgressBar::SetMinimum(int32 minimum) {
  this->minimum = minimum;
  if (this->IsHandleCreated) {
    __OS::FormsApi::ProgressBar::SetMinimum(*this);
    __OS::FormsApi::ProgressBar::SetValue(*this);
  }
}

void ProgressBar::SetValue(int32 value) {
  this->value = value;
  if (this->IsHandleCreated)
    __OS::FormsApi::ProgressBar::SetValue(*this);
}
