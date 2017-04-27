#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/ProgressBar.h"
#include "../../../../__OS/FormsApi.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void ProgressBar::CreateHandle() {
  __OS::FormsApi::Control::Create(*this);
  this->Control::CreateHandle();
}

void ProgressBar::SetMaximum(int32 maximum) {
  this->progressBarData().maximum = maximum;
  __OS::FormsApi::ProgressBar::SetMaximum(*this);
}

void ProgressBar::SetMinimum(int32 minimum) {
  this->progressBarData().minimum = minimum;
  __OS::FormsApi::ProgressBar::SetMinimum(*this);
}

void ProgressBar::SetValue(int32 value) {
  this->progressBarData().value = value;
  __OS::FormsApi::ProgressBar::SetValue(*this);
}
