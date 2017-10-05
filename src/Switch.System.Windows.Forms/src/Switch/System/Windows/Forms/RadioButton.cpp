#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/RadioButton.hpp"
#include "../../../../__OS/FormsApi.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void RadioButton::CreateHandle() {
  this->handle = __OS::FormsApi::RadioButton::Create(*this);
  this->Control::CreateHandle();
  __OS::FormsApi::RadioButton::SetGroup(*this);
  __OS::FormsApi::RadioButton::SetChecked(*this);
}

void RadioButton::SetChecked(bool checked) {
  if (this->checked != checked) {
    this->checked = checked;
    if (this->IsHandleCreated)
      __OS::FormsApi::RadioButton::SetChecked(*this);
    if (this->AutoCheck && this->checked && this->Parent()) {
      for (auto control : this->Parent()().Controls()) {
        if (control != *this && is<RadioButton>(control))
          as<RadioButton>(control)().Checked = false;
      }
    }
    this->OnCheckedChanged(EventArgs::Empty);
  }
}

void RadioButton::OnParentChanged(const EventArgs& e) {
  this->ButtonBase::OnParentChanged(e);
  __OS::FormsApi::RadioButton::SetGroup(*this);
}


