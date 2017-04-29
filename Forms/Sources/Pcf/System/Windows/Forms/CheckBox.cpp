#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/CheckBox.h"
#include "../../../../__OS/FormsApi.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void CheckBox::CreateHandle() {
  this->handle = __OS::FormsApi::Control::Create(*this);
  this->Control::CreateHandle();
  __OS::FormsApi::CheckBox::SetChecked(*this);
}

void CheckBox::SetChecked(bool checked) {
  this->checked = checked;
  if (this->IsHandleCreated)
    __OS::FormsApi::CheckBox::SetChecked(*this);
}
