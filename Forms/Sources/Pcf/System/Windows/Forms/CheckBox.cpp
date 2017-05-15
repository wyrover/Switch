#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/CheckBox.h"
#include "../../../../__OS/FormsApi.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void CheckBox::CreateHandle() {
  this->handle = __OS::FormsApi::CheckBox::Create(*this);
  this->Control::CreateHandle();
  __OS::FormsApi::CheckBox::SetChecked(*this);
}

void CheckBox::SetAutoCheck(bool autoCheck) {
  if (this->autoCheck != autoCheck) {
    this->autoCheck = autoCheck;
    if (this->IsHandleCreated)
      __OS::FormsApi::CheckBox::SetAutoCheck(*this);
  }
}

void CheckBox::SetChecked(bool checked) {
  if (this->checked != checked) {
    this->checked = checked;
    if (this->IsHandleCreated)
      __OS::FormsApi::CheckBox::SetChecked(*this);
    this->OnCheckedChanged(EventArgs::Empty);
  }
}
