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

void CheckBox::SetCheckState(System::Windows::Forms::CheckState checkState) {
  if (this->checkState != checkState) {
    bool oldChecked = this->Checked;
    this->checkState = checkState;

    if (this->IsHandleCreated)
      __OS::FormsApi::CheckBox::SetChecked(*this);

    if (oldChecked != this->Checked)
      this->OnCheckedChanged(EventArgs::Empty);

    this->OnCheckStateChanged(EventArgs::Empty);
  }
}
