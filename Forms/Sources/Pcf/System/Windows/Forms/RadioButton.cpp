#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/RadioButton.h"
#include "../../../../__OS/FormsApi.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void RadioButton::CreateHandle() {
  this->handle = __OS::FormsApi::RadioButton::Create(*this);
  this->Control::CreateHandle();
  __OS::FormsApi::RadioButton::SetAutoCheck(*this);
  __OS::FormsApi::RadioButton::SetChecked(*this);
}

void RadioButton::SetAutoCheck(bool autoCheck) {
  if (this->autoCheck != autoCheck) {
    this->autoCheck = autoCheck;
    if (this->IsHandleCreated)
      __OS::FormsApi::RadioButton::SetAutoCheck(*this);
  }
}

void RadioButton::SetChecked(bool checked) {
  if (this->checked != checked) {
    this->checked = checked;
    if (this->IsHandleCreated)
      __OS::FormsApi::RadioButton::SetChecked(*this);
  }
}

