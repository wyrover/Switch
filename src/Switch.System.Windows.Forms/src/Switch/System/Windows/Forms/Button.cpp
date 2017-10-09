#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/Button.hpp"
#include "../../../../Native/FormsApi.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void Button::CreateHandle() {
  this->handle = Native::FormsApi::Button::Create(*this);
  this->Control::CreateHandle();
  Native::FormsApi::Button::SetIsDefault(*this);
}

void Button::SetIsDefault(bool isDefault) {
  if (this->isDefault != isDefault) {
    this->isDefault = isDefault;
    if (this->IsHandleCreated)
      Native::FormsApi::Button::SetIsDefault(*this);
  }
}
