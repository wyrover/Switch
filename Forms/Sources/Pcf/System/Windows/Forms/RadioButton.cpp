#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/RadioButton.h"
#include "../../../../__OS/FormsApi.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void RadioButton::CreateHandle() {
  __OS::FormsApi::Control::Create(*this);
  this->Control::CreateHandle();
  __OS::FormsApi::RadioButton::SetChecked(*this);
}

void RadioButton::SetChecked(bool checked) {
  this->checked = checked;
  if (this->IsHandleCreated)
    __OS::FormsApi::RadioButton::SetChecked(*this);
}
