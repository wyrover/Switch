#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/RadioButton.hpp"
#include "../../../../Native/FormsApi.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void RadioButton::CreateHandle() {
  this->handle = Native::FormsApi::RadioButton::Create(*this);
  this->Control::CreateHandle();
  Native::FormsApi::RadioButton::SetGroup(*this);
  Native::FormsApi::RadioButton::SetChecked(*this);
}

void RadioButton::SetChecked(bool checked) {
  if (this->checked != checked) {
    this->checked = checked;
    if (this->IsHandleCreated)
      Native::FormsApi::RadioButton::SetChecked(*this);
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
  Native::FormsApi::RadioButton::SetGroup(*this);
}


