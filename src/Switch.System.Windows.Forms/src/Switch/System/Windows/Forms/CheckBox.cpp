#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/CheckBox.hpp"
#include "../../../../Native/FormsApi.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void CheckBox::CreateHandle() {
  this->handle = Native::FormsApi::CheckBox::Create(*this);
  this->Control::CreateHandle();
  Native::FormsApi::CheckBox::SetChecked(*this);
}

void CheckBox::SetAutoCheck(bool autoCheck) {
  if (this->autoCheck != autoCheck) {
    this->autoCheck = autoCheck;
    if (this->IsHandleCreated)
      Native::FormsApi::CheckBox::SetAutoCheck(*this);
  }
}

void CheckBox::SetCheckState(System::Windows::Forms::CheckState checkState) {
  if (this->checkState != checkState) {
    bool oldChecked = this->Checked;
    this->checkState = checkState;

    if (this->IsHandleCreated)
      Native::FormsApi::CheckBox::SetChecked(*this);

    if (oldChecked != this->Checked)
      this->OnCheckedChanged(EventArgs::Empty);

    this->OnCheckStateChanged(EventArgs::Empty);
  }
}
